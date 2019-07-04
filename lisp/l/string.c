/* ./string.c :  entry=string */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "string.h"
#pragma init (register_string)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___string();
extern pointer build_quote_vector();
static int register_string()
  { add_module_initializer("___string", ___string);}

static pointer F51293read_sharp_backslash();
static pointer F51297true_string();
static pointer F51300string();
static pointer F51303make_string();
static pointer F51306string_left_trim();
static pointer F51309string_right_trim();
static pointer F51312string_trim();
static pointer F51315nstring_downcase();
static pointer F51318nstring_upcase();
static pointer F51321string_upcase();
static pointer F51324string_downcase();
static pointer F51327string_();
static pointer F51330string_equal();
static pointer F51333substringp();
static pointer F51336string_match_at();
static pointer F51339string_match();
static pointer F51342nth_position();
static pointer F51345bm_string_match();
static pointer F51348string_replace();
static pointer F51358explode_directory_names();
static pointer F51362pathnamep();
static pointer F51365pathname();
static pointer F51368namestring();
static pointer F51371pathname_directory();
static pointer F51374pathname_name();
static pointer F51377pathname_type();
static pointer F51380directory_namestring();
static pointer F51383make_pathname();
static pointer F51386parse_namestring();
static pointer F51390null_string_p();
static pointer F51393merge_pathnames();
static pointer F51396concatenate_pathnames();
static pointer F51399truename();
static pointer F51418url_pathname();
static pointer F51420parse_url();
static pointer F51422escape_url();
static pointer F51424escaped_url_string_from_namestring();
static pointer F51426unescape_url();
static pointer F51428unescaped_url_string_from_namestring();
static pointer F51430digits_string();
static pointer F51432timed_file_name();
static pointer F51434dated_file_name();
static pointer F51436sequential_file_name();

/*read_sharp_backslash*/
static pointer F51293read_sharp_backslash(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READCH(ctx,1,local+3); /*read-char*/
	local[0] = w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ALPHAP(ctx,1,local+3); /*alpha-char-p*/
	if (w==NIL) goto CON51537;
	local[3]= local[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)UNREADCH(ctx,2,local+3); /*unread-char*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)READ(ctx,1,local+3); /*read*/
	local[1] = w;
	local[3]= *(ovafptr(local[1],fqv[0]));
	local[4]= fqv[1];
	local[5]= fqv[2];
	local[6]= (pointer)get_sym_func(fqv[3]);
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,4,local+3,&ftab[0],fqv[4]); /*assoc*/
	local[2] = w;
	if (local[2]==NIL) goto IF51576;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF51577;
IF51576:
	local[3]= *(ovafptr(local[1],fqv[0]));
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	if (makeint((eusinteger_t)1L)!=local[3]) goto IF51589;
	local[3]= local[0];
	goto IF51590;
IF51589:
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
IF51590:
IF51577:
	goto CON51535;
CON51537:
	local[3]= local[0];
	goto CON51535;
CON51600:
	local[3]= NIL;
CON51535:
	w = local[3];
	local[0]= w;
BLK51499:
	ctx->vsp=local; return(local[0]);}

/*true-string*/
static pointer F51297true_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto IF51620;
	local[0]= argv[0]->c.obj.iv[4];
	goto IF51621;
IF51620:
	local[0]= argv[0];
IF51621:
	w = local[0];
	local[0]= w;
BLK51610:
	ctx->vsp=local; return(local[0]);}

/*string*/
static pointer F51300string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!isstring(w)) goto CON51646;
	local[0]= argv[0];
	goto CON51644;
CON51646:
	w = argv[0];
	if (!issymbol(w)) goto CON51652;
	local[0]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
	goto CON51644;
CON51652:
	w = argv[0];
	if (!isnum(w)) goto CON51664;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[1])(ctx,1,local+0,&ftab[1],fqv[6]); /*princ-to-string*/
	local[0]= w;
	goto CON51644;
CON51664:
	local[0]= fqv[7];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON51644;
CON51673:
	local[0]= NIL;
CON51644:
	w = local[0];
	local[0]= w;
BLK51634:
	ctx->vsp=local; return(local[0]);}

/*make-string*/
static pointer F51303make_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= loadglobal(fqv[8]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,2,local+0); /*instantiate*/
	local[0]= w;
BLK51682:
	ctx->vsp=local; return(local[0]);}

/*string-left-trim*/
static pointer F51306string_left_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F51297true_string(ctx,1,local+1); /*true-string*/
	argv[1] = w;
WHL51742:
	local[1]= argv[1];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[9]); /*position*/
	if (w==NIL) goto WHX51743;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)ADD1(ctx,1,local+1); /*1+*/
	local[0] = w;
	goto WHL51742;
WHX51743:
	local[1]= NIL;
BLK51744:
	local[1]= argv[1];
	local[2]= local[0];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK51699:
	ctx->vsp=local; return(local[0]);}

/*string-right-trim*/
static pointer F51309string_right_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F51297true_string(ctx,1,local+1); /*true-string*/
	argv[1] = w;
WHL51818:
	local[1]= argv[1];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)SUB1(ctx,1,local+2); /*1-*/
	{ register eusinteger_t i=intval(w);
	  w=makeint(local[1]->c.str.chars[i]);}
	local[1]= w;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[9]); /*position*/
	if (w==NIL) goto WHX51819;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)SUB1(ctx,1,local+1); /*1-*/
	local[0] = w;
	goto WHL51818;
WHX51819:
	local[1]= NIL;
BLK51820:
	local[1]= argv[1];
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SUBSEQ(ctx,3,local+1); /*subseq*/
	local[0]= w;
BLK51778:
	ctx->vsp=local; return(local[0]);}

/*string-trim*/
static pointer F51312string_trim(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)F51309string_right_trim(ctx,2,local+1); /*string-right-trim*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F51306string_left_trim(ctx,2,local+0); /*string-left-trim*/
	local[0]= w;
BLK51852:
	ctx->vsp=local; return(local[0]);}

/*nstring-downcase*/
static pointer F51315nstring_downcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[10], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51896;
	local[0] = makeint((eusinteger_t)0L);
KEY51896:
	if (n & (1<<1)) goto KEY51900;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY51900:
	w = argv[0];
	if (isstring(w)) goto IF51911;
	local[2]= fqv[11];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF51912;
IF51911:
	local[2]= NIL;
IF51912:
WHL51920:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX51921;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHDOWNCASE(ctx,1,local+4); /*char-downcase*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.str.chars[i]=intval(w);}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL51920;
WHX51921:
	local[2]= NIL;
BLK51922:
	w = argv[0];
	local[0]= w;
BLK51873:
	ctx->vsp=local; return(local[0]);}

/*nstring-upcase*/
static pointer F51318nstring_upcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[12], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY51974;
	local[0] = makeint((eusinteger_t)0L);
KEY51974:
	if (n & (1<<1)) goto KEY51978;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[1] = w;
KEY51978:
	w = argv[0];
	if (isstring(w)) goto IF51989;
	local[2]= fqv[13];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto IF51990;
IF51989:
	local[2]= NIL;
IF51990:
WHL51998:
	local[2]= local[0];
	w = local[1];
	if ((eusinteger_t)local[2] >= (eusinteger_t)w) goto WHX51999;
	local[2]= argv[0];
	local[3]= local[0];
	local[4]= argv[0];
	{ register eusinteger_t i=intval(local[0]);
	  w=makeint(local[4]->c.str.chars[i]);}
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CHUPCASE(ctx,1,local+4); /*char-upcase*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[3]); v=local[2];
	  v->c.str.chars[i]=intval(w);}
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)ADD1(ctx,1,local+2); /*1+*/
	local[0] = w;
	goto WHL51998;
WHX51999:
	local[2]= NIL;
BLK52000:
	w = argv[0];
	local[0]= w;
BLK51955:
	ctx->vsp=local; return(local[0]);}

/*string-upcase*/
static pointer F51321string_upcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[14], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY52043;
	local[0] = makeint((eusinteger_t)0L);
KEY52043:
	if (n & (1<<1)) goto KEY52048;
	local[1] = NIL;
KEY52048:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F51297true_string(ctx,1,local+2); /*true-string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[15];
	local[5]= local[0];
	local[6]= fqv[16];
	if (local[1]==NIL) goto IF52079;
	local[7]= local[1];
	goto IF52080;
IF52079:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
IF52080:
	ctx->vsp=local+8;
	w=(pointer)F51318nstring_upcase(ctx,5,local+3); /*nstring-upcase*/
	local[0]= w;
BLK52033:
	ctx->vsp=local; return(local[0]);}

/*string-downcase*/
static pointer F51324string_downcase(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[17], &argv[1], n-1, local+0, 0);
	if (n & (1<<0)) goto KEY52103;
	local[0] = makeint((eusinteger_t)0L);
KEY52103:
	if (n & (1<<1)) goto KEY52108;
	local[1] = NIL;
