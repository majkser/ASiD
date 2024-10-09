#include <iostream>
#include "vector"
using namespace std;

void bubbleSort(vector<int>& v, int sizeOfV);

int main()
{
    vector<int> v = {8, 17, 42, 11, 99, 88, 77, 66, 55, 44, 33, 22, 11};
    int sizeOfV = v.size();

    bubbleSort(v, sizeOfV);
}

void bubbleSort(vector<int>& v, int sizeOfV)
{
    for (int i = 0; i < (sizeOfV - 1); i++)
    {
        for (int j = i + 1; j < sizeOfV; j++)
        {
            if (v[i] > v[j])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    cout << "tablica posortowana algorytmem bubbleSort: ";

    for (int i = 0; i < sizeOfV; i++)
    {
        cout << v[i] <<" ";
    }
}