/* ./geopack.c :  entry=geopack */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "geopack.h"
#pragma init (register_geopack)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___geopack();
extern pointer build_quote_vector();
static int register_geopack()
  { add_module_initializer("___geopack", ___geopack);}

static pointer F71vplus();
static pointer F72vector_mean();
static pointer F73direction_vector();
static pointer F74triangle();
static pointer F75triangle_normal();
static pointer F76vector_angle();
static pointer F77face_normal_vector();
static pointer F78farthest();
static pointer F79farthest_pair();
static pointer F80maxindex();
static pointer F81random_vector();
static pointer F82random_normalized_vector();
static pointer F83random_vector2();
static pointer F84random_vectors();
static pointer F85edgep();
static pointer F86facep();
static pointer F87bodyp();
static pointer F88primitive_body_p();
static pointer F89n_2();
static pointer F90eps_();
static pointer F91eps_();
static pointer F92eps_();
static pointer F93eps__();
static pointer F94eps__();
static pointer F95eps__();
static pointer F96eps_zero();
static pointer F97eps_in_range();
static pointer F98eps_v_();
static pointer F99eps_coords_();
static pointer F100make_bounding_box();
static pointer F101make_big_bounding_box();
static pointer F102bounding_box_intersection();
static pointer F103bounding_box_union();
static pointer F106make_line();
static pointer F107winged_edge_p();
static pointer F109make_plane();
static pointer F113make_polygon();

/*vplus*/
static pointer F71vplus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[0]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL116:
	if (local[2]==NIL) goto WHX117;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	goto WHL116;
WHX117:
	local[3]= NIL;
BLK118:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK114:
	ctx->vsp=local; return(local[0]);}

/*vector-mean*/
static pointer F72vector_mean(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F71vplus(ctx,1,local+1); /*vplus*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)SCALEVEC(ctx,2,local+0); /*scale*/
	local[0]= w;
BLK120:
	ctx->vsp=local; return(local[0]);}

/*direction-vector*/
static pointer F73direction_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK121:
	ctx->vsp=local; return(local[0]);}

/*triangle*/
static pointer F74triangle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT124;}
	local[0]= fqv[1];
ENT124:
ENT123:
	if (n>4) maerror();
	local[1]= argv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SCA3PROD(ctx,3,local+1); /*v.**/
	local[0]= w;
BLK122:
	ctx->vsp=local; return(local[0]);}

/*triangle-normal*/
static pointer F75triangle_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK125:
	ctx->vsp=local; return(local[0]);}

/*vector-angle*/
static pointer F76vector_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT128;}
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
ENT128:
ENT127:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SCA3PROD(ctx,3,local+1); /*v.**/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ATAN(ctx,2,local+1); /*atan*/
	local[0]= w;
BLK126:
	ctx->vsp=local; return(local[0]);}

/*face-normal-vector*/
static pointer F77face_normal_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
WHL130:
	if (local[2]==NIL) goto WHX131;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[5];
	local[1] = w;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,3,local+5); /*v+*/
	local[0] = local[1];
	goto WHL130;
WHX131:
	local[5]= NIL;
BLK132:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,3,local+5); /*v**/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VPLUS(ctx,3,local+5); /*v+*/
	local[5]= local[4];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,2,local+5); /*normalize-vector*/
	local[0]= w;
BLK129:
	ctx->vsp=local; return(local[0]);}

/*farthest*/
static pointer F78farthest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= NIL;
	local[4]= argv[1];
WHL137:
	if (local[4]==NIL) goto WHX138;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VDISTANCE(ctx,2,local+5); /*distance*/
	local[2] = w;
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF141;
	local[0] = local[3];
	local[1] = local[2];
	local[5]= local[1];
	goto IF142;
IF141:
	local[5]= NIL;
IF142:
	goto WHL137;
WHX138:
	local[5]= NIL;
BLK139:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK134:
	ctx->vsp=local; return(local[0]);}

/*farthest-pair*/
static pointer F79farthest_pair(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F78farthest(ctx,2,local+2); /*farthest*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
WHL145:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX146;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[4] = w;
	local[7]= local[4];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)F78farthest(ctx,2,local+7); /*farthest*/
	local[5] = w;
	local[7]= local[4];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)VDISTANCE(ctx,2,local+7); /*distance*/
	local[6] = w;
	local[7]= local[6];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF149;
	local[0] = local[4];
	local[2] = local[5];
	local[3] = local[6];
	local[7]= local[3];
	goto IF150;
IF149:
	local[7]= NIL;
IF150:
	goto WHL145;
WHX146:
	local[7]= NIL;
BLK147:
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[0]= w;
BLK143:
	ctx->vsp=local; return(local[0]);}

/*maxindex*/
static pointer F80maxindex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)1L));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= argv[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)0L));
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF152;}
	local[0] = makeint((eusinteger_t)1L);
	local[1]= local[0];
	goto IF153;
IF152:
	local[1]= NIL;
IF153:
	local[1]= argv[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)2L));
	  w=makeflt(local[1]->c.fvec.fv[i]);}
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= argv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeflt(local[2]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF154;}
	local[0] = makeint((eusinteger_t)2L);
	local[1]= local[0];
	goto IF155;
IF154:
	local[1]= NIL;
IF155:
	w = local[0];
	local[0]= w;
BLK151:
	ctx->vsp=local; return(local[0]);}

/*random-vector*/
static pointer F81random_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT158;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT158:
ENT157:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)RANDOM(ctx,1,local+2); /*random*/
	local[2]= w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)RANDOM(ctx,1,local+4); /*random*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0]= w;
BLK156:
	ctx->vsp=local; return(local[0]);}

/*random-normalized-vector*/
static pointer F82random_normalized_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+1;
	w=(pointer)RANDOM(ctx,1,local+0); /*random*/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)RANDOM(ctx,1,local+1); /*random*/
	local[1]= w;
	local[2]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)RANDOM(ctx,1,local+2); /*random*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK159:
	ctx->vsp=local; return(local[0]);}

/*random-vector2*/
static pointer F83random_vector2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT162;}
	local[0]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+1;
	w=(pointer)RANDOM(ctx,1,local+0); /*random*/
	local[0]= w;
ENT162:
ENT161:
	if (n>1) maerror();
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= makeflt(6.2831853071795862319959e+00);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)ROTVEC(ctx,3,local+2); /*rotate-vector*/
	local[2]= w;
	local[3]= makeflt(6.2831853071795862319959e+00);
	ctx->vsp=local+4;
	w=(pointer)RANDOM(ctx,1,local+3); /*random*/
	local[3]= w;
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTVEC(ctx,3,local+2); /*rotate-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[0]= w;
BLK160:
	ctx->vsp=local; return(local[0]);}

/*random-vectors*/
static pointer F84random_vectors(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF164;
	local[0]= NIL;
	goto IF165;
IF164:
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F81random_vector(ctx,1,local+0); /*random-vector*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F84random_vectors(ctx,2,local+1); /*random-vectors*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
IF165:
	w = local[0];
	local[0]= w;
BLK163:
	ctx->vsp=local; return(local[0]);}

/*edgep*/
static pointer F85edgep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[4]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK166:
	ctx->vsp=local; return(local[0]);}

/*facep*/
static pointer F86facep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[5]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK167:
	ctx->vsp=local; return(local[0]);}

/*bodyp*/
static pointer F87bodyp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[6]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK168:
	ctx->vsp=local; return(local[0]);}

/*primitive-body-p*/
static pointer F88primitive_body_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F87bodyp(ctx,1,local+0); /*bodyp*/
	local[0]= w;
	if (w==NIL) goto AND170;
	local[0]= argv[0];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
AND170:
	w = local[0];
	local[0]= w;
BLK169:
	ctx->vsp=local; return(local[0]);}

/*n^2*/
static pointer F89n_2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
BLK171:
	ctx->vsp=local; return(local[0]);}

/*eps=*/
static pointer F90eps_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT174;}
	local[0]= loadglobal(fqv[8]);
ENT174:
ENT173:
	if (n>3) maerror();
	local[1]= argv[0];
	{ double x,y;
		y=fltval(argv[1]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	local[1]= makeflt((double)fabs(fltval(local[1])));
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK172:
	ctx->vsp=local; return(local[0]);}

/*eps<*/
static pointer F91eps_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT177;}
	local[0]= loadglobal(fqv[8]);
ENT177:
ENT176:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x - y));}
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK175:
	ctx->vsp=local; return(local[0]);}

/*eps>*/
static pointer F92eps_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT180;}
	local[0]= loadglobal(fqv[8]);
ENT180:
ENT179:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	local[0]= w;
BLK178:
	ctx->vsp=local; return(local[0]);}

/*eps<=*/
static pointer F93eps__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT183;}
	local[0]= loadglobal(fqv[8]);
ENT183:
ENT182:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	local[0]= w;
BLK181:
	ctx->vsp=local; return(local[0]);}

/*eps>=*/
static pointer F94eps__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT186;}
	local[0]= loadglobal(fqv[8]);
ENT186:
ENT185:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[2]);
		local[2]=(makeflt(x - y));}
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	local[0]= w;
BLK184:
	ctx->vsp=local; return(local[0]);}

/*eps<>*/
static pointer F95eps__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT189;}
	local[0]= loadglobal(fqv[8]);
ENT189:
ENT188:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	w = ((w)==NIL?T:NIL);
	local[0]= w;
BLK187:
	ctx->vsp=local; return(local[0]);}

/*eps-zero*/
static pointer F96eps_zero(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT192;}
	local[0]= loadglobal(fqv[8]);
ENT192:
ENT191:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK190:
	ctx->vsp=local; return(local[0]);}

/*eps-in-range*/
static pointer F97eps_in_range(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT195;}
	local[0]= loadglobal(fqv[8]);
ENT195:
ENT194:
	if (n>4) maerror();
	local[1]= argv[0];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[1]);
		local[1]=(makeflt(x - y));}
	local[2]= argv[1];
	local[3]= argv[2];
	{ double x,y;
		y=fltval(local[0]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	ctx->vsp=local+4;
	w=(pointer)LSEQP(ctx,3,local+1); /*<=*/
	local[0]= w;
BLK193:
	ctx->vsp=local; return(local[0]);}

/*eps-v=*/
static pointer F98eps_v_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT198;}
	local[0]= loadglobal(fqv[8]);
ENT198:
ENT197:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK196:
	ctx->vsp=local; return(local[0]);}

/*eps-coords=*/
static pointer F99eps_coords_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT202;}
	local[0]= loadglobal(fqv[8]);
ENT202:
	if (n>=4) { local[1]=(argv[3]); goto ENT201;}
	local[1]= local[0];
ENT201:
ENT200:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[9]); /*coordinates-distance*/
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	local[4]= w;
	if (w==NIL) goto AND203;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (((w)->c.cons.car)==NIL?T:NIL);
	if (local[4]!=NIL) goto OR204;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	local[4]= w;
OR204:
AND203:
	w = local[4];
	local[0]= w;
BLK199:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M205bounding_box_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT208;}
	local[0]= NIL;
ENT208:
ENT207:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF209;
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF210;
IF209:
	local[1]= argv[0];
IF210:
	w = local[1];
	local[0]= w;
BLK206:
	ctx->vsp=local; return(local[0]);}

/*:minpoint*/
static pointer M211bounding_box_minpoint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK212:
	ctx->vsp=local; return(local[0]);}

/*:maxpoint*/
static pointer M213bounding_box_maxpoint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK214:
	ctx->vsp=local; return(local[0]);}

/*:center*/
static pointer M215bounding_box_center(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(5.0000000000000000000000e-01);
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[11]); /*midpoint*/
	local[0]= w;
BLK216:
	ctx->vsp=local; return(local[0]);}

/*:diagonal*/
static pointer M217bounding_box_diagonal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
BLK218:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M219bounding_box_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT222;}
	local[0]= T;
ENT222:
ENT221:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[13];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= fqv[14];
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK220:
	ctx->vsp=local; return(local[0]);}

/*:inner*/
static pointer M223bounding_box_inner(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VLESSP(ctx,2,local+0); /*v<*/
	local[0]= w;
	if (w==NIL) goto AND225;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VGREATERP(ctx,2,local+0); /*v>*/
	local[0]= w;
AND225:
	w = local[0];
	local[0]= w;
BLK224:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M226bounding_box_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT229;}
	local[0]= NIL;
ENT229:
ENT228:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)VMAX(ctx,2,local+1); /*vmax*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMIN(ctx,2,local+2); /*vmin*/
	local[2]= w;
	if (local[0]==NIL) goto IF230;
	local[3]= local[0];
	local[4]= local[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[0] = w;
	local[3]= local[1];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,3,local+3); /*v-*/
	local[3]= local[2];
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	local[3]= w;
	goto IF231;
IF230:
	local[3]= NIL;
IF231:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VLESSP(ctx,2,local+3); /*v<*/
	if (w==NIL) goto IF232;
	local[3]= loadglobal(fqv[15]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[16];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	goto IF233;
IF232:
	local[3]= NIL;
IF233:
	w = local[3];
	local[0]= w;
BLK227:
	ctx->vsp=local; return(local[0]);}

/*:union*/
static pointer M235bounding_box_union(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT238;}
	local[0]= NIL;
ENT238:
ENT237:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[16];
	local[4]= argv[0]->c.obj.iv[0];
	local[5]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+6;
	w=(pointer)VMIN(ctx,2,local+4); /*vmin*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)VMAX(ctx,2,local+5); /*vmax*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK236:
	ctx->vsp=local; return(local[0]);}

/*:intersection-p*/
static pointer M240bounding_box_intersection_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[2]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMAX(ctx,2,local+0); /*vmax*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMIN(ctx,2,local+1); /*vmin*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VLESSP(ctx,2,local+0); /*v<*/
	local[0]= w;
BLK241:
	ctx->vsp=local; return(local[0]);}

/*:grow*/
static pointer M242bounding_box_grow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT245;}
	local[0]= NIL;
ENT245:
ENT244:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF246;
	local[1]= argv[2];
	local[2]= argv[2];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	goto IF247;
IF246:
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
IF247:
	argv[2] = local[1];
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,3,local+1); /*v-*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	w = argv[0];
	local[0]= w;
BLK243:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M248bounding_box_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeint((eusinteger_t)2L);
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,3,local+1); /***/
	local[0]= w;
BLK249:
	ctx->vsp=local; return(local[0]);}

/*:extream-point*/
static pointer M250bounding_box_extream_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= loadglobal(fqv[0]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[0];
WHL253:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX254;
	local[4]= local[1];
	local[5]= local[2];
	local[6]= argv[2];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF256;
	local[6]= argv[0]->c.obj.iv[1];
	goto IF257;
IF256:
	local[6]= argv[0]->c.obj.iv[0];
IF257:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL253;
WHX254:
	local[4]= NIL;
BLK255:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK251:
	ctx->vsp=local; return(local[0]);}

/*:below*/
static pointer M258bounding_box_below(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT261;}
	local[0]= fqv[17];
ENT261:
ENT260:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[18];
	local[4]= makeflt(-1.0000000000000000000000e+00);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	local[0]= w;
