#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;  // Use a member variable for results

    void targetSum(vector<int>& candidates, int idx, int target, vector<int>& subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (idx == candidates.size()) return;

        // Pick the candidate
        if (candidates[idx] <= target) {
            subset.push_back(candidates[idx]);
            targetSum(candidates, idx, target - candidates[idx], subset); // allow picking the same index
            subset.pop_back();  // backtrack
        }

        // Don't pick the candidate
        targetSum(candidates, idx + 1, target, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort candidates
        vector<int> subset;
        targetSum(candidates, 0, target, subset);  // Start from index 0
        return res;
    }
};

int main(){
    
    return 0;
}