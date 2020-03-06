class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int edge=prerequisites.size();
        if(edge<0)
        {
            return {};
        }
        vector<int> res;
        queue<int> q;
        vector<vector<int>> node(numCourses);
        vector<int> rudu(numCourses, 0);
        for(int i=0; i<edge; ++i)
        {
            node[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++rudu[prerequisites[i][0]];
        }
        for(int i=0; i<numCourses; ++i)
        {
            if(rudu[i]==0)
            {
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            ++cnt;
            int len=node[curr].size();
            for(int i=0; i<len; ++i)
            {
                --rudu[node[curr][i]];
                if(rudu[node[curr][i]]==0)
                {
                    q.push(node[curr][i]);
                }
            }
        }
        if(cnt==numCourses)
        {
            return res;
        }
        else
        {
            return {};
        }
    }
};