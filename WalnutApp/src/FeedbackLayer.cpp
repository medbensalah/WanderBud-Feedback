#include "FeedbackLayer.h"

#include <iostream>

void FeedbackLayer::OnUIRender()
{
    ImGui::Begin("Hello", nullptr, ImGuiWindowFlags_NoResize);
    WanderBud::DrawHeader(m_Logo, m_Title);
    ImGui::Spacing();


    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
    ImGui::Text("Event :");
    ImGui::PopFont();
    ImGui::SameLine();
    ImGui::Text(m_EventName.c_str());

    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
    ImGui::Text("Date :");
    ImGui::PopFont();
    ImGui::SameLine();
    ImGui::Text(m_EventDate.c_str());

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();

    std::string qstHeader = "Question ";
    for (int i = 0; i < m_FormQuestions.size(); ++i)
    {
        WanderBud::DrawQuestion(
            (qstHeader + std::to_string(i + 1) + ":").c_str(), m_FormQuestions[i], &m_FormAnswers[i], i
        );
    }

    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
    ImGui::Text("Comment :");
    ImGui::PopFont();
    ImGui::Indent();
    ImGui::Text("Any thing you want to add ?");
    ImGui::Unindent();
    static char comment[1024] = "";
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 15.0f);
    ImGui::InputTextMultiline("##Comment", comment, 1024, ImVec2(ImGui::GetContentRegionAvail().x - 30.0f, 100),
                              ImGuiInputTextFlags_AllowTabInput);
    ImGui::SameLine();
    float lastxPos = ImGui::GetCursorPosX();
    
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();

    auto& style = ImGui::GetStyle();
    ImGui::SetCursorPosX(lastxPos - (style.FramePadding.x + style.ItemSpacing.x) * 2 - ImGui::CalcTextSize("Submit").x);
    if (ImGui::Button("Submit"))
    {
        if (IsFormValid())
        {
            memcpy(m_Comment, comment, 1024);
            Submit();
        } 
    }

    ImGui::End();

    ImGui::ShowDemoWindow();
}

bool FeedbackLayer::IsFormValid()
{
    bool result = true;
    for (int i = 0; i < m_FormAnswers.size(); i++)
    {
        if (m_FormAnswers[i] == 0)
        {
            return false;
        }
    }
    return true;
}

void FeedbackLayer::Submit()
{
}
