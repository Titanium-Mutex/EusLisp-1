/* ./viewport.c :  entry=viewport */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "viewport.h"
#pragma init (register_viewport)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___viewport();
extern pointer build_quote_vector();
static int register_viewport()
  { add_module_initializer("___viewport", ___viewport);}

static pointer F3714draw();
static pointer F3715draw_tree();
static pointer F3716erase();
static pointer F3717draw_axis();
static pointer F3718draw_arrow();
static pointer F3719hid();
static pointer F3720hidd();
static pointer F3721cls();
static pointer F3722draw_hid();
static pointer F3723draw_step();
static pointer F3724find_viewer();
static pointer F3725view();

/*:xcenter*/
static pointer M3727viewport_xcenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3730;}
	local[0]= NIL;
ENT3730:
ENT3729:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3731;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= w;
	goto IF3732;
IF3731:
	local[1]= NIL;
IF3732:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[0]= w;
BLK3728:
	ctx->vsp=local; return(local[0]);}

/*:ycenter*/
static pointer M3733viewport_ycenter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3736;}
	local[0]= NIL;
ENT3736:
ENT3735:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3737;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= w;
	goto IF3738;
IF3737:
	local[1]= NIL;
IF3738:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[0]= w;
BLK3734:
	ctx->vsp=local; return(local[0]);}

/*:center*/
static pointer M3739viewport_center(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3743;}
	local[0]= NIL;
ENT3743:
	if (n>=4) { local[1]=(argv[3]); goto ENT3742;}
	local[1]= local[0];
ENT3742:
ENT3741:
	if (n>4) maerror();
	w = local[0];
	if (!isnum(w)) goto CON3745;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint((eusinteger_t)1L);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= w;
	goto CON3744;
CON3745:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3746;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint((eusinteger_t)1L);
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= w;
	goto CON3744;
CON3746:
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	goto CON3744;
CON3747:
	local[2]= NIL;
CON3744:
	w = local[2];
	local[0]= w;
BLK3740:
	ctx->vsp=local; return(local[0]);}

/*:width*/
static pointer M3748viewport_width(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3751;}
	local[0]= NIL;
ENT3751:
ENT3750:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3752;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[0];
	local[5]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= w;
	goto IF3753;
IF3752:
	local[1]= NIL;
IF3753:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,3,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0]= w;
BLK3749:
	ctx->vsp=local; return(local[0]);}

/*:height*/
static pointer M3754viewport_height(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3757;}
	local[0]= NIL;
ENT3757:
ENT3756:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF3758;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)1L);
	local[4]= local[0];
	local[5]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= w;
	goto IF3759;
IF3758:
	local[1]= NIL;
IF3759:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,3,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0]= w;
BLK3755:
	ctx->vsp=local; return(local[0]);}

/*:size*/
static pointer M3760viewport_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3764;}
	local[0]= NIL;
ENT3764:
	if (n>=4) { local[1]=(argv[3]); goto ENT3763;}
	local[1]= local[0];
ENT3763:
ENT3762:
	if (n>4) maerror();
	w = local[0];
	if (!isnum(w)) goto CON3766;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[0];
	local[6]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint((eusinteger_t)1L);
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[1];
	local[6]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= w;
	goto CON3765;
CON3766:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON3767;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= makeint((eusinteger_t)1L);
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,4,local+2); /*aset*/
	local[2]= w;
	goto CON3765;
CON3767:
	local[2]= makeflt(2.0000000000000000000000e+00);
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,3,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeflt(2.0000000000000000000000e+00);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,3,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	goto CON3765;
CON3768:
	local[2]= NIL;
CON3765:
	w = local[2];
	local[0]= w;
BLK3761:
	ctx->vsp=local; return(local[0]);}

/*:screen-point-to-ndc*/
static pointer M3769viewport_screen_point_to_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*inverse-matrix*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,3,local+2); /*v-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[0]= w;
BLK3770:
	ctx->vsp=local; return(local[0]);}

/*:ndc-width-to-screen*/
static pointer M3771viewport_ndc_width_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
BLK3772:
	ctx->vsp=local; return(local[0]);}

/*:ndc-height-to-screen*/
static pointer M3773viewport_ndc_height_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)1L);
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,3,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
BLK3774:
	ctx->vsp=local; return(local[0]);}

/*:ndc-point-to-screen*/
static pointer M3775viewport_ndc_point_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	if (makeint((eusinteger_t)2L)!=local[0]) goto IF3777;
	local[0]= argv[2];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	goto IF3778;
IF3777:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
IF3778:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[0]= w;
BLK3776:
	ctx->vsp=local; return(local[0]);}

/*:ndc-line-to-screen*/
static pointer M3779viewport_ndc_line_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3782;}
	local[0]= T;
ENT3782:
ENT3781:
	if (n>5) maerror();
	if (local[0]==NIL) goto IF3783;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[2]); /*homo-viewport-clip*/
	argv[2] = w;
	if (argv[2]!=NIL) goto IF3785;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK3780;
	goto IF3786;
IF3785:
	local[1]= NIL;
IF3786:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[3] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.car;
	local[1]= argv[2];
	goto IF3784;
IF3783:
	local[1]= NIL;
IF3784:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint((eusinteger_t)3L);
	if ((eusinteger_t)local[1] <= (eusinteger_t)w) goto IF3787;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[3]); /*homo2normal*/
	argv[2] = w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[3]); /*homo2normal*/
	argv[3] = w;
	local[1]= argv[3];
	goto IF3788;
IF3787:
	local[1]= NIL;
IF3788:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint((eusinteger_t)3L);
	if ((eusinteger_t)local[1] >= (eusinteger_t)w) goto IF3789;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[4]); /*homogenize*/
	argv[2] = w;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[4]); /*homogenize*/
	argv[3] = w;
	local[1]= argv[3];
	goto IF3790;
IF3789:
	local[1]= NIL;
IF3790:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= loadglobal(fqv[5]);
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= loadglobal(fqv[5]);
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[3];
	local[3]= loadglobal(fqv[6]);
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= loadglobal(fqv[6]);
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= loadglobal(fqv[5]);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= loadglobal(fqv[5]);
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,2,local+1); /*float-vector*/
	local[1]= w;
	local[2]= loadglobal(fqv[6]);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= loadglobal(fqv[6]);
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,2,local+2); /*float-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0]= w;
BLK3780:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M3791viewport_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3793:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[7], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3794;
	local[1] = NIL;
KEY3794:
	if (n & (1<<1)) goto KEY3795;
	local[2] = NIL;
KEY3795:
	if (n & (1<<2)) goto KEY3796;
	local[3] = NIL;
KEY3796:
	if (n & (1<<3)) goto KEY3797;
	local[4] = NIL;
KEY3797:
	if (local[3]==NIL) goto IF3798;
	local[5]= argv[0];
	local[6]= fqv[8];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3799;
IF3798:
	local[5]= NIL;
IF3799:
	if (local[4]==NIL) goto IF3800;
	local[5]= argv[0];
	local[6]= fqv[9];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3801;
IF3800:
	local[5]= NIL;
IF3801:
	if (local[1]==NIL) goto IF3802;
	local[5]= argv[0];
	local[6]= fqv[10];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3803;
IF3802:
	local[5]= NIL;
IF3803:
	if (local[2]==NIL) goto IF3804;
	local[5]= argv[0];
	local[6]= fqv[11];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3805;
IF3804:
	local[5]= NIL;
IF3805:
	local[5]= argv[0];
	local[6]= fqv[12];
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	w = argv[0];
	local[0]= w;
BLK3792:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M3806viewport_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3808:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[13], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY3809;
	local[1] = makeint((eusinteger_t)3L);
KEY3809:
	if (n & (1<<1)) goto KEY3810;
	local[2] = makeint((eusinteger_t)100L);
KEY3810:
	if (n & (1<<2)) goto KEY3811;
	local[3] = makeint((eusinteger_t)100L);
KEY3811:
	if (n & (1<<3)) goto KEY3812;
	local[4] = makeint((eusinteger_t)200L);
KEY3812:
	if (n & (1<<4)) goto KEY3813;
	local[5] = makeint((eusinteger_t)200L);
KEY3813:
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[14]));
	local[8]= fqv[15];
	local[9]= fqv[16];
	local[10]= makeint((eusinteger_t)3L);
	ctx->vsp=local+11;
	w=(pointer)SENDMESSAGE(ctx,5,local+6); /*send-message*/
	local[6]= argv[0];
	local[7]= fqv[8];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[9];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[10];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[11];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[0];
	local[7]= fqv[12];
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	w = argv[0];
	local[0]= w;
