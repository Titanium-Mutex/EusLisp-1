/* ./compose.c :  entry=compose */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "compose.h"
#pragma init (register_compose)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___compose();
extern pointer build_quote_vector();
static int register_compose()
  { add_module_initializer("___compose", ___compose);}

static pointer F2443intersecting_edges();
static pointer F2444cut_body();
static pointer F2445insert_intersections();
static pointer F2446make_edge_segments();
static pointer F2447intersecting_segments();
static pointer F2448sort_edges_by_face();
static pointer F2449make_crossing_edges();
static pointer F2450add_alist();
static pointer F2451merge_segments();
static pointer F2452find_connecting_edge();
static pointer F2453construct_faces();
static pointer F2454initial_intersection_list();
static pointer F2455make_vertex_edge_htab();
static pointer F2456copy_add_vertex();
static pointer F2457find_colinear_int();
static pointer F2458contacting_faces();
static pointer F2459aligned_faces();
static pointer F2460find_equivalent_edge();
static pointer F2461unify_vertex();
static pointer F2462merge_edges_if_colinear();
static pointer F2463merge_contacting_faces();
static pointer F2464merge_aligned_faces();
static pointer F2465compose_body();
static pointer F2466set_original_face();
static pointer F2467body_();
static pointer F2468body_();
static pointer F2469body_();
static pointer F2470body_interference();
static pointer F2471body_();

/*intersecting-edges*/
static pointer F2443intersecting_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL2475:
	if (local[3]==NIL) goto WHX2476;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto IF2479;
	local[4]= makeflt(0.0000000000000000000000e+00);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(pointer)LSEQP(ctx,3,local+4); /*<=*/
	if (w==NIL) goto IF2479;
	local[4]= local[2];
	w = local[1];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	local[4]= local[0];
	goto IF2480;
IF2479:
	local[4]= NIL;
IF2480:
	goto WHL2475;
WHX2476:
	local[4]= NIL;
BLK2477:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2473:
	ctx->vsp=local; return(local[0]);}

/*cut-body*/
static pointer F2444cut_body(ctx,n,argv,env)
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
	local[7]= argv[1];
	local[8]= argv[0];
	local[9]= fqv[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F2443intersecting_edges(ctx,2,local+7); /*intersecting-edges*/
	local[1] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F2448sort_edges_by_face(ctx,1,local+7); /*sort-edges-by-face*/
	local[0] = w;
	local[7]= NIL;
	local[8]= local[0];
WHL2483:
	if (local[8]==NIL) goto WHX2484;
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
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[0])(ctx,1,local+9,&ftab[0],fqv[2]); /*oddp*/
	if (w==NIL) goto IF2487;
	local[9]= fqv[3];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF2488;
IF2487:
	local[9]= NIL;
IF2488:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	local[9]= local[5];
	local[10]= fqv[4];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= argv[1];
	local[11]= fqv[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+9); /*v**/
	local[3] = w;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,1,local+9,&ftab[1],fqv[5]); /*maxindex*/
	local[2] = w;
	local[9]= local[1];
	local[10]= local[3];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)AREF(ctx,2,local+10); /*aref*/
	local[10]= w;
	local[11]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+12;
	w=(pointer)GREATERP(ctx,2,local+10); /*>*/
	if (w==NIL) goto IF2489;
	local[10]= (pointer)get_sym_func(fqv[6]);
	goto IF2490;
IF2489:
	local[10]= (pointer)get_sym_func(fqv[7]);
IF2490:
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,CLO2491,env,argv,local);
	ctx->vsp=local+12;
	w=(pointer)SORT(ctx,3,local+9); /*sort*/
	local[1] = w;
WHL2492:
	if (local[1]==NIL) goto WHX2493;
	local[9]= loadglobal(fqv[8]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[9];
	local[12]= fqv[10];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= fqv[11];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[12];
	local[17]= argv[1];
	local[18]= fqv[13];
	local[19]= local[5];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,10,local+10); /*send*/
	w = local[9];
	local[9]= w;
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	goto WHL2492;
WHX2493:
	local[9]= NIL;
BLK2494:
	goto WHL2483;
WHX2484:
	local[9]= NIL;
BLK2485:
	w = NIL;
	local[7]= argv[1];
	w = local[4];
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)F2453construct_faces(ctx,1,local+7); /*construct-faces*/
	local[0]= w;
BLK2481:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2491(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= env->c.clo.env2[2];
	ctx->vsp=local+2;
	w=(pointer)AREF(ctx,2,local+0); /*aref*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*insert-intersections*/
static pointer F2445insert_intersections(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET2497,env,argv,local);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[1];
WHL2499:
	if (local[5]==NIL) goto WHX2500;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[14];
	local[8]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= fqv[15];
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF2503;
	local[6]= NIL;
	local[7]= argv[0];
WHL2506:
	if (local[7]==NIL) goto WHX2507;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[4];
	local[9]= fqv[0];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[1] = w;
	w = local[1];
	if (!iscons(w)) goto IF2510;
	local[8]= local[4];
	local[9]= fqv[16];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	if (w!=NIL) goto IF2510;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
WHL2512:
	if (local[3]==NIL) goto WHX2513;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,2,local+8,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2516;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[4];
	w = local[0];
	ctx->vsp=local+11;
	w=FLET2497(ctx,3,local+8,w);
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2514;
	goto CON2515;
CON2516:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto CON2517;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(*ftab[2])(ctx,2,local+8,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto IF2518;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= local[4];
	w = local[0];
	ctx->vsp=local+11;
	w=FLET2497(ctx,3,local+8,w);
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2514;
	goto IF2519;
IF2518:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
IF2519:
	goto CON2515;
CON2517:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)GREATERP(ctx,2,local+8); /*>*/
	if (w==NIL) goto CON2521;
	local[8]= local[3];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)RPLACD(ctx,2,local+8); /*rplacd*/
	local[8]= local[3];
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NCONC(ctx,2,local+9); /*nconc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)RPLACA(ctx,2,local+8); /*rplaca*/
	w = NIL;
	ctx->vsp=local+8;
	local[8]=w;
	goto BLK2514;
	goto CON2515;
CON2521:
	local[8]= NIL;
CON2515:
	goto WHL2512;
WHX2513:
	local[8]= NIL;
BLK2514:
	goto IF2511;
IF2510:
	local[8]= NIL;
IF2511:
	goto WHL2506;
WHX2507:
	local[8]= NIL;
BLK2508:
	w = argv[0];
	local[6]= w;
	goto IF2504;
IF2503:
	local[6]= NIL;
IF2504:
	goto WHL2499;
WHX2500:
	local[6]= NIL;
BLK2501:
	w = NIL;
	local[0]= w;
BLK2496:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET2497(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto IF2522;
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto IF2523;
IF2522:
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= makeflt((double)fabs(fltval(w)));
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[4];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VINNERPRODUCT(ctx,2,local+2); /*v.*/
	{ double left,right;
		right=fltval(makeflt((double)fabs(fltval(w)))); left=fltval(local[1]);
	if (left <= right) goto IF2524;}
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)RPLACA(ctx,2,local+1); /*rplaca*/
	local[1]= w;
	goto IF2525;
IF2524:
	local[1]= NIL;
IF2525:
	w = local[1];
	local[0]= w;
IF2523:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-edge-segments*/
static pointer F2446make_edge_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= argv[0];
WHL2528:
	if (local[10]==NIL) goto WHX2529;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[11];
	local[6] = w;
WHL2533:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2534;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[11];
	local[3] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[11]= makeflt(5.0000000000000000000000e-01);
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,4,local+11,&ftab[3],fqv[19]); /*midpoint*/
	local[11]= argv[1];
	local[12]= fqv[20];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[5] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.car;
	local[11]= local[5];
	if (argv[2]==local[11]) goto OR2539;
	local[11]= local[5];
	if (fqv[21]==local[11]) goto OR2539;
	goto IF2537;
OR2539:
	local[11]= loadglobal(fqv[8]);
	ctx->vsp=local+12;
	w=(pointer)INSTANTIATE(ctx,1,local+11); /*instantiate*/
	local[11]= w;
	local[12]= local[11];
	local[13]= fqv[9];
	local[14]= fqv[10];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[11];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	local[18]= fqv[12];
	local[19]= local[6]->c.obj.iv[3];
	local[20]= fqv[13];
	local[21]= local[6]->c.obj.iv[4];
	local[22]= fqv[22];
	local[23]= local[6]->c.obj.iv[6];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,12,local+12); /*send*/
	w = local[11];
	local[1] = w;
	local[11]= local[6];
	local[12]= local[1];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= local[5];
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,7,local+11); /*list*/
	local[11]= w;
	w = local[0];
	ctx->vsp=local+12;
	local[0] = cons(ctx,local[11],w);
	local[11]= local[0];
	goto IF2538;
IF2537:
	local[11]= NIL;
IF2538:
	goto WHL2533;
WHX2534:
	local[11]= NIL;
BLK2535:
	goto WHL2528;
WHX2529:
	local[11]= NIL;
BLK2530:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2526:
	ctx->vsp=local; return(local[0]);}

/*intersecting-segments*/
static pointer F2447intersecting_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2542,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK2541:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2542(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car!=NIL) goto OR2545;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[23]); /*fourth*/
	if (w!=NIL) goto OR2545;
	goto IF2543;
OR2545:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[24]); /*fifth*/
	local[0]= w;
	if (fqv[21]==local[0]) goto IF2543;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF2544;
IF2543:
	local[0]= NIL;
IF2544:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*sort-edges-by-face*/
static pointer F2448sort_edges_by_face(ctx,n,argv,env)
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
	local[5]= argv[0];
