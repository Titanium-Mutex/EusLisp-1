/* ./eusdebug.c :  entry=eusdebug */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "eusdebug.h"
#pragma init (register_eusdebug)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___eusdebug();
extern pointer build_quote_vector();
static int register_eusdebug()
  { add_module_initializer("___eusdebug", ___eusdebug);}

static pointer F34686warning_message();
static pointer F34690warn();
static pointer F34693describe();
static pointer F34696describe_list();
static pointer F34700apropos();
static pointer F34703apropos_list();
static pointer F34707dump_string();
static pointer F34711break();
static pointer F34714setbreak();
static pointer F34717unbreak();
static pointer F34721btrace();
static pointer F34725eval_dynamic();
static pointer F34728step_hook();
static pointer F34733tracex();
static pointer F34736trace1();
static pointer F34742inspect1();
static pointer F34745time_func();
static pointer F34747list_symbols();
static pointer F34749functions();
static pointer F34751special_variables();
static pointer F34753global_variables();
static pointer F34755variables();
static pointer F34757constants();
static pointer F34759methods();
static pointer F34761method_list();
static pointer F34763y_or_n_p();
static pointer F34765yes_or_no_p();
static pointer F34767bell();
static pointer F34769check_methods();
static pointer F34771pfuncs();
static pointer F34773class_hierarchy();
static pointer F34775classdef();
static pointer F34777classdefs();
static pointer F34779remote_error();
static pointer F34781reval();
static pointer F34783install_remote_function();
static pointer F34785open_server();

/*assert*/
static pointer F34845(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT34849;}
	local[0]= fqv[0];
ENT34849:
ENT34848:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-2);
	local[2]= fqv[1];
	local[3]= fqv[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[3];
	local[5]= fqv[4];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= NIL;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[5];
	local[6]= fqv[4];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[6];
	local[7]= fqv[7];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK34846:
	ctx->vsp=local; return(local[0]);}

/*warning-message*/
static pointer F34686warning_message(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST34923:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[8];
	local[3]= makeint((eusinteger_t)27L);
	local[4]= argv[0];
	local[5]= makeint((eusinteger_t)48L);
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= (pointer)get_sym_func(fqv[3]);
	local[2]= loadglobal(fqv[4]);
	local[3]= argv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[9];
	local[3]= makeint((eusinteger_t)27L);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK34921:
	ctx->vsp=local; return(local[0]);}

/*warn*/
static pointer F34690warn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST34967:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[3]);
	local[2]= loadglobal(fqv[4]);
	local[3]= argv[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	if (loadglobal(fqv[10])==NIL) goto IF34990;
	local[1]= fqv[11];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[6]); /*reploop*/
	local[1]= w;
	goto IF34991;
IF34990:
	local[1]= NIL;
IF34991:
	w = local[1];
	local[0]= w;
BLK34965:
	ctx->vsp=local; return(local[0]);}

/*describe*/
static pointer F34693describe(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35007;}
	local[0]= loadglobal(fqv[12]);
ENT35007:
	if (n>=3) { local[1]=(argv[2]); goto ENT35006;}
	local[1]= NIL;
ENT35006:
	w = local[1];
	ctx->vsp=local+1;
	bindspecial(ctx,fqv[13],w);
	if (n>=4) { local[4]=(argv[3]); goto ENT35005;}
	local[4]= NIL;
ENT35005:
	w = local[4];
	ctx->vsp=local+4;
	bindspecial(ctx,fqv[14],w);
ENT35004:
	if (n>4) maerror();
	w = argv[0];
	if (!isnum(w)) goto IF35034;
	local[7]= argv[0];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,2,local+7); /*print*/
	w = NIL;
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK35002;
	goto IF35035;
IF35034:
	local[7]= NIL;
IF35035:
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= NIL;
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	local[8] = local[7]->c.obj.iv[4];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[9] = w;
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)VECTORP(ctx,1,local+11); /*vectorp*/
	if (w==NIL) goto IF35092;
	local[11]= argv[0];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,2,local+11,&ftab[1],fqv[15]); /*pprint*/
	local[11]= w;
	goto IF35093;
IF35092:
	local[11]= makeint((eusinteger_t)0L);
	local[12]= local[9];
WHL35128:
	local[13]= local[11];
	w = local[12];
	if ((eusinteger_t)local[13] >= (eusinteger_t)w) goto WHX35129;
	local[13]= local[0];
	local[14]= fqv[16];
	local[15]= local[8];
	{ register eusinteger_t i=intval(local[11]);
	  w=(local[15]->c.vec.v[i]);}
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,3,local+13); /*format*/
	local[13]= local[8];
	{ register eusinteger_t i=intval(local[11]);
	  w=(local[13]->c.vec.v[i]);}
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRNTSIZE(ctx,1,local+13); /*print-size*/
	local[10] = w;
	local[13]= local[10];
	local[14]= makeint((eusinteger_t)20L);
	ctx->vsp=local+15;
	w=(pointer)GREATERP(ctx,2,local+13); /*>*/
	if (w==NIL) goto IF35160;
	local[10] = makeint((eusinteger_t)5L);
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)TERPRI(ctx,1,local+13); /*terpri*/
	local[13]= w;
	goto IF35161;
IF35160:
	local[13]= NIL;
IF35161:
	if (loadglobal(fqv[13])==NIL) goto IF35179;
	local[13]= argv[0];
	local[14]= local[7];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SLOT(ctx,3,local+13); /*slot*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PRINT(ctx,1,local+13); /*print*/
	local[13]= w;
	goto IF35180;
IF35179:
	local[13]= argv[0];
	local[14]= local[7];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SLOT(ctx,3,local+13); /*slot*/
	local[13]= w;
	local[14]= local[0];
	local[15]= local[10];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[15]= w;
	local[16]= makeint((eusinteger_t)78L);
	ctx->vsp=local+17;
	w=(*ftab[1])(ctx,4,local+13,&ftab[1],fqv[15]); /*pprint*/
	local[13]= w;
IF35180:
	local[13]= local[11];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[11] = w;
	goto WHL35128;
WHX35129:
	local[13]= NIL;
BLK35130:
	w = NIL;
	local[11]= w;
IF35093:
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)FINOUT(ctx,1,local+11); /*finish-output*/
	local[7]= w;
	ctx->vsp=local+8;
	unbindx(ctx,2);
	w = local[7];
	local[0]= w;
BLK35002:
	ctx->vsp=local; return(local[0]);}

/*describe-list*/
static pointer F34696describe_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35225;}
	local[0]= loadglobal(fqv[12]);
ENT35225:
ENT35224:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET35253,env,argv,local);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w!=NIL) goto IF35257;
	local[3]= local[0];
	local[4]= fqv[17];
	local[5]= fqv[18];
	local[6]= fqv[19];
	local[7]= fqv[20];
	local[8]= fqv[21];
	local[9]= fqv[22];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,7,local+3,&ftab[2],fqv[23]); /*open*/
	local[1] = w;
	local[3]= local[1];
	goto IF35258;
IF35257:
	local[3]= NIL;
IF35258:
	local[3]= argv[0];
	w = local[2];
	ctx->vsp=local+4;
	w=FLET35253(ctx,1,local+3,w);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w!=NIL) goto IF35293;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)CLOSE(ctx,1,local+3); /*close*/
	local[3]= w;
	goto IF35294;
IF35293:
	local[3]= NIL;
IF35294:
	w = local[3];
	local[0]= w;
BLK35222:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET35253(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON35317;
	local[0]= NIL;
	local[1]= argv[0];
WHL35342:
	if (local[1]==NIL) goto WHX35343;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	w = env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=FLET35253(ctx,1,local+2,w);
	goto WHL35342;
WHX35343:
	local[2]= NIL;
BLK35344:
	w = NIL;
	local[0]= w;
	goto CON35315;
CON35317:
	local[0]= env->c.clo.env2[1];
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)F34693describe(ctx,2,local+0); /*describe*/
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)TERPRI(ctx,1,local+0); /*terpri*/
	local[0]= w;
	goto CON35315;
CON35398:
	local[0]= NIL;
CON35315:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*apropos*/
static pointer F34700apropos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35425;}
	local[0]= NIL;
