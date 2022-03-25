#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>


using namespace std;

class LRUCache {

    private:
        list<vector<int>> dl;
        unordered_map<int, list<vector<int>>::iterator> map;
        int size = 0;
        

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        
        if(map.count(key)==0)
            return -1;
        
        if(map.count(key)>=1)
        {
            list<vector<int>> ::iterator it = map[key]; //get the iterator to that position'
            vector<int> temp = *it;
            int k = temp[0];
            int v = temp[1];
            dl.erase(it); //remove from list
            dl.push_front({k,v});
            map[k] = dl.begin();
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(dl.size()==0) //either first insert or all removed
        {
            dl.push_back({key,value});
            list<vector<int>>::iterator it = dl.begin();
            map[key] = it;

        }
        else if(dl.size()<size)
        {
            dl.push_front({key,value});
            list<vector<int>>::iterator it = dl.begin();
            map[key] = it;
        }
        else if(dl.size() == size ) // and we are trying to insert another element and its fulls.
        {
            list<vector<int>>::iterator it = dl.end(); //get last leace recently used pointer;
            vector<int> temp = *it;
            int k = temp[0]; //k is least recently used key
            map.erase(k); //purge key from the map;
            dl.push_front({key,value}); //key is new key
            it = dl.begin();
            map[key] = it; //update map with new key

        }
    }
};



int main()
{

    // vector<char> v(26);
    // cout<<"Hello World";
    char a = 'c';
    cout<<a-'a';
    cout<<endl;
    return 0;
}