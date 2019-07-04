/* ./shadow.c :  entry=shadow */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "shadow.h"
#pragma init (register_shadow)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___shadow();
extern pointer build_quote_vector();
static int register_shadow()
  { add_module_initializer("___shadow", ___shadow);}

static pointer F4299polygon_in_contact_p();
static pointer F4300make_edges_from_vertices();
static pointer F4301orthogonally_visible_faces();
static pointer F4302make_polygon();
static pointer F4303make_face_from_edge_loop();
static pointer F4304change_to_hole();
static pointer F4305project_shadow1();
static pointer F4306remove_inner_loop();
static pointer F4307project_shadow();
static pointer F4308shadow_intersection();
static pointer F4309closest_shadow();

/*do-combination*/
static pointer F4310(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST4312:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[0];
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,1,local+3); /*gensym*/
	local[3]= w;
	local[4]= fqv[1];
	local[5]= local[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	local[5]= w;
	local[6]= fqv[2];
	local[7]= fqv[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[1];
	local[9]= local[1];
	local[10]= fqv[4];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	local[9]= w;
	local[10]= fqv[5];
	local[11]= local[2];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	w = local[0];
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
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
	local[0]= w;
BLK4311:
	ctx->vsp=local; return(local[0]);}

/*polygon-in-contact-p*/
static pointer F4299polygon_in_contact_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[0];
WHL4315:
	if (local[3]==NIL) goto WHX4316;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= NIL;
	local[5]= local[1];
WHL4320:
	if (local[5]==NIL) goto WHX4321;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= fqv[7];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF4324;
	local[6]= local[2];
	local[7]= fqv[8];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	if (w==NIL) goto IF4324;
	w = T;
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK4313;
	goto IF4325;
IF4324:
	local[6]= NIL;
IF4325:
	goto WHL4320;
WHX4321:
	local[6]= NIL;
BLK4322:
	w = NIL;
	goto WHL4315;
WHX4316:
	local[4]= NIL;
BLK4317:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK4313:
	ctx->vsp=local; return(local[0]);}

/*make-edges-from-vertices*/
static pointer F4300make_edges_from_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL4327:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4328;
	local[2]= loadglobal(fqv[9]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[10];
	local[5]= fqv[11];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= fqv[12];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL4327;
WHX4328:
	local[2]= NIL;
BLK4329:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK4326:
	ctx->vsp=local; return(local[0]);}

/*orthogonally-visible-faces*/
static pointer F4301orthogonally_visible_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
WHL4334:
	if (local[4]==NIL) goto WHX4335;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[1];
	local[6]= local[3]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4338;
	local[5]= local[3];
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[1];
	goto IF4339;
IF4338:
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
IF4339:
	goto WHL4334;
WHX4335:
	local[5]= NIL;
BLK4336:
	w = NIL;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[15]); /*values*/
	local[0]= w;
BLK4332:
	ctx->vsp=local; return(local[0]);}

/*make-polygon*/
static pointer F4302make_polygon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4341:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[10];
	local[4]= fqv[17];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK4340:
	ctx->vsp=local; return(local[0]);}

/*make-face-from-edge-loop*/
static pointer F4303make_face_from_edge_loop(ctx,n,argv,env)
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
	local[2]= argv[0];
WHL4345:
	if (local[2]==NIL) goto WHX4346;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[0];
	local[4]= local[3];
	w = local[1];
	w->c.obj.iv[3] = local[4];
	goto WHL4345;
WHX4346:
	local[3]= NIL;
BLK4347:
	w = NIL;
	local[1]= local[0];
	local[2]= fqv[10];
	local[3]= fqv[19];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4343:
	ctx->vsp=local; return(local[0]);}

/*change-to-hole*/
static pointer F4304change_to_hole(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[20]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[10];
	local[3]= fqv[17];
	local[4]= argv[0];
	local[5]= fqv[17];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK4349:
	ctx->vsp=local; return(local[0]);}

/*project-shadow1*/
static pointer F4305project_shadow1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[21],w);
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= fqv[22];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,1,local+8); /*v-*/
	local[8]= w;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= local[2];
