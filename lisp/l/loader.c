/* ./loader.c :  entry=loader */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "loader.h"
#pragma init (register_loader)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___loader();
extern pointer build_quote_vector();
static int register_loader()
  { add_module_initializer("___loader", ___loader);}

static pointer F29046file_write_date();
static pointer F29049file_newer();
static pointer F29052open();
static pointer F29057probe_file();
static pointer F29061object_file_p();
static pointer F29064path_list();
static pointer F29067find_executable();
static pointer F29070system__txtload();
static pointer F29080load_module_file_name();
static pointer F29083gencname_tail();
static pointer F29086load();
static pointer F29089load_files();
static pointer F29092read_file();
static pointer F29095read_strings();
static pointer F29098read_lines();
static pointer F29101read_lists();
static pointer F29104read_binary_file();
static pointer F29107read_lines_till_eof();
static pointer F29112load_library();
static pointer F29115dump_object();
static pointer F29118dump_structure();
static pointer F29122file_size();
static pointer F29125directory_p();
static pointer F29128map_file();
static pointer F29130provide();
static pointer F29132require();

/*file-write-date*/
static pointer F29046file_write_date(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)9L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,1,local+1,&ftab[0],fqv[0]); /*namestring*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)STAT(ctx,1,local+1); /*unix:stat*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK29182:
	ctx->vsp=local; return(local[0]);}

/*file-newer*/
static pointer F29049file_newer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)F29057probe_file(ctx,1,local+0); /*probe-file*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]!=NIL) goto OR29214;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F29057probe_file(ctx,1,local+0); /*probe-file*/
	local[0]= ((w)==NIL?T:NIL);
	if (local[0]!=NIL) goto OR29214;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F29046file_write_date(ctx,1,local+0); /*file-write-date*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F29046file_write_date(ctx,1,local+1); /*file-write-date*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	local[0]= w;
OR29214:
	w = local[0];
	local[0]= w;
BLK29202:
	ctx->vsp=local; return(local[0]);}

/*open*/
static pointer F29052open(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[1], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY29256;
	local[0] = fqv[2];
KEY29256:
	if (n & (1<<1)) goto KEY29263;
	local[1] = fqv[3];
KEY29263:
	if (n & (1<<2)) goto KEY29270;
	local[2] = fqv[4];
KEY29270:
	if (n & (1<<3)) goto KEY29277;
	local[3] = makeint((eusinteger_t)420L);
KEY29277:
	if (n & (1<<4)) goto KEY29282;
	local[4] = makeint((eusinteger_t)512L);
KEY29282:
	local[5]= makeint((eusinteger_t)0L);
	local[6]= NIL;
	local[7]= NIL;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(pointer)STREAMP(ctx,1,local+8); /*streamp*/
	if (w==NIL) goto IF29307;
	local[8]= argv[0];
	ctx->vsp=local+9;
	w=(*ftab[1])(ctx,1,local+8,&ftab[1],fqv[5]); /*io-stream-p*/
	if (w==NIL) goto IF29315;
	local[7] = *(ovafptr(*(ovafptr(argv[0],fqv[6])),fqv[7]));
	local[8]= local[7];
	goto IF29316;
IF29315:
	local[7] = *(ovafptr(argv[0],fqv[7]));
	local[8]= local[7];
IF29316:
	goto IF29308;
IF29307:
	local[7] = argv[0];
	local[8]= local[7];
IF29308:
	local[8]= local[7];
	ctx->vsp=local+9;
	w=(*ftab[0])(ctx,1,local+8,&ftab[0],fqv[0]); /*namestring*/
	local[7] = w;
	local[8]= local[0];
	local[9]= local[8];
	if (fqv[2]!=local[9]) goto IF29368;
	local[5] = makeint((eusinteger_t)0L);
	local[9]= local[2];
	if (fqv[4]!=local[9]) goto IF29385;
	local[2] = fqv[8];
	local[9]= local[2];
	goto IF29386;
IF29385:
	local[9]= NIL;
IF29386:
	local[9]= local[2];
	if (fqv[9]!=local[9]) goto IF29401;
	local[9]= local[5];
	local[10]= makeint((eusinteger_t)64L);
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[5] = w;
	local[9]= local[5];
	goto IF29402;
IF29401:
	local[9]= NIL;
IF29402:
	local[9]= local[7];
	local[10]= local[5];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[10]); /*system:openfile*/
	local[6] = w;
	local[9]= local[6];
	goto IF29369;
IF29368:
	local[9]= local[8];
	w = fqv[11];
	if (memq(local[9],w)==NIL) goto IF29433;
	local[9]= local[0];
	if (fqv[12]!=local[9]) goto IF29447;
	local[5] = makeint((eusinteger_t)2L);
	local[9]= local[5];
	goto IF29448;
IF29447:
	local[5] = makeint((eusinteger_t)1L);
	local[9]= local[5];
IF29448:
	local[9]= local[1];
	local[10]= local[9];
	if (fqv[13]!=local[10]) goto IF29479;
	local[10]= local[5];
	local[11]= makeint((eusinteger_t)1024L);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29480;
IF29479:
	local[10]= local[9];
	w = fqv[14];
	if (memq(local[10],w)==NIL) goto IF29498;
	local[10]= local[5];
	local[11]= makeint((eusinteger_t)64L);
	local[12]= makeint((eusinteger_t)512L);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,3,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29499;
IF29498:
	local[10]= local[9];
	if (fqv[15]!=local[10]) goto IF29519;
	local[10]= local[5];
	local[11]= makeint((eusinteger_t)64L);
	ctx->vsp=local+12;
	w=(pointer)PLUS(ctx,2,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29520;
IF29519:
	local[10]= local[9];
	w = fqv[16];
	if (memq(local[10],w)==NIL) goto IF29538;
	local[10]= local[5];
	local[11]= makeint((eusinteger_t)64L);
	local[12]= makeint((eusinteger_t)128L);
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,3,local+10); /*+*/
	local[5] = w;
	local[10]= local[5];
	goto IF29539;
IF29538:
	if (T==NIL) goto IF29559;
	local[10]= fqv[17];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF29560;
IF29559:
	local[10]= NIL;
IF29560:
IF29539:
IF29520:
IF29499:
IF29480:
	w = local[10];
	local[9]= local[2];
	local[10]= local[9];
	if (fqv[8]!=local[10]) goto IF29581;
	local[10]= local[5];
	local[11]= makeint((eusinteger_t)64L);
	ctx->vsp=local+12;
	w=(pointer)LOGNOT(ctx,1,local+11); /*lognot*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(pointer)LOGAND(ctx,2,local+10); /*logand*/
	local[5] = w;
	local[10]= local[5];
	goto IF29582;
IF29581:
	local[10]= local[9];
	if (fqv[9]!=local[10]) goto IF29601;
	local[10]= local[5];
	local[11]= makeint((eusinteger_t)64L);
	ctx->vsp=local+12;
	w=(pointer)LOGIOR(ctx,2,local+10); /*logior*/
	local[5] = w;
	local[10]= local[5];
	goto IF29602;
