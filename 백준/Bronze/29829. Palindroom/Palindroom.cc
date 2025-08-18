#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(4);
	for (int& i : v)
	{
		cin >> i;
	}

	bool chk = false;
	for (int i = 0; i < 2; i++)
	{
		if (v[i] != v[3 - i])
		{
			if (chk)
			{
				cout << "EI";
				return 0;
			}
			else
			{
				v[i] = v[3 - i];
				chk = true;
			}
		}
	}

	cout << "JAH\n";
	for (auto i : v)
	{
		cout << i << ' ';
	}

	return 0;
}