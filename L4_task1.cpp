#include <iostream>
#include <cassert>

using namespace std;

class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length):
    m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }
    void DeleteLast();
    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);
        int *data = new int[m_length+1];
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];
        data [index] = value;
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value) { insertBefore(value, m_length); }
    void SortArray();
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

};

void ArrayInt::DeleteLast(){
    int *data = new int[m_length - 1];
    for (int i = 0; i < m_length - 1; i++)
            data[i] = m_data[i];
    delete[] m_data;
    m_data = data;
    m_length--;
} 


void ArrayInt::SortArray() {
    for(int i = 1; i < m_length; i++)     
	    for(int j = i; j > 0 && m_data[j - 1] > m_data[j]; j--) 
			{
			int temp = m_data[j - 1];
			m_data[j - 1] = m_data[j]; 
			m_data[j] = temp;
			}
}
int main()
{
    ArrayInt a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    a.SortArray();
    cout << a[0] << ' ' << a[1] << ' ' << a[2];
    

    return 0;
}
