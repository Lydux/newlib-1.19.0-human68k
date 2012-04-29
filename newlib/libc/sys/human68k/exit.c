#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dos.h>
#include "fds.h"

typedef void (*pfunc) ();
extern pfunc __dtors_start[];
extern pfunc __dtors_end[];

void
_exit (int status)
{
  int i;

  /* TODO : atexit ! */

  /* Calls destructors */

  for (i = 0; i < __dtors_end - __dtors_start; i++)
    __dtors_start[i] ();


  /* Close opened file */
  __fd_exit_clean ();

  _dos_exit2 (status);
}

