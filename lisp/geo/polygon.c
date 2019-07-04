/* ./polygon.c :  entry=polygon */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "polygon.h"
#pragma init (register_polygon)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___polygon();
extern pointer build_quote_vector();
static int register_polygon()
  { add_module_initializer("___polygon", ___polygon);}

static pointer F3026make_polygon2d();
static pointer F3027make_rectangle();
static pointer F3028make_circle();

/*:vertices*/
static pointer M3029polygon2d_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK3030:
	ctx->vsp=local; return(local[0]);}

/*:lines*/
static pointer M3031polygon2d_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK3032:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M3033polygon2d_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL3035:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3036;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	goto WHL3035;
WHX3036:
	local[2]= NIL;
BLK3037:
	w = local[0];
	local[0]= w;
BLK3034:
	ctx->vsp=local; return(local[0]);}

/*:drawners*/
static pointer M3039polygon2d_drawners(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3040:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M3041polygon2d_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[12];
	local[0]= w;
BLK3042:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M3043polygon2d_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[1]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w!=NIL) goto IF3045;
	local[0]= argv[2];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF3046;
IF3045:
	local[0]= NIL;
IF3046:
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= fqv[3];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3044:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M3047polygon2d_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
WHL3049:
	if (local[0]==NIL) goto WHX3050;
	local[4]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,3,local+4); /*transform*/
	local[4]= local[3];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	goto WHL3049;
WHX3050:
	local[4]= NIL;
BLK3051:
	local[4]= argv[0]->c.obj.iv[12];
	local[5]= fqv[4];
	local[6]= argv[0]->c.obj.iv[9];
	local[7]= loadglobal(fqv[5]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK3048:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M3054polygon2d_set_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[6]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0] = w;
	argv[0]->c.obj.iv[11] = T;
WHL3056:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3057;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,3,local+1,&ftab[0],fqv[7]); /*triangle*/
	local[1]= w;
	local[2]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF3059;
	argv[0]->c.obj.iv[11] = NIL;
	local[0] = NIL;
	local[1]= local[0];
	goto IF3060;
IF3059:
	local[1]= NIL;
IF3060:
	goto WHL3056;
WHX3057:
	local[1]= NIL;
BLK3058:
	w = local[1];
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK3055:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3062polygon2d_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[8]));
	local[2]= fqv[4];
	local[3]= fqv[9];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[2];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	argv[0]->c.obj.iv[9] = w;
	local[0]= (pointer)get_sym_func(fqv[10]);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	argv[0]->c.obj.iv[8] = w;
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[11]); /*make-bounding-box*/
	argv[0]->c.obj.iv[12] = w;
	local[0]= argv[0]->c.obj.iv[9];
	argv[0]->c.obj.iv[10] = NIL;
WHL3064:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX3065;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[12]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	goto WHL3064;
WHX3065:
	local[1]= NIL;
BLK3066:
	w = local[1];
	local[0]= argv[0];
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK3063:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M3068polygon2d_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3071;}
	local[0]= NIL;
ENT3071:
ENT3070:
	if (n>4) maerror();
	if (local[0]!=NIL) goto IF3072;
	local[0] = argv[2]->c.obj.iv[2];
	argv[2] = argv[2]->c.obj.iv[1];
	local[1]= argv[2];
	goto IF3073;
IF3072:
	local[1]= NIL;
IF3073:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[10];
WHL3075:
	if (local[6]==NIL) goto WHX3076;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5]->c.obj.iv[1];
	local[8]= local[5]->c.obj.iv[2];
	local[9]= argv[2];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,4,local+7,&ftab[3],fqv[14]); /*line-intersection*/
	local[1] = w;
	if (local[1]==NIL) goto IF3079;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= local[2];
	local[9]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LSEQP(ctx,3,local+7); /*<=*/
	if (w==NIL) goto IF3081;
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= local[3];
	local[9]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LSEQP(ctx,3,local+7); /*<=*/
	if (w==NIL) goto IF3081;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF3082;
IF3081:
	local[7]= NIL;
IF3082:
	goto IF3080;
IF3079:
	local[7]= NIL;
IF3080:
	goto WHL3075;
WHX3076:
	local[7]= NIL;
BLK3077:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK3069:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M3083polygon2d_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3086;}
	local[0]= loadglobal(fqv[5]);
ENT3086:
ENT3085:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL3088:
	if (local[4]==NIL) goto WHX3089;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[15];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto IF3092;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF3093;
IF3092:
	local[5]= NIL;
IF3093:
	goto WHL3088;
WHX3089:
	local[5]= NIL;
BLK3090:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK3084:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M3094polygon2d_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF3096;
	local[0]= fqv[17];
	goto IF3097;
IF3096:
	local[0]= argv[0];
	local[1]= fqv[18];
	local[2]= argv[2];
	local[3]= makeflt(1.0000000000000000000000e+10);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000000000e+10);
	ctx->vsp=local+5;
	w=(pointer)RANDOM(ctx,1,local+4); /*random*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,2,local+3); /*float-vector*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[19]); /*evenp*/
	local[0]= ((w)==NIL?T:NIL);
