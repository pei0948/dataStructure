class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int num;
        int len=tokens.size();
        for(int i=0; i<len; i++)
        {
             if(tokens[i]=="+")
            {
                num=nums.top();
                nums.pop();
                num=num+nums.top();
                nums.pop();
                nums.push(num);
            }
            else if(tokens[i]=="-")
            {
                num=nums.top();
                nums.pop();
                num=nums.top()-num;
                nums.pop();
                nums.push(num);
            }
            else if(tokens[i]=="*")
            {
                num=nums.top();
                nums.pop();
                num=nums.top()*num;
                nums.pop();
                nums.push(num);
            }
            else if(tokens[i]=="/")
            {
                num=nums.top();
                nums.pop();
                num=nums.top()/num;
                nums.pop();
                nums.push(num);
            }
            else
            {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};