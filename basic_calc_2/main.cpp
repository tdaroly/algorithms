#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> n;
        stack<char> o;
        int r = 0;
        // for(int i=0;i<s.size();i++)
        // {
        //     if(isdigit(s[i]))
        //         n.push(s[i]-'0');
        //     else if(s[i]!=' ')
        //         o.push(s[i]);
        // }
        
        int ptr = 0;
        while(ptr<s.size())
        {
            if(isdigit(s[ptr]))
            {   
                
                string ss = "";

                while(isdigit(s[ptr])!=0)
                    ss+=s[ptr++];
                n.push(stoi(ss));
                    
            }
            else if(s[ptr]!=' ')
                {
                o.push(s[ptr]);
                ptr++;
                }
            else //since space ignore
                ptr++;
                
        }
        
        
        while(!o.empty())
        {
            char oper = o.top();
            o.pop();
            if(oper=='/')
            {
                int right = n.top();
                n.pop();
                int left = n.top();
                n.pop();
                n.push(left/right);
            }
            else if(oper == '+')
            {
               int right = n.top();
                n.pop();
                int left = n.top();
                n.pop();
                n.push(left+right);
            }
               else if(oper == '-')
            {
               int right = n.top();
                n.pop();
                int left = n.top();
                n.pop();
                n.push(left-right);
            }
              else if(oper == '*')
            {
               int right = n.top();
                n.pop();
                int left = n.top();
                n.pop();
                n.push(left*right);
            }
        }
        
        return n.top();
        
    }
};

int main()
{

    Solution s;
    cout<<s.calculate(" 42* 3+ 44+2 /6+ 8/3+21 ");

    return 0;
}