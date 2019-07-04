/* ./dda.c :  entry=dda */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "dda.h"
#pragma init (register_dda)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___dda();
extern pointer build_quote_vector();
static int register_dda()
  { add_module_initializer("___dda", ___dda);}

static pointer F4787dda_line();
static pointer F4788dda_ellipse();
static pointer F4789draw_ellipse();

/*:init*/
static pointer M4790dda_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[1] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK4791:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4792line_dda_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[4];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[4] = w;
	local[2]= argv[5];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[5] = w;
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)ABS(ctx,1,local+2); /*abs*/
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)ABS(ctx,1,local+2); /*abs*/
	local[1] = w;
	argv[0]->c.obj.iv[6] = makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)2L);
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	argv[0]->c.obj.iv[8] = w;
	local[2]= makeint((eusinteger_t)2L);
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF4794;
	local[3]= local[1];
	goto IF4795;
IF4794:
	local[3]= local[0];
IF4795:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	argv[0]->c.obj.iv[7] = w;
	argv[0]->c.obj.iv[2] = argv[2];
	argv[0]->c.obj.iv[3] = argv[3];
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAX(ctx,2,local+2); /*max*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	argv[0]->c.obj.iv[10] = w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON4797;
	local[2]= makeint((eusinteger_t)2L);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF4798;
	local[2]= makeint((eusinteger_t)1L);
	goto IF4799;
IF4798:
	local[2]= makeint((eusinteger_t)-1L);
IF4799:
	argv[0]->c.obj.iv[9] = local[2];
	argv[0]->c.obj.iv[11] = fqv[2];
	local[2]= argv[0]->c.obj.iv[11];
	goto CON4796;
CON4797:
	local[2]= makeint((eusinteger_t)2L);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[2]= argv[0]->c.obj.iv[4];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF4801;
	local[2]= makeint((eusinteger_t)1L);
	goto IF4802;
IF4801:
	local[2]= makeint((eusinteger_t)-1L);
IF4802:
	argv[0]->c.obj.iv[9] = local[2];
	argv[0]->c.obj.iv[11] = fqv[3];
	local[2]= argv[0]->c.obj.iv[11];
	goto CON4796;
CON4800:
	local[2]= NIL;
CON4796:
	w = local[2];
	w = argv[0];
	local[0]= w;
BLK4793:
	ctx->vsp=local; return(local[0]);}

/*:update-x-major*/
static pointer M4803line_dda_update_x_major(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON4806;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4805;
CON4806:
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4805;
CON4807:
	local[0]= NIL;
CON4805:
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF4808;
	local[1]= makeint((eusinteger_t)1L);
	goto IF4809;
IF4808:
	local[1]= makeint((eusinteger_t)-1L);
IF4809:
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK4804:
	ctx->vsp=local; return(local[0]);}

/*:update-y-major*/
static pointer M4810line_dda_update_y_major(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto CON4813;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4812;
CON4813:
	local[0]= argv[0]->c.obj.iv[6];
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[6];
	goto CON4812;
CON4814:
	local[0]= NIL;
CON4812:
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF4815;
	local[1]= makeint((eusinteger_t)1L);
	goto IF4816;
IF4815:
	local[1]= makeint((eusinteger_t)-1L);
IF4816:
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4811:
	ctx->vsp=local; return(local[0]);}

/*:next*/
static pointer M4817line_dda_next(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF4819;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK4818;
	goto IF4820;
IF4819:
	local[0]= NIL;
IF4820:
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK4818:
	ctx->vsp=local; return(local[0]);}

/*dda-line*/
static pointer F4787dda_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= loadglobal(fqv[4]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[1];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
WHL4824:
	local[3]= local[0];
	local[4]= fqv[5];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto WHX4825;
	local[3]= local[1];
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	goto WHL4824;
WHX4825:
	local[3]= NIL;
BLK4826:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK4822:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4827ellipse_dda_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT4831;}
	local[0]= makeint((eusinteger_t)0L);
ENT4831:
	if (n>=6) { local[1]=(argv[5]); goto ENT4830;}
	local[1]= makeint((eusinteger_t)0L);
