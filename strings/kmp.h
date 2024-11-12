/*
    knuth-morris-pratt algorithm for prefix function
    status: not tested
*/

struct kmp {
    int n; vi pi;
    vector<vi> aut;
    kmp(string const & s) : n(s.size()), pi(n), aut(n, vi(26)) {
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j && s[i] != s[j])
                j = pi[j-1];
            pi[i] = j + (s[i] == s[j]);
        }
    }
    void init_automaton() {
        for (int i = 0; i < n; i++) {
            for (int c = 0; i < 26; i++) {
                int j = i;
                while (j && c + 'a' != s[j])
                    j = pi[j-1];
                aut[i][c] = j + (s[j] == 'a' + c);
            }
        }
    }
};