WHL4352:
	if (local[15]==NIL) goto WHX4353;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[7];
	local[17]= local[14]->c.obj.iv[1];
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	local[17]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+18;
	w=(*ftab[0])(ctx,2,local+16,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4356;
	local[16]= local[14];
	w = local[0];
	ctx->vsp=local+17;
	local[0] = cons(ctx,local[16],w);
	local[16]= local[0];
	goto IF4357;
IF4356:
	local[16]= local[14];
	w = local[1];
	ctx->vsp=local+17;
	local[1] = cons(ctx,local[16],w);
	local[16]= local[1];
IF4357:
	goto WHL4352;
WHX4353:
	local[16]= NIL;
BLK4354:
	w = NIL;
	local[14]= NIL;
	local[15]= local[0];
WHL4359:
	if (local[15]==NIL) goto WHX4360;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= local[14];
	local[23]= fqv[17];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
WHL4364:
	if (local[22]==NIL) goto WHX4365;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= argv[1];
	local[24]= fqv[23];
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	local[23]= w;
	w = local[16];
	ctx->vsp=local+24;
	local[16] = cons(ctx,local[23],w);
	goto WHL4364;
WHX4365:
	local[23]= NIL;
BLK4366:
	w = NIL;
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[16] = w;
	local[21]= NIL;
	local[22]= local[14];
	local[23]= fqv[24];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
WHL4369:
	if (local[22]==NIL) goto WHX4370;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= NIL;
	local[24]= local[21];
	local[25]= fqv[17];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.cdr;
WHL4374:
	if (local[24]==NIL) goto WHX4375;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24] = (w)->c.cons.cdr;
	w = local[25];
	local[23] = w;
	local[25]= argv[1];
	local[26]= fqv[23];
	local[27]= local[23];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	w = local[17];
	ctx->vsp=local+26;
	local[17] = cons(ctx,local[25],w);
	goto WHL4374;
WHX4375:
	local[25]= NIL;
BLK4376:
	w = NIL;
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= w;
	w = local[18];
	ctx->vsp=local+24;
	local[18] = cons(ctx,local[23],w);
	goto WHL4369;
WHX4370:
	local[23]= NIL;
BLK4371:
	w = NIL;
	local[21]= local[18];
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[18] = w;
	local[21]= NIL;
	local[22]= local[18];
WHL4379:
	if (local[22]==NIL) goto WHX4380;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= loadglobal(fqv[20]);
	ctx->vsp=local+24;
	w=(pointer)INSTANTIATE(ctx,1,local+23); /*instantiate*/
	local[23]= w;
	local[24]= local[23];
	local[25]= fqv[10];
	local[26]= fqv[17];
	local[27]= local[21];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,4,local+24); /*send*/
	w = local[23];
	local[23]= w;
	w = local[19];
	ctx->vsp=local+24;
	local[19] = cons(ctx,local[23],w);
	goto WHL4379;
WHX4380:
	local[23]= NIL;
BLK4381:
	w = NIL;
	local[21]= loadglobal(fqv[18]);
	ctx->vsp=local+22;
	w=(pointer)INSTANTIATE(ctx,1,local+21); /*instantiate*/
	local[21]= w;
	local[22]= local[21];
	local[23]= fqv[10];
	local[24]= fqv[17];
	local[25]= local[16];
	local[26]= fqv[24];
	local[27]= local[19];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,6,local+22); /*send*/
	w = local[21];
	local[21]= w;
	w = local[6];
	ctx->vsp=local+22;
	local[6] = cons(ctx,local[21],w);
	w = local[6];
	goto WHL4359;
WHX4360:
	local[16]= NIL;
BLK4361:
	w = NIL;
	local[14]= local[6];
	local[15]= (pointer)get_sym_func(fqv[25]);
	ctx->vsp=local+16;
	local[16]= makeclosure(codevec,quotevec,CLO4385,env,argv,local);
	ctx->vsp=local+17;
	w=(pointer)SORT(ctx,3,local+14); /*sort*/
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
WHL4386:
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4387;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[19];
	local[15] = w;
	local[14] = NIL;
