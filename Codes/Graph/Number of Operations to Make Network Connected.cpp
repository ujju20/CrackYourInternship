class Solution 
{
    vector<int> par,rank;
    int findParent(int node)
    {
        if(par[node]==node)
        {
            return node;
        }
        return par[node]=findParent(par[node]);
    }
    bool Unioun(int x,int y)
    {
        x=findParent(x);
        y=findParent(y);
        if(x==y)
            return false;
        if(rank[x]>rank[y])
        {
            par[y]=x;
        }
        else if(rank[y]>rank[x])
        {
            par[x]=y;
        }
        else
        {
            par[x]=y;
            rank[y]+=1;
        }
        return true;
    }
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        par= vector<int>(n,0);
        rank= vector<int>(n,0);
        if(n-1>c.size())
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        int sz=c.size();
        int temp=0;
        vector<int> v(n,0);
        for(int i=0;i<sz;i++)
        {
            if(Unioun(c[i][0],c[i][1]))
            {
                temp+=1;
                v[c[i][0]]=1;
                v[c[i][1]]=1;
            }
        }
        if(n-temp-1<=(c.size()-temp))
            return n-temp-1;;
        return -1;
        
        
        
    }
};
