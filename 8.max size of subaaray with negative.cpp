// using prefiz sum and hashmap here to calculate the len of max subarray

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    unordered_map<long long,int> mp;
    long long prefixsum=0;
    int maxlen=0;
    for(int i=0;i<nums.size();i++){
        prefixsum += nums[i];
        if (prefixsum == k)
        {
            maxlen = i + 1;
        }
        if (mp.find(prefixsum - k) != mp.end())
        {
            maxlen = max(maxlen, i - mp[prefixsum - k]);
        }
        if (mp.find(prefixsum) == mp.end())
        {
            mp[prefixsum] = i;
        }
    }
    return maxlen;
}