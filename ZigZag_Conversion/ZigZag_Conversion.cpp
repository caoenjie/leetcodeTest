#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows <= 1)
            return s;

        string res = "";
        vector<string> pattern(numRows, "");
        int row = 0;
        int down = 1;

        for (int i = 0; i < s.size(); i++)
        {
            pattern[row].push_back(s[i]);

            if (row == 0)
                down = 1;
            else if (row == numRows - 1)
                down = -1;

            row += down;
        }

        for (string row : pattern)
            res += row;
        cout << res << "\0";
        return res;
    }
};

int main()
{
    string s("PAYPALISHIRING");
    Solution a;
    a.convert(s, 4);
    return 0;
}