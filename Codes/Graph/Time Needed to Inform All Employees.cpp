class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& m, vector<int>& t) {
        vector<int> adj[n];
        for(int i=0;i<m.size();i++)
        {
            if(m[i]!=-1)
            adj[m[i]].push_back(i);
        }
        queue<vector<int> >q;
        q.push({headId,t[headId]});
        int ans=INT_MIN;
        vector<int> vis(n,0);
        vis[headId]=1;
        while(!q.empty())
        {
            int node=q.front()[0];
            int currDur=q.front()[1];
            q.pop();
            
            for(auto nbr:adj[node])
            {
                if(!vis[nbr])
                {
                    q.push({nbr,currDur+t[nbr]});
                    ans=max(ans,currDur+t[nbr]);
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};
