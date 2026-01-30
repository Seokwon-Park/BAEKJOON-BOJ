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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> med(105, -1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		med[a] = b;
	}

	int r;
	cin >> r;
	for (int i = 0; i < r; i++)
	{
		int l;
		cin >> l;
		vector<int> res;
		int wrong = 0;
		for (int j = 0; j < l; j++)
		{
			int s;
			cin >> s;
			if (med[s] == -1)
			{
				wrong++;
			}
			res.push_back(med[s]);
			
		}
		if (wrong > 0)
		{
			cout << "YOU DIED";
		}
		else
		{
			for (auto i : res)
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}


	return 0;
}