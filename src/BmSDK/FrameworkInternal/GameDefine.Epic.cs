namespace BmSDK.Framework;

public sealed class GameDefineEpic : GameDefine
{
    public const uint TimeDateStamp = 0x6508B1CE;

    public override string Name => "Epic";

    // Globals
    public override IntPtr GNames => 0x3A8E978;
    public override IntPtr GObjObjects => 0x347ACA4;
    public override IntPtr GError => 0x3A8EB68;

    // app (global)
    public override IntPtr AppRealloc => 0xFCD870;
    public override IntPtr AppFree => 0xFCD890;
    public override IntPtr EngineTick => 0x5D9850;

    // UObject (static)
    public override IntPtr StaticFindObject => 0xF66230;
    public override IntPtr StaticConstructObject => 0xF71A70;
    public override IntPtr LoadPackage => 0xF71760;
    public override IntPtr CollectGarbage => 0xF56E80;

    // UObject (local)
    public override IntPtr ProcessEvent => 0xFBBCC0;
    public override IntPtr ProcessInternal => 0xFBBB20;
    public override IntPtr CallFunction => 0xFC0A90;
    public override IntPtr AddObject => 0xF63450;
    public override IntPtr ConditionalDestroy => 0xF638D0;
    public override IntPtr FindFunction => 0xF685C0;
    public override IntPtr ConditionalPostLoad => 0xF6DAB0;
    public override IntPtr AddToRoot => 0xF58050;
    public override IntPtr RemoveFromRoot => 0xF58070;

    // UClass (local)
    public override IntPtr GetDefaultObject => 0xFBD860;

    // UWorld (local)
    public override IntPtr SpawnActor => 0xAF45A0;

    // FWindowsViewport (local)
    public override IntPtr ProcessDeferredMessage => 0x1087F80;

    // FName (local)
    public override IntPtr NameInit => 0xF62750;

    // FString (local)
    public override IntPtr StringCtor => 0x41A0;
}
