/* ./packsym.c :  entry=packsym */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "packsym.h"
#pragma init (register_packsym)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___packsym();
extern pointer build_quote_vector();
static int register_packsym()
  { add_module_initializer("___packsym", ___packsym);}

static pointer F46069metaclass_name();
static pointer F46073symbol_plist();
static pointer F46076remprop();
static pointer F46079symbol_package();
static pointer F46082symbol_name();
static pointer F46085make_symbol();
static pointer F46088documentation();
static pointer F46092gentemp();
static pointer F46097package_name();
static pointer F46100package_nicknames();
static pointer F46103package_use_list();
static pointer F46106package_used_by_list();
static pointer F46109packagep();
static pointer F46112use_package();
static pointer F46115unuse_package();
static pointer F46118make_package();
static pointer F46122rename_package();
static pointer F46125shadow();
static pointer F46128import();
static pointer F46131symbol_string();
static pointer F46134unintern();
static pointer F46136package_stats();

/*metaclass-name*/
static pointer F46069metaclass_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = *(ovafptr(argv[0],fqv[0]));
	local[0]= w;
BLK46178:
	ctx->vsp=local; return(local[0]);}

/*:home-package*/
static pointer M46208symbol_home_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK46209:
	ctx->vsp=local; return(local[0]);}

/*:pname*/
static pointer M46224symbol_pname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK46225:
	ctx->vsp=local; return(local[0]);}

/*:func*/
static pointer M46240symbol_func(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK46241:
	ctx->vsp=local; return(local[0]);}

/*:value*/
static pointer M46256symbol_value(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF46271;
	local[0]= makeint((eusinteger_t)11L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto IF46272;
IF46271:
	local[0]= NIL;
IF46272:
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK46257:
	ctx->vsp=local; return(local[0]);}

/*:constant*/
static pointer M46289symbol_constant(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46293;}
	local[0]= NIL;
ENT46293:
ENT46292:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF46312;
	goto IF46313;
IF46312:
	local[-1]= NIL;
IF46313:
	if (local[0]==NIL) goto IF46327;
	local[-1]= argv[0];
	local[0]= local[0];
	local[1]= fqv[1];
	ctx->vsp=local+2;
	w=(pointer)PUTPROP(ctx,3,local+-1); /*putprop*/
	local[-1]= w;
	goto IF46328;
IF46327:
	local[-1]= NIL;
IF46328:
	argv[0]->c.obj.iv[2] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[0];
	local[-2]= w;
BLK46290:
	ctx->vsp=local; return(local[0]);}

/*:special*/
static pointer M46352symbol_special(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46356;}
	local[0]= NIL;
ENT46356:
ENT46355:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF46374;
	local[1]= makeint((eusinteger_t)11L);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF46375;
IF46374:
	local[1]= NIL;
IF46375:
	if (local[0]==NIL) goto IF46384;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF46385;
IF46384:
	local[1]= NIL;
IF46385:
	ctx->vsp=local+1;
	w=(pointer)NEXT_SPECIAL_INDEX(ctx,0,local+1); /*system::next-special-index*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SETSPECIAL(ctx,2,local+1); /*set*/
	w = argv[0];
	local[0]= w;
BLK46353:
	ctx->vsp=local; return(local[0]);}

/*:global*/
static pointer M46413symbol_global(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46417;}
	local[0]= NIL;
ENT46417:
ENT46416:
	if (n>4) maerror();
	argv[0]->c.obj.iv[2] = makeint((eusinteger_t)2L);
	argv[0]->c.obj.iv[1] = argv[2];
	if (local[0]==NIL) goto IF46448;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF46449;
IF46448:
	local[1]= NIL;
IF46449:
	w = argv[2];
	local[0]= w;
BLK46414:
	ctx->vsp=local; return(local[0]);}

/*:vtype*/
static pointer M46464symbol_vtype(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT46468;}
	local[0]= NIL;
ENT46468:
ENT46467:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF46484;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF46485;
IF46484:
	local[1]= NIL;
