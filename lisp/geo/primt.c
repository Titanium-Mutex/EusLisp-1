/* ./primt.c :  entry=primt */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "primt.h"
#pragma init (register_primt)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___primt();
extern pointer build_quote_vector();
static int register_primt()
  { add_module_initializer("___primt", ___primt);}

static pointer F2027find_extream();
static pointer F2028leftmost_point();
static pointer F2029rightmost_point();
static pointer F2030left_points();
static pointer F2031right_points();
static pointer F2032quickhull_left();
static pointer F2033quickhull_right();
static pointer F2034quickhull();
static pointer F2035find_coplanar_vertices();
static pointer F2036colinear_p();
static pointer F2037find_colinear_points();
static pointer F2038remove_colinears_from_circuit();
static pointer F2039coplanar_p();
static pointer F2040gift_wrapping();
static pointer F2041make_face_from_vertices();
static pointer F2042make_face_from_coplanar_vertices();
static pointer F2043tangent_foot();
static pointer F2044calc_p2_of_lowest_hull();
static pointer F2045calc_p3_of_lowest_hull();
static pointer F2046find_initial_hull();
static pointer F2047enclosed_vertexp();
static pointer F2048convex_hull_3d();
static pointer F2049rotate_vertices();
static pointer F2050make_side_faces();
static pointer F2051make_prism();
static pointer F2052make_conic_side_faces();
static pointer F2053make_cone();
static pointer F2054make_solid_of_revolution();
static pointer F2055make_torus();
static pointer F2056make_cylinder();
static pointer F2057make_cube();
static pointer F2058icosahedron_points();
static pointer F2059make_icosahedron();
static pointer F2060subdivide_facet();
static pointer F2061make_dodecahedron();
static pointer F2062make_gdome();
static pointer F2063make_body_from_vertices();
static pointer F2064assoc_coordinates_axes();

/*find-extream*/
static pointer F2027find_extream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	local[1]= w;
	local[2]= NIL;
	local[3]= argv[0];
WHL2068:
	if (local[3]==NIL) goto WHX2069;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[2];
	local[5]= argv[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,2,local+5); /*funcall*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,3,local+4); /*funcall*/
	if (w==NIL) goto IF2072;
	local[0] = local[2];
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,2,local+4); /*funcall*/
	local[1] = w;
	local[4]= local[1];
	goto IF2073;
IF2072:
	local[4]= NIL;
IF2073:
	goto WHL2068;
WHX2069:
	local[4]= NIL;
BLK2070:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2065:
	ctx->vsp=local; return(local[0]);}

/*leftmost-point*/
static pointer F2028leftmost_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2075,env,argv,local);
	local[2]= (pointer)get_sym_func(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)F2027find_extream(ctx,3,local+0); /*find-extream*/
	local[0]= w;
BLK2074:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2075(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*rightmost-point*/
static pointer F2029rightmost_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2077,env,argv,local);
	local[2]= (pointer)get_sym_func(fqv[2]);
	ctx->vsp=local+3;
	w=(pointer)F2027find_extream(ctx,3,local+0); /*find-extream*/
	local[0]= w;
BLK2076:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2077(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*left-points*/
static pointer F2030left_points(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2079,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK2078:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2079(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[1];
	local[1]= argv[0];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2080;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2081;
IF2080:
	local[0]= NIL;
IF2081:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*right-points*/
static pointer F2031right_points(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2083,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK2082:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2083(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[1];
	local[1]= argv[0];
	local[2]= env->c.clo.env1[2];
	local[3]= env->c.clo.env1[3];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[1]); /*triangle*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF2084;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2085;
IF2084:
	local[0]= NIL;
IF2085:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*quickhull-left*/
static pointer F2032quickhull_left(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[0]!=NIL) goto CON2088;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2086;
	goto CON2087;
CON2088:
	local[0]= NIL;
CON2087:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F2028leftmost_point(ctx,4,local+0); /*leftmost-point*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F2030left_points(ctx,4,local+1); /*left-points*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)F2030left_points(ctx,4,local+2); /*left-points*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[1];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)F2032quickhull_left(ctx,4,local+4); /*quickhull-left*/
	local[4]= w;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[0];
	local[8]= argv[2];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)F2032quickhull_left(ctx,4,local+6); /*quickhull-left*/
	local[6]= w;
	local[7]= fqv[3];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,4,local+5,&ftab[1],fqv[4]); /*delete*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[3] = w;
	w = local[3];
	local[0]= w;
BLK2086:
	ctx->vsp=local; return(local[0]);}

/*quickhull-right*/
static pointer F2033quickhull_right(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[0]!=NIL) goto CON2091;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2089;
	goto CON2090;
CON2091:
	local[0]= NIL;
CON2090:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F2029rightmost_point(ctx,4,local+0); /*rightmost-point*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= local[0];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F2031right_points(ctx,4,local+1); /*right-points*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)F2031right_points(ctx,4,local+2); /*right-points*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[0];
	local[7]= argv[2];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)F2033quickhull_right(ctx,4,local+5); /*quickhull-right*/
	local[5]= w;
	local[6]= fqv[3];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(*ftab[1])(ctx,4,local+4,&ftab[1],fqv[4]); /*delete*/
	local[4]= w;
	local[5]= local[1];
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)F2033quickhull_right(ctx,4,local+5); /*quickhull-right*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)NCONC(ctx,2,local+4); /*nconc*/
	local[3] = w;
	w = local[3];
	local[0]= w;
BLK2089:
	ctx->vsp=local; return(local[0]);}

/*quickhull*/
static pointer F2034quickhull(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2094;}
	local[0]= fqv[5];
ENT2094:
ENT2093:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)0L));
	  w=makeflt(local[6]->c.fvec.fv[i]);}
	local[6]= makeflt((double)fabs(fltval(w)));
	local[7]= local[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)1L));
	  w=makeflt(local[7]->c.fvec.fv[i]);}
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[6]);
	if (left <= right) goto IF2095;}
	local[5] = makeint((eusinteger_t)1L);
	local[6]= local[5];
	goto IF2096;
IF2095:
	local[6]= NIL;
IF2096:
	local[6]= argv[0];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO2097,env,argv,local);
	local[8]= (pointer)get_sym_func(fqv[6]);
	ctx->vsp=local+9;
	w=(pointer)F2027find_extream(ctx,3,local+6); /*find-extream*/
	local[1] = w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,CLO2098,env,argv,local);
	local[8]= (pointer)get_sym_func(fqv[7]);
	ctx->vsp=local+9;
	w=(pointer)F2027find_extream(ctx,3,local+6); /*find-extream*/
	local[2] = w;
	local[6]= argv[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2030left_points(ctx,4,local+6); /*left-points*/
	local[6]= w;
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2032quickhull_left(ctx,4,local+6); /*quickhull-left*/
	local[3] = w;
	local[6]= argv[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2031right_points(ctx,4,local+6); /*right-points*/
	local[6]= w;
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F2033quickhull_right(ctx,4,local+6); /*quickhull-right*/
	local[4] = w;
	local[6]= local[1];
	local[7]= local[4];
	local[8]= fqv[3];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,4,local+6,&ftab[1],fqv[4]); /*delete*/
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	local[8]= fqv[3];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,4,local+6,&ftab[1],fqv[4]); /*delete*/
	local[4] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[0]= w;
BLK2092:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2097(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[5];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2098(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[5];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-coplanar-vertices*/
static pointer F2035find_coplanar_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,3,local+0,&ftab[2],fqv[8]); /*triangle-normal*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt(-(fltval(w)));
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2100,env,argv,local);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)MAPCAN(ctx,2,local+2); /*mapcan*/
	local[0]= w;
BLK2099:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2100(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= env->c.clo.env2[0];
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2101;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2102;
IF2101:
	local[0]= NIL;
IF2102:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*colinear-p*/
static pointer F2036colinear_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2105;}
	local[0]= loadglobal(fqv[9]);
ENT2105:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[10],w);
ENT2104:
	if (n>4) maerror();
	local[3]= argv[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+5); /*v**/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VNORM(ctx,1,local+5); /*norm*/
	local[5]= w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VNORM(ctx,1,local+6); /*norm*/
	local[6]= w;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAX(ctx,2,local+6); /*max*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[5];
	local[7]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,2,local+6,&ftab[3],fqv[11]); /*eps=*/
	if (w==NIL) goto IF2106;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VINNERPRODUCT(ctx,2,local+6); /*v.*/
	local[6]= w;
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)VINNERPRODUCT(ctx,2,local+7); /*v.*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)QUOTIENT(ctx,2,local+6); /*/*/
	local[6]= w;
	goto IF2107;
IF2106:
	local[6]= NIL;
IF2107:
	w = local[6];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2103:
	ctx->vsp=local; return(local[0]);}

