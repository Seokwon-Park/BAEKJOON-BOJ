#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> st(n);
	vector<int> en(n);
	for (int i = 0; i < n; i++)
	{
		cin >> st[i] >> en[i];
	}

	int res = max(0, *max_element(st.begin(), st.end()) - *min_element(en.begin(), en.end()));

	cout << res;


	return 0;
}