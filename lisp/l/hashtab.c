/* ./hashtab.c :  entry=hashtab */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "hashtab.h"
#pragma init (register_hashtab)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___hashtab();
extern pointer build_quote_vector();
static int register_hashtab()
  { add_module_initializer("___hashtab", ___hashtab);}

static pointer F61397make_hash_table();
static pointer F61400gethash();
static pointer F61403sethash();
static pointer F61406remhash();
static pointer F61409hash_table_p();
static pointer F61412maphash();
static pointer F61415clrhash();

/*:size*/
static pointer M61502hash_table_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK61503:
	ctx->vsp=local; return(local[0]);}

/*:find*/
static pointer M61518hash_table_find(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ABS(ctx,1,local+0); /*abs*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
WHL61554:
	if (T==NIL) goto WHX61555;
	local[3]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[3]->c.vec.v[i]);}
	local[1] = w;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[1];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	if (w==NIL) goto IF61572;
	w = local[0];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK61519;
	goto IF61573;
IF61572:
	local[3]= NIL;
IF61573:
	local[3]= local[1];
	if (argv[0]->c.obj.iv[7]!=local[3]) goto IF61588;
	if (local[2]!=NIL) goto IF61598;
	local[2] = local[0];
	local[3]= local[2];
	goto IF61599;
IF61598:
	local[3]= NIL;
IF61599:
	local[3]= local[2];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK61519;
	goto IF61589;
IF61588:
	local[3]= NIL;
IF61589:
	local[3]= local[1];
	if (argv[0]->c.obj.iv[8]!=local[3]) goto IF61621;
	if (local[2]!=NIL) goto IF61631;
	local[2] = local[0];
	local[3]= local[2];
	goto IF61632;
IF61631:
	local[3]= NIL;
IF61632:
	goto IF61622;
IF61621:
	local[3]= NIL;
IF61622:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)GREQP(ctx,2,local+3); /*>=*/
	if (w==NIL) goto IF61644;
	local[0] = makeint((eusinteger_t)0L);
	local[3]= local[0];
	goto IF61645;
IF61644:
	local[3]= NIL;
IF61645:
	goto WHL61554;
WHX61555:
	local[3]= NIL;
BLK61556:
	w = NIL;
	local[0]= w;
BLK61519:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M61668hash_table_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF61699;
	local[1]= argv[0]->c.obj.iv[9];
	goto IF61700;
IF61699:
	local[1]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[0]);
	  w=(local[1]->c.vec.v[i]);}
	local[1]= w;
IF61700:
	w = local[1];
	local[0]= w;
BLK61669:
	ctx->vsp=local; return(local[0]);}

/*:enter*/
static pointer M61714hash_table_enter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF61748;
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= argv[0]->c.obj.iv[6];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)GREATERP(ctx,2,local+1); /*>*/
	if (w==NIL) goto IF61759;
	local[1]= argv[0];
	local[2]= fqv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= argv[0];
	local[2]= fqv[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF61760;
IF61759:
	local[1]= NIL;
IF61760:
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[0] = w;
	local[1]= local[0];
	goto IF61749;
IF61748:
	local[1]= NIL;
IF61749:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	w = argv[2];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	w = argv[3];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[2]); v=local[1];
	  v->c.vec.v[i]=w;}
	w = argv[3];
	local[0]= w;
BLK61715:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M61830hash_table_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF61865;
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	argv[0]->c.obj.iv[3] = w;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = argv[0]->c.obj.iv[8];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= w;
	goto IF61866;
IF61865:
	local[2]= NIL;
IF61866:
	w = local[2];
	local[0]= w;
BLK61831:
	ctx->vsp=local; return(local[0]);}

/*:extend*/
static pointer M61899hash_table_extend(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)2L);
	{ eusinteger_t i,j;
		j=intval(argv[0]->c.obj.iv[2]); i=intval(local[0]);
		local[0]=(makeint(i * j));}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[2]); /*make-array*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[2]); /*make-array*/
	local[2]= w;
	local[3]= NIL;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[0];
WHL61962:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX61963;
	local[6]= local[1];
	local[7]= local[4];
	w = argv[0]->c.obj.iv[7];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[7]); v=local[6];
	  v->c.vec.v[i]=w;}
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL61962;
WHX61963:
	local[6]= NIL;
