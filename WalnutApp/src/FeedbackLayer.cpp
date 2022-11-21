#include "FeedbackLayer.h"

void FeedbackLayer::OnUIRender()
{
    ImGui::Begin("Hello");
    WanderBud::DrawHeader(m_Logo, m_Title);
    ImGui::End();

    ImGui::ShowDemoWindow();
}
