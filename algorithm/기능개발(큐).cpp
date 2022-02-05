/*
* 기능 개발(큐)
* 기능의 진도가 100일 때 배포, 앞의 기능이 100일때 같이 배포
* input: 기능의 진도(progresses), 개발 속도(speeds)
* output: 한 번 배포될 때 같이 배포되는 기능의 갯수
* 
* ex)input: progresses=[90,30,55] speeds=[1,30,5]
*     ouput: [2,1] => 90이 완성되는 7일에 30과 함께 배포, 9일째에 55 배포
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;


//내 답안
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    int day;

    //첫번째 기능 배포일 구하기 
    if ((100 - progresses[0]) % speeds[0] == 0)
        day = (100 - progresses[0]) / speeds[0];
    else
        day = (100 - progresses[0]) / speeds[0] + 1;
    

 
    while (idx < progresses.size()) {
        int count = 0;
        for (int i = idx; i < progresses.size(); i++)
        {

            //같이 배포될 기능 구하기 
            if (progresses[i] + speeds[i] * day >= 100)
            {
                idx++;
                count++;
            }
            else
                break;
        }
        //배포
        answer.push_back(count);
        
        //배포일 구하기 
        if (idx < progresses.size()) {
            if ((100 - progresses[idx]) % speeds[idx] == 0)
                day = (100 - progresses[idx]) / speeds[idx];
            else
                day = (100 - progresses[idx]) / speeds[idx] + 1;
        }

    }



    return answer;
}
/* 큐를 이용한 답안
* vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;

    //각 기능마다 배포일 구하기
    for(int i = 0; i < progresses.size(); i++) {
        int temp = (100-progresses[i]) % speeds[i];
        if(temp == 0)
            q.push((100-progresses[i]) / speeds[i]);
        else
            q.push((100-progresses[i]) / speeds[i] + 1);
    }

    //같이 배포되는 갯수 구하기 
    while(!q.empty()) {
        int cnt = 1;
        int cur = q.front();
        q.pop();

        while(cur >= q.front() && !q.empty()) {
            q.pop();
            cnt++;
        }

        answer.push_back(cnt);
    }
    return answer;
}
*/