// NativeAdd.cpp : Defines the exported functions for the DLL application.
//

#include "NativeAdd.h"
#include <stdlib.h>

extern "C"
{
	FREObject doAdd(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) 
	{
		int32_t one, two, sum;
		FREObject result;

		FREGetObjectAsInt32(argv[0], &one);
		FREGetObjectAsInt32(argv[1], &two);

		sum = one + two;

		FRENewObjectFromInt32(sum, &result);

		return result;
	}

	void ContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions)
	{
		*numFunctions = 1;
		FRENamedFunction* func = (FRENamedFunction*)malloc(sizeof(FRENamedFunction)*(*numFunctions));
	
		func[0].name = (const uint8_t*)"doAdd";
		func[0].functionData = NULL;
		func[0].function = &doAdd;

		*functions = func;
	}

	void ContextFinalizer(FREContext ctx) 
	{
		return;
	}

	void ExtInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) 
	{
		*ctxInitializer = &ContextInitializer;
		*ctxFinalizer   = &ContextFinalizer;
	}

	void ExtFinalizer(void* extData) 
	{
		return;
	}
}

