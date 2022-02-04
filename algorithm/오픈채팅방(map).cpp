/*
* 2019 KAKAO BLIND RECRUITMENT
* 채팅방 입장,퇴장 닉네임변경 고려해서 출력
* input: ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
* output: ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
* map<key,value> 
* sstream이용해서 문자열 자르기
*/
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<vector<string>> result; //자른 문자열 저장

    map<string, string> user; //사용자 목록 저장

    //문자열 자르기
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

    for (int i = 0; i < result.size(); i++) //사용자 목록 저장 (닉네임 변경까지 고려)
    {

        if (result[i][0] != "Leave") {

            user[result[i][1]] = result[i][2]; //map 에서의 수정, 추가방법

        }
    }

    for (int i = 0; i < result.size(); i++)//입장,퇴장 출력
    {
        if (result[i][0] == "Enter")
        {
            answer.push_back(user[result[i][1]] + "님이 들어왔습니다.");
        }
        else if (result[i][0] == "Leave")
        {
            answer.push_back(user[result[i][1]] + "님이 나갔습니다.");
        }

    }

    return answer;
}