/* ./object.c :  entry=object */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Thu Jul 4 11:58:33 JST 2019) */
#include "eus.h"
#include "object.h"
#pragma init (register_object)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___object();
extern pointer build_quote_vector();
static int register_object()
  { add_module_initializer("___object", ___object);}

static pointer F3592metaclass_name();
static pointer F3595metaclass_vars();

/*metaclass-name*/
static pointer F3592metaclass_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[0]));
	local[0]= w;
BLK3625:
	ctx->vsp=local; return(local[0]);}

/*metaclass-vars*/
static pointer F3595metaclass_vars(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[1]));
	local[0]= w;
BLK3640:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M3659object_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3663;}
	local[0]= T;
ENT3663:
ENT3662:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= local[0];
	local[3]= fqv[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)GETCLASS(ctx,1,local+4); /*class*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F3592metaclass_name(ctx,1,local+4); /*metaclass-name*/
	local[4]= w;
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)ADDRESS(ctx,1,local+5); /*system:address*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,4,local+2); /*format*/
	local[2]= NIL;
	local[3]= local[1];
WHL3709:
	if (local[3]==NIL) goto WHX3710;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[0];
	local[5]= fqv[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	goto WHL3709;
WHX3710:
	local[4]= NIL;
BLK3711:
	w = NIL;
	local[2]= fqv[4];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	w = argv[0];
	local[0]= w;
BLK3660:
	ctx->vsp=local; return(local[0]);}

/*:warning*/
static pointer M3773object_warning(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
RST3776:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-3);
	local[1]= (pointer)get_sym_func(fqv[5]);
	local[2]= argv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK3774:
	ctx->vsp=local; return(local[0]);}

/*:error*/
static pointer M3798object_error(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST3801:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[6]);
	local[2]= argv[0];
	local[3]= fqv[7];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= fqv[8];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[9]); /*reploop*/
	local[0]= w;
BLK3799:
	ctx->vsp=local; return(local[0]);}

/*:slots*/
static pointer M3828object_slots(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F3595metaclass_vars(ctx,1,local+0); /*metaclass-vars*/
	local[0]= w;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
WHL3884:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX3885;
	local[4]= local[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)GETCLASS(ctx,1,local+6); /*class*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SLOT(ctx,3,local+5); /*slot*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL3884;
WHX3885:
	local[4]= NIL;
BLK3886:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK3829:
	ctx->vsp=local; return(local[0]);}

/*:methods*/
static pointer M3934object_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT3939;}
	local[0]= fqv[10];
ENT3939:
ENT3938:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[11]);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	local[3]= fqv[12];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[0]= w;
BLK3936:
	ctx->vsp=local; return(local[0]);}

/*:super*/
static pointer M3968object_super(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	local[1]= fqv[13];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK3969:
	ctx->vsp=local; return(local[0]);}

/*:get-val*/
static pointer M3989object_get_val(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SLOT(ctx,3,local+0); /*slot*/
	local[0]= w;
BLK3990:
	ctx->vsp=local; return(local[0]);}

/*:set-val*/
static pointer M4012object_set_val(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)GETCLASS(ctx,1,local+1); /*class*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SETSLOT(ctx,4,local+0); /*setslot*/
	local[0]= w;
BLK4013:
	ctx->vsp=local; return(local[0]);}

/*:plist*/
static pointer M4046propertied_object_plist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4050;}
	local[0]= NIL;
ENT4050:
ENT4049:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF4066;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF4067;
IF4066:
	local[1]= argv[0]->c.obj.iv[0];
IF4067:
	w = local[1];
	local[0]= w;
BLK4047:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M4080propertied_object_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK4081:
	ctx->vsp=local; return(local[0]);}

/*:put*/
static pointer M4105propertied_object_put(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF4136;
	local[1]= local[0];
	local[2]= fqv[14];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF4137;
IF4136:
	local[1]= argv[2];
	w = argv[3];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	w = argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[0] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[0];
IF4137:
	w = argv[3];
	local[0]= w;
BLK4106:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M4170propertied_object_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4174;}
	local[0]= NIL;
