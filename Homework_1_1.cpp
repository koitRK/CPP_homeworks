
#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>

using namespace std;

float square_area_given_side(float side){
    return side*side;
}

float square_perimeter_given_side(float side){
    return 4*side;
}

float circle_circumference_given_radius(float radius){
    return 2*M_PI*radius;
}

float circle_area_given_radius(float radius){
    return M_PI*radius*radius;
}

int main(){
    float user_input_radius;

    cout << "Enter circle radius:" << endl;
    cin >> user_input_radius;

    float square_area = square_area_given_side(user_input_radius*2);
    float square_perimeter = square_perimeter_given_side(user_input_radius*2);
    float circle_circumference = circle_circumference_given_radius(user_input_radius);
    float circle_area = circle_area_given_radius(user_input_radius);

    cout << "Circle radius: " << user_input_radius << "  Square area: " << square_area  << "  Square perimeter: " << square_perimeter << "  Circle circumference: " << circle_circumference << "  Circle area: " << circle_area << endl;

    return 0;
}