IF46485:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK46465:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M46500symbol_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT46504;}
	local[0]= makeint((eusinteger_t)1L);
ENT46504:
ENT46503:
	if (n>4) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	w = argv[0];
	local[0]= w;
BLK46501:
	ctx->vsp=local; return(local[0]);}

/*symbol-plist*/
static pointer F46073symbol_plist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK46538:
	ctx->vsp=local; return(local[0]);}

/*remprop*/
static pointer F46076remprop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[3];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK46555:
	ctx->vsp=local; return(local[0]);}

/*symbol-package*/
static pointer F46079symbol_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK46575:
	ctx->vsp=local; return(local[0]);}

/*symbol-name*/
static pointer F46082symbol_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF46608;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF46609;
IF46608:
	local[0]= fqv[5];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF46609:
	w = local[0];
	local[0]= w;
BLK46592:
	ctx->vsp=local; return(local[0]);}

/*make-symbol*/
static pointer F46085make_symbol(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT46623;}
	local[0]= loadglobal(fqv[6]);
ENT46623:
ENT46622:
	if (n>2) maerror();
	w = argv[0];
	if (isstring(w)) goto IF46639;
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF46640;
IF46639:
	local[1]= NIL;
IF46640:
	local[1]= loadglobal(fqv[8]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= argv[0];
	w = local[1];
	w->c.obj.iv[4] = local[2];
	local[2]= makeint((eusinteger_t)1L);
	w = local[1];
	w->c.obj.iv[2] = local[2];
	local[2]= local[0];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[5] = local[3];
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)MAKUNBOUND(ctx,1,local+2); /*makunbound*/
	w = local[1];
	local[0]= w;
BLK46620:
	ctx->vsp=local; return(local[0]);}

/*documentation*/
static pointer F46088documentation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT46691;}
	local[0]= NIL;
ENT46691:
ENT46690:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= local[1];
	w = fqv[9];
	if (memq(local[2],w)==NIL) goto IF46718;
	local[2]= argv[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46719;
IF46718:
	local[2]= local[1];
	w = fqv[11];
	if (memq(local[2],w)==NIL) goto IF46734;
	local[2]= argv[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46735;
IF46734:
	local[2]= local[1];
	w = fqv[12];
	if (memq(local[2],w)==NIL) goto IF46750;
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46751;
IF46750:
	local[2]= local[1];
	w = fqv[14];
	if (memq(local[2],w)==NIL) goto IF46766;
	local[2]= argv[0];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	goto IF46767;
IF46766:
	if (T==NIL) goto IF46782;
	local[2]= argv[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46787;
CON46789:
	local[2]= argv[0];
	local[3]= fqv[15];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46787;
CON46797:
	local[2]= argv[0];
	local[3]= fqv[13];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46787;
CON46805:
	local[2]= argv[0];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	if (w!=NIL) goto CON46787;
CON46813:
	local[2]= NIL;
CON46787:
	goto IF46783;
IF46782:
	local[2]= NIL;
IF46783:
IF46767:
IF46751:
IF46735:
IF46719:
	w = local[2];
	local[0]= w;
BLK46688:
	ctx->vsp=local; return(local[0]);}

/*gentemp*/
static pointer F46092gentemp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT46831;}
	local[0]= fqv[16];
ENT46831:
	if (n>=2) { local[1]=(argv[1]); goto ENT46830;}
	local[1]= loadglobal(fqv[6]);
ENT46830:
ENT46829:
	if (n>2) maerror();
	local[2]= NIL;
WHL46857:
	local[3]= loadglobal(fqv[17]);
	local[4]= local[0];
	local[5]= loadglobal(fqv[18]);
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,1,local+5,&ftab[0],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[2] = w;
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)FINDSYMBOL(ctx,2,local+3); /*find-symbol*/
	if (w==NIL) goto WHX46858;
	local[3]= loadglobal(fqv[18]);
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	storeglobal(fqv[18],w);
	goto WHL46857;