/*find-colinear-points*/
static pointer F2037find_colinear_points(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
WHL2109:
	if (argv[0]==NIL) goto WHX2110;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[6];
	local[0] = w;
	local[3] = argv[0];
WHL2113:
	if (local[3]==NIL) goto WHX2114;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[6];
	local[1] = w;
	local[6]= NIL;
	local[7]= local[3];
WHL2118:
	if (local[7]==NIL) goto WHX2119;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)F2036colinear_p(ctx,3,local+8); /*colinear-p*/
	local[4] = w;
	if (local[4]==NIL) goto IF2122;
	local[8]= local[4];
	local[9]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON2125;
	local[8]= local[0];
	goto CON2124;
CON2125:
	local[8]= local[4];
	local[9]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON2126;
	local[8]= local[1];
	goto CON2124;
CON2126:
	local[8]= local[6];
	goto CON2124;
CON2127:
	local[8]= NIL;
CON2124:
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2123;
IF2122:
	local[8]= NIL;
IF2123:
	goto WHL2118;
WHX2119:
	local[8]= NIL;
BLK2120:
	w = NIL;
	goto WHL2113;
WHX2114:
	local[6]= NIL;
BLK2115:
	goto WHL2109;
WHX2110:
	local[6]= NIL;
BLK2111:
	w = local[5];
	local[0]= w;
BLK2108:
	ctx->vsp=local; return(local[0]);}

/*remove-colinears-from-circuit*/
static pointer F2038remove_colinears_from_circuit(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	w = makeint((eusinteger_t)3L);
	if ((eusinteger_t)local[0] > (eusinteger_t)w) goto CON2130;
	local[0]= argv[0];
	goto CON2129;
CON2130:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F2036colinear_p(ctx,3,local+0); /*colinear-p*/
	if (w==NIL) goto CON2131;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F2038remove_colinears_from_circuit(ctx,1,local+1); /*remove-colinears-from-circuit*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON2129;
CON2131:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F2038remove_colinears_from_circuit(ctx,1,local+1); /*remove-colinears-from-circuit*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON2129;
CON2132:
	local[0]= NIL;
CON2129:
	w = local[0];
	local[0]= w;
BLK2128:
	ctx->vsp=local; return(local[0]);}

/*coplanar-p*/
static pointer F2039coplanar_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT2135;}
	local[0]= loadglobal(fqv[9]);
ENT2135:
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[10],w);
ENT2134:
	if (n>5) maerror();
	local[3]= argv[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)VMINUS(ctx,2,local+4); /*v-*/
	local[4]= w;
	local[5]= argv[3];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)VMINUS(ctx,2,local+5); /*v-*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+6); /*v**/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)VNORMALIZE(ctx,1,local+6); /*normalize-vector*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)VINNERPRODUCT(ctx,2,local+7); /*v.*/
	local[7]= w;
	local[8]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(*ftab[3])(ctx,2,local+7,&ftab[3],fqv[11]); /*eps=*/
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK2133:
	ctx->vsp=local; return(local[0]);}

/*gift-wrapping*/
static pointer F2040gift_wrapping(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= loadglobal(fqv[13]);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[4];
WHL2138:
	if (local[8]==NIL) goto WHX2139;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w = local[1];
	if (memq(local[9],w)!=NIL) goto IF2142;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= argv[1];
	local[11]= local[4];
	ctx->vsp=local+12;
	w=(pointer)VMINUS(ctx,3,local+9); /*v-*/
	local[9]= local[4];
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[5] = w;
	local[9]= local[4];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(pointer)VINNERPRODUCT(ctx,2,local+9); /*v.*/
	local[6] = w;
	local[9]= local[5];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[0] = w;
	local[9]= local[0];
	if (loadglobal(fqv[14])!=local[9]) goto IF2144;
	local[9]= T;
	local[10]= fqv[15];
	local[11]= local[0];
	local[12]= local[4];
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[5];
	local[15]= local[6];
	ctx->vsp=local+16;
	w=(pointer)XFORMAT(ctx,7,local+9); /*format*/
	w = fqv[16];
	ctx->vsp=local+9;
	local[0]=w;
	goto BLK2136;
	goto IF2145;
IF2144:
	local[9]= NIL;
IF2145:
	local[9]= local[0];
	local[10]= loadglobal(fqv[13]);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w!=NIL) goto IF2146;
	local[9]= local[0];
	{ double left,right;
		right=fltval(local[3]); left=fltval(local[9]);
	if (left < right) goto IF2146;}
	local[2] = local[7];
	local[3] = local[0];
	local[9]= local[3];
	goto IF2147;
IF2146:
	local[9]= NIL;
IF2147:
	goto IF2143;
IF2142:
	local[9]= NIL;
IF2143:
	goto WHL2138;
WHX2139:
	local[9]= NIL;
BLK2140:
	w = NIL;
	local[7]= local[3];
	storeglobal(fqv[17],local[7]);
	w = local[2];
	local[0]= w;
BLK2136:
	ctx->vsp=local; return(local[0]);}

/*make-face-from-vertices*/
static pointer F2041make_face_from_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[18]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[19]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= NIL;
	local[7]= argv[0];
WHL2150:
	if (local[7]==NIL) goto WHX2151;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	local[8]= local[3];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(*ftab[5])(ctx,2,local+8,&ftab[5],fqv[20]); /*intersection*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	if (local[2]!=NIL) goto CON2155;
	local[8]= loadglobal(fqv[21]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[2] = w;
	local[8]= local[2];
	local[9]= fqv[22];
	local[10]= fqv[23];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[24];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[25];
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,8,local+8); /*send*/
	local[8]= local[5];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= local[6];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= w;
	goto CON2154;
CON2155:
	if (local[2]==NIL) goto CON2156;
	local[8]= local[2];
	local[9]= fqv[26];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,5,local+8); /*send*/
	local[8]= w;
	goto CON2154;
CON2156:
	local[8]= NIL;
CON2154:
	local[8]= local[2];
	w = local[1];
	ctx->vsp=local+9;
	local[1] = cons(ctx,local[8],w);
	local[5] = local[6];
	goto WHL2150;
WHX2151:
	local[8]= NIL;
BLK2152:
	w = NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= local[0];
	local[7]= fqv[22];
	local[8]= fqv[27];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	w = local[0];
	local[0]= w;
BLK2148:
	ctx->vsp=local; return(local[0]);}

/*make-face-from-coplanar-vertices*/
static pointer F2042make_face_from_coplanar_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,3,local+0,&ftab[2],fqv[8]); /*triangle-normal*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)F2035find_coplanar_vertices(ctx,4,local+1); /*find-coplanar-vertices*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	w = makeint((eusinteger_t)3L);
	if ((eusinteger_t)local[6] <= (eusinteger_t)w) goto CON2159;
	local[6]= (pointer)get_sym_func(fqv[28]);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[2] = w;
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F2034quickhull(ctx,2,local+6); /*quickhull*/
	local[3] = w;
	local[6]= local[3];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	local[3] = w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)F2038remove_colinears_from_circuit(ctx,1,local+6); /*remove-colinears-from-circuit*/
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[6]= NIL;
	local[7]= local[1];
WHL2161:
	if (local[7]==NIL) goto WHX2162;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w = local[3];
	if (memq(local[8],w)!=NIL) goto IF2165;
	local[8]= local[6];
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2166;
IF2165:
	local[8]= NIL;
IF2166:
	goto WHL2161;
WHX2162:
	local[8]= NIL;
BLK2163:
	w = NIL;
	if (local[5]==NIL) goto IF2167;
	local[6]= NIL;
	local[7]= local[5];
WHL2170:
	if (local[7]==NIL) goto WHX2171;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= T;
	local[9]= fqv[29];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w = loadglobal(fqv[30]);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	storeglobal(fqv[30],local[8]);
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF2174;
	local[8]= local[6];
	local[9]= loadglobal(fqv[31]);
	local[10]= fqv[3];
	local[11]= makeint((eusinteger_t)1L);
	ctx->vsp=local+12;
	w=(*ftab[1])(ctx,4,local+8,&ftab[1],fqv[4]); /*delete*/
	local[8]= w;
	storeglobal(fqv[31],w);
	goto IF2175;
IF2174:
	local[8]= NIL;
IF2175:
	goto WHL2170;
WHX2171:
	local[8]= NIL;
BLK2172:
	w = NIL;
	local[6]= w;
	goto IF2168;
IF2167:
	local[6]= NIL;
IF2168:
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO2176,env,argv,local);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MAPCAN(ctx,2,local+6); /*mapcan*/
	local[4] = w;
	local[6]= local[4];
	goto CON2158;
CON2159:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[4] = w;
	local[6]= local[4];
	goto CON2158;
CON2177:
	local[6]= NIL;
CON2158:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+6); /*make-face-from-vertices*/
	local[0]= w;
BLK2157:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2176(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*tangent-foot*/
static pointer F2043tangent_foot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)VMINUS(ctx,2,local+0); /*v-*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VNORM2(ctx,1,local+2); /*norm2*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	local[4]= argv[1];
	local[5]= local[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SCALEVEC(ctx,2,local+5); /*scale*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,2,local+4); /*v+*/
	local[0]= w;
BLK2178:
	ctx->vsp=local; return(local[0]);}

