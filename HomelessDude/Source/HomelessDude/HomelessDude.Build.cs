// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HomelessDude : ModuleRules
{
	public HomelessDude(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"ApparatusRuntime",
			"ECSCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}