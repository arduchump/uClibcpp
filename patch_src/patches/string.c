#include "stdio.h"
#include "string.h"

char *strerror(int errnum)
{
  static char buf[12] = {'\0', };

  snprintf(buf, sizeof(buf), "0x%x", errnum);
  buf[sizeof(buf) - 1] = '\0';
  return buf;
}

size_t strxfrm ( char * destination, const char * source, size_t num )
{
  return 0;
}
