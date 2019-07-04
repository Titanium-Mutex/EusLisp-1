/* ./common.c :  entry=common */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "common.h"
#pragma init (register_common)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___common();
extern pointer build_quote_vector();
static int register_common()
  { add_module_initializer("___common", ___common);}

static pointer F4260lisp_implementation_type();
static pointer F4262lisp_implementation_version();
static pointer F4266macroexpand();
static pointer F4295casebody();
static pointer F4298casehead();
static pointer F4301case1();
static pointer F4305classcasehead();
static pointer F4308classcase1();
static pointer F4311string();
static pointer F4315alias();
static pointer F4321caaar();
static pointer F4324caadr();
static pointer F4327cadar();
static pointer F4330cdaar();
static pointer F4333cdadr();
static pointer F4336cddar();
static pointer F4339cdddr();
static pointer F4345fourth();
static pointer F4348fifth();
static pointer F4351sixth();
static pointer F4354seventh();
static pointer F4357eighth();
static pointer F4360cddddr();
static pointer F4363cadddr();
static pointer F4366caaddr();
static pointer F4369cdaddr();
static pointer F4372caddddr();
static pointer F4375flatten();
static pointer F4378list_insert();
static pointer F4381list_delete();
static pointer F4384adjoin();
static pointer F4387union();
static pointer F4390intersection();
static pointer F4393set_difference();
static pointer F4396set_exclusive_or();
static pointer F4399rotate_list();
static pointer F4402last();
static pointer F4405copy_tree();
static pointer F4408copy_list();
static pointer F4411nreconc();
static pointer F4414rassoc();
static pointer F4417acons();
static pointer F4420member();
static pointer F4423assoc();
static pointer F4426subsetp();
static pointer F4429maplist();
static pointer F4432mapcon();
static pointer F4435find();
static pointer F4438find_if();
static pointer F4441find_if_not();
static pointer F4444position();
static pointer F4447position_if();
static pointer F4450position_if_not();
static pointer F4453count();
static pointer F4456count_if();
static pointer F4459count_if_not();
static pointer F4462member_if();
static pointer F4465member_if_not();
static pointer F4468collect_if();
static pointer F4471collect_instances();
static pointer F4474pairlis();
static pointer F4477transpose_list();
static pointer F4480make_list();
static pointer F4483make_sequence();
static pointer F4486fill();
static pointer F4489replace();
static pointer F4492remove();
static pointer F4495remove_if();
static pointer F4498remove_if_not();
static pointer F4501delete();
static pointer F4504delete_if();
static pointer F4507delete_if_not();
static pointer F4510substitute();
static pointer F4513substitute_if();
static pointer F4516substitute_if_not();
static pointer F4519nsubstitute();
static pointer F4522nsubstitute_if();
static pointer F4525nsubstitute_if_not();
static pointer F4528unique();
static pointer F4531remove_duplicates();
static pointer F4534extream();
static pointer F4543send_all();
static pointer F4546resend();
static pointer F4551make_instance();
static pointer F4555delete_method();
static pointer F4558make_class();
static pointer F4565readtablep();
static pointer F4568copy_readtable();
static pointer F4571set_syntax_from_char();
static pointer F4576keywordp();
static pointer F4579constantp();
static pointer F4582functionp();
static pointer F4585vector_class_p();
static pointer F4588compiled_function_p();
static pointer F4591input_stream_p();
static pointer F4594output_stream_p();
static pointer F4597io_stream_p();
static pointer F4600special_form_p();
static pointer F4603macro_function();
static pointer F4606zerop();
static pointer F4609plusp();
static pointer F4612minusp();
static pointer F4615oddp();
static pointer F4618evenp();
static pointer F4621logandc1();
static pointer F4624logandc2();
static pointer F4628every();
static pointer F4631some();
static pointer F4636reduce();
static pointer F4639merge_list();
static pointer F4642merge();
static pointer F4645expt();
static pointer F4648signum();
static pointer F4651rad2deg();
static pointer F4654deg2rad();
static pointer F4656setf_expand_1();
static pointer F4658setf_expand();

/*lisp-implementation-type*/
static pointer F4260lisp_implementation_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	w = fqv[0];
	local[0]= w;
BLK4802:
	ctx->vsp=local; return(local[0]);}

/*lisp-implementation-version*/
static pointer F4262lisp_implementation_version(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= NIL;
	local[1]= fqv[1];
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= loadglobal(fqv[2]);
	ctx->vsp=local+4;
	w=(pointer)F4339cdddr(ctx,1,local+3); /*cdddr*/
	local[3]= w;
	local[4]= loadglobal(fqv[3]);
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=loadglobal(fqv[2]);
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,7,local+0); /*format*/
	local[0]= w;
BLK4812:
	ctx->vsp=local; return(local[0]);}

/*macroexpand*/
static pointer F4266macroexpand(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)MACEXPAND2(ctx,1,local+0); /*macroexpand2*/
	local[0]= w;
WHL4876:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto WHX4877;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4603macro_function(ctx,1,local+1); /*macro-function*/
	if (w==NIL) goto WHX4877;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)MACEXPAND2(ctx,1,local+1); /*macroexpand2*/
	local[0] = w;
	goto WHL4876;
WHX4877:
	local[1]= NIL;
BLK4878:
	w = local[0];
	local[0]= w;
BLK4853:
	ctx->vsp=local; return(local[0]);}

/*prog1*/
static pointer F4910(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4913:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= fqv[6];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK4911:
	ctx->vsp=local; return(local[0]);}

/*loop*/
static pointer F4973(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST4976:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[8];
	local[3]= fqv[9];
	local[4]= fqv[10];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= fqv[11];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK4974:
	ctx->vsp=local; return(local[0]);}

/*unless*/
static pointer F5032(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5035:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[12];
	local[2]= fqv[13];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5033:
	ctx->vsp=local; return(local[0]);}

/*until*/
static pointer F5065(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5068:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[14];
	local[2]= fqv[13];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= local[0];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK5066:
	ctx->vsp=local; return(local[0]);}

/*pop*/
static pointer F5099(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[15];
	local[1]= fqv[16];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	local[2]= fqv[17];
	local[3]= argv[0];
	local[4]= fqv[18];
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
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5100:
	ctx->vsp=local; return(local[0]);}

/*push*/
static pointer F5146(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[17];
	local[1]= argv[1];
	local[2]= fqv[19];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK5147:
	ctx->vsp=local; return(local[0]);}

/*pushnew*/
static pointer F5183(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[20], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY5197;
	local[0] = NIL;
KEY5197:
	if (n & (1<<1)) goto KEY5202;
	local[1] = NIL;
KEY5202:
	if (n & (1<<2)) goto KEY5207;
	local[2] = NIL;
KEY5207:
	local[3]= fqv[6];
	local[4]= fqv[21];
	local[5]= fqv[13];
	local[6]= fqv[22];
	local[7]= argv[0];
	local[8]= argv[1];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
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
	local[6]= fqv[17];
	local[7]= argv[1];
	local[8]= fqv[19];
	local[9]= argv[0];
	local[10]= argv[1];
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
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK5184:
	ctx->vsp=local; return(local[0]);}

/*inc*/
static pointer F5304(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5308;}
	local[0]= NIL;
ENT5308:
ENT5307:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5322;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5323;
IF5322:
	local[1]= fqv[27];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5323:
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5305:
	ctx->vsp=local; return(local[0]);}

/*dec*/
static pointer F5358(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5362;}
	local[0]= NIL;
ENT5362:
ENT5361:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5376;
	local[1]= fqv[29];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5377;
IF5376:
	local[1]= fqv[30];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5377:
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5359:
	ctx->vsp=local; return(local[0]);}

/*incf*/
static pointer F5412(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5416;}
	local[0]= NIL;
ENT5416:
ENT5415:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5430;
	local[1]= fqv[26];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5431;
IF5430:
	local[1]= fqv[27];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5431:
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5413:
	ctx->vsp=local; return(local[0]);}

/*decf*/
static pointer F5466(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5470;}
	local[0]= NIL;
ENT5470:
ENT5469:
	if (n>2) maerror();
	if (local[0]==NIL) goto IF5484;
	local[1]= fqv[29];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
	goto IF5485;
IF5484:
	local[1]= fqv[30];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[0] = w;
	local[1]= local[0];
IF5485:
	local[1]= fqv[17];
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[0]= w;
BLK5467:
	ctx->vsp=local; return(local[0]);}

/*defvar*/
static pointer F5520(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5525;}
	local[0]= NIL;
ENT5525:
	if (n>=3) { local[1]=(argv[2]); goto ENT5524;}
	local[1]= NIL;
ENT5524:
ENT5523:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5544;
	local[2]= makeint((eusinteger_t)20L);
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF5545;
IF5544:
	local[2]= NIL;
IF5545:
	local[2]= fqv[12];
	local[3]= fqv[31];
	local[4]= fqv[32];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[35];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[32];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	local[7]= fqv[36];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[21];
	local[6]= fqv[13];
	local[7]= fqv[37];
	local[8]= fqv[33];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[32];
	local[8]= fqv[33];
	local[9]= argv[0];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[38];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
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
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5521:
	ctx->vsp=local; return(local[0]);}

/*deflocal*/
static pointer F5687(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT5692;}
	local[0]= NIL;
ENT5692:
	if (n>=3) { local[1]=(argv[2]); goto ENT5691;}
	local[1]= NIL;
ENT5691:
ENT5690:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5711;
	local[2]= makeint((eusinteger_t)20L);
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF5712;
IF5711:
	local[2]= NIL;
IF5712:
	local[2]= fqv[6];
	local[3]= fqv[32];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[39];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
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
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5688:
	ctx->vsp=local; return(local[0]);}

/*defparameter*/
static pointer F5768(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5772;}
	local[0]= NIL;
ENT5772:
ENT5771:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5789;
	local[1]= makeint((eusinteger_t)20L);
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF5790;
IF5789:
	local[1]= NIL;
IF5790:
	local[1]= fqv[32];
	local[2]= fqv[33];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[38];
	local[4]= argv[1];
	local[5]= local[0];
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
BLK5769:
	ctx->vsp=local; return(local[0]);}

/*defconstant*/
static pointer F5830(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT5834;}
	local[0]= NIL;
ENT5834:
ENT5833:
	if (n>3) maerror();
	w = argv[0];
	if (issymbol(w)) goto IF5851;
	local[1]= makeint((eusinteger_t)20L);
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF5852;
IF5851:
	local[1]= NIL;
IF5852:
	local[1]= fqv[32];
	local[2]= fqv[33];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[40];
	local[4]= argv[1];
	local[5]= local[0];
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
BLK5831:
	ctx->vsp=local; return(local[0]);}

/*dotimes*/
static pointer F5892(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST5895:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[41];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= fqv[42];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= local[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[43];
	local[5]= fqv[44];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[14];
	local[6]= fqv[45];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= local[0];
	local[8]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[27];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
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
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPEND(ctx,2,local+7); /*append*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
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
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK5893:
	ctx->vsp=local; return(local[0]);}

/*dolist*/
static pointer F6046(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6049:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w = local[2];
	if (!iscons(w)) goto IF6080;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF6080;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF6081;
IF6080:
	local[2] = NIL;
	local[3]= local[2];
IF6081:
	local[3]= fqv[5];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[9];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	w=argv[0];
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
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[2];
	local[6]= fqv[14];
	local[7]= local[1];
	local[8]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	local[10]= fqv[47];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= local[0];
	local[10]= NIL;
	ctx->vsp=local+11;
	w=(pointer)APPEND(ctx,2,local+9); /*append*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK6047:
	ctx->vsp=local; return(local[0]);}

/*do-symbols*/
static pointer F6203(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6206:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[48];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF6234;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF6235;
IF6234:
	local[3]= fqv[49];
IF6235:
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,0,local+6); /*gensym*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GENSYM(ctx,0,local+7); /*gensym*/
	local[7]= w;
	local[8]= fqv[50];
	local[9]= local[2];
	local[10]= fqv[9];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[4];
	local[11]= fqv[51];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[5];
	local[12]= fqv[52];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[7];
	local[13]= local[4];
	w = fqv[53];
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= local[6];
	local[14]= fqv[54];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[14];
	local[11]= fqv[45];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[28];
	local[13]= local[2];
	local[14]= fqv[55];
	local[15]= local[7];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[56];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[12];
	local[15]= fqv[57];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	w = local[0];
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	local[0]= w;
BLK6204:
	ctx->vsp=local; return(local[0]);}

/*do-external-symbols*/
static pointer F6430(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6433:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[58];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto IF6461;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF6462;
IF6461:
	local[3]= fqv[49];
IF6462:
	ctx->vsp=local+4;
	w=(pointer)GENSYM(ctx,0,local+4); /*gensym*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,0,local+6); /*gensym*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)GENSYM(ctx,0,local+7); /*gensym*/
	local[7]= w;
	local[8]= fqv[50];
	local[9]= local[2];
	local[10]= fqv[9];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= local[4];
	local[11]= fqv[51];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[5];
	local[12]= fqv[59];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= local[7];
	local[13]= local[4];
	w = fqv[60];
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= local[6];
	local[14]= fqv[54];
	local[15]= local[7];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[14];
	local[11]= fqv[45];
	local[12]= local[5];
	local[13]= local[6];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= fqv[28];
	local[13]= local[2];
	local[14]= fqv[55];
	local[15]= local[7];
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[56];
	local[14]= local[5];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[12];
	local[15]= fqv[57];
	local[16]= local[2];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	local[15]= cons(ctx,local[15],w);
	w = local[0];
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	local[14]= cons(ctx,local[14],w);
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	local[0]= w;
BLK6431:
	ctx->vsp=local; return(local[0]);}

/*do-all-symbols*/
static pointer F6657(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST6660:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[61];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[62];
	local[3]= local[1];
	local[4]= fqv[63];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[64];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK6658:
	ctx->vsp=local; return(local[0]);}

/*psetq*/
static pointer F6734(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST6737:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
WHL6758:
	if (local[0]==NIL) goto WHX6759;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	w = local[2];
	ctx->vsp=local+5;
	local[2] = cons(ctx,local[4],w);
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,1,local+4); /*gensym*/
	local[4]= w;
	w = local[3];
	ctx->vsp=local+5;
	local[3] = cons(ctx,local[4],w);
	goto WHL6758;
WHX6759:
	local[4]= NIL;
BLK6760:
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[1] = w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[2] = w;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[3] = w;
	local[4]= fqv[50];
	local[5]= (pointer)get_sym_func(fqv[66]);
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,3,local+5); /*mapcar*/
	local[5]= w;
	local[6]= fqv[28];
	local[7]= (pointer)get_sym_func(fqv[66]);
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)MAPCAN(ctx,3,local+7); /*mapcan*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[9];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK6735:
	ctx->vsp=local; return(local[0]);}

/*do*/
static pointer F6924(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST6927:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[67];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	if (!iscons(w)) goto IF6960;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF6960;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF6961;
IF6960:
	local[1] = NIL;
	local[3]= local[1];
IF6961:
	local[3]= fqv[8];
	local[4]= fqv[9];
	local[5]= fqv[5];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO7004,env,argv,local);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= local[1];
	local[8]= fqv[10];
	local[9]= local[2];
	local[10]= fqv[21];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[68];
	local[13]= fqv[6];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
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
	local[11]= local[0];
	local[12]= fqv[69];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO7055,env,argv,local);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)MAPCAN(ctx,2,local+13); /*mapcan*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[11];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)APPEND(ctx,2,local+11); /*append*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
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
	local[0]= w;
BLK6925:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7004(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7055(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7123;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF7124;
IF7123:
	local[0]= NIL;
IF7124:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*do**/
static pointer F7153(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST7156:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[70];
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,1,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	if (!iscons(w)) goto IF7189;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	if (fqv[43]!=local[3]) goto IF7189;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	local[3]= local[0];
	goto IF7190;
IF7189:
	local[1] = NIL;
	local[3]= local[1];
IF7190:
	local[3]= fqv[8];
	local[4]= fqv[9];
	local[5]= fqv[50];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO7233,env,argv,local);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	local[7]= local[1];
	local[8]= fqv[10];
	local[9]= local[2];
	local[10]= fqv[21];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	local[12]= fqv[68];
	local[13]= fqv[6];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
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
	local[11]= local[0];
	local[12]= fqv[28];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO7284,env,argv,local);
	local[14]= argv[0];
	ctx->vsp=local+15;
	w=(pointer)MAPCAN(ctx,2,local+13); /*mapcan*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[11];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)APPEND(ctx,2,local+11); /*append*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
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
	local[0]= w;
BLK7154:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7233(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7284(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7352;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF7353;
IF7352:
	local[0]= NIL;
IF7353:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*prog*/
static pointer F7382(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7385:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[8];
	local[2]= fqv[9];
	local[3]= fqv[5];
	local[4]= argv[0];
	local[5]= fqv[10];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
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
BLK7383:
	ctx->vsp=local; return(local[0]);}

