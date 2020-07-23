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
};

void ArrayInt::DeleteLast(){
    int *data = new int[m_length - 1];
    for (int i = 0; i < m_length - 1; i++)
            data[i] = m_data[i];
    delete[] m_data;
    m_data = data;
    m_length--;
} 


void SortArray() {
    int *data = new int[m_length];
    for(int i = 1; i < m_length; i++)     
	    for(int j = i; j > 0 && data[j - 1] > data[j]; j--) 
			int temp = data[j - 1];
			data[j - 1] = data[j]; 
			data[j] = temp;
}
