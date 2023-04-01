using UnrealBuildTool;
using System.Collections.Generic;

public class KiberPavlovServerTarget : TargetRules //Change this line according to the name of your project
{
    public KiberPavlovServerTarget(TargetInfo Target) : base(Target) //Change this line according to the name of your project
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("KiberPavlov"); //Change this line according to the name of your project
    }
}