IF29601:
	local[10]= local[9];
	if (fqv[4]!=local[10]) goto IF29619;
	local[10]= local[1];
	w = fqv[18];
	if (memq(local[10],w)!=NIL) goto IF29627;
	local[10]= local[5];
	local[11]= makeint((eusinteger_t)64L);
	ctx->vsp=local+12;
	w=(pointer)LOGIOR(ctx,2,local+10); /*logior*/
	local[5] = w;
	local[10]= local[5];
	goto IF29628;
IF29627:
	local[10]= NIL;
IF29628:
	goto IF29620;
IF29619:
	local[10]= local[9];
	if (fqv[19]!=local[10]) goto IF29648;
	local[10]= NIL;
	goto IF29649;
IF29648:
	if (T==NIL) goto IF29656;
	local[10]= fqv[20];
	ctx->vsp=local+11;
	w=(pointer)SIGERROR(ctx,1,local+10); /*error*/
	local[10]= w;
	goto IF29657;
IF29656:
	local[10]= NIL;
IF29657:
IF29649:
IF29620:
IF29602:
IF29582:
	w = local[10];
	local[9]= local[7];
	local[10]= local[5];
	local[11]= local[3];
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(*ftab[2])(ctx,4,local+9,&ftab[2],fqv[10]); /*system:openfile*/
	local[6] = w;
	local[9]= local[6];
	goto IF29434;
IF29433:
	if (T==NIL) goto IF29676;
	local[9]= fqv[21];
	ctx->vsp=local+10;
	w=(pointer)SIGERROR(ctx,1,local+9); /*error*/
	local[9]= w;
	goto IF29677;
IF29676:
	local[9]= NIL;
IF29677:
IF29434:
IF29369:
	w = local[9];
	w = local[6];
	if (!isnum(w)) goto IF29686;
	if (local[2]!=NIL) goto IF29695;
	w = NIL;
	ctx->vsp=local+8;
	local[0]=w;
	goto BLK29243;
	goto IF29696;
IF29695:
	local[8]= loadglobal(fqv[22]);
	local[9]= fqv[23];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SIGERROR(ctx,1,local+8); /*error*/
	local[8]= w;
IF29696:
	goto IF29687;
IF29686:
	local[8]= NIL;
IF29687:
	w = local[6];
	local[0]= w;
BLK29243:
	ctx->vsp=local; return(local[0]);}

/*with-open-file*/
static pointer F29718(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST29721:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= fqv[24];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[25];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	local[5]= NIL;
	ctx->vsp=local+6;
	w=(pointer)APPEND(ctx,2,local+4); /*append*/
	ctx->vsp=local+4;
	local[3]= cons(ctx,local[3],w);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= fqv[26];
	local[4]= fqv[27];
	local[5]= local[0];
	local[6]= NIL;
	ctx->vsp=local+7;
	w=(pointer)APPEND(ctx,2,local+5); /*append*/
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= fqv[28];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
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
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,1,local+3); /*list*/
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	ctx->vsp=local+2;
	w = cons(ctx,local[1],w);
	local[0]= w;
BLK29719:
	ctx->vsp=local; return(local[0]);}

/*probe-file*/
static pointer F29057probe_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)STAT(ctx,1,local+1); /*unix:stat*/
	local[1]= w;
	w = local[1];
	if (!iscons(w)) goto IF29819;
	local[2]= makeint((eusinteger_t)61440L);
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	local[3]= local[2];
	if (fqv[29]!=local[3]) goto IF29847;
	local[3]= fqv[30];
	goto IF29848;
IF29847:
	local[3]= local[2];
	if (fqv[31]!=local[3]) goto IF29857;
	local[3]= fqv[32];
	goto IF29858;
IF29857:
	local[3]= local[2];
	if (fqv[33]!=local[3]) goto IF29867;
	local[3]= fqv[34];
	goto IF29868;
IF29867:
	local[3]= local[2];
	if (fqv[35]!=local[3]) goto IF29877;
	local[3]= fqv[36];
	goto IF29878;
IF29877:
	local[3]= local[2];
	if (fqv[37]!=local[3]) goto IF29887;
	local[3]= fqv[38];
	goto IF29888;
IF29887:
	local[3]= local[2];
	if (fqv[39]!=local[3]) goto IF29897;
	local[3]= fqv[40];
	goto IF29898;
IF29897:
	local[3]= local[2];
	if (fqv[41]!=local[3]) goto IF29907;
	local[3]= fqv[42];
	goto IF29908;
IF29907:
	local[3]= NIL;
IF29908:
IF29898:
IF29888:
IF29878:
IF29868:
IF29858:
IF29848:
	w = local[3];
	local[2]= w;
	goto IF29820;
IF29819:
	local[2]= NIL;
IF29820:
	w = local[2];
	local[0]= w;
BLK29793:
	ctx->vsp=local; return(local[0]);}

/*object-file-p*/
static pointer F29061object_file_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET29935,env,argv,local);
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET29935(ctx,1,local+1,w);
	local[1]= w;
	local[2]= loadglobal(fqv[43]);
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[6];
	local[6]= w;
	local[7]= T;
	local[8]= NIL;
TAG30032:
	if (local[2]==NIL) goto OR30039;
	local[9]= local[4];
	local[10]= local[5];
	ctx->vsp=local+11;
	w=(pointer)GREQP(ctx,2,local+9); /*>=*/
	if (w!=NIL) goto OR30039;
	if (local[8]!=NIL) goto OR30039;
	goto IF30037;
OR30039:
	w = local[7];
	ctx->vsp=local+9;
	local[3]=w;
	goto BLK29961;
	goto IF30038;
IF30037:
	local[9]= NIL;
IF30038:
	if (local[6]==NIL) goto IF30061;
	local[9]= local[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(pointer)EQ(ctx,2,local+9); /*eql*/
	if (w!=NIL) goto IF30061;
	local[9]= local[3];
	w = local[6];
	if (memq(local[9],w)!=NIL) goto IF30061;
	local[7] = NIL;
	local[8] = T;
	local[9]= local[8];
	goto IF30062;
IF30061:
	local[9]= NIL;
IF30062:
	local[9]= local[1];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ELT(ctx,2,local+9); /*elt*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)ADD1(ctx,1,local+10); /*1+*/
	local[10]= w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[11];
	local[11]= w;
	local[3] = local[9];
	local[4] = local[10];
	local[6] = local[11];
	w = NIL;
	ctx->vsp=local+9;
	goto TAG30032;
	w = NIL;
	local[3]= w;
BLK29961:
	w = local[3];
	local[0]= w;
BLK29923:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET29935(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)4L);
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[44]); /*make-string*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F29052open(ctx,1,local+1); /*open*/
	local[1]= w;
	ctx->vsp=local+2;
	w = makeclosure(codevec,quotevec,UWP30211,env,argv,local);
	local[2]=(pointer)(ctx->protfp); local[3]=w;
	ctx->protfp=(struct protectframe *)(local+2);
	local[4]= local[1]->c.obj.iv[5];
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(pointer)UNIXREAD(ctx,3,local+4); /*unix:uread*/
	ctx->vsp=local+4;
	UWP30211(ctx,0,local+4,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP30211(ctx,n,argv,env)
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

/*path-list*/
static pointer F29064path_list(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT30248;}
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)GETENV(ctx,1,local+0); /*unix:getenv*/
	local[0]= w;
