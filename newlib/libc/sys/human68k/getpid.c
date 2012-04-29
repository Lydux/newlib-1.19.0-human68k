#include <errno.h>

int
getpid (void)
{
  errno = ENOSYS;
  return -1;
}

