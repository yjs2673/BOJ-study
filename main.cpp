// union-find
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m, truth;
int parent[51];
int party[51][51];
int party_size[51];

int find(int x) {
    if(x == parent[x]) return x;
    return x = find(parent[x]);
}

void union_find(int a, int b) {
    int pa = find(a), pb = find(b);
    if(pa != pb) {
        if(pa > pb) parent[pa] = parent[pb];
        else parent[pb] = parent[pa];
    }
}

int main() {
    cin >> n >> m;
    cin >> truth;
    
    for(int i = 0; i <= n; i++) parent[i] = i;
    
    for(int i = 0; i < truth; i++) {
        int num;
        cin >> num;
        parent[num] = 0;
    }
    
    for(int i = 0; i < m; i++) {
        int num, first_person;
        cin >> num >> first_person;
        party_size[i] = num;
        party[i][0] = first_person;
        
        for(int j = 1; j < num; j++) {
            int person;
            cin >> person;
            party[i][j] = person;
            union_find(first_person, person);
        }
    }
    
    int count = m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < party_size[i]; j++) {
            if(find(party[i][j]) == 0) {
                count--;
                break;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
