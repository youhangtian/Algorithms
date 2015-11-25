//whether [0, 0] in the triangle
double getD(int x, int y) {
    if (x == 0) {
        if (y > 0) return 90;
        else return 270;
    }
    if (y == 0) {
        if (x > 0) return 0;
        else return 180;
    }
    
    double res = 0;
    if (x < 0 && y > 0) res += 180;
    else if (x < 0 && y < 0) res += 180;
    else if (x > 0 && y < 0) res += 360;
    
    res += atan(double(y) / x) / acos(-1) * 180;
    return res;
}

bool inTriangle(vector<int> x, vector<int> y) {
    double d1 = getD(x[0], y[0]);
    double d2 = getD(x[1], y[1]);
    double d3 = getD(x[2], y[2]);
    
    vector<double> v;
    v.pb(d1);
    v.pb(d2);
    v.pb(d3);
    sort(v.begin(), v.end());
    
    if (v[2] - v[0] < 180) return false;
    else if (v[1] < v[2] - 180 || v[1] > v[0] + 180) return false;
    else return true;
}