ENT4830:
ENT4829:
	if (n>6) maerror();
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[0]));
	local[4]= fqv[1];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,3,local+2); /*send-message*/
	argv[0]->c.obj.iv[2] = NIL;
	argv[0]->c.obj.iv[3] = local[0];
	argv[0]->c.obj.iv[4] = local[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[5] = w;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[6] = w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[6];
	local[4]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	argv[0]->c.obj.iv[7] = w;
	local[2]= makeint((eusinteger_t)2L);
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)LOG(ctx,1,local+3); /*log*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)LOG(ctx,1,local+4); /*log*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)CEILING(ctx,1,local+3); /*ceiling*/
	local[3]= makeint(-(intval(w)));
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[6]); /*expt*/
	argv[0]->c.obj.iv[8] = w;
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[15] = w;
	argv[0]->c.obj.iv[16] = makeflt(0.0000000000000000000000e+00);
	local[2]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[13] = w;
	local[2]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+3;
	w=(pointer)ROUND(ctx,1,local+2); /*round*/
	argv[0]->c.obj.iv[14] = w;
	argv[0]->c.obj.iv[9] = argv[0]->c.obj.iv[13];
	argv[0]->c.obj.iv[10] = argv[0]->c.obj.iv[14];
	argv[0]->c.obj.iv[12] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK4828:
	ctx->vsp=local; return(local[0]);}

/*:next*/
static pointer M4832ellipse_dda_next(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF4834;
	local[0]= argv[0]->c.obj.iv[16];
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF4834;
	argv[0]->c.obj.iv[2] = T;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK4833;
	goto IF4835;
IF4834:
	local[0]= NIL;
IF4835:
	argv[0]->c.obj.iv[11] = argv[0]->c.obj.iv[15];
	argv[0]->c.obj.iv[12] = argv[0]->c.obj.iv[16];
	local[0]= argv[0]->c.obj.iv[11];
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= argv[0]->c.obj.iv[7];
	local[3]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,3,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	argv[0]->c.obj.iv[15] = w;
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[16] = w;
	local[0]= argv[0]->c.obj.iv[15];
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[16];
	ctx->vsp=local+1;
	w=(pointer)ROUND(ctx,1,local+0); /*round*/
	argv[0]->c.obj.iv[14] = w;
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4838;
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4838;
	goto CON4837;
OR4838:
	argv[0]->c.obj.iv[9] = argv[0]->c.obj.iv[13];
	argv[0]->c.obj.iv[10] = argv[0]->c.obj.iv[14];
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON4836;
CON4837:
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON4836;
CON4839:
	local[0]= NIL;
CON4836:
	w = local[0];
	local[0]= w;
BLK4833:
	ctx->vsp=local; return(local[0]);}

/*dda-ellipse*/
static pointer F4788dda_ellipse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)EUSFLOAT(ctx,1,local+12); /*float*/
	argv[0] = w;
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)EUSFLOAT(ctx,1,local+12); /*float*/
	argv[1] = w;
	local[12]= argv[1];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	local[13]= argv[0];
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[9] = w;
	local[12]= makeflt(1.0000000000000000000000e+00);
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)QUOTIENT(ctx,2,local+12); /*/*/
	local[10] = w;
	local[12]= makeint((eusinteger_t)2L);
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)LOG(ctx,1,local+13); /*log*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)2L);
	ctx->vsp=local+15;
	w=(pointer)LOG(ctx,1,local+14); /*log*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)CEILING(ctx,1,local+13); /*ceiling*/
	local[13]= makeint(-(intval(w)));
	ctx->vsp=local+14;
	w=(*ftab[0])(ctx,2,local+12,&ftab[0],fqv[6]); /*expt*/
	local[8] = w;
	local[12]= local[8];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)EUSFLOAT(ctx,1,local+12); /*float*/
	local[2] = w;
	local[3] = makeflt(0.0000000000000000000000e+00);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[6] = w;
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[7] = w;
	local[4] = local[6];
	local[5] = local[7];
