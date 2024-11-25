/*
	O(1) LCA query with O(NlogN) preprocessing using sparse table
*/

struct LCA {
	int n, root;
	vi h, e, f, v;
	vector<vi> sparse;
		LCA(vector<vector<pair<int, int>>> & adj, int root = 0) : n(size(adj)), root(root), h(n),
		f(n), v(n) {
		e.reserve(2*n);
		dfs(adj, root, root);
		build_sparse();
	}
	void dfs(vector<vector<pair<int, int>>> &adj, int cur = 0, int par = 0,
		int d = 0) {
		h[cur] = d;
		e.push_back(cur);
		f[cur] = size(e) - 1;
		for (auto & [u, id] : adj[cur]) if (u != par) {
			dfs(adj, u, cur, d + 1);
			e.push_back(cur);
		}
	}
	int merge(int a, int b) {
		return h[a] < h[b] ? a : b;
	}
	void build_sparse() {
		int l = __lg(size(e));
		sparse.resize(size(e), vi(l+1));
		for (int i = 0; i < size(e); i++) {
			sparse[i][0] = e[i];
		}
		for (int j = 1; j <= l; j++) {
			for (int i = 0; i < size(e); i++) {
				if (i + (1ll << j) - 1 >= size(e))
					continue;
				sparse[i][j] = merge(sparse[i][j-1],
					sparse[i + (1ll << (j-1))][j-1]);
			}
		}
	}
	int query(int a, int b) {
		int left = min(f[a], f[b]);
		int right = max(f[a], f[b]);
		int l = __lg(right - left + 1);
		return merge(sparse[left][l], sparse[right - (1ll << l)+ 1][l]);
	}
	int lca(int a, int b) {
		return query(a, b);
	}
};