BLK3807:
	ctx->vsp=local; return(local[0]);}

/*:viewing*/
static pointer M3814viewer_viewing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3816:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3817;
	local[1]= (pointer)get_sym_func(fqv[17]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3818;
IF3817:
	local[1]= argv[0]->c.obj.iv[1];
IF3818:
	w = local[1];
	local[0]= w;
BLK3815:
	ctx->vsp=local; return(local[0]);}

/*:viewsurface*/
static pointer M3819viewer_viewsurface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3821:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3822;
	local[1]= (pointer)get_sym_func(fqv[17]);
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3823;
IF3822:
	local[1]= argv[0]->c.obj.iv[3];
IF3823:
	w = local[1];
	local[0]= w;
BLK3820:
	ctx->vsp=local; return(local[0]);}

/*:viewport*/
static pointer M3824viewer_viewport(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3826:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto IF3827;
	local[1]= (pointer)get_sym_func(fqv[17]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto IF3828;
IF3827:
	local[1]= argv[0]->c.obj.iv[2];
IF3828:
	w = local[1];
	local[0]= w;
BLK3825:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M3829viewer_flush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3830:
	ctx->vsp=local; return(local[0]);}

/*:point-to-screen*/
static pointer M3831viewer_point_to_screen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[19];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[20];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[3]); /*homo2normal*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK3832:
	ctx->vsp=local; return(local[0]);}

/*:draw-point-ndc*/
static pointer M3833viewer_draw_point_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3836;}
	local[0]= NIL;
ENT3836:
ENT3835:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3837;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3838;
IF3837:
	local[1]= NIL;
IF3838:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK3834:
	ctx->vsp=local; return(local[0]);}

/*:draw-line-ndc*/
static pointer M3839viewer_draw_line_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3843;}
	local[0]= T;
ENT3843:
	if (n>=6) { local[1]=(argv[5]); goto ENT3842;}
	local[1]= NIL;
ENT3842:
ENT3841:
	if (n>6) maerror();
	if (local[1]==NIL) goto IF3844;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[21];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3845;
IF3844:
	local[2]= NIL;
IF3845:
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[23];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	argv[2] = w;
	if (argv[2]==NIL) goto IF3846;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[24];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF3847;
IF3846:
	local[2]= NIL;
IF3847:
	w = NIL;
	local[0]= w;
BLK3840:
	ctx->vsp=local; return(local[0]);}

/*:draw-string-ndc*/
static pointer M3848viewer_draw_string_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[25],w);
	if (n>=5) { local[3]=(argv[4]); goto ENT3851;}
	local[3]= NIL;
ENT3851:
ENT3850:
	if (n>5) maerror();
	if (local[3]==NIL) goto IF3852;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[21];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3853;
IF3852:
	local[4]= NIL;
IF3853:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[19];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	argv[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[26];
	local[6]= argv[2];
	local[7]= loadglobal(fqv[25]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK3849:
	ctx->vsp=local; return(local[0]);}

/*:draw-image-string-ndc*/
static pointer M3854viewer_draw_image_string_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[25],w);
	if (n>=5) { local[3]=(argv[4]); goto ENT3857;}
	local[3]= NIL;
ENT3857:
ENT3856:
	if (n>5) maerror();
	if (local[3]==NIL) goto IF3858;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[21];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF3859;
IF3858:
	local[4]= NIL;
IF3859:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[19];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	argv[2] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[27];
	local[6]= argv[2];
	local[7]= loadglobal(fqv[25]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	unbindx(ctx,1);
	w = local[4];
	local[0]= w;
BLK3855:
	ctx->vsp=local; return(local[0]);}

/*:draw-rectangle-ndc*/
static pointer M3860viewer_draw_rectangle_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3863;}
	local[0]= NIL;
ENT3863:
ENT3862:
	if (n>6) maerror();
	if (local[0]==NIL) goto IF3864;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3865;
IF3864:
	local[1]= NIL;
IF3865:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[28];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[29];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[30];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3861:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-rectangle-ndc*/
static pointer M3866viewer_draw_fill_rectangle_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3869;}
	local[0]= NIL;
ENT3869:
ENT3868:
	if (n>6) maerror();
	if (local[0]==NIL) goto IF3870;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3871;
IF3870:
	local[1]= NIL;
IF3871:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[28];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[29];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[31];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3867:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc-ndc*/
static pointer M3872viewer_draw_arc_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3877;}
	local[0]= makeint((eusinteger_t)0L);
ENT3877:
	if (n>=7) { local[1]=(argv[6]); goto ENT3876;}
	local[1]= makeflt(6.2831853071795862319959e+00);
ENT3876:
	if (n>=8) { local[2]=(argv[7]); goto ENT3875;}
	local[2]= NIL;
ENT3875:
ENT3874:
	if (n>8) maerror();
	if (local[2]==NIL) goto IF3878;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[21];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF3879;
IF3878:
	local[3]= NIL;
IF3879:
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[19];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[2] = w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[28];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[3] = w;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= fqv[29];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[4] = w;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= fqv[32];
	local[5]= argv[2];
	local[6]= argv[3];
	local[7]= argv[4];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,7,local+3); /*send*/
	local[0]= w;
BLK3873:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-arc-ndc*/
static pointer M3880viewer_draw_fill_arc_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<7) maerror();
	if (n>=8) { local[0]=(argv[7]); goto ENT3883;}
	local[0]= NIL;
ENT3883:
ENT3882:
	if (n>8) maerror();
	if (local[0]==NIL) goto IF3884;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3885;
IF3884:
	local[1]= NIL;
IF3885:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[19];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[28];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[3] = w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[29];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[4] = w;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[33];
	local[3]= argv[2];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= argv[5];
	local[7]= argv[6];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,7,local+1); /*send*/
	local[0]= w;
BLK3881:
	ctx->vsp=local; return(local[0]);}

/*:draw-polyline-ndc*/
static pointer M3886viewer_draw_polyline_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3889;}
	local[0]= NIL;
ENT3889:
ENT3888:
	if (n>4) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	local[2]= NIL;
WHL3891:
	if (argv[2]==NIL) goto WHX3892;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[34];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= T;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	local[1] = local[2];
	goto WHL3891;
WHX3892:
	local[3]= NIL;
BLK3893:
	w = local[3];
	local[0]= w;
BLK3887:
	ctx->vsp=local; return(local[0]);}

/*:draw-box-ndc*/
static pointer M3895viewer_draw_box_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3898;}
	local[0]= NIL;
ENT3898:
ENT3897:
	if (n>5) maerror();
	local[1]= argv[2];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)0L));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= w;
	local[2]= argv[2];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)1L));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	local[2]= w;
	local[3]= argv[3];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)0L));
	  w=makeflt(local[3]->c.fvec.fv[i]);}
	local[3]= w;
	local[4]= argv[3];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)1L));
	  w=makeflt(local[4]->c.fvec.fv[i]);}
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[35];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[3];
	local[9]= local[2];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[4];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	local[11]= local[1];
	local[12]= local[2];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,5,local+7); /*list*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[0]= w;
BLK3896:
	ctx->vsp=local; return(local[0]);}

/*:draw-star-ndc*/
static pointer M3899viewer_draw_star_ndc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3903;}
	local[0]= makeflt(1.9999999999999990007993e-02);
ENT3903:
	if (n>=5) { local[1]=(argv[4]); goto ENT3902;}
	local[1]= NIL;
ENT3902:
ENT3901:
	if (n>5) maerror();
	local[2]= argv[0];
	local[3]= fqv[34];
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	local[6]= argv[2];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= T;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[34];
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[2];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= T;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[0]= w;
BLK3900:
	ctx->vsp=local; return(local[0]);}

/*:draw-line*/
static pointer M3904viewer_draw_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3908;}
	local[0]= T;
ENT3908:
	if (n>=6) { local[1]=(argv[5]); goto ENT3907;}
	local[1]= NIL;
ENT3907:
ENT3906:
	if (n>6) maerror();
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[20];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[2] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[20];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[3] = w;
	local[2]= argv[0];
	local[3]= fqv[34];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)RECLAIM(ctx,1,local+2); /*system:reclaim*/
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)RECLAIM(ctx,1,local+2); /*system:reclaim*/
	local[0]= w;
BLK3905:
	ctx->vsp=local; return(local[0]);}

/*:draw-box*/
static pointer M3909viewer_draw_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3913;}
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(3.0000000000000000000000e+02);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
ENT3913:
	if (n>=5) { local[1]=(argv[4]); goto ENT3912;}
	local[1]= NIL;
