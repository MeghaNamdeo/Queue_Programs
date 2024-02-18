#include<bits/stdc++.h>
using namespace std;



class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) 
    {
        input.push(x);
    }

    int dequeue() {
        if(output.empty())
        {
            if(input.empty())
                return -1; // Queue is empty
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int frontElement = output.top();
        output.pop();
        return frontElement;
    }

};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

