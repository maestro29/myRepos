#include <cstdio>
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORFOR(i,j,n,m) FOR(i,0,n)FOR(j,0,m)
#define MAP(i) map.v[i / m][i - (i / m) * m]

struct Map {
	int v[8][8];
};
int n, m, cnt = 0;
Map map;
int count_safe_zone(Map& map) {
	int c = 0;
	FORFOR(i,j,n,m)
		if (!map.v[i][j])
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
	FORFOR(i, j, n, m)
		if (map.v[i][j] == 2)
			dfs(map, i, j);
	int max = count_safe_zone(map);
	if (max > cnt)
		cnt = max;
}
//void make_wall_iter() {
//	FOR(i, 0, n * m) {
//		if (MAP(i))
//			continue;
//		MAP(i) = 1;
//		FOR(j, i, n * m) {
//			if (MAP(j))
//				continue;
//			MAP(j) = 1;
//			FOR(k, j, n * m) {
//				if (MAP(k))
//					continue;
//				MAP(k) = 1;
//				spread_virus(map);
//				MAP(k) = 0;
//			}
//			MAP(j) = 0;
//		}
//		MAP(i) = 0;
//	}
//}
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
	FORFOR(i, j, n, m)
		scanf("%d", &map.v[i][j]);
	make_wall(3, 0);
	printf("%d", cnt);
}