WHL4391:
	if (local[6]==NIL) goto WHX4392;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[19];
	local[16] = w;
	storeglobal(fqv[26],local[15]);
	local[19]= local[16];
	storeglobal(fqv[27],local[19]);
	local[19]= local[15];
	local[20]= local[16];
	ctx->vsp=local+21;
	w=(*ftab[2])(ctx,2,local+19,&ftab[2],fqv[28]); /*face+*/
	local[17] = w;
	ctx->vsp=local+19;
	local[19]= makeclosure(codevec,quotevec,CLO4397,env,argv,local);
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(*ftab[3])(ctx,2,local+19,&ftab[3],fqv[29]); /*member-if*/
	if (w==NIL) goto IF4395;
	local[19]= fqv[30];
	ctx->vsp=local+20;
	w=(*ftab[4])(ctx,1,local+19,&ftab[4],fqv[31]); /*break*/
	local[19]= w;
	goto IF4396;
IF4395:
	local[19]= loadglobal(fqv[16]);
	local[20]= local[17];
	ctx->vsp=local+21;
	w=(*ftab[5])(ctx,2,local+19,&ftab[5],fqv[32]); /*collect-instances*/
	local[17] = w;
	local[19]= local[17];
IF4396:
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON4399;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
	local[20]= local[6];
	ctx->vsp=local+21;
	w=(pointer)NCONC(ctx,2,local+19); /*nconc*/
	w = NIL;
	ctx->vsp=local+19;
	local[19]=w;
	goto BLK4390;
	goto CON4398;
CON4399:
	local[19]= local[16];
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
	goto CON4398;
CON4400:
	local[19]= NIL;
CON4398:
	goto WHL4391;
WHX4392:
	local[19]= NIL;
BLK4393:
	local[19]= fqv[33];
	ctx->vsp=local+20;
	w=(pointer)SIGERROR(ctx,1,local+19); /*error*/
	local[19]= w;
BLK4390:
	local[6] = local[14];
	goto WHL4386;
WHX4387:
	local[19]= NIL;
BLK4388:
	w = local[19];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	ctx->vsp=local+15;
	unbindx(ctx,1);
	w = local[14];
	local[0]= w;
BLK4350:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4385(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[34];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4397(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[35]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*remove-inner-loop*/
static pointer F4306remove_inner_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
WHL4403:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4404;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= NIL;
	local[5]= local[2];
WHL4408:
	if (local[5]==NIL) goto WHX4409;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[3];
	local[7]= local[3];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[6])(ctx,2,local+7,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4414;
	local[6]= local[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4414;
	local[6]= local[4];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[7])(ctx,1,local+7,&ftab[7],fqv[37]); /*last*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto OR4414;
	goto IF4412;
OR4414:
	local[6]= local[3]->c.obj.iv[1];
	local[7]= local[3]->c.obj.iv[2];
	local[8]= local[4]->c.obj.iv[1];
	local[9]= local[4]->c.obj.iv[2];
	local[10]= makeflt(1.0000000000000000208167e-03);
	ctx->vsp=local+11;
	w=(*ftab[8])(ctx,5,local+6,&ftab[8],fqv[38]); /*line-intersection3*/
	local[6]= w;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	if (local[6]==NIL) goto IF4415;
	local[9]= makeflt(0.0000000000000000000000e+00);
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4415;
	local[9]= local[7];
	local[10]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4415;
	local[9]= makeflt(0.0000000000000000000000e+00);
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4415;
	local[9]= local[8];
	local[10]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+11;
	w=(*ftab[0])(ctx,2,local+9,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4415;
	local[9]= local[3];
	local[10]= local[4];
	local[11]= local[3];
	local[12]= fqv[39];
	local[13]= local[7];
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[11]= w;
	local[12]= local[7];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,5,local+9); /*list*/
	local[9]= w;
	w = local[0];
	ctx->vsp=local+10;
	local[0] = cons(ctx,local[9],w);
	local[9]= local[3];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[4];
	w = local[1];
	ctx->vsp=local+10;
	local[1] = cons(ctx,local[9],w);
	local[9]= local[1];
	goto IF4416;
IF4415:
	local[9]= NIL;
IF4416:
	w = local[9];
	local[6]= w;
	goto IF4413;
IF4412:
	local[6]= NIL;
IF4413:
	goto WHL4408;
WHX4409:
	local[6]= NIL;
BLK4410:
	w = NIL;
	goto WHL4403;
WHX4404:
	local[3]= NIL;
BLK4405:
	w = local[3];
	local[2]= NIL;
	local[3]= local[0];
WHL4418:
	if (local[3]==NIL) goto WHX4419;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[4]->c.obj.iv[2];
	local[7]= local[4]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,2,local+6); /*v-*/
	local[6]= w;
	local[7]= local[5]->c.obj.iv[2];
	local[8]= local[5]->c.obj.iv[1];
	ctx->vsp=local+9;
	w=(pointer)VMINUS(ctx,2,local+7); /*v-*/
	local[7]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= NIL;
	local[10]= argv[1];
	local[11]= local[6];
	local[12]= local[7];
	ctx->vsp=local+13;
	w=(pointer)SCA3PROD(ctx,3,local+10); /*v.**/
	local[10]= w;
	local[11]= makeint((eusinteger_t)0L);
	ctx->vsp=local+12;
	w=(pointer)LESSP(ctx,2,local+10); /*<*/
	if (w==NIL) goto IF4422;
	local[10]= local[5];
	local[11]= local[4];
	local[4] = local[10];
	local[5] = local[11];
	w = NIL;
	local[10]= w;
	goto IF4423;
IF4422:
	local[10]= NIL;
IF4423:
	local[10]= local[4];
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	if (local[9]!=NIL) goto IF4426;
	local[9] = argv[0];
	local[10]= local[9];
	goto IF4427;
IF4426:
	local[10]= NIL;
IF4427:
WHL4428:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	if (local[5]==local[10]) goto WHX4429;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[6])(ctx,2,local+10,&ftab[6],fqv[36]); /*member*/
	if (w==NIL) goto IF4431;
	local[10]= fqv[40];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF4432;