ENT35425:
ENT35424:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	argv[0] = w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET35451,env,argv,local);
	if (local[0]==NIL) goto CON35457;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FINDPACKAGE(ctx,1,local+3); /*find-package*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= *(ovafptr(local[3],fqv[26]));
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL35493:
	local[7]= local[4];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto WHX35494;
	local[7]= local[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[2] = w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[4] = w;
	w = local[2];
	if (!issymbol(w)) goto IF35523;
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[25]); /*string*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF35533;
	local[7]= local[2];
	w = local[1];
	ctx->vsp=local+8;
	w=FLET35451(ctx,1,local+7,w);
	local[7]= w;
	goto IF35534;
IF35533:
	local[7]= NIL;
IF35534:
	goto IF35524;
IF35523:
	local[7]= NIL;
IF35524:
	goto WHL35493;
WHX35494:
	local[7]= NIL;
BLK35495:
	w = NIL;
	local[2]= w;
	goto CON35455;
CON35457:
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
WHL35578:
	if (local[3]==NIL) goto WHX35579;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= *(ovafptr(local[5],fqv[26]));
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL35657:
	local[9]= local[6];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX35658;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[4] = w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[6] = w;
	w = local[4];
	if (!issymbol(w)) goto IF35687;
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,1,local+10,&ftab[3],fqv[25]); /*string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF35697;
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	w=FLET35451(ctx,1,local+9,w);
	local[9]= w;
	goto IF35698;
IF35697:
	local[9]= NIL;
IF35698:
	goto IF35688;
IF35687:
	local[9]= NIL;
IF35688:
	goto WHL35657;
WHX35658:
	local[9]= NIL;
BLK35659:
	w = NIL;
	goto WHL35578;
WHX35579:
	local[4]= NIL;
BLK35580:
	w = NIL;
	local[2]= w;
	goto CON35455;
CON35555:
	local[2]= NIL;
CON35455:
	w = NIL;
	local[0]= w;
BLK35422:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET35451(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)FBOUNDP(ctx,1,local+3); /*fboundp*/
	if (w==NIL) goto IF35736;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[5])(ctx,1,local+3,&ftab[5],fqv[29]); /*special-form-p*/
	if (w==NIL) goto IF35744;
	local[3]= fqv[30];
	goto IF35745;
IF35744:
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[31]); /*macro-function*/
	if (w==NIL) goto IF35753;
	local[3]= fqv[32];
	goto IF35754;
IF35753:
	local[3]= fqv[33];
IF35754:
IF35745:
	goto IF35737;
IF35736:
	local[3]= fqv[34];
IF35737:
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)BOUNDP(ctx,1,local+4); /*boundp*/
	if (w==NIL) goto IF35762;
	local[4]= argv[0];
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[36]!=local[5]) goto IF35787;
	local[5]= fqv[37];
	goto IF35788;
IF35787:
	local[5]= local[4];
	if (fqv[38]!=local[5]) goto IF35795;
	local[5]= fqv[39];
	goto IF35796;
IF35795:
	local[5]= local[4];
	if (fqv[40]!=local[5]) goto IF35803;
	local[5]= fqv[41];
	goto IF35804;
IF35803:
	if (T==NIL) goto IF35811;
	local[5]= fqv[42];
	goto IF35812;
IF35811:
	local[5]= NIL;
IF35812:
IF35804:
IF35796:
IF35788:
	w = local[5];
	local[4]= w;
	goto IF35763;
IF35762:
	local[4]= fqv[43];
IF35763:
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)BOUNDP(ctx,1,local+5); /*boundp*/
	if (w==NIL) goto IF35817;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SYMBNDVALUE(ctx,1,local+5); /*symbol-bound-value*/
	local[5]= w;
	goto IF35818;
IF35817:
	local[5]= fqv[44];
IF35818:
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*apropos-list*/
static pointer F34703apropos_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT35834;}
	local[0]= NIL;
ENT35834:
ENT35833:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	argv[0] = w;
	if (local[0]==NIL) goto CON35868;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FINDPACKAGE(ctx,1,local+3); /*find-package*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= *(ovafptr(local[3],fqv[26]));
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
WHL35904:
	local[7]= local[4];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto WHX35905;
	local[7]= local[5];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[2] = w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[4] = w;
	w = local[2];
	if (!issymbol(w)) goto IF35934;
	local[7]= argv[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,1,local+8,&ftab[3],fqv[25]); /*string*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF35944;
	local[7]= local[2];
	w = local[1];
	ctx->vsp=local+8;
	local[1] = cons(ctx,local[7],w);
	local[7]= local[1];
	goto IF35945;
IF35944:
	local[7]= NIL;
IF35945:
	goto IF35935;
IF35934:
	local[7]= NIL;
IF35935:
	goto WHL35904;
WHX35905:
	local[7]= NIL;
BLK35906:
	w = NIL;
	local[2]= w;
	goto CON35866;
CON35868:
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
WHL35993:
	if (local[3]==NIL) goto WHX35994;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= *(ovafptr(local[5],fqv[26]));
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
WHL36072:
	local[9]= local[6];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX36073;
	local[9]= local[7];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[4] = w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)ADD1(ctx,1,local+9); /*1+*/
	local[6] = w;
	w = local[4];
	if (!issymbol(w)) goto IF36102;
	local[9]= argv[0];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,1,local+10,&ftab[3],fqv[25]); /*string*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[27]); /*substringp*/
	if (w==NIL) goto IF36112;
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
	goto IF36113;
IF36112:
	local[9]= NIL;
IF36113:
	goto IF36103;
IF36102:
	local[9]= NIL;
IF36103:
	goto WHL36072;
WHX36073:
	local[9]= NIL;
BLK36074:
	w = NIL;
	goto WHL35993;
WHX35994:
	local[4]= NIL;
BLK35995:
	w = NIL;
	local[2]= w;
	goto CON35866;
CON35970:
	local[2]= NIL;
CON35866:
	w = local[1];
	local[0]= w;
BLK35831:
	ctx->vsp=local; return(local[0]);}

/*dump-string*/
static pointer F34707dump_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT36154;}
	local[0]= loadglobal(fqv[12]);
ENT36154:
	if (n>=3) { local[1]=(argv[2]); goto ENT36153;}
	local[1]= fqv[45];
ENT36153:
	if (n>=4) { local[2]=(argv[3]); goto ENT36152;}
	local[2]= makeint((eusinteger_t)16L);
ENT36152:
ENT36151:
	if (n>4) maerror();
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[1];
	local[7]= fqv[46];
	local[8]= fqv[47];
	local[9]= (pointer)get_sym_func(fqv[48]);
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,4,local+6,&ftab[7],fqv[49]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
WHL36220:
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX36221;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MOD(ctx,2,local+6); /*mod*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF36229;
	local[6]= local[0];
	local[7]= fqv[50];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF36230;
IF36229:
	local[6]= NIL;
IF36230:
	local[6]= local[5];
	local[7]= local[6];
	if (fqv[51]!=local[7]) goto IF36256;
	local[7]= local[0];
	local[8]= fqv[52];
	local[9]= argv[0];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF36257;
IF36256:
	local[7]= local[6];
	if (fqv[53]!=local[7]) goto IF36271;
	local[7]= local[0];
	local[8]= fqv[54];
	local[9]= makeint((eusinteger_t)65535L);
	local[10]= argv[0];
	local[11]= local[3];
	local[12]= fqv[55];
	ctx->vsp=local+13;
	w=(pointer)PEEK(ctx,3,local+10); /*system:peek*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LOGAND(ctx,2,local+9); /*logand*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF36272;
IF36271:
	local[7]= local[6];
	if (fqv[56]!=local[7]) goto IF36293;
	local[7]= local[0];
	local[8]= fqv[57];
	local[9]= argv[0];
	local[10]= local[3];
	local[11]= fqv[58];
	ctx->vsp=local+12;
	w=(pointer)PEEK(ctx,3,local+9); /*system:peek*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= w;
	goto IF36294;
IF36293:
	local[7]= NIL;
IF36294:
IF36272:
IF36257:
	w = local[7];
	local[6]= local[3];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MOD(ctx,2,local+6); /*mod*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF36325;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)TERPRI(ctx,1,local+6); /*terpri*/
	local[6]= w;
	goto IF36326;
IF36325:
	local[6]= NIL;
IF36326:
	goto WHL36220;
WHX36221:
	local[6]= NIL;
BLK36222:
	w = local[6];
	local[0]= w;
BLK36149:
	ctx->vsp=local; return(local[0]);}

/*break*/
static pointer F34711break(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT36344;}
	local[0]= NIL;
	local[1]= fqv[59];
	local[2]= loadglobal(fqv[60]);
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
ENT36344:
ENT36343:
	if (n>1) maerror();
	local[1]= loadglobal(fqv[60]);
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	w = local[1];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[60],w);
	{jmp_buf jb;
	w = loadglobal(fqv[60]);
	ctx->vsp=local+5;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT36378;}
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[0])(ctx,1,local+11,&ftab[0],fqv[6]); /*reploop*/
CAT36378:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK36341:
	ctx->vsp=local; return(local[0]);}

/*setbreak*/
static pointer F34714setbreak(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w!=NIL) goto IF36402;
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF36403;
IF36402:
	local[0]= NIL;
IF36403:
	local[0]= argv[0];
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	if (w!=NIL) goto IF36417;
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[1]= w;
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= argv[0];
	local[1]= fqv[63];
	local[2]= fqv[64];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[66];
	local[4]= fqv[67];
	local[5]= fqv[68];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[69];
	local[8]= fqv[62];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[65];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[70];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	local[0]= argv[0];
	goto IF36418;
IF36417:
	local[0]= NIL;
IF36418:
	w = local[0];
	local[0]= w;
BLK36391:
	ctx->vsp=local; return(local[0]);}

/*unbreak*/
static pointer F34717unbreak(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[62];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	if (w==NIL) goto IF36524;
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SETFUNC(ctx,2,local+0); /*setfunc*/
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[62];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= w;
	goto IF36525;
IF36524:
	local[0]= NIL;
IF36525:
	w = local[0];
	local[0]= w;
BLK36513:
	ctx->vsp=local; return(local[0]);}