WHL2548:
	if (local[5]==NIL) goto WHX2549;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[6]= local[3]->c.obj.iv[3];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ASSQ(ctx,2,local+6); /*assq*/
	local[1] = w;
	if (local[1]!=NIL) goto IF2552;
	local[6]= local[3]->c.obj.iv[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	local[6]= local[0];
	goto IF2553;
IF2552:
	local[6]= local[1];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
IF2553:
	local[6]= local[3]->c.obj.iv[4];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ASSQ(ctx,2,local+6); /*assq*/
	local[1] = w;
	if (local[1]!=NIL) goto IF2554;
	local[6]= local[3]->c.obj.iv[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[0];
	ctx->vsp=local+7;
	local[0] = cons(ctx,local[6],w);
	local[6]= local[0];
	goto IF2555;
IF2554:
	local[6]= local[1];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NCONC(ctx,2,local+6); /*nconc*/
	local[6]= w;
IF2555:
	goto WHL2548;
WHX2549:
	local[6]= NIL;
BLK2550:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2546:
	ctx->vsp=local; return(local[0]);}

/*make-crossing-edges*/
static pointer F2449make_crossing_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
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
	local[17]= NIL;
	local[18]= argv[0];
WHL2558:
	if (local[18]==NIL) goto WHX2559;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	w = local[17];
	if (iscons(w)) goto IF2562;
	local[19]= fqv[25];
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(pointer)SIGERROR(ctx,2,local+19); /*error*/
	local[19]= w;
	goto IF2563;
IF2562:
	local[19]= NIL;
IF2563:
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	local[19]= local[0];
	local[20]= fqv[4];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[13] = w;
	local[1] = NIL;
	local[19]= NIL;
	local[20]= local[2];
WHL2565:
	if (local[20]==NIL) goto WHX2566;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w = local[19];
	if (iscons(w)) goto IF2569;
	local[21]= fqv[26];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)SIGERROR(ctx,2,local+21); /*error*/
	local[21]= w;
	goto IF2570;
IF2569:
	local[21]= NIL;
IF2570:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF2571;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto IF2571;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[1];
	goto IF2572;
IF2571:
	local[21]= NIL;
IF2572:
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	if (w==NIL) goto IF2573;
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	local[21]= w;
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto IF2573;
	local[21]= local[19];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[23]); /*fourth*/
	local[21]= w;
	w = local[1];
	ctx->vsp=local+22;
	local[1] = cons(ctx,local[21],w);
	local[21]= local[1];
	goto IF2574;
IF2573:
	local[21]= NIL;
IF2574:
	goto WHL2565;
WHX2566:
	local[21]= NIL;
BLK2567:
	w = NIL;
	local[19]= NIL;
	local[20]= local[1];
WHL2576:
	if (local[20]==NIL) goto WHX2577;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	local[9] = NIL;
	local[10] = NIL;
	local[21]= NIL;
	local[22]= local[2];
WHL2581:
	if (local[22]==NIL) goto WHX2582;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	if (local[19]!=local[23]) goto CON2586;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[7])(ctx,1,local+23,&ftab[7],fqv[28]); /*sixth*/
	local[23]= w;
	local[24]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2586;
	local[23]= local[4]->c.obj.iv[1];
	w = local[9];
	ctx->vsp=local+24;
	local[9] = cons(ctx,local[23],w);
	local[23]= local[9];
	goto CON2585;
CON2586:
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[4])(ctx,1,local+23,&ftab[4],fqv[23]); /*fourth*/
	local[23]= w;
	if (local[19]!=local[23]) goto CON2587;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[9])(ctx,1,local+23,&ftab[9],fqv[30]); /*seventh*/
	local[23]= w;
	local[24]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2587;
	local[23]= local[4]->c.obj.iv[2];
	w = local[9];
	ctx->vsp=local+24;
	local[9] = cons(ctx,local[23],w);
	local[23]= local[9];
	goto CON2585;
CON2587:
	local[23]= NIL;
CON2585:
	goto WHL2581;
WHX2582:
	local[23]= NIL;
BLK2583:
	w = NIL;
	local[21]= NIL;
	local[22]= local[19];
	local[23]= argv[1];
	ctx->vsp=local+24;
	w=(pointer)ASSQ(ctx,2,local+22); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
WHL2589:
	if (local[22]==NIL) goto WHX2590;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	if (local[0]!=local[23]) goto CON2594;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[7])(ctx,1,local+23,&ftab[7],fqv[28]); /*sixth*/
	local[23]= w;
	local[24]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2594;
	local[23]= local[4]->c.obj.iv[1];
	w = local[10];
	ctx->vsp=local+24;
	local[10] = cons(ctx,local[23],w);
	local[23]= local[10];
	goto CON2593;
CON2594:
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[4])(ctx,1,local+23,&ftab[4],fqv[23]); /*fourth*/
	local[23]= w;
	if (local[0]!=local[23]) goto CON2595;
	local[23]= local[21];
	ctx->vsp=local+24;
	w=(*ftab[9])(ctx,1,local+23,&ftab[9],fqv[30]); /*seventh*/
	local[23]= w;
	local[24]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+25;
	w=(*ftab[8])(ctx,2,local+23,&ftab[8],fqv[29]); /*eps<>*/
	if (w==NIL) goto CON2595;
	local[23]= local[4]->c.obj.iv[2];
	w = local[10];
	ctx->vsp=local+24;
	local[10] = cons(ctx,local[23],w);
	local[23]= local[10];
	goto CON2593;
CON2595:
	local[23]= NIL;
CON2593:
	goto WHL2589;
WHX2590:
	local[23]= NIL;
BLK2591:
	w = NIL;
	local[21]= *(ovafptr(local[19],fqv[31]));
	local[22]= *(ovafptr(local[0],fqv[31]));
	ctx->vsp=local+23;
	w=(pointer)VCROSSPRODUCT(ctx,2,local+21); /*v**/
	local[5] = w;
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[1])(ctx,1,local+21,&ftab[1],fqv[5]); /*maxindex*/
	local[6] = w;
	local[21]= argv[3];
	if (fqv[32]!=local[21]) goto IF2596;
	local[21]= local[5];
	local[22]= local[6];
	ctx->vsp=local+23;
	w=(pointer)AREF(ctx,2,local+21); /*aref*/
	local[21]= w;
	local[22]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,2,local+21); /*<*/
	if (w==NIL) goto IF2598;
	local[21]= (pointer)get_sym_func(fqv[33]);
	goto IF2599;
IF2598:
	local[21]= (pointer)get_sym_func(fqv[34]);
IF2599:
	goto IF2597;
IF2596:
	local[21]= local[5];
	local[22]= local[6];
	ctx->vsp=local+23;
	w=(pointer)AREF(ctx,2,local+21); /*aref*/
	local[21]= w;
	local[22]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+23;
	w=(pointer)LESSP(ctx,2,local+21); /*<*/
	if (w==NIL) goto IF2600;
	local[21]= (pointer)get_sym_func(fqv[34]);
	goto IF2601;
IF2600:
	local[21]= (pointer)get_sym_func(fqv[33]);
IF2601:
IF2597:
	local[7] = local[21];
	local[21]= local[9];
	local[22]= local[10];
	ctx->vsp=local+23;
	w=(pointer)APPEND(ctx,2,local+21); /*append*/
	local[21]= w;
	local[22]= local[7];
	ctx->vsp=local+23;
	local[23]= makeclosure(codevec,quotevec,CLO2602,env,argv,local);
	ctx->vsp=local+24;
	w=(pointer)SORT(ctx,3,local+21); /*sort*/
	local[8] = w;
	local[21]= local[8];
	local[22]= fqv[35];
	local[23]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+24;
	w=(*ftab[10])(ctx,3,local+21,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[8] = w;
	local[14] = NIL;
WHL2603:
	if (local[8]==NIL) goto WHX2604;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[21];
	local[11] = w;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[21];
	local[12] = w;
	if (local[11]==NIL) goto IF2608;
	if (local[12]==NIL) goto IF2608;
	local[21]= local[0];
	local[22]= fqv[38];
	local[23]= makeflt(5.0000000000000000000000e-01);
	local[24]= local[11];
	local[25]= local[12];
	ctx->vsp=local+26;
	w=(*ftab[3])(ctx,3,local+23,&ftab[3],fqv[19]); /*midpoint*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	if (w!=NIL) goto IF2608;
	local[21]= local[19];
	local[22]= fqv[38];
	local[23]= makeflt(5.0000000000000000000000e-01);
	local[24]= local[11];
	local[25]= local[12];
	ctx->vsp=local+26;
	w=(*ftab[3])(ctx,3,local+23,&ftab[3],fqv[19]); /*midpoint*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	if (w!=NIL) goto IF2608;
	if (argv[2]!=NIL) goto OR2610;
	local[21]= local[11];
	w = local[9];
	if (memq(local[21],w)==NIL) goto AND2611;
	local[21]= local[12];
	w = local[9];
	if (memq(local[21],w)==NIL) goto AND2611;
	goto OR2610;
AND2611:
	goto IF2608;
OR2610:
	local[21]= loadglobal(fqv[8]);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,1,local+21); /*instantiate*/
	local[21]= w;
	local[22]= local[21];
	local[23]= fqv[9];
	local[24]= fqv[10];
	local[25]= local[11];
	local[26]= fqv[11];
	local[27]= local[12];
	local[28]= fqv[12];
	local[29]= local[0];
	local[30]= fqv[13];
	local[31]= local[19];
	local[32]= fqv[39];
	local[33]= NIL;
	ctx->vsp=local+34;
	w=(pointer)SEND(ctx,12,local+22); /*send*/
	w = local[21];
	local[4] = w;
	local[21]= local[4];
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto IF2609;
IF2608:
	local[21]= NIL;
IF2609:
	goto WHL2603;
WHX2604:
	local[21]= NIL;
BLK2605:
	if (local[14]==NIL) goto IF2613;
	local[21]= local[0];
	w = local[14];
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	w = local[15];
	ctx->vsp=local+22;
	local[15] = cons(ctx,local[21],w);
	local[21]= local[19];
	local[22]= local[14];
	ctx->vsp=local+23;
	w=(pointer)COPYSEQ(ctx,1,local+22); /*copy-seq*/
	ctx->vsp=local+22;
	local[21]= cons(ctx,local[21],w);
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	goto IF2614;
IF2613:
	local[21]= NIL;
IF2614:
	goto WHL2576;
WHX2577:
	local[21]= NIL;
BLK2578:
	w = NIL;
	goto WHL2558;
WHX2559:
	local[19]= NIL;
BLK2560:
	w = NIL;
	local[17]= local[15];
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,2,local+17); /*list*/
	local[0]= w;
