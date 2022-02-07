/*
* ���� 11725 Ʈ��
* Ʈ���� ��Ʈ���� 1,����� ������ ����� ���������� ������ �� �� ���(2 ����)���� �θ� ���ϱ�
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
vector<int> node[m]; //node[i][j]= i�� j�� ���� �Ǿ� ���� �� i�� �θ��� ���  
int visited[m]; 
map<int, int> tree; //key: �ڽ�, value: �θ�

int main() {



	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		pair<int, int> temp;
		cin >> temp.first;
		cin >> temp.second;


		//�Է¹޾��� ���� ���� �θ����� ��, ���� �θ��� ��츦 ����� ����
		node[temp.first].push_back(temp.second);
		node[temp.second].push_back(temp.first);

	}

	


	tree[1] = 0;

	connect(1,n);//1�� �ڽ� ���� ã�� 

	
	for (int i = 2; i <= n; i++)
		cout << tree[i] << "\n";
	
}
void connect(int parent,int n)
{
	if (parent == n+1)
		return;

	for (int i = 0; i < node[parent].size(); i++)//parent���� ����� ��� ã�� 
	{
		if (visited[node[parent][i]] == 0)//�̹� �θ� ������ ���� ����
		{
			tree[node[parent][i]] = parent;
			visited[node[parent][i]] = 1;
			connect(node[parent][i], n);//parent�� �ڽĵ��� �ڽ� ã�� 
		}
	}

}