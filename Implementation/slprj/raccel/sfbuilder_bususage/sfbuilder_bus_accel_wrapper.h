#ifndef _SFBUILDER_BUS_ACCEL_WRAPPER_H_
#define _SFBUILDER_BUS_ACCEL_WRAPPER_H_
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif
#ifdef __cplusplus
#define SFB_EXTERN_C extern "C"
#else
#define SFB_EXTERN_C extern
#endif
SFB_EXTERN_C void sfbuilder_bus_Outputs_wrapper_accel ( const void * u0 ,
void * __u0BUS , const int32_T * u1 , void * y0 , void * __y0BUS , int32_T *
y1 ) ;
#undef SFB_EXTERN_C
#endif