BLK2556:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2602(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[6];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*add-alist*/
static pointer F2450add_alist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]!=NIL) goto IF2616;
	local[1]= argv[0];
	local[2]= argv[1];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,3,local+1,&ftab[11],fqv[40]); /*acons*/
	local[1]= w;
	goto IF2617;
IF2616:
	local[1]= local[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	local[1]= argv[2];
IF2617:
	w = local[1];
	local[0]= w;
BLK2615:
	ctx->vsp=local; return(local[0]);}

/*merge-segments*/
static pointer F2451merge_segments(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
WHL2620:
	if (local[1]==NIL) goto WHX2621;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= (pointer)get_sym_func(fqv[41]);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)RPLACD(ctx,2,local+2); /*rplacd*/
	goto WHL2620;
WHX2621:
	local[2]= NIL;
BLK2622:
	w = NIL;
	local[0]= NIL;
	local[1]= argv[1];
WHL2625:
	if (local[1]==NIL) goto WHX2626;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F2450add_alist(ctx,3,local+2); /*add-alist*/
	argv[0] = w;
	goto WHL2625;
WHX2626:
	local[2]= NIL;
BLK2627:
	w = NIL;
	local[0]= NIL;
	local[1]= argv[2];
WHL2630:
	if (local[1]==NIL) goto WHX2631;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F2450add_alist(ctx,3,local+2); /*add-alist*/
	argv[0] = w;
	goto WHL2630;
WHX2631:
	local[2]= NIL;
BLK2632:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK2618:
	ctx->vsp=local; return(local[0]);}

/*find-connecting-edge*/
static pointer F2452find_connecting_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2636;}
	local[0]= (pointer)get_sym_func(fqv[42]);
ENT2636:
ENT2635:
	if (n>3) maerror();
	local[1]= local[0];
	if ((pointer)get_sym_func(fqv[42])!=local[1]) goto IF2637;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2639,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[43]); /*find-if*/
	local[1]= w;
	goto IF2638;
IF2637:
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2640,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(*ftab[12])(ctx,2,local+1,&ftab[12],fqv[43]); /*find-if*/
	local[1]= w;
IF2638:
	w = local[1];
	local[0]= w;
BLK2634:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2639(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((env->c.clo.env1[0])==(local[0])?T:NIL);
	if (local[0]!=NIL) goto OR2641;
	local[0]= argv[0]->c.obj.iv[2];
	local[0]= ((env->c.clo.env1[0])==(local[0])?T:NIL);
OR2641:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2640(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= env->c.clo.env1[0];
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,3,local+0); /*funcall*/
	local[0]= w;
	if (w!=NIL) goto OR2642;
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
OR2642:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*construct-faces*/
static pointer F2453construct_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	storeglobal(fqv[44],w);
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2644:
	if (local[4]==NIL) goto WHX2645;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[10];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	local[8]= NIL;
	local[9]= NIL;
	local[10]= loadglobal(fqv[45]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= NIL;
WHL2648:
	if (local[5]==NIL) goto WHX2649;
	local[12]= local[5];
	local[13]= fqv[11];
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[8] = w;
	local[12]= local[5];
	local[13]= fqv[46];
	local[14]= local[7];
	local[15]= local[8];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,5,local+12); /*send*/
	local[12]= local[5];
	w = local[9];
	ctx->vsp=local+13;
	local[9] = cons(ctx,local[12],w);
	local[12]= local[5];
	local[13]= local[4];
	local[14]= fqv[47];
	local[15]= makeint((eusinteger_t)1L);
	ctx->vsp=local+16;
	w=(*ftab[13])(ctx,4,local+12,&ftab[13],fqv[48]); /*delete*/
	local[4] = w;
	local[12]= local[8];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)F2452find_connecting_edge(ctx,2,local+12); /*find-connecting-edge*/
	local[5] = w;
	local[7] = local[8];
	goto WHL2648;
WHX2649:
	local[12]= NIL;
BLK2650:
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)NREVERSE(ctx,1,local+12); /*nreverse*/
	local[9] = w;
	local[12]= local[3];
	local[13]= fqv[49];
	ctx->vsp=local+14;
	w=(*ftab[14])(ctx,2,local+12,&ftab[14],fqv[50]); /*find-method*/
	if (w==NIL) goto IF2651;
	local[12]= local[3];
	local[13]= fqv[49];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[11] = w;
	local[12]= local[11];
	goto IF2652;
IF2651:
	local[12]= NIL;
IF2652:
	local[12]= local[10];
	local[13]= fqv[9];
	local[14]= fqv[1];
	local[15]= local[9];
	local[16]= fqv[49];
	local[17]= local[11];
	local[18]= fqv[51];
	if (local[11]==NIL) goto IF2653;
	local[19]= local[11];
	local[20]= fqv[51];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	goto IF2654;
IF2653:
	local[19]= NIL;
IF2654:
	local[20]= fqv[52];
	local[21]= local[3];
	local[22]= fqv[52];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,10,local+12); /*send*/
	local[12]= local[3];
	local[13]= fqv[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,2,local+12); /*send*/
	local[12]= w;
	local[13]= local[10];
	local[14]= fqv[4];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,2,local+13); /*send*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)VINNERPRODUCT(ctx,2,local+12); /*v.*/
	local[12]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[12]);
	if (left >= right) goto CON2656;}
	local[12]= local[10];
	w = local[9];
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	w = local[1];
	ctx->vsp=local+13;
	local[1] = cons(ctx,local[12],w);
	local[12]= local[1];
	goto CON2655;
CON2656:
	local[12]= local[10];
	w = local[0];
	ctx->vsp=local+13;
	local[0] = cons(ctx,local[12],w);
	local[12]= local[0];
	goto CON2655;
CON2657:
	local[12]= NIL;
CON2655:
	w = local[12];
	goto WHL2644;
WHX2645:
	local[5]= NIL;
BLK2646:
	if (local[1]==NIL) goto IF2658;
	if (loadglobal(fqv[53])==NIL) goto IF2660;
	local[5]= T;
	local[6]= fqv[54];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,4,local+5); /*format*/
	local[5]= w;
	goto IF2661;
IF2660:
	local[5]= NIL;
IF2661:
	local[5]= NIL;
	local[6]= local[1];
WHL2663:
	if (local[6]==NIL) goto WHX2664;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= NIL;
	local[8]= local[0];
WHL2669:
	if (local[8]==NIL) goto WHX2670;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[20];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= *(ovafptr((w)->c.cons.car,fqv[55]));
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	if (fqv[56]!=local[9]) goto IF2673;
	local[9]= NIL;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
WHL2676:
	if (local[10]==NIL) goto WHX2677;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[9];
	local[12]= fqv[46];
	local[13]= local[9];
	local[14]= fqv[10];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	local[14]= local[9];
	local[15]= fqv[11];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,5,local+11); /*send*/
	goto WHL2676;
WHX2677:
	local[11]= NIL;
BLK2678:
	w = NIL;
	local[9]= loadglobal(fqv[57]);
	ctx->vsp=local+10;
	w=(pointer)INSTANTIATE(ctx,1,local+9); /*instantiate*/
	local[9]= w;
	local[10]= local[9];
	local[11]= fqv[9];
	local[12]= fqv[1];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	local[14]= fqv[58];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,6,local+10); /*send*/
	w = local[9];
	local[2] = w;
	local[9]= local[7];
	local[10]= fqv[59];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	w = NIL;
	ctx->vsp=local+9;
	local[7]=w;
	goto BLK2667;
	goto IF2674;
IF2673:
	local[9]= NIL;
IF2674:
	goto WHL2669;
WHX2670:
	local[9]= NIL;
BLK2671:
	w = NIL;
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	storeglobal(fqv[60],w);
	local[7]= fqv[61];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
BLK2667:
	goto WHL2663;
WHX2664:
	local[7]= NIL;
BLK2665:
	w = NIL;
	local[5]= w;
	goto IF2659;
IF2658:
	local[5]= NIL;
IF2659:
	w = local[0];
	local[0]= w;
BLK2643:
	ctx->vsp=local; return(local[0]);}

/*initial-intersection-list*/
static pointer F2454initial_intersection_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
WHL2683:
	if (local[3]==NIL) goto WHX2684;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	local[5]= makeflt(0.0000000000000000000000e+00);
	local[6]= local[2]->c.obj.iv[1];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,2,local+6,&ftab[15],fqv[62]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	local[6]= makeflt(1.0000000000000000000000e+00);
	local[7]= local[2]->c.obj.iv[2];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(*ftab[15])(ctx,2,local+7,&ftab[15],fqv[62]); /*gethash*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL2683;
WHX2684:
	local[4]= NIL;
BLK2685:
	w = local[1];
	local[0]= w;
BLK2681:
	ctx->vsp=local; return(local[0]);}

/*make-vertex-edge-htab*/
static pointer F2455make_vertex_edge_htab(ctx,n,argv,env)
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
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[16])(ctx,1,local+5,&ftab[16],fqv[63]); /*bodyp*/
	if (w==NIL) goto CON2689;
	local[1] = argv[0]->c.obj.iv[11];
	local[0] = argv[0]->c.obj.iv[10];
	local[5]= local[0];
	goto CON2688;
