/*
* 프로그래머스 -전화번호목록
* 한번호가 다른번호를 접두어로 가지는 경우 false, else true
* ex)
* input: ["119", "97674223", "1195524421"]
* output: false -> 119를 1195524421가 접두어로 가지고 있음
* 문자열 sort방식 이해!!
* 123,1000,1234  ->sort -> 123,1234,1000
* 위처럼 바로 뒤 단어가 앞 단어를 포함안하면 뒤도 포함 x
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {

        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
        {
            answer = false;
            break;
        }

    }
    return answer;
}