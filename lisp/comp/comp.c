/* ./comp.c :  entry=comp */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "comp.h"
#pragma init (register_comp)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___comp();
extern pointer build_quote_vector();
static int register_comp()
  { add_module_initializer("___comp", ___comp);}

static pointer F6924compiled_code_p();
static pointer F6941ovafp();
static pointer F6943class_symbolp();
static pointer F6945quoted_symbolp();
static pointer F6947proclaimed_special_p();
static pointer F6949proclaimed_global_p();
static pointer F6951object_variable_names();
static pointer F6953object_variable_type();
static pointer F6955coerce_type();
static pointer F6957check_arg();
static pointer F6959def_function_type();
static pointer F7014dump_function();
static pointer F7016comfile();
static pointer F7018compile_file();
static pointer F7020compile();
static pointer F7022compile_file_if_src_newer();
static pointer F7024comp_file_toplevel();

/*compiled-code-p*/
static pointer F6924compiled_code_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK7051:
	ctx->vsp=local; return(local[0]);}

/*ovafp*/
static pointer F6941ovafp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	if (local[0]==NIL) goto AND7107;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= (issymbol(w)?T:NIL);
AND7107:
	w = local[0];
	local[0]= w;
BLK7097:
	ctx->vsp=local; return(local[0]);}

/*class-symbolp*/
static pointer F6943class_symbolp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND7137;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	local[0]= w;
	if (w==NIL) goto AND7137;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	local[0]= w;
AND7137:
	w = local[0];
	local[0]= w;
BLK7127:
	ctx->vsp=local; return(local[0]);}

/*quoted-symbolp*/
static pointer F6945quoted_symbolp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (iscons(w)?T:NIL);
	if (local[0]==NIL) goto AND7168;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[0]= ((fqv[1])==(local[0])?T:NIL);
	if (local[0]==NIL) goto AND7168;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= (issymbol(w)?T:NIL);
AND7168:
	w = local[0];
	local[0]= w;
BLK7158:
	ctx->vsp=local; return(local[0]);}

/*proclaimed-special-p*/
static pointer F6947proclaimed_special_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint((eusinteger_t)3L);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
OR7217:
	w = local[0];
	local[0]= w;
BLK7201:
	ctx->vsp=local; return(local[0]);}

/*proclaimed-global-p*/
static pointer F6949proclaimed_global_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
BLK7226:
	ctx->vsp=local; return(local[0]);}

/*object-variable-names*/
static pointer F6951object_variable_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	w = argv[0];
	if (!issymbol(w)) goto IF7273;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SYMVALUE(ctx,1,local+4); /*symbol-value*/
	local[0] = w;
	local[4]= local[0];
	goto IF7274;
IF7273:
	local[0] = argv[0];
	local[4]= local[0];
IF7274:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)CLASSP(ctx,1,local+4); /*classp*/
	if (w==NIL) goto IF7295;
	local[1] = *(ovafptr(local[0],fqv[2]));
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[2] = w;
WHL7319:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)SUB1(ctx,1,local+4); /*1-*/
	local[2] = w;
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)GREQP(ctx,2,local+4); /*>=*/
	if (w==NIL) goto WHX7320;
	local[4]= local[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[4]= w;
	w = local[3];
	ctx->vsp=local+5;
	local[3] = cons(ctx,local[4],w);
	goto WHL7319;
WHX7320:
	local[4]= NIL;
BLK7321:
	goto IF7296;
IF7295:
	local[4]= NIL;
IF7296:
	w = local[3];
	local[0]= w;
BLK7248:
	ctx->vsp=local; return(local[0]);}

/*object-variable-type*/
static pointer F6953object_variable_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)CLASSP(ctx,1,local+0); /*classp*/
	if (w!=NIL) goto IF7374;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F6943class_symbolp(ctx,1,local+0); /*class-symbolp*/
	if (w==NIL) goto IF7385;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	argv[0] = w;
	local[0]= argv[0];
	goto IF7386;
IF7385:
	local[0]= fqv[3];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF7386:
	goto IF7375;
IF7374:
	local[0]= NIL;
IF7375:
	w = argv[1];
	if (!isnum(w)) goto IF7404;
	local[0]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(argv[1]);
	  w=(local[0]->c.vec.v[i]);}
	argv[1] = w;
	local[0]= argv[1];
	goto IF7405;
IF7404:
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[4]); /*position*/
	local[0]= w;
	if (local[0]!=NIL) goto IF7437;
	local[1]= loadglobal(fqv[5]);
	local[2]= fqv[6];
	local[3]= fqv[7];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF7438;
IF7437:
	local[1]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	argv[1] = w;
	local[1]= argv[1];
IF7438:
	w = local[1];
	local[0]= w;
IF7405:
	w = argv[1];
	if (!iscons(w)) goto IF7463;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF7464;
IF7463:
	local[0]= argv[1];
IF7464:
	w = local[0];
	local[0]= w;
BLK7355:
	ctx->vsp=local; return(local[0]);}

/*coerce-type*/
static pointer F6955coerce_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[8];
	if (memq(local[0],w)==NIL) goto CON7489;
	local[0]= fqv[9];
	goto CON7487;
CON7489:
	local[0]= argv[0];
	w = fqv[10];
	if (memq(local[0],w)==NIL) goto CON7501;
	local[0]= fqv[11];
	goto CON7487;
CON7501:
	local[0]= argv[0];
	goto CON7487;
CON7513:
	local[0]= NIL;
CON7487:
	w = local[0];
	local[0]= w;
BLK7477:
	ctx->vsp=local; return(local[0]);}

/*check-arg*/
static pointer F6957check_arg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7523;}
	local[0]= fqv[12];
ENT7523:
ENT7522:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto IF7539;
	local[1]= fqv[13];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[14]); /*warn*/
	local[1]= w;
	goto IF7540;
IF7539:
	local[1]= NIL;
IF7540:
	w = local[1];
	local[0]= w;
BLK7520:
	ctx->vsp=local; return(local[0]);}

/*def-function-type*/
static pointer F6959def_function_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL7581:
	if (local[1]==NIL) goto WHX7582;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[0];
	local[4]= fqv[15];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	goto WHL7581;
WHX7582:
	local[2]= NIL;
BLK7583:
	w = NIL;
	local[0]= w;
BLK7552:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M7668identifier_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7672;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7672:
ENT7671:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F6955coerce_type(ctx,1,local+1); /*coerce-type*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK7669:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M7698identifier_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7702;}
	local[0]= argv[0]->c.obj.iv[4];
ENT7702:
ENT7701:
	if (n>3) maerror();
	argv[0]->c.obj.iv[4] = local[0];
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK7699:
	ctx->vsp=local; return(local[0]);}

/*:binding*/
static pointer M7726identifier_binding(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT7730;}
	local[0]= argv[0]->c.obj.iv[2];
ENT7730:
ENT7729:
	if (n>3) maerror();
	argv[0]->c.obj.iv[2] = local[0];
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK7727:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M7754identifier_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	argv[0]->c.obj.iv[0] = argv[2];
	argv[0]->c.obj.iv[1] = T;
	argv[0]->c.obj.iv[2] = argv[3];
	argv[0]->c.obj.iv[3] = argv[4];
	argv[0]->c.obj.iv[4] = argv[5];
	w = argv[0];
	local[0]= w;
BLK7755:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M7815identifier_table_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7819;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7819:
ENT7818:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)ASSQ(ctx,2,local+1); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7816:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M7851identifier_table_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7855;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7855:
ENT7854:
	if (n>4) maerror();
	local[1]= NIL;
WHL7883:
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto WHX7884;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[3]->c.vec.v[i]);}
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ASSQ(ctx,2,local+2); /*assq*/
	local[1] = w;
	if (local[1]==NIL) goto IF7905;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK7852;
	goto IF7906;
IF7905:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[0] = w;
	local[2]= local[0];
IF7906:
	goto WHL7883;
WHX7884:
	local[2]= NIL;
BLK7885:
	w = local[2];
	local[0]= w;
BLK7852:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M7929identifier_table_enter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT7933;}
	local[0]= argv[0]->c.obj.iv[1];
ENT7933:
ENT7932:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	w = argv[2];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[4]->c.vec.v[i]);}
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	w = argv[2];
	local[0]= w;
BLK7930:
	ctx->vsp=local; return(local[0]);}

/*:enter-special*/
static pointer M7973identifier_table_enter_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[17];
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK7974:
	ctx->vsp=local; return(local[0]);}

/*:create-frame*/
static pointer M7994identifier_table_create_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK7995:
	ctx->vsp=local; return(local[0]);}

/*:pop-frame*/
static pointer M8017identifier_table_pop_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[0]->c.obj.iv[1];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.vec.v[i]=w;}
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8018:
	ctx->vsp=local; return(local[0]);}

/*:clear-frame*/
static pointer M8046identifier_table_clear_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= argv[0]->c.obj.iv[1];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[1]); v=local[0];
	  v->c.vec.v[i]=w;}
	local[0]= w;
BLK8047:
	ctx->vsp=local; return(local[0]);}

/*:level*/
static pointer M8064identifier_table_level(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8068;}
	local[0]= argv[0]->c.obj.iv[1];
ENT8068:
ENT8067:
	if (n>3) maerror();
	argv[0]->c.obj.iv[1] = local[0];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8065:
	ctx->vsp=local; return(local[0]);}

/*:frame*/
static pointer M8092identifier_table_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8096;}
	local[0]= argv[0]->c.obj.iv[1];
ENT8096:
ENT8095:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	local[0]= w;
BLK8093:
	ctx->vsp=local; return(local[0]);}

/*:init-frames*/
static pointer M8118identifier_table_init_frames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[2];
WHL8154:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX8155;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL8154;
WHX8155:
	local[2]= NIL;
BLK8156:
	w = NIL;
	argv[0]->c.obj.iv[1] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK8119:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M8189identifier_table_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8193;}
	local[0]= makeint((eusinteger_t)20L);
ENT8193:
ENT8192:
	if (n>3) maerror();
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,1,local+1,&ftab[2],fqv[18]); /*make-array*/
	argv[0]->c.obj.iv[0] = w;
	argv[0]->c.obj.iv[1] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK8190:
	ctx->vsp=local; return(local[0]);}

/*:offset*/
static pointer M8246stack_frame_offset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8250;}
	local[0]= NIL;
ENT8250:
ENT8249:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF8266;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF8267;
IF8266:
	local[1]= NIL;
IF8267:
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK8247:
	ctx->vsp=local; return(local[0]);}

/*:special*/
static pointer M8281stack_frame_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8285;}
	local[0]= makeint((eusinteger_t)0L);
ENT8285:
ENT8284:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK8282:
	ctx->vsp=local; return(local[0]);}

/*:local*/
static pointer M8311stack_frame_local(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT8315;}
	local[0]= makeint((eusinteger_t)0L);
ENT8315:
ENT8314:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)PLUS(ctx,2,local+1); /*+*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK8312:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M8341stack_frame_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[2] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK8342:
	ctx->vsp=local; return(local[0]);}

/*:genlabel*/
static pointer M8400compiler_genlabel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT8404;}
	local[0]= fqv[19];
ENT8404:
ENT8403:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[20]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[20]); /*string*/
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[0]= w;
BLK8401:
	ctx->vsp=local; return(local[0]);}

/*:gencname-tail*/
static pointer M8433compiler_gencname_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST8436:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[21]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[0]= w;
BLK8434:
	ctx->vsp=local; return(local[0]);}

/*:progn*/
static pointer M8454compiler_progn(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto IF8469;
WHL8475:
	if (argv[2]==NIL) goto WHX8476;
	local[0]= argv[0];
	local[1]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[2];
	if (local[0]==NIL) goto AND8524;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[24];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
AND8524:
	goto WHL8475;
WHX8476:
	local[0]= NIL;
BLK8477:
	goto IF8470;
IF8469:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
IF8470:
	w = local[0];
	local[0]= w;
BLK8455:
	ctx->vsp=local; return(local[0]);}

/*:eval*/
static pointer M8541compiler_eval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!issymbol(w)) goto IF8556;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[4])(ctx,1,local+0,&ftab[4],fqv[26]); /*constantp*/
	if (w==NIL) goto IF8556;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SYMVALUE(ctx,1,local+0); /*symbol-value*/
	local[0]= w;
	w = local[0];
	if (!isnum(w)) goto CON8584;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8582;
CON8584:
	local[1]= local[0];
	w = fqv[27];
	if (memq(local[1],w)==NIL) goto CON8595;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8582;
CON8595:
	w = local[0];
	if (!issymbol(w)) goto CON8611;
	local[1]= fqv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	argv[2] = w;
	local[1]= argv[2];
	goto CON8582;
CON8611:
	w = local[0];
	if (!isstring(w)) goto CON8626;
	argv[2] = local[0];
	local[1]= argv[2];
	goto CON8582;
CON8626:
	local[1]= NIL;
CON8582:
	w = local[1];
	local[0]= w;
	goto IF8557;
IF8556:
	local[0]= NIL;
IF8557:
	local[0]= argv[2];
	if (T!=local[0]) goto CON8642;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[28];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= fqv[29];
	goto CON8640;
CON8642:
	local[0]= argv[2];
	if (NIL!=local[0]) goto CON8655;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	goto CON8640;
CON8655:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[30]); /*keywordp*/
	if (w==NIL) goto CON8666;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[31];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[29];
	goto CON8640;
CON8666:
	w = argv[2];
	if (!issymbol(w)) goto CON8683;
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON8640;
CON8683:
	w = argv[2];
	if (!isint(w)) goto CON8694;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[33];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[9];
	goto CON8640;
CON8694:
	w = argv[2];
	if (!isflt(w)) goto CON8708;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[34];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[11];
	goto CON8640;
CON8708:
	w = argv[2];
	if (!!iscons(w)) goto CON8722;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[31];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= T;
	goto CON8640;
CON8722:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F6941ovafp(ctx,1,local+0); /*ovafp*/
	if (w==NIL) goto CON8734;
	local[0]= argv[0];
	local[1]= fqv[35];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON8640;
CON8734:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON8756;
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= fqv[36];
	local[3]= fqv[37];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON8640;
CON8756:
	local[0]= argv[0];
	local[1]= fqv[38];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	local[3]= local[2];
	if (fqv[39]!=local[3]) goto IF8841;
	local[3]= argv[0];
	local[4]= fqv[40];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8842;
IF8841:
	local[3]= local[2];
	if (fqv[41]!=local[3]) goto IF8864;
	local[3]= argv[0];
	local[4]= fqv[42];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8865;
IF8864:
	local[3]= local[2];
	if (fqv[43]!=local[3]) goto IF8887;
	local[3]= argv[0];
	local[4]= fqv[22];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(*ftab[6])(ctx,1,local+5,&ftab[6],fqv[44]); /*macroexpand*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF8888;
IF8887:
	local[3]= local[2];
	if (fqv[45]!=local[3]) goto IF8904;
	local[3]= argv[0];
	local[4]= fqv[46];
	local[5]= local[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8905;
IF8904:
	if (T==NIL) goto IF8923;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[47];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF8924;
IF8923:
	local[3]= NIL;
IF8924:
IF8905:
IF8888:
IF8865:
IF8842:
	w = local[3];
	local[0]= w;
	goto CON8640;
CON8797:
	local[0]= NIL;
CON8640:
	w = local[0];
	local[0]= w;
BLK8542:
	ctx->vsp=local; return(local[0]);}

/*:get-function*/
static pointer M8936compiler_get_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF8951;
	local[0]= argv[0];
	local[1]= fqv[6];
	local[2]= fqv[48];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF8952;
IF8951:
	local[0]= NIL;
IF8952:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	if (local[0]==NIL) goto IF8977;
	local[1]= local[0];
	goto IF8978;
IF8977:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto CON8986;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SYMFUNC(ctx,1,local+1); /*symbol-function*/
	local[0] = w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[49]); /*compiled-function-p*/
	if (w==NIL) goto IF9003;
	local[1]= argv[2];
	local[2]= local[0]->c.obj.iv[2];
	local[3]= fqv[50];
	ctx->vsp=local+4;
	w=(pointer)ASSQ(ctx,2,local+2); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	goto IF9004;
IF9003:
	local[1]= argv[2];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF9004:
	goto CON8984;
CON8986:
	local[1]= argv[2];
	local[2]= fqv[39];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	goto CON8984;
CON9033:
	local[1]= NIL;
CON8984:
IF8978:
	w = local[1];
	local[0]= w;
BLK8937:
	ctx->vsp=local; return(local[0]);}

/*:call-closure*/
static pointer M9043compiler_call_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[51])==NIL) goto IF9060;
	local[0]= fqv[46];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)PRINT(ctx,1,local+0); /*print*/
	local[0]= w;
	goto IF9061;
IF9060:
	local[0]= NIL;
IF9061:
	local[0]= NIL;
	local[1]= argv[3];
WHL9093:
	if (local[1]==NIL) goto WHX9094;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL9093;
WHX9094:
	local[2]= NIL;
BLK9095:
	w = NIL;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[52];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,1,local+4,&ftab[8],fqv[53]); /*fourth*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[46];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[9])(ctx,1,local+2,&ftab[9],fqv[54]); /*fifth*/
	local[2]= w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK9044:
	ctx->vsp=local; return(local[0]);}

/*:variable*/
static pointer M9186compiler_variable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[55];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF9218;
	w = local[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK9187;
	goto IF9219;
IF9218:
	local[1]= NIL;
IF9219:
	local[1]= loadglobal(fqv[56]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[57];
	local[4]= argv[2];
	local[5]= fqv[41];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6947proclaimed_special_p(ctx,1,local+1); /*proclaimed-special-p*/
	if (w==NIL) goto CON9265;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[58];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9263;
CON9265:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6949proclaimed_global_p(ctx,1,local+1); /*proclaimed-global-p*/
	if (w==NIL) goto CON9278;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[58];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9263;
CON9278:
	local[1]= loadglobal(fqv[59]);
	local[2]= fqv[60];
	local[3]= makeint((eusinteger_t)27L);
	local[4]= argv[2];
	local[5]= makeint((eusinteger_t)27L);
	local[6]= makeint((eusinteger_t)27L);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,6,local+1); /*format*/
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[17];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto CON9263;
CON9291:
	local[1]= NIL;
CON9263:
	w = local[0];
	local[0]= w;
BLK9187:
	ctx->vsp=local; return(local[0]);}

/*:var-binding*/
static pointer M9311compiler_var_binding(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!iscons(w)) goto IF9326;
	local[0]= fqv[61];
	goto IF9327;