CON2689:
	local[5]= (pointer)get_sym_func(fqv[64]);
	local[6]= argv[0];
	local[7]= fqv[65];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[66]); /*send-all*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[1] = w;
	local[5]= (pointer)get_sym_func(fqv[64]);
	local[6]= argv[0];
	local[7]= fqv[67];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[66]); /*send-all*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[10])(ctx,1,local+5,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[0] = w;
	local[5]= local[0];
	goto CON2688;
CON2690:
	local[5]= NIL;
CON2688:
	local[5]= fqv[68];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	{ eusinteger_t i,j;
		j=intval(w); i=intval(local[6]);
		local[6]=(makeint(i * j));}
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[18])(ctx,2,local+5,&ftab[18],fqv[69]); /*make-hash-table*/
	local[2] = w;
	local[5]= NIL;
	local[6]= local[0];
WHL2692:
	if (local[6]==NIL) goto WHX2693;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[3] = local[5]->c.obj.iv[1];
	local[4] = local[5]->c.obj.iv[2];
	local[7]= local[3];
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[3];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[62]); /*gethash*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[70]); /*sethash*/
	local[7]= local[4];
	local[8]= local[2];
	local[9]= local[5];
	local[10]= local[4];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(*ftab[15])(ctx,2,local+10,&ftab[15],fqv[62]); /*gethash*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(*ftab[19])(ctx,3,local+7,&ftab[19],fqv[70]); /*sethash*/
	goto WHL2692;
WHX2693:
	local[7]= NIL;
BLK2694:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK2687:
	ctx->vsp=local; return(local[0]);}

/*copy-add-vertex*/
static pointer F2456copy_add_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO2697,env,argv,local);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[71]); /*maphash*/
	local[0]= w;
BLK2696:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2697(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	w = argv[1];
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(*ftab[19])(ctx,3,local+0,&ftab[19],fqv[70]); /*sethash*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*find-colinear-int*/
static pointer F2457find_colinear_int(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
WHL2700:
	if (local[2]==NIL) goto WHX2701;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2705:
	if (local[4]==NIL) goto WHX2706;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[72];
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto IF2709;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,2,local+5); /*list**/
	local[5]= w;
	w = local[0];
	ctx->vsp=local+6;
	local[0] = cons(ctx,local[5],w);
	local[5]= local[0];
	goto IF2710;
IF2709:
	local[5]= NIL;
IF2710:
	goto WHL2705;
WHX2706:
	local[5]= NIL;
BLK2707:
	w = NIL;
	goto WHL2700;
WHX2701:
	local[3]= NIL;
BLK2702:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK2698:
	ctx->vsp=local; return(local[0]);}

/*contacting-faces*/
static pointer F2458contacting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= loadglobal(fqv[73]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF2712;
	local[0] = argv[0]->c.obj.iv[9];
	local[8]= local[0];
	goto IF2713;
IF2712:
	local[8]= NIL;
IF2713:
	local[8]= argv[1];
	local[9]= loadglobal(fqv[73]);
	ctx->vsp=local+10;
	w=(pointer)DERIVEDP(ctx,2,local+8); /*derivedp*/
	if (w==NIL) goto IF2714;
	local[1] = argv[1]->c.obj.iv[9];
	local[8]= local[1];
	goto IF2715;
IF2714:
	local[8]= NIL;
IF2715:
	local[8]= NIL;
	local[9]= local[0];
WHL2717:
	if (local[9]==NIL) goto WHX2718;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= NIL;
	local[11]= local[1];
WHL2722:
	if (local[11]==NIL) goto WHX2723;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[8];
	local[13]= fqv[74];
	local[14]= local[10];
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto IF2726;
	local[12]= (pointer)get_sym_func(fqv[75]);
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[6] = w;
	local[12]= (pointer)get_sym_func(fqv[75]);
	local[13]= (pointer)get_sym_func(fqv[64]);
	local[14]= (pointer)get_sym_func(fqv[76]);
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)MAPCAR(ctx,2,local+14); /*mapcar*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)APPLY(ctx,2,local+13); /*apply*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)MAPCAR(ctx,2,local+12); /*mapcar*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(*ftab[10])(ctx,1,local+12,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[7] = w;
	local[12]= local[2];
	w = fqv[77];
	if (memq(local[12],w)==NIL) goto CON2729;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,3,local+12); /*list*/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2728;
CON2729:
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint((eusinteger_t)1L)==local[12]) goto OR2731;
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint((eusinteger_t)1L)==local[12]) goto OR2731;
	goto CON2730;
OR2731:
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)F2457find_colinear_int(ctx,1,local+12); /*find-colinear-int*/
	local[4] = w;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)LENGTH(ctx,1,local+12); /*length*/
	local[12]= w;
	if (makeint((eusinteger_t)1L)!=local[12]) goto IF2732;
	local[12]= T;
	local[13]= fqv[78];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,2,local+12); /*format*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.car;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[23]); /*fourth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2735;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[4])(ctx,1,local+12,&ftab[4],fqv[23]); /*fourth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2735;
	local[12]= local[10];
	local[13]= fqv[20];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[79];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[56];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w==NIL) goto CON2735;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2734;
CON2735:
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,1,local+12,&ftab[5],fqv[24]); /*fifth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2736;
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[5])(ctx,1,local+12,&ftab[5],fqv[24]); /*fifth*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	local[13]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+14;
	w=(*ftab[2])(ctx,2,local+12,&ftab[2],fqv[17]); /*eps=*/
	if (w==NIL) goto CON2736;
	local[12]= local[8];
	local[13]= fqv[20];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	local[15]= fqv[79];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	local[13]= fqv[56];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w==NIL) goto CON2736;
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2734;
CON2736:
	local[12]= NIL;
CON2734:
	goto IF2733;
IF2732:
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
IF2733:
	goto CON2728;
CON2730:
	local[12]= local[8];
	local[13]= local[10];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST_STAR(ctx,3,local+12); /*list**/
	local[12]= w;
	w = local[5];
	ctx->vsp=local+13;
	local[5] = cons(ctx,local[12],w);
	local[12]= local[5];
	goto CON2728;
CON2737:
	local[12]= NIL;
CON2728:
	goto IF2727;
IF2726:
	local[12]= NIL;
IF2727:
	goto WHL2722;
WHX2723:
	local[12]= NIL;
BLK2724:
	w = NIL;
	goto WHL2717;
WHX2718:
	local[10]= NIL;
BLK2719:
	w = NIL;
	w = local[5];
	local[0]= w;
BLK2711:
	ctx->vsp=local; return(local[0]);}

/*aligned-faces*/
static pointer F2459aligned_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[0];
	local[8]= loadglobal(fqv[73]);
	ctx->vsp=local+9;
	w=(pointer)DERIVEDP(ctx,2,local+7); /*derivedp*/
	if (w==NIL) goto IF2739;
	local[0] = argv[0]->c.obj.iv[9];
	local[7]= local[0];
	goto IF2740;
IF2739:
	local[7]= NIL;
IF2740:
	local[7]= argv[1];
	local[8]= loadglobal(fqv[73]);
	ctx->vsp=local+9;
	w=(pointer)DERIVEDP(ctx,2,local+7); /*derivedp*/
	if (w==NIL) goto IF2741;
	local[1] = argv[1]->c.obj.iv[9];
	local[7]= local[1];
	goto IF2742;
IF2741:
	local[7]= NIL;
IF2742:
	local[7]= NIL;
	local[8]= local[0];
WHL2744:
	if (local[8]==NIL) goto WHX2745;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= NIL;
	local[10]= local[1];
WHL2749:
	if (local[10]==NIL) goto WHX2750;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[11];
	local[9] = w;
	local[11]= local[7];
	local[12]= fqv[80];
	local[13]= local[9];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[2] = w;
	if (local[2]==NIL) goto IF2753;
	local[11]= local[7];
	local[12]= local[9];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,2,local+11); /*list*/
	local[11]= w;
	w = local[4];
	ctx->vsp=local+12;
	local[4] = cons(ctx,local[11],w);
	local[11]= local[4];
	goto IF2754;
IF2753:
	local[11]= NIL;
IF2754:
	goto WHL2749;
WHX2750:
	local[11]= NIL;
BLK2751:
	w = NIL;
	goto WHL2744;
WHX2745:
	local[9]= NIL;
BLK2746:
	w = NIL;
	w = local[4];
	local[0]= w;
BLK2738:
	ctx->vsp=local; return(local[0]);}

/*find-equivalent-edge*/
static pointer F2460find_equivalent_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL2757:
	if (local[1]==NIL) goto WHX2758;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2764;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2764;
	goto OR2763;
AND2764:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2765;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[21])(ctx,2,local+2,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto AND2765;
	goto OR2763;
AND2765:
	goto IF2761;
OR2763:
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK2755;
	goto IF2762;
IF2761:
	local[2]= NIL;
IF2762:
	goto WHL2757;
WHX2758:
	local[2]= NIL;
BLK2759:
	w = NIL;
	local[0]= w;
BLK2755:
	ctx->vsp=local; return(local[0]);}

/*unify-vertex*/
static pointer F2461unify_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[64]);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO2767,env,argv,local);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	local[1]= fqv[35];
	local[2]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,3,local+0,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[0];