ENT4174:
ENT4173:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF4190;
	local[1]= argv[0];
	local[2]= fqv[15];
	local[3]= fqv[16];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF4191;
IF4190:
	local[1]= argv[0];
	local[2]= fqv[17];
	local[3]= fqv[16];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF4191:
	w = local[1];
	local[0]= w;
BLK4171:
	ctx->vsp=local; return(local[0]);}

/*:remprop*/
static pointer M4212propertied_object_remprop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF4241;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[18]); /*delete*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	goto IF4242;
IF4241:
	local[1]= NIL;
IF4242:
	w = local[1];
	local[0]= w;
BLK4213:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M4259propertied_object_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4263;}
	local[0]= T;
ENT4263:
ENT4262:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[16];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	if (local[3]==NIL) goto IF4289;
	local[4]= (pointer)get_sym_func(fqv[19]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[20]));
	local[7]= fqv[21];
	local[8]= local[0];
	local[9]= local[3];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,7,local+4); /*apply*/
	local[4]= w;
	goto IF4290;
IF4289:
	local[4]= (pointer)get_sym_func(fqv[19]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[20]));
	local[7]= fqv[21];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,6,local+4); /*apply*/
	local[4]= w;
IF4290:
	w = local[4];
	local[0]= w;
BLK4260:
	ctx->vsp=local; return(local[0]);}

/*:new*/
static pointer M4343metaclass_new(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
BLK4344:
	ctx->vsp=local; return(local[0]);}

/*:super*/
static pointer M4360metaclass_super(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK4361:
	ctx->vsp=local; return(local[0]);}

/*:methods*/
static pointer M4376metaclass_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK4377:
	ctx->vsp=local; return(local[0]);}

/*:method*/
static pointer M4392metaclass_method(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[22]); /*assoc*/
	local[0]= w;
BLK4393:
	ctx->vsp=local; return(local[0]);}

/*:method-names*/
static pointer M4413metaclass_method_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4417;}
	local[0]= fqv[23];
ENT4417:
ENT4416:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[24]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[25]); /*string-upcase*/
	local[0] = w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO4447,env,argv,local);
	local[2]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[0]= w;
BLK4414:
	ctx->vsp=local; return(local[0]);}

/*:all-methods*/
static pointer M4453metaclass_all_methods(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[2]==NIL) goto IF4466;
	local[0]= argv[0]->c.obj.iv[7];
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= fqv[26];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
	goto IF4467;
IF4466:
	local[0]= argv[0]->c.obj.iv[7];
IF4467:
	w = local[0];
	local[0]= w;
BLK4454:
	ctx->vsp=local; return(local[0]);}

/*:all-method-names*/
static pointer M4482metaclass_all_method_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT4486;}
	local[0]= fqv[27];
ENT4486:
ENT4485:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0];
	local[3]= fqv[28];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	if (argv[0]->c.obj.iv[2]==NIL) goto IF4521;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= fqv[12];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF4522;
IF4521:
	local[2]= NIL;
IF4522:
	local[3]= local[1];
	w = local[2];
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK4483:
	ctx->vsp=local; return(local[0]);}

/*:slots*/
static pointer M4544metaclass_slots(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK4545:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M4560metaclass_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK4561:
	ctx->vsp=local; return(local[0]);}

/*:cid*/
static pointer M4576metaclass_cid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4577:
	ctx->vsp=local; return(local[0]);}

/*:cix*/
static pointer M4592metaclass_cix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK4593:
	ctx->vsp=local; return(local[0]);}

/*:sub*/
static pointer M4608metaclass_sub(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	ctx->vsp=local+2;
	w=(pointer)LISTALLCLASSES(ctx,0,local+2); /*system:list-all-classes*/
	local[2]= w;
WHL4648:
	if (local[2]==NIL) goto WHX4649;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[13];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto IF4697;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF4698;
IF4697:
	local[3]= NIL;
IF4698:
	goto WHL4648;
WHX4649:
	local[3]= NIL;
BLK4650:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK4609:
	ctx->vsp=local; return(local[0]);}

/*:subclasses*/
static pointer M4729metaclass_subclasses(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[29];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK4730:
	ctx->vsp=local; return(local[0]);}