IF4431:
	local[10]= NIL;
IF4432:
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	local[11]= argv[0];
	local[12]= fqv[41];
	local[13]= makeint((eusinteger_t)1L);
	ctx->vsp=local+14;
	w=(*ftab[9])(ctx,4,local+10,&ftab[9],fqv[42]); /*delete*/
	argv[0] = w;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	if (local[9]!=NIL) goto IF4433;
	local[9] = argv[0];
	local[10]= local[9];
	goto IF4434;
IF4433:
	local[10]= NIL;
IF4434:
	goto WHL4428;
WHX4429:
	local[10]= NIL;
BLK4430:
	local[10]= local[8];
	local[11]= local[10];
	w = local[4];
	w->c.obj.iv[2] = local[11];
	local[10]= local[8];
	local[11]= local[10];
	w = local[5];
	w->c.obj.iv[1] = local[11];
	w = local[10];
	goto WHL4418;
WHX4419:
	local[4]= NIL;
BLK4420:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK4401:
	ctx->vsp=local; return(local[0]);}

/*project-shadow*/
static pointer F4307project_shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[1];
	local[7]= fqv[22];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)VMINUS(ctx,1,local+7); /*v-*/
	local[7]= w;
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= NIL;
	local[17]= local[2];
WHL4437:
	if (local[17]==NIL) goto WHX4438;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[6];
	local[19]= local[16]->c.obj.iv[1];
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	local[19]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+20;
	w=(*ftab[0])(ctx,2,local+18,&ftab[0],fqv[14]); /*eps<*/
	if (w==NIL) goto IF4441;
	local[18]= local[16];
	w = local[0];
	ctx->vsp=local+19;
	local[0] = cons(ctx,local[18],w);
	local[18]= local[0];
	goto IF4442;
IF4441:
	local[18]= local[16];
	w = local[1];
	ctx->vsp=local+19;
	local[1] = cons(ctx,local[18],w);
	local[18]= local[1];
IF4442:
	goto WHL4437;
WHX4438:
	local[18]= NIL;
BLK4439:
	w = NIL;
	local[16]= NIL;
	local[17]= argv[0];
	local[18]= fqv[19];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
