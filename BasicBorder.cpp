#include "BasicBorder.h" 

std::string BasicBorder::GetBorder() const
{
    std::string messageBoarder = "+";
    for(unsigned int index = 1; index < m_screenSize-1; ++index)
        messageBoarder += "-";
    messageBoarder += "+";
    
    return messageBoarder;
}

std::string BasicBorder::Draw() const
{
    std::string t_border = GetBorder() + "\n";
    return t_border  + m_contents->Draw() + t_border;
}

std::string BasicBorder::DrawRow(const unsigned int& t_row) const
{
    if(t_row == 0 || t_row == m_contents->GetHeight()+1)
        return GetBorder();
    else
        return m_contents->DrawRow(t_row-1);
}

void BasicBorder::SetScreenSize(const unsigned int& t_screenSize)
{
    m_screenSize = t_screenSize;
    
    if(m_width > m_screenSize)
        m_width = m_screenSize;
    
    m_contents->SetScreenSize(m_screenSize);
    
    m_height = m_contents->GetHeight() + 2;
}