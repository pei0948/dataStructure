class Solution {
public:
    struct pairComp
    {
        bool operator() (pair<int, int> x, pair<int, int> y)
        {
            return x.second>y.second;
        }
    };
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        vector<int> results;
        int len=nums.size();
        if(len==0)
        {
            return results;
        }
        map<int, int> m;
        for(int i=0; i<len; i++)
        {
            m[nums[i]]++;
        }
        priority_queue<int, vector<pair<int, int>>, pairComp> pq;
        for(map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
        {
            pq.push(*it);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            results.push_back((pq.top()).first);
            pq.pop();
        }
        return results;
    }
	vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> results;
        int len=nums.size();
        if(len==0)
        {
            return results;
        }
        map<int, int> m;
        for(int i=0; i<len; i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
        {
            pq.push(pair<int, int>(it->second, it->first));
        }
        for(int i=0; i<k; i++)
        {
            results.push_back((pq.top()).second);
            pq.pop();
        }
        return results;
    }
};