KEY52108:
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)F51297true_string(ctx,1,local+2); /*true-string*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)COPYSEQ(ctx,1,local+2); /*copy-seq*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[15];
	local[5]= local[0];
	local[6]= fqv[16];
	if (local[1]==NIL) goto IF52139;
	local[7]= local[1];
	goto IF52140;
IF52139:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
IF52140:
	ctx->vsp=local+8;
	w=(pointer)F51315nstring_downcase(ctx,5,local+3); /*nstring-downcase*/
	local[0]= w;
BLK52093:
	ctx->vsp=local; return(local[0]);}

/*string=*/
static pointer F51327string_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[18], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY52167;
	local[0] = makeint((eusinteger_t)0L);
KEY52167:
	if (n & (1<<1)) goto KEY52172;
	local[1] = makeint((eusinteger_t)100000000L);
KEY52172:
	if (n & (1<<2)) goto KEY52177;
	local[2] = makeint((eusinteger_t)0L);
KEY52177:
	if (n & (1<<3)) goto KEY52182;
	local[3] = makeint((eusinteger_t)100000000L);
KEY52182:
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[3])(ctx,6,local+4,&ftab[3],fqv[19]); /*stringeq*/
	local[0]= w;
BLK52153:
	ctx->vsp=local; return(local[0]);}

/*string-equal*/
static pointer F51330string_equal(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[20], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY52216;
	local[0] = makeint((eusinteger_t)0L);
KEY52216:
	if (n & (1<<1)) goto KEY52221;
	local[1] = makeint((eusinteger_t)100000000L);
KEY52221:
	if (n & (1<<2)) goto KEY52226;
	local[2] = makeint((eusinteger_t)0L);
KEY52226:
	if (n & (1<<3)) goto KEY52231;
	local[3] = makeint((eusinteger_t)100000000L);
KEY52231:
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[2];
	local[9]= local[3];
	ctx->vsp=local+10;
	w=(*ftab[4])(ctx,6,local+4,&ftab[4],fqv[21]); /*stringequal*/
	local[0]= w;
BLK52202:
	ctx->vsp=local; return(local[0]);}

/*substringp*/
static pointer F51333substringp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[1];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[0]= (pointer)((eusinteger_t)local[0] - (eusinteger_t)w);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= makeint((eusinteger_t)0L);
TAG52300:
	local[3]= local[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)GREATERP(ctx,2,local+3); /*>*/
	if (w==NIL) goto IF52305;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK52265;
	goto IF52306;
IF52305:
	local[3]= NIL;
IF52306:
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[22];
	local[6]= local[2];
	local[7]= fqv[23];
	local[8]= local[2];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F51330string_equal(ctx,6,local+3); /*string-equal*/
	if (w==NIL) goto IF52321;
	w = T;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK52251;
	goto IF52322;
IF52321:
	local[3]= NIL;
IF52322:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[3]= w;
	local[2] = local[3];
	w = NIL;
	ctx->vsp=local+3;
	goto TAG52300;
	w = NIL;
	local[0]= w;
BLK52265:
	w = local[0];
	local[0]= w;
BLK52251:
	ctx->vsp=local; return(local[0]);}

/*string-match-at*/
static pointer F51336string_match_at(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= local[0];
WHL52429:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX52430;
	local[3]= argv[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= argv[1];
	local[5]= argv[2];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	if (w==local[3]) goto IF52438;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK52379;
	goto IF52439;
IF52438:
	local[3]= NIL;
IF52439:
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL52429;
WHX52430:
	local[3]= NIL;
BLK52431:
	w = NIL;
	w = T;
	local[0]= w;
BLK52379:
	ctx->vsp=local; return(local[0]);}

/*string-match*/
static pointer F51339string_match(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52480;}
	local[0]= makeint((eusinteger_t)0L);
ENT52480:
	if (n>=4) { local[1]=(argv[3]); goto ENT52479;}
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
ENT52479:
ENT52478:
	if (n>4) maerror();
	local[2]= local[1];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MIN(ctx,2,local+2); /*min*/
	local[1] = w;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= local[1];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)-1L);
	ctx->vsp=local+7;
	w=(pointer)MINUS(ctx,4,local+3); /*-*/
	local[3]= w;
WHL52546:
	local[4]= local[2];
	w = local[3];
	if ((eusinteger_t)local[4] >= (eusinteger_t)w) goto WHX52547;
	local[4]= argv[0];
	local[5]= argv[1];
	local[6]= local[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F51336string_match_at(ctx,3,local+4); /*string-match-at*/
	if (w==NIL) goto IF52555;
	local[4]= local[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	ctx->vsp=local+4;
	local[0]=w;
	goto BLK52476;
	goto IF52556;
IF52555:
	local[4]= NIL;
IF52556:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL52546;
WHX52547:
	local[4]= NIL;
BLK52548:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK52476:
	ctx->vsp=local; return(local[0]);}

/*nth-position*/
static pointer F51342nth_position(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[3];
WHL52644:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX52645;
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= fqv[15];
	local[6]= argv[2];
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[9]); /*position*/
	local[0] = w;
	if (local[0]!=NIL) goto IF52667;
	w = NIL;
	ctx->vsp=local+3;
	local[0]=w;
	goto BLK52596;
	goto IF52668;
IF52667:
	local[3]= NIL;
IF52668:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	argv[2] = w;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL52644;
WHX52645:
	local[3]= NIL;
BLK52646:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK52596:
	ctx->vsp=local; return(local[0]);}

/*bm-string-match*/
static pointer F51345bm_string_match(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT52710;}
	local[0]= makeint((eusinteger_t)0L);
ENT52710:
	if (n>=4) { local[1]=(argv[3]); goto ENT52709;}
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
ENT52709:
ENT52708:
	if (n>4) maerror();
	local[2]= makeint((eusinteger_t)256L);
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,1,local+2,&ftab[5],fqv[24]); /*make-array*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)0L);
	local[6]= local[2];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(*ftab[6])(ctx,2,local+6,&ftab[6],fqv[25]); /*fill*/
	local[6]= makeint((eusinteger_t)0L);
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[7]= w;
WHL52785:
	local[8]= local[6];
	w = local[7];
	if ((eusinteger_t)local[8] >= (eusinteger_t)w) goto WHX52786;
	local[8]= local[2];
	local[9]= argv[0];
	{ register eusinteger_t i=intval(local[6]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	local[10]= local[3];
	local[11]= local[6];
	local[12]= makeint((eusinteger_t)1L);
	ctx->vsp=local+13;
	w=(pointer)MINUS(ctx,3,local+10); /*-*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)ASET(ctx,3,local+8); /*aset*/
	local[8]= local[6];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[6] = w;
	goto WHL52785;
WHX52786:
	local[8]= NIL;
BLK52787:
	w = NIL;
	local[6]= local[0];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SUB1(ctx,1,local+7); /*1-*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[4] = w;
WHL52836:
	local[6]= local[4];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)LESSP(ctx,2,local+6); /*<*/
	if (w==NIL) goto WHX52837;
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SUB1(ctx,1,local+6); /*1-*/
	local[5] = w;
WHL52854:
	local[6]= argv[1];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= argv[0];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)AREF(ctx,2,local+7); /*aref*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)NUMEQUAL(ctx,2,local+6); /*=*/
	if (w==NIL) goto WHX52855;
	local[6]= local[5];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)LSEQP(ctx,2,local+6); /*<=*/
	if (w==NIL) goto IF52869;
	w = local[4];
	ctx->vsp=local+6;
	local[0]=w;
	goto BLK52706;
	goto IF52870;
IF52869:
	local[6]= NIL;
IF52870:
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)SUB1(ctx,1,local+6); /*1-*/
	local[4] = w;
	local[6]= local[5];
	ctx->vsp=local+7;
	w=(pointer)SUB1(ctx,1,local+6); /*1-*/
	local[5] = w;
	goto WHL52854;
WHX52855:
	local[6]= NIL;
BLK52856:
	local[6]= local[4];
	local[7]= local[3];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,2,local+7); /*-*/
	local[7]= w;
	local[8]= local[2];
	local[9]= argv[1];
	{ register eusinteger_t i=intval(local[4]);
	  w=makeint(local[9]->c.str.chars[i]);}
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)AREF(ctx,2,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MAX(ctx,2,local+7); /*max*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[4] = w;
	goto WHL52836;
WHX52837:
	local[6]= NIL;
BLK52838:
	w = local[6];
	w = NIL;
	local[0]= w;
BLK52706:
	ctx->vsp=local; return(local[0]);}

/*string-replace*/
static pointer F51348string_replace(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT52935;}
	local[0]= makeint((eusinteger_t)0L);
ENT52935:
ENT52934:
	if (n>4) maerror();
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)F51300string(ctx,1,local+1); /*string*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F51339string_match(ctx,3,local+1); /*string-match*/
	local[0] = w;
	if (local[0]==NIL) goto CON52955;
	local[1]= loadglobal(fqv[8]);
	local[2]= argv[2];
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,3,local+2); /*subseq*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[2];
	local[5]= local[0];
	local[6]= argv[1];
	ctx->vsp=local+7;
	w=(pointer)F51300string(ctx,1,local+6); /*string*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LENGTH(ctx,1,local+6); /*length*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,2,local+4); /*subseq*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)CONCATENATE(ctx,4,local+1); /*concatenate*/
	local[1]= w;
	goto CON52953;
