#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int lengthOfLongestSubstring(char *s)
// {
//     if (strlen(s) <= 1)
//         return strlen(s);
//     int left = 0;
//     int right = 1;
//     int longest = 0;
//     int change_left = 0;
//     for (int i = 1; i < strlen(s); i++)
//     {
//         change_left = 0;
//         for (int j = left; j < right; j++)
//         {
//             if (s[j] == s[right])
//             {
//                 change_left = 1;
//                 left = j;
//                 break;
//             }
//         }
//         left = change_left ? left + 1 : left;
//         longest = longest > right - left ? longest : right - left + 1;
//         right++;
//     }
//     return longest;
// }

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int i = 0, maxLen = 0;
    int map[256];
    for (int j = 0; j < 256; j++)
        map[j] = -1;

    for (int j = 0; j < len; j++)
    {
        if (map[s[j]] >= i)
        {
            i = map[s[j]] + 1;
        }
        map[s[j]] = j;
        maxLen = j - i + 1 > maxLen ? j - i + 1 : maxLen;
    }
    return maxLen;
}

int main()
{
    char s[] = "abcabcbb";
    lengthOfLongestSubstring(s);
    return 0;
}