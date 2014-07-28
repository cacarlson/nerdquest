
#include "Row.h"
#include <cmath>

Row::Row(unsigned int t_screenSize, std::shared_ptr<TUIObject> t_lhs, std::shared_ptr<TUIObject> t_rhs, char t_devider) : TUIObject(t_screenSize), m_lhs(t_lhs), m_rhs(t_rhs), m_devider(t_devider)
{
    SetScreenSize(m_screenSize);
}

std::string Row::Draw() const
{
    std::string t_ret = "";
    for(unsigned int row = 0; row < m_height; ++row)
    {
        t_ret += DrawRow(row) + "\n";
    }
    
    return t_ret;
}

std::string Row::DrawRow(const unsigned int& t_row) const
{
    return m_lhs->DrawRow(t_row) + m_devider + m_rhs->DrawRow(t_row);
}

void Row::SetScreenSize(const unsigned int& t_screenSize)
{
    m_screenSize = t_screenSize;
    
    if(m_width > m_screenSize)
        m_width = m_screenSize;
    
    m_lhs->SetScreenSize(std::ceil((m_screenSize)/2.0));
    m_rhs->SetScreenSize(std::floor((m_screenSize)/2.0)-1);
    
    m_height = std::max(m_lhs->GetHeight(), m_rhs->GetHeight());
}
