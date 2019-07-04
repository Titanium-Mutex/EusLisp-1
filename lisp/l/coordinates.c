/* ./coordinates.c :  entry=coordinates */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "coordinates.h"
#pragma init (register_coordinates)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___coordinates();
extern pointer build_quote_vector();
static int register_coordinates()
  { add_module_initializer("___coordinates", ___coordinates);}

static pointer F81327coordinates_p();
static pointer F81347transform_coords();
static pointer F81349transform_coords_();
static pointer F81351transform_vector();
static pointer F81353make_coords();
static pointer F81355make_cascoords();
static pointer F81357coords();
static pointer F81359cascoords();
static pointer F81361wrt();
static pointer F81366coordinates_distance();

/*coordinates-p*/
static pointer F81327coordinates_p(ctx,n,argv,env)
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
BLK81414:
	ctx->vsp=local; return(local[0]);}

/*:dimension*/
static pointer M81440coordinates_dimension(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
BLK81441:
	ctx->vsp=local; return(local[0]);}

/*:rot*/
static pointer M81457coordinates_rot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK81458:
	ctx->vsp=local; return(local[0]);}

/*:pos*/
static pointer M81473coordinates_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK81474:
	ctx->vsp=local; return(local[0]);}

/*:x-axis*/
static pointer M81489coordinates_x_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK81490:
	ctx->vsp=local; return(local[0]);}

/*:y-axis*/
static pointer M81507coordinates_y_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK81508:
	ctx->vsp=local; return(local[0]);}

/*:z-axis*/
static pointer M81524coordinates_z_axis(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)2L);
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[1]); /*matrix-row*/
	local[0]= w;
BLK81525:
	ctx->vsp=local; return(local[0]);}

/*:name*/
static pointer M81541coordinates_name(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT81545;}
	local[0]= NIL;
ENT81545:
ENT81544:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF81561;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[2];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF81562;
IF81561:
	local[1]= NIL;
IF81562:
	local[1]= argv[0];
	local[2]= fqv[2];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[0]= w;
BLK81542:
	ctx->vsp=local; return(local[0]);}

/*:newcoords*/
static pointer M81581coordinates_newcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81585;}
	local[0]= NIL;
ENT81585:
ENT81584:
	if (n>4) maerror();
	if (local[0]==NIL) goto IF81603;
	argv[0]->c.obj.iv[1] = argv[2];
	argv[0]->c.obj.iv[2] = local[0];
	local[1]= argv[0]->c.obj.iv[2];
	goto IF81604;
IF81603:
	argv[0]->c.obj.iv[1] = argv[2]->c.obj.iv[1];
	argv[0]->c.obj.iv[2] = argv[2]->c.obj.iv[2];
	local[1]= argv[0]->c.obj.iv[2];
IF81604:
	w = argv[0];
	local[0]= w;
BLK81582:
	ctx->vsp=local; return(local[0]);}

/*:replace-rot*/
static pointer M81639coordinates_replace_rot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[3]); /*replace-matrix*/
	local[0]= w;
BLK81640:
	ctx->vsp=local; return(local[0]);}

/*:replace-pos*/
static pointer M81660coordinates_replace_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[2])(ctx,2,local+0,&ftab[2],fqv[4]); /*replace*/
	local[0]= w;
BLK81661:
	ctx->vsp=local; return(local[0]);}

/*:replace-coords*/
static pointer M81681coordinates_replace_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT81685;}
	local[0]= NIL;
ENT81685:
ENT81684:
	if (n>4) maerror();
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)F81327coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto IF81704;
	local[0] = argv[2]->c.obj.iv[2];
	argv[2] = argv[2]->c.obj.iv[1];
	local[1]= argv[2];
	goto IF81705;
IF81704:
	local[1]= NIL;
IF81705:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	w = argv[0];
	local[0]= w;
BLK81682:
	ctx->vsp=local; return(local[0]);}

/*:copy-rot*/
static pointer M81746coordinates_copy_rot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(*ftab[3])(ctx,1,local+0,&ftab[3],fqv[5]); /*copy-matrix*/
	local[0]= w;
BLK81747:
	ctx->vsp=local; return(local[0]);}

/*:copy-pos*/
static pointer M81764coordinates_copy_pos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+1;
	w=(pointer)COPYSEQ(ctx,1,local+0); /*copy-seq*/
	local[0]= w;
BLK81765:
	ctx->vsp=local; return(local[0]);}

/*:copy-coords*/
static pointer M81781coordinates_copy_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT81785;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT81785:
ENT81784:
	if (n>3) maerror();
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK81782:
	ctx->vsp=local; return(local[0]);}

/*:coords*/
static pointer M81849coordinates_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT81853;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT81853:
ENT81852:
	if (n>3) maerror();
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK81850:
	ctx->vsp=local; return(local[0]);}

/*:worldrot*/
static pointer M81917coordinates_worldrot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[1];
	local[0]= w;
BLK81918:
	ctx->vsp=local; return(local[0]);}

/*:worldpos*/
static pointer M81933coordinates_worldpos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[2];
	local[0]= w;
BLK81934:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M81949coordinates_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0];
	local[0]= w;
BLK81950:
	ctx->vsp=local; return(local[0]);}

/*:copy-worldcoords*/
static pointer M81965coordinates_copy_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[7];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
BLK81966:
	ctx->vsp=local; return(local[0]);}

/*:parentcoords*/
static pointer M81984coordinates_parentcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = loadglobal(fqv[8]);
	local[0]= w;
BLK81985:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M82001coordinates_changed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK82002:
	ctx->vsp=local; return(local[0]);}

/*:reset-coords*/
static pointer M82016coordinates_reset_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= makeint((eusinteger_t)0L);
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[9]); /*array-dimension*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[10]); /*unit-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[11]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	argv[0]->c.obj.iv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK82017:
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M82070coordinates_move_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT82074;}
	local[0]= fqv[13];
ENT82074:
ENT82073:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F81327coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w!=NIL) goto IF82099;
	local[3]= fqv[14];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF82100;
IF82099:
	local[3]= NIL;
IF82100:
	local[3]= local[0];
	w = fqv[15];
	if (memq(local[3],w)!=NIL) goto OR82116;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR82116;
	goto CON82115;
OR82116:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON82113;
CON82115:
	local[3]= local[0];
	w = fqv[17];
	if (memq(local[3],w)!=NIL) goto OR82148;
	local[3]= local[0];
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR82148;
	goto CON82147;
OR82148:
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON82113;
CON82147:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F81327coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto CON82172;
	local[3]= local[0];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F81347transform_coords(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON82113;
CON82172:
	local[3]= NIL;
CON82113:
	w = local[3];
	local[0]= w;
BLK82071:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M82215coordinates_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
BLK82216:
	ctx->vsp=local; return(local[0]);}

/*:transform-vector*/
static pointer M82235coordinates_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK82236:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M82258coordinates_inverse_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)TRANSPOSE(ctx,1,local+0); /*transpose*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)TRANSFORM(ctx,2,local+1); /*transform*/
	local[1]= w;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,2,local+2); /*transform*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[0]= w;
BLK82259:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transformation*/
static pointer M82298coordinates_inverse_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT82302;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT82302:
ENT82301:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= local[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)TRANSPOSE(ctx,2,local+1); /*transpose*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,3,local+1); /*transform*/
	local[1]= makeflt(-1.0000000000000000000000e+00);
	local[2]= local[0]->c.obj.iv[2];
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SCALEVEC(ctx,3,local+1); /*scale*/
	w = local[0];
	local[0]= w;
BLK82299:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M82384coordinates_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT82388;}
	local[0]= fqv[13];
ENT82388:
ENT82387:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	argv[2] = w;
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= local[0];
	w = fqv[21];
	if (memq(local[4],w)!=NIL) goto OR82444;
	local[4]= local[0];
	if (argv[0]==local[4]) goto OR82444;
	goto CON82443;
OR82444:
	local[4]= local[2];
	local[5]= argv[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F81347transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON82441;
CON82443:
	local[4]= local[0];
	w = fqv[22];
	if (memq(local[4],w)!=NIL) goto OR82465;
	local[4]= local[0];
	if (loadglobal(fqv[8])==local[4]) goto OR82465;
	goto CON82464;
OR82465:
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F81347transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON82441;
CON82464:
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)F81327coordinates_p(ctx,1,local+4); /*coordinates-p*/
	if (w==NIL) goto CON82486;
	local[4]= local[0];
	local[5]= fqv[18];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[3] = w;
	local[4]= argv[2];
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F81347transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= local[3];
	local[5]= fqv[20];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[2];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F81347transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= local[2];
	local[5]= local[3];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)F81347transform_coords(ctx,3,local+4); /*transform-coords*/
	local[4]= w;
	goto CON82441;
