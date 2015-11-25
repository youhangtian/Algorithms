struct node {
    int a, b, c;
    
    node(int a, int b, int c): a(a), b(b), c(c) {
        
    }
    
    bool operator> (node n) const {
        if (a > n.a) return true;
        else if (a < n.a) return false;
        else if (b > n.b) return true;
        else if (b < n.b) return false;
        else if (c > n.c) return true;
        else return false;
    }
    
    bool operator< (node n) const {
        if (a < n.a) return true;
        else if (a > n.a) return false;
        else if (b < n.b) return true;
        else if (b > n.b) return false;
        else if (c < n.c) return true;
        else return false;
    }
    
    bool operator== (node n) const {
        return (a == n.a && b == n.b && c == n.c);
    }
    
    bool operator>= (node n) const {
        return ((*this > n) || (*this == n));
    }
    
    bool operator<= (node n) const {
        return ((*this < n) || (*this == n));
    }
};

ostream& operator<< (ostream &out, node n) {
    cout << n.a << " " << n.b << " " << n.c << " ";
    return out;
}
