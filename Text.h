#ifndef TEXT_H_
#define TEXT_H_

#include <iostream>
#include "TUIObject.h"

class Text : public TUIObject
{
public:
    
    Text(unsigned int t_screenSize, std::string t_message = "", unsigned int t_width = 0);
    
    virtual std::string Draw() const override;
    virtual std::string DrawRow(const unsigned int& t_row) const override;
    
    virtual void SetScreenSize(const unsigned int& t_screenSize) override;
    
private:
    std::string m_message;
};

#endif //TEXT_H_