BLK259:
	ctx->vsp=local; return(local[0]);}

/*:corners*/
static pointer M262bounding_box_corners(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[19]); /*expt*/
	local[4]= w;
WHL265:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX266;
	local[5]= loadglobal(fqv[0]);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[1] = w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[2];
WHL269:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX270;
	local[7]= local[1];
	local[8]= local[5];
	local[9]= local[5];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LOGBITP(ctx,2,local+9); /*logbitp*/
	if (w==NIL) goto IF272;
	local[9]= argv[0]->c.obj.iv[1];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
	goto IF273;
IF272:
	local[9]= argv[0]->c.obj.iv[0];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,2,local+9); /*aref*/
	local[9]= w;
IF273:
	ctx->vsp=local+10;
	w=(pointer)ASET(ctx,3,local+7); /*aset*/
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL269;
WHX270:
	local[7]= NIL;
BLK271:
	w = NIL;
	local[5]= local[1];
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL265;
WHX266:
	local[5]= NIL;
BLK267:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK263:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M274bounding_box_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)COPYSEQ(ctx,1,local+1); /*copy-seq*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYSEQ(ctx,1,local+3); /*copy-seq*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)1L);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[3];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,3,local+4); /*aset*/
	local[4]= local[0];
	local[5]= local[1];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[0];
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[3])(ctx,2,local+4,&ftab[3],fqv[20]); /*make-prism*/
	local[0]= w;
BLK275:
	ctx->vsp=local; return(local[0]);}

/*:init2*/
static pointer M276bounding_box_init2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT279;}
	local[0]= NIL;
ENT279:
ENT278:
	if (n>5) maerror();
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMIN(ctx,2,local+1); /*vmin*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMAX(ctx,2,local+1); /*vmax*/
	argv[0]->c.obj.iv[1] = w;
	if (local[0]==NIL) goto IF280;
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF281;
IF280:
	local[1]= NIL;
IF281:
	w = argv[0];
	local[0]= w;
BLK277:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M282bounding_box_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT285;}
	local[0]= NIL;
ENT285:
ENT284:
	if (n>4) maerror();
	local[1]= (pointer)get_sym_func(fqv[21]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= (pointer)get_sym_func(fqv[22]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	argv[0]->c.obj.iv[1] = w;
	if (local[0]==NIL) goto IF286;
	local[1]= argv[0];
	local[2]= fqv[10];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF287;
IF286:
	local[1]= NIL;
IF287:
	w = argv[0];
	local[0]= w;
BLK283:
	ctx->vsp=local; return(local[0]);}

/*make-bounding-box*/
static pointer F100make_bounding_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT290;}
	local[0]= loadglobal(fqv[23]);
ENT290:
ENT289:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK288:
	ctx->vsp=local; return(local[0]);}

/*make-big-bounding-box*/
static pointer F101make_big_bounding_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeflt(-1.0000000000000000000000e+20);
	local[1]= makeflt(-1.0000000000000000000000e+20);
	local[2]= makeflt(-1.0000000000000000000000e+20);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000000000e+20);
	local[2]= makeflt(1.0000000000000000000000e+20);
	local[3]= makeflt(1.0000000000000000000000e+20);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F100make_bounding_box(ctx,1,local+0); /*make-bounding-box*/
	local[0]= w;
BLK292:
	ctx->vsp=local; return(local[0]);}

/*bounding-box-intersection*/
static pointer F102bounding_box_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT295;}
	local[0]= loadglobal(fqv[23]);
ENT295:
ENT294:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= argv[0];
WHL298:
	if (local[4]==NIL) goto WHX299;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= fqv[26];
	local[7]= local[3];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[2] = w;
	if (local[2]!=NIL) goto IF302;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK293;
	goto IF303;
IF302:
	local[5]= NIL;
IF303:
	goto WHL298;
WHX299:
	local[5]= NIL;
BLK300:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK293:
	ctx->vsp=local; return(local[0]);}

/*bounding-box-union*/
static pointer F103bounding_box_union(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT306;}
	local[0]= loadglobal(fqv[23]);
ENT306:
ENT305:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[25];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= argv[0];
WHL309:
	if (local[4]==NIL) goto WHX310;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= fqv[27];
	local[7]= local[3];
	local[8]= fqv[25];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	goto WHL309;
WHX310:
	local[5]= NIL;
BLK311:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK304:
	ctx->vsp=local; return(local[0]);}

/*:nvertex*/
static pointer M313line_nvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT316;}
	local[0]= NIL;
ENT316:
ENT315:
	if (n>3) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK314:
	ctx->vsp=local; return(local[0]);}

/*:pvertex*/
static pointer M317line_pvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT320;}
	local[0]= NIL;
ENT320:
ENT319:
	if (n>3) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK318:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M321line_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK322:
	ctx->vsp=local; return(local[0]);}

/*:eq*/
static pointer M323line_eq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND325;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
AND325:
	w = local[0];
	local[0]= w;
BLK324:
	ctx->vsp=local; return(local[0]);}

/*:eql*/
static pointer M326line_eql(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND329;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
AND329:
	if (local[0]!=NIL) goto OR328;
	local[0]= argv[2]->c.obj.iv[1];
	local[0]= ((argv[0]->c.obj.iv[2])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND330;
	local[0]= argv[2]->c.obj.iv[2];
	local[0]= ((argv[0]->c.obj.iv[1])==(local[0])?T:NIL);
AND330:
OR328:
	w = local[0];
	local[0]= w;
BLK327:
	ctx->vsp=local; return(local[0]);}

/*:equall*/
static pointer M331line_equall(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	if (w==NIL) goto AND334;
	local[0]= argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
AND334:
	if (local[0]!=NIL) goto OR333;
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
	if (w==NIL) goto AND335;
	local[0]= argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
AND335:
OR333:
	w = local[0];
	local[0]= w;
BLK332:
	ctx->vsp=local; return(local[0]);}

/*:parameter*/
static pointer M336line_parameter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0]= w;
BLK337:
	ctx->vsp=local; return(local[0]);}

/*:point*/
static pointer M338line_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[11]); /*midpoint*/
	local[0]= w;
BLK339:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M340line_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT343;}
	local[0]= NIL;
ENT343:
ENT342:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[16];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK341:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M345line_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT348;}
	local[0]= NIL;
ENT348:
ENT347:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[25];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[28];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	w = local[2];
	local[0]= w;
BLK346:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M349line_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
BLK350:
	ctx->vsp=local; return(local[0]);}

/*:end-point*/
static pointer M351line_end_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (argv[2]!=local[0]) goto IF353;
	local[0]= argv[2];
	goto IF354;
IF353:
	local[0]= argv[0]->c.obj.iv[2];
	if (argv[2]!=local[0]) goto IF355;
	local[0]= argv[2];
	goto IF356;
IF355:
	local[0]= NIL;
IF356:
IF354:
	w = local[0];
	local[0]= w;
BLK352:
	ctx->vsp=local; return(local[0]);}

/*:direction*/
static pointer M357line_direction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK358:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M359line_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET361,env,argv,local);
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[13];
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[1];
	w = local[0];
	ctx->vsp=local+6;
	w=FLET361(ctx,1,local+5,w);
	local[5]= w;
	local[6]= argv[0]->c.obj.iv[2];
	w = local[0];
	ctx->vsp=local+7;
	w=FLET361(ctx,1,local+6,w);
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,6,local+1); /*send-message*/
	local[0]= w;
BLK360:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M362line_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[29], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY364;
	local[0] = NIL;
KEY364:
	if (n & (1<<1)) goto KEY365;
	local[1] = NIL;
KEY365:
	if (local[0]==NIL) goto IF366;
	argv[0]->c.obj.iv[1] = local[0];
	local[2]= argv[0]->c.obj.iv[1];
	goto IF367;
IF366:
	local[2]= NIL;
IF367:
	if (local[1]==NIL) goto IF368;
	argv[0]->c.obj.iv[2] = local[1];
	local[2]= argv[0]->c.obj.iv[2];
	goto IF369;
IF368:
	local[2]= NIL;
IF369:
	w = argv[0];
	local[0]= w;
BLK363:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET361(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)30L);
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[30]); /*make-string-output-stream*/
	local[0]= w;
	local[1]= fqv[31];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL371:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX372;
	local[3]= local[0];
	local[4]= fqv[32];
	local[5]= argv[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL371;
WHX372:
	local[3]= NIL;
BLK373:
	w = NIL;
	local[1]= local[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= w;
	w = local[0];
	w->c.obj.iv[3] = local[2];
	local[1]= fqv[33];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PRINC(ctx,2,local+1); /*princ*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[34]); /*get-output-stream-string*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:foot*/
static pointer M376line_foot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	local[2]= w;
	local[3]= local[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[0]= w;
BLK377:
	ctx->vsp=local; return(local[0]);}

/*:common-perpendicular*/
static pointer M378line_common_perpendicular(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= argv[2]->c.obj.iv[2];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[1] = w;
	local[9]= local[1];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[1] = w;
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[2];
	local[11]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[2] = w;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[3] = w;
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORM(ctx,1,local+9); /*norm*/
	local[4] = w;
	local[9]= local[4];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[4] = w;
	local[9]= local[2];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= local[1];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)TIMES(ctx,2,local+10); /***/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[0] = w;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)ABS(ctx,1,local+9); /*abs*/
	local[9]= w;
	local[10]= loadglobal(fqv[35]);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto IF380;
	w = fqv[36];
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK379;
	goto IF381;
IF380:
	local[9]= argv[0]->c.obj.iv[2];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[5] = w;
	local[9]= argv[2]->c.obj.iv[2];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)VMINUS(ctx,2,local+9); /*v-*/
	local[9]= w;
	local[10]= argv[2]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,2,local+10); /*v-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[6] = w;
	local[9]= argv[0];
	local[10]= fqv[37];
	local[11]= local[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= local[2];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[7] = w;
	local[9]= argv[2];
	local[10]= fqv[37];
	local[11]= local[3];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)TIMES(ctx,2,local+11); /***/
	local[11]= w;
	local[12]= local[4];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)TIMES(ctx,2,local+12); /***/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[8] = w;
	local[9]= local[7];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK379;
IF381:
	w = local[9];
	local[0]= w;
BLK379:
	ctx->vsp=local; return(local[0]);}

/*:distance-point*/
static pointer M382line_distance_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[38];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto CON385;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON384;
CON385:
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto CON386;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON384;
CON386:
	local[2]= argv[0];
	local[3]= fqv[37];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	goto CON384;
CON387:
	local[2]= NIL;
CON384:
	w = local[2];
	local[0]= w;
BLK383:
	ctx->vsp=local; return(local[0]);}

/*:distance-line*/
static pointer M388line_distance_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= *(ovafptr(argv[2],fqv[39]));
	local[1]= *(ovafptr(argv[2],fqv[40]));
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
	local[12]= NIL;
	local[13]= NIL;
	local[14]= argv[0]->c.obj.iv[2];
	local[15]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+16;
	w=(pointer)VMINUS(ctx,2,local+14); /*v-*/
	local[14]= w;
	local[15]= local[1];
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)VMINUS(ctx,2,local+15); /*v-*/
	local[15]= w;
	local[16]= local[14];
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	local[17]= local[14];
	local[18]= local[14];
	ctx->vsp=local+19;
	w=(pointer)VINNERPRODUCT(ctx,2,local+17); /*v.*/
	local[17]= w;
	local[18]= local[15];
	local[19]= local[15];
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	local[19]= argv[0]->c.obj.iv[1];
	local[20]= local[0];
	ctx->vsp=local+21;
	w=(pointer)VMINUS(ctx,2,local+19); /*v-*/
	local[19]= w;
	local[20]= local[16];
	{ double x,y;
		y=fltval(local[16]); x=fltval(local[20]);
		local[20]=(makeflt(x * y));}
	local[21]= local[17];
	{ double x,y;
		y=fltval(local[18]); x=fltval(local[21]);
		local[21]=(makeflt(x * y));}
	{ double x,y;
		y=fltval(local[21]); x=fltval(local[20]);
		local[20]=(makeflt(x - y));}
	local[7] = local[20];
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)ABS(ctx,1,local+20); /*abs*/
	local[20]= w;
	local[21]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+22;
	w=(pointer)GREATERP(ctx,2,local+20); /*>*/
	if (w==NIL) goto IF390;
	local[20]= local[19];
	local[21]= local[14];
	ctx->vsp=local+22;
	w=(pointer)VINNERPRODUCT(ctx,2,local+20); /*v.*/
	local[12] = w;
	local[20]= local[19];
	local[21]= local[15];
	ctx->vsp=local+22;
	w=(pointer)VINNERPRODUCT(ctx,2,local+20); /*v.*/
	local[13] = w;
	local[20]= local[18];
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= local[16];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)QUOTIENT(ctx,2,local+20); /*/*/
	local[2] = w;
	local[20]= local[16];
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)TIMES(ctx,2,local+20); /***/
	local[20]= w;
	local[21]= local[17];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(pointer)TIMES(ctx,2,local+21); /***/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)MINUS(ctx,1,local+21); /*-*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)PLUS(ctx,2,local+20); /*+*/
	local[20]= w;
	local[21]= local[7];
	ctx->vsp=local+22;
	w=(pointer)QUOTIENT(ctx,2,local+20); /*/*/
	local[3] = w;
	local[20]= makeflt(0.0000000000000000000000e+00);
	local[21]= local[2];
	local[22]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,3,local+20); /*<*/
	if (w==NIL) goto IF392;
	local[20]= makeflt(0.0000000000000000000000e+00);
	local[21]= local[3];
	local[22]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,3,local+20); /*<*/
	if (w==NIL) goto IF392;
	local[20]= argv[0];
	local[21]= fqv[37];
	local[22]= local[2];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	local[21]= argv[2];
	local[22]= fqv[37];
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)VDISTANCE(ctx,2,local+20); /*distance*/
	ctx->vsp=local+20;
	local[0]=w;
	goto BLK389;
	goto IF393;
IF392:
	local[20]= NIL;
IF393:
	goto IF391;
IF390:
	local[20]= NIL;
IF391:
	local[20]= argv[0];
	local[21]= fqv[41];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[8] = w;
	local[20]= argv[0];
	local[21]= fqv[41];
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[9] = w;
	local[20]= argv[2];
	local[21]= fqv[41];
	local[22]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[10] = w;
	local[20]= argv[2];
	local[21]= fqv[41];
	local[22]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[11] = w;
	local[20]= local[8];
	local[21]= local[9];
	local[22]= local[10];
	local[23]= local[11];
	ctx->vsp=local+24;
	w=(pointer)MIN(ctx,4,local+20); /*min*/
	local[0]= w;
BLK389:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M394line_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[37];
	local[3]= argv[0];
	local[4]= fqv[38];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
BLK395:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M396line_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto CON399;
	local[0]= argv[0];
	local[1]= fqv[41];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON398;
