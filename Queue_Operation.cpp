#include<iostream>
#include<queue>
using namespace std;

class Queue
{
public: 
    int *arr;
    int size;
    int front;
    int rear;
    
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    
    void push(int data)
    {
        if(rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if(rear == front)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if(front == size)
        {
            cout << "Queue is empty " << endl;
        }
       
            return arr[front];
       
    }

    bool isEmpty()
    {
        return front == rear;
    }

    int getSize()
    {
        return rear - front;
    }
};

int main()
{
    Queue q(10);
    q.push(12);
    q.push(9);
    q.push(1);
    q.push(99);
    q.push(2);
    q.push(40);
    q.pop();
    

    cout << "Size of element is: " << q.getSize() << endl;
    cout << "Is queue empty or not: " << q.isEmpty() << endl;
    cout <<" Front element of Queue :  "<< q.getFront() <<endl;
    
    return 0;
}
