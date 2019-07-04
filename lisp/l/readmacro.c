/* ./readmacro.c :  entry=readmacro */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "readmacro.h"
#pragma init (register_readmacro)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___readmacro();
extern pointer build_quote_vector();
static int register_readmacro()
  { add_module_initializer("___readmacro", ___readmacro);}

static pointer F3371read_backquote();
static pointer F3374conv_bq();
static pointer F3377conscons();
static pointer F3380read_comma();
static pointer F3385read_binary();
static pointer F3388read_bit_vector();
static pointer F3394read_pathname();
static pointer F3398read_radian();
static pointer F3402read_degree();

/*read-backquote*/
static pointer F3371read_backquote(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT3439;}
	local[0]= NIL;
ENT3439:
ENT3438:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3374conv_bq(ctx,1,local+1); /*conv-bq*/
	local[0]= w;
BLK3436:
	ctx->vsp=local; return(local[0]);}

/*conv-bq*/
static pointer F3374conv_bq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (argv[0]!=NIL) goto CON3472;
	local[0]= NIL;
	goto CON3470;
CON3472:
	w = argv[0];
	if (!!iscons(w)) goto CON3477;
	local[0]= fqv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON3470;
CON3477:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!!iscons(w)) goto CON3487;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[1]!=local[0]) goto CON3499;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	goto CON3497;
CON3499:
	local[0]= fqv[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3374conv_bq(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3377conscons(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3497;
CON3515:
	local[0]= NIL;
CON3497:
	goto CON3470;
CON3487:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[1]!=local[0]) goto CON3536;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3374conv_bq(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3377conscons(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3470;
CON3536:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[2]!=local[0]) goto CON3565;
	local[0]= fqv[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F3374conv_bq(ctx,1,local+2); /*conv-bq*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	goto CON3470;
CON3565:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)F3374conv_bq(ctx,1,local+0); /*conv-bq*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F3374conv_bq(ctx,1,local+1); /*conv-bq*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F3377conscons(ctx,2,local+0); /*conscons*/
	local[0]= w;
	goto CON3470;
CON3596:
	local[0]= NIL;
CON3470:
	w = local[0];
	local[0]= w;
BLK3460:
	ctx->vsp=local; return(local[0]);}

/*conscons*/
static pointer F3377conscons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[1]!=NIL) goto IF3630;
	local[0]= fqv[4];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF3631;
IF3630:
	local[0]= fqv[5];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF3631:
	w = local[0];
	local[0]= w;
BLK3618:
	ctx->vsp=local; return(local[0]);}

/*read-comma*/
static pointer F3380read_comma(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT3652;}
	local[0]= NIL;
ENT3652:
ENT3651:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)PEEKCH(ctx,1,local+1); /*peek-char*/
	local[1]= w;
	if (makeint((eusinteger_t)64L)!=local[1]) goto CON3668;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	local[1]= fqv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON3666;
CON3668:
	local[1]= fqv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,1,local+2); /*read*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON3666;
CON3686:
	local[1]= NIL;
CON3666:
	w = local[1];
	local[0]= w;
BLK3649:
	ctx->vsp=local; return(local[0]);}

/*read-binary*/
static pointer F3385read_binary(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	argv[2] = w;
WHL3736:
	local[1]= argv[2];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[7]); /*find*/
	if (w==NIL) goto WHX3737;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)48L);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	argv[2] = w;
	goto WHL3736;
WHX3737:
	local[1]= NIL;
BLK3738:
	w = argv[2];
	if (!isint(w)) goto IF3776;
	local[1]= argv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)UNREADCH(ctx,2,local+1); /*unread-char*/
	local[1]= w;
	goto IF3777;
IF3776:
	local[1]= NIL;
IF3777:
	w = local[0];
	local[0]= w;
BLK3703:
	ctx->vsp=local; return(local[0]);}

/*read-bit-vector*/
static pointer F3388read_bit_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= fqv[8];
	local[1]= fqv[9];
	local[2]= fqv[10];
	local[3]= fqv[11];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,5,local+0,&ftab[1],fqv[12]); /*make-array*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READCH(ctx,1,local+1); /*read-char*/
	argv[2] = w;
WHL3836:
	local[1]= argv[2];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[7]); /*find*/
	if (w==NIL) goto WHX3837;
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)48L);
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VECTOREXPUSH(ctx,2,local+1); /*vector-push-extend*/
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	argv[2] = w;
	goto WHL3836;
WHX3837:
	local[1]= NIL;
BLK3838:
	local[1]= local[0]->c.obj.iv[1];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,1,local+3,&ftab[2],fqv[14]); /*fill-pointer*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK3792:
	ctx->vsp=local; return(local[0]);}

/*read-pathname*/
static pointer F3394read_pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[15]); /*pathname*/
	local[0]= w;
BLK3884:
	ctx->vsp=local; return(local[0]);}

/*read-radian*/
static pointer F3398read_radian(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[16]); /*deg2rad*/
	local[0]= w;
BLK3908:
	ctx->vsp=local; return(local[0]);}

/*read-degree*/
static pointer F3402read_degree(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)READ(ctx,1,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[17]); /*rad2deg*/
	local[0]= w;
BLK3932:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___readmacro(ctx,n,argv,env)
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
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3963;
	local[0]= fqv[20];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[21],w);
	goto IF3964;
IF3963:
	local[0]= fqv[22];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3964:
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[24],module,F3371read_backquote,fqv[25]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[26],module,F3374conv_bq,fqv[27]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[28],module,F3377conscons,fqv[29]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[30],module,F3380read_comma,fqv[31]);
	local[0]= makeint((eusinteger_t)44L);
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint((eusinteger_t)96L);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[32],module,F3385read_binary,fqv[33]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[34],module,F3388read_bit_vector,fqv[35]);
	local[0]= makeint((eusinteger_t)35L);
	local[1]= makeint((eusinteger_t)66L);
	local[2]= fqv[32];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint((eusinteger_t)35L);
	local[1]= makeint((eusinteger_t)42L);
	local[2]= fqv[34];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= makeint((eusinteger_t)35L);
	local[1]= makeint((eusinteger_t)33L);
	local[2]= makeint((eusinteger_t)59L);
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[36]); /*get-macro-character*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[37],module,F3394read_pathname,fqv[38]);
	local[0]= makeint((eusinteger_t)35L);
	local[1]= makeint((eusinteger_t)80L);
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[39],module,F3398read_radian,fqv[40]);
	local[0]= makeint((eusinteger_t)35L);
	local[1]= makeint((eusinteger_t)68L);
	local[2]= fqv[39];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F3402read_degree,fqv[42]);
	local[0]= makeint((eusinteger_t)35L);
	local[1]= makeint((eusinteger_t)82L);
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
