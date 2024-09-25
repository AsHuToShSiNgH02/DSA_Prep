#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> subset;
        RemoveDupSubset(nums,subset, res, 0);
        
        for(auto i = res.begin();i != res.end(); i++){
            ans.push_back( *i);
        }

        return ans;
    }

    void RemoveDupSubset(vector<int> &nums,vector<int> subset, set<vector<int>> &res ,int index){
        if(index == nums.size()){
            sort(subset.begin(), subset.end());
            res.insert(subset);
            return;
        }

        subset.push_back(nums[index]);
        RemoveDupSubset(nums,subset, res, index +1);
        subset.pop_back();
        RemoveDupSubset(nums,subset, res, index +1);
    }
};

int main(){
    
    return 0;
}