CON82486:
	local[4]= argv[0];
	local[5]= fqv[23];
	local[6]= fqv[24];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	goto CON82441;
CON82525:
	local[4]= NIL;
CON82441:
	w = local[2];
	local[0]= w;
BLK82385:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M82540coordinates_transform(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT82544;}
	local[0]= fqv[13];
ENT82544:
ENT82543:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[25];
	if (memq(local[1],w)!=NIL) goto OR82567;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR82567;
	goto CON82566;
OR82567:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F81347transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON82564;
CON82566:
	local[1]= local[0];
	w = fqv[26];
	if (memq(local[1],w)!=NIL) goto OR82588;
	local[1]= local[0];
	if (loadglobal(fqv[8])==local[1]) goto OR82588;
	goto CON82587;
OR82588:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F81347transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON82564;
CON82587:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F81327coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON82609;
	local[1]= local[0];
	local[2]= fqv[20];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F81347transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F81347transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= local[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F81347transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON82564;
CON82609:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[27];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON82564;
CON82641:
	local[1]= NIL;
CON82564:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK82541:
	ctx->vsp=local; return(local[0]);}

/*:rotate-with-matrix*/
static pointer M82660coordinates_rotate_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[28];
	if (memq(local[0],w)!=NIL) goto OR82680;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82680;
	goto CON82679;
OR82680:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON82677;
CON82679:
	local[0]= argv[3];
	w = fqv[29];
	if (memq(local[0],w)!=NIL) goto OR82701;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR82701;
	goto CON82700;
OR82701:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON82677;
CON82700:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F81327coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON82722;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)TRANSPOSE(ctx,1,local+1); /*transpose*/
	local[1]= w;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[1];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[0]= w;
	goto CON82677;
CON82722:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[31];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON82677;
CON82767:
	local[0]= NIL;
CON82677:
	w = local[0];
	local[0]= w;
BLK82661:
	ctx->vsp=local; return(local[0]);}

/*:rotate*/
static pointer M82777coordinates_rotate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT82782;}
	local[0]= NIL;
ENT82782:
	if (n>=5) { local[1]=(argv[4]); goto ENT82781;}
	local[1]= fqv[13];
ENT82781:
ENT82780:
	if (n>5) maerror();
	local[2]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	if (makeint((eusinteger_t)2L)!=local[2]) goto CON82808;
	w = argv[2];
	if (!isnum(w)) goto CON82818;
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON82816;
CON82818:
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(*ftab[6])(ctx,1,local+2,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON82828;
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,3,local+2); /*m**/
	local[2]= w;
	goto CON82816;
CON82828:
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)SIGERROR(ctx,1,local+2); /*error*/
	local[2]= w;
	goto CON82816;
CON82841:
	local[2]= NIL;
CON82816:
	goto CON82806;
CON82808:
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,1,local+2,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON82846;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+4); /*rotation-matrix*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON82806;
CON82846:
	if (local[0]!=NIL) goto CON82864;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON82806;
CON82864:
	local[2]= local[1];
	w = fqv[36];
	if (memq(local[2],w)!=NIL) goto OR82883;
	local[2]= local[1];
	if (argv[0]==local[2]) goto OR82883;
	goto CON82882;
OR82883:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON82880;
CON82882:
	local[2]= local[1];
	w = fqv[37];
	if (memq(local[2],w)!=NIL) goto OR82905;
	local[2]= local[1];
	if (loadglobal(fqv[8])==local[2]) goto OR82905;
	goto CON82904;
OR82905:
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[2];
	local[4]= local[0];
	local[5]= T;
	local[6]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+7;
	w=(pointer)ROTMAT(ctx,5,local+2); /*rotate-matrix*/
	local[2]= w;
	goto CON82880;
CON82904:
	local[2]= local[1];
	ctx->vsp=local+3;
	w=(pointer)F81327coordinates_p(ctx,1,local+2); /*coordinates-p*/
	if (w==NIL) goto CON82927;
	local[2]= argv[0];
	local[3]= fqv[35];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+4); /*rotation-matrix*/
	local[4]= w;
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON82880;
CON82927:
	local[2]= argv[0];
	local[3]= fqv[23];
	local[4]= fqv[38];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[2]= w;
	goto CON82880;
CON82944:
	local[2]= NIL;
CON82880:
	goto CON82806;
CON82876:
	local[2]= NIL;
CON82806:
	local[2]= argv[0];
	local[3]= fqv[16];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	local[0]= w;
BLK82778:
	ctx->vsp=local; return(local[0]);}

/*:orient-with-matrix*/
static pointer M82963coordinates_orient_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[39];
	if (memq(local[0],w)!=NIL) goto OR82983;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR82983;
	goto CON82982;
OR82983:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= w;
	goto CON82980;
CON82982:
	local[0]= argv[3];
	w = fqv[40];
	if (memq(local[0],w)!=NIL) goto OR83004;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR83004;
	goto CON83003;
OR83004:
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[0]->c.obj.iv[1];
	goto CON82980;
CON83003:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F81327coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON83027;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	local[2]= argv[2];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,3,local+1); /*m**/
	local[0]= w;
	goto CON82980;
CON83027:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[41];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON82980;
CON83053:
	local[0]= NIL;
CON82980:
	w = local[0];
	local[0]= w;
BLK82964:
	ctx->vsp=local; return(local[0]);}

/*:orient*/
static pointer M83063coordinates_orient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT83067;}
	local[0]= fqv[13];
ENT83067:
ENT83066:
	if (n>5) maerror();
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON83091;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON83089;
CON83091:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON83108;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON83089;
CON83108:
	local[1]= local[0];
	w = fqv[43];
	if (memq(local[1],w)!=NIL) goto OR83129;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR83129;
	goto CON83128;
OR83129:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= w;
	goto CON83126;
CON83128:
	local[1]= local[0];
	w = fqv[44];
	if (memq(local[1],w)!=NIL) goto OR83151;
	local[1]= local[0];
	if (loadglobal(fqv[8])==local[1]) goto OR83151;
	goto CON83150;
OR83151:
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+1); /*rotation-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0]->c.obj.iv[1];
	goto CON83126;
CON83150:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F81327coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON83177;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON83126;
CON83177:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[45];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON83126;
CON83194:
	local[1]= NIL;
CON83126:
	goto CON83089;
CON83122:
	local[1]= NIL;
CON83089:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK83064:
	ctx->vsp=local; return(local[0]);}

/*:parent-vector*/
static pointer M83213coordinates_parent_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[46];
	if (memq(local[0],w)!=NIL) goto OR83233;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR83233;
	goto CON83232;
OR83233:
	local[0]= argv[0];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON83230;
CON83232:
	local[0]= argv[3];
	w = fqv[48];
	if (memq(local[0],w)!=NIL) goto OR83255;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR83255;
	goto CON83254;
OR83255:
	local[0]= argv[2];
	goto CON83230;
CON83254:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F81327coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON83272;
	local[0]= argv[3];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto CON83230;
CON83272:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[49];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON83230;
CON83285:
	local[0]= NIL;
CON83230:
	w = local[0];
	local[0]= w;
BLK83214:
	ctx->vsp=local; return(local[0]);}

/*:parent-orientation*/
static pointer M83296coordinates_parent_orientation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[50];
	if (memq(local[0],w)!=NIL) goto OR83316;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR83316;
	goto CON83315;
OR83316:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON83313;
CON83315:
	local[0]= argv[3];
	w = fqv[51];
	if (memq(local[0],w)!=NIL) goto OR83336;
	local[0]= argv[3];
	if (loadglobal(fqv[8])==local[0]) goto OR83336;
	goto CON83335;
OR83336:
	local[0]= argv[2];
	goto CON83313;
CON83335:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F81327coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto CON83353;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON83313;
CON83353:
	local[0]= argv[0];
	local[1]= fqv[23];
	local[2]= fqv[52];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON83313;
CON83368:
	local[0]= NIL;
CON83313:
	w = local[0];
	local[0]= w;
BLK83297:
	ctx->vsp=local; return(local[0]);}

/*:translate*/
static pointer M83379coordinates_translate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT83383;}
	local[0]= fqv[13];
ENT83383:
ENT83382:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0];
	local[5]= fqv[53];
	local[6]= argv[2];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	local[4]= w;
	local[5]= argv[0]->c.obj.iv[2];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK83380:
	ctx->vsp=local; return(local[0]);}

