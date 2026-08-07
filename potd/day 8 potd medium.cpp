#include <bits/stdc++.h> 
vector<vector<int>> multiplyMatrices(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    // Write your code here.
    int n=mat1.size();
    int m=mat1[0].size();
    int p=mat2[0].size();

    vector<vector<int>>ans(n,vector<int>(p,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<m;k++){
                ans[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return ans;
}