CON52955:
	local[1]= argv[2];
	goto CON52953;
CON52992:
	local[1]= NIL;
CON52953:
	w = local[1];
	local[0]= w;
BLK52932:
	ctx->vsp=local; return(local[0]);}

/*:get*/
static pointer M53005string_get(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)PEEK(ctx,3,local+0); /*system:peek*/
	local[0]= w;
BLK53006:
	ctx->vsp=local; return(local[0]);}

/*:set*/
static pointer M53028string_set(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	w = argv[2];
	if (!isnum(w)) goto IF53047;
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= argv[3];
	local[3]= argv[4];
	ctx->vsp=local+4;
	w=(pointer)POKE(ctx,4,local+0); /*system:poke*/
	local[0]= w;
	goto IF53048;
IF53047:
	local[0]= argv[4];
	local[1]= fqv[26];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.cdr;
	local[1]= NIL;
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[27]); /*flatten*/
	local[2]= w;
WHL53098:
	if (local[2]==NIL) goto WHX53099;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	w = local[1];
	if (!isnum(w)) goto CON53149;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ROUND(ctx,1,local+3); /*round*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= argv[3];
	local[6]= argv[4];
	ctx->vsp=local+7;
	w=(pointer)POKE(ctx,4,local+3); /*system:poke*/
	local[3]= argv[3];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)PLUS(ctx,2,local+3); /*+*/
	argv[3] = w;
	local[3]= argv[3];
	goto CON53147;
CON53149:
	local[3]= makeint((eusinteger_t)0L);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
WHL53204:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX53205;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)ELT(ctx,2,local+5); /*elt*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)ROUND(ctx,1,local+5); /*round*/
	local[5]= w;
	local[6]= argv[0];
	local[7]= argv[3];
	local[8]= argv[4];
	ctx->vsp=local+9;
	w=(pointer)POKE(ctx,4,local+5); /*system:poke*/
	local[5]= argv[3];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)PLUS(ctx,2,local+5); /*+*/
	argv[3] = w;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL53204;
WHX53205:
	local[5]= NIL;
BLK53206:
	w = NIL;
	local[3]= w;
	goto CON53147;
CON53175:
	local[3]= NIL;
CON53147:
	goto WHL53098;
WHX53099:
	local[3]= NIL;
BLK53100:
	w = NIL;
	local[0]= w;
IF53048:
	w = local[0];
	local[0]= w;
BLK53029:
	ctx->vsp=local; return(local[0]);}

/*explode-directory-names*/
static pointer F51358explode_directory_names(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
WHL53293:
	local[4]= makeint((eusinteger_t)47L);
	local[5]= argv[0];
	local[6]= fqv[15];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,4,local+4,&ftab[2],fqv[9]); /*position*/
	local[3] = w;
	if (local[3]==NIL) goto WHX53294;
	local[4]= argv[0];
	local[5]= local[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)SUBSEQ(ctx,3,local+4); /*subseq*/
	local[0] = w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[4] <= (eusinteger_t)w) goto IF53322;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF53323;
IF53322:
	local[4]= NIL;
IF53323:
	local[4]= local[3];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[2] = w;
	goto WHL53293;
WHX53294:
	local[4]= NIL;
BLK53295:
	local[4]= argv[0];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,2,local+4); /*subseq*/
	local[0] = w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LENGTH(ctx,1,local+4); /*length*/
	local[4]= w;
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[4] <= (eusinteger_t)w) goto IF53361;
	local[4]= local[0];
	w = local[1];
	ctx->vsp=local+5;
	local[1] = cons(ctx,local[4],w);
	local[4]= local[1];
	goto IF53362;
IF53361:
	local[4]= NIL;
IF53362:
	w = local[1];
	local[0]= w;
BLK53265:
	ctx->vsp=local; return(local[0]);}

/*:parse-namestring*/
static pointer M53402pathname_parse_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	argv[0]->c.obj.iv[2] = NIL;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[8])(ctx,1,local+7,&ftab[8],fqv[28]); /*zerop*/
	if (w==NIL) goto IF53444;
	argv[0]->c.obj.iv[0] = fqv[29];
	argv[0]->c.obj.iv[1] = fqv[30];
	w = argv[0];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK53403;
	goto IF53445;
IF53444:
	local[7]= NIL;
IF53445:
	local[7]= makeint((eusinteger_t)58L);
	local[8]= argv[2];
	ctx->vsp=local+9;
	w=(*ftab[2])(ctx,2,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto IF53472;
	local[0] = local[6];
	local[7]= argv[2];
	local[8]= makeint((eusinteger_t)0L);
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	argv[0]->c.obj.iv[0] = w;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[0] = w;
	local[7]= local[0];
	goto IF53473;
IF53472:
	local[7]= NIL;
IF53473:
	local[1] = local[0];
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)47L);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON53515;
	local[7]= fqv[31];
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	argv[0]->c.obj.iv[2] = cons(ctx,local[7],w);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[1] = w;
	local[7]= local[1];
	goto CON53513;
CON53515:
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)ELT(ctx,2,local+7); /*elt*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)126L);
	ctx->vsp=local+9;
	w=(pointer)EQ(ctx,2,local+7); /*eql*/
	if (w==NIL) goto CON53547;
	local[7]= fqv[32];
	ctx->vsp=local+8;
	w=(pointer)GETENV(ctx,1,local+7); /*unix:getenv*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)F51358explode_directory_names(ctx,1,local+7); /*explode-directory-names*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= argv[0]->c.obj.iv[2];
	local[8]= fqv[31];
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,1,local+8); /*list*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)NCONC(ctx,2,local+7); /*nconc*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[1] = w;
	local[7]= local[1];
	goto CON53513;
CON53547:
	local[7]= NIL;
CON53513:
WHL53591:
	local[7]= makeint((eusinteger_t)47L);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto WHX53592;
	local[7]= argv[2];
	local[8]= local[1];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	local[3] = w;
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	w = makeint((eusinteger_t)0L);
	if ((eusinteger_t)local[7] <= (eusinteger_t)w) goto IF53620;
	local[7]= local[3];
	w = argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	argv[0]->c.obj.iv[2] = cons(ctx,local[7],w);
	local[7]= argv[0]->c.obj.iv[2];
	goto IF53621;
IF53620:
	local[7]= NIL;
IF53621:
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[1] = w;
	local[2] = local[1];
	goto WHL53591;
WHX53592:
	local[7]= NIL;
BLK53593:
	local[7]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+8;
	w=(pointer)NREVERSE(ctx,1,local+7); /*nreverse*/
	argv[0]->c.obj.iv[2] = w;
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	local[4] = w;
	local[7]= local[4];
	local[8]= fqv[33];
	ctx->vsp=local+9;
	w=(pointer)EQUAL(ctx,2,local+7); /*equal*/
	if (w==NIL) goto CON53673;
	argv[0]->c.obj.iv[3] = local[4];
	argv[0]->c.obj.iv[4] = NIL;
	local[7]= argv[0]->c.obj.iv[4];
	goto CON53671;
CON53673:
	local[7]= makeint((eusinteger_t)46L);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[2] = w;
	if (local[2]!=NIL) goto CON53706;
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)LENGTH(ctx,1,local+7); /*length*/
	local[7]= w;
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto IF53712;
	local[7]= argv[2];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	argv[0]->c.obj.iv[3] = w;
	local[7]= argv[0]->c.obj.iv[3];
	goto IF53713;
IF53712:
	local[7]= NIL;
IF53713:
	goto CON53704;
CON53706:
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[2] = w;
WHL53742:
	local[7]= makeint((eusinteger_t)46L);
	local[8]= argv[2];
	local[9]= fqv[15];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(*ftab[2])(ctx,4,local+7,&ftab[2],fqv[9]); /*position*/
	local[6] = w;
	if (local[6]==NIL) goto WHX53743;
	local[7]= local[6];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[2] = w;
	goto WHL53742;
WHX53743:
	local[7]= NIL;
BLK53744:
	local[7]= argv[2];
	local[8]= local[1];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)SUB1(ctx,1,local+9); /*1-*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SUBSEQ(ctx,3,local+7); /*subseq*/
	argv[0]->c.obj.iv[3] = w;
	local[7]= argv[2];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,2,local+7); /*subseq*/
	argv[0]->c.obj.iv[4] = w;
	local[7]= argv[0]->c.obj.iv[3];
	ctx->vsp=local+8;
	w=(pointer)F51390null_string_p(ctx,1,local+7); /*null-string-p*/
	if (w==NIL) goto IF53788;
	argv[0]->c.obj.iv[3] = NIL;
	local[7]= argv[0]->c.obj.iv[3];
	goto IF53789;
IF53788:
	local[7]= NIL;
IF53789:
	goto CON53704;
CON53729:
	local[7]= NIL;
CON53704:
	goto CON53671;
CON53688:
	local[7]= NIL;
CON53671:
	w = argv[0];
	local[0]= w;
BLK53403:
	ctx->vsp=local; return(local[0]);}