ENT30248:
ENT30247:
	if (n>1) maerror();
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	local[4]= NIL;
WHL30278:
	local[5]= makeint((eusinteger_t)58L);
	local[6]= local[0];
	local[7]= fqv[46];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(*ftab[4])(ctx,4,local+5,&ftab[4],fqv[47]); /*position*/
	local[3] = w;
	if (local[3]==NIL) goto WHX30279;
	local[5]= local[0];
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,3,local+5); /*subseq*/
	local[4] = w;
	local[5]= loadglobal(fqv[22]);
	local[6]= local[4];
	local[7]= fqv[48];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[2] = w;
	goto WHL30278;
WHX30279:
	local[5]= NIL;
BLK30280:
	local[5]= loadglobal(fqv[22]);
	local[6]= local[0];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	local[7]= fqv[49];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,3,local+5); /*concatenate*/
	local[5]= w;
	w = local[1];
	ctx->vsp=local+6;
	local[1] = cons(ctx,local[5],w);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)NREVERSE(ctx,1,local+5); /*nreverse*/
	local[0]= w;
BLK30245:
	ctx->vsp=local; return(local[0]);}

/*find-executable*/
static pointer F29067find_executable(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F29057probe_file(ctx,1,local+0); /*probe-file*/
	if (w==NIL) goto IF30366;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[5])(ctx,1,local+0,&ftab[5],fqv[50]); /*truename*/
	local[0]= w;
	goto IF30367;
IF30366:
	ctx->vsp=local+0;
	w=(pointer)F29064path_list(ctx,0,local+0); /*path-list*/
	local[0]= w;
	local[1]= NIL;
WHL30390:
	if (local[0]==NIL) goto WHX30391;
	local[2]= argv[0];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,1,local+2,&ftab[0],fqv[0]); /*namestring*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)F29057probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto IF30443;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[50]); /*truename*/
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK30356;
	goto IF30444;
IF30443:
	local[2]= NIL;
IF30444:
	goto WHL30390;
WHX30391:
	local[2]= NIL;
BLK30392:
	w = NIL;
	local[0]= w;
IF30367:
	w = local[0];
	local[0]= w;
BLK30356:
	ctx->vsp=local; return(local[0]);}

/*system::txtload*/
static pointer F29070system__txtload(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT30466;}
	local[0]= NIL;
ENT30466:
ENT30465:
	if (n>2) maerror();
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F29052open(ctx,1,local+4); /*open*/
	local[4]= w;
	ctx->vsp=local+5;
	w = makeclosure(codevec,quotevec,UWP30510,env,argv,local);
	local[5]=(pointer)(ctx->protfp); local[6]=w;
	ctx->protfp=(struct protectframe *)(local+5);
WHL30517:
	local[7]= local[4];
	local[8]= NIL;
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)READ(ctx,3,local+7); /*read*/
	local[2] = w;
	local[7]= local[2];
	if (local[1]==local[7]) goto WHX30518;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)EVAL(ctx,1,local+7); /*eval*/
	local[3] = w;
	if (local[0]==NIL) goto IF30543;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)PRINT(ctx,1,local+7); /*print*/
	local[7]= w;
	goto IF30544;
IF30543:
	local[7]= NIL;
IF30544:
	goto WHL30517;
WHX30518:
	local[7]= NIL;
BLK30519:
	w = local[7];
	ctx->vsp=local+7;
	UWP30510(ctx,0,local+7,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK30463:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP30510(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[4];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load-module-file-name*/
static pointer F29080load_module_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+1;
	w=(*ftab[7])(ctx,1,local+0,&ftab[7],fqv[52]); /*pathname-name*/
	local[0]= w;
BLK30580:
	ctx->vsp=local; return(local[0]);}

/*gencname-tail*/
static pointer F29083gencname_tail(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST30603:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET30614,env,argv,local);
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET30616,env,argv,local);
	local[3]= local[0];
	w = local[2];
	ctx->vsp=local+4;
	w=FLET30616(ctx,1,local+3,w);
	local[0]= w;
BLK30601:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30614(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)97L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND30639;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)122L);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
AND30639:
	if (local[0]!=NIL) goto OR30635;
	local[0]= makeint((eusinteger_t)65L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND30652;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)90L);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
AND30652:
	if (local[0]!=NIL) goto OR30635;
	local[0]= makeint((eusinteger_t)48L);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
	if (w==NIL) goto AND30665;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)57L);
	ctx->vsp=local+2;
	w=(pointer)LSEQP(ctx,2,local+0); /*<=*/
	local[0]= w;
AND30665:
	if (local[0]!=NIL) goto OR30635;
	local[0]= argv[0];
	local[1]= makeint((eusinteger_t)95L);
	ctx->vsp=local+2;
	w=(pointer)NUMEQUAL(ctx,2,local+0); /*=*/
	local[0]= w;
OR30635:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30616(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO30698,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[53];
	local[3]= fqv[54];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,4,local+0,&ftab[8],fqv[55]); /*reduce*/
	local[0]= w;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO30711,env,argv,local);
	local[2]= local[0];
	local[3]= loadglobal(fqv[56]);
	ctx->vsp=local+4;
	w=(pointer)COERCE(ctx,2,local+2); /*coerce*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	local[2]= loadglobal(fqv[22]);
	ctx->vsp=local+3;
	w=(pointer)COERCE(ctx,2,local+1); /*coerce*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO30698(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[57];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO30711(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env0->c.clo.env2[1];
	ctx->vsp=local+1;
	w=FLET30614(ctx,1,local+0,w);
	if (w==NIL) goto IF30749;
	local[0]= argv[0];
	goto IF30750;
IF30749:
	local[0]= makeint((eusinteger_t)95L);
IF30750:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load*/
static pointer F29086load(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[58], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY30778;
	local[0] = NIL;
KEY30778:
	if (n & (1<<1)) goto KEY30783;
	local[8]= loadglobal(fqv[22]);
	local[9]= fqv[59];
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(*ftab[7])(ctx,1,local+10,&ftab[7],fqv[52]); /*pathname-name*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)CONCATENATE(ctx,3,local+8); /*concatenate*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F29083gencname_tail(ctx,1,local+8); /*gencname-tail*/
	local[1] = w;
KEY30783:
	if (n & (1<<2)) goto KEY30796;
	local[2] = NIL;
KEY30796:
	if (n & (1<<3)) goto KEY30801;
	local[3] = fqv[60];
KEY30801:
	if (n & (1<<4)) goto KEY30806;
	local[4] = fqv[61];
KEY30806:
	if (n & (1<<5)) goto KEY30811;
	local[5] = loadglobal(fqv[62]);
KEY30811:
	if (n & (1<<6)) goto KEY30818;
	local[6] = NIL;
KEY30818:
	if (n & (1<<7)) goto KEY30823;
	local[7] = loadglobal(fqv[63]);
KEY30823:
	local[8]= loadglobal(fqv[63]);
	w = local[8];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[63],w);
	local[11]= NIL;
	local[12]= NIL;
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,FLET30850,env,argv,local);
	ctx->vsp=local+14;
	local[14]= makeclosure(codevec,quotevec,FLET30852,env,argv,local);
	ctx->vsp=local+15;
	local[15]= makeclosure(codevec,quotevec,FLET30854,env,argv,local);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[9])(ctx,1,local+16,&ftab[9],fqv[64]); /*pathname*/
	argv[0] = w;
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)FINDPACKAGE(ctx,1,local+16); /*find-package*/
	local[16]= w;
	storeglobal(fqv[63],w);
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,1,local+16,&ftab[10],fqv[65]); /*pathname-directory*/
	if (w==NIL) goto IF30876;
	local[16]= argv[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,1,local+16,&ftab[10],fqv[65]); /*pathname-directory*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	local[17]= fqv[66];
	ctx->vsp=local+18;
	w=(pointer)EQ(ctx,2,local+16); /*eql*/
	if (w==NIL) goto IF30876;
	local[16]= argv[0];
	w = local[15];
	ctx->vsp=local+17;
	w=FLET30854(ctx,1,local+16,w);
	local[12] = w;
	if (local[12]!=NIL) goto IF30899;
	local[16]= fqv[67];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)SIGERROR(ctx,2,local+16); /*error*/
	local[16]= w;
	goto IF30900;
