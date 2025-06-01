#include <iostream>
using namespace std;

class linkedNode
{
public:
    int listItem;
    linkedNode *nextNode;
};
class linkedList
{
private:
    linkedNode *listHead;
    int numElement;

public:
    linkedList()
    {
        numElement = 0;
        listHead = NULL;
    }
    bool isEmpty()
    {
        return (listHead == NULL);
    }
    void addFirst(int itemAdded)
    {
        linkedNode *newNode = new linkedNode();
        newNode->listItem = itemAdded;
        if (isEmpty())
        {
            newNode->nextNode == NULL;
            listHead = newNode;
        }
        else
        {
            newNode->nextNode = listHead;
            listHead = newNode;
        }
        numElement++;
    }
    void addLast(int itemAdded)
    {
        linkedNode *newNode = new linkedNode();
        newNode->listItem = itemAdded;
        if (isEmpty())
        {
            addFirst(itemAdded);
        }
        else
        {
            newNode->nextNode = NULL;
            linkedNode *tempNode = listHead;
            while (tempNode != NULL)
            {
                tempNode = tempNode->nextNode;
            }
            tempNode = newNode;
        }
        numElement++;
    }
    int getSize()
    {
        return numElement;
    }
    int getHead()
    {
        if (isEmpty())
        {
            cout << "List is Empty" << endl;
            return -1;
        }
        return listHead->listItem;
    }
    void displayList()
    {
        if (isEmpty())
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            linkedNode *tempNode = listHead;
            while (tempNode != NULL)
            {
                if (tempNode->nextNode == NULL)
                {
                    cout << tempNode->listItem << endl;
                    tempNode = tempNode->nextNode;
                }
                else
                {
                    cout << tempNode->listItem << " -> ";
                    tempNode = tempNode->nextNode;
                }
            }
        }
    }
};

int main()
{
    linkedList list;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(3);
    list.addFirst(4);
    list.addLast(5);
    list.addLast(6);
    list.addLast(7);
    list.displayList();
    cout << "==========" << endl;
    cout << list.getHead() << endl;
    cout << list.getSize() << endl;
}