/*:locate*/
static pointer M83421coordinates_locate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT83425;}
	local[0]= fqv[13];
ENT83425:
ENT83424:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	local[5]= argv[0];
	local[6]= fqv[54];
	local[7]= argv[2];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,4,local+5); /*send*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[2])(ctx,2,local+4,&ftab[2],fqv[4]); /*replace*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK83422:
	ctx->vsp=local; return(local[0]);}

/*:scale*/
static pointer M83462coordinates_scale(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT83466;}
	local[0]= NIL;
ENT83466:
ENT83465:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF83482;
	local[1]= local[0];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(*ftab[8])(ctx,3,local+1,&ftab[8],fqv[55]); /*scale-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	goto IF83483;
IF83482:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(*ftab[0])(ctx,2,local+1,&ftab[0],fqv[1]); /*matrix-row*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VNORM(ctx,1,local+1); /*norm*/
	local[1]= w;
IF83483:
	w = local[1];
	local[0]= w;
BLK83463:
	ctx->vsp=local; return(local[0]);}

/*:euler*/
static pointer M83510coordinates_euler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(*ftab[9])(ctx,3,local+2,&ftab[9],fqv[56]); /*euler-matrix*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK83511:
	ctx->vsp=local; return(local[0]);}

/*:euler-angle*/
static pointer M83542coordinates_euler_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)INV_EULER(ctx,1,local+0); /*euler-angle*/
	local[0]= w;
BLK83543:
	ctx->vsp=local; return(local[0]);}

/*:rpy*/
static pointer M83559coordinates_rpy(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=5) maerror();
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= argv[4];
	ctx->vsp=local+5;
	w=(*ftab[10])(ctx,3,local+2,&ftab[10],fqv[57]); /*rpy-matrix*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
BLK83560:
	ctx->vsp=local; return(local[0]);}

/*:rpy-angle*/
static pointer M83591coordinates_rpy_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)INV_RPY(ctx,1,local+0); /*rpy-angle*/
	local[0]= w;
BLK83592:
	ctx->vsp=local; return(local[0]);}

/*:rotation-angle*/
static pointer M83608coordinates_rotation_angle(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+1;
	w=(pointer)ROTANGLE(ctx,1,local+0); /*rotation-angle*/
	local[0]= w;
BLK83609:
	ctx->vsp=local; return(local[0]);}

/*:4x4*/
static pointer M83625coordinates_4x4(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT83629;}
	local[0]= NIL;
ENT83629:
ENT83628:
	if (n>3) maerror();
	if (local[0]==NIL) goto CON83647;
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)3L);
WHL83675:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX83676;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)3L);
WHL83706:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX83707;
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[0];
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL83706;
WHX83707:
	local[5]= NIL;
BLK83708:
	w = NIL;
	local[3]= argv[0]->c.obj.iv[2];
	local[4]= local[1];
	local[5]= local[0];
	local[6]= local[1];
	local[7]= makeint((eusinteger_t)3L);
	ctx->vsp=local+8;
	w=(pointer)AREF(ctx,3,local+5); /*aref*/
	{ register eusinteger_t i; register pointer v;
	  i=intval(local[4]); v=local[3];
	  v->c.fvec.fv[i]=fltval(w);}
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL83675;
WHX83676:
	local[3]= NIL;
BLK83677:
	w = NIL;
	local[1]= argv[0];
	goto CON83645;
CON83647:
	local[1]= makeint((eusinteger_t)4L);
	local[2]= makeint((eusinteger_t)4L);
	ctx->vsp=local+3;
	w=(*ftab[11])(ctx,2,local+1,&ftab[11],fqv[58]); /*make-matrix*/
	local[0] = w;
	local[1]= local[0];
	local[2]= makeint((eusinteger_t)3L);
	local[3]= makeint((eusinteger_t)3L);
	local[4]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)ASET(ctx,4,local+1); /*aset*/
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)3L);
WHL83802:
	local[3]= local[1];
	w = local[2];
	if ((eusinteger_t)local[3] >= (eusinteger_t)w) goto WHX83803;
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)3L);
WHL83833:
	local[5]= local[3];
	w = local[4];
	if ((eusinteger_t)local[5] >= (eusinteger_t)w) goto WHX83834;
	local[5]= local[0];
	local[6]= local[1];
	local[7]= local[3];
	local[8]= argv[0]->c.obj.iv[1];
	local[9]= local[1];
	local[10]= local[3];
	ctx->vsp=local+11;
	w=(pointer)AREF(ctx,3,local+8); /*aref*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)ASET(ctx,4,local+5); /*aset*/
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)ADD1(ctx,1,local+5); /*1+*/
	local[3] = w;
	goto WHL83833;
WHX83834:
	local[5]= NIL;
BLK83835:
	w = NIL;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= makeint((eusinteger_t)3L);
	local[6]= argv[0]->c.obj.iv[2];
	{ register eusinteger_t i=intval(local[1]);
	  w=makeflt(local[6]->c.fvec.fv[i]);}
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)ASET(ctx,4,local+3); /*aset*/
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)ADD1(ctx,1,local+3); /*1+*/
	local[1] = w;
	goto WHL83802;
WHX83803:
	local[3]= NIL;
BLK83804:
	w = NIL;
	local[1]= local[0];
	goto CON83645;
CON83762:
	local[1]= NIL;
CON83645:
	w = local[1];
	local[0]= w;
BLK83626:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M83892coordinates_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT83896;}
	local[0]= T;
ENT83896:
ENT83895:
	ctx->vsp=local+1;
	local[1]= minilist(ctx,&argv[n],n-3);
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[0];
	local[5]= fqv[59];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	w = makeint((eusinteger_t)2L);
	if ((eusinteger_t)local[5] <= (eusinteger_t)w) goto CON83931;
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(pointer)INV_RPY(ctx,1,local+5); /*rpy-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[62];
	if (local[1]==NIL) goto IF83961;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF83962;
IF83961:
	local[11]= fqv[63];
IF83962:
	local[12]= local[4];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[4];
	local[14]= makeint((eusinteger_t)1L);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= local[4];
	local[15]= makeint((eusinteger_t)2L);
	ctx->vsp=local+16;
	w=(pointer)AREF(ctx,2,local+14); /*aref*/
	local[14]= w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)XFORMAT(ctx,9,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON83929;
CON83931:
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	if (makeint((eusinteger_t)2L)!=local[5]) goto CON84003;
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= NIL;
	local[10]= fqv[64];
	if (local[1]==NIL) goto IF84020;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.car;
	goto IF84021;
IF84020:
	local[11]= fqv[65];
IF84021:
	local[12]= local[4];
	local[13]= makeint((eusinteger_t)0L);
	ctx->vsp=local+14;
	w=(pointer)AREF(ctx,2,local+12); /*aref*/
	local[12]= w;
	local[13]= local[4];
	local[14]= makeint((eusinteger_t)1L);
	ctx->vsp=local+15;
	w=(pointer)AREF(ctx,2,local+13); /*aref*/
	local[13]= w;
	local[14]= local[3];
	ctx->vsp=local+15;
	w=(pointer)ROTANGLE(ctx,1,local+14); /*rotation-angle*/
	local[14]= w;
	ctx->vsp=local+15;
	w=(pointer)XFORMAT(ctx,6,local+9); /*format*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON83929;
CON84003:
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[60]));
	local[7]= fqv[61];
	local[8]= local[0];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)SENDMESSAGE(ctx,5,local+5); /*send-message*/
	local[5]= w;
	goto CON83929;
CON84041:
	local[5]= NIL;
CON83929:
	w = local[5];
	local[0]= w;
BLK83893:
	ctx->vsp=local; return(local[0]);}

/*:create*/
static pointer M84056coordinates_create(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT84060;}
	local[0]= makeint((eusinteger_t)3L);
ENT84060:
ENT84059:
	if (n>3) maerror();
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(*ftab[5])(ctx,1,local+1,&ftab[5],fqv[10]); /*unit-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= loadglobal(fqv[11]);
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,2,local+1); /*instantiate*/
	argv[0]->c.obj.iv[2] = w;
	w = argv[0];
	local[0]= w;
BLK84057:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M84094coordinates_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[66], &argv[2], n-2, local+0, 1);
	if (n & (1<<0)) goto KEY84118;
	local[0] = makeint((eusinteger_t)3L);
KEY84118:
	if (n & (1<<1)) goto KEY84123;
	local[13]= loadglobal(fqv[11]);
	local[14]= local[0];
	ctx->vsp=local+15;
	w=(pointer)INSTANTIATE(ctx,2,local+13); /*instantiate*/
	local[1] = w;
