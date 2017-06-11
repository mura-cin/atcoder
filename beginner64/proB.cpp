#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[N-1] - a[0] << endl;

    return 0;
}