CON399:
	local[0]= argv[2];
	local[1]= loadglobal(fqv[43]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON400;
	local[0]= argv[0];
	local[1]= fqv[44];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON398;
CON400:
	local[0]= NIL;
CON398:
	w = local[0];
	local[0]= w;
BLK397:
	ctx->vsp=local; return(local[0]);}

/*:colinear-point*/
static pointer M401line_colinear_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT404;}
	local[0]= loadglobal(fqv[45]);
ENT404:
ENT403:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[7])(ctx,4,local+1,&ftab[7],fqv[46]); /*colinear-p*/
	local[0]= w;
BLK402:
	ctx->vsp=local; return(local[0]);}

/*:on-line-point*/
static pointer M405line_on_line_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT408;}
	local[0]= loadglobal(fqv[45]);
ENT408:
ENT407:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	{ double x,y;
		y=fltval(w); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)VDISTANCE(ctx,2,local+4); /*distance*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F93eps__(ctx,3,local+3); /*eps<=*/
	local[0]= w;
BLK406:
	ctx->vsp=local; return(local[0]);}

/*:colinear-line*/
static pointer M409line_colinear_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT412;}
	local[0]= loadglobal(fqv[45]);
ENT412:
ENT411:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[47];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[47];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	local[3]= local[1];
	if (local[3]==NIL) goto AND413;
	local[3]= local[2];
	if (local[3]==NIL) goto AND413;
	local[3]= T;
AND413:
	w = local[3];
	local[0]= w;
BLK410:
	ctx->vsp=local; return(local[0]);}

/*:colinear-line-intersection*/
static pointer M414line_colinear_line_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	local[1]= argv[2]->c.obj.iv[2];
	local[2]= argv[0];
	local[3]= fqv[48];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[48];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w==NIL) goto IF416;
	local[6]= local[2];
	local[7]= local[3];
	local[3] = local[6];
	local[2] = local[7];
	w = NIL;
	local[6]= w;
	goto IF417;
IF416:
	local[6]= NIL;
IF417:
	local[6]= local[3];
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w!=NIL) goto OR422;
	local[6]= local[2];
	local[7]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(pointer)GREATERP(ctx,2,local+6); /*>*/
	if (w!=NIL) goto OR422;
	goto CON421;
OR422:
	local[6]= NIL;
	goto CON420;
CON421:
	local[6]= makeflt(0.0000000000000000000000e+00);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAX(ctx,2,local+6); /*max*/
	local[4] = w;
	local[6]= makeflt(1.0000000000000000000000e+00);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MIN(ctx,2,local+6); /*min*/
	local[5] = w;
	local[6]= argv[0];
	local[7]= fqv[37];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= fqv[37];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F106make_line(ctx,2,local+6); /*make-line*/
	local[6]= w;
	goto CON420;
CON423:
	local[6]= NIL;
CON420:
	w = local[6];
	local[0]= w;
BLK415:
	ctx->vsp=local; return(local[0]);}

/*:coplanar*/
static pointer M424line_coplanar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT427;}
	local[0]= loadglobal(fqv[45]);
ENT427:
ENT426:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,5,local+1,&ftab[8],fqv[49]); /*coplanar-p*/
	local[0]= w;
BLK425:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M428line_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[50];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[50];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
BLK429:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M430line_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,4,local+0,&ftab[9],fqv[51]); /*line-intersection3*/
	local[0]= w;
BLK431:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M432line_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT435;}
	local[0]= loadglobal(fqv[35]);
ENT435:
ENT434:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	local[4]= argv[2]->c.obj.iv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[9])(ctx,5,local+1,&ftab[9],fqv[51]); /*line-intersection3*/
	local[1]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	if (local[1]!=NIL) goto CON437;
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[2] = w;
	if (local[2]!=NIL) goto IF438;
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK433;
	goto IF439;
IF438:
	local[8]= NIL;
IF439:
	local[8]= argv[0];
	local[9]= fqv[47];
	local[10]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[3] = w;
	if (local[3]!=NIL) goto IF440;
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK433;
	goto IF441;
IF440:
	local[8]= NIL;
IF441:
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF442;
	local[8]= local[3];
	local[9]= local[2];
	local[2] = local[8];
	local[3] = local[9];
	w = NIL;
	local[8]= w;
	goto IF443;
IF442:
	local[8]= NIL;
IF443:
	local[8]= local[3];
	local[9]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)F91eps_(ctx,2,local+8); /*eps<*/
	if (w!=NIL) goto OR448;
	local[8]= local[2];
	local[9]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)F92eps_(ctx,2,local+8); /*eps>*/
	if (w!=NIL) goto OR448;
	goto IF446;
OR448:
	w = fqv[52];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK433;
	goto IF447;
IF446:
	local[8]= NIL;
IF447:
	local[8]= argv[2];
	local[9]= fqv[47];
	local[10]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[6] = w;
	local[8]= argv[2];
	local[9]= fqv[47];
	local[10]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[7] = w;
	if (local[6]==NIL) goto AND451;
	if (local[7]==NIL) goto AND451;
	goto IF449;
AND451:
	w = fqv[36];
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK433;
	goto IF450;
IF449:
	local[8]= NIL;
IF450:
	local[8]= local[7];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF452;
	local[8]= local[7];
	local[9]= local[6];
	local[6] = local[8];
	local[7] = local[9];
	w = NIL;
	local[8]= w;
	goto IF453;
IF452:
	local[8]= NIL;
IF453:
	local[8]= fqv[53];
	local[9]= makeflt(0.0000000000000000000000e+00);
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MAX(ctx,2,local+9); /*max*/
	local[9]= w;
	local[10]= makeflt(1.0000000000000000000000e+00);
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MIN(ctx,2,local+10); /*min*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	local[10]= makeflt(0.0000000000000000000000e+00);
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)MAX(ctx,2,local+10); /*max*/
	local[10]= w;
	local[11]= makeflt(1.0000000000000000000000e+00);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MIN(ctx,2,local+11); /*min*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,2,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	goto CON436;
CON437:
	local[8]= makeflt(0.0000000000000000000000e+00);
	local[9]= local[2];
	local[10]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)F97eps_in_range(ctx,3,local+8); /*eps-in-range*/
	if (w==NIL) goto CON456;
	local[8]= makeflt(0.0000000000000000000000e+00);
	local[9]= local[3];
	local[10]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)F97eps_in_range(ctx,3,local+8); /*eps-in-range*/
	if (w==NIL) goto CON456;
	local[8]= fqv[54];
	local[9]= local[2];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,3,local+8); /*list*/
	local[8]= w;
	goto CON436;
CON456:
	local[8]= NIL;
	goto CON436;
CON457:
	local[8]= NIL;
CON436:
	w = local[8];
	local[0]= w;
BLK433:
	ctx->vsp=local; return(local[0]);}

/*make-line*/
static pointer F106make_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[43]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[24];
	local[3]= fqv[55];
	local[4]= argv[0];
	local[5]= fqv[56];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,6,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK458:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M460edge_faces(ctx,n,argv,env)
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
BLK461:
	ctx->vsp=local; return(local[0]);}

/*:pvertex*/
static pointer M462edge_pvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON465;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON464;
CON465:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON466;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON464;
CON466:
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON464;
CON467:
	local[0]= NIL;
CON464:
	w = local[0];
	local[0]= w;
BLK463:
	ctx->vsp=local; return(local[0]);}

/*:nvertex*/
static pointer M468edge_nvertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON471;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON470;
CON471:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON472;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON470;
CON472:
	local[0]= fqv[58];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON470;
CON473:
	local[0]= NIL;
CON470:
	w = local[0];
	local[0]= w;
BLK469:
	ctx->vsp=local; return(local[0]);}

/*:next-edge*/
static pointer M474edge_next_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[59];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK475:
	ctx->vsp=local; return(local[0]);}

/*:next-vertex*/
static pointer M476edge_next_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[59];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[56];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK477:
	ctx->vsp=local; return(local[0]);}

/*:direction*/
static pointer M478edge_direction(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT481;}
	local[0]= argv[0]->c.obj.iv[3];
ENT481:
ENT480:
	if (n>3) maerror();
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]!=local[1]) goto CON483;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON482;
CON483:
	local[1]= local[0];
	if (argv[0]->c.obj.iv[4]!=local[1]) goto CON484;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON482;
CON484:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F86facep(ctx,1,local+1); /*facep*/
	if (w==NIL) goto CON485;
	local[1]= NIL;
	local[2]= local[0];
	local[3]= fqv[60];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL487:
	if (local[2]==NIL) goto WHX488;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[0];
	local[4]= local[1];
	local[5]= fqv[61];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (memq(local[3],w)==NIL) goto IF491;
	local[3]= argv[0];
	local[4]= fqv[62];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK479;
	goto IF492;
IF491:
	local[3]= NIL;
IF492:
	goto WHL487;
WHX488:
	local[3]= NIL;
BLK489:
	w = NIL;
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON482;
CON485:
	local[1]= fqv[64];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON482;
CON493:
	local[1]= NIL;
CON482:
	w = local[1];
	local[0]= w;
BLK479:
	ctx->vsp=local; return(local[0]);}

/*:next-edge-angle*/
static pointer M494edge_next_edge_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[59];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[62];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76vector_angle(ctx,3,local+0); /*vector-angle*/
	local[0]= w;
BLK495:
	ctx->vsp=local; return(local[0]);}

/*:previous-edge-angle*/
static pointer M496edge_previous_edge_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= fqv[66];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[62];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76vector_angle(ctx,3,local+0); /*vector-angle*/
	local[0]= w;
BLK497:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M498edge_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto CON501;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON500;
CON501:
	if (argv[0]->c.obj.iv[4]==NIL) goto CON502;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON500;
CON502:
	local[0]= NIL;
CON500:
	w = local[0];
	local[0]= w;
BLK499:
	ctx->vsp=local; return(local[0]);}

/*:pface*/
static pointer M503edge_pface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON506;
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON506;
	local[0]= argv[0]->c.obj.iv[3];
	goto CON505;
CON506:
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON507;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON507;
	local[0]= argv[0]->c.obj.iv[4];
	goto CON505;
CON507:
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON505;
CON508:
	local[0]= NIL;
CON505:
	w = local[0];
	local[0]= w;
BLK504:
	ctx->vsp=local; return(local[0]);}

/*:nface*/
static pointer M509edge_nface(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON512;
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON512;
	local[0]= argv[0]->c.obj.iv[4];
	goto CON511;
CON512:
	local[0]= argv[3];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON513;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON513;
	local[0]= argv[0]->c.obj.iv[3];
	goto CON511;
CON513:
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON511;
CON514:
	local[0]= NIL;
CON511:
	w = local[0];
	local[0]= w;
BLK510:
	ctx->vsp=local; return(local[0]);}

/*:another-face*/
static pointer M515edge_another_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto IF517;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF518;
IF517:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto IF519;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF520;
IF519:
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(*ftab[10])(ctx,1,local+0,&ftab[10],fqv[71]); /*warn*/
	local[0]= w;
IF520:
IF518:
	w = local[0];
	local[0]= w;
BLK516:
	ctx->vsp=local; return(local[0]);}

/*:binormal*/
static pointer M521edge_binormal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto CON524;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	goto CON523;
CON524:
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[4]!=local[0]) goto CON525;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	goto CON523;
CON525:
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= fqv[73];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON523;
CON526:
	local[0]= NIL;
CON523:
	local[1]= argv[2];
	local[2]= fqv[65];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+0); /*v**/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
BLK522:
	ctx->vsp=local; return(local[0]);}

/*:angle*/
static pointer M527edge_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK528:
	ctx->vsp=local; return(local[0]);}

/*:approximated-p*/
static pointer M529edge_approximated_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[6];
	w = makeint((eusinteger_t)1L);
	local[0]= (pointer)((eusinteger_t)local[0] & (eusinteger_t)w);
	w = ((makeint((eusinteger_t)1L))==(local[0])?T:NIL);
	local[0]= w;
BLK530:
	ctx->vsp=local; return(local[0]);}

/*:flags*/
static pointer M531edge_flags(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK532:
	ctx->vsp=local; return(local[0]);}

/*:contourp*/
static pointer M533edge_contourp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF535;
	if (argv[0]->c.obj.iv[4]==NIL) goto IF535;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[74];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	local[2]= w;
	if (w==NIL) goto AND538;
	local[2]= local[1];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	local[2]= w;
AND538:
	if (local[2]!=NIL) goto OR537;
	local[2]= local[0];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	local[2]= w;
	if (w==NIL) goto AND539;
	local[2]= local[1];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	local[2]= w;
AND539:
OR537:
	w = local[2];
	local[0]= w;
	goto IF536;
IF535:
	local[0]= T;
IF536:
	w = local[0];
	local[0]= w;
BLK534:
	ctx->vsp=local; return(local[0]);}

/*:set-approximated-flag*/
static pointer M540edge_set_approximated_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT543;}
	local[0]= makeflt(6.9999999999999973354647e-01);
ENT543:
ENT542:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,1,local+1); /*-*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,3,local+1); /*<*/
	if (w==NIL) goto IF544;
	local[1]= argv[0]->c.obj.iv[6];
	w = makeint((eusinteger_t)1L);
	argv[0]->c.obj.iv[6] = (pointer)((eusinteger_t)local[1] | (eusinteger_t)w);
	local[1]= argv[0]->c.obj.iv[6];
	goto IF545;
IF544:
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)LOGNOT(ctx,1,local+2); /*lognot*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LOGAND(ctx,2,local+1); /*logand*/
	argv[0]->c.obj.iv[6] = w;
	local[1]= argv[0]->c.obj.iv[6];
IF545:
	w = local[1];
	local[0]= w;
BLK541:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M546edge_invert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[0] = argv[0]->c.obj.iv[4];
	argv[0]->c.obj.iv[4] = argv[0]->c.obj.iv[3];
	argv[0]->c.obj.iv[3] = local[0];
	w = argv[0]->c.obj.iv[3];
	w = argv[0];
	local[0]= w;
BLK547:
	ctx->vsp=local; return(local[0]);}

/*:set-angle*/
static pointer M548edge_set_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[4]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F76vector_angle(ctx,3,local+0); /*vector-angle*/
	argv[0]->c.obj.iv[5] = w;
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK549:
	ctx->vsp=local; return(local[0]);}

/*:set-face*/
static pointer M550edge_set_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON553;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON553;
	argv[0]->c.obj.iv[3] = argv[4];
	local[0]= argv[0]->c.obj.iv[3];
	goto CON552;
CON553:
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON554;
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON554;
	argv[0]->c.obj.iv[4] = argv[4];
	local[0]= argv[0]->c.obj.iv[4];
	goto CON552;
CON554:
	local[0]= argv[0];
	local[1]= fqv[72];
	local[2]= fqv[75];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON552;
CON555:
	local[0]= NIL;
CON552:
	w = local[0];
	local[0]= w;
BLK551:
	ctx->vsp=local; return(local[0]);}

