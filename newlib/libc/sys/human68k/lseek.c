#include <sys/types.h>
#include <dos.h>

off_t
lseek(int fd, off_t offset, int whence)
{
  return _dos_seek (fd, offset, whence);
}

