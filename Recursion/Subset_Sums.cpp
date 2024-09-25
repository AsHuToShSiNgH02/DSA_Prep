#include <iostream>
#include <vector>
using namespace std;

void subsetSumsHelper(vector<int>& ans, vector<int>& arr, int sum, int index) {
    if (index < 0) {
        ans.push_back(sum);
        return;
    }
    // Exclude the current element
    subsetSumsHelper(ans, arr, sum, index - 1);
    
    // Include the current element
    subsetSumsHelper(ans, arr, sum + arr[index], index - 1);
}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    subsetSumsHelper(ans, arr, 0, n - 1);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3};  // Example array
    int n = arr.size();

    vector<int> result = subsetSums(arr, n);

    // Print the subset sums
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
