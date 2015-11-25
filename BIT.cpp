struct BIT {
    vector<int> tree;
    int maxvalue;
    
    BIT(int value) {
        tree.resize(value + 1, 0);
        maxvalue = value;
    }
    
    void add(int index) {
        while (index <= maxvalue) {
            tree[index] ++;
            index += (index & -index);
        }
    }
    
    void remove(int index) {
        while (index <= maxvalue) {
            if (tree[index] > 0) tree[index] --;
            index += (index & -index);
        }
    }
    
    int sum(int num) {
        int sum = 0;
        num --;
        while (num > 0) {
            sum += tree[num];
            num -= (num & -num);
        }
        return sum;
    }
    
    int getfre(int num) {
        return sum(num + 1) - sum(num);
    }
    
    int findrank(int rank) {
        int bitmask = (1 << 18);
        
        int index = 0;
        while (bitmask > 0 && index < maxvalue) {
            int index2 = index + bitmask;
            if (index2 > maxvalue) {
                bitmask >>= 1;
                continue;
            }
            
            if (rank > tree[index2]) {
                index = index2;
                rank -= tree[index2];
            }
            bitmask >>= 1;
        }
        
        return index + 1;
    }
};