/*:directory-string*/
static pointer M53806pathname_directory_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[2];
	w=argv[0]->c.obj.iv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	local[3]= fqv[31];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	if (w==NIL) goto IF53833;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[2]= fqv[34];
	w = local[0];
	ctx->vsp=local+3;
	local[0] = cons(ctx,local[2],w);
	local[2]= local[0];
	goto IF53834;
IF53833:
	local[2]= NIL;
IF53834:
	local[2]= NIL;
	local[3]= local[1];
WHL53914:
	if (local[3]==NIL) goto WHX53915;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	w = local[4];
	local[2] = w;
	local[4]= local[2];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	local[4]= fqv[35];
	w = local[0];
	ctx->vsp=local+5;
	local[0] = cons(ctx,local[4],w);
	goto WHL53914;
WHX53915:
	local[4]= NIL;
BLK53916:
	w = NIL;
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)NREVERSE(ctx,1,local+2); /*nreverse*/
	local[0] = w;
	local[2]= (pointer)get_sym_func(fqv[36]);
	local[3]= loadglobal(fqv[8]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,3,local+2); /*apply*/
	local[0]= w;
BLK53807:
	ctx->vsp=local; return(local[0]);}

/*:namestring*/
static pointer M54006pathname_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	if (argv[0]->c.obj.iv[4]==NIL) goto IF54034;
	local[1]= loadglobal(fqv[8]);
	local[2]= fqv[38];
	local[3]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[1]= w;
	goto IF54035;
IF54034:
	local[1]= NIL;
IF54035:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF54047;
	local[2]= loadglobal(fqv[8]);
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	local[6]= argv[0]->c.obj.iv[3];
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)CONCATENATE(ctx,6,local+2); /*concatenate*/
	local[2]= w;
	goto IF54048;
IF54047:
	local[2]= loadglobal(fqv[8]);
	local[3]= argv[0]->c.obj.iv[0];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= local[0];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)CONCATENATE(ctx,5,local+2); /*concatenate*/
	local[2]= w;
IF54048:
	w = local[2];
	local[0]= w;
BLK54007:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M54070pathname_host(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54074;}
	local[0]= NIL;
ENT54074:
ENT54073:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54090;
	argv[0]->c.obj.iv[0] = local[0];
	local[1]= argv[0]->c.obj.iv[0];
	goto IF54091;
IF54090:
	local[1]= argv[0]->c.obj.iv[0];
IF54091:
	w = local[1];
	local[0]= w;
BLK54071:
	ctx->vsp=local; return(local[0]);}

/*:device*/
static pointer M54104pathname_device(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54108;}
	local[0]= NIL;
ENT54108:
ENT54107:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54124;
	argv[0]->c.obj.iv[1] = local[0];
	local[1]= argv[0]->c.obj.iv[1];
	goto IF54125;
IF54124:
	local[1]= argv[0]->c.obj.iv[1];
IF54125:
	w = local[1];
	local[0]= w;
BLK54105:
	ctx->vsp=local; return(local[0]);}

/*:directory*/
static pointer M54138pathname_directory(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54142;}
	local[0]= NIL;
ENT54142:
ENT54141:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54158;
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF54159;
IF54158:
	local[1]= argv[0]->c.obj.iv[2];
IF54159:
	w = local[1];
	local[0]= w;
BLK54139:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M54172pathname_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54176;}
	local[0]= NIL;
ENT54176:
ENT54175:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54192;
	argv[0]->c.obj.iv[3] = local[0];
	local[1]= argv[0]->c.obj.iv[3];
	goto IF54193;
IF54192:
	local[1]= argv[0]->c.obj.iv[3];
IF54193:
	w = local[1];
	local[0]= w;
BLK54173:
	ctx->vsp=local; return(local[0]);}

/*:type*/
static pointer M54206pathname_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54210;}
	local[0]= NIL;
ENT54210:
ENT54209:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54226;
	argv[0]->c.obj.iv[4] = local[0];
	local[1]= argv[0]->c.obj.iv[4];
	goto IF54227;
IF54226:
	local[1]= argv[0]->c.obj.iv[4];
IF54227:
	w = local[1];
	local[0]= w;
BLK54207:
	ctx->vsp=local; return(local[0]);}

/*:set-type*/
static pointer M54240pathname_set_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	argv[0]->c.obj.iv[4] = argv[2];
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK54241:
	ctx->vsp=local; return(local[0]);}

/*:version*/
static pointer M54263pathname_version(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54267;}
	local[0]= NIL;
ENT54267:
ENT54266:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF54283;
	argv[0]->c.obj.iv[5] = local[0];
	local[1]= argv[0]->c.obj.iv[5];
	goto IF54284;
IF54283:
	local[1]= argv[0]->c.obj.iv[5];
IF54284:
	w = local[1];
	local[0]= w;
BLK54264:
	ctx->vsp=local; return(local[0]);}

/*:merge*/
static pointer M54297pathname_merge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[0]!=NIL) goto IF54312;
	argv[0]->c.obj.iv[0] = *(ovafptr(argv[2],fqv[39]));
	local[0]= argv[0]->c.obj.iv[0];
	goto IF54313;
IF54312:
	local[0]= NIL;
IF54313:
	if (argv[0]->c.obj.iv[1]!=NIL) goto IF54326;
	argv[0]->c.obj.iv[1] = *(ovafptr(argv[2],fqv[40]));
	local[0]= argv[0]->c.obj.iv[1];
	goto IF54327;
IF54326:
	local[0]= NIL;
IF54327:
	if (argv[0]->c.obj.iv[2]!=NIL) goto IF54340;
	argv[0]->c.obj.iv[2] = *(ovafptr(argv[2],fqv[41]));
	local[0]= argv[0]->c.obj.iv[2];
	goto IF54341;
IF54340:
	local[0]= NIL;
IF54341:
	if (argv[0]->c.obj.iv[3]!=NIL) goto IF54354;
	argv[0]->c.obj.iv[3] = *(ovafptr(argv[2],fqv[42]));
	local[0]= argv[0]->c.obj.iv[3];
	goto IF54355;
IF54354:
	local[0]= NIL;
IF54355:
	if (argv[0]->c.obj.iv[4]!=NIL) goto IF54368;
	argv[0]->c.obj.iv[4] = *(ovafptr(argv[2],fqv[43]));
	local[0]= argv[0]->c.obj.iv[4];
	goto IF54369;
IF54368:
	local[0]= NIL;
IF54369:
	if (argv[0]->c.obj.iv[5]!=NIL) goto IF54382;
	argv[0]->c.obj.iv[5] = *(ovafptr(argv[2],fqv[44]));
	local[0]= argv[0]->c.obj.iv[5];
	goto IF54383;
IF54382:
	local[0]= NIL;
IF54383:
	w = argv[0];
	local[0]= w;
BLK54298:
	ctx->vsp=local; return(local[0]);}

/*:add-directory*/
static pointer M54399pathname_add_directory(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= (pointer)get_sym_func(fqv[8]);
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK54400:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M54429pathname_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT54433;}
	local[0]= T;
ENT54433:
ENT54432:
	if (n>3) maerror();
	local[1]= local[0];
	local[2]= fqv[45];
	local[3]= argv[0];
	local[4]= fqv[46];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[0]= w;
BLK54430:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M54458pathname_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[47], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY54475;
	local[0] = NIL;
KEY54475:
	if (n & (1<<1)) goto KEY54480;
	local[1] = NIL;
KEY54480:
	if (n & (1<<2)) goto KEY54485;
	local[2] = NIL;
KEY54485:
	if (n & (1<<3)) goto KEY54490;
	local[3] = NIL;
KEY54490:
	if (n & (1<<4)) goto KEY54495;
	local[4] = NIL;
KEY54495:
	if (n & (1<<5)) goto KEY54500;
	local[5] = NIL;
KEY54500:
	if (local[0]==NIL) goto IF54509;
	argv[0]->c.obj.iv[0] = local[0];
	local[6]= argv[0]->c.obj.iv[0];
	goto IF54510;
IF54509:
	local[6]= NIL;
IF54510:
	if (local[1]==NIL) goto IF54522;
	argv[0]->c.obj.iv[1] = local[1];
	local[6]= argv[0]->c.obj.iv[1];
	goto IF54523;
IF54522:
	local[6]= NIL;
IF54523:
	if (local[2]==NIL) goto IF54535;
	argv[0]->c.obj.iv[2] = local[2];
	local[6]= argv[0]->c.obj.iv[2];
	goto IF54536;
IF54535:
	local[6]= NIL;
IF54536:
	if (local[3]==NIL) goto IF54548;
	argv[0]->c.obj.iv[3] = local[3];
	local[6]= argv[0]->c.obj.iv[3];
	goto IF54549;
IF54548:
	local[6]= NIL;
IF54549:
	if (local[4]==NIL) goto IF54561;
	argv[0]->c.obj.iv[4] = local[4];
	local[6]= argv[0]->c.obj.iv[4];
	goto IF54562;
IF54561:
	local[6]= NIL;
IF54562:
	if (local[5]==NIL) goto IF54574;
	argv[0]->c.obj.iv[5] = local[5];
	local[6]= argv[0]->c.obj.iv[5];
	goto IF54575;
