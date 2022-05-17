class Solution {
//     char check(vector<int> v)
//     {
//         char c='#';
        
//     }
public:
    string removeDuplicates(string s, int k) {
      stack<pair<char,int> > st;
        int n=s.size();
        st.push({s[0],1});
        for(int i=1;i<n;i++)
        {
            if(st.size()>0 and s[i]==st.top().first)
            {
                st.top().second+=1;
            }
            else
            {
                st.push({s[i],1});
            }
            if(st.top().second==k)
            {
                st.pop();
            }
        }
        string ans;
        while(!st.empty())
        {
            int cnt=st.top().second;
            char ch=st.top().first;
            while(cnt--)
            {
                ans.push_back(ch);
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
