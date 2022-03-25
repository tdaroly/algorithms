#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{

  vector<vector<int>> v = {{1,2},{0,1},{100,3344},{-1,3},{5,6}};

  std::sort(v.begin(),v.end(), [](const vector<int> &a, const vector<int> &b){
          return a[1]<b[1];
      });

for(auto item: v)
  cout<<"["<<item[0]<<","<<item[1]<<"], ";
cout<<"\n";

  return 0;
}