WHL4444:
	if (local[17]==NIL) goto WHX4445;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16]->c.obj.iv[3];
	local[19]= local[16]->c.obj.iv[4];
	local[20]= local[18];
	local[21]= local[0];
	ctx->vsp=local+22;
	w=(*ftab[6])(ctx,2,local+20,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	local[21]= local[19];
	local[22]= local[0];
	ctx->vsp=local+23;
	w=(*ftab[6])(ctx,2,local+21,&ftab[6],fqv[36]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= NIL;
	if (local[20]==NIL) goto CON4449;
	if (local[21]!=NIL) goto CON4449;
	local[22] = local[20];
	local[23]= local[22];
	goto CON4448;
CON4449:
	if (local[20]!=NIL) goto CON4450;
	if (local[21]==NIL) goto CON4450;
	local[22] = local[21];
	local[23]= local[22];
	goto CON4448;
CON4450:
	local[22] = NIL;
	local[23]= local[22];
	goto CON4448;
CON4451:
	local[23]= NIL;
CON4448:
	if (local[22]==NIL) goto IF4452;
	local[23]= local[16];
	local[24]= local[22];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,2,local+23); /*list*/
	local[23]= w;
	w = local[3];
	ctx->vsp=local+24;
	local[3] = cons(ctx,local[23],w);
	local[23]= local[3];
	goto IF4453;
IF4452:
	local[23]= NIL;
IF4453:
	w = local[23];
	goto WHL4444;
WHX4445:
	local[18]= NIL;
BLK4446:
	w = NIL;
	local[16]= NIL;
	local[17]= local[3];
WHL4455:
	if (local[17]==NIL) goto WHX4456;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[11];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[12];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= local[18];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[10])(ctx,2,local+20,&ftab[10],fqv[43]); /*assoc*/
	if (w!=NIL) goto IF4459;
	local[20]= local[18];
	local[21]= argv[1];
	local[22]= fqv[23];
	local[23]= local[18];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,2,local+20); /*list*/
	local[20]= w;
	w = local[5];
	ctx->vsp=local+21;
	local[5] = cons(ctx,local[20],w);
	local[20]= local[5];
	goto IF4460;
IF4459:
	local[20]= NIL;
IF4460:
	local[20]= local[19];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(*ftab[10])(ctx,2,local+20,&ftab[10],fqv[43]); /*assoc*/
	if (w!=NIL) goto IF4461;
	local[20]= local[19];
	local[21]= argv[1];
	local[22]= fqv[23];
	local[23]= local[19];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)LIST(ctx,2,local+20); /*list*/
	local[20]= w;
	w = local[5];
	ctx->vsp=local+21;
	local[5] = cons(ctx,local[20],w);
	local[20]= local[5];
	goto IF4462;
IF4461:
	local[20]= NIL;
IF4462:
	w = local[20];
	goto WHL4455;
WHX4456:
	local[18]= NIL;
BLK4457:
	w = NIL;
	local[16]= NIL;
	local[17]= local[3];
WHL4464:
	if (local[17]==NIL) goto WHX4465;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	local[19]= fqv[11];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,3,local+18); /*send*/
	local[18]= w;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	local[20]= fqv[12];
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,3,local+19); /*send*/
	local[19]= w;
	local[20]= loadglobal(fqv[9]);
	ctx->vsp=local+21;
	w=(pointer)INSTANTIATE(ctx,1,local+20); /*instantiate*/
	local[20]= w;
	local[21]= local[20];
	local[22]= fqv[10];
	local[23]= fqv[11];
	local[24]= local[18];
	local[25]= local[5];
	ctx->vsp=local+26;
	w=(*ftab[10])(ctx,2,local+24,&ftab[10],fqv[43]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	local[25]= fqv[12];
	local[26]= local[19];
	local[27]= local[5];
	ctx->vsp=local+28;
	w=(*ftab[10])(ctx,2,local+26,&ftab[10],fqv[43]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[26]= (w)->c.cons.car;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,6,local+21); /*send*/
	w = local[20];
	local[20]= w;
	w = local[8];
	ctx->vsp=local+21;
	local[8] = cons(ctx,local[20],w);
	w = local[8];
	goto WHL4464;
WHX4465:
	local[18]= NIL;
BLK4466:
	w = NIL;
WHL4469:
	if (local[8]==NIL) goto WHX4470;
	local[13] = NIL;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[16];
	local[11] = w;
	local[16]= local[11];
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	local[11] = local[11]->c.obj.iv[2];
WHL4473:
	ctx->vsp=local+16;
	local[16]= makeclosure(codevec,quotevec,CLO4476,env,argv,local);
	local[17]= local[8];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,2,local+16,&ftab[11],fqv[44]); /*find-if*/
	local[12] = w;
	if (local[12]==NIL) goto WHX4474;
	local[16]= local[12];
	local[17]= local[8];
	local[18]= fqv[41];
	local[19]= makeint((eusinteger_t)1L);
	ctx->vsp=local+20;
	w=(*ftab[9])(ctx,4,local+16,&ftab[9],fqv[42]); /*delete*/
	local[8] = w;
	local[11] = local[12]->c.obj.iv[2];
	local[16]= local[12];
	w = local[13];
	ctx->vsp=local+17;
	local[13] = cons(ctx,local[16],w);
	goto WHL4473;
