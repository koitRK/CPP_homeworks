#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>


int get_random_int() {
    int rand_int = std::rand() % 100 + 1;
    return rand_int;
}

std::string request_file_name()
{
    std::string file_name;
    std::cout << "enter file name:" << std::endl;
    std::getline(std::cin, file_name);
    return file_name;
}


int main()
{
    std::srand(std::time(NULL));

    std::string file_name = request_file_name();
    if (file_name == ""){
        file_name = "Info.txt";
    }
    std::fstream myfile;
    myfile.open(file_name);


    if (myfile.is_open()){
        for (int i = 0; i < 20; i++){
            int rnd = get_random_int();
            myfile << rnd << ", ";
            std::cout << rnd << std::endl;
        }
        myfile.close();
    }
    else{
        return 1;
    }
    
    return 0;
}