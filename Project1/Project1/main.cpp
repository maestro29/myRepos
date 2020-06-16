#include <cstdio>

int k, n[13], a[6];
void print() {
	for (int i = 0; i < 6; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void f(int d, int i) {
	if (d > 5) {
		print();
		return;
	}
	for (int j = i; j < k; j++) {
		a[d] = n[j];
		f(d + 1, j + 1);
	}
}
int main() {
	for (; scanf("%d", &k) && k;) {
		for (int i = 0; i < k; i++)
			scanf("%d", &n[i]);
		f(0, 0);
		printf("\n");
	}
}