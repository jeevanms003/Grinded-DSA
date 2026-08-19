#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long maxVal = a[0];
    long long maxDiff = LLONG_MIN;
    long long minDiff = LLONG_MAX;
    long long ans = LLONG_MIN;

    for (int k = 1; k < n; k++) {

        if (k >= 2) {
            ans = max(ans, maxDiff * a[k]);
            ans = max(ans, minDiff * a[k]);
        }

        maxDiff = max(maxDiff, maxVal - a[k]);
        minDiff = min(minDiff, maxVal - a[k]);

        maxVal = max(maxVal, a[k]);
    }

    cout << ans << '\n';

    return 0;
}
