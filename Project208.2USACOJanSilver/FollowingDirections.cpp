//
// Created by Kevin Yang on 1/28/23.
//

#include <iostream>

using namespace std;

const int N = 1502;
int n, q;

typedef struct Node {
    int x;
    int y;
    bool direction;
    int cows;
    int cost;
    Node *next;
} Node;

Node field[N][N];
int bottomVats[N], rightVats[N], cost[N];

void updateFieldAt(Node *node, int difference) {
    node->cows += difference;
    if (node->next != nullptr) {
        updateFieldAt(node->next, difference);
    }
}

void flip() {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    updateFieldAt(field[x][y].next, -field[x][y].cows);
    field[x][y].direction = !field[x][y].direction;
    field[x][y].next = field[x][y].direction ? &field[x][y + 1] : &field[x + 1][y];
    updateFieldAt(field[x][y].next, field[x][y].cows);
}

int calculateCost() {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += field[n][i].cows * field[n][i].cost;
        totalCost += field[i][n].cows * field[i][n].cost;
    }
    return totalCost;
}

int main() {
    // Input
    cin >> n;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            field[i][j].x = i;
            field[i][j].y = j;
            char direction;
            cin >> direction;
            switch (direction) {
                case 'R':
                    field[i][j].direction = true;
                    field[i][j].next = &field[i][j + 1];
                    break;
                case 'D':
                    field[i][j].direction = false;
                    field[i][j].next = &field[i + 1][j];
                    break;
            }
        }
        cin >> field[i][n].cost;
    }
    for (int j = 0; j < n; j++) {
        cin >> field[n][j].cost;
    }

    // Calculate initial cows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i][j].cows++;
            field[i][j].next->cows += field[i][j].cows;
        }
    }

    // Flip direction day by day and calculate and output cost
    cin >> q;
    for (int i = 0; i < q; i++) {
        cost[i] = calculateCost();
        flip();
    }
    cost[q] = calculateCost();

    for (int i = 0; i <= q; i++) {
        cout << cost[i] << endl;
    }
    return 0;
}