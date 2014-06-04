#include "FlashRuntimeExtensions.h"

extern "C"
{
	__declspec(dllexport) void ExtInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet, FREContextFinalizer* ctxFinalizerToSet);

	__declspec(dllexport) void ExtFinalizer(void* extData);

	__declspec(dllexport) FREObject doAdd(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
}