/*prog**/
static pointer F7427(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7430:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[8];
	local[2]= fqv[9];
	local[3]= fqv[50];
	local[4]= argv[0];
	local[5]= fqv[10];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
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
BLK7428:
	ctx->vsp=local; return(local[0]);}

/*casebody*/
static pointer F4295casebody(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto IF7483;
	local[0]= fqv[6];
	w = argv[0];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF7484;
IF7483:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF7484:
	w = local[0];
	local[0]= w;
BLK7473:
	ctx->vsp=local; return(local[0]);}

/*casehead*/
static pointer F4298casehead(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7518;
	local[0]= argv[1];
	w = fqv[71];
	if (memq(local[0],w)==NIL) goto IF7524;
	local[0]= T;
	goto IF7525;
IF7524:
	local[0]= fqv[72];
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF7525:
	goto IF7519;
IF7518:
	local[0]= fqv[73];
	local[1]= argv[0];
	local[2]= fqv[33];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,3,local+0); /*list*/
	local[0]= w;
IF7519:
	w = local[0];
	local[0]= w;
BLK7506:
	ctx->vsp=local; return(local[0]);}

/*case1*/
static pointer F4301case1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7569;
	local[0]= NIL;
	goto IF7570;
IF7569:
	local[0]= fqv[21];
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4298casehead(ctx,2,local+1); /*casehead*/
	local[1]= w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F4295casebody(ctx,1,local+2); /*casebody*/
	local[2]= w;
	local[3]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F4301case1(ctx,2,local+3); /*case1*/
	local[3]= w;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,5,local+0); /*list*/
	local[0]= w;
IF7570:
	w = local[0];
	local[0]= w;
BLK7557:
	ctx->vsp=local; return(local[0]);}

/*case*/
static pointer F7608(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7611:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[74];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= fqv[5];
	local[4]= local[1];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F4301case1(ctx,2,local+5); /*case1*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,3,local+3); /*list*/
	local[0]= w;
BLK7609:
	ctx->vsp=local; return(local[0]);}

/*classcasehead*/
static pointer F4305classcasehead(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	w = fqv[75];
	if (memq(local[0],w)==NIL) goto IF7666;
	local[0]= T;
	goto IF7667;
IF7666:
	w = argv[1];
	if (!!iscons(w)) goto IF7677;
	local[0]= fqv[76];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto IF7678;
IF7677:
	local[0]= fqv[77];
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO7698,env,argv,local);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
IF7678:
IF7667:
	w = local[0];
	local[0]= w;
BLK7654:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO7698(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[76];
	local[1]= env->c.clo.env1[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*classcase1*/
static pointer F4308classcase1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!!iscons(w)) goto IF7740;
	local[0]= NIL;
	goto IF7741;
IF7740:
	local[0]= fqv[21];
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4305classcasehead(ctx,2,local+1); /*classcasehead*/
	local[1]= w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	ctx->vsp=local+3;
	w=(pointer)F4295casebody(ctx,1,local+2); /*casebody*/
	local[2]= w;
	local[3]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)F4308classcase1(ctx,2,local+3); /*classcase1*/
	local[3]= w;
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,5,local+0); /*list*/
	local[0]= w;
IF7741:
	w = local[0];
	local[0]= w;
BLK7728:
	ctx->vsp=local; return(local[0]);}

/*classcase*/
static pointer F7779(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST7782:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[78];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F4308classcase1(ctx,2,local+4); /*classcase1*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK7780:
	ctx->vsp=local; return(local[0]);}

/*string*/
static pointer F4311string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto IF7839;
	local[0]= argv[0];
	goto IF7840;
IF7839:
	w = argv[0];
	if (!issymbol(w)) goto IF7846;
	local[0]= *(ovafptr(argv[0],fqv[79]));
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	goto IF7847;
IF7846:
	w = argv[0];
	if (!isnum(w)) goto IF7856;
	local[0]= NIL;
	local[1]= fqv[80];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF7857;
IF7856:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF7857:
IF7847:
IF7840:
	w = local[0];
	local[0]= w;
BLK7829:
	ctx->vsp=local; return(local[0]);}

/*alias*/
static pointer F4315alias(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	local[1]= w;
	w = argv[0];
	w->c.obj.iv[3] = local[1];
	w = local[0];
	local[0]= w;
BLK7871:
	ctx->vsp=local; return(local[0]);}

/*caaar*/
static pointer F4321caaar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7897:
	ctx->vsp=local; return(local[0]);}

/*caadr*/
static pointer F4324caadr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7921:
	ctx->vsp=local; return(local[0]);}

/*cadar*/
static pointer F4327cadar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK7945:
	ctx->vsp=local; return(local[0]);}

/*cdaar*/
static pointer F4330cdaar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7969:
	ctx->vsp=local; return(local[0]);}

/*cdadr*/
static pointer F4333cdadr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK7993:
	ctx->vsp=local; return(local[0]);}

/*cddar*/
static pointer F4336cddar(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8017:
	ctx->vsp=local; return(local[0]);}

/*cdddr*/
static pointer F4339cdddr(ctx,n,argv,env)
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
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8041:
	ctx->vsp=local; return(local[0]);}

/*fourth*/
static pointer F4345fourth(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8071:
	ctx->vsp=local; return(local[0]);}

/*fifth*/
static pointer F4348fifth(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8097:
	ctx->vsp=local; return(local[0]);}

/*sixth*/
static pointer F4351sixth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4339cdddr(ctx,1,local+0); /*cdddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8125:
	ctx->vsp=local; return(local[0]);}

/*seventh*/
static pointer F4354seventh(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4360cddddr(ctx,1,local+0); /*cddddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8149:
	ctx->vsp=local; return(local[0]);}

/*eighth*/
static pointer F4357eighth(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4360cddddr(ctx,1,local+0); /*cddddr*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F4363cadddr(ctx,1,local+0); /*cadddr*/
	local[0]= w;
BLK8173:
	ctx->vsp=local; return(local[0]);}

/*cddddr*/
static pointer F4360cddddr(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8190:
	ctx->vsp=local; return(local[0]);}

/*cadddr*/
static pointer F4363cadddr(ctx,n,argv,env)
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
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8216:
	ctx->vsp=local; return(local[0]);}

/*caaddr*/
static pointer F4366caaddr(ctx,n,argv,env)
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
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8242:
	ctx->vsp=local; return(local[0]);}

/*cdaddr*/
static pointer F4369cdaddr(ctx,n,argv,env)
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
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	local[0]= w;
BLK8268:
	ctx->vsp=local; return(local[0]);}

/*caddddr*/
static pointer F4372caddddr(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4339cdddr(ctx,1,local+0); /*cdddr*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK8294:
	ctx->vsp=local; return(local[0]);}

/*flatten*/
static pointer F4375flatten(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT8319;}
	local[0]= NIL;
ENT8319:
ENT8318:
	if (n>2) maerror();
	if (argv[0]!=NIL) goto CON8335;
	local[1]= local[0];
	goto CON8333;
CON8335:
	w = argv[0];
	if (!!iscons(w)) goto CON8341;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON8333;
CON8341:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F4375flatten(ctx,2,local+2); /*flatten*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F4375flatten(ctx,2,local+1); /*flatten*/
	local[1]= w;
	goto CON8333;
CON8351:
	local[1]= NIL;
CON8333:
	w = local[1];
	local[0]= w;
BLK8316:
	ctx->vsp=local; return(local[0]);}

/*list-insert*/
static pointer F4378list_insert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]!=NIL) goto CON8389;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON8387;
CON8389:
	local[0]= argv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON8397;
	local[0]= argv[2];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON8387;
CON8397:
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto CON8411;
	local[0]= argv[0];
	w = argv[2];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON8387;
CON8411:
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)RPLACD(ctx,2,local+1); /*rplacd*/
	w = argv[2];
	local[0]= w;
	goto CON8387;
CON8421:
	local[0]= NIL;
CON8387:
	w = local[0];
	local[0]= w;
BLK8373:
	ctx->vsp=local; return(local[0]);}

/*list-delete*/
static pointer F4381list_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	if (w==NIL) goto IF8470;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	local[0]= argv[0];
	goto IF8471;
IF8470:
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)SUB1(ctx,1,local+0); /*1-*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)NTHCDR(ctx,2,local+0); /*nthcdr*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)NTHCDR(ctx,2,local+1); /*nthcdr*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)RPLACD(ctx,2,local+0); /*rplacd*/
	local[0]= w;
IF8471:
	w = argv[0];
	local[0]= w;
BLK8458:
	ctx->vsp=local; return(local[0]);}

/*adjoin*/
static pointer F4384adjoin(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[81], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8518;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8518:
	if (n & (1<<1)) goto KEY8525;
	local[1] = NIL;
KEY8525:
	if (n & (1<<2)) goto KEY8530;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8530:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[23];
	local[6]= local[0];
	local[7]= fqv[24];
	local[8]= local[1];
	local[9]= fqv[25];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)F4420member(ctx,8,local+3); /*member*/
	if (w==NIL) goto IF8541;
	local[3]= argv[1];
	goto IF8542;
IF8541:
	local[3]= argv[0];
	w = argv[1];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
IF8542:
	w = local[3];
	local[0]= w;
BLK8505:
	ctx->vsp=local; return(local[0]);}

/*union*/
static pointer F4387union(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[83], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8580;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8580:
	if (n & (1<<1)) goto KEY8587;
	local[1] = NIL;
KEY8587:
	if (n & (1<<2)) goto KEY8592;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8592:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL8629:
	if (local[5]==NIL) goto WHX8630;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= local[3];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4420member(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF8679;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8680;
IF8679:
	local[6]= NIL;
IF8680:
	goto WHL8629;
WHX8630:
	local[6]= NIL;
BLK8631:
	w = NIL;
	local[4]= NIL;
	local[5]= argv[1];
WHL8734:
	if (local[5]==NIL) goto WHX8735;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= local[3];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4420member(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF8784;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8785;
IF8784:
	local[6]= NIL;
IF8785:
	goto WHL8734;
WHX8735:
	local[6]= NIL;
BLK8736:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	local[0]= w;
BLK8567:
	ctx->vsp=local; return(local[0]);}

/*intersection*/
static pointer F4390intersection(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[84], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8841;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8841:
	if (n & (1<<1)) goto KEY8848;
	local[1] = NIL;
KEY8848:
	if (n & (1<<2)) goto KEY8853;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY8853:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL8890:
	if (local[5]==NIL) goto WHX8891;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4420member(ctx,8,local+6); /*member*/
	if (w==NIL) goto IF8939;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF8940;
IF8939:
	local[6]= NIL;
IF8940:
	goto WHL8890;
WHX8891:
	local[6]= NIL;
BLK8892:
	w = NIL;
	w = local[3];
	local[0]= w;
BLK8828:
	ctx->vsp=local; return(local[0]);}

/*set-difference*/
static pointer F4393set_difference(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[85], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY8992;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY8992:
	if (n & (1<<1)) goto KEY8999;
	local[1] = NIL;
KEY8999:
	if (n & (1<<2)) goto KEY9004;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY9004:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0];
WHL9041:
	if (local[5]==NIL) goto WHX9042;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= fqv[23];
	local[9]= local[0];
	local[10]= fqv[24];
	local[11]= local[1];
	local[12]= fqv[25];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)F4420member(ctx,8,local+6); /*member*/
	if (w!=NIL) goto IF9091;
	local[6]= local[4];
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	local[6]= local[3];
	goto IF9092;
IF9091:
	local[6]= NIL;
IF9092:
	goto WHL9041;
WHX9042:
	local[6]= NIL;
BLK9043:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0]= w;
BLK8979:
	ctx->vsp=local; return(local[0]);}

