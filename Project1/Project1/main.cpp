#include <string>
#include <vector>
using namespace std;
enum type { k, b };
int a[2][101][101], N;
bool isOK(type t, int x, int y) {
    switch (t) {
    case k:
        if (a[k][x][y-1] || a[b][x][y] || a[b][x-1][y] || !y)
            return true;
        break;
    case b:
        if (a[k][x][y-1] || a[k][x+1][y-1] ||
            (a[b][x-1][y] && a[b][x+1][y]))
            return true;
    }
    return false;
}
#define chk(t,x,y) (x >= 0 && y >= 0 && x <= N && y <= N && a[t][x][y] && !isOK(t,x,y))
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for (auto i : build_frame) {
        int x = i[0], y = i[1];
        switch (i[2]) {
        case k:
            if (i[3] && isOK(k, x, y)) a[k][x][y]++;
            if (!i[3]) {
                a[k][x][y] = 0;
                if (chk(b,x-1,y+1) || chk(b,x,y+1) || chk(k,x,y+1))
                    a[k][x][y]++;
            }
            break;
        case b:
            if (i[3] && isOK(b, x, y)) a[b][x][y]++;
            if (!i[3]) {
                a[b][x][y] = 0;
                if (chk(b,x-1,y) || chk(b,x+1,y) || chk(k,x,y) || chk(k,x+1,y))
                    a[b][x][y]++;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++) {
            if (a[k][i][j]) answer.push_back({ i,j,k });
            if (a[b][i][j]) answer.push_back({ i,j,b });
        }
    return answer;
}
int main() {
    vector<vector<int>> answer;
    answer = solution(5,{ {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} });
    for (auto i : answer) {
        printf("%d %d %d\n", i[0], i[1], i[2]);
    }
}
