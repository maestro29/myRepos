#include <cstdio>
#define FOR(a,b) for(int a = 0; a < b; a++)
int n, m;
struct Map {
	int v[8][8];
};
Map map;
void make_wall() {
	FOR(i, n * m) {
		FOR(j, n * m) {

			FOR(k, n * m) {
				map[j / m][j - (j / m) * m] = 1;
				map[k / m][k - (k / m) * m] = 1;
			}
		}
	}
}
void spread_virus(Map map, int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || !map[i][j])
		return;
	map[i][j] = 2;
	spread_virus(i - 1, j);
	spread_virus(i + 1, j);
	spread_virus(i, j - 1);
	spread_virus(i, j + 1);
}
int count_safe_zone(Map map) {
	int c = 0;
	FOR(i, n)
		FOR(j, m)
		if (!map[i][j])
			c++;
	return c;
}
int main() {
	scanf("%d%d", &n, &m);
	FOR(i, n)
		FOR(j, m)
		scanf("%d", &map.v[i][j]);
}





//void a() {
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3; j++)
//			for (int k = 0; k < 3; k++)
//				printf("%d %d %d\n", i, j, k);
//}
//void b(int i, int j, int k) {
//	if (k > 2) { k = 0, j++; }
//	if (j > 2) { j = 0, i++; }
//	if (i > 2) return;
//	printf("%d %d %d\n", i, j, k);
//	k++;
//	b(i, j, k);
//}
