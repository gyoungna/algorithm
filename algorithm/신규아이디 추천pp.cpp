//2021 KAKAO BLIND RECRUITMENT
//���̵� �Է¹ް� ��Ģ�� ���� ���ο� ���̵� ���
// ** tolower(str[i])  :�ҹ��� ��ȯ �޼ҵ�
// ** str.substr(start_index, length) : start_index���� length���̸�ŭ string �ڸ��� 
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        new_id[i] = tolower(new_id[i]);//1�ܰ�
        //2�ܰ�
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= '0' && new_id[i] <= '9') ||
            (new_id[i] >= 'a' && new_id[i] <= 'z')) {
            temp += new_id[i];

        }
    }
    for (int i = 0; i < temp.size();)
    {
        answer += temp[i];
        if (temp[i] == '.')
        {
            while (temp[i] == '.')
                i++;
        }
        else
            i++;
    }

    if (!answer.empty()) {
        if (answer[0] == '.')
            answer = answer.substr(1, answer.length() - 1);
        if (answer[answer.length() - 1] == '.')
            answer = answer.substr(0, answer.length() - 1);
    }
    if (answer.empty())
        answer += 'a';
    if (answer.length() >= 16) {
        answer = answer.substr(0, 15);
        if (answer[0] == '.')
            answer = answer.substr(1, answer.length() - 1);
        if (answer[answer.length() - 1] == '.')
            answer = answer.substr(0, answer.length() - 1);
    }
    if (answer.length() <= 2) {
        while (answer.length() != 3)
            answer += answer[answer.length() - 1];
    }



    return answer;
}