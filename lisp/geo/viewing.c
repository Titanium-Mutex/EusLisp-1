/* ./viewing.c :  entry=viewing */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "viewing.h"
#pragma init (register_viewing)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewing();
extern pointer build_quote_vector();
static int register_viewing()
  { add_module_initializer("___viewing", ___viewing);}


/*:update*/
static pointer M3422viewing_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,2,local+0); /*transpose*/
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint((eusinteger_t)3L)!=local[0]) goto IF3424;
	local[0]= fqv[2];
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto IF3425;
IF3424:
	local[0]= NIL;
IF3425:
	local[0]= makeflt(-1.0000000000000000000000e+00);
	local[1]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[8]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK3423:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M3426viewing_changed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[3];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3427:
	ctx->vsp=local; return(local[0]);}

/*:viewpoint*/
static pointer M3428viewing_viewpoint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3429:
	ctx->vsp=local; return(local[0]);}

/*:view-direction*/
static pointer M3430viewing_view_direction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3431:
	ctx->vsp=local; return(local[0]);}

/*:view-up*/
static pointer M3432viewing_view_up(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3433:
	ctx->vsp=local; return(local[0]);}

/*:view-right*/
static pointer M3434viewing_view_right(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[6]); /*matrix-row*/
	local[0]= w;
BLK3435:
	ctx->vsp=local; return(local[0]);}

/*:sendviewcoords*/
static pointer M3436viewing_sendviewcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[7];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
BLK3437:
	ctx->vsp=local; return(local[0]);}

/*:look*/
static pointer M3438viewing_look(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3441;}
	local[0]= fqv[8];
ENT3441:
ENT3440:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[9];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,3,local+1); /*send-message*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ATAN(ctx,2,local+3); /*atan*/
	local[3]= makeflt(-(fltval(w)));
	local[4]= fqv[11];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ATAN(ctx,2,local+3); /*atan*/
	local[3]= w;
	{ double x,y;
		y=fltval(makeflt(3.1415926535897931159980e+00)); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[3]= makeflt(-(fltval(local[3])));
	local[4]= fqv[13];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= makeflt(-(fltval(makeflt(3.1415926535897931159980e+00))));
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= fqv[11];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[14];
	local[4]= argv[2];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK3439:
	ctx->vsp=local; return(local[0]);}

/*:makeviewcoords*/
static pointer M3442viewing_makeviewcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[0]));
	local[2]= fqv[15];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= makeflt(1.5707963267948965579990e+00);
	local[3]= fqv[11];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= makeflt(1.5707963267948965579990e+00);
	local[3]= fqv[16];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[2];
	local[3]= fqv[11];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[3];
	local[3]= fqv[13];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[10];
	local[2]= argv[4];
	local[3]= fqv[16];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[14];
	local[2]= argv[5];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3443:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3444viewing_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3446:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[17], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3447;
	local[1] = makeint((eusinteger_t)3L);
KEY3447:
	if (n & (1<<1)) goto KEY3448;
	local[2] = NIL;
KEY3448:
	if (n & (1<<2)) goto KEY3449;
	local[3] = NIL;
KEY3449:
	if (n & (1<<3)) goto KEY3450;
	local[6]= makeflt(0.0000000000000000000000e+00);
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[4] = w;
KEY3450:
	if (n & (1<<4)) goto KEY3451;
	local[5] = NIL;
KEY3451:
	local[6]= (pointer)get_sym_func(fqv[18]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[0]));
	local[9]= fqv[9];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,5,local+6); /*apply*/
	local[6]= fqv[19];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,2,local+6,&ftab[1],fqv[20]); /*coords*/
	argv[0]->c.obj.iv[8] = w;
	if (local[2]!=NIL) goto OR3454;
	if (local[3]!=NIL) goto OR3454;
	goto IF3452;
OR3454:
	if (local[3]!=NIL) goto IF3455;
	local[6]= local[2];
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[3] = w;
	local[6]= local[3];
	goto IF3456;
