#include <bits/stdc++.h> 
vector<int> nextGreaterElement(int n, vector<int> A, int m, vector<int> B) {
    // Write your code here.
    vector<int> nge(m,-1);
    stack<int> st;
    for(int i=m-1;i>=0;i--){
        while(!st.empty() && st.top() <=B[i]){
            st.pop();
        }
        if(!st.empty()){
            nge[B[i]]=st.top();
        }
        st.push(B[i]);
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(nge[A[i]]);
    }
    return ans;
}