WHX4474:
	local[16]= NIL;
BLK4475:
	local[16]= local[13];
	ctx->vsp=local+17;
	w=(pointer)NREVERSE(ctx,1,local+16); /*nreverse*/
	local[16]= w;
	w = local[4];
	ctx->vsp=local+17;
	local[4] = cons(ctx,local[16],w);
	goto WHL4469;
WHX4470:
	local[16]= NIL;
BLK4471:
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)NREVERSE(ctx,1,local+16); /*nreverse*/
	local[4] = w;
	local[16]= NIL;
	local[17]= local[4];
WHL4478:
	if (local[17]==NIL) goto WHX4479;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)F4306remove_inner_loop(ctx,2,local+18); /*remove-inner-loop*/
	local[18]= w;
	w = local[9];
	ctx->vsp=local+19;
	local[9] = cons(ctx,local[18],w);
	goto WHL4478;
WHX4479:
	local[18]= NIL;
BLK4480:
	w = NIL;
	local[4] = local[9];
	local[16]= local[4];
	storeglobal(fqv[45],local[16]);
	local[14] = NIL;
	local[15] = NIL;
	local[16]= NIL;
	local[17]= local[4];
WHL4483:
	if (local[17]==NIL) goto WHX4484;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	ctx->vsp=local+19;
	w=(pointer)F4303make_face_from_edge_loop(ctx,1,local+18); /*make-face-from-edge-loop*/
	local[18]= w;
	local[19]= local[6];
	local[20]= local[18];
	local[21]= fqv[22];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)VINNERPRODUCT(ctx,2,local+19); /*v.*/
	local[19]= w;
	{ double left,right;
		right=fltval(makeflt(0.0000000000000000000000e+00)); left=fltval(local[19]);
	if (left >= right) goto IF4487;}
	local[19]= local[18];
	w = local[15];
	ctx->vsp=local+20;
	local[15] = cons(ctx,local[19],w);
	local[19]= local[15];
	goto IF4488;
IF4487:
	local[19]= local[18];
	ctx->vsp=local+20;
	w=(pointer)F4304change_to_hole(ctx,1,local+19); /*change-to-hole*/
	local[19]= w;
	w = local[14];
	ctx->vsp=local+20;
	local[14] = cons(ctx,local[19],w);
	local[19]= local[14];
IF4488:
	w = local[19];
	goto WHL4483;
WHX4484:
	local[18]= NIL;
BLK4485:
	w = NIL;
	local[16]= NIL;
	local[17]= local[14];
WHL4490:
	if (local[17]==NIL) goto WHX4491;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= NIL;
	local[19]= local[15];
WHL4496:
	if (local[19]==NIL) goto WHX4497;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19] = (w)->c.cons.cdr;
	w = local[20];
	local[18] = w;
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO4502,env,argv,local);
	local[21]= local[16];
	local[22]= fqv[17];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(*ftab[12])(ctx,2,local+20,&ftab[12],fqv[46]); /*every*/
	if (w==NIL) goto IF4500;
	local[20]= local[18];
	local[21]= fqv[47];
	local[22]= local[16];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= local[16];
	local[21]= fqv[48];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	w = NIL;
	ctx->vsp=local+20;
	local[18]=w;
	goto BLK4494;
	goto IF4501;
IF4500:
	local[20]= NIL;
IF4501:
	goto WHL4496;
WHX4497:
	local[20]= NIL;
BLK4498:
	w = NIL;
	local[18]= w;
BLK4494:
	goto WHL4490;
