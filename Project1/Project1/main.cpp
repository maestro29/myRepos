#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int t, n;
string x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string>
			v;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
	}
	
}