#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        deque<string> a, b;

        // Helper lambda to split sentences by spaces and fill the deque
        auto fillDeque = [](const string& s, deque<string>& dq) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                dq.push_back(word);
            }
        };

        // Split sentences into deques
        fillDeque(s1, a);
        fillDeque(s2, b);

        // Remove matching words from the front
        while (!a.empty() && !b.empty() && a.front() == b.front()) {
            a.pop_front();
            b.pop_front();
        }

        // Remove matching words from the back
        while (!a.empty() && !b.empty() && a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
        }

        // If one of the deques is empty, sentences are similar
        return a.empty() || b.empty();
    }
};

int main() {
    Solution solution;
    string s1 = "I love eating ice cream";
    string s2 = "I love ice cream";
    cout << (solution.areSentencesSimilar(s1, s2) ? "True" : "False") << endl;

    return 0;
}
