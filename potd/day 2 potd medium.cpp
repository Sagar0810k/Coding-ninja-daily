#include <bits/stdc++.h> 
long long int equalCandies (vector<int> &candies, int n)
{
	// Write your code here.
    sort(candies.begin(),candies.end());
    int median=candies[n/2];
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(candies[i]-median);
    }
    return ans;
    
}