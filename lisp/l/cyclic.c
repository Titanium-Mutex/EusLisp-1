/* ./cyclic.c :  entry=cyclic */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "cyclic.h"
#pragma init (register_cyclic)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___cyclic();
extern pointer build_quote_vector();
static int register_cyclic()
  { add_module_initializer("___cyclic", ___cyclic);}

static pointer F77371timer_func();
static pointer F77373itimer_handler();
static pointer F77375find_itimer();
static pointer F77377init_cyclic();
static pointer F77379start_timer();
static pointer F77381stop_timer();

/*:init*/
static pointer M77469itimer_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT77473;}
	local[0]= NIL;
ENT77473:
ENT77472:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	argv[0]->c.obj.iv[8] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[2] = argv[0]->c.obj.iv[1];
	argv[0]->c.obj.iv[7] = T;
	argv[0]->c.obj.iv[4] = local[0];
	argv[0]->c.obj.iv[9] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[11] = NIL;
	if (argv[0]->c.obj.iv[3]!=NIL) goto IF77517;
	ctx->vsp=local+1;
	w=(pointer)MAKE_SEMAPHORE(ctx,0,local+1); /*system:make-semaphore*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= argv[0]->c.obj.iv[3];
	goto IF77518;
IF77517:
	local[1]= NIL;
IF77518:
	if (argv[0]->c.obj.iv[10]!=NIL) goto IF77535;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)MAKE_THREAD(ctx,1,local+1); /*system:make-thread*/
	local[1]= fqv[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)AFUNCALL(ctx,2,local+1); /*thread*/
	argv[0]->c.obj.iv[10] = w;
	local[1]= argv[0]->c.obj.iv[10];
	goto IF77536;
IF77535:
	local[1]= NIL;
IF77536:
	if (argv[0]->c.obj.iv[5]!=NIL) goto IF77559;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	argv[0]->c.obj.iv[5] = w;
	local[1]= argv[0]->c.obj.iv[5];
	goto IF77560;
IF77559:
	local[1]= NIL;
IF77560:
	w = argv[0];
	local[0]= w;
BLK77470:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M77580itimer_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[3]); /*delete*/
	local[0]= w;
	storeglobal(fqv[2],w);
	argv[0]->c.obj.iv[11] = T;
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)SEMA_POST(ctx,1,local+0); /*system:sema-post*/
	local[0]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+1;
	w=(pointer)WAIT_AFUNCALL(ctx,1,local+0); /*system:wait-thread*/
	local[0]= w;
BLK77581:
	ctx->vsp=local; return(local[0]);}

/*:priority*/
static pointer M77618itimer_priority(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT77622;}
	local[0]= NIL;
ENT77622:
ENT77621:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[4];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK77619:
	ctx->vsp=local; return(local[0]);}

/*:running*/
static pointer M77645itimer_running(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK77646:
	ctx->vsp=local; return(local[0]);}

/*:tick*/
static pointer M77661itimer_tick(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]==NIL) goto IF77675;
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[5]); /*zerop*/
	if (w==NIL) goto IF77675;
	argv[0]->c.obj.iv[2] = argv[0]->c.obj.iv[1];
	local[0]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[8] = w;
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= makeflt(9.9999999999999977795540e-02);
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,3,local+0); /***/
	argv[0]->c.obj.iv[6] = w;
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)SEMA_POST(ctx,1,local+0); /*system:sema-post*/
	local[0]= w;
	goto IF77676;
IF77675:
	local[0]= NIL;
IF77676:
	w = local[0];
	local[0]= w;
BLK77662:
	ctx->vsp=local; return(local[0]);}

/*:func*/
static pointer M77732itimer_func(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT77736;}
	local[0]= NIL;
ENT77736:
ENT77735:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF77752;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF77753;
IF77752:
	local[1]= NIL;
IF77753:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK77733:
	ctx->vsp=local; return(local[0]);}

/*:args*/
static pointer M77768itimer_args(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST77771:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	argv[0]->c.obj.iv[5] = local[0];
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK77769:
	ctx->vsp=local; return(local[0]);}

/*:count*/
static pointer M77794itimer_count(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK77795:
	ctx->vsp=local; return(local[0]);}

/*:stop*/
static pointer M77810itimer_stop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[7] = NIL;
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK77811:
	ctx->vsp=local; return(local[0]);}

/*:start*/
static pointer M77830itimer_start(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[7] = T;
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK77831:
	ctx->vsp=local; return(local[0]);}

/*:interval*/
static pointer M77850itimer_interval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT77854;}
	local[0]= NIL;
ENT77854:
ENT77853:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF77870;
	local[1]= local[0];
	local[2]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+3;
	w=(pointer)QUOTIENT(ctx,2,local+1); /*/*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)ROUND(ctx,1,local+1); /*round*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0]->c.obj.iv[1];
	goto IF77871;
IF77870:
	local[1]= NIL;
IF77871:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+3;
	w=(pointer)TIMES(ctx,2,local+1); /***/
	local[0]= w;
BLK77851:
	ctx->vsp=local; return(local[0]);}

