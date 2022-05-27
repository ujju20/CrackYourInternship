// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int> > ans;
    bool check(vector<vector<int> > grid,int r,int c,int n)
    {
        for(int i=0;i<r;i++)
        {
            if(grid[i][c])
            {
                return false;
            }
        }
        for(int i=0;i<c;i++)
        {
            if(grid[r][i])
            {
                return false;
            }
        }
        for(int i=r,j=c;i>=0 and j>=0;i--,j--)
        {
            if(grid[i][j])
            return false;
        }
        for(int i=r,j=c;i>=0 and j<n;i--,j++)
        {
            if(grid[i][j])
            return false;
        }
        return true;
        
        
    }
    
    void rec(vector<vector<int> > grid,int row,int n,vector<int> temp)
    {
        if(row==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(check(grid,row,i,n))
            {
                temp.push_back(i+1);
                grid[row][i]=1;
                rec(grid,row+1,n,temp);
                temp.pop_back();
                grid[row][i]=0;
            }
        }
        return;
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> temp;
        vector<vector<int> > grid(n,vector<int> (n,0));
        rec(grid,0,n,temp);
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
