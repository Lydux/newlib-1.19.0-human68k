#include <dos.h>
#include "fds.h"

int
close (int fd)
{
  if (__fd_remove (fd) < 0)
    return -1;

  return _dos_close (fd);
}

