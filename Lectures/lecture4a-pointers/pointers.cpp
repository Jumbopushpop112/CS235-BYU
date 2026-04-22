#include <iostream>
using std::cout, std::endl;

#define PRINT(x) cout << #x << " ==> " << x << endl;
#define WHERE(x) cout << "where(" << #x << ") ==> "; where(x);
#define BYTES(x) cout << "bytes(" << #x << ") ==> "; bytes(x);

class HasInt {
    int the_int;
public:
    HasInt(int value) : the_int(value) {}
    void set_int(int new_value) { the_int = new_value; }
    int get_int() const { return the_int; }
};

template <class T>
void where(T const& thing) {
    printf("%p\n", &thing);
}

/*
  This method prints the bytes in RAM that a given variable has
*/
template <class T>
void bytes(T const& thing) {
    unsigned char* addr = (unsigned char*)&thing;
    printf("0x");
    for (int i = sizeof(T) - 1; i >= 0; i--) {
        printf("%02x", addr[i]);
    }
    printf("\n");
}

int main(){
// Part 1
    HasInt first(8);
//    PRINT(first.get_int());

    HasInt second = first;
//    PRINT(second.get_int());
//
//    WHERE(first);
//    WHERE(second);
//
    second.set_int(3);
//    PRINT(second.get_int());
//    PRINT(first.get_int());
//
//    WHERE(first);
//    WHERE(second);

// Part 2
    HasInt * one = new HasInt(25);
//    PRINT(one->get_int())

    HasInt * two = one;
//    PRINT(two->get_int())

    two->set_int(42);
//    PRINT(two->get_int())
//    PRINT(one->get_int())
//
//    PRINT((*one).get_int())
//
//    WHERE(*one)
//    WHERE(*two)
//
//    BYTES(first)
//    BYTES(second)
//    BYTES(one)
//    BYTES(two)
//
//
//    BYTES(one)
//    WHERE(*one)
//    BYTES(*one)
//    BYTES(two)
//    WHERE(*two)
//    BYTES(*two)
//    WHERE(one)
//    WHERE(two)

// Part 3
    int* number = new int(5);
    WHERE(number)
    BYTES(number)
    WHERE(*number)
    BYTES(*number)

     HasInt* a = new HasInt(2);
     HasInt* b = new HasInt(1);
     HasInt* c = a;
     BYTES(a)
     BYTES(b)
     BYTES(c)

     c = b;
     BYTES(a)
     BYTES(b)
     BYTES(c)

// Part 4
    HasInt* foo = nullptr;  // Similar to None in Python or null in Java
//    BYTES(*foo)
    BYTES(nullptr)

    return 0;
}