/*:contact*/
static pointer M556edge_contact(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[76];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[23]);
	local[2]= loadglobal(fqv[77]);
	local[3]= local[0];
	if (fqv[36]==local[3]) goto IF558;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORM(ctx,1,local+3); /*norm*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF560;
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= fqv[48];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto IF560;
	local[3]= makeflt(-1.0000000000000000000000e+00);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= argv[2];
	local[5]= fqv[48];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,3,local+3); /*<*/
	if (w==NIL) goto IF560;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF561;
IF560:
	local[3]= NIL;
IF561:
	goto IF559;
IF558:
	local[3]= NIL;
IF559:
	w = local[3];
	local[0]= w;
BLK557:
	ctx->vsp=local; return(local[0]);}

/*:neighborpoints*/
static pointer M562edge_neighborpoints(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[78];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(2.0000000000000000000000e+00);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[78];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= *(ovafptr(argv[0]->c.obj.iv[3],fqv[79]));
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,2,local+2); /*v+*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= *(ovafptr(argv[0]->c.obj.iv[4],fqv[79]));
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+4); /*v**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,2,local+3); /*v+*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,4,local+0); /*list*/
	local[0]= w;
BLK563:
	ctx->vsp=local; return(local[0]);}

/*:anothervertex*/
static pointer M564edge_anothervertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORM(ctx,1,local+0); /*norm*/
	local[0]= makeflt((double)fabs(fltval(w)));
	local[1]= loadglobal(fqv[80]);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF566;
	local[0]= argv[0]->c.obj.iv[1];
	goto IF567;
IF566:
	local[0]= argv[0]->c.obj.iv[2];
IF567:
	w = local[0];
	local[0]= w;
BLK565:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M568edge_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT571;}
	local[0]= NIL;
ENT571:
ENT570:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF572;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[81];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF573;
IF572:
	local[1]= argv[0];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto IF574;
	local[1]= local[0];
	goto IF575;
IF574:
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
IF575:
IF573:
	w = local[1];
	local[0]= w;
BLK569:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M576edge_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST578:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[82], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY579;
	local[1] = NIL;
KEY579:
	if (n & (1<<1)) goto KEY580;
	local[2] = NIL;
KEY580:
	if (n & (1<<2)) goto KEY581;
	local[3] = NIL;
KEY581:
	if (n & (1<<3)) goto KEY582;
	local[4] = NIL;
KEY582:
	if (n & (1<<4)) goto KEY583;
	local[5] = makeint((eusinteger_t)0L);
KEY583:
	local[6]= (pointer)get_sym_func(fqv[83]);
	local[7]= argv[0];
	local[8]= *(ovafptr(argv[1],fqv[12]));
	local[9]= fqv[24];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,5,local+6); /*apply*/
	if (local[1]==NIL) goto IF584;
	argv[0]->c.obj.iv[3] = local[1];
	local[6]= argv[0]->c.obj.iv[3];
	goto IF585;
IF584:
	local[6]= NIL;
IF585:
	if (local[2]==NIL) goto IF586;
	argv[0]->c.obj.iv[4] = local[2];
	local[6]= argv[0]->c.obj.iv[4];
	goto IF587;
IF586:
	local[6]= NIL;
IF587:
	if (local[3]==NIL) goto IF588;
	argv[0]->c.obj.iv[5] = local[3];
	local[6]= argv[0]->c.obj.iv[5];
	goto IF589;
IF588:
	local[6]= NIL;
IF589:
	argv[0]->c.obj.iv[6] = local[5];
	if (local[4]==NIL) goto IF590;
	local[6]= argv[0];
	local[7]= fqv[84];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	goto IF591;
IF590:
	local[6]= NIL;
IF591:
	w = argv[0];
	local[0]= w;
BLK577:
	ctx->vsp=local; return(local[0]);}

/*:center-coordinates*/
static pointer M592edge_center_coordinates(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)VNORMALIZE(ctx,1,local+0); /*normalize-vector*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[85];
	ctx->vsp=local+3;
	w=(pointer)VDISTANCE(ctx,2,local+1); /*distance*/
	local[1]= w;
	{ double left,right;
		right=fltval(makeflt(9.9999999999999991239646e-05)); left=fltval(local[1]);
	if (left >= right) goto IF594;}
	local[1]= fqv[86];
	goto IF595;
IF594:
	local[1]= fqv[87];
IF595:
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+2); /*v**/
	local[2]= w;
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+3); /*v**/
	local[1] = w;
	local[3]= loadglobal(fqv[88]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= fqv[89];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[11])(ctx,3,local+7,&ftab[11],fqv[90]); /*matrix*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)TRANSPOSE(ctx,1,local+7); /*transpose*/
	local[7]= w;
	local[8]= fqv[91];
	local[9]= makeflt(5.0000000000000000000000e-01);
	local[10]= argv[0]->c.obj.iv[2];
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)VPLUS(ctx,3,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK593:
	ctx->vsp=local; return(local[0]);}

/*:pwing*/
static pointer M597edge_pwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL600:
	if (local[2]==NIL) goto WHX601;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF604;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR606;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR606;
	goto IF604;
OR606:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK598;
	goto IF605;
IF604:
	local[3]= NIL;
IF605:
	goto WHL600;
WHX601:
	local[3]= NIL;
BLK602:
	w = NIL;
	local[1]= fqv[93];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK598:
	ctx->vsp=local; return(local[0]);}

/*:pcwing*/
static pointer M607edge_pcwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL610:
	if (local[2]==NIL) goto WHX611;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF614;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR616;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR616;
	goto IF614;
OR616:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK608;
	goto IF615;
IF614:
	local[3]= NIL;
IF615:
	goto WHL610;
WHX611:
	local[3]= NIL;
BLK612:
	w = NIL;
	local[1]= fqv[94];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK608:
	ctx->vsp=local; return(local[0]);}

/*:nwing*/
static pointer M617edge_nwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL620:
	if (local[2]==NIL) goto WHX621;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF624;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR626;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]==local[3]) goto OR626;
	goto IF624;
OR626:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK618;
	goto IF625;
IF624:
	local[3]= NIL;
IF625:
	goto WHL620;
WHX621:
	local[3]= NIL;
BLK622:
	w = NIL;
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK618:
	ctx->vsp=local; return(local[0]);}

/*:ncwing*/
static pointer M627edge_ncwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[92];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
WHL630:
	if (local[2]==NIL) goto WHX631;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	if (argv[0]==local[3]) goto IF634;
	local[3]= local[1]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR636;
	local[3]= local[1]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]==local[3]) goto OR636;
	goto IF634;
OR636:
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK628;
	goto IF635;
IF634:
	local[3]= NIL;
IF635:
	goto WHL630;
WHX631:
	local[3]= NIL;
BLK632:
	w = NIL;
	local[1]= fqv[96];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[0]= w;
BLK628:
	ctx->vsp=local; return(local[0]);}

/*:connected-vertex*/
static pointer M637edge_connected_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON640;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON639;
CON640:
	local[0]= argv[2]->c.obj.iv[1];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON641;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON639;
CON641:
	local[0]= argv[2]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[1]!=local[0]) goto CON642;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON639;
CON642:
	local[0]= argv[2]->c.obj.iv[2];
	if (argv[0]->c.obj.iv[2]!=local[0]) goto CON643;
	local[0]= argv[0]->c.obj.iv[2];
	goto CON639;
CON643:
	local[0]= fqv[97];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto CON639;
CON644:
	local[0]= NIL;
CON639:
	w = local[0];
	local[0]= w;
BLK638:
	ctx->vsp=local; return(local[0]);}

/*:replace-face*/
static pointer M645edge_replace_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON648;
	argv[0]->c.obj.iv[3] = argv[3];
	local[0]= argv[0]->c.obj.iv[3];
	goto CON647;
CON648:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto CON649;
	argv[0]->c.obj.iv[4] = argv[3];
	local[0]= argv[0]->c.obj.iv[4];
	goto CON647;
CON649:
	local[0]= fqv[98];
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,3,local+0); /*error*/
	local[0]= w;
	goto CON647;
CON650:
	local[0]= NIL;
CON647:
	w = local[0];
	local[0]= w;
BLK646:
	ctx->vsp=local; return(local[0]);}

/*winged-edge-p*/
static pointer F107winged_edge_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[99]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK651:
	ctx->vsp=local; return(local[0]);}

/*:set-wings*/
static pointer M652winged_edge_set_wings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[100];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[7] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[101];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[9] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[102];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[8] = w;
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[103];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	argv[0]->c.obj.iv[10] = w;
	w = argv[0];
	local[0]= w;
BLK653:
	ctx->vsp=local; return(local[0]);}

/*:pwing*/
static pointer M654winged_edge_pwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK655:
	ctx->vsp=local; return(local[0]);}

/*:nwing*/
static pointer M656winged_edge_nwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[9];
	local[0]= w;
BLK657:
	ctx->vsp=local; return(local[0]);}

/*:pcwing*/
static pointer M658winged_edge_pcwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK659:
	ctx->vsp=local; return(local[0]);}

/*:ncwing*/
static pointer M660winged_edge_ncwing(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK661:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M662winged_edge_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST664:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[104], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY665;
	local[1] = NIL;
KEY665:
	if (n & (1<<1)) goto KEY666;
	local[2] = NIL;
KEY666:
	if (n & (1<<2)) goto KEY667;
	local[3] = NIL;
KEY667:
	if (n & (1<<3)) goto KEY668;
	local[4] = NIL;
KEY668:
	local[5]= (pointer)get_sym_func(fqv[83]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[12]));
	local[8]= fqv[24];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,5,local+5); /*apply*/
	if (local[1]==NIL) goto IF669;
	argv[0]->c.obj.iv[7] = local[1];
	local[5]= argv[0]->c.obj.iv[7];
	goto IF670;
IF669:
	local[5]= NIL;
IF670:
	if (local[2]==NIL) goto IF671;
	argv[0]->c.obj.iv[9] = local[2];
	local[5]= argv[0]->c.obj.iv[9];
	goto IF672;
IF671:
	local[5]= NIL;
IF672:
	if (local[3]==NIL) goto IF673;
	argv[0]->c.obj.iv[8] = local[3];
	local[5]= argv[0]->c.obj.iv[8];
	goto IF674;
IF673:
	local[5]= NIL;
IF674:
	if (local[4]==NIL) goto IF675;
	argv[0]->c.obj.iv[10] = local[4];
	local[5]= argv[0]->c.obj.iv[10];
	goto IF676;
IF675:
	local[5]= NIL;
IF676:
	w = argv[0];
	local[0]= w;
BLK663:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M678plane_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK679:
	ctx->vsp=local; return(local[0]);}

/*:normal*/
static pointer M680plane_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK681:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M682plane_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	w = local[0];
	local[0]= w;
BLK683:
	ctx->vsp=local; return(local[0]);}

/*:plane-distance*/
static pointer M684plane_plane_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	w = local[0];
	local[0]= w;
BLK685:
	ctx->vsp=local; return(local[0]);}

/*:on-plane-p*/
static pointer M686plane_on_plane_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT689;}
	local[0]= loadglobal(fqv[8]);
ENT689:
ENT688:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F93eps__(ctx,2,local+1); /*eps<=*/
	local[0]= w;
BLK687:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-point*/
static pointer M690plane_coplanar_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT693;}
	local[0]= loadglobal(fqv[45]);
ENT693:
ENT692:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[0]= w;
BLK691:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-line*/
static pointer M694plane_coplanar_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT697;}
	local[0]= loadglobal(fqv[45]);
ENT697:
ENT696:
	if (n>4) maerror();
	local[1]= argv[2]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[1]= w;
	if (w==NIL) goto AND698;
	local[1]= argv[2]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(0.0000000000000000000000e+00);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F90eps_(ctx,3,local+1); /*eps=*/
	local[1]= w;
AND698:
	w = local[1];
	local[0]= w;
BLK695:
	ctx->vsp=local; return(local[0]);}

/*:intersection*/
static pointer M699plane_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= local[1];
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[0])))); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= argv[0]->c.obj.iv[2];
	{ double x,y;
		y=fltval(local[1]); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[0]= w;
BLK700:
	ctx->vsp=local; return(local[0]);}

/*:intersect-edge*/
static pointer M701plane_intersect_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	local[2]= local[0];
	local[3]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)F97eps_in_range(ctx,3,local+1); /*eps-in-range*/
	if (w==NIL) goto IF703;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[37];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	goto IF704;
IF703:
	local[1]= makeflt(0.0000000000000000000000e+00);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto OR707;
	local[1]= makeflt(1.0000000000000000000000e+00);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto OR707;
	goto IF705;
OR707:
	local[1]= T;
	local[2]= fqv[106];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= w;
	goto IF706;
IF705:
	local[1]= NIL;
IF706:
IF704:
	w = local[1];
	local[0]= w;
BLK702:
	ctx->vsp=local; return(local[0]);}

/*:foot*/
static pointer M708plane_foot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x + y));}
	local[1]= argv[2];
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK709:
	ctx->vsp=local; return(local[0]);}

/*:original-body*/
static pointer M710plane_original_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK711:
	ctx->vsp=local; return(local[0]);}

/*:brightness*/
static pointer M712plane_brightness(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeflt(1.0000000000000000000000e+00);
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
BLK713:
	ctx->vsp=local; return(local[0]);}

/*:project*/
static pointer M714plane_project(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT717;}
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
ENT717:
ENT716:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[2]);
		local[2]=(makeflt(x + y));}
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,2,local+2); /*scale*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK715:
	ctx->vsp=local; return(local[0]);}

/*:separation*/
static pointer M718plane_separation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	local[4]= argv[2];
WHL721:
	if (local[4]==NIL) goto WHX722;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[74];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= loadglobal(fqv[80]);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF725;
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[107]); /*minusp*/
	if (w==NIL) goto IF727;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK719;
	goto IF728;
IF727:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF729;
	local[1] = local[0];
	local[5]= local[1];
	goto IF730;
IF729:
	local[5]= NIL;
IF730:
IF728:
	goto IF726;
IF725:
	local[5]= NIL;
IF726:
	goto WHL721;
WHX722:
	local[5]= NIL;
BLK723:
	w = NIL;
	local[3]= NIL;
	local[4]= argv[3];
WHL732:
	if (local[4]==NIL) goto WHX733;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[74];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= loadglobal(fqv[80]);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF736;
	local[5]= local[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[12])(ctx,1,local+5,&ftab[12],fqv[107]); /*minusp*/
	if (w==NIL) goto IF738;
	w = NIL;
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK719;
	goto IF739;
IF738:
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto IF740;
	local[2] = local[0];
	local[5]= local[2];
	goto IF741;
IF740:
	local[5]= NIL;
IF741:
IF739:
	goto IF737;
IF736:
	local[5]= NIL;
IF737:
	goto WHL732;
WHX733:
	local[5]= NIL;
BLK734:
	w = NIL;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[12])(ctx,1,local+3,&ftab[12],fqv[107]); /*minusp*/
	if (w==NIL) goto IF742;
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VNORMALIZE(ctx,1,local+3); /*normalize-vector*/
	local[3]= w;
	goto IF743;
IF742:
	local[3]= NIL;