IF3455:
	local[6]= NIL;
IF3456:
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[3] = w;
	if (local[5]!=NIL) goto IF3457;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[5] = w;
	local[6]= local[5];
	goto IF3458;
IF3457:
	local[6]= NIL;
IF3458:
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[5] = w;
	local[6]= local[5];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[4] = w;
	local[6]= makeflt(-1.0000000000000000000000e+00);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[3] = w;
	local[6]= loadglobal(fqv[21]);
	local[7]= local[5];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)CONCATENATE(ctx,4,local+6); /*concatenate*/
	local[6]= w;
	local[7]= w;
	w = argv[0]->c.obj.iv[1];
	w->c.obj.iv[1] = local[7];
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,2,local+6); /*transpose*/
	local[6]= w;
	goto IF3453;
IF3452:
	local[6]= NIL;
IF3453:
	local[6]= argv[0];
	local[7]= fqv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	w = argv[0];
	local[0]= w;
BLK3445:
	ctx->vsp=local; return(local[0]);}

/*:projection*/
static pointer M3459projection_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3460:
	ctx->vsp=local; return(local[0]);}

/*:newprojection*/
static pointer M3461projection_newprojection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[13] = argv[2];
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3462:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3463projection_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3464:
	ctx->vsp=local; return(local[0]);}

/*:project3*/
static pointer M3465projection_project3(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[22]); /*homogenize*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3466:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3467projection_view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[24];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3468:
	ctx->vsp=local; return(local[0]);}

/*:screen*/
static pointer M3469projection_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3473;}
	local[0]= NIL;
ENT3473:
	if (n>=4) { local[1]=(argv[3]); goto ENT3472;}
	local[1]= local[0];
ENT3472:
ENT3471:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3474;
	argv[0]->c.obj.iv[9] = local[0];
	argv[0]->c.obj.iv[10] = local[1];
	local[2]= argv[0];
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF3475;
IF3474:
	local[2]= NIL;
IF3475:
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK3470:
	ctx->vsp=local; return(local[0]);}

/*:hither*/
static pointer M3476projection_hither(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3479;}
	local[0]= NIL;
ENT3479:
ENT3478:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3480;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[11] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3481;
IF3480:
	local[1]= NIL;
IF3481:
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK3477:
	ctx->vsp=local; return(local[0]);}

/*:yon*/
static pointer M3482projection_yon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3485;}
	local[0]= NIL;
ENT3485:
ENT3484:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3486;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[12] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3487;
IF3486:
	local[1]= NIL;
IF3487:
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK3483:
	ctx->vsp=local; return(local[0]);}

/*:aspect*/
static pointer M3488projection_aspect(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3491;}
	local[0]= NIL;
ENT3491:
ENT3490:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3492;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3493;
IF3492:
	local[1]= NIL;
IF3493:
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK3489:
	ctx->vsp=local; return(local[0]);}

/*:viewreference*/
static pointer M3494projection_viewreference(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[11];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[12]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
BLK3495:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3496projection_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3498:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[26];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK3497:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3499projection_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3501:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[27], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3502;
	local[1] = makeflt(1.0000000000000000000000e+02);
KEY3502:
	if (n & (1<<1)) goto KEY3503;
	local[2] = makeflt(1.0000000000000000000000e+04);
KEY3503:
	if (n & (1<<2)) goto KEY3504;
	local[3] = makeflt(1.0000000000000000000000e+00);
KEY3504:
	if (n & (1<<3)) goto KEY3505;
	local[4] = makeflt(1.0000000000000000000000e+02);
KEY3505:
	if (n & (1<<4)) goto KEY3506;
	local[5] = local[4];
KEY3506:
	if (n & (1<<5)) goto KEY3507;
	local[7]= local[3];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[6] = w;
KEY3507:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[11] = w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[12] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[9] = w;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)EUSFLOAT(ctx,1,local+7); /*float*/
	argv[0]->c.obj.iv[10] = w;
	local[7]= (pointer)get_sym_func(fqv[18]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[0]));
	local[10]= fqv[9];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,5,local+7); /*apply*/
	local[7]= argv[0];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	w = argv[0];
	local[0]= w;
