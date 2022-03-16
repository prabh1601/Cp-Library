#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define nl cout<<"\n"

#define sz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define trav(a, x) for(auto &a : x)

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u,v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

using ll = long long;
using ld = long double;

namespace __input {
    template <class T1, class T2> void re(pair<T1, T2> &p);
    template <class T> void re(vector<T> &a);
    template <class T, size_t SZ> void re(array<T, SZ> &a);

    template <class T> void re(T &x) { cin >> x; }
    void re(double &x) { string t; re(t); x = stod(t); }
    template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first); re(rest...); }

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.first, p.second); }
    template <class T> void re(vector<T> &a) { for (auto &x : a) re(x); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (auto &x : a) re(x); }
}
using namespace __input;

namespace __output {
    template <typename T> struct is_outputtable { template <typename C> static constexpr decltype(declval<ostream &>() << declval<const C &>(), bool()) test(int) { return true; } template <typename C> static constexpr bool test(...) { return false; } static constexpr bool value = test<T>(int()); };
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_outputtable<T>::value, bool>::type> void pr(const T &x);

    template <class T, typename V = decltype(declval<ostream &>() << declval<const T &>())> void pr(const T &x) { cout << x; }
    template <class T1, class T2> void pr(const pair<T1, T2> &x);
    template <class Arg, class... Args> void pr(const Arg &first, const Args &...rest) { pr(first); pr(rest...); }

    template <class T, bool pretty = true> void prContain(const T &x) { if (pretty) pr("{"); bool fst = 1; for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0; if (pretty) pr("}"); }

    template <class T> void pc(const T &x) { prContain<T, false>(x); pr("\n"); }
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.first, ", ", x.second, "}"); }
    template <class T, typename V, typename S> void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg> void ps(const Arg &first) { pr(first); ps(); }
    template <class Arg, class... Args> void ps(const Arg &first, const Args &...rest) { pr(first, " "); ps(rest...); }
}
using namespace __output;

#define __pn(x) pr(#x, " = ")
#ifdef gupta_samarth
#define debug(...) pr("\033[1;31m"), __pn((__VA_ARGS__)), ps(__VA_ARGS__), pr("\033[0m"), cout << flush
#else
#define debug(...) 42
#endif

namespace __io {
    void setIO() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15);
        #ifdef gupta_samarth
            (void) !freopen("input.txt", "r", stdin);
            (void) !freopen("output.txt", "w", stdout);
        #endif
    }
}
using namespace __io;

template<typename T> void min_self( T &a, const T &b ){ a = min(a, b); }
template<typename T> void max_self( T &a, const T &b ){ a = max(a, b); }

const ll MOD = 1000000007;
// const ll MOD = 998244353;
template<class T1, class T2> void add( T1 &x, const T2 &y, ll m = MOD ){ x += y; if( x >= m ) x -= m; }
template<class T1, class T2> void sub( T1 &x, const T2 &y, ll m = MOD ){ x -= y; if( x < 0 ) x += m; }
ll mod( ll n, ll m=MOD ){ n %= m; if(n < 0) n += m; return n; }

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;

// }}}
// clang-format on

const int MAXN = 1e5 + 5;
const int LOGN = 21;
const ll INF = 1e16;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;

    vector<int> l(n), r(n), mark(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> mark[i];
    }

    queue<tuple<int, int, int>> q;
    q.push({a, b, 0});
    set<pair<int, int>> vis;
    int ans = -1;
    int d = 0;
    while (!q.empty()) {
        int x, y, step;
        tie(x, y, step) = q.front();
        q.pop();

        if (vis.find({x, y}) != vis.end()) continue;
        vis.insert({x, y});

        if (mark[x] != mark[y]) {
            ans = step;
            break;
        }

        q.push({l[x], l[y], step + 1});
        q.push({r[x], r[y], step + 1});
    }
    if (ans == -1)
        cout << "indistinguishable";
    else
        cout << ans;
    nl;
}

int main() {
    setIO();

    int t = 1;
    // cin >> t;
    for (int test = 1; test <= t; test++) {
        // cout<<"Case #"<<test<<": ";
        solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}