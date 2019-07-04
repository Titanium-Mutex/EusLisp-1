/* ./hid.c :  entry=hid */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "hid.h"
#pragma init (register_hid)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___hid();
extern pointer build_quote_vector();
static int register_hid()
  { add_module_initializer("___hid", ___hid);}

static pointer F3178check_visibility();
static pointer F3180make_face_image();
static pointer F3181set_contour_intersections();
static pointer F3182set_non_contour_intersections();
static pointer F3183curved_edge_image_p();
static pointer F3184hid2();

/*check-visibility*/
static pointer F3178check_visibility(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= makeflt(0.0000000000000000000000e+00);
	w = local[1];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[0],w);
	local[5]= NIL;
	local[6]= loadglobal(fqv[1]);
WHL3188:
	if (local[6]==NIL) goto WHX3189;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[0] = local[5]->c.obj.iv[2];
	local[7]= local[0];
	if (argv[0]==local[7]) goto IF3192;
	local[7]= local[0];
	if (argv[1]==local[7]) goto IF3192;
	local[7]= local[5];
	local[8]= fqv[2];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto IF3192;
	local[7]= local[0];
	local[8]= fqv[3];
	local[9]= argv[2];
	local[10]= argv[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w==NIL) goto IF3192;
	w = NIL;
	ctx->vsp=local+7;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK3186;
	goto IF3193;
IF3192:
	local[7]= NIL;
IF3193:
	goto WHL3188;
WHX3189:
	local[7]= NIL;
BLK3190:
	w = NIL;
	local[5]= T;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK3186:
	ctx->vsp=local; return(local[0]);}

/*:edge3*/
static pointer M3195edge_image_edge3(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK3196:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M3197edge_image_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK3198:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M3199edge_image_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3200:
	ctx->vsp=local; return(local[0]);}

/*:homo2real*/
static pointer M3201edge_image_homo2real(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)3L));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	{ double x,y;
		y=fltval(w); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	local[1]= local[0];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)3L));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	local[4]= makeflt(1.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[4]);
		local[4]=(makeflt(x - y));}
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[3]);
		local[3]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[3]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK3202:
	ctx->vsp=local; return(local[0]);}

/*:add-segment*/
static pointer M3203edge_image_add_segment(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3206;}
	local[0]= NIL;
ENT3206:
ENT3205:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)3L));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x * y));}
	local[2]= local[1];
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[2];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)3L));
	  w=makeflt(local[4]->c.fvec.fv[i]);}
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(makeflt(-(fltval(argv[2])))); x=fltval(local[5]);
		local[5]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(local[5]); x=fltval(local[4]);
		local[4]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[4]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[1] = w;
	local[2]= local[1];
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[2]);
	if (left < right) goto IF3207;}
	local[2]= local[1];
	{ double left,right;
		right=fltval(makeflt(1.0000000000000000000000e+00)); left=fltval(local[2]);
	if (left > right) goto IF3207;}
	local[2]= argv[2];
	local[3]= local[1];
	local[4]= T;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[5] = cons(ctx,local[2],w);
	local[2]= argv[0]->c.obj.iv[5];
	goto IF3208;
IF3207:
	local[2]= NIL;
IF3208:
	w = local[2];
	local[0]= w;
BLK3204:
	ctx->vsp=local; return(local[0]);}

/*:projected-point*/
static pointer M3209edge_image_projected_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK3210:
	ctx->vsp=local; return(local[0]);}

/*:projected-homo-point*/
static pointer M3211edge_image_projected_homo_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(argv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK3212:
	ctx->vsp=local; return(local[0]);}

/*:intersecting-point*/
static pointer M3213edge_image_intersecting_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2]->c.obj.iv[3];
	local[3]= argv[2]->c.obj.iv[4];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,5,local+0,&ftab[0],fqv[5]); /*line-intersection*/
	local[0]= w;
	if (local[0]==NIL) goto IF3215;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[6];
	local[3]= argv[0];
	local[4]= fqv[7];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3216;
IF3215:
	local[1]= NIL;
IF3216:
	w = local[1];
	local[0]= w;