IF54574:
	local[6]= NIL;
IF54575:
	w = argv[0];
	local[0]= w;
BLK54459:
	ctx->vsp=local; return(local[0]);}

/*pathnamep*/
static pointer F51362pathnamep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[48]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	local[0]= w;
BLK54592:
	ctx->vsp=local; return(local[0]);}

/*pathname*/
static pointer F51365pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[48]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF54619;
	local[0]= argv[0];
	goto IF54620;
IF54619:
	if (argv[0]==NIL) goto IF54629;
	local[0]= loadglobal(fqv[48]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[49];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F51300string(ctx,1,local+3); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	goto IF54630;
IF54629:
	local[0]= loadglobal(fqv[48]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
IF54630:
IF54620:
	w = local[0];
	local[0]= w;
BLK54609:
	ctx->vsp=local; return(local[0]);}

/*namestring*/
static pointer F51368namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	w = argv[0];
	if (!issymbol(w)) goto CON54679;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51300string(ctx,1,local+0); /*string*/
	local[0]= w;
	goto CON54677;
CON54679:
	w = argv[0];
	if (!isstring(w)) goto CON54687;
	local[0]= argv[0];
	goto CON54677;
CON54687:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51362pathnamep(ctx,1,local+0); /*pathnamep*/
	if (w==NIL) goto CON54693;
	local[0]= argv[0];
	local[1]= fqv[46];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON54677;
CON54693:
	local[0]= fqv[50];
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,2,local+0); /*error*/
	local[0]= w;
	goto CON54677;
CON54705:
	local[0]= NIL;
CON54677:
	w = local[0];
	local[0]= w;
BLK54667:
	ctx->vsp=local; return(local[0]);}

/*pathname-directory*/
static pointer F51371pathname_directory(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51365pathname(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[41]));
	local[0]= w;
BLK54714:
	ctx->vsp=local; return(local[0]);}

/*pathname-name*/
static pointer F51374pathname_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51365pathname(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[42]));
	local[0]= w;
BLK54731:
	ctx->vsp=local; return(local[0]);}

/*pathname-type*/
static pointer F51377pathname_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51365pathname(ctx,1,local+0); /*pathname*/
	w = *(ovafptr(w,fqv[43]));
	local[0]= w;
BLK54748:
	ctx->vsp=local; return(local[0]);}

/*directory-namestring*/
static pointer F51380directory_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51365pathname(ctx,1,local+0); /*pathname*/
	local[0]= w;
	local[1]= fqv[37];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK54765:
	ctx->vsp=local; return(local[0]);}

/*make-pathname*/
static pointer F51383make_pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[51], &argv[0], n-0, local+0, 0);
	if (n & (1<<0)) goto KEY54797;
	local[0] = NIL;
KEY54797:
	if (n & (1<<1)) goto KEY54802;
	local[1] = NIL;
KEY54802:
	if (n & (1<<2)) goto KEY54807;
	local[2] = NIL;
KEY54807:
	if (n & (1<<3)) goto KEY54812;
	local[3] = NIL;
KEY54812:
	if (n & (1<<4)) goto KEY54817;
	local[4] = NIL;
KEY54817:
	if (n & (1<<5)) goto KEY54822;
	local[5] = NIL;
KEY54822:
	if (n & (1<<6)) goto KEY54827;
	local[6] = NIL;
KEY54827:
	local[7]= loadglobal(fqv[48]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[52];
	local[10]= fqv[53];
	local[11]= local[0];
	local[12]= fqv[54];
	local[13]= local[1];
	local[14]= fqv[55];
	local[15]= local[2];
	local[16]= fqv[56];
	local[17]= local[3];
	local[18]= fqv[57];
	local[19]= local[4];
	local[20]= fqv[58];
	local[21]= local[5];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,14,local+8); /*send*/
	w = local[7];
	local[7]= w;
	local[8]= fqv[59];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)F51365pathname(ctx,1,local+9); /*pathname*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[0]= w;
BLK54784:
	ctx->vsp=local; return(local[0]);}

/*parse-namestring*/
static pointer F51386parse_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51365pathname(ctx,1,local+0); /*pathname*/
	local[0]= w;
BLK54887:
	ctx->vsp=local; return(local[0]);}

/*null-string-p*/
static pointer F51390null_string_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[60];
	ctx->vsp=local+2;
	w=(pointer)EQUAL(ctx,2,local+0); /*equal*/
	local[0]= w;
BLK54904:
	ctx->vsp=local; return(local[0]);}

/*merge-pathnames*/
static pointer F51393merge_pathnames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT54922;}
	local[0]= loadglobal(fqv[61]);
ENT54922:
ENT54921:
	if (n>2) maerror();
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F51362pathnamep(ctx,1,local+1); /*pathnamep*/
	if (w==NIL) goto IF54940;
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)COPYOBJ(ctx,1,local+1); /*copy-object*/
	local[1]= w;
	goto IF54941;
IF54940:
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)F51365pathname(ctx,1,local+1); /*pathname*/
	local[1]= w;
IF54941:
	argv[0] = local[1];
	local[1]= argv[0];
	local[2]= fqv[59];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F51365pathname(ctx,1,local+3); /*pathname*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK54919:
	ctx->vsp=local; return(local[0]);}

/*concatenate-pathnames*/
static pointer F51396concatenate_pathnames(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST54969:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[36]);
	local[2]= loadglobal(fqv[8]);
	local[3]= (pointer)get_sym_func(fqv[62]);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,3,local+1); /*apply*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)F51365pathname(ctx,1,local+1); /*pathname*/
	local[0]= w;
BLK54967:
	ctx->vsp=local; return(local[0]);}

/*truename*/
static pointer F51399truename(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)F51365pathname(ctx,1,local+0); /*pathname*/
	argv[0] = w;
	ctx->vsp=local+0;
	w=(pointer)GETWD(ctx,0,local+0); /*unix:getwd*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= fqv[37];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= T;
	if (local[1]==NIL) goto IF55031;
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)CHDIR(ctx,1,local+3); /*unix:chdir*/
	local[2] = w;
	local[3]= local[2];
	goto IF55032;
IF55031:
	local[3]= NIL;
IF55032:
	local[3]= local[2];
	if (T!=local[3]) goto CON55048;
	ctx->vsp=local+3;
	w=(pointer)GETWD(ctx,0,local+3); /*unix:getwd*/
	local[2] = w;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	w = makeint((eusinteger_t)1L);
	if ((eusinteger_t)local[3] <= (eusinteger_t)w) goto IF55062;
	local[3]= loadglobal(fqv[8]);
	local[4]= local[2];
	local[5]= fqv[63];
	ctx->vsp=local+6;
	w=(pointer)CONCATENATE(ctx,3,local+3); /*concatenate*/
	local[2] = w;
	local[3]= local[2];
	goto IF55063;
IF55062:
	local[3]= NIL;
IF55063:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)CHDIR(ctx,1,local+3); /*unix:chdir*/
	local[3]= fqv[56];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F51374pathname_name(ctx,1,local+4); /*pathname-name*/
	local[4]= w;
	local[5]= fqv[57];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(pointer)F51377pathname_type(ctx,1,local+6); /*pathname-type*/
	local[6]= w;
	local[7]= fqv[55];
	local[8]= local[2];
	ctx->vsp=local+9;
	w=(pointer)F51371pathname_directory(ctx,1,local+8); /*pathname-directory*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)F51383make_pathname(ctx,6,local+3); /*make-pathname*/
	local[3]= w;
	goto CON55046;
CON55048:
	local[3]= fqv[64];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto CON55046;
CON55100:
	local[3]= NIL;
CON55046:
	w = local[3];
	local[0]= w;
BLK54993:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M55149url_pathname_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= fqv[65];
	local[2]= argv[1];
	local[3]= fqv[56];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)ADDRESS(ctx,1,local+3); /*system:address*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[66];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK55150:
	ctx->vsp=local; return(local[0]);}

/*:string*/
static pointer M55181url_pathname_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[67];
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)F51368namestring(ctx,1,local+5); /*namestring*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,6,local+0); /*format*/
	local[0]= w;
BLK55182:
	ctx->vsp=local; return(local[0]);}

/*:string2*/
static pointer M55203url_pathname_string2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= fqv[68];
	local[2]= argv[0]->c.obj.iv[6];
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F51368namestring(ctx,1,local+4); /*namestring*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)XFORMAT(ctx,5,local+0); /*format*/
	local[0]= w;
BLK55204:
	ctx->vsp=local; return(local[0]);}

/*:port*/
static pointer M55224url_pathname_port(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55228;}
	local[0]= NIL;
ENT55228:
ENT55227:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF55244;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF55245;
IF55244:
	local[1]= NIL;
IF55245:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK55225:
	ctx->vsp=local; return(local[0]);}

/*:server*/
static pointer M55260url_pathname_server(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55264;}
	local[0]= NIL;
ENT55264:
ENT55263:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF55280;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto IF55281;
IF55280:
	local[1]= NIL;
IF55281:
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK55261:
	ctx->vsp=local; return(local[0]);}

