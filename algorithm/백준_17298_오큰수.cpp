#include <iostream>
#include <stack>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	
	stack<int> list;
	int temp;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		list.push(temp);
	}
	stack<int> t;
	stack<int> answer;
	
	t.push(list.top());
	answer.push(-1);
	list.pop();
	
	while(!list.empty())
	{
		while(!t.empty()&&list.top()>=t.top()){
			t.pop();
		}
		if(t.empty())
		{
			answer.push(-1);
			t.push(list.top());
		}
		else{
			answer.push(t.top());
			t.push(list.top());
		}
		
		list.pop();
		
	}
	
	while(!answer.empty())
	{
		cout<<answer.top()<<" ";
		answer.pop();
	}
	cout<<"\n";
	
	
}
//다른 답안
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	//마지막에 -1 넣어줘야 함
	vector<int> arr(n),ans(n,-1);
	stack<int> s;
	for (int i = 0, t = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i < n ; i++) {
		//오큰수 찾음
		while (!s.empty() && arr[s.top()] < arr[i]) {
			ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}