BLK61964:
	w = NIL;
	local[3] = argv[0]->c.obj.iv[0];
	argv[0]->c.obj.iv[0] = local[1];
	local[1] = local[3];
	local[3] = argv[0]->c.obj.iv[1];
	argv[0]->c.obj.iv[1] = local[2];
	local[2] = local[3];
	local[3] = argv[0]->c.obj.iv[2];
	argv[0]->c.obj.iv[2] = local[0];
	local[0] = local[3];
	argv[0]->c.obj.iv[3] = makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[0];
WHL62046:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX62047;
	local[6]= local[1];
	{ register eusinteger_t i=intval(local[4]);
	  w=(local[6]->c.vec.v[i]);}
	local[3] = w;
	local[6]= local[3];
	if (argv[0]->c.obj.iv[7]==local[6]) goto IF62066;
	local[6]= local[3];
	if (argv[0]->c.obj.iv[8]==local[6]) goto IF62066;
	local[6]= argv[0];
	local[7]= fqv[3];
	local[8]= local[3];
	local[9]= local[2];
	{ register eusinteger_t i=intval(local[4]);
	  w=(local[9]->c.vec.v[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto IF62067;
IF62066:
	local[6]= NIL;
IF62067:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL62046;
WHX62047:
	local[6]= NIL;
BLK62048:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK61900:
	ctx->vsp=local; return(local[0]);}

/*:hash*/
static pointer M62106hash_table_hash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[4]); /*string*/
	argv[2] = w;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[4]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)MOD(ctx,2,local+0); /*mod*/
	local[0]= w;
BLK62107:
	ctx->vsp=local; return(local[0]);}

/*:map*/
static pointer M62141hash_table_map(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[0]->c.obj.iv[2];
WHL62191:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX62192;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62212;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62212;
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[6]->c.vec.v[i]);}
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)FUNCALL(ctx,3,local+4); /*funcall*/
	local[4]= w;
	goto IF62213;
IF62212:
	local[4]= NIL;
IF62213:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL62191;
WHX62192:
	local[4]= NIL;
BLK62193:
	w = NIL;
	local[0]= w;
BLK62143:
	ctx->vsp=local; return(local[0]);}

/*:list-values*/
static pointer M62254hash_table_list_values(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[0]->c.obj.iv[2];
WHL62301:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX62302;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62322;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62322;
	local[4]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF62323;
IF62322:
	local[4]= NIL;
IF62323:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL62301;
WHX62302:
	local[4]= NIL;
BLK62303:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK62255:
	ctx->vsp=local; return(local[0]);}

/*:list-keys*/
static pointer M62373hash_table_list_keys(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[0]->c.obj.iv[2];
WHL62420:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX62421;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62441;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62441;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF62442;
IF62441:
	local[4]= NIL;
IF62442:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL62420;
WHX62421:
	local[4]= NIL;
BLK62422:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK62374:
	ctx->vsp=local; return(local[0]);}

/*:list*/
static pointer M62488hash_table_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= argv[0]->c.obj.iv[2];
WHL62535:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX62536;
	local[4]= argv[0]->c.obj.iv[0];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[4]->c.vec.v[i]);}
	local[0] = w;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62556;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+6;
	w=(pointer)EQ(ctx,2,local+4); /*eql*/
	if (w!=NIL) goto IF62556;
	local[4]= local[0];
	local[5]= argv[0]->c.obj.iv[1];
	{ register eusinteger_t i=intval(local[2]);
	  w=(local[5]->c.vec.v[i]);}
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF62557;
IF62556:
	local[4]= NIL;
IF62557:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL62535;
WHX62536:
	local[4]= NIL;
BLK62537:
	w = NIL;
	w = local[1];
	local[0]= w;
BLK62489:
	ctx->vsp=local; return(local[0]);}

/*:hash-function*/
static pointer M62610hash_table_hash_function(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT62614;}
	local[0]= NIL;
ENT62614:
ENT62613:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF62630;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF62631;
IF62630:
	local[1]= NIL;
IF62631:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK62611:
	ctx->vsp=local; return(local[0]);}