BLK3214:
	ctx->vsp=local; return(local[0]);}

/*:projected-intersection*/
static pointer M3217edge_image_projected_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[2]->c.obj.iv[3];
	local[3]= argv[2]->c.obj.iv[4];
	local[4]= T;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,5,local+0,&ftab[0],fqv[5]); /*line-intersection*/
	local[0]= w;
	if (local[0]==NIL) goto IF3219;
	local[1]= argv[0];
	local[2]= fqv[8];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	if (argv[3]==NIL) goto IF3221;
	local[1]= argv[2];
	local[2]= fqv[8];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF3222;
IF3221:
	local[1]= NIL;
IF3222:
	goto IF3220;
IF3219:
	local[1]= NIL;
IF3220:
	w = local[1];
	local[0]= w;
BLK3218:
	ctx->vsp=local; return(local[0]);}

/*:sort-segments*/
static pointer M3223edge_image_sort_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= (pointer)get_sym_func(fqv[9]);
	local[2]= (pointer)get_sym_func(fqv[10]);
	ctx->vsp=local+3;
	w=(pointer)SORT(ctx,3,local+0); /*sort*/
	argv[0]->c.obj.iv[5] = w;
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK3224:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M3225edge_image_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[11]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[12];
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK3226:
	ctx->vsp=local; return(local[0]);}

/*:contourp*/
static pointer M3228edge_image_contourp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK3229:
	ctx->vsp=local; return(local[0]);}

/*:mark-visible-segments*/
static pointer M3230edge_image_mark_visible_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	local[6]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL3233:
	if (local[7]==NIL) goto WHX3234;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[0];
	local[9]= fqv[13];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	{ double x,y;
		y=fltval((w)->c.cons.car); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[3] = w;
	local[8]= argv[0]->c.obj.iv[0];
	local[9]= fqv[6];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	{ double x,y;
		y=fltval((w)->c.cons.car); x=fltval(local[10]);
		local[10]=(makeflt(x + y));}
	local[11]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[1] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	local[9]= local[4];
	local[10]= local[5];
	local[11]= local[1];
	local[12]= local[3];
	local[13]= argv[2];
	ctx->vsp=local+14;
	w=(pointer)F3178check_visibility(ctx,5,local+9); /*check-visibility*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)RPLACA2(ctx,2,local+8); /*rplaca2*/
	local[0] = local[6];
	goto WHL3233;
WHX3234:
	local[8]= NIL;
BLK3235:
	w = NIL;
	local[0]= w;
BLK3231:
	ctx->vsp=local; return(local[0]);}

/*:visible-face*/
static pointer M3237edge_image_visible_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0]->c.obj.iv[3];
	local[1]= argv[0]->c.obj.iv[0]->c.obj.iv[4];
	local[2]= local[0];
	w = loadglobal(fqv[14]);
	if (memq(local[2],w)==NIL) goto IF3239;
	local[2]= local[0];
	goto IF3240;
IF3239:
	local[2]= local[1];
IF3240:
	w = local[2];
	local[0]= w;
BLK3238:
	ctx->vsp=local; return(local[0]);}

/*:collect-segments*/
static pointer M3241edge_image_collect_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
WHL3244:
	if (local[6]==NIL) goto WHX3245;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	if (argv[2]!=local[7]) goto IF3248;
	local[7]= argv[0];
	local[8]= fqv[15];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[2] = w;
	local[7]= argv[0];
	local[8]= fqv[15];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[3] = w;
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,2,local+7,&ftab[1],fqv[16]); /*homo-viewport-clip*/
	local[4] = w;
	if (local[4]==NIL) goto IF3250;
	local[7]= local[4];
	w = local[0];
	ctx->vsp=local+8;
	local[0] = cons(ctx,local[7],w);
	local[7]= local[0];
	goto IF3251;
IF3250:
	local[7]= NIL;
IF3251:
	goto IF3249;
IF3248:
	local[7]= NIL;
IF3249:
	local[1] = local[5];
	goto WHL3244;
WHX3245:
	local[7]= NIL;
BLK3246:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK3242:
	ctx->vsp=local; return(local[0]);}

