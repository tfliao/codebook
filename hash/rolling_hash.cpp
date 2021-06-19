class RollingHash {
public:
    long long R;
    long long M;
    int L;

    long long rem;
    long long val;
    queue<long long> prev;
public:
    /*
    Initialize Rolling Hash with
        * rotate length: l
        * hash range: r
        * hash multiplier: m
    */
    RollingHash(int l, long long r = -1, long long m = -1)
        : val(0LL), L(l) {
        R = (r != -1?r:23058430092369395LL);
        M = (m != -1?m:47);
        rem = 1;
        for (int i=0;i<L;++i) rem = (rem * M) % R;
    }
    /*
    add (push) value to hash
        return -1 if less than L value pushed, or hashed value
    */
    long long add(long long v) {
        val = (val * M + v) % R;
        prev.push(v);
        if (prev.size() > L) {
            val = ((val - prev.front() * rem) % R + R) % R;
            prev.pop();
        }
        return prev.size() == L ? val : -1;
    }
};
