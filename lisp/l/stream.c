/* ./stream.c :  entry=stream */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "stream.h"
#pragma init (register_stream)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___stream();
extern pointer build_quote_vector();
static int register_stream()
  { add_module_initializer("___stream", ___stream);}

static pointer F22216reset_stream();
static pointer F22227make_two_way_stream();
static pointer F22230make_msgq_input_stream();
static pointer F22233make_msgq_output_stream();
static pointer F22237make_string_input_stream();
static pointer F22240make_string_output_stream();
static pointer F22245get_output_stream_string();
static pointer F22248read_from_string();
static pointer F22251princ_to_string();
static pointer F22254prin1_to_string();
static pointer F22263make_socket_address();
static pointer F22272make_socket_port();
static pointer F22280make_server_socket_stream();
static pointer F22284connect_sigalarm_handler();
static pointer F22287make_client_socket_stream();
static pointer F22290make_dgram_socket();
static pointer F22293connect_server();
static pointer F22297select_stream();
static pointer F22302sigio_handler();
static pointer F22311make_broadcast_stream();
static pointer F22314read_buffer();
static pointer F22317write_buffer();

/*:instream*/
static pointer M22379io_stream_instream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22383;}
	local[0]= NIL;
ENT22383:
ENT22382:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*input-stream-p*/
	if (w==NIL) goto IF22399;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF22400;
IF22399:
	local[1]= NIL;
IF22400:
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK22380:
	ctx->vsp=local; return(local[0]);}

/*:outstream*/
static pointer M22418io_stream_outstream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22422;}
	local[0]= NIL;
ENT22422:
ENT22421:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,1,local+1,&ftab[1],fqv[1]); /*output-stream-p*/
	if (w==NIL) goto IF22438;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF22439;
IF22438:
	local[1]= NIL;
IF22439:
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK22419:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M22457io_stream_infd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[2];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22458:
	ctx->vsp=local; return(local[0]);}

/*:outfd*/
static pointer M22476io_stream_outfd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= fqv[3];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22477:
	ctx->vsp=local; return(local[0]);}

/*:in*/
static pointer M22495io_stream_in(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST22498:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK22496:
	ctx->vsp=local; return(local[0]);}

/*:out*/
static pointer M22519io_stream_out(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST22522:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[4]);
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[0]= w;
BLK22520:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M22543io_stream_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[5];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22544:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M22562io_stream_async(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[6];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK22563:
	ctx->vsp=local; return(local[0]);}

/*:fname*/
static pointer M22584io_stream_fname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22585:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M22603io_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = argv[3];
	w = argv[0];
	local[0]= w;
BLK22604:
	ctx->vsp=local; return(local[0]);}

/*:reset*/
static pointer M22650stream_reset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22654;}
	local[0]= NIL;
ENT22654:
ENT22653:
	if (n>3) maerror();
	argv[0]->c.obj.iv[3] = makeint((eusinteger_t)0L);
	if (local[0]==NIL) goto IF22674;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	goto IF22675;
IF22674:
	local[1]= makeint((eusinteger_t)0L);
IF22675:
	argv[0]->c.obj.iv[4] = local[1];
	w = argv[0];
	local[0]= w;
BLK22651:
	ctx->vsp=local; return(local[0]);}

/*:discard*/
static pointer M22689stream_discard(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22693;}
	local[0]= makeint((eusinteger_t)1L);
ENT22693:
ENT22692:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[4];
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)PLUS(ctx,2,local+2); /*+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAX(ctx,2,local+1); /*max*/
	argv[0]->c.obj.iv[3] = w;
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK22690:
	ctx->vsp=local; return(local[0]);}

/*:count*/
static pointer M22725stream_count(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK22726:
	ctx->vsp=local; return(local[0]);}

/*:tail*/
static pointer M22741stream_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22745;}
	local[0]= NIL;
ENT22745:
ENT22744:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF22761;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[0]->c.obj.iv[4];
	goto IF22762;
IF22761:
	local[1]= NIL;
IF22762:
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK22742:
	ctx->vsp=local; return(local[0]);}

/*:chars-left*/
static pointer M22779stream_chars_left(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+2;
	w=(pointer)MINUS(ctx,2,local+0); /*-*/
	local[0]= w;
BLK22780:
	ctx->vsp=local; return(local[0]);}

/*:tail-string*/
static pointer M22799stream_tail_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[3];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK22800:
	ctx->vsp=local; return(local[0]);}

/*:buffer*/
static pointer M22818stream_buffer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT22823;}
	local[0]= NIL;
ENT22823:
	if (n>=4) { local[1]=(argv[3]); goto ENT22822;}
	local[1]= NIL;
ENT22822:
ENT22821:
	if (n>4) maerror();
	if (local[1]==NIL) goto CON22845;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	goto CON22843;
CON22845:
	w = local[0];
	if (!isstring(w)) goto CON22855;
	argv[0]->c.obj.iv[2] = local[0];
	local[2]= argv[0]->c.obj.iv[2];
	goto CON22843;
CON22855:
	w = local[0];
	if (!isint(w)) goto CON22866;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,1,local+2,&ftab[2],fqv[8]); /*make-string*/
	argv[0]->c.obj.iv[2] = w;
	local[2]= argv[0]->c.obj.iv[2];
	goto CON22843;
CON22866:
	local[2]= argv[0]->c.obj.iv[2];
	goto CON22843;
CON22880:
	local[2]= NIL;
CON22843:
	w = local[2];
	local[0]= w;
BLK22819:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M22886stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT22891;}
	local[0]= NIL;
ENT22891:
	if (n>=6) { local[1]=(argv[5]); goto ENT22890;}
	local[1]= NIL;
ENT22890:
ENT22889:
	if (n>6) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	w = argv[3];
	if (!isstring(w)) goto IF22920;
	local[2]= argv[3];
	goto IF22921;
IF22920:
	local[2]= loadglobal(fqv[9]);
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
IF22921:
	argv[0]->c.obj.iv[2] = local[2];
	w = local[0];
	if (!isint(w)) goto IF22933;
	local[2]= local[0];
	goto IF22934;
IF22933:
	local[2]= makeint((eusinteger_t)0L);
IF22934:
	argv[0]->c.obj.iv[3] = local[2];
	w = local[1];
	if (!isint(w)) goto IF22941;
	local[2]= local[1];
	goto IF22942;
IF22941:
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
IF22942:
	argv[0]->c.obj.iv[4] = local[2];
	w = argv[0];
	local[0]= w;
BLK22887:
	ctx->vsp=local; return(local[0]);}

/*reset-stream*/
static pointer F22216reset_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[10];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK22959:
	ctx->vsp=local; return(local[0]);}

/*:fd*/
static pointer M23004file_stream_fd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK23005:
	ctx->vsp=local; return(local[0]);}

/*:instream*/
static pointer M23020file_stream_instream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[11]!=local[0]) goto IF23033;
	local[0]= argv[0];
	goto IF23034;
IF23033:
	local[0]= NIL;
IF23034:
	w = local[0];
	local[0]= w;
BLK23021:
	ctx->vsp=local; return(local[0]);}

/*:outstream*/
static pointer M23043file_stream_outstream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[12]!=local[0]) goto IF23056;
	local[0]= argv[0];
	goto IF23057;
IF23056:
	local[0]= NIL;
IF23057:
	w = local[0];
	local[0]= w;
