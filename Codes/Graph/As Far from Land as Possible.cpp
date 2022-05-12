class Solution {
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void bfs(vector<vector<int>>& grid,int n,vector<vector<int> >&ans)
    {
        queue<vector<int> >q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j,0});
                    ans[i][j]=0;
                }
            }
        }
        int dist=0;
        vector<vector<int> >vis(n,vector<int>(n,0));
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=p[0]+dx[i],y=p[1]+dy[i];
                if(x>=0 and y>=0 and x<n and y<n and grid[x][y]==0 and !vis[x][y])
                {
                    vis[x][y]=1;
                    ans[x][y]=min(ans[x][y],p[2]+1);
                    q.push({x,y,p[2]+1});
                }
            }
        }
        
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int> >ans(n,vector<int>(n,INT_MAX));
        bfs(grid,n,ans);
        int res=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                res=max(res,ans[i][j]);
            }
        }
        if(res==0)
        {
            return -1;
        }
        return res==INT_MAX?-1:res;
    }
};
