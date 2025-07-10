#pragma once

#include "INV_ItemManifest.h"
#include "StructUtils/InstancedStruct.h"

template<>
struct TBaseStructure<FINV_ItemManifest>
{
	static UScriptStruct* Get()
	{
		return FINV_ItemManifest::StaticStruct();
	}
};