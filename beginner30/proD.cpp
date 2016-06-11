#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_V = 1e5+1;
int b[MAX_V];

int main(void) {
    int N, a; cin >> N >> a;
    string k; cin >> k;
    for (int i = 1; i <= N; i++) cin >> b[i];

    vector<int> hist;
    hist.push_back(a);
    int n = b[a];
    vector<int>::iterator iter;
    while ((iter = find(hist.begin(), hist.end(), n)) == hist.end()) {
        if (hist.size() > MAX_V) break;
        hist.push_back(n);
        n = b[n];
    }
    size_t s_index = distance(hist.begin(), iter);
    size_t len = distance(iter, hist.end());

    int k_mod_C = 0;
    for (int i = 0; i < k.size(); i++) {
        k_mod_C = (k_mod_C*10 + k[i]-'0') % len;
    }

    if (k.size() <= 5 && stoi(k) <= int(1e5)) {
        n = a;
        int cnt = stoi(k);
        while (cnt--) n = b[n];
    } else {
        while (k_mod_C < s_index) k_mod_C += len;
        n = a;
        while (k_mod_C--) n = b[n];
    }

    cout << n << endl;

    return 0;
}
