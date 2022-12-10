// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPSGameJam2022 : ModuleRules
{
	public FPSGameJam2022(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
