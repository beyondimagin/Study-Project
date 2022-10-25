#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "SFB_LIMITBUS" , 14 , 8 } , {
"SFB_SIGNALBUS" , 15 , 8 } , { "SFB_COUNTERBUS" , 16 , 16 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( void * ) , sizeof ( action_T ) , 2
* sizeof ( uint32_T ) , sizeof ( SFB_LIMITBUS ) , sizeof ( SFB_SIGNALBUS ) ,
sizeof ( SFB_COUNTERBUS ) } ; static const char_T * rtDataTypeNames [ ] = {
"real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "SFB_LIMITBUS" , "SFB_SIGNALBUS" ,
"SFB_COUNTERBUS" } ; static DataTypeTransition rtBTransitions [ ] = { { (
char_T * ) ( & rtB . eaeuhrc02t ) , 16 , 0 , 3 } , { ( char_T * ) ( & rtB .
hvyyu1lsai ) , 6 , 0 , 3 } , { ( char_T * ) ( & rtDW . aytghwde2s ) , 16 , 0
, 2 } , { ( char_T * ) ( & rtDW . bahj2bvmf1 . LoggedData ) , 11 , 0 , 2 } ,
{ ( char_T * ) ( & rtDW . a3ns25gzqu ) , 6 , 0 , 3 } } ; static
DataTypeTransitionTable rtBTransTable = { 5U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
PulseGenerator1_Period ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtP .
UnitDelay_InitialCondition ) , 6 , 0 , 5 } } ; static DataTypeTransitionTable
rtPTransTable = { 2U , rtPTransitions } ;
