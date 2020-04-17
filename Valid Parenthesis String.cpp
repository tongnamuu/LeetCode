class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length();
        int val = 0, e = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
                ++val;
            else
                --val;
            if (s[i] != ')')
                ++e;
            else
                --e;
            if (e < 0)
                break;
            val = max(val, 0);
        }
        if (val)
            return false;
        return true;
    }
};