IF9326:
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[63];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
IF9327:
	w = local[0];
	local[0]= w;
BLK9312:
	ctx->vsp=local; return(local[0]);}

/*:special-variable-p*/
static pointer M9344compiler_special_variable_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[64];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]!=NIL) goto IF9375;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6947proclaimed_special_p(ctx,1,local+1); /*proclaimed-special-p*/
	local[1]= w;
	if (w!=NIL) goto OR9381;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6949proclaimed_global_p(ctx,1,local+1); /*proclaimed-global-p*/
	local[1]= w;
OR9381:
	goto IF9376;
IF9375:
	local[1]= local[0];
	local[2]= fqv[63];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[1]= ((fqv[41])==(local[1])?T:NIL);
IF9376:
	w = local[1];
	local[0]= w;
BLK9345:
	ctx->vsp=local; return(local[0]);}

/*:enter-variable*/
static pointer M9403compiler_enter_variable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[64];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]!=NIL) goto IF9435;
	local[1]= loadglobal(fqv[56]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[57];
	local[4]= argv[2];
	local[5]= fqv[65];
	local[6]= argv[0]->c.obj.iv[1];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[17];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6947proclaimed_special_p(ctx,1,local+1); /*proclaimed-special-p*/
	if (w!=NIL) goto OR9488;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F6949proclaimed_global_p(ctx,1,local+1); /*proclaimed-global-p*/
	if (w!=NIL) goto OR9488;
	goto IF9486;
OR9488:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,1,local+1,&ftab[4],fqv[26]); /*constantp*/
	if (w==NIL) goto IF9504;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[66];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF9505;
IF9504:
	local[1]= NIL;
IF9505:
	local[1]= local[0];
	local[2]= fqv[63];
	local[3]= fqv[41];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF9487;
IF9486:
	local[1]= NIL;
IF9487:
	goto IF9436;
IF9435:
	local[1]= NIL;
IF9436:
	w = local[0];
	local[0]= w;
BLK9404:
	ctx->vsp=local; return(local[0]);}

/*:bind*/
static pointer M9530compiler_bind(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT9534;}
	local[0]= NIL;
ENT9534:
ENT9533:
	if (n>6) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF9557;
	local[1]= fqv[67];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF9558;
IF9557:
	local[1]= NIL;
IF9558:
	local[1]= argv[0];
	local[2]= fqv[68];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[2];
	if (fqv[41]!=local[2]) goto CON9594;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[69];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[3];
	local[3]= local[2];
	if (fqv[70]!=local[3]) goto IF9626;
	if (local[0]==NIL) goto IF9634;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[71];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF9635;
IF9634:
	local[3]= NIL;
IF9635:
	goto IF9627;
IF9626:
	local[3]= local[2];
	if (fqv[72]!=local[3]) goto IF9649;
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[73];
	local[5]= argv[4];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF9650;
IF9649:
	if (T==NIL) goto IF9663;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[74];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF9664;
IF9663:
	local[3]= NIL;
IF9664:
IF9650:
IF9627:
	w = local[3];
	local[2]= argv[4];
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[9] = cons(ctx,local[2],w);
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[75];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto CON9592;
CON9594:
	local[2]= argv[3];
	if (fqv[70]!=local[2]) goto IF9696;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[71];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9697;
IF9696:
	local[2]= NIL;
IF9697:
	local[2]= argv[3];
	w = local[1];
	w->c.obj.iv[2] = local[2];
	local[2]= argv[4];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[4] = local[3];
	goto CON9592;
CON9692:
	local[2]= NIL;
CON9592:
	w = local[1];
	local[0]= w;
BLK9531:
	ctx->vsp=local; return(local[0]);}

/*:create-frame*/
static pointer M9726compiler_create_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[76]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
	w = argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[3] = cons(ctx,local[0],w);
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= fqv[78];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK9727:
	ctx->vsp=local; return(local[0]);}

/*:delete-frame*/
static pointer M9792compiler_delete_frame(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[3] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= local[0]->c.obj.iv[1];
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF9860;
	if (argv[2]==NIL) goto IF9866;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[79];
	local[4]= local[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9867;
IF9866:
	local[2]= argv[0];
	local[3]= fqv[80];
	local[4]= fqv[81];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
IF9867:
	goto IF9861;
IF9860:
	local[2]= NIL;
IF9861:
	if (argv[2]==NIL) goto IF9885;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[82];
	local[4]= local[0]->c.obj.iv[1];
	local[5]= local[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto IF9886;
IF9885:
	local[2]= NIL;
IF9886:
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[83];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[78];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK9793:
	ctx->vsp=local; return(local[0]);}

/*:load-ovaf*/
static pointer M9919compiler_load_ovaf(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= local[0];
	w = fqv[84];
	if (memq(local[2],w)!=NIL) goto IF9955;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[0] = w;
	local[2]= local[0];
	goto IF9956;
IF9955:
	local[2]= NIL;
IF9956:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLASSP(ctx,1,local+2); /*classp*/
	if (w==NIL) goto CON9977;
	local[2]= argv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F6951object_variable_names(ctx,1,local+3); /*object-variable-names*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[4]); /*position*/
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto IF9997;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[85];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF9998;
IF9997:
	local[2]= argv[0];
	local[3]= fqv[6];
	local[4]= fqv[86];
	local[5]= argv[2];
	local[6]= argv[3];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
IF9998:
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F6953object_variable_type(ctx,2,local+2); /*object-variable-type*/
	local[2]= w;
	goto CON9975;
CON9977:
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[35];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= T;
	goto CON9975;
CON10020:
	local[2]= NIL;
CON9975:
	w = local[2];
	local[0]= w;
BLK9920:
	ctx->vsp=local; return(local[0]);}

/*:load-var*/
static pointer M10032compiler_load_var(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!iscons(w)) goto IF10048;
	local[0]= argv[0];
	local[1]= fqv[35];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	w = T;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK10033;
	goto IF10049;
IF10048:
	local[0]= NIL;
IF10049:
	local[0]= argv[0];
	local[1]= fqv[62];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= *(ovafptr(argv[2],fqv[87]));
	local[1]= local[0];
	w = fqv[88];
	if (memq(local[1],w)==NIL) goto IF10103;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[89];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF10104;
IF10103:
	local[1]= local[0];
	w = fqv[90];
	if (memq(local[1],w)==NIL) goto IF10121;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[52];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10122;
IF10121:
	local[1]= local[0];
	w = fqv[93];
	if (memq(local[1],w)==NIL) goto IF10144;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[73];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10145;
IF10144:
	local[1]= local[0];
	w = fqv[94];
	if (memq(local[1],w)==NIL) goto IF10167;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[95];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10168;
IF10167:
	local[1]= local[0];
	if (fqv[65]!=local[1]) goto IF10190;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[96];
	local[4]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10191;
IF10190:
	local[1]= NIL;
IF10191:
IF10168:
IF10145:
IF10122:
IF10104:
	w = local[1];
	local[0]= argv[2];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK10033:
	ctx->vsp=local; return(local[0]);}

/*:store-ovaf*/
static pointer M10212compiler_store_ovaf(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	w = fqv[98];
	if (memq(local[1],w)!=NIL) goto IF10245;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)SYMVALUE(ctx,1,local+1); /*symbol-value*/
	local[0] = w;
	local[1]= local[0];
	goto IF10246;
IF10245:
	local[1]= NIL;
IF10246:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)CLASSP(ctx,1,local+1); /*classp*/
	if (w==NIL) goto IF10265;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[99];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F6951object_variable_names(ctx,1,local+4); /*object-variable-names*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[0])(ctx,2,local+3,&ftab[0],fqv[4]); /*position*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF10266;
IF10265:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[100];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF10266:
	w = local[1];
	local[0]= w;
BLK10213:
	ctx->vsp=local; return(local[0]);}

/*:store-var*/
static pointer M10295compiler_store_var(ctx,n,argv,env)
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
	argv[2] = w;
	local[0]= *(ovafptr(argv[2],fqv[87]));
	local[1]= local[0];
	w = fqv[101];
	if (memq(local[1],w)==NIL) goto IF10336;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[102];
	local[3]= *(ovafptr(argv[2],fqv[16]));
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF10337;
IF10336:
	local[1]= local[0];
	w = fqv[103];
	if (memq(local[1],w)==NIL) goto IF10354;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[104];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10355;
IF10354:
	local[1]= local[0];
	w = fqv[105];
	if (memq(local[1],w)==NIL) goto IF10377;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[106];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10378;
IF10377:
	local[1]= local[0];
	w = fqv[107];
	if (memq(local[1],w)==NIL) goto IF10400;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[108];
	local[3]= *(ovafptr(argv[2],fqv[91]));
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= *(ovafptr(argv[2],fqv[92]));
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF10401;
IF10400:
	local[1]= NIL;
IF10401:
IF10378:
IF10355:
IF10337:
	w = local[1];
	local[0]= w;
BLK10296:
	ctx->vsp=local; return(local[0]);}

/*:funcall*/
static pointer M10451compiler_funcall(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	w = fqv[109];
	if (memq(local[3],w)!=NIL) goto IF10493;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO10507,env,argv,local);
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[1] = w;
	local[3]= local[1];
	goto IF10494;
IF10493:
	local[3]= NIL;
IF10494:
	local[3]= argv[2];
	local[4]= local[3];
	w = fqv[110];
	if (memq(local[4],w)==NIL) goto IF10529;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= fqv[111];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[112];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[29];
	goto IF10530;
IF10529:
	local[4]= local[3];
	w = fqv[113];
	if (memq(local[4],w)==NIL) goto IF10557;
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	local[6]= fqv[114];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[115];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[29];
	goto IF10558;
IF10557:
	local[4]= local[3];
	w = fqv[116];
	if (memq(local[4],w)==NIL) goto IF10585;
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	local[6]= fqv[117];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[118];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10586;
IF10585:
	local[4]= local[3];
	w = fqv[119];
	if (memq(local[4],w)==NIL) goto IF10611;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= fqv[120];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF10631;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto IF10632;
IF10631:
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= fqv[11];
IF10632:
	goto IF10612;
IF10611:
	local[4]= local[3];
	w = fqv[123];
	if (memq(local[4],w)==NIL) goto IF10665;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= fqv[124];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isint(w)) goto IF10685;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[125];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto IF10686;
IF10685:
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= fqv[11];
IF10686:
	goto IF10666;
IF10665:
	local[4]= local[3];
	w = fqv[126];
	if (memq(local[4],w)==NIL) goto IF10719;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[127];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10720;
IF10719:
	local[4]= local[3];
	w = fqv[128];
	if (memq(local[4],w)==NIL) goto IF10744;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[129];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10745;
IF10744:
	local[4]= local[3];
	w = fqv[130];
	if (memq(local[4],w)==NIL) goto IF10769;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[131];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10770;
IF10769:
	local[4]= local[3];
	w = fqv[132];
	if (memq(local[4],w)==NIL) goto IF10794;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[133];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10795;
IF10794:
	local[4]= local[3];
	w = fqv[134];
	if (memq(local[4],w)==NIL) goto IF10819;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[135];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10820;
IF10819:
	local[4]= local[3];
	w = fqv[136];
	if (memq(local[4],w)==NIL) goto IF10844;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[137];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10845;
IF10844:
	local[4]= local[3];
	w = fqv[138];
	if (memq(local[4],w)==NIL) goto IF10869;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[139];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10870;
IF10869:
	local[4]= local[3];
	w = fqv[140];
	if (memq(local[4],w)==NIL) goto IF10894;
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	local[6]= fqv[141];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[142];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10895;
IF10894:
	local[4]= local[3];
	w = fqv[143];
	if (memq(local[4],w)==NIL) goto IF10920;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[144];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= T;
	goto IF10921;
IF10920:
	local[4]= local[3];
	w = fqv[145];
	if (memq(local[4],w)==NIL) goto IF10946;
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	local[6]= fqv[146];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[147];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10947;
IF10946:
	local[4]= local[3];
	w = fqv[148];
	if (memq(local[4],w)==NIL) goto IF10972;
	local[4]= makeint((eusinteger_t)3L);
	local[5]= local[0];
	local[6]= fqv[149];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[150];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= T;
	goto IF10973;
IF10972:
	local[4]= local[3];
	w = fqv[151];
	if (memq(local[4],w)==NIL) goto IF10998;
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[152];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF10999;
IF10998:
	local[4]= local[3];
	w = fqv[153];
	if (memq(local[4],w)==NIL) goto IF11022;
	local[4]= makeint((eusinteger_t)3L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[154];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF11023;
IF11022:
	local[4]= local[3];
	w = fqv[155];
	if (memq(local[4],w)==NIL) goto IF11046;
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[156];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF11047;
IF11046:
	local[4]= local[3];
	w = fqv[157];
	if (memq(local[4],w)==NIL) goto IF11070;
	local[4]= makeint((eusinteger_t)3L);
	local[5]= local[0];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[158];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF11071;
IF11070:
	local[4]= local[3];
	w = fqv[159];
	if (memq(local[4],w)==NIL) goto IF11094;
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= fqv[160];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF11105;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF11106;
IF11105:
	local[4]= argv[0];
	local[5]= fqv[161];
	local[6]= argv[2];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
IF11106:
	goto IF11095;
IF11094:
	local[4]= local[3];
	w = fqv[162];
	if (memq(local[4],w)==NIL) goto IF11135;
	local[4]= argv[0];
	local[5]= fqv[163];
	local[6]= argv[2];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF11136;
IF11135:
	local[4]= local[3];
	w = fqv[164];
	if (memq(local[4],w)==NIL) goto IF11154;
	local[4]= makeint((eusinteger_t)3L);
	local[5]= local[0];
	local[6]= fqv[165];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= argv[0];
	local[5]= fqv[166];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF11155;
IF11154:
	local[4]= local[3];
	w = fqv[167];
	if (memq(local[4],w)==NIL) goto IF11200;
	local[4]= makeint((eusinteger_t)4L);
	local[5]= local[0];
	local[6]= fqv[168];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	local[4]= argv[0];
	local[5]= fqv[169];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(*ftab[8])(ctx,1,local+9,&ftab[8],fqv[53]); /*fourth*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	local[4]= w;
	goto IF11201;
IF11200:
	local[4]= local[3];
	w = fqv[170];
	if (memq(local[4],w)==NIL) goto IF11249;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[0];
	local[6]= fqv[171];
	ctx->vsp=local+7;
	w=(pointer)F6957check_arg(ctx,3,local+4); /*check-arg*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6955coerce_type(ctx,1,local+4); /*coerce-type*/
	local[4]= w;
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON11271;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[172];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[9];
	goto CON11269;
CON11271:
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6955coerce_type(ctx,1,local+4); /*coerce-type*/
	local[4]= w;
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w==NIL) goto CON11294;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[173];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= fqv[11];
	goto CON11269;
CON11294:
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= T;
	goto CON11269;
CON11317:
	local[4]= NIL;
CON11269:
	goto IF11250;
IF11249:
	if (T==NIL) goto IF11328;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[122];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[2];
	if (!issymbol(w)) goto IF11344;
	local[4]= argv[2];
	local[5]= fqv[15];
	ctx->vsp=local+6;
	w=(pointer)GETPROP(ctx,2,local+4); /*get*/
	local[4]= w;
	goto IF11345;
IF11344:
	local[4]= T;
IF11345:
	goto IF11329;
IF11328:
	local[4]= NIL;
IF11329:
IF11250:
IF11201:
IF11155:
IF11136:
IF11095:
IF11071:
IF11047:
IF11023:
IF10999:
IF10973:
IF10947:
IF10921:
IF10895:
IF10870:
IF10845:
IF10820:
IF10795:
IF10770:
IF10745:
IF10720:
IF10666:
IF10612:
IF10586:
IF10558:
IF10530:
	w = local[4];
	local[0]= w;
