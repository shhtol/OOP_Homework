#include <iostream>
#include <string>
using namespace std;

class Car {
    protected:
    string company;
    string model;
    
    public:
    Car (string c, string m) {
        company = c;
        model = m;
        cout << "#Car's constructor#\nCompany: " << company << "\nModel: " << model << "\n"<< endl;
    }
};

class PassengerCar : virtual public Car{
    public: 
    PassengerCar (string c, string m) : Car(c, m) {
        cout << "#PassengerCar's constructor#\nCompany: " << company << "\nModel: " << model << "\n"<< endl;
    }
};

class Bus : virtual public Car {
    public: 
    Bus (string c, string m) : Car(c, m) {
        cout << "#Bus's constructor#\nCompany: " << company << "\nModel: " << model << "\n"<< endl;
    }
};

class Minivan : public Bus, public PassengerCar {
    public: 
    Minivan (string c, string m) : Bus(c, m), PassengerCar(c, m), Car(c,m) {
        cout << "#Minivan's constructohttps:#\nCompany: " << company << "\nModel: " << model << endl;
    }
};


int main()
{
    Car c("Tesla", "Model S"); 
    PassengerCar p("Subaru", "Legacy b4");
    Bus b("LiAZ", "677");
    Minivan m("Honda", "Freed Spike");

    return 0;
}
