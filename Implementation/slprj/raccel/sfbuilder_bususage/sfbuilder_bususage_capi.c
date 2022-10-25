#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "sfbuilder_bususage_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "sfbuilder_bususage.h"
#include "sfbuilder_bususage_capi.h"
#include "sfbuilder_bususage_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"sfbuilder_bususage/S-function Builder" ) , TARGET_STRING ( "" ) , 0 , 3 , 0
, 0 , 0 } , { 1 , 3 , TARGET_STRING ( "sfbuilder_bususage/slCounter" ) ,
TARGET_STRING ( "" ) , 0 , 3 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"sfbuilder_bususage/SFB_COUNTERBUSCreator1" ) , TARGET_STRING (
"SFB_COUNTERBUS" ) , 0 , 3 , 0 , 0 , 0 } , { 3 , 1 , TARGET_STRING (
"sfbuilder_bususage/S-function Builder/S-Function Builder" ) , TARGET_STRING
( "" ) , 0 , 3 , 0 , 0 , 0 } , { 4 , 1 , TARGET_STRING (
"sfbuilder_bususage/S-function Builder/S-Function Builder" ) , TARGET_STRING
( "" ) , 1 , 0 , 0 , 0 , 0 } , { 5 , 1 , TARGET_STRING (
"sfbuilder_bususage/S-function Builder/Unit Delay" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 6 , 3 , TARGET_STRING (
"sfbuilder_bususage/slCounter/Bus Creator" ) , TARGET_STRING ( "" ) , 0 , 3 ,
0 , 0 , 0 } , { 7 , 3 , TARGET_STRING ( "sfbuilder_bususage/slCounter/Switch"
) , TARGET_STRING ( "input" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 8 , TARGET_STRING (
"sfbuilder_bususage/lower_ saturation_ limit1" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 9 , TARGET_STRING (
"sfbuilder_bususage/upper_saturation_limit1" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 10 , TARGET_STRING ( "sfbuilder_bususage/Pulse Generator1" )
, TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 11 , TARGET_STRING (
"sfbuilder_bususage/Pulse Generator1" ) , TARGET_STRING ( "Period" ) , 4 , 0
, 0 } , { 12 , TARGET_STRING ( "sfbuilder_bususage/Pulse Generator1" ) ,
TARGET_STRING ( "PulseWidth" ) , 4 , 0 , 0 } , { 13 , TARGET_STRING (
"sfbuilder_bususage/Pulse Generator1" ) , TARGET_STRING ( "PhaseDelay" ) , 4
, 0 , 0 } , { 14 , TARGET_STRING (
"sfbuilder_bususage/S-function Builder/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 15 , TARGET_STRING (
"sfbuilder_bususage/slCounter/Previous Output" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 }
} ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . l1rfwvopfj , & rtB . j0vikhhhoz ,
& rtB . eaeuhrc02t , & rtB . l1rfwvopfj , & rtB . bctwqitgzv , & rtB .
jjs2flljx3 , & rtB . j0vikhhhoz , & rtB . hvyyu1lsai , & rtP .
lower_saturation_limit1_Value , & rtP . upper_saturation_limit1_Value , & rtP
. PulseGenerator1_Amp , & rtP . PulseGenerator1_Period , & rtP .
PulseGenerator1_Duty , & rtP . PulseGenerator1_PhaseDelay , & rtP .
UnitDelay_InitialCondition , & rtP . PreviousOutput_InitialCondition , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "int" ,
"int32_T" , 0 , 0 , sizeof ( int32_T ) , SS_INT32 , 0 , 0 , 0 } , { "struct"
, "SFB_SIGNALBUS" , 1 , 1 , sizeof ( SFB_SIGNALBUS ) , SS_STRUCT , 0 , 0 , 0
} , { "struct" , "SFB_LIMITBUS" , 2 , 2 , sizeof ( SFB_LIMITBUS ) , SS_STRUCT
, 0 , 0 , 0 } , { "struct" , "SFB_COUNTERBUS" , 2 , 4 , sizeof (
SFB_COUNTERBUS ) , SS_STRUCT , 0 , 0 , 0 } , { "double" , "real_T" , 0 , 0 ,
sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , { "input" , rt_offsetof ( SFB_SIGNALBUS , input ) , 0 , 0 , 0 }
, { "upper_saturation_limit" , rt_offsetof ( SFB_LIMITBUS ,
upper_saturation_limit ) , 0 , 0 , 0 } , { "lower_saturation_limit" ,
rt_offsetof ( SFB_LIMITBUS , lower_saturation_limit ) , 0 , 0 , 0 } , {
"inputsignal" , rt_offsetof ( SFB_COUNTERBUS , inputsignal ) , 1 , 0 , 0 } ,
{ "limits" , rt_offsetof ( SFB_COUNTERBUS , limits ) , 2 , 0 , 0 } } ; static
const rtwCAPI_DimensionMap rtDimensionMap [ ] = { { rtwCAPI_SCALAR , 0 , 2 ,
0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.1 , 0.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
1 ] , 0 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 8 , rtRootInputs , 0 , rtRootOutputs , 0 } , {
rtBlockParameters , 8 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 3352122353U , 4159562089U , 1871902350U ,
3937603553U } , ( NULL ) , 0 , 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * sfbuilder_bususage_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void sfbuilder_bususage_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion (
( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void sfbuilder_bususage_host_InitializeDataMapInfo (
sfbuilder_bususage_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
