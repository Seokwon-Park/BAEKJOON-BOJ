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

// 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		if (n <= 4)
		{
			cout << "YES";
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				vector<int> nv(n - i - 1);
				for (int j = 0; j < v.size() - 1; j++)
				{
					nv[j] = v[j + 1] - v[j];
				}
				v.swap(nv);
			}
			
			bool isAns = true;
			for (int i : v)
			{
				if (i != 0)
				{
					isAns = false;
				}
			}
			cout << (isAns ? "YES" : "NO");
		}
		cout << '\n';

	}


	return 0;
}