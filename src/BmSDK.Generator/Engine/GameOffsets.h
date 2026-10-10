#pragma once

#include <Windows.h>
#include <cstdint>

namespace GameOffsets
{
    inline constexpr uint32_t TimeDateStampEpic = 0x6508B1CE;

    // Globals
    inline uintptr_t GObjects = 0;
    inline uintptr_t GNames = 0;
    inline uintptr_t StaticFindObject = 0;
    inline uintptr_t LoadPackage = 0;
    inline uintptr_t BeginLoad = 0;
    inline uintptr_t EndLoad = 0;
    inline uintptr_t CollectGarbage = 0;

    // UObject
    inline uintptr_t ProcessEvent = 0;

    // Identifies the build from the PE header's TimeDateStamp
    inline void Init(uintptr_t baseAddress)
    {
        auto dosHeader = (PIMAGE_DOS_HEADER)baseAddress;
        auto ntHeaders = (PIMAGE_NT_HEADERS64)(baseAddress + dosHeader->e_lfanew);

        switch (ntHeaders->FileHeader.TimeDateStamp)
        {
            case TimeDateStampEpic:
                GObjects = 0x347ACA4;
                GNames = 0x3A8E978;
                StaticFindObject = 0xF66230;
                LoadPackage = 0xF71760;
                BeginLoad = 0xF58020;
                EndLoad = 0xF6E5B0;
                CollectGarbage = 0xF56E80;
                ProcessEvent = 0xFBBCC0;
                break;
            default:
                // Steam is the fallback since it was the only supported build before Epic
                GObjects = 0x340CBE4;
                GNames = 0x3A208B8;
                StaticFindObject = 0xF3B7F0;
                LoadPackage = 0xF46DA0;
                BeginLoad = 0xF2D410;
                EndLoad = 0xF43BF0;
                CollectGarbage = 0xF2C280;
                ProcessEvent = 0xF90CD0;
                break;
        }
    }
}
