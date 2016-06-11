#include <iostream>
using namespace std;

const int MAX_HW = 100;
int H, W;
char S[MAX_HW][MAX_HW];
char G[MAX_HW][MAX_HW];

void dfs(int h, int w) {
    bool flag = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nh = h+i, nw = w+j;
            if (0 <= nh && nh < H && 0 <= nw && nw < W) {
                if (S[nh][nw] != '#') {
                    flag = false;
                }
            }
        }
    }
    if (flag) {
        G[h][w] = '#';
    }
}

bool check() {
    char tmpS[MAX_HW][MAX_HW];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '#') {
                for (int hi = -1; hi <= 1; hi++) {
                    for (int wi = -1; wi <= 1; wi++) {
                        int nh = i+hi, nw = j+wi;
                        if (0 <= nh && nh < H && 0 <= nw && nw < W) {
                            tmpS[nh][nw] = '#';
                        }
                    }
                }
            } else {
                if (tmpS[i][j] != '#') {
                    tmpS[i][j] = '.';
                }
            }
        }
    }

    // cout << "tmpS:" << endl;
    // for (int i = 0; i < H; i++) {
    //     for (int j = 0; j < W; j++) {
    //         cout << tmpS[i][j];
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != tmpS[i][j]) return false;
        }
    }

    return true;
}

int main(void) {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S[i][j];
            G[i][j] = '.';
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dfs(i, j);
        }
    }

    bool flag = check();
    if (flag) {
        cout << "possible" << endl;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << G[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "impossible" << endl;
        // for (int i = 0; i < H; i++) {
        //     for (int j = 0; j < W; j++) {
        //         cout << G[i][j];
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}