IF743:
	w = local[3];
	local[0]= w;
BLK719:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M744plane_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto IF746;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	argv[0]->c.obj.iv[2] = makeflt(-(fltval(w)));
	local[0]= argv[0]->c.obj.iv[2];
	goto IF747;
IF746:
	w = argv[3];
	if (!isnum(w)) goto IF748;
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)EUSFLOAT(ctx,1,local+0); /*float*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[0]->c.obj.iv[2];
	goto IF749;
IF748:
	local[0]= fqv[108];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF749:
IF747:
	w = argv[0];
	local[0]= w;
BLK745:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M750polygon_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK751:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M752polygon_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK753:
	ctx->vsp=local; return(local[0]);}

/*:edge*/
static pointer M754polygon_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK755:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M756polygon_all_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK757:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M758polygon_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK759:
	ctx->vsp=local; return(local[0]);}

/*:vertex*/
static pointer M760polygon_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK761:
	ctx->vsp=local; return(local[0]);}

/*:next-edge*/
static pointer M762polygon_next_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[4];
	argv[2] = memq(local[0],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF764;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF765;
IF764:
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF765:
	w = local[0];
	local[0]= w;
BLK763:
	ctx->vsp=local; return(local[0]);}

/*:previous-edge*/
static pointer M766polygon_previous_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (argv[2]!=local[0]) goto IF768;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[109]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF769;
IF768:
	local[0]= argv[0]->c.obj.iv[4];
WHL770:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX771;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto IF773;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK767;
	goto IF774;
IF773:
	local[1]= NIL;
IF774:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	goto WHL770;
WHX771:
	local[1]= NIL;
BLK772:
	w = local[1];
	local[0]= w;
IF769:
	w = local[0];
	local[0]= w;
BLK767:
	ctx->vsp=local; return(local[0]);}

/*:adjacent-faces*/
static pointer M776polygon_adjacent_faces(ctx,n,argv,env)
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
	local[5]= argv[0]->c.obj.iv[4];
WHL779:
	if (local[5]==NIL) goto WHX780;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[2] = local[4]->c.obj.iv[3];
	local[3] = local[4]->c.obj.iv[4];
	local[6]= local[2];
	if (argv[0]!=local[6]) goto IF783;
	local[6]= local[3];
	goto IF784;
IF783:
	local[6]= local[2];
IF784:
	w = local[1];
	ctx->vsp=local+7;
	local[1] = cons(ctx,local[6],w);
	goto WHL779;
WHX780:
	local[6]= NIL;
BLK781:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK777:
	ctx->vsp=local; return(local[0]);}

/*:convexp*/
static pointer M785polygon_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK786:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M787polygon_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT790;}
	local[0]= NIL;
ENT790:
ENT789:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[15]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= argv[0]->c.obj.iv[5];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK788:
	ctx->vsp=local; return(local[0]);}

/*:boxtest*/
static pointer M792polygon_boxtest(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT795;}
	local[0]= NIL;
ENT795:
ENT794:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[25];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[26];
	local[3]= loadglobal(fqv[15]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= argv[0]->c.obj.iv[5];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK793:
	ctx->vsp=local; return(local[0]);}

/*:vertices-mean*/
static pointer M797polygon_vertices_mean(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F72vector_mean(ctx,1,local+0); /*vector-mean*/
	local[0]= w;
BLK798:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M799polygon_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[110]); /*signum*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[38];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[1];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF801;
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	w = fqv[112];
	if (memq(local[2],w)==NIL) goto IF803;
	local[2]= makeflt(0.0000000000000000000000e+00);
	goto IF804;
IF803:
	local[2]= (pointer)get_sym_func(fqv[113]);
	local[3]= argv[0]->c.obj.iv[4];
	local[4]= fqv[74];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,3,local+3,&ftab[15],fqv[114]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
IF804:
	goto IF802;
IF801:
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[115];
	if (memq(local[3],w)==NIL) goto IF805;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	goto IF806;
IF805:
	local[3]= (pointer)get_sym_func(fqv[113]);
	local[4]= argv[0]->c.obj.iv[4];
	local[5]= fqv[74];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,3,local+4,&ftab[15],fqv[114]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
IF806:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
IF802:
	w = local[2];
	local[0]= w;
BLK800:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M807polygon_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F72vector_mean(ctx,1,local+1); /*vector-mean*/
	local[1]= w;
	local[2]= makeflt(0.0000000000000000000000e+00);
WHL809:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX810;
	local[3]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)F74triangle(ctx,4,local+4); /*triangle*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[2] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	goto WHL809;
WHX810:
	local[3]= NIL;
BLK811:
	local[3]= local[2];
	local[4]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[0]= w;
BLK808:
	ctx->vsp=local; return(local[0]);}

/*:perimeter*/
static pointer M813polygon_perimeter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[116]);
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[117];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,2,local+1,&ftab[15],fqv[114]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK814:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M815polygon_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT818;}
	local[0]= fqv[118];
ENT818:
ENT817:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[119];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[1]= w;
	local[2]= makeflt(-3.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[0]= w;
BLK816:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M819polygon_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT822;}
	local[0]= NIL;
ENT822:
ENT821:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F72vector_mean(ctx,1,local+4); /*vector-mean*/
	local[4]= w;
	local[5]= makeflt(0.0000000000000000000000e+00);
	local[6]= makeflt(0.0000000000000000000000e+00);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
WHL823:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX824;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[9];
	local[2] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[4];
	local[12]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+13;
	w=(pointer)F74triangle(ctx,4,local+9); /*triangle*/
	local[5] = w;
	local[9]= local[6];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[6] = w;
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	local[9]= local[4];
	local[10]= local[8];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	local[9]= local[7];
	local[10]= local[5];
	local[11]= makeflt(3.0000000000000000000000e+00);
	ctx->vsp=local+12;
	w=(pointer)QUOTIENT(ctx,2,local+10); /*/*/
	local[10]= w;
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,3,local+9); /*v+*/
	goto WHL823;
WHX824:
	local[9]= NIL;
BLK825:
	local[9]= makeflt(1.0000000000000000000000e+00);
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SCALEVEC(ctx,2,local+9); /*scale*/
	local[7] = w;
	local[9]= local[6];
	local[10]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[6] = w;
	if (local[0]==NIL) goto IF827;
	local[9]= local[6];
	local[10]= argv[0];
	local[11]= fqv[105];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)TIMES(ctx,2,local+9); /***/
	local[9]= w;
	local[10]= makeflt(-3.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= makeflt(7.5000000000000000000000e-01);
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SCALEVEC(ctx,2,local+10); /*scale*/
	local[10]= w;
	local[11]= makeflt(2.5000000000000000000000e-01);
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)VPLUS(ctx,2,local+10); /*v+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
	goto IF828;
IF827:
	local[9]= local[6];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,2,local+9); /*list*/
	local[9]= w;
IF828:
	w = local[9];
	local[0]= w;
BLK820:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M829polygon_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT832;}
	local[0]= NIL;
ENT832:
ENT831:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF833;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[81];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF834;
IF833:
	local[1]= NIL;
IF834:
	local[1]= argv[0];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0]= w;
BLK830:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M835polygon_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT838;}
	local[0]= loadglobal(fqv[8]);
ENT838:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT837:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeflt(0.0000000000000000000000e+00);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (argv[0]->c.obj.iv[3]==NIL) goto CON840;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[9]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
WHL842:
	if (local[10]==NIL) goto WHX843;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[4];
	local[12]= local[9];
	local[13]= argv[2];
	local[14]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+15;
	w=(pointer)F74triangle(ctx,4,local+11); /*triangle*/
	local[7] = w;
	local[11]= local[7];
	local[12]= local[4];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)VDISTANCE(ctx,2,local+12); /*distance*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)QUOTIENT(ctx,2,local+11); /*/*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)F96eps_zero(ctx,1,local+11); /*eps-zero*/
	if (w==NIL) goto CON847;
	local[11]= local[9];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)VMINUS(ctx,2,local+11); /*v-*/
	local[11]= w;
	local[12]= argv[2];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)VMINUS(ctx,2,local+12); /*v-*/
	local[12]= w;
	local[13]= local[11];
	local[14]= local[12];
	ctx->vsp=local+15;
	w=(pointer)VINNERPRODUCT(ctx,2,local+13); /*v.*/
	local[13]= w;
	local[14]= local[11];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)VINNERPRODUCT(ctx,2,local+14); /*v.*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)QUOTIENT(ctx,2,local+13); /*/*/
	local[6] = w;
	local[11]= makeflt(0.0000000000000000000000e+00);
	local[12]= local[6];
	local[13]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+14;
	w=(pointer)F97eps_in_range(ctx,3,local+11); /*eps-in-range*/
	if (w==NIL) goto IF848;
	w = fqv[120];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK836;
	goto IF849;
IF848:
	local[11]= NIL;
IF849:
	goto CON846;
CON847:
	local[11]= local[7];
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[11]);
	if (left >= right) goto CON850;}
	w = fqv[52];
	ctx->vsp=local+11;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK836;
	goto CON846;
CON850:
	local[11]= NIL;
CON846:
	local[4] = local[9];
	goto WHL842;
WHX843:
	local[11]= NIL;
BLK844:
	w = NIL;
	local[9]= fqv[121];
	goto CON839;
CON840:
	local[9]= argv[0];
	local[10]= fqv[122];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (w==NIL) goto IF852;
	w = fqv[120];
	ctx->vsp=local+9;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK836;
	goto IF853;
IF852:
	local[9]= NIL;
IF853:
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,CLO854,env,argv,local);
	local[10]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(pointer)MAPCAR(ctx,2,local+9); /*mapcar*/
	local[8] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[4] = w;
WHL856:
	if (local[8]==NIL) goto WHX857;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[3] = w;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)F76vector_angle(ctx,3,local+9); /*vector-angle*/
	local[7] = w;
	local[9]= makeflt((double)fabs(fltval(local[7])));
	local[10]= makeflt(3.1415926535897931159980e+00);
	ctx->vsp=local+11;
	w=(pointer)F90eps_(ctx,2,local+9); /*eps=*/
	if (w==NIL) goto IF860;
	w = fqv[120];
	ctx->vsp=local+9;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK836;
	goto IF861;
IF860:
	local[9]= NIL;
IF861:
	local[9]= local[5];
	{ double x,y;
		y=fltval(local[7]); x=fltval(local[9]);
		local[9]=(makeflt(x + y));}
	local[5] = local[9];
	local[4] = local[3];
	goto WHL856;
WHX857:
	local[9]= NIL;
BLK858:
	local[9]= makeflt((double)fabs(fltval(local[5])));
	{ double left,right;
		right=fltval(makeflt(3.1415926535897931159980e+00)); left=fltval(local[9]);
	if (left <= right) goto IF862;}
	local[9]= fqv[121];
	goto IF863;
IF862:
	local[9]= fqv[52];
IF863:
	goto CON839;
CON851:
	local[9]= NIL;
CON839:
	w = local[9];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK836:
	ctx->vsp=local; return(local[0]);}

/*:intersect-point-vector*/
static pointer M864polygon_intersect_point_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt((double)fabs(fltval(local[0])));
	local[4]= loadglobal(fqv[35]);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF866;
	w = fqv[123];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK865;
	goto IF867;
IF866:
	local[3]= NIL;
IF867:
	local[3]= makeflt(0.0000000000000000000000e+00);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[4]);
		local[4]=(makeflt(x + y));}
	{ double x,y;
		y=fltval(makeflt(-(fltval(local[4])))); x=fltval(local[3]);
		local[3]=(makeflt(x + y));}
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[1] = w;
	local[3]= local[1];
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF868;}
	w = fqv[124];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK865;
	goto IF869;
IF868:
	local[3]= NIL;
IF869:
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,2,local+3); /*v+*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0]= w;
BLK865:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M870polygon_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeflt(0.0000000000000000000000e+00);
	local[4]= local[0];
	local[5]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+6;
	w=(pointer)F97eps_in_range(ctx,3,local+3); /*eps-in-range*/
	if (w==NIL) goto IF872;
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[0];
	local[6]= argv[2];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,3,local+5,&ftab[1],fqv[11]); /*midpoint*/
	local[1] = w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[125];
	if (memq(local[3],w)==NIL) goto IF872;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	goto IF873;
IF872:
	local[3]= NIL;
IF873:
	w = local[3];
	local[0]= w;
BLK871:
	ctx->vsp=local; return(local[0]);}

/*:intersect-edge*/
static pointer M874polygon_intersect_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[126];
	local[2]= argv[2]->c.obj.iv[1];
	local[3]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK875:
	ctx->vsp=local; return(local[0]);}

/*:intersect-face*/
static pointer M876polygon_intersect_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT879;}
	local[0]= argv[0];
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[26];
	local[2]= argv[2];
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
ENT879:
ENT878:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[4];
WHL881:
	if (local[2]==NIL) goto WHX882;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	if (local[0]==NIL) goto IF885;
	local[3]= local[0];
	local[4]= fqv[28];
	local[5]= local[1];
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF885;
	local[3]= argv[2];
	local[4]= fqv[127];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	if (w==NIL) goto IF885;
	w = T;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK877;
	goto IF886;
IF885:
	local[3]= NIL;
IF886:
	goto WHL881;
WHX882:
	local[3]= NIL;
BLK883:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK877:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO854(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F73direction_vector(ctx,2,local+0); /*direction-vector*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:visible*/
static pointer M887polygon_visible(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[105];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF889;
	local[0]= argv[0];
	goto IF890;
IF889:
	local[0]= NIL;
IF890:
	w = local[0];
	local[0]= w;
BLK888:
	ctx->vsp=local; return(local[0]);}

/*:transform-normal*/
static pointer M891polygon_transform_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[128];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	argv[0]->c.obj.iv[2] = local[1];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK892:
	ctx->vsp=local; return(local[0]);}

/*:reset-normal*/
static pointer M893polygon_reset_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F77face_normal_vector(ctx,1,local+0); /*face-normal-vector*/
	argv[0]->c.obj.iv[1] = w;
	local[0]= argv[0]->c.obj.iv[1];
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	argv[0]->c.obj.iv[2] = makeflt(-(fltval(w)));
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK894:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M895polygon_set_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	w=argv[0]->c.obj.iv[5];
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
	argv[0]->c.obj.iv[3] = T;
WHL897:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX898;
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
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)F74triangle(ctx,4,local+1); /*triangle*/
	local[1]= w;
	local[2]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF900;
	argv[0]->c.obj.iv[3] = NIL;
	local[0] = NIL;
	local[1]= local[0];
	goto IF901;
IF900:
	local[1]= NIL;
IF901:
	goto WHL897;
WHX898:
	local[1]= NIL;
