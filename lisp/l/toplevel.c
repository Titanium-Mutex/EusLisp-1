/* ./toplevel.c :  entry=toplevel */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "toplevel.h"
#pragma init (register_toplevel)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___toplevel();
extern pointer build_quote_vector();
static int register_toplevel()
  { add_module_initializer("___toplevel", ___toplevel);}

static pointer F70957count_up_timer();
static pointer F70960skip_blank();
static pointer F70964read_list_from_line();
static pointer F70967sigint_handler();
static pointer F70971eussig();
static pointer F70974evaluate_stream();
static pointer F70977toplevel_prompt();
static pointer F70980rep1();
static pointer F70983prompt();
static pointer F70986reploop_non_select();
static pointer F70989repsel();
static pointer F70992reploop_select();
static pointer F70995reploop();
static pointer F70998euserror();
static pointer F71001eustop();
static pointer F71004reset();

/*count-up-timer*/
static pointer F70957count_up_timer(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=0) maerror();
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	storeglobal(fqv[0],w);
	w = local[0];
	local[0]= w;
BLK71078:
	ctx->vsp=local; return(local[0]);}

/*skip-blank*/
static pointer F70960skip_blank(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT71100;}
	ctx->vsp=local+0;
	w=(pointer)GENSYM(ctx,0,local+0); /*gensym*/
	local[0]= w;
ENT71100:
ENT71099:
	if (n>2) maerror();
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,3,local+1); /*read-char*/
	local[1]= w;
	local[2]= local[1];
	if (local[0]!=local[2]) goto IF71130;
	w = local[0];
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK71097;
	goto IF71131;
IF71130:
	local[2]= NIL;
IF71131:
WHL71142:
	local[2]= local[1];
	local[3]= fqv[1];
	ctx->vsp=local+4;
	w=(*ftab[0])(ctx,2,local+2,&ftab[0],fqv[2]); /*position*/
	if (w==NIL) goto WHX71143;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)READCH(ctx,1,local+2); /*read-char*/
	local[1] = w;
	goto WHL71142;
WHX71143:
	local[2]= NIL;
BLK71144:
	local[2]= local[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)UNREADCH(ctx,2,local+2); /*unread-char*/
	w = local[1];
	local[0]= w;
BLK71097:
	ctx->vsp=local; return(local[0]);}

/*read-list-from-line*/
static pointer F70964read_list_from_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT71177;}
	local[0]= loadglobal(fqv[3]);
ENT71177:
	if (n>=2) { local[1]=(argv[1]); goto ENT71176;}
	ctx->vsp=local+1;
	w=(pointer)GENSYM(ctx,0,local+1); /*gensym*/
	local[1]= w;
ENT71176:
ENT71175:
	if (n>2) maerror();
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F70960skip_blank(ctx,2,local+6); /*skip-blank*/
	local[2] = w;
	local[6]= NIL;
	storeglobal(fqv[4],local[6]);
	local[6]= local[2];
	if (local[1]!=local[6]) goto CON71225;
	local[6]= local[1];
	goto CON71223;
CON71225:
	local[6]= local[2];
	if (makeint((eusinteger_t)40L)!=local[6]) goto CON71232;
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)READ(ctx,3,local+6); /*read*/
	local[4] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[2] = w;
	local[6]= local[2];
	local[7]= makeint((eusinteger_t)10L);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w!=NIL) goto IF71258;
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)UNREADCH(ctx,2,local+6); /*unread-char*/
	local[6]= w;
	goto IF71259;
IF71258:
	local[6]= NIL;
IF71259:
	local[6]= local[4];
	goto CON71223;
CON71232:
	local[6]= local[2];
	if (makeint((eusinteger_t)44L)!=local[6]) goto CON71274;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READ(ctx,1,local+6); /*read*/
	local[4] = w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= local[4];
	goto CON71223;
CON71274:
	local[6]= local[0];
	local[7]= NIL;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)READLINE(ctx,3,local+6); /*read-line*/
	local[6]= w;
	storeglobal(fqv[4],w);
	local[6]= loadglobal(fqv[4]);
	if (local[1]!=local[6]) goto IF71310;
	w = local[1];
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK71173;
	goto IF71311;
IF71310:
	local[6]= NIL;
IF71311:
	local[6]= loadglobal(fqv[4]);
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,1,local+6,&ftab[1],fqv[5]); /*make-string-input-stream*/
	local[6]= w;
	goto CON71223;
CON71297:
	local[6]= NIL;
CON71223:
	w = local[6];
	local[0]= w;
BLK71173:
	ctx->vsp=local; return(local[0]);}

/*sigint-handler*/
static pointer F70967sigint_handler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)1L);
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[7]); /*warning-message*/
	local[0]= fqv[8];
	ctx->vsp=local+1;
	w=(pointer)FBOUNDP(ctx,1,local+0); /*fboundp*/
	if (w==NIL) goto IF71345;
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[3])(ctx,2,local+0,&ftab[3],fqv[8]); /*unix:ualarm*/
	local[0]= w;
	goto IF71346;
IF71345:
	local[0]= makeint((eusinteger_t)0L);
	ctx->vsp=local+1;
	w=(pointer)ALARM(ctx,1,local+0); /*unix:alarm*/
	local[0]= w;
