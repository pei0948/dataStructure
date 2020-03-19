#include <vector>
using namespace std;

template <typename T>
void bubbleSort(vector<T> &nums)//O(n^2)
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	bool unSorted = true;
	while (unSorted)
	{
		unSorted = false;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i - 1] > nums[i])
			{
				swap(nums[i - 1], nums[i]);
				unSorted = true;
			}
		}
		--len;
	}
}

template <typename T>
int getMax(vector<T> &nums, int n)
{
	if (n == 0)
	{
		return 0;
	}
	int maxIdx = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (nums[i] > nums[maxIdx])
		{
			maxIdx = i;
		}
	}
	return maxIdx;
}
template <typename T>
void selectSort(vector<T> &nums)//O(n^2)
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	int maxIdx;
	for (int i = len - 1; i > 0; --i)
	{
		maxIdx = getMax(nums, i);
		swap(nums[i], nums[maxIdx]);
	}
}

template <typename T>
void insertSort(vector<T> &nums)//O(n^2)
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	for (int i = 1; i < len; ++i)
	{
		T temp = nums[i];
		int j = i;
		while (j > 0 && nums[j - 1] > temp)
		{
			nums[j] = nums[j - 1];
			--j;
		}
		nums[j] = temp;
	}
}

template <typename T>
void quickSort(vector<T> &nums, int lowTmp, int highTmp)//O(nlogn)
{
	if (highTmp - lowTmp < 2)
	{
		return;
	}
	swap(nums[lowTmp], nums[rand() % (highTmp - lowTmp) + lowTmp]);
	int low = lowTmp,
		high = highTmp-1,
		pivot = nums[low];
	while (low < high)
	{
		while (low < high)
		{
			if (nums[high] > pivot)
			{
				--high;
			}
			else
			{
				nums[low] = nums[high];
				++low;
				break;
			}
		}
		while (low < high)
		{
			if (nums[low] < pivot)
			{
				++low;
			}
			else
			{
				nums[high] = nums[low];
				--high;
				break;
			}
		}
	}
	nums[low] = pivot;
	quickSort(nums, lowTmp, low);
	quickSort(nums, low + 1, highTmp);
}

template <typename T>
void merge(vector<T> &nums, int low, int mid, int high)
{
	vector<T> left(nums.begin() + low, nums.begin() + mid);

	int idxL = 0,
		idxR = mid,
		idx=low;
	int lenLeft = mid - low;
	while (idxL < lenLeft || idxR < high)
	{
		if ((idxL < lenLeft)
			&& (idxR >= high || left[idxL] <= nums[idxR]))
		{
			nums[idx] = left[idxL];
			++idxL;
			++idx;
		}
		if ((idxR < high)
			&& (idxL >= lenLeft || nums[idxR] < left[idxL]))
		{
			nums[idx] = nums[idxR];
			++idx;
			++idxR;
		}
	}
}

template <typename T>
void mergeSort(vector<T> &nums, int low, int high)//O(nlogn)
{
	if (high - low < 2)
	{
		return;
	}
	int mid = ((low + high) >> 1);
	mergeSort(nums, low, mid);
	mergeSort(nums, mid, high);
	merge(nums, low, mid, high);
}

template <typename T>
void shellSort(vector<T> &nums)//O(nlogn)
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	int gap = 1;
	while (gap < len / 3)
	{
		gap = gap * 3 + 1;//保证最后间隔变为1
	}
	while (gap > 0)
	{
		for (int i = 0; i < gap; ++i)
		{
			for (int j = i + gap; j < len; ++j)
			{
				int temp = nums[j];
				int k = j;
				while (k >= gap && nums[k - gap] > temp)
				{
					nums[k] = nums[k - gap];
					k -= gap;
				}
				nums[k] = temp;
			}
		}
		gap /= 3;
	}
}

template <typename T>
void adjustHeap(vector<T> &nums, int end, int i)
{
	int maxIdx = ((i << 1) ^ 1);
	while (maxIdx < end)
	{
		if (maxIdx + 1 < end && nums[maxIdx] < nums[maxIdx + 1])
		{
			maxIdx += 1;
		}
		if (nums[i] >= nums[maxIdx])
		{
			break;
		}
		swap(nums[i], nums[maxIdx]);
		i = maxIdx;
		maxIdx = ((i << 1) ^ 1);
	}

}
template <typename T>
void makeHeap(vector<T> &nums, int &len)
{
	for(int i=len/2-1; i>=0; --i)
	{
		adjustHeap(nums, len, i);
	}
}
template <typename T>
void heapSort(vector<T> &nums)//O(nlogn)
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	makeHeap(nums, len);
	for (int i = len - 1; i > 0; --i)
	{
		swap(nums[0], nums[i]);
		adjustHeap(nums, i, 0);
	}
}

void bucketSort(vector<int> &nums)//O(n+k)
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	int maxV = nums[0];
	for (int i = 1; i < len; ++i)
	{
		if (nums[i] > maxV)
		{
			maxV = nums[i];
		}
	}
	vector<int> buckets(maxV + 1,0);
	for (int &num : nums)
	{
		++buckets[num];
	}
	int idx = 0;
	for (int i = 0; i <= maxV; ++i)
	{
		while (buckets[i] > 0)
		{
			nums[idx] = i;
			++idx;
			--buckets[i];
		}
	}
}

void countSort(vector<int> &nums)//O(n+k)
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	int maxV = nums[0];
	for (int &num : nums)
	{
		if (num > maxV)
		{
			maxV = num;
		}
	}
	vector<int> cnt(maxV+1, 0);
	for (int &num : nums)
	{
		++cnt[num];
	}
	for (int i = 1; i <= maxV; ++i)
	{
		cnt[i] += cnt[i - 1];
	}
	vector<int> numsTemp(nums);
	for (int i = len - 1; i >= 0; --i)//一定要从后面开始，以应对同一个桶里面的数据
	{
		--cnt[numsTemp[i]];
		nums[cnt[numsTemp[i]]] = numsTemp[i];
	}
}

int getNumOfDigit(vector<int> &nums)
{
	int numOfDigit = 1;
	int base = 10;
	for (int &num : nums)
	{
		while (num > base)
		{
			base *= 10;
			++numOfDigit;
		}
	}
	return numOfDigit;
}
void radixSort(vector<int> &nums)//O(k*(m+n)),k为数字中的最大位数，m为桶数量，n为输入数据数量
{
	int len = nums.size();
	if (len < 2)
	{
		return;
	}
	int numOfDigit = getNumOfDigit(nums);
	int base = 1;
	vector<int> cnt(10, 0);
	vector<int> tmpNums(nums);
	int bucket;
	while (numOfDigit > 0)
	{
		cnt.clear();
		cnt.resize(10, 0);
		for (int &num : nums)
		{
			++cnt[(num / base) %10];
		}
		for (int i = 1; i < 10; ++i)
		{
			cnt[i] += cnt[i - 1];
		}
		for (int j = len - 1; j >= 0; --j)//要从后面开始，以应对同一个桶里面的数据
		{
			bucket = (nums[j] / base) % 10;
			--cnt[bucket];
			tmpNums[cnt[bucket]] = nums[j];
		}
		nums = tmpNums;
		--numOfDigit;
		base *= 10;
	}
}
