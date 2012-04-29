#include <errno.h>

int
kill (int pid, int sig)
{
  errno = ENOSYS;
  return -1;
}