/*timing*/
static pointer F36557(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST36560:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[71];
	local[2]= fqv[72];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[73];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[74];
	local[5]= fqv[75];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[76];
	local[6]= fqv[77];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[78];
	local[7]= fqv[79];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[1];
	local[4]= fqv[80];
	local[5]= fqv[72];
	local[6]= fqv[81];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[82];
	local[6]= fqv[72];
	local[7]= fqv[83];
	local[8]= fqv[72];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[82];
	local[5]= fqv[78];
	local[6]= fqv[75];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[1];
	local[6]= fqv[80];
	local[7]= fqv[73];
	local[8]= fqv[84];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[82];
	local[8]= fqv[73];
	local[9]= fqv[83];
	local[10]= fqv[73];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[82];
	local[7]= fqv[76];
	local[8]= fqv[85];
	local[9]= fqv[75];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[78];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[3];
	local[8]= fqv[86];
	local[9]= fqv[87];
	local[10]= fqv[88];
	local[11]= fqv[89];
	local[12]= fqv[88];
	local[13]= fqv[90];
	local[14]= fqv[91];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[85];
	local[14]= fqv[78];
	local[15]= fqv[74];
	local[16]= fqv[76];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK36558:
	ctx->vsp=local; return(local[0]);}

/*btrace*/
static pointer F34721btrace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT36843;}
	local[0]= makeint((eusinteger_t)10L);
ENT36843:
ENT36842:
	if (n>1) maerror();
	local[1]= (pointer)get_sym_func(fqv[92]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)BKTRACE(ctx,1,local+2); /*system::bktrace*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)MAPC(ctx,2,local+1); /*mapc*/
	w = T;
	local[0]= w;
BLK36840:
	ctx->vsp=local; return(local[0]);}

/*eval-dynamic*/
static pointer F34725eval_dynamic(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT36875;}
	ctx->vsp=local+0;
	w=(pointer)LISTBINDINGS(ctx,0,local+0); /*system:list-all-bindings*/
	local[0]= w;
ENT36875:
ENT36874:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL36917:
	if (local[3]==NIL) goto WHX36918;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car!=local[4]) goto IF36966;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK36872;
	goto IF36967;
IF36966:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)VECTORP(ctx,1,local+4); /*vectorp*/
	if (w==NIL) goto IF36985;
	local[4]= argv[0];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,2,local+4,&ftab[8],fqv[93]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF36985;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)GETCLASS(ctx,1,local+5); /*class*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SLOT(ctx,3,local+4); /*slot*/
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK36872;
	goto IF36986;
IF36985:
	local[4]= NIL;
IF36986:
IF36967:
	goto WHL36917;
WHX36918:
	local[4]= NIL;
BLK36919:
	w = NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)BOUNDP(ctx,1,local+2); /*boundp*/
	if (w==NIL) goto IF37035;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= w;
	goto IF37036;
IF37035:
	local[2]= fqv[94];
IF37036:
	w = local[2];
	local[0]= w;
BLK36872:
	ctx->vsp=local; return(local[0]);}

/*step-hook*/
static pointer F34728step_hook(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= T;
	local[3]= makeint((eusinteger_t)10L);
	local[4]= makeint((eusinteger_t)5L);
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[13],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[14],w);
	local[11]= loadglobal(fqv[95]);
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[11]= w;
	storeglobal(fqv[95],w);
	local[11]= loadglobal(fqv[95]);
	ctx->vsp=local+12;
	w=(*ftab[9])(ctx,1,local+11,&ftab[9],fqv[96]); /*spaces*/
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)PRINT(ctx,1,local+11); /*print*/
WHL37110:
	if (local[2]==NIL) goto WHX37111;
	local[11]= T;
	local[12]= fqv[97];
	local[13]= loadglobal(fqv[95]);
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	ctx->vsp=local+11;
	w=(pointer)FINOUT(ctx,0,local+11); /*finish-output*/
	local[11]= loadglobal(fqv[98]);
	w = local[11];
	ctx->vsp=local+12;
	bindspecial(ctx,fqv[99],w);
	ctx->vsp=local+15;
	w=(pointer)READ(ctx,0,local+15); /*read*/
	local[15]= w;
	ctx->vsp=local+16;
	unbindx(ctx,1);
	w = local[15];
	local[0] = w;
	local[11]= local[0];
	local[12]= local[11];
	w = fqv[100];
	if (memq(local[12],w)==NIL) goto IF37162;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(*ftab[1])(ctx,1,local+12,&ftab[1],fqv[15]); /*pprint*/
	local[12]= w;
	goto IF37163;
IF37162:
	local[12]= local[11];
	w = fqv[101];
	if (memq(local[12],w)==NIL) goto IF37176;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto IF37177;
IF37176:
	local[12]= local[11];
	w = fqv[102];
	if (memq(local[12],w)==NIL) goto IF37190;
	local[12]= argv[0];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)EVAL(ctx,2,local+12); /*eval*/
	local[1] = w;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= T;
	local[13]= fqv[103];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,3,local+12); /*format*/
	local[2] = NIL;
	local[12]= local[2];
	goto IF37191;
IF37190:
	local[12]= local[11];
	w = fqv[104];
	if (memq(local[12],w)==NIL) goto IF37227;
	local[12]= argv[0];
	local[13]= (pointer)get_sym_func(fqv[66]);
	local[14]= argv[1];
	ctx->vsp=local+15;
	w=(pointer)EVALHOOK(ctx,3,local+12); /*evalhook*/
	local[1] = w;
	local[12]= T;
	local[13]= fqv[105];
	local[14]= argv[0];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,4,local+12); /*format*/
	local[2] = NIL;
	local[12]= local[2];
	goto IF37228;
IF37227:
	local[12]= local[11];
	w = fqv[106];
	if (memq(local[12],w)==NIL) goto IF37263;
	local[12]= fqv[107];
	w = fqv[108];
	ctx->vsp=local+13;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF37264;
IF37263:
	local[12]= local[11];
	w = fqv[109];
	if (memq(local[12],w)==NIL) goto IF37281;
	local[12]= T;
	local[13]= fqv[110];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[111];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[112];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[113];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= T;
	local[13]= fqv[114];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= w;
	goto IF37282;
IF37281:
	local[12]= local[11];
	if (fqv[115]!=local[12]) goto IF37309;
	ctx->vsp=local+12;
	w=(pointer)READ(ctx,0,local+12); /*read*/
	local[0] = w;
	w = local[0];
	if (!issymbol(w)) goto CON37330;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)F34725eval_dynamic(ctx,1,local+12); /*eval-dynamic*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto CON37328;
CON37330:
	{jmp_buf jb;
	w = fqv[116];
	ctx->vsp=local+12;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT37344;}
	local[18]= fqv[117];
	w = local[18];
	ctx->vsp=local+19;
	bindspecial(ctx,fqv[118],w);
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)EVAL(ctx,1,local+22); /*eval*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)PRINT(ctx,1,local+22); /*print*/
	local[22]= w;
	ctx->vsp=local+23;
	unbindx(ctx,1);
	w = local[22];
CAT37344:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[12]= w;
	goto CON37328;
CON37340:
	local[12]= NIL;
CON37328:
	goto IF37310;
IF37309:
	if (T==NIL) goto IF37373;
	local[12]= T;
	local[13]= fqv[119];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	local[12]= w;
	goto IF37374;
IF37373:
	local[12]= NIL;
IF37374:
IF37310:
IF37282:
IF37264:
IF37228:
IF37191:
IF37177:
IF37163:
	w = local[12];
	goto WHL37110;
WHX37111:
	local[11]= NIL;
BLK37112:
	local[11]= loadglobal(fqv[95]);
	ctx->vsp=local+12;
	w=(pointer)SUB1(ctx,1,local+11); /*1-*/
	local[11]= w;
	storeglobal(fqv[95],w);
	local[11]= local[1];
	ctx->vsp=local+12;
	unbindx(ctx,2);
	w = local[11];
	local[0]= w;
BLK37051:
	ctx->vsp=local; return(local[0]);}

/*step*/
static pointer F37395(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[120];
	local[1]= fqv[82];
	local[2]= fqv[95];
	local[3]= fqv[121];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[122];
	local[3]= fqv[69];
	local[4]= fqv[107];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[123];
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[124];
	local[7]= fqv[69];
	local[8]= fqv[66];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK37396:
	ctx->vsp=local; return(local[0]);}

/*tracex*/
static pointer F34733tracex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= loadglobal(fqv[95]);
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[95],w);
	local[6]= T;
	local[7]= fqv[125];
	local[8]= loadglobal(fqv[95]);
	local[9]= argv[0];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,5,local+6); /*format*/
	local[6]= argv[0];
	local[7]= fqv[126];
	ctx->vsp=local+8;
	w=(pointer)GETPROP(ctx,2,local+6); /*get*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[0] = w;
	local[6]= T;
	local[7]= fqv[127];
	local[8]= loadglobal(fqv[95]);
	local[9]= local[0];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,5,local+6); /*format*/
	local[6]= loadglobal(fqv[95]);
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	local[6]= w;
	if (w==NIL) goto AND37538;
	ctx->vsp=local+6;
	w=(pointer)TERPRI(ctx,0,local+6); /*terpri*/
	local[6]= w;
