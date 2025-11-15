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

int n, f;
int x[10][10];
vector<int> ans;
int sum;
bool isused[11];


void func(int k)
{
	if (sum > f)
	{
		return;
	}
	if (k == n)
	{
		if (sum != f) return;
		for (auto i : ans)
		{
			cout << i << ' ';
		}
		exit(0);
	}
	for (int i = 1; i <= n; i++)
	{
		if (isused[i]) continue;
		isused[i] = true;
		ans.push_back(i);
		sum += i * x[n - 1][k];
		func(k + 1);
		sum -= i * x[n - 1][k];
		ans.pop_back();
		isused[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> f;

	x[0][0] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			x[i + 1][j] += x[i][j];
			x[i + 1][j + 1] += x[i][j];
		}
	}

	func(0);


	return 0;
}