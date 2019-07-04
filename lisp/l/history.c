/* ./history.c :  entry=history */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "history.h"
#pragma init (register_history)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___history();
extern pointer build_quote_vector();
static int register_history()
  { add_module_initializer("___history", ___history);}

static pointer F75220refresh_line();
static pointer F75222line_head();
static pointer F75224line_left();
static pointer F75226line_right();
static pointer F75228line_delch();
static pointer F75230line_delch_previous();
static pointer F75232line_tail();
static pointer F75234line_refresh();
static pointer F75236line_insert();
static pointer F75238line_clear();
static pointer F75240line_null();
static pointer F75242line_abort();
static pointer F75244line_end();
static pointer F75248line_edit();
static pointer F75250new_history();
static pointer F75252add_history();
static pointer F75254print_history();
static pointer F75256h();
static pointer F75258get_history();
static pointer F75260_();

/*refresh-line*/
static pointer F75220refresh_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+0;
	w=(*ftab[1])(ctx,0,local+0,&ftab[1],fqv[1]); /*erase-eol*/
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
WHL75351:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX75352;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ELT(ctx,2,local+2); /*elt*/
	local[2]= w;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)WRTBYTE(ctx,2,local+2); /*write-byte*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL75351;
WHX75352:
	local[2]= NIL;
BLK75353:
	w = NIL;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= w;
BLK75300:
	ctx->vsp=local; return(local[0]);}

/*line-head*/
static pointer F75222line_head(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint((eusinteger_t)0L);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75391:
	ctx->vsp=local; return(local[0]);}

/*line-left*/
static pointer F75224line_left(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF75431;
	ctx->vsp=local+0;
	w=(*ftab[2])(ctx,0,local+0,&ftab[2],fqv[3]); /*cursor-backward*/
	local[0]= w;
	goto IF75432;
IF75431:
	local[0]= NIL;
IF75432:
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	local[1]= w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75415:
	ctx->vsp=local; return(local[0]);}

/*line-right*/
static pointer F75226line_right(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF75468;
	ctx->vsp=local+0;
	w=(*ftab[3])(ctx,0,local+0,&ftab[3],fqv[4]); /*cursor-forward*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF75469;
IF75468:
	local[0]= NIL;
IF75469:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75451:
	ctx->vsp=local; return(local[0]);}

/*line-delch*/
static pointer F75228line_delch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF75515;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[5]); /*list-delete*/
	argv[1] = w;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F75220refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= w;
	goto IF75516;
IF75515:
	local[0]= NIL;
IF75516:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75498:
	ctx->vsp=local; return(local[0]);}

/*line-delch-previous*/
static pointer F75230line_delch_previous(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF75575;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[2] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[5]); /*list-delete*/
	argv[1] = w;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F75220refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= w;
	goto IF75576;
IF75575:
	local[0]= NIL;
IF75576:
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75558:
	ctx->vsp=local; return(local[0]);}

/*line-tail*/
static pointer F75232line_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= argv[3];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75626:
	ctx->vsp=local; return(local[0]);}

/*line-refresh*/
static pointer F75234line_refresh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F75220refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	local[0]= argv[1];
	local[1]= argv[3];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75652:
	ctx->vsp=local; return(local[0]);}

/*line-insert*/
static pointer F75236line_insert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,3,local+0,&ftab[5],fqv[6]); /*list-insert*/
	argv[1] = w;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[3] = w;
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)F75220refresh_line(ctx,3,local+0); /*refresh-line*/
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[2] = w;
	ctx->vsp=local+0;
	w=(*ftab[3])(ctx,0,local+0,&ftab[3],fqv[4]); /*cursor-forward*/
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75683:
	ctx->vsp=local; return(local[0]);}

/*line-clear*/
static pointer F75238line_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint((eusinteger_t)0L);
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+0;
	w=(*ftab[1])(ctx,0,local+0,&ftab[1],fqv[1]); /*erase-eol*/
	local[0]= fqv[7];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75746:
	ctx->vsp=local; return(local[0]);}

/*line-null*/
static pointer F75240line_null(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[1];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
BLK75773:
	ctx->vsp=local; return(local[0]);}

/*line-abort*/
static pointer F75242line_abort(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	w = NIL;
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[0];
	local[0]= w;
BLK75795:
	ctx->vsp=local; return(local[0]);}

/*line-end*/
static pointer F75244line_end(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= fqv[8];
	w = argv[1];
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[0];
	local[0]= w;
BLK75817:
	ctx->vsp=local; return(local[0]);}

/*line-edit*/
static pointer F75248line_edit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)COERCE(ctx,2,local+0); /*coerce*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[3];
	local[5]= NIL;
	local[6]= T;
	local[7]= fqv[10];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,0,local+6,&ftab[6],fqv[11]); /*tty-raw*/
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[0]); /*cursor-pos*/
	ctx->vsp=local+6;
	w=(pointer)FINOUT(ctx,0,local+6); /*finish-output*/
	ctx->vsp=local+6;
	w=(pointer)READCH(ctx,0,local+6); /*read-char*/
	local[2] = w;
	{jmp_buf jb;
	w = fqv[8];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT75921;}