BLK10452:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO10507(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[22];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:vector-op*/
static pointer M11400compiler_vector_op(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[2];
	local[2]= fqv[174];
	ctx->vsp=local+3;
	w=(pointer)ASSQ(ctx,2,local+1); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	w = local[0];
	if (!issymbol(w)) goto IF11446;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)BOUNDP(ctx,1,local+2); /*boundp*/
	if (w==NIL) goto IF11446;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLASSP(ctx,1,local+2); /*classp*/
	if (w==NIL) goto IF11446;
	local[2]= local[0];
	local[3]= loadglobal(fqv[175]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11472;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[9];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11470;
CON11472:
	local[2]= local[0];
	local[3]= loadglobal(fqv[20]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11490;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[176];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11470;
CON11490:
	local[2]= local[0];
	local[3]= loadglobal(fqv[177]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11507;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= fqv[11];
	goto CON11470;
CON11507:
	local[2]= local[0];
	local[3]= loadglobal(fqv[178]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11525;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[122];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= fqv[9];
	goto CON11470;
CON11525:
	local[2]= local[0];
	local[3]= loadglobal(fqv[179]);
	ctx->vsp=local+4;
	w=(pointer)SUBCLASSP(ctx,2,local+2); /*subclassp*/
	if (w==NIL) goto CON11544;
	local[2]= loadglobal(fqv[23]);
	local[3]= local[1];
	local[4]= fqv[180];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= T;
	goto CON11470;
CON11544:
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[122];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= T;
	goto CON11470;
CON11560:
	local[2]= NIL;
CON11470:
	goto IF11447;
IF11446:
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[122];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
IF11447:
	w = local[2];
	local[0]= w;
BLK11401:
	ctx->vsp=local; return(local[0]);}

/*:slot*/
static pointer M11580compiler_slot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = argv[4];
	if (isnum(w)) goto IF11616;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)F6943class_symbolp(ctx,1,local+1); /*class-symbolp*/
	if (w==NIL) goto IF11616;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)F6945quoted_symbolp(ctx,1,local+1); /*quoted-symbolp*/
	if (w==NIL) goto IF11616;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= *(ovafptr(w,fqv[2]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[4]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF11616;
	argv[4] = local[0];
	local[1]= argv[4];
	goto IF11617;
IF11616:
	local[1]= NIL;
IF11617:
	w = argv[4];
	if (!isnum(w)) goto CON11665;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[85];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[3];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)F6953object_variable_type(ctx,2,local+1); /*object-variable-type*/
	local[1]= w;
	goto CON11663;
CON11665:
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[122];
	local[3]= fqv[165];
	local[4]= makeint((eusinteger_t)3L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto CON11663;
CON11681:
	local[1]= NIL;
CON11663:
	w = local[1];
	local[0]= w;
BLK11581:
	ctx->vsp=local; return(local[0]);}

/*:setslot*/
static pointer M11708compiler_setslot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= NIL;
	w = argv[4];
	if (isnum(w)) goto IF11739;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)F6943class_symbolp(ctx,1,local+1); /*class-symbolp*/
	if (w==NIL) goto IF11739;
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(pointer)F6945quoted_symbolp(ctx,1,local+1); /*quoted-symbolp*/
	if (w==NIL) goto IF11739;
	w=argv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= *(ovafptr(w,fqv[2]));
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[4]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF11739;
	argv[4] = local[0];
	local[1]= argv[4];
	goto IF11740;
IF11739:
	local[1]= NIL;
IF11740:
	w = argv[4];
	if (!isnum(w)) goto CON11788;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[181];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[99];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[3];
	local[2]= argv[4];
	ctx->vsp=local+3;
	w=(pointer)F6953object_variable_type(ctx,2,local+1); /*object-variable-type*/
	local[1]= w;
	goto CON11786;
CON11788:
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[122];
	local[3]= fqv[168];
	local[4]= makeint((eusinteger_t)4L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto CON11786;
CON11824:
	local[1]= NIL;
CON11786:
	w = local[1];
	local[0]= w;
BLK11709:
	ctx->vsp=local; return(local[0]);}

/*:arithmetic*/
static pointer M11892compiler_arithmetic(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= loadglobal(fqv[182]);
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto IF11911;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[122];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto IF11912;
IF11911:
	local[0]= argv[2];
	if (fqv[183]!=local[0]) goto CON11931;
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO11945,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON11941;
	local[0]= argv[3];
	local[1]= local[0];
	w = fqv[185];
	if (memq(local[1],w)==NIL) goto IF11966;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[186];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF11967;
IF11966:
	local[1]= local[0];
	w = fqv[187];
	if (memq(local[1],w)==NIL) goto IF11982;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[188];
	local[3]= fqv[183];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF11983;
IF11982:
	if (T==NIL) goto IF12000;
WHL12008:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[3] = w;
	local[1]= argv[3];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto WHX12009;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[188];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL12008;
WHX12009:
	local[1]= NIL;
BLK12010:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[186];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[188];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12001;
IF12000:
	local[1]= NIL;
IF12001:
IF11983:
IF11967:
	w = local[1];
	local[0]= fqv[9];
	goto CON11939;
CON11941:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12052,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON12048;
	local[0]= argv[3];
	local[1]= local[0];
	w = fqv[190];
	if (memq(local[1],w)==NIL) goto IF12072;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[191];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF12073;
IF12072:
	local[1]= local[0];
	w = fqv[192];
	if (memq(local[1],w)==NIL) goto IF12088;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[193];
	local[3]= fqv[183];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12089;
IF12088:
	if (T==NIL) goto IF12106;
WHL12114:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[3] = w;
	local[1]= argv[3];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto WHX12115;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[193];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL12114;
WHX12115:
	local[1]= NIL;
BLK12116:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[191];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[193];
	local[3]= fqv[189];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12107;
IF12106:
	local[1]= NIL;
IF12107:
IF12089:
IF12073:
	w = local[1];
	local[0]= fqv[11];
	goto CON11939;
CON12048:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[122];
	local[2]= fqv[183];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto CON11939;
CON12154:
	local[0]= NIL;
CON11939:
	goto CON11929;
CON11931:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12176,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON12172;
WHL12183:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[3];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto WHX12184;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[188];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	goto WHL12183;
WHX12184:
	local[0]= NIL;
BLK12185:
	local[0]= fqv[9];
	goto CON12170;
CON12172:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO12211,env,argv,local);
	local[1]= argv[4];
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,2,local+0,&ftab[10],fqv[184]); /*every*/
	if (w==NIL) goto CON12207;
WHL12218:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	argv[3] = w;
	local[0]= argv[3];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto WHX12219;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[193];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	goto WHL12218;
WHX12219:
	local[0]= NIL;
BLK12220:
	local[0]= fqv[11];
	goto CON12170;
CON12207:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[122];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= T;
	goto CON12170;
CON12242:
	local[0]= NIL;
CON12170:
	goto CON11929;
CON12166:
	local[0]= NIL;
CON11929:
IF11912:
	w = local[0];
	local[0]= w;
BLK11893:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO11945(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[194];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12052(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[195];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12176(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[196];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO12211(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = fqv[197];
	w = memq(local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:special-form*/
static pointer M12349compiler_special_form(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= local[0];
	w = fqv[198];
	if (memq(local[1],w)==NIL) goto IF12379;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[31];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12380;
IF12379:
	local[1]= local[0];
	w = fqv[199];
	if (memq(local[1],w)==NIL) goto IF12404;
	local[1]= argv[0];
	local[2]= fqv[200];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF12405;
IF12404:
	local[1]= local[0];
	w = fqv[201];
	if (memq(local[1],w)==NIL) goto IF12421;
	local[1]= argv[0];
	local[2]= fqv[202];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12422;
IF12421:
	local[1]= local[0];
	w = fqv[203];
	if (memq(local[1],w)==NIL) goto IF12442;
	local[1]= argv[0];
	local[2]= fqv[204];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12443;
IF12442:
	local[1]= local[0];
	w = fqv[205];
	if (memq(local[1],w)==NIL) goto IF12463;
	local[1]= argv[0];
	local[2]= fqv[206];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12464;
IF12463:
	local[1]= local[0];
	w = fqv[207];
	if (memq(local[1],w)==NIL) goto IF12484;
	local[1]= argv[0];
	local[2]= fqv[208];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12485;
IF12484:
	local[1]= local[0];
	w = fqv[209];
	if (memq(local[1],w)==NIL) goto IF12505;
	local[1]= argv[0];
	local[2]= fqv[210];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12506;
IF12505:
	local[1]= local[0];
	w = fqv[211];
	if (memq(local[1],w)==NIL) goto IF12526;
	local[1]= argv[0];
	local[2]= fqv[212];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12527;
IF12526:
	local[1]= local[0];
	w = fqv[213];
	if (memq(local[1],w)==NIL) goto IF12547;
	local[1]= argv[0];
	local[2]= fqv[214];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12548;
IF12547:
	local[1]= local[0];
	w = fqv[215];
	if (memq(local[1],w)==NIL) goto IF12568;
	local[1]= argv[0];
	local[2]= fqv[216];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12569;
IF12568:
	local[1]= local[0];
	w = fqv[217];
	if (memq(local[1],w)==NIL) goto IF12598;
	local[1]= argv[0];
	local[2]= fqv[218];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12599;
IF12598:
	local[1]= local[0];
	w = fqv[219];
	if (memq(local[1],w)==NIL) goto IF12630;
	local[1]= argv[0];
	local[2]= fqv[220];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12631;
IF12630:
	local[1]= local[0];
	w = fqv[221];
	if (memq(local[1],w)==NIL) goto IF12660;
	local[1]= argv[0];
	local[2]= fqv[222];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12661;
IF12660:
	local[1]= local[0];
	w = fqv[223];
	if (memq(local[1],w)==NIL) goto IF12692;
	local[1]= argv[0];
	local[2]= fqv[224];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12693;
IF12692:
	local[1]= local[0];
	w = fqv[225];
	if (memq(local[1],w)==NIL) goto IF12713;
	local[1]= argv[0];
	local[2]= fqv[226];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12714;
IF12713:
	local[1]= local[0];
	w = fqv[227];
	if (memq(local[1],w)==NIL) goto IF12738;
	local[1]= argv[0];
	local[2]= fqv[228];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= T;
	goto IF12739;
IF12738:
	local[1]= local[0];
	w = fqv[229];
	if (memq(local[1],w)==NIL) goto IF12768;
	local[1]= argv[0];
	local[2]= fqv[228];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	local[1]= T;
	goto IF12769;
IF12768:
	local[1]= local[0];
	w = fqv[230];
	if (memq(local[1],w)==NIL) goto IF12798;
	local[1]= argv[0];
	local[2]= fqv[231];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= T;
	goto IF12799;
IF12798:
	local[1]= local[0];
	w = fqv[232];
	if (memq(local[1],w)==NIL) goto IF12828;
	local[1]= argv[0];
	local[2]= fqv[233];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12829;
IF12828:
	local[1]= local[0];
	w = fqv[234];
	if (memq(local[1],w)==NIL) goto IF12849;
	local[1]= argv[0];
	local[2]= fqv[235];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12850;
IF12849:
	local[1]= local[0];
	w = fqv[236];
	if (memq(local[1],w)==NIL) goto IF12874;
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F6955coerce_type(ctx,1,local+1); /*coerce-type*/
	local[1]= w;
	goto IF12875;
IF12874:
	local[1]= local[0];
	w = fqv[237];
	if (memq(local[1],w)==NIL) goto IF12908;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[238];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12909;
IF12908:
	local[1]= local[0];
	w = fqv[239];
	if (memq(local[1],w)==NIL) goto IF12928;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[240];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12929;
IF12928:
	local[1]= local[0];
	w = fqv[241];
	if (memq(local[1],w)==NIL) goto IF12948;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[242];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12949;
IF12948:
	local[1]= local[0];
	w = fqv[243];
	if (memq(local[1],w)==NIL) goto IF12968;
	local[1]= argv[0];
	local[2]= fqv[80];
	local[3]= fqv[244];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= T;
	goto IF12969;
IF12968:
	if (T==NIL) goto IF12988;
	local[1]= argv[0];
	local[2]= fqv[6];
	local[3]= fqv[245];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF12989;
IF12988:
	local[1]= NIL;
IF12989:
IF12969:
IF12949:
IF12929:
IF12909:
IF12875:
IF12850:
IF12829:
IF12799:
IF12769:
IF12739:
IF12714:
IF12693:
IF12661:
IF12631:
IF12599:
IF12569:
IF12548:
IF12527:
IF12506:
IF12485:
IF12464:
IF12443:
IF12422:
IF12405:
IF12380:
	w = local[1];
	local[0]= w;
BLK12350:
	ctx->vsp=local; return(local[0]);}

/*:conditional-jump*/
static pointer M13027compiler_conditional_jump(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (argv[3]==NIL) goto IF13044;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[246];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF13045;
IF13044:
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[247];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF13045:
	w = local[0];
	local[0]= w;
BLK13028:
	ctx->vsp=local; return(local[0]);}

/*:evcon*/
static pointer M13062compiler_evcon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[4];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LISTP(ctx,1,local+5); /*listp*/
	if (w==NIL) goto IF13098;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	local[5]= local[1];
	goto IF13099;
IF13098:
	local[5]= NIL;
IF13099:
	w = argv[2];
	if (!iscons(w)) goto OR13127;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w = makeint((eusinteger_t)1L);
	if ((eusinteger_t)local[5] <= (eusinteger_t)w) goto OR13127;
	goto CON13126;
OR13127:
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[248];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13124;
CON13126:
	local[5]= local[0];
	if (fqv[114]!=local[5]) goto CON13152;
	local[5]= makeint((eusinteger_t)2L);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6957check_arg(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[22];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[22];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[4]==NIL) goto IF13191;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[249];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13192;
IF13191:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[250];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
IF13192:
	goto CON13124;
CON13152:
	local[5]= local[0];
	w = fqv[251];
	if (memq(local[5],w)==NIL) goto CON13208;
	local[5]= makeint((eusinteger_t)1L);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6957check_arg(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[252];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= argv[4];
	local[9]= argv[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON13124;
CON13208:
	local[5]= local[0];
	if (fqv[253]!=local[5]) goto CON13237;
	if (argv[4]!=NIL) goto IF13245;
	local[5]= argv[0];
	local[6]= fqv[254];
	local[7]= fqv[255];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= local[4];
	goto IF13246;
IF13245:
	local[5]= NIL;
IF13246:
WHL13262:
	if (local[1]==NIL) goto WHX13263;
	local[5]= argv[0];
	local[6]= fqv[252];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	local[8]= NIL;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	goto WHL13262;
WHX13263:
	local[5]= NIL;
BLK13264:
	if (argv[4]!=NIL) goto IF13313;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= argv[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13314;
IF13313:
	local[5]= NIL;
IF13314:
	goto CON13124;
CON13237:
	local[5]= local[0];
	if (fqv[258]!=local[5]) goto CON13334;
	if (argv[3]!=NIL) goto IF13342;
	local[5]= argv[0];
	local[6]= fqv[254];
	local[7]= fqv[259];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[4] = w;
	local[5]= local[4];
	goto IF13343;
IF13342:
	local[4] = argv[3];
	local[5]= local[4];
IF13343:
WHL13365:
	if (local[1]==NIL) goto WHX13366;
	local[5]= argv[0];
	local[6]= fqv[252];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	local[8]= local[4];
	local[9]= NIL;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	goto WHL13365;
WHX13366:
	local[5]= NIL;
BLK13367:
	if (argv[3]!=NIL) goto IF13416;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= argv[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF13417;
IF13416:
	local[5]= NIL;
IF13417:
	goto CON13124;
CON13334:
	local[5]= local[0];
	w = fqv[260];
	if (memq(local[5],w)==NIL) goto CON13437;
	local[5]= makeint((eusinteger_t)1L);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)F6957check_arg(ctx,3,local+5); /*check-arg*/
	local[5]= argv[0];
	local[6]= fqv[22];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	if (argv[4]==NIL) goto IF13466;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[261];
	local[7]= local[0];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto IF13467;
IF13466:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[262];
	local[7]= local[0];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
IF13467:
	goto CON13124;
CON13437:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	if (makeint((eusinteger_t)2L)!=local[5]) goto CON13485;
	local[5]= local[0];
	w = fqv[263];
	if (memq(local[5],w)==NIL) goto CON13485;
	ctx->vsp=local+5;
	local[5]= makeclosure(codevec,quotevec,CLO13505,env,argv,local);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MAPCAR(ctx,2,local+5); /*mapcar*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[264];
	ctx->vsp=local+7;
	w=(*ftab[11])(ctx,2,local+5,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON13516;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)EQ(ctx,2,local+5); /*eql*/
	if (w==NIL) goto CON13516;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= fqv[266];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	if (argv[3]==NIL) goto CON13569;
	local[4] = argv[3];
	local[5]= local[4];
	goto CON13567;
CON13569:
	local[5]= local[0];
	local[6]= fqv[267];
	ctx->vsp=local+7;
	w=(pointer)ASSQ(ctx,2,local+5); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[5]= local[0];
	goto CON13567;
CON13580:
	local[5]= NIL;
CON13567:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[268];
	local[7]= local[3];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON13514;
CON13516:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[122];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LENGTH(ctx,1,local+8); /*length*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[248];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13514;
CON13606:
	local[5]= NIL;
CON13514:
	goto CON13124;
CON13485:
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[248];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	goto CON13124;
CON13626:
	local[5]= NIL;
CON13124:
	w = local[5];
	local[0]= w;
BLK13063:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO13505(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[0];
	local[1]= fqv[22];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:if*/
static pointer M13688compiler_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[269];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[254];
	local[3]= fqv[270];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[252];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= NIL;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[256];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[271];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[257];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[257];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK13689:
	ctx->vsp=local; return(local[0]);}

/*:setq*/
static pointer M13793compiler_setq(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto IF13809;
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[25];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = T;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK13794;
	goto IF13810;
IF13809:
	local[0]= NIL;
IF13810:
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL13847:
	if (argv[2]==NIL) goto WHX13848;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[2] = NIL;
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[3] = w;
	if (argv[2]!=NIL) goto IF13899;
	local[4]= argv[0];
	local[5]= fqv[272];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	w = fqv[273];
	if (memq(local[4],w)==NIL) goto IF13899;
	local[2] = T;
	local[4]= loadglobal(fqv[23]);
	local[5]= fqv[181];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	goto IF13900;
IF13899:
	local[4]= NIL;
IF13900:
	w = local[0];
	if (!issymbol(w)) goto IF13934;
	local[4]= argv[0];
	local[5]= fqv[274];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	goto IF13935;
IF13934:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (issymbol(w)) goto IF13949;
	local[4]= argv[0];
	local[5]= fqv[6];
	local[6]= fqv[275];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto IF13950;
IF13949:
	local[4]= NIL;
IF13950:
	local[4]= argv[0];
	local[5]= fqv[100];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
IF13935:
	local[4]= ((argv[2])==NIL?T:NIL);
	if (local[4]==NIL) goto AND13982;
	local[4]= ((local[2])==NIL?T:NIL);
	if (local[4]==NIL) goto AND13982;
	local[4]= argv[0];
	local[5]= fqv[32];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
AND13982:
	goto WHL13847;
WHX13848:
	local[4]= NIL;
BLK13849:
	w = local[3];
	local[0]= w;
BLK13794:
	ctx->vsp=local; return(local[0]);}

/*:let**/
static pointer M14007compiler_let_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= argv[0];
	local[3]= fqv[77];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
WHL14077:
	if (argv[2]==NIL) goto WHX14078;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX14078;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	if (fqv[276]!=local[2]) goto WHX14078;
	local[2]= argv[0];
	local[3]= fqv[277];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL14077;
WHX14078:
	local[2]= NIL;
BLK14079:
	local[2]= NIL;
	local[3]= local[0];
WHL14166:
	if (local[3]==NIL) goto WHX14167;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= fqv[22];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto IF14219;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF14220;
IF14219:
	local[6]= NIL;
IF14220:
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= argv[0];
	local[5]= fqv[278];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto IF14240;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	goto IF14241;
IF14240:
	local[6]= local[2];
IF14241:
	local[7]= fqv[70];
	local[8]= loadglobal(fqv[23]);
	local[9]= fqv[279];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SUB1(ctx,1,local+8); /*1-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	goto WHL14166;
WHX14167:
	local[4]= NIL;
BLK14168:
	w = NIL;
	local[2]= argv[0];
	local[3]= fqv[233];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	argv[0]->c.obj.iv[9] = local[1];
	local[2]= argv[0];
	local[3]= fqv[280];
	local[4]= T;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK14008:
	ctx->vsp=local; return(local[0]);}

/*:let*/
static pointer M14288compiler_let(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[0];
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= argv[0];
	local[6]= fqv[77];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
WHL14364:
	if (argv[2]==NIL) goto WHX14365;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX14365;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	if (fqv[276]!=local[5]) goto WHX14365;
	local[5]= argv[0];
	local[6]= fqv[277];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL14364;
WHX14365:
	local[5]= NIL;
BLK14366:
	local[5]= NIL;
	local[6]= local[0];
WHL14453:
	if (local[6]==NIL) goto WHX14454;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= fqv[78];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)LISTP(ctx,1,local+7); /*listp*/
	if (w==NIL) goto IF14517;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	goto IF14518;
IF14517:
	local[7]= local[5];
IF14518:
	local[1] = local[7];
	local[7]= argv[0];
	local[8]= fqv[22];
	local[9]= local[5];
	ctx->vsp=local+10;
	w=(pointer)LISTP(ctx,1,local+9); /*listp*/
	if (w==NIL) goto IF14568;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	goto IF14569;
IF14568:
	local[9]= NIL;
IF14569:
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= loadglobal(fqv[23]);
	local[8]= fqv[279];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[3] = w;
	local[7]= argv[0];
	local[8]= fqv[281];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	if (w==NIL) goto CON14598;
	w=argv[0]->c.obj.iv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= fqv[71];
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[2];
	ctx->vsp=local+8;
	local[2] = cons(ctx,local[7],w);
	local[7]= local[2];
	goto CON14596;
CON14598:
	local[7]= argv[0];
	local[8]= fqv[278];
	local[9]= local[1];
	local[10]= fqv[70];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	local[7]= w;
	goto CON14596;
CON14632:
	local[7]= NIL;
CON14596:
	goto WHL14453;
WHX14454:
	local[7]= NIL;
BLK14455:
	w = NIL;
	local[5]= NIL;
	local[6]= local[2];
WHL14666:
	if (local[6]==NIL) goto WHX14667;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= loadglobal(fqv[23]);
	local[8]= fqv[279];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[3] = w;
	local[7]= loadglobal(fqv[23]);
	local[8]= fqv[52];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[7]= argv[0];
	local[8]= fqv[278];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[70];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,5,local+7); /*send*/
	goto WHL14666;
WHX14667:
	local[7]= NIL;
BLK14668:
	w = NIL;
	local[5]= argv[0]->c.obj.iv[0];
	local[6]= fqv[78];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	argv[0]->c.obj.iv[2] = w;
	local[5]= argv[0];
	local[6]= fqv[233];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	argv[0]->c.obj.iv[9] = local[4];
	local[5]= argv[0];
	local[6]= fqv[280];
	local[7]= T;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK14289:
	ctx->vsp=local; return(local[0]);}

/*:cond*/
static pointer M14787compiler_cond(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[254];
	local[6]= fqv[282];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
WHL14825:
	if (argv[2]==NIL) goto WHX14826;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[5];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[5]= argv[0];
	local[6]= fqv[254];
	local[7]= fqv[283];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr!=NIL) goto CON14890;
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[181];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[247];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[24];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto CON14888;
CON14890:
	local[5]= local[1];
	if (T!=local[5]) goto CON14924;
	local[3] = T;
	local[5]= local[3];
	goto CON14888;
CON14924:
	local[5]= argv[0];
	local[6]= fqv[252];
	local[7]= local[1];
	local[8]= NIL;
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= w;
	goto CON14888;
CON14934:
	local[5]= NIL;
CON14888:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF14947;
	local[5]= argv[0];
	local[6]= fqv[233];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[271];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
	goto IF14948;
IF14947:
	local[5]= NIL;
IF14948:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL14825;
WHX14826:
	local[5]= NIL;
BLK14827:
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[0]= w;
BLK14788:
	ctx->vsp=local; return(local[0]);}

/*:while*/
static pointer M15004compiler_while(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	local[2]= argv[0];
	local[3]= fqv[254];
	local[4]= fqv[284];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[254];
	local[5]= fqv[285];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[286];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	local[4]= w;
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[252];
	local[7]= local[0];
	local[8]= NIL;
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[233];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[24];
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[256];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[25];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= loadglobal(fqv[23]);
	local[6]= fqv[257];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= argv[0];
	local[6]= fqv[287];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[0]= w;
BLK15005:
	ctx->vsp=local; return(local[0]);}

/*:and*/
static pointer M15127compiler_and(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[288];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
WHL15157:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15158;
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[181];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[246];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[24];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL15157;
WHX15158:
	local[1]= NIL;
BLK15159:
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[257];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15128:
	ctx->vsp=local; return(local[0]);}

/*:or*/
static pointer M15247compiler_or(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[289];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
WHL15277:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15278;
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[181];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[247];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[24];
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	goto WHL15277;
WHX15278:
	local[1]= NIL;
BLK15279:
	local[1]= argv[0];
	local[2]= fqv[22];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[257];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15248:
	ctx->vsp=local; return(local[0]);}

/*:catch*/
static pointer M15367compiler_catch(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[290];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[279];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[9] = cons(ctx,local[1],w);
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[291];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[233];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[292];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK15368:
	ctx->vsp=local; return(local[0]);}

/*:throw*/
static pointer M15479compiler_throw(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[222];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK15480:
	ctx->vsp=local; return(local[0]);}

/*:unwind-protect*/
static pointer M15515compiler_unwind_protect(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[293];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[279];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	w = argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[9] = cons(ctx,local[2],w);
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[294];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[295];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[296];
	local[4]= local[0];
	local[5]= fqv[39];
	local[6]= NIL;
	w = argv[3];
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[297];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[298];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[9] = (w)->c.cons.cdr;
	w = local[2];
	local[0]= w;
BLK15516:
	ctx->vsp=local; return(local[0]);}

/*:enter-block*/
static pointer M15686compiler_enter_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[279];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[254];
	local[3]= fqv[299];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	w = argv[2];
	if (issymbol(w)) goto IF15724;
	local[2]= argv[0];
	local[3]= fqv[80];
	local[4]= fqv[300];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF15725;
IF15724:
	local[2]= NIL;
IF15725:
	local[2]= argv[2];
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	argv[0]->c.obj.iv[4] = cons(ctx,local[2],w);
	w = local[1];
	local[0]= w;
BLK15687:
	ctx->vsp=local; return(local[0]);}

/*:leave-block*/
static pointer M15756compiler_leave_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[4] = (w)->c.cons.cdr;
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK15757:
	ctx->vsp=local; return(local[0]);}

/*:block*/
static pointer M15780compiler_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[286];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[0];
	local[1]= fqv[233];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= loadglobal(fqv[23]);
	local[1]= fqv[257];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[287];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK15781:
	ctx->vsp=local; return(local[0]);}

/*:return-from*/
static pointer M15828compiler_return_from(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF15865;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[301];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF15866;
IF15865:
	local[3]= NIL;
IF15866:
	local[3]= argv[0];
	local[4]= fqv[22];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= argv[0]->c.obj.iv[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF15885;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[302];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF15886;
IF15885:
	local[3]= NIL;
IF15886:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,1,local+3,&ftab[8],fqv[53]); /*fourth*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[9];
	if (local[3]==NIL) goto AND15917;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	local[3]= w;
AND15917:
	local[1] = local[3];
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[218];
	local[5]= local[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[256];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK15829:
	ctx->vsp=local; return(local[0]);}

/*:tagbody*/
static pointer M15955compiler_tagbody(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[279];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
WHL15999:
	if (local[2]==NIL) goto WHX16000;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	w = local[3];
	if (!!iscons(w)) goto IF16008;
	local[6]= local[3];
	local[7]= argv[0];
	local[8]= fqv[254];
	local[9]= fqv[303];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,3,local+6); /*list*/
	local[6]= w;
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+7;
	argv[0]->c.obj.iv[5] = cons(ctx,local[6],w);
	local[6]= argv[0]->c.obj.iv[5];
	goto IF16009;
IF16008:
	local[6]= NIL;
IF16009:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	goto WHL15999;
WHX16000:
	local[6]= NIL;
BLK16001:
WHL16057:
	if (argv[2]==NIL) goto WHX16058;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[6];
	local[5] = w;
	w = local[5];
	if (!!iscons(w)) goto CON16108;
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[257];
	local[8]= local[5];
	local[9]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+10;
	w=(pointer)ASSQ(ctx,2,local+8); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON16106;
CON16108:
	local[6]= argv[0];
	local[7]= fqv[22];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[24];
	local[8]= makeint((eusinteger_t)1L);
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= w;
	goto CON16106;
CON16128:
	local[6]= NIL;
CON16106:
	goto WHL16057;
WHX16058:
	local[6]= NIL;
BLK16059:
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[25];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	argv[0]->c.obj.iv[5] = local[0];
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK15956:
	ctx->vsp=local; return(local[0]);}

/*:go*/
static pointer M16159compiler_go(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)ASSQ(ctx,2,local+0); /*assq*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]!=NIL) goto IF16194;
	local[3]= argv[0];
	local[4]= fqv[6];
	local[5]= fqv[304];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF16195;
IF16194:
	local[3]= NIL;
IF16195:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= argv[0]->c.obj.iv[9];
	if (local[3]==NIL) goto AND16224;
	w=argv[0]->c.obj.iv[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	local[3]= w;
AND16224:
	local[2] = local[3];
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[305];
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= loadglobal(fqv[23]);
	local[4]= fqv[256];
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0]= w;
BLK16160:
	ctx->vsp=local; return(local[0]);}

/*:function*/
static pointer M16258compiler_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (!issymbol(w)) goto IF16273;
	local[0]= argv[0];
	local[1]= fqv[38];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[45]!=local[1]) goto IF16295;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[52];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[8])(ctx,1,local+5,&ftab[8],fqv[53]); /*fourth*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto IF16296;
IF16295:
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[306];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF16296:
	w = local[1];
	local[0]= w;
	goto IF16274;
IF16273:
	local[0]= argv[0];
	local[1]= fqv[254];
	local[2]= fqv[307];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[294];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[295];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= argv[0];
	local[3]= fqv[296];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,3,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
IF16274:
	w = local[0];
	local[0]= w;
BLK16259:
	ctx->vsp=local; return(local[0]);}

/*:flet*/
static pointer M16383compiler_flet(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= argv[2];
WHL16439:
	if (local[7]==NIL) goto WHX16440;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= argv[0];
	local[9]= fqv[254];
	local[10]= fqv[308];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	local[2] = w;
	local[8]= loadglobal(fqv[23]);
	local[9]= fqv[294];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[45];
	local[10]= loadglobal(fqv[23]);
	local[11]= fqv[279];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,2,local+10); /*send*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SUB1(ctx,1,local+10); /*1-*/
	local[10]= w;
	local[11]= argv[0]->c.obj.iv[1];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,5,local+8); /*list*/
	local[8]= w;
	w = argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	argv[0]->c.obj.iv[8] = cons(ctx,local[8],w);
	local[8]= argv[0];
	local[9]= fqv[295];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	local[3] = w;
	local[8]= local[3];
	w = local[4];
	ctx->vsp=local+9;
	local[4] = cons(ctx,local[8],w);
	local[8]= argv[0];
	local[9]= fqv[296];
	local[10]= local[2];
	local[11]= fqv[39];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,3,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,3,local+8); /*send*/
	goto WHL16439;
