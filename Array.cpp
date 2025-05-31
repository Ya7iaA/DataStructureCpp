#include <iostream>
using namespace std;

class struArray
{
private:
    int arraySize;
    int numElement;
    int *dynamicArray;

public:
    struArray(int arraySize)
    {
        this->arraySize = arraySize;
        numElement = 0;
        dynamicArray = new int[arraySize];
    }
    bool isEmpty()
    {
        return (numElement == 0);
    }
    bool isFull()
    {
        return (numElement >= arraySize);
    }
    int searchItem(int itemSearched)
    {
        for (int i = 0; i < numElement; i++)
        {
            if (itemSearched == dynamicArray[i])
            {
                return i;
            }
        }
        return -1;
    }
    void addItem(int itemAdded)
    {
        if (isFull())
        {
            cout << "Array is Full" << endl;
        }
        else
        {
            dynamicArray[numElement] = itemAdded;
            numElement++;
        }
    }
    void insertItem(int itemInserted, int indexWanted)
    {
        if (isFull())
        {
            cout << "Array is Full" << endl;
        }
        else
        {
            if (indexWanted < 1 || indexWanted > numElement)
            {
                cout << "Invalid index" << endl;
            }
            else
            {
                for (int i = numElement - 1; i >= indexWanted - 1; i--)
                {
                    dynamicArray[i + 1] = dynamicArray[i];
                }
                dynamicArray[indexWanted - 1] = itemInserted;
                numElement++;
            }
        }
    }
    void deleteItem(int itemDeleted)
    {
        int itemSearched = searchItem(itemDeleted);
        if (itemSearched == -1)
        {
            cout << "Item not Found" << endl;
        }
        else
        {
            for (int i = itemSearched; i < numElement - 1; i++)
            {
                dynamicArray[i] = dynamicArray[i + 1];
            }
        }
        numElement--;
    }
    int getSize()
    {
        return arraySize;
    }
    int getItemAtIndex(int indexWanted)
    {
        if (indexWanted < numElement && indexWanted >= 0)
        {
            return dynamicArray[indexWanted];
        }
        else
        {
            cout << "Index dose not match" << endl;
            return -1;
        }
    }
    int getCountElement()
    {
        return numElement;
    }
    void clearArray()
    {
        numElement = 0;
    }
    void displayArray()
    {
        if (isEmpty())
        {
            cout << "Array is Empty" << endl;
        }
        else
        {
            cout << "[";
            for (int i = 0; i < numElement; i++)
            {
                if (i == numElement - 1)
                {
                    cout << " " << dynamicArray[i] << " ";
                }
                else
                {
                    cout << " " << dynamicArray[i] << " ,";
                }
            }
            cout << "]" << endl;
        }
    }
    ~struArray()
    {
        delete[] dynamicArray;
    }
};

int main()
{
    struArray array(10);
    array.addItem(1);
    array.addItem(2);
    array.addItem(3);
    array.deleteItem(2);
    array.addItem(4);
    array.insertItem(2, 2);
    array.displayArray();
    cout << "===========" << endl;
    cout << array.getCountElement() << endl;
    cout << array.getSize() << endl;
    cout << array.getItemAtIndex(3) << endl;
}