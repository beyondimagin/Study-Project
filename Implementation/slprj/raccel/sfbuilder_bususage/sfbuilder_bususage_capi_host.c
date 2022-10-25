#include "sfbuilder_bususage_capi_host.h"
static sfbuilder_bususage_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        sfbuilder_bususage_host_InitializeDataMapInfo(&(root), "sfbuilder_bususage");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
