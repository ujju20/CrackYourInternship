class StockSpanner {
    stack<pair<int,int> > s1;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        if(s1.empty())
        {
            s1.push({price,1});
        }
        else
        {
            while(!s1.empty() and s1.top().first<=price)
            {
                cnt+=s1.top().second;
                s1.pop();
            }
            s1.push({price,cnt});
        }
        
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
