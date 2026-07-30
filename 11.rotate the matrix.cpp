#include <bits/stdc++.h> 
vector<vector<int>> solve(vector<vector<int>> &arr, int k)
{   int n=arr.size();
    // Write your code here.
    k%=n;
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][(j+k)%n]=arr[i][j];
        }
    }
    return ans;
}