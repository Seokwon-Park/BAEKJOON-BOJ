#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<int> split(string s)
{
	istringstream iss(s);
	string tmp;
	vector<int> ymd;
	while (getline(iss, tmp, '-'))
	{
		ymd.push_back(stoi(tmp));
	}
	return ymd;
}

bool isValid(vector<int> a, vector<int> b)
{
	if (a[0] < b[0])
	{
		return true;
	}
	else if (a[0] == b[0])
	{
		if (a[1] < b[1])
			return true;
		else if (a[1] == b[1])
		{
			if (a[2] <= b[2])
				return true;
			else
				return false;
		}
		return false;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string t;
	cin >> t;
	
	auto today = split(t);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		auto coup = split(x);

		ans += isValid(today, coup);
	}
	cout << ans;

	return 0;
}