#include "Text.h"
#include <cmath>
#include <algorithm>

Text::Text(unsigned int t_screenSize, std::string t_message, unsigned int t_width) : TUIObject(t_screenSize), m_message(t_message)
{
    m_width = t_width;
    SetScreenSize(m_screenSize);
}

std::string Text::Draw() const
{
    std::string t_ret = "";
    
    for(unsigned int row = 0; row < m_height; row += 1)
    {
        t_ret += DrawRow(row) + "\n"; 
    }
                            
    return t_ret;
}

std::string Text::DrawRow(const unsigned int& t_row) const
{
    if(m_width*(t_row+1) < m_message.size())
        return m_message.substr(m_width*t_row, m_width) + FillWhiteSpace(m_screenSize - m_width);
    else if(m_width*t_row > m_message.size())
        return FillWhiteSpace(m_width)+ FillWhiteSpace(m_screenSize - m_width);
    else
        return m_message.substr(m_width*t_row, m_message.size() - m_width*t_row) + FillWhiteSpace(m_width*(t_row+1) - m_message.size())+ FillWhiteSpace(m_screenSize - m_width);
}

void Text::SetScreenSize(const unsigned int& t_screenSize)
{
    m_screenSize = t_screenSize;
    
    if(m_width > m_screenSize)
    {
        m_width = m_screenSize;
    }
    
    m_height = std::ceil((m_message.size()-1)/(double)m_width);
}