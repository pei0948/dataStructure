class Solution {
public:
    string replaceSpace(string s) {
        if(s=="")
        {
            return "";
        }
        int len=s.size();
        int cntOfBlank=0;
        for(char &c:s)
        {
            if(c==' ')
            {
                ++cntOfBlank;
            }
        }
        int newLen=len+cntOfBlank*2;
        s.resize(newLen);
        int idxNew=newLen-1,
            idxOld=len-1;
        while(idxNew!=idxOld)
        {
            if(s[idxOld]==' ')
            {
                s[idxNew]='0';
                --idxNew;
                s[idxNew]='2';
                --idxNew;
                s[idxNew]='%';
            }
            else
            {
                s[idxNew]=s[idxOld];
            }
            --idxNew;
            --idxOld;
        }
        return s;
    }
};