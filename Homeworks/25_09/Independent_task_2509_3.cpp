
#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>


int get_random_int(){
    int rand_int = std::rand() % 80 + 1;
    return rand_int;
}


template<typename T, size_t n>
void print_array(std::array<T, n> arr)
{
	for (size_t i = 0; i < n; i++)
    {
	    std::cout << arr[i] << ' ';
    }
}


int main()
{
    std::srand(std::time(NULL));

    std::array<int, 20> int_array;
    int new_rand;

    for (int i = 0; i<20; i++)
    {
        new_rand = get_random_int();
        
        if(std::find(int_array.begin(), int_array.end(), new_rand) != int_array.end()) 
        {
            i--;
        } else {
            int_array[i] = new_rand;
        }

    }

    print_array(int_array);

    std::array<int, 20> sorted_array = int_array;
    std::sort(sorted_array.begin(), sorted_array.end(), std::greater<int>());


    std::ofstream myfile;
    myfile.open ("lotto_numbers.txt");
    myfile << "Lotto numbers in sorted order: ";

    for (size_t i=0; i<sorted_array.size(); i++)
    {
        myfile << std::to_string(sorted_array[i]) + " ";
    }
    myfile.close();


    return 0;
}