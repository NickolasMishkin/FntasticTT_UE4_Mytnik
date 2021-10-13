// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FntasticTT_Mytnik : ModuleRules
{
	public FntasticTT_Mytnik(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });
	}
}
