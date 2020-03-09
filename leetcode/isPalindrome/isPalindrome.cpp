class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")
        {
            return true;
        }
        int low=0;
        int high=s.size()-1;
        while(low<high)
        {
            while(!((s[low]>='a' && s[low]<='z')
                    ||(s[low]>='0' && s[low]<='9')
                    || (s[low]>='A' && s[low]<='Z')))
            {
                ++low;
                if(low>=high)
                {
                    return true;
                }
            }
            if(s[low]>='A' && s[low]<='Z')
            {
                s[low]+=32;
            }

            while(!((s[high]>='a' && s[high]<='z')
                    ||(s[high]>='0' && s[high]<='9')
                    || (s[high]>='A' && s[high]<='Z')))
            {
                --high;
                if(high<=low)
                {
                    return true;
                }
            }
            if(s[high]>='A' && s[high]<='Z')
            {
                s[high]+=32;
            }

            if(s[low]!=s[high])
            {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};