#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int CheckSTL (vector <int> vec) {
    set <int> st;
    for(auto i : vec)
        st.insert(i);
    return st.size();
}

int CheckAlgo (vector <int> vec) {
    int counter = 0;
    for(int i = 1; i < vec.size(); i++)     
	    for(int j = i; j>0 && vec[j - 1] > vec[j]; j--)
			swap(vec[j-1], vec[j]);
	for(int i = 0; i < vec.size() - 1; i++){
	    if(vec[i] != vec[i + 1])
	        counter++;
	}
	if(vec[vec.size() - 2] != vec[vec.size() - 1] )
	    counter++;
	return counter;
}

int main () {
    int SIZE = 5;
    vector <int> vec;
    for(int i = 0; i < SIZE; i++){
        int n;
        cout << "Enter the element" << endl;
        cin >> n;
        vec.push_back(n);
    }
    cout << CheckSTL(vec) << endl;
    cout << CheckAlgo(vec);
    return 0;
}