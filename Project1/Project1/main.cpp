#include <set>
using namespace std;
set<int> s[9];
int nn;
int solution(int N, int number) {
    nn = N;
    for (int i = 1; i <= 8; i++) {
        s[i].insert(nn);
        nn = nn * 10 + N;
        for (int j = 1; j <= i / 2; j++) {
            for (auto x : s[j])
                for (auto y : s[i-j]) {
                    s[i].insert(x + y);
                    s[i].insert(x - y);
                    s[i].insert(y - x);
                    s[i].insert(x * y);
                    s[i].insert(x / y);
                    s[i].insert(y / x);
                    if (s[i].find(number) != s[i].end())
                        return i;
                }
            s[i].erase(0);
        }
    }
    return -1;
}
int main() {
    printf("%d", solution(2, 11));
}