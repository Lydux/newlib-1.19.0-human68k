#include <fcntl.h>
#include <dos.h>
#include "fds.h"

int
open (const char *pathname, int flags, ...)
{
  int fd;

  if (flags & (O_CREAT | O_EXCL))
    fd = _dos_create (pathname, flags);
  else
    fd = _dos_open (pathname, flags & O_ACCMODE);

  flags |= O_BINARY;

  if ((fd >= 0) && (__fd_assign (fd, pathname, flags) < 0))
  {
    _dos_close (fd);
    return -1;
  }

  return fd;
}