/*calc-p2-of-lowest-hull*/
static pointer F2044calc_p2_of_lowest_hull(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeflt(1.5707963267948965579990e+00);
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[1];
WHL2181:
	if (local[6]==NIL) goto WHX2182;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[4] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)EQUAL(ctx,2,local+7); /*equal*/
	if (w!=NIL) goto IF2185;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	{ double left,right;
		right=fltval(makeflt(9.9999999999999977795540e-02)); left=fltval(local[7]);
	if (left <= right) goto IF2185;}
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= local[4];
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto AND2187;
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= local[4];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto AND2187;
	goto IF2185;
AND2187:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)COPYOBJ(ctx,1,local+7); /*copy-object*/
	local[3] = w;
	local[7]= local[3];
	local[8]= makeint((eusinteger_t)2L);
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)SETELT(ctx,3,local+7); /*setelt*/
	local[7]= makeflt(0.0000000000000000000000e+00);
	local[8]= local[4];
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NUMEQUAL(ctx,2,local+7); /*=*/
	if (w==NIL) goto IF2188;
	local[2] = makeflt(0.0000000000000000000000e+00);
	local[7]= local[2];
	goto IF2189;
IF2188:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)VNORMALIZE(ctx,1,local+7); /*normalize-vector*/
	local[7]= w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)VNORMALIZE(ctx,1,local+8); /*normalize-vector*/
	local[8]= w;
	local[9]= local[4];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+9); /*v**/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)VNORMALIZE(ctx,1,local+9); /*normalize-vector*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[6])(ctx,3,local+7,&ftab[6],fqv[32]); /*vector-angle*/
	local[2] = w;
	local[7]= local[2];
IF2189:
	local[7]= local[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF2190;
	local[0] = local[5];
	local[1] = local[2];
	local[7]= local[1];
	goto IF2191;
IF2190:
	local[7]= NIL;
IF2191:
	goto IF2186;
IF2185:
	local[7]= NIL;
IF2186:
	goto WHL2181;
WHX2182:
	local[7]= NIL;
BLK2183:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2179:
	ctx->vsp=local; return(local[0]);}

/*calc-p3-of-lowest-hull*/
static pointer F2045calc_p3_of_lowest_hull(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeflt(3.1415926535897931159980e+00);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL2194:
	if (local[7]==NIL) goto WHX2195;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)EQUAL(ctx,2,local+8); /*equal*/
	if (w!=NIL) goto IF2198;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)EQUAL(ctx,2,local+8); /*equal*/
	if (w!=NIL) goto IF2198;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)F2043tangent_foot(ctx,3,local+8); /*tangent-foot*/
	local[0] = w;
	local[8]= local[0];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,2,local+8); /*v-*/
	local[4] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)VNORM(ctx,1,local+8); /*norm*/
	local[8]= w;
	{ double left,right;
		right=fltval(makeflt(1.9999999999999995559108e-01)); left=fltval(local[8]);
	if (left <= right) goto IF2200;}
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,3,local+8,&ftab[2],fqv[8]); /*triangle-normal*/
	local[5] = w;
	local[8]= local[5];
	local[9]= makeint((eusinteger_t)2L);
	ctx->vsp=local+10;
	w=(pointer)ELT(ctx,2,local+8); /*elt*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF2202;
	local[8]= makeint((eusinteger_t)-1L);
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,2,local+8); /*scale*/
	local[5] = w;
	local[8]= local[5];
	goto IF2203;
IF2202:
	local[8]= NIL;
IF2203:
	local[8]= fqv[33];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)VMINUS(ctx,2,local+8); /*v-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)VNORM(ctx,1,local+8); /*norm*/
	local[8]= w;
	local[9]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,2,local+8,&ftab[3],fqv[11]); /*eps=*/
	if (w==NIL) goto IF2204;
	local[3] = makeflt(0.0000000000000000000000e+00);
	local[8]= local[3];
	goto IF2205;
IF2204:
	local[8]= fqv[34];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)VNORMALIZE(ctx,1,local+9); /*normalize-vector*/
	local[9]= w;
	local[10]= fqv[35];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+10); /*v**/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VNORMALIZE(ctx,1,local+10); /*normalize-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[6])(ctx,3,local+8,&ftab[6],fqv[32]); /*vector-angle*/
	local[3] = w;
	local[8]= local[3];
IF2205:
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF2206;
	local[1] = local[6];
	local[2] = local[3];
	local[8]= local[2];
	goto IF2207;
IF2206:
	local[8]= NIL;
IF2207:
	goto IF2201;
IF2200:
	local[8]= NIL;
IF2201:
	goto IF2199;
IF2198:
	local[8]= NIL;
IF2199:
	goto WHL2194;
WHX2195:
	local[8]= NIL;
BLK2196:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK2192:
	ctx->vsp=local; return(local[0]);}

/*find-initial-hull*/
static pointer F2046find_initial_hull(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2209,env,argv,local);
	local[2]= (pointer)get_sym_func(fqv[6]);
	ctx->vsp=local+3;
	w=(pointer)F2027find_extream(ctx,3,local+0); /*find-extream*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F2044calc_p2_of_lowest_hull(ctx,2,local+4); /*calc-p2-of-lowest-hull*/
	local[1] = w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F2045calc_p3_of_lowest_hull(ctx,3,local+4); /*calc-p3-of-lowest-hull*/
	local[2] = w;
	if (local[2]!=NIL) goto IF2210;
	w = NIL;
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK2208;
	goto IF2211;
IF2210:
	local[4]= NIL;
IF2211:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,3,local+4,&ftab[0],fqv[1]); /*triangle*/
	local[4]= w;
	local[5]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF2212;
	local[3] = local[1];
	local[1] = local[2];
	local[2] = local[3];
	local[4]= local[2];
	goto IF2213;
IF2212:
	local[4]= NIL;
IF2213:
WHL2214:
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[1];
	local[6]= local[0];
	local[7]= local[2];
	local[8]= local[1];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,5,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F2038remove_colinears_from_circuit(ctx,1,local+4); /*remove-colinears-from-circuit*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	w = makeint((eusinteger_t)5L);
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX2215;
	local[4]= local[2];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[7])(ctx,2,local+4,&ftab[7],fqv[36]); /*remove*/
	argv[0] = w;
	local[4]= local[0];
	local[5]= local[1];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F2045calc_p3_of_lowest_hull(ctx,3,local+4); /*calc-p3-of-lowest-hull*/
	local[2] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,3,local+4,&ftab[0],fqv[1]); /*triangle*/
	local[4]= w;
	local[5]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF2217;
	local[3] = local[1];
	local[1] = local[2];
	local[2] = local[3];
	local[4]= local[2];
	goto IF2218;
IF2217:
	local[4]= NIL;
IF2218:
	goto WHL2214;
WHX2215:
	local[4]= NIL;
BLK2216:
	local[4]= local[0];
	local[5]= local[2];
	local[6]= local[1];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)F2042make_face_from_coplanar_vertices(ctx,4,local+4); /*make-face-from-coplanar-vertices*/
	local[0]= w;
BLK2208:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2209(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*enclosed-vertexp*/
static pointer F2047enclosed_vertexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
WHL2221:
	if (local[2]==NIL) goto WHX2222;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= *(ovafptr(local[1],fqv[37]));
	if (local[3]==NIL) goto AND2225;
	local[3]= *(ovafptr(local[1],fqv[38]));
	if (local[3]==NIL) goto AND2225;
	local[3]= local[0];
AND2225:
	local[0] = local[3];
	goto WHL2221;
WHX2222:
	local[3]= NIL;
BLK2223:
	w = NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	if (local[1]==NIL) goto AND2226;
	local[1]= local[0];
AND2226:
	w = local[1];
	local[0]= w;
BLK2219:
	ctx->vsp=local; return(local[0]);}

/*convex-hull-3d*/
static pointer F2048convex_hull_3d(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
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
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	storeglobal(fqv[39],argv[0]);
	local[17]= (pointer)get_sym_func(fqv[40]);
	local[18]= argv[0];
	ctx->vsp=local+19;
	w=(pointer)MAPCAR(ctx,2,local+17); /*mapcar*/
	storeglobal(fqv[31],w);
	storeglobal(fqv[41],NIL);
	storeglobal(fqv[30],NIL);
	local[17]= loadglobal(fqv[31]);
	ctx->vsp=local+18;
	w=(pointer)F2046find_initial_hull(ctx,1,local+17); /*find-initial-hull*/
	local[0] = w;
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	storeglobal(fqv[42],w);
	local[17]= local[0];
	local[18]= fqv[27];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)COPYSEQ(ctx,1,local+17); /*copy-seq*/
	local[14] = w;
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	local[13] = w;
	local[17]= NIL;
	local[18]= loadglobal(fqv[39]);