/*:connect*/
static pointer M55296url_pathname_connect(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55300;}
	local[0]= makeint((eusinteger_t)5L);
ENT55300:
ENT55299:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[7];
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[9])(ctx,3,local+1,&ftab[9],fqv[69]); /*connect-server*/
	local[0]= w;
BLK55297:
	ctx->vsp=local; return(local[0]);}

/*:host*/
static pointer M55323url_pathname_host(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55327;}
	local[0]= NIL;
ENT55327:
ENT55326:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF55343;
	argv[0]->c.obj.iv[7] = local[0];
	local[1]= argv[0]->c.obj.iv[7];
	goto IF55344;
IF55343:
	local[1]= NIL;
IF55344:
	w = argv[0]->c.obj.iv[7];
	local[0]= w;
BLK55324:
	ctx->vsp=local; return(local[0]);}

/*:protocol*/
static pointer M55359url_pathname_protocol(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT55363;}
	local[0]= NIL;
ENT55363:
ENT55362:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF55379;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF55380;
IF55379:
	local[1]= NIL;
IF55380:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK55360:
	ctx->vsp=local; return(local[0]);}

/*:parse-namestring*/
static pointer M55395url_pathname_parse_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= makeint((eusinteger_t)0L);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)58L);
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,2,local+3,&ftab[2],fqv[9]); /*position*/
	local[0] = w;
	if (local[0]==NIL) goto IF55426;
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[6] = w;
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[0] = w;
	local[3]= local[0];
	goto IF55427;
IF55426:
	argv[0]->c.obj.iv[6] = fqv[70];
	local[0] = makeint((eusinteger_t)0L);
	local[3]= local[0];
IF55427:
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)47L);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON55463;
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)AREF(ctx,2,local+3); /*aref*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)47L);
	ctx->vsp=local+5;
	w=(pointer)EQ(ctx,2,local+3); /*eql*/
	if (w==NIL) goto CON55463;
	local[3]= makeint((eusinteger_t)47L);
	local[4]= argv[2];
	local[5]= fqv[15];
	local[6]= makeint((eusinteger_t)3L);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)PLUS(ctx,2,local+6); /*+*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[9]); /*position*/
	local[2] = w;
	if (local[2]!=NIL) goto IF55503;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[2] = w;
	local[3]= local[2];
	goto IF55504;
IF55503:
	local[3]= NIL;
IF55504:
	local[3]= argv[2];
	local[4]= makeint((eusinteger_t)2L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)PLUS(ctx,2,local+4); /*+*/
	local[4]= w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[7] = w;
	local[3]= makeint((eusinteger_t)58L);
	local[4]= argv[0]->c.obj.iv[7];
	ctx->vsp=local+5;
	w=(*ftab[2])(ctx,2,local+3,&ftab[2],fqv[9]); /*position*/
	local[1] = w;
	if (local[1]==NIL) goto IF55537;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)ADD1(ctx,1,local+4); /*1+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SUBSEQ(ctx,2,local+3); /*subseq*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(*ftab[10])(ctx,1,local+3,&ftab[10],fqv[71]); /*read-from-string*/
	argv[0]->c.obj.iv[8] = w;
	local[3]= argv[0]->c.obj.iv[7];
	local[4]= makeint((eusinteger_t)0L);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SUBSEQ(ctx,3,local+3); /*subseq*/
	argv[0]->c.obj.iv[7] = w;
	local[3]= argv[0]->c.obj.iv[7];
	goto IF55538;
IF55537:
	argv[0]->c.obj.iv[8] = makeint((eusinteger_t)80L);
	local[3]= argv[0]->c.obj.iv[8];
IF55538:
	local[3]= argv[0];
	local[4]= *(ovafptr(argv[1],fqv[72]));
	local[5]= fqv[49];
	local[6]= argv[2];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)SENDMESSAGE(ctx,4,local+3); /*send-message*/
	local[3]= fqv[73];
	w=argv[0]->c.obj.iv[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
	ctx->vsp=local+5;
	w=(pointer)APPEND(ctx,2,local+3); /*append*/
	argv[0]->c.obj.iv[2] = w;
	local[3]= argv[0];
	goto CON55461;
CON55463:
	local[3]= fqv[74];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SIGERROR(ctx,2,local+3); /*error*/
	local[3]= w;
	goto CON55461;
CON55604:
	local[3]= NIL;
CON55461:
	w = local[3];
	local[0]= w;
BLK55396:
	ctx->vsp=local; return(local[0]);}

/*:percent-escape*/
static pointer M55613url_pathname_percent_escape(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[75], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY55626;
	local[0] = T;
KEY55626:
	if (n & (1<<1)) goto KEY55631;
	local[1] = NIL;
KEY55631:
	local[2]= argv[0];
	local[3]= fqv[49];
	if (local[1]==NIL) goto IF55644;
	local[4]= argv[0];
	local[5]= fqv[66];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F51428unescaped_url_string_from_namestring(ctx,2,local+4); /*unescaped-url-string-from-namestring*/
	local[4]= w;
	goto IF55645;
IF55644:
	local[4]= argv[0];
	local[5]= fqv[66];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F51424escaped_url_string_from_namestring(ctx,2,local+4); /*escaped-url-string-from-namestring*/
	local[4]= w;
IF55645:
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[0]= w;
BLK55614:
	ctx->vsp=local; return(local[0]);}

/*url-pathname*/
static pointer F51418url_pathname(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= loadglobal(fqv[76]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF55679;
	local[0]= argv[0];
	goto IF55680;
IF55679:
	if (argv[0]==NIL) goto IF55690;
	local[0]= loadglobal(fqv[76]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[49];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F51300string(ctx,1,local+3); /*string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
	goto IF55691;
IF55690:
	local[0]= loadglobal(fqv[76]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
IF55691:
IF55680:
	w = local[0];
	local[0]= w;
BLK55669:
	ctx->vsp=local; return(local[0]);}

/*parse-url*/
static pointer F51420parse_url(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= fqv[77];
	local[1]= NIL;
	local[2]= NIL;
	local[3]= makeint((eusinteger_t)80L);
	local[4]= makeint((eusinteger_t)0L);
	local[5]= NIL;
	local[6]= makeint((eusinteger_t)58L);
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,2,local+6,&ftab[2],fqv[9]); /*position*/
	local[4] = w;
	if (local[4]==NIL) goto IF55762;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[0] = w;
	local[6]= local[4];
	ctx->vsp=local+7;
	w=(pointer)ADD1(ctx,1,local+6); /*1+*/
	local[4] = w;
	local[6]= local[4];
	goto IF55763;
IF55762:
	local[4] = makeint((eusinteger_t)0L);
	local[6]= local[4];
IF55763:
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)47L);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto CON55797;
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)47L);
	ctx->vsp=local+8;
	w=(pointer)EQ(ctx,2,local+6); /*eql*/
	if (w==NIL) goto CON55797;
	local[6]= argv[0];
	local[7]= makeint((eusinteger_t)2L);
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= makeint((eusinteger_t)47L);
	local[9]= argv[0];
	local[10]= fqv[15];
	local[11]= makeint((eusinteger_t)3L);
	local[12]= local[4];
	ctx->vsp=local+13;
	w=(pointer)PLUS(ctx,2,local+11); /*+*/
	local[11]= w;
	ctx->vsp=local+12;
	w=(*ftab[2])(ctx,4,local+8,&ftab[2],fqv[9]); /*position*/
	local[4] = w;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[1] = w;
	local[6]= makeint((eusinteger_t)58L);
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[2])(ctx,2,local+6,&ftab[2],fqv[9]); /*position*/
	local[5] = w;
	if (local[5]==NIL) goto IF55850;
	local[6]= local[1];
	local[7]= local[5];
	ctx->vsp=local+8;
	w=(pointer)ADD1(ctx,1,local+7); /*1+*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(*ftab[10])(ctx,1,local+6,&ftab[10],fqv[71]); /*read-from-string*/
	local[3] = w;
	local[6]= local[1];
	local[7]= makeint((eusinteger_t)0L);
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)SUBSEQ(ctx,3,local+6); /*subseq*/
	local[1] = w;
	local[6]= local[1];
	goto IF55851;
IF55850:
	local[3] = makeint((eusinteger_t)80L);
	local[6]= local[3];
IF55851:
	local[6]= argv[0];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SUBSEQ(ctx,2,local+6); /*subseq*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)F51365pathname(ctx,1,local+6); /*pathname*/
	local[2] = w;
	local[6]= local[2];
	local[7]= fqv[55];
	local[8]= fqv[78];
	local[9]= local[2];
	local[10]= fqv[55];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	ctx->vsp=local+10;
	w=(pointer)APPEND(ctx,2,local+8); /*append*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,3,local+6); /*send*/
	local[6]= local[0];
	local[7]= local[1];
	local[8]= local[3];
	local[9]= local[2];
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,4,local+6); /*list*/
	local[6]= w;
	goto CON55795;
CON55797:
	local[6]= fqv[79];
	local[7]= argv[0];
	ctx->vsp=local+8;
	w=(pointer)SIGERROR(ctx,2,local+6); /*error*/
	local[6]= w;
	goto CON55795;
