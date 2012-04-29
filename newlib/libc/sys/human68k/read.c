#include <sys/types.h>
#include <dos.h>

int
read (int fd, const void *buf, size_t nbyte)
{
  return _dos_read (fd, buf, nbyte);
}

