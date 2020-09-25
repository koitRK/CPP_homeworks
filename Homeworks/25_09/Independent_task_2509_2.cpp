
#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>


std::string get_user_input()
{
    std::string user_input;
    std::cin >> user_input;
    return user_input;
}


bool is_float(std::string s) 
{ 
    if (std::count(s.begin(), s.end(), '.') > 1)
    {
        return false;
    };
    
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) == false && s[i] != '.')
        {
            return false; 
        }
    }   
    return true; 
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

    std::array<float, 6> float_array;
    std::string user_input;
    std::string user_name;

    float max_result;
    float second_max_result;

    int a = 1;
    int b = 2;

    std::cout << "Enter your name:" << std::endl;
    std::cin >> user_name;

    for (int i = 0; i<6; i++)
    {
        std::cout << "Enter " << i+1 << ". result:" << std::endl;
        user_input = get_user_input();

        if (!is_float(user_input))
        {
            std::cout << "Invalid value. Enter " << i+1 << ". result (float):" << std::endl;
            i--;
        }
        else
        {
            float_array[i] = stof(user_input);
            if (i > 0 && float_array[i]-float_array[i-1]>0){
                std::cout << "This result is " << float_array[i]-float_array[i-1] << "m better than previous" << std::endl;
            }
            else if(i > 0){
                std::cout << "This result is " << float_array[i-1]-float_array[i] << "m worse than previous" << std::endl;
            }
        }
    }

    std::array<float, 6> sorted_array = float_array;
    std::sort(sorted_array.begin(), sorted_array.end(), std::greater<float>());

    max_result = sorted_array[0];
    second_max_result = sorted_array[1];

    std::cout << "Maximum result is: " << max_result << "m, Second max result is: " << second_max_result << "m" << std::endl;

    std::ofstream myfile;
    myfile.open (user_name + "_results.txt");
    myfile << "Player: " + user_name + "\nResults in throw order: ";

    for (size_t i=0; i<float_array.size(); i++)
    {
        myfile << std::to_string(float_array[i]) + " ";
    }
    myfile.close();


    return 0;
}