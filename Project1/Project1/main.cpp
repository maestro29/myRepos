#include <string>
#include <vector>
#include <iostream>
using namespace std;

void rotate(vector<vector<int>>& key) {
    int m = key.size();
    vector<vector<int>> tmp(key);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            key[i][j] = tmp[m - 1 - j][i];
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(), n = lock.size();
    int z = 4;
    while (z--) {
        for (int x = 1 - m; x < n; x++) {
            for (int y = 1 - m; y < n; y++) {
                int sum = 0;
                vector<vector<int>> combine(lock);
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        if (x + i >= 0 && y + j >= 0 && x + i < n && y + j < n)
                            combine[x + i][y + j] = (key[i][j] ^ combine[x + i][y + j]) ? 1 : 0;
                    }
                }
                for (auto i : combine)
                    for (auto j : i)
                        sum += j;
                if (sum == n * n)
                    return true;
            }
        }
        rotate(key);
    }
    return false;
}

int main() {
    bool result = solution({ { 0,0,1},{1,0,0},{1,0,0} }, { {1,1,1,1,1},{1,1,1,1,1},{1,1,0,1,1},{1,1,1,1,1},{1,1,1,0,0} });
    cout << ((result)? "true" : "false");
}