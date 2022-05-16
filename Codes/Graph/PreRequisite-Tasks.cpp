// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    // Code here
	    vector<int> adj[N];
	    for(int i=0;i<p.size();i++)
	    {
	        adj[p[i].first].push_back(p[i].second);
	    }
	    vector<int> indegree(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto x:adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(auto nbr:adj[node])
	        {
	            indegree[nbr]--;
	            if(indegree[nbr]==0)
	            {
	                q.push(nbr);
	            }
	        }
	    }
	    for(auto x:indegree)
	    {
	        if(x!=0)
	        {
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
