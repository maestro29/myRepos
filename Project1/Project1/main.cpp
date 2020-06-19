#include <iostream>
using namespace std;
int r, c, ans = 0;
char s[20][20];
void dfs(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c || !s[i][j])
		return;
	ans++;
	s[i][j] = 0;
	dfs(i - 1, j);
	dfs(i + 1, j);
	dfs(i, j - 1);
	dfs(i, j + 1);
}
int main() {
	ios::sync_with_stdio(0);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		cin >> s[i];
	}
	dfs(0, 0);
	cout << ans;
}