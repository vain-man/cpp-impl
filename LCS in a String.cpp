
#include<bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define vii vector <int>
#define pii pair <int, int>
#define fi first
#define se second
#define rep(i,a,n)		for(int i=a;i<n;i++)
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof a)
#define mod 1000000007LL;
#define mkp make_pair
#define pb push_back
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
using namespace std;
double pi = 3.1415926535;
double eps = 0.000001;

void print(vii &arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	cout << endl;
}
int binexpmod(int a,  int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return (res);
}

int32_t main() {
/////////////////////////////////////////////////////////////////////
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);
//For fast IO
/////////////////////////////////////////////////////////////////////
//	std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
//    std::cout.precision(10);
	string s1, s2, s3 = "";
	cin >> s1 >> s2;
	int n1 = s1.size(), n2 = s2.size();
	int dp[n2 + 1][n1 + 1];
	mem(dp, 0);
	char trace[n2 + 1][n1 + 1];
	mem(trace, 'o');
	rep(i, 1, n2 + 1) {
		rep(ii, 1, n1 + 1) {
			if (s2[i - 1] == s1[ii - 1]) {
				dp[i][ii] += dp[i - 1][ii - 1] + 1;
				trace[i][ii] = 'd';
			}
			else if (dp[i][ii - 1] != dp[i - 1][ii]) {
				dp[i][ii] = max(dp[i][ii - 1], dp[i - 1][ii]);
				if (dp[i][ii - 1] > dp[i - 1][ii]) trace[i][ii] = 'l';
				else trace[i][ii] = 'u';
			}
			else {
				dp[i][ii] = dp[i][ii - 1];
				trace[i][ii] = 'l';
			}
		}
	}

	rep(i, 0, n2 + 1) {
		rep(ii, 0, n1 + 1) cout << dp[i][ii] << "  ";
		cout << endl;
	}
	cout << "Trace: " << endl;
	rep(i, 0, n2 + 1) {
		rep(ii, 0, n1 + 1) cout << trace[i][ii] << "  ";
		cout << endl;
	}
	int i2 = n2, i1 = n1;
	while (trace[i2][i1] != 'o') {
		if (trace[i2][i1] == 'd') {
			s3 += s2[i2 - 1];
			i2--;
			i1--;
		}
		else if (trace[i2][i1] == 'u') {
			i2--;
		}
		else if (trace[i2][i1] == 'l') {
			i1--;
		}
	}
	reverse(s3.begin(), s3.end());
	cout << s3 << endl;
	return 0;
}

