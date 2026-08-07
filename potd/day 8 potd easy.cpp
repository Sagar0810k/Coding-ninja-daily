#include <bits/stdc++.h> 
int maximumChocolates(vector<int> &arr, int k){
    // Write your code here.
    const int MOD=1e9+7;
    priority_queue<int>pq;
    for(int x: arr){
        pq.push(x);
    }
    long long ans=0;
    while(k--){
        int x=pq.top();
        pq.pop();
        ans=(ans+x)%MOD;
        pq.push(x/2);
    }
    return ans;
}