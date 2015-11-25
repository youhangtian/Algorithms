int size;
vector<vector<int> > g, g2;
int gccid[100];
vector<vector<int> > gcc;

bool visited[100];
stack<int> s;
int id;

void dfs(int from) {
    visited[from] = true;
    for (int to: g[from]) if (!visited[to]) dfs(to);
    s.push(from);
}

void dfs2(int from) {
    gccid[from] = id;
    gcc[id].pb(from);
    for (int to: g2[from]) if (gccid[to] == -1) dfs2(to);
}

void getgcc() {
    g2.clear();
    g2.resize(size, vector<int>(0));
    rep(i, size) for (int j: g[i]) g2[j].pb(i);
    
    mem(visited, false);
    rep(i, size) if (!visited[i]) dfs(i);
    
    mem(gccid, -1);
    id = 0;
    gcc.clear();
    rep(i, size) if (gccid[i] == -1) {
        gcc.pb(vector<int>(0));
        dfs2(i);
        id ++;
    }
}