/*set-exclusive-or*/
static pointer F4396set_exclusive_or(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[86], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9149;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY9149:
	if (n & (1<<1)) goto KEY9156;
	local[1] = NIL;
KEY9156:
	if (n & (1<<2)) goto KEY9161;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY9161:
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
WHL9200:
	if (local[6]==NIL) goto WHX9201;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[5] = w;
	local[7]= local[5];
	local[8]= argv[1];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)F4420member(ctx,8,local+7); /*member*/
	if (w!=NIL) goto IF9260;
	local[7]= local[5];
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
	goto IF9261;
IF9260:
	local[7]= NIL;
IF9261:
	goto WHL9200;
WHX9201:
	local[7]= NIL;
BLK9202:
	w = NIL;
	local[5]= NIL;
	local[6]= argv[1];
WHL9313:
	if (local[6]==NIL) goto WHX9314;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[5] = w;
	local[7]= local[5];
	local[8]= argv[0];
	local[9]= fqv[23];
	local[10]= local[0];
	local[11]= fqv[24];
	local[12]= local[1];
	local[13]= fqv[25];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)F4420member(ctx,8,local+7); /*member*/
	if (w!=NIL) goto IF9373;
	local[7]= local[5];
	w = local[4];
	ctx->vsp=local+8;
	local[4] = cons(ctx,local[7],w);
	local[7]= local[4];
	goto IF9374;
IF9373:
	local[7]= NIL;
IF9374:
	goto WHL9313;
WHX9314:
	local[7]= NIL;
BLK9315:
	w = NIL;
	local[5]= local[3];
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[0]= w;
BLK9136:
	ctx->vsp=local; return(local[0]);}

/*rotate-list*/
static pointer F4399rotate_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPEND(ctx,2,local+0); /*append*/
	local[0]= w;
BLK9416:
	ctx->vsp=local; return(local[0]);}

/*last*/
static pointer F4402last(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
WHL9452:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (!iscons(w)) goto WHX9453;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	goto WHL9452;
WHX9453:
	local[0]= NIL;
BLK9454:
	w = argv[0];
	local[0]= w;
BLK9442:
	ctx->vsp=local; return(local[0]);}

/*copy-tree*/
static pointer F4405copy_tree(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= T;
	local[1]= T;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SUBST(ctx,3,local+0); /*subst*/
	local[0]= w;
BLK9479:
	ctx->vsp=local; return(local[0]);}

/*copy-list*/
static pointer F4408copy_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)REVERSE(ctx,1,local+0); /*reverse*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	local[0]= w;
BLK9494:
	ctx->vsp=local; return(local[0]);}

/*nreconc*/
static pointer F4411nreconc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)NREVERSE(ctx,1,local+0); /*nreverse*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
BLK9511:
	ctx->vsp=local; return(local[0]);}

/*rassoc*/
static pointer F4414rassoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[1];
WHL9560:
	if (local[1]==NIL) goto WHX9561;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)EQUAL(ctx,2,local+2); /*equal*/
	if (w==NIL) goto IF9609;
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK9531;
	goto IF9610;
IF9609:
	local[2]= NIL;
IF9610:
	goto WHL9560;
WHX9561:
	local[2]= NIL;
BLK9562:
	w = NIL;
	local[0]= w;
BLK9531:
	ctx->vsp=local; return(local[0]);}

/*acons*/
static pointer F4417acons(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	w = argv[1];
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	w = argv[2];
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
BLK9631:
	ctx->vsp=local; return(local[0]);}

/*member*/
static pointer F4420member(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[87], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9670;
	local[0] = NIL;
KEY9670:
	if (n & (1<<1)) goto KEY9675;
	local[1] = NIL;
KEY9675:
	if (n & (1<<2)) goto KEY9680;
	local[2] = NIL;
KEY9680:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUPERMEMBER(ctx,5,local+3); /*supermember*/
	local[0]= w;
BLK9657:
	ctx->vsp=local; return(local[0]);}

/*assoc*/
static pointer F4423assoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[88], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9711;
	local[0] = NIL;
KEY9711:
	if (n & (1<<1)) goto KEY9716;
	local[1] = NIL;
KEY9716:
	if (n & (1<<2)) goto KEY9721;
	local[2] = NIL;
KEY9721:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUPERASSOC(ctx,5,local+3); /*superassoc*/
	local[0]= w;
BLK9698:
	ctx->vsp=local; return(local[0]);}

/*subsetp*/
static pointer F4426subsetp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[89], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY9752;
	local[0] = NIL;
KEY9752:
	if (n & (1<<1)) goto KEY9757;
	local[1] = NIL;
KEY9757:
	if (n & (1<<2)) goto KEY9762;
	local[2] = NIL;
KEY9762:
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO9772,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F4628every(ctx,2,local+3); /*every*/
	local[0]= w;
BLK9739:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO9772(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[1];
	local[2]= fqv[25];
	local[3]= env->c.clo.env2[0];
	local[4]= fqv[23];
	local[5]= env->c.clo.env2[1];
	local[6]= fqv[24];
	local[7]= env->c.clo.env2[2];
	ctx->vsp=local+8;
	w=(pointer)F4420member(ctx,8,local+0); /*member*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*maplist*/
static pointer F4429maplist(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST9804:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF9821;
	local[3]= NIL;
	local[4]= NIL;
WHL9838:
	if (argv[1]==NIL) goto WHX9839;
	local[3] = NIL;
	local[5]= argv[1];
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[4] = local[0];
WHL9882:
	if (local[4]==NIL) goto WHX9883;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	local[5]= local[4];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)RPLACA2(ctx,2,local+5); /*rplaca2*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	goto WHL9882;
WHX9883:
	local[5]= NIL;
BLK9884:
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL9838;
WHX9839:
	local[5]= NIL;
BLK9840:
	w = local[5];
	local[3]= w;
	goto IF9822;
IF9821:
WHL9946:
	if (argv[1]==NIL) goto WHX9947;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,2,local+3); /*funcall*/
	local[3]= w;
	w = local[2];
	ctx->vsp=local+4;
	local[2] = cons(ctx,local[3],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	goto WHL9946;
WHX9947:
	local[3]= NIL;
BLK9948:
IF9822:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK9802:
	ctx->vsp=local; return(local[0]);}

/*mapcon*/
static pointer F4432mapcon(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST9987:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF10004;
	local[3]= NIL;
	local[4]= NIL;
WHL10021:
	if (argv[1]==NIL) goto WHX10022;
	local[3] = NIL;
	local[5]= argv[1];
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[4] = local[0];
WHL10065:
	if (local[4]==NIL) goto WHX10066;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+6;
	local[3] = cons(ctx,local[5],w);
	local[5]= local[4];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.cdr;
	ctx->vsp=local+7;
	w=(pointer)RPLACA2(ctx,2,local+5); /*rplaca2*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	goto WHL10065;
WHX10066:
	local[5]= NIL;
BLK10067:
	local[5]= argv[0];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[5]= w;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NCONC(ctx,2,local+5); /*nconc*/
	local[2] = w;
	goto WHL10021;
WHX10022:
	local[5]= NIL;
BLK10023:
	w = local[5];
	local[3]= w;
	goto IF10005;
IF10004:
WHL10127:
	if (argv[1]==NIL) goto WHX10128;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)FUNCALL(ctx,2,local+3); /*funcall*/
	local[3]= w;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)NCONC(ctx,2,local+3); /*nconc*/
	local[2] = w;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	goto WHL10127;
WHX10128:
	local[3]= NIL;
BLK10129:
IF10005:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK9985:
	ctx->vsp=local; return(local[0]);}

/*find*/
static pointer F4435find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[90], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10179;
	local[0] = makeint((eusinteger_t)0L);
KEY10179:
	if (n & (1<<1)) goto KEY10184;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[1] = w;
KEY10184:
	if (n & (1<<2)) goto KEY10192;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY10192:
	if (n & (1<<3)) goto KEY10199;
	local[3] = NIL;
KEY10199:
	if (n & (1<<4)) goto KEY10204;
	local[4] = (pointer)get_sym_func(fqv[82]);
KEY10204:
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)FIND(ctx,9,local+5); /*system::raw-find*/
	local[0]= w;
BLK10164:
	ctx->vsp=local; return(local[0]);}

/*find-if*/
static pointer F4438find_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[91], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10239;
	local[0] = makeint((eusinteger_t)0L);
KEY10239:
	if (n & (1<<1)) goto KEY10244;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10244:
	if (n & (1<<2)) goto KEY10252;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10252:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= NIL;
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)FIND(ctx,9,local+3); /*system::raw-find*/
	local[0]= w;
BLK10226:
	ctx->vsp=local; return(local[0]);}

/*find-if-not*/
static pointer F4441find_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[92], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10285;
	local[0] = makeint((eusinteger_t)0L);
KEY10285:
	if (n & (1<<1)) goto KEY10290;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10290:
	if (n & (1<<2)) goto KEY10298;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10298:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)FIND(ctx,9,local+3); /*system::raw-find*/
	local[0]= w;
BLK10272:
	ctx->vsp=local; return(local[0]);}

/*position*/
static pointer F4444position(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[93], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10334;
	local[0] = makeint((eusinteger_t)0L);
KEY10334:
	if (n & (1<<1)) goto KEY10339;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY10339:
	if (n & (1<<2)) goto KEY10347;
	local[2] = makeint((eusinteger_t)1L);
KEY10347:
	if (n & (1<<3)) goto KEY10352;
	local[3] = (pointer)get_sym_func(fqv[72]);
KEY10352:
	if (n & (1<<4)) goto KEY10359;
	local[4] = NIL;
KEY10359:
	if (n & (1<<5)) goto KEY10364;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY10364:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[2];
	ctx->vsp=local+16;
	w=(pointer)POSITION(ctx,10,local+6); /*system::raw-position*/
	local[0]= w;
BLK10318:
	ctx->vsp=local; return(local[0]);}

/*position-if*/
static pointer F4447position_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[94], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10401;
	local[0] = makeint((eusinteger_t)0L);
KEY10401:
	if (n & (1<<1)) goto KEY10406;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY10406:
	if (n & (1<<2)) goto KEY10414;
	local[2] = makeint((eusinteger_t)1L);
KEY10414:
	if (n & (1<<3)) goto KEY10419;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY10419:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)POSITION(ctx,10,local+4); /*system::raw-position*/
	local[0]= w;
BLK10387:
	ctx->vsp=local; return(local[0]);}

/*position-if-not*/
static pointer F4450position_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[95], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10454;
	local[0] = makeint((eusinteger_t)0L);
KEY10454:
	if (n & (1<<1)) goto KEY10459;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY10459:
	if (n & (1<<2)) goto KEY10467;
	local[2] = makeint((eusinteger_t)1L);
KEY10467:
	if (n & (1<<3)) goto KEY10472;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY10472:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)POSITION(ctx,10,local+4); /*system::raw-position*/
	local[0]= w;
BLK10440:
	ctx->vsp=local; return(local[0]);}

/*count*/
static pointer F4453count(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[96], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10508;
	local[0] = makeint((eusinteger_t)0L);
KEY10508:
	if (n & (1<<1)) goto KEY10513;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[1] = w;
KEY10513:
	if (n & (1<<2)) goto KEY10521;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY10521:
	if (n & (1<<3)) goto KEY10528;
	local[3] = NIL;
KEY10528:
	if (n & (1<<4)) goto KEY10533;
	local[4] = (pointer)get_sym_func(fqv[82]);
KEY10533:
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[2];
	local[8]= local[3];
	local[9]= local[4];
	local[10]= NIL;
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	ctx->vsp=local+14;
	w=(pointer)COUNT(ctx,9,local+5); /*system::raw-count*/
	local[0]= w;
BLK10493:
	ctx->vsp=local; return(local[0]);}

/*count-if*/
static pointer F4456count_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[97], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10568;
	local[0] = makeint((eusinteger_t)0L);
KEY10568:
	if (n & (1<<1)) goto KEY10573;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10573:
	if (n & (1<<2)) goto KEY10581;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10581:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= NIL;
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)COUNT(ctx,9,local+3); /*system::raw-count*/
	local[0]= w;
BLK10555:
	ctx->vsp=local; return(local[0]);}

/*count-if-not*/
static pointer F4459count_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[98], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10614;
	local[0] = makeint((eusinteger_t)0L);
KEY10614:
	if (n & (1<<1)) goto KEY10619;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[1] = w;
KEY10619:
	if (n & (1<<2)) goto KEY10627;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY10627:
	local[3]= NIL;
	local[4]= argv[1];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[2];
	local[8]= NIL;
	local[9]= argv[0];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)COUNT(ctx,9,local+3); /*system::raw-count*/
	local[0]= w;
BLK10601:
	ctx->vsp=local; return(local[0]);}

/*member-if*/
static pointer F4462member_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[99], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10658;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY10658:
WHL10669:
	if (argv[1]==NIL) goto WHX10670;
	local[1]= argv[0];
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w==NIL) goto IF10677;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK10647;
	goto IF10678;
IF10677:
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[1]= argv[1];
IF10678:
	goto WHL10669;
WHX10670:
	local[1]= NIL;
BLK10671:
	w = local[1];
	local[0]= w;
BLK10647:
	ctx->vsp=local; return(local[0]);}

/*member-if-not*/
static pointer F4465member_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[100], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY10720;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY10720:
WHL10731:
	if (argv[1]==NIL) goto WHX10732;
	local[1]= argv[0];
	local[2]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w!=NIL) goto IF10739;
	w = argv[1];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK10709;
	goto IF10740;
IF10739:
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	local[1]= argv[1];
IF10740:
	goto WHL10731;
WHX10732:
	local[1]= NIL;
BLK10733:
	w = local[1];
	local[0]= w;
BLK10709:
	ctx->vsp=local; return(local[0]);}

/*collect-if*/
static pointer F4468collect_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
WHL10804:
	if (local[3]==NIL) goto WHX10805;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,2,local+4); /*funcall*/
	if (w==NIL) goto IF10853;
	local[4]= local[2];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF10854;
IF10853:
	local[4]= NIL;
IF10854:
	goto WHL10804;
WHX10805:
	local[4]= NIL;
BLK10806:
	w = NIL;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0]= w;
BLK10771:
	ctx->vsp=local; return(local[0]);}

/*collect-instances*/
static pointer F4471collect_instances(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO10895,env,argv,local);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F4375flatten(ctx,1,local+1); /*flatten*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F4468collect_if(ctx,2,local+0); /*collect-if*/
	local[0]= w;
