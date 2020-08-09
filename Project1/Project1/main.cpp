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
		vector<string> v;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		bool no = 0;
		for (int i = 1; i < v.size(); i++)
			if (v[i - 1] == v[i].substr(0, v[i - 1].length())) {
				no = 1;
				break;
			}
		cout << ((no)? "NO" : "YES") << "\n";
	}
}