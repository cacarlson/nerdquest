#include "TextEngine.h"

#include <sstream>

void TextEngine::WaitForInput()
{
    std::string t_response;
    while(true)
    {
        m_output << "> ";
        std::getline(std::cin, t_response);
        
        if(m_lookupTable.count(t_response) == 1) //because I just can't assume 1 is true!
        {
            m_lookupTable[t_response]("");
        }
    }
}

void TextEngine::RegisterCallBack(const std::string& t_input, std::function<void(std::string)> func)
{
    m_lookupTable[t_input] = func;
}

std::string TextEngine::GetBoarder()
{
    std::string messageBoarder = "+";
    for(unsigned int index = 1; index < m_consoleWidth; ++index)
        messageBoarder += "-";
    messageBoarder += "+";
    
    return messageBoarder + "\n" + messageBoarder;
}

void TextEngine::printDialogue(const std::string& t_name, const std::string& t_message)
{
    
}

void TextEngine::printTitle(const std::string& t_title)
{
    m_output << std::endl;
    
    
    m_output << std::endl;
}

void TextEngine::printMessage(const std::string& t_message)
{
    m_output << std::endl <<  GetBoarder() << std::endl;
    
    m_output << std::endl;
    
    for(unsigned int line_pos = 0; line_pos < t_message.size(); line_pos += m_consoleWidth)
    {
        if (line_pos + m_consoleWidth > t_message.size())
            m_output.write(t_message.substr(line_pos, t_message.size()).c_str(), t_message.size() - line_pos);
        else
        {
            m_output.write(t_message.substr(line_pos, line_pos+m_consoleWidth).c_str(), m_consoleWidth);
            m_output << std::endl;
        }
    }
    
    m_output << std::endl;
    
    m_output << std::endl << GetBoarder() << std::endl;
}

std::vector<unsigned int> TextEngine::printList(const std::vector<std::string>&t_list)
{
    return std::vector<unsigned int>();
}

bool TextEngine::printTrueFalse(const std::string& t_top, const std::string& t_bottom)
{
    m_output << std::endl;
    std::string trueMessage =  "[True]  " + t_top;
    for(unsigned int line_pos = 0; line_pos < trueMessage.size(); line_pos += m_consoleWidth)
    {
        if (line_pos + m_consoleWidth > trueMessage.size())
            m_output.write(trueMessage.substr(line_pos, trueMessage.size()).c_str(), trueMessage.size() - line_pos);
        else
            m_output.write(trueMessage.substr(line_pos, line_pos+m_consoleWidth).c_str(), m_consoleWidth);

        m_output << std::endl;

    }
    m_output << std::endl;

    std::string falseMessage =  "[False] " + t_bottom;
    for(unsigned int line_pos = 0; line_pos < falseMessage.size(); line_pos += m_consoleWidth)
    {
        if (line_pos + m_consoleWidth > falseMessage.size())
            m_output.write(falseMessage.substr(line_pos, falseMessage.size()).c_str(), falseMessage.size() - line_pos);
        else
            m_output.write(falseMessage.substr(line_pos, line_pos+m_consoleWidth).c_str(), m_consoleWidth);
        
        m_output << std::endl;
    }
    m_output << std::endl;
    
    std::string t_response;
    
    while(true)
    {
        m_output << "> ";
        m_input >> t_response;
        if(t_response == "T" || t_response == "t" || t_response == "True" || t_response == "true")
            return true;
        else if(t_response == "F" || t_response == "f" || t_response == "True" || t_response == "true" )
            return false;
    }
}

bool TextEngine::printYesNo(const std::string& t_top, const std::string& t_bottom)
{
    return false; 
}