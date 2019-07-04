/* ./mathtran.c :  entry=mathtran */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "mathtran.h"
#pragma init (register_mathtran)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___mathtran();
extern pointer build_quote_vector();
static int register_mathtran()
  { add_module_initializer("___mathtran", ___mathtran);}

static pointer F68837expression();
static pointer F68839infix2prefix();
static pointer F68841read_aref();

/*expression*/
static pointer F68837expression(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT68865;}
	local[0]= NIL;
ENT68865:
ENT68864:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,FLET68887,env,argv,local);
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,FLET68889,env,argv,local);
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,FLET68891,env,argv,local);
	ctx->vsp=local+7;
	local[7]= makeclosure(codevec,quotevec,FLET68893,env,argv,local);
	ctx->vsp=local+8;
	local[8]= makeclosure(codevec,quotevec,FLET68895,env,argv,local);
	ctx->vsp=local+9;
	local[9]= makeclosure(codevec,quotevec,FLET68897,env,argv,local);
	ctx->vsp=local+10;
	local[10]= makeclosure(codevec,quotevec,FLET68899,env,argv,local);
	ctx->vsp=local+11;
	local[11]= makeclosure(codevec,quotevec,FLET68901,env,argv,local);
	local[12]= argv[0];
	w = local[10];
	ctx->vsp=local+13;
	w=FLET68899(ctx,1,local+12,w);
	local[12]= w;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	if (argv[0]==NIL) goto IF68947;
	local[12]= fqv[0];
	ctx->vsp=local+13;
	w=(pointer)SIGERROR(ctx,1,local+12); /*error*/
	local[12]= w;
	goto IF68948;
IF68947:
	local[12]= NIL;
IF68948:
	local[12]= local[2];
	w = local[11];
	ctx->vsp=local+13;
	w=FLET68901(ctx,1,local+12,w);
	local[0]= w;
BLK68862:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68887(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	local[2]= fqv[1];
	local[3]= (pointer)get_sym_func(fqv[2]);
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,4,local+0,&ftab[0],fqv[3]); /*assoc*/
	local[0]= w;
	if (local[0]==NIL) goto CON68992;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)RPLACA2(ctx,2,local+1); /*rplaca2*/
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON68990;
CON68992:
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[0] = w;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	w = env->c.clo.env2[3];
	ctx->vsp=local+2;
	env->c.clo.env2[3] = cons(ctx,local[1],w);
	local[1]= local[0];
	goto CON68990;
CON69026:
	local[1]= NIL;
