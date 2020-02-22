class RandomizedSet {
public:
    map<int, int> m;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val))
        {
            return false;
        }
        else
        {
            nums.push_back(val);
            m[val]=nums.size()-1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.count(val))
        {
            m[nums.back()]=m[val];
            swap(nums[m[val]], nums.back());
            nums.pop_back();
            m.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return (nums.empty()?0:nums[rand()%nums.size()]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */