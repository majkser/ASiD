#include <iostream>
#include "vector"
using namespace std;

void bubbleSort(vector<int> &v, int sizeOfV);
void quickSort(vector<int> &v, int low, int sizeOfV);

int main()
{
    vector<int> v = {69, 17, 42, 13, 99, 88, 77, 66, 55, 44, 33, 22, 11};
    int sizeOfV = v.size();

    cout << "tablica przed posortowaniem: ";

    for (int i = 0; i < sizeOfV; i++)
    {
        cout << v[i] << " ";
    }

    insertionSort(v, sizeOfV);

    cout << "\ntablica posortowana algorytmem insertionSort: ";

    for (int i = 0; i < sizeOfV; i++)
    {
        cout << v[i] << " ";
    }

    quickSort(v, 0, sizeOfV - 1);

    cout << "\ntablica posortowana algorytmem quickSort: ";

    for (int i = 0; i < sizeOfV; i++)
    {
        cout << v[i] << " ";
    }
}

void insertionSort(vector<int> &v, int sizeOfV)
{
    for (int i = 0; i < (sizeOfV -  1); i++)
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
}

void quickSort(vector<int> &v, int low, int sizeOfV)
{
    if (low < sizeOfV)
    {
        int pivot = v[sizeOfV];
        int i = low - 1;

        for (int j = low; j < sizeOfV; j++)
        {
            if (v[j] < pivot)
            {
                i++;
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }

        int temp = v[i + 1];
        v[i + 1] = v[sizeOfV];
        v[sizeOfV] = temp;

        quickSort(v, low, i);
        quickSort(v, i + 2, sizeOfV);
    }

}