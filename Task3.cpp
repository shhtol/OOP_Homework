#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;
    public:
    
    Fraction (int n, int d){
        numerator = n;
        denominator = d;
    }
    Fraction (){
        numerator = 0;
        denominator = 0;
    }
    
    void show(){
        cout << numerator << '|' << denominator << endl;
    }
    
    Fraction operator- () const{
        return Fraction(-numerator, denominator);
    }
    
    friend Fraction operator*(const Fraction &f1, const Fraction &f2) {
        return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
    }
    
    friend Fraction operator/(const Fraction &f1, const Fraction &f2) {
        
        return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
    }
    
    Fraction operator+(Fraction f){
        Fraction r;
        r.numerator = (numerator*f.denominator) + (denominator*f.numerator);
        r.denominator = denominator*f.denominator;
        return (r);
        }
    
    Fraction operator-(Fraction f){
        Fraction r;
        r.numerator = (numerator*f.denominator) - (denominator*f.numerator);
        r.denominator = denominator*f.denominator;
        return (r);
    }
        
    
    bool operator<(const Fraction &f1) {
        if((numerator / denominator) < (f1.numerator / f1.denominator)) return true;
        else return false;
    }
    
    bool operator>(const Fraction &f1) {
         if((numerator / denominator) < (f1.numerator / f1.denominator)) return false;
        else return true;
    }
    
    bool operator<=(const Fraction &f1) {
        if((numerator / denominator) <= (f1.numerator / f1.denominator)) return true;
        else return false;
    }
    
    bool operator>=(const Fraction &f1) {
        if((numerator / denominator) <= (f1.numerator / f1.denominator)) return false;
        else return true;
    } 
    
    bool operator==(const Fraction &f2)
    {
    return (numerator == f2.numerator &&
            denominator == f2.denominator);
    }
 
    bool operator!=(const Fraction &f2)
    {
    return (numerator != f2.numerator ||
            denominator != f2.denominator);
    }
};
int main()
{
    Fraction f1(3, 7);
    Fraction f2(5, 6);
    Fraction f3;
    f1 = -f1;
    f1.show();
    f3 = f1 + f2;
    f3.show();
    f3 = f1 - f2;
    f3.show();
    f3 = f1 * f2;
    f3.show();
    f3 = f1 / f2;
    f3.show();
    bool res = f1 < f2;
    cout << res << endl;
    res = f1 < f2;
    cout << res << endl;
    res = f1 >= f2;
    cout << res << endl;
    res = f1 <= f2;
    cout << res << endl;
    res = f1 != f2;
    cout << res << endl;
    res = f1 == f2;
    cout << res << endl;
    
    

    return 0;
}
