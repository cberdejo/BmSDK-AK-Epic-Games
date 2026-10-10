#pragma once

#include <Windows.h>
#include <cstdint>

namespace offsets {
    inline constexpr uint32_t TimeDateStampEpic = 0x6508B1CE;

    inline uintptr_t BaseAddress = 0;
    inline uintptr_t EngineLoopPreInit = 0;

    // Identifies the build from the PE header's TimeDateStamp
    inline void init() {
        BaseAddress = (uintptr_t)GetModuleHandle(NULL);

        auto dosHeader = (PIMAGE_DOS_HEADER)BaseAddress;
        auto ntHeaders = (PIMAGE_NT_HEADERS64)(BaseAddress + dosHeader->e_lfanew);

        switch (ntHeaders->FileHeader.TimeDateStamp) {
            case TimeDateStampEpic:
                EngineLoopPreInit = 0x5DEA60;
                break;
            default:
                // Steam is the fallback since it was the only supported build before Epic
                EngineLoopPreInit = 0x5B7220;
                break;
        }
    }
}
