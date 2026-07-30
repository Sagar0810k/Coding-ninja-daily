int longestSubarrayWithSumK(vector<int> a, long long k) {
    int l=0,r=0;
    long long sum=0;
    int maxlen=0;
    while(r<a.size()){
        sum+=a[r];
        while(sum>k){
            sum-=a[l];
            l++;
        }
        if(sum==k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}