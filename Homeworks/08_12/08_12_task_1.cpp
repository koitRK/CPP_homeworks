#include <iostream>
#include <vector>
#include <math.h>

class Punkt {
    protected:
        int x, y;
    public:
        Punkt(){
            std::cout << "Creating instance of class Punkt" << std::endl;
        }
        Punkt(int new_x, int new_y){
            std::cout << "Creating instance of class Punkt with parameters" << std::endl;
            x = new_x;
            y = new_y;
        }
        void set_x(int new_x){
            x = new_x;
        }
        void set_y(int new_y) {
            y = new_y;
        }
        int get_x(){
            return x;
        }
        int get_y(){
            return y;
        }
        virtual void print_param(){
            std::cout << "x:" << x << " y:" << y << std::endl;
        }
        std::vector<int> add_point(Punkt pt){
            std::vector<int> result {x + pt.x, y + pt.y};
            return result;
        }
        friend void printDistance(Punkt pt);
};


class RuumiPunkt : public Punkt{
    int z;
    public:
        RuumiPunkt(int new_x, int new_y, int new_z) : Punkt(new_x, new_y) {
            std::cout << "Creating instance of class RuumiPunkt with parameters" << std::endl;
            z = new_z;
        }
        void set_z(int new_z) {
            z = new_z;
        }
        int get_z() {
            return z;
        }
        void print_param() {
            std::cout << "x:" << x << " y:" << y << " z:" << z << std::endl;
        }
};


void printDistance(Punkt pt){
    float result = sqrt(pow(pt.x, 2) + pow(pt.y, 2));
    std::cout << "Point distance from (0, 0): " << result << std::endl;
}

int main() {
    Punkt punkt1 = (Punkt(1, 1));
    RuumiPunkt punkt2 = (RuumiPunkt(2, 3, 4));
    Punkt punkt3 = (Punkt(10, 10));
    RuumiPunkt punkt4 = (RuumiPunkt(20, 30, 40));

    std::vector<Punkt*> punktid{&punkt1, &punkt2, &punkt3, &punkt4};

    for (Punkt* pt : punktid){
        pt->print_param();
    }
}