/*
	disjoint set union
	source: usaco
*/

struct dsu {
	vi e;
	dsu(int n) : e(n, -1) {}
	int get(int a) { e[a] < 0 ? a : e[a] = get(e[a]); }
	bool merge(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return 0;
		if (e[a] > e[b])
			swap(a, b);
		e[a] += e[b];
		e[b] = a;
		return 1;
	}
	int sz(int a) { return -e[get(a)]; }
};
