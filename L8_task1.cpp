#include <iostream>

using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        throw "DivisionByZero";
    }
    return a/b;
}

int main()
{
    try {
        double answer = divide(6, 2);
        cout << answer << endl;
    }
    catch (const char* ex) {
        cout << ex << endl;
    }
    
    try {
        double answer = divide(6, 0);
        cout << answer << endl;
    }
    catch (const char* ex) {
        cout << "Zero cannot be a denominator!" << endl;
    }


    return 0;
}
