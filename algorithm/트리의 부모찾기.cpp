/*
* 백준 11725 트리
* 트리의 루트노드는 1,노드의 개수와 연결된 두정점들이 나열될 때 각 노드(2 부터)들의 부모 구하기
* ex) input:
* 7
* 1 6
* 6 3
* 3 5
* 4 1
* 2 4
* 4 7
* output:
* 4
* 6
* 1
* 3
* 1
* 4

*/
#include<iostream>
#include<vector>
#include <map>
using namespace std;
void connect(int parent,int n );

#define m 1000000 + 1
vector<int> node[m]; //node[i][j]= i와 j가 연결 되어 있을 때 i가 부모인 경우  
int visited[m]; 
map<int, int> tree; //key: 자식, value: 부모

int main() {



	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		pair<int, int> temp;
		cin >> temp.first;
		cin >> temp.second;


		//입력받았을 때는 누가 부모인지 모름, 각각 부모일 경우를 고려해 삽입
		node[temp.first].push_back(temp.second);
		node[temp.second].push_back(temp.first);

	}

	


	tree[1] = 0;

	connect(1,n);//1의 자식 먼저 찾기 

	
	for (int i = 2; i <= n; i++)
		cout << tree[i] << "\n";
	
}
void connect(int parent,int n)
{
	if (parent == n+1)
		return;

	for (int i = 0; i < node[parent].size(); i++)//parent한테 연결된 노드 찾기 
	{
		if (visited[node[parent][i]] == 0)//이미 부모가 결정된 노드면 무시
		{
			tree[node[parent][i]] = parent;
			visited[node[parent][i]] = 1;
			connect(node[parent][i], n);//parent의 자식들의 자식 찾기 
		}
	}

}