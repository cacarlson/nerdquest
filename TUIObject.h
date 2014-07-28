#ifndef TUIOBJECT_H_
#define TUIOBJECT_H_

#include <iostream> 
#include <string>

class TUIObject
{
public:
    
    TUIObject(const unsigned int& t_screenSize);
    
    virtual std::string Draw() const = 0;
    virtual std::string DrawRow(const unsigned int& t_row) const = 0;
    
    std::string FillWhiteSpace(const unsigned int& t_num) const;
    
    virtual void SetScreenSize(const unsigned int& t_screenSize);
    
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;
    
protected:
    unsigned int m_screenSize;
    unsigned int m_width;
    unsigned int m_height; 
};

#endif //TUIOBJECT_H_