#include <iostream>
#include <vector>

using namespace std;

int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    int maxSum = dp[0];

    for (int i = 1; i < n; ++i) {
        int maxPrev = INT_MIN;

        for (int j = max(0, i - k); j < i; ++j) {
            maxPrev = max(maxPrev, dp[j]);
        }

        dp[i] = max(maxPrev + nums[i], nums[i]);
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    // Example 1
    vector<int> nums1 = { 10, 2, -10, 5, 20 };
    int k1 = 2;
    cout << "Example 1 Result: " << maxResult(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = { -1, -2, -3 };
    int k2 = 1;
    cout << "Example 2 Result: " << maxResult(nums2, k2) << endl;

    // Example 3
    vector<int> nums3 = { 10, -2, -10, -5, 20 };
    int k3 = 2;
    cout << "Example 3 Result: " << maxResult(nums3, k3) << endl;

    return 0;
}
