#define HL_NAME(n) hlimgui_##n

#include <hl.h>
#include <vector>
#include "imgui/imgui.h"
#include "utils.h"

HL_PRIM void HL_NAME(load_ini_settings_from_disk)(vstring* ini_filename)
{
    ImGui::LoadIniSettingsFromDisk(convertString(ini_filename));
}

HL_PRIM void HL_NAME(load_ini_settings_from_memory)(vstring* ini_data, int* ini_size)
{
    ImGui::LoadIniSettingsFromMemory(convertString(ini_data), (size_t)(convertPtr(ini_size, 0)));
}

HL_PRIM void HL_NAME(save_ini_settings_to_disk)(vstring* ini_filename)
{
    ImGui::SaveIniSettingsToDisk(convertString(ini_filename));
}

HL_PRIM vbyte* HL_NAME(save_ini_settings_to_memory)(int* out_ini_size)
{
    size_t _out_ini_size;
    vbyte* result = getVByteFromCStr(ImGui::SaveIniSettingsToMemory(&_out_ini_size));
    if (out_ini_size != nullptr)
    {
        *out_ini_size = (int)_out_ini_size;
    }
    return result;
}

DEFINE_PRIM(_VOID, load_ini_settings_from_disk, _STRING);
DEFINE_PRIM(_VOID, save_ini_settings_to_disk, _STRING);
DEFINE_PRIM(_VOID, load_ini_settings_from_memory, _STRING _REF(_I32));
DEFINE_PRIM(_BYTES, save_ini_settings_to_memory, _REF(_I32));