IF30899:
	local[16]= local[12];
IF30900:
	goto IF30877;
IF30876:
	local[16]= NIL;
	local[17]= loadglobal(fqv[68]);
	local[18]= (pointer)get_sym_func(fqv[0]);
	local[19]= loadglobal(fqv[69]);
	ctx->vsp=local+20;
	w=(pointer)MAPCAR(ctx,2,local+18); /*mapcar*/
	local[18]= w;
	local[19]= fqv[70];
	local[20]= (pointer)get_sym_func(fqv[71]);
	ctx->vsp=local+21;
	w=(*ftab[11])(ctx,4,local+17,&ftab[11],fqv[72]); /*union*/
	local[17]= w;
WHL30952:
	if (local[17]==NIL) goto WHX30953;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[17];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17] = (w)->c.cons.cdr;
	w = local[18];
	local[16] = w;
	local[18]= local[16];
	local[19]= argv[0];
	ctx->vsp=local+20;
	w=(*ftab[12])(ctx,2,local+18,&ftab[12],fqv[73]); /*concatenate-pathnames*/
	local[11] = w;
	local[18]= local[11];
	w = local[15];
	ctx->vsp=local+19;
	w=FLET30854(ctx,1,local+18,w);
	local[12] = w;
	if (local[12]==NIL) goto IF31023;
	w = local[12];
	ctx->vsp=local+18;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK30762;
	goto IF31024;
IF31023:
	local[18]= NIL;
IF31024:
	goto WHL30952;
WHX30953:
	local[18]= NIL;
BLK30954:
	w = NIL;
	local[16]= fqv[74];
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)SIGERROR(ctx,2,local+16); /*error*/
	local[16]= w;
IF30877:
	w = local[16];
	local[13]= w;
	ctx->vsp=local+14;
	unbindx(ctx,1);
	w = local[13];
	local[0]= w;
BLK30762:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30850(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (env->c.clo.env2[5]==NIL) goto IF31053;
	local[0]= T;
	local[1]= fqv[75];
	local[2]= argv[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,1,local+3,&ftab[0],fqv[0]); /*namestring*/
	local[3]= w;
	local[4]= loadglobal(fqv[63]);
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
	goto IF31054;
IF31053:
	local[0]= NIL;
IF31054:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30852(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[76]); /*directory-namestring*/
	local[0]= w;
	w = loadglobal(fqv[68]);
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= NIL;
	w = local[0];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[68],w);
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,1,local+6,&ftab[0],fqv[0]); /*namestring*/
	argv[0] = w;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F29061object_file_p(ctx,1,local+6); /*object-file-p*/
	if (w==NIL) goto CON31115;
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[7])(ctx,1,local+6,&ftab[7],fqv[52]); /*pathname-name*/
	local[6]= w;
	local[7]= loadglobal(fqv[77]);
	local[8]= fqv[78];
	local[9]= (pointer)get_sym_func(fqv[79]);
	local[10]= fqv[70];
	local[11]= (pointer)get_sym_func(fqv[80]);
	ctx->vsp=local+12;
	w=(*ftab[14])(ctx,6,local+6,&ftab[14],fqv[81]); /*find*/
	local[1] = w;
	if (local[1]==NIL) goto IF31124;
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[15])(ctx,1,local+6,&ftab[15],fqv[82]); /*system::unbinload*/
	local[6]= T;
	local[7]= fqv[83];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto IF31125;
IF31124:
	local[6]= NIL;
IF31125:
	local[6]= fqv[84];
	local[7]= argv[0];
	w = env->c.clo.env2[13];
	ctx->vsp=local+8;
	w=FLET30850(ctx,2,local+6,w);
	local[6]= argv[0];
	local[7]= env->c.clo.env2[1];
	ctx->vsp=local+8;
	w=(pointer)BINLOAD(ctx,2,local+6); /*system:binload*/
	local[2] = w;
	if (local[2]==NIL) goto IF31180;
	local[6]= local[2];
	w = loadglobal(fqv[77]);
	ctx->vsp=local+7;
	local[6]= cons(ctx,local[6],w);
	storeglobal(fqv[77],local[6]);
	goto IF31181;
IF31180:
	local[6]= NIL;
IF31181:
	local[6]= local[2];
	goto CON31113;
CON31115:
	local[6]= fqv[85];
	local[7]= argv[0];
	w = env->c.clo.env2[13];
	ctx->vsp=local+8;
	w=FLET30850(ctx,2,local+6,w);
	local[6]= argv[0];
	local[7]= env->c.clo.env2[6];
	ctx->vsp=local+8;
	w=(pointer)F29070system__txtload(ctx,2,local+6); /*system::txtload*/
	local[6]= T;
	goto CON31113;
CON31200:
	local[6]= NIL;
