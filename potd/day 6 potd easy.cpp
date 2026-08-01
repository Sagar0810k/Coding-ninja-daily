#include <bits/stdc++.h> 
string isPossible(string str,int n) {
    //	Write your code here. 
    int x=0,y=0;
    int dir=0;
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    for(char ch:str){
        if(ch=='G'){
            x+=dx[dir];
            y+=dy[dir];

        }
        else if(ch=='L'){
            dir=(dir+3)%4;
        }
        else if(ch=='R'){
            dir=(dir+1)%4;
        }
    }
    if((x==0) && (y==0) || dir!=0){
        return "True";

    }
    else{
        return "False";
    }
}
