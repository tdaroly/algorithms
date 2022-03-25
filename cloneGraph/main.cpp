#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
    //BFS is probably a good candidate here
    
     queue<Node*> q;
     unordered_set<Node*> v;
     unordered_map<int, Node* > map_n;
     q.push(node);
     v.insert(node);
     Node *r  = new Node(node->val);
     map_n[node->val] = r;
     while(!q.empty())
     {
         Node* top = q.front();
         q.pop();
         cout<<top->val<<":";
         r = map_n[top->val];
         for(auto it: top->neighbors)
         {
             cout<<it->val<<"->";
             Node *n;
             if(map_n.count(it->val) == 0 ) //thuck means that a node wasnt created for mucknesioum
             {
                 n = new Node(it->val);
                 map_n[it->val] = n;
             }
             else
             {
                 n = map_n[it->val];
             }
             r->neighbors.push_back(n);
             if(v.count(it)==0) //not visted
             {
                 q.push(it);
                 v.insert(it);
             }
         }
         cout<<"\n";
     }
    
        // std::unordered_set<Node*> v1;
        // cout<<"\nbfs1"<<" \n";
        // bfs(node,v1);

        // std::unordered_set<Node*> v2;
        // cout<<"\nbfs2"<<" \n";
        // bfs(r,v1);
        
        return map_n[node->val];
    }



    private:
        void dfs(Node* n, unordered_set<Node*> &v)
        {
            if(v.count(n)>=1) //visited
                return;
            cout<<n->val<<" "<<n<<" \n";
            v.insert(n);
            for(auto it: n->neighbors)
                dfs(it,v);
            
        }

        void bfs(Node*n, unordered_set<Node*> &v)
        {
            queue<Node*> q;
               q.push(n);
               v.insert(n);
               while(!q.empty())
               {
                   Node* top = q.front();
                   q.pop();
                   cout<<top->val<<":";
                   for(auto it:top->neighbors)
                   {
                       cout<<it->val<<"->";
                       if(v.count(it) == 0) //not visited
                       {
                           q.push(it);
                           v.insert(it);
                       }
                   }
                   cout<<"\n";
               }

        }
};

int main()
{

    Solution s;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    s.cloneGraph(node1);

    cout<<"\n";
    return 0;
}