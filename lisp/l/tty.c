/* ./tty.c :  entry=tty */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "tty.h"
#pragma init (register_tty)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___tty();
extern pointer build_quote_vector();
static int register_tty()
  { add_module_initializer("___tty", ___tty);}

static pointer F74642tty_raw();
static pointer F74644tty_cooked();
static pointer F74646backspace();
static pointer F74648cursor_up();
static pointer F74650cursor_down();
static pointer F74652cursor_forward();
static pointer F74654cursor_backward();
static pointer F74656cursor_return();
static pointer F74658cursor_pos();
static pointer F74660erase_eol();

/*tty-raw*/
static pointer F74642tty_raw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74691;}
	local[0]= makeint((eusinteger_t)0L);
ENT74691:
ENT74690:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)COPYSEQ(ctx,1,local+1); /*copy-seq*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)7L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)12L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)13L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)14L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)15L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)21L);
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)22L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[1]); /*unix:tcsets*/
	local[0]= w;
BLK74688:
	ctx->vsp=local; return(local[0]);}

/*tty-cooked*/
static pointer F74644tty_cooked(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74764;}
	local[0]= makeint((eusinteger_t)0L);
ENT74764:
ENT74763:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*unix:tcsets*/
	local[0]= w;
BLK74761:
	ctx->vsp=local; return(local[0]);}

/*backspace*/
static pointer F74646backspace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74784;}
	local[0]= makeint((eusinteger_t)1L);
ENT74784:
ENT74783:
	if (n>1) maerror();
	local[1]= makeint((eusinteger_t)0L);
	local[2]= local[0];
WHL74819:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX74820;
	local[3]= makeint((eusinteger_t)8L);
	local[4]= loadglobal(fqv[2]);
	ctx->vsp=local+5;
	w=(pointer)WRTBYTE(ctx,2,local+3); /*write-byte*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL74819;
WHX74820:
	local[3]= NIL;
BLK74821:
	w = NIL;
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK74781:
	ctx->vsp=local; return(local[0]);}

/*cursor-up*/
static pointer F74648cursor_up(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74852;}
	local[0]= makeint((eusinteger_t)1L);
ENT74852:
ENT74851:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[3];
	local[3]= makeint((eusinteger_t)27L);
	local[4]= makeint((eusinteger_t)91L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK74849:
	ctx->vsp=local; return(local[0]);}

/*cursor-down*/
static pointer F74650cursor_down(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74876;}
	local[0]= makeint((eusinteger_t)1L);
ENT74876:
ENT74875:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[4];
	local[3]= makeint((eusinteger_t)27L);
	local[4]= makeint((eusinteger_t)91L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK74873:
	ctx->vsp=local; return(local[0]);}

/*cursor-forward*/
static pointer F74652cursor_forward(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74900;}
	local[0]= makeint((eusinteger_t)1L);
ENT74900:
ENT74899:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[5];
	local[3]= makeint((eusinteger_t)27L);
	local[4]= makeint((eusinteger_t)91L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK74897:
	ctx->vsp=local; return(local[0]);}

/*cursor-backward*/
static pointer F74654cursor_backward(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT74924;}
	local[0]= makeint((eusinteger_t)1L);
ENT74924:
ENT74923:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[2]);
	local[2]= fqv[6];
	local[3]= makeint((eusinteger_t)27L);
	local[4]= makeint((eusinteger_t)91L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK74921:
	ctx->vsp=local; return(local[0]);}

/*cursor-return*/
static pointer F74656cursor_return(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[7];
	local[2]= makeint((eusinteger_t)13L);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK74945:
	ctx->vsp=local; return(local[0]);}

/*cursor-pos*/
static pointer F74658cursor_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF74971;
	ctx->vsp=local+0;
	w=(pointer)F74656cursor_return(ctx,0,local+0); /*cursor-return*/
	local[0]= w;
	goto IF74972;
IF74971:
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[8];
	local[2]= makeint((eusinteger_t)13L);
	local[3]= makeint((eusinteger_t)27L);
	local[4]= makeint((eusinteger_t)91L);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
IF74972:
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK74961:
	ctx->vsp=local; return(local[0]);}

/*erase-eol*/
static pointer F74660erase_eol(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[2]);
	local[1]= fqv[9];
	local[2]= makeint((eusinteger_t)27L);
	local[3]= makeint((eusinteger_t)91L);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= loadglobal(fqv[2]);
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK74988:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___tty(ctx,n,argv,env)
register context *ctx; int n; pointer *argv; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv;
  register int i;
  numunion nu;
  module=argv[0];
  quotevec=build_quote_vector(ctx,QUOTE_STRINGS_SIZE, quote_strings);
  module->c.code.quotevec=quotevec;
  codevec=module->c.code.codevec;
  fqv=qv=quotevec->c.vec.v;
  init_ftab();
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[11],module,F74642tty_raw,fqv[12]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[13],module,F74644tty_cooked,fqv[14]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[15],module,F74646backspace,fqv[16]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[17],module,F74648cursor_up,fqv[18]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[19],module,F74650cursor_down,fqv[20]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[21],module,F74652cursor_forward,fqv[22]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[23],module,F74654cursor_backward,fqv[24]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[25],module,F74656cursor_return,fqv[26]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[27],module,F74658cursor_pos,fqv[28]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[29],module,F74660erase_eol,fqv[30]);
	local[0]= fqv[31];
	local[1]= fqv[32];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[33]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<2; i++) ftab[i]=fcallx;
}
