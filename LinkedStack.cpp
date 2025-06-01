#include <iostream>
using namespace std;

class linkedNode
{
public:
    int stackItem;
    linkedNode *nextNode;
};
class linkedStack
{
private:
    linkedNode *stackTop;
    int numElement;

public:
    linkedStack()
    {
        stackTop = NULL;
        numElement = 0;
    }
    bool isEmpty()
    {
        return (stackTop == NULL);
    }
    bool searchItem(int itemSearched)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            linkedNode *tempNode = stackTop;
            while (tempNode != NULL)
            {
                if (tempNode->stackItem == itemSearched)
                {
                    return true;
                }
                else
                {
                    tempNode = tempNode->nextNode;
                }
            }
            return false;
        }
    }
    void pushItem(int itemPushed)
    {
        linkedNode *newNode = new linkedNode();
        newNode->stackItem = itemPushed;
        newNode->nextNode = stackTop;
        stackTop = newNode;
        numElement++;
    }
    void popItem()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            linkedNode *deleteItem = stackTop;
            stackTop = stackTop->nextNode;
            delete deleteItem;
            numElement--;
        }
    }
    int getTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackTop->stackItem;
    }
    int getSize()
    {
        return numElement;
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
            linkedNode *tempNode = stackTop;
            while (tempNode != NULL)
            {
                cout << "| " << tempNode->stackItem << " |" << endl;
                tempNode = tempNode->nextNode;
            }
        }
    }
    ~linkedStack()
    {
        while (!isEmpty())
        {
            popItem();
        }
    }
};

int main()
{
    linkedStack stack;
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
    cout << stack.searchItem(5) << endl;
}