KEY84123:
	if (n & (1<<2)) goto KEY84132;
	local[13]= local[0];
	ctx->vsp=local+14;
	w=(*ftab[5])(ctx,1,local+13,&ftab[5],fqv[10]); /*unit-matrix*/
	local[2] = w;
KEY84132:
	if (n & (1<<3)) goto KEY84140;
	local[3] = NIL;
KEY84140:
	if (n & (1<<4)) goto KEY84145;
	local[4] = NIL;
KEY84145:
	if (n & (1<<5)) goto KEY84150;
	local[5] = NIL;
KEY84150:
	if (n & (1<<6)) goto KEY84155;
	local[6] = NIL;
KEY84155:
	if (n & (1<<7)) goto KEY84160;
	local[7] = NIL;
KEY84160:
	if (n & (1<<8)) goto KEY84165;
	local[8] = local[7];
KEY84165:
	if (n & (1<<9)) goto KEY84171;
	local[9] = NIL;
KEY84171:
	if (n & (1<<10)) goto KEY84176;
	local[10] = fqv[13];
KEY84176:
	if (n & (1<<11)) goto KEY84183;
	local[11] = NIL;
KEY84183:
	if (n & (1<<12)) goto KEY84188;
	local[12] = NIL;
KEY84188:
	argv[0]->c.obj.iv[1] = local[2];
	local[13]= local[10];
	ctx->vsp=local+14;
	w=(pointer)F81327coordinates_p(ctx,1,local+13); /*coordinates-p*/
	if (w==NIL) goto IF84206;
	local[13]= local[10];
	local[14]= fqv[47];
	local[15]= local[1];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto IF84207;
IF84206:
	local[13]= local[1];
IF84207:
	argv[0]->c.obj.iv[2] = local[13];
	if (local[3]==NIL) goto CON84226;
	local[13]= argv[0];
	local[14]= fqv[67];
	local[15]= local[3];
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[3];
	local[17]= makeint((eusinteger_t)1L);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[3];
	local[18]= makeint((eusinteger_t)2L);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON84224;
CON84226:
	if (local[4]==NIL) goto CON84245;
	local[13]= argv[0];
	local[14]= fqv[68];
	local[15]= local[4];
	local[16]= makeint((eusinteger_t)0L);
	ctx->vsp=local+17;
	w=(pointer)ELT(ctx,2,local+15); /*elt*/
	local[15]= w;
	local[16]= local[4];
	local[17]= makeint((eusinteger_t)1L);
	ctx->vsp=local+18;
	w=(pointer)ELT(ctx,2,local+16); /*elt*/
	local[16]= w;
	local[17]= local[4];
	local[18]= makeint((eusinteger_t)2L);
	ctx->vsp=local+19;
	w=(pointer)ELT(ctx,2,local+17); /*elt*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON84224;
CON84245:
	if (local[8]==NIL) goto CON84264;
	local[13]= argv[0];
	local[14]= fqv[69];
	local[15]= local[8];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto CON84224;
CON84264:
	w = local[6];
	if (!iscons(w)) goto CON84275;
	local[13]= NIL;
	local[14]= local[6];
WHL84298:
	if (local[14]==NIL) goto WHX84299;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	local[16]= fqv[70];
	local[17]= local[13];
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[18]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[18];
	local[18]= w;
	local[19]= local[10];
	ctx->vsp=local+20;
	w=(pointer)SEND(ctx,5,local+15); /*send*/
	goto WHL84298;
WHX84299:
	local[15]= NIL;
BLK84300:
	w = NIL;
	local[13]= w;
	goto CON84224;
CON84275:
	w = local[6];
	if (!isnum(w)) goto CON84391;
	local[13]= argv[0];
	local[14]= fqv[70];
	local[15]= local[6];
	local[16]= local[5];
	local[17]= local[10];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,5,local+13); /*send*/
	local[13]= w;
	goto CON84224;
CON84391:
	if (local[9]==NIL) goto CON84404;
	local[13]= argv[0];
	local[14]= fqv[71];
	local[15]= local[9];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto CON84224;
CON84404:
	local[13]= NIL;
CON84224:
	if (local[11]==NIL) goto IF84417;
	local[13]= argv[0];
	local[14]= fqv[2];
	local[15]= local[11];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,3,local+13); /*send*/
	local[13]= w;
	goto IF84418;
IF84417:
	local[13]= NIL;
IF84418:
	local[13]= NIL;
	local[14]= local[12];
WHL84447:
	if (local[14]==NIL) goto WHX84448;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.car;
	w=local[14];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14] = (w)->c.cons.cdr;
	w = local[15];
	local[13] = w;
	local[15]= argv[0];
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[17]= (w)->c.cons.car;
	ctx->vsp=local+18;
	w=(pointer)PUTPROP(ctx,3,local+15); /*putprop*/
	goto WHL84447;
WHX84448:
	local[15]= NIL;
BLK84449:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK84095:
	ctx->vsp=local; return(local[0]);}

/*:parent*/
static pointer M84560cascaded_coords_parent(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK84561:
	ctx->vsp=local; return(local[0]);}

/*:descendants*/
static pointer M84576cascaded_coords_descendants(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[4];
	local[0]= w;
BLK84577:
	ctx->vsp=local; return(local[0]);}

/*:inheritance*/
static pointer M84592cascaded_coords_inheritance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO84606,env,argv,local);
	local[1]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	w=(pointer)MAPCAR(ctx,2,local+0); /*mapcar*/
	local[0]= w;
BLK84593:
	ctx->vsp=local; return(local[0]);}

/*:leaves*/
static pointer M84612cascaded_coords_leaves(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[4]==NIL) goto IF84625;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[72];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[73]); /*send-all*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(*ftab[13])(ctx,1,local+0,&ftab[13],fqv[74]); /*flatten*/
	local[0]= w;
	goto IF84626;
IF84625:
	local[0]= argv[0];
IF84626:
	w = local[0];
	local[0]= w;
BLK84613:
	ctx->vsp=local; return(local[0]);}

/*:assoc*/
static pointer M84642cascaded_coords_assoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT84646;}
	local[0]= NIL;
ENT84646:
ENT84645:
	if (n>4) maerror();
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	if (memq(local[1],w)!=NIL) goto IF84665;
	if (local[0]!=NIL) goto IF84679;
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[75];
	local[3]= argv[2];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0] = w;
	local[1]= local[0];
	goto IF84680;
IF84679:
	local[1]= NIL;
IF84680:
	local[1]= argv[2];
	local[2]= fqv[76];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[16];
	local[3]= local[0]->c.obj.iv[1];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= argv[2];
	w = argv[0]->c.obj.iv[4];
	ctx->vsp=local+2;
	argv[0]->c.obj.iv[4] = cons(ctx,local[1],w);
	local[1]= argv[2];
	goto IF84666;
IF84665:
	local[1]= NIL;
IF84666:
	w = local[1];
	local[0]= w;
BLK84643:
	ctx->vsp=local; return(local[0]);}

/*:dissoc*/
static pointer M84745cascaded_coords_dissoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	w = argv[0]->c.obj.iv[4];
	if (memq(local[0],w)==NIL) goto IF84761;
	local[0]= argv[2];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[77];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[4];
	ctx->vsp=local+3;
	w=(*ftab[14])(ctx,2,local+1,&ftab[14],fqv[78]); /*delete*/
	argv[0]->c.obj.iv[4] = w;
	local[1]= argv[2];
	local[2]= fqv[79];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= argv[2];
	local[2]= fqv[16];
	local[3]= local[0]->c.obj.iv[1];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = argv[2];
	local[0]= w;
	goto IF84762;
IF84761:
	local[0]= NIL;
IF84762:
	w = local[0];
	local[0]= w;
BLK84746:
	ctx->vsp=local; return(local[0]);}

/*:clear-assoc*/
static pointer M84831cascaded_coords_clear_assoc(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL84861:
	if (local[1]==NIL) goto WHX84862;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[80];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL84861;
WHX84862:
	local[2]= NIL;
BLK84863:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK84832:
	ctx->vsp=local; return(local[0]);}

/*:obey*/
static pointer M84922cascaded_coords_obey(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF84937;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[80];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF84938;
IF84937:
	local[0]= NIL;
IF84938:
	argv[0]->c.obj.iv[3] = argv[2];
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK84923:
	ctx->vsp=local; return(local[0]);}

