#include <array>
#include <iostream>

template<typename T, size_t n>
void print_array(std::array<T, n> arr)
{
	for (size_t i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
}

template <size_t N>
void multiply_array_element_if_below_limit(std::array<float, N>& input_array, float limit_value, float multiplier){
    for (auto& element : input_array){
        if (element < limit_value){
            element *= multiplier;
        }
    }
}
 
int main()
{
    std::array<float, 6> salaries { 700, 800, 900, 1000, 1100, 1200};
    float user_input_percentage;
    float user_input_limit_value;

    std::cout << "Enter salary increase percentage (e.g. 5%): ";
    std::cin >> user_input_percentage;
    std::cout << "Enter maximum increase limit (e.g. 1000): ";
    std::cin >> user_input_limit_value;


    std::cout << "Salaries before: ";
    print_array(salaries);

    multiply_array_element_if_below_limit(salaries, user_input_limit_value, user_input_percentage*0.01+1);

    std::cout << std::endl << "Salaries after: ";
    print_array(salaries);
    
 
    return 0;
}