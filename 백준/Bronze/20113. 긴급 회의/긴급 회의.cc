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

	vector<int> voted(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		voted[m]++;
	}

	auto mxfirst = max_element(voted.begin()+1, voted.end());
	int fix = mxfirst - voted.begin();
	if (fix == voted.size() - 1)
	{
		cout << fix;
	}
	else
	{
		auto mxsecond = max_element(voted.begin() + fix + 1, voted.end());
		if (*mxfirst == *mxsecond)
			cout << "skipped";
		else
			cout << fix;

	}

	

	return 0;
}