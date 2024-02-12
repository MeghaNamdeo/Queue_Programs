
#include <iostream>
using namespace std;
class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    
    Deque(int size)
    {
        this->size=size;
        arr=new int[size];
        front=-1;
        rear =-1;
    }
    void pushRear(int data)
    {
        if(front == 0 && rear == size -1)
        {
            cout<<"Q is full, cannot insert"<<endl;
            return;
        }
        else if(front == -1)
        {
            front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
            
        }
        else {
            rear++;
            
        }
        arr[rear] = data;
        
        
    }

void pushFront(int data)
    {
        if(front == 0 && rear == size -1)
        {
            cout<<"Q is full, cannot insert"<<endl;
            return;
        }
        else if(front == -1)
        {
            front = rear = 0;
            
        }
        else if(rear != size-1 && front == 0)
        {
           front= size -1 ;
            
        }
        else {
            front--;
            
        }
        arr[front] = data;
        
        
    }
    void popFront()
    {
        if(front == -1)
        {
            cout<<"Queue is empty, cannpt pop"<<endl;
            return;
        }
        else if (front == rear)
        {
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1)
        {
            front =0;
        }
        else
        {
            front++;
        }
    }
void popRear()
    {
        if(front == -1)
        {
            cout<<"Queue is empty, cannpt pop"<<endl;
            
        }
        else if (front == rear)
        {
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(rear == 0)
        {
            rear = size -1 ;
        }
        else
        {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);

        cout << endl;
    }
};    
    
    


int main() {
        Deque dq(5);
    dq.pushRear(5);
    dq.pushFront(15);
    dq.pushRear(25);
    dq.pushRear(95);
    dq.pushFront(115);
    dq.pushRear(225);
    dq.pushRear(5);
    dq.popFront();
    dq.pushRear(25);
    dq.popRear();
    dq.pushFront(115);
    dq.pushRear(225);
    dq.display();
    return 0;

}