AND37538:
	local[6]= local[0];
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK37480:
	ctx->vsp=local; return(local[0]);}

/*trace1*/
static pointer F34736trace1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[128]); /*functionp*/
	if (w!=NIL) goto IF37574;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK37553;
	goto IF37575;
IF37574:
	local[1]= NIL;
IF37575:
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[126];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= argv[0];
	local[2]= fqv[63];
	local[3]= fqv[129];
	local[4]= fqv[130];
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[131];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SETFUNC(ctx,2,local+1); /*setfunc*/
	w = argv[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK37553;
	w = local[1];
	local[0]= w;
BLK37553:
	ctx->vsp=local; return(local[0]);}

/*trace*/
static pointer F37630(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST37633:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[132];
	local[2]= fqv[133];
	local[3]= fqv[69];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[134];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[135];
	local[4]= fqv[48];
	local[5]= fqv[133];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[136];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[137];
	local[6]= fqv[138];
	local[7]= fqv[133];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[139];
	local[7]= fqv[140];
	local[8]= fqv[133];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[86];
	local[7]= fqv[141];
	local[8]= fqv[133];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[142];
	local[9]= fqv[133];
	local[10]= fqv[134];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK37631:
	ctx->vsp=local; return(local[0]);}

/*untrace*/
static pointer F37764(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST37767:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	if (local[0]!=NIL) goto IF37777;
	local[0] = loadglobal(fqv[134]);
	local[1]= local[0];
	goto IF37778;
IF37777:
	local[1]= NIL;
IF37778:
	local[1]= fqv[132];
	local[2]= fqv[133];
	local[3]= fqv[69];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[134];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[135];
	local[4]= fqv[48];
	local[5]= fqv[133];
	local[6]= fqv[134];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[143];
	local[6]= fqv[124];
	local[7]= fqv[133];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[68];
	local[8]= fqv[133];
	local[9]= fqv[69];
	local[10]= fqv[126];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[82];
	local[7]= fqv[134];
	local[8]= fqv[144];
	local[9]= fqv[133];
	local[10]= fqv[134];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK37765:
	ctx->vsp=local; return(local[0]);}

/*inspect1*/
static pointer F34742inspect1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT37914;}
	local[0]= NIL;
ENT37914:
ENT37913:
	if (n>2) maerror();
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET37930,env,argv,local);
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	w=FLET37930(ctx,1,local+2,w);
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)GETCLASS(ctx,1,local+3); /*class*/
	local[3]= *(ovafptr(w,fqv[145]));
	local[4]= NIL;
TAG37962:
	if (NIL==NIL) goto IF37967;
	w = NIL;
	ctx->vsp=local+5;
	local[2]=w;
	goto BLK37936;
	goto IF37968;
IF37967:
	local[5]= NIL;
IF37968:
	w = local[2];
	if (!issymbol(w)) goto IF37988;
	local[5]= local[2]->c.obj.iv[4];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)0L));
	  w=makeint(local[5]->c.str.chars[i]);}
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CHUPCASE(ctx,1,local+5); /*char-upcase*/
	local[5]= w;
	goto IF37989;
IF37988:
	local[5]= local[2];
IF37989:
	local[6]= local[5];
	if (fqv[146]!=local[6]) goto IF38008;
	local[6]= argv[0];
	local[7]= loadglobal(fqv[147]);
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)3L);
	ctx->vsp=local+10;
	w=(pointer)F34693describe(ctx,4,local+6); /*describe*/
	local[6]= w;
	goto IF38009;
IF38008:
	local[6]= local[5];
	if (fqv[148]!=local[6]) goto IF38021;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[15]); /*pprint*/
	local[6]= w;
	goto IF38022;
IF38021:
	local[6]= local[5];
	if (fqv[149]!=local[6]) goto IF38032;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[2] = w;
	local[6]= loadglobal(fqv[25]);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[25]); /*string*/
	local[7]= w;
	local[8]= fqv[150];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,1,local+9,&ftab[3],fqv[25]); /*string*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)CONCATENATE(ctx,4,local+6); /*concatenate*/
	local[4] = w;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[151]); /*find*/
	if (w!=NIL) goto OR38069;
	w = local[2];
	if (!isint(w)) goto AND38078;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR38083;
	w = argv[0];
	if (iscons(w)) goto OR38083;
	goto AND38078;
OR38083:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto AND38078;
	goto OR38069;
AND38078:
	goto IF38067;
OR38069:
	w = local[2];
	if (!isint(w)) goto IF38101;
	local[6]= argv[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	goto IF38102;
IF38101:
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SLOT(ctx,3,local+6); /*slot*/
	local[6]= w;
IF38102:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F34742inspect1(ctx,2,local+6); /*inspect1*/
	local[6]= w;
	goto IF38068;
IF38067:
	local[6]= makeint((eusinteger_t)4L);
	local[7]= fqv[152];
	ctx->vsp=local+8;
	w=(pointer)F34686warning_message(ctx,2,local+6); /*warning-message*/
	local[6]= w;
IF38068:
	goto IF38033;
IF38032:
	local[6]= local[5];
	if (fqv[153]!=local[6]) goto IF38122;
	w = NIL;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK37911;
	goto IF38123;
IF38122:
	local[6]= local[5];
	if (fqv[154]!=local[6]) goto IF38133;
	local[6]= fqv[155];
	w = NIL;
	ctx->vsp=local+7;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF38134;
IF38133:
	local[6]= local[5];
	if (fqv[156]!=local[6]) goto IF38146;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[2] = w;
	ctx->vsp=local+6;
	w=(pointer)READ(ctx,0,local+6); /*read*/
	local[4] = w;
	w = local[2];
	if (!isint(w)) goto IF38169;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR38175;
	w = argv[0];
	if (iscons(w)) goto OR38175;
	goto IF38169;
OR38175:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto IF38169;
	local[6]= argv[0];
	local[7]= local[2];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SETELT(ctx,3,local+6); /*setelt*/
	local[6]= w;
	goto IF38170;
IF38169:
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[151]); /*find*/
	if (w==NIL) goto IF38198;
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SETSLOT(ctx,4,local+6); /*setslot*/
	local[6]= w;
	goto IF38199;
IF38198:
	local[6]= NIL;
IF38199:
IF38170:
	goto IF38147;
IF38146:
	local[6]= local[5];
	w = fqv[157];
	if (memq(local[6],w)==NIL) goto IF38216;
	local[6]= T;
	local[7]= fqv[158];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,2,local+6); /*format*/
	local[6]= w;
	goto IF38217;
IF38216:
	if (T==NIL) goto IF38229;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[151]); /*find*/
	if (w==NIL) goto CON38236;
	local[6]= argv[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)GETCLASS(ctx,1,local+7); /*class*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SLOT(ctx,3,local+6); /*slot*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F34693describe(ctx,1,local+6); /*describe*/
	local[6]= w;
	goto CON38234;
CON38236:
	w = local[2];
	if (!isint(w)) goto CON38253;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)ARRAYP(ctx,1,local+6); /*arrayp*/
	if (w!=NIL) goto OR38258;
	w = argv[0];
	if (iscons(w)) goto OR38258;
	goto CON38253;
OR38258:
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto CON38253;
	local[6]= argv[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PRINT(ctx,1,local+6); /*print*/
	local[6]= w;
	goto CON38234;
CON38253:
	{jmp_buf jb;
	w = fqv[159];
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT38285;}
	local[12]= fqv[160];
	w = local[12];
	ctx->vsp=local+13;
	bindspecial(ctx,fqv[118],w);
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)EVAL(ctx,1,local+16); /*eval*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)PRINT(ctx,1,local+16); /*print*/
	local[16]= w;
	ctx->vsp=local+17;
	unbindx(ctx,1);
	w = local[16];
CAT38285:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[6]= w;
	goto CON38234;
CON38281:
	local[6]= NIL;
CON38234:
	goto IF38230;
IF38229:
	local[6]= NIL;
IF38230:
IF38217:
IF38147:
IF38134:
IF38123:
IF38033:
IF38022:
IF38009:
	w = local[6];
	local[5]= local[0];
	w = local[1];
	ctx->vsp=local+6;
	w=FLET37930(ctx,1,local+5,w);
	local[2] = w;
	local[4] = NIL;
	ctx->vsp=local+5;
	goto TAG37962;
	w = NIL;
	local[2]= w;
BLK37936:
	w = local[2];
	local[0]= w;