/*:hierarchy*/
static pointer M4748metaclass_hierarchy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[29];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
WHL4791:
	if (local[2]==NIL) goto WHX4792;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	goto WHL4791;
WHX4792:
	local[3]= NIL;
BLK4793:
	w = NIL;
	local[1]= argv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK4749:
	ctx->vsp=local; return(local[0]);}

/*:superclasses*/
static pointer M4868metaclass_superclasses(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL4898:
	if (local[1]==NIL) goto WHX4899;
	local[2]= local[1];
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= local[1];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	goto WHL4898;
WHX4899:
	local[2]= NIL;
BLK4900:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK4869:
	ctx->vsp=local; return(local[0]);}

/*:add-method*/
static pointer M4934metaclass_add_method(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[22]); /*assoc*/
	if (w!=NIL) goto IF4949;
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[7];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[7] = cons(ctx,local[0],w);
	local[0]= argv[0]->c.obj.iv[7];
	goto IF4950;
IF4949:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[22]); /*assoc*/
	local[0]= w;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)RPLACD(ctx,2,local+0); /*rplacd*/
	local[0]= w;
IF4950:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK4935:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO4447(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.car;
	local[0]= env->c.clo.env2[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[31]); /*symbol-name*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[32]); /*substringp*/
	if (w==NIL) goto IF5016;
	local[0]= argv[0];
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF5017;
IF5016:
	local[0]= NIL;
IF5017:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M5053load_module_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5057;}
	local[0]= T;
ENT5057:
ENT5056:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[19]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[20]));
	local[5]= fqv[21];
	local[6]= local[0];
	local[7]= loadglobal(fqv[24]);
	local[8]= fqv[33];
	local[9]= argv[0]->c.obj.iv[5];
	local[10]= fqv[34];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,4,local+7); /*concatenate*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK5054:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___object(ctx,n,argv,env)
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
	local[0]= fqv[35];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[36];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF5101;
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[38],w);
	goto IF5102;
IF5101:
	local[0]= fqv[39];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF5102:
	local[0]= fqv[40];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F3592metaclass_name,fqv[42]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[43],module,F3595metaclass_vars,fqv[44]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3659object_prin1,fqv[21],fqv[45],fqv[46]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3773object_warning,fqv[7],fqv[45],fqv[47]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3798object_error,fqv[48],fqv[45],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3828object_slots,fqv[50],fqv[45],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3934object_methods,fqv[52],fqv[45],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3968object_super,fqv[13],fqv[45],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M3989object_get_val,fqv[55],fqv[45],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4012object_set_val,fqv[57],fqv[45],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4046propertied_object_plist,fqv[59],fqv[60],fqv[61]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4080propertied_object_get,fqv[17],fqv[60],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4105propertied_object_put,fqv[15],fqv[60],fqv[63]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4170propertied_object_name,fqv[16],fqv[60],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4212propertied_object_remprop,fqv[65],fqv[60],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4259propertied_object_prin1,fqv[21],fqv[60],fqv[67]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4343metaclass_new,fqv[68],fqv[69],fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4360metaclass_super,fqv[13],fqv[69],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4376metaclass_methods,fqv[52],fqv[69],fqv[72]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4392metaclass_method,fqv[73],fqv[69],fqv[74]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4413metaclass_method_names,fqv[28],fqv[69],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4453metaclass_all_methods,fqv[26],fqv[69],fqv[76]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4482metaclass_all_method_names,fqv[12],fqv[69],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4544metaclass_slots,fqv[50],fqv[69],fqv[78]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4560metaclass_name,fqv[16],fqv[69],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4576metaclass_cid,fqv[80],fqv[69],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4592metaclass_cix,fqv[82],fqv[69],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4608metaclass_sub,fqv[29],fqv[69],fqv[84]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4729metaclass_subclasses,fqv[85],fqv[69],fqv[86]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4748metaclass_hierarchy,fqv[30],fqv[69],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4868metaclass_superclasses,fqv[88],fqv[69],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M4934metaclass_add_method,fqv[90],fqv[69],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M5053load_module_prin1,fqv[21],fqv[92],fqv[93]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
