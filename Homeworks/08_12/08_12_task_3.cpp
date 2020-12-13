#include <iostream>
#include <vector>
#include <iterator>
#include <typeinfo>


template <class T>
struct Node {
    T data;
    struct Node* next;
};


template <class T>
struct Node<T>* head = NULL;


template <class T>
void insert(T new_data) {
    struct Node<T>* new_node = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    new_node->data = new_data;
    new_node->next = head<T>;
    head<T> = new_node;
}


template <class T>
void display() {
    struct Node<T>* ptr;
    ptr = head<T>;
    while (ptr != NULL) {
        ptr->data.printPoint();
        ptr = ptr->next;
    }
}


template<class T>
T add(T t1, T t2) {
    return t1 + t2;
}


template<class T>
T compare(T t1, T t2) {
    return t1 < t2;
}


template<class T>
T getLargest(std::vector<T> vec) {
    T largest = vec[0];
    for (T i : vec){
        if (largest < i){
            largest = i;
        }
    }
    return largest;
}


template<class T>
int getIndex(std::vector<T> vec, T target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target){
            return i;
        }
    }
    return -1;
}


class Punkt {
    int x, y;
    public:
        Punkt(int new_x, int new_y){
            x = new_x;
            y = new_y;
        }
        int get_x() {
            return x;
        }
        int get_y() {
            return y;
        }
        Punkt operator+(Punkt& pt2){
            return Punkt(x + pt2.x, y + pt2.y);
        }
        bool operator<(Punkt& pt2){
            return x < pt2.x;
        }
        bool operator==(Punkt& pt2) {
            return ((x==pt2.x)&&(y==pt2.y));
        }
        void printPoint() {
            std::cout << x << " " << y << std::endl;
        }
};

template<class T1, class T2>
class KlassKaheElemendiga{
    T1 x;
    T2 y;
    public:
        KlassKaheElemendiga(T1 new_x, T2 new_y) {
            x = new_x;
            y = new_y;
        }
        void set_x(T1 new_x) {
            x = new_x;
        }
        void set_y(T2 new_y) {
            y = new_y;
        }
        T1 get_x() {
            return x;
        }
        T2 get_y() {
            return y;
        }
};


int main(void) {
    Punkt point1 = Punkt(1, 2);
    Punkt point2 = Punkt(10, 20);
    Punkt point3 = Punkt(100, 200);

    Punkt point4 = add(point1, point2);

    std::vector<Punkt> points{ point1, point2, point3 };

    Punkt largest = getLargest(points);

    int largestIndex = getIndex(points, largest);


    insert(point1);
    insert(point2);
    insert(point3);
    std::cout << "The linked list is: " << std::endl;
    display<Punkt>();


    KlassKaheElemendiga<int, std::string> foo = KlassKaheElemendiga<int, std::string>(123, "String");
    std::cout << foo.get_x() << "  " << foo.get_y() << std::endl;

    return 1;
}