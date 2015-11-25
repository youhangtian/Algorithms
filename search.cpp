int binarysearch(const vector<int> &v, int x, int l, int r) {
    int left = l;
    int right = max(l, r + 1);
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (x <= v[mid]) right = mid;
        else left = mid + 1;
    }
    
    return right;
}

int bs2() {
    int left = 0, right = 1e9 + 1;
    
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        
        if (good(mid)) left = mid;
        else right = mid;
    }
    
    return left;
}

int ternarysearchmax(const vector<int> &v, int l, int r) {
    if (r - l <= 2) {
        int p = l;
        for (int i = l; i <= r; i ++) {
            if (v[i] > v[p]) p = i;
        }
        return p;
    }
    
    int left = l + (r - l) / 3;
    int right = r - (r - l) / 3;
    
    if (v[left] < v[right]) return ternarysearchmax(v, left, r);
    else return ternarysearchmax(v, l, right);
}