BLK23044:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M23066file_stream_infd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[11]!=local[0]) goto IF23079;
	local[0]= argv[0]->c.obj.iv[5];
	goto IF23080;
IF23079:
	local[0]= NIL;
IF23080:
	w = local[0];
	local[0]= w;
BLK23067:
	ctx->vsp=local; return(local[0]);}

/*:outfd*/
static pointer M23089file_stream_outfd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	if (fqv[12]!=local[0]) goto IF23102;
	local[0]= argv[0]->c.obj.iv[5];
	goto IF23103;
IF23102:
	local[0]= NIL;
IF23103:
	w = local[0];
	local[0]= w;
BLK23090:
	ctx->vsp=local; return(local[0]);}

/*:fname*/
static pointer M23112file_stream_fname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK23113:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M23128file_stream_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint((eusinteger_t)3L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
BLK23129:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M23145file_stream_async(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON23162;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)8192L);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint((eusinteger_t)8L);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23160;
CON23162:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)8192L);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23160;
CON23185:
	local[0]= NIL;
CON23160:
	w = local[0];
	local[0]= w;
BLK23146:
	ctx->vsp=local; return(local[0]);}

/*:nonblock*/
static pointer M23204file_stream_nonblock(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON23221;
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[13]);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint((eusinteger_t)8L);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23219;
CON23221:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= loadglobal(fqv[13]);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON23219;
CON23246:
	local[0]= NIL;
CON23219:
	w = local[0];
	local[0]= w;
BLK23205:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M23266file_stream_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT23270;}
	local[0]= T;
ENT23270:
ENT23269:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= (pointer)get_sym_func(fqv[14]);
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[15]));
	local[5]= fqv[16];
	local[6]= local[0];
	local[7]= NIL;
	local[8]= fqv[17];
	local[9]= argv[0]->c.obj.iv[6];
	local[10]= argv[0]->c.obj.iv[1];
	local[11]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)LENGTH(ctx,1,local+11); /*length*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,5,local+7); /*format*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,7,local+2); /*apply*/
	local[0]= w;
BLK23267:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M23307file_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<5) maerror();
	if (n>=6) { local[0]=(argv[5]); goto ENT23311;}
	local[0]= makeint((eusinteger_t)128L);
ENT23311:
ENT23310:
	if (n>6) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[15]));
	local[3]= fqv[18];
	local[4]= argv[4];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	argv[0]->c.obj.iv[6] = argv[3];
	argv[0]->c.obj.iv[4] = makeint((eusinteger_t)0L);
	w = argv[0];
	local[0]= w;
BLK23308:
	ctx->vsp=local; return(local[0]);}

/*:read-bytes*/
static pointer M23383file_stream_read_bytes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT23388;}
	local[0]= argv[2];
	ctx->vsp=local+1;
	w=(*ftab[2])(ctx,1,local+0,&ftab[2],fqv[8]); /*make-string*/
	local[0]= w;
ENT23388:
	if (n>=5) { local[1]=(argv[4]); goto ENT23387;}
	local[1]= makeint((eusinteger_t)0L);
ENT23387:
ENT23386:
	if (n>5) maerror();
	local[2]= NIL;
	w = local[0];
	if (isstring(w)) goto IF23421;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto IF23421;
	local[3]= fqv[19];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF23422;
IF23421:
	local[3]= NIL;
IF23422:
	local[3]= argv[0];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(*ftab[3])(ctx,1,local+3,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto IF23438;
	local[3]= local[0];
	local[4]= argv[0];
	local[5]= fqv[22];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[23];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,4,local+3,&ftab[4],fqv[24]); /*replace*/
	local[3]= argv[2];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)MIN(ctx,2,local+3); /*min*/
	local[2] = w;
	local[3]= argv[0]->c.obj.iv[3];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[0]->c.obj.iv[3] = w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[1] = w;
	local[3]= local[1];
	goto IF23439;
IF23438:
	local[3]= NIL;
IF23439:
WHL23508:
	local[3]= local[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)LESSP(ctx,2,local+3); /*<*/
	if (w==NIL) goto WHX23509;
	local[3]= argv[0]->c.obj.iv[5];
	local[4]= local[0];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,2,local+5); /*-*/
	local[5]= w;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)UNIXREAD(ctx,4,local+3); /*unix:uread*/
	local[2] = w;
	local[3]= local[2];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)LSEQP(ctx,2,local+3); /*<=*/
	if (w==NIL) goto IF23534;
	local[3]= fqv[25];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF23535;
IF23534:
	local[3]= NIL;
IF23535:
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	local[1] = w;
	goto WHL23508;
WHX23509:
	local[3]= NIL;
BLK23510:
	w = local[0];
	local[0]= w;
BLK23384:
	ctx->vsp=local; return(local[0]);}

/*:read-bytes-eof*/
static pointer M23560file_stream_read_bytes_eof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto IF23584;
	local[2]= argv[0];
	local[3]= fqv[22];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[26];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	goto IF23585;
IF23584:
	local[2]= NIL;
IF23585:
WHL23623:
	local[2]= argv[0]->c.obj.iv[5];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)UNIXREAD(ctx,2,local+2); /*unix:uread*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[21]); /*plusp*/
	if (w==NIL) goto WHX23624;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	goto WHL23623;
WHX23624:
	local[2]= NIL;
BLK23625:
	local[2]= (pointer)get_sym_func(fqv[27]);
	local[3]= loadglobal(fqv[9]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[0]= w;
BLK23561:
	ctx->vsp=local; return(local[0]);}

/*make-two-way-stream*/
static pointer F22227make_two_way_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= loadglobal(fqv[28]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[18];
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	local[0]= w;
BLK23668:
	ctx->vsp=local; return(local[0]);}

/*make-msgq-input-stream*/
static pointer F22230make_msgq_input_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT23712;}
	local[0]= makeint((eusinteger_t)128L);
ENT23712:
ENT23711:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MSGGET(ctx,1,local+4); /*unix:msgget*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK23709:
	ctx->vsp=local; return(local[0]);}

/*make-msgq-output-stream*/
static pointer F22233make_msgq_output_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT23763;}
	local[0]= makeint((eusinteger_t)128L);
ENT23763:
ENT23762:
	if (n>2) maerror();
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)MSGGET(ctx,1,local+4); /*unix:msgget*/
	local[4]= w;
	local[5]= argv[0];
	local[6]= fqv[12];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	local[0]= w;
BLK23760:
	ctx->vsp=local; return(local[0]);}

/*make-string-input-stream*/
static pointer F22237make_string_input_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT23815;}
	local[0]= NIL;
ENT23815:
	if (n>=3) { local[1]=(argv[2]); goto ENT23814;}
	local[1]= NIL;
ENT23814:
ENT23813:
	if (n>3) maerror();
	w = argv[0];
	if (isstring(w)) goto IF23833;
	local[2]= fqv[30];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF23834;
IF23833:
	local[2]= NIL;
IF23834:
	local[2]= loadglobal(fqv[31]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[18];
	local[5]= fqv[11];
	local[6]= argv[0];
	local[7]= local[0];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	argv[0] = w;
	w = argv[0];
	local[0]= w;
BLK23811:
	ctx->vsp=local; return(local[0]);}

/*make-string-output-stream*/
static pointer F22240make_string_output_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT23887;}
	local[0]= makeint((eusinteger_t)64L);
ENT23887:
	if (n>=2) { local[1]=(argv[1]); goto ENT23886;}
	local[1]= NIL;