WHL2769:
	if (local[2]==NIL) goto WHX2770;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1]->c.obj.iv[1];
	local[4]= local[0];
	local[5]= fqv[35];
	local[6]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,4,local+3,&ftab[6],fqv[27]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[1] = local[4];
	local[3]= local[1]->c.obj.iv[2];
	local[4]= local[0];
	local[5]= fqv[35];
	local[6]= (pointer)get_sym_func(fqv[36]);
	ctx->vsp=local+7;
	w=(*ftab[6])(ctx,4,local+3,&ftab[6],fqv[27]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[2] = local[4];
	goto WHL2769;
WHX2770:
	local[3]= NIL;
BLK2771:
	w = NIL;
	local[0]= w;
BLK2766:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2767(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*merge-edges-if-colinear*/
static pointer F2462merge_edges_if_colinear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[0]==NIL) goto IF2774;
	if (argv[1]==NIL) goto IF2774;
	local[0]= argv[0];
	local[1]= fqv[82];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF2774;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2777;
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[1] = local[1];
	goto CON2776;
CON2777:
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2778;
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[2] = local[1];
	goto CON2776;
CON2778:
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2779;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[1] = local[1];
	goto CON2776;
CON2779:
	local[0]= argv[1]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,2,local+0,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2780;
	local[0]= argv[1]->c.obj.iv[1];
	local[1]= local[0];
	w = argv[0];
	w->c.obj.iv[2] = local[1];
	goto CON2776;
CON2780:
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK2773;
	goto CON2776;
CON2781:
	local[0]= NIL;
CON2776:
	local[0]= NIL;
	local[1]= argv[3];
WHL2783:
	if (local[1]==NIL) goto WHX2784;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[13])(ctx,2,local+2,&ftab[13],fqv[48]); /*delete*/
	goto WHL2783;
WHX2784:
	local[2]= NIL;
BLK2785:
	w = NIL;
	local[0]= argv[1];
	goto IF2775;
IF2774:
	local[0]= NIL;
IF2775:
	w = local[0];
	local[0]= w;
BLK2773:
	ctx->vsp=local; return(local[0]);}

/*merge-contacting-faces*/
static pointer F2463merge_contacting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[83]); /*assoc*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[83]); /*assoc*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL2789:
	if (local[9]==NIL) goto WHX2790;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)F2460find_equivalent_edge(ctx,2,local+10); /*find-equivalent-edge*/
	local[2] = w;
	if (local[2]==NIL) goto CON2794;
	local[10]= local[2];
	local[11]= fqv[84];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	local[10]= local[8];
	local[11]= fqv[84];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= local[3];
	local[11]= fqv[4];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	local[11]= local[4];
	local[12]= fqv[4];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[21])(ctx,2,local+10,&ftab[21],fqv[36]); /*eps-v=*/
	if (w==NIL) goto CON2796;
	local[10]= local[3];
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[5] = w;
	local[10]= local[4];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[6] = w;
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8];
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[8]->c.obj.iv[1];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)F2452find_connecting_edge(ctx,2,local+10); /*find-connecting-edge*/
	local[10]= w;
	local[11]= local[8]->c.obj.iv[2];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.cdr;
	ctx->vsp=local+13;
	w=(pointer)F2452find_connecting_edge(ctx,2,local+11); /*find-connecting-edge*/
	local[11]= w;
	local[12]= local[2]->c.obj.iv[1];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	ctx->vsp=local+14;
	w=(pointer)F2452find_connecting_edge(ctx,2,local+12); /*find-connecting-edge*/
	local[12]= w;
	local[13]= local[2]->c.obj.iv[2];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.cdr;
	ctx->vsp=local+15;
	w=(pointer)F2452find_connecting_edge(ctx,2,local+13); /*find-connecting-edge*/
	local[13]= w;
	local[14]= local[12];
	local[15]= local[10];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2462merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[12];
	local[15]= local[11];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2462merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[13];
	local[15]= local[10];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2462merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[14]= local[13];
	local[15]= local[11];
	local[16]= argv[2];
	local[17]= argv[3];
	ctx->vsp=local+18;
	w=(pointer)F2462merge_edges_if_colinear(ctx,4,local+14); /*merge-edges-if-colinear*/
	local[10]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
WHL2798:
	if (local[11]==NIL) goto WHX2799;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= local[10]->c.obj.iv[3];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w!=NIL) goto OR2804;
	local[12]= local[10]->c.obj.iv[4];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)EQ(ctx,2,local+12); /*eql*/
	if (w!=NIL) goto OR2804;
	goto IF2802;
OR2804:
	local[12]= local[10];
	local[13]= fqv[85];
	local[14]= local[4];
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,4,local+12); /*send*/
	local[12]= w;
	goto IF2803;
IF2802:
	local[12]= NIL;
IF2803:
	goto WHL2798;
WHX2799:
	local[12]= NIL;
BLK2800:
	w = NIL;
	local[10]= local[5];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[6];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	argv[3] = w;
	local[10]= local[5];
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto CON2795;
CON2796:
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[2];
	local[11]= fqv[85];
	local[12]= argv[0];
	local[13]= local[4];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	goto CON2795;
CON2805:
	local[10]= NIL;
CON2795:
	goto CON2793;
CON2794:
	local[10]= argv[0];
	local[11]= fqv[20];
	local[12]= local[8];
	local[13]= fqv[86];
	local[14]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[32];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	local[10]= w;
	if (w!=NIL) goto CON2793;
CON2806:
	local[10]= local[8];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[27]); /*member*/
	if (w!=NIL) goto CON2807;
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[0];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[8];
	local[11]= fqv[85];
	local[12]= argv[1];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= w;
	goto CON2793;
CON2807:
	local[10]= fqv[87];
	local[11]= argv[0];
	local[12]= local[8];
	ctx->vsp=local+13;
	w=(*ftab[23])(ctx,3,local+10,&ftab[23],fqv[88]); /*warn*/
	local[10]= w;
	goto CON2793;
CON2808:
	local[10]= NIL;
CON2793:
	goto WHL2789;
WHX2790:
	local[10]= NIL;
BLK2791:
	w = NIL;
	local[8]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
WHL2810:
	if (local[9]==NIL) goto WHX2811;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= argv[1];
	local[11]= fqv[20];
	local[12]= local[8];
	local[13]= fqv[86];
	local[14]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,3,local+12); /*send*/
	local[12]= w;
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= fqv[56];
	ctx->vsp=local+12;
	w=(pointer)EQ(ctx,2,local+10); /*eql*/
	if (w==NIL) goto CON2815;
	local[10]= local[8];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	local[10]= local[1];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)NCONC(ctx,2,local+10); /*nconc*/
	local[10]= local[8];
	local[11]= fqv[85];
	local[12]= argv[0];
	local[13]= argv[1];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,4,local+10); /*send*/
	local[10]= local[8];
	local[11]= fqv[84];
	local[12]= argv[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	local[11]= argv[2];
	ctx->vsp=local+12;
	w=(*ftab[22])(ctx,2,local+10,&ftab[22],fqv[83]); /*assoc*/
	local[10]= w;
	w = local[7];
	ctx->vsp=local+11;
	local[7] = cons(ctx,local[10],w);
	local[10]= local[7];
	goto CON2814;
CON2815:
	local[10]= NIL;
CON2814:
	goto WHL2810;
WHX2811:
	local[10]= NIL;
BLK2812:
	w = NIL;
	local[8]= (pointer)get_sym_func(fqv[64]);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	local[11]= (pointer)get_sym_func(fqv[76]);
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)MAPCAR(ctx,2,local+11); /*mapcar*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,4,local+8); /*apply*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F2461unify_vertex(ctx,1,local+8); /*unify-vertex*/
	w = argv[3];
	local[0]= w;
BLK2787:
	ctx->vsp=local; return(local[0]);}

/*merge-aligned-faces*/
static pointer F2464merge_aligned_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,2,local+0,&ftab[22],fqv[83]); /*assoc*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,2,local+1,&ftab[22],fqv[83]); /*assoc*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	storeglobal(fqv[89],local[0]);
	local[6]= local[1];
	storeglobal(fqv[90],local[6]);
	if (loadglobal(fqv[53])==NIL) goto IF2817;
	local[6]= fqv[91];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,1,local+6,&ftab[24],fqv[92]); /*break*/
	local[6]= w;
	goto IF2818;
IF2817:
	local[6]= NIL;
IF2818:
	local[6]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2820:
	if (local[7]==NIL) goto WHX2821;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)F2460find_equivalent_edge(ctx,2,local+8); /*find-equivalent-edge*/
	local[2] = w;
	if (local[2]==NIL) goto CON2825;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2824;
CON2825:
	local[8]= argv[0];
	local[9]= fqv[20];
	local[10]= local[6];
	local[11]= fqv[86];
	local[12]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[56];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2826;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2824;
CON2826:
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[0];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,2,local+8); /*nconc*/
	local[8]= local[6];
	local[9]= fqv[85];
	local[10]= argv[1];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	goto CON2824;
CON2827:
	local[8]= NIL;
CON2824:
	goto WHL2820;
WHX2821:
	local[8]= NIL;
BLK2822:
	w = NIL;
	local[6]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2829:
	if (local[7]==NIL) goto WHX2830;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[1];
	local[9]= fqv[20];
	local[10]= local[6];
	local[11]= fqv[86];
	local[12]= makeflt(5.0000000000000000000000e-01);
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[8]= w;
	local[9]= fqv[56];
	ctx->vsp=local+10;
	w=(pointer)EQ(ctx,2,local+8); /*eql*/
	if (w==NIL) goto CON2834;
	local[8]= local[6];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= local[6];
	local[9]= local[6];
	local[10]= fqv[84];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	local[9]= w;
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[22])(ctx,2,local+9,&ftab[22],fqv[83]); /*assoc*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[8]= w;
	goto CON2833;
CON2834:
	local[8]= NIL;
CON2833:
	goto WHL2829;
WHX2830:
	local[8]= NIL;
BLK2831:
	w = NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF2835;
	local[6]= fqv[93];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF2836;
IF2835:
	local[6]= NIL;
IF2836:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[4] = local[3];
WHL2837:
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2838;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[6];
	local[2] = w;
	local[6]= NIL;
	local[7]= NIL;
TAG2842:
	local[7] = local[3];
TAG2843:
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	if (local[6]!=NIL) goto CON2846;
	w = NIL;
	ctx->vsp=local+8;
	local[6]=w;
	goto BLK2841;
	goto CON2845;
CON2846:
	local[8]= local[2];
	local[9]= local[6];
	local[10]= argv[2];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(pointer)F2462merge_edges_if_colinear(ctx,4,local+8); /*merge-edges-if-colinear*/
	if (w==NIL) goto CON2847;
	local[8]= local[6];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[13])(ctx,2,local+8,&ftab[13],fqv[48]); /*delete*/
	local[3] = w;
	local[8]= NIL;
	local[9]= argv[2];