WHL75928:
	if (T==NIL) goto WHX75929;
	local[12]= loadglobal(fqv[12]);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[2];
	local[14]= local[0];
	local[15]= local[4];
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)FUNCALL(ctx,5,local+12); /*funcall*/
	local[1] = w;
	local[12]= loadglobal(fqv[2]);
	ctx->vsp=local+13;
	w=(pointer)FINOUT(ctx,1,local+12); /*finish-output*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)READCH(ctx,0,local+12); /*read-char*/
	local[2] = w;
	goto WHL75928;
WHX75929:
	local[12]= NIL;
BLK75930:
	w = local[12];
CAT75921:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[1] = w;
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,0,local+6,&ftab[7],fqv[13]); /*tty-cooked*/
	if (local[1]==NIL) goto IF76003;
	local[6]= local[0];
	local[7]= loadglobal(fqv[14]);
	ctx->vsp=local+8;
	w=(pointer)COERCE(ctx,2,local+6); /*coerce*/
	local[6]= w;
	goto IF76004;
IF76003:
	local[6]= NIL;
IF76004:
	w = local[6];
	local[0]= w;
BLK75859:
	ctx->vsp=local; return(local[0]);}

/*new-history*/
static pointer F75250new_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[8])(ctx,1,local+0,&ftab[8],fqv[15]); /*make-array*/
	local[0]= w;
	storeglobal(fqv[16],w);
	local[0]= argv[0];
	storeglobal(fqv[17],local[0]);
	local[0]= makeint((eusinteger_t)0L);
	storeglobal(fqv[18],local[0]);
	local[0]= loadglobal(fqv[16]);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= loadglobal(fqv[19]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= w;
BLK76020:
	ctx->vsp=local; return(local[0]);}

/*add-history*/
static pointer F75252add_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[19]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	storeglobal(fqv[19],w);
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	storeglobal(fqv[18],w);
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[17]);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF76091;
	local[0]= loadglobal(fqv[17]);
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	storeglobal(fqv[18],w);
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[16]);
	local[2]= fqv[20];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= fqv[21];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,6,local+0,&ftab[9],fqv[22]); /*replace*/
	local[0]= w;
	goto IF76092;
IF76091:
	local[0]= NIL;
IF76092:
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= loadglobal(fqv[19]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto IF76130;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[25]); /*find-method*/
	if (w==NIL) goto IF76130;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF76131;
IF76130:
	local[0]= NIL;
IF76131:
	w = loadglobal(fqv[16]);
	local[0]= w;
BLK76062:
	ctx->vsp=local; return(local[0]);}

/*print-history*/
static pointer F75254print_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT76161;}
	local[0]= loadglobal(fqv[2]);
ENT76161:
ENT76160:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= loadglobal(fqv[18]);
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
WHL76203:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX76204;
	local[5]= loadglobal(fqv[16]);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[2] = w;
	w = local[2];
	if (!iscons(w)) goto IF76222;
	local[5]= local[0];
	local[6]= fqv[26];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	goto IF76223;
IF76222:
	local[5]= NIL;
IF76223:
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL76203;
WHX76204:
	local[5]= NIL;
BLK76205:
	w = NIL;
	local[0]= w;
BLK76158:
	ctx->vsp=local; return(local[0]);}

/*h*/
static pointer F75256h(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)F75254print_history(ctx,0,local+0); /*print-history*/
	local[0]= w;
BLK76257:
	ctx->vsp=local; return(local[0]);}

/*get-history*/
static pointer F75258get_history(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF76278;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	if (w==NIL) goto IF76284;
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= argv[0];
	local[3]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,3,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF76285;
IF76284:
	local[0]= loadglobal(fqv[16]);
	local[1]= loadglobal(fqv[18]);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[0];
	local[4]= loadglobal(fqv[16]);
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,3,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MIN(ctx,2,local+1); /*min*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF76285:
	goto IF76279;
IF76278:
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[14]); /*string*/
	local[1]= w;
	local[2]= NIL;
TAG76361:
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)LSEQP(ctx,2,local+3); /*<=*/
	if (w==NIL) goto IF76366;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK76333;
	goto IF76367;
IF76366:
	local[3]= NIL;
IF76367:
	local[3]= local[1];
	local[4]= loadglobal(fqv[16]);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,1,local+4,&ftab[11],fqv[14]); /*string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,2,local+3,&ftab[12],fqv[27]); /*substringp*/
	if (w==NIL) goto IF76380;
	w = local[2];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK76268;
	goto IF76381;
IF76380:
	local[3]= NIL;
IF76381:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[3]= w;
	local[0] = local[3];
	w = NIL;
	ctx->vsp=local+3;
	goto TAG76361;
	w = NIL;
	local[0]= w;
BLK76333:
IF76279:
	w = local[0];
	local[0]= w;
BLK76268:
	ctx->vsp=local; return(local[0]);}

/*!*/
static pointer F75260_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT76444;}
	local[0]= makeint((eusinteger_t)0L);