ENT23886:
	if (n>=3) { local[2]=(argv[2]); goto ENT23885;}
	local[2]= NIL;
ENT23885:
ENT23884:
	if (n>3) maerror();
	local[3]= loadglobal(fqv[31]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[18];
	local[6]= fqv[12];
	local[7]= local[0];
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	local[0] = w;
	w = local[0];
	local[0]= w;
BLK23882:
	ctx->vsp=local; return(local[0]);}

/*with-input-from-string*/
static pointer F23946(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST23949:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[32];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[33];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[34];
	local[6]= fqv[35];
	local[7]= fqv[36];
	local[8]= fqv[37];
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
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[38];
	local[8]= fqv[35];
	local[9]= fqv[36];
	local[10]= fqv[37];
	local[11]= argv[0];
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
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[39];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	local[7]= fqv[35];
	local[8]= fqv[40];
	local[9]= fqv[37];
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
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[38];
	local[9]= fqv[35];
	local[10]= fqv[40];
	local[11]= fqv[37];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	ctx->vsp=local+12;
	w=(pointer)LIST(ctx,1,local+11); /*list*/
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	local[8]= cons(ctx,local[8],w);
	local[9]= fqv[39];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
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
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	w = local[0];
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK23947:
	ctx->vsp=local; return(local[0]);}

/*with-output-to-string*/
static pointer F24114(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST24117:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[32];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[41];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= local[0];
	local[4]= fqv[42];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,1,local+5); /*list*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK24115:
	ctx->vsp=local; return(local[0]);}

/*get-output-stream-string*/
static pointer F22245get_output_stream_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK24175:
	ctx->vsp=local; return(local[0]);}

/*read-from-string*/
static pointer F22248read_from_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT24203;}
	local[0]= T;
ENT24203:
	if (n>=3) { local[1]=(argv[2]); goto ENT24202;}
	local[1]= NIL;
ENT24202:
ENT24201:
	if (n>3) maerror();
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F22237make_string_input_stream(ctx,1,local+2); /*make-string-input-stream*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)READ(ctx,3,local+2); /*read*/
	local[0]= w;
BLK24199:
	ctx->vsp=local; return(local[0]);}

/*princ-to-string*/
static pointer F22251princ_to_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT24233;}
	local[0]= makeint((eusinteger_t)16L);
ENT24233:
ENT24232:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F22240make_string_output_stream(ctx,1,local+1); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PRINC(ctx,2,local+2); /*princ*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F22245get_output_stream_string(ctx,1,local+2); /*get-output-stream-string*/
	local[0]= w;
BLK24230:
	ctx->vsp=local; return(local[0]);}

/*prin1-to-string*/
static pointer F22254prin1_to_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT24274;}
	local[0]= makeint((eusinteger_t)16L);
ENT24274:
ENT24273:
	if (n>2) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F22240make_string_output_stream(ctx,1,local+1); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)PRIN1(ctx,2,local+2); /*prin1*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F22245get_output_stream_string(ctx,1,local+2); /*get-output-stream-string*/
	local[0]= w;
BLK24271:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M24325socket_address_domain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK24326:
	ctx->vsp=local; return(local[0]);}

/*:port*/
static pointer M24344socket_address_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)2L);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[44]); /*unix::ntohs*/
	local[0]= w;
BLK24345:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M24366socket_address_host(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= makeint((eusinteger_t)8L);
	ctx->vsp=local+3;
	w=(pointer)SUBSEQ(ctx,3,local+0); /*subseq*/
	local[0]= w;
BLK24367:
	ctx->vsp=local; return(local[0]);}

/*:next-port*/
static pointer M24383socket_address_next_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[45];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[6])(ctx,1,local+0,&ftab[6],fqv[46]); /*unix::htons*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= fqv[43];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
BLK24384:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M24412socket_address_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT24416;}
	local[0]= T;
ENT24416:
ENT24415:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[15]));
	local[3]= fqv[16];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= fqv[47];
	local[7]= argv[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)4L));
	  w=makeint(local[7]->c.str.chars[i]);}
	local[7]= w;
	local[8]= argv[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)5L));
	  w=makeint(local[8]->c.str.chars[i]);}
	local[8]= w;
	local[9]= argv[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)6L));
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	local[10]= argv[0];
	{ register eusinteger_t i=intval(makeint((eusinteger_t)7L));
	  w=makeint(local[10]->c.str.chars[i]);}
	local[10]= w;
	local[11]= argv[0];
	local[12]= fqv[45];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,2,local+11); /*send*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)XFORMAT(ctx,7,local+5); /*format*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[0]= w;
BLK24413:
	ctx->vsp=local; return(local[0]);}

/*make-socket-address*/
static pointer F22263make_socket_address(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[48], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY24479;
	local[0] = makeint((eusinteger_t)2L);
KEY24479:
	if (n & (1<<1)) goto KEY24484;
	local[1] = NIL;
KEY24484:
	if (n & (1<<2)) goto KEY24489;
	local[2] = fqv[49];
KEY24489:
	if (n & (1<<3)) goto KEY24494;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)GETSERVBYNAME(ctx,1,local+6); /*unix:getservbyname*/
	local[3] = w;
KEY24494:
	if (n & (1<<4)) goto KEY24502;
	local[6]= fqv[50];
	ctx->vsp=local+7;
	w=(pointer)GETENV(ctx,1,local+6); /*unix:getenv*/
	local[4] = w;
KEY24502:
	if (n & (1<<5)) goto KEY24509;
	local[5] = NIL;
KEY24509:
	local[6]= local[0];
	if (makeint((eusinteger_t)1L)!=local[6]) goto CON24520;
	local[6]= loadglobal(fqv[51]);
	local[7]= makeint((eusinteger_t)16L);
	local[8]= makeint((eusinteger_t)2L);
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)LENGTH(ctx,1,local+9); /*length*/
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[8]= (pointer)((eusinteger_t)local[8] + (eusinteger_t)w);
	ctx->vsp=local+9;
	w=(pointer)MAX(ctx,2,local+7); /*max*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= local[1];
	local[9]= fqv[52];
	local[10]= makeint((eusinteger_t)2L);
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,4,local+7,&ftab[4],fqv[24]); /*replace*/
	local[7]= local[0];
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	w = local[6];
	local[6]= w;
	goto CON24518;
CON24520:
	local[6]= local[0];
	if (makeint((eusinteger_t)2L)!=local[6]) goto CON24565;
	local[6]= loadglobal(fqv[51]);
	local[7]= makeint((eusinteger_t)16L);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,2,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[0];
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)0L);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	if (local[4]==NIL) goto IF24592;
	local[7]= local[4];
	if (fqv[53]!=local[7]) goto IF24601;
	local[7]= makeint((eusinteger_t)0L);
	local[8]= makeint((eusinteger_t)0L);
	local[9]= makeint((eusinteger_t)0L);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)MKINTVECTOR(ctx,4,local+7); /*integer-vector*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	local[4] = w;
	local[7]= local[4];
	goto IF24602;
IF24601:
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)GETHOSTBYNAME(ctx,1,local+7); /*unix:gethostbyname*/
	local[4] = w;
	local[7]= local[4];
