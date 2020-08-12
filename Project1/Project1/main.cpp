#include <cstdio>
#include <queue>
#include <stack>
#define PUSH(z) if (!v[z]) q.push(z), v[z] = 1
int t, n, k, d[1001], x, y, a[1001][1001], w, v[1001];
std::queue<int> q;
std::stack<int> s;
void sol() {
	int cur;
	PUSH(w);
	while (q.size()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
			if (a[i][cur]) PUSH(i), s.push(i);
	}
	while (s.size()) {
		cur = s.top();
		s.pop();
		for (int i = 1; i <= n; i++)
			if (a[cur][i] && d[i] < d[cur])
				;
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &d[i]);
		while (k--) {
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		scanf("%d", &w);
		sol();
	}
}