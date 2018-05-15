#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parents, rank;

    UnionFind(int n) : parents(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            rank[i] = 0;
        }        
    }

    int root(int x) {
        if (parents[x] == x) { // root
            return x;
        } else {
            return parents[x] = root(parents[x]);
        }
    }

    bool isSame(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parents[x] = y;
        } else {
            parents[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
};

int main() {

    int N, M; cin >> N >> M;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i]; p[i]--;
    }

    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        uf.unite(x-1, y-1);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == p[i] || uf.isSame(i, p[i])) ans++;
    }

    cout << ans << endl;

    return 0;
}