IF24602:
	w = local[4];
	if (!isnum(w)) goto IF24627;
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SYSERRLIST(ctx,1,local+7); /*unix:syserrlist*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK24467;
	goto IF24628;
IF24627:
	local[7]= NIL;
IF24628:
	local[7]= local[6];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	local[9]= fqv[52];
	local[10]= makeint((eusinteger_t)4L);
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,4,local+7,&ftab[4],fqv[24]); /*replace*/
	local[7]= w;
	goto IF24593;
IF24592:
	local[7]= NIL;
IF24593:
	if (local[2]==NIL) goto IF24655;
	local[7]= local[2];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)GETSERVBYNAME(ctx,2,local+7); /*unix:getservbyname*/
	local[2] = w;
	w = local[2];
	if (!isnum(w)) goto IF24674;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,1,local+7); /*-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SYSERRLIST(ctx,1,local+7); /*unix:syserrlist*/
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK24467;
	goto IF24675;
IF24674:
	local[7]= NIL;
IF24675:
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	local[7]= w;
	goto IF24656;
IF24655:
	local[7]= NIL;
IF24656:
	if (local[3]==NIL) goto IF24702;
	w = local[3];
	if (!isstring(w)) goto IF24711;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)GETSERVBYNAME(ctx,1,local+7); /*unix:getservbyname*/
	local[3] = w;
	local[7]= local[3];
	goto IF24712;
IF24711:
	local[7]= NIL;
IF24712:
	w = local[3];
	if (!isint(w)) goto IF24726;
	local[7]= local[3];
	local[8]= makeint((eusinteger_t)0L);
	ctx->vsp=local+9;
	w=(pointer)GREQP(ctx,2,local+7); /*>=*/
	if (w==NIL) goto IF24726;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,1,local+7,&ftab[6],fqv[46]); /*unix::htons*/
	local[7]= w;
	local[8]= local[6];
	local[9]= makeint((eusinteger_t)2L);
	local[10]= fqv[43];
	ctx->vsp=local+11;
	w=(pointer)POKE(ctx,4,local+7); /*system:poke*/
	local[7]= w;
	goto IF24727;
IF24726:
	local[7]= NIL;
IF24727:
	goto IF24703;
IF24702:
	local[7]= NIL;
IF24703:
	w = local[6];
	local[6]= w;
	goto CON24518;
CON24565:
	local[6]= NIL;
CON24518:
	w = local[6];
	local[0]= w;
BLK24467:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M24766socket_port_domain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK24767:
	ctx->vsp=local; return(local[0]);}

/*:address*/
static pointer M24785socket_port_address(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK24786:
	ctx->vsp=local; return(local[0]);}

/*:id*/
static pointer M24801socket_port_id(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK24802:
	ctx->vsp=local; return(local[0]);}

/*:fd*/
static pointer M24817socket_port_fd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK24818:
	ctx->vsp=local; return(local[0]);}

/*:infd*/
static pointer M24833socket_port_infd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[0];
	local[0]= w;
BLK24834:
	ctx->vsp=local; return(local[0]);}

/*:listen*/
static pointer M24849socket_port_listen(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT24853;}
	local[0]= makeint((eusinteger_t)3L);
ENT24853:
ENT24852:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)LISTEN(ctx,2,local+1); /*unix:listen*/
	local[0]= w;
BLK24850:
	ctx->vsp=local; return(local[0]);}

/*:accept*/
static pointer M24874socket_port_accept(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	w=(pointer)ACCEPT(ctx,1,local+0); /*unix:accept*/
	local[0]= w;
BLK24875:
	ctx->vsp=local; return(local[0]);}

/*:flag*/
static pointer M24891socket_port_flag(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint((eusinteger_t)3L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
BLK24892:
	ctx->vsp=local; return(local[0]);}

/*:async*/
static pointer M24908socket_port_async(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[2]==NIL) goto CON24925;
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)8192L);
	ctx->vsp=local+4;
	w=(pointer)LOGIOR(ctx,2,local+2); /*logior*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint((eusinteger_t)8L);
	ctx->vsp=local+2;
	w=(pointer)GETPID(ctx,0,local+2); /*unix:getpid*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON24923;
CON24925:
	local[0]= argv[0]->c.obj.iv[0];
	local[1]= makeint((eusinteger_t)4L);
	local[2]= argv[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)8192L);
	ctx->vsp=local+4;
	w=(pointer)LOGNOT(ctx,1,local+3); /*lognot*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)FCNTL(ctx,3,local+0); /*unix:fcntl*/
	local[0]= w;
	goto CON24923;
CON24951:
	local[0]= NIL;
CON24923:
	w = local[0];
	local[0]= w;
BLK24909:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M24970socket_port_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)1L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)SOCKET(ctx,3,local+1); /*unix:socket*/
	argv[0]->c.obj.iv[0] = w;
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto IF25014;
	w = argv[0]->c.obj.iv[0];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK24971;
	goto IF25015;
IF25014:
	local[1]= NIL;
IF25015:
	local[1]= argv[0]->c.obj.iv[0];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)BIND(ctx,2,local+1); /*unix:bind*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)LESSP(ctx,2,local+1); /*<*/
	if (w==NIL) goto CON25037;
	local[1]= fqv[55];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[56]); /*unix:perror*/
	local[1]= local[0];
	goto CON25035;
CON25037:
	local[1]= argv[0];
	local[2]= fqv[57];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)NUMEQUAL(ctx,2,local+1); /*=*/
	if (w==NIL) goto IF25062;
	local[1]= argv[0];
	goto IF25063;
IF25062:
	local[1]= local[0];
IF25063:
	goto CON25035;
CON25047:
	local[1]= NIL;
CON25035:
	w = local[1];
	local[0]= w;
BLK24971:
	ctx->vsp=local; return(local[0]);}

/*make-socket-port*/
static pointer F22272make_socket_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[58]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= fqv[18];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK25074:
	ctx->vsp=local; return(local[0]);}

/*:domain*/
static pointer M25115socket_stream_domain(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= makeint((eusinteger_t)0L);
	local[2]= fqv[43];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK25116:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M25134socket_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT25138;}
	local[0]= makeint((eusinteger_t)128L);
ENT25138:
ENT25137:
	if (n>5) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[2];
	local[5]= fqv[59];
	local[6]= fqv[11];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[18];
	local[4]= argv[2];
	local[5]= fqv[60];
	local[6]= fqv[12];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,6,local+2); /*send*/
	w = local[1];
	argv[0]->c.obj.iv[2] = w;
	argv[0]->c.obj.iv[3] = argv[3];
	w = argv[0];
	local[0]= w;
BLK25135:
	ctx->vsp=local; return(local[0]);}

/*make-server-socket-stream*/
static pointer F22280make_server_socket_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT25244;}
	local[0]= makeint((eusinteger_t)512L);
ENT25244:
ENT25243:
	if (n>2) maerror();
	local[1]= NIL;
	local[2]= argv[0];
	local[3]= fqv[61];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto IF25277;
	local[2]= local[1];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF25277;
	w = local[1];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK25241;
	goto IF25278;
IF25277:
	local[2]= NIL;
IF25278:
	local[2]= loadglobal(fqv[62]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[18];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= argv[0];
	local[7]= fqv[63];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,5,local+3); /*send*/
	w = local[2];
	local[0]= w;
BLK25241:
	ctx->vsp=local; return(local[0]);}

/*connect-sigalarm-handler*/
static pointer F22284connect_sigalarm_handler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= fqv[64];
	local[1]= loadglobal(fqv[65]);
	ctx->vsp=local+2;
	w=(*ftab[8])(ctx,2,local+0,&ftab[8],fqv[66]); /*warn*/
	local[0]= w;
