vector<int> zFunction(vector<int> &s) {
    int n = (int)s.size();
    vector<int> z(n);
    
    for (int i = 1, l = 0, r = 0; i < n; i ++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] ++;
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}

int findNumberOfOccurences(vector<int> &v, vector<int> &pattern) {
    vector<int> str = pattern;
    str.insert(str.end(), v.begin(), v.end());
    vector<int> z = zFunction(str);
    
    int res = 0;
    for (int i = (int)pattern.size(); i < z.size(); i ++) if (z[i] >= pattern.size()) res ++;
    
    return res;
}

// compacts the array of arbitrary numbers into an array of [0 .. K - 1] numbers where K is the number of distinct numbers in the original array.
// the items in the resulting array are guaranteed to give the same comparison result as the items in the original array on the same positions
// Complexity - O(N logN)
vector<int> compactArray(vector<int>& v) {
    vector<int> inputNumbers = v;
    sort(inputNumbers.begin(), inputNumbers.end());
    inputNumbers.resize(unique(inputNumbers.begin(), inputNumbers.end()) - inputNumbers.begin());
    map<int, int> mapping;
    for (int i = 0 ; i < inputNumbers.size() ; i++)
        mapping[inputNumbers[i]] = i;
    vector<int> result(v.size());
    for (int i = 0 ; i < v.size() ; i++)
        result[i] = mapping[v[i]];
    return result;
}

// algorithm is mostly taken from e-maxx "as is", only arrays were changed to vectors
vector<int> calcSuffixArray(vector<int> s) {
    s = compactArray(s);
    // reduce the numbers in the input array since the complexity of the algorithm below depends on alphabet size
    
    int n = (int)s.size();
    int alphabet = n;
    
    vector<int> p(n);
    vector<int> cnt(n);
    vector<int> c(n);
    
    for (int i=0; i < n; ++i)
        ++cnt[s[i]];
    for (int i=1; i<alphabet; ++i)
        cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]])  ++classes;
        c[p[i]] = classes-1;
    }
    
    vector<int> pn(n);
    vector<int> cn(n);
    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        cnt.assign(classes, 0);
        for (int i=0; i<n; ++i)
            ++cnt[c[pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
                ++classes;
            cn[p[i]] = classes-1;
        }
        c = cn;
    }
    
    return p;
}

vector<int> v1;
/// compares the subarray of array v1 starting at index i1 with array v2
bool comp(int i1, vector<int> v2) {
    int len1 = (int)v1.size() - i1;
    int len2 = (int)v2.size();
    int len = min(len1, len2);
    for (int i = 0 ; i < len ; i++)
        if (v1[i1 + i] != v2[i]) {
            return v1[i1 + i] < v2[i];
        }
    if (len1 != len2) return len1 < len2;
    return false;
}

int findNumberOfOccurences(vector<int> v, vector<int> &pattern) {
    v.push_back(INT_MIN);
    
    vector<int> suffixArray = calcSuffixArray(v);
    
    v1 = v;
    
    vector<int>::iterator it1 = lower_bound(suffixArray.begin(), suffixArray.end(), pattern, comp);
    pattern.back()++;
    vector<int>::iterator it2 = lower_bound(suffixArray.begin(), suffixArray.end(), pattern, comp);
    
    return (int)(it2 - it1);
}
