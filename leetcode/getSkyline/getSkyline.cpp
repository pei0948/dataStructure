class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> all;
        vector<vector<int>> res;

        for(auto &building:buildings)
        {
            all.push_back({building[0], -building[2]});
            all.push_back({building[1], building[2]});
        }
        
        sort(all.begin(), all.end());

        multiset<int> height({0});
        int lastH=0, currH=0;
        for(auto &dot:all)
        {
            if(dot.second<0)
            {
                height.insert(-dot.second);
            }
            else
            {
                height.erase(height.find(dot.second));
            }
            currH=*(height.rbegin());
            if(lastH!=currH)
            {
                res.push_back({dot.first, currH});
                lastH=currH;
            }
        }
        return res;
    }
};