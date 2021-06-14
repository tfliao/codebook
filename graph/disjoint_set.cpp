class DisjointSet {
private:
    // - size, + parent
    vector<int> _sz;
public:
    DisjointSet(int N = 1) {
        _sz.assign(N, -1);
    }
    int find(int x) {
        if (_sz[x] < 0) return x;
        else return _sz[x] = this->find(_sz[x]);
    }
    int size(int x) {
        return -_sz[find(x)];
    }
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
};