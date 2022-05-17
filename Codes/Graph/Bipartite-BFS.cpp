// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool bfs(vector<int> adj[],int src,int V,vector<int> &col)
    {
        queue<int> q;
        q.push(src);
        col[src]=0;
        int c=0;
        while(!q.empty())
        {
            int sz=q.size();
            c=1-c;
            while(sz--)
            {
            int node=q.front();
            q.pop();
            for(auto nbr:adj[node])
            {
                if(col[nbr]==-1)
                {
                    col[nbr]=c;
                    q.push(nbr);
                }
                if(col[nbr]==col[node])
                {
                    return false;
                }
            }
            }
            
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(col[i]==-1)
	        {
	            if(!bfs(adj,i,V,col))
    	            return false;
	        }
	    }
	    return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
