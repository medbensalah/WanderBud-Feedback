#include "Walnut/Application.h"
#include "Walnut/Image.h"

namespace WanderBud
{
    static void SetImGuiStyle();
    static void DrawHeader(const Walnut::Image& image, const Walnut::Image& title, ImVec4 tint = {1.0f,1.0f,1.0f,1.0f});

    
}


void WanderBud::SetImGuiStyle()
{
    ImGuiStyle* style = &ImGui::GetStyle();

    style->WindowPadding = ImVec2(7, 5);
    style->FramePadding = ImVec2(7, 3);
    style->CellPadding = ImVec2(7, 0);
    style->ItemSpacing = ImVec2(7, 3);
    style->ItemInnerSpacing = ImVec2(5, 5);
    style->TouchExtraPadding = ImVec2(0, 0);

    style->IndentSpacing = 15.0f;
    style->ScrollbarSize = 10.0f;
    style->GrabMinSize = 3.0f;

    //Borders
    style->WindowBorderSize = 1.0f;
    style->ChildBorderSize = 1.0f;
    style->PopupBorderSize = 1.0f;
    style->FrameBorderSize = 0.0f;
    style->TabBorderSize = 1.0f;

    //Rounding
    style->WindowRounding = 10.0f;
    style->ChildRounding = 0.0f;
    style->FrameRounding = 5.0f;
    style->PopupRounding = 10.0f;
    style->ScrollbarRounding = 10.0f;
    style->GrabRounding = 5.0f;
    style->LogSliderDeadzone = 5.0f;
    style->TabRounding = 5.0f;

    //Alignment
    style->WindowTitleAlign = ImVec2(0.02f, 0.02f);
    style->WindowMenuButtonPosition = ImGuiDir_Left;
    style->ColorButtonPosition = ImGuiDir_Left;
    style->ButtonTextAlign = ImVec2(0.5f, 0.5f);

    //Safe area
    style->DisplaySafeAreaPadding = ImVec2(5, 5);

    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text] = ImVec4(0.870f, 0.870f, 0.870f, 1.000f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.540f, 0.540f, 0.540f, 1.000f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.100f, 0.100f, 0.100f, 1.000f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.150f, 0.150f, 0.150f, 1.000f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.150f, 0.150f, 0.150f, 0.900f);
    colors[ImGuiCol_Border] = ImVec4(0.040f, 0.040f, 0.040f, 1.000f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.000f, 0.000f, 0.000f, 0.710f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.062f, 0.062f, 0.062f, 1.000f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.000f, 0.000f, 0.490f, 1.000f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.000f, 0.000f, 0.350f, 1.000f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.130f, 0.130f, 0.130f, 1.000f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.060f, 0.060f, 0.060f, 1.000f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.130f, 0.130f, 0.130f, 1.000f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.130f, 0.130f, 0.130f, 1.000f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.070f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(1.000f, 1.000f, 1.000f, 0.130f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.560f, 0.560f, 0.560f, 1.000f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.800f, 0.800f, 0.800f, 0.900f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.690f, 0.690f, 0.700f, 1.000f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.000f, 0.000f, 0.490f, 1.000f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.000f, 0.000f, 0.350f, 1.000f);
    colors[ImGuiCol_Button] = ImVec4(0.060f, 0.060f, 0.060f, 1.000f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.000f, 0.000f, 0.490f, 1.000f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.000f, 0.000f, 0.350f, 1.000f);
    colors[ImGuiCol_Header] = ImVec4(0.030f, 0.030f, 0.030f, 1.000f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.000f, 0.000f, 0.490f, 1.000f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.000f, 0.000f, 0.350f, 0.880f);
    colors[ImGuiCol_Separator] = ImVec4(0.060f, 0.060f, 0.060f, 1.000f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.000f, 0.000f, 0.490f, 1.000f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.000f, 0.000f, 0.350f, 1.000f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.020f, 0.000f, 0.310f, 1.000f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.000f, 0.000f, 0.490f, 1.000f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.000f, 0.000f, 0.350f, 1.000f);
    colors[ImGuiCol_Tab] = ImVec4(0.060f, 0.060f, 0.060f, 1.000f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.290f, 0.290f, 0.290f, 1.000f);
    colors[ImGuiCol_TabActive] = ImVec4(0.220f, 0.220f, 0.220f, 1.000f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.280f, 0.280f, 0.280f, 1.000f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.200f, 0.200f, 0.200f, 1.000f);
    colors[ImGuiCol_DockingPreview] = ImVec4(0.000f, 0.000f, 0.490f, 1.000f);
    colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.100f, 0.100f, 0.100f, 1.000f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.890f, 0.890f, 0.890f, 0.630f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.250f, 1.000f, 0.000f, 1.000f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.890f, 0.890f, 0.890f, 0.630f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.250f, 1.000f, 0.000f, 1.000f);
    colors[ImGuiCol_TableHeaderBg] = ImVec4(0.060f, 0.060f, 0.060f, 1.000f);
    colors[ImGuiCol_TableBorderStrong] = ImVec4(0.060f, 0.060f, 0.060f, 1.000f);
    colors[ImGuiCol_TableBorderLight] = ImVec4(0.210f, 0.210f, 0.210f, 1.000f);
    colors[ImGuiCol_TableRowBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.060f);
    colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.000f, 1.000f, 1.000f, 0.060f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.000f, 0.000f, 0.350f, 1.000f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(0.090f, 0.540f, 0.000f, 1.000f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.260f, 0.590f, 0.980f, 1.000f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 1.000f, 1.000f, 0.700f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800f, 0.800f, 0.800f, 0.200f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.710f);


    ImGuiColorEditFlags flags = ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoSidePreview |
        ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_PickerHueWheel |
        ImGuiColorEditFlags_NoSidePreview;

    ImGui::SetColorEditOptions(flags);
}


void WanderBud::DrawHeader(const Walnut::Image& image, const Walnut::Image& title, ImVec4 tint)
{
    // Draw the header
    ImGui::Image(image.GetDescriptorSet(), ImVec2{128.0f, 128.0f});

    ImGui::SameLine();
    
    // Draw the header
    float maxHeight = 128.0f;
    float titleHeight = maxHeight;
    float titleWidth = title.GetWidth() * (titleHeight / title.GetHeight());

    float availableWidth = ImGui::GetContentRegionAvail().x;
    if (titleWidth > availableWidth)
    {
        titleWidth = availableWidth - 20.0f;
        titleHeight = title.GetHeight() * (titleWidth / title.GetWidth());
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + (maxHeight - titleHeight) / 2.0f);
    }
    ImGui::Image(title.GetDescriptorSet(), ImVec2{titleWidth, titleHeight}, ImVec2{0.0f, 0.0f}, ImVec2{1.0f, 1.0f}, tint);

    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
    ImGui::Text("testing font !!!");
    ImGui::PopFont();
    ImGui::Text("testing font !!!");
    
}
