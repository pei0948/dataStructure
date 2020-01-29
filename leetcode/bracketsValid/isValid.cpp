class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
        {
            return true;
        }
        int len=s.length();
        string sTemp;
        for(int i=0; i<len; i++)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{':
                    sTemp.push_back(s[i]);
                    break;
                case ')':
                    if(sTemp.back()=='(')
                    {
                        sTemp.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if(sTemp.back()=='[')
                    {
                        sTemp.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '}':
                    if(sTemp.back()=='{')
                    {
                        sTemp.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return (sTemp.empty());
    }
};