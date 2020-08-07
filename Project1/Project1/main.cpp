#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct N {
    int v;
    N* n;
    N() { v = 0, n = NULL; }
} roota[10001], rootz[10001];
void push(string s, N* root) {
    N* cur = &root[s.length()];
    cur->v++;
    for (int i = 0; s[i]; i++) {
        if (!cur->n) cur->n = new N[26];
        cur = &(cur->n[s[i] - 'a']);
        cur->v++;
    }
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (string s : words) {
        push(s, roota);
        reverse(s.begin(), s.end());
        push(s, rootz);
    }
    for (string s : queries) {
        N* cur;
        if (s[0] == '?') {
            cur = &rootz[s.length()];
            reverse(s.begin(), s.end());
        }
        else cur = &roota[s.length()];
        for (char c : s) {
            if (c == '?' || !cur->n) {
                answer.push_back(cur->v);
                break;
            }
            cur = &(cur->n[c - 'a']);
        }
    }
    return answer;
}
int main() {
    vector<int> a = solution({ "frodo","front","frost","frozen","frame","kakao" }, { "fro??","????o","fr???","fro???","pro?","fp","?????" });
    for (auto i : a) cout << i << " ";
}