BLK37911:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET37930(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[161];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= T;
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= loadglobal(fqv[162]);
	local[1]= NIL;
	local[2]= fqv[163];
	ctx->vsp=local+3;
	w=(pointer)READ(ctx,3,local+0); /*read*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*inspect*/
static pointer F38358(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[122];
	local[1]= fqv[69];
	local[2]= fqv[155];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[164];
	local[3]= argv[0];
	local[4]= fqv[3];
	local[5]= fqv[136];
	local[6]= fqv[165];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK38359:
	ctx->vsp=local; return(local[0]);}

/*time-func*/
static pointer F34745time_func(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[63];
	local[1]= fqv[64];
	local[2]= fqv[65];
	local[3]= fqv[166];
	local[4]= fqv[167];
	local[5]= fqv[168];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[169];
	local[3]= fqv[68];
	local[4]= fqv[69];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[170];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[82];
	local[4]= fqv[167];
	local[5]= fqv[171];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[168];
	local[7]= fqv[172];
	local[8]= fqv[68];
	local[9]= fqv[69];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[173];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[65];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[169];
	local[5]= fqv[68];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[174];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[85];
	local[7]= fqv[171];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[167];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[168];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK38422:
	ctx->vsp=local; return(local[0]);}

/*time*/
static pointer F38595(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT38599;}
	local[0]= NIL;
ENT38599:
ENT38598:
	if (n>2) maerror();
	local[1]= fqv[120];
	local[2]= fqv[135];
	local[3]= fqv[68];
	local[4]= fqv[69];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[173];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[175];
	local[5]= fqv[176];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[69];
	local[8]= fqv[177];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[69];
	local[9]= fqv[178];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[68];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[170];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[69];
	local[11]= fqv[179];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[69];
	local[12]= fqv[180];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[69];
	local[13]= fqv[181];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[89];
	local[14]= fqv[182];
	local[15]= fqv[68];
	local[16]= fqv[69];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[174];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[69];
	local[15]= fqv[183];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[184];
	local[7]= local[0];
	local[8]= fqv[143];
	local[9]= fqv[68];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[170];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[185];
	local[11]= fqv[68];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[174];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[186];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[187];
	local[5]= fqv[2];
	local[6]= fqv[138];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[31];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[188];
	local[6]= fqv[189];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[86];
	local[6]= fqv[71];
	local[7]= fqv[190];
	local[8]= fqv[124];
	local[9]= fqv[69];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	local[8]= fqv[143];
	local[9]= fqv[68];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[170];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[191];
	local[11]= fqv[68];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[174];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[192];
	local[13]= fqv[68];
	local[14]= fqv[69];
	local[15]= argv[0];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[173];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[190];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[193];
	local[10]= fqv[69];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[194];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[142];
	local[11]= fqv[69];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[195];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[176];
	local[12]= fqv[69];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[69];
	local[14]= fqv[177];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[69];
	local[15]= fqv[196];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	local[15]= fqv[69];
	local[16]= fqv[197];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK38596:
	ctx->vsp=local; return(local[0]);}

/*untime*/
static pointer F39133(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[120];
	local[1]= fqv[198];
	local[2]= fqv[68];
	local[3]= fqv[69];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[173];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[82];
	local[4]= fqv[195];
	local[5]= fqv[144];
	local[6]= fqv[69];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[195];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[193];
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[68];
	local[7]= fqv[69];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[173];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[69];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK39134:
	ctx->vsp=local; return(local[0]);}

/*list-symbols*/
static pointer F34747list_symbols(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[1];
WHL39293:
	if (local[2]==NIL) goto WHX39294;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)FINDPACKAGE(ctx,1,local+4); /*find-package*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= *(ovafptr(local[4],fqv[26]));
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
WHL39372:
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto WHX39373;
	local[8]= local[6];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[3] = w;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[5] = w;
	w = local[3];
	if (!issymbol(w)) goto IF39402;
	local[8]= argv[0];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	if (w==NIL) goto IF39411;
	local[8]= local[3];
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	local[8]= local[0];
	goto IF39412;
IF39411:
	local[8]= NIL;
IF39412:
	goto IF39403;
IF39402:
	local[8]= NIL;
IF39403:
	goto WHL39372;
WHX39373:
	local[8]= NIL;
BLK39374:
	w = NIL;
	goto WHL39293;
WHX39294:
	local[3]= NIL;
BLK39295:
	w = NIL;
	local[1]= local[0];
	local[2]= (pointer)get_sym_func(fqv[199]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,2,local+1); /*sort*/
	local[0]= w;
BLK39255:
	ctx->vsp=local; return(local[0]);}

/*functions*/
static pointer F34749functions(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39449;}
	local[0]= fqv[200];
ENT39449:
ENT39448:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39472,env,argv,local);
	if (local[1]==NIL) goto IF39475;
	local[3]= local[1];
	goto IF39476;
IF39475:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39476:
	ctx->vsp=local+4;
	w=(pointer)F34747list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39446:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39472(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND39495;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39495:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*special-variables*/
static pointer F34751special_variables(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39514;}
	local[0]= fqv[201];
ENT39514:
ENT39513:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39537,env,argv,local);
	if (local[1]==NIL) goto IF39540;
	local[3]= local[1];
	goto IF39541;
IF39540:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39541:
	ctx->vsp=local+4;
	w=(pointer)F34747list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39511:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39537(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39560;
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)3L);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
	if (w==NIL) goto AND39560;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39560:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*global-variables*/
static pointer F34753global_variables(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39588;}
	local[0]= fqv[202];
ENT39588:
ENT39587:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39611,env,argv,local);
	if (local[1]==NIL) goto IF39614;
	local[3]= local[1];
	goto IF39615;
IF39614:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39615:
	ctx->vsp=local+4;
	w=(pointer)F34747list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39585:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39611(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39634;
	local[0]= argv[0];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
	if (w==NIL) goto AND39634;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39634:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*variables*/
static pointer F34755variables(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39662;}
	local[0]= fqv[203];
ENT39662:
ENT39661:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[25]); /*string*/
	local[0] = w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39685,env,argv,local);
	if (local[1]==NIL) goto IF39688;
	local[3]= local[1];
	goto IF39689;
IF39688:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39689:
	ctx->vsp=local+4;
	w=(pointer)F34747list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39659:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39685(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND39708;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[204]); /*constantp*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]==NIL) goto AND39708;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39708:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*constants*/
static pointer F34757constants(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39735;}
	local[0]= fqv[205];
ENT39735:
ENT39734:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39749,env,argv,local);
	if (local[1]==NIL) goto IF39752;
	local[3]= local[1];
	goto IF39753;
IF39752:
	ctx->vsp=local+3;
	w=(pointer)ALLPACKAGES(ctx,0,local+3); /*list-all-packages*/
	local[3]= w;
IF39753:
	ctx->vsp=local+4;
	w=(pointer)F34747list_symbols(ctx,2,local+2); /*list-symbols*/
	local[0]= w;
BLK39732:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39749(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[12])(ctx,1,local+0,&ftab[12],fqv[204]); /*constantp*/
	local[0]= w;
	if (w==NIL) goto AND39772;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
AND39772:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*methods*/
static pointer F34759methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39792;}
	local[0]= fqv[206];
ENT39792:
	if (n>=2) { local[1]=(argv[1]); goto ENT39791;}
	local[1]= fqv[207];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	local[1]= w;
ENT39791:
ENT39790:
	if (n>2) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO39811,env,argv,local);
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO39815,env,argv,local);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F34747list_symbols(ctx,2,local+3); /*list-symbols*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[0]= w;
BLK39788:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39811(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[208];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
	local[2]= fqv[209];
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[210]); /*send-all*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO39815(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[25]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[27]); /*substringp*/
	local[0]= w;
	if (w==NIL) goto AND39857;
	local[0]= argv[0];
	local[1]= fqv[208];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
AND39857:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*method-list*/
static pointer F34761method_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT39878;}
	local[0]= T;
ENT39878:
	if (n>=2) { local[1]=(argv[1]); goto ENT39877;}
	local[1]= NIL;
ENT39877:
ENT39876:
	ctx->vsp=local+2;
	local[2]= minilist(ctx,&argv[n],n-2);
	if (local[2]!=NIL) goto IF39896;
	ctx->vsp=local+3;
	w=(pointer)LISTALLCLASSES(ctx,0,local+3); /*system:list-all-classes*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[2] = w;
	local[3]= local[2];
	goto IF39897;
IF39896:
	local[3]= NIL;
IF39897:
	local[3]= NIL;
	local[4]= local[2];
WHL39932:
	if (local[4]==NIL) goto WHX39933;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	local[8]= fqv[211];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,1,local+9,&ftab[14],fqv[212]); /*metaclass-name*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)XFORMAT(ctx,3,local+7); /*format*/
	local[7]= (pointer)get_sym_func(fqv[213]);
	local[8]= local[3]->c.obj.iv[7];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	local[6] = w;
	local[7]= NIL;
	local[8]= local[6];
	local[9]= (pointer)get_sym_func(fqv[199]);
	ctx->vsp=local+10;
	w=(pointer)SORT(ctx,2,local+8); /*sort*/
	local[8]= w;
WHL40038:
	if (local[8]==NIL) goto WHX40039;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[3];
	local[10]= local[7];
	local[11]= fqv[214];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[215]); /*documentation*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,2,local+9,&ftab[7],fqv[49]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	if (local[5]==NIL) goto IF40107;
	local[9]= local[5];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)40L);
	ctx->vsp=local+11;
	w=(pointer)EQUAL(ctx,2,local+9); /*equal*/
	if (w==NIL) goto IF40107;
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(*ftab[16])(ctx,1,local+9,&ftab[16],fqv[216]); /*read-from-string*/
	local[5] = w;
	w = local[5];
	if (!iscons(w)) goto IF40135;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (fqv[217]!=local[9]) goto IF40144;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[9];
	local[9]= w;
	goto IF40145;
