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
#define repr(i,n,b)     for(int i=n;i>b;i--)
// #define endl            '\n'
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
const int ddx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
const int ddy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

ll powmod(ll a, ll b, ll c = mod) {ll res = 1; a %= c; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % c; a = a * a % c;} return res;}
ll powb(ll a, ll b) {ll res = 1; a ; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a; a = a * a;} return res;}

const int SIZE = 10000005;                            //constant SIZE here

void qinit(int idx[], int sz[], int n) {
	rep(i, 0, n) idx[i] = i, sz[i] = 1;
}
int qroot(int index, int idx[]) {
	while (index != idx[index]) {
		idx[index] = idx[idx[index]];
		index = idx[index];
	}
	return index;
}
bool qfind(int p, int q, int idx[]) {
	return qroot(p, idx) == qroot(q, idx);
}
void qunion(int p, int q, int idx[], int sz[]) {
	int rootp = qroot(p, idx), rootq = qroot(q, idx);
	if (rootp == rootq) return;
	if (sz[rootp] >= sz[rootq]) {
		idx[rootq] = idx[rootp];
		sz[rootp] += sz[rootq];
	}
	else {
		idx[rootp] = idx[rootq];
		sz[rootq] += sz[rootp];
	}
}

signed main() {
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);
//For fast IO
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
	// std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
	// std::cout.precision(15);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
// More design than code

	int n;
	cin >> n;
	int m;
	cin >> m;
	//n = number of vertices, m = number of edges

	vector < pair <int, pii> > edges(m);
	rep(i, 0, m) {
		cin >> edges[i].se.fi >> edges[i].se.se >> edges[i].fi;
		edges[i].se.fi--;
		edges[i].se.se--;
	}
	sort(all(edges));
	int idx[n], size[n];
	qinit(idx, size, n);
	vector < pair <int, pii> > MST;
	int total = 0;
	rep(i, 0, m) {
		if (!qfind(edges[i].se.fi, edges[i].se.se, idx)) {
			qunion(edges[i].se.fi, edges[i].se.se, idx, size);
			total += edges[i].fi;
			MST.pb({edges[i]});
		}
	}
	cout << total << endl;
	cout << "MST has edges: " << endl;
	for (auto i : MST) {
		cout << i.se.fi << " " << i.se.se << " " << i.fi << endl;
	}
#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}