class Solution {
    int eval(int a,int b,string op)
    {
        if(op=="+")
        {
            return a+b;
        }
        if(op=="-")
            return b-a;
        if(op=="*")
            return a*b;
        if(op=="/")
            return b/a;
        return -1;
    }
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        for(int i=0;i<t.size();i++)
        {
            if(isdigit(t[i][0]) or isdigit(t[i][1]))
            {
                s.push(stoi(t[i]));
            }
            else
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int c=eval(a,b,t[i]);
                s.push(c);
            }
        }
        return s.top();
    }
};
