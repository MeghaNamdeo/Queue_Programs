
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    
    void reverse(queue<int> &q)
    {
      //base case
       if(q.empty())
       {
           return;
       }
       //one case 
       int element = q.front();
       q.pop();
       
       
       //recursive call
       rev(q);
       
       q.push(element);
       
       
    
    }
    queue<int> rev(queue<int> &q)
    {
        reverse(q);
        return q;
    }
       
};

int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
