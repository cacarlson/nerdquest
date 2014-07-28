#ifndef ROW_H_
#define ROW_H_

#include <iostream>
#include "TUIObject.h"

class Row : public TUIObject
{
public:
    
    Row(unsigned int t_screenSize, std::shared_ptr<TUIObject> t_lhs, std::shared_ptr<TUIObject> t_rhs, char t_devider = ' ');
    
    virtual std::string Draw() const override;
    
    virtual std::string DrawRow(const unsigned int& t_row) const override;
    
    virtual void SetScreenSize(const unsigned int& t_screenSize) override;
    
private:
    
    std::shared_ptr<TUIObject> m_lhs;
    std::shared_ptr<TUIObject> m_rhs;
    
    char m_devider = ' ';
};

#endif //ROW_H_