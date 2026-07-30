//sort and check 

int isSorted(int n, vector<int> a) {
    // Write your code here.
    vector<int>b=a;
    sort(a.begin(),a.end());
    return a==b;
}


//check in place without extra space and onplace
int isSorted(int n, vector<int> a) {
    for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]) return 0;

    }
    return 1;
}