IF40144:
	local[9]= NIL;
IF40145:
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (fqv[218]!=local[9]) goto IF40192;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[9];
	local[9]= w;
	goto IF40193;
IF40192:
	local[9]= NIL;
IF40193:
	goto IF40136;
IF40135:
	local[9]= NIL;
IF40136:
	goto IF40108;
IF40107:
	local[9]= NIL;
IF40108:
	local[9]= local[0];
	local[10]= fqv[219];
	local[11]= makeint((eusinteger_t)9L);
	local[12]= local[7];
	if (local[1]==NIL) goto IF40243;
	if (local[5]==NIL) goto IF40243;
	local[13]= local[5];
	goto IF40244;
IF40243:
	local[13]= fqv[220];
IF40244:
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,5,local+9); /*format*/
	goto WHL40038;
WHX40039:
	local[9]= NIL;
BLK40040:
	w = NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)TERPRI(ctx,1,local+7); /*terpri*/
	goto WHL39932;
WHX39933:
	local[5]= NIL;
BLK39934:
	w = NIL;
	local[0]= w;
BLK39874:
	ctx->vsp=local; return(local[0]);}

/*more*/
static pointer F40267(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= fqv[221];
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	local[1]= NIL;
	local[2]= fqv[222];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	local[2]= fqv[223];
	local[3]= fqv[120];
	local[4]= fqv[224];
	local[5]= fqv[12];
	local[6]= local[0];
	local[7]= fqv[17];
	local[8]= fqv[18];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[225];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[226];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK40268:
	ctx->vsp=local; return(local[0]);}

/*y-or-n-p*/
static pointer F34763y_or_n_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40360;}
	local[0]= NIL;
ENT40360:
ENT40359:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= NIL;
	local[3]= NIL;
TAG40377:
	if (local[0]==NIL) goto IF40383;
	local[4]= (pointer)get_sym_func(fqv[3]);
	local[5]= T;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto IF40384;
IF40383:
	local[4]= NIL;
IF40384:
	local[4]= T;
	local[5]= fqv[227];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)READLINE(ctx,1,local+4); /*read-line*/
	local[3] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	if (makeint((eusinteger_t)0L)!=local[4]) goto IF40413;
	ctx->vsp=local+4;
	goto TAG40377;
	goto IF40414;
IF40413:
	local[4]= NIL;
IF40414:
	local[4]= local[3];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHUPCASE(ctx,1,local+4); /*char-upcase*/
	local[4]= w;
	local[5]= local[4];
	if (fqv[228]!=local[5]) goto IF40441;
	w = T;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK40357;
	goto IF40442;
IF40441:
	local[5]= local[4];
	if (fqv[229]!=local[5]) goto IF40452;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK40357;
	goto IF40453;
IF40452:
	if (T==NIL) goto IF40463;
	ctx->vsp=local+5;
	goto TAG40377;
	goto IF40464;
IF40463:
	local[5]= NIL;
IF40464:
IF40453:
IF40442:
	w = local[5];
	w = NIL;
	local[0]= w;
BLK40357:
	ctx->vsp=local; return(local[0]);}

/*yes-or-no-p*/
static pointer F34765yes_or_no_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT40476;}
	local[0]= NIL;
ENT40476:
ENT40475:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-1);
	local[2]= NIL;
	local[3]= NIL;
TAG40493:
	if (local[0]==NIL) goto IF40499;
	local[4]= (pointer)get_sym_func(fqv[3]);
	local[5]= T;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,4,local+4); /*apply*/
	local[4]= w;
	goto IF40500;
IF40499:
	local[4]= NIL;
IF40500:
	local[4]= T;
	local[5]= fqv[230];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,2,local+4); /*format*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)READLINE(ctx,1,local+4); /*read-line*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[17])(ctx,1,local+4,&ftab[17],fqv[231]); /*string-upcase*/
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[232];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[233]); /*string=*/
	if (w==NIL) goto CON40534;
	w = T;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK40473;
	goto CON40532;
CON40534:
	local[4]= local[3];
	local[5]= fqv[234];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[233]); /*string=*/
	if (w==NIL) goto CON40545;
	w = NIL;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK40473;
	goto CON40532;
CON40545:
	ctx->vsp=local+4;
	goto TAG40493;
	goto CON40532;
CON40555:
	local[4]= NIL;
CON40532:
	w = NIL;
	local[0]= w;
BLK40473:
	ctx->vsp=local; return(local[0]);}

/*bell*/
static pointer F34767bell(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT40566;}
	local[0]= T;
ENT40566:
ENT40565:
	if (n>2) maerror();
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
WHL40603:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX40604;
	local[3]= local[0];
	local[4]= fqv[235];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,2,local+3); /*format*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL40603;
WHX40604:
	local[3]= NIL;
BLK40605:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,1,local+1); /*finish-output*/
	local[0]= w;
BLK40563:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M40644compiled_code_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= local[0];
	if (fqv[236]!=local[1]) goto IF40670;
	local[1]= fqv[237];
	goto IF40671;
IF40670:
	local[1]= local[0];
	if (fqv[238]!=local[1]) goto IF40680;
	local[1]= fqv[239];
	goto IF40681;
IF40680:
	local[1]= local[0];
	if (fqv[240]!=local[1]) goto IF40690;
	local[1]= fqv[241];
	goto IF40691;
IF40690:
	local[1]= local[0];
	if (fqv[242]!=local[1]) goto IF40700;
	local[1]= fqv[243];
	goto IF40701;
IF40700:
	local[1]= NIL;
IF40701:
IF40691:
IF40681:
IF40671:
	w = local[1];
	local[0]= w;
BLK40645:
	ctx->vsp=local; return(local[0]);}

/*check-methods*/
static pointer F34769check_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	ctx->vsp=local+0;
	w=(pointer)LISTALLCLASSES(ctx,0,local+0); /*system:list-all-classes*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[244]);
	local[2]= local[0];
	local[3]= fqv[245];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[210]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[246]);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[213]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(*ftab[19])(ctx,1,local+4,&ftab[19],fqv[247]); /*remove-duplicates*/
	local[4]= w;
	local[5]= T;
	local[6]= fqv[248];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	local[10]= (pointer)get_sym_func(fqv[249]);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[20])(ctx,2,local+10,&ftab[20],fqv[250]); /*count-if*/
	local[10]= w;
	local[11]= (pointer)get_sym_func(fqv[249]);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(*ftab[21])(ctx,2,local+11,&ftab[21],fqv[251]); /*count-if-not*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,7,local+5); /*format*/
	local[0]= w;
BLK40713:
	ctx->vsp=local; return(local[0]);}

/*pfuncs*/
static pointer F34771pfuncs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT40791;}
	ctx->vsp=local+0;
	w=(pointer)F34749functions(ctx,0,local+0); /*functions*/
	local[0]= w;
ENT40791:
	if (n>=3) { local[1]=(argv[2]); goto ENT40790;}
	local[1]= NIL;
ENT40790:
ENT40789:
	if (n>3) maerror();
	local[2]= argv[0];
	local[3]= fqv[17];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,3,local+2,&ftab[2],fqv[23]); /*open*/
	local[2]= w;
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP40829,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
WHL40862:
	if (local[7]==NIL) goto WHX40863;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)SYMFUNC(ctx,1,local+8); /*symbol-function*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(*ftab[22])(ctx,1,local+8,&ftab[22],fqv[249]); /*compiled-function-p*/
	if (w!=NIL) goto OR40914;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,1,local+8,&ftab[6],fqv[31]); /*macro-function*/
	if (w==NIL) goto OR40914;
	goto IF40912;
OR40914:
	local[8]= local[2];
	local[9]= fqv[252];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[23])(ctx,1,local+10,&ftab[23],fqv[253]); /*symbol-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,1,local+10,&ftab[24],fqv[254]); /*string-downcase*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= makeint((eusinteger_t)40L);
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)PRNTSIZE(ctx,1,local+9); /*print-size*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[9])(ctx,2,local+8,&ftab[9],fqv[96]); /*spaces*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[25])(ctx,1,local+8,&ftab[25],fqv[255]); /*symbol-package*/
	local[5] = w;
	local[8]= local[2];
	local[9]= fqv[256];
	local[10]= local[5];
	local[11]= fqv[257];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	if (w==NIL) goto IF40968;
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[26])(ctx,1,local+10,&ftab[26],fqv[258]); /*package-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[24])(ctx,1,local+10,&ftab[24],fqv[254]); /*string-downcase*/
	local[10]= w;
	goto IF40969;
IF40968:
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(*ftab[26])(ctx,1,local+10,&ftab[26],fqv[258]); /*package-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[17])(ctx,1,local+10,&ftab[17],fqv[231]); /*string-upcase*/
	local[10]= w;
