#include <cstdio>
#include <algorithm>
struct Pos {
	int x;
	int y;
}p1, p2;
int m, n, k, a[100][100] = { 0 }, ans[6000], cnt = 0, area;
void rec(Pos p1, Pos p2) {
	for (int i = p1.x; i < p2.x; i++)
		for (int j = p1.y; j < p2.y; j++)
			a[i][j] = 1;
}
void dfs(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n || a[x][y])
		return;
	a[x][y] = 1;
	area++;
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (k--) {
		scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
		rec(p1, p2);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!a[i][j]) {
				area = 0;
				dfs(i, j);
				ans[cnt++] = area;
			}
	std::sort(ans, ans + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", ans[i]);
}