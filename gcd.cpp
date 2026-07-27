int calcGCD(int n, int m){
    int rem=n%m;
    while(rem!=0){
        n=m;
        m=rem;
        rem=n%m;
    }
    return m;
}