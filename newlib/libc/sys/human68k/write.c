#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <human68k/error.h>
#include <dos.h>
#include "fds.h"

#define TXTBUFSIZE	2048

int
write (int fd, const void *buf, size_t nbyte)
{
  const char *bufptr = (const char *) buf;
  int rc;

  if (!__valid_fd (fd))
  {
    errno = EBADF;
    return -1;
  }

  if (nbyte <= 0)
    return 0;

  /* TODO : Test for directory fd */

  if (__fd_flags (fd) & O_BINARY)
  {
    rc = _dos_write (fd, bufptr, nbyte);
    if (rc <0)
    {
      errno = __doserr2e (rc);
      return -1;
    }
    else if (rc != nbyte)
    {
      errno = ENOSPC;
      return -1;
    }
  }
  else	/* O_TEXT */
  {
    size_t bytes_in_buf;
    size_t writted = 0;
    char txtbuf[TXTBUFSIZE];
    char *wp;

    while (bufptr < buf + nbyte)
    {
      wp = txtbuf;
      bytes_in_buf = 0;
      while (bufptr < buf + nbyte && wp < txtbuf + TXTBUFSIZE)
      {
        if (*bufptr == '\n')
	{
	  *wp++ = '\r';
	  bytes_in_buf++;
	}
	
	*wp++ = *bufptr++;
	bytes_in_buf++;
      }

      writted += _dos_write (fd, txtbuf, bytes_in_buf);
    }

  }

  return rc;
}