ENT3912:
ENT3911:
	if (n>5) maerror();
	local[2]= local[0];
	local[3]= local[0];
	local[4]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= fqv[20];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[3]); /*homo2normal*/
	argv[2] = w;
	local[2]= argv[0];
	local[3]= fqv[36];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,2,local+5); /*v+*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[0]= w;
BLK3910:
	ctx->vsp=local; return(local[0]);}

/*:draw-polyline*/
static pointer M3914viewer_draw_polyline(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3917;}
	local[0]= NIL;
ENT3917:
ENT3916:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[35];
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO3918,env,argv,local);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK3915:
	ctx->vsp=local; return(local[0]);}

/*:draw-arc*/
static pointer M3919viewer_draw_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3924;}
	local[0]= makeint((eusinteger_t)0L);
ENT3924:
	if (n>=7) { local[1]=(argv[6]); goto ENT3923;}
	local[1]= makeflt(6.2831853071795862319959e+00);
ENT3923:
	if (n>=8) { local[2]=(argv[7]); goto ENT3922;}
	local[2]= NIL;
ENT3922:
ENT3921:
	if (n>8) maerror();
	local[3]= NIL;
	local[4]= NIL;
	if (local[2]==NIL) goto IF3925;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= fqv[21];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3926;
IF3925:
	local[5]= NIL;
IF3926:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[20];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[2] = w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[37];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[38];
	local[7]= argv[2];
	local[8]= local[4];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= local[4];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	local[0]= w;
BLK3920:
	ctx->vsp=local; return(local[0]);}

/*:draw-fill-arc*/
static pointer M3927viewer_draw_fill_arc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT3932;}
	local[0]= makeint((eusinteger_t)0L);
ENT3932:
	if (n>=7) { local[1]=(argv[6]); goto ENT3931;}
	local[1]= makeflt(6.2831853071795862319959e+00);
ENT3931:
	if (n>=8) { local[2]=(argv[7]); goto ENT3930;}
	local[2]= NIL;
ENT3930:
ENT3929:
	if (n>8) maerror();
	local[3]= NIL;
	local[4]= NIL;
	if (local[2]==NIL) goto IF3933;
	local[5]= argv[0]->c.obj.iv[3];
	local[6]= fqv[21];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF3934;
IF3933:
	local[5]= NIL;
IF3934:
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[20];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[2] = w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= fqv[37];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,2,local+7); /*float-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= argv[0];
	local[6]= fqv[39];
	local[7]= argv[2];
	local[8]= local[4];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= local[4];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	local[10]= local[0];
	local[11]= local[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	local[0]= w;
BLK3928:
	ctx->vsp=local; return(local[0]);}

/*:draw-arrow*/
static pointer M3935viewer_draw_arrow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT3939;}
	local[0]= T;
ENT3939:
	if (n>=6) { local[1]=(argv[5]); goto ENT3938;}
	local[1]= NIL;
ENT3938:
ENT3937:
	ctx->vsp=local+2;
	n=parsekeyparams(fqv[40], &argv[6], n-6, local+2, 0);
	if (n & (1<<0)) goto KEY3940;
	local[2] = fqv[41];
KEY3940:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[20];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	argv[2] = w;
	local[7]= argv[0]->c.obj.iv[1];
	local[8]= fqv[20];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	argv[3] = w;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[3]); /*homo2normal*/
	argv[2] = w;
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[3]); /*homo2normal*/
	argv[3] = w;
	local[7]= argv[2];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[3] = w;
	local[7]= makeflt(2.9999999999999982236432e-01);
	local[8]= local[3];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= local[2];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[2];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= local[3];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[4] = w;
	local[7]= local[3];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= local[2];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= local[3];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= argv[3];
	local[8]= makeflt(5.0000000000000000000000e-01);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[5] = w;
	local[7]= argv[3];
	local[8]= makeflt(-5.0000000000000000000000e-01);
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)VPLUS(ctx,2,local+7); /*v+*/
	local[6] = w;
	local[7]= argv[0];
	local[8]= fqv[34];
	local[9]= argv[2];
	local[10]= argv[3];
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[34];
	local[9]= local[5];
	local[10]= argv[3];
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[34];
	local[9]= local[6];
	local[10]= argv[3];
	local[11]= local[0];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,6,local+7); /*send*/
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)RECLAIM(ctx,1,local+7); /*system:reclaim*/
	local[0]= w;
BLK3936:
	ctx->vsp=local; return(local[0]);}

/*:pane*/
static pointer M3941viewer_pane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= fqv[42];
	local[3]= fqv[43];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3942:
	ctx->vsp=local; return(local[0]);}

/*:draw-star*/
static pointer M3943viewer_draw_star(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3947;}
	local[0]= NIL;
ENT3947:
	if (n>=5) { local[1]=(argv[4]); goto ENT3946;}
	local[1]= NIL;
ENT3946:
ENT3945:
	if (n>5) maerror();
	if (local[0]!=NIL) goto IF3948;
	local[0] = makeflt(1.9999999999999990007993e-02);
	local[2]= local[0];
	goto IF3949;
IF3948:
	local[2]= NIL;
IF3949:
	local[2]= argv[0];
	local[3]= fqv[44];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= fqv[20];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,1,local+4,&ftab[3],fqv[3]); /*homo2normal*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[0]= w;
BLK3944:
	ctx->vsp=local; return(local[0]);}

/*:draw-2dlnseg*/
static pointer M3950viewer_draw_2dlnseg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[24];
	local[2]= argv[2];
	local[3]= fqv[45];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK3951:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO3918(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0]->c.obj.iv[1];
	local[1]= fqv[20];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:draw-edge-image*/
static pointer M3952viewer_draw_edge_image(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3956;}
	local[0]= NIL;
ENT3956:
	if (n>=5) { local[1]=(argv[4]); goto ENT3955;}
	local[1]= argv[2];
	local[2]= fqv[21];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
ENT3955:
ENT3954:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= fqv[47];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL3958:
	if (local[3]==NIL) goto WHX3959;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[34];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	goto WHL3958;
WHX3959:
	local[4]= NIL;
BLK3960:
	w = NIL;
	if (local[0]==NIL) goto IF3962;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[48];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= fqv[49];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
WHL3965:
	if (local[3]==NIL) goto WHX3966;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[34];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	goto WHL3965;
WHX3966:
	local[4]= NIL;
BLK3967:
	w = NIL;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= fqv[48];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF3963;
IF3962:
	local[2]= NIL;
IF3963:
	w = local[2];
	local[0]= w;
BLK3953:
	ctx->vsp=local; return(local[0]);}

/*:draw-edge*/
static pointer M3969viewer_draw_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3972;}
	local[0]= NIL;
ENT3972:
ENT3971:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF3973;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[21];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF3974;
IF3973:
	local[1]= NIL;
IF3974:
	local[1]= argv[0];
	local[2]= fqv[24];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK3970:
	ctx->vsp=local; return(local[0]);}

/*:draw-faces*/
static pointer M3975viewer_draw_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT3979;}
	local[0]= NIL;
ENT3979:
	if (n>=5) { local[1]=(argv[4]); goto ENT3978;}
	local[1]= NIL;
ENT3978:
ENT3977:
	if (n>5) maerror();
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= fqv[50];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL3981:
	if (local[7]==NIL) goto WHX3982;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[0]==NIL) goto AND3987;
	local[8]= local[6];
	local[9]= fqv[51];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto AND3987;
	goto IF3985;
AND3987:
	if (local[1]==NIL) goto IF3988;
	local[8]= local[1];
	goto IF3989;
IF3988:
	local[8]= local[6];
	local[9]= fqv[21];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
IF3989:
	local[5] = local[8];
	local[8]= NIL;
	local[9]= local[6];
	local[10]= fqv[52];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL3991:
	if (local[9]==NIL) goto WHX3992;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	w = local[2];
	if (memq(local[10],w)!=NIL) goto IF3995;
	local[10]= argv[0];
	local[11]= fqv[53];
	local[12]= local[8];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	w = local[2];
	ctx->vsp=local+11;
	local[2] = cons(ctx,local[10],w);
	local[10]= local[2];
	goto IF3996;
IF3995:
	local[10]= NIL;
IF3996:
	goto WHL3991;
WHX3992:
	local[10]= NIL;
BLK3993:
	w = NIL;
	local[8]= w;
	goto IF3986;
IF3985:
	local[8]= NIL;
IF3986:
	goto WHL3981;
WHX3982:
	local[8]= NIL;
BLK3983:
	w = NIL;
