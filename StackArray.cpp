#include <iostream>
using namespace std;

class stackArray
{
private:
    int top;
    int *dynamicStack;
    int stackSize;

public:
    stackArray(int stackSize)
    {
        this->stackSize = stackSize;
        top = -1;
        dynamicStack = new int[stackSize];
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top >= stackSize - 1);
    }
    int searchItem(int itemSearched)
    {
        for (int i = 0; i < top + 1; i++)
        {
            if (itemSearched == dynamicStack[i])
            {
                return i;
            }
        }
        return -1;
    }
    void pushItem(int itemPushed)
    {
        if (isFull())
        {
            cout << "Stack is Full" << endl;
        }
        else
        {
            top++;
            dynamicStack[top] = itemPushed;
        }
    }
    void popItem()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            top--;
        }
    }
    int getTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return dynamicStack[top];
    }
    int getCountElement()
    {
        return top + 1;
    }
    int getSize()
    {
        return stackSize;
    }
    void clearStack()
    {
        while (!isEmpty())
        {
            popItem();
        }
    }
    void displayStack()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << "| " << dynamicStack[i] << " |" << endl;
            }
        }
    }
    ~stackArray()
    {
        delete[] dynamicStack;
    }
};

int main()
{
    stackArray stack(10);
    stack.pushItem(1);
    stack.pushItem(2);
    stack.pushItem(3);
    stack.popItem();
    stack.pushItem(4);
    stack.pushItem(5);
    stack.displayStack();
    cout << "==========" << endl;
    cout << stack.getTop() << endl;
    cout << stack.getSize() << endl;
    cout << stack.getCountElement() << endl;
    cout << stack.searchItem(5) << endl;
}