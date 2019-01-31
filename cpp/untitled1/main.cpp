#include<bits/stdc++.h>

using namespace std;
using ll = long long;

tuple<ll, ll, ll> extended_euclidean(ll a, ll b) {
    if (b == 0)
        return make_tuple(a, 1, 0);
    ll g, x, y;
    tie(g, x, y) = extended_euclidean(b, a%b);
    return make_tuple(g, y, x-(a/b)*y);
}

ll ceil(ll a, ll b) {
    if (a >= 0)
        return (a + b - 1) / b;
    return a / b;
}

void solve(ll k, ll c) {
    ll g, x0, y0;
    tie(g, x0, y0) = extended_euclidean(k, c);

    if (g != 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    ll t = min(ceil(-x0, c), ceil(y0, k)) - 1;
    if (y0 - 1e9 > k*t) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << y0 - t * k << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll k, c;
        cin >> k >> c;
        solve(k, c);
    }

    return 0;
}