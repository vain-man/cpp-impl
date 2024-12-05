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
#define mod 			1000000007
#define mod2 			1000000009
#define mod3 			998244353
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
db eps       =          1e-7;
// const int dx[] = {0, 0, -1, 1, 0, 0};
// const int dy[] = {0, 0, 0, 0, -1, 1};
const int dx[] = { -1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// const int dz[] = { -1, 1, 0, 0, 0, 0};
const int ddx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
const int ddy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

ll powmod(ll a, ll b, ll c = mod) {ll res = 1; a %= c; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % c; a = a * a % c;} return res;}
ll powb(ll a, ll b) {ll res = 1; a ; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a; a = a * a;} return res;}

const int SIZE = 200010;        //constant SIZE here
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
	if (n < r) return 0;
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

class TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode()
	{
		val = 0;
		left = right = NULL;
	}
	TreeNode(int a)
	{
		val = a;
		left = right = NULL;
	}
	int getHeight(TreeNode *root)
	{
		if (!root) return -1;
		return 1 + max(root->getHeight(root->left), root->getHeight(root->right));
	}
	int getBalanceFactor(TreeNode *root)
	{
		if (!root) return -1;
		return root->getHeight(root->left) - root->getHeight(root->right);
	}
	TreeNode * leftRotate(TreeNode *x)
	{
		TreeNode * y = x -> right;
		TreeNode * T2 = y -> left;

		y -> left = x;
		x -> right = T2;

		return y;
	}
	TreeNode * rightRotate(TreeNode *y)
	{
		TreeNode * x = y -> left;
		TreeNode * T2 = x -> right;

		x -> right = y;
		y -> left = T2;

		return x;
	}
	TreeNode *insertAsAVL(TreeNode *root, TreeNode *newNode)
	{
		if (!root)
		{
			root = newNode;
			//We found newNode's place in the tree - newNode is happy now
			cout << newNode->val << " value inserted successfully" << endl;
			return root;
		}
		if (root->val > newNode->val)
		{
			root->left = root->left->insertAsAVL(root->left, newNode);
		}
		else if (root->val < newNode->val)
		{
			root->right = root->right->insertAsAVL(root->right, newNode);
		}
		else
		{
			//Throw an error as our tree does not allow duplicates
			cout << "ERROR: " << newNode->val << " is a duplicate value" << endl;
			return root;
		}


		//getBalanceFactor takes O(height) time
		int bf = getBalanceFactor(root);


		//RR Rotation
		if (bf > 1 && newNode->val < root->left->val)
		{
			return root->rightRotate(root);
		}


		//LL Rotation
		if (bf < -1 && newNode->val > root->right->val)
		{
			return root->leftRotate(root);
		}

		//LR Rotation
		if (bf > 1 && newNode->val > root->left->val)
		{
			root->left = root->left->leftRotate(root->left);
			return root->rightRotate(root);
		}

		//RL Rotation
		if (bf < -1 && newNode->val < root->right->val)
		{
			root->right = rightRotate(root->right);
			return root->leftRotate(root);
		}

		//if no changes, then return root as is
		return root;
	}
	TreeNode * deleteFromAVL(TreeNode *root, int val)
	{
		//Base case
		if (!root) return root;


		//Is value to be deleted in left subtree, or right subtree, or is current
		//node to be deleted?
		if (root->val > val)
		{
			root->left = root->left->deleteFromAVL(root->left, val);
		}
		else if (root->val < val)
		{
			root->right = root->right->deleteFromAVL(root->right, val);
		}
		else
		{
			//Case 1: No children
			if (!root->left && !root->right)
			{
				delete root;
				return NULL;
			}

			//Case 2.1: 1 child (right)
			if (!root->left)
			{
				TreeNode *temp = root->right;
				delete root;
				return temp;
			}

			//Case 2.2: 1 child (left)
			if (!root->right)
			{
				TreeNode *temp = root->left;
				delete root;
				return temp;
			}

			//Case 3: Both children

			//Find inorder successor
			TreeNode *inorderS = root->right;
			while (inorderS->left)
			{
				inorderS = inorderS->left;
			}
			//Set root as inorder successor, and delete inorder successor
			//from right subtree
			root->val = inorderS->val;
			root->right = root->right->deleteFromAVL(root->right, inorderS->val);
		}

		//Check balancing
		int bf = root->getBalanceFactor(root);
		//LL
		if (bf == 2 && getBalanceFactor(root->left) > 0)
		{
			return rightRotate(root);
		}

		//LR
		if (bf == 2 && getBalanceFactor(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		//RR
		if (bf == -2 && getBalanceFactor(root->right) > 0)
		{
			return leftRotate(root);
		}

		//RL
		if (bf == -2 && getBalanceFactor(root->right) < 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}


		//Return root unchanged if balanced
		return root;
	}
	void inorder(TreeNode *root)
	{
		if (!root) return;
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
};

void solve()
{
	int n;
	cin >> n;
	TreeNode *root = NULL;
	cout << "1: Insert" << endl;
	cout << "2: Delete" << endl;
	cout << "Plx enter valid queries" << endl;
	rep(i, 0, n)
	{
		cout << "Query # " << i + 1 << endl;
		int q;
		cin >> q;
		if (q == 1)
		{
			if (i == 0)
			{
				int v;
				cin >> v;
				root = new TreeNode(v);
				cout << "Root created" << endl;
			}
			else
			{
				int v;
				cin >> v;
				TreeNode *newNode = new TreeNode(v);
				root = root->insertAsAVL(root, newNode);
			}
		}
		else
		{
			int v;
			cin >> v;
			root = root->deleteFromAVL(root, v);
			cout << v << " deleted from tree" << endl;
		}
	}
	root->inorder(root);
	cout << endl;
}

signed main() {
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	// cerr.tie(NULL);
//For fast IO
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
	// std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
	// std::cout.precision(12);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
// More design than code
	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
	}

#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}