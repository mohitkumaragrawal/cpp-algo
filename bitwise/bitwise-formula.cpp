#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll m;

struct Value {
  Value() { que = true; }
  Value(const string& v) : val(v) {
    isconst = true;
    que = false;
  }
  Value(Value* v1, Value* v2, const string& op) : x1(v1), x2(v2), op(op) {
    isconst = false;
    que = false;
  }

  bool is_set(ll pos, bool q) {
    if (que) return q;
    if (isconst) {
      char ch = val[val.size() - 1 - pos];
      return (ch == '1');
    }

    // caching
    if (q) {
      if (chset.find(pos) != chset.end()) return chset[pos];
    } else {
      if (chunset.find(pos) != chunset.end()) return chunset[pos];
    }

    bool v1 = x1->is_set(pos, q);
    bool v2 = x2->is_set(pos, q);

    bool result;
    if (op == "XOR") {
      result = v1 ^ v2;
    } else if (op == "OR") {
      result = v1 | v2;
    } else {
      result = v1 & v2;
    }
    if (q) {
      chset[pos] = result;
    } else {
      chunset[pos] = result;
    }
    return result;
  }

  bool isconst;
  bool que = false;
  string val;

  Value *x1, *x2;
  string op;

  // caching;
  unordered_map<ll, bool> chset, chunset;
};

unordered_map<string, Value*> mp;

void solve() {
  ll n;
  cin >> n >> m;
  cin.ignore();

  string s, t;
  vector<string> v;

  auto get_val = [&](const string& str) -> Value* {
    if (str[0] == '?') return new Value();
    if (isdigit(str[0])) return new Value(str);
    return mp[str];
  };

  for (ll i = 0; i < n; ++i) {
    v.clear();
    getline(cin, s);
    istringstream is(s);
    while (is >> t) {
      v.push_back(t);
    }
    if (v.size() == 3) {  // const
      mp[v[0]] = new Value(move(v[2]));
    } else if (v.size() == 5) {
      mp[v[0]] = new Value(get_val(v[2]), get_val(v[4]), move(v[3]));
    }
  }

  string vmin, vmax;

  for (ll i = 0; i < m; ++i) {
    ll cset = 0, cunset = 0;

    for (auto pr : mp) {
      if (pr.second->is_set(i, true)) cset++;
      if (pr.second->is_set(i, false)) cunset++;
    }

    if (cset > cunset) {
      vmax.push_back('1');
      vmin.push_back('0');
    } else if (cset < cunset) {
      vmax.push_back('0');
      vmin.push_back('1');
    } else {
      vmin.push_back('0');
      vmax.push_back('0');
    }
  }

  reverse(all(vmin));
  reverse(all(vmax));

  cout << vmin << endl;
  cout << vmax << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  solve();
}