WHX16440:
	local[8]= NIL;
BLK16441:
	w = NIL;
	if (argv[4]==NIL) goto IF16581;
	local[6]= local[4];
	local[7]= fqv[309];
	local[8]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	w=(*ftab[12])(ctx,3,local+6,&ftab[12],fqv[310]); /*send-all*/
	local[6]= w;
	goto IF16582;
IF16581:
	local[6]= NIL;
IF16582:
	local[6]= argv[0];
	local[7]= fqv[233];
	local[8]= argv[3];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[0]->c.obj.iv[8] = w;
	local[6]= loadglobal(fqv[23]);
	local[7]= fqv[82];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[0]= w;
BLK16384:
	ctx->vsp=local; return(local[0]);}

/*:change-flets*/
static pointer M16623compiler_change_flets(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[8] = argv[2];
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK16624:
	ctx->vsp=local; return(local[0]);}

/*:declare*/
static pointer M16645compiler_declare(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[2];
WHL16692:
	if (local[2]==NIL) goto WHX16693;
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
	local[3]= (w)->c.cons.car;
	local[4]= local[3];
	if (fqv[41]!=local[4]) goto IF16758;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL16787:
	if (local[5]==NIL) goto WHX16788;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= fqv[41];
	local[7]= local[6];
	w = local[0];
	w->c.obj.iv[2] = local[7];
	goto WHL16787;
WHX16788:
	local[6]= NIL;
BLK16789:
	w = NIL;
	local[4]= w;
	goto IF16759;
IF16758:
	local[4]= local[3];
	if (fqv[311]!=local[4]) goto IF16857;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL16888:
	if (local[5]==NIL) goto WHX16889;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[97];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL16888;
WHX16889:
	local[6]= NIL;
BLK16890:
	w = NIL;
	local[4]= w;
	goto IF16858;
IF16857:
	local[4]= local[3];
	if (fqv[312]!=local[4]) goto IF16964;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
	ctx->vsp=local+6;
	w=(pointer)F6959def_function_type(ctx,2,local+4); /*def-function-type*/
	local[4]= w;
	goto IF16965;
IF16964:
	local[4]= local[3];
	w = fqv[313];
	if (memq(local[4],w)==NIL) goto IF16988;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL17020:
	if (local[5]==NIL) goto WHX17021;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[97];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL17020;
WHX17021:
	local[6]= NIL;
BLK17022:
	w = NIL;
	local[4]= w;
	goto IF16989;
IF16988:
	local[4]= local[3];
	if (fqv[314]!=local[4]) goto IF17094;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[315],local[4]);
	goto IF17095;
IF17094:
	local[4]= local[3];
	if (fqv[316]!=local[4]) goto IF17114;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[182],local[4]);
	goto IF17115;
IF17114:
	local[4]= local[3];
	if (fqv[317]!=local[4]) goto IF17133;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	storeglobal(fqv[318],local[4]);
	goto IF17134;
IF17133:
	local[4]= local[3];
	if (fqv[319]!=local[4]) goto IF17153;
	local[4]= NIL;
	goto IF17154;
IF17153:
	local[4]= local[3];
	if (fqv[320]!=local[4]) goto IF17161;
	local[4]= NIL;
	goto IF17162;
IF17161:
	if (T==NIL) goto IF17169;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)F6943class_symbolp(ctx,1,local+4); /*class-symbolp*/
	if (w==NIL) goto CON17176;
	local[4]= NIL;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL17209:
	if (local[5]==NIL) goto WHX17210;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[0];
	local[7]= fqv[68];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	local[6]= local[0];
	local[7]= fqv[97];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	goto WHL17209;
WHX17210:
	local[6]= NIL;
BLK17211:
	w = NIL;
	local[4]= w;
	goto CON17174;
CON17176:
	local[4]= argv[0];
	local[5]= fqv[80];
	local[6]= fqv[321];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON17174;
CON17282:
	local[4]= NIL;
CON17174:
	goto IF17170;
IF17169:
	local[4]= NIL;
IF17170:
IF17162:
IF17154:
IF17134:
IF17115:
IF17095:
IF16989:
IF16965:
IF16858:
IF16759:
	w = local[4];
	goto WHL16692;
WHX16693:
	local[3]= NIL;
BLK16694:
	w = NIL;
	local[0]= w;
BLK16646:
	ctx->vsp=local; return(local[0]);}

/*:lambda*/
static pointer M17297compiler_lambda(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= fqv[322];
	w = argv[2];
	local[5]= memq(local[5],w);
	local[6]= fqv[323];
	w = argv[2];
	local[6]= memq(local[6],w);
	local[7]= fqv[324];
	w = argv[2];
	local[7]= memq(local[7],w);
	local[8]= fqv[325];
	w = argv[2];
	local[8]= memq(local[8],w);
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= makeint((eusinteger_t)0L);
	local[15]= NIL;
	local[16]= fqv[326];
	w = argv[2];
	local[16]= memq(local[16],w);
	local[17]= argv[0]->c.obj.iv[9];
	local[18]= NIL;
	local[19]= NIL;
	local[20]= local[5];
	if (local[20]!=NIL) goto CON17417;
CON17419:
	local[20]= local[6];
	if (local[20]!=NIL) goto CON17417;
CON17423:
	local[20]= local[7];
	if (local[20]!=NIL) goto CON17417;
CON17427:
	local[20]= local[8];
	if (local[20]!=NIL) goto CON17417;
CON17431:
	local[20]= NIL;
CON17417:
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[20]= w;
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)NTHCDR(ctx,2,local+20); /*nthcdr*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)REVERSE(ctx,1,local+20); /*reverse*/
	local[10] = w;
	local[20]= local[6];
	if (local[20]!=NIL) goto CON17452;
CON17454:
	local[20]= local[7];
	if (local[20]!=NIL) goto CON17452;
CON17458:
	local[20]= local[8];
	if (local[20]!=NIL) goto CON17452;
CON17462:
	local[20]= NIL;
CON17452:
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[20]= w;
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)NTHCDR(ctx,2,local+20); /*nthcdr*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)REVERSE(ctx,1,local+20); /*reverse*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	if (local[6]==NIL) goto CON17480;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	goto CON17478;
CON17480:
	local[20]= NIL;
CON17478:
	local[6] = local[20];
	local[20]= local[10];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[2] = w;
	local[20]= local[5];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[3] = w;
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO17505,env,argv,local);
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,2,local+20); /*mapcar*/
	local[11] = w;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	local[20]= local[7];
	ctx->vsp=local+21;
	w=(pointer)LENGTH(ctx,1,local+20); /*length*/
	local[4] = w;
	if (local[16]==NIL) goto IF17527;
	local[20]= local[7];
	local[21]= makeint((eusinteger_t)0L);
	local[22]= local[4];
	ctx->vsp=local+23;
	w=(pointer)SUB1(ctx,1,local+22); /*1-*/
	local[4] = w;
	local[22]= local[4];
	ctx->vsp=local+23;
	w=(pointer)SUBSEQ(ctx,3,local+20); /*subseq*/
	local[7] = w;
	local[20]= local[7];
	goto IF17528;
IF17527:
	local[20]= NIL;
IF17528:
	if (local[5]==NIL) goto IF17554;
WHL17560:
	local[20]= local[1];
	local[21]= local[3];
	ctx->vsp=local+22;
	w=(pointer)LSEQP(ctx,2,local+20); /*<=*/
	if (w==NIL) goto WHX17561;
	local[20]= argv[0];
	local[21]= fqv[254];
	local[22]= fqv[327];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	w = local[0];
	ctx->vsp=local+21;
	local[0] = cons(ctx,local[20],w);
	local[20]= local[1];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[1] = w;
	goto WHL17560;
WHX17561:
	local[20]= NIL;
BLK17562:
	goto IF17555;
IF17554:
	if (local[6]==NIL) goto IF17594;
	local[20]= argv[0];
	local[21]= fqv[254];
	local[22]= fqv[328];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	ctx->vsp=local+21;
	w=(pointer)LIST(ctx,1,local+20); /*list*/
	local[0] = w;
	local[20]= local[0];
	goto IF17595;
