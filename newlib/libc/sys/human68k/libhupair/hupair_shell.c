#include <string.h>
#include <hupair.h>

int
hupair_shell (const struct dos_psp *psp)
{
  struct dos_comline *cmdline = psp->comline;

  return (strncmp (cmdline - 8, HUPAIR_MAGIC, 8) == 0);
}