BLK25333:
	ctx->vsp=local; return(local[0]);}

/*make-client-socket-stream*/
static pointer F22287make_client_socket_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT25356;}
	local[0]= makeint((eusinteger_t)5L);
ENT25356:
	if (n>=3) { local[1]=(argv[2]); goto ENT25355;}
	local[1]= makeint((eusinteger_t)512L);
ENT25355:
ENT25354:
	if (n>3) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	local[5]= fqv[54];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)1L);
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)SOCKET(ctx,3,local+4); /*unix:socket*/
	local[2] = w;
	local[4]= local[2];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF25398;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)UNIXCLOSE(ctx,1,local+4); /*unix:uclose*/
	w = local[2];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK25352;
	goto IF25399;
IF25398:
	local[4]= NIL;
IF25399:
	local[4]= makeint((eusinteger_t)14L);
	local[5]= fqv[67];
	ctx->vsp=local+6;
	w=(pointer)SIGNAL(ctx,2,local+4); /*unix:signal*/
	local[4]= w;
	storeglobal(fqv[68],w);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ALARM(ctx,1,local+4); /*unix:alarm*/
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP25430,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[2];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)CONNECT(ctx,2,local+6); /*unix:connect*/
	local[3] = w;
	w = local[3];
	ctx->vsp=local+6;
	UWP25430(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[4]= local[3];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)LESSP(ctx,2,local+4); /*<*/
	if (w==NIL) goto IF25447;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)UNIXCLOSE(ctx,1,local+4); /*unix:uclose*/
	w = local[3];
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK25352;
	goto IF25448;
IF25447:
	local[4]= NIL;
IF25448:
	local[4]= loadglobal(fqv[62]);
	ctx->vsp=local+5;
	w=(pointer)INSTANTIATE(ctx,1,local+4); /*instantiate*/
	local[4]= w;
	local[5]= local[4];
	local[6]= fqv[18];
	local[7]= local[2];
	local[8]= argv[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,5,local+5); /*send*/
	w = local[4];
	local[0]= w;
BLK25352:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP25430(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= makeint((eusinteger_t)0L);
	ctx->vsp=local+1;
	w=(pointer)ALARM(ctx,1,local+0); /*unix:alarm*/
	local[0]= makeint((eusinteger_t)14L);
	local[1]= loadglobal(fqv[68]);
	ctx->vsp=local+2;
	w=(pointer)SIGNAL(ctx,2,local+0); /*unix:signal*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*make-dgram-socket*/
static pointer F22290make_dgram_socket(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[54];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)2L);
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)SOCKET(ctx,3,local+1); /*unix:socket*/
	local[0] = w;
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)BIND(ctx,2,local+1); /*unix:bind*/
	w = local[0];
	local[0]= w;
BLK25512:
	ctx->vsp=local; return(local[0]);}

/*connect-server*/
static pointer F22293connect_server(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT25557;}
	local[0]= makeint((eusinteger_t)5L);
ENT25557:
ENT25556:
	if (n>3) maerror();
	local[1]= fqv[54];
	local[2]= makeint((eusinteger_t)2L);
	local[3]= fqv[69];
	local[4]= argv[0];
	local[5]= fqv[45];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F22263make_socket_address(ctx,6,local+1); /*make-socket-address*/
	local[1]= w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F22287make_client_socket_stream(ctx,2,local+1); /*make-client-socket-stream*/
	local[0]= w;
BLK25554:
	ctx->vsp=local; return(local[0]);}

/*select-stream*/
static pointer F22297select_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT25594;}
	local[0]= makeflt(0.0000000000000000000000e+00);
ENT25594:
ENT25593:
	if (n>2) maerror();
	local[1]= makeint((eusinteger_t)0L);
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0];
WHL25644:
	if (local[6]==NIL) goto WHX25645;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	w = local[5];
	if (!isint(w)) goto CON25697;
	local[7]= local[5];
	goto CON25695;
CON25697:
	local[7]= local[5];
	local[8]= fqv[2];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	goto CON25695;
CON25703:
	local[7]= NIL;
CON25695:
	local[4] = local[7];
	local[7]= makeint((eusinteger_t)1L);
	local[8]= local[1];
	local[9]= local[4];
	local[10]= makeint((eusinteger_t)1L);
	ctx->vsp=local+11;
	w=(pointer)DPB(ctx,4,local+7); /*dpb*/
	local[1] = w;
	local[7]= loadglobal(fqv[70]);
	local[8]= local[4];
	w = local[5];
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[8]); v=local[7];
	  v->c.vec.v[i]=w;}
	goto WHL25644;
WHX25645:
	local[7]= NIL;
BLK25646:
	w = NIL;
	local[5]= local[1];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)SELECT_READ(ctx,2,local+5); /*unix:select-read-fd*/
	local[1] = w;
WHL25746:
	local[5]= local[1];
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)GREATERP(ctx,2,local+5); /*>*/
	if (w==NIL) goto WHX25747;
	local[5]= local[1];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)LOGTEST(ctx,2,local+5); /*logtest*/
	if (w==NIL) goto IF25754;
	local[5]= loadglobal(fqv[70]);
	{ register eusinteger_t i=intval(local[3]);
	  w=(local[5]->c.vec.v[i]);}
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF25755;
IF25754:
	local[5]= NIL;
IF25755:
	local[5]= local[1];
	local[6]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+7;
	w=(pointer)ASH(ctx,2,local+5); /*ash*/
	local[1] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL25746;
WHX25747:
	local[5]= NIL;
BLK25748:
	w = local[2];
	local[0]= w;
BLK25591:
	ctx->vsp=local; return(local[0]);}

/*sigio-handler*/
static pointer F22302sigio_handler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= loadglobal(fqv[71]);
	ctx->vsp=local+2;
	w=(pointer)F22297select_stream(ctx,1,local+1); /*select-stream*/
	local[1]= w;
WHL25838:
	if (local[1]==NIL) goto WHX25839;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= loadglobal(fqv[72]);
	w = local[0];
	if (!isint(w)) goto IF25891;
	local[3]= local[0];
	goto IF25892;
IF25891:
	local[3]= local[0];
	local[4]= fqv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
IF25892:
	{ register eusinteger_t i=intval(local[3]);
	  w=(local[2]->c.vec.v[i]);}
	local[2]= w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,2,local+2); /*funcall*/
	goto WHL25838;
WHX25839:
	local[2]= NIL;
BLK25840:
	w = NIL;
	local[0]= w;
BLK25806:
	ctx->vsp=local; return(local[0]);}

