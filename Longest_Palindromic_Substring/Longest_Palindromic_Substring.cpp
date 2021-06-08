#include <iostream>
#include <string>

using namespace std;
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.size();
        if (size == 0)
            return s;

        int startPos = 0, maxLen = 1;

        for (int i = 0; i < size; i++)
        {
            int left = i, right = i;
            char mid = s[i];

            // check for all same character, expanding to the right
            while (s[right] == mid)
            {
                right++;
                if (right == size)
                    break;
            }
            right--;   // shrink back to last success
            i = right; // skip past smaller versions of all-same palindrome

            // from arbitrary starting point, expand each end of palindrome per cycle
            while (left >= 0 && right < size)
            {
                if (s[left] != s[right])
                    break;

                left--;
                right++;
            }
            // shrink query space back to last success
            left++;
            right--;

            // update maxLen and starting point
            if (right - left + 1 > maxLen)
            {
                maxLen = right - left + 1;
                startPos = left;
            }
        }

        return s.substr(startPos, maxLen);
    }
};