WHL3997:
	if (local[2]==NIL) goto WHX3998;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)RECLAIM(ctx,1,local+6); /*system:reclaim*/
	local[2] = local[4];
	goto WHL3997;
WHX3998:
	local[6]= NIL;
BLK3999:
	w = local[6];
	local[0]= w;
BLK3976:
	ctx->vsp=local; return(local[0]);}

/*:draw-body*/
static pointer M4000viewer_draw_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4003;}
	local[0]= T;
ENT4003:
ENT4002:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[55];
	local[3]= argv[2];
	local[4]= fqv[56];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= fqv[21];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[0]= w;
BLK4001:
	ctx->vsp=local; return(local[0]);}

/*:draw-axis*/
static pointer M4004viewer_draw_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4007;}
	local[0]= NIL;
ENT4007:
ENT4006:
	if (n>4) maerror();
	if (local[0]!=NIL) goto IF4008;
	local[0] = makeflt(1.0000000000000000000000e+00);
	local[1]= local[0];
	goto IF4009;
IF4008:
	local[1]= NIL;
IF4009:
	local[1]= argv[2];
	local[2]= fqv[57];
	local[3]= fqv[58];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeflt(2.9999999999999982236432e-01);
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[57];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= fqv[57];
	local[10]= local[0];
	local[11]= makeint((eusinteger_t)0L);
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[1];
	local[8]= argv[2];
	local[9]= fqv[57];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[0];
	local[12]= makeint((eusinteger_t)0L);
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[1];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[4];
	local[8]= argv[2];
	local[9]= fqv[57];
	local[10]= local[3];
	local[11]= local[2];
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[24];
	local[7]= local[4];
	local[8]= argv[2];
	local[9]= fqv[57];
	local[10]= local[3];
	local[11]= makeint((eusinteger_t)0L);
	local[12]= local[2];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[0]= w;
BLK4005:
	ctx->vsp=local; return(local[0]);}

/*:draw-one*/
static pointer M4010viewer_draw_one(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[2];
	if (!isnum(w)) goto CON4013;
	local[0]= NIL;
	goto CON4012;
CON4013:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON4014;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON4016;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[59];
	if (memq(local[1],w)==NIL) goto IF4018;
	local[1]= argv[0];
	local[2]= fqv[24];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF4019;
IF4018:
	local[1]= local[0];
	if (fqv[60]!=local[1]) goto IF4020;
	local[1]= argv[0];
	local[2]= fqv[34];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF4021;
IF4020:
	if (T==NIL) goto IF4022;
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF4023;
IF4022:
	local[1]= NIL;
IF4023:
IF4021:
IF4019:
	w = local[1];
	local[0]= w;
	goto CON4015;
CON4016:
	local[0]= NIL;
	local[1]= argv[2];
WHL4026:
	if (local[1]==NIL) goto WHX4027;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[62];
	local[4]= local[0];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL4026;
WHX4027:
	local[2]= NIL;
BLK4028:
	w = NIL;
	local[0]= w;
	goto CON4015;
CON4024:
	local[0]= NIL;
CON4015:
	goto CON4012;
CON4014:
	local[0]= argv[2];
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[64]); /*find-method*/
	if (w==NIL) goto CON4030;
	local[0]= argv[2];
	local[1]= fqv[63];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4030:
	local[0]= argv[2];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[64]); /*find-method*/
	if (w==NIL) goto CON4031;
	local[0]= argv[2];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[64]); /*find-method*/
	if (w==NIL) goto IF4032;
	local[0]= argv[2];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF4033;
IF4032:
	local[0]= NIL;
IF4033:
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4031:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[66]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4034;
	local[0]= argv[0];
	local[1]= fqv[53];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4034:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[67]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4035;
	local[0]= argv[0];
	local[1]= fqv[68];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4035:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[69]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4036;
	local[0]= argv[2];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[2];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[70];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
WHL4038:
	if (local[2]==NIL) goto WHX4039;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[53];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL4038;
WHX4039:
	local[3]= NIL;
BLK4040:
	w = NIL;
	local[0]= w;
	goto CON4012;
CON4036:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[71]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4042;
	local[0]= argv[2];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[2];
	local[1]= fqv[21];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[2];
	local[3]= fqv[72];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL4044:
	if (local[2]==NIL) goto WHX4045;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[53];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL4044;
WHX4045:
	local[3]= NIL;
BLK4046:
	w = NIL;
	local[0]= w;
	goto CON4012;
CON4042:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[73]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4048;
	local[0]= argv[0];
	local[1]= fqv[55];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4048:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[74]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4049;
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[72];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL4051:
	if (local[1]==NIL) goto WHX4052;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[53];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL4051;
WHX4052:
	local[2]= NIL;
BLK4053:
	w = NIL;
	local[0]= w;
	goto CON4012;
CON4049:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*float-vector-p*/
	if (w==NIL) goto CON4055;
	local[0]= argv[0];
	local[1]= fqv[75];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[3];
	goto CON4012;
CON4055:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[76]); /*coordinates-p*/
	if (w==NIL) goto CON4056;
	local[0]= argv[0];
	local[1]= fqv[77];
	local[2]= argv[2];
	local[3]= fqv[54];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4056:
	local[0]= fqv[78];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON4057;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[78]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4057;
	local[0]= argv[0];
	local[1]= fqv[79];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4057:
	local[0]= fqv[80];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON4058;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[80]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4058;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[81];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4058:
	local[0]= fqv[82];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w==NIL) goto CON4059;
	local[0]= argv[2];
	local[1]= loadglobal(fqv[82]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON4059;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[21];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON4012;
CON4059:
	local[0]= NIL;
CON4012:
	w = local[0];
	local[0]= w;
BLK4011:
	ctx->vsp=local; return(local[0]);}

/*:draw*/
static pointer M4060viewer_draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4063;}
	local[0]= NIL;
ENT4063:
ENT4062:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON4065;
	local[1]= NIL;
	local[2]= argv[2];
WHL4067:
	if (local[2]==NIL) goto WHX4068;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= fqv[62];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	goto WHL4067;
WHX4068:
	local[3]= NIL;
BLK4069:
	w = NIL;
	local[1]= w;
	goto CON4064;
CON4065:
	if (argv[2]==NIL) goto CON4071;
	local[1]= argv[0];
	local[2]= fqv[62];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON4064;
CON4071:
	local[1]= NIL;
CON4064:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = T;
	local[0]= w;
BLK4061:
	ctx->vsp=local; return(local[0]);}

/*:erase*/
static pointer M4072viewer_erase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[83];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[63];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[84];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4073:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M4074viewer_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[85];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4075:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M4076viewer_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[86], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY4078;
	local[0] = NIL;
KEY4078:
	if (n & (1<<1)) goto KEY4079;
	local[1] = NIL;
KEY4079:
	if (n & (1<<2)) goto KEY4080;
	local[2] = NIL;
KEY4080:
	if (n & (1<<3)) goto KEY4081;
	local[3] = NIL;
KEY4081:
	if (n & (1<<4)) goto KEY4082;
	local[4] = NIL;
KEY4082:
	local[5]= argv[0];
	local[6]= local[4];
	local[7]= fqv[87];
	ctx->vsp=local+8;
	w=(pointer)PUTPROP(ctx,3,local+5); /*putprop*/
	argv[0]->c.obj.iv[1] = local[0];
	argv[0]->c.obj.iv[2] = local[1];
	argv[0]->c.obj.iv[3] = local[2];
	local[5]= local[3];
	storeglobal(fqv[88],local[5]);
	local[5]= argv[0];
	w = loadglobal(fqv[89]);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	storeglobal(fqv[89],local[5]);
	w = argv[0];
	local[0]= w;
BLK4077:
	ctx->vsp=local; return(local[0]);}

/*:adjust-viewport*/
static pointer M4083viewer_adjust_viewport(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4089;}
	local[0]= NIL;
ENT4089:
	if (n>=4) { local[1]=(argv[3]); goto ENT4088;}
	local[1]= NIL;
ENT4088:
	if (n>=5) { local[2]=(argv[4]); goto ENT4087;}
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
ENT4087:
	if (n>=6) { local[3]=(argv[5]); goto ENT4086;}
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
ENT4086:
ENT4085:
	if (n>6) maerror();
	if (local[0]!=NIL) goto IF4090;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[8];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[0] = w;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	goto IF4091;
IF4090:
	local[4]= NIL;
IF4091:
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[90];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= fqv[91];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[0]= w;
BLK4084:
	ctx->vsp=local; return(local[0]);}

/*:resize*/
static pointer M4092viewer_resize(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT4095;}
	local[0]= argv[2];
