#include <cstdio>
#define M 100

int a[M*3+1][M*3+1], z = 1, x = M, y = M, u = -1, v = 0;
void f(int n, int b) {
	if (x < 0 || y < 0 || x > M*2 || y > M*2 ) return;
	for (int i = 0; i < 2 * n - 1; i++) {
		a[x][y] = z++;
		if (i == 0) u = b, v = 0;
		if (i == n - 1) u = 0, v = b;
		x += u, y += v;
	}
	f(n + 1, -b);
}
int main() {
	f(1, 1);
	for (int i = M-5; i < M+5; i++) {
		for (int j = M-5; j < M+5; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}






//#include <cstdio>
//#define MAX(a,b) (a>b)?a:b
//int t, n, k, d[1001], e[1001], x, y, a[1001][1001], w;
//int f(int v) {
//	if (!e[v]) return d[v];
//	int max = -1;
//	for (int i = 1; i <= n; i++)
//		if (a[i][v]) max = MAX(max, f(i));
//	return d[v]+max;
//}
//int main() {
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d%d", &n, &k);
//		for (int i = 1; i <= n; i++)
//			scanf("%d", &d[i]);
//		while (k--) {
//			scanf("%d%d", &x, &y);
//			a[x][y] = 1;
//			e[y]++;
//		}
//		scanf("%d", &w);
//		printf("%d\n", f(w));
//	}
//}