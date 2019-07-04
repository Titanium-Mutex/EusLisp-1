/* ./geobody.c :  entry=geobody */
/* compiled by EusLisp 9.23(2f2203a0) for Linux64 created on parrot(Tue Feb 19 20:22:26 JST 2019) */
#include "eus.h"
#include "geobody.h"
#pragma init (register_geobody)
extern double fabs();
extern pointer fcallx();
static void init_ftab();
extern pointer loadglobal(),storeglobal();
static pointer module,*qv,codevec,quotevec;
extern pointer ___geobody();
extern pointer build_quote_vector();
static int register_geobody()
  { add_module_initializer("___geobody", ___geobody);}

static pointer F1247add_wings();

/*:update*/
static pointer M1248faceset_update(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	if (loadglobal(fqv[0])==NIL) goto IF1250;
	local[0]= loadglobal(fqv[1]);
	local[1]= fqv[2];
	local[2]= argv[0];
	local[3]= fqv[3];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)XFORMAT(ctx,3,local+0); /*format*/
	local[0]= w;
	goto IF1251;
IF1250:
	local[0]= NIL;
IF1251:
	local[0]= argv[0];
	local[1]= fqv[4];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL1253:
	if (local[1]==NIL) goto WHX1254;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[5];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	goto WHL1253;
WHX1254:
	local[2]= NIL;
BLK1255:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[6];
	ctx->vsp=local+2;
	w=(*ftab[0])(ctx,2,local+0,&ftab[0],fqv[7]); /*remprop*/
	w = argv[0];
	local[0]= w;
BLK1249:
	ctx->vsp=local; return(local[0]);}

/*:vertices*/
static pointer M1257faceset_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[11];
	local[0]= w;
BLK1258:
	ctx->vsp=local; return(local[0]);}

/*:faces*/
static pointer M1259faceset_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1261:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	if (local[0]==NIL) goto CON1263;
	local[1]= (pointer)get_sym_func(fqv[8]);
	local[2]= argv[0];
	local[3]= fqv[9];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)APPLY(ctx,4,local+1); /*apply*/
	local[1]= w;
	goto CON1262;
CON1263:
	local[1]= argv[0]->c.obj.iv[9];
	goto CON1262;
CON1264:
	local[1]= NIL;
CON1262:
	w = local[1];
	local[0]= w;
BLK1260:
	ctx->vsp=local; return(local[0]);}

/*:face*/
static pointer M1265faceset_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1266:
	ctx->vsp=local; return(local[0]);}

/*:all-edges*/
static pointer M1267faceset_all_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1268:
	ctx->vsp=local; return(local[0]);}

/*:edges*/
static pointer M1269faceset_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[10];
	local[0]= w;
BLK1270:
	ctx->vsp=local; return(local[0]);}

/*:edge*/
static pointer M1271faceset_edge(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1272:
	ctx->vsp=local; return(local[0]);}

/*:vertex*/
static pointer M1273faceset_vertex(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)NTH(ctx,2,local+0); /*nth*/
	local[0]= w;
BLK1274:
	ctx->vsp=local; return(local[0]);}

/*:box*/
static pointer M1275faceset_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1276:
	ctx->vsp=local; return(local[0]);}

/*:color*/
static pointer M1277faceset_color(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1280;}
	local[0]= NIL;
ENT1280:
ENT1279:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1281;
	local[1]= argv[0];
	local[2]= local[0];
	local[3]= fqv[10];
	ctx->vsp=local+4;
	w=(pointer)PUTPROP(ctx,3,local+1); /*putprop*/
	local[1]= w;
	goto IF1282;
IF1281:
	local[1]= argv[0];
	local[2]= fqv[10];
	ctx->vsp=local+3;
	w=(pointer)GETPROP(ctx,2,local+1); /*get*/
	local[1]= w;
IF1282:
	w = local[1];
	local[0]= w;
BLK1278:
	ctx->vsp=local; return(local[0]);}

/*:reflectance*/
static pointer M1283faceset_reflectance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1286;}
	local[0]= NIL;
ENT1286:
ENT1285:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1287;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[11];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1288;
IF1287:
	local[3]= argv[0];
	local[4]= fqv[11];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1289;
	local[3]= local[2];
	goto IF1290;
IF1289:
	local[3]= makeflt(5.0000000000000000000000e-01);
IF1290:
IF1288:
	w = local[3];
	local[0]= w;
BLK1284:
	ctx->vsp=local; return(local[0]);}

/*:diffusion*/
static pointer M1291faceset_diffusion(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1294;}
	local[0]= NIL;
ENT1294:
ENT1293:
	if (n>3) maerror();
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1295;
	local[3]= argv[0];
	local[4]= local[0];
	local[5]= fqv[12];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	local[3]= w;
	goto IF1296;
IF1295:
	local[3]= argv[0];
	local[4]= fqv[12];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	if (local[2]==NIL) goto IF1297;
	local[3]= local[2];
	goto IF1298;
IF1297:
	local[3]= makeflt(5.0000000000000000000000e-01);
IF1298:
IF1296:
	w = local[3];
	local[0]= w;
BLK1292:
	ctx->vsp=local; return(local[0]);}

/*:holes*/
static pointer M1299faceset_holes(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[13]);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[14];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1300:
	ctx->vsp=local; return(local[0]);}

/*:visible-faces*/
static pointer M1301faceset_visible_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= loadglobal(fqv[16]);
	ctx->vsp=local+2;
	w=(pointer)DERIVEDP(ctx,2,local+0); /*derivedp*/
	if (w==NIL) goto IF1303;
	local[0]= argv[2];
	local[1]= fqv[17];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	argv[2] = w;
	local[0]= argv[2];
	goto IF1304;
IF1303:
	local[0]= NIL;
IF1304:
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1305,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1302:
	ctx->vsp=local; return(local[0]);}

/*:visible-edges*/
static pointer M1306faceset_visible_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= loadglobal(fqv[16]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto IF1308;
	local[3]= argv[2];
	local[4]= fqv[17];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	argv[2] = w;
	local[3]= argv[2];
	goto IF1309;
IF1308:
	local[3]= NIL;
IF1309:
	local[3]= argv[0];
	local[4]= fqv[6];
	ctx->vsp=local+5;
	w=(pointer)GETPROP(ctx,2,local+3); /*get*/
	local[2] = w;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)EQUAL(ctx,2,local+3); /*equal*/
	if (w==NIL) goto IF1310;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.cdr;
	goto IF1311;
IF1310:
	local[3]= fqv[18];
	local[4]= makeflt(1.5000000000000000000000e+00);
	local[5]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+6;
	w=(pointer)LENGTH(ctx,1,local+5); /*length*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(pointer)TIMES(ctx,2,local+4); /***/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)ROUND(ctx,1,local+4); /*round*/
	local[4]= w;
	local[5]= fqv[19];
	local[6]= (pointer)get_sym_func(fqv[20]);
	ctx->vsp=local+7;
	w=(*ftab[2])(ctx,4,local+3,&ftab[2],fqv[21]); /*make-hash-table*/
	local[3]= w;
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= fqv[22];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[5]= w;
WHL1313:
	if (local[5]==NIL) goto WHX1314;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[23];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL1318:
	if (local[7]==NIL) goto WHX1319;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= local[3];
	local[10]= local[6];
	ctx->vsp=local+11;
	w=(*ftab[3])(ctx,3,local+8,&ftab[3],fqv[24]); /*sethash*/
	goto WHL1318;
WHX1319:
	local[8]= NIL;
BLK1320:
	w = NIL;
	goto WHL1313;
WHX1314:
	local[6]= NIL;
BLK1315:
	w = NIL;
	local[4]= local[3];
	local[5]= fqv[25];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[2] = w;
	local[4]= argv[0];
	local[5]= argv[2];
	w = local[2];
	ctx->vsp=local+6;
	local[5]= cons(ctx,local[5],w);
	local[6]= fqv[6];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= local[3]->c.obj.iv[0];
	ctx->vsp=local+5;
	w=(pointer)RECLAIM(ctx,1,local+4); /*system:reclaim*/
	local[4]= local[3]->c.obj.iv[1];
	ctx->vsp=local+5;
	w=(pointer)RECLAIM(ctx,1,local+4); /*system:reclaim*/
	w = local[2];
	local[3]= w;
IF1311:
	w = local[3];
	local[0]= w;
BLK1307:
	ctx->vsp=local; return(local[0]);}

/*:contour-edges*/
static pointer M1322faceset_contour_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL1325:
	if (local[4]==NIL) goto WHX1326;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1330;
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w!=NIL) goto IF1331;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1332;
IF1331:
	local[5]= NIL;
IF1332:
	goto CON1329;
CON1330:
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1333;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w!=NIL) goto IF1334;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1335;
IF1334:
	local[5]= NIL;
IF1335:
	goto CON1329;
CON1333:
	local[5]= NIL;
CON1329:
	goto WHL1325;
WHX1326:
	local[5]= NIL;
BLK1327:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1323:
	ctx->vsp=local; return(local[0]);}

/*:non-contour-edges*/
static pointer M1336faceset_non_contour_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[22];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[10];
WHL1339:
	if (local[4]==NIL) goto WHX1340;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3]->c.obj.iv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1343;
	local[5]= local[3]->c.obj.iv[4];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(*ftab[4])(ctx,2,local+5,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1343;
	local[5]= local[3];
	w = local[2];
	ctx->vsp=local+6;
	local[2] = cons(ctx,local[5],w);
	local[5]= local[2];
	goto IF1344;
IF1343:
	local[5]= NIL;
IF1344:
	goto WHL1339;
WHX1340:
	local[5]= NIL;
BLK1341:
	w = NIL;
	w = local[2];
	local[0]= w;
BLK1337:
	ctx->vsp=local; return(local[0]);}

/*:common-box*/
static pointer M1345faceset_common_box(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1348;}
	local[0]= NIL;
ENT1348:
ENT1347:
	if (n>4) maerror();
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[27];
	local[3]= argv[2];
	local[4]= fqv[28];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK1346:
	ctx->vsp=local; return(local[0]);}

/*:newbox*/
static pointer M1349faceset_newbox(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1352;}
	local[0]= loadglobal(fqv[29]);
ENT1352:
ENT1351:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[11];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(*ftab[5])(ctx,2,local+1,&ftab[5],fqv[30]); /*make-bounding-box*/
	argv[0]->c.obj.iv[8] = w;
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1350:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1305(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[31];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1353;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1354;
IF1353:
	local[0]= NIL;
IF1354:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:reset-vertices*/
static pointer M1355faceset_reset_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[12];
	local[1]= argv[0]->c.obj.iv[11];
	local[2]= argv[0]->c.obj.iv[5]->c.obj.iv[1];
	local[3]= argv[0]->c.obj.iv[5]->c.obj.iv[2];
WHL1357:
	if (local[0]==NIL) goto WHX1358;
	local[4]= local[2];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)TRANSFORM(ctx,3,local+4); /*transform*/
	local[4]= local[3];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	ctx->vsp=local+7;
	w=(pointer)VPLUS(ctx,3,local+4); /*v+*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[4];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0] = (w)->c.cons.cdr;
	w = local[4];
	goto WHL1357;
WHX1358:
	local[4]= NIL;
BLK1359:
	local[4]= argv[0]->c.obj.iv[8];
	local[5]= fqv[32];
	local[6]= argv[0]->c.obj.iv[11];
	local[7]= loadglobal(fqv[29]);
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,4,local+4); /*send*/
	w = argv[0];
	local[0]= w;
BLK1356:
	ctx->vsp=local; return(local[0]);}

/*:translate-vertices*/
static pointer M1362faceset_translate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[12];
WHL1365:
	if (local[1]==NIL) goto WHX1366;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[2];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)VPLUS(ctx,3,local+2); /*v+*/
	goto WHL1365;
WHX1366:
	local[2]= NIL;
BLK1367:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK1363:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vertices*/
static pointer M1369faceset_rotate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= NIL;
	local[1]= argv[3];
	ctx->vsp=local+2;
	w=(*ftab[6])(ctx,1,local+1,&ftab[6],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto IF1371;
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(*ftab[7])(ctx,2,local+1,&ftab[7],fqv[35]); /*rotation*/
	local[0] = w;
	local[1]= local[0];
	goto IF1372;
IF1371:
	local[1]= NIL;
IF1372:
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1374:
	if (local[2]==NIL) goto WHX1375;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(*ftab[6])(ctx,1,local+3,&ftab[6],fqv[34]); /*float-vector-p*/
	if (w==NIL) goto IF1378;
	local[3]= local[0];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)TRANSFORM(ctx,3,local+3); /*transform*/
	local[3]= w;
	goto IF1379;
IF1378:
	local[3]= local[1];
	local[4]= argv[2];
	local[5]= argv[3];
	local[6]= local[1];
	ctx->vsp=local+7;
	w=(pointer)ROTVEC(ctx,4,local+3); /*rotate-vector*/
	local[3]= w;
IF1379:
	goto WHL1374;
WHX1375:
	local[3]= NIL;
BLK1376:
	w = NIL;
	local[0]= argv[0];
	local[1]= fqv[33];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	w = argv[0];
	local[0]= w;
BLK1370:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M1380faceset_magnify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1383;}
	local[0]= NIL;
ENT1383:
ENT1382:
	if (n>4) maerror();
	if (local[0]==NIL) goto CON1385;
	local[1]= local[0];
	local[2]= fqv[36];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1387;
	local[1]= fqv[37];
	goto CON1386;
CON1387:
	local[1]= local[0];
	local[2]= fqv[38];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1388;
	local[1]= fqv[39];
	goto CON1386;
CON1388:
	local[1]= local[0];
	local[2]= fqv[40];
	ctx->vsp=local+3;
	w=(pointer)EQ(ctx,2,local+1); /*eql*/
	if (w==NIL) goto CON1389;
	local[1]= fqv[41];
	goto CON1386;
