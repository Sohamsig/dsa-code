#include <bits/stdc++.h>
using namespace std;

/*
Problem: Russian Doll Envelopes
Given a list of envelopes with width and height,
find the maximum number of envelopes you can nest (one inside another).

Approach:
1. Sort envelopes by width ascending. If widths are equal, sort by height descending.
2. Find the Longest Increasing Subsequence (LIS) of heights.
   - This ensures that widths are strictly increasing, and equal widths don't count.
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes: width asc, height desc if width equal
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // Extract heights
        vector<int> heights;
        for (auto &env : envelopes) heights.push_back(env[1]);

        // Apply LIS on heights
        vector<int> dp;  // dp[i] = smallest ending height of LIS of length i+1
        for (int h : heights) {
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) dp.push_back(h);
            else *it = h;
        }

        return dp.size();
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    cout << "Maximum Russian Doll Envelopes: " << sol.maxEnvelopes(envelopes) << endl;
    return 0;
}