/*:clear*/
static pointer M62646hash_table_clear(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[2];
WHL62682:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX62683;
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= local[0];
	w = argv[0]->c.obj.iv[7];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	w = NIL;
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.vec.v[i]=w;}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL62682;
WHX62683:
	local[2]= NIL;
BLK62684:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK62647:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M62725hash_table_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT62729;}
	local[0]= T;
ENT62729:
ENT62728:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[5]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[6]));
	local[5]= fqv[7];
	local[6]= local[0];
	local[7]= NIL;
	local[8]= fqv[8];
	local[9]= argv[0]->c.obj.iv[3];
	local[10]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,4,local+7); /*format*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK62726:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M62763hash_table_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[9], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY62779;
	local[0] = NIL;
KEY62779:
	if (n & (1<<1)) goto KEY62784;
	local[1] = makeint((eusinteger_t)10L);
KEY62784:
	if (n & (1<<2)) goto KEY62789;
	local[2] = (pointer)get_sym_func(fqv[10]);
KEY62789:
	if (n & (1<<3)) goto KEY62796;
	local[3] = makeflt(2.0000000000000000000000e+00);
KEY62796:
	if (n & (1<<4)) goto KEY62801;
	local[4] = (pointer)get_sym_func(fqv[11]);
KEY62801:
	argv[0]->c.obj.iv[2] = local[1];
	local[5]= loadglobal(fqv[12]);
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	argv[0]->c.obj.iv[0] = w;
	local[5]= loadglobal(fqv[12]);
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	argv[0]->c.obj.iv[1] = w;
	argv[0]->c.obj.iv[4] = local[4];
	argv[0]->c.obj.iv[5] = local[2];
	local[5]= fqv[13];
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,1,local+5); /*gensym*/
	argv[0]->c.obj.iv[7] = w;
	local[5]= fqv[14];
	ctx->vsp=local+6;
	w=(pointer)GENSYM(ctx,1,local+5); /*gensym*/
	argv[0]->c.obj.iv[8] = w;
	argv[0]->c.obj.iv[9] = local[0];
	argv[0]->c.obj.iv[3] = makeint((eusinteger_t)0L);
	argv[0]->c.obj.iv[6] = local[3];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[1];
WHL62877:
	local[7]= local[5];
	w = local[6];
	if ((eusinteger_t)local[7] >= (eusinteger_t)w) goto WHX62878;
	local[7]= argv[0]->c.obj.iv[0];
	local[8]= local[5];
	w = argv[0]->c.obj.iv[7];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.vec.v[i]=w;}
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[5] = w;
	goto WHL62877;
WHX62878:
	local[7]= NIL;
BLK62879:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK62764:
	ctx->vsp=local; return(local[0]);}

/*make-hash-table*/
static pointer F61397make_hash_table(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[15], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY62922;
	local[0] = makeint((eusinteger_t)10L);
KEY62922:
	if (n & (1<<1)) goto KEY62927;
	local[1] = (pointer)get_sym_func(fqv[10]);
KEY62927:
	if (n & (1<<2)) goto KEY62934;
	local[2] = makeflt(1.6999999999999992894573e+00);
KEY62934:
	if (n & (1<<3)) goto KEY62939;
	local[3] = (pointer)get_sym_func(fqv[11]);
KEY62939:
	if (n & (1<<4)) goto KEY62946;
	local[4] = NIL;
KEY62946:
	local[5]= loadglobal(fqv[16]);
	ctx->vsp=local+6;
	w=(pointer)INSTANTIATE(ctx,1,local+5); /*instantiate*/
	local[5]= w;
	local[6]= local[5];
	local[7]= fqv[17];
	local[8]= fqv[18];
	local[9]= local[0];
	local[10]= fqv[19];
	local[11]= local[1];
	local[12]= fqv[20];
	local[13]= local[2];
	local[14]= fqv[21];
	local[15]= local[3];
	local[16]= fqv[22];
	local[17]= local[4];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,12,local+6); /*send*/
	w = local[5];
	local[0]= w;
BLK62911:
	ctx->vsp=local; return(local[0]);}

/*gethash*/
static pointer F61400gethash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[23];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK62997:
	ctx->vsp=local; return(local[0]);}

