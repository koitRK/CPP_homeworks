#include <iostream>
#include <vector>
#include <string>


char request_character()
{
    std::string input;
    std::cout << "enter character:" << std::endl;
    std::getline(std::cin, input);
    char firstLetter = input.at(0);
    return firstLetter;
}

int main()
{
    std::string n1 = "Aadam";
    std::string n2 = "Anna";
    std::string n3 = "Jaan";
    std::string n4 = "Karl";
    std::string n5 = "Kristjan";

    std::vector<std::string*> nimed{&n1, &n2, &n3, &n4, &n5};

    char user_char = request_character();

    std::string** pp = &nimed[0];

    for (int i = 0; i<nimed.size(); i++){
        if ((**pp).at(0) == user_char){
            std::cout << **pp << std::endl;
        }
        pp += 1;
    }

    return 0;
}