/*def-async*/
static pointer F25911(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST25915:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	if ((w)->c.cons.cdr==NIL) goto CON25932;
	ctx->vsp=local+3;
	w=(pointer)GENSYM(ctx,0,local+3); /*gensym*/
	local[2] = w;
	local[3]= fqv[73];
	local[4]= local[2];
	w = local[0];
	ctx->vsp=local+5;
	w = cons(ctx,local[4],w);
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto CON25930;
CON25932:
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[0] = NIL;
	local[3]= local[0];
	goto CON25930;
CON25964:
	local[3]= NIL;
CON25930:
	local[3]= fqv[74];
	local[4]= fqv[75];
	local[5]= argv[0];
	local[6]= fqv[71];
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,1,local+6); /*list*/
	ctx->vsp=local+6;
	w = cons(ctx,local[5],w);
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[76];
	local[6]= fqv[77];
	local[7]= fqv[37];
	local[8]= fqv[78];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,1,local+7); /*list*/
	ctx->vsp=local+7;
	w = cons(ctx,local[6],w);
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[34];
	local[7]= fqv[79];
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[74];
	local[9]= fqv[80];
	local[10]= argv[0];
	local[11]= fqv[81];
	local[12]= fqv[82];
	local[13]= fqv[80];
	local[14]= argv[0];
	local[15]= fqv[83];
	local[16]= fqv[84];
	ctx->vsp=local+17;
	w=(pointer)LIST(ctx,1,local+16); /*list*/
	ctx->vsp=local+16;
	w = cons(ctx,local[15],w);
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	local[14]= fqv[85];
	ctx->vsp=local+15;
	w=(pointer)LIST(ctx,1,local+14); /*list*/
	ctx->vsp=local+14;
	w = cons(ctx,local[13],w);
	ctx->vsp=local+13;
	local[12]= cons(ctx,local[12],w);
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[80];
	local[11]= argv[0];
	local[12]= fqv[86];
	local[13]= fqv[87];
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	local[13]= w;
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
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
	local[9]= fqv[4];
	local[10]= argv[0];
	local[11]= fqv[6];
	local[12]= fqv[88];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	w = cons(ctx,local[10],w);
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	w = cons(ctx,local[7],w);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	local[7]= fqv[89];
	local[8]= fqv[90];
	local[9]= fqv[72];
	local[10]= fqv[34];
	local[11]= fqv[79];
	local[12]= argv[0];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	local[11]= cons(ctx,local[11],w);
	local[12]= argv[0];
	local[13]= fqv[4];
	local[14]= argv[0];
	local[15]= fqv[2];
	ctx->vsp=local+16;
	w=(pointer)LIST(ctx,1,local+15); /*list*/
	ctx->vsp=local+15;
	w = cons(ctx,local[14],w);
	ctx->vsp=local+14;
	local[13]= cons(ctx,local[13],w);
	ctx->vsp=local+14;
	w=(pointer)LIST(ctx,1,local+13); /*list*/
	ctx->vsp=local+13;
	w = cons(ctx,local[12],w);
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
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,1,local+9); /*list*/
	ctx->vsp=local+9;
	w = cons(ctx,local[8],w);
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
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
BLK25913:
	ctx->vsp=local; return(local[0]);}

/*:destinations*/
static pointer M26216broadcast_stream_destinations(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT26220;}
	local[0]= NIL;
ENT26220:
ENT26219:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF26236;
	local[1]= local[0];
	w = argv[0]->c.obj.iv[5];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[5] = cons(ctx,local[1],w);
	local[1]= argv[0]->c.obj.iv[5];
	goto IF26237;
IF26236:
	local[1]= NIL;
IF26237:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK26217:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M26257broadcast_stream_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[15]));
	local[2]= fqv[18];
	local[3]= fqv[12];
	local[4]= makeint((eusinteger_t)256L);
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	argv[0]->c.obj.iv[5] = argv[2];
	w = argv[0];
	local[0]= w;
BLK26258:
	ctx->vsp=local; return(local[0]);}

/*:flush*/
static pointer M26293broadcast_stream_flush(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[3];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF26310;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[1] = w;
	local[2]= local[1];
	goto IF26311;
IF26310:
	local[1] = argv[0]->c.obj.iv[2];
	local[2]= local[1];
IF26311:
	argv[0]->c.obj.iv[3] = makeint((eusinteger_t)0L);
	local[2]= NIL;
	local[3]= argv[0]->c.obj.iv[5];
WHL26358:
	if (local[3]==NIL) goto WHX26359;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[1];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)PRINC(ctx,2,local+4); /*princ*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)FINOUT(ctx,1,local+4); /*finish-output*/
	goto WHL26358;
WHX26359:
	local[4]= NIL;
BLK26360:
	w = NIL;
	w = T;
	local[0]= w;
BLK26294:
	ctx->vsp=local; return(local[0]);}

/*:close*/
static pointer M26421broadcast_stream_close(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[5];
WHL26451:
	if (local[1]==NIL) goto WHX26452;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)CLOSE(ctx,1,local+2); /*close*/
	goto WHL26451;
WHX26452:
	local[2]= NIL;
BLK26453:
	w = NIL;
	local[0]= w;
BLK26422:
	ctx->vsp=local; return(local[0]);}

/*make-broadcast-stream*/
static pointer F22311make_broadcast_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST26511:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= local[0];
WHL26541:
	if (local[4]==NIL) goto WHX26542;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)STREAMP(ctx,1,local+5); /*streamp*/
	if (w==NIL) goto IF26590;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF26591;
IF26590:
	local[5]= local[3];
	local[6]= fqv[91];
	local[7]= fqv[12];
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,3,local+5,&ftab[9],fqv[92]); /*open*/
	local[5]= w;
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
IF26591:
	goto WHL26541;
WHX26542:
	local[5]= NIL;
BLK26543:
	w = NIL;
	local[3]= loadglobal(fqv[93]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[18];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,3,local+4); /*send*/
	w = local[3];
	local[0]= w;
BLK26509:
	ctx->vsp=local; return(local[0]);}

/*read-buffer*/
static pointer F22314read_buffer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT26662;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT26662:
ENT26661:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[91];
	local[3]= fqv[11];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,3,local+1,&ftab[9],fqv[92]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP26699,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= makeint((eusinteger_t)0L);
WHL26716:
	local[5]= local[4];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto WHX26717;
	local[5]= local[4];
	local[6]= local[1];
	local[7]= fqv[94];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= argv[1];
	local[8]= local[0];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)MINUS(ctx,2,local+8); /*-*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)UNIXREAD(ctx,4,local+6); /*unix:uread*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[4] = w;
	goto WHL26716;
WHX26717:
	local[5]= NIL;
BLK26718:
	w = local[5];
	w = argv[1];
	ctx->vsp=local+4;
	UWP26699(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK26659:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP26699(ctx,n,argv,env)
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

/*write-buffer*/
static pointer F22317write_buffer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT26773;}
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
ENT26773:
ENT26772:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[91];
	local[3]= fqv[12];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,3,local+1,&ftab[9],fqv[92]); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP26810,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1];
	local[5]= argv[1];
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)UNIXWRITE(ctx,4,local+4); /*unix:write*/
	ctx->vsp=local+4;
	UWP26810(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK26770:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP26810(ctx,n,argv,env)
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

/*:init*/
static pointer M26859port_selector_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST26862:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= loadglobal(fqv[95]);
	local[2]= fqv[96];
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,3,local+1,&ftab[10],fqv[98]); /*make-array*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[95]);
	local[2]= fqv[96];
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,3,local+1,&ftab[10],fqv[98]); /*make-array*/
	argv[0]->c.obj.iv[3] = w;
	local[1]= loadglobal(fqv[95]);
	ctx->vsp=local+2;
	w=(*ftab[10])(ctx,1,local+1,&ftab[10],fqv[98]); /*make-array*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= NIL;
	local[2]= local[0];
WHL26921:
	if (local[2]==NIL) goto WHX26922;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= (pointer)get_sym_func(fqv[4]);
	local[4]= argv[0];
	local[5]= fqv[99];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,6,local+3); /*apply*/
	goto WHL26921;