WHX46858:
	local[3]= NIL;
BLK46859:
	local[3]= local[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)INTERN(ctx,2,local+3); /*intern*/
	local[0]= w;
BLK46827:
	ctx->vsp=local; return(local[0]);}

/*:use-list*/
static pointer M46920package_use_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK46921:
	ctx->vsp=local; return(local[0]);}

/*:used-by-list*/
static pointer M46936package_used_by_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK46937:
	ctx->vsp=local; return(local[0]);}

/*:used-by*/
static pointer M46952package_used_by(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[19]); /*adjoin*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK46953:
	ctx->vsp=local; return(local[0]);}

/*:use*/
static pointer M46979package_use(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF46994;
WHL47005:
	if (argv[2]==NIL) goto WHX47006;
	local[0]= argv[0];
	local[1]= fqv[20];
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	w=argv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[2] = (w)->c.cons.cdr;
	goto WHL47005;
WHX47006:
	local[0]= NIL;
BLK47007:
	local[0]= argv[0]->c.obj.iv[2];
	goto IF46995;
IF46994:
	local[0]= NIL;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	argv[2] = w;
	local[1]= argv[2];
	if (argv[0]==local[1]) goto IF47056;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F46109packagep(ctx,1,local+1); /*packagep*/
	if (w==NIL) goto IF47056;
	local[1]= NIL;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)FINDPACKAGE(ctx,1,local+2); /*find-package*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= *(ovafptr(local[2],fqv[21]));
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL47102:
	local[6]= local[3];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX47103;
	local[6]= local[4];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[1] = w;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[3] = w;
	w = local[1];
	if (!issymbol(w)) goto IF47132;
	local[6]= argv[0];
	local[7]= fqv[22];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47153;
	local[6]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[6]->c.vec.v[i]);}
	local[6]= w;
	if (local[1]==local[6]) goto IF47153;
	local[6]= fqv[23];
	local[7]= local[1];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,3,local+6); /*error*/
	local[6]= w;
	goto IF47154;
IF47153:
	local[6]= NIL;
IF47154:
	goto IF47133;
IF47132:
	local[6]= NIL;
IF47133:
	goto WHL47102;
WHX47103:
	local[6]= NIL;
BLK47104:
	w = NIL;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[19]); /*adjoin*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[2];
	local[2]= fqv[24];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF47057;
IF47056:
	local[1]= NIL;
IF47057:
	w = local[1];
	local[0]= w;
IF46995:
	w = local[0];
	local[0]= w;
BLK46980:
	ctx->vsp=local; return(local[0]);}

/*:unuse*/
static pointer M47194package_unuse(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	argv[2] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)F46109packagep(ctx,1,local+0); /*packagep*/
	if (w==NIL) goto IF47219;
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[25]); /*delete*/
	argv[0]->c.obj.iv[2] = w;
	local[0]= argv[2];
	local[1]= fqv[26];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF47220;
IF47219:
	local[0]= NIL;
IF47220:
	w = local[0];
	local[0]= w;
BLK47195:
	ctx->vsp=local; return(local[0]);}

/*:unused*/
static pointer M47248package_unused(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[25]); /*delete*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK47249:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M47274package_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK47275:
	ctx->vsp=local; return(local[0]);}

/*:rename*/
static pointer M47294package_rename(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[17]); /*string*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK47295:
	ctx->vsp=local; return(local[0]);}

/*:nicknames*/
static pointer M47321package_nicknames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT47325;}
	local[0]= NIL;
