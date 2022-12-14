#ifndef RTW_HEADER_sfbuilder_bususage_types_h_
#define RTW_HEADER_sfbuilder_bususage_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_SFB_LIMITBUS_
#define DEFINED_TYPEDEF_FOR_SFB_LIMITBUS_
typedef struct { int32_T upper_saturation_limit ; int32_T
lower_saturation_limit ; } SFB_LIMITBUS ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_SFB_SIGNALBUS_
#define DEFINED_TYPEDEF_FOR_SFB_SIGNALBUS_
typedef struct { int32_T input ; uint8_T sl_padding0 [ 4 ] ; } SFB_SIGNALBUS
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_SFB_COUNTERBUS_
#define DEFINED_TYPEDEF_FOR_SFB_COUNTERBUS_
typedef struct { SFB_SIGNALBUS inputsignal ; SFB_LIMITBUS limits ; }
SFB_COUNTERBUS ;
#endif
typedef struct P_ P ;
#endif
