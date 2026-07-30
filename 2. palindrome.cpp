bool check(string &str,int l,int r){
    if(l>=r) return 1;
    else if(str[l]!=str[r]) return 0;
    return check(str,l+1,r-1);
}

bool isPalindrome(string& str) {
    // Write your code here.
    return check(str,0,str.size()-1);
}

