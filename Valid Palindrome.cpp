class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        int len = s.length();
        string tmp = s;
        for (i = 0;i < len;i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - ('A' - 'a');
        }
        
        j = 0;
        for (i = 0;i < len;i++)
        {
            if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
                tmp[j++] = s[i];
        }
        
        bool flag = true;
        for (i = 0;i < (j+1)/2;i++)
        {
            if (tmp[i] != tmp[j - i - 1])
            {
                flag = false;
            }
        }
        
        if(flag)
        {
            return true;
        }
        return false;
    }
};