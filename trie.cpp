struct node {
    int count;
    vector<node*> v;
    
    node() {
        count = 1;
        v.clear();
        v.resize(26, NULL);
    }
    
    void add(int i) {
        if (v[i] == NULL) v[i] = new node();
        else (v[i]->count) ++;
    }
};

int main() {
    node* head = new node();
    
    int n;
    cin >> n;
    rep(i, n) {
        string s;
        cin >> s;
        
        node* current = head;
        rep(j, sz(s)) {
            current->add(s[j] - 'a');
            current = current->v[s[j] - 'a'];
        }
    }
    
    cin >> n;
    rep(i, n) {
        string s;
        cin >> s;
        
        node* current = head;
        bool b = true;
        rep(j, sz(s)) {
            if (current->v[s[j] - 'a'] == NULL) {
                b = false;
                break;
            }
            else current = current->v[s[j] - 'a'];
        }
        
        if (!b) cout << 0 << endl;
        else cout << current->count << endl;
    }
    return 0;
}