BLK3500:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3508viewing2d_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK3509:
	ctx->vsp=local; return(local[0]);}

/*:project2*/
static pointer M3510viewing2d_project2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[22]); /*homogenize*/
	local[0]= w;
BLK3511:
	ctx->vsp=local; return(local[0]);}

/*:view*/
static pointer M3512viewing2d_view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[28];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[24];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3513:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3514viewing2d_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)2L);
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[29]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeflt(2.0000000000000000000000e+00);
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint((eusinteger_t)1L);
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeflt(2.0000000000000000000000e+00);
	local[4]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	w = argv[0]->c.obj.iv[13];
	local[0]= w;
BLK3515:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3516viewing2d_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3518:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[30], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3519;
	local[1] = makeflt(1.0000000000000000000000e+00);
KEY3519:
	if (n & (1<<1)) goto KEY3520;
	local[2] = local[1];
KEY3520:
	if (n & (1<<2)) goto KEY3521;
	local[3] = local[2];
KEY3521:
	local[4]= (pointer)get_sym_func(fqv[18]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[0]));
	local[7]= fqv[9];
	local[8]= fqv[19];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,7,local+4); /*apply*/
	argv[0]->c.obj.iv[9] = local[2];
	argv[0]->c.obj.iv[10] = local[3];
	local[4]= argv[0];
	local[5]= fqv[25];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK3517:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3522parallel_viewing_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)4L);
	local[1]= makeint((eusinteger_t)4L);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[29]); /*make-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeflt(1.0000000000000000000000e+00);
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint((eusinteger_t)1L);
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeflt(1.0000000000000000000000e+00);
	local[4]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint((eusinteger_t)2L);
	local[2]= makeint((eusinteger_t)2L);
	local[3]= makeflt(1.0000000000000000000000e+00);
	local[4]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint((eusinteger_t)2L);
	local[2]= makeint((eusinteger_t)3L);
	local[3]= argv[0]->c.obj.iv[11];
	local[4]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	local[0]= argv[0]->c.obj.iv[13];
	local[1]= makeint((eusinteger_t)3L);
	local[2]= makeint((eusinteger_t)3L);
	local[3]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,4,local+0); /*aset*/
	w = argv[0];
	local[0]= w;
BLK3523:
	ctx->vsp=local; return(local[0]);}

/*:ray*/
static pointer M3526perspective_viewing_ray(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[31];
	local[2]= argv[0]->c.obj.iv[9];
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[10];
	{ double x,y;
		y=fltval(argv[3]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	local[4]= makeflt(-(fltval(argv[0]->c.obj.iv[14])));
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK3527:
	ctx->vsp=local; return(local[0]);}

/*:view-plane*/
static pointer M3528perspective_viewing_view_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3531;}
	local[0]= makeflt(0.0000000000000000000000e+00);
ENT3531:
ENT3530:
	if (n>3) maerror();
	local[1]= fqv[32];
	local[2]= argv[0];
	local[3]= fqv[33];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= fqv[34];
	local[4]= argv[0];
	local[5]= fqv[24];
	local[6]= makeflt(0.0000000000000000000000e+00);
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= local[0];
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[4])(ctx,4,local+1,&ftab[4],fqv[35]); /*make-plane*/
	local[0]= w;
BLK3529:
	ctx->vsp=local; return(local[0]);}

