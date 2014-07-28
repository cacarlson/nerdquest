#ifndef TEXTENGINE_H_
#define TEXTENGINE_H_

#include <iostream>
#include <functional>
#include <map>
#include "IOEngine.h"

class TextEngine : public IOEngine
{
public:
    using IOEngine::IOEngine;
    
    virtual void printDialogue(const std::string& t_name, const std::string& t_message) override;
    
    virtual void printTitle(const std::string& t_title) override;
    
    virtual void printMessage(const std::string& t_message) override;
    
    virtual std::vector<unsigned int> printList(const std::vector<std::string>& t_list) override;
    
    virtual bool printTrueFalse(const std::string& t_top, const std::string& t_bottom) override;
    
    virtual bool printYesNo(const std::string& t_top, const std::string& t_bottom) override;
    
    //virtual void printScene();
    //virtual void printProfile();
    
private:
    std::string GetBoarder();
    
    void WaitForInput();
    
    void RegisterCallBack(const std::string& t_input, std::function<void(std::string)>);
    
    std::map<std::string, std::function<void(std::string)>> m_lookupTable;
    unsigned int m_consoleWidth = 50;
};

#endif //TEXTENGINE_H_