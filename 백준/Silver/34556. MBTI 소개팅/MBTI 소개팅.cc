#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

string m[10];
string w[10];
bool isused[10];
int n;
int ans;

int calc(string a, string b)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i])
			ret++;
	}
	return ret;
}

void func(int k, int score)
{
	if (k == n)
	{
		ans = max(ans, score);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isused[i]) continue;
		isused[i] = 1;
		func(k + 1, score+calc(m[i], w[k]));
		isused[i] = 0;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}

	func(0, 0);
	cout << ans;

	return 0;
}