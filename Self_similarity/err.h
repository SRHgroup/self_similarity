/*
 * err.h : error functions
 */

#ifndef SRC_ERR_H
#define SRC_ERR_H

#ifndef printerr
#ifdef VERBOSE
#define printerr(err, proc, msg) \
  do { \
    if (err) { \
      sprintf(&err[strlen(err)], "%s line %d (%s): %s.\n", __FILE__, __LINE__, proc, msg); \
      fprintf(stderr, "Error: %s", err); \
    } \
  }while(0)
#else
#define printerr(err, proc, msg) \
  do { \
    if (err) { \
      sprintf(&err[strlen(err)], "%s line %d (%s): %s.\n", __FILE__, __LINE__, proc, msg); \
    } \
  }while(0)
#endif
#endif

#endif