CON68990:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68889(ctx,n,argv,env)
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
	local[1]= NIL;
	local[2]= NIL;
	w = local[0];
	if (!iscons(w)) goto CON69115;
	local[3]= local[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET68895(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	if (local[2]==NIL) goto IF69163;
	local[3]= fqv[4];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF69164;
IF69163:
	local[3]= NIL;
IF69164:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69113;
CON69115:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto CON69176;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[6]!=local[3]) goto CON69230;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[9];
	ctx->vsp=local+4;
	w=FLET68897(ctx,1,local+3,w);
	local[1] = w;
	local[3]= fqv[6];
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	if (env->c.clo.env2[0]!=NIL) goto IF69276;
	local[3]= local[2];
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET68887(ctx,1,local+3,w);
	local[2] = w;
	local[3]= local[2];
	goto IF69277;
IF69276:
	local[3]= NIL;
IF69277:
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69228;
CON69230:
	local[3]= local[0];
	local[4]= local[1];
	w = env->c.clo.env2[9];
	ctx->vsp=local+5;
	w=FLET68897(ctx,1,local+4,w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET68887(ctx,1,local+3,w);
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69228;
CON69300:
	local[3]= NIL;
CON69228:
	goto CON69113;
CON69176:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69113;
CON69318:
	local[3]= NIL;
CON69113:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68891(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[5];
	ctx->vsp=local+4;
	w=FLET68889(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[7]!=local[3]) goto CON69393;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[5];
	ctx->vsp=local+4;
	w=FLET68889(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w = local[1];
	w = local[1];
	if (!isint(w)) goto CON69453;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)10L);
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto CON69453;
	local[3]= fqv[8];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[2] = w;
	w = local[0];
	if (!!iscons(w)) goto CON69476;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[1];
WHL69505:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX69506;
	local[5]= local[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL69505;
WHX69506:
	local[5]= NIL;
BLK69507:
	w = NIL;
	local[3]= local[2];
	w = env->c.clo.env2[4];
	ctx->vsp=local+4;
	w=FLET68887(ctx,1,local+3,w);
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69474;
CON69476:
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[1];
WHL69567:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX69568;
	local[5]= local[2];
	local[6]= fqv[9];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL69567;
WHX69568:
	local[5]= NIL;
BLK69569:
	w = NIL;
	local[3]= fqv[10];
	local[4]= fqv[9];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69474;
CON69540:
	local[3]= NIL;
CON69474:
	goto CON69451;
CON69453:
	local[3]= fqv[11];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69451;
CON69617:
	local[3]= NIL;
CON69451:
	goto CON69391;
CON69393:
	w = local[0];
	if (!isnum(w)) goto CON69629;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69391;
CON69629:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69391;
CON69638:
	local[3]= NIL;
CON69391:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68893(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[6];
	ctx->vsp=local+4;
	w=FLET68891(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= local[1];
	w = fqv[12];
	if (memq(local[3],w)==NIL) goto CON69725;
WHL69736:
	local[3]= local[1];
	w = fqv[13];
	if (memq(local[3],w)==NIL) goto WHX69737;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[0] = w;
WHL69760:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (local[1]!=local[3]) goto WHX69761;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[6];
	ctx->vsp=local+4;
	w=FLET68891(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	goto WHL69760;
WHX69761:
	local[3]= NIL;
BLK69762:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	goto WHL69736;
WHX69737:
	local[3]= NIL;
BLK69738:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69723;
CON69725:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[3]= w;
	goto CON69723;
CON69841:
	local[3]= NIL;
CON69723:
	w = local[3];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68895(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
	w = fqv[14];
	if (memq(local[3],w)==NIL) goto IF69877;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[3]= argv[0];
	goto IF69878;
IF69877:
	local[3]= NIL;
IF69878:
	local[3]= argv[0];
	w = env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=FLET68893(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w = local[1];
	local[3]= local[0];
	if (fqv[15]!=local[3]) goto IF69942;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[1] = w;
	local[3]= local[1];
	goto IF69943;
IF69942:
	local[3]= NIL;
IF69943:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w = fqv[16];
	if (memq(local[3],w)==NIL) goto IF69962;
	local[3]= fqv[17];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[1] = w;
WHL69992:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	local[3]= local[0];
	w = fqv[18];
	if (memq(local[3],w)==NIL) goto WHX69993;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	w = env->c.clo.env2[7];
	ctx->vsp=local+4;
	w=FLET68893(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[0];
	if (fqv[15]!=local[3]) goto IF70061;
	local[3]= fqv[15];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[2] = w;
	local[3]= local[2];
	goto IF70062;
IF70061:
	local[3]= NIL;
IF70062:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	goto WHL69992;
WHX69993:
	local[3]= NIL;
BLK69994:
	goto IF69963;
IF69962:
	local[3]= NIL;
IF69963:
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68897(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
WHL70114:
	if (argv[0]==NIL) goto WHX70115;
	local[2]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+3;
	w=FLET68895(ctx,1,local+2,w);
	local[2]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	local[2]= local[0];
	w = local[1];
	ctx->vsp=local+3;
	local[1] = cons(ctx,local[2],w);
	goto WHL70114;
WHX70115:
	local[2]= NIL;
BLK70116:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68899(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET68895(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w = local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	w = fqv[19];
	if (memq(local[3],w)==NIL) goto IF70291;
	local[3]= argv[0];
	w = env->c.clo.env2[8];
	ctx->vsp=local+4;
	w=FLET68895(ctx,1,local+3,w);
	local[3]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w = local[2];
	local[3]= local[1];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[3]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[0] = w;
	local[3]= local[0];
	goto IF70292;
IF70291:
	local[3]= NIL;
IF70292:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,2,local+3,&ftab[1],fqv[5]); /*values*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET68901(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	argv[0] = w;
	local[0]= NIL;
	local[1]= NIL;
	local[2]= env->c.clo.env2[3];
WHL70421:
	if (local[2]==NIL) goto WHX70422;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF70470;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF70471;
IF70470:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)NSUBST(ctx,3,local+3); /*nsubst*/
	local[3]= w;
IF70471:
	goto WHL70421;
WHX70422:
	local[3]= NIL;
BLK70423:
	w = NIL;
	if (local[0]==NIL) goto IF70527;
	local[1]= fqv[21];
	local[2]= local[0];
	w = argv[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF70528;
IF70527:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
IF70528:
	w = local[1];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*infix2prefix*/
static pointer F68839infix2prefix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT70553;}
	local[0]= NIL;
ENT70553:
ENT70552:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)READ(ctx,1,local+1); /*read*/
	local[1]= w;
	w = local[1];
	if (!issymbol(w)) goto CON70582;
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	local[3]= T;
	ctx->vsp=local+4;
	w=(pointer)F68837expression(ctx,2,local+2); /*expression*/
	local[2]= w;
	goto CON70580;
CON70582:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[22]!=local[2]) goto CON70595;
	local[2]= fqv[23];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)F68837expression(ctx,2,local+4); /*expression*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON70580;
CON70595:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[22]!=local[2]) goto CON70626;
	local[2]= fqv[24];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,2,local+3); /*list*/
	local[3]= w;
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)F68837expression(ctx,2,local+3); /*expression*/
	local[3]= w;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,1,local+4,&ftab[2],fqv[25]); /*cdddr*/
	local[4]= w;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)F68837expression(ctx,2,local+4); /*expression*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON70580;
CON70626:
	local[2]= local[1];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)F68837expression(ctx,2,local+2); /*expression*/
	local[2]= w;
	goto CON70580;
CON70667:
	local[2]= NIL;
CON70580:
	w = local[2];
	local[0]= w;
BLK70550:
	ctx->vsp=local; return(local[0]);}

/*read-aref*/
static pointer F68841read_aref(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT70679;}
	local[0]= NIL;
ENT70679:
ENT70678:
	if (n>2) maerror();
	local[1]= fqv[6];
	local[2]= makeint((eusinteger_t)93L);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,2,local+2,&ftab[3],fqv[26]); /*read-delimited-list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK70676:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___mathtran(ctx,n,argv,env)
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
	local[0]= fqv[27];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF70711;
	local[0]= fqv[28];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[29],w);
	goto IF70712;
IF70711:
	local[0]= fqv[30];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF70712:
	ctx->vsp=local+0;
	compfun(ctx,fqv[31],module,F68837expression,fqv[32]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F68839infix2prefix,fqv[34]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[35],module,F68841read_aref,fqv[36]);
	local[0]= makeint((eusinteger_t)37L);
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint((eusinteger_t)91L);
	local[1]= fqv[35];
	ctx->vsp=local+2;
	w=(pointer)SETMACROCH(ctx,2,local+0); /*set-macro-character*/
	local[0]= makeint((eusinteger_t)93L);
	local[1]= makeint((eusinteger_t)41L);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[37]); /*set-syntax-from-char*/
	local[0]= fqv[38];
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,2,local+0,&ftab[5],fqv[40]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<6; i++) ftab[i]=fcallx;
}
