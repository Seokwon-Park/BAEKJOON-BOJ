#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n;
int myn = 1;
vector<int> ans;

void func(int k, int base, int prev)
{
	if (k == n)
	{
		if (base > myn)
		{
			for (int i : ans)
				cout << i << ' ';
			exit(0);
		}
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (i < prev)continue;
		ans.push_back(i);
		func(k + 1, base * i, i);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	vector<int> my(n);
	for (int i = 0; i < n; i++)
	{
		cin >> my[i];
		myn *= my[i];
	}

	vector<int> v(10, 0);

	func(0, 1, 0);

	cout << -1;

	return 0;
}