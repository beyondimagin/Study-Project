#include <string.h>
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif
#include "sfbuilder_bus_accel_wrapper.h"
#include "sfbuilder_bus_bus.h"
extern void sfbuilder_bus_Start_wrapper ( void ) ; extern void
sfbuilder_bus_Outputs_wrapper ( const SFB_COUNTERBUS * u0 , const int32_T *
u1 , SFB_COUNTERBUS * y0 , int32_T * y1 ) ; extern void
sfbuilder_bus_Terminate_wrapper ( void ) ; void
sfbuilder_bus_Outputs_wrapper_accel ( const void * u0 , void * __u0BUS ,
const int32_T * u1 , void * y0 , void * __y0BUS , int32_T * y1 ) { ( * (
SFB_COUNTERBUS * ) __u0BUS ) . inputsignal . input = * ( ( int32_T * ) ( (
char * ) u0 ) ) ; ( * ( SFB_COUNTERBUS * ) __u0BUS ) . limits .
upper_saturation_limit = * ( ( int32_T * ) ( ( char * ) u0 + 8 ) ) ; ( * (
SFB_COUNTERBUS * ) __u0BUS ) . limits . lower_saturation_limit = * ( (
int32_T * ) ( ( char * ) u0 + 12 ) ) ; sfbuilder_bus_Outputs_wrapper ( (
SFB_COUNTERBUS * ) __u0BUS , u1 , ( SFB_COUNTERBUS * ) __y0BUS , y1 ) ; * ( (
int32_T * ) ( ( char * ) y0 ) ) = ( * ( SFB_COUNTERBUS * ) __y0BUS ) .
inputsignal . input ; * ( ( int32_T * ) ( ( char * ) y0 + 8 ) ) = ( * (
SFB_COUNTERBUS * ) __y0BUS ) . limits . upper_saturation_limit ; * ( (
int32_T * ) ( ( char * ) y0 + 12 ) ) = ( * ( SFB_COUNTERBUS * ) __y0BUS ) .
limits . lower_saturation_limit ; }
