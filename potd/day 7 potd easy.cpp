#include <bits/stdc++.h> 
vector<int> linearProbing(vector<int> keys)
{
    // Write your code here.
    int n=keys.size();
    vector<int>ht(n,-1);
    for(int key:keys){
        int idx=key%n;
        while(ht[idx]!=-1){
            idx=(idx+1)%n;

        }
        ht[idx]=key;
    }
    return ht;
}