CON31113:
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET30854(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F29057probe_file(ctx,1,local+2); /*probe-file*/
	local[2]= w;
	local[3]= fqv[86];
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON31242;
	local[2]= argv[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30852(ctx,1,local+2,w);
	local[2]= w;
	goto CON31240;
CON31242:
	local[2]= fqv[88];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F29057probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31259;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30852(ctx,1,local+2,w);
	local[2]= w;
	goto CON31240;
CON31259:
	local[2]= fqv[89];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F29057probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31278;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30852(ctx,1,local+2,w);
	local[2]= w;
	goto CON31240;
CON31278:
	local[2]= fqv[90];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F29057probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31297;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30852(ctx,1,local+2,w);
	local[2]= w;
	goto CON31240;
CON31297:
	local[2]= fqv[91];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[0] = w;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)F29057probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31316;
	local[2]= local[0];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30852(ctx,1,local+2,w);
	local[2]= w;
	goto CON31240;
CON31316:
	local[2]= fqv[92];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,2,local+2,&ftab[6],fqv[51]); /*merge-pathnames*/
	local[1] = w;
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F29057probe_file(ctx,1,local+2); /*probe-file*/
	if (w==NIL) goto CON31335;
	local[2]= local[1];
	w = env->c.clo.env2[14];
	ctx->vsp=local+3;
	w=FLET30852(ctx,1,local+2,w);
	local[2]= w;
	goto CON31240;
CON31335:
	local[2]= NIL;
CON31240:
	w = local[2];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*load-files*/
static pointer F29089load_files(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST31360:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= NIL;
	local[2]= local[0];
WHL31386:
	if (local[2]==NIL) goto WHX31387;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= local[1];
	local[4]= fqv[93];
	local[5]= T;
	ctx->vsp=local+6;
	w=(pointer)F29086load(ctx,3,local+3); /*load*/
	goto WHL31386;
WHX31387:
	local[3]= NIL;
BLK31388:
	w = NIL;
	w = T;
	local[0]= w;
BLK31358:
	ctx->vsp=local; return(local[0]);}

/*read-file*/
static pointer F29092read_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F29052open(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31471,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	ctx->vsp=local+3;
	UWP31471(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31447:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31471(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-strings*/
static pointer F29095read_strings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F29052open(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31520,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
WHL31545:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31546;
	local[6]= local[3];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	local[6]= fqv[94];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	goto WHL31545;
WHX31546:
	local[6]= NIL;
BLK31547:
	local[6]= (pointer)get_sym_func(fqv[95]);
	local[7]= loadglobal(fqv[22]);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)NREVERSE(ctx,1,local+8); /*nreverse*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,3,local+6); /*apply*/
	ctx->vsp=local+3;
	UWP31520(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31496:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31520(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-lines*/
static pointer F29098read_lines(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F29052open(ctx,1,local+0); /*open*/
	local[0]= w;
	ctx->vsp=local+1;
	w = makeclosure(codevec,quotevec,UWP31635,env,argv,local);
	local[1]=(pointer)(ctx->protfp); local[2]=w;
	ctx->protfp=(struct protectframe *)(local+1);
	local[3]= NIL;
	local[4]= NIL;
	w = NIL;
	ctx->vsp=local+5;
	local[4]= cons(ctx,local[4],w);
	local[5]= NIL;
WHL31660:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[3] = w;
	local[6]= local[3];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31661;
	local[6]= local[3];
	w = local[5];
	ctx->vsp=local+7;
	local[5] = cons(ctx,local[6],w);
	goto WHL31660;
WHX31661:
	local[6]= NIL;
BLK31662:
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	ctx->vsp=local+3;
	UWP31635(ctx,0,local+3,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[0]= w;
BLK31611:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31635(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-lists*/
static pointer F29101read_lists(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F29052open(ctx,1,local+3); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP31753,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
WHL31760:
	local[6]= local[3];
	local[7]= NIL;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[1] = w;
	local[6]= local[1];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto WHX31761;
	local[6]= local[1];
	w = local[2];
	ctx->vsp=local+7;
	local[2] = cons(ctx,local[6],w);
	goto WHL31760;
WHX31761:
	local[6]= NIL;
BLK31762:
	w = local[6];
	ctx->vsp=local+6;
	UWP31753(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK31710:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31753(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-binary-file*/
static pointer F29104read_binary_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)F29122file_size(ctx,1,local+0); /*file-size*/
	local[0]= w;
	local[1]= NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[3])(ctx,1,local+2,&ftab[3],fqv[44]); /*make-string*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F29052open(ctx,1,local+3); /*open*/
	local[3]= w;
	ctx->vsp=local+4;
	w = makeclosure(codevec,quotevec,UWP31854,env,argv,local);
	local[4]=(pointer)(ctx->protfp); local[5]=w;
	ctx->protfp=(struct protectframe *)(local+4);
	local[6]= local[3];
	local[7]= fqv[96];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)UNIXREAD(ctx,3,local+6); /*unix:uread*/
	local[1] = w;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,2,local+6,&ftab[17],fqv[97]); /*/=*/
	if (w==NIL) goto IF31876;
	local[6]= fqv[98];
	ctx->vsp=local+7;
	w=(pointer)SIGERROR(ctx,1,local+6); /*error*/
	local[6]= w;
	goto IF31877;
IF31876:
	local[6]= NIL;
IF31877:
	w = local[6];
	ctx->vsp=local+6;
	UWP31854(ctx,0,local+6,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	w = local[2];
	local[0]= w;
BLK31810:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP31854(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[3];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*read-lines-till-eof*/
static pointer F29107read_lines_till_eof(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	w = NIL;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
WHL31936:
	local[3]= argv[0];
	local[4]= NIL;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)READLINE(ctx,3,local+3); /*read-line*/
	local[1] = w;
	local[3]= local[1];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w!=NIL) goto WHX31937;
	local[3]= local[1];
	w = local[0];
	ctx->vsp=local+4;
	local[0] = cons(ctx,local[3],w);
	goto WHL31936;
WHX31937:
	local[3]= NIL;
BLK31938:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)NREVERSE(ctx,1,local+3); /*nreverse*/
	local[0]= w;
BLK31907:
	ctx->vsp=local; return(local[0]);}

/*do-file-line*/
static pointer F31973(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST31976:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[99],w);
	local[6]= fqv[100];
	local[7]= loadglobal(fqv[99]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[24];
	local[9]= local[2];
	local[10]= fqv[56];
	local[11]= fqv[19];
	local[12]= fqv[19];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[101];
	local[11]= fqv[102];
	local[12]= fqv[103];
	local[13]= local[2];
	local[14]= fqv[104];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[105];
	local[17]= loadglobal(fqv[99]);
	local[18]= fqv[19];
	local[19]= local[2];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
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
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK31974:
	ctx->vsp=local; return(local[0]);}

/*do-file-form*/
static pointer F32121(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32124:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)GENSYM(ctx,0,local+2); /*gensym*/
	local[2]= w;
	w = local[1];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[99],w);
	local[6]= fqv[100];
	local[7]= loadglobal(fqv[99]);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+8;
	local[7]= cons(ctx,local[7],w);
	local[8]= fqv[24];
	local[9]= local[2];
	local[10]= fqv[56];
	local[11]= fqv[19];
	local[12]= fqv[19];
	ctx->vsp=local+13;
	w=(pointer)LIST(ctx,1,local+12); /*list*/
	ctx->vsp=local+12;
	w = cons(ctx,local[11],w);
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)LIST(ctx,1,local+10); /*list*/
	ctx->vsp=local+10;
	local[9]= cons(ctx,local[9],w);
	local[10]= fqv[101];
	local[11]= fqv[102];
	local[12]= fqv[103];
	local[13]= local[2];
	local[14]= fqv[104];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	local[16]= fqv[106];
	local[17]= loadglobal(fqv[99]);
	local[18]= fqv[19];
	local[19]= local[2];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	ctx->vsp=local+19;
	w = cons(ctx,local[18],w);
	ctx->vsp=local+18;
	w = cons(ctx,local[17],w);
	ctx->vsp=local+17;
	local[16]= cons(ctx,local[16],w);
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
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK32122:
	ctx->vsp=local; return(local[0]);}

/*load-library*/
static pointer F29112load_library(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST32271:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= (pointer)get_sym_func(fqv[107]);
	local[2]= argv[0];
	local[3]= fqv[108];
	local[4]= NIL;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,5,local+1); /*apply*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(*ftab[18])(ctx,2,local+2,&ftab[18],fqv[109]); /*system::list-module-initializers*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[2];
WHL32326:
	if (local[5]==NIL) goto WHX32327;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= loadglobal(fqv[110]);
	ctx->vsp=local+7;
	w=(pointer)ISATTY(ctx,1,local+6); /*unix:isatty*/
	if (w==NIL) goto IF32376;
	local[6]= loadglobal(fqv[111]);
	local[7]= fqv[112];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= loadglobal(fqv[111]);
	ctx->vsp=local+7;
	w=(pointer)FINOUT(ctx,1,local+6); /*finish-output*/
	local[6]= w;
	goto IF32377;
IF32376:
	local[6]= NIL;
IF32377:
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	ctx->vsp=local+8;
	w=(pointer)FUNCALL(ctx,2,local+6); /*funcall*/
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w = local[3];
	ctx->vsp=local+7;
	local[3] = cons(ctx,local[6],w);
	goto WHL32326;
WHX32327:
	local[6]= NIL;
BLK32328:
	w = NIL;
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)NREVERSE(ctx,1,local+4); /*nreverse*/
	local[0]= w;
BLK32269:
	ctx->vsp=local; return(local[0]);}

/*dump-object*/
static pointer F29115dump_object(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32446:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= T;
	local[2]= T;
	local[3]= NIL;
	local[4]= NIL;
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[113],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[114],w);
	w = local[2];
	ctx->vsp=local+11;
	bindspecial(ctx,fqv[115],w);
	w = local[1];
	ctx->vsp=local+14;
	bindspecial(ctx,fqv[116],w);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)STREAMP(ctx,1,local+17); /*streamp*/
	if (w==NIL) goto IF32488;
	local[17]= NIL;
	local[18]= local[0];
