#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 10;

vector<int> adjList[N];
int vis[N],  dir[N];
vector<pair<int, int>> input(N);
int n, m;
int W, U, V;

bool cycle(int nd) {
    vis[nd] = 1;

    bool ans = true;
    for (int i : adjList[nd]) {
        if (vis[i] == 1) {U = nd, V = i; return false;}
        else if (!vis[i]) ans &= cycle(i);
    }

    vis[nd] = 2;
    return ans;
}

int readAns(ifstream &fin) {
    string ans; fin >> ans;
    if (ans == "NO") return -1; // have no solution possible

    for (int i = 0; i < m; i++) {
        int u, v; fin >> u >> v;
        if (dir[i] and u != input[i].first) {W = i, U = u, V = v; return -2;} // wrong order of edges printed
        adjList[u].pb(v);
    }

    bool can = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) can &= cycle(i);
    }

    for (int i = 1; i <= n; i++) {
        adjList[i].clear();
        vis[i] = 0;
    }

    if (!can) return -3; // cycle found

    return 0;
}

int main() {
    ifstream fin("/mnt/3E86036E860325CD/CP/TestCases/input_file", ifstream::in);
    ifstream ans("/mnt/3E86036E860325CD/CP/TestCases/myAnswer", ifstream::in);
    ifstream cor("/mnt/3E86036E860325CD/CP/TestCases/correctAnswer", ifstream::in);
    // use fin instead of cin here

    int t_c; fin >> t_c;
    for (int tc = 0; tc < t_c; tc++) {
        fin >> n >> m;

        for (int i = 0; i < m; i++)
            fin >> input[i].first >> input[i].second >> dir[i];

        int my = readAns(ans);
        int correct = readAns(cor);

        if (correct == -2) {
            cout << "Test Case : " << tc << endl;
            cout << "Correct solution prints the edges b/w # " << W + 1 << ": " << U << " " << V << " in wrong order" << endl;
            return -1;
        } else if (correct == -3) {
            cout << "Test Case : " << tc << endl;
            cout << "Cycle found in correct solution b/w" << U << " " << V << endl;
            return -1;
        }

        if (my == -2) {
            cout << "Test Case : " << tc << endl;
            cout << "Your solution prints the edges b/w " << U << " " << V << " in wrong order" << endl;
            return -1;
        } else if (my == -3) {
            cout << "Test Case : " << tc << endl;
            cout << "Cycle found in your solution b/w" << U << " " << V << endl;
            return -1;
        }

        if (my == - 1 and correct != - 1) {
            cout << "Test Case : " << tc << endl;
            cout << "Correct solution has a solution but you dont" << endl;
            return -1;
        } else if (my != -1 and correct == -1) {
            cout << "Test Case : " << tc << endl;
            cout << "No solution possible but you print one" << endl;
            return - 1;
        }
    }

    cout << "OK Correct Solution found" << endl;
    return 0;
}