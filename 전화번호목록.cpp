/*
* ���α׷��ӽ� -��ȭ��ȣ���
* �ѹ�ȣ�� �ٸ���ȣ�� ���ξ�� ������ ��� false, else true
* ex)
* input: ["119", "97674223", "1195524421"]
* output: false -> 119�� 1195524421�� ���ξ�� ������ ����
* ���ڿ� sort��� ����!!
* 123,1000,1234  ->sort -> 123,1234,1000
* ��ó�� �ٷ� �� �ܾ �� �ܾ ���Ծ��ϸ� �ڵ� ���� x
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