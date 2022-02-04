/*
* 2019 KAKAO BLIND RECRUITMENT
* ä�ù� ����,���� �г��Ӻ��� ����ؼ� ���
* input: ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
* output: ["Prodo���� ���Խ��ϴ�.", "Ryan���� ���Խ��ϴ�.", "Prodo���� �������ϴ�.", "Prodo���� ���Խ��ϴ�."]
* map<key,value> 
* sstream�̿��ؼ� ���ڿ� �ڸ���
*/
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<vector<string>> result; //�ڸ� ���ڿ� ����

    map<string, string> user; //����� ��� ����

    //���ڿ� �ڸ���
    for (int i = 0; i < record.size(); i++)
    {
        vector<string> unit;
        stringstream ss(record[i]);
        ss.str(record[i]);

        string word;

        while (ss >> word)
            unit.push_back(word);

        result.push_back(unit);

    }

    for (int i = 0; i < result.size(); i++) //����� ��� ���� (�г��� ������� ���)
    {

        if (result[i][0] != "Leave") {

            user[result[i][1]] = result[i][2]; //map ������ ����, �߰����

        }
    }

    for (int i = 0; i < result.size(); i++)//����,���� ���
    {
        if (result[i][0] == "Enter")
        {
            answer.push_back(user[result[i][1]] + "���� ���Խ��ϴ�.");
        }
        else if (result[i][0] == "Leave")
        {
            answer.push_back(user[result[i][1]] + "���� �������ϴ�.");
        }

    }

    return answer;
}