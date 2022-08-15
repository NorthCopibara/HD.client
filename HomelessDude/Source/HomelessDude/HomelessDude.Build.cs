// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HomelessDude : ModuleRules
{
	public HomelessDude(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp17;
		PublicIncludePaths.AddRange(new string[]
		{
			"HomelessDude/Private"
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"ApparatusRuntime",
			"ECSCore",
			"HTTP",
			"Json",
			"JsonUtilities",
			"ALSV4_CPP"
		});
	}
}