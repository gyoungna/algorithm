#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>


using namespace std;

vector<int> inorder;
stack<int> postorder;
map<int, pair<int, int>> tree;
int n;
int daq(int i, int j);
void preorder(int root);
int main() {
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		inorder.push_back(temp);
	}
	for (int j = 0; j < n; j++)
	{
		cin >> temp;
		postorder.push(temp);
	}
	int root=daq(0, n);
	preorder(root);
	//cout << tree[2].second;
	cout << "\n";

}
int daq(int i,int j)
{
	int root = postorder.top();
	postorder.pop();
	int idx = 0;

		for (int k = i; k< j; k++)
		{
			if (root == inorder[k])
			{
				idx = k;
				break;
			}
		}
		if(idx+1<j)
			tree[root].second = daq(idx + 1,j);
		if(i<idx)
			tree[root].first = daq(i, idx);
		//cout << root;
	return root;
}
void preorder(int root)
{
	cout << root<<" ";
	if(tree[root].first)
		preorder(tree[root].first);
	if(tree[root].second)
		preorder(tree[root].second);
}