IF71346:
	local[0]= loadglobal(fqv[9]);
	ctx->vsp=local+1;
	w=(pointer)ADD1(ctx,1,local+0); /*1+*/
	local[0]= w;
	w = local[0];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[9],w);
	local[3]= fqv[10];
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[11],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+6;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT71376;}
	local[12]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+13;
	w=(pointer)F70995reploop(ctx,1,local+12); /*reploop*/
CAT71376:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[6]= w;
	ctx->vsp=local+7;
	unbindx(ctx,2);
	w = local[6];
	local[0]= w;
BLK71329:
	ctx->vsp=local; return(local[0]);}

/*eussig*/
static pointer F70971eussig(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
RST71394:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-1);
	local[1]= NIL;
	local[2]= loadglobal(fqv[13]);
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)AREF(ctx,2,local+2); /*aref*/
	local[2]= w;
	if (local[2]==NIL) goto CON71416;
	local[3]= local[2];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)FUNCALL(ctx,3,local+3); /*funcall*/
	local[3]= w;
	goto CON71414;
CON71416:
	local[3]= fqv[8];
	ctx->vsp=local+4;
	w=(pointer)FBOUNDP(ctx,1,local+3); /*fboundp*/
	if (w==NIL) goto IF71430;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(*ftab[3])(ctx,2,local+3,&ftab[3],fqv[8]); /*unix:ualarm*/
	local[3]= w;
	goto IF71431;
IF71430:
	local[3]= makeint((eusinteger_t)0L);
	ctx->vsp=local+4;
	w=(pointer)ALARM(ctx,1,local+3); /*unix:alarm*/
	local[3]= w;
IF71431:
	local[3]= makeint((eusinteger_t)1L);
	local[4]= fqv[14];
	local[5]= argv[0];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[7]); /*warning-message*/
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	w = local[3];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[9],w);
	local[6]= fqv[15];
	w = local[6];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[11],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT71464;}
	local[15]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+16;
	w=(pointer)F70995reploop(ctx,1,local+15); /*reploop*/
CAT71464:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,2);
	w = local[9];
	local[3]= w;
	goto CON71414;
CON71426:
	local[3]= NIL;
CON71414:
	w = local[3];
	local[0]= w;
BLK71392:
	ctx->vsp=local; return(local[0]);}

/*evaluate-stream*/
static pointer F70974evaluate_stream(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	w = NIL;
	ctx->vsp=local+1;
	local[0]= cons(ctx,local[0],w);
	local[1]= argv[0];
	local[2]= NIL;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,3,local+1); /*read*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= local[1];
	local[5]= ((local[0])==(local[5])?T:NIL);
	if (local[5]!=NIL) goto CON71511;
CON71513:
	w = local[1];
	if (!issymbol(w)) goto CON71521;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)FBOUNDP(ctx,1,local+5); /*fboundp*/
	if (w==NIL) goto CON71529;
	local[2] = NIL;
WHL71543:
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,3,local+5); /*read*/
	local[3] = w;
	local[5]= local[3];
	if (local[0]==local[5]) goto WHX71544;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	goto WHL71543;
WHX71544:
	local[5]= NIL;
BLK71545:
	local[5]= local[1];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)NREVERSE(ctx,1,local+6); /*nreverse*/
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	storeglobal(fqv[16],local[5]);
	local[5]= loadglobal(fqv[16]);
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON71527;
CON71529:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)BOUNDP(ctx,1,local+5); /*boundp*/
	if (w==NIL) goto CON71591;
	local[5]= argv[0];
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)READ(ctx,3,local+5); /*read*/
	local[5]= w;
	if (local[0]!=local[5]) goto CON71591;
	local[5]= local[1];
	storeglobal(fqv[16],local[5]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON71527;
CON71591:
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	if (w==NIL) goto CON71620;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	if (w==NIL) goto IF71632;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(*ftab[4])(ctx,1,local+5,&ftab[4],fqv[17]); /*string*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)FINDPACKAGE(ctx,1,local+5); /*find-package*/
	local[5]= w;
	storeglobal(fqv[18],w);
	goto IF71633;
IF71632:
	local[5]= fqv[19];
	ctx->vsp=local+6;
	w=(pointer)SIGERROR(ctx,1,local+5); /*error*/
	local[5]= w;
IF71633:
	goto CON71527;
CON71620:
	if (loadglobal(fqv[20])==NIL) goto CON71653;
	local[5]= fqv[21];
	local[6]= *(ovafptr(argv[0],fqv[22]));
	ctx->vsp=local+7;
	w=(pointer)LIST(ctx,2,local+5); /*list*/
	local[5]= w;
	storeglobal(fqv[16],w);
	local[5]= *(ovafptr(argv[0],fqv[22]));
	ctx->vsp=local+6;
	w=(pointer)SYSTEM(ctx,1,local+5); /*unix:system*/
	local[4] = w;
	local[5]= local[4];
	goto CON71527;
CON71653:
	local[5]= fqv[23];
	ctx->vsp=local+6;
	w=(*ftab[5])(ctx,1,local+5,&ftab[5],fqv[24]); /*warn*/
	local[5]= w;
	goto CON71527;
CON71679:
	local[5]= NIL;
CON71527:
	goto CON71511;
CON71521:
	local[5]= local[1];
	storeglobal(fqv[16],local[5]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)EVAL(ctx,1,local+5); /*eval*/
	local[4] = w;
	local[5]= local[4];
	goto CON71511;
CON71685:
	local[5]= NIL;
CON71511:
	w = local[4];
	local[0]= w;
BLK71478:
	ctx->vsp=local; return(local[0]);}

