#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> hash;
        int longest = 0;
        int start = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(hash.find(s[i]) != hash.end() && hash[s[i]] >= start)
            {
                start = hash[s[i]] +1;
            }
            else
                longest = max(longest, i-start+1);    
            hash[s[i]] = i;
        }
        cout << longest << endl;
        return longest;
    }
};

int main()
{
    string s("abcabcbb");
    Solution a;
    a.lengthOfLongestSubstring(s);
    return 0;
}