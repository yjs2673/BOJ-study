#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

#define max 100001

using namespace std;

int num_vertex, num_edge;
int id, d[max];
bool finished[max];
vector<int> a[max];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x) {
    d[x] = ++id;
    s.push(x);
    
    int parent = d[x];
    for(int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if(d[y] == 0) parent = min(parent, dfs(y));
        else if(!finished[y]) parent = min(parent, d[y]);
    }
    
    if(parent == d[x]) {
        vector<int> scc;
        while(1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == x) break;
        }
        SCC.push_back(scc);
    }
    
    return parent;
}

int main() {
    std::string input;
    std::getline(std::cin, input); // input one line
    
    std::istringstream iss(input);
    iss >> num_vertex >> num_edge;

    for(int i = 0; i < num_edge; i++) {
        std::string input;
        std::getline(std::cin, input); // input one line
        
        if(input.empty()) break;
        
        int u, v;
        std::istringstream iss(input);
        iss >> u >> v;
        a[u].push_back(v);
    }
    
    for(int i = 1; i <= num_vertex; i++) if(d[i] == 0) dfs(i);
    
    cout << SCC.size() << endl;

    for(int i = 0; i < SCC.size(); i++) {
        sort(SCC[i].begin(), SCC[i].end());
    }
    sort(SCC.begin(), SCC.end());
    for(int i = 0; i < SCC.size(); i++) {
        for(int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << " ";
        cout << "-1" << endl;
    }
    
    return 0;
}