/*toplevel-prompt*/
static pointer F70977toplevel_prompt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	if (loadglobal(fqv[25])==NIL) goto IF71719;
	local[0]= argv[0];
	local[1]= fqv[26];
	local[2]= loadglobal(fqv[27]);
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF71720;
IF71719:
	local[0]= NIL;
IF71720:
	local[0]= loadglobal(fqv[9]);
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(pointer)GREATERP(ctx,2,local+0); /*>*/
	if (w==NIL) goto IF71734;
	local[0]= argv[0];
	local[1]= fqv[28];
	local[2]= loadglobal(fqv[11]);
	local[3]= loadglobal(fqv[9]);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,4,local+0); /*format*/
	local[0]= w;
	goto IF71735;
IF71734:
	local[0]= NIL;
IF71735:
	local[0]= loadglobal(fqv[18]);
	local[1]= loadglobal(fqv[29]);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w!=NIL) goto IF71747;
	local[0]= argv[0];
	local[1]= fqv[30];
	local[2]= loadglobal(fqv[18]);
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[31]); /*package-name*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF71748;
IF71747:
	local[0]= NIL;
IF71748:
	local[0]= argv[0];
	local[1]= fqv[32];
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
BLK71709:
	ctx->vsp=local; return(local[0]);}

/*rep1*/
static pointer F70980rep1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT71775;}
	local[0]= T;
ENT71775:
ENT71774:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F70964read_list_from_line(ctx,2,local+1); /*read-list-from-line*/
	local[1]= w;
	local[2]= NIL;
	local[3]= local[1];
	if (argv[1]!=local[3]) goto IF71809;
	w = argv[1];
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK71772;
	goto IF71810;
IF71809:
	local[3]= NIL;
IF71810:
	if (local[1]==NIL) goto IF71822;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto OR71828;
	local[3]= local[1];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[3] > (eusinteger_t)w) goto OR71828;
	goto IF71822;
OR71828:
	if (loadglobal(fqv[25])==NIL) goto IF71849;
	w = local[1];
	if (!iscons(w)) goto CON71861;
	local[3]= NIL;
	local[4]= fqv[35];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,3,local+3); /*format*/
	local[3]= w;
	goto CON71859;
CON71861:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto CON71869;
	local[3]= local[1];
	local[4]= fqv[34];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	goto CON71859;
CON71869:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,1,local+3,&ftab[4],fqv[17]); /*string*/
	local[3]= w;
	goto CON71859;
CON71881:
	local[3]= NIL;
CON71859:
	ctx->vsp=local+4;
	w=(*ftab[7])(ctx,1,local+3,&ftab[7],fqv[36]); /*add-history*/
	local[3]= w;
	goto IF71850;
IF71849:
	local[3]= NIL;
IF71850:
	if (loadglobal(fqv[37])==NIL) goto IF71891;
	local[3]= loadglobal(fqv[37]);
	ctx->vsp=local+4;
	w=(pointer)FUNCALL(ctx,1,local+3); /*funcall*/
	local[3]= w;
	goto IF71892;
IF71891:
	local[3]= NIL;
IF71892:
	goto IF71823;
IF71822:
	local[3]= NIL;
IF71823:
	if (local[1]!=NIL) goto CON71904;
	local[3]= NIL;
	goto CON71902;
CON71904:
	w = local[1];
	if (!issymbol(w)) goto CON71909;
	storeglobal(fqv[16],local[1]);
	local[3]= loadglobal(fqv[9]);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto CON71922;
	local[3]= local[1];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[38]); /*eval-dynamic*/
	local[3]= w;
	goto CON71920;
CON71922:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)BOUNDP(ctx,1,local+3); /*boundp*/
	if (w==NIL) goto CON71932;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[3]= w;
	goto CON71920;
CON71932:
	local[3]= fqv[39];
	goto CON71920;
CON71942:
	local[3]= NIL;
CON71920:
	local[2] = local[3];
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON71902;
CON71909:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto OR71955;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)LISTP(ctx,1,local+3); /*listp*/
	if (w!=NIL) goto OR71955;
	goto CON71954;
OR71955:
	local[3]= local[1];
	storeglobal(fqv[16],local[3]);
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EVAL(ctx,1,local+3); /*eval*/
	local[2] = w;
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON71902;
CON71954:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)STREAMP(ctx,1,local+3); /*streamp*/
	if (w==NIL) goto CON71987;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)F70974evaluate_stream(ctx,1,local+3); /*evaluate-stream*/
	local[2] = w;
	local[3]= local[2];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON71902;
CON71987:
	local[3]= fqv[40];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)PRINT(ctx,2,local+3); /*print*/
	local[3]= w;
	goto CON71902;
CON72007:
	local[3]= NIL;
CON71902:
	storeglobal(fqv[42],loadglobal(fqv[41]));
	storeglobal(fqv[41],loadglobal(fqv[43]));
	local[3]= loadglobal(fqv[16]);
	storeglobal(fqv[43],local[3]);
	storeglobal(fqv[45],loadglobal(fqv[44]));
	storeglobal(fqv[44],loadglobal(fqv[46]));
	local[3]= local[2];
	storeglobal(fqv[46],local[3]);
	w = local[3];
	local[0]= w;
BLK71772:
	ctx->vsp=local; return(local[0]);}

