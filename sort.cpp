//merge sort
void msort(vector<int> &v, int left, int right) {
    if (left >= right) return;
    
    int mid = (left + right) / 2;
    msort(v, left, mid);
    msort(v, mid + 1, right);
    
    int n1 = mid - left + 1, n2 = right - mid;
    int a1[n1 + 1], a2[n2 + 1];
    
    for (int i = left; i <= mid; i ++) a1[i - left] = v[i];
    for (int i = mid + 1; i <= right; i ++) a2[i - mid - 1] = v[i];
    a1[n1] = INT_MAX;
    a2[n2] = INT_MAX;
    
    int l = 0, r = 0;
    for (int i = left; i <= right; i ++) {
        if (a1[l] <= a2[r]) v[i] = a1[l ++];
        else v[i] = a2[r ++];
    }
}

//heap sort
void heapify(vector<int> &v, int i, int size) {
    int left = 2 * i + 1;
    int right = 2 * i  + 2;
    
    int largest = i;
    if (left < size && v[left] > v[largest]) largest = left;
    if (right < size && v[right] > v[largest]) largest = right;
    
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, largest, size);
    }
}

void hsort(vector<int> &v) {
    int size = sz(v);
    for (int i = size - 1; i >= 0; i --) heapify(v, i, size);
    for (int i = size - 1; i > 0; i --) {
        swap(v[0], v[i]);
        size --;
        heapify(v, 0, size);
    }
}

//quick sort
int par(vector<int> &v, int left, int right) {
    int x = v[right];
    int i = left;
    for (int j = i; j < right; j ++) {
        if (v[j] <= x) swap(v[i ++], v[j]);
    }
    
    swap(v[i], v[right]);
    return i;
}

void qsort(vector<int> &v, int left, int right) {
    if (left >= right) return;
    
    int q = par(v, left, right);
    qsort(v, left, q - 1);
    qsort(v, q + 1, right);
}

//counting sort
void csort(vector<int> &v) {
    int maxvalue = 0;
    for (int i: v) maxvalue = max(i, maxvalue);
    
    int count[maxvalue + 1];
    mem(count, 0);
    for (int i: v) count[i] ++;
    for (int i = 1; i <= maxvalue; i ++) count[i] += count[i - 1];
    
    int arr[sz(v)];
    for (int i = sz(v) - 1; i >= 0; i --) arr[-- count[v[i]]] = v[i];
    
    rep(i, sz(v)) v[i] = arr[i];
}
