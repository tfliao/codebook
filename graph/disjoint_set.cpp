class DisjointSet {
private:
    // - size, + parent
    vector<int> _sz;
public:
    DisjointSet(int N = 1) {
        _sz.assign(N, -1);
    }
    /*
        find root node of subtree contains x
    */
    int find(int x) {
        if (_sz[x] < 0) return x;
        else return _sz[x] = this->find(_sz[x]);
    }
    /*
        get size of subtree contains x
    */
    int size(int x) {
        return -_sz[find(x)];
    }
    /*
        merge two subtrees, use the one with more children as root
    */
    bool merge(int x, int y) {
        int rx = this->find(x), ry = this->find(y);
        if (rx != ry) {
            if (_sz[rx] > _sz[ry])
                swap(rx, ry);
            _sz[rx] += _sz[ry];
            _sz[ry] = rx;
            return true;
        }
        return false;
    }
    /*
        merge subtree c to subtree p, ingore size comparasion
    */
    bool merge_to(int c, int p) {
        int rc = this->find(c), rp = this->find(p);
        if (rx != ry) {
            _sz[rp] += _sz[rc];
            _sz[rc] = rp;
            return true;
        }
        return false;
    }
};