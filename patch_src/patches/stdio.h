#ifndef __INCLUDED_0E3B8D125AE311E6907500F1F38F93EF
#define __INCLUDED_0E3B8D125AE311E6907500F1F38F93EF

#include <stdio.h>

// Latest stdio.h already supported predeclare these functions
#ifndef BUFSIZ

#ifdef FILE
#undef FILE
typedef struct __file FILE;
#endif

typedef int fpos_t;

#ifdef __cplusplus
extern "C"
{
#endif

int fseek(FILE *stream, long offset, int whence);
int fgetpos(FILE *stream, fpos_t *pos);
int fsetpos(FILE *stream, fpos_t *pos);
long ftell(FILE *stream);
FILE *fopen(const char *path, const char *mode);
FILE *freopen(const char *path, const char *mode, FILE *stream);

void perror(const char *s);
int remove(const char *pathname);
int rename(const char *old_name, const char *new_name);
void rewind(FILE *stream);
void setbuf(FILE *stream, char *buf);
int setvbuf(FILE *stream, char *buf, int mode, size_t size);
FILE *tmpfile(void);
char *tmpnam(char *s);
int fileno(FILE *stream);

#ifdef __cplusplus
}
#endif

#endif // BUFSIZ

#endif // __INCLUDED_0E3B8D125AE311E6907500F1F38F93EF
