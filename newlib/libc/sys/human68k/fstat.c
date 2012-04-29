#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
  if (fd < 3)
  {
      st->st_mode = S_IFCHR;
      st->st_blksize = 0;
      return 0;
  }
  else
  {
      return -1;
  }  
}
