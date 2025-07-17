#include <string>
using namespace std;

/**
 * 需要注意的是当l+1后不行的时候还需要回过头考虑r-1的情况。
 *
 */


class Solution {
public:
    bool check(string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        int count = 0;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            } else {
                return check(s, l+1, r) || check(s, l, r-1);
            }
        }
        return true;
    }
};