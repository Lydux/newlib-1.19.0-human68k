#include <errno.h>

int
fork()
{
  errno = ENOSYS;
  return -1;
}