/*:disobey*/
static pointer M84959cascaded_coords_disobey(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	if (argv[0]->c.obj.iv[3]!=local[0]) goto IF84974;
	argv[0]->c.obj.iv[3] = NIL;
	local[0]= argv[0]->c.obj.iv[3];
	goto IF84975;
IF84974:
	local[0]= NIL;
IF84975:
	w = argv[0]->c.obj.iv[3];
	local[0]= w;
BLK84960:
	ctx->vsp=local; return(local[0]);}

/*:newcoords*/
static pointer M84990cascaded_coords_newcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT84994;}
	local[0]= NIL;
ENT84994:
ENT84993:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[60]));
	local[3]= fqv[16];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= argv[0];
	local[2]= fqv[12];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK84991:
	ctx->vsp=local; return(local[0]);}

/*:changed*/
static pointer M85032cascaded_coords_changed(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]!=NIL) goto IF85046;
	argv[0]->c.obj.iv[7] = T;
	local[0]= argv[0]->c.obj.iv[4];
	local[1]= fqv[12];
	ctx->vsp=local+2;
	w=(*ftab[12])(ctx,2,local+0,&ftab[12],fqv[73]); /*send-all*/
	local[0]= w;
	goto IF85047;
IF85046:
	local[0]= NIL;
IF85047:
	w = local[0];
	local[0]= w;
BLK85033:
	ctx->vsp=local; return(local[0]);}

/*:worldrot*/
static pointer M85068cascaded_coords_worldrot(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = w->c.obj.iv[1];
	local[0]= w;
BLK85069:
	ctx->vsp=local; return(local[0]);}

/*:worldpos*/
static pointer M85092cascaded_coords_worldpos(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = w->c.obj.iv[2];
	local[0]= w;
BLK85093:
	ctx->vsp=local; return(local[0]);}

/*:worldcoords*/
static pointer M85116cascaded_coords_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[7]==NIL) goto IF85130;
	if (argv[0]->c.obj.iv[3]==NIL) goto IF85139;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0];
	local[2]= argv[0]->c.obj.iv[5];
	ctx->vsp=local+3;
	w=(pointer)F81347transform_coords(ctx,3,local+0); /*transform-coords*/
	local[0]= w;
	goto IF85140;
IF85139:
	local[0]= argv[0]->c.obj.iv[5];
	local[1]= fqv[69];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
IF85140:
	local[0]= argv[0];
	local[1]= fqv[81];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[0]->c.obj.iv[7] = NIL;
	local[0]= argv[0]->c.obj.iv[7];
	goto IF85131;
IF85130:
	local[0]= NIL;
IF85131:
	w = argv[0]->c.obj.iv[5];
	local[0]= w;
BLK85117:
	ctx->vsp=local; return(local[0]);}

/*:copy-worldcoords*/
static pointer M85177cascaded_coords_copy_worldcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT85181;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT85181:
ENT85180:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= local[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
	ctx->vsp=local+3;
	w=(*ftab[2])(ctx,2,local+1,&ftab[2],fqv[4]); /*replace*/
	local[1]= local[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[3]); /*replace-matrix*/
	w = local[0];
	local[0]= w;
BLK85178:
	ctx->vsp=local; return(local[0]);}

/*:update*/
static pointer M85259cascaded_coords_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = NIL;
	local[0]= w;
BLK85260:
	ctx->vsp=local; return(local[0]);}

/*:parentcoords*/
static pointer M85273cascaded_coords_parentcoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (argv[0]->c.obj.iv[3]==NIL) goto IF85286;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto IF85287;
IF85286:
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= local[0];
	if (fqv[83]!=local[1]) goto IF85314;
	local[1]= loadglobal(fqv[8]);
	goto IF85315;
IF85314:
	local[1]= local[0];
	if (fqv[84]!=local[1]) goto IF85324;
	local[1]= loadglobal(fqv[85]);
	goto IF85325;
IF85324:
	if (T==NIL) goto IF85334;
	local[1]= fqv[86];
	ctx->vsp=local+2;
	w=(pointer)SIGERROR(ctx,1,local+1); /*error*/
	local[1]= w;
	goto IF85335;
IF85334:
	local[1]= NIL;
IF85335:
IF85325:
IF85315:
	w = local[1];
	local[0]= w;
IF85287:
	w = local[0];
	local[0]= w;
BLK85274:
	ctx->vsp=local; return(local[0]);}

/*:transform-vector*/
static pointer M85343cascaded_coords_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK85344:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vector*/
static pointer M85369cascaded_coords_rotate_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[87];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK85370:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transform-vector*/
static pointer M85395cascaded_coords_inverse_transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[18];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[88];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK85396:
	ctx->vsp=local; return(local[0]);}

/*:inverse-transformation*/
static pointer M85421cascaded_coords_inverse_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT85425;}
	local[0]= loadglobal(fqv[0]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = local[0];
	local[0]= w;
ENT85425:
ENT85424:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= fqv[20];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK85422:
	ctx->vsp=local; return(local[0]);}

/*:transformation*/
static pointer M85476cascaded_coords_transformation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT85480;}
	local[0]= fqv[13];
ENT85480:
ENT85479:
	if (n>4) maerror();
	local[1]= argv[2];
	local[2]= fqv[18];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= local[0];
	w = fqv[89];
	if (memq(local[6],w)!=NIL) goto OR85534;
	local[6]= local[0];
	if (argv[0]==local[6]) goto OR85534;
	goto CON85533;
OR85534:
	local[6]= local[3];
	local[7]= local[1];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON85531;
CON85533:
	local[6]= local[0];
	w = fqv[90];
	if (memq(local[6],w)!=NIL) goto OR85555;
	local[6]= local[0];
	if (argv[0]->c.obj.iv[3]==local[6]) goto OR85555;
	goto CON85554;
OR85555:
	local[6]= argv[0];
	local[7]= *(ovafptr(argv[1],fqv[60]));
	local[8]= fqv[20];
	ctx->vsp=local+9;
	w=(pointer)SENDMESSAGE(ctx,3,local+6); /*send-message*/
	local[4] = w;
	local[6]= local[1];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[3];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= argv[0];
	local[7]= local[4];
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON85531;
CON85554:
	local[6]= local[0];
	w = fqv[91];
	if (memq(local[6],w)!=NIL) goto OR85602;
	local[6]= local[0];
	local[7]= loadglobal(fqv[8]);
	ctx->vsp=local+8;
	w=(pointer)EQUAL(ctx,2,local+6); /*equal*/
	if (w!=NIL) goto OR85602;
	goto CON85601;
OR85602:
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON85531;
CON85601:
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)F81327coordinates_p(ctx,1,local+6); /*coordinates-p*/
	if (w==NIL) goto CON85625;
	local[6]= local[0];
	local[7]= fqv[18];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[5] = w;
	local[6]= local[3];
	local[7]= local[5];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[1];
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= local[5];
	local[7]= fqv[20];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,2,local+6); /*send*/
	local[6]= w;
	local[7]= local[3];
	local[8]= local[3];
	ctx->vsp=local+9;
	w=(pointer)F81347transform_coords(ctx,3,local+6); /*transform-coords*/
	local[6]= w;
	goto CON85531;
CON85625:
	local[6]= argv[0];
	local[7]= fqv[23];
	local[8]= fqv[92];
	local[9]= local[0];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,4,local+6); /*send*/
	local[6]= w;
	goto CON85531;
CON85664:
	local[6]= NIL;
CON85531:
	w = local[6];
	local[0]= w;
BLK85477:
	ctx->vsp=local; return(local[0]);}

/*:transform*/
static pointer M85676cascaded_coords_transform(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT85680;}
	local[0]= fqv[13];
ENT85680:
ENT85679:
	if (n>4) maerror();
	local[1]= local[0];
	w = fqv[93];
	if (memq(local[1],w)!=NIL) goto OR85703;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR85703;
	goto CON85702;
OR85703:
	local[1]= argv[0];
	local[2]= argv[2];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F81347transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON85700;
CON85702:
	local[1]= local[0];
	w = fqv[94];
	if (memq(local[1],w)!=NIL) goto OR85724;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR85724;
	goto CON85723;
OR85724:
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)F81347transform_coords(ctx,3,local+1); /*transform-coords*/
	local[1]= w;
	goto CON85700;
CON85723:
	local[1]= local[0];
	w = fqv[95];
	if (memq(local[1],w)!=NIL) goto OR85745;
	local[1]= local[0];
	local[2]= loadglobal(fqv[8]);
	ctx->vsp=local+3;
	w=(pointer)EQUAL(ctx,2,local+1); /*equal*/
	if (w!=NIL) goto OR85745;
	goto CON85744;