WHL2229:
	if (local[18]==NIL) goto WHX2230;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[0];
	local[20]= fqv[43];
	local[21]= local[17];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= makeflt(9.9999999999999991239646e-05);
	ctx->vsp=local+21;
	w=(pointer)GREATERP(ctx,2,local+19); /*>*/
	if (w==NIL) goto IF2233;
	local[19]= loadglobal(fqv[44]);
	local[20]= fqv[45];
	local[21]= local[17];
	local[22]= local[0];
	local[23]= fqv[43];
	local[24]= local[17];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)XFORMAT(ctx,4,local+19); /*format*/
	local[19]= local[17];
	local[20]= loadglobal(fqv[39]);
	local[21]= fqv[3];
	local[22]= makeint((eusinteger_t)1L);
	ctx->vsp=local+23;
	w=(*ftab[7])(ctx,4,local+19,&ftab[7],fqv[36]); /*remove*/
	local[19]= w;
	storeglobal(fqv[39],w);
	goto IF2234;
IF2233:
	local[19]= NIL;
IF2234:
	goto WHL2229;
WHX2230:
	local[19]= NIL;
BLK2231:
	w = NIL;
WHL2235:
	if (local[13]==NIL) goto WHX2236;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[17];
	local[0] = w;
	local[17]= NIL;
	local[18]= local[0];
	local[19]= fqv[27];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,2,local+18); /*send*/
	local[18]= w;
WHL2240:
	if (local[18]==NIL) goto WHX2241;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	w = local[14];
	if (memq(local[19],w)==NIL) goto CON2245;
	local[19]= local[17];
	local[20]= fqv[23];
	local[21]= local[0];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= loadglobal(fqv[31]);
	ctx->vsp=local+21;
	w=(pointer)ASSQ(ctx,2,local+19); /*assq*/
	local[6] = w;
	local[19]= local[17];
	local[20]= fqv[24];
	local[21]= local[0];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= loadglobal(fqv[31]);
	ctx->vsp=local+21;
	w=(pointer)ASSQ(ctx,2,local+19); /*assq*/
	local[7] = w;
	if (local[6]==NIL) goto OR2248;
	if (local[7]==NIL) goto OR2248;
	goto IF2246;
OR2248:
	storeglobal(fqv[46],local[17]);
	local[19]= local[0];
	storeglobal(fqv[47],local[19]);
	local[19]= fqv[48];
	ctx->vsp=local+20;
	w=(pointer)SIGERROR(ctx,1,local+19); /*error*/
	local[19]= w;
	goto IF2247;
IF2246:
	local[19]= NIL;
IF2247:
	local[19]= local[0];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= local[0];
	local[22]= fqv[49];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	local[22]= local[17];
	local[23]= fqv[50];
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	local[23]= loadglobal(fqv[31]);
	ctx->vsp=local+24;
	w=(pointer)F2040gift_wrapping(ctx,5,local+19); /*gift-wrapping*/
	local[8] = w;
	local[19]= local[0];
	local[20]= fqv[49];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	ctx->vsp=local+23;
	w=(*ftab[2])(ctx,3,local+20,&ftab[2],fqv[8]); /*triangle-normal*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+19); /*v**/
	local[19]= w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)VMINUS(ctx,2,local+20); /*v-*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)VINNERPRODUCT(ctx,2,local+19); /*v.*/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left >= right) goto IF2249;}
	local[9] = local[7];
	local[7] = local[8];
	local[8] = local[9];
	local[19]= local[8];
	goto IF2250;
IF2249:
	local[19]= NIL;
IF2250:
	if (*(ovafptr(local[17],fqv[37]))==NIL) goto IF2251;
	local[19]= *(ovafptr(local[17],fqv[37]));
	goto IF2252;
IF2251:
	local[19]= *(ovafptr(local[17],fqv[38]));
IF2252:
	local[20]= fqv[12];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[16] = w;
	local[19]= (pointer)get_sym_func(fqv[40]);
	local[20]= local[16];
	local[21]= local[17];
	local[22]= fqv[12];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[8])(ctx,2,local+20,&ftab[8],fqv[51]); /*set-difference*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)MAPCAR(ctx,2,local+19); /*mapcar*/
	local[16] = w;
	local[19]= local[6];
	local[20]= local[7];
	local[21]= local[8];
	local[22]= loadglobal(fqv[31]);
	local[23]= local[16];
	local[24]= fqv[52];
	local[25]= (pointer)get_sym_func(fqv[28]);
	ctx->vsp=local+26;
	w=(*ftab[8])(ctx,4,local+22,&ftab[8],fqv[51]); /*set-difference*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)F2042make_face_from_coplanar_vertices(ctx,4,local+19); /*make-face-from-coplanar-vertices*/
	local[11] = w;
	local[19]= local[11];
	local[20]= fqv[27];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[10] = w;
	local[19]= NIL;
	local[20]= local[10];
WHL2254:
	if (local[20]==NIL) goto WHX2255;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	local[21]= local[19];
	w = local[14];
	if (memq(local[21],w)==NIL) goto CON2259;
	local[21]= local[19];
	local[22]= local[14];
	ctx->vsp=local+23;
	w=(*ftab[1])(ctx,2,local+21,&ftab[1],fqv[4]); /*delete*/
	local[14] = w;
	local[21]= local[19];
	w = local[15];
	ctx->vsp=local+22;
	local[15] = cons(ctx,local[21],w);
	local[21]= NIL;
	local[22]= NIL;
	local[23]= local[19];
	local[24]= fqv[12];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,2,local+23); /*send*/
	local[23]= w;
WHL2261:
	if (local[23]==NIL) goto WHX2262;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23] = (w)->c.cons.cdr;
	w = local[24];
	local[22] = w;
	local[24]= local[22];
	local[25]= loadglobal(fqv[31]);
	local[26]= fqv[52];
	local[27]= (pointer)get_sym_func(fqv[28]);
	ctx->vsp=local+28;
	w=(*ftab[9])(ctx,4,local+24,&ftab[9],fqv[53]); /*find*/
	local[21] = w;
	local[24]= local[21];
	ctx->vsp=local+25;
	w=(pointer)F2047enclosed_vertexp(ctx,1,local+24); /*enclosed-vertexp*/
	if (w==NIL) goto IF2265;
	local[24]= local[21];
	local[25]= loadglobal(fqv[31]);
	local[26]= fqv[3];
	local[27]= makeint((eusinteger_t)1L);
	ctx->vsp=local+28;
	w=(*ftab[1])(ctx,4,local+24,&ftab[1],fqv[4]); /*delete*/
	local[24]= w;
	storeglobal(fqv[31],w);
	goto IF2266;
IF2265:
	local[24]= NIL;
IF2266:
	goto WHL2261;
WHX2262:
	local[24]= NIL;
BLK2263:
	w = NIL;
	local[21]= w;
	goto CON2258;
CON2259:
	local[21]= local[19];
	w = local[15];
	if (memq(local[21],w)==NIL) goto CON2267;
	local[21]= loadglobal(fqv[44]);
	local[22]= fqv[54];
	local[23]= local[19];
	ctx->vsp=local+24;
	w=(pointer)XFORMAT(ctx,3,local+21); /*format*/
	local[21]= loadglobal(fqv[9]);
	local[22]= makeint((eusinteger_t)2L);
	ctx->vsp=local+23;
	w=(pointer)QUOTIENT(ctx,2,local+21); /*/*/
	local[21]= w;
	w = local[21];
	ctx->vsp=local+22;
	bindspecial(ctx,fqv[9],w);
	local[25]= loadglobal(fqv[44]);
	local[26]= fqv[55];
	local[27]= makeint((eusinteger_t)2L);
	local[28]= loadglobal(fqv[9]);
	ctx->vsp=local+29;
	w=(pointer)TIMES(ctx,2,local+27); /***/
	local[27]= w;
	local[28]= loadglobal(fqv[9]);
	ctx->vsp=local+29;
	w=(pointer)XFORMAT(ctx,4,local+25); /*format*/
	local[25]= loadglobal(fqv[9]);
	local[26]= makeflt(9.9999999999999991239646e-06);
	ctx->vsp=local+27;
	w=(pointer)LESSP(ctx,2,local+25); /*<*/
	if (w==NIL) goto IF2268;
	local[25]= fqv[56];
	ctx->vsp=local+26;
	w=(pointer)SIGERROR(ctx,1,local+25); /*error*/
	local[25]= w;
	goto IF2269;
IF2268:
	local[25]= argv[0];
	ctx->vsp=local+26;
	w=(pointer)F2048convex_hull_3d(ctx,1,local+25); /*convex-hull-3d*/
	ctx->vsp=local+25;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK2227;
IF2269:
	ctx->vsp=local+26;
	unbindx(ctx,1);
	w = local[25];
	local[21]= w;
	goto CON2258;
CON2267:
	local[21]= local[14];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)LIST(ctx,1,local+22); /*list*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)APPEND(ctx,2,local+21); /*append*/
	local[14] = w;
	local[21]= local[14];
	goto CON2258;
CON2270:
	local[21]= NIL;
CON2258:
	goto WHL2254;
WHX2255:
	local[21]= NIL;