IF40969:
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)SYMFUNC(ctx,1,local+11); /*symbol-function*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,1,local+11,&ftab[22],fqv[249]); /*compiled-function-p*/
	if (w==NIL) goto IF40990;
	local[11]= fqv[259];
	goto IF40991;
IF40990:
	local[11]= fqv[260];
IF40991:
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(*ftab[6])(ctx,1,local+12,&ftab[6],fqv[31]); /*macro-function*/
	if (w==NIL) goto IF41000;
	local[12]= fqv[261];
	goto IF41001;
IF41000:
	local[12]= fqv[262];
IF41001:
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,5,local+8); /*format*/
	if (local[1]==NIL) goto IF41010;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(*ftab[15])(ctx,1,local+8,&ftab[15],fqv[215]); /*documentation*/
	if (w==NIL) goto IF41010;
	local[8]= local[2];
	local[9]= fqv[263];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,1,local+10,&ftab[15],fqv[215]); /*documentation*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	goto IF41011;
IF41010:
	local[8]= NIL;
IF41011:
	goto IF40913;
IF40912:
	local[8]= NIL;
IF40913:
	goto WHL40862;
WHX40863:
	local[8]= NIL;
BLK40864:
	w = NIL;
	ctx->vsp=local+5;
	UWP40829(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK40787:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP40829(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[2];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*class-hierarchy*/
static pointer F34773class_hierarchy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT41051;}
	local[0]= loadglobal(fqv[264]);
ENT41051:
	if (n>=2) { local[1]=(argv[1]); goto ENT41050;}
	local[1]= T;
ENT41050:
	if (n>=3) { local[2]=(argv[2]); goto ENT41049;}
	local[2]= NIL;
ENT41049:
ENT41048:
	if (n>3) maerror();
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET41075,env,argv,local);
	local[4]= local[0];
	local[5]= fqv[265];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	w = local[3];
	ctx->vsp=local+6;
	w=FLET41075(ctx,2,local+4,w);
	local[0]= w;
BLK41046:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET41075(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[1]= argv[1];
	local[2]= env->c.clo.env2[1];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,2,local+1,&ftab[9],fqv[96]); /*spaces*/
	local[1]= env->c.clo.env2[1];
	local[2]= fqv[266];
	local[3]= local[0];
	local[4]= fqv[209];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[24])(ctx,1,local+3,&ftab[24],fqv[254]); /*string-downcase*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	if (env->c.clo.env2[2]==NIL) goto IF41143;
	local[1]= local[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[27])(ctx,1,local+2,&ftab[27],fqv[267]); /*metaclass-vars*/
	local[2]= w;
	local[3]= loadglobal(fqv[67]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	if (local[1]==NIL) goto IF41172;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[27])(ctx,1,local+3,&ftab[27],fqv[267]); /*metaclass-vars*/
	local[3]= w;
	local[4]= loadglobal(fqv[67]);
	ctx->vsp=local+5;
	w=(pointer)COERCE(ctx,2,local+3); /*coerce*/
	local[3]= w;
	goto IF41173;
IF41172:
	local[3]= NIL;
IF41173:
	local[4]= local[2];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[28])(ctx,2,local+4,&ftab[28],fqv[268]); /*set-difference*/
	local[2] = w;
	local[4]= (pointer)get_sym_func(fqv[254]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[2] = w;
	local[4]= env->c.clo.env2[1];
	local[5]= fqv[269];
	if (local[2]==NIL) goto IF41210;
	local[6]= local[2];
	goto IF41211;
IF41210:
	local[6]= fqv[270];
IF41211:
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[1]= w;
	goto IF41144;
IF41143:
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= w;
IF41144:
	w = local[1];
	local[0]= NIL;
	local[1]= argv[0];
WHL41241:
	if (local[1]==NIL) goto WHX41242;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[1];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	w = env->c.clo.env2[3];
	ctx->vsp=local+4;
	w=FLET41075(ctx,2,local+2,w);
	goto WHL41241;
WHX41242:
	local[2]= NIL;
BLK41243:
	w = NIL;
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*classdef*/
static pointer F34775classdef(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[271];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= fqv[272];
	local[4]= argv[0];
	local[5]= fqv[209];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[271];
	if (local[0]==NIL) goto IF41347;
	local[6]= local[0];
	local[7]= fqv[209];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF41348;
IF41347:
	local[6]= NIL;
IF41348:
	local[7]= fqv[273];
	local[8]= argv[0];
	local[9]= fqv[273];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	local[9]= loadglobal(fqv[67]);
	ctx->vsp=local+10;
	w=(pointer)COERCE(ctx,2,local+8); /*coerce*/
	local[8]= w;
	if (local[0]==NIL) goto IF41373;
	local[9]= local[0];
	local[10]= fqv[273];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	goto IF41374;
IF41373:
	local[9]= NIL;
IF41374:
	local[10]= loadglobal(fqv[67]);
	ctx->vsp=local+11;
	w=(pointer)COERCE(ctx,2,local+9); /*coerce*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,2,local+8,&ftab[28],fqv[268]); /*set-difference*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK41305:
	ctx->vsp=local; return(local[0]);}

/*classdefs*/
static pointer F34777classdefs(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT41404;}
	local[0]= loadglobal(fqv[264]);
ENT41404:
	if (n>=2) { local[1]=(argv[1]); goto ENT41403;}
	local[1]= T;
ENT41403:
ENT41402:
	if (n>2) maerror();
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F34775classdef(ctx,1,local+2); /*classdef*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,2,local+2,&ftab[1],fqv[15]); /*pprint*/
	local[2]= NIL;
	local[3]= local[0];
	local[4]= fqv[274];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL41449:
	if (local[3]==NIL) goto WHX41450;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)F34777classdefs(ctx,2,local+4); /*classdefs*/
	goto WHL41449;
WHX41450:
	local[4]= NIL;
BLK41451:
	w = NIL;
	local[0]= w;
BLK41400:
	ctx->vsp=local; return(local[0]);}

/*remote-error*/
static pointer F34779remote_error(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT41510;}
	local[0]= NIL;
ENT41510:
ENT41509:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[275];
	local[3]= loadglobal(fqv[276]);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	if (local[0]==NIL) goto IF41535;
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[277];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF41536;
IF41535:
	local[1]= NIL;
IF41536:
	if (argv[2]==NIL) goto IF41546;
	local[1]= loadglobal(fqv[4]);
	local[2]= fqv[278];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF41547;
IF41546:
	local[1]= NIL;
IF41547:
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= fqv[279];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK41507:
	ctx->vsp=local; return(local[0]);}

/*reval*/
static pointer F34781reval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[280];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[162],w);
	local[3]= argv[0];
	local[4]= fqv[281];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[12],w);
	local[6]= loadglobal(fqv[12]);
	w = local[6];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[4],w);
	local[9]= fqv[282];
	w = local[9];
	ctx->vsp=local+9;
	bindspecial(ctx,fqv[118],w);
	{jmp_buf jb;
	w = fqv[279];
	ctx->vsp=local+12;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT41608;}
	local[18]= argv[0];
	ctx->vsp=local+19;
	w=(pointer)READ(ctx,1,local+18); /*read*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)EVAL(ctx,1,local+18); /*eval*/
	local[18]= w;
	local[19]= argv[0];
	ctx->vsp=local+20;
	w=(pointer)PRINT(ctx,2,local+18); /*print*/
CAT41608:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[12]= w;
	ctx->vsp=local+13;
	unbindx(ctx,4);
	w = local[12];
	local[0]= w;
BLK41567:
	ctx->vsp=local; return(local[0]);}

/*install-remote-function*/
static pointer F34783install_remote_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= fqv[283];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= T;
	local[1]= fqv[284];
	local[2]= loadglobal(fqv[285]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[29])(ctx,1,local+0,&ftab[29],fqv[286]); /*make-server-socket-stream*/
	local[0]= w;
	local[1]= local[0];
	w = loadglobal(fqv[287]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[287],local[1]);
	local[1]= local[0];
	local[2]= loadglobal(fqv[288]);
	local[3]= fqv[47];
	local[4]= NIL;
	local[5]= fqv[289];
	local[6]= NIL;
	local[7]= fqv[290];
	local[8]= NIL;
	ctx->vsp=local+9;
	w=(*ftab[30])(ctx,8,local+1,&ftab[30],fqv[48]); /*member*/
	if (w!=NIL) goto IF41680;
	local[1]= local[0];
	w = loadglobal(fqv[288]);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	storeglobal(fqv[288],local[1]);
	goto IF41681;
IF41680:
	local[1]= NIL;
IF41681:
	local[1]= makeint((eusinteger_t)29L);
	local[2]= fqv[291];
	ctx->vsp=local+3;
	w=(pointer)SIGNAL(ctx,2,local+1); /*unix:signal*/
	w = local[0];
	if (!isint(w)) goto IF41714;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)4L);
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)3L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)8192L);
	ctx->vsp=local+5;
	w=(pointer)LOGIOR(ctx,2,local+3); /*logior*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FCNTL(ctx,3,local+1); /*unix:fcntl*/
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)8L);
	ctx->vsp=local+3;
	w=(pointer)GETPID(ctx,0,local+3); /*unix:getpid*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)FCNTL(ctx,3,local+1); /*unix:fcntl*/
	local[1]= w;
	goto IF41715;
