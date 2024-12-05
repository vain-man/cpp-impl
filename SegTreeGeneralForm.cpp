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
#define mod 			1000000007 //     998244353
#define mod2 			1000000009
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
// const int dx[] = {0, 0, -1, 1, 0, 0};
// const int dy[] = {0, 0, 0, 0, -1, 1};
const int dx[] = { -1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// const int dz[] = { -1, 1, 0, 0, 0, 0};
const int ddx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
const int ddy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

ll powmod(ll a, ll b, ll c = mod) {ll res = 1; a %= c; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % c; a = a * a % c;} return res;}
ll powb(ll a, ll b) {ll res = 1; a ; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a; a = a * a;} return res;}

const int SIZE = 100001;        //constant SIZE here
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
	for (i = 0; i < r; i++) {
		// ans = (ans * A[i] % mod);    //with mod
		ans = (ans * A[i]);				//without mod
	}
	return ans;
}

//int st[4*SIZE];
//void buildTree(int arr[], int v, int start, int end) {
//	if (start == end) {
//		st[v] = (arr[start]==0);
//		return;
//	}
//	int mid = start + (end - start) / 2;
//
//	buildTree(arr, 2 * v, start, mid);
//	buildTree(arr, 2 * v + 1, mid + 1, end);
//
//	st[v] = st[2 * v] + st[2 * v + 1];
//}
//
//int answerQuery(int l, int r, int ss, int se, int v) {
//	if (ss > r || se < l) {
//		return 0;
//	}
//	if (ss >= l && se <= r) {
//		return st[v];
//	}
//	int mid = ss + (se - ss) / 2;
//
//	int lans = answerQuery(l, r, ss, mid, 2 * v);
//	int rans = answerQuery(l, r, mid + 1, se, 2 * v + 1);
//
//	return lans + rans;
//}
//
//void pointUpdate(int val, int idx, int ss, int se, int v){
//	if(ss==se){
//		st[v]=(val==0);
//		return;
//	}
//
//	int mid=ss+(se-ss)/2;
//
//	if(idx<=mid){
//		pointUpdate(val,idx,ss,mid,2*v);
//	}
//	else pointUpdate(val,idx,mid+1,se,2*v+1);
//	st[v]=st[2*v]+st[2*v+1];
//}
//
//int find_kth(int v, int tl, int tr, int k){
//	if(k>st[v]) return -1;
//	if(tl==tr) return tl;
//	int tm=(tl+tr)/2;
//	if(st[2*v]>=k){
//		return find_kth(2*v,tl,tm,k);
//	}
//	else{
//		return find_kth(2*v+1,tm+1,tr,k-st[2*v]);
//	}
//}

//Basic SegTree
//Min, Max, Sum, GCD/LCM, Number of Zeros/Index of K-th 0,
//Maximum with frequency of maximum, Finding subsegments with the maximal sum (VVIP)
// https://ideone.com/2myOOp - Code to lazy Prop implementation

struct node {
	int sum, pref, suff, ans;
};

node st[4 * SIZE];

node make_node(int val) {
	node newnode;
	newnode.sum = val;
	newnode.ans = newnode.pref = newnode.suff = max(val, 0);
	return newnode;
}

node combine(node l, node r) {
	node parent;
	parent.sum = l.sum + r.sum;
	parent.pref = max(l.pref, l.sum + r.pref);
	parent.suff = max(r.suff, r.sum + l.suff);
	parent.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	return parent;
}

void build(int arr[], int v, int start, int end) {
	if (start == end) {
		st[v] = make_node(arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	build(arr, 2 * v, start, mid);
	build(arr, 2 * v + 1, mid + 1, end);
	st[v] = combine(st[2 * v], st[2 * v + 1]);
}

void update(int val, int idx, int tl, int tr, int v) {
	if (tl == tr) {
		st[v] = make_node(val);
		return;
	}
	int tm = (tl + tr) / 2;
	if (idx <= tm) {
		update(val, idx, tl, tm, 2 * v);
	}
	else update(val, idx, tm + 1, tr, 2 * v + 1);
	st[v] = combine(st[2 * v], st[2 * v + 1]);
}

node query(int l, int r, int tl, int tr, int v) {
	if (tl > r || tr < l) return make_node(0);

	if (tl >= l && tr <= r) {
		return st[v];
	}

	int tm = (tl + tr) / 2;

	node left = query(l, r, tl, tm, 2 * v);
	node right = query(l, r, tm + 1, tr, 2 * v + 1);

	return combine(left, right);
}

void printnode(node a) {
	cout << a.sum << " " << a.pref << " " << a.suff << " " << a.ans << endl;
}
//int st[SIZE];
//void buildTree(int arr[], int v, int start, int end) {
//	if (start == end) {
//		st[v] = (arr[start]==0);
//		return;
//	}
//	int mid = start + (end - start) / 2;
//
//	buildTree(arr, 2 * v, start, mid);
//	buildTree(arr, 2 * v + 1, mid + 1, end);
//
//	st[v] = st[2 * v] + st[2 * v + 1];
//}
//
//int answerQuery(int l, int r, int ss, int se, int v) {
//	if (ss > r || se < l) {
//		return 0;
//	}
//	if (ss >= l && se <= r) {
//		return st[v];
//	}
//	int mid = ss + (se - ss) / 2;
//
//	int lans = answerQuery(l, r, ss, mid, 2 * v);
//	int rans = answerQuery(l, r, mid + 1, se, 2 * v + 1);
//
//	return lans + rans;
//}
//
//void pointUpdate(int val, int idx, int ss, int se, int v){
//	if(ss==se){
//		st[v]=(val==0);
//		return;
//	}
//
//	int mid=ss+(se-ss)/2;
//
//	if(idx<=mid){
//		pointUpdate(val,idx,ss,mid,2*v);
//	}
//	else pointUpdate(val,idx,mid+1,se,2*v+1);
//	st[v]=st[2*v]+st[2*v+1];
//}
//
//int find_kth(int v, int tl, int tr, int k){
//	if(k>st[v]) return -1;
//	if(tl==tr) return tl;
//	int tm=(tl+tr)/2;
//	if(st[2*v]>=k){
//		return find_kth(2*v,tl,tm,k);
//	}
//	else{
//		return find_kth(2*v+1,tm+1,tr,k-st[2*v]);
//	}
//}

void solve() {
	int n;
	cin >> n;
	int arr[n];
	rep(i, 0, n) cin >> arr[i];
	rep(i, 0, n) cerr << arr[i] << " ";
	cerr << endl;
	build(arr, 1, 0, n - 1);
	rep(i, 1, 2 * n + 1) {
		printnode(st[i]);
	}
	cout << endl;
	int q;
	cin >> q;
	while (q--) {
		int a, l, r;
		cin >> a >> l >> r;
		if (a == 1) printnode(query(l - 1, r - 1, 0, n - 1, 1));
		else if (a == 2) {
			update(r, l - 1, 0, n - 1, 1);
		}
//		else if(a==3){
//			cout<<find_kth(1,0,n-1,l)<<endl;
//		}
	}
	return;
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
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}