/*:make-projection*/
static pointer M3532perspective_viewing_make_projection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(2.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= makeflt(2.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[12]); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[14]); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	local[2]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint((eusinteger_t)4L);
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,1,local+5,&ftab[5],fqv[36]); /*unit-matrix*/
	local[3] = w;
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= makeint((eusinteger_t)3L);
	local[8]= makeflt(-(fltval(argv[0]->c.obj.iv[14])));
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	local[8]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= makeint((eusinteger_t)4L);
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(*ftab[3])(ctx,2,local+5,&ftab[3],fqv[29]); /*make-matrix*/
	local[4] = w;
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)1L);
	local[7]= makeint((eusinteger_t)1L);
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= makeint((eusinteger_t)2L);
	local[8]= makeflt(1.0000000000000000000000e+00);
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= makeint((eusinteger_t)3L);
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)3L);
	local[7]= makeint((eusinteger_t)3L);
	local[8]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[4];
	local[6]= local[3];
	local[7]= argv[0]->c.obj.iv[13];
	ctx->vsp=local+8;
	w=(pointer)MATTIMES(ctx,3,local+5); /*m**/
	local[0]= w;
BLK3533:
	ctx->vsp=local; return(local[0]);}

/*:viewdistance*/
static pointer M3534perspective_viewing_viewdistance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3537;}
	local[0]= NIL;
ENT3537:
ENT3536:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3538;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[14] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3539;
IF3538:
	local[1]= NIL;
IF3539:
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK3535:
	ctx->vsp=local; return(local[0]);}

/*:view-angle*/
static pointer M3540perspective_viewing_view_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3543;}
	local[0]= NIL;
ENT3543:
ENT3542:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3544;
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[14];
	local[3]= local[0];
	local[4]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TAN(ctx,1,local+3); /*tan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= NIL;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= local[1];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)TIMES(ctx,2,local+6); /***/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[3] = w;
	local[4]= argv[0];
	local[5]= fqv[37];
	local[6]= local[3];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[25];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = local[0];
	local[1]= w;
	goto IF3545;
IF3544:
	local[1]= makeint((eusinteger_t)2L);
	local[2]= argv[0]->c.obj.iv[9];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[9]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[10];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[10]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[3]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)SQRT(ctx,1,local+2); /*sqrt*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+4;
	w=(pointer)ATAN(ctx,2,local+2); /*atan*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
IF3545:
	w = local[1];
	local[0]= w;
BLK3541:
	ctx->vsp=local; return(local[0]);}

/*:fovy*/
static pointer M3546perspective_viewing_fovy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)2L);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+3;
	w=(pointer)ATAN(ctx,2,local+1); /*atan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK3547:
	ctx->vsp=local; return(local[0]);}

/*:zoom*/
static pointer M3548perspective_viewing_zoom(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3551;}
	local[0]= NIL;
ENT3551:
ENT3550:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3552;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0]->c.obj.iv[9] = w;
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0];
	local[2]= fqv[25];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF3553;
IF3552:
	local[1]= NIL;
IF3553:
	local[1]= argv[0];
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0]= w;
BLK3549:
	ctx->vsp=local; return(local[0]);}

/*:lookaround*/
static pointer M3554perspective_viewing_lookaround(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[12];
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[11]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[14];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,1,local+3); /*v-*/
	local[3]= w;
	local[4]= fqv[39];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= argv[2];
	local[4]= fqv[16];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= argv[3];
	local[4]= fqv[11];
	local[5]= fqv[39];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[14];
	local[3]= local[0];
	local[4]= fqv[39];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3555:
	ctx->vsp=local; return(local[0]);}

