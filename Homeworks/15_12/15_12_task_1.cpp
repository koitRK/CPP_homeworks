#include <iostream>

class Person {
    int age;
    std::string name;
    bool gender;
    public:
        Person(int new_age, std::string new_name, bool new_gender){
            age = new_age;
            name = new_name;
            gender = new_gender;
        }
        int get_age() {
            return age;
        }
        std::string get_name() {
            return name;
        }
        bool get_gender() {
            return gender;
        }
        void print_age_till_retired(){
            int ret_age = (gender) ? 60 : 65;
            for (int temp_age = age; temp_age <= ret_age; temp_age += 5){
                std::cout << temp_age << std::endl;
            }
        }
};


int main(void) {
    Person male1 = Person(26, "Jaan Tamm", 0);
    Person female1 = Person(31, "Anna Kask", 1);

    male1.print_age_till_retired();
    female1.print_age_till_retired();

    return 1;
}