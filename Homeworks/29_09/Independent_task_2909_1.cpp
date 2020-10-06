#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <iterator>
#include <sstream>
#include <algorithm>



template <typename Out>
void split2(const std::string& s, char delim, Out result) 
{
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = std::stof(item);
    }
}

std::vector<float> split(const std::string& s, char delim) 
{
    std::vector<float> elems;
    split2(s, delim, std::back_inserter(elems));
    return elems;
}


std::string request_file_name()
{
    std::string file_name;
    std::cout << "enter file name:" << std::endl;
    std::cin >> file_name;
    return file_name;
}


template<typename T>
void print_vector(std::vector<T> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}


std::vector<std::string> read_file(std::string file_name)
{
    std::ifstream myfile(file_name);
    std::string line;
    std::vector<std::string> file_data;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            file_data.push_back(line);
        }
        myfile.close();
        return file_data;
    }
    else
    {
        std::cout << "Unable to open file";
        return file_data;
    }
}


std::map<std::string, std::vector<float>> format_temperatures_data(std::vector<std::string> input_data)
{
    std::map<std::string, std::vector<float>> formatted_data;

    for (std::string& line : input_data)
    {
        std::vector<float> line_values;
        size_t last_index = line.find_first_of("0123456789");

        std::string name = line.substr(0, last_index - 1);
        line_values = split(line.substr(last_index, line.size()), ' ');

        std::sort(line_values.begin(), line_values.end());

        formatted_data.insert({ name, line_values });

    }

    return formatted_data;
}


int main()
{
    std::string file_name;
    std::vector<std::string> file_data;
    std::map<std::string, std::vector<float>> temperatures;

    file_name = request_file_name();

    file_data = read_file(file_name);

    temperatures = format_temperatures_data(file_data);


    for (const auto& p : temperatures)
    {
        std::cout << "Press enter to continue..." << std::endl;
        std::cin.ignore();

        std::string name = p.first;
        std::vector<float> temps = p.second;

        float my_min = temps[0];
        float my_max = temps.back();
        float my_sum = std::accumulate(temps.begin(), temps.end(), 0.0);
        float my_average = my_sum / temps.size();
        float my_trimmed_average = (my_sum - my_min - my_max) / (temps.size() - 2);

        std::cout << name << " - Max:" << my_max << " Min:" << my_min << " Average:" << my_average << " Trimmed average:" << my_trimmed_average << std::endl;

    }

    return 0;
}