/*:look-body*/
static pointer M3556perspective_viewing_look_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3558:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[40]); /*flatten*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[41]); /*bounding-box-union*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[1];
	local[6]= fqv[42];
	local[7]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[43];
	local[7]= argv[0];
	local[8]= fqv[44];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[1];
	local[9]= fqv[45];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= loadglobal(fqv[46]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[9];
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3560,env,argv,local);
	local[9]= local[1];
	local[10]= fqv[47];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	w = local[5];
	local[1] = w;
	local[5]= local[1];
	local[6]= fqv[48];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORMALIZE(ctx,1,local+5); /*normalize-vector*/
	local[2] = w;
	local[5]= local[1];
	local[6]= fqv[49];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORMALIZE(ctx,1,local+5); /*normalize-vector*/
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[50]); /*acos*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[51];
	local[7]= makeflt(5.0000000000000000000000e-01);
	local[8]= local[1];
	local[9]= fqv[52];
	local[10]= fqv[53];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[54];
	local[7]= makeflt(2.0000000000000000000000e+00);
	local[8]= local[1];
	local[9]= fqv[52];
	local[10]= fqv[55];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[38];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	w = argv[0];
	local[0]= w;
BLK3557:
	ctx->vsp=local; return(local[0]);}

/*:look-body2*/
static pointer M3561perspective_viewing_look_body2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3563:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[40]); /*flatten*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[41]); /*bounding-box-union*/
	local[1]= w;
	local[2]= fqv[42];
	local[3]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= *(ovafptr(local[1],fqv[56]));
	local[3]= *(ovafptr(local[1],fqv[57]));
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[45];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[44];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[43];
	local[10]= argv[0];
	local[11]= fqv[44];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= makeflt(2.0000000000000000000000e+00);
	local[9]= local[2];
	local[10]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ATAN(ctx,2,local+9); /*atan*/
	{ double x,y;
		y=fltval(w); x=fltval(local[8]);
		local[8]=(makeflt(x * y));}
	local[7] = local[8];
	local[8]= local[2];
	local[9]= local[4];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,1,local+8); /*print*/
	local[8]= argv[0];
	local[9]= fqv[51];
	local[10]= makeflt(5.0000000000000000000000e-01);
	local[11]= local[1];
	local[12]= fqv[52];
	local[13]= fqv[58];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[54];
	local[10]= makeflt(2.0000000000000000000000e+00);
	local[11]= local[1];
	local[12]= fqv[52];
	local[13]= fqv[59];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)2L);
	ctx->vsp=local+13;
	w=(pointer)AREF(ctx,2,local+11); /*aref*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= argv[0];
	local[9]= fqv[38];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w = argv[0];
	local[0]= w;
BLK3562:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M3564perspective_viewing_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3567;}
	local[0]= NIL;
ENT3567:
ENT3566:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[0]));
	local[3]= fqv[60];
	local[4]= argv[2];
	local[5]= NIL;
	local[6]= fqv[61];
	local[7]= argv[0];
	local[8]= fqv[38];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[62]); /*rad2deg*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK3565:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3568perspective_viewing_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3570:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[63], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3571;
	local[1] = NIL;
KEY3571:
	if (local[1]==NIL) goto IF3572;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)EUSFLOAT(ctx,1,local+2); /*float*/
	argv[0]->c.obj.iv[14] = w;
	local[2]= argv[0]->c.obj.iv[14];
	goto IF3573;
IF3572:
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF3574;
	argv[0]->c.obj.iv[14] = makeflt(1.0000000000000000000000e+02);
	local[2]= argv[0]->c.obj.iv[14];
	goto IF3575;
IF3574:
	local[2]= NIL;
IF3575:
IF3573:
	if (argv[0]->c.obj.iv[13]!=NIL) goto IF3576;
	local[2]= makeint((eusinteger_t)4L);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[36]); /*unit-matrix*/
	argv[0]->c.obj.iv[13] = w;
	local[2]= argv[0]->c.obj.iv[13];
	goto IF3577;
IF3576:
	local[2]= NIL;
IF3577:
	local[2]= (pointer)get_sym_func(fqv[18]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[0]));
	local[5]= fqv[9];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,5,local+2); /*apply*/
	w = argv[0];
	local[0]= w;
BLK3569:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3560(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[8];
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:view-orient*/
static pointer M3578perspective_viewing_view_orient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3581;}
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)MKFLTVEC(ctx,2,local+0); /*float-vector*/
	local[0]= w;
