//2021 īī�� ä�뿬���� ���Ͻ�
//�׿��� ���ε����� ���ڸ� �ǳ� �� �Ϻ� �ڸ����� ���ܾ�� �ٲ� ī�带 �ǳ��ָ� ���ε��� ���� ���ڸ� ã�� ����
//ex) input :"one4seveneight"  output: 1478
//
//**string->int : sstream �̿�
//** <algorithm> str.find("���ڿ�")  : str���� �ش� ���ڿ��� ã�Ƽ� ù idx�� ��ȯ, ������� string:npos��ȯ
//** str.replace(idx, length, new ���ڿ�) : str[idx]���� length�� ���̸�ŭ��  new ���ڿ��� �ٲ��� 
//**string �� ���ڷ� �ٲܶ� ex)"123":->123  : num=num*10+str[i]-'0'
//tip!: one,two,three,,, �� �迭�� �ؼ� �������� �ڵ尡 �� ������������!
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";

    while (s.find("zero") != string::npos)
    {
        int idx = s.find("zero");
        s.replace(idx, 4, "0");
    }
    while (s.find("one") != string::npos)
    {
        int idx = s.find("one");
        s.replace(idx, 3, "1");
    }
    while (s.find("two") != string::npos)
    {
        int idx = s.find("two");
        s.replace(idx, 3, "2");
    }
    while (s.find("three") != string::npos)
    {
        int idx = s.find("three");
        s.replace(idx, 5, "3");
    }
    while (s.find("four") != string::npos)
    {
        int idx = s.find("four");
        s.replace(idx, 4, "4");
    }
    while (s.find("five") != string::npos)
    {
        int idx = s.find("five");
        s.replace(idx, 4, "5");
    }
    while (s.find("six") != string::npos)
    {
        int idx = s.find("six");
        s.replace(idx, 3, "6");
    }
    while (s.find("seven") != string::npos)
    {
        int idx = s.find("seven");
        s.replace(idx, 5, "7");
    }
    while (s.find("eight") != string::npos)
    {
        int idx = s.find("eight");
        s.replace(idx, 5, "8");
    }
    while (s.find("nine") != string::npos)
    {
        int idx = s.find("nine");
        s.replace(idx, 4, "9");
    }

    stringstream ss(s);
    ss >> answer;
    return answer;
}
