
/* file: geline.h
 * author: Hans Henrik Staerfeldt
 * usage: get a line of any length
 */

/* 
   getline reads characters from the stream into memory. The address of
   that memory is returned. The memory is static and will change between
   each call to getline.
   It reads until a new-line character is read and transferred to the
   buffer, or an end-of-file condition is encountered.  The string is then 
   terminated with a null character.
   If end-of-file is encountered and no characters have been read, no
   characters are transferred to memory and a NULL pointer is returned.
   The buffer will grow to accomodate any length of line read, and will
   never be freed.
*/ 


char *getline_mn (FILE *stream);
