#ifndef _HUPAIR_H
#define _HUPAIR_H

#include <sys/cdefs.h>
#include <dos.h>

#define HUPAIR_MAGIC	"#HUPAIR"

__BEGIN_DECLS

int	__hupair_shell (const struct dos_psp *);
int     dehupair (const struct dos_psp *, char *);
int     enhupair (const char *, char const **, char *, int);

__END_DECLS

#endif /* _HUPAIR_H */

