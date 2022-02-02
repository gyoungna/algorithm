/*
* 2020 KAKAO BLIND RECRUITMENT 
* ���ڿ� ����
* ���ڿ��� 1�� �̻��� ������ �߶� ����
* ��)
* aabbaccc -> 2a2ba3c (1�� ����)
* abcabcdede -> 2abcdede (3�� ����)
*/





#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++)//����
    {
        string temp = "";
        int idx = 0;
        string unit = s.substr(idx, i);
        idx = idx + i;
        int count = 1;
        while (idx <= s.length() - 1)
        {

            if (unit == s.substr(idx, i))//���� �� �߰�
            {
                count++;
                idx = idx + i;

            }
            else {//�ٸ��� �߰�
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
