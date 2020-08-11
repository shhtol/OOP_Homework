#include <iostream>

using namespace std;

template <typename T> 

class Pair1 {
    private:
    T el_first;
    T el_second;
    
    public:
    Pair1(T f, T s) : el_first(f), el_second(s) {}
    
    T first() const{
        return el_first;
    }
    T second() const{
        return el_second;
    }
    
};

int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

