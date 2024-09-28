#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void partitionhelper(string s, vector<vector<string>> &ans, vector<string> subst, int idx){
        if(idx == s.size()){
            ans.push_back(subst);
            return;
        }

        for(int i = idx; i< s.size();++i){
            if(palidrome(s, idx, i)){
                subst.push_back(s.substr(idx, i-idx+1));
                partitionhelper(s,ans,subst,i+1);
                subst.pop_back();
            }
        }
    }

    bool palidrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subst;
        partitionhelper(s,ans,subst,0);
        return ans;
    }
};

int main(){
    
    return 0;
}