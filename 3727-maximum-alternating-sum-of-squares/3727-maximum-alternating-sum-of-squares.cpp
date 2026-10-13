
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long result = 0;
        int n = squares.size();

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                result -= squares[i];
            } else {
                result += squares[i];
            }
        }

        return result;
    }
};