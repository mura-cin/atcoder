#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, p;
    vector<int> degree;         // ノードの個数

    DisjointSet() {};
    DisjointSet(int s) {
        rank.resize(s);
        p.resize(s);
        degree.resize(s);
        for (int i = 0; i < s; i++) makeSet(i);
    }

    void makeSet(int x) {
        p[x] = x;
        rank[x] = 0;
        degree[x] = 1;
    }

    bool same(int x, int y) {
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y) {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y) {
        if (x == y) return;     // 親が同じ場合は更新しない

        if (rank[x] > rank[y]) {
            p[y] = x;
            degree[x] += degree[y];
        } else {
            p[x] = y;
            degree[y] += degree[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int findSet(int x) {
        while (x != p[x]) {
            x = p[x];
        }
        return x;
    }

    int countSet(int x) {
        return degree[findSet(x)];
    }
};

struct query {
    int type;                   // 0->edge, 1->query
    int from, to, year, idx;
    query(int from, int to, int year) {
        this->type = 0;
        this->from = from;
        this->to = to;
        this->year = year;
    }
    query(int from, int to, int year, int idx) {
        this->type = 1;
        this->to = to;
        this->from = from;
        this->year = year;
        this->idx = idx;
    }
    bool operator< (const query& right) const {
        if (this->year == right.year) {
            return this->type > right.type; // クエリの方を優先
        }
        return this->year > right.year; // 年の新しい順
    }
};

int main(void) {

    vector<query> q;
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int s, t, y; scanf("%d %d %d", &s, &t, &y);
        q.emplace_back(s-1, t-1, y);
    }

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int v, w; scanf("%d %d", &v, &w);
        q.emplace_back(v-1, -1, w, i);
    }

    sort(q.begin(), q.end());

    vector<int> ans(Q);
    DisjointSet ds = DisjointSet(N);
    for (auto i = 0; i < q.size(); i++) {
        if (q[i].type == 0) {
            ds.unite(q[i].from, q[i].to);
        } else {
            ans[q[i].idx] = ds.countSet(q[i].from);
        }
    }

    for (auto i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    // for (auto i = 0; i < q.size(); i++) {
    //     if (q[i].type == 0) {
    //         printf("year: %d, type: edge, from: %d, to: %d\n",
    //                q[i].year, q[i].from, q[i].to);
    //     } else {
    //         printf("year: %d, type: query, from: %d\n",
    //                q[i].year, q[i].from);
    //     }
    // }

    return 0;
}
