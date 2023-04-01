
using UnrealBuildTool;
using System.Collections.Generic;

public class KiberPavlov : TargetRules
{
    public KiberPavlov(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("KiberPavlov"); 
    }
}