BLK10882:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO10895(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env1[0];
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*pairlis*/
static pointer F4474pairlis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT10921;}
	local[0]= NIL;
ENT10921:
ENT10920:
	if (n>3) maerror();
	if (argv[0]==NIL) goto IF10937;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4474pairlis(ctx,3,local+2); /*pairlis*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto IF10938;
IF10937:
	local[1]= local[0];
IF10938:
	w = local[1];
	local[0]= w;
BLK10918:
	ctx->vsp=local; return(local[0]);}

/*transpose-list*/
static pointer F4477transpose_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= makeint((eusinteger_t)0L);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL11022:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX11023;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO11036,env,argv,local);
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL11022;
WHX11023:
	local[3]= NIL;
BLK11024:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK10974:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO11036(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env2[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-list*/
static pointer F4480make_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[101], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY11089;
	local[0] = NIL;
KEY11089:
	local[1]= NIL;
	w = argv[0];
	if (isint(w)) goto IF11108;
	local[2]= fqv[102];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF11109;
IF11108:
	local[2]= NIL;
IF11109:
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[0];
WHL11143:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX11144;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL11143;
WHX11144:
	local[4]= NIL;
BLK11145:
	w = local[1];
	local[0]= w;
BLK11080:
	ctx->vsp=local; return(local[0]);}

/*make-sequence*/
static pointer F4483make_sequence(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[103], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11190;
	local[0] = NIL;
KEY11190:
	local[1]= argv[0];
	w = fqv[104];
	if (memq(local[1],w)!=NIL) goto OR11201;
	local[1]= argv[0];
	if (loadglobal(fqv[19])==local[1]) goto OR11201;
	goto IF11199;
OR11201:
	local[1]= argv[1];
	local[2]= fqv[105];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F4480make_list(ctx,3,local+1); /*make-list*/
	local[1]= w;
	goto IF11200;
IF11199:
	local[1]= argv[1];
	local[2]= fqv[106];
	local[3]= argv[0];
	local[4]= fqv[105];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(*ftab[0])(ctx,5,local+1,&ftab[0],fqv[107]); /*make-array*/
	local[1]= w;
IF11200:
	w = local[1];
	local[0]= w;
BLK11179:
	ctx->vsp=local; return(local[0]);}

/*fill*/
static pointer F4486fill(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[108], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11247;
	local[0] = makeint((eusinteger_t)0L);
KEY11247:
	if (n & (1<<1)) goto KEY11252;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY11252:
	local[2]= argv[0];
	local[3]= argv[1];
	local[4]= local[0];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)FILL(ctx,4,local+2); /*system::raw-fill*/
	local[0]= w;
BLK11235:
	ctx->vsp=local; return(local[0]);}

/*replace*/
static pointer F4489replace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[109], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11286;
	local[0] = makeint((eusinteger_t)0L);
KEY11286:
	if (n & (1<<1)) goto KEY11291;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11291:
	if (n & (1<<2)) goto KEY11299;
	local[2] = makeint((eusinteger_t)0L);
KEY11299:
	if (n & (1<<3)) goto KEY11304;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[3] = w;
KEY11304:
	local[4]= argv[0];
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)MIN(ctx,2,local+5); /*min*/
	local[5]= w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11346;
	local[6]= local[0];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[0] = w;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11366;
	local[6]= local[2];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[1] = w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[5];
WHL11407:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX11408;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= w;
	local[9]= w;
	*(ovafptr(argv[0],fqv[16])) = local[9];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL11407;
WHX11408:
	local[8]= NIL;
BLK11409:
	w = NIL;
	local[6]= w;
	goto CON11364;
CON11366:
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[5];
WHL11529:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX11530;
	local[8]= argv[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	local[9]= w;
	*(ovafptr(argv[0],fqv[16])) = local[9];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[2] = w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0] = (w)->c.cons.cdr;
	w = local[8];
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL11529;
WHX11530:
	local[8]= NIL;
BLK11531:
	w = NIL;
	local[6]= w;
	goto CON11364;
CON11502:
	local[6]= NIL;
CON11364:
	goto CON11344;
CON11346:
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LISTP(ctx,1,local+6); /*listp*/
	if (w==NIL) goto CON11603;
	local[6]= local[2];
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)NTHCDR(ctx,2,local+6); /*nthcdr*/
	argv[1] = w;
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[5];
WHL11644:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX11645;
	local[8]= argv[0];
	local[9]= local[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[10];
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[0] = w;
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL11644;
WHX11645:
	local[8]= NIL;
BLK11646:
	w = NIL;
	local[6]= w;
	goto CON11344;
CON11603:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[2];
	local[11]= local[3];
	ctx->vsp=local+12;
	w=(pointer)VECREPLACE(ctx,6,local+6); /*system::vector-replace*/
	local[6]= w;
	goto CON11344;
CON11713:
	local[6]= NIL;
CON11344:
	w = local[4];
	local[0]= w;
BLK11272:
	ctx->vsp=local; return(local[0]);}

/*remove*/
static pointer F4492remove(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[110], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11747;
	local[0] = makeint((eusinteger_t)0L);
KEY11747:
	if (n & (1<<1)) goto KEY11752;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY11752:
	if (n & (1<<2)) goto KEY11760;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY11760:
	if (n & (1<<3)) goto KEY11767;
	local[3] = NIL;
KEY11767:
	if (n & (1<<4)) goto KEY11772;
	local[4] = makeint((eusinteger_t)1000000L);
KEY11772:
	if (n & (1<<5)) goto KEY11777;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY11777:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(pointer)UNIREMOVE(ctx,10,local+6); /*system::universal-remove*/
	local[0]= w;
BLK11731:
	ctx->vsp=local; return(local[0]);}

/*remove-if*/
static pointer F4495remove_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[111], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11814;
	local[0] = makeint((eusinteger_t)0L);
KEY11814:
	if (n & (1<<1)) goto KEY11819;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11819:
	if (n & (1<<2)) goto KEY11827;
	local[2] = makeint((eusinteger_t)1000000L);
KEY11827:
	if (n & (1<<3)) goto KEY11832;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY11832:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)UNIREMOVE(ctx,10,local+4); /*system::universal-remove*/
	local[0]= w;
BLK11800:
	ctx->vsp=local; return(local[0]);}

/*remove-if-not*/
static pointer F4498remove_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[112], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11867;
	local[0] = makeint((eusinteger_t)0L);
KEY11867:
	if (n & (1<<1)) goto KEY11872;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11872:
	if (n & (1<<2)) goto KEY11880;
	local[2] = makeint((eusinteger_t)1000000L);
KEY11880:
	if (n & (1<<3)) goto KEY11885;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY11885:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)UNIREMOVE(ctx,10,local+4); /*system::universal-remove*/
	local[0]= w;
BLK11853:
	ctx->vsp=local; return(local[0]);}

/*delete*/
static pointer F4501delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[113], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11922;
	local[0] = makeint((eusinteger_t)0L);
KEY11922:
	if (n & (1<<1)) goto KEY11927;
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY11927:
	if (n & (1<<2)) goto KEY11935;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY11935:
	if (n & (1<<3)) goto KEY11942;
	local[3] = NIL;
KEY11942:
	if (n & (1<<4)) goto KEY11947;
	local[4] = makeint((eusinteger_t)1000000L);
KEY11947:
	if (n & (1<<5)) goto KEY11952;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY11952:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[5];
	local[11]= NIL;
	local[12]= NIL;
	local[13]= local[0];
	local[14]= local[1];
	local[15]= local[4];
	ctx->vsp=local+16;
	w=(pointer)DELETE(ctx,10,local+6); /*system::raw-delete*/
	local[0]= w;
BLK11906:
	ctx->vsp=local; return(local[0]);}

/*delete-if*/
static pointer F4504delete_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[114], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY11989;
	local[0] = makeint((eusinteger_t)0L);
KEY11989:
	if (n & (1<<1)) goto KEY11994;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY11994:
	if (n & (1<<2)) goto KEY12002;
	local[2] = makeint((eusinteger_t)1000000L);
KEY12002:
	if (n & (1<<3)) goto KEY12007;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12007:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= argv[0];
	local[10]= NIL;
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)DELETE(ctx,10,local+4); /*system::raw-delete*/
	local[0]= w;
BLK11975:
	ctx->vsp=local; return(local[0]);}

/*delete-if-not*/
static pointer F4507delete_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[115], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY12042;
	local[0] = makeint((eusinteger_t)0L);
KEY12042:
	if (n & (1<<1)) goto KEY12047;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12047:
	if (n & (1<<2)) goto KEY12055;
	local[2] = makeint((eusinteger_t)1000000L);
KEY12055:
	if (n & (1<<3)) goto KEY12060;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12060:
	local[4]= NIL;
	local[5]= argv[1];
	local[6]= NIL;
	local[7]= NIL;
	local[8]= local[3];
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= local[0];
	local[12]= local[1];
	local[13]= local[2];
	ctx->vsp=local+14;
	w=(pointer)DELETE(ctx,10,local+4); /*system::raw-delete*/
	local[0]= w;
BLK12028:
	ctx->vsp=local; return(local[0]);}

/*substitute*/
static pointer F4510substitute(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[116], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12099;
	local[0] = makeint((eusinteger_t)0L);
KEY12099:
	if (n & (1<<1)) goto KEY12104;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY12104:
	if (n & (1<<2)) goto KEY12112;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY12112:
	if (n & (1<<3)) goto KEY12119;
	local[3] = NIL;
KEY12119:
	if (n & (1<<4)) goto KEY12124;
	local[4] = makeint((eusinteger_t)1000000L);
KEY12124:
	if (n & (1<<5)) goto KEY12129;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY12129:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[5];
	local[12]= NIL;
	local[13]= NIL;
	local[14]= local[0];
	local[15]= local[1];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)SUBSTITUTE(ctx,11,local+6); /*system::raw-substitute*/
	local[0]= w;
BLK12081:
	ctx->vsp=local; return(local[0]);}

/*substitute-if*/
static pointer F4513substitute_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[117], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12169;
	local[0] = makeint((eusinteger_t)0L);
KEY12169:
	if (n & (1<<1)) goto KEY12174;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12174:
	if (n & (1<<2)) goto KEY12182;
	local[2] = makeint((eusinteger_t)1000000L);
KEY12182:
	if (n & (1<<3)) goto KEY12187;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12187:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= argv[1];
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)SUBSTITUTE(ctx,11,local+4); /*system::raw-substitute*/
	local[0]= w;
BLK12153:
	ctx->vsp=local; return(local[0]);}

/*substitute-if-not*/
static pointer F4516substitute_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[118], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12225;
	local[0] = makeint((eusinteger_t)0L);
KEY12225:
	if (n & (1<<1)) goto KEY12230;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12230:
	if (n & (1<<2)) goto KEY12238;
	local[2] = makeint((eusinteger_t)1000000L);
KEY12238:
	if (n & (1<<3)) goto KEY12243;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12243:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= NIL;
	local[11]= argv[1];
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)SUBSTITUTE(ctx,11,local+4); /*system::raw-substitute*/
	local[0]= w;
BLK12209:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute*/
static pointer F4519nsubstitute(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[119], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12283;
	local[0] = makeint((eusinteger_t)0L);
KEY12283:
	if (n & (1<<1)) goto KEY12288;
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[1] = w;
KEY12288:
	if (n & (1<<2)) goto KEY12296;
	local[2] = (pointer)get_sym_func(fqv[72]);
KEY12296:
	if (n & (1<<3)) goto KEY12303;
	local[3] = NIL;
KEY12303:
	if (n & (1<<4)) goto KEY12308;
	local[4] = makeint((eusinteger_t)1000000L);
KEY12308:
	if (n & (1<<5)) goto KEY12313;
	local[5] = (pointer)get_sym_func(fqv[82]);
KEY12313:
	local[6]= argv[0];
	local[7]= argv[1];
	local[8]= argv[2];
	local[9]= local[2];
	local[10]= local[3];
	local[11]= local[5];
	local[12]= NIL;
	local[13]= NIL;
	local[14]= local[0];
	local[15]= local[1];
	local[16]= local[4];
	ctx->vsp=local+17;
	w=(pointer)NSUBSTITUTE(ctx,11,local+6); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12265:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute-if*/
static pointer F4522nsubstitute_if(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[120], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12353;
	local[0] = makeint((eusinteger_t)0L);
KEY12353:
	if (n & (1<<1)) goto KEY12358;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12358:
	if (n & (1<<2)) goto KEY12366;
	local[2] = makeint((eusinteger_t)1000000L);
KEY12366:
	if (n & (1<<3)) goto KEY12371;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12371:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= argv[1];
	local[11]= NIL;
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)NSUBSTITUTE(ctx,11,local+4); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12337:
	ctx->vsp=local; return(local[0]);}

/*nsubstitute-if-not*/
static pointer F4525nsubstitute_if_not(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[121], &argv[3], n-3, local+0, 0);
	if (n & (1<<0)) goto KEY12409;
	local[0] = makeint((eusinteger_t)0L);
KEY12409:
	if (n & (1<<1)) goto KEY12414;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY12414:
	if (n & (1<<2)) goto KEY12422;
	local[2] = makeint((eusinteger_t)1000000L);
KEY12422:
	if (n & (1<<3)) goto KEY12427;
	local[3] = (pointer)get_sym_func(fqv[82]);
KEY12427:
	local[4]= argv[0];
	local[5]= NIL;
	local[6]= argv[2];
	local[7]= NIL;
	local[8]= NIL;
	local[9]= local[3];
	local[10]= NIL;
	local[11]= argv[1];
	local[12]= local[0];
	local[13]= local[1];
	local[14]= local[2];
	ctx->vsp=local+15;
	w=(pointer)NSUBSTITUTE(ctx,11,local+4); /*system::raw-nsubstitute*/
	local[0]= w;
BLK12393:
	ctx->vsp=local; return(local[0]);}

/*unique*/
static pointer F4528unique(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (!!iscons(w)) goto CON12461;
	local[0]= argv[0];
	goto CON12459;
CON12461:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	if (memq(local[0],w)==NIL) goto CON12471;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)F4528unique(ctx,1,local+0); /*unique*/
	local[0]= w;
	goto CON12459;