OR85745:
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON85700;
CON85744:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)F81327coordinates_p(ctx,1,local+1); /*coordinates-p*/
	if (w==NIL) goto CON85800;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[0];
	local[3]= fqv[18];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[2]= local[1];
	local[3]= fqv[20];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,3,local+2); /*transform-coords*/
	local[1]= w;
	goto CON85700;
CON85800:
	local[1]= argv[0];
	local[2]= fqv[23];
	local[3]= fqv[96];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON85700;
CON85864:
	local[1]= NIL;
CON85700:
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK85677:
	ctx->vsp=local; return(local[0]);}

/*:move-to*/
static pointer M85883cascaded_coords_move_to(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT85887;}
	local[0]= fqv[13];
ENT85887:
ENT85886:
	if (n>4) maerror();
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)F81327coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w!=NIL) goto IF85912;
	local[3]= fqv[97];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,1,local+3); /*error*/
	local[3]= w;
	goto IF85913;
IF85912:
	local[3]= NIL;
IF85913:
	local[3]= local[0];
	w = fqv[98];
	if (memq(local[3],w)!=NIL) goto OR85929;
	local[3]= local[0];
	if (argv[0]==local[3]) goto OR85929;
	goto CON85928;
OR85929:
	local[3]= argv[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85926;
CON85928:
	local[3]= local[0];
	w = fqv[99];
	if (memq(local[3],w)!=NIL) goto OR85961;
	local[3]= local[0];
	if (argv[0]->c.obj.iv[3]==local[3]) goto OR85961;
	goto CON85960;
OR85961:
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85926;
CON85960:
	local[3]= local[0];
	w = fqv[100];
	if (memq(local[3],w)!=NIL) goto OR85983;
	local[3]= local[0];
	local[4]= loadglobal(fqv[8]);
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w!=NIL) goto OR85983;
	goto CON85982;
OR85983:
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85926;
CON85982:
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)F81327coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto CON86025;
	local[3]= local[0];
	local[4]= fqv[18];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[19];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= fqv[20];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[2];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)F81347transform_coords(ctx,3,local+3); /*transform-coords*/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto CON85926;
CON86025:
	local[3]= NIL;
CON85926:
	w = local[3];
	local[0]= w;
BLK85884:
	ctx->vsp=local; return(local[0]);}

/*:rotate-with-matrix*/
static pointer M86068cascaded_coords_rotate_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[101];
	if (memq(local[0],w)!=NIL) goto OR86088;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR86088;
	goto CON86087;
OR86088:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON86085;
CON86087:
	local[0]= argv[3];
	w = fqv[102];
	if (memq(local[0],w)!=NIL) goto OR86117;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR86117;
	goto CON86116;
OR86117:
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON86085;
CON86116:
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[1];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F81327coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto IF86172;
	local[3]= argv[3];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	argv[2] = w;
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)TRANSPOSE(ctx,1,local+4); /*transpose*/
	local[4]= w;
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= w;
	goto IF86173;
IF86172:
	local[3]= NIL;
IF86173:
	local[3]= argv[2];
	local[4]= local[2];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[2];
	local[4]= argv[0]->c.obj.iv[1];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[0]= w;
	goto CON86085;
CON86145:
	local[0]= NIL;
CON86085:
	w = local[0];
	local[0]= w;
BLK86069:
	ctx->vsp=local; return(local[0]);}

/*:rotate*/
static pointer M86241cascaded_coords_rotate(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT86245;}
	local[0]= fqv[13];
ENT86245:
ENT86244:
	if (n>5) maerror();
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	if (makeint((eusinteger_t)2L)!=local[1]) goto CON86269;
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[60]));
	local[3]= fqv[70];
	local[4]= argv[2];
	local[5]= argv[3];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= w;
	goto CON86267;
CON86269:
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON86286;
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86267;
CON86286:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON86303;
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86267;
CON86303:
	local[1]= local[0];
	w = fqv[103];
	if (memq(local[1],w)!=NIL) goto OR86324;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR86324;
	goto CON86323;
OR86324:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86321;
CON86323:
	local[1]= local[0];
	w = fqv[104];
	if (memq(local[1],w)!=NIL) goto OR86354;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR86354;
	goto CON86353;
OR86354:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= T;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86321;
CON86353:
	local[1]= argv[0];
	local[2]= fqv[35];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86321;
CON86383:
	local[1]= NIL;
CON86321:
	goto CON86267;
CON86317:
	local[1]= NIL;
CON86267:
	w = local[1];
	local[0]= w;
BLK86242:
	ctx->vsp=local; return(local[0]);}

/*:orient-with-matrix*/
static pointer M86398cascaded_coords_orient_with_matrix(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[105];
	if (memq(local[0],w)!=NIL) goto OR86418;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR86418;
	goto CON86417;
OR86418:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	local[2]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+3;
	w=(pointer)MATTIMES(ctx,3,local+0); /*m**/
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON86415;
CON86417:
	local[0]= argv[3];
	w = fqv[106];
	if (memq(local[0],w)!=NIL) goto OR86447;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR86447;
	goto CON86446;
OR86447:
	argv[0]->c.obj.iv[1] = argv[2];
	local[0]= argv[0];
	local[1]= fqv[16];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto CON86415;
CON86446:
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[19];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
	local[2]= local[1]->c.obj.iv[1];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)F81327coordinates_p(ctx,1,local+3); /*coordinates-p*/
	if (w==NIL) goto IF86504;
	local[3]= argv[3];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[0] = w;
	local[3]= local[0];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)MATTIMES(ctx,2,local+3); /*m**/
	argv[2] = w;
	local[3]= argv[2];
	goto IF86505;
IF86504:
	local[3]= NIL;
IF86505:
	local[3]= local[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSPOSE(ctx,1,local+3); /*transpose*/
	local[3]= w;
	local[4]= argv[2];
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)MATTIMES(ctx,3,local+3); /*m**/
	local[3]= argv[0];
	local[4]= fqv[16];
	local[5]= argv[0]->c.obj.iv[1];
	local[6]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[0]= w;
	goto CON86415;
CON86477:
	local[0]= NIL;
CON86415:
	w = local[0];
	local[0]= w;
BLK86399:
	ctx->vsp=local; return(local[0]);}

/*:orient*/
static pointer M86555cascaded_coords_orient(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<4) maerror();
	if (n>=5) { local[0]=(argv[4]); goto ENT86559;}
	local[0]= fqv[13];
ENT86559:
ENT86558:
	if (n>5) maerror();
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[7])(ctx,1,local+1,&ftab[7],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto CON86583;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86581;
CON86583:
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[32]); /*matrixp*/
	if (w==NIL) goto CON86600;
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86581;
CON86600:
	local[1]= local[0];
	w = fqv[107];
	if (memq(local[1],w)!=NIL) goto OR86621;
	local[1]= local[0];
	if (argv[0]==local[1]) goto OR86621;
	goto CON86620;
OR86621:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[2];
	local[3]= argv[3];
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+6;
	w=(pointer)ROTMAT(ctx,5,local+1); /*rotate-matrix*/
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86618;
CON86620:
	local[1]= local[0];
	w = fqv[108];
	if (memq(local[1],w)!=NIL) goto OR86651;
	local[1]= local[0];
	if (argv[0]->c.obj.iv[3]==local[1]) goto OR86651;
	goto CON86650;
OR86651:
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+1); /*rotation-matrix*/
	argv[0]->c.obj.iv[1] = w;
	local[1]= argv[0];
	local[2]= fqv[16];
	local[3]= argv[0]->c.obj.iv[1];
	local[4]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86618;
CON86650:
	local[1]= argv[0];
	local[2]= fqv[42];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)ROTATION_MATRIX(ctx,2,local+3); /*rotation-matrix*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[1]= w;
	goto CON86618;
CON86684:
	local[1]= NIL;
CON86618:
	goto CON86581;
CON86614:
	local[1]= NIL;
CON86581:
	w = local[1];
	local[0]= w;
BLK86556:
	ctx->vsp=local; return(local[0]);}

/*:parent-vector*/
static pointer M86699cascaded_coords_parent_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[109];
	if (memq(local[0],w)!=NIL) goto OR86719;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR86719;
	goto CON86718;
OR86719:
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[60]));
	local[2]= fqv[47];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= w;
	goto CON86716;
CON86718:
	local[0]= argv[3];
	w = fqv[110];
	if (memq(local[0],w)!=NIL) goto OR86744;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR86744;
	goto CON86743;
OR86744:
	local[0]= argv[2];
	goto CON86716;
CON86743:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F81327coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto IF86764;
	local[0]= argv[3];
	local[1]= fqv[47];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF86765;
