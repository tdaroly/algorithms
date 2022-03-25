/*
You work in an automated robot factory. Once robots are assembled, they are sent to the shipping center via a series of autonomous delivery carts, each of which moves packages on a one-way route.

Given input that provides the (directed) steps that each cart takes as pairs, write a function that identifies all the start locations, and a collection of all of the possible ending locations for each start location.

In this diagram, starting locations are at the top and destinations are at the bottom - i.e. the graph is directed exclusively downward.

   A         E      J       Key:  [Origins]
  / \       / \      \             \
 B   C     F   L      M            [Destinations]
  \ /  \  /
   K     G
        / \
       H   I

paths = [
  ["A", "B"],
  ["A", "C"],
  ["B", "K"],
  ["C", "K"],
  ["E", "L"],
  ["F", "G"],
  ["J", "M"],
  ["E", "F"],
  ["G", "H"],
  ["G", "I"],
  ["C", "G"]
]

Expected output (unordered):
[ "A": ["K", "H", "I"],
  "E:" ["H", "L", "I"],
  "J": ["M"] ]

N: Number of pairs in the input.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include<unordered_set>
using namespace std;

void print_degree(unordered_map<string, int> degree)
{
    for (auto [k, v] : degree)
        cout << k << ":" << v << "\n";
}

void print_adj(unordered_map<string, vector<string>> adj)
{
    for (auto [k, v] : adj)
    {
        cout << k << ":";
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
}
unordered_map<string, vector<string>> topo(vector<vector<string>> paths)
{
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> degree;
    unordered_map<string, vector<string>> r;
    for (auto it : paths)
    {
        degree[it[0]] = 0;
        degree[it[1]] = 0;
    }
    for (auto it : paths)
    {
        adj[it[0]].push_back(it[1]);
        degree[it[1]]++;
    }

    for (auto [k, v] : degree)
        if (v == 0)
            r[k] = {};

    // print_degree(degree);
    // print_adj(adj);

    queue<string> q;
    // q.push("A");
    unordered_set<string> visited;
    for (auto [k, v] : r)
    {
        q.push(k);
        visited.insert(k);
        while (!q.empty())
        {
            string n = q.front();
            q.pop();
            if (adj.count(n) == 0) // not in adj
            {
                r[k].push_back(n);
            }
            else
            {
                vector<string> t = adj[n];
                for (auto it : t)
                    {

                        if(visited.count(it)==0) //means not visited yet;
                            {
                                q.push(it);
                                visited.insert(it);    
                            }
                    }
            }
        }
        visited.clear();
    }
    
    

    return r;
}

int main()
{
    vector<vector<string>> paths = {
        {"A", "B"},
        {"A", "C"},
        {"B", "K"},
        {"C", "K"},
        {"E", "L"},
        {"F", "G"},
        {"J", "M"},
        {"E", "F"},
        {"G", "H"},
        {"G", "I"},
        {"C", "G"},
    };
    unordered_map<string, vector<string>> r = topo(paths);
    for (auto [k, v] : r)
    {
        cout << k << ":";

        for (auto it : v)
        {

            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