ENT4095:
ENT4094:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[92];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[93];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= fqv[94];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK4093:
	ctx->vsp=local; return(local[0]);}

/*draw*/
static pointer F3714draw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4097:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[95]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4098;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	goto IF4099;
IF4098:
	local[4]= loadglobal(fqv[96]);
IF4099:
	local[2] = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4101;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[2];
	local[5]= fqv[97];
	local[6]= fqv[98];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4102;
IF4101:
	local[4]= NIL;
IF4102:
	local[4]= NIL;
	local[5]= local[0];
WHL4105:
	if (local[5]==NIL) goto WHX4106;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[63];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL4105;
WHX4106:
	local[6]= NIL;
BLK4107:
	w = NIL;
	w = local[3];
	if (!isint(w)) goto IF4109;
	local[4]= local[2];
	local[5]= fqv[97];
	local[6]= fqv[98];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4110;
IF4109:
	local[4]= NIL;
IF4110:
	w = local[4];
	local[0]= w;
BLK4096:
	ctx->vsp=local; return(local[0]);}

/*draw-tree*/
static pointer F3715draw_tree(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4112:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
WHL4113:
	if (local[0]==NIL) goto WHX4114;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= loadglobal(fqv[71]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF4117;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F3714draw(ctx,1,local+3); /*draw*/
	local[3]= w;
	goto IF4118;
IF4117:
	local[3]= NIL;
IF4118:
	local[3]= local[1];
	local[4]= fqv[99];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[2];
WHL4120:
	if (local[4]==NIL) goto WHX4121;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	goto WHL4120;
WHX4121:
	local[5]= NIL;
BLK4122:
	w = NIL;
	goto WHL4113;
WHX4114:
	local[3]= NIL;
BLK4115:
	w = local[3];
	local[0]= w;
BLK4111:
	ctx->vsp=local; return(local[0]);}

/*erase*/
static pointer F3716erase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4125:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[96]);
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[95]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4126;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	goto IF4127;
IF4126:
	local[4]= NIL;
IF4127:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4129;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[2];
	local[5]= fqv[97];
	local[6]= fqv[98];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4130;
IF4129:
	local[4]= NIL;
IF4130:
	local[4]= local[2];
	local[5]= fqv[100];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	if (!isint(w)) goto IF4132;
	local[4]= local[2];
	local[5]= fqv[97];
	local[6]= fqv[98];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF4133;
IF4132:
	local[4]= NIL;
IF4133:
	w = local[4];
	local[0]= w;
BLK4124:
	ctx->vsp=local; return(local[0]);}

/*draw-axis*/
static pointer F3717draw_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4135:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[96]);
	local[3]= makeflt(1.0000000000000000000000e+01);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= loadglobal(fqv[95]);
	ctx->vsp=local+6;
	w=(pointer)DERIVEDP(ctx,2,local+4); /*derivedp*/
	if (w==NIL) goto IF4136;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	goto IF4137;
IF4136:
	local[4]= NIL;
IF4137:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isnum(w)) goto IF4139;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[3] = w;
	local[4]= local[3];
	goto IF4140;
IF4139:
	local[4]= NIL;
IF4140:
	local[4]= NIL;
	local[5]= local[0];
WHL4143:
	if (local[5]==NIL) goto WHX4144;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[77];
	local[8]= local[4];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	goto WHL4143;
WHX4144:
	local[6]= NIL;
BLK4145:
	w = NIL;
	local[4]= local[2];
	local[5]= fqv[97];
	local[6]= fqv[18];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[0]= w;
BLK4134:
	ctx->vsp=local; return(local[0]);}

/*draw-arrow*/
static pointer F3718draw_arrow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[96]);
	local[1]= fqv[101];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[102]);
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4147:
	ctx->vsp=local; return(local[0]);}

/*hid*/
static pointer F3719hid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4149:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[96]);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= T;
	local[6]= makeflt(0.0000000000000000000000e+00);
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= makeflt(0.0000000000000000000000e+00);
	local[9]= makeflt(0.0000000000000000000000e+00);
	w = local[9];
	ctx->vsp=local+10;
	bindspecial(ctx,fqv[103],w);
	w = local[8];
	ctx->vsp=local+13;
	bindspecial(ctx,fqv[104],w);
	w = local[7];
	ctx->vsp=local+16;
	bindspecial(ctx,fqv[105],w);
	w = local[6];
	ctx->vsp=local+19;
	bindspecial(ctx,fqv[106],w);
	w = local[5];
	ctx->vsp=local+22;
	bindspecial(ctx,fqv[107],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	local[26]= loadglobal(fqv[95]);
	ctx->vsp=local+27;
	w=(pointer)DERIVEDP(ctx,2,local+25); /*derivedp*/
	if (w==NIL) goto IF4150;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[25];
	local[2] = w;
	local[25]= local[2];
	goto IF4151;
IF4150:
	local[25]= NIL;
IF4151:
	local[25]= NIL;
	local[26]= local[0];
	ctx->vsp=local+27;
	w=(*ftab[7])(ctx,1,local+26,&ftab[7],fqv[108]); /*flatten*/
	local[26]= w;
WHL4154:
	if (local[26]==NIL) goto WHX4155;
	w=local[26];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	w=local[26];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26] = (w)->c.cons.cdr;
	w = local[27];
	local[25] = w;
	local[27]= local[25];
	local[28]= fqv[65];
	ctx->vsp=local+29;
	w=(*ftab[5])(ctx,2,local+27,&ftab[5],fqv[64]); /*find-method*/
	if (w==NIL) goto IF4158;
	local[27]= local[25];
	local[28]= fqv[65];
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,2,local+27); /*send*/
	local[27]= w;
	local[28]= local[3];
	ctx->vsp=local+29;
	w=(pointer)APPEND(ctx,2,local+27); /*append*/
	local[3] = w;
	local[27]= local[3];
	goto IF4159;
IF4158:
	local[27]= local[25];
	w = local[3];
	ctx->vsp=local+28;
	local[3] = cons(ctx,local[27],w);
	local[27]= local[3];
IF4159:
	goto WHL4154;
WHX4155:
	local[27]= NIL;
BLK4156:
	w = NIL;
	local[25]= local[3];
	local[26]= local[2];
	local[27]= fqv[109];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(*ftab[8])(ctx,2,local+25,&ftab[8],fqv[110]); /*hid2*/
	local[25]= local[2];
	local[26]= fqv[63];
	local[27]= loadglobal(fqv[111]);
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	ctx->vsp=local+26;
	unbindx(ctx,5);
	w = local[25];
	local[0]= w;
BLK4148:
	ctx->vsp=local; return(local[0]);}

/*hidd*/
static pointer F3720hidd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4161:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[96]);
	local[3]= NIL;
	local[4]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= loadglobal(fqv[95]);
	ctx->vsp=local+7;
	w=(pointer)DERIVEDP(ctx,2,local+5); /*derivedp*/
	if (w==NIL) goto IF4162;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[2] = w;
	local[5]= local[2];
	goto IF4163;
IF4162:
	local[5]= NIL;
IF4163:
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,1,local+6,&ftab[7],fqv[108]); /*flatten*/
	local[6]= w;
WHL4166:
	if (local[6]==NIL) goto WHX4167;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[65];
	ctx->vsp=local+9;
	w=(*ftab[5])(ctx,2,local+7,&ftab[5],fqv[64]); /*find-method*/
	if (w==NIL) goto IF4170;
	local[7]= local[5];
	local[8]= fqv[65];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	local[3] = w;
	local[7]= local[3];
	goto IF4171;
IF4170:
	local[7]= local[5];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
IF4171:
	goto WHL4166;
WHX4167:
	local[7]= NIL;
BLK4168:
	w = NIL;
	local[5]= makeflt(0.0000000000000000000000e+00);
	local[6]= makeflt(0.0000000000000000000000e+00);
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= makeflt(0.0000000000000000000000e+00);
	w = local[8];
	ctx->vsp=local+9;
	bindspecial(ctx,fqv[103],w);
	w = local[7];
	ctx->vsp=local+12;
	bindspecial(ctx,fqv[104],w);
	w = local[6];
	ctx->vsp=local+15;
	bindspecial(ctx,fqv[105],w);
	w = local[5];
	ctx->vsp=local+18;
	bindspecial(ctx,fqv[106],w);
	local[21]= local[3];
	local[22]= local[2];
	local[23]= fqv[109];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(*ftab[8])(ctx,2,local+21,&ftab[8],fqv[110]); /*hid2*/
	local[21]= w;
	ctx->vsp=local+22;
	unbindx(ctx,4);
	w = local[21];
	local[5]= NIL;
	local[6]= loadglobal(fqv[111]);
