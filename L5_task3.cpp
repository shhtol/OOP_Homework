#include <iostream>
#include <string>
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
template <typename T2>

class StringValuePair : public Pair <string, T2> {
    
    public:
    StringValuePair(string f, T2 s) : Pair<string, T2>(f, s) {}
    
    
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;

    return 0;
}
