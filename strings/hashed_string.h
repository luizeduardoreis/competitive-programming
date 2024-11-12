/*
    hashed string
    source: quirino.net
    status: tested
*/

struct HashedString {
    ll n, b, MOD = (1ll << 61) - 1;
    vll pow{1}, p;

    __int128 mul(ll a, ll b) { return (__int128) a * b; }
    ll mod_mul(ll a, ll b) { return mul(a, b) % MOD; }

    HashedString(string const & s) : p(s.size() + 1) {
        b = 31; // initialize base randomly if needed
        while ((int) pow.size() < (int) s.size() + 1)
            pow.push_back(mod_mul(pow.back(), b));
        for (int i = 1; i <= (int) s.size(); i++)
            p[i] = (mod_mul(p[i-1], b) + s[i]) % MOD;
    }

    ll get(int l, int r) {
        ll val = p[r + 1] - mod_mul(p[l], pow[r + 1 - l]);
        return (val + MOD) % MOD;
    }
};
