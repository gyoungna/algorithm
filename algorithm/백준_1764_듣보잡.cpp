
/*
map.find()
데이터가 존재하면 iterator 객체 반환(auto it=map.find())
데이터가 없으면 map.end()반환
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n,m;
	map<string,int> map;
	
	cin>>n>>m;
	string temp;
	for(int i=0;i<n;i++)
	{
		
		cin>> temp;
		
		map[temp]=1;
	}
	int count=0;
	vector<string> name;
	for(int i=0;i<m;i++)
	{
		cin>>temp;
		if(map.find(temp)!=map.end())
		{
			count++;
			name.push_back(temp);
		}

	}
	
	sort(name.begin(), name.end());
	
	cout<<count<<"\n";
	for(int i=0;i<name.size();i++)
	{
		cout<<name[i]<<"\n";
	}
	
	
}
