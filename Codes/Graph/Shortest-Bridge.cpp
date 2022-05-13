class Solution {
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    queue<vector<int> >q;
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis,int n)
    {
        if(i<0 or j<0 or i>=n or j>=n or vis[i][j] or grid[i][j]==0)
        {
            return;
        }
        vis[i][j]=1;
        q.push({i,j,0});
        dfs(grid,i+1,j,vis,n);
        dfs(grid,i-1,j,vis,n);
        dfs(grid,i,j+1,vis,n);
        dfs(grid,i,j-1,vis,n);
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int> > vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,vis,n);
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        int ans=INT_MAX;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int x=p[0]+dx[i],y=p[1]+dy[i];
                //cout<<x<<" "<<y<<endl;
                if(x>=0 and y>=0 and x<n and y<n and !vis[x][y])
                {
                    if(grid[x][y]==1)
                    {
                        ans=min(ans,p[2]);
                    }
                    else
                    {
                        vis[x][y]=1;
                        q.push({x,y,p[2]+1});
                    }
                }
            }
        }
        return ans;
        
    }
};
