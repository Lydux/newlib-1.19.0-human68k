#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <dos.h>

extern caddr_t	_HSTA;
extern caddr_t	_HEND;
extern struct dos_psp	*_PSP;
extern caddr_t	_HMAX;

caddr_t
sbrk (size_t nbytes)
{
  caddr_t result;

  if (( _HEND + nbytes < _HSTA) ||
        _HEND + nbytes > _HMAX ||
	_dos_setblock (_PSP, (int) (_HEND + nbytes - (int) _PSP)) < 0)
  {
     errno = ENOMEM;
     return ((caddr_t) -1);
  }

  result = (caddr_t) _HEND;
  _HEND += nbytes;

  return result;
}

