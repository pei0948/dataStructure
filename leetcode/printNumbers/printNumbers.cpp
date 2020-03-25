class Solution {
public:
    vector<int> printNumbers1(int n) {
        if(n<1)
        {
            return {};
        }
        int maxNum=pow(10, n);
        vector<int> nums;
        for(int i=1; i<maxNum; ++i)
        {
            nums.push_back(i);
        }
        return nums;
    }
	
	bool increseNum(vector<char> &nums, int &len)
	{
		bool unOverFlow = true;
		int carry = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			int currNum = nums[i] - '0' + carry;
			if (i == len - 1)
				++currNum;
			if(currNum>=10)
			{
				if (i == 0)
				{
					unOverFlow = false;
					break;
				}
				else
				{
					carry=1;
					currNum -= 10;
					nums[i] = currNum + '0';
				}

			}
			else
			{
				nums[i] = currNum + '0';
				break;
			}
		}
		return unOverFlow;
	}

	void coutNums(vector<char> &nums, int &len)
	{
		int begin = 0;
		while (begin<len && nums[begin] == '0')
		{
			++begin;
		}
		while (begin < len)
		{
			cout << nums[begin];
			++begin;
		}
		cout << " ";
	}

	void printNumbers2(int n)
	{
		if (n < 1)
		{
			cout << "" << endl;
			return;
		}
		vector<char> nums(n, '0');
		while (increseNum(nums, n))
		{
			coutNums(nums, n);
		}
	}
	
	void setNextDigit(vector<char> &nums, int &len, int idx)
	{
		if (idx == len)
		{
			coutNums(nums, len);
			return;
		}
		for (int i = 0; i < 10; ++i)
		{
			nums[idx] = '0' + i;
			setNextDigit(nums, len, idx + 1);
		}
	}

	void printNumbers3(int n)
	{
		if (n < 1)
		{
			cout << "" << endl;
		}
		vector<char> nums(n, '0');
		for (int i = 0; i < 10; ++i)
		{
			nums[0] = '0' + i;
			setNextDigit(nums, n, 1);
		}
	}

};

模拟加法
bool increseNum(vector<char> &nums, int &len)
{
	bool unOverFlow = true;
	int carry = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		int currNum = nums[i] - '0' + carry;
		if (i == len - 1)
			++currNum;
		if(currNum>=10)
		{
			if (i == 0)
			{
				unOverFlow = false;
				break;
			}
			else
			{
				carry=1;
				currNum -= 10;
				nums[i] = currNum + '0';
			}

		}
		else
		{
			nums[i] = currNum + '0';
			break;
		}
	}
	return unOverFlow;
}

void coutNums(vector<char> &nums, int &len)
{
	int begin = 0;
	while (begin<len && nums[begin] == '0')
	{
		++begin;
	}
	while (begin < len)
	{
		cout << nums[begin];
		++begin;
	}
	cout << " ";
}

void printNumbers2(int n)
{
	if (n < 1)
	{
		cout << "" << endl;
		return;
	}
	vector<char> nums(n, '0');
	while (increseNum(nums, n))
	{
		coutNums(nums, n);
	}
}



排列
void setNextDigit(vector<char> &nums, int &len, int idx)
{
	if (idx == len)
	{
		coutNums(nums, len);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		nums[idx] = '0' + i;
		setNextDigit(nums, len, idx + 1);
	}
}

void printNumbers3(int n)
{
	if (n < 1)
	{
		cout << "" << endl;
	}
	vector<char> nums(n, '0');
	for (int i = 0; i < 10; ++i)
	{
		nums[0] = '0' + i;
		setNextDigit(nums, n, 1);
	}
}
