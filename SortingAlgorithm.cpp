#include <iostream>
#include <algorithm>
using Namespace std;

void selectionSort(int unsortArray[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        int minIndex = i;
        for (int k = i + 1; k < arraySize; k++)
        {
            if (unsortArray[k] < unsortArray[minIndex])
            {
                minIndex = k;
            }
        }
        swap(unsortArray[minIndex], unsortArray[i]);
    }
}
void bubbleSort(int unsortArray[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int k = 0; k < arraySize - i - 1; k++)
        {
            if (unsortArray[k] > unsortArray[k + 1])
            {
                swap(unsortArray[k], unsortArray[k + 1]);
            }
        }
    }
}
void insertionSort(int unsortArray[], int arraySize)
{
    for (int i = 1; i < arraySize; i++)
    {
        int keyValue = unsortArray[i];
        int j = i - 1;
        while (j >= 0 && unsortArray[j] > keyValue)
        {
            unsortArray[j + 1] = unsortArray[j];
            j--;
        }
        unsortArray[j + 1] = keyValue;
    }
}
void displayArray(int arrayDisplayed[], int arraySize)
{
    cout << "[";
    for (int i = 0; i < arraySize; i++)
    {
        if (i == arraySize - 1)
        {
            cout << " " << arrayDisplayed[i] << " ";
        }
        else
        {
            cout << " " << arrayDisplayed[i] << " ,";
        }
    }
    cout << "]" << endl;
}

int main()
{
    cout << "== Selection Sort ==" << endl;
    int selectionArray[5] = {4, 7, 2, 9, 12};
    selectionSort(selectionArray, 5);
    displayArray(selectionArray, 5);

    cout << "== Bubble Sort ==" << endl;
    int bubbleArray[5] = {41, 71, 21, 91, 121};
    bubbleSort(bubbleArray, 5);
    displayArray(bubbleArray, 5);

    cout << "== Insertion Sort ==" << endl;
    int insertionArray[5] = {8, 13, 0, 60, 34};
    insertionSort(insertionArray, 5);
    displayArray(insertionArray, 5);
}