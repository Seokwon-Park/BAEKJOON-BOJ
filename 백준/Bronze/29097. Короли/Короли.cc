#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, a, b, c;
	cin >> n >> m >> k >> a >> b >> c;

	vector<int> v;
	v.push_back(n * a);
	v.push_back(m * b);
	v.push_back(k * c);

	int mx = *max_element(v.begin(), v.end());

	string kings[3] = { "Joffrey", "Robb", "Stannis" };
	for (int i = 0; i < 3; i++)
	{
		if (mx == v[i])
			cout << kings[i] << ' ';
	}


	return 0;
}