IF86764:
	local[0]= NIL;
IF86765:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF86784;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[88];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	goto IF86785;
IF86784:
	local[0]= argv[2];
IF86785:
	goto CON86716;
CON86760:
	local[0]= NIL;
CON86716:
	w = local[0];
	local[0]= w;
BLK86700:
	ctx->vsp=local; return(local[0]);}

/*:parent-orientation*/
static pointer M86798cascaded_coords_parent_orientation(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[3];
	w = fqv[111];
	if (memq(local[0],w)!=NIL) goto OR86818;
	local[0]= argv[3];
	if (argv[0]==local[0]) goto OR86818;
	goto CON86817;
OR86818:
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto CON86815;
CON86817:
	local[0]= argv[3];
	w = fqv[112];
	if (memq(local[0],w)!=NIL) goto OR86838;
	local[0]= argv[3];
	if (argv[0]->c.obj.iv[3]==local[0]) goto OR86838;
	goto CON86837;
OR86838:
	local[0]= argv[2];
	goto CON86815;
CON86837:
	local[0]= argv[3];
	ctx->vsp=local+1;
	w=(pointer)F81327coordinates_p(ctx,1,local+0); /*coordinates-p*/
	if (w==NIL) goto IF86858;
	local[0]= argv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF86859;
IF86858:
	local[0]= NIL;
IF86859:
	if (argv[0]->c.obj.iv[3]==NIL) goto IF86880;
	local[0]= argv[0]->c.obj.iv[3];
	local[1]= fqv[30];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	ctx->vsp=local+1;
	w=(pointer)TRANSPOSE(ctx,1,local+0); /*transpose*/
	local[0]= w;
	local[1]= argv[2];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	goto IF86881;
IF86880:
	local[0]= argv[2];
IF86881:
	goto CON86815;
CON86854:
	local[0]= NIL;
CON86815:
	w = local[0];
	local[0]= w;
BLK86799:
	ctx->vsp=local; return(local[0]);}

/*:manager*/
static pointer M86898cascaded_coords_manager(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT86902;}
	local[0]= NIL;
ENT86902:
ENT86901:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF86918;
	argv[0]->c.obj.iv[6] = local[0];
	local[1]= argv[0]->c.obj.iv[6];
	goto IF86919;
IF86918:
	local[1]= NIL;
IF86919:
	w = argv[0]->c.obj.iv[6];
	local[0]= w;
BLK86899:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M86934cascaded_coords_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST86937:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[113], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY86950;
	local[1] = NIL;
KEY86950:
	if (n & (1<<1)) goto KEY86955;
	local[2] = NIL;
KEY86955:
	local[3]= (pointer)get_sym_func(fqv[114]);
	local[4]= argv[0];
	local[5]= *(ovafptr(argv[1],fqv[60]));
	local[6]= fqv[115];
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(pointer)APPLY(ctx,5,local+3); /*apply*/
	argv[0]->c.obj.iv[6] = argv[0];
	argv[0]->c.obj.iv[7] = T;
	local[3]= loadglobal(fqv[0]);
	ctx->vsp=local+4;
	w=(pointer)INSTANTIATE(ctx,1,local+3); /*instantiate*/
	local[3]= w;
	local[4]= local[3];
	local[5]= fqv[115];
	local[6]= fqv[116];
	local[7]= argv[0]->c.obj.iv[1];
	ctx->vsp=local+8;
	w=(*ftab[3])(ctx,1,local+7,&ftab[3],fqv[5]); /*copy-matrix*/
	local[7]= w;
	local[8]= fqv[117];
	local[9]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+10;
	w=(pointer)COPYSEQ(ctx,1,local+9); /*copy-seq*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,6,local+4); /*send*/
	w = local[3];
	argv[0]->c.obj.iv[5] = w;
	if (local[1]==NIL) goto IF87033;
	local[3]= local[1];
	local[4]= fqv[118];
	local[5]= argv[0];
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	local[3]= w;
	goto IF87034;
IF87033:
	local[3]= NIL;
IF87034:
	w = argv[0];
	local[0]= w;
BLK86935:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO84606(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= argv[0];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	ctx->vsp=local+1;
	w = cons(ctx,local[0],w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*transform-coords*/
static pointer F81347transform_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT87073;}
	local[0]= argv[0];
	local[1]= fqv[82];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= loadglobal(fqv[0]);
	ctx->vsp=local+2;
	w=(pointer)INSTANTIATE(ctx,1,local+1); /*instantiate*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[16];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[5])(ctx,1,local+4,&ftab[5],fqv[10]); /*unit-matrix*/
	local[4]= w;
	local[5]= loadglobal(fqv[11]);
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,2,local+5); /*instantiate*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,4,local+2); /*send*/
	w = local[1];
	local[0]= w;
ENT87073:
ENT87072:
	if (n>3) maerror();
	local[1]= argv[0];
	if (local[0]!=local[1]) goto IF87136;
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[1]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)TRANSFORM(ctx,2,local+2); /*transform*/
	local[2]= w;
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= w;
	goto IF87137;
IF87136:
	local[1]= argv[0]->c.obj.iv[2];
	local[2]= argv[0]->c.obj.iv[1];
	local[3]= argv[1]->c.obj.iv[2];
	local[4]= local[0]->c.obj.iv[2];
	ctx->vsp=local+5;
	w=(pointer)TRANSFORM(ctx,3,local+2); /*transform*/
	local[2]= w;
	local[3]= local[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VPLUS(ctx,3,local+1); /*v+*/
	local[1]= w;
IF87137:
	local[1]= argv[0]->c.obj.iv[1];
	local[2]= argv[1]->c.obj.iv[1];
	local[3]= local[0]->c.obj.iv[1];
	ctx->vsp=local+4;
	w=(pointer)MATTIMES(ctx,3,local+1); /*m**/
	w = local[0];
	local[0]= w;
BLK87070:
	ctx->vsp=local; return(local[0]);}

/*transform-coords**/
static pointer F81349transform_coords_(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST87220:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= argv[1];
	ctx->vsp=local+5;
	w=(pointer)F81347transform_coords(ctx,2,local+3); /*transform-coords*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[0];
WHL87264:
	if (local[4]==NIL) goto WHX87265;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[2];
	local[6]= local[3];
	local[7]= local[2];
	ctx->vsp=local+8;
	w=(pointer)F81347transform_coords(ctx,3,local+5); /*transform-coords*/
	goto WHL87264;
WHX87265:
	local[5]= NIL;
BLK87266:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK87218:
	ctx->vsp=local; return(local[0]);}

/*transform-vector*/
static pointer F81351transform_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[1];
	local[1]= argv[1];
	ctx->vsp=local+2;
	w=(pointer)TRANSFORM(ctx,2,local+0); /*transform*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK87325:
	ctx->vsp=local; return(local[0]);}

/*make-coords*/
static pointer F81353make_coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST87361:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK87359:
	ctx->vsp=local; return(local[0]);}

/*make-cascoords*/
static pointer F81355make_cascoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST87384:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[121]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK87382:
	ctx->vsp=local; return(local[0]);}

/*coords*/
static pointer F81357coords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST87408:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK87406:
	ctx->vsp=local; return(local[0]);}

/*cascoords*/
static pointer F81359cascoords(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<0) maerror();
RST87431:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-0);
	local[1]= (pointer)get_sym_func(fqv[120]);
	local[2]= loadglobal(fqv[121]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= fqv[115];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[0]= w;
BLK87429:
	ctx->vsp=local; return(local[0]);}

/*wrt*/
static pointer F81361wrt(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[47];
	local[2]= argv[1];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK87452:
	ctx->vsp=local; return(local[0]);}

/*coordinates-distance*/
static pointer F81366coordinates_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[75];
	local[3]= argv[1];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= local[1];
	local[3]= fqv[59];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORM(ctx,1,local+2); /*norm*/
	local[2]= w;
	local[3]= local[1];
	local[4]= fqv[30];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)ROTANGLE(ctx,1,local+3); /*rotation-angle*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[0]= w;
BLK87476:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___coordinates(ctx,n,argv,env)
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
	local[0]= fqv[122];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w!=NIL) goto IF87524;
	local[0]= fqv[123];
	local[1]= fqv[124];
	local[2]= fqv[125];
	ctx->vsp=local+3;
	w=(*ftab[15])(ctx,3,local+0,&ftab[15],fqv[126]); /*make-package*/
	local[0]= fqv[127];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF87543;
	local[0]= fqv[128];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF87544;
IF87543:
	local[0]= fqv[130];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF87544:
	local[0]= fqv[131];
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[132]); /*use-package*/
	local[0]= w;
	goto IF87525;