BLK899:
	w = local[1];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK896:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M903polygon_invert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	argv[0]->c.obj.iv[5] = w;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	argv[0]->c.obj.iv[4] = w;
	local[0]= makeflt(-1.0000000000000000000000e+00);
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= makeflt(-1.0000000000000000000000e+00);
	local[1]= argv[0]->c.obj.iv[6];
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,3,local+0); /*scale*/
	local[0]= makeflt(-1.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[2]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	argv[0]->c.obj.iv[2] = local[0];
	local[0]= makeflt(-1.0000000000000000000000e+00);
	{ double x,y;
		y=fltval(argv[0]->c.obj.iv[7]); x=fltval(local[0]);
		local[0]=(makeflt(x * y));}
	argv[0]->c.obj.iv[7] = local[0];
	local[0]= argv[0];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK904:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M905polygon_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[130], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY907;
	local[0] = NIL;
KEY907:
	if (n & (1<<1)) goto KEY908;
	local[1] = NIL;
KEY908:
	if (n & (1<<2)) goto KEY909;
	local[2] = NIL;
KEY909:
	if (n & (1<<3)) goto KEY910;
	local[3] = NIL;
KEY910:
	if (local[1]==NIL) goto CON912;
	argv[0]->c.obj.iv[4] = local[1];
	if (local[0]!=NIL) goto CON914;
	local[4]= NIL;
	local[5]= local[1];
WHL916:
	if (local[5]==NIL) goto WHX917;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[56];
	local[8]= argv[0];
	local[9]= fqv[131];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	goto WHL916;
WHX917:
	local[6]= NIL;
BLK918:
	w = NIL;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[55];
	local[6]= argv[0];
	local[7]= fqv[131];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	w = local[0];
	ctx->vsp=local+5;
	argv[0]->c.obj.iv[5] = cons(ctx,local[4],w);
	local[4]= argv[0]->c.obj.iv[5];
	goto CON913;
CON914:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,1,local+4,&ftab[13],fqv[109]); /*last*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	argv[0]->c.obj.iv[5] = w;
	local[4]= argv[0]->c.obj.iv[5];
	goto CON913;
CON920:
	local[4]= NIL;
CON913:
	goto CON911;
CON912:
	if (local[0]==NIL) goto CON921;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,1,local+4,&ftab[13],fqv[109]); /*last*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	argv[0]->c.obj.iv[5] = w;
WHL922:
	if (local[0]==NIL) goto WHX923;
	local[4]= loadglobal(fqv[132]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[24];
	local[7]= fqv[55];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= fqv[56];
	if (local[0]==NIL) goto IF927;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF928;
IF927:
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
IF928:
	local[11]= fqv[133];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,8,local+5); /*send*/
	w = local[4];
	local[4]= w;
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	argv[0]->c.obj.iv[4] = cons(ctx,local[4],w);
	goto WHL922;
WHX923:
	local[4]= NIL;
BLK924:
	local[4]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	argv[0]->c.obj.iv[4] = w;
	local[4]= argv[0]->c.obj.iv[4];
	goto CON911;
CON921:
	local[4]= NIL;
CON911:
	if (local[2]==NIL) goto IF929;
	argv[0]->c.obj.iv[1] = local[2];
	local[4]= argv[0]->c.obj.iv[1];
	goto IF930;
IF929:
	local[4]= argv[0];
	local[5]= fqv[134];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
IF930:
	if (local[3]==NIL) goto IF931;
	argv[0]->c.obj.iv[2] = local[3];
	local[4]= argv[0]->c.obj.iv[2];
	goto IF932;
IF931:
	local[4]= NIL;
IF932:
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)COPYSEQ(ctx,1,local+4); /*copy-seq*/
	argv[0]->c.obj.iv[6] = w;
	argv[0]->c.obj.iv[7] = argv[0]->c.obj.iv[2];
	local[4]= argv[0];
	local[5]= fqv[129];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK906:
	ctx->vsp=local; return(local[0]);}

/*:on-vertex*/
static pointer M933polygon_on_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT936;}
	local[0]= loadglobal(fqv[23]);
ENT936:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT935:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
WHL938:
	if (local[6]==NIL) goto WHX939;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= argv[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)F98eps_v_(ctx,2,local+7); /*eps-v=*/
	if (w==NIL) goto IF942;
	local[7]= local[5];
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF943;
IF942:
	local[7]= NIL;
IF943:
	goto WHL938;
WHX939:
	local[7]= NIL;
BLK940:
	w = NIL;
	local[5]= local[4];
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK934:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M944polygon_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT947;}
	local[0]= loadglobal(fqv[23]);
ENT947:
ENT946:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[4];
WHL949:
	if (local[4]==NIL) goto WHX950;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[135];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto IF953;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF954;
IF953:
	local[5]= NIL;
IF954:
	goto WHL949;
WHX950:
	local[5]= NIL;
BLK951:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK945:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-distance*/
static pointer M955polygon_coplanar_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[111];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[136];
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,2,local+0,&ftab[16],fqv[137]); /*member*/
	if (w==NIL) goto IF957;
	local[0]= fqv[121];
	goto IF958;
IF957:
	local[0]= (pointer)get_sym_func(fqv[113]);
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,3,local+1,&ftab[15],fqv[114]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
IF958:
	w = local[0];
	local[0]= w;
BLK956:
	ctx->vsp=local; return(local[0]);}

/*:coplanar-intersections*/
static pointer M959polygon_coplanar_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT962;}
	local[0]= loadglobal(fqv[45]);
ENT962:
ENT961:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F102bounding_box_intersection(ctx,2,local+1); /*bounding-box-intersection*/
	local[1]= w;
	local[2]= NIL;
	if (local[1]!=NIL) goto IF963;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK960;
	goto IF964;
IF963:
	local[3]= NIL;
IF964:
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[4];
WHL966:
	if (local[4]==NIL) goto WHX967;
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
	local[7]= NIL;
	local[8]= argv[2];
	local[9]= fqv[61];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
WHL971:
	if (local[8]==NIL) goto WHX972;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[3];
	local[10]= fqv[126];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[6] = w;
	w = local[6];
	if (!iscons(w)) goto IF975;
	local[9]= local[7];
	w = local[6];
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto IF976;
IF975:
	local[9]= NIL;
IF976:
	goto WHL971;
WHX972:
	local[9]= NIL;
BLK973:
	w = NIL;
	if (local[5]==NIL) goto IF977;
	local[7]= local[3];
	w = local[5];
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto IF978;
IF977:
	local[7]= NIL;
IF978:
	w = local[7];
	goto WHL966;
WHX967:
	local[5]= NIL;
BLK968:
	w = NIL;
	if (local[2]==NIL) goto IF979;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK960;
	goto IF980;
IF979:
	local[3]= NIL;
IF980:
	local[3]= NIL;
	w=argv[0]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL982:
	if (local[4]==NIL) goto WHX983;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= fqv[138];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF986;
	local[5]= argv[2];
	local[6]= fqv[111];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	w = fqv[139];
	if (memq(local[5],w)==NIL) goto IF986;
	w = fqv[140];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK960;
	goto IF987;
IF986:
	local[5]= NIL;
IF987:
	goto WHL982;
WHX983:
	local[5]= NIL;
BLK984:
	w = NIL;
	local[3]= NIL;
	local[4]= argv[2];
	local[5]= fqv[141];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL989:
	if (local[4]==NIL) goto WHX990;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= fqv[138];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (w==NIL) goto IF993;
	local[5]= argv[0];
	local[6]= fqv[111];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	w = fqv[142];
	if (memq(local[5],w)==NIL) goto IF993;
	w = fqv[143];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK960;
	goto IF994;
IF993:
	local[5]= NIL;
IF994:
	goto WHL989;
WHX990:
	local[5]= NIL;
BLK991:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK960:
	ctx->vsp=local; return(local[0]);}

/*:contact-edge*/
static pointer M995polygon_contact_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT998;}
	local[0]= loadglobal(fqv[23]);
ENT998:
ENT997:
	if (n>4) maerror();
	local[1]= argv[2]->c.obj.iv[1];
	local[2]= argv[2]->c.obj.iv[2];
	local[3]= argv[0];
	local[4]= fqv[105];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[105];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR1001;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w!=NIL) goto OR1001;
	local[5]= argv[0];
	local[6]= fqv[144];
	local[7]= argv[2];
	local[8]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	if (w==NIL) goto OR1001;
	goto CON1000;
OR1001:
	local[5]= fqv[52];
	goto CON999;
CON1000:
	local[5]= argv[0];
	local[6]= fqv[111];
	local[7]= local[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[121];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w!=NIL) goto OR1003;
	local[5]= argv[0];
	local[6]= fqv[111];
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,1,local+5); /*eql*/
	if (w!=NIL) goto OR1003;
	goto CON1002;
OR1003:
	local[5]= T;
	goto CON999;
CON1002:
	local[5]= NIL;
CON999:
	w = local[5];
	local[0]= w;
BLK996:
	ctx->vsp=local; return(local[0]);}

/*:contact-plane*/
static pointer M1004polygon_contact_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1007;}
	local[0]= loadglobal(fqv[23]);
ENT1007:
ENT1006:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= fqv[65];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= makeflt(-1.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)F90eps_(ctx,2,local+1); /*eps=*/
	if (w==NIL) goto IF1008;
	local[1]= makeflt(-(fltval(argv[0]->c.obj.iv[2])));
	local[2]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)F90eps_(ctx,2,local+1); /*eps=*/
	if (w==NIL) goto IF1008;
	local[1]= argv[0];
	local[2]= fqv[145];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF1009;
IF1008:
	local[1]= NIL;
IF1009:
	w = local[1];
	local[0]= w;
BLK1005:
	ctx->vsp=local; return(local[0]);}

/*:contact-point*/
static pointer M1010polygon_contact_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1013;}
	local[0]= loadglobal(fqv[23]);
ENT1013:
ENT1012:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ABS(ctx,1,local+3); /*abs*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1014;
	local[2]= fqv[52];
	goto IF1015;
IF1014:
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= argv[2];
	local[5]= local[1];
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF1015:
	w = local[2];
	local[0]= w;
BLK1011:
	ctx->vsp=local; return(local[0]);}

/*:contactp*/
static pointer M1016polygon_contactp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1019;}
	local[0]= loadglobal(fqv[23]);
ENT1019:
ENT1018:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[42]); /*float-vector-p*/
	if (w==NIL) goto CON1021;
	local[1]= argv[0];
	local[2]= fqv[146];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1020;
CON1021:
	local[1]= argv[2];
	local[2]= loadglobal(fqv[43]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON1022;
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1020;
CON1022:
	local[1]= argv[2];
	local[2]= loadglobal(fqv[148]);
	ctx->vsp=local+3;
	w=(pointer)DERIVEDP(ctx,2,local+1); /*derivedp*/
	if (w==NIL) goto CON1023;
	local[1]= argv[0];
	local[2]= fqv[149];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON1020;
CON1023:
	local[1]= NIL;
CON1020:
	w = local[1];
	local[0]= w;
BLK1017:
	ctx->vsp=local; return(local[0]);}

/*:aligned-plane*/
static pointer M1024polygon_aligned_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= fqv[65];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)F90eps_(ctx,2,local+0); /*eps=*/
	if (w==NIL) goto IF1026;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)F90eps_(ctx,2,local+0); /*eps=*/
	if (w==NIL) goto IF1026;
	local[0]= argv[0];
	local[1]= fqv[145];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF1027;
IF1026:
	local[0]= NIL;
IF1027:
	w = local[0];
	local[0]= w;
BLK1025:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M1028face_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1031;}
	local[0]= makeflt(1.0000000000000000208167e-03);
ENT1031:
ENT1030:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[111];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[121]==local[2]) goto IF1032;
	local[2]= local[1];
	goto IF1033;
IF1032:
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
WHL1035:
	if (local[3]==NIL) goto WHX1036;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[111];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	if (fqv[121]!=local[4]) goto IF1039;
	w = fqv[52];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1029;
	goto IF1040;
IF1039:
	local[4]= local[1];
	if (fqv[120]!=local[4]) goto IF1041;
	w = fqv[120];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1029;
	goto IF1042;
IF1041:
	local[4]= NIL;
IF1042:
IF1040:
	goto WHL1035;
WHX1036:
	local[4]= NIL;
BLK1037:
	w = NIL;
	local[2]= fqv[121];
IF1033:
	w = local[2];
	local[0]= w;
BLK1029:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M1043face_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[105];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[110]); /*signum*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[38];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[1];
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	if (w==NIL) goto IF1045;
	local[2]= argv[0];
	local[3]= fqv[111];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	w = fqv[150];
	if (memq(local[2],w)==NIL) goto IF1047;
	local[2]= makeflt(0.0000000000000000000000e+00);
	goto IF1048;
IF1047:
	local[2]= (pointer)get_sym_func(fqv[113]);
	local[3]= argv[0];
	local[4]= fqv[92];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[74];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,3,local+3,&ftab[15],fqv[114]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
IF1048:
	goto IF1046;
IF1045:
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= fqv[111];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	w = fqv[151];
	if (memq(local[3],w)==NIL) goto IF1049;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)VDISTANCE(ctx,2,local+3); /*distance*/
	local[3]= w;
	goto IF1050;
IF1049:
	local[3]= (pointer)get_sym_func(fqv[113]);
	local[4]= argv[0];
	local[5]= fqv[92];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[74];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,3,local+4,&ftab[15],fqv[114]); /*send-all*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
IF1050:
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
IF1046:
	w = local[2];
	local[0]= w;
BLK1044:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M1051face_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= w;
	local[1]= (pointer)get_sym_func(fqv[116]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[119];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
BLK1052:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M1053face_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1056;}
	local[0]= NIL;
ENT1056:
ENT1055:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[152];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,4,local+1); /*send-message*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[152];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,3,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	local[3]= (pointer)get_sym_func(fqv[153]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= (pointer)get_sym_func(fqv[116]);
	local[6]= (pointer)get_sym_func(fqv[154]);
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[2];
WHL1058:
	if (local[6]==NIL) goto WHX1059;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[3];
	local[8]= (pointer)get_sym_func(fqv[153]);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,2,local+8); /*apply*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,3,local+7); /*v-*/
	goto WHL1058;
WHX1059:
	local[7]= NIL;
BLK1060:
	w = NIL;
	if (local[0]==NIL) goto IF1062;
	local[5]= local[4];
	local[6]= argv[0];
	local[7]= fqv[105];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)TIMES(ctx,2,local+5); /***/
	local[5]= w;
	local[6]= makeflt(-3.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= makeflt(2.5000000000000000000000e-01);
	local[7]= makeflt(1.0000000000000000000000e+00);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SCALEVEC(ctx,2,local+7); /*scale*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,3,local+6,&ftab[1],fqv[11]); /*midpoint*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	goto IF1063;
IF1062:
	local[5]= local[4];
	local[6]= makeflt(1.0000000000000000000000e+00);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,2,local+6); /*scale*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
IF1063:
	w = local[5];
	local[0]= w;
BLK1054:
	ctx->vsp=local; return(local[0]);}

/*:on-vertex*/
static pointer M1064face_on_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1067;}
	local[0]= loadglobal(fqv[23]);
