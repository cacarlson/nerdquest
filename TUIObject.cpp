#include "TUIObject.h"

unsigned int TUIObject::GetWidth() const
{
    return m_width;
}

unsigned int TUIObject::GetHeight() const
{
    return m_height;
}

TUIObject::TUIObject(const unsigned int& t_screenSize)
{
    SetScreenSize(t_screenSize);
}

std::string TUIObject::FillWhiteSpace(const unsigned int& t_num) const
{
    return std::string(t_num, ' ');
}

void TUIObject::SetScreenSize(const unsigned int& t_screenSize)
{
    m_screenSize = t_screenSize;
    
    if(m_width > m_screenSize)
        m_width = m_screenSize;

}