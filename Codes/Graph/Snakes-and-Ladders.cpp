class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n=b.size();
        bool flag=false;
        // if(n%2)
        //     flag=true;
        map<int,int> m;
        int k=1;
        for(int i=n-1;i>=0;i--)
        {
            if(!flag)
            {
                for(int j=0;j<n;j++)
                {
                    if(b[i][j]!=-1)
                    {
                        m[k]=b[i][j];
                    }
                    k++;
                }
                flag=true;
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(b[i][j]!=-1)
                    {
                        m[k]=b[i][j];
                    }
                    k++;
                } 
                flag=false;
            }
        }
        // for(auto x:m)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        queue<pair<int,int> > q;
        q.push({1,0});
        vector<int> vis(n*n+1,0);
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
                auto node=q.front();
                q.pop();
                for(int i=1;i<=6;i++)
                {
                    int nbr=node.first+i;
                    if(nbr==n*n)
                    {
                        return node.second+1;
                    }
                    if(nbr<=n*n)
                    {
                        if(m.find(nbr)!=m.end())
                        {
                            if(m[nbr]==n*n)
                            {
                                return node.second+1;
                            }
                            if(!vis[m[nbr]])
                            {
                                //cout<<m[nbr]<<" ";
                                vis[m[nbr]]=1;
                                q.push({m[nbr],node.second+1});
                            }
                        }
                        else
                        {
                            if(!vis[nbr])
                            {
                                vis[nbr]=1;
                                q.push({nbr,node.second+1});
                            }
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};