WHL32513:
	if (local[18]==NIL) goto WHX32514;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	local[20]= argv[0];
	ctx->vsp=local+21;
	w=(pointer)PRINT(ctx,2,local+19); /*print*/
	goto WHL32513;
WHX32514:
	local[19]= NIL;
BLK32515:
	w = NIL;
	local[17]= w;
	goto IF32489;
IF32488:
	local[17]= argv[0];
	local[18]= fqv[117];
	local[19]= fqv[118];
	ctx->vsp=local+20;
	w=(pointer)F29052open(ctx,3,local+17); /*open*/
	local[17]= w;
	ctx->vsp=local+18;
	w = makeclosure(codevec,quotevec,UWP32587,env,argv,local);
	local[18]=(pointer)(ctx->protfp); local[19]=w;
	ctx->protfp=(struct protectframe *)(local+18);
	local[20]= NIL;
	local[21]= local[0];
WHL32611:
	if (local[21]==NIL) goto WHX32612;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= local[20];
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)PRINT(ctx,2,local+22); /*print*/
	goto WHL32611;
WHX32612:
	local[22]= NIL;
BLK32613:
	w = NIL;
	ctx->vsp=local+20;
	UWP32587(ctx,0,local+20,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[17]= w;
IF32489:
	ctx->vsp=local+18;
	unbindx(ctx,4);
	w = local[17];
	local[0]= w;
BLK32444:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP32587(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[17];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*dump-structure*/
static pointer F29118dump_structure(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32685:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= T;
	local[2]= T;
	local[3]= NIL;
	local[4]= NIL;
	w = local[4];
	ctx->vsp=local+5;
	bindspecial(ctx,fqv[113],w);
	w = local[3];
	ctx->vsp=local+8;
	bindspecial(ctx,fqv[114],w);
	w = local[2];
	ctx->vsp=local+11;
	bindspecial(ctx,fqv[115],w);
	w = local[1];
	ctx->vsp=local+14;
	bindspecial(ctx,fqv[119],w);
	local[17]= argv[0];
	ctx->vsp=local+18;
	w=(pointer)STREAMP(ctx,1,local+17); /*streamp*/
	if (w==NIL) goto IF32727;
	local[17]= NIL;
	local[18]= local[0];
WHL32752:
	if (local[18]==NIL) goto WHX32753;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[19]= (w)->c.cons.car;
	w=local[18];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18] = (w)->c.cons.cdr;
	w = local[19];
	local[17] = w;
	local[19]= local[17];
	local[20]= argv[0];
	ctx->vsp=local+21;
	w=(pointer)PRINT(ctx,2,local+19); /*print*/
	goto WHL32752;
WHX32753:
	local[19]= NIL;
BLK32754:
	w = NIL;
	local[17]= w;
	goto IF32728;
IF32727:
	local[17]= argv[0];
	local[18]= fqv[117];
	local[19]= fqv[118];
	ctx->vsp=local+20;
	w=(pointer)F29052open(ctx,3,local+17); /*open*/
	local[17]= w;
	ctx->vsp=local+18;
	w = makeclosure(codevec,quotevec,UWP32826,env,argv,local);
	local[18]=(pointer)(ctx->protfp); local[19]=w;
	ctx->protfp=(struct protectframe *)(local+18);
	local[20]= NIL;
	local[21]= local[0];
WHL32850:
	if (local[21]==NIL) goto WHX32851;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[22]= (w)->c.cons.car;
	w=local[21];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[21] = (w)->c.cons.cdr;
	w = local[22];
	local[20] = w;
	local[22]= local[20];
	local[23]= local[17];
	ctx->vsp=local+24;
	w=(pointer)PRINT(ctx,2,local+22); /*print*/
	goto WHL32850;
WHX32851:
	local[22]= NIL;
BLK32852:
	w = NIL;
	ctx->vsp=local+20;
	UWP32826(ctx,0,local+20,ctx->protfp->cleaner);
	ctx->protfp=ctx->protfp->protlink;
	local[17]= w;
IF32728:
	ctx->vsp=local+18;
	unbindx(ctx,4);
	w = local[17];
	local[0]= w;
BLK32683:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer UWP32826(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= env->c.clo.env2[17];
	ctx->vsp=local+1;
	w=(pointer)CLOSE(ctx,1,local+0); /*close*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*dump-loadable-structure*/
static pointer F32922(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST32925:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= local[0];
WHL32963:
	if (local[3]==NIL) goto WHX32964;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= fqv[120];
	local[5]= fqv[104];
	local[6]= local[2];
	local[7]= fqv[120];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SYMVALUE(ctx,1,local+8); /*symbol-value*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,3,local+5); /*list*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,2,local+4); /*list*/
	local[4]= w;
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	goto WHL32963;
WHX32964:
	local[4]= NIL;
BLK32965:
	w = NIL;
	local[2]= fqv[121];
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)REVERSE(ctx,1,local+4); /*reverse*/
	ctx->vsp=local+4;
	w = cons(ctx,local[3],w);
	ctx->vsp=local+3;
	w = cons(ctx,local[2],w);
	local[0]= w;
BLK32923:
	ctx->vsp=local; return(local[0]);}

/*file-size*/
static pointer F29122file_size(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	argv[0] = w;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F29057probe_file(ctx,1,local+0); /*probe-file*/
	if (w==NIL) goto IF33076;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[0])(ctx,1,local+0,&ftab[0],fqv[0]); /*namestring*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)STAT(ctx,1,local+0); /*unix:stat*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)7L);
	ctx->vsp=local+2;
	w=(pointer)ELT(ctx,2,local+0); /*elt*/
	local[0]= w;
	goto IF33077;
IF33076:
	local[0]= fqv[122];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
IF33077:
	w = local[0];
	local[0]= w;
BLK33057:
	ctx->vsp=local; return(local[0]);}

/*directory-p*/
static pointer F29125directory_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)STAT(ctx,1,local+2); /*unix:stat*/
	local[1] = w;
	w = local[1];
	if (!iscons(w)) goto IF33110;
	local[2]= makeint((eusinteger_t)16384L);
	local[3]= local[1];
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)ELT(ctx,2,local+3); /*elt*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LOGAND(ctx,2,local+2); /*logand*/
	local[2]= w;
	local[3]= makeint((eusinteger_t)16384L);
	ctx->vsp=local+4;
	w=(pointer)NUMEQUAL(ctx,2,local+2); /*=*/
	local[2]= w;
	goto IF33111;