BLK2256:
	w = NIL;
	local[19]= local[11];
	w = local[13];
	ctx->vsp=local+20;
	local[13] = cons(ctx,local[19],w);
	local[19]= loadglobal(fqv[42]);
	local[20]= local[11];
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)NCONC(ctx,2,local+19); /*nconc*/
	if (loadglobal(fqv[57])==NIL) goto IF2271;
	local[19]= loadglobal(fqv[42]);
	ctx->vsp=local+20;
	w=(pointer)LENGTH(ctx,1,local+19); /*length*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)PRINT(ctx,1,local+19); /*print*/
	local[19]= w;
	goto IF2272;
IF2271:
	local[19]= NIL;
IF2272:
	goto CON2244;
CON2245:
	local[19]= NIL;
CON2244:
	goto WHL2240;
WHX2241:
	local[19]= NIL;
BLK2242:
	w = NIL;
	goto WHL2235;
WHX2236:
	local[17]= NIL;
BLK2237:
	local[17]= (pointer)get_sym_func(fqv[58]);
	local[18]= loadglobal(fqv[42]);
	local[19]= fqv[27];
	ctx->vsp=local+20;
	w=(*ftab[10])(ctx,2,local+18,&ftab[10],fqv[59]); /*send-all*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,2,local+17); /*apply*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,1,local+17,&ftab[11],fqv[60]); /*remove-duplicates*/
	local[17]= w;
	storeglobal(fqv[61],w);
	local[17]= (pointer)get_sym_func(fqv[58]);
	local[18]= loadglobal(fqv[42]);
	local[19]= fqv[12];
	ctx->vsp=local+20;
	w=(*ftab[10])(ctx,2,local+18,&ftab[10],fqv[59]); /*send-all*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)APPLY(ctx,2,local+17); /*apply*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,1,local+17,&ftab[11],fqv[60]); /*remove-duplicates*/
	local[17]= w;
	storeglobal(fqv[31],w);
	local[17]= loadglobal(fqv[62]);
	ctx->vsp=local+18;
	w=(pointer)INSTANTIATE(ctx,1,local+17); /*instantiate*/
	local[17]= w;
	local[18]= local[17];
	local[19]= fqv[22];
	local[20]= fqv[63];
	local[21]= loadglobal(fqv[42]);
	local[22]= fqv[27];
	local[23]= loadglobal(fqv[61]);
	local[24]= fqv[12];
	local[25]= loadglobal(fqv[31]);
	local[26]= fqv[64];
	local[27]= fqv[65];
	local[28]= loadglobal(fqv[31]);
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,2,local+27); /*list*/
	local[27]= w;
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,10,local+18); /*send*/
	w = local[17];
	local[17]= w;
	storeglobal(fqv[66],w);
	w = local[17];
	local[0]= w;
BLK2227:
	ctx->vsp=local; return(local[0]);}

/*rotate-vertices*/
static pointer F2049rotate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SUB1(ctx,1,local+4); /*1-*/
	local[4]= w;
WHL2276:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX2277;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[2];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)ROTVEC(ctx,3,local+5); /*rotate-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[2] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL2276;
WHX2277:
	local[5]= NIL;
BLK2278:
	w = NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK2274:
	ctx->vsp=local; return(local[0]);}

/*make-side-faces*/
static pointer F2050make_side_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2281;}
	local[0]= NIL;
ENT2281:
ENT2280:
	if (n>3) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= makeint((eusinteger_t)0L);
WHL2282:
	if (argv[1]==NIL) goto WHX2283;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[10];
	local[4] = w;
	if (argv[1]==NIL) goto IF2286;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF2287;
IF2286:
	local[10]= local[2];
IF2287:
	local[5] = local[10];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[10];
	local[7] = w;
	if (argv[0]==NIL) goto IF2289;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	goto IF2290;
IF2289:
	local[10]= local[1];
IF2290:
	local[6] = local[10];
	local[10]= local[4];
	local[11]= local[5];
	local[12]= local[6];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,4,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+10); /*make-face-from-vertices*/
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[67];
	if (local[0]==NIL) goto IF2291;
	local[12]= fqv[68];
	local[13]= local[0];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	goto IF2292;
IF2291:
	local[12]= fqv[68];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,2,local+12); /*list*/
	local[12]= w;
IF2292:
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= local[9];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[9] = w;
	local[10]= local[8];
	w = local[3];
	ctx->vsp=local+11;
	local[3] = cons(ctx,local[10],w);
	goto WHL2282;
WHX2283:
	local[10]= NIL;
BLK2284:
	w = local[3];
	local[0]= w;
BLK2279:
	ctx->vsp=local; return(local[0]);}

/*make-prism*/
static pointer F2051make_prism(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2294:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[69], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2295;
	local[2]= fqv[70];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[1] = w;
KEY2295:
	w = argv[1];
	if (!isnum(w)) goto IF2296;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	argv[1] = w;
	local[2]= argv[1];
	goto IF2297;
IF2296:
	local[2]= NIL;
IF2297:
	local[2]= (pointer)get_sym_func(fqv[40]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO2298,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= NIL;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+5); /*make-face-from-vertices*/
	local[5]= w;
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[67];
	local[7]= fqv[71];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= local[4];
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)REVERSE(ctx,1,local+7); /*reverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F2050make_side_faces(ctx,2,local+6); /*make-side-faces*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+5); /*make-face-from-vertices*/
	local[5]= w;
	w = local[4];
	ctx->vsp=local+6;
	local[4] = cons(ctx,local[5],w);
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[67];
	local[7]= fqv[72];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= (pointer)get_sym_func(fqv[73]);
	local[6]= loadglobal(fqv[62]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= fqv[22];
	local[8]= fqv[63];
	local[9]= local[4];
	local[10]= fqv[74];
	local[11]= T;
	local[12]= fqv[64];
	local[13]= local[1];
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)APPLY(ctx,10,local+5); /*apply*/
	local[0]= w;
BLK2293:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2298(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-conic-side-faces*/
static pointer F2052make_conic_side_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2301;}
	local[0]= NIL;
ENT2301:
ENT2300:
	if (n>3) maerror();
	local[1]= NIL;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= makeint((eusinteger_t)0L);
WHL2302:
	if (argv[1]==NIL) goto WHX2303;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= argv[0];
	if (argv[1]==NIL) goto IF2306;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF2307;
IF2306:
	local[6]= local[2];
IF2307:
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+4); /*make-face-from-vertices*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[67];
	if (local[0]==NIL) goto IF2308;
	local[6]= fqv[68];
	local[7]= local[0];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	goto IF2309;
IF2308:
	local[6]= fqv[68];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
IF2309:
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[3] = w;
	goto WHL2302;
WHX2303:
	local[4]= NIL;
BLK2304:
	w = local[1];
	local[0]= w;
BLK2299:
	ctx->vsp=local; return(local[0]);}

/*make-cone*/
static pointer F2053make_cone(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2311:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[75], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2312;
	local[1] = makeint((eusinteger_t)16L);
KEY2312:
	if (n & (1<<1)) goto KEY2313;
	local[2] = NIL;
KEY2313:
	if (n & (1<<2)) goto KEY2314;
	local[3] = NIL;
KEY2314:
	local[4]= NIL;
	local[5]= NIL;
	w = argv[1];
	if (!isnum(w)) goto IF2315;
	local[6]= argv[1];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	local[7]= local[1];
	local[8]= makeflt(6.2831853071795862319959e+00);
	local[9]= fqv[76];
	ctx->vsp=local+10;
	w=(pointer)F2049rotate_vertices(ctx,4,local+6); /*rotate-vertices*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	argv[1] = w;
	local[6]= argv[1];
	goto IF2316;
IF2315:
	local[6]= (pointer)get_sym_func(fqv[40]);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	argv[1] = w;
	local[6]= argv[1];
IF2316:
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+6); /*make-face-from-vertices*/
	local[5] = w;
	local[6]= local[5];
	local[7]= fqv[67];
	local[8]= fqv[72];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= (pointer)get_sym_func(fqv[73]);
	local[7]= loadglobal(fqv[62]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= fqv[22];
	local[9]= fqv[63];
	local[10]= local[5];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)F2052make_conic_side_faces(ctx,2,local+11); /*make-conic-side-faces*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= fqv[74];
	local[12]= T;
	local[13]= fqv[64];
	local[14]= fqv[77];
	local[15]= fqv[71];
	local[16]= (pointer)get_sym_func(fqv[28]);
	local[17]= argv[1];
	ctx->vsp=local+18;
	w=(pointer)MAPCAR(ctx,2,local+16); /*mapcar*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,3,local+14); /*list*/
	local[14]= w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,10,local+6); /*apply*/
	local[0]= w;
BLK2310:
	ctx->vsp=local; return(local[0]);}

/*on-z-axis-p*/
static pointer F2317(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[2];
	local[1]= fqv[78];
	local[2]= fqv[79];
	local[3]= argv[0];
	local[4]= fqv[80];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[81];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK2318:
	ctx->vsp=local; return(local[0]);}

/*make-solid-of-revolution*/
static pointer F2054make_solid_of_revolution(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2320:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[82], &argv[1], n-1, local+1, 1);
	if (n & (1<<0)) goto KEY2321;
	local[1] = makeint((eusinteger_t)16L);