IF41714:
	local[1]= local[0];
	local[2]= fqv[292];
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF41715:
	local[1]= loadglobal(fqv[293]);
	w = local[0];
	if (!isint(w)) goto IF41749;
	local[2]= local[0];
	goto IF41750;
IF41749:
	local[2]= local[0];
	local[3]= fqv[294];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
IF41750:
	local[3]= loadglobal(fqv[285]);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[0]= w;
BLK41627:
	ctx->vsp=local; return(local[0]);}

/*open-server*/
static pointer F34785open_server(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT41769;}
	local[0]= makeint((eusinteger_t)2048L);
ENT41769:
	if (n>=2) { local[1]=(argv[1]); goto ENT41768;}
	local[1]= (pointer)get_sym_func(fqv[279]);
ENT41768:
ENT41767:
	if (n>2) maerror();
	local[2]= fqv[295];
	local[3]= makeint((eusinteger_t)2L);
	local[4]= fqv[296];
	ctx->vsp=local+5;
	w=(pointer)GETHOSTNAME(ctx,0,local+5); /*unix:gethostname*/
	local[5]= w;
	local[6]= fqv[297];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[31])(ctx,6,local+2,&ftab[31],fqv[298]); /*make-socket-address*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[32])(ctx,1,local+3,&ftab[32],fqv[299]); /*make-socket-port*/
	local[3]= w;
	storeglobal(fqv[300],w);
	local[3]= loadglobal(fqv[300]);
	local[4]= loadglobal(fqv[301]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON41819;
	local[3]= fqv[302];
	ctx->vsp=local+4;
	w=(pointer)GETHOSTNAME(ctx,0,local+4); /*unix:gethostname*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F34690warn(ctx,3,local+3); /*warn*/
	local[3]= w;
	goto CON41817;
CON41819:
	local[3]= loadglobal(fqv[300]);
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SYSERRLIST(ctx,1,local+3); /*unix:syserrlist*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK41765;
	goto CON41817;
CON41833:
	local[3]= NIL;
CON41817:
	local[3]= local[1];
	storeglobal(fqv[285],local[3]);
	local[3]= loadglobal(fqv[300]);
	local[4]= loadglobal(fqv[288]);
	local[5]= fqv[47];
	local[6]= NIL;
	local[7]= fqv[289];
	local[8]= NIL;
	local[9]= fqv[290];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(*ftab[30])(ctx,8,local+3,&ftab[30],fqv[48]); /*member*/
	if (w!=NIL) goto IF41862;
	local[3]= loadglobal(fqv[300]);
	w = loadglobal(fqv[288]);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	storeglobal(fqv[288],local[3]);
	goto IF41863;
IF41862:
	local[3]= NIL;
IF41863:
	local[3]= makeint((eusinteger_t)29L);
	local[4]= fqv[291];
	ctx->vsp=local+5;
	w=(pointer)SIGNAL(ctx,2,local+3); /*unix:signal*/
	w = loadglobal(fqv[300]);
	if (!isint(w)) goto IF41894;
	local[3]= loadglobal(fqv[300]);
	local[4]= makeint((eusinteger_t)4L);
	local[5]= loadglobal(fqv[300]);
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)FCNTL(ctx,3,local+5); /*unix:fcntl*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)8192L);
	ctx->vsp=local+7;
	w=(pointer)LOGIOR(ctx,2,local+5); /*logior*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= loadglobal(fqv[300]);
	local[4]= makeint((eusinteger_t)8L);
	ctx->vsp=local+5;
	w=(pointer)GETPID(ctx,0,local+5); /*unix:getpid*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FCNTL(ctx,3,local+3); /*unix:fcntl*/
	local[3]= w;
	goto IF41895;
IF41894:
	local[3]= loadglobal(fqv[300]);
	local[4]= fqv[292];
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
IF41895:
	local[3]= loadglobal(fqv[293]);
	w = loadglobal(fqv[300]);
	if (!isint(w)) goto IF41928;
	local[4]= loadglobal(fqv[300]);
	goto IF41929;
IF41928:
	local[4]= loadglobal(fqv[300]);
	local[5]= fqv[294];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
IF41929:
	local[5]= fqv[303];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[0]= w;
BLK41765:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___eusdebug(ctx,n,argv,env)
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
	local[0]= fqv[304];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF41950;
	local[0]= fqv[305];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[99],w);
	goto IF41951;
IF41950:
	local[0]= fqv[306];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF41951:
	local[0]= fqv[307];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[308],module,F34845,fqv[309]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[310],module,F34686warning_message,fqv[311]);
	local[0]= fqv[10];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF41978;
	local[0]= fqv[10];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[10];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42001;
	local[0]= fqv[10];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42002;
IF42001:
	local[0]= NIL;
IF42002:
	local[0]= fqv[10];
	goto IF41979;
IF41978:
	local[0]= NIL;
IF41979:
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F34690warn,fqv[313]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[314],module,F34693describe,fqv[315]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[316],module,F34696describe_list,fqv[317]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[318],module,F34700apropos,fqv[319]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[320],module,F34703apropos_list,fqv[321]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[322],module,F34707dump_string,fqv[323]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[324],module,F34711break,fqv[325]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[326],module,F34714setbreak,fqv[327]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[328],module,F34717unbreak,fqv[329]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[330],module,F36557,fqv[331]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[332],module,F34721btrace,fqv[333]);
	local[0]= fqv[95];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42043;
	local[0]= fqv[95];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[95];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42066;
	local[0]= fqv[95];
	local[1]= fqv[312];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42067;
IF42066:
	local[0]= NIL;
IF42067:
	local[0]= fqv[95];
	goto IF42044;
IF42043:
	local[0]= NIL;
IF42044:
	ctx->vsp=local+0;
	compfun(ctx,fqv[334],module,F34725eval_dynamic,fqv[335]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F34728step_hook,fqv[336]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[337],module,F37395,fqv[338]);
	local[0]= fqv[134];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42092;
	local[0]= fqv[134];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42115;
	local[0]= fqv[134];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42116;
IF42115:
	local[0]= NIL;
IF42116:
	local[0]= fqv[134];
	goto IF42093;
IF42092:
	local[0]= NIL;
IF42093:
	ctx->vsp=local+0;
	compfun(ctx,fqv[130],module,F34733tracex,fqv[339]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F34736trace1,fqv[340]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[341],module,F37630,fqv[342]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[343],module,F37764,fqv[344]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[164],module,F34742inspect1,fqv[345]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[155],module,F38358,fqv[346]);
	local[0]= fqv[195];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42147;
	local[0]= fqv[195];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[195];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42170;
	local[0]= fqv[195];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42171;
IF42170:
	local[0]= NIL;
IF42171:
	local[0]= fqv[195];
	goto IF42148;
IF42147:
	local[0]= NIL;
IF42148:
	ctx->vsp=local+0;
	compfun(ctx,fqv[194],module,F34745time_func,fqv[347]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[348],module,F38595,fqv[349]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[350],module,F39133,fqv[351]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[352],module,F34747list_symbols,fqv[353]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[354],module,F34749functions,fqv[355]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[356],module,F34751special_variables,fqv[357]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[358],module,F34753global_variables,fqv[359]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[360],module,F34755variables,fqv[361]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[362],module,F34757constants,fqv[363]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[364],module,F34759methods,fqv[365]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[366],module,F34761method_list,fqv[367]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[368],module,F40267,fqv[369]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[370],module,F34763y_or_n_p,fqv[371]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[372],module,F34765yes_or_no_p,fqv[373]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[374],module,F34767bell,fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M40644compiled_code_type,fqv[376],fqv[377],fqv[378]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[379],module,F34769check_methods,fqv[380]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[381],module,F34771pfuncs,fqv[382]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[383],module,F34773class_hierarchy,fqv[384]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[385],module,F34775classdef,fqv[386]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[387],module,F34777classdefs,fqv[388]);
	local[0]= fqv[300];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42232;
	local[0]= fqv[300];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[300];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42255;
	local[0]= fqv[300];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42256;
IF42255:
	local[0]= NIL;
IF42256:
	local[0]= fqv[300];
	goto IF42233;
IF42232:
	local[0]= NIL;
IF42233:
	ctx->vsp=local+0;
	compfun(ctx,fqv[282],module,F34779remote_error,fqv[389]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[279],module,F34781reval,fqv[390]);
	local[0]= fqv[287];
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF42279;
	local[0]= fqv[287];
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[287];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF42302;
	local[0]= fqv[287];
	local[1]= fqv[312];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF42303;
IF42302:
	local[0]= NIL;
IF42303:
	local[0]= fqv[287];
	goto IF42280;
IF42279:
	local[0]= NIL;
IF42280:
	ctx->vsp=local+0;
	compfun(ctx,fqv[303],module,F34783install_remote_function,fqv[391]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[392],module,F34785open_server,fqv[393]);
	local[0]= fqv[394];
	local[1]= fqv[395];
	ctx->vsp=local+2;
	w=(*ftab[33])(ctx,2,local+0,&ftab[33],fqv[396]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<34; i++) ftab[i]=fcallx;
}