CON1389:
	local[1]= local[0];
	ctx->vsp=local+2;
	w=(pointer)VNORMALIZE(ctx,1,local+1); /*normalize-vector*/
	local[1]= w;
	goto CON1386;
CON1390:
	local[1]= NIL;
CON1386:
	local[0] = local[1];
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1392:
	if (local[2]==NIL) goto WHX1393;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= makeflt(1.0000000000000000000000e+00);
	ctx->vsp=local+5;
	w=(pointer)MINUS(ctx,2,local+3); /*-*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,2,local+3); /***/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SCALEVEC(ctx,2,local+3); /*scale*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VPLUS(ctx,3,local+3); /*v+*/
	goto WHL1392;
WHX1393:
	local[3]= NIL;
BLK1394:
	w = NIL;
	local[1]= w;
	goto CON1384;
CON1385:
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[12];
WHL1398:
	if (local[2]==NIL) goto WHX1399;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[2];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.cdr;
	w = local[3];
	local[1] = w;
	local[3]= argv[2];
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,3,local+3); /*scale*/
	goto WHL1398;
WHX1399:
	local[3]= NIL;
BLK1400:
	w = NIL;
	local[1]= w;
	goto CON1384;
CON1396:
	local[1]= NIL;
CON1384:
	local[1]= argv[0];
	local[2]= fqv[33];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	w = argv[0];
	local[0]= w;
BLK1381:
	ctx->vsp=local; return(local[0]);}

/*:faces-intersect-with-point-vector*/
static pointer M1402faceset_faces_intersect_with_point_vector(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	w = argv[3];
	ctx->vsp=local+0;
	bindspecial(ctx,fqv[42],w);
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1405:
	if (local[6]==NIL) goto WHX1406;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[43];
	local[9]= argv[2];
	local[10]= loadglobal(fqv[42]);
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	if (fqv[44]!=local[7]) goto IF1409;
	local[7]= local[5];
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	ctx->vsp=local+9;
	w=(pointer)LIST(ctx,2,local+7); /*list*/
	local[7]= w;
	w = local[3];
	ctx->vsp=local+8;
	local[3] = cons(ctx,local[7],w);
	local[7]= local[3];
	goto IF1410;
IF1409:
	local[7]= NIL;
IF1410:
	goto WHL1405;
WHX1406:
	local[7]= NIL;
BLK1407:
	w = NIL;
	w = local[3];
	local[3]= w;
	ctx->vsp=local+4;
	unbindx(ctx,1);
	w = local[3];
	local[0]= w;
BLK1403:
	ctx->vsp=local; return(local[0]);}

/*:distance*/
static pointer M1411faceset_distance(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[2];
	local[4]= loadglobal(fqv[45]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON1414;
	local[0] = makeflt(9.9999999999999973840965e+29);
	local[3]= NIL;
	local[4]= argv[0]->c.obj.iv[9];
WHL1416:
	if (local[4]==NIL) goto WHX1417;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[46];
	local[7]= argv[2];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	local[5]= local[2];
	ctx->vsp=local+6;
	w=(pointer)ABS(ctx,1,local+5); /*abs*/
	local[5]= w;
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)ABS(ctx,1,local+6); /*abs*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF1420;
	local[0] = local[2];
	local[1] = local[3];
	local[5]= local[1];
	goto IF1421;
IF1420:
	local[5]= NIL;
IF1421:
	goto WHL1416;
WHX1417:
	local[5]= NIL;
BLK1418:
	w = NIL;
	local[3]= w;
	goto CON1413;
CON1414:
	local[3]= argv[2];
	local[4]= loadglobal(fqv[47]);
	ctx->vsp=local+5;
	w=(pointer)DERIVEDP(ctx,2,local+3); /*derivedp*/
	if (w==NIL) goto CON1422;
	local[3]= argv[2];
	local[4]= fqv[46];
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[0] = w;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.car;
	local[3]= NIL;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL1424:
	if (local[4]==NIL) goto WHX1425;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[2];
	local[6]= fqv[46];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	local[2] = w;
	local[5]= local[2];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(pointer)LESSP(ctx,2,local+5); /*<*/
	if (w==NIL) goto IF1428;
	local[0] = local[2];
	local[1] = local[3];
	local[5]= local[1];
	goto IF1429;
IF1428:
	local[5]= NIL;
IF1429:
	goto WHL1424;
WHX1425:
	local[5]= NIL;
BLK1426:
	w = NIL;
	local[3]= w;
	goto CON1413;
CON1422:
	local[3]= NIL;
CON1413:
	local[3]= local[0];
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(*ftab[8])(ctx,2,local+3,&ftab[8],fqv[48]); /*values*/
	local[0]= w;
BLK1412:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1430faceset_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1432:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[49], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1433;
	local[1] = NIL;
KEY1433:
	if (n & (1<<1)) goto KEY1434;
	local[2] = NIL;
KEY1434:
	if (n & (1<<2)) goto KEY1435;
	local[3] = NIL;
KEY1435:
	if (n & (1<<3)) goto KEY1436;
	local[4] = NIL;
KEY1436:
	if (n & (1<<4)) goto KEY1437;
	local[5] = NIL;
KEY1437:
	if (n & (1<<5)) goto KEY1438;
	local[6] = NIL;
KEY1438:
	if (local[1]==NIL) goto IF1439;
	argv[0]->c.obj.iv[9] = local[1];
	if (local[2]!=NIL) goto IF1441;
	local[7]= (pointer)get_sym_func(fqv[13]);
	local[8]= local[1];
	local[9]= fqv[23];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[15]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,2,local+7); /*apply*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[50]); /*remove-duplicates*/
	argv[0]->c.obj.iv[10] = w;
	local[7]= argv[0]->c.obj.iv[10];
	goto IF1442;
IF1441:
	local[7]= NIL;
IF1442:
	if (local[3]!=NIL) goto IF1443;
	local[7]= (pointer)get_sym_func(fqv[13]);
	local[8]= local[1];
	local[9]= fqv[51];
	ctx->vsp=local+10;
	w=(*ftab[1])(ctx,2,local+8,&ftab[1],fqv[15]); /*send-all*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,2,local+7); /*apply*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(*ftab[9])(ctx,1,local+7,&ftab[9],fqv[50]); /*remove-duplicates*/
	argv[0]->c.obj.iv[11] = w;
	local[7]= argv[0]->c.obj.iv[11];
	goto IF1444;
IF1443:
	local[7]= NIL;
IF1444:
	goto IF1440;
IF1439:
	local[7]= NIL;
IF1440:
	local[7]= (pointer)get_sym_func(fqv[52]);
	local[8]= argv[0];
	local[9]= *(ovafptr(argv[1],fqv[53]));
	local[10]= fqv[32];
	local[11]= local[0];
	ctx->vsp=local+12;
	w=(pointer)APPLY(ctx,5,local+7); /*apply*/
	if (local[2]==NIL) goto IF1445;
	argv[0]->c.obj.iv[10] = local[2];
	local[7]= argv[0]->c.obj.iv[10];
	goto IF1446;
IF1445:
	local[7]= NIL;
IF1446:
	if (local[3]==NIL) goto IF1447;
	argv[0]->c.obj.iv[11] = local[3];
	local[7]= argv[0]->c.obj.iv[11];
	goto IF1448;
IF1447:
	local[7]= NIL;
IF1448:
	local[7]= loadglobal(fqv[54]);
	ctx->vsp=local+8;
	w=(pointer)INSTANTIATE(ctx,1,local+7); /*instantiate*/
	local[7]= w;
	local[8]= local[7];
	local[9]= fqv[32];
	local[10]= argv[0]->c.obj.iv[11];
	local[11]= loadglobal(fqv[29]);
	ctx->vsp=local+12;
	w=(pointer)SEND(ctx,4,local+8); /*send*/
	w = local[7];
	argv[0]->c.obj.iv[8] = w;
	if (argv[0]->c.obj.iv[12]!=NIL) goto IF1450;
	local[7]= NIL;
	goto IF1451;
IF1450:
	local[7]= NIL;
IF1451:
	local[7]= (pointer)get_sym_func(fqv[55]);
	local[8]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+9;
	w=(pointer)MAPCAR(ctx,2,local+7); /*mapcar*/
	argv[0]->c.obj.iv[12] = w;
	if (local[4]==NIL) goto IF1452;
	local[7]= argv[0];
	local[8]= local[4];
	local[9]= fqv[10];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1453;
IF1452:
	local[7]= NIL;
IF1453:
	if (local[5]==NIL) goto IF1454;
	local[7]= argv[0];
	local[8]= local[5];
	local[9]= fqv[11];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1455;
IF1454:
	local[7]= NIL;
IF1455:
	if (local[6]==NIL) goto IF1456;
	local[7]= argv[0];
	local[8]= local[6];
	local[9]= fqv[12];
	ctx->vsp=local+10;
	w=(pointer)PUTPROP(ctx,3,local+7); /*putprop*/
	local[7]= w;
	goto IF1457;
IF1456:
	local[7]= NIL;
IF1457:
	w = argv[0];
	local[0]= w;
BLK1431:
	ctx->vsp=local; return(local[0]);}

/*:translate-vertices*/
static pointer M1458body_translate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[56];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SENDMESSAGE(ctx,4,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[15];
	local[1]= fqv[56];
	local[2]= argv[2];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,2,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1459:
	ctx->vsp=local; return(local[0]);}

/*:rotate-vertices*/
static pointer M1460body_rotate_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[57];
	local[3]= argv[2];
	local[4]= argv[3];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= argv[0]->c.obj.iv[15];
	local[1]= fqv[57];
	local[2]= argv[2];
	local[3]= argv[3];
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,3,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,1,local+1); /*list*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1461:
	ctx->vsp=local; return(local[0]);}

/*:magnify*/
static pointer M1462body_magnify(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1465;}
	local[0]= NIL;
ENT1465:
ENT1464:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= *(ovafptr(argv[1],fqv[53]));
	local[3]= fqv[58];
	local[4]= argv[2];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SENDMESSAGE(ctx,5,local+1); /*send-message*/
	local[1]= argv[0]->c.obj.iv[15];
	local[2]= fqv[58];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)EUSFLOAT(ctx,1,local+3); /*float*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,3,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)NCONC(ctx,2,local+1); /*nconc*/
	w = argv[0];
	local[0]= w;
BLK1463:
	ctx->vsp=local; return(local[0]);}

/*:euler*/
static pointer M1466body_euler(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+1;
	w=(pointer)LENGTH(ctx,1,local+0); /*length*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)LENGTH(ctx,1,local+1); /*length*/
	local[1]= w;
	local[2]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+3;
	w=(pointer)LENGTH(ctx,1,local+2); /*length*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[14];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LENGTH(ctx,1,local+3); /*length*/
	local[3]= w;
	local[4]= local[1];
	local[5]= makeint(-(intval(local[2])));
	local[6]= makeint(-(intval(local[0])));
	local[7]= makeint((eusinteger_t)2L);
	w = local[3];
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	w = (pointer)((eusinteger_t)local[7] + (eusinteger_t)w);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	w = (pointer)((eusinteger_t)local[6] + (eusinteger_t)w);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	w = (pointer)((eusinteger_t)local[5] + (eusinteger_t)w);
#if sun4 || vax || mips || i386 || alpha || x86_64 || ARM
	w=(pointer)((eusinteger_t)w-2);
#endif
	local[4]= (pointer)((eusinteger_t)local[4] + (eusinteger_t)w);
	local[5]= makeint((eusinteger_t)2L);
	ctx->vsp=local+6;
	w=(pointer)QUOTIENT(ctx,2,local+4); /*/*/
	local[0]= w;
BLK1467:
	ctx->vsp=local; return(local[0]);}

/*:perimeter*/
static pointer M1468body_perimeter(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[59]);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[60];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1469:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M1470body_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1473;}
	local[0]= fqv[61];
ENT1473:
ENT1472:
	if (n>3) maerror();
	local[1]= (pointer)get_sym_func(fqv[59]);
	local[2]= argv[0]->c.obj.iv[9];
	local[3]= fqv[62];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(*ftab[1])(ctx,3,local+2,&ftab[1],fqv[15]); /*send-all*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPLY(ctx,2,local+1); /*apply*/
	local[0]= w;
BLK1471:
	ctx->vsp=local; return(local[0]);}

/*:centroid*/
static pointer M1474body_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1477;}
	local[0]= makeint((eusinteger_t)0L);
	local[1]= makeint((eusinteger_t)0L);
	local[2]= makeint((eusinteger_t)0L);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*float-vector*/
	local[0]= w;
ENT1477:
ENT1476:
	if (n>3) maerror();
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[63];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(*ftab[1])(ctx,3,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	local[2]= (pointer)get_sym_func(fqv[59]);
	local[3]= (pointer)get_sym_func(fqv[64]);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)APPLY(ctx,2,local+2); /*apply*/
	local[2]= w;
	ctx->vsp=local+3;
	local[3]= makeclosure(codevec,quotevec,CLO1478,env,argv,local);
	local[4]= local[1];
	ctx->vsp=local+5;
	w=(pointer)MAPCAR(ctx,2,local+3); /*mapcar*/
	local[3]= w;
	local[4]= makeint((eusinteger_t)0L);
	local[5]= makeint((eusinteger_t)0L);
	local[6]= makeint((eusinteger_t)0L);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	local[5]= NIL;
	local[6]= local[3];
WHL1480:
	if (local[6]==NIL) goto WHX1481;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= local[4];
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)VPLUS(ctx,3,local+7); /*v+*/
	goto WHL1480;
WHX1481:
	local[7]= NIL;