KEY2321:
	local[2]= (pointer)get_sym_func(fqv[40]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= makeint((eusinteger_t)0L);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto IF2323;
	local[7]= local[3];
	local[8]= local[1];
	local[9]= makeflt(6.2831853071795862319959e+00);
	local[10]= fqv[76];
	ctx->vsp=local+11;
	w=(pointer)F2049rotate_vertices(ctx,4,local+7); /*rotate-vertices*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+7); /*make-face-from-vertices*/
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[67];
	local[9]= fqv[72];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF2324;
IF2323:
	local[7]= NIL;
IF2324:
WHL2325:
	if (local[2]==NIL) goto WHX2326;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[7];
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w!=NIL) goto IF2329;
	local[7]= local[4];
	local[8]= local[1];
	local[9]= makeflt(6.2831853071795862319959e+00);
	local[10]= fqv[76];
	ctx->vsp=local+11;
	w=(pointer)F2049rotate_vertices(ctx,4,local+7); /*rotate-vertices*/
	local[4] = w;
	local[7]= local[4];
	goto IF2330;
IF2329:
	local[7]= NIL;
IF2330:
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON2332;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF2333;
	local[7]= fqv[83];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF2334;
IF2333:
	local[7]= NIL;
IF2334:
	local[7]= local[4];
	local[8]= local[3];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F2052make_conic_side_faces(ctx,3,local+7); /*make-conic-side-faces*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto CON2331;
CON2332:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON2335;
	local[7]= local[3];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)REVERSE(ctx,1,local+8); /*reverse*/
	local[8]= w;
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F2052make_conic_side_faces(ctx,3,local+7); /*make-conic-side-faces*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto CON2331;
CON2335:
	local[7]= local[3];
	local[8]= local[4];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F2050make_side_faces(ctx,3,local+7); /*make-side-faces*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto CON2331;
CON2336:
	local[7]= NIL;
CON2331:
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[6] = w;
	local[3] = local[4];
	goto WHL2325;
WHX2326:
	local[7]= NIL;
BLK2327:
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF2337;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LISTP(ctx,1,local+7); /*listp*/
	if (w==NIL) goto IF2337;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)REVERSE(ctx,1,local+7); /*reverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+7); /*make-face-from-vertices*/
	local[7]= w;
	w = local[5];
	ctx->vsp=local+8;
	local[5] = cons(ctx,local[7],w);
	local[7]= local[5];
	goto IF2338;
IF2337:
	local[7]= NIL;
IF2338:
	local[7]= (pointer)get_sym_func(fqv[73]);
	local[8]= loadglobal(fqv[62]);
	ctx->vsp=local+9;
	w=(pointer)INSTANTIATE(ctx,1,local+8); /*instantiate*/
	local[8]= w;
	local[9]= fqv[22];
	local[10]= fqv[63];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[12])(ctx,1,local+11,&ftab[12],fqv[84]); /*flatten*/
	local[11]= w;
	local[12]= fqv[74];
	local[13]= T;
	local[14]= fqv[64];
	local[15]= fqv[85];
	local[16]= argv[0];
	local[17]= local[1];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,3,local+15); /*list*/
	local[15]= w;
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(pointer)APPLY(ctx,10,local+7); /*apply*/
	local[0]= w;
BLK2319:
	ctx->vsp=local; return(local[0]);}

/*make-torus*/
static pointer F2055make_torus(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2340:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[86], &argv[1], n-1, local+1, 1);
	if (n & (1<<0)) goto KEY2341;
	local[1] = makeint((eusinteger_t)16L);
KEY2341:
	local[2]= NIL;
	local[3]= (pointer)get_sym_func(fqv[40]);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	local[5]= local[1];
	local[6]= makeflt(6.2831853071795862319959e+00);
	local[7]= fqv[76];
	ctx->vsp=local+8;
	w=(pointer)F2049rotate_vertices(ctx,4,local+4); /*rotate-vertices*/
	local[4]= w;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= makeint((eusinteger_t)0L);
	local[5] = local[4];
WHL2343:
	if (local[3]==NIL) goto WHX2344;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= local[1];
	local[10]= makeflt(6.2831853071795862319959e+00);
	local[11]= fqv[76];
	ctx->vsp=local+12;
	w=(pointer)F2049rotate_vertices(ctx,4,local+8); /*rotate-vertices*/
	local[6] = w;
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[6];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)F2050make_side_faces(ctx,3,local+9); /*make-side-faces*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[2] = w;
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[7] = w;
	local[5] = local[6];
	goto WHL2343;
WHX2344:
	local[8]= NIL;
BLK2345:
	local[8]= local[2];
	local[9]= local[6];
	local[10]= local[4];
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)F2050make_side_faces(ctx,3,local+9); /*make-side-faces*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= (pointer)get_sym_func(fqv[73]);
	local[9]= loadglobal(fqv[62]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= fqv[22];
	local[11]= fqv[63];
	local[12]= local[2];
	local[13]= fqv[64];
	local[14]= fqv[87];
	local[15]= argv[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,3,local+14); /*list*/
	local[14]= w;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)APPLY(ctx,8,local+8); /*apply*/
	local[0]= w;
BLK2339:
	ctx->vsp=local; return(local[0]);}

/*make-cylinder*/
static pointer F2056make_cylinder(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST2348:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[88], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY2349;
	local[1] = makeint((eusinteger_t)12L);
KEY2349:
	if (n & (1<<1)) goto KEY2350;
	local[2] = NIL;
KEY2350:
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	argv[0] = w;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	argv[1] = w;
	local[3]= makeflt(6.2831853071795862319959e+00);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	if (local[2]==NIL) goto IF2351;
	local[4]= argv[0];
	local[5]= local[3];
	local[6]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)COS(ctx,1,local+5); /*cos*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	goto IF2352;
IF2351:
	local[4]= argv[0];
IF2352:
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	local[7]= NIL;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SUB1(ctx,1,local+9); /*1-*/
	local[9]= w;
WHL2354:
	local[10]= local[8];
	w = local[9];
	if ((eusinteger_t)local[10] >= (eusinteger_t)w) goto WHX2355;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[3];
	local[12]= fqv[76];
	ctx->vsp=local+13;
	w=(pointer)ROTVEC(ctx,3,local+10); /*rotate-vector*/
	local[10]= w;
	w = local[6];
	ctx->vsp=local+11;
	local[6] = cons(ctx,local[10],w);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[8] = w;
	goto WHL2354;
WHX2355:
	local[10]= NIL;
BLK2356:
	w = NIL;
	local[8]= (pointer)get_sym_func(fqv[89]);
	local[9]= local[6];
	local[10]= argv[1];
	local[11]= fqv[64];
	local[12]= fqv[90];
	local[13]= local[4];
	local[14]= argv[1];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,4,local+12); /*list*/
	local[12]= w;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(pointer)APPLY(ctx,6,local+8); /*apply*/
	local[7] = w;
	local[8]= local[7];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= makeint((eusinteger_t)0L);
	local[11]= makeint((eusinteger_t)0L);
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[13])(ctx,2,local+9,&ftab[13],fqv[91]); /*make-line*/
	local[9]= w;
	local[10]= fqv[92];
	ctx->vsp=local+11;
	w=(pointer)PUTPROP(ctx,3,local+8); /*putprop*/
	w = local[7];
	local[0]= w;
BLK2347:
	ctx->vsp=local; return(local[0]);}

/*make-cube*/
static pointer F2057make_cube(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST2358:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[0] = w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[1] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EUSFLOAT(ctx,1,local+1); /*float*/
	argv[2] = w;
	local[1]= argv[0];
	local[2]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= argv[1];
	local[3]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,1,local+3); /*-*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[4] = w;
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[5] = w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[6] = w;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[7] = w;
	local[9]= (pointer)get_sym_func(fqv[89]);
	local[10]= local[4];
	local[11]= local[5];
	local[12]= local[6];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,4,local+10); /*list*/
	local[10]= w;
	local[11]= argv[2];
	local[12]= fqv[64];
	local[13]= fqv[93];
	local[14]= argv[0];
	local[15]= argv[1];
	local[16]= argv[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,4,local+13); /*list*/
	local[13]= w;
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)APPLY(ctx,6,local+9); /*apply*/
	local[8] = w;
	local[9]= NIL;
	local[10]= local[8];
	local[11]= fqv[94];
	local[12]= NIL;
	local[13]= fqv[68];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
