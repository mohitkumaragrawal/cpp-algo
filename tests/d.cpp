#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve()
{
  ll n, m, d, D;
  cin >> n >> m >> d >> D;

  vector<pll> edges;

  ll edge_count = 0;
  set<pll> st;

  vector<vector<ll>> mat(n + 1, vector<ll>(n + 1));
  vector<ll> deg(n + 1);

  for (ll i = 1; i <= n;)
  {
    if (i + d - 1 <= n)
    {
      for (ll j = 0; j < d; ++j)
      {
        if (d != D)
          st.insert({d, i + j});

        deg[i + j] = d;

        for (ll k = 0; k < d; ++k)
        {
          edges.emplace_back(i + j, i + k);
          mat[i + j][i + k] = 1;
        }
      }

      edge_count += d * d;

      i += d;
    }
    else
    {
      for (ll k = i; k <= n; ++k)
      {
        edges.emplace_back(k, k);
        deg[k] += 1;

        mat[k][k] = 1;
        edge_count++;

        ll tmp = d - 1;
        while (tmp--)
        {
          if (st.empty())
          {
            cout << -1 << endl;
            return;
          }

          auto [cnt, v] = *st.begin();
          st.erase(st.begin());

          edges.emplace_back(v, k);
          edges.emplace_back(k, v);

          deg[v] += 1;
          deg[k] += 1;

          mat[v][k] = 1;
          mat[k][v] = 1;

          edge_count += 2;

          if (cnt + 1 < D)
            st.insert({cnt + 1, v});
        }

        if (D != d)
          st.insert({d, k});
      }

      break;
    }
  }

  ll rem = m - edge_count;
  if (rem < 0)
  {
    cout << -1 << endl;
    return;
  }

  for (ll i = 1; i <= n; ++i)
  {
    for (ll j = 1; j <= n; ++j)
    {
      if (mat[i][j] == 0 && rem > 1 && deg[i] < D && deg[j] < D)
      {
        mat[i][j] = 1;
        mat[j][i] = 1;

        deg[i]++;
        deg[j]++;

        edges.emplace_back(i, j);
        edges.emplace_back(j, i);

        edge_count += 2;
        rem -= 2;
      }
    }
  }

  if (rem == 1)
  {
    ll first = 1;
    while (first <= n && deg[first] == D)
      ++first;

    ll second = first + 1;
    while (second <= n && deg[second] == D)
      ++second;

    if (second > n)
    {
      cout << -1 << endl;
      return;
    }

    edges.emplace_back(first, second);
  }

  for (auto [u, v] : edges)
    cout << u << " " << v << endl;
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--)
    solve();
}
