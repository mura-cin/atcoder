#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
    int n, m; cin >> n >> m;
    n = (n+12)%12;
    double hour = n*30 + (double)m/2.0;
    double min = m*6;

    double ans = fabs(hour - min);
    if (ans > 180.0) ans = 360.0 - ans;
    // printf("hour: %.6f min: %.6f\n", hour, min);
    printf("%.10f\n", ans);

    return 0;
}
