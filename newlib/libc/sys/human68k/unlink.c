#include <errno.h>

int unlink(char *name)
{
  errno = ENOSYS;
  return -1;
}