CON55924:
	local[6]= NIL;
CON55795:
	w = local[6];
	local[0]= w;
BLK55727:
	ctx->vsp=local; return(local[0]);}

/*escape-url*/
static pointer F51422escape_url(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT55939;}
	local[0]= loadglobal(fqv[80]);
ENT55939:
	if (n>=3) { local[1]=(argv[2]); goto ENT55938;}
	local[1]= T;
ENT55938:
ENT55937:
	if (n>3) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET55961,env,argv,local);
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,FLET55963,env,argv,local);
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= loadglobal(fqv[81]);
	ctx->vsp=local+7;
	w=(pointer)COERCE(ctx,2,local+5); /*coerce*/
	local[5]= w;
WHL55988:
	if (local[5]==NIL) goto WHX55989;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= local[4];
	w = local[2];
	ctx->vsp=local+7;
	w=FLET55961(ctx,1,local+6,w);
	if (w==NIL) goto CON56039;
	local[6]= local[4];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)WRTBYTE(ctx,2,local+6); /*write-byte*/
	local[6]= w;
	goto CON56037;
CON56039:
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)13L);
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[82]); /*char=*/
	if (w==NIL) goto CON56052;
	local[6]= makeint((eusinteger_t)10L);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)WRTBYTE(ctx,2,local+6); /*write-byte*/
	local[6]= w;
	goto CON56037;
CON56052:
	if (local[1]==NIL) goto CON56063;
	local[6]= local[4];
	local[7]= makeint((eusinteger_t)32L);
	ctx->vsp=local+8;
	w=(*ftab[11])(ctx,2,local+6,&ftab[11],fqv[82]); /*char=*/
	if (w==NIL) goto CON56063;
	local[6]= makeint((eusinteger_t)43L);
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)WRTBYTE(ctx,2,local+6); /*write-byte*/
	local[6]= w;
	goto CON56037;
CON56063:
	local[6]= local[0];
	local[7]= fqv[83];
	local[8]= NIL;
	local[9]= fqv[84];
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)XFORMAT(ctx,3,local+8); /*format*/
	local[8]= w;
	local[9]= makeint((eusinteger_t)2L);
	w = local[3];
	ctx->vsp=local+10;
	w=FLET55963(ctx,2,local+8,w);
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)XFORMAT(ctx,3,local+6); /*format*/
	local[6]= w;
	goto CON56037;
CON56077:
	local[6]= NIL;
CON56037:
	goto WHL55988;
WHX55989:
	local[6]= NIL;
BLK55990:
	w = NIL;
	local[0]= w;
BLK55935:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET55961(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= makeint((eusinteger_t)65L);
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)90L);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w!=NIL) goto OR56105;
	local[0]= makeint((eusinteger_t)97L);
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)122L);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w!=NIL) goto OR56105;
	local[0]= makeint((eusinteger_t)48L);
	local[1]= argv[0];
	local[2]= makeint((eusinteger_t)57L);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,3,local+0); /*<=*/
	local[0]= w;
	if (w!=NIL) goto OR56105;
	local[0]= argv[0];
	local[1]= loadglobal(fqv[85]);
	local[2]= fqv[2];
	local[3]= (pointer)get_sym_func(fqv[82]);
	ctx->vsp=local+4;
	w=(*ftab[12])(ctx,4,local+0,&ftab[12],fqv[86]); /*find*/
	local[0]= w;
OR56105:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET55963(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	w=(*ftab[13])(ctx,0,local+0,&ftab[13],fqv[87]); /*make-string-output-stream*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= argv[1];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)MINUS(ctx,2,local+2); /*-*/
	local[2]= w;
WHL56189:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX56190;
	local[3]= makeint((eusinteger_t)48L);
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)WRTBYTE(ctx,2,local+3); /*write-byte*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL56189;
WHX56190:
	local[3]= NIL;
BLK56191:
	w = NIL;
	local[1]= local[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,2,local+1); /*format*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[88]); /*get-output-stream-string*/
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,1,local+1,&ftab[14],fqv[88]); /*get-output-stream-string*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*escaped-url-string-from-namestring*/
static pointer F51424escaped_url_string_from_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT56232;}
	local[0]= T;
ENT56232:
ENT56231:
	if (n>2) maerror();
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,0,local+1,&ftab[13],fqv[87]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F51422escape_url(ctx,3,local+2); /*escape-url*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,1,local+2,&ftab[14],fqv[88]); /*get-output-stream-string*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,1,local+2,&ftab[14],fqv[88]); /*get-output-stream-string*/
	local[0]= w;
BLK56229:
	ctx->vsp=local; return(local[0]);}

/*unescape-url*/
static pointer F51426unescape_url(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT56278;}
	local[0]= loadglobal(fqv[80]);
ENT56278:
	if (n>=3) { local[1]=(argv[2]); goto ENT56277;}
	local[1]= T;
ENT56277:
ENT56276:
	if (n>3) maerror();
	local[2]= argv[0];
	local[3]= fqv[15];
	local[4]= fqv[89];
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,2,local+3,&ftab[15],fqv[90]); /*member*/
	if (w==NIL) goto IF56307;
	local[3]= fqv[15];
	local[4]= fqv[91];
	ctx->vsp=local+5;
	w=(*ftab[15])(ctx,2,local+3,&ftab[15],fqv[90]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	goto IF56308;
IF56307:
	local[3]= NIL;
IF56308:
	local[4]= fqv[16];
	local[5]= fqv[92];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,2,local+4,&ftab[15],fqv[90]); /*member*/
	if (w==NIL) goto IF56331;
	local[4]= fqv[16];
	local[5]= fqv[93];
	ctx->vsp=local+6;
	w=(*ftab[15])(ctx,2,local+4,&ftab[15],fqv[90]); /*member*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	goto IF56332;
IF56331:
	local[4]= NIL;
IF56332:
	ctx->vsp=local+5;
	w=(*ftab[16])(ctx,3,local+2,&ftab[16],fqv[94]); /*make-string-input-stream*/
	local[2]= w;
WHL56359:
	local[3]= local[2];
	local[4]= NIL;
	ctx->vsp=local+5;
	w=(pointer)PEEKCH(ctx,2,local+3); /*peek-char*/
	if (w==NIL) goto WHX56360;
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)PEEKCH(ctx,1,local+3); /*peek-char*/
	local[3]= w;
	local[4]= local[3];
	if (fqv[95]!=local[4]) goto IF56384;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= makeint((eusinteger_t)35L);
	local[5]= makeint((eusinteger_t)120L);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)READCH(ctx,1,local+6); /*read-char*/
	local[6]= w;
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)READCH(ctx,1,local+7); /*read-char*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)LIST(ctx,4,local+4); /*list*/
	local[4]= w;
	local[5]= loadglobal(fqv[8]);
	ctx->vsp=local+6;
	w=(pointer)COERCE(ctx,2,local+4); /*coerce*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,1,local+4,&ftab[10],fqv[71]); /*read-from-string*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto IF56385;
IF56384:
	local[4]= local[3];
	if (fqv[96]!=local[4]) goto IF56415;
	if (local[1]==NIL) goto IF56423;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= makeint((eusinteger_t)32L);
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto IF56424;
IF56423:
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
IF56424:
	goto IF56416;
IF56415:
	if (T==NIL) goto IF56445;
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)READCH(ctx,1,local+4); /*read-char*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)WRTBYTE(ctx,2,local+4); /*write-byte*/
	local[4]= w;
	goto IF56446;
IF56445:
	local[4]= NIL;
IF56446:
IF56416:
IF56385:
	w = local[4];
	goto WHL56359;
WHX56360:
	local[3]= NIL;
BLK56361:
	w = local[3];
	local[0]= w;
BLK56274:
	ctx->vsp=local; return(local[0]);}

/*unescaped-url-string-from-namestring*/
static pointer F51428unescaped_url_string_from_namestring(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<1) maerror();
	if (n>=2) { local[0]=(argv[1]); goto ENT56462;}
	local[0]= T;
ENT56462:
ENT56461:
	if (n>2) maerror();
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,0,local+1,&ftab[13],fqv[87]); /*make-string-output-stream*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= local[1];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F51426unescape_url(ctx,3,local+2); /*unescape-url*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,1,local+2,&ftab[14],fqv[88]); /*get-output-stream-string*/
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,1,local+2,&ftab[14],fqv[88]); /*get-output-stream-string*/
	local[0]= w;
BLK56459:
	ctx->vsp=local; return(local[0]);}

/*digits-string*/
static pointer F51430digits_string(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT56507;}
	local[0]= makeint((eusinteger_t)10L);
ENT56507:
ENT56506:
	if (n>3) maerror();
	local[1]= argv[1];
	local[2]= makeint((eusinteger_t)1L);
	ctx->vsp=local+3;
	w=(pointer)LSEQP(ctx,2,local+1); /*<=*/
	if (w==NIL) goto IF56523;
	local[1]= NIL;
	local[2]= fqv[97];
	local[3]= argv[0];
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[4]= w;
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)XFORMAT(ctx,3,local+1); /*format*/
	local[1]= w;
	goto IF56524;