/*:run*/
static pointer M77893itimer_run(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)AREF(ctx,2,local+1); /*aref*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[9] = w;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ASET(ctx,3,local+0); /*aset*/
	if (argv[0]->c.obj.iv[4]==NIL) goto IF77926;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	goto IF77927;
IF77926:
	local[0]= NIL;
IF77927:
	w = local[0];
	local[0]= w;
BLK77894:
	ctx->vsp=local; return(local[0]);}

/*:thread-waiting*/
static pointer M77937itimer_thread_waiting(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
WHL77950:
	if (argv[0]->c.obj.iv[11]!=NIL) goto WHX77951;
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)SEMA_WAIT(ctx,1,local+0); /*system:sema-wait*/
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	goto WHL77950;
WHX77951:
	local[0]= NIL;
BLK77952:
	w = local[0];
	local[0]= w;
BLK77938:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M78024behavior_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST78027:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[7]);
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[8]));
	local[4]= fqv[9];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	argv[0]->c.obj.iv[7] = NIL;
	ctx->vsp=local+1;
	w=(pointer)MAKE_SEMAPHORE(ctx,0,local+1); /*system:make-semaphore*/
	argv[0]->c.obj.iv[12] = w;
	w = argv[0];
	local[0]= w;
BLK78025:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M78069behavior_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[11] = T;
	local[0]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+1;
	w=(pointer)SEMA_POST(ctx,1,local+0); /*system:sema-post*/
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[8]));
	local[2]= fqv[10];
	ctx->vsp=local+3;
	w=(pointer)SENDMESSAGE(ctx,3,local+0); /*send-message*/
	local[0]= w;
BLK78070:
	ctx->vsp=local; return(local[0]);}

/*:initiate*/
static pointer M78101behavior_initiate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]==NIL) goto CON78116;
	local[0]= NIL;
	goto CON78114;
CON78116:
	local[0]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+1;
	w=(pointer)SEMA_POST(ctx,1,local+0); /*system:sema-post*/
	local[0]= T;
	goto CON78114;
CON78121:
	local[0]= NIL;
CON78114:
	w = local[0];
	local[0]= w;
BLK78102:
	ctx->vsp=local; return(local[0]);}

/*:starting*/
static pointer M78130behavior_starting(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[7] = T;
	argv[0]->c.obj.iv[8] = makeint((eusinteger_t)0L);
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK78131:
	ctx->vsp=local; return(local[0]);}

/*:thread-waiting*/
static pointer M78152behavior_thread_waiting(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
WHL78165:
	if (argv[0]->c.obj.iv[11]!=NIL) goto WHX78166;
	local[0]= argv[0]->c.obj.iv[12];
	ctx->vsp=local+1;
	w=(pointer)SEMA_WAIT(ctx,1,local+0); /*system:sema-wait*/
	if (argv[0]->c.obj.iv[11]!=NIL) goto IF78178;
	local[0]= argv[0];
	local[1]= fqv[11];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
WHL78193:
	if (argv[0]->c.obj.iv[7]==NIL) goto WHX78194;
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)SEMA_WAIT(ctx,1,local+0); /*system:sema-wait*/
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	goto WHL78193;
WHX78194:
	local[0]= NIL;
BLK78195:
	goto IF78179;
IF78178:
	local[0]= NIL;
IF78179:
	goto WHL78165;
WHX78166:
	local[0]= NIL;
BLK78167:
	w = local[0];
	local[0]= w;
BLK78153:
	ctx->vsp=local; return(local[0]);}

/*timer-func*/
static pointer F77371timer_func(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= T;
	local[1]= fqv[13];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK78212:
	ctx->vsp=local; return(local[0]);}

/*itimer-handler*/
static pointer F77373itimer_handler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
WHL78240:
	if (T==NIL) goto WHX78241;
	local[0]= loadglobal(fqv[14]);
	ctx->vsp=local+1;
	w=(pointer)SEMA_WAIT(ctx,1,local+0); /*system:sema-wait*/
	local[0]= loadglobal(fqv[15]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	storeglobal(fqv[15],w);
	if (loadglobal(fqv[16])==NIL) goto IF78263;
	local[0]= NIL;
	local[1]= loadglobal(fqv[2]);
WHL78290:
	if (local[1]==NIL) goto WHX78291;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[17];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	goto WHL78290;
WHX78291:
	local[2]= NIL;
BLK78292:
	w = NIL;
	local[0]= w;
	goto IF78264;
IF78263:
	local[0]= NIL;
IF78264:
	goto WHL78240;
WHX78241:
	local[0]= NIL;
BLK78242:
	w = local[0];
	local[0]= w;
BLK78232:
	ctx->vsp=local; return(local[0]);}

/*find-itimer*/
static pointer F77375find_itimer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO78359,env,argv,local);
	local[1]= loadglobal(fqv[2]);
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[18]); /*find-if*/
	local[0]= w;