/*sethash*/
static pointer F61403sethash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[1];
	local[1]= fqv[3];
	local[2]= argv[0];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK63017:
	ctx->vsp=local; return(local[0]);}

/*remhash*/
static pointer F61406remhash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[24];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK63040:
	ctx->vsp=local; return(local[0]);}

/*hash-table-p*/
static pointer F61409hash_table_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK63060:
	ctx->vsp=local; return(local[0]);}

/*maphash*/
static pointer F61412maphash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	local[1]= fqv[25];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK63076:
	ctx->vsp=local; return(local[0]);}

/*clrhash*/
static pointer F61415clrhash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[26];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK63096:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M63129queue_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = NIL;
	w = argv[0];
	local[0]= w;
BLK63130:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M63153queue_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK63154:
	ctx->vsp=local; return(local[0]);}

/*:empty?*/
static pointer M63170queue_empty_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = ((argv[0]->c.obj.iv[0])==NIL?T:NIL);
	local[0]= w;
BLK63171:
	ctx->vsp=local; return(local[0]);}

/*:trim*/
static pointer M63189queue_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MINUS(ctx,2,local+1); /*-*/
	local[1]= w;
WHL63235:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX63236;
	local[2]= argv[0];
	local[3]= fqv[27];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL63235;
WHX63236:
	local[2]= NIL;
BLK63237:
	w = NIL;
	local[0]= w;
BLK63190:
	ctx->vsp=local; return(local[0]);}

/*:dequeue*/
static pointer M63262queue_dequeue(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT63266;}
	local[0]= NIL;
ENT63266:
ENT63265:
	if (n>3) maerror();
	if (argv[0]->c.obj.iv[0]!=NIL) goto CON63284;
	if (local[0]==NIL) goto IF63290;
	local[1]= fqv[28];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,2,local+1); /*error*/
	local[1]= w;
	goto IF63291;
IF63290:
	local[1]= NIL;
IF63291:
	goto CON63282;
CON63284:
	local[1]= argv[0]->c.obj.iv[0];
	if (argv[0]->c.obj.iv[1]!=local[1]) goto CON63298;
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	argv[0]->c.obj.iv[0] = NIL;
	argv[0]->c.obj.iv[1] = NIL;
	w = local[1];
	local[1]= w;
	goto CON63282;
CON63298:
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[0] = (w)->c.cons.cdr;
	w = local[1];
	local[1]= w;
	goto CON63282;
CON63335:
	local[1]= NIL;
CON63282:
	w = local[1];
	local[0]= w;
BLK63263:
	ctx->vsp=local; return(local[0]);}

/*:enqueue*/
static pointer M63374queue_enqueue(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[1]==NIL) goto CON63391;
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	w = NIL;
	ctx->vsp=local+2;
	local[1]= cons(ctx,local[1],w);
	ctx->vsp=local+2;
	w=(pointer)RPLACD2(ctx,2,local+0); /*rplacd2*/
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	argv[0]->c.obj.iv[1] = (w)->c.cons.cdr;
	local[0]= argv[0]->c.obj.iv[1];
	goto CON63389;
CON63391:
	local[0]= argv[2];
	w = NIL;
	ctx->vsp=local+1;
	argv[0]->c.obj.iv[1] = cons(ctx,local[0],w);
	argv[0]->c.obj.iv[0] = argv[0]->c.obj.iv[1];
	local[0]= argv[0]->c.obj.iv[0];
	goto CON63389;
CON63416:
	local[0]= NIL;
CON63389:
	w = argv[2];
	local[0]= w;
BLK63375:
	ctx->vsp=local; return(local[0]);}

/*:search*/
static pointer M63440queue_search(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT63444;}
	local[0]= (pointer)get_sym_func(fqv[29]);
ENT63444:
ENT63443:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[0];
	local[3]= fqv[19];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,4,local+1,&ftab[2],fqv[30]); /*find*/
	local[0]= w;
BLK63441:
	ctx->vsp=local; return(local[0]);}

/*:delete*/
static pointer M63473queue_delete(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT63478;}
	local[0]= (pointer)get_sym_func(fqv[29]);
ENT63478:
	if (n>=5) { local[1]=(argv[4]); goto ENT63477;}
	local[1]= makeint((eusinteger_t)1L);
