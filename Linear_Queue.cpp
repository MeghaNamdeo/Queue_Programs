#include <iostream>
#define MAXSIZE 10
#define clrscr() system("cls")
using namespace std;

class Myqueue
{
private:
    int rear, front;
    int queue[MAXSIZE];

public:
    Myqueue()
    {
        rear = -1;
        front = 0;
    }

public:
    void insert();
    void deleteMethod();
    void display();
};

void Myqueue::insert()
{
    int n;
    if (rear == MAXSIZE - 1)
        cout << "\n Queue is overflow";
    else
    {
        cout << "Enter an Element: ";
        cin >> n;
        rear++;
        queue[rear] = n;
    }
}

void Myqueue::deleteMethod()
{
    int n;
    if (front > rear)
        cout << "\n Queue is underflow";
    else
    {
        n = queue[front];
        front++;
        cout << "\n Deleted Element is : " << n << endl;
    }
}

void Myqueue::display()
{
    int n;
    if (front > rear)
        cout << "\n Queue is Empty";
    else
    {
        for (int i = rear; i >= front; i--)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    Myqueue M;

    do
    {
        cout << "\n-------------Queue Menu--------";
        cout << "\n1. Insert";
        cout << "\n2. Delete Method ";
        cout << "\n3. Display";
        cout << "\n----------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            M.insert();
            break;
        case 2:
            M.deleteMethod();
            break;
        case 3:
            M.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid call" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