IF3097:
	w = local[0];
	local[0]= w;
BLK3095:
	ctx->vsp=local; return(local[0]);}

/*:intersect-polygon2d*/
static pointer M3098polygon2d_intersect_polygon2d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[20];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF3100;
	local[0]= argv[2];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[10];
WHL3103:
	if (local[5]==NIL) goto WHX3104;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[1] = local[4]->c.obj.iv[1];
	local[2] = local[4]->c.obj.iv[2];
	local[6]= NIL;
	local[7]= local[0];
WHL3108:
	if (local[7]==NIL) goto WHX3109;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[1];
	local[9]= local[2];
	local[10]= local[6]->c.obj.iv[1];
	local[11]= local[6]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(*ftab[3])(ctx,4,local+8,&ftab[3],fqv[14]); /*line-intersection*/
	local[3] = w;
	if (local[3]==NIL) goto IF3112;
	local[8]= makeflt(0.0000000000000000000000e+00);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeflt(1.0000000000000000000000e+00);
	local[11]= makeflt(-1.0000000000000000208167e-03);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,4,local+8,&ftab[5],fqv[22]); /*eps-in-range*/
	if (w==NIL) goto CON3115;
	local[8]= makeflt(0.0000000000000000000000e+00);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeflt(1.0000000000000000000000e+00);
	local[11]= makeflt(-1.0000000000000000208167e-03);
	ctx->vsp=local+12;
	w=(*ftab[5])(ctx,4,local+8,&ftab[5],fqv[22]); /*eps-in-range*/
	if (w==NIL) goto CON3115;
	w = T;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK3099;
	goto CON3114;
CON3115:
	local[8]= NIL;
CON3114:
	goto IF3113;
IF3112:
	local[8]= NIL;
IF3113:
	goto WHL3108;
WHX3109:
	local[8]= NIL;
BLK3110:
	w = NIL;
	goto WHL3103;
WHX3104:
	local[6]= NIL;
BLK3105:
	w = NIL;
	local[4]= NIL;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= NIL;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL3117:
	if (local[9]==NIL) goto WHX3118;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[2];
	local[11]= fqv[23];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[4];
	if (T!=local[10]) goto CON3122;
	w = T;
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3099;
	goto CON3121;
CON3122:
	local[10]= local[4];
	if (NIL!=local[10]) goto CON3123;
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[6] = w;
	local[10]= local[6];
	goto CON3121;
CON3123:
	local[10]= local[4];
	if (fqv[17]!=local[10]) goto CON3124;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[7] = w;
	local[10]= local[7];
	goto CON3121;
CON3124:
	local[10]= NIL;
CON3121:
	goto WHL3117;
WHX3118:
	local[10]= NIL;
BLK3119:
	w = NIL;
	local[8]= NIL;
	local[9]= argv[2];
	local[10]= fqv[24];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL3126:
	if (local[9]==NIL) goto WHX3127;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[0];
	local[11]= fqv[23];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[4];
	if (T!=local[10]) goto CON3131;
	w = T;
	ctx->vsp=local+10;
	local[0]=w;
	goto BLK3099;
	goto CON3130;
CON3131:
	local[10]= local[4];
	if (NIL!=local[10]) goto CON3132;
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[6] = w;
	local[10]= local[6];
	goto CON3130;
CON3132:
	local[10]= local[4];
	if (fqv[17]!=local[10]) goto CON3133;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[7] = w;
	local[10]= local[7];
	goto CON3130;
CON3133:
	local[10]= NIL;
CON3130:
	goto WHL3126;
WHX3127:
	local[10]= NIL;
BLK3128:
	w = NIL;
	local[8]= local[7];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto IF3134;
	local[8]= fqv[17];
	goto IF3135;
IF3134:
	local[8]= NIL;
IF3135:
	w = local[8];
	local[0]= w;
	goto IF3101;
IF3100:
	local[0]= NIL;
IF3101:
	w = local[0];
	local[0]= w;
BLK3099:
	ctx->vsp=local; return(local[0]);}

/*:distance-point*/
static pointer M3136polygon2d_distance_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[25]);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[26];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,3,local+1,&ftab[6],fqv[27]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK3137:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M3138polygon2d_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[28];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= loadglobal(fqv[5]);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON3141;
	local[1]= fqv[17];
	goto CON3140;
CON3141:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w==NIL) goto CON3142;
	local[1]= fqv[29];
	goto CON3140;
CON3142:
	local[1]= local[0];
	goto CON3140;
CON3143:
	local[1]= NIL;
CON3140:
	w = local[1];
	local[0]= w;
BLK3139:
	ctx->vsp=local; return(local[0]);}

