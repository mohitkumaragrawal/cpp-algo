#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

vector<vector<ll>> tree;
ll n;
vector<ll> a;

ll count_large_el(const vector<ll>& v, ll k) {
    ll id = upper_bound(all(v), k) - v.begin();
    return v.size() - id;
}

void build_tree(ll id, ll tl, ll tr) {
    if (tl == tr) {
        tree[id].push_back(a[tl]);
        return;
    }

    ll mid = (tl + tr) / 2;
    build_tree(2 * id, tl, mid);
    build_tree(2 * id + 1, mid + 1, tr);

    // now merge both of them;
    ll i = 0, j = 0;
    auto& vec1 = tree[2 * id];
    auto& vec2 = tree[2 * id + 1];
    auto& vec = tree[id];

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            vec.push_back(vec1[i]) ;
            i++;
        } else {
            vec.push_back(vec2[j]);
            j++;
        }
    }

    while (i < vec1.size()) {
        vec.push_back(vec1[i]);
        i++;
    }

    while (j < vec2.size()) {
        vec.push_back(vec2[j]);
        j++;
    }
}

ll query(ll id, ll tl, ll tr, ll ql, ll qr, ll k) {
    if (tl > qr || ql > tr) return 0;
    if (ql <= tl && tr <= qr) return count_large_el(tree[id], k);

    ll mid = (tl + tr) / 2;
    return query(2 * id, tl, mid, ql, qr, k) + query(2 * id + 1, mid + 1, tr, ql, qr, k);
}

void solve() {
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    tree.resize(4 * n + 10);
    build_tree(1, 0, n-1);

    ll q;
    cin >> q;
    while (q--) {
        ll i, j, k;
        cin >> i >> j >> k;
        i--; j--;

        cout << query(1, 0, n-1, i, j, k) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);


    solve();
}
