#ifndef __INCLUDED_63C25E465AE811E6911100F1F38F93EF
#define __INCLUDED_63C25E465AE811E6911100F1F38F93EF

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define strcoll strcmp
char *strerror(int errnum);
size_t strxfrm ( char * destination, const char * source, size_t num );

#ifdef __cplusplus
}
#endif

#endif // __INCLUDED_63C25E465AE811E6911100F1F38F93EF