ENT63477:
ENT63476:
	if (n>5) maerror();
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= fqv[19];
	local[5]= local[0];
	local[6]= fqv[31];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,6,local+2,&ftab[3],fqv[32]); /*delete*/
	argv[0]->c.obj.iv[0] = w;
	local[2]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+3;
	w=(*ftab[4])(ctx,1,local+2,&ftab[4],fqv[33]); /*last*/
	argv[0]->c.obj.iv[1] = w;
	w = argv[0];
	local[0]= w;
BLK63474:
	ctx->vsp=local; return(local[0]);}

/*:first*/
static pointer M63532queue_first(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK63533:
	ctx->vsp=local; return(local[0]);}

/*:last*/
static pointer M63552queue_last(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= w;
BLK63553:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___hashtab(ctx,n,argv,env)
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
	local[0]= fqv[34];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF63578;
	local[0]= fqv[35];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[36],w);
	goto IF63579;
IF63578:
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF63579:
	local[0]= fqv[38];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[16];
	local[1]= fqv[39];
	local[2]= fqv[16];
	local[3]= fqv[40];
	local[4]= loadglobal(fqv[41]);
	local[5]= fqv[42];
	local[6]= fqv[43];
	local[7]= fqv[44];
	local[8]= NIL;
	local[9]= fqv[45];
	local[10]= NIL;
	local[11]= fqv[18];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[46];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,13,local+2,&ftab[5],fqv[47]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[48];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61502hash_table_size,fqv[18],fqv[16],fqv[49]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61518hash_table_find,fqv[0],fqv[16],fqv[50]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61668hash_table_get,fqv[23],fqv[16],fqv[51]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61714hash_table_enter,fqv[3],fqv[16],fqv[52]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61830hash_table_delete,fqv[24],fqv[16],fqv[53]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M61899hash_table_extend,fqv[1],fqv[16],fqv[54]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62106hash_table_hash,fqv[21],fqv[16],fqv[55]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62141hash_table_map,fqv[25],fqv[16],fqv[56]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62254hash_table_list_values,fqv[57],fqv[16],fqv[58]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62373hash_table_list_keys,fqv[59],fqv[16],fqv[60]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62488hash_table_list,fqv[61],fqv[16],fqv[62]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62610hash_table_hash_function,fqv[63],fqv[16],fqv[64]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62646hash_table_clear,fqv[26],fqv[16],fqv[65]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62725hash_table_prin1,fqv[7],fqv[16],fqv[66]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M62763hash_table_init,fqv[17],fqv[16],fqv[67]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[68],module,F61397make_hash_table,fqv[69]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[70],module,F61400gethash,fqv[71]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F61403sethash,fqv[73]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[74],module,F61406remhash,fqv[75]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F61409hash_table_p,fqv[77]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F61412maphash,fqv[79]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[80],module,F61415clrhash,fqv[81]);
	local[0]= fqv[82];
	local[1]= fqv[39];
	local[2]= fqv[82];
	local[3]= fqv[40];
	local[4]= loadglobal(fqv[83]);
	local[5]= fqv[42];
	local[6]= fqv[84];
	local[7]= fqv[44];
	local[8]= NIL;
	local[9]= fqv[45];
	local[10]= NIL;
	local[11]= fqv[18];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[46];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[5])(ctx,13,local+2,&ftab[5],fqv[47]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63129queue_init,fqv[17],fqv[82],fqv[85]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63153queue_length,fqv[86],fqv[82],fqv[87]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63170queue_empty_,fqv[88],fqv[82],fqv[89]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63189queue_trim,fqv[90],fqv[82],fqv[91]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63262queue_dequeue,fqv[27],fqv[82],fqv[92]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63374queue_enqueue,fqv[93],fqv[82],fqv[94]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63440queue_search,fqv[95],fqv[82],fqv[96]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63473queue_delete,fqv[24],fqv[82],fqv[97]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63532queue_first,fqv[98],fqv[82],fqv[99]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M63552queue_last,fqv[100],fqv[82],fqv[101]);
	local[0]= fqv[102];
	local[1]= fqv[103];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,2,local+0,&ftab[6],fqv[104]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<7; i++) ftab[i]=fcallx;
}