/*:visible-segments*/
static pointer M3252edge_image_visible_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= T;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3253:
	ctx->vsp=local; return(local[0]);}

/*:invisible-segments*/
static pointer M3254edge_image_invisible_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= NIL;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3255:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M3256edge_image_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3259;}
	local[0]= argv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
ENT3259:
ENT3258:
	if (n>5) maerror();
	argv[0]->c.obj.iv[0] = argv[2];
	local[1]= argv[3];
	local[2]= fqv[19];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[3];
	local[2]= fqv[19];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[20]); /*homo2normal*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[20]); /*homo2normal*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	local[2]= makeflt(1.0000000000000000000000e+00);
	local[3]= makeflt(1.0000000000000000000000e+00);
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[0]->c.obj.iv[5] = w;
	local[1]= argv[2];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[6] = w;
	w = argv[0];
	local[0]= w;
BLK3257:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3260edge_image_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[22], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY3262;
	local[0] = NIL;
KEY3262:
	if (n & (1<<1)) goto KEY3263;
	local[1] = NIL;
KEY3263:
	if (n & (1<<2)) goto KEY3264;
	local[2] = NIL;
KEY3264:
	if (n & (1<<3)) goto KEY3265;
	local[3] = NIL;
KEY3265:
	if (n & (1<<4)) goto KEY3266;
	local[4] = NIL;
KEY3266:
	if (local[0]==NIL) goto IF3267;
	argv[0]->c.obj.iv[0] = local[0];
	local[5]= argv[0]->c.obj.iv[0];
	goto IF3268;
IF3267:
	local[5]= NIL;
IF3268:
	if (local[1]==NIL) goto IF3269;
	argv[0]->c.obj.iv[1] = local[1];
	local[5]= argv[0]->c.obj.iv[1];
	goto IF3270;
IF3269:
	local[5]= NIL;
IF3270:
	if (local[2]==NIL) goto IF3271;
	argv[0]->c.obj.iv[2] = local[2];
	local[5]= argv[0]->c.obj.iv[2];
	goto IF3272;
IF3271:
	local[5]= NIL;
IF3272:
	if (local[3]==NIL) goto IF3273;
	argv[0]->c.obj.iv[3] = local[3];
	local[5]= argv[0]->c.obj.iv[3];
	goto IF3274;
IF3273:
	local[5]= NIL;
IF3274:
	if (local[4]==NIL) goto IF3275;
	argv[0]->c.obj.iv[4] = local[4];
	local[5]= argv[0]->c.obj.iv[4];
	goto IF3276;
IF3275:
	local[5]= NIL;
IF3276:
	w = argv[0];
	local[0]= w;
BLK3261:
	ctx->vsp=local; return(local[0]);}

/*:face3d*/
static pointer M3277face_image_face3d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK3278:
	ctx->vsp=local; return(local[0]);}

/*:possibly-hiding*/
static pointer M3279face_image_possibly_hiding(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[23];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3280:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M3281face_image_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3282:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3283face_image_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[3];
WHL3286:
	if (local[2]==NIL) goto WHX3287;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	if (local[1]==NIL) goto IF3290;
	local[3]= local[1];
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF3291;
IF3290:
	local[3]= NIL;
IF3291:
	goto WHL3286;
WHX3287:
	local[3]= NIL;
BLK3288:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[26]); /*flatten*/
	local[0] = w;
	argv[0]->c.obj.iv[2] = argv[2];
	argv[0]->c.obj.iv[1] = argv[3];
	local[1]= loadglobal(fqv[11]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[27];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[28];
	local[3]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[0]->c.obj.iv[1];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= makeflt(1.0000000000000000000000e+20);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	w = argv[0];
	local[0]= w;
BLK3284:
	ctx->vsp=local; return(local[0]);}

/*make-face-image*/
static pointer F3180make_face_image(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[29]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[27];
	local[3]= argv[0];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO3295,env,argv,local);
	local[5]= argv[0];
	local[6]= fqv[30];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK3293:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3295(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[31]); /*gethash*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*set-contour-intersections*/
