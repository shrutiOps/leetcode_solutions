class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int maxdepth=INT_MIN;
        for(int i =0 ; i< s.length(); i++){
            if(s[i]== '(') maxi++;
            if(s[i] == ')') maxi--;
            maxdepth= max(maxdepth , maxi);
        }
        return maxdepth;
    }
};