IF33110:
	local[2]= NIL;
IF33111:
	w = local[2];
	local[0]= w;
BLK33096:
	ctx->vsp=local; return(local[0]);}

/*map-file*/
static pointer F29128map_file(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[123], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY33150;
	local[0] = fqv[2];
KEY33150:
	if (n & (1<<1)) goto KEY33157;
	local[1] = makeint((eusinteger_t)0L);
KEY33157:
	if (n & (1<<2)) goto KEY33162;
	local[2] = NIL;
KEY33162:
	if (n & (1<<3)) goto KEY33167;
	local[3] = NIL;
KEY33167:
	if (n & (1<<4)) goto KEY33172;
	local[4] = T;
KEY33172:
	if (n & (1<<5)) goto KEY33177;
	local[5] = NIL;
KEY33177:
	if (n & (1<<6)) goto KEY33182;
	local[6] = makeint((eusinteger_t)0L);
KEY33182:
	local[7]= NIL;
	local[8]= makeint((eusinteger_t)0L);
	local[9]= NIL;
	local[10]= argv[0];
	local[11]= fqv[117];
	local[12]= local[0];
	local[13]= fqv[124];
	local[14]= fqv[13];
	ctx->vsp=local+15;
	w=(pointer)F29052open(ctx,5,local+10); /*open*/
	local[7] = w;
	if (local[2]!=NIL) goto IF33220;
	local[10]= argv[0];
	ctx->vsp=local+11;
	w=(pointer)F29122file_size(ctx,1,local+10); /*file-size*/
	local[2] = w;
	local[10]= local[2];
	goto IF33221;
IF33220:
	local[10]= NIL;
IF33221:
	if (local[3]!=NIL) goto IF33239;
	local[10]= local[0];
	local[11]= fqv[125];
	ctx->vsp=local+12;
	w=(pointer)ASSQ(ctx,2,local+10); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[10]= local[3];
	goto IF33240;
IF33239:
	local[10]= NIL;
IF33240:
	if (local[4]==NIL) goto IF33263;
	local[8] = makeint((eusinteger_t)1L);
	local[10]= local[8];
	goto IF33264;
IF33263:
	local[10]= NIL;
IF33264:
	if (local[5]==NIL) goto IF33275;
	local[8] = makeint((eusinteger_t)2L);
	local[10]= local[8];
	goto IF33276;
IF33275:
	local[10]= NIL;
IF33276:
	local[10]= local[6];
	local[11]= local[2];
	local[12]= local[3];
	local[13]= local[8];
	local[14]= local[7];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(*ftab[19])(ctx,6,local+10,&ftab[19],fqv[126]); /*unix:mmap*/
	local[9] = w;
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)CLOSE(ctx,1,local+10); /*close*/
	w = local[9];
	local[0]= w;
BLK33135:
	ctx->vsp=local; return(local[0]);}

/*provide*/
static pointer F29130provide(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST33313:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[127]); /*keywordp*/
	if (w!=NIL) goto IF33325;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,1,local+1,&ftab[22],fqv[128]); /*string-upcase*/
	local[1]= w;
	local[2]= loadglobal(fqv[129]);
	ctx->vsp=local+3;
	w=(pointer)INTERN(ctx,2,local+1); /*intern*/
	argv[0] = w;
	local[1]= argv[0];
	goto IF33326;
IF33325:
	local[1]= NIL;
IF33326:
	local[1]= argv[0];
	local[2]= loadglobal(fqv[130]);
	ctx->vsp=local+3;
	w=(*ftab[23])(ctx,2,local+1,&ftab[23],fqv[131]); /*assoc*/
	if (w!=NIL) goto IF33355;
	local[1]= loadglobal(fqv[130]);
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)LIST_STAR(ctx,2,local+2); /*list**/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	local[1]= w;
	storeglobal(fqv[130],w);
	goto IF33356;
IF33355:
	local[1]= NIL;
IF33356:
	w = argv[0];
	local[0]= w;
BLK33311:
	ctx->vsp=local; return(local[0]);}

/*require*/
static pointer F29132require(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST33388:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,1,local+1,&ftab[20],fqv[127]); /*keywordp*/
	if (w!=NIL) goto IF33400;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[22])(ctx,1,local+1,&ftab[22],fqv[128]); /*string-upcase*/
	local[1]= w;
	local[2]= loadglobal(fqv[129]);
	ctx->vsp=local+3;
	w=(pointer)INTERN(ctx,2,local+1); /*intern*/
	argv[0] = w;
	local[1]= argv[0];
	goto IF33401;
IF33400:
	local[1]= NIL;
IF33401:
	local[1]= argv[0];
	local[2]= loadglobal(fqv[130]);
	ctx->vsp=local+3;
	w=(*ftab[23])(ctx,2,local+1,&ftab[23],fqv[131]); /*assoc*/
	if (w!=NIL) goto IF33427;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	if (isstring(w)) goto IF33440;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(*ftab[21])(ctx,1,local+1,&ftab[21],fqv[22]); /*string*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[24])(ctx,1,local+1,&ftab[24],fqv[132]); /*string-downcase*/
	local[1]= w;
	w = local[0];
	ctx->vsp=local+2;
	local[0] = cons(ctx,local[1],w);
	local[1]= local[0];
	goto IF33441;
