// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int bfs(vector<vector<int>>& grid)
    {
        queue<vector<int>> q;
        // vector<vector<int> >vis(grid,size(),vector<int>(grid[0].size(),0));
        // vis[i][j]=1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int cnt=-1;
        while(!q.empty())
        {
           int sz=q.size();
          
           while(sz--)
           {
               auto v=q.front();
               q.pop();
               
               for(int i=0;i<4;i++)
               {
                   int x=v[0]+dx[i],y=v[1]+dy[i];
                   if(x>=0 and y>=0 and x<grid.size() and y<grid[0].size() and grid[x][y]==1)
                   {
                       grid[x][y]=2;
                       q.push({x,y});
                   }
               }
               
               
           }
            cnt++;
        }
        return cnt;
    }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        int ans=bfs(grid);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
