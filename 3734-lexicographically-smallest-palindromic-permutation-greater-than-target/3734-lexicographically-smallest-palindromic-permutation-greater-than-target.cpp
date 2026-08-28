class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        bool possible = true;
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                odd++;
            }
        }
        if (odd > 1)
            possible = false;
        else if (odd == 1 && n % 2 == 0)
            possible = false;
        if (!possible)
            return "";
        char midvalue = 0;
        if (n % 2 == 1) {
            int oddindex = -1;
            for (int i = 0; i < 26; i++) {
                if (count[i] % 2 == 1) {
                    oddindex = i;
                    break;
                }
            }
            midvalue = char('a' + oddindex);
            count[oddindex]--;
        }

        int half = n / 2;
        for (int i = 0; i < half; i++) {
            count[target[i] - 'a'] -= 2;
        }
        if (check(count)) {
            string head = target.substr(0, half);
            string rev = head;
            reverse(rev.begin(), rev.end());
            string tail = "";
            if (midvalue != 0)
                tail += midvalue;
            tail += rev;
            if (tail > target.substr(half)) {
                return head + tail;
            }
        }
        for (int i = half - 1; i >= 0; i--) {
            char w = target[i];
            count[w - 'a'] += 2;
            if (!check(count))
                continue;
            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (count[j] < 2)
                    continue;
                count[j] -= 2;
                string res = target.substr(0, i);
                res += char('a' + j);
                for (int k = 0; k < 26; k++) {
                    int cnt = count[k] / 2;
                    if (cnt > 0) {
                        res.append(cnt, char('a' + k));
                    }
                }
                string part = res;
                reverse(part.begin(), part.end());
                if (midvalue != 0)
                    res += midvalue;
                res += part;
                return res;
            }
        }
        return "";
    }

    bool check(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] < 0)
                return false;
        }

        return true;
    }
};