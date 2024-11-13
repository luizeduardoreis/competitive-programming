/*
    suffix automaton 
    status: not tested
*/

struct suffix_automaton {
    int n, id = 2, last = 1;
    vi len, link;
    vector<map<char, int>> to; // if n is up to 1e6 use vector<array<int, 26>>

    suffix_automaton(string const & s) : n(2 * s.size() + 2), len(n), link(n), to(n) {
        for (auto & c : s)
            push(c);
    }

    void push(const char& c) {
        int cur = id++;
        len[cur] = len[last] + 1;
        int p = last;
        while (p && !to[p][c]) {
            to[p][c] = cur;
            p = link[p];
        }
        if (!p)
            link[cur] = 1;
        else {
            int q = to[p][c];
            if (len[q] == len[p] + 1) {
                link[cur] = q;
            } else {
                int clone = id++;
                to[clone] = to[q];
                len[clone] = len[p] + 1;
                link[clone] = link[q];
                while (p && to[p][c] == q) {
                    to[p][c] = clone;
                    p = link[p];
                }
                link[cur] = link[q] = clone;
            }
        }
        last = cur;
    }
};