ENT47325:
ENT47324:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF47341;
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= (pointer)get_sym_func(fqv[17]);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)MAPCAR(ctx,2,local+2); /*mapcar*/
	local[2]= w;
	local[3]= fqv[27];
	local[4]= (pointer)get_sym_func(fqv[28]);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,4,local+1,&ftab[3],fqv[29]); /*union*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0]->c.obj.iv[1];
	goto IF47342;
IF47341:
	local[1]= NIL;
IF47342:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK47322:
	ctx->vsp=local; return(local[0]);}

/*:hash*/
static pointer M47369package_hash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[17]); /*string*/
	argv[2] = w;
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SXHASH(ctx,1,local+0); /*sxhash*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
BLK47370:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M47402package_enter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47417;
	w = NIL;
	ctx->vsp=local+0;
	local[0]=w;
	goto BLK47403;
	goto IF47418;
IF47417:
	local[0]= NIL;
IF47418:
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(pointer)SXHASH(ctx,1,local+0); /*sxhash*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF47451;
	local[2]= fqv[30];
	local[3]= argv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,3,local+2); /*error*/
	local[2]= w;
	goto IF47452;
IF47451:
	local[2]= NIL;
IF47452:
WHL47463:
	local[2]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	if (!issymbol(w)) goto WHX47464;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)GREQP(ctx,2,local+2); /*>=*/
	if (w==NIL) goto IF47474;
	local[0] = makeint((eusinteger_t)0L);
	local[2]= local[0];
	goto IF47475;
IF47474:
	local[2]= NIL;
IF47475:
	goto WHL47463;
WHX47464:
	local[2]= NIL;
BLK47465:
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= local[0];
	w = argv[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	argv[0]->c.obj.iv[6] = w;
	w = argv[2];
	local[0]= w;
BLK47403:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M47514package_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47535;
	local[0]= fqv[31];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF47536;
IF47535:
	local[0]= NIL;
IF47536:
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SXHASH(ctx,1,local+1); /*sxhash*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	local[1]= w;
	local[2]= NIL;
WHL47571:
	if (T==NIL) goto WHX47572;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MOD(ctx,2,local+4); /*mod*/
	{ register eusinteger_t i=intval(w);
	  w=(local[3]->c.vec.v[i]);}
	local[2] = w;
	local[3]= local[2];
	if (makeint((eusinteger_t)0L)!=local[3]) goto CON47594;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47515;
	goto CON47592;
CON47594:
	local[3]= local[2];
	local[3]= ((makeint((eusinteger_t)1L))==(local[3])?T:NIL);
	if (local[3]!=NIL) goto CON47592;
CON47602:
	local[3]= local[2]->c.obj.iv[4];
	local[4]= argv[2]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto CON47609;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MOD(ctx,2,local+3); /*mod*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47515;
	goto CON47592;
CON47609:
	local[3]= NIL;
CON47592:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF47627;
	local[3]= fqv[32];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto IF47628;
IF47627:
	local[3]= NIL;
IF47628:
	goto WHL47571;
WHX47572:
	local[3]= NIL;
BLK47573:
	w = NIL;
	local[0]= w;
BLK47515:
	ctx->vsp=local; return(local[0]);}

/*:shadow*/
static pointer M47653package_shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w!=NIL) goto IF47669;
	local[0]= argv[0];
	local[1]= fqv[33];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[17]); /*string*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F46085make_symbol(ctx,2,local+2); /*make-symbol*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF47670;
IF47669:
	local[0]= NIL;
IF47670:
	w = local[0];
	local[0]= w;
BLK47654:
	ctx->vsp=local; return(local[0]);}

/*:import*/
static pointer M47695package_import(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[22];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF47726;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[5];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[2]->c.vec.v[i]);}
	if (w==local[1]) goto IF47726;
	local[1]= fqv[34];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF47727;
IF47726:
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
IF47727:
	w = local[1];
	local[0]= w;
BLK47696:
	ctx->vsp=local; return(local[0]);}