static pointer F3181set_contour_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
WHL3297:
	if (argv[0]==NIL) goto WHX3298;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= local[0]->c.obj.iv[0];
	local[2]= local[1]->c.obj.iv[3];
	local[3]= local[1]->c.obj.iv[4];
	if (local[2]==NIL) goto IF3301;
	local[4]= local[2]->c.obj.iv[4];
	goto IF3302;
IF3301:
	local[4]= NIL;
IF3302:
	if (local[3]==NIL) goto IF3303;
	local[5]= local[3]->c.obj.iv[4];
	goto IF3304;
IF3303:
	local[5]= NIL;
IF3304:
	local[6]= NIL;
	local[7]= argv[0];
WHL3306:
	if (local[7]==NIL) goto WHX3307;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6]->c.obj.iv[0];
	w = local[4];
	if (memq(local[8],w)!=NIL) goto IF3310;
	local[8]= local[6]->c.obj.iv[0];
	w = local[5];
	if (memq(local[8],w)!=NIL) goto IF3310;
	local[8]= local[0];
	local[9]= fqv[32];
	local[10]= local[6];
	local[11]= T;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto IF3311;
IF3310:
	local[8]= NIL;
IF3311:
	goto WHL3306;
WHX3307:
	local[8]= NIL;
BLK3308:
	w = NIL;
	goto WHL3297;
WHX3298:
	local[0]= NIL;
BLK3299:
	w = local[0];
	local[0]= w;
BLK3296:
	ctx->vsp=local; return(local[0]);}

/*set-non-contour-intersections*/
static pointer F3182set_non_contour_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
WHL3314:
	if (local[1]==NIL) goto WHX3315;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0]->c.obj.iv[0];
	local[3]= local[2]->c.obj.iv[3];
	local[4]= local[2]->c.obj.iv[4];
	if (local[3]==NIL) goto IF3318;
	local[5]= local[3]->c.obj.iv[4];
	goto IF3319;
IF3318:
	local[5]= NIL;
IF3319:
	if (local[4]==NIL) goto IF3320;
	local[6]= local[4]->c.obj.iv[4];
	goto IF3321;
IF3320:
	local[6]= NIL;
IF3321:
	local[7]= NIL;
	local[8]= argv[1];
WHL3323:
	if (local[8]==NIL) goto WHX3324;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7]->c.obj.iv[0];
	w = local[5];
	if (memq(local[9],w)!=NIL) goto IF3327;
	local[9]= local[7]->c.obj.iv[0];
	w = local[6];
	if (memq(local[9],w)!=NIL) goto IF3327;
	local[9]= local[0];
	local[10]= fqv[32];
	local[11]= local[7];
	local[12]= NIL;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,4,local+9); /*send*/
	local[9]= w;
	goto IF3328;
IF3327:
	local[9]= NIL;
IF3328:
	goto WHL3323;
WHX3324:
	local[9]= NIL;
BLK3325:
	w = NIL;
	goto WHL3314;
WHX3315:
	local[2]= NIL;
BLK3316:
	w = NIL;
	local[0]= w;
BLK3312:
	ctx->vsp=local; return(local[0]);}

/*curved-edge-image-p*/
static pointer F3183curved_edge_image_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[33]);
	if (local[0]==NIL) goto AND3330;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
AND3330:
	w = local[0];
	local[0]= w;
BLK3329:
	ctx->vsp=local; return(local[0]);}

/*hid2*/
static pointer F3184hid2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3333;}
	local[0]= NIL;
