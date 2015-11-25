/*
    1       |-- -- y
0       2   |
    3       x
*/

int n, endx, endy;
char table[105][105];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dd[] = {3, 0, 1, 2};
char dirc[] = {'N', 'E', 'S', 'W'};

char dircres[10005];

bool good(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int get(int x, int y, int d) {
    rep(i, 10000) {
        if (x == endx && y == endy) return i;
        
        rep(j, 4) {
            int x2 = x + dx[(j + d) % 4], y2 = y + dy[(j + d) % 4];
            int d2 = (d + dd[j]) % 4;
            
            if (good(x2, y2) && table[x2][y2] == '.') {
                dircres[i] = dirc[(j + d) % 4];
                
                d = d2;
                x = x2;
                y = y2;
                break;
            }
        }
    }
    
    return -1;
}

/*
        1   2
    0           3
        5   4
*/

char table[105][105];
int n;

int dx[] = {-1, -1, 0, 1, 1, 0};
int dy[] = {0, 1, 1, 0, -1, -1};
int dd[] = {4, 5, 0, 1, 2, 3};

bool good(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool get(int x, int y, int d) {
    char c = table[x][y];
    table[x][y] = '.';
    
    if (c == 'B' && y == n - 1) return true;
    if (c == 'R' && x == n - 1) return true;
    
    rep(i, 5) {
        int x2 = x + dx[(d + i) % 6], y2 = y + dy[(d + i) % 6];
        int d2 = (d + dd[i]) % 6;
        
        if (good(x2, y2) && table[x2][y2] == c && get(x2, y2, d2)) return true;
    }
    
    return false;
}