ENT1067:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[8],w);
ENT1066:
	if (n>4) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= (pointer)get_sym_func(fqv[155]);
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[12]));
	local[8]= fqv[122];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[8]);
	ctx->vsp=local+11;
	w=(pointer)SENDMESSAGE(ctx,5,local+6); /*send-message*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= fqv[122];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[8]);
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,4,local+7,&ftab[15],fqv[114]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,3,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	unbindx(ctx,1);
	w = local[5];
	local[0]= w;
BLK1065:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M1068face_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1071;}
	local[0]= loadglobal(fqv[23]);
ENT1071:
ENT1070:
	if (n>4) maerror();
	local[1]= (pointer)get_sym_func(fqv[155]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[12]));
	local[4]= fqv[156];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,5,local+2); /*send-message*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= fqv[156];
	local[5]= argv[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,4,local+3,&ftab[15],fqv[114]); /*send-all*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK1069:
	ctx->vsp=local; return(local[0]);}

/*:invert*/
static pointer M1072face_invert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[157];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[157];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[114]); /*send-all*/
	local[0]= w;
BLK1073:
	ctx->vsp=local; return(local[0]);}

/*:holes*/
static pointer M1074face_holes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1075:
	ctx->vsp=local; return(local[0]);}

/*:enter-hole*/
static pointer M1076face_enter_hole(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[8] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1077:
	ctx->vsp=local; return(local[0]);}

/*:transform-normal*/
static pointer M1078face_transform_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[158];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[158];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,3,local+0,&ftab[15],fqv[114]); /*send-all*/
	local[0]= w;
BLK1079:
	ctx->vsp=local; return(local[0]);}

/*:reset-normal*/
static pointer M1080face_reset_normal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[12]));
	local[2]= fqv[134];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[134];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[114]); /*send-all*/
	local[0]= w;
BLK1081:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1082face_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK1083:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M1084face_all_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= (pointer)get_sym_func(fqv[159]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[61];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK1085:
	ctx->vsp=local; return(local[0]);}

/*:all-vertices*/
static pointer M1086face_all_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= (pointer)get_sym_func(fqv[159]);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[141];
	ctx->vsp=local+4;
	w=(*ftab[15])(ctx,2,local+2,&ftab[15],fqv[114]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK1087:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M1088face_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1091;}
	local[0]= NIL;
ENT1091:
ENT1090:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1092;
	argv[0]->c.obj.iv[9] = local[0];
	local[1]= argv[0]->c.obj.iv[9];
	goto IF1093;
IF1092:
	local[1]= argv[0]->c.obj.iv[9];
IF1093:
	w = local[1];
	local[0]= w;
BLK1089:
	ctx->vsp=local; return(local[0]);}

/*:primitive-face*/
static pointer M1094face_primitive_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1097;}
	local[0]= NIL;
ENT1097:
ENT1096:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1098;
	argv[0]->c.obj.iv[10] = local[0];
	local[1]= argv[0]->c.obj.iv[10];
	goto IF1099;
IF1098:
	local[1]= NIL;
IF1099:
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1095:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body*/
static pointer M1100face_primitive_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1101:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M1102face_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1105;}
	local[0]= NIL;
ENT1105:
ENT1104:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1106;
	argv[0]->c.obj.iv[11] = local[0];
	local[1]= argv[0]->c.obj.iv[11];
	goto IF1107;
IF1106:
	local[1]= argv[0]->c.obj.iv[11];
IF1107:
	w = local[1];
	local[0]= w;
BLK1103:
	ctx->vsp=local; return(local[0]);}

/*:face-id*/
static pointer M1108face_face_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[160];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK1109:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body-type*/
static pointer M1110face_primitive_body_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[161];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1111:
	ctx->vsp=local; return(local[0]);}

/*:body-type*/
static pointer M1112face_body_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[161];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1113:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M1114face_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= (pointer)get_sym_func(fqv[83]);
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[13];
	local[4]= argv[2];
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1116;
	local[5]= argv[0]->c.obj.iv[9];
	local[6]= fqv[161];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	goto IF1117;
IF1116:
	local[5]= fqv[162];
IF1117:
	local[6]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,7,local+0); /*apply*/
	local[0]= w;
BLK1115:
	ctx->vsp=local; return(local[0]);}

/*:copied-primitive-face-p*/
static pointer M1118face_copied_primitive_face_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[163];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
BLK1119:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body*/
static pointer M1120face_primitive_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[67];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK1121:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1122face_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[164], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1124;
	local[0] = NIL;
KEY1124:
	if (n & (1<<1)) goto KEY1125;
	local[1] = NIL;
KEY1125:
	if (n & (1<<2)) goto KEY1126;
	local[2] = NIL;
KEY1126:
	if (n & (1<<3)) goto KEY1127;
	local[3] = NIL;
KEY1127:
	if (n & (1<<4)) goto KEY1128;
	local[4] = NIL;
KEY1128:
	if (n & (1<<5)) goto KEY1129;
	local[5] = NIL;
KEY1129:
	if (n & (1<<6)) goto KEY1130;
	local[6] = NIL;
KEY1130:
	if (n & (1<<7)) goto KEY1131;
	local[7] = argv[0];
KEY1131:
	argv[0]->c.obj.iv[8] = local[4];
	local[8]= local[4];
	local[9]= fqv[131];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[15])(ctx,3,local+8,&ftab[15],fqv[114]); /*send-all*/
	if (local[5]==NIL) goto IF1132;
	argv[0]->c.obj.iv[11] = local[5];
	local[8]= argv[0]->c.obj.iv[11];
	goto IF1133;
IF1132:
	local[8]= NIL;
IF1133:
	argv[0]->c.obj.iv[10] = local[7];
	if (local[6]==NIL) goto IF1134;
	argv[0]->c.obj.iv[9] = local[6];
	local[8]= argv[0]->c.obj.iv[9];
	goto IF1135;
IF1134:
	local[8]= NIL;
IF1135:
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[12]));
	local[10]= fqv[24];
	local[11]= fqv[65];
	local[12]= local[0];
	local[13]= fqv[74];
	local[14]= local[1];
	local[15]= fqv[61];
	local[16]= local[2];
	local[17]= fqv[141];
	local[18]= local[3];
	ctx->vsp=local+19;
	w=(pointer)SENDMESSAGE(ctx,11,local+8); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1123:
	ctx->vsp=local; return(local[0]);}

/*:reflectance*/
static pointer M1136face_reflectance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1139;}
	local[0]= NIL;
ENT1139:
ENT1138:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1140;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[165];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1141;
IF1140:
	local[3]= argv[0];
	local[4]= fqv[165];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1142;
	local[3]= local[2];
	goto IF1143;
IF1142:
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= fqv[165];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF1143:
IF1141:
	w = local[3];
	local[0]= w;
BLK1137:
	ctx->vsp=local; return(local[0]);}

/*:diffusion*/
static pointer M1144face_diffusion(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1147;}
	local[0]= NIL;
ENT1147:
ENT1146:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1148;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[166];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1149;
IF1148:
	local[3]= argv[0];
	local[4]= fqv[166];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1150;
	local[3]= local[2];
	goto IF1151;
IF1150:
	local[3]= argv[0]->c.obj.iv[9];
	local[4]= fqv[166];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF1151:
IF1149:
	w = local[3];
	local[0]= w;
BLK1145:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M1152face_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1155;}
	local[0]= NIL;
ENT1155:
ENT1154:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1156;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[81];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF1157;
IF1156:
	local[1]= argv[0];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto IF1158;
	local[1]= local[0];
	goto IF1159;
IF1158:
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1160;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF1161;
IF1160:
	local[1]= NIL;
IF1161:
IF1159:
IF1157:
	w = local[1];
	local[0]= w;
BLK1153:
	ctx->vsp=local; return(local[0]);}

/*:contact-edge*/
static pointer M1162face_contact_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= *(ovafptr(argv[0],fqv[79]));
	local[2]= argv[2]->c.obj.iv[2];
	local[3]= argv[2]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= loadglobal(fqv[23]);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF1164;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1163;
	goto IF1165;
IF1164:
	local[1]= NIL;
IF1165:
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[92];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL1167:
	if (local[2]==NIL) goto WHX1168;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= fqv[167];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF1171;
	w = local[0];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK1163;
	goto IF1172;
IF1171:
	local[3]= NIL;
IF1172:
	goto WHL1167;
WHX1168:
	local[3]= NIL;
BLK1169:
	w = NIL;
	local[0]= w;
BLK1163:
	ctx->vsp=local; return(local[0]);}

/*:contact-point*/
static pointer M1173face_contact_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1176;}
	local[0]= loadglobal(fqv[23]);
ENT1176:
ENT1175:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[12]));
	local[3]= fqv[146];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	local[2]= local[1];
	if (fqv[121]==local[2]) goto IF1177;
	local[2]= local[1];
	goto IF1178;
IF1177:
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[8];
WHL1180:
	if (local[3]==NIL) goto WHX1181;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= fqv[146];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[1] = w;
	local[4]= local[1];
	if (fqv[121]!=local[4]) goto IF1184;
	w = fqv[52];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1174;
	goto IF1185;
IF1184:
	local[4]= local[1];
	if (fqv[120]!=local[4]) goto IF1186;
	w = fqv[120];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK1174;
	goto IF1187;
IF1186:
	local[4]= NIL;
IF1187:
IF1185:
	goto WHL1180;
WHX1181:
	local[4]= NIL;
BLK1182:
	w = NIL;
	local[2]= fqv[121];
IF1178:
	w = local[2];
	local[0]= w;
BLK1174:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1188hole_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1191;}
	local[0]= NIL;
ENT1191:
ENT1190:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F86facep(ctx,1,local+1); /*facep*/
	if (w==NIL) goto IF1192;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF1193;
IF1192:
	local[1]= NIL;
IF1193:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1189:
	ctx->vsp=local; return(local[0]);}

/*:hollowed-faces*/
static pointer M1194hole_hollowed_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[4];
WHL1197:
	if (local[2]==NIL) goto WHX1198;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1]->c.obj.iv[3];
	local[4]= local[1]->c.obj.iv[4];
	local[5]= local[3];
	if (argv[0]->c.obj.iv[8]==local[5]) goto IF1201;
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[168]); /*adjoin*/
	local[0] = w;
	local[5]= local[0];
	goto IF1202;
IF1201:
	local[5]= NIL;
IF1202:
	local[5]= local[4];
	if (argv[0]->c.obj.iv[8]==local[5]) goto IF1203;
	local[5]= local[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[17])(ctx,2,local+5,&ftab[17],fqv[168]); /*adjoin*/
	local[0] = w;
	local[5]= local[0];
	goto IF1204;
IF1203:
	local[5]= NIL;
IF1204:
	w = local[5];
	goto WHL1197;
WHX1198:
	local[3]= NIL;
BLK1199:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1195:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1205hole_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[169], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1207;
	local[0] = NIL;
KEY1207:
	if (n & (1<<1)) goto KEY1208;
	local[1] = NIL;
KEY1208:
	if (n & (1<<2)) goto KEY1209;
	local[2] = NIL;
KEY1209:
	if (n & (1<<3)) goto KEY1210;
	local[3] = NIL;
KEY1210:
	if (n & (1<<4)) goto KEY1211;
	local[4] = NIL;
KEY1211:
	argv[0]->c.obj.iv[8] = local[4];
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[12]));
	local[7]= fqv[24];
	local[8]= fqv[65];
	local[9]= local[0];
	local[10]= fqv[74];
	local[11]= local[1];
	local[12]= fqv[61];
	local[13]= local[2];
	local[14]= fqv[141];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SENDMESSAGE(ctx,11,local+5); /*send-message*/
	w = argv[0];
	local[0]= w;
BLK1206:
	ctx->vsp=local; return(local[0]);}

/*make-plane*/
static pointer F109make_plane(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[170], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY1213;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[0] = w;
KEY1213:
	if (n & (1<<1)) goto KEY1214;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[1] = w;
KEY1214:
	if (n & (1<<2)) goto KEY1215;
	local[2] = NIL;
KEY1215:
	w = local[1];
	if (!iscons(w)) goto IF1216;
	local[3]= local[1];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)F77face_normal_vector(ctx,2,local+3); /*face-normal-vector*/
	local[0] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= local[1];
	goto IF1217;
IF1216:
	local[3]= NIL;
IF1217:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)VNORMALIZE(ctx,1,local+3); /*normalize-vector*/
	local[0] = w;
	if (local[2]==NIL) goto IF1218;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[1] = w;
	local[3]= local[1];
	goto IF1219;
IF1218:
	local[3]= NIL;
IF1219:
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[24];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK1212:
	ctx->vsp=local; return(local[0]);}

/*make-polygon*/
static pointer F113make_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST1225:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[171]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[24];
	local[4]= fqv[141];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK1224:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___geopack(ctx,n,argv,env)
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
	local[0]= fqv[172];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF1227;
	local[0]= fqv[173];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[174],w);
	goto IF1228;
IF1227:
	local[0]= fqv[175];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF1228:
	local[0]= fqv[176];
	local[1]= fqv[177];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[178]); /*require*/
	local[0]= fqv[179];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[132];
	local[1]= fqv[180];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1229;
	local[0]= fqv[132];
	local[1]= fqv[180];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[132];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1231;
	local[0]= fqv[132];
	local[1]= fqv[181];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1232;
IF1231:
	local[0]= NIL;
IF1232:
	local[0]= fqv[132];
	goto IF1230;
IF1229:
	local[0]= NIL;
IF1230:
	local[0]= fqv[182];
	local[1]= fqv[180];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1233;
	local[0]= fqv[182];
	local[1]= fqv[180];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[182];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1235;
	local[0]= fqv[182];
	local[1]= fqv[181];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1236;
IF1235:
	local[0]= NIL;
IF1236:
	local[0]= fqv[182];
	goto IF1234;
IF1233:
	local[0]= NIL;
IF1234:
	local[0]= fqv[183];
	local[1]= fqv[180];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1237;
	local[0]= fqv[183];
	local[1]= fqv[180];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[183];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1239;
	local[0]= fqv[183];
	local[1]= fqv[181];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1240;
IF1239:
	local[0]= NIL;
IF1240:
	local[0]= fqv[183];
	goto IF1238;
IF1237:
	local[0]= NIL;
IF1238:
	local[0]= fqv[184];
	local[1]= fqv[180];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF1241;
	local[0]= fqv[184];
	local[1]= fqv[180];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[184];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF1243;
	local[0]= fqv[184];
	local[1]= fqv[181];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF1244;
IF1243:
	local[0]= NIL;
IF1244:
	local[0]= fqv[184];
	goto IF1242;
IF1241:
	local[0]= NIL;