IF33440:
	local[1]= NIL;
IF33441:
	local[1]= (pointer)get_sym_func(fqv[107]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F29130provide(ctx,1,local+1); /*provide*/
	local[1]= w;
	goto IF33428;
IF33427:
	local[1]= NIL;
IF33428:
	w = local[1];
	local[0]= w;
BLK33386:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___loader(ctx,n,argv,env)
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
	local[0]= fqv[133];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF33488;
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[63],w);
	goto IF33489;
IF33488:
	local[0]= fqv[136];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF33489:
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[138],module,F29046file_write_date,fqv[139]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[140],module,F29049file_newer,fqv[141]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[25],module,F29052open,fqv[142]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[100],module,F29718,fqv[143]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[144],module,F29057probe_file,fqv[145]);
	local[0]= fqv[43];
	local[1]= fqv[146];
	local[2]= fqv[147];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33528;
	local[2]= makeint((eusinteger_t)7L);
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33528:
	local[2]= fqv[149];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33540;
	local[2]= makeint((eusinteger_t)127L);
	local[3]= makeint((eusinteger_t)69L);
	local[4]= makeint((eusinteger_t)76L);
	local[5]= makeint((eusinteger_t)70L);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33540:
	local[2]= fqv[150];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33551;
	local[2]= makeint((eusinteger_t)127L);
	local[3]= makeint((eusinteger_t)69L);
	local[4]= makeint((eusinteger_t)76L);
	local[5]= makeint((eusinteger_t)70L);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33551:
	local[2]= fqv[151];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33562;
	local[2]= makeint((eusinteger_t)98L);
	local[3]= makeint((eusinteger_t)1L);
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33562:
	local[2]= fqv[152];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33573;
	local[2]= makeint((eusinteger_t)127L);
	local[3]= makeint((eusinteger_t)69L);
	local[4]= makeint((eusinteger_t)76L);
	local[5]= makeint((eusinteger_t)70L);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33573:
	local[2]= fqv[153];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33584;
	local[2]= fqv[154];
	local[3]= fqv[155];
	local[4]= fqv[156];
	local[5]= fqv[157];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33584:
	local[2]= fqv[158];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33603;
	local[2]= makeint((eusinteger_t)127L);
	local[3]= makeint((eusinteger_t)69L);
	local[4]= makeint((eusinteger_t)76L);
	local[5]= makeint((eusinteger_t)70L);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33603:
	local[2]= fqv[159];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33614;
	local[2]= makeint((eusinteger_t)77L);
	local[3]= makeint((eusinteger_t)90L);
	local[4]= makeint((eusinteger_t)144L);
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33614:
	local[2]= fqv[160];
	local[3]= loadglobal(fqv[148]);
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,2,local+2,&ftab[16],fqv[87]); /*member*/
	if (w==NIL) goto CON33625;
	local[2]= makeint((eusinteger_t)131L);
	local[3]= makeint((eusinteger_t)1L);
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33625:
	local[2]= NIL;
	local[3]= NIL;
	local[4]= makeint((eusinteger_t)1L);
	local[5]= fqv[161];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	goto CON33526;
CON33636:
	local[2]= NIL;
CON33526:
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[162],module,F29061object_file_p,fqv[163]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[164],module,F29064path_list,fqv[165]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[166],module,F29067find_executable,fqv[167]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[168],module,F29070system__txtload,fqv[169]);
	local[0]= fqv[69];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33655;
	local[0]= fqv[69];
	local[1]= fqv[170];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[69];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33678;
	local[0]= fqv[69];
	local[1]= fqv[171];
	local[2]= fqv[172];
	local[3]= loadglobal(fqv[173]);
	local[4]= NIL;
	local[5]= fqv[174];
	local[6]= loadglobal(fqv[173]);
	ctx->vsp=local+7;
	w=(pointer)XFORMAT(ctx,3,local+4); /*format*/
	local[4]= w;
	local[5]= NIL;
	local[6]= fqv[175];
	local[7]= loadglobal(fqv[173]);
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,3,local+5); /*format*/
	local[5]= w;
	local[6]= NIL;
	local[7]= fqv[176];
	local[8]= loadglobal(fqv[173]);
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,5,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33679;
IF33678:
	local[0]= NIL;
IF33679:
	local[0]= fqv[69];
	goto IF33656;
IF33655:
	local[0]= NIL;
IF33656:
	local[0]= fqv[68];
	local[1]= fqv[177];
	local[2]= fqv[178];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[62];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33721;
	local[0]= fqv[62];
	local[1]= fqv[170];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[62];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33744;
	local[0]= fqv[62];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33745;
IF33744:
	local[0]= NIL;
IF33745:
	local[0]= fqv[62];
	goto IF33722;
IF33721:
	local[0]= NIL;
IF33722:
	local[0]= fqv[77];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33764;
	local[0]= fqv[77];
	local[1]= fqv[170];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[77];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33787;
	local[0]= fqv[77];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33788;
IF33787:
	local[0]= NIL;
IF33788:
	local[0]= fqv[77];
	goto IF33765;
IF33764:
	local[0]= NIL;
IF33765:
	ctx->vsp=local+0;
	compfun(ctx,fqv[79],module,F29080load_module_file_name,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[180],module,F29083gencname_tail,fqv[181]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[107],module,F29086load,fqv[182]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[183],module,F29089load_files,fqv[184]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[185],module,F29092read_file,fqv[186]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[187],module,F29095read_strings,fqv[188]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[189],module,F29098read_lines,fqv[190]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[191],module,F29101read_lists,fqv[192]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[193],module,F29104read_binary_file,fqv[194]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[195],module,F29107read_lines_till_eof,fqv[196]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[197],module,F31973,fqv[198]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[199],module,F32121,fqv[200]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[201],module,F29112load_library,fqv[202]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[203],module,F29115dump_object,fqv[204]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F29118dump_structure,fqv[205]);
	ctx->vsp=local+0;
	compmacro(ctx,fqv[206],module,F32922,fqv[207]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[208],module,F29122file_size,fqv[209]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[210],module,F29125directory_p,fqv[211]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[212],module,F29128map_file,fqv[213]);
	local[0]= fqv[130];
	local[1]= fqv[170];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF33845;
	local[0]= fqv[130];
	local[1]= fqv[170];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF33868;
	local[0]= fqv[130];
	local[1]= fqv[171];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF33869;
IF33868:
	local[0]= NIL;
IF33869:
	local[0]= fqv[130];
	goto IF33846;
IF33845:
	local[0]= NIL;
IF33846:
	ctx->vsp=local+0;
	compfun(ctx,fqv[214],module,F29130provide,fqv[215]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[216],module,F29132require,fqv[217]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<25; i++) ftab[i]=fcallx;
}