ENT3333:
ENT3332:
	if (n>3) maerror();
	local[1]= fqv[35];
	local[2]= makeint((eusinteger_t)100L);
	local[3]= fqv[36];
	local[4]= (pointer)get_sym_func(fqv[37]);
	local[5]= fqv[38];
	local[6]= (pointer)get_sym_func(fqv[39]);
	ctx->vsp=local+7;
	w=(*ftab[5])(ctx,6,local+1,&ftab[5],fqv[40]); /*make-hash-table*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)RUNTIME(ctx,0,local+3); /*unix:runtime*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	storeglobal(fqv[14],NIL);
	storeglobal(fqv[1],NIL);
	storeglobal(fqv[41],NIL);
	storeglobal(fqv[42],NIL);
	storeglobal(fqv[43],NIL);
	storeglobal(fqv[44],NIL);
	storeglobal(fqv[45],NIL);
	local[8]= NIL;
	storeglobal(fqv[46],local[8]);
	local[8]= NIL;
	local[9]= argv[0];
WHL3335:
	if (local[9]==NIL) goto WHX3336;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[8];
	local[13]= loadglobal(fqv[47]);
	ctx->vsp=local+14;
	w=(pointer)DERIVEDP(ctx,2,local+12); /*derivedp*/
	if (w==NIL) goto IF3339;
	local[12]= local[8];
	local[13]= fqv[48];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	goto IF3340;
IF3339:
	local[12]= NIL;
IF3340:
	local[12]= NIL;
	local[13]= local[8];
	local[14]= loadglobal(fqv[47]);
	ctx->vsp=local+15;
	w=(pointer)DERIVEDP(ctx,2,local+13); /*derivedp*/
	if (w==NIL) goto IF3342;
	local[13]= local[8];
	local[14]= fqv[49];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	goto IF3343;
IF3342:
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
IF3343:
WHL3344:
	if (local[13]==NIL) goto WHX3345;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[12];
	local[15]= fqv[50];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+16;
	w=(pointer)GREATERP(ctx,2,local+14); /*>*/
	if (w==NIL) goto IF3348;
	local[14]= local[12];
	w = local[10];
	ctx->vsp=local+15;
	local[10] = cons(ctx,local[14],w);
	local[14]= local[10];
	goto IF3349;
IF3348:
	local[14]= NIL;
IF3349:
	goto WHL3344;
WHX3345:
	local[14]= NIL;
BLK3346:
	w = NIL;
	local[12]= (pointer)get_sym_func(fqv[51]);
	local[13]= local[10];
	local[14]= fqv[52];
	ctx->vsp=local+15;
	w=(*ftab[6])(ctx,2,local+13,&ftab[6],fqv[53]); /*send-all*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,2,local+12); /*apply*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[7])(ctx,1,local+12,&ftab[7],fqv[54]); /*remove-duplicates*/
	local[11] = w;
	local[12]= loadglobal(fqv[42]);
	local[13]= local[8];
	local[14]= fqv[52];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(*ftab[8])(ctx,2,local+13,&ftab[8],fqv[55]); /*set-difference*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	storeglobal(fqv[42],w);
	local[12]= local[11];
	local[13]= loadglobal(fqv[41]);
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	storeglobal(fqv[41],w);
	local[12]= local[10];
	local[13]= loadglobal(fqv[14]);
	ctx->vsp=local+14;
	w=(pointer)NCONC(ctx,2,local+12); /*nconc*/
	local[12]= w;
	storeglobal(fqv[14],w);
	w = local[12];
	goto WHL3335;
WHX3336:
	local[10]= NIL;
BLK3337:
	w = NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[41]);