WHL4173:
	if (local[6]==NIL) goto WHX4174;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= fqv[68];
	local[9]= local[5];
	local[10]= T;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	goto WHL4173;
WHX4174:
	local[7]= NIL;
BLK4175:
	w = NIL;
	if (loadglobal(fqv[112])==NIL) goto IF4177;
	local[5]= local[2];
	local[6]= fqv[97];
	local[7]= fqv[48];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= NIL;
	local[6]= loadglobal(fqv[113]);
WHL4180:
	if (local[6]==NIL) goto WHX4181;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	if (loadglobal(fqv[107])==NIL) goto AND4186;
	local[7]= local[5];
	local[8]= fqv[114];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	if (w==NIL) goto AND4186;
	goto IF4184;
AND4186:
	local[7]= local[2];
	local[8]= fqv[53];
	local[9]= local[5];
	local[10]= local[5];
	local[11]= fqv[21];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= w;
	goto IF4185;
IF4184:
	local[7]= NIL;
IF4185:
	goto WHL4180;
WHX4181:
	local[7]= NIL;
BLK4182:
	w = NIL;
	local[5]= local[2];
	local[6]= fqv[97];
	local[7]= fqv[48];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF4178;
IF4177:
	local[5]= NIL;
IF4178:
	local[5]= local[2];
	local[6]= fqv[97];
	local[7]= fqv[18];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK4160:
	ctx->vsp=local; return(local[0]);}

/*cls*/
static pointer F3721cls(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT4189;}
	local[0]= loadglobal(fqv[96]);
ENT4189:
ENT4188:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= fqv[97];
	local[3]= fqv[85];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= local[0];
	local[2]= fqv[97];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK4187:
	ctx->vsp=local; return(local[0]);}

/*draw-hid*/
static pointer F3722draw_hid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT4192;}
	local[0]= loadglobal(fqv[96]);
ENT4192:
ENT4191:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
WHL4194:
	if (local[2]==NIL) goto WHX4195;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= fqv[34];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	goto WHL4194;
WHX4195:
	local[3]= NIL;
BLK4196:
	w = NIL;
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,0,local+1,&ftab[9],fqv[115]); /*xflush*/
	local[0]= w;
BLK4190:
	ctx->vsp=local; return(local[0]);}

/*draw-step*/
static pointer F3723draw_step(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4199:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= loadglobal(fqv[96]);
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[96],w);
	local[5]= makeint((eusinteger_t)3L);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= loadglobal(fqv[95]);
	ctx->vsp=local+8;
	w=(pointer)DERIVEDP(ctx,2,local+6); /*derivedp*/
	if (w==NIL) goto IF4200;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	storeglobal(fqv[96],w);
	goto IF4201;
IF4200:
	local[6]= NIL;
IF4201:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF4203;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[5] = w;
	local[6]= local[5];
	goto IF4204;
IF4203:
	local[6]= NIL;
IF4204:
	ctx->vsp=local+6;
	w = makeclosure(codevec,quotevec,UWP4206,env,argv,local);
	local[6]=(pointer)(ctx->protfp); local[7]=w;
	ctx->protfp=(struct protectframe *)(local+6);
	local[8]= NIL;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[7])(ctx,1,local+9,&ftab[7],fqv[108]); /*flatten*/
	local[9]= w;
WHL4208:
	if (local[9]==NIL) goto WHX4209;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= loadglobal(fqv[96]);
	local[11]= fqv[97];
	local[12]= fqv[98];
	local[13]= local[5];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[96]);
	local[11]= fqv[97];
	local[12]= fqv[116];
	local[13]= makeint((eusinteger_t)6L);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)PRINT(ctx,1,local+10); /*print*/
	local[10]= loadglobal(fqv[96]);
	local[11]= fqv[63];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	ctx->vsp=local+10;
	w=(pointer)READCH(ctx,0,local+10); /*read-char*/
	local[10]= w;
	local[11]= local[10];
	local[12]= makeint((eusinteger_t)113L);
	ctx->vsp=local+13;
	w=(pointer)EQ(ctx,2,local+11); /*eql*/
	if (w==NIL) goto IF4212;
	w = local[8];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK4198;
	goto IF4213;
IF4212:
	local[11]= NIL;
IF4213:
	w = local[11];
	local[10]= loadglobal(fqv[96]);
	local[11]= fqv[63];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= loadglobal(fqv[96]);
	local[11]= fqv[97];
	local[12]= fqv[98];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[96]);
	local[11]= fqv[97];
	local[12]= fqv[116];
	local[13]= makeint((eusinteger_t)15L);
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= loadglobal(fqv[96]);
	local[11]= fqv[63];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(pointer)F3714draw(ctx,3,local+10); /*draw*/
	goto WHL4208;
WHX4209:
	local[10]= NIL;
BLK4210:
	w = NIL;
	ctx->vsp=local+8;
	UWP4206(ctx,0,local+8,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK4198:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP4206(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[96]);
	local[1]= fqv[97];
	local[2]= fqv[98];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[96]);
	local[1]= fqv[97];
	local[2]= fqv[116];
	local[3]= makeint((eusinteger_t)15L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-viewer*/
static pointer F3724find_viewer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO4215,env,argv,local);
	local[1]= loadglobal(fqv[89]);
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[117]); /*find-if*/
	local[0]= w;
BLK4214:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4215(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= argv[0];
	local[2]= fqv[87];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,2,local+0,&ftab[11],fqv[118]); /*string-equal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*view*/
static pointer F3725view(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4217:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[119], &argv[0], n-0, local+1, 1);
	if (n & (1<<0)) goto KEY4218;
	local[1] = NIL;
KEY4218:
	if (n & (1<<1)) goto KEY4219;
	local[2] = NIL;
KEY4219:
	if (n & (1<<2)) goto KEY4220;
	local[3] = NIL;
KEY4220:
	if (n & (1<<3)) goto KEY4221;
	local[4] = makeint((eusinteger_t)3L);
KEY4221:
	if (n & (1<<4)) goto KEY4222;
	local[5] = makeint((eusinteger_t)500L);
KEY4222:
	if (n & (1<<5)) goto KEY4223;
	local[6] = local[5];
KEY4223:
	if (n & (1<<6)) goto KEY4224;
	local[7] = local[5];
KEY4224:
	if (n & (1<<7)) goto KEY4225;
	local[8] = makeint((eusinteger_t)100L);
KEY4225:
	if (n & (1<<8)) goto KEY4226;
	local[9] = makeint((eusinteger_t)100L);
KEY4226:
	if (n & (1<<9)) goto KEY4227;
	local[10] = fqv[120];
KEY4227:
	if (n & (1<<10)) goto KEY4228;
	local[11] = local[10];
KEY4228:
	if (n & (1<<11)) goto KEY4229;
	local[12] = NIL;
KEY4229:
	if (n & (1<<12)) goto KEY4230;
	local[13] = makeint((eusinteger_t)3L);
KEY4230:
	if (n & (1<<13)) goto KEY4231;
	local[14] = NIL;
KEY4231:
	if (n & (1<<14)) goto KEY4232;
	local[28]= makeint((eusinteger_t)300L);
	local[29]= makeint((eusinteger_t)200L);
	local[30]= makeint((eusinteger_t)100L);
	ctx->vsp=local+31;
	w=(pointer)MKFLTVEC(ctx,3,local+28); /*float-vector*/
	local[15] = w;
KEY4232:
	if (n & (1<<15)) goto KEY4233;
	local[28]= makeint((eusinteger_t)0L);
	local[29]= makeint((eusinteger_t)0L);
	local[30]= makeint((eusinteger_t)0L);
	ctx->vsp=local+31;
	w=(pointer)MKFLTVEC(ctx,3,local+28); /*float-vector*/
	local[16] = w;
KEY4233:
	if (n & (1<<16)) goto KEY4234;
	local[17] = makeflt(5.0000000000000000000000e+00);
KEY4234:
	if (n & (1<<17)) goto KEY4235;
	local[18] = makeflt(1.0000000000000000000000e+02);
KEY4235:
	if (n & (1<<18)) goto KEY4236;
	local[19] = makeflt(1.0000000000000000000000e+04);
KEY4236:
	if (n & (1<<19)) goto KEY4237;
	local[20] = makeflt(1.0000000000000000000000e+00);
KEY4237:
	if (n & (1<<20)) goto KEY4238;
	local[21] = local[20];
KEY4238:
	if (n & (1<<21)) goto KEY4239;
	local[22] = local[20];
