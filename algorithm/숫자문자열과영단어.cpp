//2021 카카오 채용연계형 인턴십
//네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임
//ex) input :"one4seveneight"  output: 1478
//
//**string->int : sstream 이용
//** <algorithm> str.find("문자열")  : str에서 해당 문자열을 찾아서 첫 idx를 반환, 없을경우 string:npos반환
//** str.replace(idx, length, new 문자열) : str[idx]에서 length의 길이만큼을  new 문자열로 바꿔줌 
//**string 을 숫자로 바꿀때 ex)"123":->123  : num=num*10+str[i]-'0'
//tip!: one,two,three,,, 를 배열로 해서 비교했으면 코드가 더 간결했을지도!
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
