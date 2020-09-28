#include <string>
#include <vector>
using namespace std;
enum type { ki, bo };
int k[101][101], b[101][101], N;
bool chk(type t, int x, int y) {
    if (x < 0 || y < 0 || x > N || y > N)
        return true;
    switch (t) {
    case ki:
        if (k[x][y - 1] || b[x][y] || b[x - 1][y] || y == 0)
            return true;
        break;
    case bo:
        if (k[x][y - 1] || k[x + 1][y - 1] ||
            (b[x - 1][y] && b[x + 1][y]))
            return true;
    }
    return false;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for (auto i : build_frame) {
        int x = i[0], y = i[1];
        switch (i[2]) {
        case ki:
            if (i[3] && chk(ki, x, y)) k[x][y]++;
            if (!i[3]) {
                k[x][y]--;
                if ((b[x-1][y+1] && !chk(bo, x - 1, y + 1))
                    || (b[x][y+1] && !chk(bo, x, y + 1))
                    || (k[x][y+1] && !chk(ki, x, y + 1)))
                    k[x][y]++;
            }
            break;
        case bo:
            if (i[3] && chk(bo, x, y)) b[x][y]++;
            if (!i[3]) {
                b[x][y]--;
                if ((b[x-1][y] && !chk(bo, x - 1, y))
                    || (b[x+1][y] && !chk(bo, x + 1, y))
                    || (k[x][y] && !chk(ki, x, y))
                    || (k[x+1][y] && !chk(ki, x + 1, y)))
                    b[x][y]++;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++) {
            if (k[i][j]) answer.push_back({ i,j,ki });
            if (b[i][j]) answer.push_back({ i,j,bo });
        }
    return answer;
}
int main() {
    vector<vector<int>> answer;
    answer = solution(5, { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} });
    for (auto i : answer) {
        printf("%d %d %d\n", i[0], i[1], i[2]);
    }
}