WHX26922:
	local[3]= NIL;
BLK26923:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK26860:
	ctx->vsp=local; return(local[0]);}

/*:get-stream-fd*/
static pointer M27004port_selector_get_stream_fd(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)STREAMP(ctx,1,local+1); /*streamp*/
	if (w==NIL) goto CON27033;
	local[1]= argv[2];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON27031;
CON27033:
	w = argv[2];
	if (!isnum(w)) goto CON27045;
	local[1]= argv[2];
	goto CON27031;
CON27045:
	local[1]= argv[2];
	local[2]= fqv[94];
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,2,local+1,&ftab[11],fqv[100]); /*find-method*/
	if (w==NIL) goto CON27051;
	local[1]= argv[2];
	local[2]= fqv[94];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	goto CON27031;
CON27051:
	local[1]= fqv[101];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto CON27031;
CON27066:
	local[1]= NIL;
CON27031:
	local[0] = local[1];
	local[1]= local[0];
	local[2]= loadglobal(fqv[95]);
	ctx->vsp=local+3;
	w=(pointer)GREQP(ctx,2,local+1); /*>=*/
	if (w==NIL) goto IF27075;
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF27076;
IF27075:
	local[1]= NIL;
IF27076:
	w = local[0];
	local[0]= w;
BLK27005:
	ctx->vsp=local; return(local[0]);}

/*:add-port*/
static pointer M27089port_selector_add_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
RST27092:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-4);
	local[1]= argv[0];
	local[2]= fqv[103];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,3,local+4); /*list**/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,3,local+2); /*aset*/
	local[0]= w;
BLK27090:
	ctx->vsp=local; return(local[0]);}

/*:remove-port*/
static pointer M27143port_selector_remove_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[103];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0];
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)ASET(ctx,3,local+1); /*aset*/
	local[0]= w;
BLK27144:
	ctx->vsp=local; return(local[0]);}

/*:streams*/
static pointer M27187port_selector_streams(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= loadglobal(fqv[95]);
WHL27232:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX27233;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	if (w==NIL) goto IF27241;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF27242;
IF27241:
	local[3]= NIL;
IF27242:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL27232;
WHX27233:
	local[3]= NIL;
BLK27234:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK27188:
	ctx->vsp=local; return(local[0]);}

/*:fds*/
static pointer M27282port_selector_fds(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= loadglobal(fqv[95]);
WHL27327:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX27328;
	local[3]= makeint((eusinteger_t)1L);
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)NUMEQUAL(ctx,2,local+3); /*=*/
	if (w==NIL) goto IF27336;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	local[3]= local[0];
	goto IF27337;
IF27336:
	local[3]= NIL;
IF27337:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL27327;
WHX27328:
	local[3]= NIL;
BLK27329:
	w = NIL;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)NREVERSE(ctx,1,local+1); /*nreverse*/
	local[0]= w;
BLK27283:
	ctx->vsp=local; return(local[0]);}

/*:select*/
static pointer M27374port_selector_select(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT27378;}
	local[0]= makeflt(9.9999999999999977795540e-02);
ENT27378:
ENT27377:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,2,local+4,&ftab[4],fqv[24]); /*replace*/
	local[4]= argv[0]->c.obj.iv[3];
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SELECT(ctx,4,local+4); /*unix:select*/
	local[1] = w;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)GREATERP(ctx,2,local+4); /*>*/
	if (w==NIL) goto IF27422;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= loadglobal(fqv[95]);
WHL27451:
	local[6]= local[4];
	w = local[5];
	if ((eusinteger_t)local[6] >= (eusinteger_t)w) goto WHX27452;
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)1L);
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto IF27461;
	local[6]= argv[0]->c.obj.iv[2];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(*ftab[12])(ctx,1,local+6,&ftab[12],fqv[104]); /*functionp*/
	if (w==NIL) goto IF27501;
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,2,local+6); /*apply*/
	local[6]= w;
	goto IF27502;
IF27501:
	local[6]= (pointer)get_sym_func(fqv[4]);
	local[7]= local[2];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	local[6]= w;
IF27502:
	goto IF27462;
IF27461:
	local[6]= NIL;
IF27462:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	goto WHL27451;
WHX27452:
	local[6]= NIL;
BLK27453:
	w = T;
	local[4]= w;
	goto IF27423;
IF27422:
	local[4]= NIL;
IF27423:
	w = local[4];
	local[0]= w;
BLK27375:
	ctx->vsp=local; return(local[0]);}

/*:select-loop*/
static pointer M27535port_selector_select_loop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT27540;}
	local[0]= makeflt(9.9999999999999977795540e-02);
ENT27540:
	if (n>=4) { local[1]=(argv[3]); goto ENT27539;}
	local[1]= NIL;
ENT27539:
ENT27538:
	ctx->vsp=local+2;
	local[2]= minilist(ctx,&argv[n],n-4);
	{jmp_buf jb;
	w = fqv[105];
	ctx->vsp=local+3;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT27561;}
WHL27568:
	if (T==NIL) goto WHX27569;
	local[9]= argv[0];
	local[10]= fqv[106];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,3,local+9); /*send*/
	if (local[1]==NIL) goto IF27582;
	local[9]= local[1];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)APPLY(ctx,2,local+9); /*apply*/
	local[9]= w;
	goto IF27583;
IF27582:
	local[9]= NIL;
IF27583:
	goto WHL27568;
WHX27569:
	local[9]= NIL;
BLK27570:
	w = local[9];
CAT27561:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK27536:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___stream(ctx,n,argv,env)
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
	local[0]= fqv[107];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF27599;
	local[0]= fqv[108];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[109],w);
	goto IF27600;
