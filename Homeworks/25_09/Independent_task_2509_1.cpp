
#include <iostream>
#include <array>


std::string get_user_input()
{
    std::string user_input;
    std::cin >> user_input;
    return user_input;
}


bool is_number(std::string s) 
{ 
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) == false)
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


template<size_t n>
int count_odd_numbers_in_array(std::array<int, n> arr)
{
    int odd_counter = 0;

    for (size_t i = 0; i<n; i++)
    {
        if (arr[i] % 2 == 1)
        {
            odd_counter += 1;
        }
    }
    return odd_counter;
}


int main()
{
    std::array<int, 5> integer_array;
    std::string user_input;


    for (int i = 0; i<5; i++)
    {
        std::cout << "Enter " << i+1 << ". integer:" << std::endl;
        user_input = get_user_input();

        if (!is_number(user_input))
        {
            std::cout << "Invalid value. Enter " << i+1 << ". integer:" << std::endl;
            i--;
        }
        else
        {
            integer_array[i] = stoi(user_input);
        }
    }


    print_array(integer_array);
    int odd_count = count_odd_numbers_in_array(integer_array);
    int even_count = integer_array.size() - odd_count;
    std::cout << "Found " << odd_count << " odd and " << even_count << " even numbers" << std::endl;

    return 0;
}