ENT3581:
ENT3580:
	if (n>3) maerror();
	local[1]= *(ovafptr(argv[0]->c.obj.iv[8],fqv[64]));
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= local[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)0L));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	local[2]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[9]); x=fltval(local[2]);
		local[2]=(makeflt(x * y));}
	local[3]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= local[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)1L));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[10]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	local[4]= argv[0]->c.obj.iv[14];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[0]= w;
BLK3579:
	ctx->vsp=local; return(local[0]);}

/*:view-line*/
static pointer M3582perspective_viewing_view_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3585;}
	local[0]= fqv[65];
ENT3585:
ENT3584:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[66]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[9];
	local[4]= argv[0];
	local[5]= fqv[67];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[44];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK3583:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewing(ctx,n,argv,env)
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
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3587;
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[70],w);
	goto IF3588;
IF3587:
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3588:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3422viewing_update,fqv[1],fqv[72],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3426viewing_changed,fqv[3],fqv[72],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3428viewing_viewpoint,fqv[44],fqv[72],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3430viewing_view_direction,fqv[33],fqv[72],fqv[76]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3432viewing_view_up,fqv[77],fqv[72],fqv[78]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3434viewing_view_right,fqv[79],fqv[72],fqv[80]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3436viewing_sendviewcoords,fqv[81],fqv[72],fqv[82]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3438viewing_look,fqv[43],fqv[72],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3442viewing_makeviewcoords,fqv[84],fqv[72],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3444viewing_init,fqv[9],fqv[72],fqv[86]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3459projection_projection,fqv[87],fqv[88],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3461projection_newprojection,fqv[90],fqv[88],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3463projection_project,fqv[92],fqv[88],fqv[93]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3465projection_project3,fqv[23],fqv[88],fqv[94]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3467projection_view,fqv[95],fqv[88],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3469projection_screen,fqv[37],fqv[88],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3476projection_hither,fqv[51],fqv[88],fqv[98]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3482projection_yon,fqv[54],fqv[88],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3488projection_aspect,fqv[100],fqv[88],fqv[101]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3494projection_viewreference,fqv[102],fqv[88],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3496projection_make_projection,fqv[25],fqv[88],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3499projection_init,fqv[9],fqv[88],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3508viewing2d_project,fqv[92],fqv[106],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3510viewing2d_project2,fqv[28],fqv[106],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3512viewing2d_view,fqv[95],fqv[106],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3514viewing2d_make_projection,fqv[25],fqv[106],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3516viewing2d_init,fqv[9],fqv[106],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3522parallel_viewing_make_projection,fqv[25],fqv[112],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3526perspective_viewing_ray,fqv[114],fqv[115],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3528perspective_viewing_view_plane,fqv[117],fqv[115],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3532perspective_viewing_make_projection,fqv[25],fqv[115],fqv[119]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3534perspective_viewing_viewdistance,fqv[120],fqv[115],fqv[121]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3540perspective_viewing_view_angle,fqv[38],fqv[115],fqv[122]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3546perspective_viewing_fovy,fqv[123],fqv[115],fqv[124]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3548perspective_viewing_zoom,fqv[125],fqv[115],fqv[126]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3554perspective_viewing_lookaround,fqv[127],fqv[115],fqv[128]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3556perspective_viewing_look_body,fqv[129],fqv[115],fqv[130]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3561perspective_viewing_look_body2,fqv[131],fqv[115],fqv[132]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3564perspective_viewing_prin1,fqv[60],fqv[115],fqv[133]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3568perspective_viewing_init,fqv[9],fqv[115],fqv[134]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3578perspective_viewing_view_orient,fqv[67],fqv[115],fqv[135]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3582perspective_viewing_view_line,fqv[136],fqv[115],fqv[137]);
	local[0]= fqv[138];
	local[1]= fqv[139];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[140]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<11; i++) ftab[i]=fcallx;
}