WHL2849:
	if (local[9]==NIL) goto WHX2850;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[6];
	local[11]= local[8];
	ctx->vsp=local+12;
	w=(*ftab[13])(ctx,2,local+10,&ftab[13],fqv[48]); /*delete*/
	goto WHL2849;
WHX2850:
	local[10]= NIL;
BLK2851:
	w = NIL;
	ctx->vsp=local+8;
	goto TAG2842;
	goto CON2845;
CON2847:
	ctx->vsp=local+8;
	goto TAG2843;
	goto CON2845;
CON2853:
	local[8]= NIL;
CON2845:
	w = NIL;
	local[6]= w;
BLK2841:
	goto WHL2837;
WHX2838:
	local[6]= NIL;
BLK2839:
	local[6]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
WHL2855:
	if (local[7]==NIL) goto WHX2856;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[84];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[4] = w;
	local[8]= local[4];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[22])(ctx,2,local+8,&ftab[22],fqv[83]); /*assoc*/
	local[4] = w;
	if (local[4]==NIL) goto IF2859;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2860;
IF2859:
	local[8]= local[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(*ftab[22])(ctx,2,local+8,&ftab[22],fqv[83]); /*assoc*/
	local[4] = w;
	if (local[4]==NIL) goto IF2861;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[5];
	ctx->vsp=local+9;
	local[5] = cons(ctx,local[8],w);
	local[8]= local[5];
	goto IF2862;
IF2861:
	local[8]= NIL;
IF2862:
IF2860:
	goto WHL2855;
WHX2856:
	local[8]= NIL;
BLK2857:
	w = NIL;
	local[6]= (pointer)get_sym_func(fqv[64]);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,1,local+6,&ftab[10],fqv[37]); /*remove-duplicates*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F2461unify_vertex(ctx,1,local+6); /*unify-vertex*/
	if (loadglobal(fqv[53])==NIL) goto IF2863;
	local[6]= fqv[94];
	ctx->vsp=local+7;
	w=(*ftab[24])(ctx,1,local+6,&ftab[24],fqv[92]); /*break*/
	local[6]= w;
	goto IF2864;
IF2863:
	local[6]= NIL;
IF2864:
	w = local[6];
	w = argv[3];
	local[0]= w;
BLK2816:
	ctx->vsp=local; return(local[0]);}

/*compose-body*/
static pointer F2465compose_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[1];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[50]); /*find-method*/
	if (w==NIL) goto IF2866;
	local[0]= argv[1];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF2867;
IF2866:
	local[0]= NIL;
IF2867:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F2455make_vertex_edge_htab(ctx,1,local+0); /*make-vertex-edge-htab*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F2455make_vertex_edge_htab(ctx,1,local+1); /*make-vertex-edge-htab*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[96];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[1];
	local[4]= fqv[96];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= argv[1];
	local[6]= fqv[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	local[9]= fqv[97];
	local[10]= argv[1];
	local[11]= makeflt(9.9999999999999950039964e-03);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	local[8]= w;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
	local[23]= NIL;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[16] = w;
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)F2456copy_add_vertex(ctx,1,local+24); /*copy-add-vertex*/
	local[24]= local[1];
	ctx->vsp=local+25;
	w=(pointer)F2456copy_add_vertex(ctx,1,local+24); /*copy-add-vertex*/
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[17] = w;
	local[24]= local[4];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)F2454initial_intersection_list(ctx,2,local+24); /*initial-intersection-list*/
	local[6] = w;
	local[24]= local[5];
	local[25]= local[1];
	ctx->vsp=local+26;
	w=(pointer)F2454initial_intersection_list(ctx,2,local+24); /*initial-intersection-list*/
	local[7] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[18] = w;
	local[24]= local[6];
	local[25]= local[3];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(pointer)F2445insert_intersections(ctx,3,local+24); /*insert-intersections*/
	local[24]= local[7];
	local[25]= local[2];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(pointer)F2445insert_intersections(ctx,3,local+24); /*insert-intersections*/
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[19] = w;
	storeglobal(fqv[98],local[6]);
	local[24]= local[7];
	storeglobal(fqv[99],local[24]);
	local[24]= local[6];
	local[25]= argv[1];
	local[26]= argv[2];
	ctx->vsp=local+27;
	w=(pointer)F2446make_edge_segments(ctx,3,local+24); /*make-edge-segments*/
	local[9] = w;
	local[24]= local[7];
	local[25]= argv[0];
	local[26]= argv[2];
	ctx->vsp=local+27;
	w=(pointer)F2446make_edge_segments(ctx,3,local+24); /*make-edge-segments*/
	local[10] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[20] = w;
	local[24]= local[9];
	ctx->vsp=local+25;
	w=(pointer)F2447intersecting_segments(ctx,1,local+24); /*intersecting-segments*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)F2448sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[6] = w;
	local[24]= local[10];
	ctx->vsp=local+25;
	w=(pointer)F2447intersecting_segments(ctx,1,local+24); /*intersecting-segments*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)F2448sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[7] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[21] = w;
	local[24]= local[9];
	ctx->vsp=local+25;
	w=(pointer)F2448sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[9] = w;
	local[24]= local[10];
	ctx->vsp=local+25;
	w=(pointer)F2448sort_edges_by_face(ctx,1,local+24); /*sort-edges-by-face*/
	local[10] = w;
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[22] = w;
	local[24]= local[6];
	local[25]= local[10];
	local[26]= T;
	local[27]= argv[2];
	ctx->vsp=local+28;
	w=(pointer)F2449make_crossing_edges(ctx,4,local+24); /*make-crossing-edges*/
	local[12] = w;
	local[24]= local[7];
	local[25]= local[9];
	local[26]= NIL;
	local[27]= argv[2];
	ctx->vsp=local+28;
	w=(pointer)F2449make_crossing_edges(ctx,4,local+24); /*make-crossing-edges*/
	local[13] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	storeglobal(fqv[102],local[12]);
	local[24]= local[13];
	storeglobal(fqv[103],local[24]);
	if (loadglobal(fqv[53])==NIL) goto IF2868;
	local[24]= T;
	local[25]= fqv[104];
	ctx->vsp=local+26;
	w=(pointer)XFORMAT(ctx,2,local+24); /*format*/
	local[24]= fqv[105];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2869;
IF2868:
	local[24]= NIL;
IF2869:
	local[24]= local[9];
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)F2451merge_segments(ctx,3,local+24); /*merge-segments*/
	local[9] = w;
	local[24]= local[10];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)F2451merge_segments(ctx,3,local+24); /*merge-segments*/
	local[10] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	local[24]= argv[1];
	local[25]= loadglobal(fqv[73]);
	ctx->vsp=local+26;
	w=(pointer)DERIVEDP(ctx,2,local+24); /*derivedp*/
	if (w==NIL) goto IF2870;
	local[24]= argv[0];
	local[25]= argv[1];
	ctx->vsp=local+26;
	w=(pointer)F2458contacting_faces(ctx,2,local+24); /*contacting-faces*/
	local[14] = w;
	local[24]= local[14];
	goto IF2871;
IF2870:
	local[24]= NIL;
IF2871:
	if (local[14]==NIL) goto IF2872;
	local[24]= loadglobal(fqv[106]);
	local[25]= fqv[107];
	local[26]= local[14];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)XFORMAT(ctx,3,local+24); /*format*/
	if (loadglobal(fqv[53])==NIL) goto IF2874;
	local[24]= fqv[108];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2875;
IF2874:
	local[24]= NIL;
IF2875:
	local[24]= NIL;
	local[25]= local[14];
WHL2877:
	if (local[25]==NIL) goto WHX2878;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	local[28]= local[9];
	local[29]= local[10];
	ctx->vsp=local+30;
	w=(pointer)F2463merge_contacting_faces(ctx,4,local+26); /*merge-contacting-faces*/
	local[10] = w;
	goto WHL2877;
WHX2878:
	local[26]= NIL;
BLK2879:
	w = NIL;
	local[24]= w;
	goto IF2873;
IF2872:
	local[24]= NIL;
IF2873:
	local[24]= (pointer)get_sym_func(fqv[76]);
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(*ftab[25])(ctx,2,local+24,&ftab[25],fqv[109]); /*delete-if-not*/
	local[9] = w;
	local[24]= (pointer)get_sym_func(fqv[76]);
	local[25]= local[10];
	ctx->vsp=local+26;
	w=(*ftab[25])(ctx,2,local+24,&ftab[25],fqv[109]); /*delete-if-not*/
	local[10] = w;
	storeglobal(fqv[100],local[9]);
	local[24]= local[10];
	storeglobal(fqv[101],local[24]);
	local[24]= (pointer)get_sym_func(fqv[75]);
	local[25]= local[9];
	ctx->vsp=local+26;
	w=(pointer)MAPCAR(ctx,2,local+24); /*mapcar*/
	local[24]= w;
	local[25]= (pointer)get_sym_func(fqv[75]);
	local[26]= local[10];
	ctx->vsp=local+27;
	w=(pointer)MAPCAR(ctx,2,local+25); /*mapcar*/
	local[25]= w;
	ctx->vsp=local+26;
	w=(pointer)F2459aligned_faces(ctx,2,local+24); /*aligned-faces*/
	local[15] = w;
	if (local[15]==NIL) goto IF2881;
	local[24]= loadglobal(fqv[106]);
	local[25]= fqv[110];
	local[26]= local[15];
	ctx->vsp=local+27;
	w=(pointer)LENGTH(ctx,1,local+26); /*length*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)XFORMAT(ctx,3,local+24); /*format*/
	local[24]= NIL;
	local[25]= local[15];