TAG4841:
	local[0] = local[2];
	local[1] = local[3];
	local[12]= local[0];
	local[13]= local[8];
	local[14]= local[10];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)TIMES(ctx,3,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,2,local+12); /*-*/
	local[2] = w;
	local[12]= local[1];
	local[13]= local[8];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)TIMES(ctx,2,local+13); /***/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)PLUS(ctx,2,local+12); /*+*/
	local[3] = w;
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[6] = w;
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)ROUND(ctx,1,local+12); /*round*/
	local[7] = w;
	local[12]= local[4];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[1])(ctx,2,local+12,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4844;
	local[12]= local[5];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(*ftab[1])(ctx,2,local+12,&ftab[1],fqv[7]); /*/=*/
	if (w!=NIL) goto OR4844;
	goto IF4842;
OR4844:
	local[4] = local[6];
	local[5] = local[7];
	local[12]= local[4];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
	w = local[11];
	ctx->vsp=local+13;
	local[11] = cons(ctx,local[12],w);
	local[12]= local[4];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PRINT(ctx,1,local+12); /*print*/
	local[12]= w;
	goto IF4843;
IF4842:
	local[12]= NIL;
IF4843:
	local[12]= local[1];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)LESSP(ctx,2,local+12); /*<*/
	if (w==NIL) goto AND4847;
	local[12]= local[3];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)GREQP(ctx,2,local+12); /*>=*/
	if (w==NIL) goto AND4847;
	goto IF4845;
AND4847:
	ctx->vsp=local+12;
	goto TAG4841;
	goto IF4846;
IF4845:
	local[12]= NIL;
IF4846:
	w = T;
	local[0]= w;
BLK4840:
	ctx->vsp=local; return(local[0]);}

/*draw-ellipse*/
static pointer F4789draw_ellipse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT4850;}
	local[0]= loadglobal(fqv[8]);
ENT4850:
ENT4849:
	if (n>5) maerror();
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= argv[0];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[1]= w;
	local[2]= NIL;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[10],w);
WHL4852:
	local[6]= loadglobal(fqv[10]);
	local[7]= fqv[5];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto WHX4853;
	local[6]= local[0];
	local[7]= fqv[11];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	goto WHL4852;
WHX4853:
	local[6]= NIL;
BLK4854:
	local[6]= local[0];
	local[7]= fqv[12];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK4848:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___dda(ctx,n,argv,env)
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
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[10];
	local[1]= fqv[14];
	local[2]= fqv[10];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[16]);
	local[5]= fqv[17];
	local[6]= fqv[18];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[14];
	local[2]= fqv[4];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[10]);
	local[5]= fqv[17];
	local[6]= fqv[24];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[9];
	local[1]= fqv[14];
	local[2]= fqv[9];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[10]);
	local[5]= fqv[17];
	local[6]= fqv[25];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[26];
	local[1]= fqv[14];
	local[2]= fqv[26];
	local[3]= fqv[15];
	local[4]= loadglobal(fqv[9]);
	local[5]= fqv[17];
	local[6]= fqv[27];
	local[7]= fqv[19];
	local[8]= NIL;
	local[9]= fqv[20];
	local[10]= NIL;
	local[11]= fqv[21];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[22];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[2])(ctx,13,local+2,&ftab[2],fqv[23]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4790dda_init,fqv[1],fqv[10],fqv[28]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4792line_dda_init,fqv[1],fqv[4],fqv[29]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4803line_dda_update_x_major,fqv[2],fqv[4],fqv[30]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4810line_dda_update_y_major,fqv[3],fqv[4],fqv[31]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4817line_dda_next,fqv[5],fqv[4],fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F4787dda_line,fqv[34]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4827ellipse_dda_init,fqv[1],fqv[9],fqv[35]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4832ellipse_dda_next,fqv[5],fqv[9],fqv[36]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[37],module,F4788dda_ellipse,fqv[38]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[39],module,F4789draw_ellipse,fqv[40]);
	local[0]= fqv[41];
	local[1]= fqv[42];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[43]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
