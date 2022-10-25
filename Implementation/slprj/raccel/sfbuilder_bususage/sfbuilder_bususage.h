#ifndef RTW_HEADER_sfbuilder_bususage_h_
#define RTW_HEADER_sfbuilder_bususage_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef sfbuilder_bususage_COMMON_INCLUDES_
#define sfbuilder_bususage_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sfbuilder_bus_accel_wrapper.h"
#endif
#include "sfbuilder_bususage_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME sfbuilder_bususage
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (6) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { SFB_COUNTERBUS eaeuhrc02t ; SFB_COUNTERBUS j0vikhhhoz ;
SFB_COUNTERBUS l1rfwvopfj ; int32_T hvyyu1lsai ; int32_T jjs2flljx3 ; int32_T
bctwqitgzv ; } B ; typedef struct { SFB_COUNTERBUS aytghwde2s ;
SFB_COUNTERBUS bcwuhs2hmz ; struct { void * LoggedData ; } bahj2bvmf1 ;
struct { void * LoggedData ; } a22vvppw0s ; int32_T a3ns25gzqu ; int32_T
lkj5j0uhm2 ; int32_T hgpael0gzw ; } DW ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
PulseGenerator1_Period ; real_T PulseGenerator1_Duty ; real_T
PulseGenerator1_PhaseDelay ; int32_T UnitDelay_InitialCondition ; int32_T
PreviousOutput_InitialCondition ; int32_T PulseGenerator1_Amp ; int32_T
lower_saturation_limit1_Value ; int32_T upper_saturation_limit1_Value ; } ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW
rtDW ; extern P rtP ; extern mxArray * mr_sfbuilder_bususage_GetDWork ( ) ;
extern void mr_sfbuilder_bususage_SetDWork ( const mxArray * ssDW ) ; extern
mxArray * mr_sfbuilder_bususage_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * sfbuilder_bususage_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