BLK1482:
	w = NIL;
	local[5]= makeflt(1.0000000000000000000000e+00);
	local[6]= local[2];
	ctx->vsp=local+7;
	w=(pointer)QUOTIENT(ctx,2,local+5); /*/*/
	local[5]= w;
	local[6]= local[4];
	local[7]= local[4];
	ctx->vsp=local+8;
	w=(pointer)SCALEVEC(ctx,3,local+5); /*scale*/
	w = local[4];
	local[0]= w;
BLK1475:
	ctx->vsp=local; return(local[0]);}

/*:world-centroid*/
static pointer M1484body_world_centroid(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[66];
	local[2]= argv[0];
	local[3]= fqv[63];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
BLK1485:
	ctx->vsp=local; return(local[0]);}

/*:area*/
static pointer M1486body_area(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= (pointer)get_sym_func(fqv[59]);
	local[1]= argv[0]->c.obj.iv[9];
	local[2]= fqv[67];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
BLK1487:
	ctx->vsp=local; return(local[0]);}

/*:extream-point*/
static pointer M1488body_extream_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= argv[2];
	local[2]= local[0];
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	w=argv[0]->c.obj.iv[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.cdr;
WHL1491:
	if (local[4]==NIL) goto WHX1492;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[2];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[2] = w;
	local[5]= local[2];
	{ double left,right;
		right=fltval(local[1]); left=fltval(local[5]);
	if (left <= right) goto IF1495;}
	local[1] = local[2];
	local[0] = local[3];
	local[5]= local[0];
	goto IF1496;
IF1495:
	local[5]= NIL;
IF1496:
	goto WHL1491;
WHX1492:
	local[5]= NIL;
BLK1493:
	w = NIL;
	w = local[0];
	local[0]= w;
BLK1489:
	ctx->vsp=local; return(local[0]);}

/*:length*/
static pointer M1497body_length(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0];
	local[2]= fqv[68];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VINNERPRODUCT(ctx,2,local+0); /*v.*/
	local[0]= w;
	local[1]= argv[2];
	local[2]= argv[0];
	local[3]= fqv[68];
	local[4]= makeflt(-1.0000000000000000000000e+00);
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SCALEVEC(ctx,2,local+4); /*scale*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VINNERPRODUCT(ctx,2,local+1); /*v.*/
	{ double x,y;
		y=fltval(w); x=fltval(local[0]);
		local[0]=(makeflt(x - y));}
	w = local[0];
	local[0]= w;
BLK1498:
	ctx->vsp=local; return(local[0]);}

/*:supporting-faces*/
static pointer M1499body_supporting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1502;}
	local[0]= makeflt(0.0000000000000000000000e+00);
	local[1]= makeflt(0.0000000000000000000000e+00);
	local[2]= makeflt(-1.0000000000000000000000e+00);
	ctx->vsp=local+3;
	w=(pointer)MKFLTVEC(ctx,3,local+0); /*floatvector*/
	local[0]= w;
ENT1502:
ENT1501:
	if (n>3) maerror();
	local[1]= argv[0];
	local[2]= fqv[69];
	local[3]= argv[0];
	local[4]= fqv[63];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	local[0]= w;
BLK1500:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1478(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= (pointer)get_sym_func(fqv[70]);
	local[1]= argv[0];
	ctx->vsp=local+2;
	w=(pointer)APPLY(ctx,2,local+0); /*apply*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:possibly-interfering-faces*/
static pointer M1503body_possibly_interfering_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1505,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1504:
	ctx->vsp=local; return(local[0]);}

/*:possibly-interfering-edges*/
static pointer M1506body_possibly_interfering_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1508,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1507:
	ctx->vsp=local; return(local[0]);}

/*:intersect-face*/
static pointer M1509body_intersect_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[9];
WHL1512:
	if (local[1]==NIL) goto WHX1513;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[71];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w!=NIL) goto OR1518;
	local[2]= argv[2];
	local[3]= fqv[71];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w!=NIL) goto OR1518;
	goto IF1516;
OR1518:
	w = T;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1510;
	goto IF1517;
IF1516:
	local[2]= NIL;
IF1517:
	goto WHL1512;
WHX1513:
	local[2]= NIL;
BLK1514:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK1510:
	ctx->vsp=local; return(local[0]);}

/*:intersectp*/
static pointer M1519body_intersectp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	local[1]= NIL;
	local[2]= NIL;
	if (local[0]==NIL) goto IF1521;
	local[3]= argv[0];
	local[4]= fqv[72];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[1] = w;
	local[3]= argv[2];
	local[4]= fqv[72];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[2] = w;
	local[3]= NIL;
	local[4]= local[1];
WHL1524:
	if (local[4]==NIL) goto WHX1525;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= NIL;
	local[6]= local[2];
WHL1529:
	if (local[6]==NIL) goto WHX1530;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[3];
	local[8]= fqv[28];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
	local[8]= fqv[27];
	local[9]= local[5];
	local[10]= fqv[28];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[0] = w;
	local[7]= local[3];
	local[8]= fqv[71];
	local[9]= local[5];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w!=NIL) goto OR1535;
	local[7]= local[5];
	local[8]= fqv[71];
	local[9]= local[3];
	local[10]= local[0];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	if (w!=NIL) goto OR1535;
	goto IF1533;
OR1535:
	w = T;
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1520;
	goto IF1534;
IF1533:
	local[7]= NIL;
IF1534:
	goto WHL1529;
WHX1530:
	local[7]= NIL;
BLK1531:
	w = NIL;
	goto WHL1524;
WHX1525:
	local[5]= NIL;
BLK1526:
	w = NIL;
	local[3]= w;
	goto IF1522;
IF1521:
	local[3]= NIL;
IF1522:
	w = local[3];
	local[0]= w;
BLK1520:
	ctx->vsp=local; return(local[0]);}

/*:intersectp2*/
static pointer M1536body_intersectp2(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1539;}
	local[0]= loadglobal(fqv[73]);
ENT1539:
ENT1538:
	if (n>4) maerror();
	local[1]= argv[0];
	local[2]= fqv[74];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= NIL;
	local[8]= NIL;
	local[9]= NIL;
	if (local[1]==NIL) goto IF1540;
	local[10]= argv[0];
	local[11]= fqv[72];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[2] = w;
	local[10]= argv[2];
	local[11]= fqv[72];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	local[10]= argv[0];
	local[11]= fqv[75];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[4] = w;
	local[10]= argv[2];
	local[11]= fqv[75];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[5] = w;
	local[10]= NIL;
	local[11]= local[2];
WHL1543:
	if (local[11]==NIL) goto WHX1544;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= NIL;
	local[13]= local[5];
WHL1548:
	if (local[13]==NIL) goto WHX1549;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[10];
	local[15]= fqv[76];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto CON1553;
	if (local[8]!=NIL) goto IF1554;
	local[14]= NIL;
	local[15]= local[10];
	local[16]= fqv[23];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
WHL1557:
	if (local[15]==NIL) goto WHX1558;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[77];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (!iscons(w)) goto IF1561;
	local[16]= local[10];
	local[17]= fqv[78];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= makeflt(1.0000000000000000000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[3];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1565;
	local[17]= makeflt(1.0000000000000000000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[4];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1565;
	goto IF1563;
OR1565:
	w = fqv[80];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK1537;
	goto IF1564;
IF1563:
	local[8] = fqv[81];
	w = local[8];
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK1559;
IF1564:
	w = local[17];
	local[16]= w;
	goto IF1562;
IF1561:
	local[16]= NIL;
IF1562:
	goto WHL1557;
WHX1558:
	local[16]= NIL;
BLK1559:
	w = NIL;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[12]->c.obj.iv[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto IF1566;
	local[14]= local[10];
	local[15]= fqv[78];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[3];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1570;
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[4];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1570;
	goto IF1568;
OR1570:
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1537;
	goto IF1569;
IF1568:
	local[8] = fqv[81];
	local[15]= local[8];
IF1569:
	w = local[15];
	local[14]= w;
	goto IF1567;
IF1566:
	local[14]= NIL;
IF1567:
	goto IF1555;
IF1554:
	local[14]= NIL;
IF1555:
	goto CON1552;
CON1553:
	local[14]= local[10];
	local[15]= fqv[27];
	local[16]= local[12]->c.obj.iv[1];
	local[17]= local[12]->c.obj.iv[2];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[6] = w;
	local[14]= local[6];
	if (loadglobal(fqv[83])==local[14]) goto IF1572;
	local[14]= makeflt(0.0000000000000000000000e+00);
	local[15]= local[6];
	local[16]= makeflt(1.0000000000000000000000e+00);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,4,local+14,&ftab[11],fqv[84]); /*eps-in-range*/
	if (w==NIL) goto IF1572;
	local[14]= local[12];
	local[15]= fqv[85];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[7] = w;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[9] = w;
	local[14]= local[6];
	local[15]= makeflt(0.0000000000000000000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1576;
	local[14]= local[6];
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1576;
	goto CON1575;
OR1576:
	local[14]= local[9];
	local[15]= fqv[86];
	ctx->vsp=local+16;
	w=(*ftab[4])(ctx,2,local+14,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1575;
	local[8] = fqv[81];
	local[14]= local[8];
	goto CON1574;
CON1575:
	local[14]= local[9];
	local[15]= local[14];
	if (fqv[44]!=local[15]) goto IF1579;
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1537;
	goto IF1580;
IF1579:
	local[15]= local[14];
	if (fqv[87]!=local[15]) goto IF1581;
	local[8] = fqv[81];
	local[15]= local[8];
	goto IF1582;
IF1581:
	local[15]= NIL;
IF1582:
IF1580:
	w = local[15];
	local[14]= w;
	goto CON1574;
CON1577:
	local[14]= NIL;
CON1574:
	goto IF1573;
IF1572:
	local[14]= NIL;
IF1573:
	goto CON1552;
CON1571:
	local[14]= NIL;
CON1552:
	goto WHL1548;
WHX1549:
	local[14]= NIL;
BLK1550:
	w = NIL;
	goto WHL1543;
WHX1544:
	local[12]= NIL;
BLK1545:
	w = NIL;
	local[10]= NIL;
	local[11]= local[3];
WHL1584:
	if (local[11]==NIL) goto WHX1585;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[12]= (w)->c.cons.car;
	w=local[11];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11] = (w)->c.cons.cdr;
	w = local[12];
	local[10] = w;
	local[12]= NIL;
	local[13]= local[5];
WHL1589:
	if (local[13]==NIL) goto WHX1590;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[14]= (w)->c.cons.car;
	w=local[13];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13] = (w)->c.cons.cdr;
	w = local[14];
	local[12] = w;
	local[14]= local[10];
	local[15]= fqv[76];
	local[16]= local[12];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto CON1594;
	if (local[8]!=NIL) goto IF1595;
	local[14]= NIL;
	local[15]= local[10];
	local[16]= fqv[23];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,2,local+15); /*send*/
	local[15]= w;
WHL1598:
	if (local[15]==NIL) goto WHX1599;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[16]= (w)->c.cons.car;
	w=local[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15] = (w)->c.cons.cdr;
	w = local[16];
	local[14] = w;
	local[16]= local[14];
	local[17]= fqv[77];
	local[18]= local[12];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,3,local+16); /*send*/
	if (!iscons(w)) goto IF1602;
	local[16]= local[10];
	local[17]= fqv[78];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,2,local+16); /*send*/
	local[16]= w;
	local[17]= makeflt(1.0000000000000000000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[3];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1606;
	local[17]= makeflt(1.0000000000000000000000e+00);
	local[18]= local[16];
	local[19]= local[12]->c.obj.iv[4];
	local[20]= fqv[78];
	ctx->vsp=local+21;
	w=(pointer)SEND(ctx,2,local+19); /*send*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)VINNERPRODUCT(ctx,2,local+18); /*v.*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(*ftab[10])(ctx,2,local+17,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1606;
	goto IF1604;
OR1606:
	w = fqv[80];
	ctx->vsp=local+17;
	local[0]=w;
	goto BLK1537;
	goto IF1605;
IF1604:
	local[8] = fqv[81];
	w = local[8];
	ctx->vsp=local+17;
	local[16]=w;
	goto BLK1600;
IF1605:
	w = local[17];
	local[16]= w;
	goto IF1603;
IF1602:
	local[16]= NIL;
IF1603:
	goto WHL1598;
WHX1599:
	local[16]= NIL;
BLK1600:
	w = NIL;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[12]->c.obj.iv[1];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	if (w==NIL) goto IF1607;
	local[14]= local[10];
	local[15]= fqv[78];
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,2,local+14); /*send*/
	local[14]= w;
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[3];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1611;
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[14];
	local[17]= local[12]->c.obj.iv[4];
	local[18]= fqv[78];
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,2,local+17); /*send*/
	local[17]= w;
	ctx->vsp=local+18;
	w=(pointer)VINNERPRODUCT(ctx,2,local+16); /*v.*/
	local[16]= w;
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,2,local+15,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1611;
	goto IF1609;
OR1611:
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1537;
	goto IF1610;
IF1609:
	local[8] = fqv[81];
	local[15]= local[8];
IF1610:
	w = local[15];
	local[14]= w;
	goto IF1608;
IF1607:
	local[14]= NIL;
IF1608:
	goto IF1596;
IF1595:
	local[14]= NIL;
IF1596:
	goto CON1593;
