// https://www.interviewcake.com/concept/java/counting-sort

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> r;
        vector<string> cp = strs;
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < cp.size(); i++)
        {
            std::sort(cp[i].begin(), cp[i].end());
            map[cp[i]].push_back(strs[i]);
        }

        for (auto [k, v] : map)
            r.push_back(v);

        return r;
    }

    // private:

    string countSort(string s)
    {
        if (s == "")
            return s;
        if (s.size() == 1)
            return s;
        
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++)
            ++v[s[i] - 'a'];
        
        s = "";
        for (int i = 0; i < v.size(); i++)
            if (v[i] != 0)
            {
                for (int j = 0; j < v[i]; j++)
                    s += i + 'a';
            }

        return s;
    }
};

int main()
{

    Solution s;
    string t = "ajfdhfjdfjdfjdfdj";
    cout << t << "\n";
    cout << s.countSort(t) << "\n";
    sort(t.begin(), t.end());
    cout << t;
    cout << endl;

    return 0;
}