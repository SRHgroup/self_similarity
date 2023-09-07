
#include <stdio.h>

#define INSTREAM_GZIP        1
#define INSTREAM_BZIP        2
#define INSTREAM_COMPRESS    3
#define INSTREAM_PLAIN       4
#define INSTREAM_STDIN       5

FILE *openinstream(char *fname, int *type);
int closeinstream(FILE *f, int type);
int canopeninstream(char *fname, int *type);
