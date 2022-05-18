class Solution {
    vector<vector<int> >ans;
    void dfs(vector<int> adj[],vector<int> &tin,vector<int> &low,int &timer,int src,vector<int> &vis,int parent)
    {
        vis[src]=1;
        tin[src]=low[src]=timer++;
        for(auto nbr:adj[src])
        {
            if(nbr==parent) continue;
            if(!vis[nbr])
            {
                dfs(adj,tin,low,timer,nbr,vis,src);
                low[src]=min(low[src],low[nbr]);
                if(low[nbr]>tin[src])
                {
                    ans.push_back({src,nbr});
                }
            }
            else
            {
                low[src]=min(low[src],tin[nbr]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<int> tin(n,0),low(n,0);
        int timer=1;
        vector<int> adj[n];
        for(int i=0;i<c.size();i++)
        {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        vector<int> vis(n,0);
        dfs(adj,tin,low,timer,0,vis,-1);
        return ans;
    }
};