CON1594:
	local[14]= local[10];
	local[15]= fqv[27];
	local[16]= local[12]->c.obj.iv[1];
	local[17]= local[12]->c.obj.iv[2];
	ctx->vsp=local+18;
	w=(pointer)SEND(ctx,4,local+14); /*send*/
	local[6] = w;
	local[14]= local[6];
	if (loadglobal(fqv[83])==local[14]) goto IF1613;
	local[14]= makeflt(0.0000000000000000000000e+00);
	local[15]= local[6];
	local[16]= makeflt(1.0000000000000000000000e+00);
	local[17]= local[0];
	ctx->vsp=local+18;
	w=(*ftab[11])(ctx,4,local+14,&ftab[11],fqv[84]); /*eps-in-range*/
	if (w==NIL) goto IF1613;
	local[14]= local[12];
	local[15]= fqv[85];
	local[16]= local[6];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[7] = w;
	local[14]= local[10];
	local[15]= fqv[82];
	local[16]= local[7];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,3,local+14); /*send*/
	local[9] = w;
	local[14]= local[6];
	local[15]= makeflt(0.0000000000000000000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1617;
	local[14]= local[6];
	local[15]= makeflt(1.0000000000000000000000e+00);
	local[16]= local[0];
	ctx->vsp=local+17;
	w=(*ftab[10])(ctx,3,local+14,&ftab[10],fqv[79]); /*eps=*/
	if (w!=NIL) goto OR1617;
	goto CON1616;
OR1617:
	local[14]= local[9];
	local[15]= fqv[88];
	ctx->vsp=local+16;
	w=(*ftab[4])(ctx,2,local+14,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto CON1616;
	local[8] = fqv[81];
	local[14]= local[8];
	goto CON1615;
CON1616:
	local[14]= local[9];
	local[15]= local[14];
	if (fqv[44]!=local[15]) goto IF1620;
	w = fqv[80];
	ctx->vsp=local+15;
	local[0]=w;
	goto BLK1537;
	goto IF1621;
IF1620:
	local[15]= local[14];
	if (fqv[87]!=local[15]) goto IF1622;
	local[8] = fqv[81];
	local[15]= local[8];
	goto IF1623;
IF1622:
	local[15]= NIL;
IF1623:
IF1621:
	w = local[15];
	local[14]= w;
	goto CON1615;
CON1618:
	local[14]= NIL;
CON1615:
	goto IF1614;
IF1613:
	local[14]= NIL;
IF1614:
	goto CON1593;
CON1612:
	local[14]= NIL;
CON1593:
	goto WHL1589;
WHX1590:
	local[14]= NIL;
BLK1591:
	w = NIL;
	goto WHL1584;
WHX1585:
	local[12]= NIL;
BLK1586:
	w = NIL;
	local[10]= local[8];
	goto IF1541;
IF1540:
	local[10]= NIL;
IF1541:
	w = local[10];
	local[0]= w;
BLK1537:
	ctx->vsp=local; return(local[0]);}

/*:insidep*/
static pointer M1624body_insidep(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<3) maerror();
	if (n>=4) { local[0]=(argv[3]); goto ENT1627;}
	local[0]= loadglobal(fqv[89]);
ENT1627:
ENT1626:
	if (n>4) maerror();
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF1628;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= fqv[90];
	local[3]= argv[2];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	if (w!=NIL) goto IF1628;
	w = fqv[91];
	ctx->vsp=local+1;
	local[0]=w;
	goto BLK1625;
	goto IF1629;
IF1628:
	local[1]= NIL;
IF1629:
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	if (argv[0]->c.obj.iv[13]==NIL) goto CON1631;
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1633:
	if (local[6]==NIL) goto WHX1634;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[92];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[1] = w;
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto CON1638;
	local[7]= local[5];
	local[8]= fqv[82];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[3] = w;
	local[7]= local[3];
	if (fqv[91]!=local[7]) goto IF1639;
	w = fqv[91];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1625;
	goto IF1640;
IF1639:
	w = fqv[87];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1625;
IF1640:
	goto CON1637;
CON1638:
	local[7]= local[1];
	local[8]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+9;
	w=(pointer)GREATERP(ctx,2,local+7); /*>*/
	if (w==NIL) goto CON1641;
	w = fqv[91];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1625;
	goto CON1637;
CON1641:
	local[7]= NIL;
CON1637:
	goto WHL1633;
WHX1634:
	local[7]= NIL;
BLK1635:
	w = NIL;
	local[5]= fqv[44];
	goto CON1630;
CON1631:
	local[3] = NIL;
WHL1643:
	if (local[3]!=NIL) goto WHX1644;
	ctx->vsp=local+5;
	w=(*ftab[12])(ctx,0,local+5,&ftab[12],fqv[93]); /*random-normalized-vector*/
	local[2] = w;
	local[4] = makeint((eusinteger_t)0L);
	local[5]= NIL;
	local[6]= argv[0]->c.obj.iv[9];
WHL1647:
	if (local[6]==NIL) goto WHX1648;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	w=local[6];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.cdr;
	w = local[7];
	local[5] = w;
	local[7]= local[5];
	local[8]= fqv[92];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)ABS(ctx,1,local+7); /*abs*/
	local[7]= w;
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)LESSP(ctx,2,local+7); /*<*/
	if (w==NIL) goto IF1651;
	local[7]= local[5];
	local[8]= fqv[82];
	local[9]= argv[2];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,3,local+7); /*send*/
	local[7]= w;
	if (fqv[91]==local[7]) goto IF1651;
	w = fqv[87];
	ctx->vsp=local+7;
	local[0]=w;
	goto BLK1625;
	goto IF1652;
IF1651:
	local[7]= NIL;
IF1652:
	local[7]= local[5];
	local[8]= fqv[43];
	local[9]= argv[2];
	local[10]= local[2];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,4,local+7); /*send*/
	local[3] = w;
	w=local[3];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7]= (w)->c.cons.car;
	local[8]= local[7];
	if (fqv[44]!=local[8]) goto IF1654;
	local[8]= local[4];
	ctx->vsp=local+9;
	w=(pointer)ADD1(ctx,1,local+8); /*1+*/
	local[4] = w;
	local[8]= local[4];
	goto IF1655;
IF1654:
	local[8]= local[7];
	if (fqv[91]!=local[8]) goto IF1656;
	local[8]= NIL;
	goto IF1657;
IF1656:
	if (T==NIL) goto IF1658;
	local[3] = NIL;
	w = NIL;
	ctx->vsp=local+8;
	local[7]=w;
	goto BLK1649;
	goto IF1659;
IF1658:
	local[8]= NIL;
IF1659:
IF1657:
IF1655:
	w = local[8];
	goto WHL1647;
WHX1648:
	local[7]= NIL;
BLK1649:
	w = NIL;
	goto WHL1643;
WHX1644:
	local[5]= NIL;
BLK1645:
	if (argv[0]->c.obj.iv[14]!=NIL) goto IF1660;
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,1,local+5,&ftab[13],fqv[94]); /*oddp*/
	if (w==NIL) goto IF1662;
	local[5]= fqv[44];
	goto IF1663;
IF1662:
	local[5]= fqv[91];
IF1663:
	goto IF1661;
IF1660:
	local[5]= local[4];
	ctx->vsp=local+6;
	w=(*ftab[13])(ctx,1,local+5,&ftab[13],fqv[94]); /*oddp*/
	if (w==NIL) goto IF1664;
	local[5]= fqv[91];
	goto IF1665;
IF1664:
	local[5]= fqv[44];
IF1665:
IF1661:
	goto CON1630;
CON1642:
	local[5]= NIL;
CON1630:
	w = local[5];
	local[0]= w;
BLK1625:
	ctx->vsp=local; return(local[0]);}

/*:evert*/
static pointer M1666body_evert(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	local[0]= argv[0]->c.obj.iv[10];
	local[1]= fqv[95];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	argv[0]->c.obj.iv[14] = ((argv[0]->c.obj.iv[14])==NIL?T:NIL);
	if (argv[0]->c.obj.iv[14]==NIL) goto CON1669;
	local[0]= loadglobal(fqv[54]);
	ctx->vsp=local+1;
	w=(pointer)INSTANTIATE(ctx,1,local+0); /*instantiate*/
	local[0]= w;
	local[1]= local[0];
	local[2]= fqv[96];
	local[3]= makeflt(-1.0000000000000000000000e+10);
	local[4]= makeflt(-1.0000000000000000000000e+10);
	local[5]= makeflt(-1.0000000000000000000000e+10);
	ctx->vsp=local+6;
	w=(pointer)MKFLTVEC(ctx,3,local+3); /*float-vector*/
	local[3]= w;
	local[4]= makeflt(1.0000000000000000000000e+10);
	local[5]= makeflt(1.0000000000000000000000e+10);
	local[6]= makeflt(1.0000000000000000000000e+10);
	ctx->vsp=local+7;
	w=(pointer)MKFLTVEC(ctx,3,local+4); /*float-vector*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,4,local+1); /*send*/
	w = local[0];
	argv[0]->c.obj.iv[8] = w;
	argv[0]->c.obj.iv[13] = NIL;
	local[0]= argv[0]->c.obj.iv[13];
	goto CON1668;
CON1669:
	local[0]= argv[0];
	local[1]= fqv[97];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= argv[0];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	goto CON1668;
CON1671:
	local[0]= NIL;
CON1668:
	w = argv[0]->c.obj.iv[14];
	local[0]= w;
BLK1667:
	ctx->vsp=local; return(local[0]);}

/*:set-convexp*/
static pointer M1672body_set_convexp(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1676,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	local[2]= fqv[99];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,2,local+1,&ftab[1],fqv[15]); /*send-all*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(*ftab[14])(ctx,2,local+0,&ftab[14],fqv[100]); /*every*/
	if (w==NIL) goto IF1674;
	argv[0]->c.obj.iv[13] = T;
	local[0]= argv[0]->c.obj.iv[13];
	goto IF1675;
IF1674:
	local[0]= NIL;
IF1675:
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[98];
	ctx->vsp=local+2;
	w=(*ftab[1])(ctx,2,local+0,&ftab[1],fqv[15]); /*send-all*/
	w = argv[0];
	local[0]= w;
BLK1673:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1505(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1677;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1678;
IF1677:
	local[0]= NIL;
IF1678:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1508(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1679;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1680;
IF1679:
	local[0]= NIL;
IF1680:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1676(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+2;
	w=(pointer)GREQP(ctx,2,local+0); /*>=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:get-face*/
static pointer M1681body_get_face(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1686;}
	local[0]= NIL;
ENT1686:
	if (n>=4) { local[1]=(argv[3]); goto ENT1685;}
	local[1]= NIL;
ENT1685:
	if (n>=5) { local[2]=(argv[4]); goto ENT1684;}
	local[2]= NIL;
ENT1684:
ENT1683:
	if (n>5) maerror();
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[15])(ctx,1,local+7,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1688;
	local[7]= NIL;
	local[8]= argv[0]->c.obj.iv[9];
WHL1690:
	if (local[8]==NIL) goto WHX1691;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[103];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	if (local[0]!=local[9]) goto IF1694;
	local[9]= local[7];
	w = local[3];
	ctx->vsp=local+10;
	local[3] = cons(ctx,local[9],w);
	local[9]= local[3];
	goto IF1695;
IF1694:
	local[9]= NIL;
IF1695:
	goto WHL1690;
WHX1691:
	local[9]= NIL;
BLK1692:
	w = NIL;
	local[7]= w;
	goto CON1687;
CON1688:
	local[7]= local[0];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[104]); /*keywordp*/
	if (w==NIL) goto CON1696;
	local[7]= NIL;
	local[8]= argv[0]->c.obj.iv[9];
WHL1698:
	if (local[8]==NIL) goto WHX1699;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[105];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (local[0]!=local[9]) goto IF1702;
	local[9]= local[7];
	w = local[3];
	ctx->vsp=local+10;
	local[3] = cons(ctx,local[9],w);
	local[9]= local[3];
	goto IF1703;
IF1702:
	local[9]= NIL;
IF1703:
	goto WHL1698;
WHX1699:
	local[9]= NIL;
BLK1700:
	w = NIL;
	local[7]= w;
	goto CON1687;
CON1696:
	local[7]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+8;
	w=(pointer)COPYSEQ(ctx,1,local+7); /*copy-seq*/
	local[3] = w;
	local[7]= local[3];
	goto CON1687;
CON1704:
	local[7]= NIL;
CON1687:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[17])(ctx,1,local+7,&ftab[17],fqv[106]); /*facep*/
	if (w==NIL) goto CON1706;
	local[7]= NIL;
	local[8]= local[3];
WHL1708:
	if (local[8]==NIL) goto WHX1709;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[107];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
	if (local[1]!=local[9]) goto IF1712;
	local[9]= local[7];
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	local[9]= local[4];
	goto IF1713;
IF1712:
	local[9]= NIL;
IF1713:
	goto WHL1708;
WHX1709:
	local[9]= NIL;
BLK1710:
	w = NIL;
	local[7]= w;
	goto CON1705;
CON1706:
	local[7]= local[1];
	ctx->vsp=local+8;
	w=(*ftab[16])(ctx,1,local+7,&ftab[16],fqv[104]); /*keywordp*/
	if (w==NIL) goto CON1714;
	local[7]= NIL;
	local[8]= local[3];
WHL1716:
	if (local[8]==NIL) goto WHX1717;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[108];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6] = (w)->c.cons.car;
	local[9]= local[6];
	if (local[1]==local[9]) goto OR1722;
	local[9]= local[1];
	if (fqv[109]!=local[9]) goto AND1723;
	local[9]= local[6];
	local[10]= fqv[110];
	ctx->vsp=local+11;
	w=(*ftab[4])(ctx,2,local+9,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto AND1723;
	goto OR1722;
AND1723:
	goto IF1720;
OR1722:
	local[9]= local[7];
	w = local[4];
	ctx->vsp=local+10;
	local[4] = cons(ctx,local[9],w);
	local[9]= local[4];
	goto IF1721;
IF1720:
	local[9]= NIL;
IF1721:
	goto WHL1716;
WHX1717:
	local[9]= NIL;
BLK1718:
	w = NIL;
	local[7]= w;
	goto CON1705;
CON1714:
	local[4] = local[3];
	local[7]= local[4];
	goto CON1705;
CON1724:
	local[7]= NIL;
CON1705:
	if (local[2]==NIL) goto CON1726;
	local[7]= NIL;
	local[8]= local[4];
WHL1728:
	if (local[8]==NIL) goto WHX1729;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	w=local[8];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8] = (w)->c.cons.cdr;
	w = local[9];
	local[7] = w;
	local[9]= local[7];
	local[10]= fqv[108];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.car;
	if (local[2]!=local[9]) goto IF1732;
	local[9]= local[7];
	w = local[5];
	ctx->vsp=local+10;
	local[5] = cons(ctx,local[9],w);
	local[9]= local[5];
	goto IF1733;