CON12471:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F4528unique(ctx,1,local+1); /*unique*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON12459;
CON12495:
	local[0]= NIL;
CON12459:
	w = local[0];
	local[0]= w;
BLK12449:
	ctx->vsp=local; return(local[0]);}

/*remove-duplicates*/
static pointer F4531remove_duplicates(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[122], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY12528;
	local[0] = (pointer)get_sym_func(fqv[72]);
KEY12528:
	if (n & (1<<1)) goto KEY12535;
	local[1] = NIL;
KEY12535:
	if (n & (1<<2)) goto KEY12540;
	local[2] = (pointer)get_sym_func(fqv[82]);
KEY12540:
	if (n & (1<<3)) goto KEY12547;
	local[3] = makeint((eusinteger_t)0L);
KEY12547:
	if (n & (1<<4)) goto KEY12552;
	local[4] = makeint((eusinteger_t)1000000L);
KEY12552:
	local[5]= argv[0];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)REMOVE_DUPLICATES(ctx,6,local+5); /*system::raw-remove-duplicates*/
	local[0]= w;
BLK12515:
	ctx->vsp=local; return(local[0]);}

/*extream*/
static pointer F4534extream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT12574;}
	local[0]= (pointer)get_sym_func(fqv[82]);
ENT12574:
ENT12573:
	if (n>3) maerror();
	if (argv[0]!=NIL) goto IF12592;
	local[1]= NIL;
	goto IF12593;
IF12592:
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	local[2]= local[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	local[2]= w;
	local[3]= NIL;
	w = argv[0];
	if (!iscons(w)) goto IF12617;
	local[4]= NIL;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.cdr;
WHL12644:
	if (local[5]==NIL) goto WHX12645;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,3,local+6); /*funcall*/
	if (w==NIL) goto IF12694;
	local[1] = local[4];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[2] = w;
	local[6]= local[2];
	goto IF12695;
IF12694:
	local[6]= NIL;
IF12695:
	goto WHL12644;
WHX12645:
	local[6]= NIL;
BLK12646:
	w = NIL;
	local[4]= w;
	goto IF12618;
IF12617:
	local[4]= makeint((eusinteger_t)0L);
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
WHL12750:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX12751;
	local[6]= argv[1];
	local[7]= local[0];
	local[8]= argv[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[3] = w;
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[7]= w;
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,3,local+6); /*funcall*/
	if (w==NIL) goto IF12760;
	local[1] = local[3];
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	local[2] = w;
	local[6]= local[2];
	goto IF12761;
IF12760:
	local[6]= NIL;
IF12761:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL12750;
WHX12751:
	local[6]= NIL;
BLK12752:
	w = NIL;
	local[4]= w;
IF12618:
	w = local[1];
	local[1]= w;
IF12593:
	w = local[1];
	local[0]= w;
BLK12571:
	ctx->vsp=local; return(local[0]);}

/*send-super-lexpr*/
static pointer F12815(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST12818:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[126];
	local[4]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= argv[0];
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12816:
	ctx->vsp=local; return(local[0]);}

/*send-super**/
static pointer F12875(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST12878:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[125];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[126];
	local[4]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12876:
	ctx->vsp=local; return(local[0]);}

/*send-lexpr*/
static pointer F12929(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST12932:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= argv[0];
	local[4]= argv[1];
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12930:
	ctx->vsp=local; return(local[0]);}

/*send**/
static pointer F12973(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST12976:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[123];
	local[2]= fqv[124];
	local[3]= fqv[32];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK12974:
	ctx->vsp=local; return(local[0]);}

/*send-super*/
static pointer F13005(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13008:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[125];
	local[2]= fqv[126];
	local[3]= fqv[127];
	w = fqv[128];
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= argv[0];
	local[5]= local[0];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13006:
	ctx->vsp=local; return(local[0]);}

/*send-all*/
static pointer F4543send_all(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13057:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO13069,env,argv,local);
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[0]= w;
BLK13055:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO13069(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[32];
	local[1]= argv[0];
	local[2]= env->c.clo.env2[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,3,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*resend*/
static pointer F4546resend(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[32];
	local[1]= argv[0];
	w = argv[1];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	ctx->vsp=local+1;
	w=(pointer)EVAL(ctx,1,local+0); /*eval*/
	local[0]= w;
BLK13092:
	ctx->vsp=local; return(local[0]);}

/*instance*/
static pointer F13118(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13121:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	if (local[0]==NIL) goto IF13132;
	local[1]= fqv[129];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= fqv[130];
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
	local[3]= w;
	local[4]= fqv[32];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[1]= w;
	goto IF13133;
IF13132:
	local[1]= fqv[130];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF13133:
	w = local[1];
	local[0]= w;
BLK13119:
	ctx->vsp=local; return(local[0]);}

/*instance**/
static pointer F13199(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13202:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	if (local[0]==NIL) goto IF13213;
	local[1]= fqv[131];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= fqv[5];
	local[3]= local[1];
	local[4]= fqv[130];
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
	local[3]= w;
	local[4]= fqv[132];
	local[5]= local[1];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[1]= w;
	goto IF13214;
IF13213:
	local[1]= fqv[130];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
IF13214:
	w = local[1];
	local[0]= w;
BLK13200:
	ctx->vsp=local; return(local[0]);}

/*make-instance*/
static pointer F4551make_instance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13282:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
WHL13306:
	if (local[0]==NIL) goto WHX13307;
	local[2]= local[1];
	local[3]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)F4311string(ctx,1,local+4); /*string*/
	local[4]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[5];
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SETSLOT(ctx,4,local+2); /*setslot*/
	goto WHL13306;
WHX13307:
	local[2]= NIL;
BLK13308:
	w = local[1];
	local[0]= w;
BLK13280:
	ctx->vsp=local; return(local[0]);}

/*defclassmethod*/
static pointer F13396(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST13399:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[133];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SYMVALUE(ctx,1,local+2); /*symbol-value*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GETCLASS(ctx,1,local+2); /*class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,1,local+2,&ftab[1],fqv[134]); /*metaclass-name*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK13397:
	ctx->vsp=local; return(local[0]);}

/*delete-method*/
static pointer F4555delete_method(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= fqv[25];
	local[3]= (pointer)get_sym_func(fqv[16]);
	ctx->vsp=local+4;
	w=(pointer)F4501delete(ctx,4,local+0); /*delete*/
	local[0]= w;
	local[1]= w;
	w = argv[0];
	w->c.obj.iv[7] = local[1];
	local[0]= T;
	ctx->vsp=local+1;
	w=(pointer)METHCACHE(ctx,1,local+0); /*system::method-cache*/
	local[0]= w;
BLK13430:
	ctx->vsp=local; return(local[0]);}

/*make-class*/
static pointer F4558make_class(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[135], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY13483;
	local[0] = loadglobal(fqv[136]);
KEY13483:
	if (n & (1<<1)) goto KEY13490;
	local[1] = loadglobal(fqv[136]);
KEY13490:
	if (n & (1<<2)) goto KEY13496;
	local[2] = NIL;
KEY13496:
	if (n & (1<<3)) goto KEY13501;
	local[3] = NIL;
KEY13501:
	if (n & (1<<4)) goto KEY13506;
	local[4] = NIL;
KEY13506:
	if (n & (1<<5)) goto KEY13511;
	local[5] = NIL;
KEY13511:
	if (n & (1<<6)) goto KEY13516;
	local[6] = NIL;
KEY13516:
	if (n & (1<<7)) goto KEY13521;
	local[7] = NIL;
KEY13521:
	if (n & (1<<8)) goto KEY13526;
	local[8] = makeint((eusinteger_t)-1L);
KEY13526:
	if (n & (1<<9)) goto KEY13531;
	local[9] = NIL;
KEY13531:
	if (n & (1<<10)) goto KEY13536;
	local[10] = NIL;
KEY13536:
	w = local[0];
	if (!issymbol(w)) goto IF13545;
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SYMVALUE(ctx,1,local+11); /*symbol-value*/
	local[0] = w;
	local[11]= local[0];
	goto IF13546;
IF13545:
	local[11]= NIL;
IF13546:
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)BOUNDP(ctx,1,local+11); /*boundp*/
	if (w==NIL) goto IF13567;
	local[11]= argv[0];
	ctx->vsp=local+12;
	w=(pointer)SYMVALUE(ctx,1,local+11); /*symbol-value*/
	local[11]= w;
	goto IF13568;
IF13567:
	local[11]= NIL;
IF13568:
	local[12]= NIL;
	local[13]= NIL;
	local[14]= NIL;
	local[15]= NIL;
	local[16]= makeint((eusinteger_t)0L);
	local[17]= NIL;
	local[18]= NIL;
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)CLASSP(ctx,1,local+19); /*classp*/
	if (w!=NIL) goto CON13604;
	local[19]= local[6];
	if (local[19]!=NIL) goto CON13612;
CON13614:
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)CLASSP(ctx,1,local+19); /*classp*/
	local[19]= w;
	if (w!=NIL) goto CON13612;
CON13618:
	if (local[0]==NIL) goto CON13624;
	local[19]= local[0];
	ctx->vsp=local+20;
	w=(pointer)GETCLASS(ctx,1,local+19); /*class*/
	local[6] = w;
	local[19]= local[6];
	goto CON13612;
CON13624:
	local[19]= fqv[137];
	ctx->vsp=local+20;
	w=(pointer)SYMVALUE(ctx,1,local+19); /*symbol-value*/
	local[6] = w;
	local[19]= local[6];
	goto CON13612;
CON13637:
	local[19]= NIL;
CON13612:
	local[19]= local[6];
	ctx->vsp=local+20;
	w=(pointer)INSTANTIATE(ctx,1,local+19); /*instantiate*/
	local[11] = w;
	local[19]= local[11];
	goto CON13602;
CON13604:
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(pointer)GETCLASS(ctx,1,local+19); /*class*/
	local[6] = w;
	local[19]= local[6];
	goto CON13602;
CON13658:
	local[19]= NIL;
