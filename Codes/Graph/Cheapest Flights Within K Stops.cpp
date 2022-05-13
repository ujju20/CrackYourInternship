class Solution {
    priority_queue<int,vector<int>,greater<int> >pq;
    int bfs(vector<pair<int,int> >adj[],int src,int dst,int k,int n)
    {
        
        queue<vector<int> >q;
        q.push({src,0,1});
        vector<int> costs(n,INT_MAX);
        costs[src]=0;
        vector<int> vis(n,0);
        vis[src]=1;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            if(p[2]>=k+2)
            {
                continue;
            }
            for(auto nbr:adj[p[0]])
            {
                if(costs[nbr.first]>p[1]+nbr.second)
                {
                    costs[nbr.first]=p[1]+nbr.second;
                    q.push({nbr.first,nbr.second+p[1],p[2]+1});
                }
            }
        }
        if(costs[dst]==INT_MAX)
        {
            return -1;
        }
        return costs[dst];
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        queue<vector<int> > q;
        vector<pair<int,int> >adj[n];
        for(int i=0;i<f.size();i++)
        {
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        return bfs(adj,src,dst,k,n);
    }
};
