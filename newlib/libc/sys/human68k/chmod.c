#include <sys/stat.h>
#include <errno.h>
#include <dos.h>

int
chmod (const char *path, mode_t mode)
{
  int attr;

  /* TODO : mode = mode2dos (mode) */
  attr = _dos_chmod (path, mode);

  if (attr < 0)
  {
    /* TODO : errno = errcvt (attr); */
    errno = ENOENT;
    return -1;
  }

  return 0;
}
