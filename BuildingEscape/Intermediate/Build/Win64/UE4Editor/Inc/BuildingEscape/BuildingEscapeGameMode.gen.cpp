// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BuildingEscape.h"
#include "BuildingEscapeGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBuildingEscapeGameMode() {}
// Cross Module References
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_ABuildingEscapeGameMode_NoRegister();
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_ABuildingEscapeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_BuildingEscape();
// End Cross Module References
	void ABuildingEscapeGameMode::StaticRegisterNativesABuildingEscapeGameMode()
	{
	}
	UClass* Z_Construct_UClass_ABuildingEscapeGameMode_NoRegister()
	{
		return ABuildingEscapeGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ABuildingEscapeGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameMode,
				(UObject* (*)())Z_Construct_UPackage__Script_BuildingEscape,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "BuildingEscapeGameMode.h" },
				{ "ModuleRelativePath", "BuildingEscapeGameMode.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ABuildingEscapeGameMode>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ABuildingEscapeGameMode::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x0090028Cu,
				nullptr, 0,
				nullptr, 0,
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABuildingEscapeGameMode, 3588090414);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABuildingEscapeGameMode(Z_Construct_UClass_ABuildingEscapeGameMode, &ABuildingEscapeGameMode::StaticClass, TEXT("/Script/BuildingEscape"), TEXT("ABuildingEscapeGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABuildingEscapeGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
