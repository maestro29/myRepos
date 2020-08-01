#include <string>
#include <vector>
#include <iostream>
using namespace std;

void rotate(vector<vector<int>>& key) {
    int tmp[20][20];
    int m = key.size();

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            tmp[i][j] = key[i][j];
 
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            key[i][j] = tmp[m - 1 - j][i];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int m = key.size(), n = lock.size();
    int x, y;
    vector<vector<int>> result(lock);
    
    x = y = (-1) * (m + 2);
    for (x; x < n; x++) {
        for (y; y < n; y++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (x + i >= 0 && y + j >= 0 && x + i < n && y + j < n)
                        result[x + i][y + j] ^= key[i][j];
                }
            }
        }
    }

    for (auto i : result)
        for (auto j : i)
            if (!j) {
                answer = false;
                break;
            }
    return answer;
}

int main() {
    solution({ { 0,0,0 }, { 1,0,0 }, { 0,1,1 } }, { {1,1,1},{1,1,0},{1,0,1} });
}