IF1732:
	local[9]= NIL;
IF1733:
	goto WHL1728;
WHX1729:
	local[9]= NIL;
BLK1730:
	w = NIL;
	local[7]= local[5];
	goto CON1725;
CON1726:
	local[7]= local[4];
	goto CON1725;
CON1734:
	local[7]= NIL;
CON1725:
	w = local[7];
	local[0]= w;
BLK1682:
	ctx->vsp=local; return(local[0]);}

/*:primitive-body-p*/
static pointer M1735body_primitive_body_p(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.car;
	local[0]= (iscons(w)?T:NIL);
	if (local[0]==NIL) goto AND1737;
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.car;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	w=(*ftab[16])(ctx,1,local+0,&ftab[16],fqv[104]); /*keywordp*/
	local[0]= w;
AND1737:
	w = local[0];
	local[0]= w;
BLK1736:
	ctx->vsp=local; return(local[0]);}

/*:primitive-bodies*/
static pointer M1738body_primitive_bodies(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1742;}
	local[0]= NIL;
ENT1742:
	if (n>=4) { local[1]=(argv[3]); goto ENT1741;}
	local[1]= NIL;
ENT1741:
ENT1740:
	if (n>4) maerror();
	ctx->vsp=local+2;
	local[2]= makeclosure(codevec,quotevec,FLET1743,env,argv,local);
	local[3]= NIL;
	local[4]= local[0];
	local[5]= local[4];
	if (fqv[111]!=local[5]) goto IF1745;
	local[5]= argv[0];
	local[6]= fqv[112];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= local[3];
	goto IF1746;
IF1745:
	local[5]= local[4];
	if (fqv[113]!=local[5]) goto IF1747;
	local[5]= argv[0];
	local[6]= fqv[112];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.car;
	local[5]= local[3];
	goto IF1748;
IF1747:
	if (T==NIL) goto IF1749;
	local[5]= argv[0];
	w = local[2];
	ctx->vsp=local+6;
	w=FLET1743(ctx,1,local+5,w);
	local[3] = w;
	local[5]= local[3];
	goto IF1750;
IF1749:
	local[5]= NIL;
IF1750:
IF1748:
IF1746:
	w = local[5];
	if (local[1]==NIL) goto CON1752;
	ctx->vsp=local+4;
	local[4]= makeclosure(codevec,quotevec,CLO1753,env,argv,local);
	local[5]= local[3];
	ctx->vsp=local+6;
	w=(*ftab[18])(ctx,2,local+4,&ftab[18],fqv[114]); /*collect-if*/
	local[4]= w;
	goto CON1751;
CON1752:
	local[4]= local[3];
	goto CON1751;
CON1754:
	local[4]= NIL;
CON1751:
	w = local[4];
	local[0]= w;
BLK1739:
	ctx->vsp=local; return(local[0]);}

/*:csg*/
static pointer M1755body_csg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1758;}
	local[0]= NIL;
ENT1758:
ENT1757:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1759;
	argv[0]->c.obj.iv[15] = local[0];
	local[1]= argv[0]->c.obj.iv[15];
	goto IF1760;
IF1759:
	local[1]= argv[0]->c.obj.iv[15];
IF1760:
	w = local[1];
	local[0]= w;
BLK1756:
	ctx->vsp=local; return(local[0]);}

/*:copy-csg*/
static pointer M1761body_copy_csg(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1763,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[115];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1764;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1763(ctx,1,local+1,w);
	local[1]= w;
	goto IF1765;
IF1764:
	local[1]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1763(ctx,1,local+1,w);
	local[1]= w;
IF1765:
	w = local[1];
	local[0]= w;
BLK1762:
	ctx->vsp=local; return(local[0]);}

/*:body-type*/
static pointer M1766body_body_type(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	local[1]= fqv[116];
	ctx->vsp=local+2;
	w=(*ftab[4])(ctx,2,local+0,&ftab[4],fqv[26]); /*member*/
	if (w==NIL) goto IF1768;
	local[0]= fqv[117];
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto IF1769;
IF1768:
	w=argv[0]->c.obj.iv[15];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
IF1769:
	w = local[0];
	local[0]= w;
BLK1767:
	ctx->vsp=local; return(local[0]);}

/*:creation-form*/
static pointer M1770body_creation_form(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1772,env,argv,local);
	local[1]= argv[0];
	local[2]= fqv[115];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (w==NIL) goto IF1773;
	local[1]= argv[0];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1772(ctx,1,local+1,w);
	local[1]= w;
	goto IF1774;
IF1773:
	local[1]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+2;
	w=FLET1772(ctx,1,local+1,w);
	local[1]= w;
IF1774:
	w = local[1];
	local[0]= w;
BLK1771:
	ctx->vsp=local; return(local[0]);}

/*:prin1*/
static pointer M1775body_prin1(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= *(ovafptr(argv[1],fqv[53]));
	local[2]= fqv[118];
	local[3]= argv[2];
	local[4]= argv[0];
	local[5]= fqv[119];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,5,local+0); /*send-message*/
	local[0]= w;
BLK1776:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1777body_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1779:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	ctx->vsp=local+1;
	n=parsekeyparams(fqv[120], &argv[2], n-2, local+1, 1);
	if (n & (1<<0)) goto KEY1780;
	local[1] = NIL;
KEY1780:
	if (n & (1<<1)) goto KEY1781;
	local[2] = NIL;
KEY1781:
	if (n & (1<<2)) goto KEY1782;
	local[3] = NIL;
KEY1782:
	local[4]= (pointer)get_sym_func(fqv[52]);
	local[5]= argv[0];
	local[6]= *(ovafptr(argv[1],fqv[53]));
	local[7]= fqv[32];
	local[8]= local[0];
	ctx->vsp=local+9;
	w=(pointer)APPLY(ctx,5,local+4); /*apply*/
	local[4]= argv[0]->c.obj.iv[10];
	local[5]= fqv[121];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,2,local+4,&ftab[1],fqv[15]); /*send-all*/
	if (local[1]==NIL) goto IF1783;
	local[4]= argv[0]->c.obj.iv[10];
	local[5]= fqv[122];
	ctx->vsp=local+6;
	w=(*ftab[1])(ctx,2,local+4,&ftab[1],fqv[15]); /*send-all*/
	local[4]= w;
	goto IF1784;
IF1783:
	local[4]= NIL;
IF1784:
	local[4]= (pointer)get_sym_func(fqv[123]);
	local[5]= argv[0]->c.obj.iv[10];
	local[6]= fqv[99];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,2,local+5,&ftab[1],fqv[15]); /*send-all*/
	local[5]= w;
	ctx->vsp=local+6;
	w=(*ftab[14])(ctx,2,local+4,&ftab[14],fqv[100]); /*every*/
	if (w==NIL) goto IF1785;
	argv[0]->c.obj.iv[13] = T;
	local[4]= argv[0]->c.obj.iv[13];
	goto IF1786;
IF1785:
	local[4]= NIL;
IF1786:
	if (argv[0]->c.obj.iv[11]==NIL) goto IF1787;
	if (argv[0]->c.obj.iv[9]==NIL) goto IF1787;
	local[4]= argv[0];
	local[5]= argv[0];
	local[6]= fqv[63];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[63];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= argv[0];
	local[5]= argv[0];
	local[6]= fqv[62];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
	local[6]= fqv[62];
	ctx->vsp=local+7;
	w=(pointer)PUTPROP(ctx,3,local+4); /*putprop*/
	local[4]= w;
	goto IF1788;
IF1787:
	local[4]= NIL;
IF1788:
	if (local[2]==NIL) goto IF1789;
	local[4]= argv[0]->c.obj.iv[9];
	local[5]= fqv[124];
	local[6]= argv[0];
	ctx->vsp=local+7;
	w=(*ftab[1])(ctx,3,local+4,&ftab[1],fqv[15]); /*send-all*/
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)LIST(ctx,1,local+4); /*list*/
	argv[0]->c.obj.iv[15] = w;
	local[4]= argv[0]->c.obj.iv[15];
	goto IF1790;
IF1789:
	local[4]= NIL;
IF1790:
	w = argv[0];
	local[0]= w;
BLK1778:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1743(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[125]); /*primitive-body-p*/
	if (w==NIL) goto CON1792;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON1791;
CON1792:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1793;
	local[0]= env->c.clo.env2[2];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)LISTP(ctx,1,local+1); /*listp*/
	if (w==NIL) goto CON1795;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON1794;
CON1795:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	goto CON1794;
CON1796:
	local[1]= NIL;
CON1794:
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1791;
CON1793:
	local[0]= env->c.clo.env2[2];
	local[1]= argv[0];
	local[2]= fqv[126];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1791;
CON1797:
	local[0]= NIL;
CON1791:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1753(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[119];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	w = env->c.clo.env2[1];
	if (!iscons(w)) goto IF1798;
	local[2]= local[1];
	local[3]= env->c.clo.env2[1];
	ctx->vsp=local+4;
	w=(*ftab[4])(ctx,2,local+2,&ftab[4],fqv[26]); /*member*/
	local[2]= w;
	goto IF1799;
IF1798:
	local[2]= env->c.clo.env2[1];
	local[3]= local[1];
	ctx->vsp=local+4;
	w=(pointer)EQ(ctx,2,local+2); /*eql*/
	local[2]= w;
IF1799:
	w = local[2];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1763(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1801;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,CLO1802,env,argv,local);
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST(ctx,2,local+0); /*list*/
	local[0]= w;
	goto CON1800;
CON1801:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[15])(ctx,1,local+0,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1803;
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= argv[0];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	local[4]= fqv[127];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[1] = w;
	if (local[1]==NIL) goto IF1804;
	local[3]= local[1];
	local[4]= fqv[128];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1805;
IF1804:
	local[3]= NIL;
IF1805:
	local[3]= argv[0];
	local[4]= fqv[129];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[2] = w;
	local[3]= argv[0];
	local[4]= fqv[130];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= argv[0];
	ctx->vsp=local+4;
	w=(pointer)COPYOBJ(ctx,1,local+3); /*copy-object*/
	local[0] = w;
	if (local[1]==NIL) goto IF1806;
	local[3]= local[1];
	local[4]= fqv[131];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	goto IF1807;
IF1806:
	local[3]= NIL;
IF1807:
	local[3]= NIL;
	local[4]= local[2];
WHL1809:
	if (local[4]==NIL) goto WHX1810;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= argv[0];
	local[6]= fqv[131];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL1809;
WHX1810:
	local[5]= NIL;
BLK1811:
	w = NIL;
	local[3]= local[0];
	local[4]= fqv[65];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= NIL;
	local[4]= local[0]->c.obj.iv[9];
WHL1814:
	if (local[4]==NIL) goto WHX1815;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4] = (w)->c.cons.cdr;
	w = local[5];
	local[3] = w;
	local[5]= local[3];
	local[6]= fqv[107];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)SEND(ctx,3,local+5); /*send*/
	goto WHL1814;
WHX1815:
	local[5]= NIL;
BLK1816:
	w = NIL;
	local[3]= local[0];
	local[4]= argv[0];
	local[5]= fqv[132];
	ctx->vsp=local+6;
	w=(pointer)PUTPROP(ctx,3,local+3); /*putprop*/
	w = local[0];
	local[0]= w;
	goto CON1800;
CON1803:
	local[0]= NIL;
CON1800:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1802(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	w = env->c.clo.env0->c.clo.env2[0];
	ctx->vsp=local+1;
	w=FLET1763(ctx,1,local+0,w);
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1772(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1819;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1821;
	local[0]= fqv[133];
	local[1]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST_STAR(ctx,2,local+0); /*list**/
	local[0]= w;
	goto CON1820;
CON1821:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1822;
	local[0]= fqv[135];
	local[1]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	ctx->vsp=local+3;
	w=(pointer)MAPCAR(ctx,2,local+1); /*mapcar*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)LIST_STAR(ctx,2,local+0); /*list**/
	local[0]= w;
	goto CON1820;
CON1822:
	local[0]= NIL;
CON1820:
	goto CON1818;
CON1819:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[15])(ctx,1,local+0,&ftab[15],fqv[102]); /*bodyp*/
	if (w==NIL) goto CON1823;
	local[0]= argv[0];
	local[1]= fqv[126];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	local[2]= local[1];
	if (fqv[136]!=local[2]) goto IF1825;
	local[2]= fqv[137];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w = (w)->c.cons.cdr;
	ctx->vsp=local+3;
	local[2]= cons(ctx,local[2],w);
	goto IF1826;
IF1825:
	local[2]= local[1];
	if (fqv[138]!=local[2]) goto IF1827;
	local[2]= fqv[139];
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3]= (w)->c.cons.car;
	w=local[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[4]= (w)->c.cons.car;
	local[5]= fqv[140];
	local[6]= local[0];
	ctx->vsp=local+7;
	w=(*ftab[20])(ctx,1,local+6,&ftab[20],fqv[141]); /*cdddr*/
	local[6]= w;
	ctx->vsp=local+7;
	w=(pointer)LIST_STAR(ctx,5,local+2); /*list**/
	local[2]= w;
	goto IF1828;
IF1827:
	if (T==NIL) goto IF1829;
	local[2]= fqv[142];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SIGERROR(ctx,2,local+2); /*error*/
	local[2]= w;
	goto IF1830;
IF1829:
	local[2]= NIL;
IF1830:
IF1828:
IF1826:
	w = local[2];
	local[0] = w;
	local[1]= local[0];
	local[2]= fqv[3];
	local[3]= argv[0];
	local[4]= fqv[3];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)APPEND(ctx,2,local+1); /*append*/
	local[1]= fqv[8];
	local[2]= local[0];
	local[3]= fqv[143];
	local[4]= argv[0];
	local[5]= fqv[65];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	local[5]= fqv[144];
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
	goto CON1818;
