

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void K_reverse(queue<int>&q, int k)
    {
        //step A
        stack<int>s;
        int count = 0 , n = q.size();
        
        if(k<=0||k>n)
        {
            return;
        }
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            s.push(temp);
            count++;
            
            if(count == k)
            break;
        }
        //stepB
        while(!s.empty())
        {
            int temp = s.top();
            s.pop();
            q.push(temp);
        }
        //step C
        count = 0 ;
        while(!q.empty()&&n-k!=0)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            count++;
            if(count == n - k)
            break;
        }

    }
    queue<int> modifyQueue(queue<int> &q, int k) {
        K_reverse(q,k);
        return q;
        
    }
};




int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
