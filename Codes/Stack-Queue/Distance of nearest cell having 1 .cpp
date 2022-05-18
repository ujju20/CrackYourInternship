// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    vector<vector<int> > ans;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void bfs(vector<vector<int> >grid,int m,int n)
    {
        queue<vector<int> >q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j,0});
            }
        }
        vector<vector<int> >vis(m,vector<int>(n,0));
        while(!q.empty())
        {
            vector<int> v=q.front();
            q.pop();
            ans[v[0]][v[1]]=v[2];
            for(int i=0;i<4;i++)
            {
                int x=v[0]+dx[i],y=v[1]+dy[i],dist=v[2];
                if(x>=0 and y>=0 and x<m and y<n and grid[x][y]==0 and !vis[x][y])
                {
                    vis[x][y]=1;
                    q.push({x,y,dist+1});
                }
            }
            
        }
    }
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size();
	    int n=grid[0].size();
	    ans=vector<vector<int> >(m,vector<int>(n,0));
	    bfs(grid,m,n);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
