#include <cstdio>
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define MAP(i) map.v[i / m][i - (i / m) * m]

struct Map {
	int v[8][8];
};
int n, m, max = 0;
Map map;
int count_safe_zone(Map& map) {
	int c = 0;
	FOR(i, 0, n*m)
		if (!MAP(i))
			c++;
	return c;
}
void dfs(Map& map, int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m
		|| (map.v[i][j] != 2 && map.v[i][j]))
		return;
	map.v[i][j] = 3;
	dfs(map, i - 1, j);
	dfs(map, i + 1, j);
	dfs(map, i, j - 1);
	dfs(map, i, j + 1);
}
void spread_virus(Map map) {
	FOR(i, 0, n)
	FOR(j, 0, m)
		if (map.v[i][j] == 2)
			dfs(map, i, j);
	int cnt = count_safe_zone(map);
	if (cnt > max)
		max = cnt;
}
void make_wall(int wall, int i) {
	if (!wall) {
		spread_virus(map);
		return;
	}
	FOR(j, i, n*m) {
		if (MAP(j))
			continue;
		MAP(j) = 1;
		make_wall(wall - 1, j);
		MAP(j) = 0;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n*m)
		scanf("%d", &MAP(i));
	make_wall(3, 0);
	printf("%d", max);
}