IF17594:
	local[20]= NIL;
IF17595:
IF17555:
	ctx->vsp=local+20;
	local[20]= makeclosure(codevec,quotevec,CLO17616,env,argv,local);
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)MAPCAR(ctx,2,local+20); /*mapcar*/
	local[5] = w;
	local[20]= argv[0];
	local[21]= fqv[77];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	if (local[7]==NIL) goto IF17631;
	local[20]= NIL;
	local[21]= NIL;
	local[22]= NIL;
	local[23]= NIL;
	local[24]= local[7];
WHL17667:
	if (local[24]==NIL) goto WHX17668;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[25]= (w)->c.cons.car;
	w=local[24];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24] = (w)->c.cons.cdr;
	w = local[25];
	local[23] = w;
	local[25]= local[23];
	ctx->vsp=local+26;
	w=(pointer)LISTP(ctx,1,local+25); /*listp*/
	if (w==NIL) goto CON17718;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23] = (w)->c.cons.car;
	local[25]= local[23];
	ctx->vsp=local+26;
	w=(pointer)LISTP(ctx,1,local+25); /*listp*/
	if (w==NIL) goto CON17748;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.car;
	w=local[23];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.car;
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(*ftab[5])(ctx,1,local+25,&ftab[5],fqv[30]); /*keywordp*/
	if (w!=NIL) goto IF17776;
	local[25]= argv[0];
	local[26]= fqv[6];
	local[27]= fqv[329];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	goto IF17777;
IF17776:
	local[25]= NIL;
IF17777:
	if (local[22]==NIL) goto AND17792;
	w = local[22];
	if (!issymbol(w)) goto AND17792;
	goto IF17790;
AND17792:
	local[25]= argv[0];
	local[26]= fqv[6];
	local[27]= fqv[330];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,3,local+25); /*send*/
	local[25]= w;
	goto IF17791;
IF17790:
	local[25]= NIL;
IF17791:
	goto CON17746;
CON17748:
	local[22] = local[23];
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(*ftab[13])(ctx,1,local+25,&ftab[13],fqv[331]); /*symbol-name*/
	local[25]= w;
	local[26]= loadglobal(fqv[332]);
	ctx->vsp=local+27;
	w=(pointer)INTERN(ctx,2,local+25); /*intern*/
	local[21] = w;
	local[25]= local[21];
	goto CON17746;
CON17805:
	local[25]= NIL;
CON17746:
	goto CON17716;
CON17718:
	local[20] = NIL;
	local[22] = local[23];
	local[25]= local[22];
	ctx->vsp=local+26;
	w=(*ftab[13])(ctx,1,local+25,&ftab[13],fqv[331]); /*symbol-name*/
	local[25]= w;
	local[26]= loadglobal(fqv[332]);
	ctx->vsp=local+27;
	w=(pointer)INTERN(ctx,2,local+25); /*intern*/
	local[21] = w;
	local[25]= local[21];
	goto CON17716;
CON17824:
	local[25]= NIL;
CON17716:
	local[25]= local[21];
	w = local[12];
	ctx->vsp=local+26;
	local[12] = cons(ctx,local[25],w);
	local[25]= local[22];
	w = local[9];
	ctx->vsp=local+26;
	local[9] = cons(ctx,local[25],w);
	local[25]= local[20];
	w = local[13];
	ctx->vsp=local+26;
	local[13] = cons(ctx,local[25],w);
	goto WHL17667;
WHX17668:
	local[25]= NIL;
BLK17669:
	w = NIL;
	local[23]= local[12];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[9];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[13];
	ctx->vsp=local+24;
	w=(pointer)NREVERSE(ctx,1,local+23); /*nreverse*/
	local[23]= local[12];
	ctx->vsp=local+24;
	w=(pointer)LENGTH(ctx,1,local+23); /*length*/
	local[23]= w;
	w = makeint((eusinteger_t)128L);
	if ((eusinteger_t)local[23] < (eusinteger_t)w) goto IF17885;
	local[23]= argv[0];
	local[24]= fqv[6];
	local[25]= fqv[333];
	local[26]= local[12];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,4,local+23); /*send*/
	local[23]= w;
	goto IF17886;
IF17885:
	local[23]= NIL;
IF17886:
	w = local[23];
	local[20]= w;
	goto IF17632;
IF17631:
	local[20]= NIL;
IF17632:
WHL17901:
	if (argv[3]==NIL) goto WHX17902;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!iscons(w)) goto WHX17902;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20]= (w)->c.cons.car;
	if (fqv[276]!=local[20]) goto WHX17902;
	local[20]= argv[0];
	local[21]= fqv[277];
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[3] = (w)->c.cons.cdr;
	w = local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.cdr;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	goto WHL17901;
WHX17902:
	local[20]= NIL;
BLK17903:
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[334];
	local[22]= local[2];
	local[23]= local[3];
	if (local[6]==NIL) goto IF17980;
	local[24]= makeint((eusinteger_t)1L);
	goto IF17981;
IF17980:
	if (local[7]==NIL) goto IF17986;
	local[24]= local[4];
	goto IF17987;
IF17986:
	local[24]= makeint((eusinteger_t)0L);
IF17987:
IF17981:
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,4,local+20); /*send*/
	local[1] = makeint((eusinteger_t)0L);
	local[20]= NIL;
	local[21]= local[10];
WHL18019:
	if (local[21]==NIL) goto WHX18020;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[20];
	local[25]= fqv[72];
	local[26]= local[1];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[1] = w;
	goto WHL18019;
WHX18020:
	local[22]= NIL;
BLK18021:
	w = NIL;
WHL18091:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX18092;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[335];
	local[22]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,4,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[22];
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[257];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[278];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	local[23]= fqv[70];
	local[24]= loadglobal(fqv[23]);
	local[25]= fqv[279];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SUB1(ctx,1,local+24); /*1-*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,5,local+20); /*send*/
	local[20]= local[1];
	ctx->vsp=local+21;
	w=(pointer)ADD1(ctx,1,local+20); /*1+*/
	local[1] = w;
	goto WHL18091;
WHX18092:
	local[20]= NIL;
BLK18093:
	if (local[0]==NIL) goto IF18258;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[257];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[22];
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	goto IF18259;
IF18258:
	local[20]= NIL;
IF18259:
	if (local[6]==NIL) goto CON18310;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[336];
	local[22]= local[2];
	local[23]= local[3];
	ctx->vsp=local+24;
	w=(pointer)PLUS(ctx,2,local+22); /*+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= argv[0];
	local[21]= fqv[278];
	local[22]= local[6];
	local[23]= fqv[70];
	local[24]= loadglobal(fqv[23]);
	local[25]= fqv[279];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SUB1(ctx,1,local+24); /*1-*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,5,local+20); /*send*/
	local[20]= w;
	goto CON18308;
CON18310:
	local[20]= local[3];
	local[21]= makeint((eusinteger_t)0L);
	ctx->vsp=local+22;
	w=(pointer)GREATERP(ctx,2,local+20); /*>*/
	if (w==NIL) goto CON18340;
	if (local[7]!=NIL) goto CON18340;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[337];
	local[22]= local[1];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[20]= w;
	goto CON18308;
CON18340:
	local[20]= NIL;
CON18308:
	if (local[7]==NIL) goto IF18358;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[279];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[14] = w;
	local[20]= loadglobal(fqv[23]);
	local[21]= fqv[338];
	local[22]= local[12];
	local[23]= loadglobal(fqv[179]);
	ctx->vsp=local+24;
	w=(pointer)COERCE(ctx,2,local+22); /*coerce*/
	local[22]= w;
	local[23]= local[2];
	local[24]= local[3];
	ctx->vsp=local+25;
	w=(pointer)PLUS(ctx,2,local+23); /*+*/
	local[23]= w;
	local[24]= local[4];
	local[25]= local[16];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,6,local+20); /*send*/
	local[20]= makeint((eusinteger_t)0L);
	local[21]= local[4];
WHL18417:
	local[22]= local[20];
	w = local[21];
	if ((eusinteger_t)local[22] >= (eusinteger_t)w) goto WHX18418;
	local[22]= argv[0];
	local[23]= fqv[254];
	local[24]= fqv[339];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[0] = w;
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[340];
	local[24]= local[20];
	local[25]= local[0];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= argv[0];
	local[23]= fqv[22];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[24];
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[22];
	local[18] = w;
	local[22]= argv[0];
	local[23]= fqv[281];
	local[24]= local[18];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	if (w==NIL) goto CON18529;
	local[22]= argv[0];
	local[23]= fqv[254];
	local[24]= fqv[341];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[19] = w;
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[256];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[257];
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[271];
	local[24]= makeint((eusinteger_t)1L);
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[52];
	local[24]= local[20];
	local[25]= local[14];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= makeint((eusinteger_t)0L);
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[257];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[18];
	local[25]= fqv[70];
	local[26]= local[14];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	local[27]= T;
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,6,local+22); /*send*/
	local[22]= w;
	goto CON18527;
CON18529:
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[18];
	local[25]= fqv[70];
	local[26]= local[14];
	local[27]= local[20];
	ctx->vsp=local+28;
	w=(pointer)PLUS(ctx,2,local+26); /*+*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[104];
	local[24]= local[14];
	local[25]= local[20];
	ctx->vsp=local+26;
	w=(pointer)PLUS(ctx,2,local+24); /*+*/
	local[24]= w;
	local[25]= makeint((eusinteger_t)0L);
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,4,local+22); /*send*/
	local[22]= loadglobal(fqv[23]);
	local[23]= fqv[257];
	local[24]= local[0];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	goto CON18527;
CON18599:
	local[22]= NIL;
CON18527:
	local[22]= local[20];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[20] = w;
	goto WHL18417;
WHX18418:
	local[22]= NIL;
BLK18419:
	w = NIL;
	local[20]= w;
	goto IF18359;
IF18358:
	local[20]= NIL;
IF18359:
	local[20]= NIL;
	local[21]= local[8];
WHL18662:
	if (local[21]==NIL) goto WHX18663;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	w = local[20];
	if (!iscons(w)) goto IF18711;
	local[22]= argv[0];
	local[23]= fqv[22];
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
	goto IF18712;
IF18711:
	local[22]= argv[0];
	local[23]= fqv[22];
	local[24]= NIL;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,3,local+22); /*send*/
	local[22]= w;
IF18712:
	local[22]= argv[0];
	local[23]= fqv[278];
	local[24]= local[20];
	ctx->vsp=local+25;
	w=(pointer)LISTP(ctx,1,local+24); /*listp*/
	if (w==NIL) goto IF18739;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[24]= (w)->c.cons.car;
	goto IF18740;
IF18739:
	local[24]= local[20];
IF18740:
	local[25]= fqv[70];
	local[26]= loadglobal(fqv[23]);
	local[27]= fqv[279];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SUB1(ctx,1,local+26); /*1-*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,5,local+22); /*send*/
	goto WHL18662;
WHX18663:
	local[22]= NIL;
BLK18664:
	w = NIL;
	local[20]= argv[0];
	local[21]= fqv[233];
	local[22]= argv[3];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	argv[0]->c.obj.iv[9] = local[17];
	local[20]= argv[0];
	local[21]= fqv[280];
	local[22]= T;
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,3,local+20); /*send*/
	local[0]= w;
BLK17298:
	ctx->vsp=local; return(local[0]);}

/*:lambda-block*/
static pointer M18787compiler_lambda_block(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	ctx->vsp=local+0;
	w=(pointer)RUNTIME(ctx,0,local+0); /*unix:runtime*/
	local[0]= w;
	local[1]= NIL;
	if (loadglobal(fqv[342])==NIL) goto IF18822;
	local[2]= T;
	local[3]= fqv[343];
	local[4]= makeint((eusinteger_t)27L);
	local[5]= argv[2];
	local[6]= makeint((eusinteger_t)27L);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,5,local+2); /*format*/
	local[2]= w;
	goto IF18823;
IF18822:
	local[2]= NIL;
IF18823:
	ctx->vsp=local+2;
	w=(pointer)FINOUT(ctx,0,local+2); /*finish-output*/
	local[2]= argv[0];
	local[3]= fqv[286];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[1] = w;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[17];
	local[4]= argv[5];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[344];
	local[4]= argv[3];
	local[5]= argv[4];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[257];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[345];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[287];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (loadglobal(fqv[342])==NIL) goto IF18883;
	local[2]= T;
	local[3]= fqv[346];
	local[4]= makeflt(1.6669999999999990381028e-02);
	ctx->vsp=local+5;
	w=(pointer)RUNTIME(ctx,0,local+5); /*unix:runtime*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
	goto IF18884;
IF18883:
	local[2]= NIL;
IF18884:
	w = argv[5];
	local[0]= w;
BLK18788:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO17505(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF18913;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF18914;
IF18913:
	local[0]= NIL;
IF18914:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO17616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF18938;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	goto IF18939;
IF18938:
	local[0]= argv[0];
IF18939:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:def-user-entry*/
static pointer M18978compiler_def_user_entry(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[347]!=local[0]) goto IF18993;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[0];
	local[2]= fqv[254];
	local[3]= fqv[348];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[14])(ctx,1,local+4,&ftab[14],fqv[21]); /*lisp::gencname-tail*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	local[4]= fqv[349];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= local[0];
	w = loadglobal(fqv[350]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[350],local[2]);
	w = local[2];
	local[0]= w;
	goto IF18994;
IF18993:
	local[0]= NIL;
IF18994:
	w = local[0];
	local[0]= w;
BLK18979:
	ctx->vsp=local; return(local[0]);}

/*:defun*/
static pointer M19050compiler_defun(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=6) maerror();
	local[0]= argv[3];
	local[1]= fqv[349];
	ctx->vsp=local+2;
	w=(pointer)GETPROP(ctx,2,local+0); /*get*/
	local[0]= w;
	local[1]= NIL;
	if (local[0]!=NIL) goto IF19088;
	local[2]= argv[0];
	local[3]= fqv[254];
	local[4]= fqv[351];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0] = w;
	local[2]= local[0];
	goto IF19089;
IF19088:
	local[2]= NIL;
IF19089:
	local[2]= loadglobal(fqv[315]);
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)GREATERP(ctx,2,local+2); /*>*/
	if (w==NIL) goto IF19106;
	local[2]= argv[3];
	local[3]= local[0];
	local[4]= fqv[349];
	ctx->vsp=local+5;
	w=(pointer)PUTPROP(ctx,3,local+2); /*putprop*/
	local[2]= argv[3];
	w = loadglobal(fqv[350]);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	storeglobal(fqv[350],local[2]);
	goto IF19107;
IF19106:
	local[2]= NIL;
IF19107:
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto IF19135;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF19135;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[5] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	goto IF19136;
IF19135:
	local[2]= NIL;
	local[3]= fqv[352];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,3,local+2); /*format*/
	local[2]= w;
IF19136:
	local[1] = local[2];
	local[2]= argv[0];
	local[3]= fqv[353];
	local[4]= argv[3];
	local[5]= argv[4];
	local[6]= argv[5];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[354];
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= argv[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK19051:
	ctx->vsp=local; return(local[0]);}

/*:defmethod*/
static pointer M19216compiler_defmethod(ctx,n,argv,env)
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
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)F6951object_variable_names(ctx,1,local+7); /*object-variable-names*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= NIL;
	local[10]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	local[11]= argv[0];
	local[12]= fqv[77];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= NIL;
	local[12]= local[7];
WHL19301:
	if (local[12]==NIL) goto WHX19302;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.car;
	w=local[12];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12] = (w)->c.cons.cdr;
	w = local[13];
	local[11] = w;
	local[13]= argv[0];
	local[14]= fqv[68];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[9] = w;
	local[13]= fqv[355];
	*(ovafptr(local[9],fqv[87])) = local[13];
	local[13]= local[8];
	*(ovafptr(local[9],fqv[91])) = local[13];
	local[13]= argv[0]->c.obj.iv[1];
	*(ovafptr(local[9],fqv[92])) = local[13];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)SYMVALUE(ctx,1,local+13); /*symbol-value*/
	local[13]= w;
	local[14]= local[11];
	ctx->vsp=local+15;
	w=(pointer)F6953object_variable_type(ctx,2,local+13); /*object-variable-type*/
	local[13]= w;
	local[14]= w;
	*(ovafptr(local[9],fqv[311])) = local[14];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)ADD1(ctx,1,local+13); /*1+*/
	local[8] = w;
	goto WHL19301;
WHX19302:
	local[13]= NIL;
BLK19303:
	w = NIL;
WHL19392:
	if (argv[2]==NIL) goto WHX19393;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[11];
	local[0] = w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[11]= fqv[356];
	local[12]= fqv[357];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[2] = cons(ctx,local[11],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[11]= argv[0];
	local[12]= fqv[254];
	local[13]= fqv[358];
	local[14]= local[6];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[14])(ctx,2,local+14,&ftab[14],fqv[21]); /*lisp::gencname-tail*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)SEND(ctx,4,local+11); /*send*/
	local[4] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!isstring(w)) goto IF19493;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF19493;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	goto IF19494;
IF19493:
	local[11]= NIL;
	local[12]= fqv[359];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)XFORMAT(ctx,3,local+11); /*format*/
	local[11]= w;
IF19494:
	local[10] = local[11];
	local[11]= argv[0];
	local[12]= fqv[353];
	local[13]= local[1];
	local[14]= local[2];
	local[15]= local[3];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,6,local+11); /*send*/
	local[11]= argv[0];
	local[12]= fqv[354];
	local[13]= fqv[360];
	local[14]= local[6];
	local[15]= local[1];
	local[16]= local[4];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,5,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	goto WHL19392;
WHX19393:
	local[11]= NIL;
BLK19394:
	local[6] = NIL;
	local[11]= argv[0];
	local[12]= fqv[280];
	local[13]= NIL;
	ctx->vsp=local+14;
	w=(pointer)SEND(ctx,3,local+11); /*send*/
	local[0]= w;
BLK19217:
	ctx->vsp=local; return(local[0]);}

/*:add-initcode*/
static pointer M19615compiler_add_initcode(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[7];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[7] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK19616:
	ctx->vsp=local; return(local[0]);}

/*:add-closure*/
static pointer M19641compiler_add_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[6];
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[6] = cons(ctx,local[0],w);
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK19642:
	ctx->vsp=local; return(local[0]);}