IF87524:
	local[0]= NIL;
IF87525:
	local[0]= fqv[133];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF87565;
	local[0]= fqv[134];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[129],w);
	goto IF87566;
IF87565:
	local[0]= fqv[135];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF87566:
	local[0]= fqv[136];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[137];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[138];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[139];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[140];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[0];
	local[1]= fqv[141];
	local[2]= fqv[0];
	local[3]= fqv[142];
	local[4]= loadglobal(fqv[143]);
	local[5]= fqv[144];
	local[6]= fqv[145];
	local[7]= fqv[146];
	local[8]= NIL;
	local[9]= fqv[147];
	local[10]= NIL;
	local[11]= fqv[148];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[149];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[150]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[151],module,F81327coordinates_p,fqv[152]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81440coordinates_dimension,fqv[82],fqv[0],fqv[153]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81457coordinates_rot,fqv[116],fqv[0],fqv[154]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81473coordinates_pos,fqv[117],fqv[0],fqv[155]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81489coordinates_x_axis,fqv[156],fqv[0],fqv[157]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81507coordinates_y_axis,fqv[158],fqv[0],fqv[159]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81524coordinates_z_axis,fqv[160],fqv[0],fqv[161]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81541coordinates_name,fqv[2],fqv[0],fqv[162]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81581coordinates_newcoords,fqv[16],fqv[0],fqv[163]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81639coordinates_replace_rot,fqv[164],fqv[0],fqv[165]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81660coordinates_replace_pos,fqv[166],fqv[0],fqv[167]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81681coordinates_replace_coords,fqv[69],fqv[0],fqv[168]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81746coordinates_copy_rot,fqv[169],fqv[0],fqv[170]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81764coordinates_copy_pos,fqv[171],fqv[0],fqv[172]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81781coordinates_copy_coords,fqv[77],fqv[0],fqv[173]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81849coordinates_coords,fqv[7],fqv[0],fqv[174]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81917coordinates_worldrot,fqv[30],fqv[0],fqv[175]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81933coordinates_worldpos,fqv[59],fqv[0],fqv[176]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81949coordinates_worldcoords,fqv[18],fqv[0],fqv[177]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81965coordinates_copy_worldcoords,fqv[178],fqv[0],fqv[179]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M81984coordinates_parentcoords,fqv[19],fqv[0],fqv[180]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82001coordinates_changed,fqv[12],fqv[0],fqv[181]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82016coordinates_reset_coords,fqv[182],fqv[0],fqv[183]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82070coordinates_move_to,fqv[184],fqv[0],fqv[185]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82215coordinates_rotate_vector,fqv[87],fqv[0],fqv[186]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82235coordinates_transform_vector,fqv[47],fqv[0],fqv[187]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82258coordinates_inverse_transform_vector,fqv[88],fqv[0],fqv[188]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82298coordinates_inverse_transformation,fqv[20],fqv[0],fqv[189]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82384coordinates_transformation,fqv[75],fqv[0],fqv[190]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82540coordinates_transform,fqv[191],fqv[0],fqv[192]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82660coordinates_rotate_with_matrix,fqv[35],fqv[0],fqv[193]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82777coordinates_rotate,fqv[70],fqv[0],fqv[194]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M82963coordinates_orient_with_matrix,fqv[42],fqv[0],fqv[195]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83063coordinates_orient,fqv[196],fqv[0],fqv[197]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83213coordinates_parent_vector,fqv[54],fqv[0],fqv[198]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83296coordinates_parent_orientation,fqv[53],fqv[0],fqv[199]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83379coordinates_translate,fqv[200],fqv[0],fqv[201]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83421coordinates_locate,fqv[202],fqv[0],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83462coordinates_scale,fqv[204],fqv[0],fqv[205]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83510coordinates_euler,fqv[67],fqv[0],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83542coordinates_euler_angle,fqv[207],fqv[0],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83559coordinates_rpy,fqv[68],fqv[0],fqv[209]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83591coordinates_rpy_angle,fqv[210],fqv[0],fqv[211]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83608coordinates_rotation_angle,fqv[212],fqv[0],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83625coordinates_4x4,fqv[71],fqv[0],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M83892coordinates_prin1,fqv[61],fqv[0],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84056coordinates_create,fqv[6],fqv[0],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84094coordinates_init,fqv[115],fqv[0],fqv[217]);
	local[0]= fqv[121];
	local[1]= fqv[141];
	local[2]= fqv[121];
	local[3]= fqv[142];
	local[4]= loadglobal(fqv[0]);
	local[5]= fqv[144];
	local[6]= fqv[218];
	local[7]= fqv[146];
	local[8]= NIL;
	local[9]= fqv[147];
	local[10]= NIL;
	local[11]= fqv[148];
	local[12]= makeint((eusinteger_t)-1L);
	local[13]= fqv[149];
	local[14]= NIL;
	ctx->vsp=local+15;
	w=(*ftab[17])(ctx,13,local+2,&ftab[17],fqv[150]); /*make-class*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84560cascaded_coords_parent,fqv[219],fqv[121],fqv[220]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84576cascaded_coords_descendants,fqv[221],fqv[121],fqv[222]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84592cascaded_coords_inheritance,fqv[119],fqv[121],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84612cascaded_coords_leaves,fqv[72],fqv[121],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84642cascaded_coords_assoc,fqv[118],fqv[121],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84745cascaded_coords_dissoc,fqv[80],fqv[121],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84831cascaded_coords_clear_assoc,fqv[227],fqv[121],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84922cascaded_coords_obey,fqv[76],fqv[121],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84959cascaded_coords_disobey,fqv[79],fqv[121],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M84990cascaded_coords_newcoords,fqv[16],fqv[121],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85032cascaded_coords_changed,fqv[12],fqv[121],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85068cascaded_coords_worldrot,fqv[30],fqv[121],fqv[233]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85092cascaded_coords_worldpos,fqv[59],fqv[121],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85116cascaded_coords_worldcoords,fqv[18],fqv[121],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85177cascaded_coords_copy_worldcoords,fqv[178],fqv[121],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85259cascaded_coords_update,fqv[81],fqv[121],fqv[237]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85273cascaded_coords_parentcoords,fqv[19],fqv[121],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85343cascaded_coords_transform_vector,fqv[47],fqv[121],fqv[239]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85369cascaded_coords_rotate_vector,fqv[87],fqv[121],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85395cascaded_coords_inverse_transform_vector,fqv[88],fqv[121],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85421cascaded_coords_inverse_transformation,fqv[20],fqv[121],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85476cascaded_coords_transformation,fqv[75],fqv[121],fqv[243]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85676cascaded_coords_transform,fqv[191],fqv[121],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M85883cascaded_coords_move_to,fqv[184],fqv[121],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86068cascaded_coords_rotate_with_matrix,fqv[35],fqv[121],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86241cascaded_coords_rotate,fqv[70],fqv[121],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86398cascaded_coords_orient_with_matrix,fqv[42],fqv[121],fqv[248]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86555cascaded_coords_orient,fqv[196],fqv[121],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86699cascaded_coords_parent_vector,fqv[54],fqv[121],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86798cascaded_coords_parent_orientation,fqv[53],fqv[121],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86898cascaded_coords_manager,fqv[252],fqv[121],fqv[253]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M86934cascaded_coords_init,fqv[115],fqv[121],fqv[254]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[255],module,F81347transform_coords,fqv[256]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[257],module,F81349transform_coords_,fqv[258]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[259],module,F81351transform_vector,fqv[260]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[261],module,F81353make_coords,fqv[262]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[263],module,F81355make_cascoords,fqv[264]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[265],module,F81357coords,fqv[266]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[267],module,F81359cascoords,fqv[268]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[269],module,F81361wrt,fqv[270]);
	local[0]= fqv[8];
	local[1]= fqv[271];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[115];
	local[5]= fqv[2];
	local[6]= fqv[8];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,4,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= fqv[85];
	local[1]= fqv[271];
	local[2]= loadglobal(fqv[0]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[115];
	local[5]= fqv[82];
	local[6]= makeint((eusinteger_t)2L);
	local[7]= fqv[2];
	local[8]= fqv[85];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,6,local+3); /*send*/
	w = local[2];
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	ctx->vsp=local+0;
	compfun(ctx,fqv[272],module,F81366coordinates_distance,fqv[273]);
	local[0]= fqv[274];
	local[1]= fqv[275];
	ctx->vsp=local+2;
	w=(*ftab[18])(ctx,2,local+0,&ftab[18],fqv[276]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<19; i++) ftab[i]=fcallx;
}
