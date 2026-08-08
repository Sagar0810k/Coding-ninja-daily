#include <bits/stdc++.h> 
unordered_map<string,int>mp;
void wordFilter(vector<string> &words)
{
    //  Write your code here.
    mp.clear();
    for(int i=0;i<(int)words.size();i++){
        string &word =words[i];
        int len=word.size();
        for(int p=1;p<=len;p++){
            string prefix=word.substr(0,p);
            for(int s=1;s<=len;s++){
                string suffix=word.substr(len-s,s);
                string key=prefix+"#"+suffix;
                mp[key]=i;
            }
        }
    }
}

int find(string &prefix, string &suffix)
{
    //  Write your code here.
    string key =prefix+"#"+suffix;
    auto it=mp.find(key);
    if(it!=mp.end()){
        return it->second;
    }
    return -1;
}