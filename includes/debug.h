using namespace std;
int64_t _inf = 4e18;
string _pinf = to_string(_inf);
string _ninf = to_string(-_inf);

bool add1 = false;

string convert(string t) {
    if (t == _pinf)
        return "\u221E";
    else if (t == _ninf)
        return "-\u221E";
    else
        return t;
}

// single variable printers

inline string to_String(int64_t _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(int64_t), "%lld", _val + add1));
}

inline string to_String(uint64_t _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(uint64_t), "%llu", _val + add1));
}

inline string to_String(int _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(int), "%d", _val + add1));
}

inline string to_String(unsigned _val) {
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(unsigned), "%u", _val + add1));
}

inline string to_String(float _val) {
    const int __n = __gnu_cxx::__numeric_traits<float>::__max_exponent10 + 20;
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n, "%f", _val));
}

inline string to_String(double _val) {
    const int __n = __gnu_cxx::__numeric_traits<double>::__max_exponent10 + 20;
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n, "%f", _val));
}

inline string to_String(long double _val) {
    const int __n = __gnu_cxx::__numeric_traits<long double>::__max_exponent10 + 20;
    return convert(__gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n, "%Lf", _val));
}

string to_String(bool b) { return b ? "true" : "false"; }

string to_String(char c) { return string(1, c); }

string to_String(string s) { return s; }

string to_String(const char *s) { return (string)s; }

// data structure printers

string to_String(vector<bool> v);

template <size_t SZ> string to_String(bitset<SZ> b);

template <class T> string to_String(T v);

template <class A, class B, class C> string to_String(priority_queue<A, B, C> pq);

template <class A> string to_String(stack<A> s);

template <class A> string to_String(queue<A> q);

template <class A, class B> string to_String(pair<A, B> p) {
    return "(" + to_String(p.first) + ", " + to_String(p.second) + ")";
}

template <class A> string to_String(complex<A> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}

string to_String(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < (int)v.size(); i++) res += char('0' + v[i]);
    res += "}";
    return res;
}

template <size_t SZ> string to_String(bitset<SZ> b) {
    string res;
    for (int i = 0; i < SZ; i++) res += char('0' + b[i]);
    return res;
}

template <class T> string to_String(T v) {  // containers with begin(), end()
    bool fst = true;
    string res = "{";
    for (const auto &x : v) {
        if (!fst) res += ", ";
        fst = false;
        res += to_String(x);
    }
    res += "}";
    return res;
}

template <class A, class B, class C> string to_String(priority_queue<A, B, C> pq) {
    bool fst = true;
    string res = "{";
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

template <class A> string to_String(stack<A> s) {
    bool fst = true;
    string res = "{";
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

template <class A> string to_String(queue<A> q) {
    bool fst = true;
    string res = "{";
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
template <typename T> void DBG(const char *names, T t) {
    cerr << " [" << names << " : " << to_String(t) << "]" << endl;
}

template <typename H, typename... T> void DBG(const char *names, H h, T... t) {
    const char *others = strchr(names + 1, ',');
    cerr << " [";
    cerr.write(names, others - names) << " : " << to_String(h) << "] ";
    DBG(others + 2, t...);
}

string ci(auto v) {
    add1 = true;
    string ans = to_String(v);
    add1 = false;
    return ans;
}

#define dbg(...)                        \
    cerr << "(" << __LINE__ << ") -> "; \
    DBG(#__VA_ARGS__, __VA_ARGS__);
#define dbga(...)                                    \
    add1 = true, cerr << "(" << __LINE__ << ") -> "; \
    DBG(#__VA_ARGS__, __VA_ARGS__), add1 = false

// OUTPUT
template <class A> void pr(A x) { cout << to_String(x); }

template <class H, class... T> void pr(const H &h, const T &...t) {
    pr(h);
    pr(t...);
}

void ps() { pr("\n"); }  // print w/ spaces

template <class H, class... T> void ps(const H &h, const T &...t) {
    pr(h);
    if (sizeof...(t)) pr(" ");
    ps(t...);
}