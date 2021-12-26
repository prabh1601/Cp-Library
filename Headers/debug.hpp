using namespace std;
typedef string str;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
str pinf = "4000000000000000000";
str ninf = "-4000000000000000000";

// single variable printers

bool add1 = false;

str convert(string t) {
    if (t == pinf) return "\u221E";
    else if (t == ninf) return "-\u221E";
    else return t;
}

inline string
to_String(long long _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf,
                   4 * sizeof(long long),
                   "%lld", _val + add1));
}

inline string
to_String(unsigned long long _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf,
                   4 * sizeof(unsigned long long),
                   "%llu", _val + add1));
}

inline string
to_String(int _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(int),
                   "%d", _val + add1));
}

inline string
to_String(unsigned _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf,
                   4 * sizeof(unsigned),
                   "%u", _val + add1));
}

inline string
to_String(float _val) {
    const int __n =
        __gnu_cxx::__numeric_traits<float>::__max_exponent10 + 20;
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n,
                   "%f", _val));
}

inline string
to_String(double _val) {
    const int __n =
        __gnu_cxx::__numeric_traits<double>::__max_exponent10 + 20;
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n,
                   "%f", _val));
}

inline string
to_String(long double _val) {
    const int __n =
        __gnu_cxx::__numeric_traits<long double>::__max_exponent10 + 20;
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n,
                   "%Lf", _val));
}

str to_String(bool b) { return b ? "true" : "false"; }

str to_String(char c) { return str(1, c); }

str to_String(str s) { return s; }

str to_String(const char *s) { return (str) s; }

// data structure printers

str to_String(vector<bool> v);

template<size_t SZ>
str to_String(bitset<SZ> b);

template<class T>
str to_String(T v);

template<class A, class B, class C>
str to_String(priority_queue<A, B, C> pq);

template<class A>
str to_String(stack<A> s);

template<class A>
str to_String(queue<A> q);

template<class A, class B>
str to_String(pair<A, B> p) {
    return "(" + to_String(p.first) + ", " + to_String(p.second) + ")";
}

template<class A>
str to_String(complex<A> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}

str to_String(vector<bool> v) {
    str res = "{";
    F0R(i, (int) v.size()) res += char('0' + v[i]);
    res += "}";
    return res;
}

template<size_t SZ>
str to_String(bitset<SZ> b) {
    str res;
    F0R(i, SZ) res += char('0' + b[i]);
    return res;
}

template<class T>
str to_String(T v) { // containers with begin(), end()
    bool fst = true;
    str res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = false;
        res += to_String(x);
    }
    res += "}";
    return res;
}

template<class A, class B, class C>
str to_String(priority_queue<A, B, C> pq) {
    bool fst = true;
    str res = "{";
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if (!fst) res += ", ";
        fst = false;
        res += to_String(x);
    }
    res += "}";
    return res;
}

template<class A>
str to_String(stack<A> s) {
    bool fst = true;
    str res = "{";
    while (!s.empty()) {
        auto x = s.top();
        s.pop();
        if (!fst) res += ", ";
        fst = false;
        res += to_String(x);
    }
    res += "}";
    return res;
}

template<class A>
str to_String(queue<A> q) {
    bool fst = true;
    str res = "{";
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        if (!fst) res += ", ";
        fst = false;
        res += to_String(x);
    }
    res += "}";
    return res;
}

// DEBUG
template<typename T>
void DBG(const char *names, T t) { cerr << " [" << names << " : " << to_String(t) << "]" << endl; }

template<typename H, typename... T>
void DBG(const char *names, H h, T ... t) {
    const char *others = strchr(names + 1, ',');
    cerr << " [";
    cerr.write(names, others - names) << " : " << to_String(h) << "] ";
    DBG(others + 2, t...);
}

str a(auto v) {
    add1 = true;
    str ans = to_String(v);
    add1 = false;
    return ans;
}

#define dbg(...) cerr << "(" << __LINE__ << ") -> "; DBG(#__VA_ARGS__, __VA_ARGS__);
#define dbga(...) add1 = true, cerr << "(" << __LINE__ << ") -> "; DBG(#__VA_ARGS__, __VA_ARGS__), add1 = false

// OUTPUT
template<class A>
void pr(A x) { cout << to_String(x); }

template<class H, class... T>
void pr(const H &h, const T &... t) {
    pr(h);
    pr(t...);
}

void ps() { pr("\n"); } // print w/ spaces

template<class H, class... T>
void ps(const H &h, const T &... t) {
    pr(h);
    if (sizeof...(t)) pr(" ");
    ps(t...);
}