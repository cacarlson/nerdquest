#ifndef BASICBOARDER_H_
#define BASICBOARDER_H_

#include <iostream>
#include "Border.h"

class BasicBorder : public Border
{
public:
    
    using Border::Border; 
    
    virtual std::string Draw() const override;
    virtual std::string DrawRow(const unsigned int& t_row) const override;
    
    virtual void SetScreenSize(const unsigned int& t_screenSize) override;
    
private:
    std::string GetBorder() const;
};

#endif //BASICBOARDER_H_