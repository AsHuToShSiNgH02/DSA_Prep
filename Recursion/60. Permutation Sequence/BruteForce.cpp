#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void PermutationHelper(string &s, vector<string> &ans, int index){
        if(index == s.size()){
            ans.push_back(s);
            return;
        }

        for(int i = index;i<s.size();i++){
            swap(s[i], s[index]);
            PermutationHelper(s, ans, index+1);
            swap(s[i], s[index]);
        }
    }
    string getPermutation(int n, int k) {
        string s;
        vector<string> ans;

        for(int i = 1;i<=n;i++){
            s.push_back(i + '0');
        }  

        PermutationHelper(s, ans, 0); 

        sort(ans.begin(), ans.end());

        auto it = ans.begin() + (k - 1);

        return *it;
    }
};

int main(){
    
    return 0;
}