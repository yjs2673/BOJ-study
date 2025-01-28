// 스택
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string words, bomb;
    cin >> words >> bomb;
    string S; // 결과 문자열을 저장하는 스택
    
    int len_words = words.length();
    int len_bomb = bomb.length();
    
    for(char c : words) {
        S += c; // 입력 문자열을 하나씩 스택에 추가
        
        if(S.size() >= len_bomb) { // 문자를 추가한 스택의 총 길이가 폭탄의 길이 이상이면
            bool flag = true;      // 스택의 끝 부분이 폭탄과 같은지 체크
            for(int i = 0; i < len_bomb; i++) {
                if(S[S.length() - len_bomb + i] != bomb[i]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) S.erase(S.end() - len_bomb, S.end()); // 같으면 바로 폭탄의 길이만큼 스택의 끝 지우기
        }
    }
    
    cout << (S.empty() ? "FRULA" : S) << endl;
    return 0;
}
