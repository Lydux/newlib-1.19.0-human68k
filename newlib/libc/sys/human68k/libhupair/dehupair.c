#include <string.h>
#include <hupair.h>

int
dehupair (const struct dos_psp *psp, char *comm)
{
  int c;
  int ret, inquote;
  char *q;
  const char *p;
  int _hupair;

  p = psp->comline->buffer;
  q = comm;
  ret = 1;
  inquote = 0;

  /* Check for hupair support */
  _hupair = hupair_shell (psp);

  while (*p == ' ')
    p++;

  if (*p == '\0')
  {
    *q++ = '\0';
    *q++ = '\0';
    return 0;
  }

  while ((c = *p++))
  {
    if (!_hupair && c == '\\')
    {
      if (*p == '\'' || *p == '"')
      {
        *q++ = *p++;
        continue;
      }
    }

    if (inquote)
    {
      if (c == inquote)
        inquote = 0;
      else
        *q++ = c;
    }
    else if (c == '\'' || c == '"')
      inquote = c;
    else if (c == ' ')
    {
      *q++ = '\0';
	    
      while (*p == ' ')
        p++;

      if (*p == '\0')
        goto null_char;

      ret++;
    }
    else
      *q++ = c;
  }

  *q++ = '\0';

null_char:
  *q = '\0';

  return ret;
}

