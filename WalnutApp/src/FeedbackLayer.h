#pragma once

#include "Walnut/Layer.h"
#include "DrawingHelpers.h"

class FeedbackLayer : public Walnut::Layer
{
public:
    FeedbackLayer()
    :    m_Logo(Walnut::Image("Resources/Logo.png")),
    m_Title(Walnut::Image("Resources/Title.png"))
    {
        
    }
    virtual void OnUIRender() override;

private:
    Walnut::Image m_Logo;
    Walnut::Image m_Title;
    ImVec4 m_TitleTint = { 1.0f, 1.0f, 1.0f, 1.0f };
};
