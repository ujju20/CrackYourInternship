class Solution {
    vector<int> ans;
    void dfs(vector<vector<int>>& graph,int src,vector<int> &vis,vector<int> &safe)
    {
        vis[src]=1;
        if(graph[src].size()==0)
        {
            safe[src]=1;
            return;
        }
        for(auto nbr:graph[src])
        {
            if(!vis[nbr])
            {
                dfs(graph,nbr,vis,safe);
            }
        }
        for(auto nbr:graph[src])
        {
            if(safe[nbr])
            {
                continue;
            }
            else
            {
                return;
            }
        }
        safe[src]=true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe(graph.size(),0);
        vector<int> vis(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i])
            {
                dfs(graph,i,vis,safe);
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            if(safe[i]) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