/*:unintern*/
static pointer M47752package_unintern(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= *(ovafptr(argv[2],fqv[35]));
	if (argv[0]!=local[1]) goto IF47777;
	local[1]= NIL;
	local[2]= local[1];
	*(ovafptr(argv[2],fqv[35])) = local[2];
	goto IF47778;
IF47777:
	local[1]= NIL;
IF47778:
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47803;
	local[1]= argv[0]->c.obj.iv[5];
	local[2]= local[0];
	w = makeint((eusinteger_t)1L);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[0]->c.obj.iv[6] = w;
	local[1]= argv[0]->c.obj.iv[6];
	goto IF47804;
IF47803:
	local[1]= NIL;
IF47804:
	local[1]= argv[0];
	local[2]= fqv[36];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	if (local[0]==NIL) goto IF47840;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= local[0];
	w = makeint((eusinteger_t)1L);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	goto IF47841;
IF47840:
	local[1]= NIL;
IF47841:
	w = local[1];
	local[0]= w;
BLK47753:
	ctx->vsp=local; return(local[0]);}

/*:find-external*/
static pointer M47865package_find_external(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w = argv[2];
	if (issymbol(w)) goto IF47886;
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
	goto IF47887;
IF47886:
	local[0]= NIL;
IF47887:
	local[0]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)SXHASH(ctx,1,local+1); /*sxhash*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)MOD(ctx,2,local+1); /*mod*/
	local[1]= w;
	local[2]= NIL;
WHL47922:
	if (T==NIL) goto WHX47923;
	local[3]= argv[0]->c.obj.iv[3];
	{ register eusinteger_t i=intval(local[1]);
	  w=(local[3]->c.vec.v[i]);}
	local[2] = w;
	local[3]= local[2];
	if (makeint((eusinteger_t)0L)!=local[3]) goto CON47942;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47866;
	goto CON47940;
CON47942:
	local[3]= local[2];
	local[3]= ((makeint((eusinteger_t)1L))==(local[3])?T:NIL);
	if (local[3]!=NIL) goto CON47940;
CON47950:
	local[3]= local[2]->c.obj.iv[4];
	local[4]= argv[2]->c.obj.iv[4];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto CON47957;
	w = local[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK47866;
	goto CON47940;
CON47957:
	local[3]= NIL;
CON47940:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF47973;
	local[1] = makeint((eusinteger_t)0L);
	local[3]= local[1];
	goto IF47974;
IF47973:
	local[3]= NIL;
IF47974:
	goto WHL47922;
WHX47923:
	local[3]= NIL;
BLK47924:
	w = NIL;
	local[0]= w;
BLK47866:
	ctx->vsp=local; return(local[0]);}

/*:unexport*/
static pointer M47996package_unexport(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[36];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF48027;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= local[0];
	w = makeint((eusinteger_t)0L);
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= w;
	goto IF48028;
IF48027:
	local[1]= NIL;
IF48028:
	w = local[1];
	local[0]= w;
BLK47997:
	ctx->vsp=local; return(local[0]);}

/*package-name*/
static pointer F46097package_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	argv[0] = w;
	local[0]= argv[0];
	local[1]= fqv[38];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK48042:
	ctx->vsp=local; return(local[0]);}

/*package-nicknames*/
static pointer F46100package_nicknames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[39];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK48068:
	ctx->vsp=local; return(local[0]);}

/*package-use-list*/
static pointer F46103package_use_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[40];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK48087:
	ctx->vsp=local; return(local[0]);}

/*package-used-by-list*/
static pointer F46106package_used_by_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK48106:
	ctx->vsp=local; return(local[0]);}

/*packagep*/
static pointer F46109packagep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)GETCLASS(ctx,1,local+0); /*class*/
	local[0]= w;
	w = ((loadglobal(fqv[42]))==(local[0])?T:NIL);
	local[0]= w;
BLK48125:
	ctx->vsp=local; return(local[0]);}

/*use-package*/
static pointer F46112use_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48149;}
	local[0]= loadglobal(fqv[6]);
ENT48149:
ENT48148:
	if (n>2) maerror();
	local[1]= local[0];
	local[2]= fqv[20];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = T;
	local[0]= w;
BLK48146:
	ctx->vsp=local; return(local[0]);}

/*unuse-package*/
static pointer F46115unuse_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48177;}
	local[0]= loadglobal(fqv[6]);
ENT48177:
ENT48176:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	local[1]= w;
	local[2]= fqv[43];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK48174:
	ctx->vsp=local; return(local[0]);}

