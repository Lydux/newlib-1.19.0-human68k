#include <ctype.h>
#include <string.h>
#include <hupair.h>

/* Macros */
#define PUT(c)		\
{		\
  if (q < max)	\
    *q++ = c;	\
  else		\
    return -1;	\
}

static __inline int
decide_quote (const char *arg)
{
  int ch;

  if (*arg == 0)
    return '"';

  while ((ch = *arg++))
  {
    if (ch == '"')
      return '\'';

    if (ch == '\'' || isblank (ch))
      return '"';

  }

  return 0;
}

int
enhupair (const char *argv0, const char **argv, char *cmdline, int bufsiz)
{
  int c, ret, quote;
  char *q;
  const char *arg;
  const char *max;

  q = cmdline;
  max = q + bufsiz - (strlen (argv0) + 1);

  PUT ('\0');

  while ((arg = *argv++))
  {
    quote = decide_quote (arg);
    if (quote)
      PUT (quote);

    while ((c = *arg++))
    {
      if (c == quote)
      {
        PUT (quote);

        quote = (c == '"') ? '\'' : '"';

        PUT (quote);
      }
      PUT (c);
    }

    if (quote)
      PUT (quote);

    if (*argv)
      PUT (' ');
  }

  PUT ('\0');

  strcpy (q, argv0);

  strcpy (cmdline - 8, HUPAIR_MAGIC);

  ret = q - 2 - cmdline;

  *cmdline = (ret > 255) ? 255 : ret;

  return ret;
}

