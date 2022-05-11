class Solution {
    int bfs(vector<vector<int> >&adj,int src,vector<int> &vis)
    {
        int ans=0;
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            //cout<<node<<" ";
            ans++;
            for(auto nbr:adj[node])
            {
                if(!vis[nbr])
                {
                    vis[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& s) {
        int n=s.size();
        vector<vector<int> >adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i][0]==s[j][0] or s[i][1]==s[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans+=bfs(adj,i,vis)-1;
            }
        }
        return ans;
    }
};