/*make-package*/
static pointer F46118make_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[44], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY48212;
	local[0] = NIL;
KEY48212:
	if (n & (1<<1)) goto KEY48217;
	local[2]= fqv[45];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[1] = w;
KEY48217:
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAKEPACKAGE(ctx,3,local+2); /*system::makepackage*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[20];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK48202:
	ctx->vsp=local; return(local[0]);}

/*in-package*/
static pointer F48255(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[46];
	local[1]= fqv[47];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[48];
	local[3]= fqv[6];
	local[4]= fqv[47];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[49];
	local[4]= fqv[50];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK48256:
	ctx->vsp=local; return(local[0]);}

/*rename-package*/
static pointer F46122rename_package(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT48317;}
	local[0]= NIL;
ENT48317:
ENT48316:
	if (n>3) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)FINDPACKAGE(ctx,1,local+1); /*find-package*/
	argv[0] = w;
	local[1]= argv[0];
	local[2]= fqv[51];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (local[0]==NIL) goto IF48349;
	local[1]= argv[0];
	local[2]= fqv[39];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48350;
IF48349:
	local[1]= NIL;
IF48350:
	w = local[1];
	local[0]= w;
BLK48314:
	ctx->vsp=local; return(local[0]);}

/*shadow*/
static pointer F46125shadow(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48366;}
	local[0]= loadglobal(fqv[6]);
ENT48366:
ENT48365:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48381;
	local[1]= local[0];
	local[2]= fqv[52];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48382;
IF48381:
WHL48393:
	if (argv[0]==NIL) goto WHX48394;
	local[1]= local[0];
	local[2]= fqv[52];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL48393;
WHX48394:
	local[1]= NIL;
BLK48395:
IF48382:
	w = local[1];
	local[0]= w;
BLK48363:
	ctx->vsp=local; return(local[0]);}

/*import*/
static pointer F46128import(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48427;}
	local[0]= loadglobal(fqv[6]);
ENT48427:
ENT48426:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48442;
	local[1]= local[0];
	local[2]= fqv[53];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48443;
IF48442:
WHL48454:
	if (argv[0]==NIL) goto WHX48455;
	local[1]= local[0];
	local[2]= fqv[53];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL48454;
WHX48455:
	local[1]= NIL;
BLK48456:
IF48443:
	w = T;
	local[0]= w;
BLK48424:
	ctx->vsp=local; return(local[0]);}

/*symbol-string*/
static pointer F46131symbol_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48497;
	local[0]= *(ovafptr(argv[0],fqv[54]));
	goto IF48498;
IF48497:
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF48498:
	w = local[0];
	local[0]= w;
BLK48487:
	ctx->vsp=local; return(local[0]);}

/*unintern*/
static pointer F46134unintern(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT48512;}
	local[0]= loadglobal(fqv[6]);
ENT48512:
ENT48511:
	if (n>2) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF48527;
	local[1]= local[0];
	local[2]= fqv[56];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF48528;
IF48527:
	local[1]= fqv[57];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
IF48528:
	w = local[1];
	local[0]= w;
BLK48509:
	ctx->vsp=local; return(local[0]);}

/*package-stats*/
static pointer F46136package_stats(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT48545;}
	local[0]= T;
ENT48545:
ENT48544:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)ALLPACKAGES(ctx,0,local+5); /*list-all-packages*/
	local[5]= w;
