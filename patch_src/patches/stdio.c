#include "stdio.h"

int fseek(FILE *stream, long offset, int whence)
{
  return -1;
}

int fgetpos(FILE *stream, fpos_t *pos)
{
  return -1;
}

int fsetpos(FILE *stream, fpos_t *pos)
{
  return -1;
}

long ftell(FILE *stream)
{
  return -1;
}

FILE *fopen(const char *path, const char *mode)
{
  return NULL;
}

FILE *freopen(const char *path, const char *mode, FILE *stream)
{
  return NULL;
}

void perror(const char *s)
{
}

int remove(const char *pathname)
{
  return -1;
}

int rename(const char *old_name, const char *new_name)
{
  return -1;
}

void rewind(FILE *stream)
{
}

void setbuf(FILE *stream, char *buf)
{
}

int setvbuf(FILE *stream, char *buf, int mode, size_t size)
{
  return -1;
}

FILE *tmpfile(void)
{
  return NULL;
}

char *tmpnam(char *s)
{
  return NULL;
}

int fileno(FILE *stream)
{
  return (int)stream;
}
