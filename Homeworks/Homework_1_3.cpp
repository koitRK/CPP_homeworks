
#include <iostream>

int main(){
    
    std::string user_input;
    int maximum_warm_temp = 25;
    int minimum_warm_temp = 10;
    bool quit = false;

    while (!quit){
        std::cout << "Enter temperature or press 'q' to quit" << std::endl;
        std::cin >> user_input;

        if (user_input == "q" || user_input == "Q"){
            quit = true;
            break;
        }
        std::cout << "user pressed: " << user_input << std::endl;
        float user_input_temperature = std::stof(user_input);

        if (user_input_temperature > maximum_warm_temp){
            std::cout << "HOT!" << std::endl;
        }
        else if (user_input_temperature < minimum_warm_temp){
            std::cout << "COLD!" << std::endl;
        }
        else{
            std::cout << "WARM!" << std::endl;
        }
    }

    return 0;
}