CON13602:
	local[19]= *(ovafptr(local[0],fqv[138]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[12] = w;
	local[19]= *(ovafptr(local[0],fqv[139]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[13] = w;
	local[19]= *(ovafptr(local[0],fqv[140]));
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[14] = w;
	local[19]= NIL;
	local[20]= local[9];
WHL13719:
	if (local[20]==NIL) goto WHX13720;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	w = local[19];
	if (!iscons(w)) goto CON13770;
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	local[22]= local[12];
	ctx->vsp=local+23;
	w=(pointer)F4420member(ctx,2,local+21); /*member*/
	if (w==NIL) goto IF13776;
	local[21]= fqv[141];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto IF13777;
IF13776:
	local[21]= NIL;
IF13777:
	w=local[19];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w = local[12];
	ctx->vsp=local+22;
	local[12] = cons(ctx,local[21],w);
	local[21]= fqv[142];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)F4444position(ctx,2,local+21); /*position*/
	local[18] = w;
	if (local[18]==NIL) goto IF13823;
	local[21]= local[19];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	goto IF13824;
IF13823:
	local[21]= T;
IF13824:
	w = local[13];
	ctx->vsp=local+22;
	local[13] = cons(ctx,local[21],w);
	local[21]= fqv[143];
	local[22]= local[19];
	ctx->vsp=local+23;
	w=(pointer)F4444position(ctx,2,local+21); /*position*/
	local[18] = w;
	if (local[18]==NIL) goto IF13857;
	local[21]= local[19];
	local[22]= local[18];
	ctx->vsp=local+23;
	w=(pointer)ADD1(ctx,1,local+22); /*1+*/
	local[22]= w;
	ctx->vsp=local+23;
	w=(pointer)ELT(ctx,2,local+21); /*elt*/
	local[21]= w;
	goto IF13858;
IF13857:
	local[21]= NIL;
IF13858:
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto CON13768;
CON13770:
	w = local[19];
	if (!issymbol(w)) goto CON13874;
	local[21]= local[19];
	local[22]= local[12];
	ctx->vsp=local+23;
	w=(pointer)F4420member(ctx,2,local+21); /*member*/
	if (w==NIL) goto IF13880;
	local[21]= fqv[144];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto IF13881;
IF13880:
	local[21]= NIL;
IF13881:
	local[21]= local[19];
	w = local[12];
	ctx->vsp=local+22;
	local[12] = cons(ctx,local[21],w);
	local[21]= T;
	w = local[13];
	ctx->vsp=local+22;
	local[13] = cons(ctx,local[21],w);
	local[21]= NIL;
	w = local[14];
	ctx->vsp=local+22;
	local[14] = cons(ctx,local[21],w);
	local[21]= local[14];
	goto CON13768;
CON13874:
	local[21]= fqv[145];
	ctx->vsp=local+22;
	w=(pointer)SIGERROR(ctx,1,local+21); /*error*/
	local[21]= w;
	goto CON13768;
CON13924:
	local[21]= NIL;
CON13768:
	goto WHL13719;
WHX13720:
	local[21]= NIL;
BLK13721:
	w = NIL;
	local[19]= local[12];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[12] = w;
	local[19]= local[13];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[13] = w;
	local[19]= local[14];
	ctx->vsp=local+20;
	w=(pointer)NREVERSE(ctx,1,local+19); /*nreverse*/
	local[19]= w;
	local[20]= loadglobal(fqv[146]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[14] = w;
	local[19]= local[7];
	local[20]= fqv[147];
	ctx->vsp=local+21;
	w=(pointer)ASSQ(ctx,2,local+19); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	if (local[15]!=NIL) goto IF13978;
	local[19]= local[6];
	local[20]= loadglobal(fqv[148]);
	ctx->vsp=local+21;
	w=(pointer)SUBCLASSP(ctx,2,local+19); /*subclassp*/
	if (w==NIL) goto IF13986;
	local[19]= local[0]->c.obj.iv[8];
	goto IF13987;
IF13986:
	local[19]= makeint((eusinteger_t)0L);
IF13987:
	local[15] = local[19];
	local[19]= local[15];
	goto IF13979;
IF13978:
	local[19]= NIL;
IF13979:
	local[19]= argv[0];
	*(ovafptr(local[11],fqv[149])) = local[19];
	local[19]= local[12];
	*(ovafptr(local[11],fqv[138])) = local[19];
	local[19]= local[13];
	*(ovafptr(local[11],fqv[139])) = local[19];
	local[19]= local[14];
	*(ovafptr(local[11],fqv[140])) = local[19];
	local[19]= local[0];
	local[20]= local[19];
	*(ovafptr(local[11],fqv[128])) = local[20];
	local[19]= local[6];
	local[20]= loadglobal(fqv[148]);
	ctx->vsp=local+21;
	w=(pointer)SUBCLASSP(ctx,2,local+19); /*subclassp*/
	if (w==NIL) goto IF14022;
	local[19]= local[15];
	*(ovafptr(local[11],fqv[150])) = local[19];
	local[19]= local[8];
	local[20]= local[19];
	*(ovafptr(local[11],fqv[151])) = local[20];
	goto IF14023;
IF14022:
	local[19]= NIL;
IF14023:
	if (*(ovafptr(local[11],fqv[152]))!=NIL) goto IF14040;
	local[19]= local[11];
	ctx->vsp=local+20;
	w=(*ftab[2])(ctx,1,local+19,&ftab[2],fqv[153]); /*enter-class*/
	local[19]= w;
	goto IF14041;
IF14040:
	local[19]= NIL;
IF14041:
	local[19]= local[11];
	local[20]= local[10];
	local[21]= fqv[154];
	ctx->vsp=local+22;
	w=(pointer)PUTPROP(ctx,3,local+19); /*putprop*/
	local[19]= local[12];
	local[20]= loadglobal(fqv[19]);
	ctx->vsp=local+21;
	w=(pointer)COERCE(ctx,2,local+19); /*coerce*/
	local[12] = w;
	local[19]= NIL;
	local[20]= local[12];
WHL14086:
	if (local[20]==NIL) goto WHX14087;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21]= (w)->c.cons.car;
	w=local[20];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[20] = (w)->c.cons.cdr;
	w = local[21];
	local[19] = w;
	local[21]= loadglobal(fqv[155]);
	local[22]= argv[0];
	ctx->vsp=local+23;
	w=(pointer)F4311string(ctx,1,local+22); /*string*/
	local[22]= w;
	local[23]= fqv[156];
	local[24]= local[19];
	ctx->vsp=local+25;
	w=(pointer)F4311string(ctx,1,local+24); /*string*/
	local[24]= w;
	ctx->vsp=local+25;
	w=(pointer)CONCATENATE(ctx,4,local+21); /*concatenate*/
	local[21]= w;
	ctx->vsp=local+22;
	w=(pointer)INTERN(ctx,1,local+21); /*intern*/
	local[17] = w;
	local[21]= local[17];
	local[22]= fqv[157];
	local[23]= fqv[158];
	ctx->vsp=local+24;
	w=(pointer)LIST(ctx,1,local+23); /*list*/
	local[23]= w;
	local[24]= fqv[66];
	local[25]= fqv[33];
	local[26]= fqv[159];
	ctx->vsp=local+27;
	w=(pointer)LIST(ctx,1,local+26); /*list*/
	ctx->vsp=local+26;
	local[25]= cons(ctx,local[25],w);
	local[26]= fqv[158];
	local[27]= fqv[33];
	local[28]= argv[0];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	local[27]= cons(ctx,local[27],w);
	local[28]= local[16];
	ctx->vsp=local+29;
	w=(pointer)LIST(ctx,1,local+28); /*list*/
	ctx->vsp=local+28;
	w = cons(ctx,local[27],w);
	ctx->vsp=local+27;
	w = cons(ctx,local[26],w);
	ctx->vsp=local+26;
	w = cons(ctx,local[25],w);
	ctx->vsp=local+25;
	local[24]= cons(ctx,local[24],w);
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	local[22]= cons(ctx,local[22],w);
	ctx->vsp=local+23;
	w=(pointer)SETFUNC(ctx,2,local+21); /*setfunc*/
	local[21]= local[16];
	ctx->vsp=local+22;
	w=(pointer)ADD1(ctx,1,local+21); /*1+*/
	local[16] = w;
	goto WHL14086;
WHX14087:
	local[21]= NIL;
BLK14088:
	w = NIL;
	w = local[11];
	local[0]= w;
BLK13464:
	ctx->vsp=local; return(local[0]);}

/*defstruct*/
static pointer F14222(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST14225:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[6];
	local[2]= fqv[32];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[38];
	local[5]= fqv[160];
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[161];
	local[8]= fqv[33];
	local[9]= local[0];
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
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[33];
	local[4]= argv[0];
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
	local[0]= w;
BLK14223:
	ctx->vsp=local; return(local[0]);}

/*defclass*/
static pointer F14304(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[162], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY14320;
	local[0] = NIL;
KEY14320:
	if (n & (1<<1)) goto KEY14325;
	local[1] = fqv[136];
KEY14325:
	if (n & (1<<2)) goto KEY14332;
	local[2] = makeint((eusinteger_t)-1L);
KEY14332:
	if (n & (1<<3)) goto KEY14337;
	local[3] = NIL;
KEY14337:
	if (n & (1<<4)) goto KEY14342;
	local[4] = NIL;
KEY14342:
	if (n & (1<<5)) goto KEY14347;
	local[5] = NIL;
KEY14347:
	if (n & (1<<6)) goto KEY14352;
	local[6] = local[5];
KEY14352:
	local[7]= fqv[6];
	local[8]= fqv[32];
	local[9]= fqv[33];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[38];
	local[11]= fqv[160];
	local[12]= fqv[33];
	local[13]= argv[0];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	local[13]= fqv[163];
	local[14]= local[1];
	local[15]= fqv[161];
	local[16]= fqv[33];
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(pointer)LIST(ctx,1,local+17); /*list*/
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
	local[17]= fqv[164];
	local[18]= local[3];
	local[19]= fqv[106];
	local[20]= local[4];
	local[21]= fqv[165];
	local[22]= local[2];
	local[23]= fqv[166];
	local[24]= local[6];
	ctx->vsp=local+25;
	w=(pointer)LIST(ctx,1,local+24); /*list*/
	ctx->vsp=local+24;
	w = cons(ctx,local[23],w);
	ctx->vsp=local+23;
	w = cons(ctx,local[22],w);
	ctx->vsp=local+22;
	w = cons(ctx,local[21],w);
	ctx->vsp=local+21;
	w = cons(ctx,local[20],w);
	ctx->vsp=local+20;
	w = cons(ctx,local[19],w);
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	w = cons(ctx,local[16],w);
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	w = cons(ctx,local[9],w);
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[33];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	local[0]= w;
BLK14305:
	ctx->vsp=local; return(local[0]);}

/*readtablep*/
static pointer F4565readtablep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[167]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14477:
	ctx->vsp=local; return(local[0]);}

/*copy-readtable*/
static pointer F4568copy_readtable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT14498;}
	local[0]= loadglobal(fqv[168]);
ENT14498:
	if (n>=2) { local[1]=(argv[1]); goto ENT14497;}
	local[1]= NIL;
ENT14497:
ENT14496:
	if (n>2) maerror();
	if (local[0]!=NIL) goto IF14517;
	local[0] = loadglobal(fqv[169]);
	local[2]= local[0];
	goto IF14518;
IF14517:
	local[2]= NIL;
IF14518:
	if (local[1]!=NIL) goto IF14535;
	local[2]= loadglobal(fqv[167]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[1] = w;
	local[2]= loadglobal(fqv[155]);
	local[3]= makeint((eusinteger_t)256L);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[1] = local[3];
	local[2]= loadglobal(fqv[146]);
	local[3]= makeint((eusinteger_t)256L);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[2] = local[3];
	local[2]= loadglobal(fqv[146]);
	local[3]= makeint((eusinteger_t)256L);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= w;
	w = local[1];
	w->c.obj.iv[3] = local[3];
	goto IF14536;
IF14535:
	local[2]= NIL;
IF14536:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F4565readtablep(ctx,1,local+2); /*readtablep*/
	if (w==NIL) goto OR14583;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F4565readtablep(ctx,1,local+2); /*readtablep*/
	if (w==NIL) goto OR14583;
	goto IF14581;
OR14583:
	local[2]= fqv[170];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF14582;
IF14581:
	local[2]= NIL;
IF14582:
	local[2]= local[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)F4489replace(ctx,2,local+2); /*replace*/
	local[2]= local[1]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)F4489replace(ctx,2,local+2); /*replace*/
	local[2]= local[1]->c.obj.iv[3];
	local[3]= local[0]->c.obj.iv[3];
	ctx->vsp=local+4;
	w=(pointer)F4489replace(ctx,2,local+2); /*replace*/
	local[2]= local[0]->c.obj.iv[4];
	local[3]= local[2];
	w = local[1];
	w->c.obj.iv[4] = local[3];
	w = local[1];
	local[0]= w;
BLK14494:
	ctx->vsp=local; return(local[0]);}

/*set-syntax-from-char*/
static pointer F4571set_syntax_from_char(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT14657;}
	local[0]= loadglobal(fqv[168]);
ENT14657:
	if (n>=4) { local[1]=(argv[3]); goto ENT14656;}
	local[1]= loadglobal(fqv[169]);
ENT14656:
ENT14655:
	if (n>4) maerror();
	local[2]= NIL;
	local[3]= local[1]->c.obj.iv[1];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[2] = w;
	local[3]= local[0]->c.obj.iv[1];
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= local[2];
	if (makeint((eusinteger_t)7L)==local[3]) goto OR14715;
	local[3]= local[2];
	if (makeint((eusinteger_t)8L)==local[3]) goto OR14715;
	goto IF14713;
OR14715:
	local[3]= local[0]->c.obj.iv[2];
	local[4]= argv[0];
	local[5]= local[1]->c.obj.iv[2];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ASET(ctx,3,local+3); /*aset*/
	local[3]= w;
	goto IF14714;
IF14713:
	local[3]= NIL;
IF14714:
	w = local[2];
	local[0]= w;
BLK14653:
	ctx->vsp=local; return(local[0]);}

/*keywordp*/
static pointer F4576keywordp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND14764;
	local[0]= argv[0]->c.obj.iv[5];
	local[0]= ((loadglobal(fqv[171]))==(local[0])?T:NIL);
AND14764:
	w = local[0];
	local[0]= w;
BLK14748:
	ctx->vsp=local; return(local[0]);}

/*constantp*/
static pointer F4579constantp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF14798;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4576keywordp(ctx,1,local+0); /*keywordp*/
	if (w!=NIL) goto OR14806;
	local[0]= argv[0]->c.obj.iv[2];
	if (makeint((eusinteger_t)0L)==local[0]) goto OR14806;
	goto IF14804;
OR14806:
	local[0]= T;
	goto IF14805;
IF14804:
	local[0]= NIL;
IF14805:
	goto IF14799;
IF14798:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF14818;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[33]!=local[0]) goto IF14826;
	local[0]= T;
	goto IF14827;
IF14826:
	local[0]= NIL;
IF14827:
	goto IF14819;
IF14818:
	w = argv[0];
	if (!!iscons(w)) goto IF14838;
	local[0]= T;
	goto IF14839;
IF14838:
	local[0]= NIL;
IF14839:
IF14819:
IF14799:
	w = local[0];
	local[0]= w;
BLK14782:
	ctx->vsp=local; return(local[0]);}

/*functionp*/
static pointer F4582functionp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isnum(w)) goto CON14858;
	local[0]= NIL;
	goto CON14856;
CON14858:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON14863;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w = fqv[172];
	if (memq(local[0],w)!=NIL) goto OR14873;
	goto IF14871;
OR14873:
	local[0]= T;
	goto IF14872;
IF14871:
	local[0]= NIL;
IF14872:
	goto CON14856;
CON14863:
	local[0]= argv[0];
	local[1]= loadglobal(fqv[173]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto CON14887;
	local[0]= argv[0]->c.obj.iv[2];
	local[0]= ((makeint((eusinteger_t)0L))==(local[0])?T:NIL);
	goto CON14856;
CON14887:
	w = argv[0];
	if (!issymbol(w)) goto CON14904;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto CON14904;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F4582functionp(ctx,1,local+0); /*functionp*/
	local[0]= w;
	goto CON14856;
CON14904:
	local[0]= NIL;
	goto CON14856;
CON14920:
	local[0]= NIL;
CON14856:
	w = local[0];
	local[0]= w;
BLK14846:
	ctx->vsp=local; return(local[0]);}

/*vector-class-p*/
static pointer F4585vector_class_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[148]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14926:
	ctx->vsp=local; return(local[0]);}

/*compiled-function-p*/
static pointer F4588compiled_function_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[173]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK14942:
	ctx->vsp=local; return(local[0]);}

/*input-stream-p*/
static pointer F4591input_stream_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[174]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND14978;
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((fqv[175])==(local[0])?T:NIL);
AND14978:
	if (local[0]!=NIL) goto OR14974;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
OR14974:
	w = local[0];
	local[0]= w;
BLK14958:
	ctx->vsp=local; return(local[0]);}

/*output-stream-p*/
static pointer F4594output_stream_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[174]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
	if (w==NIL) goto AND15023;
	local[0]= argv[0]->c.obj.iv[1];
	local[0]= ((fqv[177])==(local[0])?T:NIL);
AND15023:
	if (local[0]!=NIL) goto OR15019;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
OR15019:
	w = local[0];
	local[0]= w;
BLK15003:
	ctx->vsp=local; return(local[0]);}

/*io-stream-p*/
static pointer F4597io_stream_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[176]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK15046:
	ctx->vsp=local; return(local[0]);}

/*special-form-p*/
static pointer F4600special_form_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND15072;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND15072;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	argv[0] = w;
	local[0]= argv[0];
	if (local[0]==NIL) goto AND15072;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4588compiled_function_p(ctx,1,local+0); /*compiled-function-p*/
	local[0]= w;
	if (w==NIL) goto AND15072;
	local[0]= *(ovafptr(argv[0],fqv[178]));
	local[0]= ((makeint((eusinteger_t)2L))==(local[0])?T:NIL);
AND15072:
	w = local[0];
	local[0]= w;
BLK15062:
	ctx->vsp=local; return(local[0]);}

/*macro-function*/
static pointer F4603macro_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	local[0]= (issymbol(w)?T:NIL);
	if (local[0]==NIL) goto AND15118;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	local[0]= w;
	if (w==NIL) goto AND15118;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)SYMFUNC(ctx,1,local+0); /*symbol-function*/
	argv[0] = w;
	local[0]= argv[0];
	if (local[0]==NIL) goto AND15118;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4588compiled_function_p(ctx,1,local+0); /*compiled-function-p*/
	if (w==NIL) goto IF15142;
	local[0]= *(ovafptr(argv[0],fqv[178]));
	if (makeint((eusinteger_t)1L)!=local[0]) goto IF15142;
	local[0]= argv[0];
	goto IF15143;
