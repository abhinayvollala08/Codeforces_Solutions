/*
 ~ Author    : @tridib_2003
*/

#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

#define int                 long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007 // 998244353
#define vi                  vector<int>
#define vb                  vector<bool>
#define vvi                 vector<vector<int> >
#define vll                 vector<long long>
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)        for (auto& (i) : (a))
#define printall(a)         for (auto& (i) : (a)) cout << i << ' '
#define print(a)            cout << a << '\n'
#define rsort(a)            sort((a).rbegin(), (a).rend())
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define max3(a, b, c)       max((a), max((b), (c)))
#define min3(a, b, c)       min((a), min((b), (c)))
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


const int INF = 1e9 + 7;
const int MAX_K = 447;

void solve() {

	int n;
	cin >> n;

	vi arr(n + 1), pSum(n + 1, 0);

	FOR (i, 1, n + 1) {
		cin >> arr[i];
		pSum[i] = pSum[i - 1] + arr[i];
	}

	vvi dp(n + 2, vi (MAX_K, -INF));
	// dp[i][j] = the max. sum of the 1st segment in the range [i, n]
	// 			  such that we have j segments in total

	dp[n + 1][0] = INF;

	RFOR (i, n + 1, 1) {
		dp[i][0] = INF;

		FOR (j, 1, MAX_K) {

			if (i + j > n + 1)
				break;

			int firstSegSum = pSum[i + j - 1] - pSum[i - 1];

			if (firstSegSum < dp[i + j][j - 1])
				dp[i][j] = firstSegSum;

			dp[i][j] = max(dp[i][j], dp[i + 1][j]);
		}
	}

	RFOR (i, MAX_K, 1) {
		if (dp[1][i] > 0) {
			cout << i;
			return;
		}
	}
}

int32_t main() {

	FIO;

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