IF27599:
	local[0]= fqv[110];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF27600:
	local[0]= fqv[111];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22379io_stream_instream,fqv[112],fqv[28],fqv[113]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22418io_stream_outstream,fqv[114],fqv[28],fqv[115]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22457io_stream_infd,fqv[2],fqv[28],fqv[116]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22476io_stream_outfd,fqv[3],fqv[28],fqv[117]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22495io_stream_in,fqv[118],fqv[28],fqv[119]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22519io_stream_out,fqv[120],fqv[28],fqv[121]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22543io_stream_flag,fqv[5],fqv[28],fqv[122]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22562io_stream_async,fqv[6],fqv[28],fqv[123]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22584io_stream_fname,fqv[7],fqv[28],fqv[124]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22603io_stream_init,fqv[18],fqv[28],fqv[125]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22650stream_reset,fqv[10],fqv[31],fqv[126]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22689stream_discard,fqv[26],fqv[31],fqv[127]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22725stream_count,fqv[128],fqv[31],fqv[129]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22741stream_tail,fqv[130],fqv[31],fqv[131]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22779stream_chars_left,fqv[20],fqv[31],fqv[132]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22799stream_tail_string,fqv[22],fqv[31],fqv[133]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22818stream_buffer,fqv[134],fqv[31],fqv[135]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M22886stream_init,fqv[18],fqv[31],fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F22216reset_stream,fqv[138]);
	local[0]= fqv[85];
	local[1]= fqv[139];
	local[2]= makeint((eusinteger_t)8192L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[83];
	local[1]= fqv[139];
	local[2]= makeint((eusinteger_t)3L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[81];
	local[1]= fqv[139];
	local[2]= makeint((eusinteger_t)4L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[86];
	local[1]= fqv[139];
	local[2]= makeint((eusinteger_t)8L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23004file_stream_fd,fqv[94],fqv[29],fqv[140]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23020file_stream_instream,fqv[112],fqv[29],fqv[141]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23043file_stream_outstream,fqv[114],fqv[29],fqv[142]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23066file_stream_infd,fqv[2],fqv[29],fqv[143]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23089file_stream_outfd,fqv[3],fqv[29],fqv[144]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23112file_stream_fname,fqv[7],fqv[29],fqv[145]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23128file_stream_flag,fqv[5],fqv[29],fqv[146]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23145file_stream_async,fqv[6],fqv[29],fqv[147]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23204file_stream_nonblock,fqv[148],fqv[29],fqv[149]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23266file_stream_prin1,fqv[16],fqv[29],fqv[150]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23307file_stream_init,fqv[18],fqv[29],fqv[151]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23383file_stream_read_bytes,fqv[152],fqv[29],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M23560file_stream_read_bytes_eof,fqv[154],fqv[29],fqv[155]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[156],module,F22227make_two_way_stream,fqv[157]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[158],module,F22230make_msgq_input_stream,fqv[159]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[160],module,F22233make_msgq_output_stream,fqv[161]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[33],module,F22237make_string_input_stream,fqv[162]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[41],module,F22240make_string_output_stream,fqv[163]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[164],module,F23946,fqv[165]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[166],module,F24114,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[42],module,F22245get_output_stream_string,fqv[168]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[169],module,F22248read_from_string,fqv[170]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[171],module,F22251princ_to_string,fqv[172]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[173],module,F22254prin1_to_string,fqv[174]);
	local[0]= fqv[51];
	local[1]= fqv[175];
	local[2]= fqv[51];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[9]);
	local[5]= fqv[177];
	local[6]= fqv[39];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= fqv[179];
	local[11]= fqv[180];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24325socket_address_domain,fqv[54],fqv[51],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24344socket_address_port,fqv[45],fqv[51],fqv[184]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24366socket_address_host,fqv[69],fqv[51],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24383socket_address_next_port,fqv[186],fqv[51],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24412socket_address_prin1,fqv[16],fqv[51],fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F22263make_socket_address,fqv[190]);
	local[0]= fqv[58];
	local[1]= fqv[175];
	local[2]= fqv[58];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[191]);
	local[5]= fqv[177];
	local[6]= fqv[192];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[193];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24766socket_port_domain,fqv[54],fqv[58],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24785socket_port_address,fqv[63],fqv[58],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24801socket_port_id,fqv[196],fqv[58],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24817socket_port_fd,fqv[94],fqv[58],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24833socket_port_infd,fqv[2],fqv[58],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24849socket_port_listen,fqv[57],fqv[58],fqv[200]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24874socket_port_accept,fqv[61],fqv[58],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24891socket_port_flag,fqv[5],fqv[58],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24908socket_port_async,fqv[6],fqv[58],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M24970socket_port_init,fqv[18],fqv[58],fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[205],module,F22272make_socket_port,fqv[206]);
	local[0]= fqv[62];
	local[1]= fqv[175];
	local[2]= fqv[62];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[28]);
	local[5]= fqv[177];
	local[6]= fqv[207];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M25115socket_stream_domain,fqv[54],fqv[62],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M25134socket_stream_init,fqv[18],fqv[62],fqv[209]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[210],module,F22280make_server_socket_stream,fqv[211]);
	local[0]= fqv[68];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF27872;
	local[0]= fqv[68];
	local[1]= fqv[212];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[68];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF27895;
	local[0]= fqv[68];
	local[1]= fqv[175];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF27896;
IF27895:
	local[0]= NIL;
IF27896:
	local[0]= fqv[68];
	goto IF27873;
IF27872:
	local[0]= NIL;
IF27873:
	ctx->vsp=local+0;
	compfun(ctx,fqv[67],module,F22284connect_sigalarm_handler,fqv[213]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F22287make_client_socket_stream,fqv[215]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F22290make_dgram_socket,fqv[217]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[218],module,F22293connect_server,fqv[219]);
	local[0]= fqv[70];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF27923;
	local[0]= fqv[70];
	local[1]= fqv[212];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[70];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF27946;
	local[0]= fqv[70];
	local[1]= fqv[175];
	local[2]= loadglobal(fqv[220]);
	local[3]= makeint((eusinteger_t)32L);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF27947;
IF27946:
	local[0]= NIL;
IF27947:
	local[0]= fqv[70];
	goto IF27924;
IF27923:
	local[0]= NIL;
IF27924:
	ctx->vsp=local+0;
	compfun(ctx,fqv[221],module,F22297select_stream,fqv[222]);
	local[0]= fqv[71];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF27972;
	local[0]= fqv[71];
	local[1]= fqv[212];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[71];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF27995;
	local[0]= fqv[71];
	local[1]= fqv[175];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF27996;
IF27995:
	local[0]= NIL;
IF27996:
	local[0]= fqv[71];
	goto IF27973;
IF27972:
	local[0]= NIL;
IF27973:
	local[0]= fqv[72];
	local[1]= fqv[212];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF28015;
	local[0]= fqv[72];
	local[1]= fqv[212];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[72];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF28038;
	local[0]= fqv[72];
	local[1]= fqv[175];
	local[2]= loadglobal(fqv[220]);
	local[3]= makeint((eusinteger_t)32L);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,2,local+2); /*instantiate*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF28039;
IF28038:
	local[0]= NIL;
IF28039:
	local[0]= fqv[72];
	goto IF28016;
IF28015:
	local[0]= NIL;
IF28016:
	ctx->vsp=local+0;
	compfun(ctx,fqv[78],module,F22302sigio_handler,fqv[223]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[224],module,F25911,fqv[225]);
	local[0]= fqv[93];
	local[1]= fqv[175];
	local[2]= fqv[93];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[31]);
	local[5]= fqv[177];
	local[6]= fqv[226];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26216broadcast_stream_destinations,fqv[227],fqv[93],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26257broadcast_stream_init,fqv[18],fqv[93],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26293broadcast_stream_flush,fqv[230],fqv[93],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26421broadcast_stream_close,fqv[232],fqv[93],fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F22311make_broadcast_stream,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F22314read_buffer,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F22317write_buffer,fqv[239]);
	local[0]= fqv[95];
	local[1]= fqv[175];
	local[2]= makeint((eusinteger_t)64L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[240];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[241];
	local[1]= fqv[175];
	local[2]= fqv[241];
	local[3]= fqv[176];
	local[4]= loadglobal(fqv[242]);
	local[5]= fqv[177];
	local[6]= fqv[243];
	local[7]= fqv[178];
	local[8]= NIL;
	local[9]= fqv[96];
	local[10]= NIL;
	local[11]= fqv[180];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[181];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[13])(ctx,13,local+2,&ftab[13],fqv[182]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M26859port_selector_init,fqv[18],fqv[241],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27004port_selector_get_stream_fd,fqv[103],fqv[241],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27089port_selector_add_port,fqv[99],fqv[241],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27143port_selector_remove_port,fqv[247],fqv[241],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27187port_selector_streams,fqv[249],fqv[241],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27282port_selector_fds,fqv[251],fqv[241],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27374port_selector_select,fqv[106],fqv[241],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M27535port_selector_select_loop,fqv[105],fqv[241],fqv[254]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<14; i++) ftab[i]=fcallx;
}