WHL3351:
	if (local[9]==NIL) goto WHX3352;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= loadglobal(fqv[56]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[57];
	local[13]= local[8];
	local[14]= argv[1];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	w = local[10];
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[21];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	if (w==NIL) goto IF3356;
	local[11]= local[10];
	w = loadglobal(fqv[44]);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	storeglobal(fqv[44],local[11]);
	goto IF3357;
IF3356:
	local[11]= local[10];
	ctx->vsp=local+12;
	w=(pointer)F3183curved_edge_image_p(ctx,1,local+11); /*curved-edge-image-p*/
	if (w!=NIL) goto IF3358;
	local[11]= local[10];
	w = loadglobal(fqv[45]);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	storeglobal(fqv[45],local[11]);
	goto IF3359;
IF3358:
	local[11]= NIL;
IF3359:
IF3357:
	local[11]= local[8];
	local[12]= local[1];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(*ftab[9])(ctx,3,local+11,&ftab[9],fqv[58]); /*sethash*/
	goto WHL3351;
WHX3352:
	local[10]= NIL;
BLK3353:
	w = NIL;
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[5] = w;
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,CLO3360,env,argv,local);
	local[9]= loadglobal(fqv[14]);
	ctx->vsp=local+10;
	w=(pointer)MAPCAR(ctx,2,local+8); /*mapcar*/
	local[8]= w;
	storeglobal(fqv[1],w);
	local[8]= loadglobal(fqv[44]);
	ctx->vsp=local+9;
	w=(pointer)F3181set_contour_intersections(ctx,1,local+8); /*set-contour-intersections*/
	local[8]= loadglobal(fqv[45]);
	local[9]= loadglobal(fqv[44]);
	ctx->vsp=local+10;
	w=(pointer)F3182set_non_contour_intersections(ctx,2,local+8); /*set-non-contour-intersections*/
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[60];
	local[13]= fqv[61];
	local[14]= fqv[62];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[63];
	local[13]= fqv[61];
	local[14]= fqv[64];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[65];
	local[13]= fqv[61];
	local[14]= fqv[66];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= loadglobal(fqv[56]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= local[8];
	local[10]= fqv[27];
	local[11]= fqv[59];
	local[12]= fqv[67];
	local[13]= fqv[61];
	local[14]= fqv[68];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,6,local+9); /*send*/
	w = local[8];
	local[8]= w;
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= NIL;
	local[9]= local[4];
WHL3366:
	if (local[9]==NIL) goto WHX3367;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= loadglobal(fqv[44]);
WHL3371:
	if (local[11]==NIL) goto WHX3372;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10];
	local[13]= fqv[32];
	local[14]= local[8];
	local[15]= NIL;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	goto WHL3371;
WHX3372:
	local[12]= NIL;
BLK3373:
	w = NIL;
	local[10]= NIL;
	local[11]= loadglobal(fqv[45]);
WHL3376:
	if (local[11]==NIL) goto WHX3377;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10];
	local[13]= fqv[32];
	local[14]= local[8];
	local[15]= NIL;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	goto WHL3376;
WHX3377:
	local[12]= NIL;
BLK3378:
	w = NIL;
	goto WHL3366;
WHX3367:
	local[10]= NIL;
BLK3368:
	w = NIL;
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[6] = w;
	local[8]= loadglobal(fqv[44]);
	local[9]= loadglobal(fqv[45]);
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	storeglobal(fqv[69],w);
	local[8]= loadglobal(fqv[69]);
	local[9]= fqv[70];
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,2,local+8,&ftab[6],fqv[53]); /*send-all*/
	local[8]= loadglobal(fqv[69]);
	local[9]= fqv[71];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,3,local+8,&ftab[6],fqv[53]); /*send-all*/
	ctx->vsp=local+8;
	w=(pointer)RUNTIME(ctx,0,local+8); /*unix:runtime*/
	local[7] = w;
	local[8]= local[5];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[6];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,2,local+9); /*-*/
	local[9]= w;
	local[10]= local[7];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,2,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PRINT(ctx,1,local+8); /*print*/
	local[0]= w;