CON1823:
	local[0]= NIL;
CON1818:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:replace-shape*/
static pointer M1831body_replace_shape(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[0]->c.obj.iv[4];
WHL1834:
	if (local[1]==NIL) goto WHX1835;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= fqv[132];
	ctx->vsp=local+4;
	w=(pointer)GETPROP(ctx,2,local+2); /*get*/
	if (w==NIL) goto IF1838;
	local[2]= argv[0];
	local[3]= fqv[128];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	goto IF1839;
IF1838:
	local[2]= NIL;
IF1839:
	goto WHL1834;
WHX1835:
	local[2]= NIL;
BLK1836:
	w = NIL;
	argv[0]->c.obj.iv[9] = argv[2]->c.obj.iv[9];
	argv[0]->c.obj.iv[10] = argv[2]->c.obj.iv[10];
	argv[0]->c.obj.iv[11] = argv[2]->c.obj.iv[11];
	argv[0]->c.obj.iv[12] = argv[2]->c.obj.iv[12];
	argv[0]->c.obj.iv[8] = argv[2]->c.obj.iv[8];
	argv[0]->c.obj.iv[13] = argv[2]->c.obj.iv[13];
	argv[0]->c.obj.iv[15] = argv[2]->c.obj.iv[15];
	local[0]= argv[0];
	local[1]= NIL;
	local[2]= fqv[6];
	ctx->vsp=local+3;
	w=(pointer)PUTPROP(ctx,3,local+0); /*putprop*/
	local[0]= argv[0];
	local[1]= fqv[65];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= fqv[145];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[12];
WHL1840:
	if (local[1]==NIL) goto WHX1841;
	local[2]= local[1];
	local[3]= local[0];
	local[4]= fqv[66];
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5]= (w)->c.cons.car;
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)RPLACA2(ctx,2,local+2); /*rplaca2*/
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	goto WHL1840;
WHX1841:
	local[2]= NIL;
BLK1842:
	w = local[2];
	local[0]= argv[0]->c.obj.iv[9];
	local[1]= fqv[124];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[1])(ctx,3,local+0,&ftab[1],fqv[15]); /*send-all*/
	local[0]= NIL;
	local[1]= argv[0];
	local[2]= fqv[146];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL1844:
	if (local[1]==NIL) goto WHX1845;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= argv[0];
	local[3]= fqv[131];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	goto WHL1844;
WHX1845:
	local[2]= NIL;
BLK1846:
	w = NIL;
	w = argv[0];
	local[0]= w;
BLK1832:
	ctx->vsp=local; return(local[0]);}

/*:+*/
static pointer M1848body__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1850:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[133]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1849:
	ctx->vsp=local; return(local[0]);}

/*:-*/
static pointer M1851body__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1853:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[135]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1852:
	ctx->vsp=local; return(local[0]);}

/*:**/
static pointer M1854body__(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
RST1856:
	ctx->vsp=local+0;
	local[0]= minilist(ctx,&argv[n],n-2);
	local[1]= argv[0];
	local[2]= fqv[147];
	local[3]= (pointer)get_sym_func(fqv[148]);
	local[4]= argv[0];
	local[5]= local[0];
	ctx->vsp=local+6;
	w=(pointer)APPLY(ctx,3,local+3); /*apply*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[0]= w;
BLK1855:
	ctx->vsp=local; return(local[0]);}

/*:primitive-groups*/
static pointer M1857body_primitive_groups(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,FLET1859,env,argv,local);
	ctx->vsp=local+1;
	local[1]= makeclosure(codevec,quotevec,FLET1860,env,argv,local);
	local[2]= argv[0];
	local[3]= fqv[115];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	if (w==NIL) goto IF1861;
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)LIST(ctx,1,local+2); /*list*/
	local[2]= w;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
	goto IF1862;
IF1861:
	local[2]= argv[0]->c.obj.iv[15];
	w = local[0];
	ctx->vsp=local+3;
	w=FLET1859(ctx,1,local+2,w);
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[15];
	w = local[1];
	ctx->vsp=local+4;
	w=FLET1860(ctx,1,local+3,w);
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)LIST(ctx,2,local+2); /*list*/
	local[2]= w;
IF1862:
	w = local[2];
	local[0]= w;
BLK1858:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1859(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto CON1864;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1866;
	local[0]= env->c.clo.env2[0];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1865;
CON1866:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1867;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[21])(ctx,1,local+0,&ftab[21],fqv[149]); /*caadr*/
	local[0]= w;
	w = env->c.clo.env2[0];
	ctx->vsp=local+1;
	w=FLET1859(ctx,1,local+0,w);
	local[0]= w;
	local[1]= env->c.clo.env2[1];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[150]); /*cdadr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON1865;
CON1867:
	local[0]= NIL;
CON1865:
	goto CON1863;
CON1864:
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[19])(ctx,1,local+0,&ftab[19],fqv[125]); /*primitive-body-p*/
	if (w==NIL) goto CON1868;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto CON1863;
CON1868:
	local[0]= NIL;
CON1863:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer FLET1860(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LISTP(ctx,1,local+0); /*listp*/
	if (w==NIL) goto IF1869;
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[59]!=local[0]) goto CON1872;
	local[0]= env->c.clo.env2[1];
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	w=(w)->c.cons.cdr;
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1]= (w)->c.cons.car;
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
	goto CON1871;
CON1872:
	w=argv[0];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[0]= (w)->c.cons.car;
	if (fqv[134]!=local[0]) goto CON1873;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(*ftab[21])(ctx,1,local+0,&ftab[21],fqv[149]); /*caadr*/
	local[0]= w;
	w = env->c.clo.env2[1];
	ctx->vsp=local+1;
	w=FLET1860(ctx,1,local+0,w);
	local[0]= w;
	local[1]= env->c.clo.env2[0];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(*ftab[22])(ctx,1,local+2,&ftab[22],fqv[150]); /*cdadr*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)MAPCAN(ctx,2,local+1); /*mapcan*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)NCONC(ctx,2,local+0); /*nconc*/
	local[0]= w;
	goto CON1871;
CON1873:
	local[0]= NIL;
CON1871:
	goto IF1870;
IF1869:
	local[0]= NIL;
IF1870:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:constraint*/
static pointer M1874body_constraint(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= fqv[27];
	local[4]= argv[2];
	local[5]= fqv[28];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,2,local+4); /*send*/
	local[4]= w;
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	if (w==NIL) goto IF1876;
	local[2]= argv[0];
	local[3]= fqv[151];
	local[4]= argv[2];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[0];
	local[4]= fqv[152];
	local[5]= argv[2];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[0] = w;
	local[2]= argv[2];
	local[3]= fqv[151];
	local[4]= argv[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= argv[2];
	local[4]= fqv[152];
	local[5]= argv[0];
	ctx->vsp=local+6;
	w=(pointer)SEND(ctx,3,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)NCONC(ctx,2,local+2); /*nconc*/
	local[1] = w;
	local[2]= loadglobal(fqv[153]);
	ctx->vsp=local+3;
	w=(pointer)INSTANTIATE(ctx,1,local+2); /*instantiate*/
	local[2]= w;
	local[3]= local[2];
	local[4]= fqv[32];
	local[5]= fqv[154];
	local[6]= argv[0];
	local[7]= fqv[155];
	local[8]= argv[2];
	local[9]= fqv[156];
	local[10]= local[0];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(*ftab[23])(ctx,2,local+10,&ftab[23],fqv[157]); /*contact-to-constraint*/
	local[10]= w;
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,8,local+3); /*send*/
	w = local[2];
	local[2]= w;
	goto IF1877;
IF1876:
	local[2]= NIL;
IF1877:
	w = local[2];
	local[0]= w;
BLK1875:
	ctx->vsp=local; return(local[0]);}

/*:contact-vertices*/
static pointer M1879body_contact_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF1881;
	local[1]= argv[0];
	local[2]= fqv[158];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[159];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
WHL1884:
	if (local[7]==NIL) goto WHX1885;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= local[2];
WHL1889:
	if (local[9]==NIL) goto WHX1890;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[160];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[10]= w;
	if (fqv[91]==local[10]) goto IF1893;
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[6];
	local[15]= fqv[163];
	local[16]= local[8];
	ctx->vsp=local+17;
	w=(pointer)SEND(ctx,6,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[3];
	ctx->vsp=local+11;
	local[3] = cons(ctx,local[10],w);
	w = local[3];
	ctx->vsp=local+10;
	local[10]=w;
	goto BLK1891;
	goto IF1894;
IF1893:
	local[10]= NIL;
IF1894:
	goto WHL1889;
WHX1890:
	local[10]= NIL;
BLK1891:
	w = NIL;
	goto WHL1884;
WHX1885:
	local[8]= NIL;
BLK1886:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
WHL1897:
	if (local[7]==NIL) goto WHX1898;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= argv[0]->c.obj.iv[10];
WHL1902:
	if (local[9]==NIL) goto WHX1903;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[6]->c.obj.iv[0];
	local[11]= local[8]->c.obj.iv[1];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w!=NIL) goto OR1908;
	local[10]= local[6]->c.obj.iv[0];
	local[11]= local[8]->c.obj.iv[2];
	ctx->vsp=local+12;
	w=(pointer)EQUAL(ctx,2,local+10); /*equal*/
	if (w!=NIL) goto OR1908;
	goto IF1906;
OR1908:
	local[10]= local[8];
	w = local[6]->c.obj.iv[3];
	ctx->vsp=local+11;
	local[10]= cons(ctx,local[10],w);
	local[11]= local[10];
	w = local[6];
	w->c.obj.iv[3] = local[11];
	goto IF1907;
IF1906:
	local[10]= NIL;
IF1907:
	goto WHL1902;
WHX1903:
	local[10]= NIL;
BLK1904:
	w = NIL;
	goto WHL1897;
WHX1898:
	local[8]= NIL;
BLK1899:
	w = NIL;
	local[6]= NIL;
	local[7]= local[3];
WHL1910:
	if (local[7]==NIL) goto WHX1911;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= fqv[164];
	ctx->vsp=local+10;
	w=(pointer)SEND(ctx,2,local+8); /*send*/
	goto WHL1910;
WHX1911:
	local[8]= NIL;
BLK1912:
	w = NIL;
	w = local[3];
	local[1]= w;
	goto IF1882;
IF1881:
	local[1]= NIL;
IF1882:
	w = local[1];
	local[0]= w;
BLK1880:
	ctx->vsp=local; return(local[0]);}

/*:contact-edges*/
static pointer M1914body_contact_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0]->c.obj.iv[8];
	local[1]= fqv[27];
	local[2]= argv[2];
	local[3]= fqv[28];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= w;
	if (local[0]==NIL) goto IF1916;
	local[1]= argv[0];
	local[2]= fqv[165];
	local[3]= local[0];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,3,local+1); /*send*/
	local[1]= w;
	local[2]= argv[2];
	local[3]= fqv[159];
	local[4]= local[0];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,3,local+2); /*send*/
	local[2]= w;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= NIL;
	local[6]= NIL;
	local[7]= local[1];
WHL1919:
	if (local[7]==NIL) goto WHX1920;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= NIL;
	local[9]= local[2];
WHL1924:
	if (local[9]==NIL) goto WHX1925;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= fqv[166];
	local[12]= local[6];
	ctx->vsp=local+13;
	w=(pointer)SEND(ctx,3,local+10); /*send*/
	local[3] = w;
	if (local[3]==NIL) goto IF1928;
	local[10]= local[3];
	local[11]= local[4];
	local[12]= fqv[167];
	ctx->vsp=local+13;
	local[13]= makeclosure(codevec,quotevec,CLO1930,env,argv,local);
	ctx->vsp=local+14;
	w=(*ftab[24])(ctx,4,local+10,&ftab[24],fqv[168]); /*find*/
	if (w!=NIL) goto IF1928;
	local[10]= local[6]->c.obj.iv[5];
	ctx->vsp=local+11;
	w=(*ftab[25])(ctx,1,local+10,&ftab[25],fqv[123]); /*plusp*/
	if (w==NIL) goto IF1931;
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[3];
	local[15]= fqv[163];
	local[16]= local[8];
	local[17]= fqv[169];
	local[18]= local[6];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,8,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
	goto IF1932;
IF1931:
	local[10]= loadglobal(fqv[161]);
	ctx->vsp=local+11;
	w=(pointer)INSTANTIATE(ctx,1,local+10); /*instantiate*/
	local[10]= w;
	local[11]= local[10];
	local[12]= fqv[32];
	local[13]= fqv[162];
	local[14]= local[3];
	local[15]= fqv[163];
	local[16]= local[8];
	local[17]= fqv[169];
	local[18]= local[6]->c.obj.iv[3];
	ctx->vsp=local+19;
	w=(pointer)LIST(ctx,1,local+18); /*list*/
	local[18]= w;
	local[19]= local[6]->c.obj.iv[4];
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,1,local+19); /*list*/
	local[19]= w;
	ctx->vsp=local+20;
	w=(pointer)LIST(ctx,2,local+18); /*list*/
	local[18]= w;
	ctx->vsp=local+19;
	w=(pointer)SEND(ctx,8,local+11); /*send*/
	w = local[10];
	local[10]= w;
	w = local[4];
	ctx->vsp=local+11;
	local[4] = cons(ctx,local[10],w);
	local[10]= local[4];
