class Solution {
public:
    int calculate(string s) {
        int len=s.size();
        stack<int> nums;
        char op='+';
        int num;
        for(int i=0; i<len; i++)
        {
            if(s[i]==' ')
            {
                continue;
            }
            num=0;
            while(i<len && s[i]>=48)
            {
                num=num*10-'0'+s[i];
                i++;
            }
            switch(op)
            {
                case '+':
                    nums.push(num);
                    break;
                case '-':
                    nums.push(-num);
                    break;
                case '*':
                    num=num*nums.top();
                    nums.pop();
                    nums.push(num);
                    break;
                case '/':
                    num=nums.top()/num;
                    nums.pop();
                    nums.push(num);
                    break;
                case ' ':
                    break;

            }
            op=s[i];
        }
        num=0;
        while(!nums.empty())
        {
            num=num+nums.top();
            nums.pop();
        }
        return num;
    }
};