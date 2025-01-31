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

int n, m, cnt = 0, max_cnt = 0;
int map[8][8];
vector<pair<int, int>> loc_two;
vector<pair<int, int>> loc_zero;
bool visited[8][8];

int x_move[4] = {1, -1, 0, 0};
int y_move[4] = {0, 0, 1, -1};

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        for (int j = 0; j < m; j++) {
            cin >> num;
            map[i][j] = num;
            if (num == 0) {
                cnt++;
                loc_zero.push_back(make_pair(i, j));
            }
            else if (num == 2) loc_two.push_back(make_pair(i, j));
        }
    }
}

void bfs() {
    for (int i = 0; i < loc_zero.size() - 2; i++) { // arr.size() vs sizeof(arr) 의 차이점 숙지하기
        int ax = loc_zero[i].first;                 // size()는 요소의 개수, sizeof()은 바이트 수를 반환
        int ay = loc_zero[i].second;
        map[ax][ay] = 1;
        
        for (int j = i + 1; j < loc_zero.size() - 1; j++) {
            int bx = loc_zero[j].first;
            int by = loc_zero[j].second;
            map[bx][by] = 1;
            
            for (int k = j + 1; k < loc_zero.size(); k++) {
                memset(visited, false, sizeof(visited));
                int curr_cnt = cnt - 3;
                
                int cx = loc_zero[k].first;
                int cy = loc_zero[k].second;
                map[cx][cy] = 1;
                
                queue<pair<int, int>> Q;
                for(int l = 0; l < loc_two.size(); l++) {
                    Q.push(make_pair(loc_two[l].first, loc_two[l].second));
                }
                
                while(!Q.empty()) {
                    int Cx = Q.front().first, Cy = Q.front().second;
                    Q.pop();
                    
                    for(int g = 0; g < 4; g++) {
                        int Nx = Cx + x_move[g], Ny = Cy + y_move[g];
                        if(Nx >= 0 && Nx < n && Ny >= 0 && Ny < m && map[Nx][Ny] == 0 && !visited[Nx][Ny]) {
                            visited[Nx][Ny] = true;
                            curr_cnt--;
                            Q.push(make_pair(Nx, Ny));
                        }
                    }
                }
                
                if(curr_cnt > max_cnt) max_cnt = curr_cnt;
                map[cx][cy] = 0;
                curr_cnt++;
            }
            map[bx][by] = 0;
        }
        map[ax][ay] = 0;
    }
}

int main() {
    init();
    bfs();
    cout << max_cnt << endl;
    return 0;
}