IF1932:
	goto IF1929;
IF1928:
	local[10]= NIL;
IF1929:
	goto WHL1924;
WHX1925:
	local[10]= NIL;
BLK1926:
	w = NIL;
	goto WHL1919;
WHX1920:
	local[8]= NIL;
BLK1921:
	w = NIL;
	w = local[4];
	local[1]= w;
	goto IF1917;
IF1916:
	local[1]= NIL;
IF1917:
	w = local[1];
	local[0]= w;
BLK1915:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-vertices*/
static pointer M1935body_possibly_contacting_vertices(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1937,env,argv,local);
	local[1]= argv[0]->c.obj.iv[11];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1936:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-edges*/
static pointer M1938body_possibly_contacting_edges(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1940,env,argv,local);
	local[1]= argv[0]->c.obj.iv[10];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1939:
	ctx->vsp=local; return(local[0]);}

/*:possibly-contacting-faces*/
static pointer M1941body_possibly_contacting_faces(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	ctx->vsp=local+0;
	local[0]= makeclosure(codevec,quotevec,CLO1943,env,argv,local);
	local[1]= argv[0]->c.obj.iv[9];
	ctx->vsp=local+2;
	w=(pointer)MAPCAN(ctx,2,local+0); /*mapcan*/
	local[0]= w;
BLK1942:
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1930(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= argv[0];
	local[1]= argv[1]->c.obj.iv[0];
	local[2]= loadglobal(fqv[29]);
	ctx->vsp=local+3;
	w=(*ftab[26])(ctx,3,local+0,&ftab[26],fqv[170]); /*eps-v=*/
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1937(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= env->c.clo.env1[2];
	local[1]= fqv[90];
	local[2]= argv[0];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	if (w==NIL) goto IF1944;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1945;
IF1944:
	local[0]= NIL;
IF1945:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1940(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	local[3]= loadglobal(fqv[29]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	if (w==NIL) goto IF1946;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1947;
IF1946:
	local[0]= NIL;
IF1947:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*closure or cleaner*/
static pointer CLO1943(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= argv[0];
	local[1]= fqv[101];
	local[2]= env->c.clo.env1[2];
	local[3]= loadglobal(fqv[29]);
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	if (w==NIL) goto IF1948;
	local[0]= argv[0];
	ctx->vsp=local+1;
	w=(pointer)LIST(ctx,1,local+0); /*list*/
	local[0]= w;
	goto IF1949;
IF1948:
	local[0]= NIL;
IF1949:
	w = local[0];
	local[0]= w;
	ctx->vsp=local; return(local[0]);}

/*:radius*/
static pointer M1952sphere_radius(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	if (n>=3) { local[0]=(argv[2]); goto ENT1955;}
	local[0]= NIL;
ENT1955:
ENT1954:
	if (n>3) maerror();
	if (local[0]==NIL) goto IF1956;
	argv[0]->c.obj.iv[8] = local[0];
	local[1]= argv[0]->c.obj.iv[8];
	goto IF1957;
IF1956:
	local[1]= NIL;
IF1957:
	w = argv[0]->c.obj.iv[8];
	local[0]= w;
BLK1953:
	ctx->vsp=local; return(local[0]);}

/*:inner*/
static pointer M1958sphere_inner(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[2];
	local[1]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+2;
	w=(pointer)VDISTANCE(ctx,2,local+0); /*distance*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+2;
	w=(pointer)LESSP(ctx,2,local+0); /*<*/
	local[0]= w;
BLK1959:
	ctx->vsp=local; return(local[0]);}

/*:volume*/
static pointer M1960sphere_volume(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=2) maerror();
	local[0]= makeflt(4.0000000000000000000000e+00);
	local[1]= makeflt(3.1415926535897931159980e+00);
	local[2]= argv[0]->c.obj.iv[8];
	local[3]= argv[0]->c.obj.iv[8];
	local[4]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+5;
	w=(pointer)TIMES(ctx,5,local+0); /***/
	local[0]= w;
	local[1]= makeint((eusinteger_t)3L);
	ctx->vsp=local+2;
	w=(pointer)QUOTIENT(ctx,2,local+0); /*/*/
	local[0]= w;
BLK1961:
	ctx->vsp=local; return(local[0]);}

/*:intersect-line*/
static pointer M1962sphere_intersect_line(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=4) maerror();
	local[0]= argv[2];
	local[1]= argv[2];
	local[2]= argv[3];
	ctx->vsp=local+3;
	w=(pointer)VMINUS(ctx,2,local+1); /*v-*/
	local[1]= w;
	local[2]= argv[0];
	local[3]= fqv[171];
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,2,local+2); /*send*/
	local[2]= w;
	local[3]= local[0];
	local[4]= local[2];
	ctx->vsp=local+5;
	w=(pointer)VMINUS(ctx,2,local+3); /*v-*/
	local[3]= w;
	local[4]= local[1];
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)VINNERPRODUCT(ctx,2,local+4); /*v.*/
	local[4]= w;
	local[5]= local[1];
	local[6]= local[3];
	ctx->vsp=local+7;
	w=(pointer)VINNERPRODUCT(ctx,2,local+5); /*v.*/
	local[5]= w;
	local[6]= local[3];
	local[7]= local[3];
	ctx->vsp=local+8;
	w=(pointer)VINNERPRODUCT(ctx,2,local+6); /*v.*/
	local[6]= w;
	local[7]= argv[0]->c.obj.iv[8];
	local[8]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	ctx->vsp=local+8;
	w=(pointer)MINUS(ctx,2,local+6); /*-*/
	local[6]= w;
	local[7]= local[5];
	local[8]= local[5];
	ctx->vsp=local+9;
	w=(pointer)TIMES(ctx,2,local+7); /***/
	local[7]= w;
	local[8]= local[4];
	local[9]= local[6];
	ctx->vsp=local+10;
	w=(pointer)TIMES(ctx,2,local+8); /***/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)MINUS(ctx,1,local+8); /*-*/
	local[8]= w;
	ctx->vsp=local+9;
	w=(pointer)PLUS(ctx,2,local+7); /*+*/
	local[7]= w;
	local[8]= local[7];
	local[9]= makeflt(0.0000000000000000000000e+00);
	ctx->vsp=local+10;
	w=(pointer)LESSP(ctx,2,local+8); /*<*/
	if (w==NIL) goto IF1964;
	local[8]= NIL;
	goto IF1965;
IF1964:
	local[8]= local[5];
	local[9]= local[7];
	ctx->vsp=local+10;
	w=(pointer)SQRT(ctx,1,local+9); /*sqrt*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)PLUS(ctx,2,local+8); /*+*/
	local[8]= w;
	local[9]= local[4];
	ctx->vsp=local+10;
	w=(pointer)QUOTIENT(ctx,2,local+8); /*/*/
	local[8]= w;
	local[9]= argv[2];
	local[10]= argv[3];
	ctx->vsp=local+11;
	w=(*ftab[27])(ctx,3,local+8,&ftab[27],fqv[172]); /*midpoint*/
	local[8]= w;
	local[9]= local[5];
	local[10]= local[7];
	ctx->vsp=local+11;
	w=(pointer)SQRT(ctx,1,local+10); /*sqrt*/
	local[10]= makeflt(-(fltval(w)));
	ctx->vsp=local+11;
	w=(pointer)PLUS(ctx,2,local+9); /*+*/
	local[9]= w;
	local[10]= local[4];
	ctx->vsp=local+11;
	w=(pointer)QUOTIENT(ctx,2,local+9); /*/*/
	local[9]= w;
	local[10]= argv[2];
	local[11]= argv[3];
	ctx->vsp=local+12;
	w=(*ftab[27])(ctx,3,local+9,&ftab[27],fqv[172]); /*midpoint*/
	local[9]= w;
	ctx->vsp=local+10;
	w=(pointer)LIST(ctx,2,local+8); /*list*/
	local[8]= w;
IF1965:
	w = local[8];
	local[0]= w;
BLK1963:
	ctx->vsp=local; return(local[0]);}

/*:closest-point*/
static pointer M1966sphere_closest_point(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= argv[0];
	local[1]= fqv[171];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= argv[0]->c.obj.iv[8];
	local[2]= argv[2];
	local[3]= argv[0];
	local[4]= fqv[171];
	ctx->vsp=local+5;
	w=(pointer)SEND(ctx,2,local+3); /*send*/
	local[3]= w;
	ctx->vsp=local+4;
	w=(pointer)VMINUS(ctx,2,local+2); /*v-*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)VNORMALIZE(ctx,1,local+2); /*normalize-vector*/
	local[2]= w;
	ctx->vsp=local+3;
	w=(pointer)SCALEVEC(ctx,2,local+1); /*scale*/
	local[1]= w;
	ctx->vsp=local+2;
	w=(pointer)VPLUS(ctx,2,local+0); /*v+*/
	local[0]= w;
BLK1967:
	ctx->vsp=local; return(local[0]);}

/*:intersect-with-body*/
static pointer M1968sphere_intersect_with_body(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=3) maerror();
	local[0]= NIL;
	local[1]= argv[2];
	local[2]= fqv[173];
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,2,local+1); /*send*/
	local[1]= w;
WHL1971:
	if (local[1]==NIL) goto WHX1972;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2]= (w)->c.cons.car;
	w=local[1];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[1] = (w)->c.cons.cdr;
	w = local[2];
	local[0] = w;
	local[2]= local[0];
	local[3]= argv[0]->c.obj.iv[2];
	ctx->vsp=local+4;
	w=(pointer)VDISTANCE(ctx,2,local+2); /*distance*/
	local[2]= w;
	local[3]= argv[0]->c.obj.iv[8];
	ctx->vsp=local+4;
	w=(pointer)LESSP(ctx,2,local+2); /*<*/
	if (w==NIL) goto IF1975;
	w = T;
	ctx->vsp=local+2;
	local[0]=w;
	goto BLK1969;
	goto IF1976;
IF1975:
	local[2]= NIL;
IF1976:
	goto WHL1971;
WHX1972:
	local[2]= NIL;
BLK1973:
	w = NIL;
	w = NIL;
	local[0]= w;
BLK1969:
	ctx->vsp=local; return(local[0]);}

/*:init*/
static pointer M1977sphere_init(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n<2) maerror();
	ctx->vsp=local+0;
	n=parsekeyparams(fqv[174], &argv[2], n-2, local+0, 0);
	if (n & (1<<0)) goto KEY1979;
	local[2]= makeint((eusinteger_t)0L);
	local[3]= makeint((eusinteger_t)0L);
	local[4]= makeint((eusinteger_t)0L);
	ctx->vsp=local+5;
	w=(pointer)MKFLTVEC(ctx,3,local+2); /*float-vector*/
	local[0] = w;
KEY1979:
	if (n & (1<<1)) goto KEY1980;
	local[1] = makeflt(1.0000000000000000000000e+00);
KEY1980:
	local[2]= argv[0];
	local[3]= *(ovafptr(argv[1],fqv[53]));
	local[4]= fqv[32];
	ctx->vsp=local+5;
	w=(pointer)SENDMESSAGE(ctx,3,local+2); /*send-message*/
	argv[0]->c.obj.iv[2] = local[0];
	argv[0]->c.obj.iv[8] = local[1];
	w = argv[0];
	local[0]= w;
BLK1978:
	ctx->vsp=local; return(local[0]);}

/*add-wings*/
static pointer F1247add_wings(ctx,n,argv,env)
register context *ctx;
register int n; register pointer argv[]; pointer env;
{ register pointer *local=ctx->vsp, w, *fqv=qv;
  numunion nu;
	if (n!=1) maerror();
	local[0]= NIL;
	local[1]= NIL;
	local[2]= NIL;
	local[3]= NIL;
	local[4]= NIL;
	local[5]= argv[0]->c.obj.iv[10];
WHL1983:
	if (local[5]==NIL) goto WHX1984;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[6]= loadglobal(fqv[175]);
	ctx->vsp=local+7;
	w=(pointer)INSTANTIATE(ctx,1,local+6); /*instantiate*/
	local[6]= w;
	local[7]= local[6];
	local[8]= fqv[32];
	local[9]= fqv[176];
	local[10]= local[4]->c.obj.iv[3];
	local[11]= fqv[177];
	local[12]= local[4]->c.obj.iv[4];
	local[13]= fqv[178];
	local[14]= local[4]->c.obj.iv[1];
	local[15]= fqv[179];
	local[16]= local[4]->c.obj.iv[2];
	local[17]= fqv[99];
	local[18]= local[4]->c.obj.iv[5];
	local[19]= fqv[180];
	local[20]= local[4];
	local[21]= fqv[180];
	ctx->vsp=local+22;
	w=(pointer)SEND(ctx,2,local+20); /*send*/
	local[20]= w;
	local[21]= fqv[181];
	local[22]= local[4];
	local[23]= fqv[181];
	ctx->vsp=local+24;
	w=(pointer)SEND(ctx,2,local+22); /*send*/
	local[22]= w;
	local[23]= fqv[182];
	local[24]= local[4];
	local[25]= fqv[182];
	ctx->vsp=local+26;
	w=(pointer)SEND(ctx,2,local+24); /*send*/
	local[24]= w;
	local[25]= fqv[183];
	local[26]= local[4];
	local[27]= fqv[183];
	ctx->vsp=local+28;
	w=(pointer)SEND(ctx,2,local+26); /*send*/
	local[26]= w;
	ctx->vsp=local+27;
	w=(pointer)SEND(ctx,20,local+7); /*send*/
	w = local[6];
	local[3] = w;
	local[6]= local[4];
	local[7]= local[3];
	local[8]= local[1];
	ctx->vsp=local+9;
	w=(*ftab[28])(ctx,3,local+6,&ftab[28],fqv[184]); /*acons*/
	local[1] = w;
	goto WHL1983;
WHX1984:
	local[6]= NIL;
BLK1985:
	w = NIL;
	local[4]= NIL;
	local[5]= local[1];
WHL1989:
	if (local[5]==NIL) goto WHX1990;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[2] = (w)->c.cons.car;
	w=local[4];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[3] = (w)->c.cons.cdr;
	local[6]= local[3];
	local[7]= fqv[32];
	local[8]= fqv[180];
	local[9]= local[3]->c.obj.iv[7];
	local[10]= local[1];
	ctx->vsp=local+11;
	w=(pointer)ASSQ(ctx,2,local+9); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9]= (w)->c.cons.cdr;
	local[10]= fqv[182];
	local[11]= local[3]->c.obj.iv[9];
	local[12]= local[1];
	ctx->vsp=local+13;
	w=(pointer)ASSQ(ctx,2,local+11); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[11]= (w)->c.cons.cdr;
	local[12]= fqv[181];
	local[13]= local[3]->c.obj.iv[8];
	local[14]= local[1];
	ctx->vsp=local+15;
	w=(pointer)ASSQ(ctx,2,local+13); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[13]= (w)->c.cons.cdr;
	local[14]= fqv[183];
	local[15]= local[3]->c.obj.iv[10];
	local[16]= local[1];
	ctx->vsp=local+17;
	w=(pointer)ASSQ(ctx,2,local+15); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[15]= (w)->c.cons.cdr;
	ctx->vsp=local+16;
	w=(pointer)SEND(ctx,10,local+6); /*send*/
	goto WHL1989;
