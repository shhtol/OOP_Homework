#include <iostream>

using namespace std;

ostream& endl2(ostream& os) {
    cout.flush();
    return os << '\n' << '\n';
}

int main()
{   cout << "Start" << endl;
    cout << "Hello World" << endl2;
    cout << "End";

    return 0;
}