/*prompt*/
static pointer F70983prompt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = loadglobal(fqv[47]);
	if (!isstring(w)) goto CON72059;
	local[0]= loadglobal(fqv[47]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)PRINC(ctx,2,local+0); /*princ*/
	local[0]= w;
	goto CON72057;
CON72059:
	local[0]= loadglobal(fqv[47]);
	ctx->vsp=local+1;
	w=(*ftab[9])(ctx,1,local+0,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto CON72069;
	local[0]= loadglobal(fqv[47]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)FUNCALL(ctx,2,local+0); /*funcall*/
	local[0]= w;
	goto CON72057;
CON72069:
	local[0]= argv[0];
	local[1]= fqv[49];
	local[2]= loadglobal(fqv[33]);
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto CON72057;
CON72081:
	local[0]= NIL;
CON72057:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)FINOUT(ctx,1,local+0); /*finish-output*/
	local[0]= w;
BLK72047:
	ctx->vsp=local; return(local[0]);}

/*reploop-non-select*/
static pointer F70986reploop_non_select(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72099;}
	local[0]= loadglobal(fqv[50]);
ENT72099:
	if (n>=2) { local[1]=(argv[1]); goto ENT72098;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT72098:
ENT72097:
	if (n>2) maerror();
	local[2]= fqv[51];
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[52],w);
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= loadglobal(fqv[9]);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF72141;
	ctx->vsp=local+9;
	w=(pointer)LISTBINDINGS(ctx,0,local+9); /*system:list-all-bindings*/
	local[7] = w;
	local[9]= local[7];
	goto IF72142;
IF72141:
	local[9]= NIL;
IF72142:
WHL72155:
	if (T==NIL) goto WHX72156;
	{jmp_buf jb;
	w = fqv[53];
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT72162;}
	if (local[1]==NIL) goto IF72169;
	local[15]= local[0];
	ctx->vsp=local+16;
	w=(pointer)F70983prompt(ctx,1,local+15); /*prompt*/
	local[15]= w;
	goto IF72170;
IF72169:
	local[15]= NIL;
IF72170:
	local[15]= local[0];
	local[16]= local[5];
	local[17]= local[7];
	local[18]= local[1];
	ctx->vsp=local+19;
	w=(pointer)F70980rep1(ctx,4,local+15); /*rep1*/
	local[15]= w;
	local[16]= local[5];
	ctx->vsp=local+17;
	w=(pointer)EQ(ctx,2,local+15); /*eql*/
	if (w==NIL) goto IF72179;
	w = NIL;
	ctx->vsp=local+15;
	unwind(ctx,local+0);
	local[0]=w;
	goto BLK72095;
	goto IF72180;
IF72179:
	local[15]= NIL;
IF72180:
	w = local[15];
CAT72162:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL72155;
WHX72156:
	local[9]= NIL;
BLK72157:
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK72095:
	ctx->vsp=local; return(local[0]);}

/*repsel*/
static pointer F70989repsel(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[1];
	local[2]= argv[3];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F70980rep1(ctx,4,local+0); /*rep1*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF72216;
	local[0]= fqv[54];
	w = NIL;
	ctx->vsp=local+1;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	goto IF72217;
IF72216:
	local[0]= NIL;
IF72217:
	if (argv[2]==NIL) goto IF72236;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F70983prompt(ctx,1,local+0); /*prompt*/
	local[0]= w;
	goto IF72237;
IF72236:
	local[0]= NIL;
IF72237:
	w = local[0];
	local[0]= w;
BLK72200:
	ctx->vsp=local; return(local[0]);}

/*reploop-select*/
static pointer F70992reploop_select(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT72251;}
	local[0]= loadglobal(fqv[50]);
ENT72251:
	if (n>=2) { local[1]=(argv[1]); goto ENT72250;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT72250:
ENT72249:
	if (n>2) maerror();
	local[2]= fqv[51];
	w = local[2];
	ctx->vsp=local+2;
	bindspecial(ctx,fqv[52],w);
	ctx->vsp=local+5;
	w=(pointer)GENSYM(ctx,0,local+5); /*gensym*/
	local[5]= w;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	if (local[1]==NIL) goto IF72292;
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)F70983prompt(ctx,1,local+9); /*prompt*/
	local[9]= w;
	goto IF72293;
IF72292:
	local[9]= NIL;
IF72293:
	local[9]= loadglobal(fqv[9]);
	local[10]= makeint((eusinteger_t)0L);
	ctx->vsp=local+11;
	w=(pointer)GREATERP(ctx,2,local+9); /*>*/
	if (w==NIL) goto IF72302;
	ctx->vsp=local+9;
	w=(pointer)LISTBINDINGS(ctx,0,local+9); /*system:list-all-bindings*/
	local[7] = w;
	local[9]= local[7];
	goto IF72303;
IF72302:
	local[9]= NIL;
