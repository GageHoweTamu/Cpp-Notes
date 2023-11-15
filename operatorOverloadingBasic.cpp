#include <iostream>
#include <string>

using namespace std;

class Car {
    public:
        Car() {                    // default constructor
            brand = "Audi";
            year = 1985;
        }

        Car(string x, int y) {     // constructor with parameters
            brand = x;
            year = y;
        }

        string brand;
        int year;
};

void printCar(Car* car) {
    cout << "Car brand: " << car->brand << endl;
    cout << "Car year: " << car->year << endl;
}

void operator<<(ostream&cout, Car* car) {
    cout << "Car brand: " << car->brand << endl;
    cout << "Car year: " << car->year << endl;
}

int main()
{
    cout << "Hello World!" << std::endl;
    cout << "Let's make some cars!" << std::endl;

    Car myCar;                                 // create a new object of Car, using the default constructor
    Car* myTesla = new Car("Tesla",2014);       // create a pointer to a new Car object, using the constructor with parameters
    

    printCar(&myCar);
    // print the car, by referencing its address

    printCar(myTesla);

    cout << &myCar;
    // normally, this would print the address of the car.
    // however, since we overloaded the << operator, it will print the car's brand and year instead

    cout << myTesla;
    // print the car using the overloaded << operator on the myTesla pointer

    delete myTesla;

    return 0;
}

// NOTE

    // we don't need to delete myCar because it was created on the stack.
    // Therefore, it will be deleted automatically when it goes out of scope.
    // myTesla, however, was created on the heap with the "new" keyword, so we need to delete it manually.

    /*
    OUTPUT:

Hello World!
Let's make some cars!
Car brand: Audi
Car year: 1985
Car brand: Tesla
Car year: 2014
Car brand: Audi
Car year: 1985
Car brand: Audi
Car year: 1985
Car brand: Tesla
Car year: 2014
    */