#include <iostream>
#include "vector"
using namespace std;

template <typename T>
void bubbleSort(vector<T> &v, int sizeOfV);

template <typename T>
void quickSort(vector<T> &v, int low, int sizeOfV);

int main()
{
    vector<int> v = {69, 17, 42, 13, 99, 88, 77, 66, 55, 44, 33, 22, 11};
    int sizeOfV = v.size();

    cout << "przykładowy vector intów przed posortowaniem: ";

    for (int i = 0; i < sizeOfV; i++)
    {
        cout << v[i] << " ";
    }

    bubbleSort(v, sizeOfV);

    cout << "\nvector po posortowaniu algorytmem bubbleSort: ";

    for (int i = 0; i < sizeOfV; i++)
    {
        cout << v[i] << " ";
    }

    quickSort(v, 0, sizeOfV - 1);

    cout << "\nvector po posortowaniu algorytmem quickSort: ";

    for (int i = 0; i < sizeOfV; i++)
    {
        cout << v[i] << " ";
    }
}

template <typename T>
void bubbleSort(vector<T>& v, int sizeOfV)
{
    for (int i = 0; i < sizeOfV - 1; i++)
    {
        for (int j = 0; j < sizeOfV - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                T temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void quickSort(vector<T> &v, int low, int sizeOfV)
{
    if (low < sizeOfV)
    {
        T pivot = v[sizeOfV];
        int i = low - 1;

        for (int j = low; j < sizeOfV; j++)
        {
            if (v[j] < pivot)
            {
                i++;
                T temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }

        T temp = v[i + 1];
        v[i + 1] = v[sizeOfV];
        v[sizeOfV] = temp;

        quickSort(v, low, i);
        quickSort(v, i + 2, sizeOfV);
    }

}