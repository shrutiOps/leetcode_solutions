class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());
        string first="", mid ="";
        for ( int i =0 ; i< s.length(); i++){
            if( i+1 < s.size() && s[i]==s[i+1]){
                first += s[i];
                i++;
            } else{
                mid= s[i];
            }
        }
        string second = first;
        reverse(second.begin(), second.end());
        return (first + mid + second);
    }
};