#ifndef _FCNTL_H
#define _FCNTL_H

#include "bits/errno.h"
#include "bits/fcntl.h"

/* For XPG all symbols from <sys/stat.h> should also be available.  */
#ifdef __USE_XOPEN
# include <sys/stat.h>
#endif

#ifdef	__USE_MISC
# ifndef R_OK			/* Verbatim from <unistd.h>.  Ugh.  */
/* Values for the second argument to access.
   These may be OR'd together.  */
#  define R_OK	4		/* Test for read permission.  */
#  define W_OK	2		/* Test for write permission.  */
#  define X_OK	1		/* Test for execute permission.  */
#  define F_OK	0		/* Test for existence.  */
# endif
#endif /* Use misc.  */

/* XPG wants the following symbols.  */
#ifdef __USE_XOPEN		/* <stdio.h> has the same definitions.  */
# define SEEK_SET	0	/* Seek from beginning of file.  */
# define SEEK_CUR	1	/* Seek from current position.  */
# define SEEK_END	2	/* Seek from end of file.  */
#endif	/* XPG */

#ifdef __USE_ATFILE
# define AT_FDCWD		-100	/* Special value used to indicate
             the *at functions should use the
             current working directory. */
# define AT_SYMLINK_NOFOLLOW	0x100	/* Do not follow symbolic links.  */
# define AT_REMOVEDIR		0x200	/* Remove directory instead of
             unlinking file.  */
# define AT_SYMLINK_FOLLOW	0x400	/* Follow symbolic links.  */
# define AT_EACCESS		0x200	/* Test access permitted for
             effective IDs, not real IDs.  */
#endif

#ifdef __cplusplus
extern "C"
{
#endif

int fcntl(int fd, int cmd, ... /* arg */ );

#ifdef __cplusplus
}
#endif

#endif // _FCNTL_H
