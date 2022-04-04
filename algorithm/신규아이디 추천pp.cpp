//2021 KAKAO BLIND RECRUITMENT
//아이디를 입력받고 규칙에 따라 새로운 아이디 출력
// ** tolower(str[i])  :소문자 변환 메소드
// ** str.substr(start_index, length) : start_index부터 length길이만큼 string 자르기 
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        new_id[i] = tolower(new_id[i]);//1단계
        //2단계
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