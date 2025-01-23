// 에라토스테네스의 체
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int card[1000001];
int score[1000001]; // 중복되는 숫자는 없으므로, 숫자 자체에 점수를 매길 수 있음!
vector<int> number;

void input();
void battle();
void print_score();

int main() {
    input();
    battle();
    print_score();
    
    return 0;
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        number.push_back(num);
        card[num] = 1;
    }
    
    return;
}

void battle() {
    for(int i = 0; i < n; i++) {
        for(int j = number[i] * 2; j < 1000001; j += number[i]) {
            if(card[j] == 1) {
                score[number[i]]++;
                score[j]--;
            }
        }
    }
    return;
}

void print_score() {
    for(int i = 0; i < n; i++) cout << score[number[i]] << " ";
    cout << endl;
    
    return;
}
