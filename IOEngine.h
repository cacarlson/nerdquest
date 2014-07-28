#ifndef IOENGINE_H_
#define IOENGINE_H_

#include <iostream>
#include <vector>
#include <string>
#include <functional> 

class IOEngine
{
public:
    IOEngine(std::ostream& output = std::cout, std::istream& input = std::cin): m_output(output), m_input(input)
    {};
    
    virtual void printDialogue(const std::string& t_name, const std::string& t_message) = 0;
    
    virtual void printTitle(const std::string& t_title) = 0;
    
    virtual void printMessage(const std::string& t_message) = 0;
    
    virtual std::vector<unsigned int> printList(const std::vector<std::string>& t_list) = 0;
    
    virtual bool printTrueFalse(const std::string& t_top, const std::string& t_bottom) = 0;
    
    virtual bool printYesNo(const std::string& t_top, const std::string& t_bottom) = 0;
    
    //virtual void printScene();
    //virtual void printProfile();
protected:
    std::ostream& m_output;
    
    std::istream& m_input;
};

#endif //IOENGINE_H_