string bstring (int num) {
    string s = "";
    while (num) {
        if (num & 1) s = '1' + s;
        else s = '0' + s;
        num >>= 1;
    }
    return s;
}

vector<int> submask(int mask) {
    vector<int> res;
    for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) res.pb(sub);
    return res;
}
