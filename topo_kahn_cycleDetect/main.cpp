#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include<queue>
#include <algorithm>
using namespace std;

class Solution
{

public:
    void print_g(unordered_map<char, vector<char>> &adj)
    {
        unordered_set<char> v;
        stack<char> s;
        for (auto [k, val] : adj)
            dfs(k, adj, v, s);
        cout << "\n";
        print_s(s);
    }

    void topo(unordered_map<char, vector<char>> &adj)
    {
        std::unordered_map<char, int> degree;
        vector<char> r;
        for (auto [k, v] : adj) // assume 0 degree
            degree[k] = 0;

        for (auto [k, v] : adj)
        {
            for (auto it : v)
            {
                degree[it]++;
            }
        }
        queue<char> q;

        for(auto [k,v]: degree)
        {
            if(v==0)
                q.push(k);
        }

        if(q.size()==0)
            {
                cout<<"Like a sumbooty";
                return;
            }

            while(!q.empty())
            {
                char n = q.front();
                q.pop();
                cout<<n<<"->";
                r.push_back(n);
                for(auto it:adj[n])
                    {
                        degree[it]--;
                        if(degree[it] == 0)
                            q.push(it);    
                    }

            }
            if(r.size()!=adj.size())
                {
                    cout<<"graph has a cycle my guy";
                    return;
                    }
            
        
    }

private:
    void print_s(stack<char> s) // pass by value cause dont wanna del stack elements yet. learned this trick years ago and it just stayed in mind and this is wy i think i should be doing cp but who knows
    {
        while (!s.empty())
        {
            cout << s.top() << "->";

            s.pop();
        }
    }

    void dfs(char node, unordered_map<char, vector<char>> &adj, unordered_set<char> &v, stack<char> &s)
    {
        if (v.count(node) >= 1) // visited
            return;

        cout << node << " ";
        v.insert(node);

        for (auto it : adj[node])
            dfs(it, adj, v, s);

        s.push(node);
    }
};

int main()
{

    std::unordered_map<char, vector<char>> adj;

    adj['A'] = {'C'};
    adj['B'] = {'C', 'D'};
    adj['C'] = {'E'};
    adj['D'] = {'F'};
    adj['E'] = {'F', 'H'};
    adj['F'] = {'G'};
    

    Solution s;
    
    s.topo(adj);
    cout << "\n";

    return 0;
}