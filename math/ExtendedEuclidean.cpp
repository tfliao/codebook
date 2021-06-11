#define R (1000000007LL)
#define MOD(x) ((x) % R)

typedef long long LL;

/*
 * extended_gcd(x, y):
 *     return pair(a,b) that satisfy ax + by = gcd(x,y)
 */
pair<LL, LL> exgcd(LL x, LL y) {
	if (x % y == 0) {
		return make_pair(0, 1);
	} else {
		auto r = exgcd(y, x%y);
		return make_pair(r.second, r.first - r.second * (x/y));
	}
}

/*
 * inverse(x):
 *     return equivalent of 1/x (mod R)
 */
LL inverse(LL x) {
	auto r = exgcd(x, R);
	return r.first;
}
