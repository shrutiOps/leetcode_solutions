using ll = long long;

class RollingHash {
public:
    const ll base = 100003;
    const ll mod = 1000000007;

    vector<ll> hash;
    vector<ll> power;

    RollingHash(vector<int>& v) {
        int n = v.size();

        hash.resize(n + 1, 0);
        power.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + v[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }

    ll getHash(int l, int r) {
        return (hash[r + 1] 
                - hash[l] * power[r - l + 1] % mod 
                + mod) % mod;
    }
};

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;

        RollingHash rh(nums);

        while (l <= r) {
            int mid = l + (r - l) / 2;

            unordered_map<ll, int> mp;
            for (int i = 0; i + mid <= n; i++) {
                ll hash = rh.getHash(i, i + mid - 1);
                mp[hash]++;
            }

            bool flag = false;

            for (auto& x : mp) {
                if (x.second == 1) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};