IF1242:
	local[0]= fqv[35];
	local[1]= fqv[185];
	local[2]= makeflt(9.9999999999999950039964e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[45];
	local[1]= fqv[185];
	local[2]= makeflt(9.9999999999999950039964e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[8];
	local[1]= fqv[185];
	local[2]= makeflt(4.9999999999999975019982e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[23];
	local[1]= fqv[185];
	local[2]= makeflt(8.0000000000000001665335e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[77];
	local[1]= fqv[185];
	local[2]= makeflt(1.0000000000000000208167e-03);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[80];
	local[1]= fqv[185];
	local[2]= makeflt(9.9999999999999977795540e-02);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[186];
	ctx->vsp=local+1;
	w=(pointer)PROCLAIM(ctx,1,local+0); /*proclaim*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F71vplus,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F72vector_mean,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F73direction_vector,fqv[192]);
	local[0]= fqv[193];
	local[1]= fqv[181];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[194];
	local[1]= fqv[181];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F74triangle,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F75triangle_normal,fqv[198]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F76vector_angle,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F77face_normal_vector,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F78farthest,fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F79farthest_pair,fqv[206]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F80maxindex,fqv[208]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[209],module,F81random_vector,fqv[210]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[211],module,F82random_normalized_vector,fqv[212]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[213],module,F83random_vector2,fqv[214]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F84random_vectors,fqv[216]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[217],module,F85edgep,fqv[218]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[219],module,F86facep,fqv[220]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F87bodyp,fqv[222]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[223],module,F88primitive_body_p,fqv[224]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[225],module,F89n_2,fqv[226]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[227],module,F90eps_,fqv[228]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[229],module,F91eps_,fqv[230]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[231],module,F92eps_,fqv[232]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[233],module,F93eps__,fqv[234]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[235],module,F94eps__,fqv[236]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[237],module,F95eps__,fqv[238]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[239],module,F96eps_zero,fqv[240]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[241],module,F97eps_in_range,fqv[242]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[243],module,F98eps_v_,fqv[244]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[245],module,F99eps_coords_,fqv[246]);
	local[0]= loadglobal(fqv[15]);
	storeglobal(fqv[247],local[0]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M205bounding_box_box,fqv[25],fqv[15],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M211bounding_box_minpoint,fqv[249],fqv[15],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M213bounding_box_maxpoint,fqv[251],fqv[15],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M215bounding_box_center,fqv[253],fqv[15],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M217bounding_box_diagonal,fqv[255],fqv[15],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M219bounding_box_prin1,fqv[13],fqv[15],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M223bounding_box_inner,fqv[138],fqv[15],fqv[258]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M226bounding_box_intersection,fqv[26],fqv[15],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M235bounding_box_union,fqv[27],fqv[15],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M240bounding_box_intersection_p,fqv[28],fqv[15],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M242bounding_box_grow,fqv[10],fqv[15],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M248bounding_box_volume,fqv[263],fqv[15],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M250bounding_box_extream_point,fqv[18],fqv[15],fqv[265]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M258bounding_box_below,fqv[266],fqv[15],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M262bounding_box_corners,fqv[268],fqv[15],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M274bounding_box_body,fqv[67],fqv[15],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M276bounding_box_init2,fqv[16],fqv[15],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M282bounding_box_init,fqv[24],fqv[15],fqv[272]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[273],module,F100make_bounding_box,fqv[274]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[275],module,F101make_big_bounding_box,fqv[276]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[277],module,F102bounding_box_intersection,fqv[278]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[279],module,F103bounding_box_union,fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M313line_nvertex,fqv[56],fqv[43],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M317line_pvertex,fqv[55],fqv[43],fqv[282]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M321line_vertices,fqv[141],fqv[43],fqv[283]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M323line_eq,fqv[284],fqv[43],fqv[285]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M326line_eql,fqv[286],fqv[43],fqv[287]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M331line_equall,fqv[288],fqv[43],fqv[289]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M336line_parameter,fqv[48],fqv[43],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M338line_point,fqv[37],fqv[43],fqv[291]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M340line_box,fqv[25],fqv[43],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M345line_boxtest,fqv[144],fqv[43],fqv[293]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M349line_length,fqv[117],fqv[43],fqv[294]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M351line_end_point,fqv[295],fqv[43],fqv[296]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M357line_direction,fqv[62],fqv[43],fqv[297]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M359line_prin1,fqv[13],fqv[43],fqv[298]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M362line_init,fqv[24],fqv[43],fqv[299]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M376line_foot,fqv[38],fqv[43],fqv[300]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M378line_common_perpendicular,fqv[76],fqv[43],fqv[301]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M382line_distance_point,fqv[41],fqv[43],fqv[302]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M388line_distance_line,fqv[44],fqv[43],fqv[303]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M394line_distance,fqv[74],fqv[43],fqv[304]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M396line_distance,fqv[74],fqv[43],fqv[305]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M401line_colinear_point,fqv[47],fqv[43],fqv[306]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M405line_on_line_point,fqv[135],fqv[43],fqv[307]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M409line_colinear_line,fqv[308],fqv[43],fqv[309]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M414line_colinear_line_intersection,fqv[310],fqv[43],fqv[311]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M424line_coplanar,fqv[312],fqv[43],fqv[313]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M428line_project,fqv[50],fqv[43],fqv[314]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M430line_intersection,fqv[26],fqv[43],fqv[315]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M432line_intersect_line,fqv[126],fqv[43],fqv[316]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[317],module,F106make_line,fqv[318]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M460edge_faces,fqv[319],fqv[4],fqv[320]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M462edge_pvertex,fqv[55],fqv[4],fqv[321]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M468edge_nvertex,fqv[56],fqv[4],fqv[322]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M474edge_next_edge,fqv[59],fqv[4],fqv[323]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M476edge_next_vertex,fqv[324],fqv[4],fqv[325]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M478edge_direction,fqv[62],fqv[4],fqv[326]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M494edge_next_edge_angle,fqv[327],fqv[4],fqv[328]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M496edge_previous_edge_angle,fqv[329],fqv[4],fqv[330]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M498edge_body,fqv[67],fqv[4],fqv[331]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M503edge_pface,fqv[133],fqv[4],fqv[332]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M509edge_nface,fqv[333],fqv[4],fqv[334]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M515edge_another_face,fqv[335],fqv[4],fqv[336]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M521edge_binormal,fqv[337],fqv[4],fqv[338]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M527edge_angle,fqv[339],fqv[4],fqv[340]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M529edge_approximated_p,fqv[341],fqv[4],fqv[342]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M531edge_flags,fqv[343],fqv[4],fqv[344]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M533edge_contourp,fqv[345],fqv[4],fqv[346]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M540edge_set_approximated_flag,fqv[84],fqv[4],fqv[347]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M546edge_invert,fqv[157],fqv[4],fqv[348]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M548edge_set_angle,fqv[349],fqv[4],fqv[350]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M550edge_set_face,fqv[351],fqv[4],fqv[352]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M556edge_contact,fqv[167],fqv[4],fqv[353]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M562edge_neighborpoints,fqv[354],fqv[4],fqv[355]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M564edge_anothervertex,fqv[78],fqv[4],fqv[356]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M568edge_color,fqv[81],fqv[4],fqv[357]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M576edge_init,fqv[24],fqv[4],fqv[358]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M592edge_center_coordinates,fqv[359],fqv[4],fqv[360]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M597edge_pwing,fqv[100],fqv[4],fqv[361]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M607edge_pcwing,fqv[102],fqv[4],fqv[362]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M617edge_nwing,fqv[101],fqv[4],fqv[363]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M627edge_ncwing,fqv[103],fqv[4],fqv[364]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M637edge_connected_vertex,fqv[365],fqv[4],fqv[366]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M645edge_replace_face,fqv[367],fqv[4],fqv[368]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[369],module,F107winged_edge_p,fqv[370]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M652winged_edge_set_wings,fqv[371],fqv[99],fqv[372]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M654winged_edge_pwing,fqv[100],fqv[99],fqv[373]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M656winged_edge_nwing,fqv[101],fqv[99],fqv[374]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M658winged_edge_pcwing,fqv[102],fqv[99],fqv[375]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M660winged_edge_ncwing,fqv[103],fqv[99],fqv[376]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M662winged_edge_init,fqv[24],fqv[99],fqv[377]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M678plane_id,fqv[378],fqv[148],fqv[379]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M680plane_normal,fqv[65],fqv[148],fqv[380]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M682plane_distance,fqv[74],fqv[148],fqv[381]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M684plane_plane_distance,fqv[105],fqv[148],fqv[382]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M686plane_on_plane_p,fqv[383],fqv[148],fqv[384]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M690plane_coplanar_point,fqv[385],fqv[148],fqv[386]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M694plane_coplanar_line,fqv[387],fqv[148],fqv[388]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M699plane_intersection,fqv[26],fqv[148],fqv[389]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M701plane_intersect_edge,fqv[127],fqv[148],fqv[390]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M708plane_foot,fqv[38],fqv[148],fqv[391]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M710plane_original_body,fqv[392],fqv[148],fqv[393]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M712plane_brightness,fqv[394],fqv[148],fqv[395]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M714plane_project,fqv[50],fqv[148],fqv[396]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M718plane_separation,fqv[397],fqv[148],fqv[398]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M744plane_init,fqv[24],fqv[148],fqv[399]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M750polygon_face,fqv[131],fqv[171],fqv[400]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M752polygon_edges,fqv[61],fqv[171],fqv[401]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M754polygon_edge,fqv[402],fqv[171],fqv[403]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M756polygon_all_edges,fqv[92],fqv[171],fqv[404]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M758polygon_vertices,fqv[141],fqv[171],fqv[405]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M760polygon_vertex,fqv[406],fqv[171],fqv[407]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M762polygon_next_edge,fqv[59],fqv[171],fqv[408]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M766polygon_previous_edge,fqv[66],fqv[171],fqv[409]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M776polygon_adjacent_faces,fqv[410],fqv[171],fqv[411]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M785polygon_convexp,fqv[412],fqv[171],fqv[413]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M787polygon_box,fqv[25],fqv[171],fqv[414]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M792polygon_boxtest,fqv[144],fqv[171],fqv[415]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M797polygon_vertices_mean,fqv[416],fqv[171],fqv[417]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M799polygon_distance,fqv[74],fqv[171],fqv[418]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M807polygon_area,fqv[119],fqv[171],fqv[419]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M813polygon_perimeter,fqv[420],fqv[171],fqv[421]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M815polygon_volume,fqv[263],fqv[171],fqv[422]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M819polygon_centroid,fqv[152],fqv[171],fqv[423]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M829polygon_color,fqv[81],fqv[171],fqv[424]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M835polygon_insidep,fqv[111],fqv[171],fqv[425]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M864polygon_intersect_point_vector,fqv[426],fqv[171],fqv[427]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M870polygon_intersect_line,fqv[126],fqv[171],fqv[428]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M874polygon_intersect_edge,fqv[127],fqv[171],fqv[429]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M876polygon_intersect_face,fqv[430],fqv[171],fqv[431]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M887polygon_visible,fqv[432],fqv[171],fqv[433]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M891polygon_transform_normal,fqv[158],fqv[171],fqv[434]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M893polygon_reset_normal,fqv[134],fqv[171],fqv[435]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M895polygon_set_convexp,fqv[129],fqv[171],fqv[436]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M903polygon_invert,fqv[157],fqv[171],fqv[437]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M905polygon_init,fqv[24],fqv[171],fqv[438]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M933polygon_on_vertex,fqv[122],fqv[171],fqv[439]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M944polygon_on_edge,fqv[156],fqv[171],fqv[440]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M955polygon_coplanar_distance,fqv[441],fqv[171],fqv[442]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M959polygon_coplanar_intersections,fqv[145],fqv[171],fqv[443]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M995polygon_contact_edge,fqv[147],fqv[171],fqv[444]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1004polygon_contact_plane,fqv[149],fqv[171],fqv[445]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1010polygon_contact_point,fqv[146],fqv[171],fqv[446]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1016polygon_contactp,fqv[447],fqv[171],fqv[448]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1024polygon_aligned_plane,fqv[449],fqv[171],fqv[450]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1028face_insidep,fqv[111],fqv[5],fqv[451]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1043face_distance,fqv[74],fqv[5],fqv[452]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1051face_area,fqv[119],fqv[5],fqv[453]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1053face_centroid,fqv[152],fqv[5],fqv[454]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1064face_on_vertex,fqv[122],fqv[5],fqv[455]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1068face_on_edge,fqv[156],fqv[5],fqv[456]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1072face_invert,fqv[157],fqv[5],fqv[457]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1074face_holes,fqv[60],fqv[5],fqv[458]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1076face_enter_hole,fqv[459],fqv[5],fqv[460]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1078face_transform_normal,fqv[158],fqv[5],fqv[461]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1080face_reset_normal,fqv[134],fqv[5],fqv[462]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1082face_face,fqv[131],fqv[5],fqv[463]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1084face_all_edges,fqv[92],fqv[5],fqv[464]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1086face_all_vertices,fqv[465],fqv[5],fqv[466]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1088face_body,fqv[67],fqv[5],fqv[467]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1094face_primitive_face,fqv[468],fqv[5],fqv[469]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1100face_primitive_body,fqv[470],fqv[5],fqv[471]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1102face_id,fqv[378],fqv[5],fqv[472]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1108face_face_id,fqv[473],fqv[5],fqv[474]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1110face_primitive_body_type,fqv[475],fqv[5],fqv[476]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1112face_body_type,fqv[161],fqv[5],fqv[477]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1114face_prin1,fqv[13],fqv[5],fqv[478]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1118face_copied_primitive_face_p,fqv[479],fqv[5],fqv[480]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1120face_primitive_body,fqv[470],fqv[5],fqv[481]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1122face_init,fqv[24],fqv[5],fqv[482]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1136face_reflectance,fqv[165],fqv[5],fqv[483]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1144face_diffusion,fqv[166],fqv[5],fqv[484]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1152face_color,fqv[81],fqv[5],fqv[485]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1162face_contact_edge,fqv[147],fqv[5],fqv[486]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1173face_contact_point,fqv[146],fqv[5],fqv[487]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1188hole_face,fqv[131],fqv[488],fqv[489]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1194hole_hollowed_faces,fqv[490],fqv[488],fqv[491]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1205hole_init,fqv[24],fqv[488],fqv[492]);
	local[0]= fqv[132];
	local[1]= fqv[181];
	local[2]= loadglobal(fqv[4]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[182];
	local[1]= fqv[181];
	local[2]= loadglobal(fqv[5]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[493];
	local[1]= fqv[181];
	local[2]= loadglobal(fqv[488]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[183];
	local[1]= fqv[181];
	local[2]= loadglobal(fqv[6]);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[494],module,F109make_plane,fqv[495]);
	local[0]= fqv[496];
	local[1]= fqv[497];
	ctx->vsp=local+2;
	w=(pointer)F109make_plane(ctx,0,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[498];
	local[1]= fqv[497];
	local[2]= fqv[65];
	local[3]= fqv[499];
	ctx->vsp=local+4;
	w=(pointer)F109make_plane(ctx,2,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[500];
	local[1]= fqv[497];
	local[2]= fqv[65];
	local[3]= fqv[501];
	ctx->vsp=local+4;
	w=(pointer)F109make_plane(ctx,2,local+2); /*make-plane*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[502],module,F113make_polygon,fqv[503]);
	local[0]= fqv[504];
	local[1]= fqv[505];
	ctx->vsp=local+2;
	w=(*ftab[19])(ctx,2,local+0,&ftab[19],fqv[506]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<20; i++) ftab[i]=fcallx;
}
