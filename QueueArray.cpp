#include <iostream>
using namespace std;

class queueArray
{
private:
    int queueHead;
    int queueTail;
    int queueSize;
    int *dynamicArray;
    int numElement;

public:
    queueArray(int queueSize)
    {
        this->queueSize = queueSize;
        queueHead = 0;
        queueTail = queueSize - 1;
        numElement = 0;
        dynamicArray = new int[queueSize];
    }
    bool isEmpty()
    {
        return (numElement == 0);
    }
    bool isFull()
    {
        return (numElement >= queueSize);
    }
    void enqueueItem(int itemEnqueue)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            queueTail = (queueTail + 1) % queueSize;
            dynamicArray[queueTail] = itemEnqueue;
            numElement++;
        }
    }
    void dequeueItem()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            queueHead = (queueHead + 1) % queueSize;
            numElement--;
        }
    }
    int getHead()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return dynamicArray[queueHead];
    }
    int getTail()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return dynamicArray[queueTail];
    }
    int getSize()
    {
        return queueSize;
    }
    int getCountElement()
    {
        return numElement;
    }
    void displayQueue()
    {
        for (int i = queueHead; i != queueTail + 1; i = (i + 1) % queueSize)
        {
            cout << " " << dynamicArray[i] << " ";
        }
        cout << endl;
    }
    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeueItem();
        }
    }
    ~queueArray()
    {
        delete[] dynamicArray;
    }
};

int main()
{
    queueArray queue(10);
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
    cout << queue.getCountElement() << endl;
}