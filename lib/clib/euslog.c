/*************************************************************
/* euslog.c 2021-10-12 by Toshihiro Matsui
/* % cc -c -fpic -DLinux -Dx86_64 -falign-functions=8 -DGCC\
   -shared -I../../include euslog.c
/* % ld -o euslog.so -shared euslog.o
/* From euslisp,
/* (openlog "eventtag" option default-facility)
/* (syslog priority "message")
/***************************************/  

#include "eus.h"
#include <syslog.h>

/*
       void openlog(const char *ident, int option, int facility);
       void syslog(int priority, const char *format, ...);
       void closelog(void);
*/

pointer OPENLOG(context *ctx, int n, pointer argv[])
{ char *identp; 
  int option=0, facility=0;

  ckarg2(1,3); /* ident, option, facility */
  identp=argv[0]->c.str.chars;
  fprintf(stderr, "OPENLOG!!! n=%d %s\n", n, identp);
  if (n>=2) option=ckintval(argv[1]);
  if (n==3) facility=ckintval(argv[2]);
  openlog(identp, option, facility);
  return(NIL);}

pointer SYSLOG(context *ctx, int n, pointer argv[])
{ int priority;
  char *formatp; 

  ckarg(2);
  priority=ckintval(argv[0]);
  formatp=argv[1]->c.str.chars;
  syslog(priority, formatp);
  fprintf(stderr, "SYSLOG: %d %s\n", priority, formatp);
  return(NIL); }


pointer euslog(context *ctx, int n, pointer argv[])
{ pointer mod=argv[0];

  defun(ctx,"OPENLOG",mod,OPENLOG);
  defun(ctx,"SYSLOG", mod, SYSLOG);
  return(T);
  }

