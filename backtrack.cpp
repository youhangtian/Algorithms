int n;
vector<int> v;
bool visited[100];

void backtrack(int index) {
    if (index == n) {
        for (int i: v) cout << i << " ";
        cout << endl;
    }
    else {
        rep(i, n) if (!visited[i]) {
            v[index] = i;
            visited[i] = true;
            backtrack(index + 1);
            v[index] = -1;
            visited[i] = false;
        }
    }
}

int main() {
    n = 5;
    v.clear();
    v.resize(n, -1);
    
    mem(visited, false);
    backtrack(0);
    return 0;
}
