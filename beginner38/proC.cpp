#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(void) {
  int N; cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  ll cnt = 1;
  ll ans = 1;
  for (int i = 1; i < N; i++) {
    if (a[i] > a[i-1]) {
      cnt++;
      ans += cnt;
    } else {
      cnt = 1;
      ans += cnt;
    }
  }

  cout << ans << endl;

  return 0;
}
