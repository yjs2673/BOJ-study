// 백트래킹
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
} node;

int n, m;
node* house[50];
node* chick[13];
int selected[13];
int h_idx = 0, c_idx = 0;
int min = 10000000;

int distance(node* a, node* b) {
    int newx = a->x > b->x ? a->x - b->x : b->x - a->x;
    int newy = a->y > b->y ? a->y - b->y : b->y - a->y;
    return newx + newy;
}

void calculate() {
    int dis = 0, sum = 0;
    for(int i = 0; i < h_idx; i++) {
        int chick_dis = 50 * 2;
        
        for(int j = 0; j < m; j++) {
            dis = distance(house[i], selected[j]);
            if(dis < chick_dis) chick_dis = dis;
        }
        sum += chick_dis;
    }
    
    if(sum < min) min = sum;
}

void backtrack(int depth, int count, int chosen) {
    if(chosen == 1) selected[count - 1] = chick[depth];
    if(count == m) {
        calculate();
        return;
    }
    if(depth == c_idx) return;
    
    backtrack(depth + 1, count + 1, 1);
    backtrack(depth + 1, count, 0);
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int num;
            scanf("%d", &num);
            if(num == 1) {
                node* new_node = (node*)malloc(sizeof(node));
                new_node->x = i;
                new_node->y = j;
                house[h_idx++] = new_node;
            } 
            else if(num == 2) {
                node* new_node = (node*)malloc(sizeof(node));
                new_node->x = i;
                new_node->y = j;
                chick[c_idx++] = new_node;
            }
        }
    }

    backtrack(0, 0, -1);

    printf("%d\n", min);
    for(int i = 0; i < h_idx; i++) free(house[i]);
    for(int i = 0; i < c_idx; i++) free(chick[i]);
    return 0;
}
