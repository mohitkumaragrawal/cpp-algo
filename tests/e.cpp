#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MX = 750005;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];

    sort(all(a), greater<ll>());

    vector<ll> dp(MX);

    dp[a[0]] = 1;

    for (ll i = 1; i < n; ++i)
    {
        ll val = a[i];
        dp[val] = 1;

        for (ll j = 2 * val; j < MX; j += val)
        {
            dp[val] = (dp[val] + dp[j]) % MOD;
        }
    }

    ll ans = 0;

    for (auto x : dp)
    {
        ans = (ans + x) % MOD;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    ll T;
    cin >> T;
    while (T--)
        solve();
}