/*:closure-level*/
static pointer M19667compiler_closure_level(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)PLUS(ctx,2,local+0); /*+*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK19668:
	ctx->vsp=local; return(local[0]);}

/*:compile-a-closure*/
static pointer M19693compiler_compile_a_closure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	if (loadglobal(fqv[51])==NIL) goto IF19710;
	local[0]= T;
	local[1]= fqv[361];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF19711;
IF19710:
	local[0]= NIL;
IF19711:
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	argv[0]->c.obj.iv[6] = NIL;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[362];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[17];
	local[4]= argv[2];
	local[5]= fqv[363];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[344];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[345];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[364];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[0]= w;
BLK19694:
	ctx->vsp=local; return(local[0]);}

/*:compile-closures*/
static pointer M19784compiler_compile_closures(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)REVERSE(ctx,1,local+1); /*reverse*/
	local[1]= w;
WHL19816:
	if (local[1]==NIL) goto WHX19817;
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[365];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	goto WHL19816;
WHX19817:
	local[2]= NIL;
BLK19818:
	w = NIL;
	argv[0]->c.obj.iv[6] = NIL;
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK19785:
	ctx->vsp=local; return(local[0]);}

/*:toplevel-eval*/
static pointer M19900compiler_toplevel_eval(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[6] = NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	local[2]= local[1];
	w = fqv[366];
	if (memq(local[2],w)==NIL) goto IF19947;
	local[2]= argv[0];
	local[3]= fqv[367];
	local[4]= local[0];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,1,local+7,&ftab[15],fqv[368]); /*cdddr*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[364];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF19948;
IF19947:
	local[2]= local[1];
	w = fqv[369];
	if (memq(local[2],w)==NIL) goto IF19993;
	local[2]= argv[0];
	local[3]= fqv[370];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= argv[0];
	local[3]= fqv[364];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF19994;
IF19993:
	local[2]= local[1];
	w = fqv[371];
	if (memq(local[2],w)==NIL) goto IF20023;
	local[2]= NIL;
	goto IF20024;
IF20023:
	if (T==NIL) goto IF20034;
	local[2]= argv[0];
	local[3]= fqv[354];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF20035;
IF20034:
	local[2]= NIL;
IF20035:
IF20024:
IF19994:
IF19948:
	w = local[2];
	local[0]= w;
BLK19901:
	ctx->vsp=local; return(local[0]);}

/*:toplevel*/
static pointer M20047compiler_toplevel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT20051;}
	local[0]= NIL;
ENT20051:
ENT20050:
	if (n>5) maerror();
	if (local[0]!=NIL) goto IF20071;
	local[1]= loadglobal(fqv[23]);
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto IF20072;
IF20071:
	local[1]= NIL;
IF20072:
	w = argv[2];
	if (!!iscons(w)) goto IF20083;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK20048;
	goto IF20084;
IF20083:
	local[1]= NIL;
IF20084:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[16])(ctx,1,local+1,&ftab[16],fqv[372]); /*macro-function*/
	if (w==NIL) goto IF20093;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[44]); /*macroexpand*/
	argv[2] = w;
	local[1]= argv[2];
	goto IF20094;
IF20093:
	local[1]= NIL;
IF20094:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[373]!=local[1]) goto CON20117;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= NIL;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
WHL20169:
	if (local[3]==NIL) goto WHX20170;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= fqv[374];
	w = local[1];
	if (memq(local[4],w)==NIL) goto IF20219;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)EVAL(ctx,1,local+4); /*eval*/
	local[4]= w;
	goto IF20220;
IF20219:
	local[4]= NIL;
IF20220:
	local[4]= fqv[375];
	w = local[1];
	if (memq(local[4],w)==NIL) goto IF20238;
	local[4]= argv[0];
	local[5]= fqv[376];
	local[6]= local[2];
	local[7]= NIL;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,5,local+4); /*send*/
	local[4]= w;
	goto IF20239;
IF20238:
	local[4]= NIL;
IF20239:
	goto WHL20169;
WHX20170:
	local[4]= NIL;
BLK20171:
	w = NIL;
	local[1]= w;
	goto CON20115;
CON20117:
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[377]!=local[1]) goto CON20262;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[1];
WHL20310:
	if (argv[2]==NIL) goto WHX20311;
	local[1]= argv[0];
	local[2]= fqv[376];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	local[4]= argv[3];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,5,local+1); /*send*/
	goto WHL20310;
WHX20311:
	local[1]= NIL;
BLK20312:
	goto CON20115;
CON20262:
	if (argv[3]==NIL) goto IF20363;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)EVAL(ctx,1,local+1); /*eval*/
	local[1]= w;
	goto IF20364;
IF20363:
	local[1]= NIL;
IF20364:
	if (local[0]==NIL) goto IF20373;
	local[1]= argv[0];
	local[2]= fqv[378];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF20374;
IF20373:
	local[1]= argv[0];
	local[2]= fqv[379];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF20374:
	goto CON20115;
CON20359:
	local[1]= NIL;
CON20115:
	w = local[1];
	local[0]= w;
BLK20048:
	ctx->vsp=local; return(local[0]);}

/*:toplevel-execution*/
static pointer M20391compiler_toplevel_execution(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= local[0];
	local[2]= local[1];
	if (fqv[347]!=local[2]) goto IF20432;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[367];
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
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[53]); /*fourth*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
	goto IF20433;
IF20432:
	local[2]= local[1];
	if (fqv[380]!=local[2]) goto IF20464;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[381];
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
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[53]); /*fourth*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,5,local+2); /*send*/
	local[2]= w;
	goto IF20465;
IF20464:
	local[2]= local[1];
	if (fqv[360]!=local[2]) goto IF20496;
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[370];
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
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[8])(ctx,1,local+6,&ftab[8],fqv[53]); /*fourth*/
	local[6]= w;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[54]); /*fifth*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	local[2]= w;
	goto IF20497;
IF20496:
	if (T==NIL) goto IF20531;
	local[2]= argv[0];
	local[3]= fqv[22];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= loadglobal(fqv[23]);
	local[3]= fqv[24];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF20532;
IF20531:
	local[2]= NIL;
IF20532:
IF20497:
IF20465:
IF20433:
	w = local[2];
	local[0]= w;
BLK20392:
	ctx->vsp=local; return(local[0]);}

/*:compile-file*/
static pointer M20553compiler_compile_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[382], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY20575;
	local[0] = fqv[383];
KEY20575:
	if (n & (1<<1)) goto KEY20580;
	local[1] = loadglobal(fqv[315]);
KEY20580:
	if (n & (1<<2)) goto KEY20586;
	local[2] = makeint((eusinteger_t)2L);
KEY20586:
	if (n & (1<<3)) goto KEY20591;
	local[3] = loadglobal(fqv[182]);
KEY20591:
	if (n & (1<<4)) goto KEY20597;
	local[4] = loadglobal(fqv[384]);
KEY20597:
	if (n & (1<<5)) goto KEY20604;
	local[5] = loadglobal(fqv[385]);
KEY20604:
	if (n & (1<<6)) goto KEY20611;
	local[6] = loadglobal(fqv[342]);
KEY20611:
	if (n & (1<<7)) goto KEY20617;
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[17])(ctx,1,local+9,&ftab[17],fqv[386]); /*pathname-name*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[14])(ctx,1,local+9,&ftab[14],fqv[21]); /*lisp::gencname-tail*/
	local[7] = w;
KEY20617:
	if (n & (1<<8)) goto KEY20628;
	local[8] = NIL;
KEY20628:
	w = local[2];
	if (!isint(w)) goto IF20637;
	local[9]= local[2];
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF20637;
	local[9]= NIL;
	local[10]= fqv[387];
	local[11]= local[2];
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,3,local+9); /*format*/
	local[9]= w;
	storeglobal(fqv[388],w);
	goto IF20638;
IF20637:
	local[9]= fqv[389];
	storeglobal(fqv[388],local[9]);
