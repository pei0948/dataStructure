/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> nums;
    int index=0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        putNums(nestedList);
    }
    void putNums(vector<NestedInteger> &ntdIt)
    {
        int len=ntdIt.size();
        for(int i=0; i<len; i++)
        {
            if(ntdIt[i].isInteger())
            {
                nums.push_back(ntdIt[i].getInteger());
            }
            else
            {
                putNums(ntdIt[i].getList());
            }
        }
    }

    int next() {
        return nums[index++];
    }

    bool hasNext() {
        if(index<nums.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */