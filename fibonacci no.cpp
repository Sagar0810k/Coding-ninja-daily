vector<int> generateFibonacciNumbers(int n) {
    if(n==0) return {};
    vector<int>fib(n);
    fib[0]=0;
    if(n==1) return {0};
    fib[1]=1;
    for(int i=2;i<n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib;
}