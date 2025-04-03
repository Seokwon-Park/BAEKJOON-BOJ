#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	set<int, greater<int>> s;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s.insert(v[i]);
	}

	int winner = -1;
	for (auto i : s)
	{
		if (count(v.begin(), v.end(), i) == 1)
		{
			winner = find(v.begin(), v.end(), i)-v.begin()+1;
			break;
		}
	}
	if (winner == -1)
	{
		cout << "none";
	}
	else
	{
		cout << winner;
	}
	

	return 0;
}