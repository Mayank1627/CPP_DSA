#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long q = k / (n - 1);
        long long r = k % (n - 1);

        long long ans;
        if (r == 0)
            ans = q * n - 1;
        else
            ans = q * n + r;

        cout << ans << "\n";
    }

    return 0;
}