IF72303:
	local[9]= loadglobal(fqv[55]);
	local[10]= fqv[56];
	local[11]= local[0];
	local[12]= fqv[57];
	local[13]= local[0];
	local[14]= local[5];
	local[15]= local[1];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,8,local+9); /*send*/
	{jmp_buf jb;
	w = fqv[54];
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT72330;}
WHL72337:
	if (T==NIL) goto WHX72338;
	local[15]= loadglobal(fqv[55]);
	local[16]= fqv[58];
	local[17]= loadglobal(fqv[59]);
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,3,local+15); /*send*/
	if (w!=NIL) goto IF72345;
	local[15]= loadglobal(fqv[60]);
	ctx->vsp=local+16;
	w=(*ftab[9])(ctx,1,local+15,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto IF72360;
	local[15]= loadglobal(fqv[60]);
	ctx->vsp=local+16;
	w=(pointer)FUNCALL(ctx,1,local+15); /*funcall*/
	local[15]= w;
	goto IF72361;
IF72360:
	local[15]= NIL;
	local[16]= loadglobal(fqv[60]);
WHL72389:
	if (local[16]==NIL) goto WHX72390;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	w=local[16];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16] = (w)->c.cons.cdr;
	w = local[17];
	local[15] = w;
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(*ftab[9])(ctx,1,local+17,&ftab[9],fqv[48]); /*functionp*/
	if (w==NIL) goto IF72438;
	local[17]= local[15];
	ctx->vsp=local+18;
	w=(pointer)FUNCALL(ctx,1,local+17); /*funcall*/
	local[17]= w;
	goto IF72439;
IF72438:
	local[17]= NIL;
IF72439:
	goto WHL72389;
WHX72390:
	local[17]= NIL;
BLK72391:
	w = NIL;
	local[15]= w;
IF72361:
	goto IF72346;
IF72345:
	local[15]= NIL;
IF72346:
	goto WHL72337;
WHX72338:
	local[15]= NIL;
BLK72339:
	w = local[15];
CAT72330:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,1);
	w = local[9];
	local[0]= w;
BLK72247:
	ctx->vsp=local; return(local[0]);}

/*reploop*/
static pointer F70995reploop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT72460;}
	local[0]= loadglobal(fqv[50]);
ENT72460:
	if (n>=3) { local[1]=(argv[2]); goto ENT72459;}
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	local[1]= w;
ENT72459:
ENT72458:
	if (n>3) maerror();
	local[2]= argv[0];
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[47],w);
	if (loadglobal(fqv[61])==NIL) goto IF72496;
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F70992reploop_select(ctx,2,local+6); /*reploop-select*/
	local[6]= w;
	goto IF72497;
IF72496:
	local[6]= local[0];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)F70986reploop_non_select(ctx,2,local+6); /*reploop-non-select*/
	local[6]= w;
IF72497:
	ctx->vsp=local+7;
	unbindx(ctx,1);
	w = local[6];
	local[0]= w;
BLK72456:
	ctx->vsp=local; return(local[0]);}

/*euserror*/
static pointer F70998euserror(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT72517;}
	local[0]= NIL;
ENT72517:
ENT72516:
	if (n>4) maerror();
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[63];
	local[3]= makeint((eusinteger_t)27L);
	local[4]= makeint((eusinteger_t)1L);
	w = makeint((eusinteger_t)48L);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[4]= (pointer)((eusinteger_t)local[4] + (eusinteger_t)w);
	local[5]= loadglobal(fqv[64]);
	ctx->vsp=local+6;
	w=(pointer)THR_SELF(ctx,0,local+6); /*unix:thr-self*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	if (local[0]==NIL) goto IF72550;
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[65];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF72551;
IF72550:
	local[1]= NIL;
IF72551:
	if (argv[2]==NIL) goto IF72561;
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[66];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF72562;
IF72561:
	local[1]= NIL;
IF72562:
	local[1]= loadglobal(fqv[62]);
	local[2]= fqv[67];
	local[3]= makeint((eusinteger_t)27L);
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= loadglobal(fqv[9]);
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[1]= w;
	local[2]= fqv[68];
	w = local[2];
	ctx->vsp=local+3;
	bindspecial(ctx,fqv[11],w);
	w = local[1];
	ctx->vsp=local+6;
	bindspecial(ctx,fqv[9],w);
	{jmp_buf jb;
	w = loadglobal(fqv[9]);
	ctx->vsp=local+9;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT72598;}
	local[15]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+16;
	w=(pointer)F70995reploop(ctx,1,local+15); /*reploop*/
CAT72598:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[9]= w;
	ctx->vsp=local+10;
	unbindx(ctx,2);
	w = local[9];
	local[1]= loadglobal(fqv[9]);
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK72514:
	ctx->vsp=local; return(local[0]);}

/*eustop*/
static pointer F71001eustop(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST72619:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(pointer)ISATTY(ctx,1,local+1); /*unix:isatty*/
	if (w==NIL) goto IF72629;
	local[1]= makeint((eusinteger_t)4L);
	local[2]= fqv[69];
	ctx->vsp=local+3;
	w=(*ftab[10])(ctx,0,local+3,&ftab[10],fqv[70]); /*lisp-implementation-version*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[2])(ctx,3,local+1,&ftab[2],fqv[7]); /*warning-message*/
	local[1]= loadglobal(fqv[62]);
	ctx->vsp=local+2;
	w=(pointer)TERPRI(ctx,1,local+1); /*terpri*/
	local[1]= makeint((eusinteger_t)2L);
	local[2]= fqv[71];
	local[3]= makeint((eusinteger_t)2L);
	ctx->vsp=local+4;
	w=(pointer)SIGNAL(ctx,3,local+1); /*unix:signal*/
	local[1]= makeint((eusinteger_t)13L);
	local[2]= fqv[72];
	ctx->vsp=local+3;
	w=(pointer)SIGNAL(ctx,2,local+1); /*unix:signal*/
	local[1]= fqv[73];
	ctx->vsp=local+2;
	w=(pointer)FBOUNDP(ctx,1,local+1); /*fboundp*/
	if (w==NIL) goto IF72661;
	local[1]= loadglobal(fqv[3]);
	ctx->vsp=local+2;
	w=(*ftab[11])(ctx,1,local+1,&ftab[11],fqv[73]); /*unix:tcgets*/
	local[1]= w;
	storeglobal(fqv[74],w);
	local[1]= loadglobal(fqv[75]);
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,1,local+1,&ftab[12],fqv[76]); /*new-history*/
	local[1]= w;
	goto IF72662;
