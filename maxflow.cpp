int size, flow, cost;
int g[105][105], g2[105][105], f[105][105];
int c[105][105], c2[105][105];

void setgcf() {
    mem(g2, 0);
    rep(i, size) rep(j, size) g2[i][j] = g[i][j];
    
    mem(c2, 0);
    rep(i, size) rep(j, size) if (c[i][j] > 0) {
        c2[i][j] = c[i][j];
        c2[j][i] = -1 * c[i][j];
    }
    
    mem(f, 0);
    
    flow = 0;
}

void getmaxflow() {
    int num[size];
    int parent[size];
    mem(num, -1);
    mem(parent, -1);
    
    queue<int> q;
    q.push(0);
    num[0] = INT_MAX;
    
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        
        rep(to, size) if (num[to] == -1 && g2[from][to] > 0) {
            num[to] = min(num[from], g2[from][to]);
            parent[to] = from;
            
            q.push(to);
        }
    }
    
    if (num[size - 1] > 0) {
        flow += num[size - 1];
        
        int current = size - 1;
        int p = parent[current];
        while (p != -1) {
            g2[p][current] -= num[size - 1];
            g2[current][p] += num[size - 1];
            f[p][current] += num[size - 1];
            f[current][p] -= num[size - 1];
            
            current = p;
            p = parent[p];
        }
        
        getmaxflow();
    }
}

void getmincost() {
    int dist[size];
    rep(i, size) dist[i] = 1e9;
    
    int parent[size];
    mem(parent, -1);
    
    dist[0] = 0;
    rep(i, size) {
        rep(from, size) rep(to, size) if (g2[from][to] > 0) {
            if (dist[from] + c2[from][to] < dist[to]) {
                dist[to] = dist[from] + c2[from][to];
                parent[to] = from;
            }
        }
    }
    
    int start = -1;
    rep(i, size) {
        bool visited[size];
        mem(visited, false);
        
        visited[i] = true;
        int p = parent[i];
        
        while (p != -1 && !visited[p]) {
            visited[p] = true;
            p = parent[p];
        }
        
        if (p != -1) {
            start = p;
            break;
        }
    }
    
    if (start != -1) {
        int current = start;
        int p = parent[current];
        
        int num = g2[p][current];
        while (p != start) {
            current = p;
            p = parent[p];
            
            num = min(num, g2[p][current]);
        }
        
        current = start;
        p = parent[current];
        
        g2[p][current] -= num;
        g2[current][p] += num;
        f[p][current] += num;
        f[current][p] -= num;
        while (p != start) {
            current = p;
            p = parent[p];
            
            g2[p][current] -= num;
            g2[current][p] += num;
            f[p][current] += num;
            f[current][p] -= num;
        }
        
        getmincost();
    }
    else {
        cost = 0;
        rep(i, size) rep(j, size) cost += f[i][j] * c[i][j];
    }
}
