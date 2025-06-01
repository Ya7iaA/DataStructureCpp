#include <iostream>
using namespace std;

class linkedNode
{
public:
    int queueItem;
    linkedNode *nextNode;
};
class linkedQueue
{
private:
    int numElement;
    linkedNode *queueHead;
    linkedNode *queueTail;

public:
    linkedQueue()
    {
        queueHead = queueTail = NULL;
        numElement = 0;
    }
    bool isEmpty()
    {
        return (queueHead == NULL);
    }
    void enqueueItem(int itemEnqueued)
    {
        linkedNode *newNode = new linkedNode();
        newNode->queueItem = itemEnqueued;
        if (isEmpty())
        {
            newNode->nextNode = NULL;
            queueHead = queueTail = newNode;
        }
        else
        {
            newNode->nextNode = NULL;
            queueTail->nextNode = newNode;
            queueTail = newNode;
        }
        numElement++;
    }
    void dequeueItem()
    {
        linkedNode *deleteItem = queueHead;
        queueHead = queueHead->nextNode;
        delete deleteItem;
        numElement--;
    }
    int getSize()
    {
        return numElement;
    }
    int getHead()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return queueHead->queueItem;
    }
    int getTail()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return queueTail->queueItem;
    }
    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeueItem();
        }
    }
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            linkedNode *tempNode = queueHead;
            while (tempNode != NULL)
            {
                cout << " " << tempNode->queueItem << " ";
                tempNode = tempNode->nextNode;
            }
            cout << endl;
        }
    }
    ~linkedQueue()
    {
        while (!isEmpty())
        {
            dequeueItem();
        }
    }
};

int main()
{
    linkedQueue queue;
    queue.enqueueItem(1);
    queue.enqueueItem(2);
    queue.enqueueItem(3);
    queue.enqueueItem(4);
    queue.dequeueItem();
    queue.enqueueItem(5);
    queue.displayQueue();
    cout << "==========" << endl;
    cout << queue.getSize() << endl;
    cout << queue.getHead() << endl;
    cout << queue.getTail() << endl;
}