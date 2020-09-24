
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

bool quit = false;
int balance = 0;
int target = 0;

void change_target(){
    target = std::rand() % 100000;
    target = std::rand() % 100000;
    std::cout << "New target is " << target << std::endl;
    return;
}

void quit_game(){
    quit = true;
    
    if (balance < 0){
        std::cout << "You lost $" << -balance << ". Thanks for playing. Come again!" << std::endl;
    }
    else{
        std::cout << "You won $" << balance << ". Thanks for playing. Come again!" << std::endl;
    }
    std::cout << "Quitting game" << std::endl;
}

std::string get_user_input(){
    std::string user_input;
    std::cin >> user_input;
    return user_input;
}

bool is_number(std::string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 

int main(){

    std::srand(std::time(NULL));


    std::string user_input;


    change_target();

    std::cout << "\nWant to win a million dollars?\nIf so, guess the winning number (a number between 0 and 100000).\n" << std::endl;    

    while (!quit){

        std::cout << "\nInsert $1.00 and enter your number or 'q' to quit:" << std::endl;

        user_input = get_user_input();

        
        if (is_number(user_input)){
            int guess = stoi(user_input);
            balance -= 1;
            if (guess == target){
                std::cout << "YOU WIN!" << std::endl;
                balance += 1000000;
                quit_game();
            }
            else{
                std::cout << "Sorry, good guess, but not quite right. Do you want me to give you a hint (y|n)?" << std::endl;
                user_input = get_user_input();
                if (user_input == "y" || user_input == "Y"){
                    if (guess < target){
                        std::cout << "Your number is too low!" << std::endl;
                    }
                    else{
                        std::cout << "Your number is too high!" << std::endl;
                    }
                    balance -= 2;
                }
            }

        }
        else if (user_input == "q"){
            quit_game();
        }
        else{
            std::cout << "Invalid input: '" << user_input << "'" << std::endl;
        }
        
    }

    return 0;
}