vector<set<int> > t;
int size;

int table[2001][2001];

long long dis[2001];

void dfs(int from) {
    for (int to: t[from]) if (dis[to] == -1) {
        dis[to] = dis[from] + table[from][to];
        dfs(to);
    }
}

long long getres(int from) {
    mem(dis, -1);
    dis[from] = 0;
    dfs(from);
    
    long long maxd = -1;
    int p = -1;
    
    rep(i, size) if (dis[i] > maxd) {
        maxd = dis[i];
        p = i;
    }
    
    mem(dis, -1);
    dis[p] = 0;
    dfs(p);
    
    long long res = -1;
    rep(i, size) res = max(res, dis[i]);
    
    return res;
}
