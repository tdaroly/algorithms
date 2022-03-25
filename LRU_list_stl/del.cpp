#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct r{
    string start;
    string mid;
    string end;
};

class Solution
{

    public:
        r getStartEndMid(vector<vector<string>> tickets)
        {
                unordered_map<string,string> adj;
                unordered_map<string,int> map;
                for(int i=0;i<tickets.size();i++)
                        {
                            adj[tickets[i][0]] = tickets[i][1];
                            map[tickets[i][0]]++;    
                            map[tickets[i][1]]++;
                        }

        string start = "";
        
        for(auto [k,v]:map)
            if(v==1 && start=="" && adj.count(k)>=1)
                start = k;
        
        queue<string> q;
        q.push(start);
        vector<string> v;
        while(!q.empty())
        {
            string top = q.front();
            q.pop();
            v.push_back(top);
            if(adj.count(top)>=1)
                q.push(adj[top]);
        }


    r rr;
        rr.start = start;
        rr.mid = v.size()%2==0 ? v[v.size()/2-1]:v[v.size()/2];
        rr.end = v[v.size()-1];

        return rr;
                
                    
        }



};


int main()
{

    vector<vector<string>> tickets = {{"LHR","NRT"},{"NRT","HKG"},{"JFK","LHR"},{"HKG","SFO"},{"SFO","HTX"}};

    Solution s;
    r RR;
    RR = s.getStartEndMid(tickets);

    return 0;
}