WHL2884:
	if (local[25]==NIL) goto WHX2885;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[27]= (w)->c.cons.car;
	local[28]= local[9];
	local[29]= local[10];
	ctx->vsp=local+30;
	w=(pointer)F2464merge_aligned_faces(ctx,4,local+26); /*merge-aligned-faces*/
	goto WHL2884;
WHX2885:
	local[26]= NIL;
BLK2886:
	w = NIL;
	local[24]= w;
	goto IF2882;
IF2881:
	local[24]= NIL;
IF2882:
	local[24]= NIL;
	storeglobal(fqv[111],local[24]);
	if (loadglobal(fqv[53])==NIL) goto IF2888;
	local[24]= T;
	local[25]= fqv[112];
	ctx->vsp=local+26;
	w=(pointer)XFORMAT(ctx,2,local+24); /*format*/
	local[24]= fqv[113];
	ctx->vsp=local+25;
	w=(*ftab[24])(ctx,1,local+24,&ftab[24],fqv[92]); /*break*/
	local[24]= w;
	goto IF2889;
IF2888:
	local[24]= NIL;
IF2889:
	local[24]= NIL;
	local[25]= local[9];
WHL2891:
	if (local[25]==NIL) goto WHX2892;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2895;
	local[26]= T;
	local[27]= fqv[114];
	local[28]= loadglobal(fqv[111]);
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)XFORMAT(ctx,3,local+26); /*format*/
	local[26]= w;
	goto IF2896;
IF2895:
	local[26]= NIL;
IF2896:
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)F2453construct_faces(ctx,1,local+26); /*construct-faces*/
	local[26]= w;
	w = loadglobal(fqv[111]);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	storeglobal(fqv[111],local[26]);
	goto WHL2891;
WHX2892:
	local[26]= NIL;
BLK2893:
	w = NIL;
	local[24]= NIL;
	local[25]= local[10];
WHL2898:
	if (local[25]==NIL) goto WHX2899;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	w=local[25];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25] = (w)->c.cons.cdr;
	w = local[26];
	local[24] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2902;
	local[26]= T;
	local[27]= fqv[115];
	local[28]= loadglobal(fqv[111]);
	ctx->vsp=local+29;
	w=(pointer)LENGTH(ctx,1,local+28); /*length*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)XFORMAT(ctx,3,local+26); /*format*/
	local[26]= w;
	goto IF2903;
IF2902:
	local[26]= NIL;
IF2903:
	local[26]= local[24];
	ctx->vsp=local+27;
	w=(pointer)F2453construct_faces(ctx,1,local+26); /*construct-faces*/
	local[26]= w;
	w = loadglobal(fqv[111]);
	ctx->vsp=local+27;
	local[26]= cons(ctx,local[26],w);
	storeglobal(fqv[111],local[26]);
	goto WHL2898;
WHX2899:
	local[26]= NIL;
BLK2900:
	w = NIL;
	local[24]= loadglobal(fqv[111]);
	ctx->vsp=local+25;
	w=(pointer)NREVERSE(ctx,1,local+24); /*nreverse*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(*ftab[26])(ctx,1,local+24,&ftab[26],fqv[116]); /*flatten*/
	local[24]= w;
	storeglobal(fqv[111],w);
	ctx->vsp=local+24;
	w=(pointer)RUNTIME(ctx,0,local+24); /*unix:runtime*/
	local[23] = w;
	if (loadglobal(fqv[53])==NIL) goto IF2904;
	local[24]= T;
	local[25]= fqv[117];
	local[26]= makeflt(1.6699999999999992628119e-02);
	local[27]= local[17];
	local[28]= local[16];
	ctx->vsp=local+29;
	w=(pointer)MINUS(ctx,2,local+27); /*-*/
	local[27]= w;
	ctx->vsp=local+28;
	w=(pointer)TIMES(ctx,2,local+26); /***/
	local[26]= w;
	local[27]= makeflt(1.6699999999999992628119e-02);
	local[28]= local[18];
	local[29]= local[17];
	ctx->vsp=local+30;
	w=(pointer)MINUS(ctx,2,local+28); /*-*/
	local[28]= w;
	ctx->vsp=local+29;
	w=(pointer)TIMES(ctx,2,local+27); /***/
	local[27]= w;
	local[28]= makeflt(1.6699999999999992628119e-02);
	local[29]= local[19];
	local[30]= local[18];
	ctx->vsp=local+31;
	w=(pointer)MINUS(ctx,2,local+29); /*-*/
	local[29]= w;
	ctx->vsp=local+30;
	w=(pointer)TIMES(ctx,2,local+28); /***/
	local[28]= w;
	local[29]= makeflt(1.6699999999999992628119e-02);
	local[30]= local[20];
	local[31]= local[19];
	ctx->vsp=local+32;
	w=(pointer)MINUS(ctx,2,local+30); /*-*/
	local[30]= w;
	ctx->vsp=local+31;
	w=(pointer)TIMES(ctx,2,local+29); /***/
	local[29]= w;
	local[30]= makeflt(1.6699999999999992628119e-02);
	local[31]= local[21];
	local[32]= local[20];
	ctx->vsp=local+33;
	w=(pointer)MINUS(ctx,2,local+31); /*-*/
	local[31]= w;
	ctx->vsp=local+32;
	w=(pointer)TIMES(ctx,2,local+30); /***/
	local[30]= w;
	local[31]= makeflt(1.6699999999999992628119e-02);
	local[32]= local[22];
	local[33]= local[21];
	ctx->vsp=local+34;
	w=(pointer)MINUS(ctx,2,local+32); /*-*/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)TIMES(ctx,2,local+31); /***/
	local[31]= w;
	local[32]= makeflt(1.6699999999999992628119e-02);
	local[33]= local[23];
	local[34]= local[22];
	ctx->vsp=local+35;
	w=(pointer)MINUS(ctx,2,local+33); /*-*/
	local[33]= w;
	ctx->vsp=local+34;
	w=(pointer)TIMES(ctx,2,local+32); /***/
	local[32]= w;
	ctx->vsp=local+33;
	w=(pointer)XFORMAT(ctx,9,local+24); /*format*/
	local[24]= w;
	goto IF2905;
IF2904:
	local[24]= NIL;
IF2905:
	local[24]= loadglobal(fqv[118]);
	ctx->vsp=local+25;
	w=(pointer)INSTANTIATE(ctx,1,local+24); /*instantiate*/
	local[24]= w;
	local[25]= local[24];
	local[26]= fqv[9];
	local[27]= fqv[96];
	local[28]= loadglobal(fqv[111]);
	ctx->vsp=local+29;
	w=(pointer)SEND(ctx,4,local+25); /*send*/
	w = local[24];
	local[0]= w;
BLK2865:
	ctx->vsp=local; return(local[0]);}

/*set-original-face*/
static pointer F2466set_original_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[119];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[120];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,CLO2908,env,argv,local);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
WHL2910:
	if (local[6]==NIL) goto WHX2911;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[51];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[27])(ctx,1,local+7,&ftab[27],fqv[121]); /*primitive-body-p*/
	if (w==NIL) goto CON2915;
	local[7]= local[3];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,2,local+7,&ftab[28],fqv[122]); /*position*/
	local[4] = w;
	if (local[4]==NIL) goto IF2916;
	local[7]= local[5];
	local[8]= fqv[49];
	local[9]= local[5];
	local[10]= fqv[49];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	local[10]= local[3];
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(*ftab[28])(ctx,2,local+9,&ftab[28],fqv[122]); /*position*/
	local[9]= w;
	local[10]= local[4];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)NTH(ctx,2,local+10); /*nth*/
	local[10]= w;
	local[11]= fqv[96];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)NTH(ctx,2,local+9); /*nth*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	goto IF2917;
IF2916:
	local[7]= NIL;
IF2917:
	goto CON2914;
CON2915:
	local[7]= fqv[123];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(*ftab[23])(ctx,2,local+7,&ftab[23],fqv[88]); /*warn*/
	local[7]= w;
	goto CON2914;
CON2918:
	local[7]= NIL;
CON2914:
	local[7]= local[5];
	local[8]= fqv[51];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	goto WHL2910;
WHX2911:
	local[7]= NIL;
BLK2912:
	w = NIL;
	local[5]= NIL;
	local[6]= local[1];
WHL2920:
	if (local[6]==NIL) goto WHX2921;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= T;
	local[9]= fqv[124];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= argv[0];
	local[8]= fqv[125];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	goto WHL2920;
WHX2921:
	local[7]= NIL;
BLK2922:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK2907:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO2908(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[124];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*body+*/
static pointer F2467body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2925:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	local[3]= fqv[126];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL2927:
	if (local[4]==NIL) goto WHX2928;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[1];
	local[6]= local[3];
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)F2465compose_body(ctx,3,local+5); /*compose-body*/
	local[1] = w;
	local[5]= local[3];
	local[6]= fqv[126];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL2927;
WHX2928:
	local[5]= NIL;
BLK2929:
	w = NIL;
	local[3]= local[1];
	local[4]= fqv[119];
	local[5]= fqv[127];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2466set_original_face(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2924:
	ctx->vsp=local; return(local[0]);}

/*body**/
static pointer F2468body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2932:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[126];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
WHL2934:
	if (local[0]==NIL) goto WHX2935;
	local[3]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[56];
	ctx->vsp=local+6;
	w=(pointer)F2465compose_body(ctx,3,local+3); /*compose-body*/
	local[1] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= fqv[126];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	goto WHL2934;
WHX2935:
	local[3]= NIL;
BLK2936:
	local[3]= local[1];
	local[4]= fqv[119];
	local[5]= fqv[128];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2466set_original_face(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2931:
	ctx->vsp=local; return(local[0]);}

