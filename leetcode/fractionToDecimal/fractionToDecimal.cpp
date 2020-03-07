class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0)
        {
            return "";
        }
        if(numerator==0)
        {
            return "0";
        }
        long long numeratorTmp=numerator;
        long long denominatorTmp=denominator;
        string res="";
        if(numeratorTmp<0)
        {
            if(denominatorTmp<0)
            {
                numeratorTmp=-numeratorTmp;
                denominatorTmp=-denominatorTmp;
            }
            else
            {
                res+="-";
                numeratorTmp=-numeratorTmp;
            }
        }
        else
        {
            if(denominatorTmp<0)
            {
                res+="-";
                denominatorTmp=-denominatorTmp;
            }
        }
        res+=to_string(numeratorTmp/denominatorTmp);
        numeratorTmp=numeratorTmp%denominatorTmp;
        if(numeratorTmp!=0)
        {
            int index=res.size();
            res+=".";
            map<long long, int> m;
            while(numeratorTmp)
            {
                if(m.count(numeratorTmp))
                {
                    res.insert(m[numeratorTmp],"(");
                    res+=")";
                    break;
                }
                m[numeratorTmp]=index+1;
                numeratorTmp*=10;
                while(numeratorTmp<denominatorTmp)
                {
                    numeratorTmp*=10;
                    res+="0";
                    ++index;
                }
                res+=to_string(numeratorTmp/denominatorTmp);
                ++index;
                numeratorTmp=numeratorTmp%denominatorTmp;
            }
        }
        return res;
    }
};