//priority_queue: queue 라이브러리에 존재

#include <string>
#include <vector>
#include <algorithm>
#include <queue> //priority_queue 라이브러리
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer =0;

    priority_queue<int, vector<int>, greater<int>> q;  //priority_queue 작은 순으로 정렬해줌
    for(int i=0;i<scoville.size();i++)
    {
        q.push(scoville[i]);
    }


    while(q.top()<K) //작은 순서대로 팝
    {
        int temp=q.top();
        q.pop();
        temp+=q.top()*2;
        q.pop();
        q.push(temp);
        answer++;
        if(answer==scoville.size()-1&&q.top()<K){
            answer=-1;
            break;
        }
    }

    return answer;
}