IF72661:
	local[1]= NIL;
IF72662:
	goto IF72630;
IF72629:
	local[1]= NIL;
IF72630:
	if (local[0]==NIL) goto IF72689;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)ELT(ctx,2,local+1); /*elt*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[13])(ctx,1,local+1,&ftab[13],fqv[77]); /*find-executable*/
	local[1]= w;
	storeglobal(fqv[78],w);
	goto IF72690;
IF72689:
	local[1]= NIL;
IF72690:
	local[1]= fqv[79];
	ctx->vsp=local+2;
	w=(pointer)GETENV(ctx,1,local+1); /*unix:getenv*/
	local[1]= w;
	storeglobal(fqv[80],w);
	local[1]= local[0];
	storeglobal(fqv[81],local[1]);
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[82]); /*pathname-name*/
	local[1]= w;
	storeglobal(fqv[33],w);
	local[1]= fqv[83];
	ctx->vsp=local+2;
	w=(pointer)GETENV(ctx,1,local+1); /*unix:getenv*/
	local[1]= w;
	if (local[1]!=NIL) goto IF72744;
	local[2]= loadglobal(fqv[17]);
	local[3]= fqv[84];
	ctx->vsp=local+4;
	w=(pointer)GETENV(ctx,1,local+3); /*unix:getenv*/
	local[3]= w;
	local[4]= fqv[85];
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,3,local+2); /*concatenate*/
	local[1] = w;
	local[2]= local[1];
	goto IF72745;
IF72744:
	local[2]= NIL;
IF72745:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,1,local+2,&ftab[15],fqv[86]); /*probe-file*/
	if (w==NIL) goto IF72765;
	local[2]= local[1];
	local[3]= fqv[87];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,3,local+2,&ftab[16],fqv[88]); /*load*/
	local[2]= w;
	goto IF72766;
IF72765:
	local[2]= NIL;
IF72766:
	w = local[2];
	local[1]= fqv[89];
	ctx->vsp=local+2;
	w=(*ftab[15])(ctx,1,local+1,&ftab[15],fqv[86]); /*probe-file*/
	if (w==NIL) goto IF72783;
	local[1]= fqv[90];
	local[2]= fqv[87];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(*ftab[16])(ctx,3,local+1,&ftab[16],fqv[88]); /*load*/
	local[1]= w;
	goto IF72784;
IF72783:
	local[1]= NIL;
IF72784:
	if (local[0]==NIL) goto IF72799;
	local[1]= loadglobal(fqv[64]);
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[82]); /*pathname-name*/
	local[1]= w;
	local[2]= fqv[91];
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w==NIL) goto IF72799;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	w = makeint((eusinteger_t)2L);
	if ((eusinteger_t)local[1] < (eusinteger_t)w) goto IF72799;
	local[1]= (pointer)get_sym_func(fqv[92]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[17])(ctx,1,local+1,&ftab[17],fqv[93]); /*exit*/
	local[1]= w;
	goto IF72800;
IF72799:
	local[1]= NIL;
IF72800:
	if (loadglobal(fqv[94])==NIL) goto IF72831;
	local[1]= loadglobal(fqv[94]);
	local[2]= loadglobal(fqv[81]);
	ctx->vsp=local+3;
	w=(pointer)FUNCALL(ctx,2,local+1); /*funcall*/
	local[1]= w;
	goto IF72832;
IF72831:
	local[1]= NIL;
IF72832:
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= loadglobal(fqv[81]);
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[3]= w;
WHL72879:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX72880;
	local[4]= loadglobal(fqv[81]);
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[1] = w;
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	if (makeint((eusinteger_t)40L)!=local[4]) goto CON72902;
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[18])(ctx,1,local+4,&ftab[18],fqv[95]); /*read-from-string*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)EVAL(ctx,1,local+4); /*eval*/
	local[4]= w;
	goto CON72900;
CON72902:
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)0L);
	ctx->vsp=local+6;
	w=(pointer)ELT(ctx,2,local+4); /*elt*/
	local[4]= w;
	local[4]= ((makeint((eusinteger_t)45L))==(local[4])?T:NIL);
	if (local[4]!=NIL) goto CON72900;
CON72915:
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,1,local+4,&ftab[16],fqv[88]); /*load*/
	local[4]= w;
	goto CON72900;
CON72924:
	local[4]= NIL;
CON72900:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL72879;
WHX72880:
	local[4]= NIL;
BLK72881:
	w = NIL;
	{jmp_buf jb;
	w = fqv[96];
	ctx->vsp=local+1;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT72945;}
