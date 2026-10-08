class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int bal = 0;
        for (char c : s) {
            if (c == '(') {
                if (bal++) res.push_back(c);
            } else {
                if (--bal) res.push_back(c);
            }
        }
        return res;
    }
};
