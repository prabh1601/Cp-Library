// Come on mate, keep going, we ain't that weak
#include "bits/stdc++.h"
using namespace std;

#ifdef PRABH
#include "debug.h"
#else
#define dbg(...)
#pragma GCC optimize("Ofast,unroll-loops")  // careful, this might break floating point arithmatic
#pragma GCC target("avx,avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

template <class Fun> class y_combinator_result {
    Fun fun_;

   public:
    template <class T> explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args> decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun> decltype(auto) y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void yes(bool caps = true) { cout << (caps ? "YES" : "Yes") << '\n'; }
void no(bool caps = true) { cout << (caps ? "NO" : "No") << '\n'; }

template <typename T> bool ckmin(T& a, T b) { return b < a && (a = b, true); }
template <typename T> bool ckmax(T& a, T b) { return b > a && (a = b, true); }

#define int int64_t
#define pb push_back
#define all(v) begin(v), end(v)
using ld = long double;
const int inf = 4e18;
const int N = 2e5 + 10;  // verify before using

void testCase() {
	cout << "LMAO\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t_c = 1;
    cin >> t_c;
    for (int testNo = 1; testNo <= t_c; testNo++) {
        cout << "Case #" << testNo << ": ";
        testCase();
    }
}