IF15142:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF15156;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[157]!=local[0]) goto IF15156;
	local[0]= argv[0];
	goto IF15157;
IF15156:
	local[0]= NIL;
IF15157:
IF15143:
AND15118:
	w = local[0];
	local[0]= w;
BLK15108:
	ctx->vsp=local; return(local[0]);}

/*zerop*/
static pointer F4606zerop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
BLK15177:
	ctx->vsp=local; return(local[0]);}

/*plusp*/
static pointer F4609plusp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
BLK15192:
	ctx->vsp=local; return(local[0]);}

/*minusp*/
static pointer F4612minusp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
BLK15207:
	ctx->vsp=local; return(local[0]);}

/*oddp*/
static pointer F4615oddp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGBITP(ctx,2,local+0); /*logbitp*/
	local[0]= w;
BLK15222:
	ctx->vsp=local; return(local[0]);}

/*evenp*/
static pointer F4618evenp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOGBITP(ctx,2,local+0); /*logbitp*/
	w = ((w)==NIL?T:NIL);
	local[0]= w;
BLK15237:
	ctx->vsp=local; return(local[0]);}

/*logandc1*/
static pointer F4621logandc1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LOGNOT(ctx,1,local+0); /*lognot*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	local[0]= w;
BLK15256:
	ctx->vsp=local; return(local[0]);}

/*logandc2*/
static pointer F4624logandc2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LOGNOT(ctx,1,local+1); /*lognot*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LOGAND(ctx,2,local+0); /*logand*/
	local[0]= w;
BLK15278:
	ctx->vsp=local; return(local[0]);}

/*ecase*/
static pointer F15300(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST15303:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= fqv[179];
	w = local[0];
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK15301:
	ctx->vsp=local; return(local[0]);}

/*every*/
static pointer F4628every(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST15323:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]!=NIL) goto CON15338;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON15338;
WHL15350:
	if (argv[1]==NIL) goto WHX15351;
	local[1]= argv[0];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	if (w!=NIL) goto IF15359;
	w = NIL;
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK15321;
	goto IF15360;
IF15359:
	local[1]= NIL;
IF15360:
	goto WHL15350;
WHX15351:
	local[1]= NIL;
BLK15352:
	goto CON15336;
CON15338:
	local[1]= argv[1];
	w = local[0];
	ctx->vsp=local+2;
	argv[1] = cons(ctx,local[1],w);
	local[1]= makeint((eusinteger_t)0L);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
WHL15451:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX15452;
	local[3]= argv[0];
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO15468,env,argv,local);
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,2,local+3); /*apply*/
	if (w!=NIL) goto IF15461;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK15321;
	goto IF15462;
IF15461:
	local[3]= NIL;
IF15462:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL15451;
WHX15452:
	local[3]= NIL;
BLK15453:
	w = NIL;
	local[1]= w;
	goto CON15336;
CON15407:
	local[1]= NIL;
CON15336:
	w = T;
	local[0]= w;
BLK15321:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO15468(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[1];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*some*/
static pointer F4631some(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST15513:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[1];
	w = local[0];
	ctx->vsp=local+4;
	argv[1] = cons(ctx,local[3],w);
	local[3]= makeint((eusinteger_t)0L);
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL15570:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX15571;
	local[5]= argv[0];
	ctx->vsp=local+6;
	local[6]= makeclosure(codevec,quotevec,CLO15588,env,argv,local);
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)MAPCAR(ctx,2,local+6); /*mapcar*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)APPLY(ctx,2,local+5); /*apply*/
	local[2] = w;
	if (local[2]==NIL) goto IF15579;
	w = local[2];
	ctx->vsp=local+5;
	local[0]=w;
	goto BLK15511;
	goto IF15580;
IF15579:
	local[5]= NIL;
IF15580:
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL15570;
WHX15571:
	local[5]= NIL;
BLK15572:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK15511:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO15588(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= env->c.clo.env2[3];
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*reduce*/
static pointer F4636reduce(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[180], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY15648;
	local[0] = makeint((eusinteger_t)0L);
KEY15648:
	if (n & (1<<1)) goto KEY15653;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[1] = w;
KEY15653:
	if (n & (1<<2)) goto KEY15661;
	local[2] = NIL;
KEY15661:
	if (n & (1<<3)) goto KEY15666;
	local[3] = NIL;
KEY15666:
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)MINUS(ctx,2,local+4); /*-*/
	local[4]= w;
	if (local[2]==NIL) goto IF15692;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)REVERSE(ctx,1,local+5); /*reverse*/
	argv[1] = w;
	local[5]= argv[1];
	goto IF15693;
IF15692:
	local[5]= NIL;
IF15693:
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON15712;
	if (local[3]!=NIL) goto CON15712;
	local[5]= argv[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	goto CON15710;
CON15712:
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)NUMEQUAL(ctx,2,local+5); /*=*/
	if (w==NIL) goto CON15725;
	if (local[3]==NIL) goto IF15731;
	local[5]= local[3];
	goto IF15732;
IF15731:
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,1,local+5); /*funcall*/
	local[5]= w;
IF15732:
	goto CON15710;
CON15725:
	if (local[3]!=NIL) goto IF15745;
	local[5]= argv[0];
	local[6]= argv[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ELT(ctx,2,local+6); /*elt*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[0] = w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,3,local+5); /*funcall*/
	local[3] = w;
	local[5]= local[4];
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[4] = w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[0] = w;
	local[5]= local[0];
	goto IF15746;
IF15745:
	local[5]= NIL;
IF15746:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[4];
WHL15824:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX15825;
	local[7]= argv[0];
	local[8]= local[3];
	local[9]= argv[1];
	local[10]= local[0];
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	local[3] = w;
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL15824;
WHX15825:
	local[7]= NIL;
BLK15826:
	w = NIL;
	local[5]= local[3];
	goto CON15710;
CON15740:
	local[5]= NIL;
CON15710:
	w = local[5];
	local[0]= w;
BLK15634:
	ctx->vsp=local; return(local[0]);}

/*merge-list*/
static pointer F4639merge_list(ctx,n,argv,env)
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
WHL15898:
	if (argv[1]==NIL) goto WHX15899;
	local[7]= argv[2];
	local[8]= argv[3];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[8]= w;
	local[9]= argv[3];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)FUNCALL(ctx,2,local+9); /*funcall*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	if (w!=NIL) goto WHX15899;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[1] = (w)->c.cons.cdr;
	w = local[7];
	local[7]= w;
	w = local[1];
	ctx->vsp=local+8;
	local[1] = cons(ctx,local[7],w);
	goto WHL15898;
WHX15899:
	local[7]= NIL;
BLK15900:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	local[1] = w;
	local[2] = argv[0];
WHL15990:
	if (argv[1]==NIL) goto WHX15991;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto WHX15991;
	local[7]= argv[3];
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)FUNCALL(ctx,2,local+7); /*funcall*/
	local[4] = w;
WHL16020:
	if (local[2]==NIL) goto WHX16021;
	local[7]= argv[2];
	local[8]= argv[3];
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,2,local+8); /*funcall*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)FUNCALL(ctx,3,local+7); /*funcall*/
	if (w==NIL) goto WHX16021;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[7];
	goto WHL16020;
WHX16021:
	local[7]= NIL;
BLK16022:
	if (local[2]==NIL) goto IF16082;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w=argv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	local[7]= local[2];
	local[8]= argv[1];
	ctx->vsp=local+9;
	w=(pointer)RPLACD2(ctx,2,local+7); /*rplacd2*/
	local[7]= argv[1];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)RPLACD2(ctx,2,local+7); /*rplacd2*/
	local[2] = argv[1];
	argv[1] = local[6];
	local[7]= argv[1];
	goto IF16083;
IF16082:
	local[7]= NIL;
IF16083:
	goto WHL15990;
WHX15991:
	local[7]= NIL;
BLK15992:
	local[7]= local[1];
	local[8]= argv[0];
	local[9]= argv[1];
	ctx->vsp=local+10;
	w=(pointer)NCONC(ctx,3,local+7); /*nconc*/
	local[0]= w;
BLK15868:
	ctx->vsp=local; return(local[0]);}

/*merge*/
static pointer F4642merge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[181], &argv[4], n-4, local+0, 0);
	if (n & (1<<0)) goto KEY16163;
	local[0] = (pointer)get_sym_func(fqv[82]);
KEY16163:
	local[1]= argv[0];
	if (loadglobal(fqv[19])!=local[1]) goto IF16174;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF16174;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto IF16174;
	local[1]= argv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F4639merge_list(ctx,4,local+1); /*merge-list*/
	local[1]= w;
	goto IF16175;
IF16174:
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)F4483make_sequence(ctx,2,local+4); /*make-sequence*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	local[7]= makeint((eusinteger_t)0L);
	local[8]= NIL;
	local[9]= NIL;
	local[10]= NIL;
WHL16240:
	local[11]= local[7];
	local[12]= local[3];
	ctx->vsp=local+13;
	w=(pointer)LESSP(ctx,2,local+11); /*<*/
	if (w==NIL) goto WHX16241;
	local[11]= local[5];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto CON16251;
	local[11]= argv[2];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[10] = w;
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[6] = w;
	local[11]= local[6];
	goto CON16249;
CON16251:
	local[11]= local[6];
	local[12]= local[2];
	ctx->vsp=local+13;
	w=(pointer)GREQP(ctx,2,local+11); /*>=*/
	if (w==NIL) goto CON16276;
	local[11]= argv[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[10] = w;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[5] = w;
	local[11]= local[5];
	goto CON16249;
CON16276:
	local[11]= argv[1];
	local[12]= local[5];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[8] = w;
	local[11]= argv[2];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)ELT(ctx,2,local+11); /*elt*/
	local[9] = w;
	local[11]= argv[3];
	local[12]= local[0];
	local[13]= local[8];
	ctx->vsp=local+14;
	w=(pointer)FUNCALL(ctx,2,local+12); /*funcall*/
	local[12]= w;
	local[13]= local[0];
	local[14]= local[9];
	ctx->vsp=local+15;
	w=(pointer)FUNCALL(ctx,2,local+13); /*funcall*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)FUNCALL(ctx,3,local+11); /*funcall*/
	if (w==NIL) goto IF16321;
	local[11]= local[5];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[5] = w;
	local[10] = local[8];
	local[11]= local[10];
	goto IF16322;
IF16321:
	local[11]= local[6];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[6] = w;
	local[10] = local[9];
	local[11]= local[10];
IF16322:
	goto CON16249;
CON16301:
	local[11]= NIL;
CON16249:
	local[11]= local[4];
	local[12]= local[7];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)SETELT(ctx,3,local+11); /*setelt*/
	local[11]= local[7];
	ctx->vsp=local+12;
	w=(pointer)ADD1(ctx,1,local+11); /*1+*/
	local[7] = w;
	goto WHL16240;
WHX16241:
	local[11]= NIL;
BLK16242:
	w = local[4];
	local[1]= w;
IF16175:
	w = local[1];
	local[0]= w;
BLK16148:
	ctx->vsp=local; return(local[0]);}

/*expt*/
static pointer F4645expt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[1];
	if (!isint(w)) goto CON16412;
	local[0]= argv[1];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	if (w==NIL) goto CON16412;
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F4606zerop(ctx,1,local+0); /*zerop*/
	if (w==NIL) goto IF16422;
	local[0]= makeint((eusinteger_t)1L);
	goto IF16423;
IF16422:
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)1L);
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	local[2]= w;
WHL16457:
	local[3]= local[2];
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[3] <= (eusinteger_t)w) goto WHX16458;
	local[3]= local[2];
	w = local[1];
	if ((eusinteger_t)local[3] <= (eusinteger_t)w) goto CON16467;
	local[3]= local[0];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[0] = w;
	local[3]= local[2];
	w = local[1];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[2] = (pointer)((eusinteger_t)local[3] - (eusinteger_t)w);
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ASH(ctx,2,local+3); /*ash*/
	local[1] = w;
	local[3]= local[1];
	goto CON16465;
CON16467:
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[0] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[2] = w;
	local[3]= local[2];
	goto CON16465;
CON16499:
	local[3]= NIL;
CON16465:
	goto WHL16457;
WHX16458:
	local[3]= NIL;
BLK16459:
	w = local[0];
	local[0]= w;
IF16423:
	goto CON16410;
CON16412:
	local[0]= argv[1];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LOG(ctx,1,local+1); /*log*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)EXP(ctx,1,local+0); /*exp*/
	local[0]= w;
	goto CON16410;
CON16522:
	local[0]= NIL;
CON16410:
	w = local[0];
	local[0]= w;
BLK16398:
	ctx->vsp=local; return(local[0]);}

/*signum*/
static pointer F4648signum(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F4606zerop(ctx,1,local+0); /*zerop*/
	if (w==NIL) goto IF16548;
	local[0]= argv[0];
	goto IF16549;
IF16548:
	local[0]= argv[0];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)ABS(ctx,1,local+1); /*abs*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
IF16549:
	w = local[0];
	local[0]= w;
BLK16538:
	ctx->vsp=local; return(local[0]);}

/*rad2deg*/
static pointer F4651rad2deg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(3.6000000000000000000000e+02);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(6.2831853071795862319959e+00);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK16565:
	ctx->vsp=local; return(local[0]);}

/*deg2rad*/
static pointer F4654deg2rad(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeflt(6.2831853071795862319959e+00);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)TIMES(ctx,2,local+0); /***/
	local[0]= w;
	local[1]= makeflt(3.6000000000000000000000e+02);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK16585:
	ctx->vsp=local; return(local[0]);}

/*defsetf*/
static pointer F16604(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST16607:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.car==NIL) goto CON16620;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (issymbol(w)) goto OR16629;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4582functionp(ctx,1,local+1); /*functionp*/
	if (w!=NIL) goto OR16629;
	goto CON16620;
OR16629:
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[183];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[186];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[182];
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)ENDP(ctx,1,local+7); /*endp*/
	if (w!=NIL) goto IF16755;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (isstring(w)) goto IF16771;
	local[7]= fqv[187];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF16772;
IF16771:
	local[7]= NIL;
IF16772:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.cdr;
	ctx->vsp=local+8;
	w=(pointer)ENDP(ctx,1,local+7); /*endp*/
	if (w!=NIL) goto IF16790;
	local[7]= fqv[188];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,1,local+7); /*error*/
	local[7]= w;
	goto IF16791;
