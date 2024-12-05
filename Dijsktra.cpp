// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define db              double
#define ll              long long int
#define ld              long double
//#define int           long long int
#define ull             unsigned long long
#define fi              first
#define se              second
#define rep(i,a,n)      for(int i=a;i<n;i++)
#define repr(i,n,b)     for(int i=n;i>=b;i--)
#define endl            '\n'
#define mem(a,b)        memset(a, b, sizeof a)
#define mkp             make_pair
#define pb              push_back
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define w(t)            int t; cin>>t; while(t--)
#define all(a)          a.begin(), a.end()
#define sz(a)           int((a).size())
#define debug           cerr << " Here. " << endl;
#define dbg(x)          cerr << #x << " = " << x << endl;
#define dbgp(x)         cerr<<"[ "<<#x<<".fi : "<<x.first<<", "<<#x<<".se : "<<x.second<<" ]"<<endl
#define dbgs(x)         cerr<<"[ "; for(auto i:x) cerr<<i<<" "; cerr<<" ]"<<endl;
#define dbgm(x)         cerr<<"----------"<<endl; for(auto i:x) cerr<<i.fi<<":"<<i.se<<endl; cerr<<"----------";
#define printdb(i)      printf("%.12lf\n",i)
#define isOn(S, j)      (S & (1<<j))
#define setBit(S, j)    (S |= (1<<j))
#define clearBit(S, j)  (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S)       (S & (-S))
#define setAll(S, n)    (S = (1<<n)-1)
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define display(a)      for(auto x: a) cerr<<x<<" "; cerr<<"\n";
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef map < int, int > mii;
typedef vector < int > vii;
typedef vector < ll > vll;
typedef vector < vii > vvi;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T> >;
template <class T> using max_heap = priority_queue<T>;
const db PI =           acos(-1);
const int INF =         0x3f3f3f3f;
const ll LINF =         (ll)2e18;
db eps       =          1e-5;
ll mod       =          1000000007;    //    998244353LL
int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = { -1, 1, 0, 0, 0, 0};

ll powmod(ll a, ll b, ll c = mod) {ll res = 1; a %= c; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % c; a = a * a % c;} return res;}
ll powb(ll a, ll b) {ll res = 1; a ; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a; a = a * a;} return res;}

const int SIZE = 500001;                              //constant SIZE here
bool judge(int a[], int n) {
    static int used[SIZE + 1];
    for (int i = 1; i <= n; i++) used[i] = 0;
    for (int i = 0; i < n; i++) used[a[i]] = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) return 0;
    }
    return 1;
}

ll ncr(ll n, ll r) {
    r = min(r, n - r);
    ll A[r], i, j, B[r];
    iota(A, A + r, n - r + 1);
    iota(B, B + r, 1);

    ll g;
    for (i = 0; i < r; i++)
        for (j = 0; j < r; j++)
        {
            if (B[i] == 1)
                break;
            g = __gcd(B[i], A[j] );
            A[j] /= g;
            B[i] /= g;
        }
    ll ans = 1;
    for (i = 0; i < r; i++)
        ans = (ans * A[i] % mod);
    return ans;
}
vector <vector < pii > > adj(SIZE);
signed main() {
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
//For fast IO
/////////////////////////////////////////////////////////////////////
// Have you thought about it enough?
/////////////////////////////////////////////////////////////////////
//  std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
//  std::cout.precision(6);
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    map <pii, int> mp;
    rep(i, 0, m) {
        int u, v, e;
        cin >> u >> v >> e;
        if (mp.find({u, v}) == mp.end()) {
            mp[ {u, v}] = e;
        }
        else mp[ {u, v}] = min(mp[ {u, v}], e);
    }
    for (auto i : mp) {
        int u, v, e;
        u = i.fi.fi;
        v = i.fi.se;
        e = i.se;
        adj[u].pb({v, e});
        if (u != v) adj[v].pb({u, e});
    }
    int src;
    cin >> src;
    vii d(n + 1, INT_MAX);
    min_heap < pii > s;
    d[src] = 0;
    s.push({0, src});
    while (!s.empty()) {
        pii p = s.top();
        s.pop();
        if (d[p.se] != p.fi) continue;
        for (auto i : adj[p.se]) {
            if (d[p.se] + i.se < d[i.fi]) {
                d[i.fi] = d[p.se] + i.se;
                s.push({d[i.fi], i.fi});
            }
        }
    }
    return 0;
}