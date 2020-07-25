#include <iostream>

using namespace std;

template <typename T1, typename T2>

class Pair {
    private:
    T1 el_first;
    T2 el_second;
    
    public:
    Pair(T1 f, T2 s) : el_first(f), el_second(s) {}
    
    T1 first() const{
        return el_first;
    }
    T2 second() const{
        return el_second;
    }
    
};

int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
