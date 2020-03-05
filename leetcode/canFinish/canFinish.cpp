class Solution {
public:
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        int edge=prerequisites.size();
        if(edge<1)
        {
            return true;
        }
        vector<vector<int>> node(numCourses, vector<int>());
        vector<int> rudu(numCourses, 0);
        for(int i=0; i<edge; ++i)
        {
            node[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++rudu[prerequisites[i][0]];
        }
        queue<int> q;
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
            ++cnt;
            int chuduSize=node[curr].size();
            for(int i=0; i<chuduSize; ++i)
            {
                --rudu[node[curr][i]];
                if(rudu[node[curr][i]]==0)
                {
                    q.push(node[curr][i]);
                }
            }
        }
        return (cnt==numCourses);
    }
	
	bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        int edge=prerequisites.size();
        if(edge<1)
        {
            return true;
        }
        vector<vector<int>> adjacency(numCourses, vector<int>(numCourses, 0));
        for(int i=0; i<edge; ++i)
        {
            adjacency[prerequisites[i][1]][prerequisites[i][0]]=1;
        }
        vector<int> flag(numCourses, 0);
        /*
        *0代表还未访问
        *1代表存在于当前访问路径上
        *-1代表已经访问过
        */
        for(int i=0; i<numCourses; ++i)
        {
            if(flag[i]==0)
            {
                if(!dfs(adjacency, numCourses, flag, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>> &adjacency, int &numCourses, vector<int> &flag, int currNode)
    {
        flag[currNode]=1;
        for(int i=0; i<numCourses; ++i)
        {
            if(i==currNode || adjacency[currNode][i]==0)
                continue;
            if(flag[i]==0)
            {
                if(!dfs(adjacency, numCourses, flag, i))
                {
                    return false;
                }
            }
            else if(flag[i]==1)
            {
                return false;
            }
        }
        flag[currNode]=-1;
        return true;
    }
};
