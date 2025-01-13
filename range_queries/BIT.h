/*
	Binary indexed tree
*/

struct bit {
	int n; vector<int> t;
	bit(int n) : n(n), t(n) {}
	void update(int p, int x) {
		for (; p < n; p|=(p+1))
			t[p] += x;
	}
	int query(int p) {
		int res = 0;
		for (; p >= 0; p = (p&(p+1))-1)
			res += t[p];
	}
	int query(int l, int r) { return query(r) - query(l-1); }
};