BLK78348:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO78359(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[19];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*deftimer*/
static pointer F78384(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST78387:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= fqv[20];
	local[2]= fqv[21];
	local[3]= fqv[22];
	local[4]= fqv[23];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[24];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[25];
	local[4]= fqv[26];
	local[5]= fqv[21];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[27];
	local[6]= fqv[21];
	local[7]= fqv[25];
	local[8]= fqv[28];
	local[9]= fqv[29];
	local[10]= fqv[23];
	local[11]= argv[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[30];
	local[11]= argv[1];
	local[12]= fqv[31];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
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
	local[9]= fqv[32];
	local[10]= argv[1];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[33];
	local[11]= fqv[27];
	local[12]= fqv[24];
	local[13]= fqv[23];
	local[14]= argv[1];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[32];
	local[13]= fqv[31];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
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
	local[4]= fqv[34];
	local[5]= fqv[27];
	local[6]= argv[0];
	local[7]= fqv[35];
	local[8]= fqv[21];
	local[9]= fqv[9];
	local[10]= argv[2];
	local[11]= fqv[24];
	local[12]= local[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[2];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[36];
	local[6]= fqv[21];
	local[7]= fqv[19];
	local[8]= fqv[23];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK78385:
	ctx->vsp=local; return(local[0]);}

/*init-cyclic*/
static pointer F77377init_cyclic(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint((eusinteger_t)3L);
	ctx->vsp=local+1;
	w=(pointer)MAKE_THREAD(ctx,1,local+0); /*system:make-thread*/
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)AFUNCALL_NO_WAIT(ctx,1,local+0); /*system:thread-no-wait*/
	local[0]= makeint((eusinteger_t)14L);
	local[1]= loadglobal(fqv[14]);
	local[2]= makeint((eusinteger_t)20L);
	ctx->vsp=local+3;
	w=(pointer)SIGNAL(ctx,3,local+0); /*unix:signal*/
	local[0]= w;
BLK78632:
	ctx->vsp=local; return(local[0]);}

/*start-timer*/
static pointer F77379start_timer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)1L);
	local[2]= makeflt(9.9999999999999977795540e-02);
	ctx->vsp=local+3;
	w=(pointer)SETITIMER(ctx,3,local+0); /*unix:setitimer*/
	local[0]= w;
BLK78652:
	ctx->vsp=local; return(local[0]);}

/*stop-timer*/
static pointer F77381stop_timer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)SETITIMER(ctx,3,local+0); /*unix:setitimer*/
	local[0]= w;
BLK78663:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___cyclic(ctx,n,argv,env)
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
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[40];
	local[1]= fqv[41];
	local[2]= makeflt(9.9999999999999977795540e-02);
	local[3]= fqv[42];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[2];
	local[1]= fqv[43];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[16];
	local[1]= fqv[43];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[14];
	local[1]= fqv[43];
	ctx->vsp=local+2;
	w=(pointer)MAKE_SEMAPHORE(ctx,0,local+2); /*system:make-semaphore*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[15];
	local[1]= fqv[43];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[31];
	local[1]= fqv[43];
	local[2]= fqv[31];
	local[3]= fqv[44];
	local[4]= loadglobal(fqv[45]);
	local[5]= fqv[46];
	local[6]= fqv[47];
	local[7]= fqv[48];
	local[8]= NIL;
	local[9]= fqv[49];
	local[10]= NIL;
	local[11]= fqv[50];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[51];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,13,local+2,&ftab[3],fqv[52]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77469itimer_init,fqv[9],fqv[31],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77580itimer_delete,fqv[10],fqv[31],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77618itimer_priority,fqv[4],fqv[31],fqv[55]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77645itimer_running,fqv[56],fqv[31],fqv[57]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77661itimer_tick,fqv[17],fqv[31],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77732itimer_func,fqv[59],fqv[31],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77768itimer_args,fqv[61],fqv[31],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77794itimer_count,fqv[63],fqv[31],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77810itimer_stop,fqv[65],fqv[31],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77830itimer_start,fqv[67],fqv[31],fqv[68]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77850itimer_interval,fqv[0],fqv[31],fqv[69]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77893itimer_run,fqv[6],fqv[31],fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M77937itimer_thread_waiting,fqv[12],fqv[31],fqv[71]);
	local[0]= fqv[72];
	local[1]= fqv[43];
	local[2]= fqv[72];
	local[3]= fqv[44];
	local[4]= loadglobal(fqv[31]);
	local[5]= fqv[46];
	local[6]= fqv[73];
	local[7]= fqv[48];
	local[8]= NIL;
	local[9]= fqv[49];
	local[10]= NIL;
	local[11]= fqv[50];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[51];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[3])(ctx,13,local+2,&ftab[3],fqv[52]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78024behavior_init,fqv[9],fqv[72],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78069behavior_delete,fqv[10],fqv[72],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78101behavior_initiate,fqv[76],fqv[72],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78130behavior_starting,fqv[11],fqv[72],fqv[78]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M78152behavior_thread_waiting,fqv[12],fqv[72],fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[1],module,F77371timer_func,fqv[80]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[37],module,F77373itimer_handler,fqv[81]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[22],module,F77375find_itimer,fqv[82]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[83],module,F78384,fqv[84]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[85],module,F77377init_cyclic,fqv[86]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[87],module,F77379start_timer,fqv[88]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[89],module,F77381stop_timer,fqv[90]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
