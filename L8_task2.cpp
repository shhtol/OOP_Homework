#include <iostream>

using namespace std;

class Ex {
    private: 
    double x;
    public:
    Ex (double c) {
        x = c;
    }
};

class Bar {
    private:
    double y;
    public:
    Bar (){
        y = 0;
    }
    void set(double a)
    {
        if(y+a<=100)
        {
            y=a;
            
        } else throw Ex(y*a);
    }
};
int main()
{
    Bar b;
    int x{};
    while(cin>>x && x!=0){
        
        try
        {
            b.set(x);
        } 
        catch(Ex &err)
        {
            cout << "Error!" << endl;
        }
    }

    return 0;
}
