#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1, 0);
        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;
        auto balance = [&]() {
            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            } else if (lower.size() - upper.size() > 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }
        };
        
        auto add = [&](int val) {
            if (lower.empty() || val <= *lower.rbegin()) {
                lower.insert(val);
                lowerSum += val;
            } else {
                upper.insert(val);
                upperSum += val;
            }
            balance();
        };
        
        auto remove = [&](int val) {
            auto it = lower.find(val);
            if (it != lower.end()) {
                lower.erase(it);
                lowerSum -= val;
            } else {
                upper.erase(upper.find(val));
                upperSum -= val;
            }
            balance();
        };
        
        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }
        long long median = *lower.rbegin();
        cost[0] = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
        for (int i = x; i < n; ++i) {
            remove(nums[i - x]);
            add(nums[i]);
            median = *lower.rbegin();
            cost[i - x + 1] = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
        }
        
        vector<long long> dp(n + 1, LLONG_MAX / 2);
        dp[0] = 0;
        for (int j = 1; j <= k; ++j) {
            vector<long long> next_dp(n + 1, LLONG_MAX / 2);
            long long min_prev = LLONG_MAX / 2;
            for (int i = (j - 1) * x; i <= n - x; ++i) {
                min_prev = min(min_prev, dp[i]);
                
                if (min_prev != LLONG_MAX / 2) {
                    next_dp[i + x] = min(next_dp[i + x], min_prev + cost[i]);
                }
            }
            for (int i = 1; i <= n; ++i) {
                next_dp[i] = min(next_dp[i], next_dp[i - i]);
            }
            dp = move(next_dp);
        }
        
        long long ans = LLONG_MAX / 2;
        for (int i = k * x; i <= n; ++i) {
            ans = min(ans, dp[i]);
        }
        return ans == LLONG_MAX / 2 ? -1 : ans;
    }
};