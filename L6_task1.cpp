#include <iostream>
#include <string>
using namespace std;

bool is_digit(string s) {
    for(auto ch : s){
        if(!isdigit(ch)) return false;
    }
    return true;
}

int main()
{
    string n;
   
    do{ 
    cout<<"Enter the number: ";
    cin >> n;
    }
    while(!is_digit(n));
    cout << "Number is " << n << endl;

    return 0;
}