ENT76444:
ENT76443:
	if (n>1) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F75258get_history(ctx,1,local+1); /*get-history*/
	local[1]= w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F75248line_edit(ctx,1,local+2); /*line-edit*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TERPRI(ctx,0,local+3); /*terpri*/
	if (local[2]==NIL) goto CON76477;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F75252add_history(ctx,1,local+3); /*add-history*/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,1,local+3,&ftab[13],fqv[28]); /*make-string-input-stream*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[14])(ctx,1,local+3,&ftab[14],fqv[29]); /*evaluate-stream*/
	local[3]= w;
	goto CON76475;
CON76477:
	local[3]= NIL;
	goto CON76475;
CON76493:
	local[3]= NIL;
CON76475:
	w = local[3];
	local[0]= w;
BLK76441:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___history(ctx,n,argv,env)
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
	local[0]= fqv[30];
	local[1]= fqv[31];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[32]); /*require*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[12];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76517;
	local[0]= fqv[12];
	local[1]= fqv[34];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[12];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76540;
	local[0]= fqv[12];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)128L);
	ctx->vsp=local+3;
	w=(*ftab[8])(ctx,1,local+2,&ftab[8],fqv[15]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76541;
IF76540:
	local[0]= NIL;
IF76541:
	local[0]= fqv[12];
	goto IF76518;
IF76517:
	local[0]= NIL;
IF76518:
	ctx->vsp=local+0;
	compfun(ctx,fqv[36],module,F75220refresh_line,fqv[37]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[38],module,F75222line_head,fqv[39]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[40],module,F75224line_left,fqv[41]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[42],module,F75226line_right,fqv[43]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[44],module,F75228line_delch,fqv[45]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[46],module,F75230line_delch_previous,fqv[47]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[48],module,F75232line_tail,fqv[49]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[50],module,F75234line_refresh,fqv[51]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[52],module,F75236line_insert,fqv[53]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[54],module,F75238line_clear,fqv[55]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[56],module,F75240line_null,fqv[57]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[58],module,F75242line_abort,fqv[59]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[60],module,F75244line_end,fqv[61]);
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)128L);
WHL76608:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX76609;
	local[2]= loadglobal(fqv[12]);
	local[3]= local[0];
	local[4]= fqv[52];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL76608;
WHX76609:
	local[2]= NIL;
BLK76610:
	w = NIL;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)32L);
WHL76658:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX76659;
	local[2]= loadglobal(fqv[12]);
	local[3]= local[0];
	local[4]= fqv[56];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL76658;
WHX76659:
	local[2]= NIL;
BLK76660:
	w = NIL;
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)1L);
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)2L);
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)3L);
	local[2]= fqv[58];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)4L);
	local[2]= fqv[44];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)6L);
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)7L);
	local[2]= fqv[50];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)8L);
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)10L);
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)11L);
	local[2]= fqv[42];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)12L);
	local[2]= fqv[48];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)13L);
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)18L);
	local[2]= fqv[50];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)21L);
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	local[0]= loadglobal(fqv[12]);
	local[1]= makeint((eusinteger_t)127L);
	local[2]= fqv[46];
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[8],module,F75248line_edit,fqv[62]);
	local[0]= fqv[17];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76788;
	local[0]= fqv[17];
	local[1]= fqv[34];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[17];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76811;
	local[0]= fqv[17];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)50L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76812;
IF76811:
	local[0]= NIL;
IF76812:
	local[0]= fqv[17];
	goto IF76789;
IF76788:
	local[0]= NIL;
IF76789:
	local[0]= fqv[16];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76831;
	local[0]= fqv[16];
	local[1]= fqv[34];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76854;
	local[0]= fqv[16];
	local[1]= fqv[35];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76855;
IF76854:
	local[0]= NIL;
IF76855:
	local[0]= fqv[16];
	goto IF76832;
IF76831:
	local[0]= NIL;
IF76832:
	local[0]= fqv[18];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76874;
	local[0]= fqv[18];
	local[1]= fqv[34];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[18];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76897;
	local[0]= fqv[18];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76898;
IF76897:
	local[0]= NIL;
IF76898:
	local[0]= fqv[18];
	goto IF76875;
IF76874:
	local[0]= NIL;
IF76875:
	local[0]= fqv[19];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF76917;
	local[0]= fqv[19];
	local[1]= fqv[34];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[19];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF76940;
	local[0]= fqv[19];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF76941;
IF76940:
	local[0]= NIL;
IF76941:
	local[0]= fqv[19];
	goto IF76918;
IF76917:
	local[0]= NIL;
IF76918:
	ctx->vsp=local+0;
	compfun(ctx,fqv[63],module,F75250new_history,fqv[64]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[65],module,F75252add_history,fqv[66]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F75254print_history,fqv[68]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F75256h,fqv[70]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F75258get_history,fqv[72]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[73],module,F75260_,fqv[74]);
	local[0]= fqv[75];
	local[1]= fqv[76];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[77]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<17; i++) ftab[i]=fcallx;
}