WHL72952:
	if (T==NIL) goto WHX72953;
	{jmp_buf jb;
	w = makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	mkcatchframe(ctx,w,(jmp_buf *)jb);
	if ((w=(pointer)eussetjmp(jb))!=0) { /*fsp=vsp;*/ goto CAT72959;}
	local[13]= makeint((eusinteger_t)0L);
	local[14]= fqv[97];
	w = local[14];
	ctx->vsp=local+15;
	bindspecial(ctx,fqv[11],w);
	w = local[13];
	ctx->vsp=local+18;
	bindspecial(ctx,fqv[9],w);
	local[21]= (pointer)get_sym_func(fqv[12]);
	ctx->vsp=local+22;
	w=(pointer)F70995reploop(ctx,1,local+21); /*reploop*/
	local[21]= w;
	ctx->vsp=local+22;
	unbindx(ctx,2);
	w = local[21];
	local[13]= fqv[96];
	w = NIL;
	ctx->vsp=local+14;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[13];
CAT72959:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	goto WHL72952;
WHX72953:
	local[7]= NIL;
BLK72954:
	w = local[7];
CAT72945:
	if (w==(pointer)(1)) w=makeint(0);
	restorecatch(ctx);};
	local[0]= w;
BLK72617:
	ctx->vsp=local; return(local[0]);}

/*reset*/
static pointer F71004reset(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	if (n>=1) { local[0]=(argv[0]); goto ENT73001;}
	local[0]= makeint((eusinteger_t)0L);
ENT73001:
ENT73000:
	if (n>1) maerror();
	local[1]= local[0];
	w = NIL;
	ctx->vsp=local+2;
	throw(ctx,vpop(),w);
	error(E_NOCATCHER,NULL);
	w = local[1];
	local[0]= w;
BLK72998:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___toplevel(ctx,n,argv,env)
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
	local[0]= fqv[98];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF73023;
	local[0]= fqv[99];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[18],w);
	goto IF73024;
IF73023:
	local[0]= fqv[100];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF73024:
	local[0]= fqv[101];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[16];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73046;
	local[0]= fqv[16];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[16];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73069;
	local[0]= fqv[16];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73070;
IF73069:
	local[0]= NIL;
IF73070:
	local[0]= fqv[16];
	goto IF73047;
IF73046:
	local[0]= NIL;
IF73047:
	local[0]= fqv[46];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73089;
	local[0]= fqv[46];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[46];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73112;
	local[0]= fqv[46];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73113;
IF73112:
	local[0]= NIL;
IF73113:
	local[0]= fqv[46];
	goto IF73090;
IF73089:
	local[0]= NIL;
IF73090:
	local[0]= fqv[44];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73132;
	local[0]= fqv[44];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[44];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73155;
	local[0]= fqv[44];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73156;
IF73155:
	local[0]= NIL;
IF73156:
	local[0]= fqv[44];
	goto IF73133;
IF73132:
	local[0]= NIL;
IF73133:
	local[0]= fqv[45];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73175;
	local[0]= fqv[45];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[45];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73198;
	local[0]= fqv[45];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73199;
IF73198:
	local[0]= NIL;
IF73199:
	local[0]= fqv[45];
	goto IF73176;
IF73175:
	local[0]= NIL;
IF73176:
	local[0]= fqv[43];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73218;
	local[0]= fqv[43];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[43];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73241;
	local[0]= fqv[43];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73242;
IF73241:
	local[0]= NIL;
IF73242:
	local[0]= fqv[43];
	goto IF73219;
IF73218:
	local[0]= NIL;
IF73219:
	local[0]= fqv[41];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73261;
	local[0]= fqv[41];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[41];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73284;
	local[0]= fqv[41];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73285;
IF73284:
	local[0]= NIL;
IF73285:
	local[0]= fqv[41];
	goto IF73262;
IF73261:
	local[0]= NIL;
IF73262:
	local[0]= fqv[42];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73304;
	local[0]= fqv[42];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[42];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73327;
	local[0]= fqv[42];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73328;
IF73327:
	local[0]= NIL;
IF73328:
	local[0]= fqv[42];
	goto IF73305;
IF73304:
	local[0]= NIL;
IF73305:
	local[0]= fqv[104];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73347;
	local[0]= fqv[104];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[104];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73370;
	local[0]= fqv[104];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[3]);
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73371;
IF73370:
	local[0]= NIL;
IF73371:
	local[0]= fqv[104];
	goto IF73348;
IF73347:
	local[0]= NIL;
IF73348:
	local[0]= fqv[105];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73393;
	local[0]= fqv[105];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[105];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73416;
	local[0]= fqv[105];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73417;
IF73416:
	local[0]= NIL;
IF73417:
	local[0]= fqv[105];
	goto IF73394;
IF73393:
	local[0]= NIL;
IF73394:
	local[0]= fqv[94];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73436;
	local[0]= fqv[94];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[94];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73459;
	local[0]= fqv[94];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73460;
IF73459:
	local[0]= NIL;
IF73460:
	local[0]= fqv[94];
	goto IF73437;
IF73436:
	local[0]= NIL;
IF73437:
	local[0]= fqv[47];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73479;
	local[0]= fqv[47];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[47];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73502;
	local[0]= fqv[47];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73503;
IF73502:
	local[0]= NIL;
IF73503:
	local[0]= fqv[47];
	goto IF73480;
IF73479:
	local[0]= NIL;
IF73480:
	local[0]= fqv[37];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73522;
	local[0]= fqv[37];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[37];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73545;
	local[0]= fqv[37];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73546;
IF73545:
	local[0]= NIL;