WHL2360:
	if (local[10]==NIL) goto WHX2361;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= fqv[67];
	local[13]= local[9];
	local[14]= fqv[67];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	local[14]= makeint((eusinteger_t)1L);
	local[15]= local[9];
	local[16]= fqv[67];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)NTH(ctx,2,local+14); /*nth*/
	local[14]= w;
	local[15]= fqv[95];
	ctx->vsp=local+16;
	w=(pointer)NTH(ctx,2,local+14); /*nth*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)APPEND(ctx,2,local+13); /*append*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	goto WHL2360;
WHX2361:
	local[11]= NIL;
BLK2362:
	w = NIL;
	w = local[8];
	local[0]= w;
BLK2357:
	ctx->vsp=local; return(local[0]);}

/*icosahedron-points*/
static pointer F2058icosahedron_points(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2366;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT2366:
ENT2365:
	if (n>1) maerror();
	local[1]= makeflt(1.0000000000000000000000e+00);
	local[2]= makeflt(5.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)SQRT(ctx,1,local+2); /*sqrt*/
	{ double x,y;
		y=fltval(w); x=fltval(local[1]);
		local[1]=(makeflt(x + y));}
	local[2]= makeflt(2.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)SQRT(ctx,1,local+3); /*sqrt*/
	local[3]= w;
	local[4]= makeflt(5.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SQRT(ctx,1,local+4); /*sqrt*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)QUOTIENT(ctx,2,local+3); /*/*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)TIMES(ctx,2,local+2); /***/
	local[2]= w;
	local[3]= local[0];
	local[4]= makeflt(1.0000000000000000000000e+00);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SQRT(ctx,1,local+5); /*sqrt*/
	local[5]= w;
	local[6]= makeflt(5.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)SQRT(ctx,1,local+6); /*sqrt*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SQRT(ctx,1,local+6); /*sqrt*/
	{ double x,y;
		y=fltval(w); x=fltval(local[5]);
		local[5]=(makeflt(x * y));}
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,1,local+6); /*-*/
	local[6]= w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MKFLTVEC(ctx,3,local+6); /*float-vector*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,1,local+9); /*-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)MKFLTVEC(ctx,3,local+7); /*float-vector*/
	local[7]= w;
	local[8]= local[3];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)MKFLTVEC(ctx,3,local+8); /*float-vector*/
	local[8]= w;
	local[9]= local[3];
	local[10]= makeint((eusinteger_t)0L);
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)MKFLTVEC(ctx,3,local+9); /*float-vector*/
	local[9]= w;
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)MINUS(ctx,1,local+10); /*-*/
	local[10]= w;
	local[11]= makeint((eusinteger_t)0L);
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)MKFLTVEC(ctx,3,local+10); /*float-vector*/
	local[10]= w;
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)MINUS(ctx,1,local+11); /*-*/
	local[11]= w;
	local[12]= makeint((eusinteger_t)0L);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MINUS(ctx,1,local+13); /*-*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MKFLTVEC(ctx,3,local+11); /*float-vector*/
	local[11]= w;
	local[12]= local[2];
	local[13]= local[3];
	local[14]= makeint((eusinteger_t)0L);
	ctx->vsp=local+15;
	w=(pointer)MKFLTVEC(ctx,3,local+12); /*float-vector*/
	local[12]= w;
	local[13]= local[2];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	local[15]= makeint((eusinteger_t)0L);
	ctx->vsp=local+16;
	w=(pointer)MKFLTVEC(ctx,3,local+13); /*float-vector*/
	local[13]= w;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)MINUS(ctx,1,local+14); /*-*/
	local[14]= w;
	local[15]= local[3];
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)MKFLTVEC(ctx,3,local+14); /*float-vector*/
	local[14]= w;
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MINUS(ctx,1,local+15); /*-*/
	local[15]= w;
	local[16]= local[3];
	ctx->vsp=local+17;
	w=(pointer)MINUS(ctx,1,local+16); /*-*/
	local[16]= w;
	local[17]= makeint((eusinteger_t)0L);
	ctx->vsp=local+18;
	w=(pointer)MKFLTVEC(ctx,3,local+15); /*float-vector*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,12,local+4); /*list*/
	local[0]= w;
BLK2364:
	ctx->vsp=local; return(local[0]);}

/*make-icosahedron*/
static pointer F2059make_icosahedron(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2369;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT2369:
ENT2368:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F2058icosahedron_points(ctx,1,local+3); /*icosahedron-points*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F2048convex_hull_3d(ctx,1,local+3); /*convex-hull-3d*/
	local[2] = w;
	local[3]= local[2];
	local[4]= fqv[96];
	local[5]= fqv[97];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK2367:
	ctx->vsp=local; return(local[0]);}

/*subdivide-facet*/
static pointer F2060subdivide_facet(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2371;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2372;
IF2371:
	local[3]= NIL;
IF2372:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2373;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2374;
IF2373:
	local[3]= NIL;
IF2374:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2375;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2376;
IF2375:
	local[3]= NIL;
IF2376:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= (pointer)get_sym_func(fqv[8]);
	local[4]= (pointer)get_sym_func(fqv[28]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)VINNERPRODUCT(ctx,2,local+3); /*v.*/
	local[3]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[3]);
	if (left >= right) goto IF2377;}
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF2378;
IF2377:
	local[3]= NIL;
IF2378:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+3); /*make-face-from-vertices*/
	local[3]= w;
	w = local[1];
	ctx->vsp=local+4;
	local[1] = cons(ctx,local[3],w);
	w = local[1];
	local[0]= w;
BLK2370:
	ctx->vsp=local; return(local[0]);}

/*make-dodecahedron*/
static pointer F2061make_dodecahedron(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT2381;}
	local[0]= makeflt(1.0000000000000000000000e+00);
ENT2381:
ENT2380:
	if (n>1) maerror();
	ctx->vsp=local+1;
	w=(pointer)F2059make_icosahedron(ctx,0,local+1); /*make-icosahedron*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[1]->c.obj.iv[9];
WHL2383:
	if (local[6]==NIL) goto WHX2384;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w=local[5]->c.obj.iv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(*ftab[14])(ctx,1,local+7,&ftab[14],fqv[98]); /*vector-mean*/
	local[2] = w;
	local[7]= local[0];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)VNORM(ctx,1,local+8); /*norm*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)QUOTIENT(ctx,2,local+7); /*/*/
	local[7]= w;
	local[8]= local[2];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SCALEVEC(ctx,3,local+7); /*scale*/
	local[7]= local[2];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	goto WHL2383;
WHX2384:
	local[7]= NIL;
BLK2385:
	w = NIL;
	local[5]= local[3];
	storeglobal(fqv[99],local[5]);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)F2048convex_hull_3d(ctx,1,local+5); /*convex-hull-3d*/
	local[4] = w;
	local[5]= local[4];
	local[6]= fqv[96];
	local[7]= fqv[100];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK2379:
	ctx->vsp=local; return(local[0]);}

/*make-gdome*/
static pointer F2062make_gdome(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[101];
	local[1]= (pointer)get_sym_func(fqv[102]);
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,2,local+0,&ftab[15],fqv[103]); /*make-hash-table*/
	local[0]= w;
	local[1]= fqv[101];
	local[2]= (pointer)get_sym_func(fqv[102]);
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,2,local+1,&ftab[15],fqv[103]); /*make-hash-table*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	w=*(ovafptr(argv[0],fqv[104]));
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)VNORM(ctx,1,local+7); /*norm*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= *(ovafptr(argv[0],fqv[104]));
WHL2389:
	if (local[10]==NIL) goto WHX2390;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= local[0];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)COPYOBJ(ctx,1,local+13); /*copy-object*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(*ftab[16])(ctx,3,local+11,&ftab[16],fqv[105]); /*sethash*/
	goto WHL2389;
WHX2390:
	local[11]= NIL;
BLK2391:
	w = NIL;
	local[9]= NIL;
	local[10]= *(ovafptr(argv[0],fqv[106]));
WHL2394:
	if (local[10]==NIL) goto WHX2395;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[7];
	local[12]= *(ovafptr(local[9],fqv[107]));
	local[13]= *(ovafptr(local[9],fqv[108]));
	ctx->vsp=local+14;
	w=(pointer)VPLUS(ctx,2,local+12); /*v+*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)VNORMALIZE(ctx,1,local+12); /*normalize-vector*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SCALEVEC(ctx,2,local+11); /*scale*/
	local[4] = w;
	local[11]= local[9];
	local[12]= local[1];
	local[13]= local[9];
	local[14]= local[4];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(*ftab[16])(ctx,3,local+11,&ftab[16],fqv[105]); /*sethash*/
	goto WHL2394;
WHX2395:
	local[11]= NIL;
BLK2396:
	w = NIL;
	local[9]= NIL;
	local[10]= *(ovafptr(argv[0],fqv[109]));
WHL2399:
	if (local[10]==NIL) goto WHX2400;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[4] = *(ovafptr(local[9],fqv[104]));
	local[5] = *(ovafptr(local[9],fqv[106]));
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(*ftab[17])(ctx,2,local+11,&ftab[17],fqv[110]); /*gethash*/
	local[11]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(*ftab[17])(ctx,2,local+12,&ftab[17],fqv[110]); /*gethash*/
	local[12]= w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,2,local+13,&ftab[17],fqv[110]); /*gethash*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[2] = w;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(*ftab[17])(ctx,2,local+11,&ftab[17],fqv[110]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(*ftab[17])(ctx,2,local+12,&ftab[17],fqv[110]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.cdr;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,2,local+13,&ftab[17],fqv[110]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,3,local+11); /*list*/
	local[3] = w;
	local[11]= *(ovafptr(local[9],fqv[111]));
	local[12]= local[2];
	local[13]= local[3];
	ctx->vsp=local+14;
	w=(pointer)F2060subdivide_facet(ctx,3,local+11); /*subdivide-facet*/
	local[11]= w;
	w = local[6];
	ctx->vsp=local+12;
	local[6] = cons(ctx,local[11],w);
	goto WHL2399;
