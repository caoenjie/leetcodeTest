# https://leetcode.com/problems/longest-palindromic-substring/
'''
Share
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
'''
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        longest = ""
        centres = [len(s) - 1]
        for diff in range(1, len(s)):
            centres.append(centres[0] + diff)
            centres.append(centres[0] - diff)
                
            for i in centres:
                print(i, end=" ")
            print("")

        for centre in centres:
            if (min(centre + 1, 2 * len(s) - 1 - centre) <= len(longest)):
                break
            if centre % 2 == 0:
                left, right = (centre // 2) - 1, (centre // 2) + 1
            else:
                left, right = centre // 2, (centre // 2) + 1
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            if right - left - 1 > len(longest):
                longest = s[left + 1 : right]
            print(longest)
            return longest

if __name__ == "__main__":
    s = Solution()
    s.longestPalindrome("babcd")
    