IF73546:
	local[0]= fqv[37];
	goto IF73523;
IF73522:
	local[0]= NIL;
IF73523:
	local[0]= fqv[9];
	local[1]= fqv[106];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[11];
	local[1]= fqv[106];
	local[2]= fqv[107];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[4];
	local[1]= fqv[106];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[33];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73589;
	local[0]= fqv[33];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[33];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73612;
	local[0]= fqv[33];
	local[1]= fqv[103];
	local[2]= fqv[108];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73613;
IF73612:
	local[0]= NIL;
IF73613:
	local[0]= fqv[33];
	goto IF73590;
IF73589:
	local[0]= NIL;
IF73590:
	local[0]= fqv[25];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73632;
	local[0]= fqv[25];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[25];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73655;
	local[0]= fqv[25];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73656;
IF73655:
	local[0]= NIL;
IF73656:
	local[0]= fqv[25];
	goto IF73633;
IF73632:
	local[0]= NIL;
IF73633:
	local[0]= fqv[74];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73675;
	local[0]= fqv[74];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[74];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73698;
	local[0]= fqv[74];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73699;
IF73698:
	local[0]= NIL;
IF73699:
	local[0]= fqv[74];
	goto IF73676;
IF73675:
	local[0]= NIL;
IF73676:
	local[0]= fqv[81];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73718;
	local[0]= fqv[81];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[81];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73741;
	local[0]= fqv[81];
	local[1]= fqv[103];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73742;
IF73741:
	local[0]= NIL;
IF73742:
	local[0]= fqv[81];
	goto IF73719;
IF73718:
	local[0]= NIL;
IF73719:
	local[0]= fqv[55];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73761;
	local[0]= fqv[55];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[55];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73784;
	local[0]= fqv[55];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[109]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[110];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73785;
IF73784:
	local[0]= NIL;
IF73785:
	local[0]= fqv[55];
	goto IF73762;
IF73761:
	local[0]= NIL;
IF73762:
	local[0]= fqv[60];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73829;
	local[0]= fqv[60];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[60];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73852;
	local[0]= fqv[60];
	local[1]= fqv[103];
	local[2]= fqv[111];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73853;
IF73852:
	local[0]= NIL;
IF73853:
	local[0]= fqv[60];
	goto IF73830;
IF73829:
	local[0]= NIL;
IF73830:
	local[0]= fqv[0];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73876;
	local[0]= fqv[0];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[0];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73899;
	local[0]= fqv[0];
	local[1]= fqv[103];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73900;
IF73899:
	local[0]= NIL;
IF73900:
	local[0]= fqv[0];
	goto IF73877;
IF73876:
	local[0]= NIL;
IF73877:
	local[0]= fqv[59];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73919;
	local[0]= fqv[59];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[59];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73942;
	local[0]= fqv[59];
	local[1]= fqv[103];
	local[2]= makeflt(1.0000000000000000000000e+01);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73943;
IF73942:
	local[0]= NIL;
IF73943:
	local[0]= fqv[59];
	goto IF73920;
IF73919:
	local[0]= NIL;
IF73920:
	local[0]= fqv[61];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF73962;
	local[0]= fqv[61];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[61];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF73985;
	local[0]= fqv[61];
	local[1]= fqv[103];
	local[2]= fqv[112];
	ctx->vsp=local+3;
	w=(pointer)GETENV(ctx,1,local+2); /*unix:getenv*/
	local[2]= ((w)==NIL?T:NIL);
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF73986;
IF73985:
	local[0]= NIL;
IF73986:
	local[0]= fqv[61];
	goto IF73963;
IF73962:
	local[0]= NIL;
IF73963:
	local[0]= fqv[20];
	local[1]= fqv[103];
	local[2]= T;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[111],module,F70957count_up_timer,fqv[113]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[114],module,F70960skip_blank,fqv[115]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[116],module,F70964read_list_from_line,fqv[117]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[71],module,F70967sigint_handler,fqv[118]);
	local[0]= fqv[13];
	local[1]= fqv[102];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF74026;
	local[0]= fqv[13];
	local[1]= fqv[102];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[13];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF74049;
	local[0]= fqv[13];
	local[1]= fqv[103];
	local[2]= loadglobal(fqv[119]);
	local[3]= makeint((eusinteger_t)32L);
	ctx->vsp=local+4;
	w=(*ftab[19])(ctx,2,local+2,&ftab[19],fqv[120]); /*make-sequence*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF74050;
IF74049:
	local[0]= NIL;
IF74050:
	local[0]= fqv[13];
	goto IF74027;
IF74026:
	local[0]= NIL;
IF74027:
	ctx->vsp=local+0;
	compfun(ctx,fqv[72],module,F70971eussig,fqv[121]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[122],module,F70974evaluate_stream,fqv[123]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[12],module,F70977toplevel_prompt,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F70980rep1,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F70983prompt,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F70986reploop_non_select,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[57],module,F70989repsel,fqv[131]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F70992reploop_select,fqv[133]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[134],module,F70995reploop,fqv[135]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[51],module,F70998euserror,fqv[136]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[137],module,F71001eustop,fqv[138]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[139],module,F71004reset,fqv[140]);
	local[0]= fqv[141];
	local[1]= fqv[142];
	ctx->vsp=local+2;
	w=(*ftab[20])(ctx,2,local+0,&ftab[20],fqv[143]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<21; i++) ftab[i]=fcallx;
}