WHX1990:
	local[6]= NIL;
BLK1991:
	w = NIL;
	local[4]= NIL;
	local[5]= argv[0];
	local[6]= fqv[185];
	ctx->vsp=local+7;
	w=(pointer)SEND(ctx,2,local+5); /*send*/
	local[5]= w;
WHL1994:
	if (local[5]==NIL) goto WHX1995;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[6]= (w)->c.cons.car;
	w=local[5];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[5] = (w)->c.cons.cdr;
	w = local[6];
	local[4] = w;
	local[0] = NIL;
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[186];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL1999:
	if (local[7]==NIL) goto WHX2000;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[8]= local[6];
	local[9]= local[1];
	ctx->vsp=local+10;
	w=(pointer)ASSQ(ctx,2,local+8); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.cdr;
	w = local[0];
	ctx->vsp=local+9;
	local[0] = cons(ctx,local[8],w);
	goto WHL1999;
WHX2000:
	local[8]= NIL;
BLK2001:
	w = NIL;
	local[6]= local[0];
	local[7]= local[6];
	w = local[4];
	w->c.obj.iv[4] = local[7];
	local[6]= NIL;
	local[7]= local[4];
	local[8]= fqv[14];
	ctx->vsp=local+9;
	w=(pointer)SEND(ctx,2,local+7); /*send*/
	local[7]= w;
WHL2004:
	if (local[7]==NIL) goto WHX2005;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[8]= (w)->c.cons.car;
	w=local[7];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[7] = (w)->c.cons.cdr;
	w = local[8];
	local[6] = w;
	local[0] = NIL;
	local[8]= NIL;
	local[9]= local[6];
	local[10]= fqv[186];
	ctx->vsp=local+11;
	w=(pointer)SEND(ctx,2,local+9); /*send*/
	local[9]= w;
WHL2009:
	if (local[9]==NIL) goto WHX2010;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.car;
	w=local[9];
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[9] = (w)->c.cons.cdr;
	w = local[10];
	local[8] = w;
	local[10]= local[8];
	local[11]= local[1];
	ctx->vsp=local+12;
	w=(pointer)ASSQ(ctx,2,local+10); /*assq*/
	if (!iscons(w) && w!=NIL) error(E_NOLIST);
	local[10]= (w)->c.cons.cdr;
	w = local[0];
	ctx->vsp=local+11;
	local[0] = cons(ctx,local[10],w);
	goto WHL2009;
WHX2010:
	local[10]= NIL;
BLK2011:
	w = NIL;
	local[8]= local[0];
	local[9]= local[8];
	w = local[6];
	w->c.obj.iv[4] = local[9];
	goto WHL2004;
WHX2005:
	local[8]= NIL;
BLK2006:
	w = NIL;
	goto WHL1994;
WHX1995:
	local[6]= NIL;
BLK1996:
	w = NIL;
	local[4]= (pointer)get_sym_func(fqv[187]);
	local[5]= local[1];
	ctx->vsp=local+6;
	w=(pointer)MAPCAR(ctx,2,local+4); /*mapcar*/
	local[4]= w;
	local[5]= w;
	w = argv[0];
	w->c.obj.iv[10] = local[5];
	w = argv[0];
	local[0]= w;
BLK1981:
	ctx->vsp=local; return(local[0]);}

/* initializer*/
pointer ___geobody(ctx,n,argv,env)
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
	local[0]= fqv[188];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	if (w==NIL) goto IF2013;
	local[0]= fqv[189];
	ctx->vsp=local+1;
	w=(pointer)FINDPACKAGE(ctx,1,local+0); /*find-package*/
	local[0]= w;
	storeglobal(fqv[190],w);
	goto IF2014;
IF2013:
	local[0]= fqv[191];
	ctx->vsp=local+1;
	w=(pointer)SIGERROR(ctx,1,local+0); /*error*/
	local[0]= w;
IF2014:
	local[0]= fqv[192];
	ctx->vsp=local+1;
	w=(pointer)EXPORT(ctx,1,local+0); /*export*/
	local[0]= fqv[193];
	local[1]= fqv[194];
	ctx->vsp=local+2;
	w=(*ftab[29])(ctx,2,local+0,&ftab[29],fqv[195]); /*require*/
	local[0]= fqv[196];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2015;
	local[0]= fqv[196];
	local[1]= fqv[197];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[196];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2017;
	local[0]= fqv[196];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2018;
IF2017:
	local[0]= NIL;
IF2018:
	local[0]= fqv[196];
	goto IF2016;
IF2015:
	local[0]= NIL;
IF2016:
	local[0]= fqv[199];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2019;
	local[0]= fqv[199];
	local[1]= fqv[197];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[199];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2021;
	local[0]= fqv[199];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2022;
IF2021:
	local[0]= NIL;
IF2022:
	local[0]= fqv[199];
	goto IF2020;
IF2019:
	local[0]= NIL;
IF2020:
	local[0]= fqv[200];
	local[1]= fqv[197];
	ctx->vsp=local+2;
	w=(pointer)SEND(ctx,2,local+0); /*send*/
	local[0]= w;
	local[1]= makeint((eusinteger_t)1L);
	ctx->vsp=local+2;
	w=(pointer)EQ(ctx,2,local+0); /*eql*/
	if (w==NIL) goto IF2023;
	local[0]= fqv[200];
	local[1]= fqv[197];
	local[2]= makeint((eusinteger_t)2L);
	ctx->vsp=local+3;
	w=(pointer)SEND(ctx,3,local+0); /*send*/
	local[0]= fqv[200];
	ctx->vsp=local+1;
	w=(pointer)BOUNDP(ctx,1,local+0); /*boundp*/
	if (w!=NIL) goto IF2025;
	local[0]= fqv[200];
	local[1]= fqv[198];
	local[2]= NIL;
	local[3]= NIL;
	ctx->vsp=local+4;
	w=(pointer)SEND(ctx,4,local+0); /*send*/
	local[0]= w;
	goto IF2026;
IF2025:
	local[0]= NIL;
IF2026:
	local[0]= fqv[200];
	goto IF2024;
IF2023:
	local[0]= NIL;
IF2024:
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1248faceset_update,fqv[33],fqv[201],fqv[202]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1257faceset_vertices,fqv[173],fqv[201],fqv[203]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1259faceset_faces,fqv[185],fqv[201],fqv[204]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1265faceset_face,fqv[205],fqv[201],fqv[206]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1267faceset_all_edges,fqv[23],fqv[201],fqv[207]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1269faceset_edges,fqv[186],fqv[201],fqv[208]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1271faceset_edge,fqv[209],fqv[201],fqv[210]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1273faceset_vertex,fqv[211],fqv[201],fqv[212]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1275faceset_box,fqv[28],fqv[201],fqv[213]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1277faceset_color,fqv[10],fqv[201],fqv[214]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1283faceset_reflectance,fqv[11],fqv[201],fqv[215]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1291faceset_diffusion,fqv[12],fqv[201],fqv[216]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1299faceset_holes,fqv[14],fqv[201],fqv[217]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1301faceset_visible_faces,fqv[22],fqv[201],fqv[218]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1306faceset_visible_edges,fqv[6],fqv[201],fqv[219]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1322faceset_contour_edges,fqv[220],fqv[201],fqv[221]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1336faceset_non_contour_edges,fqv[222],fqv[201],fqv[223]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1345faceset_common_box,fqv[74],fqv[201],fqv[224]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1349faceset_newbox,fqv[97],fqv[201],fqv[225]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1355faceset_reset_vertices,fqv[4],fqv[201],fqv[226]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1362faceset_translate_vertices,fqv[56],fqv[201],fqv[227]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1369faceset_rotate_vertices,fqv[57],fqv[201],fqv[228]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1380faceset_magnify,fqv[58],fqv[201],fqv[229]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1402faceset_faces_intersect_with_point_vector,fqv[69],fqv[201],fqv[230]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1411faceset_distance,fqv[46],fqv[201],fqv[231]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1430faceset_init,fqv[32],fqv[201],fqv[232]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1458body_translate_vertices,fqv[56],fqv[233],fqv[234]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1460body_rotate_vertices,fqv[57],fqv[233],fqv[235]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1462body_magnify,fqv[58],fqv[233],fqv[236]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1466body_euler,fqv[237],fqv[233],fqv[238]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1468body_perimeter,fqv[239],fqv[233],fqv[240]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1470body_volume,fqv[62],fqv[233],fqv[241]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1474body_centroid,fqv[63],fqv[233],fqv[242]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1484body_world_centroid,fqv[243],fqv[233],fqv[244]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1486body_area,fqv[67],fqv[233],fqv[245]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1488body_extream_point,fqv[68],fqv[233],fqv[246]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1497body_length,fqv[60],fqv[233],fqv[247]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1499body_supporting_faces,fqv[248],fqv[233],fqv[249]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1503body_possibly_interfering_faces,fqv[72],fqv[233],fqv[250]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1506body_possibly_interfering_edges,fqv[75],fqv[233],fqv[251]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1509body_intersect_face,fqv[71],fqv[233],fqv[252]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1519body_intersectp,fqv[253],fqv[233],fqv[254]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1536body_intersectp2,fqv[255],fqv[233],fqv[256]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1624body_insidep,fqv[82],fqv[233],fqv[257]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1666body_evert,fqv[258],fqv[233],fqv[259]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1672body_set_convexp,fqv[98],fqv[233],fqv[260]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1681body_get_face,fqv[9],fqv[233],fqv[261]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1735body_primitive_body_p,fqv[115],fqv[233],fqv[262]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1738body_primitive_bodies,fqv[146],fqv[233],fqv[263]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1755body_csg,fqv[126],fqv[233],fqv[264]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1761body_copy_csg,fqv[265],fqv[233],fqv[266]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1766body_body_type,fqv[119],fqv[233],fqv[267]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1770body_creation_form,fqv[268],fqv[233],fqv[269]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1775body_prin1,fqv[118],fqv[233],fqv[270]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1777body_init,fqv[32],fqv[233],fqv[271]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1831body_replace_shape,fqv[147],fqv[233],fqv[272]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1848body__,fqv[111],fqv[233],fqv[273]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1851body__,fqv[113],fqv[233],fqv[274]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1854body__,fqv[275],fqv[233],fqv[276]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1857body_primitive_groups,fqv[112],fqv[233],fqv[277]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1874body_constraint,fqv[278],fqv[233],fqv[279]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1879body_contact_vertices,fqv[151],fqv[233],fqv[280]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1914body_contact_edges,fqv[152],fqv[233],fqv[281]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1935body_possibly_contacting_vertices,fqv[158],fqv[233],fqv[282]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1938body_possibly_contacting_edges,fqv[165],fqv[233],fqv[283]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1941body_possibly_contacting_faces,fqv[159],fqv[233],fqv[284]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1952sphere_radius,fqv[285],fqv[286],fqv[287]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1958sphere_inner,fqv[90],fqv[286],fqv[288]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1960sphere_volume,fqv[62],fqv[286],fqv[289]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1962sphere_intersect_line,fqv[77],fqv[286],fqv[290]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1966sphere_closest_point,fqv[291],fqv[286],fqv[292]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1968sphere_intersect_with_body,fqv[293],fqv[286],fqv[294]);
	ctx->vsp=local+0;
	addcmethod(ctx,module,M1977sphere_init,fqv[32],fqv[286],fqv[295]);
	ctx->vsp=local+0;
	compfun(ctx,fqv[296],module,F1247add_wings,fqv[297]);
	local[0]= fqv[298];
	local[1]= fqv[299];
	ctx->vsp=local+2;
	w=(*ftab[30])(ctx,2,local+0,&ftab[30],fqv[300]); /*provide*/
	local[0]= NIL;
	ctx->vsp=local; return(local[0]);}
static void init_ftab()
{  register int i;
  for (i=0; i<31; i++) ftab[i]=fcallx;
}
