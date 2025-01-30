// BFS
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, k;
queue<int> Q;

int dis[100001] = {0,};
int cnt[100001] = {0,};

int main() {
    cin >> n >> k;
    
    Q.push(n);
    cnt[n] = 1;
    
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
     
        for(int new_loc : {curr + 1, curr - 1, curr * 2}) { // 반복문 형태를 이용해 코드를 간결하게
            if(new_loc < 0 || new_loc > 100000) continue;
            
            if(dis[new_loc] == 0) {                                // 새로 발견한 지점 -> 가장 빨리 발견한 것 -> 저장
                dis[new_loc] = dis[curr] + 1;
                cnt[new_loc] = 1;
                Q.push(new_loc);
            }
            else {
                if(dis[new_loc] == dis[curr] + 1) cnt[new_loc]++;  // 나중에 발견한 지점 -> 항상 그 횟수가 최솟값 이상
            }
        }
    }
    
    cout << dis[k] << endl << cnt[k] << endl;
    return 0;
}