IF16790:
	local[7]= NIL;
IF16791:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	goto IF16756;
IF16755:
	local[7]= NIL;
IF16756:
	local[8]= fqv[33];
	local[9]= fqv[189];
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
	local[6]= fqv[33];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON16618;
CON16620:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,1,local+1,&ftab[3],fqv[190]); /*list-length*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w!=NIL) goto IF16854;
	local[1]= fqv[191];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF16855;
IF16854:
	local[1]= NIL;
IF16855:
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[33];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[183];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[186];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
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
	local[1]= cons(ctx,local[1],w);
	goto CON16618;
CON16849:
	local[1]= NIL;
CON16618:
	w = local[1];
	local[0]= w;
BLK16605:
	ctx->vsp=local; return(local[0]);}

/*define-setf-method*/
static pointer F16980(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST16983:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[6];
	local[2]= fqv[182];
	local[3]= fqv[33];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[124];
	local[5]= fqv[192];
	local[6]= local[0];
	local[7]= NIL;
	ctx->vsp=local+8;
	w=(pointer)APPEND(ctx,2,local+6); /*append*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[186];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	local[3]= fqv[184];
	local[4]= fqv[33];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	local[4]= fqv[184];
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[33];
	local[7]= fqv[183];
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[33];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
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
BLK16981:
	ctx->vsp=local; return(local[0]);}

/*setf-expand-1*/
static pointer F4656setf_expand_1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F4266macroexpand(ctx,1,local+1); /*macroexpand*/
	argv[0] = w;
	w = argv[0];
	if (!iscons(w)) goto CON17138;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[193]!=local[1]) goto CON17138;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[193];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)F4656setf_expand_1(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17136;
CON17138:
	w = argv[0];
	if (!issymbol(w)) goto CON17181;
	local[1]= fqv[28];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17136;
CON17181:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto CON17197;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[183];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17197;
	local[1]= local[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.cdr;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17136;
CON17197:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (!issymbol(w)) goto CON17236;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[194];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17236;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	if (w==NIL) goto CON17236;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[66]==local[1]) goto CON17236;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	if (fqv[146]==local[1]) goto CON17236;
	local[1]= fqv[195];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[33];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17136;
CON17236:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4603macro_function(ctx,1,local+1); /*macro-function*/
	if (w==NIL) goto CON17330;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F4266macroexpand(ctx,1,local+1); /*macroexpand*/
	local[1]= w;
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F4656setf_expand_1(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17136;
CON17330:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= fqv[185];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0] = w;
	if (local[0]==NIL) goto CON17347;
	local[1]= fqv[196];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,2,local+2); /*append*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)APPEND(ctx,3,local+1); /*append*/
	local[1]= w;
	local[2]= argv[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	goto CON17136;
CON17347:
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON17136;
CON17400:
	local[1]= NIL;
CON17136:
	w = local[1];
	local[0]= w;
BLK17106:
	ctx->vsp=local; return(local[0]);}

/*setf-expand*/
static pointer F4658setf_expand(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)ENDP(ctx,1,local+0); /*endp*/
	if (w==NIL) goto CON17420;
	local[0]= NIL;
	goto CON17418;
CON17420:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	ctx->vsp=local+1;
	w=(pointer)ENDP(ctx,1,local+0); /*endp*/
	if (w==NIL) goto CON17427;
	local[0]= fqv[198];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON17418;
CON17427:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)F4656setf_expand_1(ctx,2,local+0); /*setf-expand-1*/
	local[0]= w;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)F4658setf_expand(ctx,1,local+1); /*setf-expand*/
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	goto CON17418;
CON17441:
	local[0]= NIL;
CON17418:
	w = local[0];
	local[0]= w;
BLK17408:
	ctx->vsp=local; return(local[0]);}

/*setf*/
static pointer F17471(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST17474:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17485;
	local[1]= NIL;
	goto CON17483;
CON17485:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17492;
	local[1]= fqv[199];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto CON17483;
CON17492:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.cdr;
	ctx->vsp=local+2;
	w=(pointer)ENDP(ctx,1,local+1); /*endp*/
	if (w==NIL) goto CON17506;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)F4656setf_expand_1(ctx,2,local+1); /*setf-expand-1*/
	local[1]= w;
	goto CON17483;
CON17506:
	local[1]= fqv[6];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F4658setf_expand(ctx,1,local+2); /*setf-expand*/
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	goto CON17483;
CON17533:
	local[1]= NIL;
CON17483:
	w = local[1];
	local[0]= w;
BLK17472:
	ctx->vsp=local; return(local[0]);}

/*multiple-value-bind*/
static pointer F17545(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST17548:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= fqv[200];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= NIL;
	local[5]= argv[0];
WHL17592:
	if (local[5]==NIL) goto WHX17593;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	local[7]= fqv[55];
	local[8]= local[1];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,2,local+6); /*list*/
	local[6]= w;
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[3] = w;
	goto WHL17592;
WHX17593:
	local[6]= NIL;
BLK17594:
	w = NIL;
	local[4]= fqv[50];
	local[5]= local[1];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	w = local[0];
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	local[0]= w;
BLK17546:
	ctx->vsp=local; return(local[0]);}

/*multiple-value-setq*/
static pointer F17701(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= fqv[201];
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,1,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
WHL17748:
	if (local[4]==NIL) goto WHX17749;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[0];
	local[6]= fqv[202];
	ctx->vsp=local+7;
	w=(pointer)F4423assoc(ctx,2,local+5); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[0] = w;
	goto WHL17748;
WHX17749:
	local[5]= NIL;
BLK17750:
	w = NIL;
	local[3]= fqv[5];
	local[4]= local[1];
	local[5]= argv[1];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	local[5]= fqv[28];
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	local[0]= w;
BLK17702:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___common(ctx,n,argv,env)
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
	local[0]= fqv[203];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF17878;
	local[0]= fqv[204];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[49],w);
	goto IF17879;
IF17878:
	local[0]= fqv[205];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF17879:
	local[0]= fqv[206];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[207];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[208];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[209];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[210];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[211];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[212];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[213];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[214];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[215],module,F4260lisp_implementation_type,fqv[216]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[2],module,F4262lisp_implementation_version,fqv[217]);
	local[0]= NIL;
	storeglobal(fqv[218],local[0]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[219],module,F4266macroexpand,fqv[220]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[15],module,F4910,fqv[221]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[222],module,F4973,fqv[223]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[224],module,F5032,fqv[225]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[226],module,F5065,fqv[227]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[47],module,F5099,fqv[228]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[229],module,F5146,fqv[230]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[231],module,F5183,fqv[232]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[56],module,F5304,fqv[233]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[234],module,F5358,fqv[235]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[236],module,F5412,fqv[237]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[238],module,F5466,fqv[239]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[240],module,F5520,fqv[241]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[242],module,F5687,fqv[243]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[244],module,F5768,fqv[245]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[246],module,F5830,fqv[247]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[248],module,F5892,fqv[249]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[62],module,F6046,fqv[250]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[64],module,F6203,fqv[251]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[252],module,F6430,fqv[253]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[254],module,F6657,fqv[255]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[69],module,F6734,fqv[256]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[257],module,F6924,fqv[258]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[259],module,F7153,fqv[260]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[261],module,F7382,fqv[262]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[263],module,F7427,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F4295casebody,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F4298casehead,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F4301case1,fqv[270]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[179],module,F7608,fqv[271]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F4305classcasehead,fqv[273]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[274],module,F4308classcase1,fqv[275]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[276],module,F7779,fqv[277]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[155],module,F4311string,fqv[278]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[279],module,F4315alias,fqv[280]);
	local[0]= fqv[190];
	local[1]= fqv[54];
	ctx->vsp=local+2;
	w=(pointer)F4315alias(ctx,2,local+0); /*alias*/
	local[0]= fqv[281];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)F4315alias(ctx,2,local+0); /*alias*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[282],module,F4321caaar,fqv[283]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[284],module,F4324caadr,fqv[285]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[286],module,F4327cadar,fqv[287]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[288],module,F4330cdaar,fqv[289]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[290],module,F4333cdadr,fqv[291]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[292],module,F4336cddar,fqv[293]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[294],module,F4339cdddr,fqv[295]);
	local[0]= fqv[296];
	local[1]= fqv[16];
	ctx->vsp=local+2;
	w=(pointer)F4315alias(ctx,2,local+0); /*alias*/
	local[0]= fqv[297];
	local[1]= fqv[298];
	ctx->vsp=local+2;
	w=(pointer)F4315alias(ctx,2,local+0); /*alias*/
	local[0]= fqv[299];
	local[1]= fqv[300];
	ctx->vsp=local+2;
	w=(pointer)F4315alias(ctx,2,local+0); /*alias*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[301],module,F4345fourth,fqv[302]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[303],module,F4348fifth,fqv[304]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[305],module,F4351sixth,fqv[306]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[307],module,F4354seventh,fqv[308]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[309],module,F4357eighth,fqv[310]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[311],module,F4360cddddr,fqv[312]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[313],module,F4363cadddr,fqv[314]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[315],module,F4366caaddr,fqv[316]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[317],module,F4369cdaddr,fqv[318]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[319],module,F4372caddddr,fqv[320]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[321],module,F4375flatten,fqv[322]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[323],module,F4378list_insert,fqv[324]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[325],module,F4381list_delete,fqv[326]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[327],module,F4384adjoin,fqv[328]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[329],module,F4387union,fqv[330]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[331],module,F4390intersection,fqv[332]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[333],module,F4393set_difference,fqv[334]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[335],module,F4396set_exclusive_or,fqv[336]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[337],module,F4399rotate_list,fqv[338]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[339],module,F4402last,fqv[340]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[341],module,F4405copy_tree,fqv[342]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[343],module,F4408copy_list,fqv[344]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[345],module,F4411nreconc,fqv[346]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[347],module,F4414rassoc,fqv[348]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[349],module,F4417acons,fqv[350]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[22],module,F4420member,fqv[351]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[352],module,F4423assoc,fqv[353]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[354],module,F4426subsetp,fqv[355]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[356],module,F4429maplist,fqv[357]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[358],module,F4432mapcon,fqv[359]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[360],module,F4435find,fqv[361]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[362],module,F4438find_if,fqv[363]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[364],module,F4441find_if_not,fqv[365]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[366],module,F4444position,fqv[367]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[368],module,F4447position_if,fqv[369]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[370],module,F4450position_if_not,fqv[371]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[372],module,F4453count,fqv[373]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[374],module,F4456count_if,fqv[375]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[376],module,F4459count_if_not,fqv[377]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[378],module,F4462member_if,fqv[379]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[380],module,F4465member_if_not,fqv[381]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[382],module,F4468collect_if,fqv[383]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[384],module,F4471collect_instances,fqv[385]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[386],module,F4474pairlis,fqv[387]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[388],module,F4477transpose_list,fqv[389]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[390],module,F4480make_list,fqv[391]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[392],module,F4483make_sequence,fqv[393]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[394],module,F4486fill,fqv[395]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[396],module,F4489replace,fqv[397]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[398],module,F4492remove,fqv[399]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[400],module,F4495remove_if,fqv[401]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[402],module,F4498remove_if_not,fqv[403]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[404],module,F4501delete,fqv[405]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[406],module,F4504delete_if,fqv[407]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[408],module,F4507delete_if_not,fqv[409]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[410],module,F4510substitute,fqv[411]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[412],module,F4513substitute_if,fqv[413]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[414],module,F4516substitute_if_not,fqv[415]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[416],module,F4519nsubstitute,fqv[417]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[418],module,F4522nsubstitute_if,fqv[419]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[420],module,F4525nsubstitute_if_not,fqv[421]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[422],module,F4528unique,fqv[423]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[424],module,F4531remove_duplicates,fqv[425]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[426],module,F4534extream,fqv[427]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[428],module,F12815,fqv[429]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[430],module,F12875,fqv[431]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[432],module,F12929,fqv[433]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[132],module,F12973,fqv[434]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[435],module,F13005,fqv[436]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[437],module,F4543send_all,fqv[438]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[439],module,F4546resend,fqv[440]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[441],module,F13118,fqv[442]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[443],module,F13199,fqv[444]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[445],module,F4551make_instance,fqv[446]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[447],module,F13396,fqv[448]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[449],module,F4555delete_method,fqv[450]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F4558make_class,fqv[451]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[452],module,F14222,fqv[453]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[454],module,F14304,fqv[455]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[456],module,F4565readtablep,fqv[457]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[458],module,F4568copy_readtable,fqv[459]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[460],module,F4571set_syntax_from_char,fqv[461]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[462],module,F4576keywordp,fqv[463]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[464],module,F4579constantp,fqv[465]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[466],module,F4582functionp,fqv[467]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[468],module,F4585vector_class_p,fqv[469]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[470],module,F4588compiled_function_p,fqv[471]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[472],module,F4591input_stream_p,fqv[473]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[474],module,F4594output_stream_p,fqv[475]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[476],module,F4597io_stream_p,fqv[477]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[478],module,F4600special_form_p,fqv[479]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[480],module,F4603macro_function,fqv[481]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[482],module,F4606zerop,fqv[483]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[484],module,F4609plusp,fqv[485]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[486],module,F4612minusp,fqv[487]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[488],module,F4615oddp,fqv[489]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[490],module,F4618evenp,fqv[491]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[492],module,F4621logandc1,fqv[493]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[494],module,F4624logandc2,fqv[495]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[496],module,F15300,fqv[497]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[498],module,F4628every,fqv[499]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[500],module,F4631some,fqv[501]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[502],module,F4636reduce,fqv[503]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[504],module,F4639merge_list,fqv[505]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[506],module,F4642merge,fqv[507]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[508],module,F4645expt,fqv[509]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[510],module,F4648signum,fqv[511]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[512],module,F4651rad2deg,fqv[513]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[514],module,F4654deg2rad,fqv[515]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[516],module,F16604,fqv[517]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[518],module,F16980,fqv[519]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[520],module,F4656setf_expand_1,fqv[521]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[522],module,F4658setf_expand,fqv[523]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[17],module,F17471,fqv[524]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[525],module,F17545,fqv[526]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[527],module,F17701,fqv[528]);
	local[0]= fqv[281];
	local[1]= fqv[66];
	ctx->vsp=local+2;
	w=(pointer)F4315alias(ctx,2,local+0); /*alias*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<4; i++) ftab[i]=fcallx;
}
