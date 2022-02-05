/*
* ��� ����(ť)
* ����� ������ 100�� �� ����, ���� ����� 100�϶� ���� ����
* input: ����� ����(progresses), ���� �ӵ�(speeds)
* output: �� �� ������ �� ���� �����Ǵ� ����� ����
* 
* ex)input: progresses=[90,30,55] speeds=[1,30,5]
*     ouput: [2,1] => 90�� �ϼ��Ǵ� 7�Ͽ� 30�� �Բ� ����, 9��°�� 55 ����
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;


//�� ���
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    int day;

    //ù��° ��� ������ ���ϱ� 
    if ((100 - progresses[0]) % speeds[0] == 0)
        day = (100 - progresses[0]) / speeds[0];
    else
        day = (100 - progresses[0]) / speeds[0] + 1;
    

 
    while (idx < progresses.size()) {
        int count = 0;
        for (int i = idx; i < progresses.size(); i++)
        {

            //���� ������ ��� ���ϱ� 
            if (progresses[i] + speeds[i] * day >= 100)
            {
                idx++;
                count++;
            }
            else
                break;
        }
        //����
        answer.push_back(count);
        
        //������ ���ϱ� 
        if (idx < progresses.size()) {
            if ((100 - progresses[idx]) % speeds[idx] == 0)
                day = (100 - progresses[idx]) / speeds[idx];
            else
                day = (100 - progresses[idx]) / speeds[idx] + 1;
        }

    }



    return answer;
}
/* ť�� �̿��� ���
* vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;

    //�� ��ɸ��� ������ ���ϱ�
    for(int i = 0; i < progresses.size(); i++) {
        int temp = (100-progresses[i]) % speeds[i];
        if(temp == 0)
            q.push((100-progresses[i]) / speeds[i]);
        else
            q.push((100-progresses[i]) / speeds[i] + 1);
    }

    //���� �����Ǵ� ���� ���ϱ� 
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