IF20638:
	storeglobal(fqv[315],local[1]);
	storeglobal(fqv[182],local[3]);
	local[9]= local[6];
	storeglobal(fqv[342],local[9]);
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(*ftab[18])(ctx,1,local+9,&ftab[18],fqv[390]); /*pathname*/
	local[9]= w;
	local[10]= fqv[391];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (w!=NIL) goto IF20673;
	local[9]= fqv[392];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[19])(ctx,2,local+9,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(*ftab[20])(ctx,1,local+9,&ftab[20],fqv[394]); /*namestring*/
	argv[2] = w;
	local[9]= argv[2];
	goto IF20674;
IF20673:
	local[9]= NIL;
IF20674:
	if (local[8]==NIL) goto IF20703;
	local[9]= local[8];
	ctx->vsp=local+10;
	w=(*ftab[18])(ctx,1,local+9,&ftab[18],fqv[390]); /*pathname*/
	local[8] = w;
	local[9]= local[8];
	local[10]= argv[2];
	ctx->vsp=local+11;
	w=(*ftab[19])(ctx,2,local+9,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[8] = w;
	local[9]= fqv[395];
	local[10]= local[8];
	ctx->vsp=local+11;
	w=(*ftab[19])(ctx,2,local+9,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[8] = w;
	local[9]= local[8];
	goto IF20704;
IF20703:
	local[9]= NIL;
IF20704:
	local[9]= NIL;
	local[10]= NIL;
	local[11]= NIL;
	local[12]= NIL;
	local[13]= NIL;
	local[14]= fqv[396];
	local[15]= argv[2];
	ctx->vsp=local+16;
	w=(*ftab[19])(ctx,2,local+14,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[14]= w;
	local[15]= fqv[397];
	local[16]= argv[2];
	ctx->vsp=local+17;
	w=(*ftab[19])(ctx,2,local+15,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[15]= w;
	local[16]= fqv[398];
	local[17]= argv[2];
	ctx->vsp=local+18;
	w=(*ftab[19])(ctx,2,local+16,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[16]= w;
	if (local[8]==NIL) goto IF20780;
	local[17]= local[8];
	goto IF20781;
IF20780:
	local[17]= fqv[399];
	local[18]= argv[2];
	ctx->vsp=local+19;
	w=(*ftab[19])(ctx,2,local+17,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[17]= w;
IF20781:
	if (local[8]==NIL) goto IF20793;
	local[18]= fqv[400];
	local[19]= local[8];
	ctx->vsp=local+20;
	w=(*ftab[19])(ctx,2,local+18,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[18]= w;
	goto IF20794;
IF20793:
	local[18]= fqv[401];
	local[19]= argv[2];
	ctx->vsp=local+20;
	w=(*ftab[19])(ctx,2,local+18,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[18]= w;
IF20794:
	if (local[8]==NIL) goto IF20808;
	local[19]= fqv[402];
	local[20]= local[8];
	ctx->vsp=local+21;
	w=(*ftab[19])(ctx,2,local+19,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[19]= w;
	goto IF20809;
IF20808:
	local[19]= fqv[403];
	local[20]= argv[2];
	ctx->vsp=local+21;
	w=(*ftab[19])(ctx,2,local+19,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[19]= w;
IF20809:
	local[20]= loadglobal(fqv[404]);
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[18])(ctx,1,local+21,&ftab[18],fqv[390]); /*pathname*/
	local[21]= w;
	local[22]= fqv[405];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= w;
	local[22]= makeint((eusinteger_t)2L);
	ctx->vsp=local+23;
	w=(pointer)ACCESS(ctx,2,local+21); /*unix:access*/
	local[21]= w;
	if (T==local[21]) goto IF20829;
	local[21]= fqv[406];
	local[22]= argv[2];
	local[23]= local[8];
	local[24]= fqv[405];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,2,local+23); /*send*/
	local[23]= w;
	ctx->vsp=local+24;
	w=(*ftab[1])(ctx,3,local+21,&ftab[1],fqv[14]); /*warn*/
	local[21]= fqv[407];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[14] = w;
	local[21]= fqv[408];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[15] = w;
	local[21]= fqv[409];
	local[22]= local[8];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[16] = w;
	local[21]= local[16];
	goto IF20830;
IF20829:
	local[21]= NIL;
IF20830:
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[21])(ctx,1,local+21,&ftab[21],fqv[410]); /*probe-file*/
	if (w!=NIL) goto IF20875;
	local[21]= fqv[411];
	local[22]= argv[2];
	ctx->vsp=local+23;
	w=(*ftab[19])(ctx,2,local+21,&ftab[19],fqv[393]); /*merge-pathnames*/
	argv[2] = w;
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[21])(ctx,1,local+21,&ftab[21],fqv[410]); /*probe-file*/
	if (w!=NIL) goto IF20896;
	local[21]= fqv[412];
	local[22]= argv[2];
	ctx->vsp=local+23;
	w=(pointer)SIGERROR(ctx,2,local+21); /*error*/
	local[21]= w;
	goto IF20897;
IF20896:
	local[21]= NIL;
IF20897:
	goto IF20876;
IF20875:
	local[21]= NIL;
IF20876:
	local[21]= fqv[413];
	local[22]= argv[2];
	ctx->vsp=local+23;
	w=(*ftab[20])(ctx,1,local+22,&ftab[20],fqv[394]); /*namestring*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(*ftab[1])(ctx,2,local+21,&ftab[1],fqv[14]); /*warn*/
	local[21]= argv[2];
	ctx->vsp=local+22;
	w=(*ftab[22])(ctx,1,local+21,&ftab[22],fqv[414]); /*open*/
	local[12] = w;
	local[21]= NIL;
	storeglobal(fqv[350],local[21]);
	if (loadglobal(fqv[415])==NIL) goto IF20930;
WHL20940:
	if (T==NIL) goto WHX20941;
	local[21]= local[12];
	local[22]= NIL;
	local[23]= fqv[416];
	ctx->vsp=local+24;
	w=(pointer)READ(ctx,3,local+21); /*read*/
	local[11] = w;
	local[21]= local[11];
	if (fqv[416]!=local[21]) goto IF20958;
	w = NIL;
	ctx->vsp=local+21;
	local[21]=w;
	goto BLK20942;
	goto IF20959;
IF20958:
	local[21]= NIL;
IF20959:
	local[21]= argv[0];
	local[22]= fqv[376];
	local[23]= local[11];
	local[24]= T;
	local[25]= T;
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,5,local+21); /*send*/
	goto WHL20940;
WHX20941:
	local[21]= NIL;
BLK20942:
	local[21]= local[12];
	local[22]= makeint((eusinteger_t)0L);
	ctx->vsp=local+23;
	w=(pointer)LSEEK(ctx,2,local+21); /*unix:lseek*/
	local[21]= w;
	goto IF20931;
IF20930:
	local[21]= NIL;
IF20931:
	local[21]= loadglobal(fqv[350]);
	ctx->vsp=local+22;
	w=(pointer)NREVERSE(ctx,1,local+21); /*nreverse*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[417];
	local[23]= argv[2];
	local[24]= local[14];
	local[25]= local[15];
	local[26]= local[7];
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,6,local+21); /*send*/
	local[21]= argv[0]->c.obj.iv[0];
	local[22]= fqv[418];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	argv[0]->c.obj.iv[3] = NIL;
	argv[0]->c.obj.iv[2] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[4] = NIL;
	argv[0]->c.obj.iv[7] = NIL;
WHL21014:
	if (T==NIL) goto WHX21015;
	local[21]= local[12];
	local[22]= NIL;
	local[23]= fqv[416];
	ctx->vsp=local+24;
	w=(pointer)READ(ctx,3,local+21); /*read*/
	local[11] = w;
	local[21]= local[11];
	if (fqv[416]!=local[21]) goto IF21032;
	w = NIL;
	ctx->vsp=local+21;
	local[21]=w;
	goto BLK21016;
	goto IF21033;
IF21032:
	local[21]= NIL;
IF21033:
	local[21]= argv[0];
	local[22]= fqv[376];
	local[23]= local[11];
	local[24]= T;
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,4,local+21); /*send*/
	goto WHL21014;
WHX21015:
	local[21]= NIL;
BLK21016:
	local[21]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+22;
	w=(pointer)REVERSE(ctx,1,local+21); /*reverse*/
	argv[0]->c.obj.iv[7] = w;
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[419];
	local[23]= local[7];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,3,local+21); /*send*/
	local[21]= NIL;
	local[22]= argv[0]->c.obj.iv[7];
WHL21085:
	if (local[22]==NIL) goto WHX21086;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= argv[0];
	local[24]= fqv[420];
	local[25]= local[21];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,3,local+23); /*send*/
	goto WHL21085;
WHX21086:
	local[23]= NIL;
BLK21087:
	w = NIL;
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[25];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[345];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= argv[0];
	local[22]= fqv[364];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[421];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[422];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= *(ovafptr(local[20],fqv[423]));
	local[22]= *(ovafptr(local[20],fqv[424]));
	local[23]= makeint((eusinteger_t)0L);
	ctx->vsp=local+24;
	w=(*ftab[2])(ctx,1,local+23,&ftab[2],fqv[18]); /*make-array*/
	local[23]= w;
	*(ovafptr(local[20],fqv[423])) = local[23];
	local[23]= makeint((eusinteger_t)1L);
	local[24]= local[23];
	*(ovafptr(local[20],fqv[424])) = local[24];
	local[23]= loadglobal(fqv[23]);
	local[24]= fqv[425];
	ctx->vsp=local+25;
	w=(pointer)SEND(ctx,2,local+23); /*send*/
	local[23]= local[21];
	*(ovafptr(local[20],fqv[423])) = local[23];
	local[23]= local[22];
	local[24]= local[23];
	*(ovafptr(local[20],fqv[424])) = local[24];
	w = local[23];
	local[21]= loadglobal(fqv[23]);
	local[22]= fqv[426];
	ctx->vsp=local+23;
	w=(pointer)SEND(ctx,2,local+21); /*send*/
	local[21]= local[12];
	ctx->vsp=local+22;
	w=(pointer)CLOSE(ctx,1,local+21); /*close*/
	local[21]= loadglobal(fqv[20]);
	local[22]= loadglobal(fqv[427]);
	local[23]= fqv[428];
	if (local[8]==NIL) goto IF21232;
	local[24]= loadglobal(fqv[20]);
	local[25]= fqv[429];
	local[26]= local[8];
	ctx->vsp=local+27;
	w=(*ftab[20])(ctx,1,local+26,&ftab[20],fqv[394]); /*namestring*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)CONCATENATE(ctx,3,local+24); /*concatenate*/
	local[24]= w;
	goto IF21233;
IF21232:
	local[24]= NIL;
IF21233:
	local[25]= fqv[430];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21246;
	local[25]= fqv[432];
	goto CON21244;
CON21246:
	local[25]= fqv[433];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21257;
	local[25]= fqv[434];
	goto CON21244;
CON21257:
	local[25]= fqv[435];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21267;
	local[25]= fqv[436];
	goto CON21244;
CON21267:
	local[25]= fqv[437];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21277;
	local[25]= fqv[438];
	goto CON21244;
CON21277:
	local[25]= fqv[439];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21287;
	local[25]= fqv[440];
	goto CON21244;
CON21287:
	local[25]= fqv[441];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21297;
	local[25]= fqv[442];
	goto CON21244;
CON21297:
	local[25]= fqv[443];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21307;
	local[25]= fqv[444];
	goto CON21244;
CON21307:
	local[25]= fqv[445];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21317;
	local[25]= fqv[446];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto IF21328;
	local[25]= fqv[447];
	goto IF21329;
IF21328:
	local[25]= fqv[448];
IF21329:
	goto CON21244;
CON21317:
	local[25]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21338;
	local[25]= fqv[450];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21338;
	local[25]= fqv[446];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21360;
	local[25]= fqv[451];
	goto CON21358;
CON21360:
	local[25]= fqv[452];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21370;
	local[25]= fqv[453];
	goto CON21358;
CON21370:
	local[25]= fqv[454];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21380;
	local[25]= fqv[455];
	goto CON21358;
CON21380:
	local[25]= fqv[456];
	goto CON21358;
CON21390:
	local[25]= NIL;
CON21358:
	goto CON21244;
CON21338:
	local[25]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21393;
	local[25]= fqv[446];
	w = loadglobal(fqv[457]);
	if (memq(local[25],w)==NIL) goto IF21404;
	local[25]= fqv[458];
	goto IF21405;
IF21404:
	local[25]= fqv[459];
IF21405:
	goto CON21244;
CON21393:
	local[25]= fqv[460];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21415;
	local[25]= fqv[461];
	goto CON21244;
CON21415:
	local[25]= fqv[462];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21425;
	local[25]= fqv[463];
	goto CON21244;
CON21425:
	local[25]= fqv[464];
	w = loadglobal(fqv[431]);
	if (memq(local[25],w)==NIL) goto CON21435;
	local[25]= fqv[465];
	goto CON21244;
CON21435:
	local[25]= fqv[466];
	ctx->vsp=local+26;
	w=(*ftab[1])(ctx,1,local+25,&ftab[1],fqv[14]); /*warn*/
	local[25]= w;
	goto CON21244;
CON21445:
	local[25]= NIL;
CON21244:
	local[26]= fqv[467];
	w = loadglobal(fqv[431]);
	if (memq(local[26],w)==NIL) goto CON21453;
	local[26]= fqv[468];
	goto CON21451;
CON21453:
	local[26]= fqv[469];
	w = loadglobal(fqv[431]);
	if (memq(local[26],w)==NIL) goto CON21463;
	local[26]= fqv[470];
	goto CON21451;
CON21463:
	local[26]= fqv[471];
	w = loadglobal(fqv[431]);
	if (memq(local[26],w)==NIL) goto CON21473;
	local[26]= fqv[472];
	goto CON21451;
CON21473:
	local[26]= fqv[473];
	goto CON21451;
CON21483:
	local[26]= NIL;
CON21451:
	local[27]= fqv[474];
	w = loadglobal(fqv[431]);
	if (memq(local[27],w)==NIL) goto IF21487;
	local[27]= fqv[475];
	goto IF21488;
IF21487:
	local[27]= NIL;
IF21488:
	local[28]= fqv[476];
	w = loadglobal(fqv[431]);
	if (memq(local[28],w)==NIL) goto IF21498;
	local[28]= fqv[477];
	goto IF21499;
IF21498:
	local[28]= NIL;
IF21499:
	local[29]= fqv[478];
	w = loadglobal(fqv[431]);
	if (memq(local[29],w)==NIL) goto IF21509;
	local[29]= fqv[479];
	goto IF21510;
IF21509:
	local[29]= NIL;
IF21510:
	local[30]= fqv[480];
	w = loadglobal(fqv[431]);
	if (memq(local[30],w)==NIL) goto IF21520;
	local[30]= fqv[481];
	goto IF21521;
IF21520:
	local[30]= NIL;
IF21521:
	if (local[5]==NIL) goto IF21531;
	local[31]= fqv[469];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21539;
	local[31]= fqv[482];
	goto CON21537;
CON21539:
	local[31]= fqv[462];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21549;
	local[31]= fqv[483];
	goto CON21537;
CON21549:
	local[31]= fqv[474];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21559;
	local[31]= fqv[484];
	goto CON21537;
CON21559:
	local[31]= fqv[471];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21569;
	local[31]= fqv[485];
	goto CON21537;
CON21569:
	local[31]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21579;
	local[31]= fqv[486];
	goto CON21537;
CON21579:
	local[31]= fqv[435];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21589;
	local[31]= fqv[487];
	goto CON21537;
CON21589:
	local[31]= fqv[437];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21599;
	local[31]= fqv[488];
	goto CON21537;
CON21599:
	local[31]= fqv[460];
	w = loadglobal(fqv[431]);
	if (memq(local[31],w)==NIL) goto CON21609;
	local[31]= fqv[489];
	goto CON21537;
CON21609:
	local[31]= fqv[490];
	goto CON21537;
CON21619:
	local[31]= NIL;
CON21537:
	goto IF21532;
IF21531:
	local[31]= NIL;
IF21532:
	local[32]= local[0];
	local[33]= fqv[491];
	local[34]= loadglobal(fqv[492]);
	ctx->vsp=local+35;
	w=(*ftab[20])(ctx,1,local+34,&ftab[20],fqv[394]); /*namestring*/
	local[34]= w;
	local[35]= fqv[493];
	local[36]= loadglobal(fqv[388]);
	local[37]= loadglobal(fqv[494]);
	local[38]= fqv[495];
	local[39]= local[14];
	ctx->vsp=local+40;
	w=(*ftab[20])(ctx,1,local+39,&ftab[20],fqv[394]); /*namestring*/
	local[39]= w;
	local[40]= fqv[469];
	w = loadglobal(fqv[431]);
	if (memq(local[40],w)==NIL) goto IF21634;
	if (local[5]==NIL) goto IF21634;
	local[40]= loadglobal(fqv[20]);
	local[41]= fqv[496];
	local[42]= local[18];
	ctx->vsp=local+43;
	w=(*ftab[20])(ctx,1,local+42,&ftab[20],fqv[394]); /*namestring*/
	local[42]= w;
	local[43]= fqv[497];
	local[44]= local[17];
	ctx->vsp=local+45;
	w=(*ftab[20])(ctx,1,local+44,&ftab[20],fqv[394]); /*namestring*/
	local[44]= w;
	ctx->vsp=local+45;
	w=(pointer)CONCATENATE(ctx,5,local+40); /*concatenate*/
	local[40]= w;
	goto IF21635;
IF21634:
	local[40]= NIL;
IF21635:
	local[41]= fqv[435];
	w = loadglobal(fqv[431]);
	if (memq(local[41],w)!=NIL) goto OR21661;
	local[41]= fqv[437];
	w = loadglobal(fqv[431]);
	if (memq(local[41],w)!=NIL) goto OR21661;
	goto IF21658;
OR21661:
	if (local[5]==NIL) goto IF21658;
	local[41]= loadglobal(fqv[20]);
	local[42]= fqv[498];
	local[43]= local[18];
	ctx->vsp=local+44;
	w=(*ftab[20])(ctx,1,local+43,&ftab[20],fqv[394]); /*namestring*/
	local[43]= w;
	local[44]= fqv[499];
	local[45]= local[17];
	ctx->vsp=local+46;
	w=(*ftab[20])(ctx,1,local+45,&ftab[20],fqv[394]); /*namestring*/
	local[45]= w;
	ctx->vsp=local+46;
	w=(pointer)CONCATENATE(ctx,5,local+41); /*concatenate*/
	local[41]= w;
	goto IF21659;
IF21658:
	local[41]= NIL;
IF21659:
	local[42]= fqv[449];
	w = loadglobal(fqv[431]);
	if (memq(local[42],w)==NIL) goto IF21692;
	if (local[5]==NIL) goto IF21692;
	local[42]= loadglobal(fqv[20]);
	local[43]= fqv[445];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto CON21711;
	local[43]= fqv[500];
	goto CON21709;
CON21711:
	local[43]= fqv[501];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto CON21721;
	local[43]= fqv[502];
	goto CON21709;
CON21721:
	local[43]= fqv[503];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto CON21731;
	local[43]= fqv[504];
	goto CON21709;
CON21731:
	local[43]= fqv[505];
	goto CON21709;
CON21741:
	local[43]= NIL;
CON21709:
	local[44]= local[18];
	ctx->vsp=local+45;
	w=(*ftab[20])(ctx,1,local+44,&ftab[20],fqv[394]); /*namestring*/
	local[44]= w;
	local[45]= fqv[506];
	local[46]= local[17];
	ctx->vsp=local+47;
	w=(*ftab[20])(ctx,1,local+46,&ftab[20],fqv[394]); /*namestring*/
	local[46]= w;
	ctx->vsp=local+47;
	w=(pointer)CONCATENATE(ctx,5,local+42); /*concatenate*/
	local[42]= w;
	goto IF21693;
IF21692:
	local[42]= fqv[507];
IF21693:
	local[43]= fqv[460];
	w = loadglobal(fqv[431]);
	if (memq(local[43],w)==NIL) goto IF21752;
	if (local[5]==NIL) goto IF21752;
	local[43]= loadglobal(fqv[20]);
	local[44]= fqv[508];
	local[45]= local[18];
	ctx->vsp=local+46;
	w=(*ftab[20])(ctx,1,local+45,&ftab[20],fqv[394]); /*namestring*/
	local[45]= w;
	local[46]= fqv[509];
	local[47]= local[17];
	ctx->vsp=local+48;
	w=(*ftab[20])(ctx,1,local+47,&ftab[20],fqv[394]); /*namestring*/
	local[47]= w;
	ctx->vsp=local+48;
	w=(pointer)CONCATENATE(ctx,5,local+43); /*concatenate*/
	local[43]= w;
	goto IF21753;
IF21752:
	local[43]= fqv[510];
IF21753:
	local[44]= fqv[462];
	w = loadglobal(fqv[431]);
	if (memq(local[44],w)==NIL) goto IF21776;
	if (loadglobal(fqv[511])!=NIL) goto IF21776;
	local[44]= loadglobal(fqv[20]);
	local[45]= fqv[512];
	local[46]= local[19];
	ctx->vsp=local+47;
	w=(*ftab[20])(ctx,1,local+46,&ftab[20],fqv[394]); /*namestring*/
	local[46]= w;
	local[47]= fqv[513];
	local[48]= local[17];
	ctx->vsp=local+49;
	w=(*ftab[20])(ctx,1,local+48,&ftab[20],fqv[394]); /*namestring*/
	local[48]= w;
	local[49]= fqv[514];
	local[50]= loadglobal(fqv[492]);
	local[51]= fqv[515];
	ctx->vsp=local+52;
	w=(pointer)GETENV(ctx,1,local+51); /*unix:getenv*/
	local[51]= w;
	local[52]= fqv[516];
	local[53]= fqv[517];
	local[54]= fqv[518];
	ctx->vsp=local+55;
	w=(pointer)CONCATENATE(ctx,11,local+44); /*concatenate*/
	local[44]= w;
	goto IF21777;
IF21776:
	local[44]= NIL;
IF21777:
	ctx->vsp=local+45;
	w=(pointer)CONCATENATE(ctx,24,local+21); /*concatenate*/
	local[13] = w;
	if (local[4]==NIL) goto IF21810;
	local[21]= fqv[519];
	local[22]= local[13];
	ctx->vsp=local+23;
	w=(*ftab[1])(ctx,2,local+21,&ftab[1],fqv[14]); /*warn*/
	local[21]= local[13];
	ctx->vsp=local+22;
	w=(pointer)SYSTEM(ctx,1,local+21); /*unix:system*/
	local[21]= w;
	goto IF21811;
IF21810:
	local[21]= NIL;
IF21811:
	local[21]= NIL;
	local[22]= loadglobal(fqv[350]);
WHL21844:
	if (local[22]==NIL) goto WHX21845;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[23]= (w)->c.cons.car;
	w=local[22];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22] = (w)->c.cons.cdr;
	w = local[23];
	local[21] = w;
	local[23]= local[21];
	local[24]= fqv[349];
	ctx->vsp=local+25;
	w=(*ftab[23])(ctx,2,local+23,&ftab[23],fqv[520]); /*remprop*/
	goto WHL21844;
WHX21845:
	local[23]= NIL;
BLK21846:
	w = NIL;
	local[21]= loadglobal(fqv[59]);
	ctx->vsp=local+22;
	w=(pointer)TERPRI(ctx,1,local+21); /*terpri*/
	local[0]= w;
BLK20554:
	ctx->vsp=local; return(local[0]);}

/*:specials*/
static pointer M21907compiler_specials(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[521];
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= fqv[522];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK21908:
	ctx->vsp=local; return(local[0]);}

/*:copy-compiler*/
static pointer M21929compiler_copy_compiler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[6];
	argv[0]->c.obj.iv[7] = NIL;
	argv[0]->c.obj.iv[6] = NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYOBJ(ctx,1,local+3); /*copy-object*/
	local[0] = w;
	local[3]= local[0];
	local[4]= fqv[523];
	local[5]= makeint((eusinteger_t)1L);
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	argv[0]->c.obj.iv[7] = local[1];
	argv[0]->c.obj.iv[6] = local[2];
	w = local[0];
	local[0]= w;
BLK21930:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M21996compiler_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[524]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	storeglobal(fqv[23],w);
	local[0]= loadglobal(fqv[525]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[0] = w;
	argv[0]->c.obj.iv[2] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[1] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK21997:
	ctx->vsp=local; return(local[0]);}

/*dump-function*/
static pointer F7014dump_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST22063:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	local[2]= fqv[526];
	local[3]= fqv[527];
	ctx->vsp=local+4;
	w=(*ftab[22])(ctx,3,local+1,&ftab[22],fqv[414]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP22092,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= NIL;
	local[5]= local[0];
WHL22116:
	if (local[5]==NIL) goto WHX22117;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)SYMFUNC(ctx,1,local+6); /*symbol-function*/
	local[6]= w;
	local[7]= NIL;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[8];
	if (fqv[39]!=local[9]) goto IF22199;
	local[9]= fqv[347];
	local[10]= local[4];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	goto IF22200;
IF22199:
	local[9]= local[8];
	if (fqv[43]!=local[9]) goto IF22221;
	local[9]= fqv[347];
	local[10]= local[4];
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	goto IF22222;
IF22221:
	local[9]= NIL;
IF22222:
IF22200:
	w = local[9];
	local[7] = w;
	local[8]= local[7];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(*ftab[24])(ctx,2,local+8,&ftab[24],fqv[528]); /*pprint*/
	goto WHL22116;
WHX22117:
	local[6]= NIL;
BLK22118:
	w = NIL;
	ctx->vsp=local+4;
	UWP22092(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK22061:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP22092(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*comfile*/
static pointer F7016comfile(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22274:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= local[0];
WHL22300:
	if (local[2]==NIL) goto WHX22301;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= loadglobal(fqv[5]);
	local[4]= fqv[529];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	goto WHL22300;
WHX22301:
	local[3]= NIL;
BLK22302:
	w = NIL;
	local[0]= w;
BLK22272:
	ctx->vsp=local; return(local[0]);}

/*compile-file*/
static pointer F7018compile_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST22362:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= (pointer)get_sym_func(fqv[530]);
	local[2]= loadglobal(fqv[5]);
	local[3]= fqv[529];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[0]= w;
BLK22360:
	ctx->vsp=local; return(local[0]);}

/*compile*/
static pointer F7020compile(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22387:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= fqv[531];
	ctx->vsp=local+3;
	w=(pointer)GETPID(ctx,0,local+3); /*unix:getpid*/
	local[3]= w;
	local[4]= fqv[532];
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,1,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[13])(ctx,1,local+4,&ftab[13],fqv[331]); /*symbol-name*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,4,local+1); /*format*/
	local[1]= w;
	local[2]= NIL;
	local[3]= (pointer)get_sym_func(fqv[533]);
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F7018compile_file(ctx,1,local+3); /*compile-file*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[534];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[535];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[536]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[534];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[537];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[536]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[534];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[538];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[536]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[26])(ctx,1,local+3,&ftab[26],fqv[375]); /*load*/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	local[3]= fqv[534];
	local[4]= local[1];
	local[5]= fqv[97];
	local[6]= fqv[539];
	ctx->vsp=local+7;
	w=(*ftab[25])(ctx,4,local+3,&ftab[25],fqv[536]); /*make-pathname*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[20])(ctx,1,local+3,&ftab[20],fqv[394]); /*namestring*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)UNLINK(ctx,1,local+3); /*unix:unlink*/
	w = local[0];
	local[0]= w;
BLK22385:
	ctx->vsp=local; return(local[0]);}

/*compile-file-if-src-newer*/
static pointer F7022compile_file_if_src_newer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT22522;}
	local[0]= fqv[540];
ENT22522:
ENT22521:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-2);
	local[2]= argv[0];
	local[3]= fqv[541];
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,2,local+2,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[2]= w;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,1,local+4,&ftab[18],fqv[390]); /*pathname*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[19])(ctx,2,local+3,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[3]= w;
	local[4]= fqv[542];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,1,local+5,&ftab[18],fqv[390]); /*pathname*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[19])(ctx,2,local+4,&ftab[19],fqv[393]); /*merge-pathnames*/
	local[4]= w;
	local[5]= local[3];
	local[6]= fqv[97];
	local[7]= fqv[543];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[21])(ctx,1,local+5,&ftab[21],fqv[410]); /*probe-file*/
	if (w==NIL) goto OR22576;
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(*ftab[27])(ctx,2,local+5,&ftab[27],fqv[544]); /*file-newer*/
	if (w!=NIL) goto OR22576;
	goto IF22574;
OR22576:
	local[5]= (pointer)get_sym_func(fqv[545]);
	local[6]= argv[0];
	local[7]= fqv[546];
	local[8]= local[3];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)APPLY(ctx,5,local+5); /*apply*/
	local[5]= w;
	goto IF22575;
IF22574:
	local[5]= NIL;
IF22575:
	w = argv[0];
	local[0]= w;
BLK22519:
	ctx->vsp=local; return(local[0]);}

