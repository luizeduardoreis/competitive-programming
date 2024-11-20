/*
	iterative segment tree
	source: https://codeforces.com/blog/entry/18051
*/

struct segment_tree {
	struct node {
		// define node
		node() {
			// define default constructor
		}
		node operator +(node other) {
			// define merge
		}
	};
	vector<node> t;
	segment_tree(int n) : t(2 * n) {}
	void update(int p, node val) {
		for (t[p += n] = val; p > 1; p >>= 1)
			t[p >> 1] = t[p] + t[p ^ 1];
	}
	node query(int l, int r) {
		node resl();
		node resr();
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = resl + t[l++];
			if (r&1) resr = resr + t[--r];
		}
		return resl + resr;
	}
};
