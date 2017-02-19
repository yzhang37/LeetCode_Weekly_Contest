class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = true;
        bool ufirst = false;
        bool uall = false;
        bool lall = false;
        for (size_t i = 0; i != word.size(); ++i)
        {
            if (i == 0)
            {
                if (word[i] >= 'A' && word[i] <= 'Z')
                {
                    ufirst = true;
                }
                else
                {
                    ufirst = false;
                    lall = true;
                }
            }
            else
            {
                if (word[i] >= 'A' && word[i] <= 'Z')
                {
                    if (!ufirst || lall)
                    {
                        flag = false;
                        break;
                    }
                    uall = true;
                }
                else
                {
                    if (uall)
                    {
                        flag = false;
                        break;
                    }
                    lall = true;
                }
            }
        }
        return flag;
    }
};