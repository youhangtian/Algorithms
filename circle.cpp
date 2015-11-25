bool circle(int j, int i) {
    bool visited[size];
    mem(visited, false);
    visited[j] = true;
    visited[i] = true;
    
    queue<int> q;
    for (int k: g[j]) if (k != i) {
        q.push(k);
        visited[k] = true;
    }
    
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        
        for (int to: g[from]) {
            if (to == i) return true;
            
            if (!visited[to]) {
                visited[to] = true;
                q.push(to);
            }
        }
    }
    
    return false;
}