/*comp-file-toplevel*/
static pointer F7024comp_file_toplevel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST22611:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[547];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[14]); /*warn*/
	local[1]= loadglobal(fqv[59]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= makeint((eusinteger_t)60000L);
	ctx->vsp=local+2;
	w=(pointer)ALLOC(ctx,1,local+1); /*system:alloc*/
	local[1]= fqv[548];
	storeglobal(fqv[549],local[1]);
	local[1]= makeint((eusinteger_t)1L);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= fqv[550];
	w = local[5];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[551],w);
	local[9]= local[2];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto CON22668;
	local[9]= (pointer)get_sym_func(fqv[552]);
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	goto CON22666;
CON22668:
	local[9]= local[2];
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto CON22678;
	local[9]= T;
	local[10]= fqv[553];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,2,local+9); /*format*/
	local[9]= makeint((eusinteger_t)1L);
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,1,local+9,&ftab[28],fqv[554]); /*exit*/
	local[9]= w;
	goto CON22666;
CON22678:
WHL22693:
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)LESSP(ctx,2,local+9); /*<*/
	if (w==NIL) goto WHX22694;
	{jmp_buf jb;
	w = makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT22702;}
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[3] = w;
	local[15]= local[3];
	ctx->vsp=local+16;
	w=(*ftab[29])(ctx,1,local+15,&ftab[29],fqv[555]); /*string-upcase*/
	local[4] = w;
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[4];
	local[16]= fqv[556];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22739;
	local[15]= fqv[439];
	w = loadglobal(fqv[431]);
	if (memq(local[15],w)!=NIL) goto IF22747;
	local[15]= fqv[557];
	storeglobal(fqv[388],local[15]);
	goto IF22748;
IF22747:
	local[15]= NIL;
IF22748:
	goto CON22737;
CON22739:
	local[15]= local[4];
	local[16]= fqv[558];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22761;
	local[15]= makeint((eusinteger_t)1L);
	storeglobal(fqv[315],local[15]);
	goto CON22737;
CON22761:
	local[15]= local[4];
	local[16]= fqv[559];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22772;
	local[15]= makeint((eusinteger_t)2L);
	storeglobal(fqv[315],local[15]);
	goto CON22737;
CON22772:
	local[15]= local[4];
	local[16]= fqv[560];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22783;
	local[15]= makeint((eusinteger_t)3L);
	storeglobal(fqv[315],local[15]);
	goto CON22737;
CON22783:
	local[15]= local[4];
	local[16]= fqv[561];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22794;
	local[15]= T;
	storeglobal(fqv[342],local[15]);
	goto CON22737;
CON22794:
	local[15]= local[4];
	local[16]= fqv[562];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22805;
	local[15]= makeint((eusinteger_t)0L);
	storeglobal(fqv[182],local[15]);
	goto CON22737;
CON22805:
	local[15]= local[4];
	local[16]= fqv[563];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22816;
	local[15]= makeint((eusinteger_t)1L);
	storeglobal(fqv[182],local[15]);
	goto CON22737;
CON22816:
	local[15]= local[4];
	local[16]= fqv[564];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22827;
	local[15]= makeint((eusinteger_t)2L);
	storeglobal(fqv[182],local[15]);
	goto CON22737;
CON22827:
	local[15]= local[4];
	local[16]= fqv[565];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22838;
	local[15]= makeint((eusinteger_t)3L);
	storeglobal(fqv[182],local[15]);
	goto CON22737;
CON22838:
	local[15]= local[4];
	local[16]= fqv[566];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22849;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[30])(ctx,1,local+15,&ftab[30],fqv[567]); /*read-from-string*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(pointer)EVAL(ctx,1,local+15); /*eval*/
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[1];
	goto CON22737;
CON22849:
	local[15]= local[4];
	local[16]= fqv[568];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22875;
	local[15]= NIL;
	storeglobal(fqv[384],local[15]);
	goto CON22737;
CON22875:
	local[15]= local[4];
	local[16]= fqv[569];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22886;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[30])(ctx,1,local+15,&ftab[30],fqv[567]); /*read-from-string*/
	local[15]= w;
	w = loadglobal(fqv[431]);
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	storeglobal(fqv[431],local[15]);
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[1];
	goto CON22737;
CON22886:
	local[15]= local[4];
	local[16]= fqv[570];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22918;
	local[15]= local[0];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	ctx->vsp=local+16;
	w=(*ftab[30])(ctx,1,local+15,&ftab[30],fqv[567]); /*read-from-string*/
	local[15]= w;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	if (w!=NIL) goto IF22943;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(*ftab[31])(ctx,1,local+16,&ftab[31],fqv[571]); /*make-package*/
	local[16]= w;
	goto IF22944;
IF22943:
	local[16]= NIL;
IF22944:
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	if (w==NIL) goto IF22960;
	local[16]= local[15];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	local[16]= w;
	storeglobal(fqv[404],w);
	goto IF22961;
IF22960:
	local[16]= fqv[572];
	ctx->vsp=local+17;
	w=(pointer)SIGERROR(ctx,1,local+16); /*error*/
	local[16]= w;
IF22961:
	w = local[16];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)ADD1(ctx,1,local+15); /*1+*/
	local[1] = w;
	local[15]= local[1];
	goto CON22737;
CON22918:
	local[15]= local[4];
	local[16]= fqv[573];
	ctx->vsp=local+17;
	w=(pointer)EQUAL(ctx,2,local+15); /*equal*/
	if (w==NIL) goto CON22987;
	local[15]= T;
	storeglobal(fqv[385],local[15]);
	goto CON22737;
CON22987:
	local[15]= local[4];
	local[16]= fqv[574];
	ctx->vsp=local+17;
	w=(*ftab[32])(ctx,2,local+15,&ftab[32],fqv[575]); /*string-equal*/
	if (w==NIL) goto CON22998;
	local[15]= NIL;
	storeglobal(fqv[385],local[15]);
	goto CON22737;
CON22998:
	local[15]= loadglobal(fqv[5]);
	local[16]= fqv[529];
	local[17]= local[3];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	local[15]= w;
	goto CON22737;
CON23010:
	local[15]= NIL;
CON22737:
	w = local[15];
CAT22702:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL22693;
WHX22694:
	local[9]= NIL;
BLK22695:
	goto CON22666;
CON22689:
	local[9]= NIL;
CON22666:
	local[9]= makeint((eusinteger_t)0L);
	ctx->vsp=local+10;
	w=(*ftab[28])(ctx,1,local+9,&ftab[28],fqv[554]); /*exit*/
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK22609:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___comp(ctx,n,argv,env)
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
	local[0]= fqv[576];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF23031;
	local[0]= fqv[577];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[404],w);
	goto IF23032;
IF23031:
	local[0]= fqv[578];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF23032:
	local[0]= fqv[579];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[580];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[581],module,F6924compiled_code_p,fqv[582]);
	local[0]= fqv[388];
	local[1]= fqv[583];
	local[2]= fqv[584];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[494];
	local[1]= fqv[583];
	local[2]= fqv[585];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[350];
	local[1]= fqv[583];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[342];
	local[1]= fqv[583];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[315];
	local[1]= fqv[583];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[182];
	local[1]= fqv[583];
	local[2]= makeint((eusinteger_t)1L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[318];
	local[1]= fqv[583];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[384];
	local[1]= fqv[583];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[385];
	local[1]= fqv[583];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[511];
	local[1]= fqv[583];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[427];
	local[1]= fqv[583];
	local[2]= fqv[501];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23149;
	local[2]= fqv[586];
	goto CON23147;
CON23149:
	local[2]= fqv[503];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23158;
	local[2]= fqv[587];
	goto CON23147;
CON23158:
	local[2]= fqv[474];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23167;
	local[2]= fqv[588];
	goto CON23147;
CON23167:
	local[2]= fqv[460];
	local[3]= loadglobal(fqv[431]);
	ctx->vsp=local+4;
	w=(*ftab[11])(ctx,2,local+2,&ftab[11],fqv[265]); /*member*/
	if (w==NIL) goto CON23176;
	local[2]= fqv[589];
	goto CON23147;
CON23176:
	local[2]= fqv[590];
	goto CON23147;
CON23185:
	local[2]= NIL;
CON23147:
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[5];
	local[1]= fqv[591];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF23192;
	local[0]= fqv[5];
	local[1]= fqv[591];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF23215;
	local[0]= fqv[5];
	local[1]= fqv[583];
	local[2]= NIL;
	local[3]= fqv[592];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF23216;
IF23215:
	local[0]= NIL;
IF23216:
	local[0]= fqv[5];
	goto IF23193;
IF23192:
	local[0]= NIL;
IF23193:
	local[0]= fqv[23];
	local[1]= fqv[591];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF23235;
	local[0]= fqv[23];
	local[1]= fqv[591];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[23];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF23258;
	local[0]= fqv[23];
	local[1]= fqv[583];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF23259;
IF23258:
	local[0]= NIL;
IF23259:
	local[0]= fqv[23];
	goto IF23236;
IF23235:
	local[0]= NIL;
IF23236:
	local[0]= fqv[415];
	local[1]= fqv[591];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF23278;
	local[0]= fqv[415];
	local[1]= fqv[591];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[415];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF23301;
	local[0]= fqv[415];
	local[1]= fqv[583];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF23302;
IF23301:
	local[0]= NIL;
IF23302:
	local[0]= fqv[415];
	goto IF23279;
IF23278:
	local[0]= NIL;
IF23279:
	ctx->vsp=local+0;
	compfun(ctx,fqv[593],module,F6941ovafp,fqv[594]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[595],module,F6943class_symbolp,fqv[596]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[597],module,F6945quoted_symbolp,fqv[598]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[599],module,F6947proclaimed_special_p,fqv[600]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[601],module,F6949proclaimed_global_p,fqv[602]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[603],module,F6951object_variable_names,fqv[604]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[605],module,F6953object_variable_type,fqv[606]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[607],module,F6955coerce_type,fqv[608]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[609],module,F6957check_arg,fqv[610]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[611],module,F6959def_function_type,fqv[612]);
	local[0]= fqv[9];
	local[1]= fqv[613];
	ctx->vsp=local+2;
	w=(pointer)F6959def_function_type(ctx,2,local+0); /*def-function-type*/
	local[0]= fqv[11];
	local[1]= fqv[614];
	ctx->vsp=local+2;
	w=(pointer)F6959def_function_type(ctx,2,local+0); /*def-function-type*/
	local[0]= loadglobal(fqv[177]);
	local[1]= fqv[615];
	ctx->vsp=local+2;
	w=(pointer)F6959def_function_type(ctx,2,local+0); /*def-function-type*/
	local[0]= fqv[56];
	local[1]= fqv[583];
	local[2]= fqv[56];
	local[3]= fqv[616];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[617];
	local[6]= fqv[618];
	local[7]= fqv[619];
	local[8]= NIL;
	local[9]= fqv[620];
	local[10]= NIL;
	local[11]= fqv[621];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[622];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[623]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7668identifier_type,fqv[97],fqv[56],fqv[624]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7698identifier_offset,fqv[625],fqv[56],fqv[626]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7726identifier_binding,fqv[63],fqv[56],fqv[627]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7754identifier_init,fqv[57],fqv[56],fqv[628]);
	local[0]= fqv[525];
	local[1]= fqv[583];
	local[2]= fqv[525];
	local[3]= fqv[616];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[617];
	local[6]= fqv[629];
	local[7]= fqv[619];
	local[8]= NIL;
	local[9]= fqv[620];
	local[10]= NIL;
	local[11]= fqv[621];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[622];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[623]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7815identifier_table_find,fqv[64],fqv[525],fqv[630]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7851identifier_table_get,fqv[55],fqv[525],fqv[631]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7929identifier_table_enter,fqv[17],fqv[525],fqv[632]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7973identifier_table_enter_special,fqv[58],fqv[525],fqv[633]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M7994identifier_table_create_frame,fqv[77],fqv[525],fqv[634]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8017identifier_table_pop_frame,fqv[83],fqv[525],fqv[635]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8046identifier_table_clear_frame,fqv[636],fqv[525],fqv[637]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8064identifier_table_level,fqv[78],fqv[525],fqv[638]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8092identifier_table_frame,fqv[522],fqv[525],fqv[639]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8118identifier_table_init_frames,fqv[418],fqv[525],fqv[640]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8189identifier_table_init,fqv[57],fqv[525],fqv[641]);
	local[0]= fqv[76];
	local[1]= fqv[583];
	local[2]= fqv[76];
	local[3]= fqv[616];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[617];
	local[6]= fqv[642];
	local[7]= fqv[619];
	local[8]= NIL;
	local[9]= fqv[620];
	local[10]= NIL;
	local[11]= fqv[621];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[622];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[623]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8246stack_frame_offset,fqv[625],fqv[76],fqv[643]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8281stack_frame_special,fqv[69],fqv[76],fqv[644]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8311stack_frame_local,fqv[71],fqv[76],fqv[645]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8341stack_frame_init,fqv[57],fqv[76],fqv[646]);
	local[0]= fqv[647];
	local[1]= fqv[583];
	local[2]= fqv[647];
	local[3]= fqv[616];
	local[4]= loadglobal(fqv[355]);
	local[5]= fqv[617];
	local[6]= fqv[648];
	local[7]= fqv[619];
	local[8]= NIL;
	local[9]= fqv[620];
	local[10]= NIL;
	local[11]= fqv[621];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[622];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[33])(ctx,13,local+2,&ftab[33],fqv[623]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8400compiler_genlabel,fqv[254],fqv[647],fqv[649]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8433compiler_gencname_tail,fqv[650],fqv[647],fqv[651]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8454compiler_progn,fqv[233],fqv[647],fqv[652]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8541compiler_eval,fqv[22],fqv[647],fqv[653]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M8936compiler_get_function,fqv[38],fqv[647],fqv[654]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9043compiler_call_closure,fqv[46],fqv[647],fqv[655]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9186compiler_variable,fqv[62],fqv[647],fqv[656]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9311compiler_var_binding,fqv[272],fqv[647],fqv[657]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9344compiler_special_variable_p,fqv[281],fqv[647],fqv[658]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9403compiler_enter_variable,fqv[68],fqv[647],fqv[659]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9530compiler_bind,fqv[278],fqv[647],fqv[660]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9726compiler_create_frame,fqv[77],fqv[647],fqv[661]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9792compiler_delete_frame,fqv[280],fqv[647],fqv[662]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M9919compiler_load_ovaf,fqv[35],fqv[647],fqv[663]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10032compiler_load_var,fqv[32],fqv[647],fqv[664]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10212compiler_store_ovaf,fqv[100],fqv[647],fqv[665]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10295compiler_store_var,fqv[274],fqv[647],fqv[666]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M10451compiler_funcall,fqv[40],fqv[647],fqv[667]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11400compiler_vector_op,fqv[161],fqv[647],fqv[668]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11580compiler_slot,fqv[166],fqv[647],fqv[669]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11708compiler_setslot,fqv[169],fqv[647],fqv[670]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M11892compiler_arithmetic,fqv[163],fqv[647],fqv[671]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M12349compiler_special_form,fqv[42],fqv[647],fqv[672]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13027compiler_conditional_jump,fqv[248],fqv[647],fqv[673]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13062compiler_evcon,fqv[252],fqv[647],fqv[674]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13688compiler_if,fqv[202],fqv[647],fqv[675]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M13793compiler_setq,fqv[200],fqv[647],fqv[676]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14007compiler_let_,fqv[206],fqv[647],fqv[677]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14288compiler_let,fqv[204],fqv[647],fqv[678]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M14787compiler_cond,fqv[208],fqv[647],fqv[679]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15004compiler_while,fqv[210],fqv[647],fqv[680]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15127compiler_and,fqv[212],fqv[647],fqv[681]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15247compiler_or,fqv[214],fqv[647],fqv[682]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15367compiler_catch,fqv[220],fqv[647],fqv[683]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15479compiler_throw,fqv[222],fqv[647],fqv[684]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15515compiler_unwind_protect,fqv[231],fqv[647],fqv[685]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15686compiler_enter_block,fqv[286],fqv[647],fqv[686]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15756compiler_leave_block,fqv[287],fqv[647],fqv[687]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15780compiler_block,fqv[216],fqv[647],fqv[688]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15828compiler_return_from,fqv[218],fqv[647],fqv[689]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M15955compiler_tagbody,fqv[224],fqv[647],fqv[690]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16159compiler_go,fqv[226],fqv[647],fqv[691]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16258compiler_function,fqv[235],fqv[647],fqv[692]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16383compiler_flet,fqv[228],fqv[647],fqv[693]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16623compiler_change_flets,fqv[309],fqv[647],fqv[694]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M16645compiler_declare,fqv[277],fqv[647],fqv[695]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M17297compiler_lambda,fqv[344],fqv[647],fqv[696]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M18787compiler_lambda_block,fqv[353],fqv[647],fqv[697]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M18978compiler_def_user_entry,fqv[378],fqv[647],fqv[698]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19050compiler_defun,fqv[367],fqv[647],fqv[699]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19216compiler_defmethod,fqv[370],fqv[647],fqv[700]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19615compiler_add_initcode,fqv[354],fqv[647],fqv[701]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19641compiler_add_closure,fqv[296],fqv[647],fqv[702]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19667compiler_closure_level,fqv[523],fqv[647],fqv[703]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19693compiler_compile_a_closure,fqv[365],fqv[647],fqv[704]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19784compiler_compile_closures,fqv[364],fqv[647],fqv[705]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M19900compiler_toplevel_eval,fqv[379],fqv[647],fqv[706]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20047compiler_toplevel,fqv[376],fqv[647],fqv[707]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20391compiler_toplevel_execution,fqv[420],fqv[647],fqv[708]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M20553compiler_compile_file,fqv[529],fqv[647],fqv[709]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21907compiler_specials,fqv[710],fqv[647],fqv[711]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21929compiler_copy_compiler,fqv[295],fqv[647],fqv[712]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M21996compiler_init,fqv[57],fqv[647],fqv[713]);
	local[0]= loadglobal(fqv[647]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	storeglobal(fqv[5],w);
	local[0]= loadglobal(fqv[5]);
	local[1]= fqv[57];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[533],module,F7014dump_function,fqv[714]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[715],module,F7016comfile,fqv[716]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[545],module,F7018compile_file,fqv[717]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[374],module,F7020compile,fqv[718]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[719],module,F7022compile_file_if_src_newer,fqv[720]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[721],module,F7024comp_file_toplevel,fqv[722]);
	local[0]= fqv[723];
	local[1]= fqv[724];
	ctx->vsp=local+2;
	w=(*ftab[34])(ctx,2,local+0,&ftab[34],fqv[725]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<35; i++) ftab[i]=fcallx;
}
