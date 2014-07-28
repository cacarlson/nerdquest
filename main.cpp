#include "IOEngine.h"
#include "TextEngine.h"
#include "Text.h"
#include "BasicBorder.h"
#include "Row.h"

int main()
{
    std::shared_ptr<IOEngine> spEngine(std::make_shared<TextEngine>());
    
    spEngine->printMessage("Hello World!hhhhhhhhjkl;jfkladsjk;asd;fjkals;djfkl;asdjfkla;sjfklads;fjklasjfkl;asjfkla;sjdfkl;sadjkf;asdfjklas;dfjkl;asjfklas;jfklas;djfkl;sajdkfl;ajskfl;dsjfkl;asdjfklasdjfklas;jdfklas;jdfkla;sfjkldsa;jfkla;sdjfklda;sfjal;fjsadkl;");
    
    if(spEngine->printTrueFalse("Hell yeah!", "No way! Oh yes. Let's do this this. sdklfja sfklasd;f jakl;fjakls;fjakls;fjklsajfklsajfkl;asfjklsajfkl;asj"))
        std::cout << "Okay!" << std::endl;
    
    std::cout << BasicBorder(50, std::make_shared<Text>(50, "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789", 50)).Draw();
    
    BasicBorder t_border = BasicBorder(50, std::make_shared<Text>(50, "012345678901234567890123456789", 50));
    std::cout << t_border.DrawRow(0) << std::endl;
    std::cout << t_border.DrawRow(1) << std::endl;
    std::cout << t_border.DrawRow(2) << std::endl;
    
    std::cout << BasicBorder(70, std::make_shared<Row>(50, std::make_shared<BasicBorder>(t_border), std::make_shared<Text>(50, "012345678901234567890123456789", 50), '|')).Draw();
    return 0;
}