/*:3d*/
static pointer M3144polygon2d_3d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3148;}
	local[0]= makeflt(0.0000000000000000000000e+00);
ENT3148:
	if (n>=4) { local[1]=(argv[3]); goto ENT3147;}
	local[1]= loadglobal(fqv[30]);
ENT3147:
ENT3146:
	if (n>4) maerror();
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[4];
	local[5]= fqv[24];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO3150,env,argv,local);
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)BUTLAST(ctx,1,local+7); /*butlast*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK3145:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3150(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:radius*/
static pointer M3151circle2d_radius(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK3152:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M3153circle2d_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[31];
	local[2]= argv[0];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,5,local+0); /*send*/
	local[0]= w;
BLK3154:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3155circle2d_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST3157:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0]->c.obj.iv[8] = w;
	local[1]= (pointer)get_sym_func(fqv[33]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[8]));
	local[4]= fqv[4];
	local[5]= fqv[9];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,7,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK3156:
	ctx->vsp=local; return(local[0]);}

/*make-polygon2d*/
static pointer F3026make_polygon2d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST3159:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[34]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[4];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK3158:
	ctx->vsp=local; return(local[0]);}

/*make-rectangle*/
static pointer F3027make_rectangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= loadglobal(fqv[34]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[4];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,1,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,2,local+5); /*float-vector*/
	local[5]= w;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,2,local+6); /*float-vector*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,2,local+8); /*float-vector*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,4,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK3161:
	ctx->vsp=local; return(local[0]);}

/*make-circle*/
static pointer F3028make_circle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST3164:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[35]);
	local[2]= loadglobal(fqv[36]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[4];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK3163:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M3165polygon2d_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3168;}
	local[0]= NIL;
ENT3168:
ENT3167:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3169;
	local[1]= argv[2];
	local[2]= fqv[37];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3170;
IF3169:
	local[1]= NIL;
IF3170:
	local[1]= argv[2];
	local[2]= fqv[38];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3166:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill*/
static pointer M3171polygon2d_draw_fill(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3174;}
	local[0]= NIL;
ENT3174:
ENT3173:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3175;
	local[1]= argv[2];
	local[2]= fqv[37];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3176;
IF3175:
	local[1]= NIL;
IF3176:
	local[1]= argv[2];
	local[2]= fqv[39];
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3172:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___polygon(ctx,n,argv,env)
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
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[34];
	local[1]= fqv[41];
	local[2]= fqv[34];
	local[3]= fqv[42];
	local[4]= loadglobal(fqv[43]);
	local[5]= fqv[44];
	local[6]= fqv[45];
	local[7]= fqv[46];
	local[8]= NIL;
	local[9]= fqv[47];
	local[10]= NIL;
	local[11]= fqv[48];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[49];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,13,local+2,&ftab[7],fqv[50]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3029polygon2d_vertices,fqv[24],fqv[34],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3031polygon2d_lines,fqv[21],fqv[34],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3033polygon2d_edges,fqv[0],fqv[34],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3039polygon2d_drawners,fqv[54],fqv[34],fqv[55]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3041polygon2d_box,fqv[2],fqv[34],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3043polygon2d_boxtest,fqv[20],fqv[34],fqv[57]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3047polygon2d_update,fqv[58],fqv[34],fqv[59]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3054polygon2d_set_convexp,fqv[13],fqv[34],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3062polygon2d_init,fqv[4],fqv[34],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3068polygon2d_intersect_line,fqv[18],fqv[34],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3083polygon2d_on_edge,fqv[16],fqv[34],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3094polygon2d_insidep,fqv[23],fqv[34],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3098polygon2d_intersect_polygon2d,fqv[65],fqv[34],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3136polygon2d_distance_point,fqv[28],fqv[34],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3138polygon2d_distance,fqv[26],fqv[34],fqv[68]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3144polygon2d_3d,fqv[69],fqv[34],fqv[70]);
	local[0]= fqv[36];
	local[1]= fqv[41];
	local[2]= fqv[36];
	local[3]= fqv[42];
	local[4]= loadglobal(fqv[43]);
	local[5]= fqv[44];
	local[6]= fqv[71];
	local[7]= fqv[46];
	local[8]= NIL;
	local[9]= fqv[47];
	local[10]= NIL;
	local[11]= fqv[48];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[49];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[7])(ctx,13,local+2,&ftab[7],fqv[50]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3151circle2d_radius,fqv[72],fqv[36],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3153circle2d_draw,fqv[74],fqv[36],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3155circle2d_init,fqv[4],fqv[36],fqv[76]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[77],module,F3026make_polygon2d,fqv[78]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F3027make_rectangle,fqv[80]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[81],module,F3028make_circle,fqv[82]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3165polygon2d_draw,fqv[74],fqv[34],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3171polygon2d_draw_fill,fqv[84],fqv[34],fqv[85]);
	local[0]= fqv[86];
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[88]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<9; i++) ftab[i]=fcallx;
}
