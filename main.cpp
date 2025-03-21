#include <iostream>
#include "WeaponNameGenerator.h"

int main()
{
    /*while (true) {



        std::cout << "stop generation?(y/n)\n";
        std::string givenAnswer;
        std::getline(std::cin, givenAnswer);
        if (givenAnswer.compare("y") == 0) {
            break;
        }
    }*/
    WeaponNameGenerator names;
    
    names.GenerateMelee();
    names.GenerateRanged();
}