WHX2400:
	local[11]= NIL;
BLK2401:
	w = NIL;
	local[9]= loadglobal(fqv[62]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[22];
	local[12]= fqv[63];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(*ftab[12])(ctx,1,local+13,&ftab[12],fqv[84]); /*flatten*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	w = local[9];
	local[8] = w;
	local[9]= local[8];
	local[10]= fqv[96];
	local[11]= fqv[112];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	w = local[8];
	local[0]= w;
BLK2387:
	ctx->vsp=local; return(local[0]);}

/*make-body-from-vertices*/
static pointer F2063make_body_from_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2406;}
	local[0]= loadglobal(fqv[62]);
ENT2406:
ENT2405:
	if (n>2) maerror();
	local[1]= (pointer)get_sym_func(fqv[40]);
	local[2]= (pointer)get_sym_func(fqv[58]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	local[3]= fqv[101];
	local[4]= (pointer)get_sym_func(fqv[102]);
	ctx->vsp=local+5;
	w=(*ftab[11])(ctx,3,local+2,&ftab[11],fqv[60]); /*remove-duplicates*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL2408:
	if (local[5]==NIL) goto WHX2409;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[4];
WHL2413:
	if (local[8]==NIL) goto WHX2414;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= local[1];
	local[11]= fqv[101];
	local[12]= (pointer)get_sym_func(fqv[102]);
	ctx->vsp=local+13;
	w=(*ftab[18])(ctx,4,local+9,&ftab[18],fqv[113]); /*assoc*/
	local[9]= w;
	w = local[6];
	ctx->vsp=local+10;
	local[6] = cons(ctx,local[9],w);
	goto WHL2413;
WHX2414:
	local[9]= NIL;
BLK2415:
	w = NIL;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F2041make_face_from_vertices(ctx,1,local+7); /*make-face-from-vertices*/
	local[7]= w;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	w = local[2];
	goto WHL2408;
WHX2409:
	local[6]= NIL;
BLK2410:
	w = NIL;
	local[4]= loadglobal(fqv[62]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[22];
	local[7]= fqv[63];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	w = local[4];
	local[3] = w;
	local[4]= local[3];
	local[5]= fqv[96];
	local[6]= fqv[114];
	w = argv[0];
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK2404:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M2418coordinates_axes_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[7] = NIL;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2421:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX2422;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+4;
	w=(pointer)NTH(ctx,2,local+2); /*nth*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[115];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+7;
	w=(pointer)NTH(ctx,2,local+5); /*nth*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,2,local+2,&ftab[19],fqv[116]); /*replace*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL2421;
WHX2422:
	local[2]= NIL;
BLK2423:
	w = NIL;
	local[0]= w;
BLK2419:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M2424coordinates_axes_magnify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
WHL2427:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX2428;
	local[2]= argv[2];
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+5;
	w=(pointer)NTH(ctx,2,local+3); /*nth*/
	local[3]= w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+6;
	w=(pointer)NTH(ctx,2,local+4); /*nth*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,3,local+2); /*scale*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL2427;
WHX2428:
	local[2]= NIL;
BLK2429:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[117];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK2425:
	ctx->vsp=local; return(local[0]);}

/*:drawners*/
static pointer M2430coordinates_axes_drawners(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK2431:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M2432coordinates_axes_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST2434:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	argv[0]->c.obj.iv[10] = NIL;
	argv[0]->c.obj.iv[11] = NIL;
	argv[0]->c.obj.iv[8] = argv[2];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= argv[2];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= argv[2];
	local[2]= makeflt(5.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[2];
	local[4]= makeflt(7.9999999999999982236432e-01);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[2];
	local[3]= makeflt(5.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= makeflt(7.9999999999999982236432e-01);
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MKFLTVEC(ctx,3,local+1); /*float-vector*/
	local[1]= w;
	w = argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[10] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)COPYOBJ(ctx,1,local+1); /*copy-object*/
	argv[0]->c.obj.iv[9] = w;
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[91]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[91]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	w=argv[0]->c.obj.iv[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(*ftab[20])(ctx,1,local+2,&ftab[20],fqv[118]); /*fourth*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[91]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[118]); /*fourth*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(*ftab[21])(ctx,1,local+2,&ftab[21],fqv[119]); /*fifth*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[91]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[118]); /*fourth*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[120]); /*sixth*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[13])(ctx,2,local+1,&ftab[13],fqv[91]); /*make-line*/
	local[1]= w;
	w = argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[11] = cons(ctx,local[1],w);
	local[1]= (pointer)get_sym_func(fqv[121]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[122]));
	local[4]= fqv[22];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	w = argv[0];
	local[0]= w;
BLK2433:
	ctx->vsp=local; return(local[0]);}

/*assoc-coordinates-axes*/
static pointer F2064assoc_coordinates_axes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT2438;}
	local[0]= makeint((eusinteger_t)1L);
ENT2438:
	if (n>=3) { local[1]=(argv[2]); goto ENT2437;}
	ctx->vsp=local+1;
	w=(*ftab[23])(ctx,0,local+1,&ftab[23],fqv[123]); /*coords*/
	local[1]= w;
ENT2437:
ENT2436:
	if (n>3) maerror();
	local[2]= loadglobal(fqv[124]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[22];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[125];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK2435:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___primt(ctx,n,argv,env)
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
	local[0]= fqv[126];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2440;
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[128],w);
	goto IF2441;
IF2440:
	local[0]= fqv[129];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2441:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F2027find_extream,fqv[133]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[134],module,F2028leftmost_point,fqv[135]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[136],module,F2029rightmost_point,fqv[137]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[138],module,F2030left_points,fqv[139]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[140],module,F2031right_points,fqv[141]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[142],module,F2032quickhull_left,fqv[143]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[144],module,F2033quickhull_right,fqv[145]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[146],module,F2034quickhull,fqv[147]);
	local[0]= makeflt(1.0000000000000000208167e-03);
	storeglobal(fqv[9],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[148],module,F2035find_coplanar_vertices,fqv[149]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[150],module,F2036colinear_p,fqv[151]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[152],module,F2037find_colinear_points,fqv[153]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[154],module,F2038remove_colinears_from_circuit,fqv[155]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[156],module,F2039coplanar_p,fqv[157]);
	local[0]= fqv[13];
	local[1]= fqv[158];
	local[2]= makeflt(-1.0000000000000000000000e+00);
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[159];
	local[1]= fqv[158];
	local[2]= makeflt(1.0000000000000000000000e+00);
	local[3]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= fqv[14];
	local[4]= fqv[158];
	local[5]= makeflt(0.0000000000000000000000e+00);
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F2040gift_wrapping,fqv[161]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[162],module,F2041make_face_from_vertices,fqv[163]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[164],module,F2042make_face_from_coplanar_vertices,fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F2043tangent_foot,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F2044calc_p2_of_lowest_hull,fqv[169]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[170],module,F2045calc_p3_of_lowest_hull,fqv[171]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[172],module,F2046find_initial_hull,fqv[173]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[174],module,F2047enclosed_vertexp,fqv[175]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[176],module,F2048convex_hull_3d,fqv[177]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[178],module,F2049rotate_vertices,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F2050make_side_faces,fqv[181]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F2051make_prism,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F2052make_conic_side_faces,fqv[184]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F2053make_cone,fqv[186]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[187],module,F2317,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F2054make_solid_of_revolution,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F2055make_torus,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F2056make_cylinder,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F2057make_cube,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F2058icosahedron_points,fqv[198]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F2059make_icosahedron,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F2060subdivide_facet,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F2061make_dodecahedron,fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F2062make_gdome,fqv[206]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[207],module,F2063make_body_from_vertices,fqv[208]);
	local[0]= fqv[124];
	local[1]= fqv[158];
	local[2]= fqv[124];
	local[3]= fqv[209];
	local[4]= loadglobal(fqv[210]);
	local[5]= fqv[211];
	local[6]= fqv[212];
	local[7]= fqv[213];
	local[8]= NIL;
	local[9]= fqv[214];
	local[10]= NIL;
	local[11]= fqv[215];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[216];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[24])(ctx,13,local+2,&ftab[24],fqv[217]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2418coordinates_axes_update,fqv[117],fqv[124],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2424coordinates_axes_magnify,fqv[219],fqv[124],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2430coordinates_axes_drawners,fqv[221],fqv[124],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2432coordinates_axes_init,fqv[22],fqv[124],fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F2064assoc_coordinates_axes,fqv[225]);
	local[0]= fqv[226];
	local[1]= fqv[227];
	ctx->vsp=local+2;
	w=(*ftab[25])(ctx,2,local+0,&ftab[25],fqv[228]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<26; i++) ftab[i]=fcallx;
}