BLK3331:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3360(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	local[2]= env->c.clo.env2[2];
	ctx->vsp=local+3;
	w=(pointer)F3180make_face_image(ctx,3,local+0); /*make-face-image*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___hid(ctx,n,argv,env)
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
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF3380;
	local[0]= fqv[73];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[74],w);
	goto IF3381;
IF3380:
	local[0]= fqv[75];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF3381:
	local[0]= fqv[76];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[14];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3382;
	local[0]= fqv[14];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[14];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3384;
	local[0]= fqv[14];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3385;
IF3384:
	local[0]= NIL;
IF3385:
	local[0]= fqv[14];
	goto IF3383;
IF3382:
	local[0]= NIL;
IF3383:
	local[0]= fqv[1];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3386;
	local[0]= fqv[1];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[1];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3388;
	local[0]= fqv[1];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3389;
IF3388:
	local[0]= NIL;
IF3389:
	local[0]= fqv[1];
	goto IF3387;
IF3386:
	local[0]= NIL;
IF3387:
	local[0]= fqv[41];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3390;
	local[0]= fqv[41];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3392;
	local[0]= fqv[41];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3393;
IF3392:
	local[0]= NIL;
IF3393:
	local[0]= fqv[41];
	goto IF3391;
IF3390:
	local[0]= NIL;
IF3391:
	local[0]= fqv[44];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3394;
	local[0]= fqv[44];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3396;
	local[0]= fqv[44];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3397;
IF3396:
	local[0]= NIL;
IF3397:
	local[0]= fqv[44];
	goto IF3395;
IF3394:
	local[0]= NIL;
IF3395:
	local[0]= fqv[69];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3398;
	local[0]= fqv[69];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3400;
	local[0]= fqv[69];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3401;
IF3400:
	local[0]= NIL;
IF3401:
	local[0]= fqv[69];
	goto IF3399;
IF3398:
	local[0]= NIL;
IF3399:
	local[0]= fqv[46];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3402;
	local[0]= fqv[46];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3404;
	local[0]= fqv[46];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3405;
IF3404:
	local[0]= NIL;
IF3405:
	local[0]= fqv[46];
	goto IF3403;
IF3402:
	local[0]= NIL;
IF3403:
	local[0]= fqv[45];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3406;
	local[0]= fqv[45];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3408;
	local[0]= fqv[45];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3409;
IF3408:
	local[0]= NIL;
IF3409:
	local[0]= fqv[45];
	goto IF3407;
IF3406:
	local[0]= NIL;
IF3407:
	local[0]= fqv[42];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3410;
	local[0]= fqv[42];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3412;
	local[0]= fqv[42];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3413;
IF3412:
	local[0]= NIL;
IF3413:
	local[0]= fqv[42];
	goto IF3411;
IF3410:
	local[0]= NIL;
IF3411:
	local[0]= fqv[43];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3414;
	local[0]= fqv[43];
	local[1]= fqv[77];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3416;
	local[0]= fqv[43];
	local[1]= fqv[78];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3417;
IF3416:
	local[0]= NIL;
IF3417:
	local[0]= fqv[43];
	goto IF3415;
IF3414:
	local[0]= NIL;
IF3415:
	local[0]= fqv[33];
	local[1]= fqv[79];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F3178check_visibility,fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3195edge_image_edge3,fqv[82],fqv[56],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3197edge_image_vertices,fqv[25],fqv[56],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3199edge_image_color,fqv[4],fqv[56],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3201edge_image_homo2real,fqv[7],fqv[56],fqv[86]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3203edge_image_add_segment,fqv[8],fqv[56],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3209edge_image_projected_point,fqv[13],fqv[56],fqv[88]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3211edge_image_projected_homo_point,fqv[15],fqv[56],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3213edge_image_intersecting_point,fqv[90],fqv[56],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3217edge_image_projected_intersection,fqv[32],fqv[56],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3223edge_image_sort_segments,fqv[70],fqv[56],fqv[93]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3225edge_image_box,fqv[94],fqv[56],fqv[95]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3228edge_image_contourp,fqv[21],fqv[56],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3230edge_image_mark_visible_segments,fqv[71],fqv[56],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3237edge_image_visible_face,fqv[98],fqv[56],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3241edge_image_collect_segments,fqv[17],fqv[56],fqv[100]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3252edge_image_visible_segments,fqv[101],fqv[56],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3254edge_image_invisible_segments,fqv[103],fqv[56],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3256edge_image_project,fqv[57],fqv[56],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3260edge_image_init,fqv[27],fqv[56],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3277face_image_face3d,fqv[107],fqv[29],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3279face_image_possibly_hiding,fqv[2],fqv[29],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3281face_image_boxtest,fqv[110],fqv[29],fqv[111]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3283face_image_init,fqv[27],fqv[29],fqv[112]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[113],module,F3180make_face_image,fqv[114]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[115],module,F3181set_contour_intersections,fqv[116]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[117],module,F3182set_non_contour_intersections,fqv[118]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[119],module,F3183curved_edge_image_p,fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F3184hid2,fqv[122]);
	local[0]= fqv[123];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[125]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<11; i++) ftab[i]=fcallx;
}
