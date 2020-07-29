#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number: ";
    while(!(cin >> n)){
        cout << "Not a number, try again: " << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << "Number is " << n << endl;
    return 0;
}
