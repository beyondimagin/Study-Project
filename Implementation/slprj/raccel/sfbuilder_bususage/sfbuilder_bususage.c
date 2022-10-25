#include "rt_logging_mmi.h"
#include "sfbuilder_bususage_capi.h"
#include <math.h>
#include "sfbuilder_bususage.h"
#include "sfbuilder_bususage_private.h"
#include "sfbuilder_bususage_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.5 (R2021a) 14-Nov-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct
* S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlInitialize ( void ) { rtDW . hgpael0gzw = 0 ; rtDW .
a3ns25gzqu = rtP . PreviousOutput_InitialCondition ; rtDW . lkj5j0uhm2 = rtP
. UnitDelay_InitialCondition ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { int_T numCols = 4 ; rtDW . bahj2bvmf1 . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "scopeout1" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
( int_T * ) & numCols , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.1 , 1
) ; if ( rtDW . bahj2bvmf1 . LoggedData == ( NULL ) ) return ; } { int_T
numCols = 4 ; rtDW . a22vvppw0s . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "scopeout2" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
( int_T * ) & numCols , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.1 , 1
) ; if ( rtDW . a22vvppw0s . LoggedData == ( NULL ) ) return ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { int32_T ctbjleknyo ;
boolean_T dbj2y2ufyn ; rtB . eaeuhrc02t . inputsignal . input = ( rtDW .
hgpael0gzw < rtP . PulseGenerator1_Duty ) && ( rtDW . hgpael0gzw >= 0 ) ? rtP
. PulseGenerator1_Amp : 0 ; if ( rtDW . hgpael0gzw >= rtP .
PulseGenerator1_Period - 1.0 ) { rtDW . hgpael0gzw = 0 ; } else { rtDW .
hgpael0gzw ++ ; } rtB . eaeuhrc02t . limits . upper_saturation_limit = rtP .
upper_saturation_limit1_Value ; rtB . eaeuhrc02t . limits .
lower_saturation_limit = rtP . lower_saturation_limit1_Value ; ctbjleknyo =
rtB . eaeuhrc02t . inputsignal . input + rtDW . a3ns25gzqu ; dbj2y2ufyn = (
ctbjleknyo >= rtB . eaeuhrc02t . limits . lower_saturation_limit ) ; if ( (
rtB . eaeuhrc02t . limits . upper_saturation_limit >= ctbjleknyo ) &&
dbj2y2ufyn ) { rtB . hvyyu1lsai = ctbjleknyo ; } else if ( dbj2y2ufyn ) { rtB
. hvyyu1lsai = rtB . eaeuhrc02t . limits . upper_saturation_limit ; } else {
rtB . hvyyu1lsai = rtB . eaeuhrc02t . limits . lower_saturation_limit ; } rtB
. j0vikhhhoz . inputsignal . input = rtB . hvyyu1lsai ; rtB . j0vikhhhoz .
limits = rtB . eaeuhrc02t . limits ; if ( ssGetLogOutput ( rtS ) ) { real_T u
[ 4 ] ; u [ 0 ] = ssGetTaskTime ( rtS , 0 ) ; ; u [ 1 ] = rtB . j0vikhhhoz .
inputsignal . input ; u [ 2 ] = rtB . j0vikhhhoz . limits .
upper_saturation_limit ; u [ 3 ] = rtB . j0vikhhhoz . limits .
lower_saturation_limit ; rt_UpdateLogVar ( ( LogVar * ) rtDW . bahj2bvmf1 .
LoggedData , u , 0 ) ; } rtB . jjs2flljx3 = rtDW . lkj5j0uhm2 ;
sfbuilder_bus_Outputs_wrapper_accel ( & rtB . eaeuhrc02t , & rtDW .
aytghwde2s , & rtB . jjs2flljx3 , & rtB . l1rfwvopfj , & rtDW . bcwuhs2hmz ,
& rtB . bctwqitgzv ) ; if ( ssGetLogOutput ( rtS ) ) { real_T u [ 4 ] ; u [ 0
] = ssGetTaskTime ( rtS , 0 ) ; ; u [ 1 ] = rtB . l1rfwvopfj . inputsignal .
input ; u [ 2 ] = rtB . l1rfwvopfj . limits . upper_saturation_limit ; u [ 3
] = rtB . l1rfwvopfj . limits . lower_saturation_limit ; rt_UpdateLogVar ( (
LogVar * ) rtDW . a22vvppw0s . LoggedData , u , 0 ) ; } UNUSED_PARAMETER (
tid ) ; } void MdlOutputsTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { rtDW . a3ns25gzqu = rtB . hvyyu1lsai ; rtDW .
lkj5j0uhm2 = rtB . bctwqitgzv ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate
( void ) { } static void mr_sfbuilder_bususage_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_sfbuilder_bususage_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_sfbuilder_bususage_restoreDataFromMxArray (
void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) ; static void mr_sfbuilder_bususage_restoreDataFromMxArray ( void
* destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes )
{ memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_sfbuilder_bususage_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) ; static void
mr_sfbuilder_bususage_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_sfbuilder_bususage_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_sfbuilder_bususage_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_sfbuilder_bususage_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_sfbuilder_bususage_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_sfbuilder_bususage_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_sfbuilder_bususage_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_sfbuilder_bususage_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_sfbuilder_bususage_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_sfbuilder_bususage_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_sfbuilder_bususage_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_sfbuilder_bususage_GetDWork ( ) {
static const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_sfbuilder_bususage_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) &
( rtB ) , sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 5 ] =
{ "rtDW.aytghwde2s" , "rtDW.bcwuhs2hmz" , "rtDW.a3ns25gzqu" ,
"rtDW.lkj5j0uhm2" , "rtDW.hgpael0gzw" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 5 , rtdwDataFieldNames ) ;
mr_sfbuilder_bususage_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void *
) & ( rtDW . aytghwde2s ) , sizeof ( rtDW . aytghwde2s ) ) ;
mr_sfbuilder_bususage_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void *
) & ( rtDW . bcwuhs2hmz ) , sizeof ( rtDW . bcwuhs2hmz ) ) ;
mr_sfbuilder_bususage_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void *
) & ( rtDW . a3ns25gzqu ) , sizeof ( rtDW . a3ns25gzqu ) ) ;
mr_sfbuilder_bususage_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void *
) & ( rtDW . lkj5j0uhm2 ) , sizeof ( rtDW . lkj5j0uhm2 ) ) ;
mr_sfbuilder_bususage_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void *
) & ( rtDW . hgpael0gzw ) , sizeof ( rtDW . hgpael0gzw ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_sfbuilder_bususage_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_sfbuilder_bususage_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW ,
0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_sfbuilder_bususage_restoreDataFromMxArray ( ( void * ) &
( rtDW . aytghwde2s ) , rtdwData , 0 , 0 , sizeof ( rtDW . aytghwde2s ) ) ;
mr_sfbuilder_bususage_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bcwuhs2hmz ) , rtdwData , 0 , 1 , sizeof ( rtDW . bcwuhs2hmz ) ) ;
mr_sfbuilder_bususage_restoreDataFromMxArray ( ( void * ) & ( rtDW .
a3ns25gzqu ) , rtdwData , 0 , 2 , sizeof ( rtDW . a3ns25gzqu ) ) ;
mr_sfbuilder_bususage_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lkj5j0uhm2 ) , rtdwData , 0 , 3 , sizeof ( rtDW . lkj5j0uhm2 ) ) ;
mr_sfbuilder_bususage_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hgpael0gzw ) , rtdwData , 0 , 4 , sizeof ( rtDW . hgpael0gzw ) ) ; } }
mxArray * mr_sfbuilder_bususage_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 2 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char * blockType [ 2 ] = { "Scope" , "Scope" , } ; static const char *
blockPath [ 2 ] = { "sfbuilder_bususage/ScopeA1" ,
"sfbuilder_bususage/ScopeA2" , } ; static const int reason [ 2 ] = { 0 , 0 ,
} ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 2 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ]
= 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough
( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 22 ) ;
ssSetNumBlockIO ( rtS , 6 ) ; ssSetNumBlockParams ( rtS , 8 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.1 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 3352122353U ) ; ssSetChecksumVal ( rtS , 1 ,
4159562089U ) ; ssSetChecksumVal ( rtS , 2 , 1871902350U ) ; ssSetChecksumVal
( rtS , 3 , 3937603553U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 17 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
sfbuilder_bususage_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive
( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "sfbuilder_bususage" ) ;
ssSetPath ( rtS , "sfbuilder_bususage" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 10.0 ) ; ssSetStepSize ( rtS , 0.1 ) ; ssSetFixedStepSize
( rtS , 0.1 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_INT32 , SS_INT32 } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "DSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"sfbuilder_bususage/slCounter/Previous Output" ,
"sfbuilder_bususage/S-function Builder/Unit Delay" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0
, 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ;
static int_T rt_LoggedStateIdxList [ ] = { 4 , 5 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 2 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtDW . a3ns25gzqu ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . lkj5j0uhm2 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo )
; ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver (
rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
3352122353U ) ; ssSetChecksumVal ( rtS , 1 , 4159562089U ) ; ssSetChecksumVal
( rtS , 2 , 1871902350U ) ; ssSetChecksumVal ( rtS , 3 , 3937603553U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 4 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_sfbuilder_bususage_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_sfbuilder_bususage_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_sfbuilder_bususage_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
