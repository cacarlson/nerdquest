#ifndef BORDER_H_
#define BORDER_H_

#include <iostream>
#include "TUIObject.h"

class Border : public TUIObject
{
public:
    
    Border(unsigned int t_screenSize, std::shared_ptr<TUIObject> t_object) : TUIObject(t_screenSize), m_contents(t_object) { m_contents->SetScreenSize(t_screenSize); };
    
    virtual std::string Draw() const = 0;
    virtual std::string DrawRow(const unsigned int& t_row) const = 0;
    
    virtual void SetScreenSize(const unsigned int& t_screenSize) = 0;
    
protected:
    std::shared_ptr<TUIObject> m_contents;
};

#endif //BORDER_H_