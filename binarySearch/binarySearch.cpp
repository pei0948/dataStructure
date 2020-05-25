#include <iostream>
#include <vector>
using namespace std;

//nums��С�����Ź���
//Ѱ����Ŀ��ֵ��ͬ��Ԫ�أ����������target������-1
int binarySearchEq(vector<int> &nums, int target, int beg, int end)
{
	int mid;
	while(beg<=end)
	{
		mid=beg+((end-beg)>>1);
		if(nums[mid]==target)
		{
			return mid;
		}
		else if(nums[mid]<target)
		{
			beg=mid+1;
		}
		else if(nums[mid]>target)
		{
			end=mid-1;
		}
	}
	return -1;
}

//nums��С�����Ź���
//���nums����target���򷵻�target����С�±꣬���������target������-1
int binarySearchLeft(vector<int> &nums, int target, int tmpBeg, int tmpEnd)
{
	int beg=tmpBeg,
	    end=tmpEnd,
	    mid;
	while(beg<end)
	{
		mid=beg+((end-beg)>>1);
		if(nums[mid]==target)
		{
			end=mid;
		}
		else if(nums[mid]<target)
		{
			beg=mid+1;
		}
		else if(nums[mid]>target)
		{
			end=mid;
		}
	}
	if(beg==tmpEnd)
		return -1;
	return nums[beg]==target?beg:-1;
}

//numsΪ��С�������������
//���nums�д���target������target������±꣬���������target,�򷵻�-1
int binarySearchRight(vector<int> &nums, int target, int tmpBeg, int tmpEnd)
{
	int beg=tmpBeg,
	    end=tmpEnd,
	    mid;
	while(beg<end)
	{
		mid=beg+((end-beg)>>1);
		if(nums[mid]==target)
		{
			beg=mid+1;
		}
		else if(nums[mid]<target)
		{
			beg=mid+1;
		}
		else if(nums[mid]>target)
		{
			end=mid;
		}
	}
	if(beg==0)
		return -1;
	return nums[beg-1]==target?beg-1:-1;
}

int main(int argc, char **argv)
{
	vector<int> nums({1,2,2,2,4,5,5,8,9});
	cout<<binarySearchEq(nums, 1, 0, 8)<<endl;
	cout<<binarySearchEq(nums, 2, 0, 8)<<endl;
	cout<<binarySearchEq(nums, 4, 0, 8)<<endl;
	cout<<binarySearchEq(nums, 5, 0, 8)<<endl;
	cout<<binarySearchEq(nums, 8, 0, 8)<<endl;
	cout<<binarySearchEq(nums, 9, 0, 8)<<endl;
	cout<<binarySearchEq(nums, 3, 0, 8)<<endl;

	cout<<endl;
	cout<<binarySearchLeft(nums, 1, 0, 9)<<endl;
	cout<<binarySearchLeft(nums, 2, 0, 9)<<endl;
	cout<<binarySearchLeft(nums, 4, 0, 9)<<endl;
	cout<<binarySearchLeft(nums, 5, 0, 9)<<endl;
	cout<<binarySearchLeft(nums, 8, 0, 9)<<endl;
	cout<<binarySearchLeft(nums, 9, 0, 9)<<endl;
	cout<<binarySearchLeft(nums, 3, 0, 9)<<endl;

	cout<<endl;
	cout<<binarySearchRight(nums, 1, 0, 9)<<endl;
	cout<<binarySearchRight(nums, 2, 0, 9)<<endl;
	cout<<binarySearchRight(nums, 4, 0, 9)<<endl;
	cout<<binarySearchRight(nums, 5, 0, 9)<<endl;
	cout<<binarySearchRight(nums, 8, 0, 9)<<endl;
	cout<<binarySearchRight(nums, 9, 0, 9)<<endl;
	cout<<binarySearchRight(nums, 3, 0, 9)<<endl;
	return 0;
}

