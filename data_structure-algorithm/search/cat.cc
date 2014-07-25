#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std; 

const int N = 9;
const int INF = 1 << 30;
const int dR[6] = {-1, -1, 0, 0, 1, 1};
const int dC[6] = {-1, 0, -1, 1, -1, 0};

class Cat
{
    private:
        int board[N][N];
        queue <int> Q;
        int inQ[N * N];
        int dis[N * N];
    public:
        Cat() {
            memset(inQ, 0, sizeof(inQ));
            fill(dis, dis + N * N, INF);
            while(!Q.empty()) {
                Q.pop();
            }
        }

        Cat(int board[][N]) {
            memcpy(&board, this->board, N * N);
            memset(inQ, 0, sizeof(inQ));
            fill(dis, dis + N * N, INF);
            while(!Q.empty()) {
                Q.pop();
            }
        }
        
        int minStep() {
            int ret = -1;
            init();
            for (int i = 1; i < N * N; i++) {
                if (canCatchCat(i)) {
                    ret = i;
                    break;
                }
            }
            return ret;
        }

        void init() {
            int s = 0;
            for (int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if (board[i][j] == 2) {
                        s = i * N + j;
                        inQ[s] = 1;
                        dis[s] = 0;
                        Q.push(s);
                    }
                }
            }
            while(!Q.empty()) {
                int u = Q.front();
                Q.pop();
                inQ[u] = 0;
                int r = u / N, c = u % N;
                for (int i = 0; i < 6; i++) {
                    int nextR = r + dR[i];
                    int nextC = c + dC[i] + r % 1;
                    int v = nextR * N + nextC;
                    if (nextR < N && nextC >= 0 && nextC < N && nextC >= 0 && board[nextR][nextC] == 0) {
                        if (dis[v] > dis[u] + 1) {
                            dis[v] = dis[u] + 1;
                            if (!inQ[v]) {
                                inQ[v] = 1;
                                Q.push(v);
                            }
                        }
                    }
                }
            }
        }

        bool canCatchCat(int step) {
            int cnt = 0;
            for (int i = 0; i < N * N; i++) {
                if (dis[i] == step - 1 && board[i / N][i % N] == 0) {
                    cnt++;
                }
            }
            if (cnt <= step) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    ifstream fin("boardConfig.txt");
    string str;
    int board[N][N];
    int r = 0;
    while(fin >> str) {
        for (int c = 0; str[c]; c++) {
            if (str[c] == 'c') {
                board[r][c] = 2;
            } else if (str[c] == 'e') {
                board[r][c] = 1;
            } else {
                board[r][c] = 0;
            }
        }
        r++;
    }
    Cat cat(board);
    cout << cat.minStep() << endl;
    fin.close();
    return 0;
}
