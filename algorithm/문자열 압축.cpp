/*
* 2020 KAKAO BLIND RECRUITMENT 
* 문자열 압축
* 문자열을 1개 이상의 단위로 잘라 압축
* 예)
* aabbaccc -> 2a2ba3c (1개 단위)
* abcabcdede -> 2abcdede (3개 단위)
*/





#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++)//단위
    {
        string temp = "";
        int idx = 0;
        string unit = s.substr(idx, i);
        idx = idx + i;
        int count = 1;
        while (idx <= s.length() - 1)
        {

            if (unit == s.substr(idx, i))//같은 거 발견
            {
                count++;
                idx = idx + i;

            }
            else {//다른거 발견
                if (count == 1)
                    temp += unit;
                else
                    temp += to_string(count) + unit;

                count = 1;
                unit = s.substr(idx, i);
                idx = idx + i;
            }
        }
        if (count == 1)
            temp += unit;
        else
            temp += to_string(count) + unit;
        if (answer > temp.length())
            answer = temp.length();
    }




    return answer;
}