IF56523:
	local[1]= loadglobal(fqv[8]);
	local[2]= argv[0];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)QUOTIENT(ctx,2,local+2); /*/*/
	local[2]= w;
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SUB1(ctx,1,local+3); /*1-*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)F51430digits_string(ctx,2,local+2); /*digits-string*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= makeint((eusinteger_t)1L);
	ctx->vsp=local+5;
	w=(pointer)F51430digits_string(ctx,2,local+3); /*digits-string*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)CONCATENATE(ctx,3,local+1); /*concatenate*/
	local[1]= w;
IF56524:
	w = local[1];
	local[0]= w;
BLK56504:
	ctx->vsp=local; return(local[0]);}

/*timed-file-name*/
static pointer F51432timed_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT56564;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT56564:
ENT56563:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= fqv[98];
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)F51430digits_string(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)1L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= makeint((eusinteger_t)2L);
	ctx->vsp=local+7;
	w=(pointer)F51430digits_string(ctx,2,local+5); /*digits-string*/
	local[5]= w;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)0L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)F51430digits_string(ctx,2,local+6); /*digits-string*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	local[0]= w;
BLK56561:
	ctx->vsp=local; return(local[0]);}

/*dated-file-name*/
static pointer F51434dated_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT56605;}
	ctx->vsp=local+0;
	w=(pointer)LOCALTIME(ctx,0,local+0); /*unix:localtime*/
	local[0]= w;
ENT56605:
ENT56604:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= fqv[99];
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= makeint((eusinteger_t)5L);
	ctx->vsp=local+6;
	w=(pointer)AREF(ctx,2,local+4); /*aref*/
	local[4]= w;
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)F51430digits_string(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= local[0];
	local[6]= makeint((eusinteger_t)4L);
	ctx->vsp=local+7;
	w=(pointer)AREF(ctx,2,local+5); /*aref*/
	local[5]= w;
	local[6]= fqv[100];
	ctx->vsp=local+7;
	w=(*ftab[0])(ctx,2,local+5,&ftab[0],fqv[4]); /*assoc*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	local[6]= local[0];
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,2,local+6); /*aref*/
	local[6]= w;
	local[7]= makeint((eusinteger_t)2L);
	ctx->vsp=local+8;
	w=(pointer)F51430digits_string(ctx,2,local+6); /*digits-string*/
	local[6]= w;
	local[7]= argv[1];
	ctx->vsp=local+8;
	w=(pointer)XFORMAT(ctx,7,local+1); /*format*/
	local[0]= w;
BLK56602:
	ctx->vsp=local; return(local[0]);}

/*sequential-file-name*/
static pointer F51436sequential_file_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT56654;}
	local[0]= makeint((eusinteger_t)4L);
ENT56654:
ENT56653:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= fqv[101];
	local[3]= argv[0];
	local[4]= argv[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)F51430digits_string(ctx,2,local+4); /*digits-string*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)XFORMAT(ctx,5,local+1); /*format*/
	local[0]= w;
BLK56651:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___string(ctx,n,argv,env)
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
	local[0]= fqv[102];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= fqv[103];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF56689;
	local[0]= fqv[104];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[105],w);
	goto IF56690;
IF56689:
	local[0]= fqv[106];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF56690:
	local[0]= fqv[107];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[108],module,F51293read_sharp_backslash,fqv[109]);
	local[0]= makeint((eusinteger_t)35L);
	local[1]= makeint((eusinteger_t)92L);
	local[2]= fqv[108];
	ctx->vsp=local+3;
	w=(pointer)SETDISPMACRO(ctx,3,local+0); /*set-dispatch-macro-character*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[110],module,F51297true_string,fqv[111]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[8],module,F51300string,fqv[112]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[113],module,F51303make_string,fqv[114]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[115],module,F51306string_left_trim,fqv[116]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[117],module,F51309string_right_trim,fqv[118]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[119],module,F51312string_trim,fqv[120]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[121],module,F51315nstring_downcase,fqv[122]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[123],module,F51318nstring_upcase,fqv[124]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[125],module,F51321string_upcase,fqv[126]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[127],module,F51324string_downcase,fqv[128]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[129],module,F51327string_,fqv[130]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[3],module,F51330string_equal,fqv[131]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[132],module,F51333substringp,fqv[133]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[134],module,F51336string_match_at,fqv[135]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[136],module,F51339string_match,fqv[137]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[138],module,F51342nth_position,fqv[139]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[140],module,F51345bm_string_match,fqv[141]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[142],module,F51348string_replace,fqv[143]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53005string_get,fqv[144],fqv[8],fqv[145]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53028string_set,fqv[146],fqv[8],fqv[147]);
	local[0]= fqv[48];
	local[1]= fqv[148];
	local[2]= fqv[48];
	local[3]= fqv[149];
	local[4]= loadglobal(fqv[150]);
	local[5]= fqv[151];
	local[6]= fqv[152];
	local[7]= fqv[153];
	local[8]= NIL;
	local[9]= fqv[154];
	local[10]= NIL;
	local[11]= fqv[155];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[156];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[157]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[158];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[159],module,F51358explode_directory_names,fqv[160]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53402pathname_parse_namestring,fqv[49],fqv[48],fqv[161]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M53806pathname_directory_string,fqv[37],fqv[48],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54006pathname_namestring,fqv[46],fqv[48],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54070pathname_host,fqv[53],fqv[48],fqv[164]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54104pathname_device,fqv[54],fqv[48],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54138pathname_directory,fqv[55],fqv[48],fqv[166]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54172pathname_name,fqv[56],fqv[48],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54206pathname_type,fqv[57],fqv[48],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54240pathname_set_type,fqv[169],fqv[48],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54263pathname_version,fqv[58],fqv[48],fqv[171]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54297pathname_merge,fqv[59],fqv[48],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54399pathname_add_directory,fqv[173],fqv[48],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54429pathname_prin1,fqv[175],fqv[48],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M54458pathname_init,fqv[52],fqv[48],fqv[177]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[178],module,F51362pathnamep,fqv[179]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[48],module,F51365pathname,fqv[180]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[62],module,F51368namestring,fqv[181]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[182],module,F51371pathname_directory,fqv[183]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[184],module,F51374pathname_name,fqv[185]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[186],module,F51377pathname_type,fqv[187]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[188],module,F51380directory_namestring,fqv[189]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[190],module,F51383make_pathname,fqv[191]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[192],module,F51386parse_namestring,fqv[193]);
	local[0]= fqv[61];
	local[1]= fqv[148];
	local[2]= fqv[194];
	local[3]= fqv[195];
	local[4]= fqv[196];
	local[5]= fqv[197];
	ctx->vsp=local+6;
	w=(pointer)LIST(ctx,4,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[198],module,F51390null_string_p,fqv[199]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[200],module,F51393merge_pathnames,fqv[201]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[202],module,F51396concatenate_pathnames,fqv[203]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[204],module,F51399truename,fqv[205]);
	local[0]= fqv[76];
	local[1]= fqv[148];
	local[2]= fqv[76];
	local[3]= fqv[149];
	local[4]= loadglobal(fqv[48]);
	local[5]= fqv[151];
	local[6]= fqv[206];
	local[7]= fqv[153];
	local[8]= NIL;
	local[9]= fqv[154];
	local[10]= NIL;
	local[11]= fqv[155];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[156];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[157]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55149url_pathname_prin1,fqv[175],fqv[76],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55181url_pathname_string,fqv[66],fqv[76],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55203url_pathname_string2,fqv[209],fqv[76],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55224url_pathname_port,fqv[211],fqv[76],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55260url_pathname_server,fqv[213],fqv[76],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55296url_pathname_connect,fqv[215],fqv[76],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55323url_pathname_host,fqv[53],fqv[76],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55359url_pathname_protocol,fqv[218],fqv[76],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55395url_pathname_parse_namestring,fqv[49],fqv[76],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M55613url_pathname_percent_escape,fqv[221],fqv[76],fqv[222]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[76],module,F51418url_pathname,fqv[223]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[224],module,F51420parse_url,fqv[225]);
	local[0]= fqv[85];
	local[1]= fqv[226];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF56913;
	local[0]= fqv[85];
	local[1]= fqv[226];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[85];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF56936;
	local[0]= fqv[85];
	local[1]= fqv[148];
	local[2]= fqv[227];
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF56937;
IF56936:
	local[0]= NIL;
IF56937:
	local[0]= fqv[85];
	goto IF56914;
IF56913:
	local[0]= NIL;
IF56914:
	ctx->vsp=local+0;
	compfun(ctx,fqv[228],module,F51422escape_url,fqv[229]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[230],module,F51424escaped_url_string_from_namestring,fqv[231]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[232],module,F51426unescape_url,fqv[233]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[234],module,F51428unescaped_url_string_from_namestring,fqv[235]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[236],module,F51430digits_string,fqv[237]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[238],module,F51432timed_file_name,fqv[239]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[240],module,F51434dated_file_name,fqv[241]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[242],module,F51436sequential_file_name,fqv[243]);
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<18; i++) ftab[i]=fcallx;
}