WHL48581:
	if (local[5]==NIL) goto WHX48582;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= (pointer)get_sym_func(fqv[58]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F46103package_use_list(ctx,1,local+7); /*package-use-list*/
	local[7]= w;
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[59]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[2] = w;
	local[6]= (pointer)get_sym_func(fqv[58]);
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)F46106package_used_by_list(ctx,1,local+7); /*package-used-by-list*/
	local[7]= w;
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,2,local+7,&ftab[4],fqv[59]); /*send-all*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[3] = w;
	local[6]= local[0];
	local[7]= fqv[60];
	local[8]= local[4];
	local[9]= fqv[39];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= local[4];
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF48676;
	local[9]= local[4];
	local[10]= fqv[39];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	goto IF48677;
IF48676:
	local[9]= fqv[61];
IF48677:
	local[10]= local[4]->c.obj.iv[4];
	if (local[2]==NIL) goto IF48704;
	local[11]= local[2];
	goto IF48705;
IF48704:
	local[11]= fqv[62];
IF48705:
	if (local[3]==NIL) goto IF48711;
	local[12]= local[3];
	goto IF48712;
IF48711:
	local[12]= fqv[63];
IF48712:
	ctx->vsp=local+13;
	w=(pointer)XFORMAT(ctx,7,local+6); /*format*/
	goto WHL48581;
WHX48582:
	local[6]= NIL;
BLK48583:
	w = NIL;
	local[0]= w;
BLK48542:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___packsym(ctx,n,argv,env)
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
	local[0]= fqv[64];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[65];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF48731;
	local[0]= fqv[66];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[6],w);
	goto IF48732;
IF48731:
	local[0]= fqv[67];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF48732:
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[69],module,F46069metaclass_name,fqv[70]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46208symbol_home_package,fqv[4],fqv[8],fqv[71]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46224symbol_pname,fqv[72],fqv[8],fqv[73]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46240symbol_func,fqv[74],fqv[8],fqv[75]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46256symbol_value,fqv[76],fqv[8],fqv[77]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46289symbol_constant,fqv[78],fqv[8],fqv[79]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46352symbol_special,fqv[80],fqv[8],fqv[81]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46413symbol_global,fqv[82],fqv[8],fqv[83]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46464symbol_vtype,fqv[84],fqv[8],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46500symbol_init,fqv[86],fqv[8],fqv[87]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[88],module,F46073symbol_plist,fqv[89]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[90],module,F46076remprop,fqv[91]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[92],module,F46079symbol_package,fqv[93]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[94],module,F46082symbol_name,fqv[95]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[96],module,F46085make_symbol,fqv[97]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[98],module,F46088documentation,fqv[99]);
	local[0]= makeint((eusinteger_t)0L);
	storeglobal(fqv[18],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[100],module,F46092gentemp,fqv[101]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46920package_use_list,fqv[40],fqv[42],fqv[102]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46936package_used_by_list,fqv[41],fqv[42],fqv[103]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46952package_used_by,fqv[24],fqv[42],fqv[104]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M46979package_use,fqv[20],fqv[42],fqv[105]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47194package_unuse,fqv[43],fqv[42],fqv[106]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47248package_unused,fqv[26],fqv[42],fqv[107]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47274package_name,fqv[38],fqv[42],fqv[108]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47294package_rename,fqv[51],fqv[42],fqv[109]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47321package_nicknames,fqv[39],fqv[42],fqv[110]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47369package_hash,fqv[111],fqv[42],fqv[112]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47402package_enter,fqv[33],fqv[42],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47514package_find,fqv[22],fqv[42],fqv[114]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47653package_shadow,fqv[52],fqv[42],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47695package_import,fqv[53],fqv[42],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47752package_unintern,fqv[56],fqv[42],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47865package_find_external,fqv[36],fqv[42],fqv[118]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M47996package_unexport,fqv[119],fqv[42],fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F46097package_name,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F46100package_nicknames,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F46103package_use_list,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F46106package_used_by_list,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F46109packagep,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[131],module,F46112use_package,fqv[132]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[133],module,F46115unuse_package,fqv[134]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[135],module,F46118make_package,fqv[136]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[137],module,F48255,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F46122rename_package,fqv[140]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[141],module,F46125shadow,fqv[142]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[143],module,F46128import,fqv[144]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[145],module,F46131symbol_string,fqv[146]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[147],module,F46134unintern,fqv[148]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[149],module,F46136package_stats,fqv[150]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<5; i++) ftab[i]=fcallx;
}
