
#include <iostream>
#define MAXSIZE 10
#define clr System('clr')
using namespace std;
class MyCqueue{
    private:
        int rear ;
        int front ;
        int q[MAXSIZE];
    public:
        MyCqueue(){
              front = -1;
              rear = -1;
                  }
    void  insert();
    void  deleteElement();
    void display();
};
void MyCqueue::insert(){
    if((rear+1)%MAXSIZE == front)
    cout<<" Circular Queue is Overflow "<<endl;
    else
    {
    int n;
    cout<<"Enter element here : ";
    cin>>n;
    rear = (rear+1)%MAXSIZE;
    q[rear]= n ;
    
    }
    
}
void MyCqueue::deleteElement(){
    if(rear == -1 && front == -1)
    cout<<" Circular Queue is Empty "<<endl;
    else
    {
       if(rear == front )
       {
         rear = 0;
         front = 0;
         
        }
        else
        {
            int n = q[front];
            front = (front + 1)  % MAXSIZE;
            cout<<" Element is deleted ";
        }
        
    }
}

void MyCqueue::display(){
    if(rear == -1 && front == -1)
    cout<<" Circular Queue is Empty "<<endl;
    else
    {
       int i ;
       for(i = front ; i != rear ; i= (i + 1)% MAXSIZE)
       {
        cout<<q[i]<<" ";
       }
       
    }
    cout<<q[rear]<<" ";
}
int main()
{
    MyCqueue M;
    int Choice;
    
    
    do{
    cout<<"\n--------------Circular Queue ------------->";
    cout<<"\n 1 . INSERT ";
    cout<<"\n 2 . DELETE ";
    cout<<"\n 3 . DISPLAY ";
    cout<<"----------------------------------------";
        
            cout << "\n Enter Choice here :  ";
            cin >> Choice;
            switch(Choice)
        {
            case 1 : M.insert();
            break;
            case 2 : M.deleteElement();
            break;
            case 3 : M.display();
            break;
            case 4 : 
            break;
            default: cout<<" Invalid Choice "<<endl;
            
        }
    
     }   while(Choice!=4);
      
        return 0;
    }
    // Another way 
    
#include <iostream>
using namespace std;

class CirQueue{
        public:
        int size;
        int *arr;
        int front;
        int rear;

        CirQueue(int size) {
                this->size = size;
                arr = new int[size];
                front = -1;
                rear = -1;
        }

        void push(int data) {
                //Queue Full

                //single element case - > first element

                //circular nature

                //normal flow
                //TODO: add one more condition in the QUEUE FULL if block
                if((front == 0 && rear == size-1)) {
                        cout << "Q is fulll, cannot insert" << endl;
                }
                else if(front == -1) {
                        front = rear = 0;
                        arr[rear] = data;
                }
                else if(rear == size-1 && front != 0 ) {
                        rear = 0;
                        arr[rear] = data;
                }
                else{
                        rear++;
                        arr[rear]= data;
                } 
        }

        void pop() {
                //empty check
                //single element
                //circular nature
                //normal flow
                if(front == -1) {
                        cout << "Q is empty , cannot pop" << endl;
                }
                else if (front == rear) {
                        arr[front] = -1;
                        front = -1;
                        rear = -1;  
                }
                else if(front == size-1) {
                        front = 0;
                }
                else {
                        front++;
                }
        }

};

int main() {
    int size;
    cout << "Enter the size of the Circular Queue: ";
    cin >> size;

    CirQueue cq(size);

    cq.push(1);
    cq.push(2);
    cq.push(3);

    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();

    return 0;
}

//leetocde solution 
class MyCircularQueue {
public:
    vector<int> cq;
    int size;
    int rear;
    int front;

    MyCircularQueue(int k) {
        cq.resize(k);

        size = k;
        rear = -1;
        front = -1;
    }

    bool enQueue(int value) {

        if ((rear + 1) % size == front) {
            return false;
        } else {
            if (rear == -1 && front == -1) {
                rear = 0;
                front = 0;
            } else {
                rear = (rear + 1) % size;
            }
            cq[rear] = value;
            return true;
        }
    }

    bool deQueue() {
        if (rear == -1 && front == -1)
            return false;
        else {
            int n;
            n = cq[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            return true;
        }
    }

    int Front() {
        if (front == -1) {
            return -1;
        }

        return cq[front];
    }

    int Rear() {
        if (rear == -1) {
            return -1;
        }
        return cq[rear];
    }

    bool isEmpty() { return (rear == -1 && front == -1); }

    bool isFull() { return ((rear + 1) % size == front); }
};

/*
TC : O(1)
SC : O(k)
 */
