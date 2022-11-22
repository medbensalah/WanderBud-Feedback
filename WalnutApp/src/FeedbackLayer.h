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
        m_FormQuestions.push_back("How did you like the organisation in general?");
        m_FormQuestions.push_back("How did you like the communiccation before the event?");
        m_FormQuestions.push_back("How did you like the activities quality?");
        m_FormQuestions.push_back("How did you like the customer support?");

        for (int i = 0; i < m_FormQuestions.size(); i++)
        {
            m_FormAnswers.push_back(0);
        }

        m_EventName = "Event Name";
        m_EventDate = "XX/XX/XXXX";
    }

    void SetEventData(const std::string& eventName, const std::string& eventDate)
    {
        m_EventName = eventName;
        m_EventDate = eventDate;
    }
    
    virtual void OnUIRender() override;

private:
    bool IsFormValid();

    void Submit();
    
private:
    Walnut::Image m_Logo;
    Walnut::Image m_Title;
    ImVec4 m_TitleTint = { 1.0f, 1.0f, 1.0f, 1.0f };

    std::string m_EventName;
    std::string m_EventDate;

    std::vector<const char*> m_FormQuestions;
    std::vector<int> m_FormAnswers;
    char m_Comment[1024] = "";
};