/*body-*/
static pointer F2469body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST2939:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[129];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	ctx->vsp=local+3;
	w = makeclosure(codevec,quotevec,UWP2940,env,argv,local);
	local[3]=(pointer)(ctx->protfp); local[4]=w;
	ctx->protfp=(struct protectframe *)(local+3);
WHL2941:
	if (local[0]==NIL) goto WHX2942;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[126];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)F2465compose_body(ctx,3,local+5); /*compose-body*/
	local[1] = w;
	local[5]= T;
	local[6]= local[5];
	*(ovafptr(local[1],fqv[130])) = local[6];
	goto WHL2941;
WHX2942:
	local[5]= NIL;
BLK2943:
	w = local[5];
	ctx->vsp=local+5;
	UWP2940(ctx,0,local+5,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[3]= local[1];
	local[4]= fqv[129];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[1];
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= local[1];
	local[4]= fqv[119];
	local[5]= fqv[131];
	local[6]= argv[0];
	local[7]= fqv[126];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F2466set_original_face(ctx,1,local+3); /*set-original-face*/
	w = local[1];
	local[0]= w;
BLK2938:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP2940(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*body-interference*/
static pointer F2470body_interference(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST2946:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	local[2]= fqv[95];
	ctx->vsp=local+3;
	w=(*ftab[17])(ctx,2,local+1,&ftab[17],fqv[66]); /*send-all*/
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL2947:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX2948;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[1] = w;
	local[4]= NIL;
	local[5]= local[0];
WHL2952:
	if (local[5]==NIL) goto WHX2953;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[1];
	local[7]= fqv[132];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF2956;
	local[6]= local[4];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF2957;
IF2956:
	local[6]= NIL;
IF2957:
	goto WHL2952;
WHX2953:
	local[6]= NIL;
BLK2954:
	w = NIL;
	goto WHL2947;
WHX2948:
	local[4]= NIL;
BLK2949:
	w = local[3];
	local[0]= w;
BLK2945:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M2958plane_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[133]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[9];
	local[3]= makeflt(-9.9999999999999973840965e+29);
	local[4]= makeflt(-9.9999999999999973840965e+29);
	local[5]= makeflt(-9.9999999999999973840965e+29);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeflt(9.9999999999999973840965e+29);
	local[5]= makeflt(9.9999999999999973840965e+29);
	local[6]= makeflt(9.9999999999999973840965e+29);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK2959:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M2961semi_space_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK2962:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M2963semi_space_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
BLK2964:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M2965semi_space_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2968;}
	local[0]= makeflt(0.0000000000000000000000e+00);
ENT2968:
ENT2967:
	if (n>3) maerror();
	local[1]= loadglobal(fqv[133]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[134];
	local[4]= makeflt(-9.9999999999999973840965e+29);
	local[5]= makeflt(-9.9999999999999973840965e+29);
	local[6]= makeflt(-9.9999999999999973840965e+29);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= makeflt(9.9999999999999973840965e+29);
	local[6]= makeflt(9.9999999999999973840965e+29);
	local[7]= makeflt(9.9999999999999973840965e+29);
	ctx->vsp=local+8;
	w=(pointer)MKFLTVEC(ctx,3,local+5); /*float-vector*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK2966:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M2970semi_space_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[135];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	if (w==NIL) goto IF2972;
	local[0]= fqv[56];
	goto IF2973;
IF2972:
	local[0]= fqv[32];
IF2973:
	w = local[0];
	local[0]= w;
BLK2971:
	ctx->vsp=local; return(local[0]);}

/*:primitive-face*/
static pointer M2974semi_space_primitive_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2977;}
	local[0]= NIL;
ENT2977:
ENT2976:
	if (n>3) maerror();
	w = argv[0];
	local[0]= w;
BLK2975:
	ctx->vsp=local; return(local[0]);}

/*:body*/
static pointer M2978semi_space_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2981;}
	local[0]= NIL;
ENT2981:
ENT2980:
	if (n>3) maerror();
	w = NIL;
	local[0]= w;
BLK2979:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M2982semi_space_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT2985;}
	local[0]= NIL;
ENT2985:
ENT2984:
	if (n>3) maerror();
	w = NIL;
	local[0]= w;
BLK2983:
	ctx->vsp=local; return(local[0]);}

/*:on-edge*/
static pointer M2986semi_space_on_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT2989;}
	local[0]= NIL;
ENT2989:
ENT2988:
	if (n>4) maerror();
	w = NIL;
	local[0]= w;
BLK2987:
	ctx->vsp=local; return(local[0]);}

/*body/*/
static pointer F2471body_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[136]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[9];
	local[3]= *(ovafptr(argv[1],fqv[31]));
	local[4]= *(ovafptr(argv[1],fqv[137]));
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)F2465compose_body(ctx,3,local+1); /*compose-body*/
	local[0]= w;
BLK2990:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___compose(ctx,n,argv,env)
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
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2992;
	local[0]= fqv[139];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[140],w);
	goto IF2993;
IF2992:
	local[0]= fqv[141];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2993:
	local[0]= fqv[142];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[143];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[144];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2994;
	local[0]= fqv[144];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[144];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2996;
	local[0]= fqv[144];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2997;
IF2996:
	local[0]= NIL;
IF2997:
	local[0]= fqv[144];
	goto IF2995;
IF2994:
	local[0]= NIL;
IF2995:
	local[0]= fqv[147];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2998;
	local[0]= fqv[147];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[147];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3000;
	local[0]= fqv[147];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3001;
IF3000:
	local[0]= NIL;
IF3001:
	local[0]= fqv[147];
	goto IF2999;
IF2998:
	local[0]= NIL;
IF2999:
	local[0]= fqv[111];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3002;
	local[0]= fqv[111];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[111];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3004;
	local[0]= fqv[111];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3005;
IF3004:
	local[0]= NIL;
IF3005:
	local[0]= fqv[111];
	goto IF3003;
IF3002:
	local[0]= NIL;
IF3003:
	local[0]= fqv[148];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3006;
	local[0]= fqv[148];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[148];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3008;
	local[0]= fqv[148];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3009;
IF3008:
	local[0]= NIL;
IF3009:
	local[0]= fqv[148];
	goto IF3007;
IF3006:
	local[0]= NIL;
IF3007:
	local[0]= fqv[8];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3010;
	local[0]= fqv[8];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3012;
	local[0]= fqv[8];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3013;
IF3012:
	local[0]= NIL;
IF3013:
	local[0]= fqv[8];
	goto IF3011;
IF3010:
	local[0]= NIL;
IF3011:
	local[0]= fqv[45];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3014;
	local[0]= fqv[45];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3016;
	local[0]= fqv[45];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3017;
IF3016:
	local[0]= NIL;
IF3017:
	local[0]= fqv[45];
	goto IF3015;
IF3014:
	local[0]= NIL;
IF3015:
	local[0]= fqv[57];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3018;
	local[0]= fqv[57];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3020;
	local[0]= fqv[57];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3021;
IF3020:
	local[0]= NIL;
IF3021:
	local[0]= fqv[57];
	goto IF3019;
IF3018:
	local[0]= NIL;
IF3019:
	local[0]= fqv[118];
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF3022;
	local[0]= fqv[118];
	local[1]= fqv[145];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[118];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF3024;
	local[0]= fqv[118];
	local[1]= fqv[146];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF3025;
IF3024:
	local[0]= NIL;
IF3025:
	local[0]= fqv[118];
	goto IF3023;
IF3022:
	local[0]= NIL;
IF3023:
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F2443intersecting_edges,fqv[150]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F2444cut_body,fqv[152]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[153],module,F2445insert_intersections,fqv[154]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F2446make_edge_segments,fqv[156]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[157],module,F2447intersecting_segments,fqv[158]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F2448sort_edges_by_face,fqv[160]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[161],module,F2449make_crossing_edges,fqv[162]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[163],module,F2450add_alist,fqv[164]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[165],module,F2451merge_segments,fqv[166]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[167],module,F2452find_connecting_edge,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F2453construct_faces,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F2454initial_intersection_list,fqv[172]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F2455make_vertex_edge_htab,fqv[174]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[175],module,F2456copy_add_vertex,fqv[176]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[177],module,F2457find_colinear_int,fqv[178]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[179],module,F2458contacting_faces,fqv[180]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[181],module,F2459aligned_faces,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F2460find_equivalent_edge,fqv[184]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F2461unify_vertex,fqv[186]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F2462merge_edges_if_colinear,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F2463merge_contacting_faces,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F2464merge_aligned_faces,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F2465compose_body,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F2466set_original_face,fqv[196]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[197],module,F2467body_,fqv[198]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[199],module,F2468body_,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F2469body_,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F2470body_interference,fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2958plane_box,fqv[14],fqv[205],fqv[206]);
	local[0]= fqv[136];
	local[1]= fqv[146];
	local[2]= fqv[136];
	local[3]= fqv[207];
	local[4]= loadglobal(fqv[205]);
	local[5]= fqv[208];
	local[6]= fqv[209];
	local[7]= fqv[210];
	local[8]= NIL;
	local[9]= fqv[211];
	local[10]= NIL;
	local[11]= fqv[68];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[212];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[29])(ctx,13,local+2,&ftab[29],fqv[213]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2961semi_space_edges,fqv[1],fqv[136],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2963semi_space_faces,fqv[96],fqv[136],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2965semi_space_box,fqv[14],fqv[136],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2970semi_space_insidep,fqv[20],fqv[136],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2974semi_space_primitive_face,fqv[49],fqv[136],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2978semi_space_body,fqv[51],fqv[136],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2982semi_space_id,fqv[52],fqv[136],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M2986semi_space_on_edge,fqv[38],fqv[136],fqv[221]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[222],module,F2471body_,fqv[223]);
	local[0]= fqv[224];
	local[1]= fqv[225];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[226]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<31; i++) ftab[i]=fcallx;
}