WHX4491:
	local[18]= NIL;
BLK4492:
	w = NIL;
	local[10] = local[15];
	local[16]= local[10];
	ctx->vsp=local+17;
	w=(pointer)COPYSEQ(ctx,1,local+16); /*copy-seq*/
	local[16]= w;
	storeglobal(fqv[49],w);
	local[16]= NIL;
	local[17]= NIL;
	local[18]= NIL;
	local[19]= NIL;
	local[20]= NIL;
WHL4503:
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX4504;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[21];
	local[17] = w;
	local[16] = NIL;
WHL4508:
	if (local[10]==NIL) goto WHX4509;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10] = (w)->c.cons.cdr;
	w = local[21];
	local[18] = w;
	storeglobal(fqv[26],local[17]);
	local[21]= local[18];
	storeglobal(fqv[27],local[21]);
	local[21]= local[17];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(*ftab[2])(ctx,2,local+21,&ftab[2],fqv[28]); /*face+*/
	local[19] = w;
	ctx->vsp=local+21;
	local[21]= makeclosure(codevec,quotevec,CLO4514,env,argv,local);
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(*ftab[3])(ctx,2,local+21,&ftab[3],fqv[29]); /*member-if*/
	if (w==NIL) goto IF4512;
	local[21]= fqv[50];
	ctx->vsp=local+22;
	w=(*ftab[4])(ctx,1,local+21,&ftab[4],fqv[31]); /*break*/
	local[21]= w;
	goto IF4513;
IF4512:
	local[21]= loadglobal(fqv[16]);
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(*ftab[5])(ctx,2,local+21,&ftab[5],fqv[32]); /*collect-instances*/
	local[19] = w;
	local[21]= local[19];
IF4513:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON4516;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	local[22]= local[10];
	ctx->vsp=local+23;
	w=(pointer)NCONC(ctx,2,local+21); /*nconc*/
	w = NIL;
	ctx->vsp=local+21;
	local[21]=w;
	goto BLK4507;
	goto CON4515;
CON4516:
	local[21]= local[18];
	w = local[16];
	ctx->vsp=local+22;
	local[16] = cons(ctx,local[21],w);
	local[21]= local[16];
	goto CON4515;
CON4517:
	local[21]= NIL;
CON4515:
	goto WHL4508;
WHX4509:
	local[21]= NIL;
BLK4510:
	local[21]= fqv[51];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
BLK4507:
	local[10] = local[16];
	goto WHL4503;
WHX4504:
	local[21]= NIL;
BLK4505:
	w = local[21];
	w=local[10];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK4435:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4476(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	w = ((env->c.clo.env2[11])==(local[0])?T:NIL);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4502(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[18];
	local[1]= fqv[52];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[53];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4514(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[35]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*shadow-intersection*/
static pointer F4308shadow_intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F4307project_shadow(ctx,2,local+0); /*project-shadow*/
	local[0]= w;
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)F4307project_shadow(ctx,2,local+1); /*project-shadow*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,2,local+0,&ftab[13],fqv[54]); /*face**/
	local[0]= w;
BLK4518:
	ctx->vsp=local; return(local[0]);}

/*closest-shadow*/
static pointer F4309closest_shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[55];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= argv[1];
	local[3]= fqv[22];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,1,local+3); /*v-*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[1];
	local[8]= fqv[56];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= NIL;
	w = NIL;
	local[0]= w;
BLK4519:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___shadow(ctx,n,argv,env)
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
	local[0]= fqv[57];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF4520;
	local[0]= fqv[58];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[59],w);
	goto IF4521;
IF4520:
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF4521:
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compmacro(ctx,fqv[62],module,F4310,fqv[63]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[64],module,F4299polygon_in_contact_p,fqv[65]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[66],module,F4300make_edges_from_vertices,fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F4301orthogonally_visible_faces,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F4302make_polygon,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F4303make_face_from_edge_loop,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F4304change_to_hole,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F4305project_shadow1,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F4306remove_inner_loop,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F4307project_shadow,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[82],module,F4308shadow_intersection,fqv[83]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[84],module,F4309closest_shadow,fqv[85]);
	local[0]= fqv[86];
	local[1]= fqv[87];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[88]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<15; i++) ftab[i]=fcallx;
}