KEY4239:
	if (n & (1<<22)) goto KEY4240;
	local[28]= local[6];
	local[29]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+30;
	w=(pointer)QUOTIENT(ctx,2,local+28); /*/*/
	local[23] = w;
KEY4240:
	if (n & (1<<23)) goto KEY4241;
	local[28]= local[7];
	local[29]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+30;
	w=(pointer)QUOTIENT(ctx,2,local+28); /*/*/
	local[24] = w;
KEY4241:
	if (n & (1<<24)) goto KEY4242;
	local[25] = makeint((eusinteger_t)2L);
KEY4242:
	if (n & (1<<25)) goto KEY4243;
	local[26] = makeint((eusinteger_t)0L);
KEY4243:
	if (n & (1<<26)) goto KEY4244;
	local[27] = NIL;
KEY4244:
	local[28]= NIL;
	local[29]= NIL;
	local[30]= NIL;
	local[31]= NIL;
	if (local[2]==NIL) goto IF4245;
	local[28] = local[2];
	local[32]= local[28];
	goto IF4246;
IF4245:
	local[32]= (pointer)get_sym_func(fqv[121]);
	local[33]= fqv[122];
	local[34]= local[8];
	local[35]= fqv[123];
	local[36]= local[9];
	local[37]= fqv[8];
	local[38]= local[6];
	local[39]= fqv[9];
	local[40]= local[7];
	local[41]= fqv[124];
	local[42]= local[10];
	local[43]= fqv[125];
	local[44]= local[12];
	local[45]= fqv[126];
	local[46]= local[13];
	local[47]= fqv[127];
	local[48]= local[14];
	local[49]= fqv[128];
	local[50]= local[25];
	local[51]= fqv[129];
	local[52]= local[26];
	local[53]= fqv[87];
	local[54]= local[11];
	local[55]= local[0];
	ctx->vsp=local+56;
	w=(pointer)APPLY(ctx,24,local+32); /*apply*/
	local[28] = w;
	local[32]= local[28];
IF4246:
	if (local[1]==NIL) goto IF4247;
	local[29] = local[1];
	local[32]= local[29];
	goto IF4248;
