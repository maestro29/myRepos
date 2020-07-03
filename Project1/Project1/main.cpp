#include <cstdio>
#include <queue>
#include <tuple>
#define PUSH(x,y) if (a[x][y]=='0') q.push({x,y,w,v+1}), a[x][y] = '2';\
				  else if (a[x][y] == '1' && !w) q.push({x,y,w+1,v+1}), a[x][y] = '2';
using namespace std;
int n, m, x, y, w, v;
queue<tuple<int, int, int, int>> q;
char a[1000][1001];
int bfs() {
	PUSH(0, 0);
	while (q.size()) {
		tie(x,y,w,v) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1)
			return v;
		if (x) PUSH(x - 1, y);
		if (y) PUSH(x, y - 1);
		if (x < n - 1) PUSH(x + 1, y);
		if (y < m - 1) PUSH(x, y + 1);
	}
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);
	printf("%d", bfs());
}