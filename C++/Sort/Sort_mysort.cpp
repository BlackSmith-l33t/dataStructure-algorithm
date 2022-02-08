#include <iostream>
#include <vector>
#include <stdlib.h>

#define SIZE 10

using namespace std;

void printVector(const vector<int>& vec);
void swap(int& left, int& right);
void merge(vector<int>& vec, int start_index, int mid_index, int end_index);

void selectionSort(vector<int>& vec);
void insertionSort(vector<int>& vec);
void bubbleSort(vector<int> vec);
void mergeSort(vector<int>& vec, int start_index, int end_index);
void quickSork(vector<int> vec, int start_index, int end_index);

int main()
{
    srand((unsigned int)time(NULL));

    vector<int> selectionVector; // 선택정렬 
    vector<int> insertionVector; // 삽입정렬


    for (int i = 0; i < SIZE; i++)
    {
        int random = rand() % SIZE;

        selectionVector.push_back(random);
        insertionVector.push_back(random);
    }

    cout << "Non Sorted Vector : ";
    printVector(selectionVector);
    cout << endl;

    selectionSort(selectionVector);
    cout << "selectionVector : " << endl;
    printVector(selectionVector);
    cout << endl;

    insertionSort(insertionVector);
    cout << "insertionVector : " << endl;
    printVector(insertionVector);
    cout << endl;


        
}

void printVector(const vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ", "; 
    }
    cout << endl;
}

void swap(int& left, int& right)
{
    int temp = left;
    left = right;
    right = temp;
}

void selectionSort(vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int min_index = i;
        for (int j = i; j < vec.size(); j++)
        {
            if (vec[j] < vec[min_index])
            {
                min_index = j;
            }
        }
        swap(vec[i], vec[min_index]);
    }
}

void insertionSort(vector<int>& vec)
{
    int i, j, key;
    for (i = 1; i < vec.size(); i++)
    {
        key = vec[i];
        for (j = i; j && vec[j - 1] > key; j--)
        {
            vec[j] = vec[j - 1];
        }
        vec[j] = key;
    }
}