IF4247:
	local[32]= loadglobal(fqv[130]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= local[32];
	local[34]= fqv[15];
	local[35]= fqv[16];
	local[36]= local[4];
	local[37]= fqv[10];
	local[38]= local[23];
	local[39]= fqv[11];
	local[40]= local[24];
	local[41]= fqv[8];
	local[42]= local[6];
	local[43]= fqv[9];
	local[44]= fqv[131];
	local[45]= loadglobal(fqv[132]);
	ctx->vsp=local+46;
	w=(*ftab[12])(ctx,2,local+44,&ftab[12],fqv[133]); /*member*/
	if (w!=NIL) goto OR4252;
	local[44]= fqv[134];
	local[45]= loadglobal(fqv[132]);
	ctx->vsp=local+46;
	w=(*ftab[12])(ctx,2,local+44,&ftab[12],fqv[133]); /*member*/
	if (w!=NIL) goto OR4252;
	goto IF4250;
OR4252:
	local[44]= local[7];
	ctx->vsp=local+45;
	w=(pointer)MINUS(ctx,1,local+44); /*-*/
	local[44]= w;
	goto IF4251;
IF4250:
	local[44]= local[7];
IF4251:
	ctx->vsp=local+45;
	w=(pointer)SEND(ctx,12,local+33); /*send*/
	w = local[32];
	local[29] = w;
	local[32]= local[29];
IF4248:
	if (local[3]==NIL) goto IF4253;
	local[32]= local[3];
	goto IF4254;
IF4253:
	local[32]= local[4];
	local[33]= makeint((eusinteger_t)2L);
	ctx->vsp=local+34;
	w=(pointer)NUMEQUAL(ctx,2,local+32); /*=*/
	if (w==NIL) goto IF4255;
	local[32]= loadglobal(fqv[135]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= (pointer)get_sym_func(fqv[17]);
	local[34]= local[32];
	local[35]= fqv[15];
	local[36]= fqv[125];
	local[37]= NIL;
	local[38]= fqv[136];
	local[39]= local[15];
	local[40]= makeint((eusinteger_t)0L);
	ctx->vsp=local+41;
	w=(pointer)AREF(ctx,2,local+39); /*aref*/
	local[39]= w;
	local[40]= local[15];
	local[41]= makeint((eusinteger_t)1L);
	ctx->vsp=local+42;
	w=(pointer)AREF(ctx,2,local+40); /*aref*/
	local[40]= w;
	ctx->vsp=local+41;
	w=(pointer)MKFLTVEC(ctx,2,local+39); /*float-vector*/
	local[39]= w;
	local[40]= local[0];
	ctx->vsp=local+41;
	w=(pointer)APPLY(ctx,8,local+33); /*apply*/
	w = local[32];
	local[32]= w;
	goto IF4256;
IF4255:
	local[32]= loadglobal(fqv[137]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= (pointer)get_sym_func(fqv[17]);
	local[34]= local[32];
	local[35]= fqv[15];
	local[36]= fqv[125];
	local[37]= NIL;
	local[38]= fqv[136];
	local[39]= local[15];
	local[40]= fqv[138];
	local[41]= local[16];
	local[42]= fqv[139];
	local[43]= local[17];
	local[44]= fqv[140];
	local[45]= local[18];
	local[46]= fqv[141];
	local[47]= local[19];
	local[48]= fqv[142];
	local[49]= local[21];
	local[50]= fqv[143];
	local[51]= local[22];
	local[52]= local[0];
	ctx->vsp=local+53;
	w=(pointer)APPLY(ctx,20,local+33); /*apply*/
	w = local[32];
	local[32]= w;
IF4256:
IF4254:
	local[30] = local[32];
	local[32]= local[11];
	ctx->vsp=local+33;
	w=(pointer)F3724find_viewer(ctx,1,local+32); /*find-viewer*/
	local[31] = w;
	if (local[31]!=NIL) goto IF4259;
	local[32]= loadglobal(fqv[95]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[31] = w;
	local[32]= local[31];
	goto IF4260;
IF4259:
	local[32]= NIL;
IF4260:
	local[32]= fqv[144];
	ctx->vsp=local+33;
	w=(pointer)BOUNDP(ctx,1,local+32); /*boundp*/
	if (w==NIL) goto IF4261;
	w = loadglobal(fqv[144]);
	if (!isnum(w)) goto IF4261;
	if (local[27]==NIL) goto IF4261;
	local[32]= local[27];
	local[33]= loadglobal(fqv[145]);
	ctx->vsp=local+34;
	w=(pointer)DERIVEDP(ctx,2,local+32); /*derivedp*/
	if (w!=NIL) goto IF4261;
	local[32]= loadglobal(fqv[146]);
	ctx->vsp=local+33;
	w=(pointer)INSTANTIATE(ctx,1,local+32); /*instantiate*/
	local[32]= w;
	local[33]= local[32];
	local[34]= fqv[147];
	local[35]= fqv[8];
	local[36]= local[6];
	local[37]= fqv[9];
	local[38]= local[7];
	ctx->vsp=local+39;
	w=(pointer)SEND(ctx,6,local+33); /*send*/
	w = local[32];
	local[27] = w;
	local[32]= local[27];
	goto IF4262;
IF4261:
	local[32]= NIL;
IF4262:
	local[32]= local[31];
	local[33]= fqv[15];
	local[34]= fqv[109];
	local[35]= local[30];
	local[36]= fqv[97];
	local[37]= local[28];
	local[38]= fqv[148];
	local[39]= local[29];
	local[40]= fqv[87];
	local[41]= local[11];
	local[42]= fqv[149];
	local[43]= local[27];
	ctx->vsp=local+44;
	w=(pointer)SEND(ctx,12,local+32); /*send*/
	w = local[31];
	local[0]= w;
BLK4216:
	ctx->vsp=local; return(local[0]);}

/*with-gc*/
static pointer F4264(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4266:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = argv[0];
	if (!iscons(w)) goto CON4268;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[4]= fqv[150];
	local[5]= fqv[151];
	local[6]= fqv[147];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= fqv[17];
	local[5]= local[1];
	local[6]= fqv[152];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[3] = w;
	local[4]= local[3];
	goto CON4267;
CON4268:
	local[1] = argv[0];
	local[2] = argv[0];
	local[3] = NIL;
	local[4]= local[3];
	goto CON4267;
CON4269:
	local[4]= NIL;
CON4267:
	local[4]= fqv[153];
	local[5]= fqv[154];
	local[6]= fqv[17];
	local[7]= fqv[96];
	local[8]= fqv[97];
	local[9]= fqv[155];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
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
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[156];
	local[7]= fqv[157];
	local[8]= fqv[17];
	local[9]= fqv[96];
	local[10]= fqv[97];
	local[11]= fqv[155];
	local[12]= local[1];
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
	w = local[0];
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[17];
	local[9]= fqv[96];
	local[10]= fqv[97];
	local[11]= fqv[155];
	local[12]= fqv[154];
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
	w = local[3];
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
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
	local[0]= w;
BLK4265:
	ctx->vsp=local; return(local[0]);}

/*with-viewsurface*/
static pointer F4270(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4272:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[153];
	local[2]= fqv[158];
	local[3]= fqv[159];
	local[4]= fqv[96];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[156];
	local[4]= fqv[157];
	local[5]= fqv[160];
	local[6]= fqv[159];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= argv[0];
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
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[160];
	local[6]= fqv[159];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[158];
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
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK4271:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___viewport(ctx,n,argv,env)
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
	local[0]= fqv[161];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4273;
	local[0]= fqv[162];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[163],w);
	goto IF4274;
IF4273:
	local[0]= fqv[164];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4274:
	local[0]= fqv[96];
	local[1]= fqv[165];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4275;
	local[0]= fqv[96];
	local[1]= fqv[165];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[96];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4277;
	local[0]= fqv[96];
	local[1]= fqv[166];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4278;
IF4277:
	local[0]= NIL;
IF4278:
	local[0]= fqv[96];
	goto IF4276;
IF4275:
	local[0]= NIL;
IF4276:
	local[0]= fqv[89];
	local[1]= fqv[165];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4279;
	local[0]= fqv[89];
	local[1]= fqv[165];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[89];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4281;
	local[0]= fqv[89];
	local[1]= fqv[166];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4282;
IF4281:
	local[0]= NIL;
IF4282:
	local[0]= fqv[89];
	goto IF4280;
IF4279:
	local[0]= NIL;
IF4280:
	local[0]= fqv[167];
	local[1]= fqv[165];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4283;
	local[0]= fqv[167];
	local[1]= fqv[165];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[167];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4285;
	local[0]= fqv[167];
	local[1]= fqv[166];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4286;
IF4285:
	local[0]= NIL;
IF4286:
	local[0]= fqv[167];
	goto IF4284;
IF4283:
	local[0]= NIL;
IF4284:
	local[0]= fqv[102];
	local[1]= fqv[165];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4287;
	local[0]= fqv[102];
	local[1]= fqv[165];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[102];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4289;
	local[0]= fqv[102];
	local[1]= fqv[166];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4290;
IF4289:
	local[0]= NIL;
IF4290:
	local[0]= fqv[102];
	goto IF4288;
IF4287:
	local[0]= NIL;
IF4288:
	local[0]= fqv[168];
	local[1]= fqv[165];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4291;
	local[0]= fqv[168];
	local[1]= fqv[165];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[168];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4293;
	local[0]= fqv[168];
	local[1]= fqv[166];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4294;
IF4293:
	local[0]= NIL;
IF4294:
	local[0]= fqv[168];
	goto IF4292;
IF4291:
	local[0]= NIL;
IF4292:
	local[0]= fqv[169];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[5];
	local[1]= fqv[166];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[6];
	local[1]= fqv[166];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[130];
	local[1]= fqv[166];
	local[2]= fqv[130];
	local[3]= fqv[170];
	local[4]= loadglobal(fqv[171]);
	local[5]= fqv[172];
	local[6]= fqv[173];
	local[7]= fqv[174];
	local[8]= NIL;
	local[9]= fqv[175];
	local[10]= NIL;
	local[11]= fqv[91];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[176];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[177]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3727viewport_xcenter,fqv[10],fqv[130],fqv[178]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3733viewport_ycenter,fqv[11],fqv[130],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3739viewport_center,fqv[90],fqv[130],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3748viewport_width,fqv[8],fqv[130],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3754viewport_height,fqv[9],fqv[130],fqv[182]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3760viewport_size,fqv[91],fqv[130],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3769viewport_screen_point_to_ndc,fqv[184],fqv[130],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3771viewport_ndc_width_to_screen,fqv[28],fqv[130],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3773viewport_ndc_height_to_screen,fqv[29],fqv[130],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3775viewport_ndc_point_to_screen,fqv[19],fqv[130],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3779viewport_ndc_line_to_screen,fqv[23],fqv[130],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3791viewport_resize,fqv[92],fqv[130],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3806viewport_init,fqv[15],fqv[130],fqv[191]);
	local[0]= fqv[95];
	local[1]= fqv[166];
	local[2]= fqv[95];
	local[3]= fqv[170];
	local[4]= loadglobal(fqv[192]);
	local[5]= fqv[172];
	local[6]= fqv[193];
	local[7]= fqv[174];
	local[8]= NIL;
	local[9]= fqv[175];
	local[10]= NIL;
	local[11]= fqv[91];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[176];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[177]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3814viewer_viewing,fqv[109],fqv[95],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3819viewer_viewsurface,fqv[97],fqv[95],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3824viewer_viewport,fqv[148],fqv[95],fqv[196]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3829viewer_flush,fqv[18],fqv[95],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3831viewer_point_to_screen,fqv[198],fqv[95],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3833viewer_draw_point_ndc,fqv[200],fqv[95],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3839viewer_draw_line_ndc,fqv[34],fqv[95],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3848viewer_draw_string_ndc,fqv[203],fqv[95],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3854viewer_draw_image_string_ndc,fqv[205],fqv[95],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3860viewer_draw_rectangle_ndc,fqv[207],fqv[95],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3866viewer_draw_fill_rectangle_ndc,fqv[209],fqv[95],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3872viewer_draw_arc_ndc,fqv[38],fqv[95],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3880viewer_draw_fill_arc_ndc,fqv[39],fqv[95],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3886viewer_draw_polyline_ndc,fqv[35],fqv[95],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3895viewer_draw_box_ndc,fqv[36],fqv[95],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3899viewer_draw_star_ndc,fqv[44],fqv[95],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3904viewer_draw_line,fqv[24],fqv[95],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3909viewer_draw_box,fqv[217],fqv[95],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3914viewer_draw_polyline,fqv[219],fqv[95],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3919viewer_draw_arc,fqv[32],fqv[95],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3927viewer_draw_fill_arc,fqv[33],fqv[95],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3935viewer_draw_arrow,fqv[101],fqv[95],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3941viewer_pane,fqv[224],fqv[95],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3943viewer_draw_star,fqv[75],fqv[95],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3950viewer_draw_2dlnseg,fqv[79],fqv[95],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3952viewer_draw_edge_image,fqv[68],fqv[95],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3969viewer_draw_edge,fqv[53],fqv[95],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3975viewer_draw_faces,fqv[55],fqv[95],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4000viewer_draw_body,fqv[231],fqv[95],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4004viewer_draw_axis,fqv[77],fqv[95],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4010viewer_draw_one,fqv[62],fqv[95],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4060viewer_draw,fqv[63],fqv[95],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4072viewer_erase,fqv[100],fqv[95],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4074viewer_clear,fqv[85],fqv[95],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4076viewer_init,fqv[15],fqv[95],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4083viewer_adjust_viewport,fqv[93],fqv[95],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4092viewer_resize,fqv[92],fqv[95],fqv[240]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[241],module,F3714draw,fqv[242]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[243],module,F3715draw_tree,fqv[244]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[245],module,F3716erase,fqv[246]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[247],module,F3717draw_axis,fqv[248]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[249],module,F3718draw_arrow,fqv[250]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[251],module,F3719hid,fqv[252]);
	local[0]= fqv[112];
	local[1]= fqv[165];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF4295;
	local[0]= fqv[112];
	local[1]= fqv[165];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[112];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF4297;
	local[0]= fqv[112];
	local[1]= fqv[166];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF4298;
IF4297:
	local[0]= NIL;
IF4298:
	local[0]= fqv[112];
	goto IF4296;
IF4295:
	local[0]= NIL;
IF4296:
	ctx->vsp=local+0;
	compfun(ctx,fqv[253],module,F3720hidd,fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F3721cls,fqv[256]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F3722draw_hid,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F3723draw_step,fqv[260]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F3724find_viewer,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F3725view,fqv[264]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[265],module,F4264,fqv[266]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[267],module,F4270,fqv[268]);
	local[0]= fqv[148];
	local[1]= fqv[269];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[270]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<15; i++) ftab[i]=fcallx;
}
