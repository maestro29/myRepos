#include <iostream>
using namespace std;
int r, c, ans, v[26];
char s[21][21];
void dfs(int cnt, int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c || v[s[i][j] - 'A'])
		return;
	v[s[i][j] - 'A'] = 1;
	if (++cnt > ans)
		ans = cnt;
	dfs(cnt, i - 1, j);
	dfs(cnt, i + 1, j);
	dfs(cnt, i, j - 1);
	dfs(cnt, i, j + 1);
	//v[s[i][j]] = 0;
}
int main() {
	ios::sync_with_stdio(0);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		cin >> s[i];
	dfs(0, 0, 0);
	cout << ans;
}