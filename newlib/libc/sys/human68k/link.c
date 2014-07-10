#include <errno.h>

int link(char *existing, char *new)
{
  errno = ENOSYS;
  return -1;
}
