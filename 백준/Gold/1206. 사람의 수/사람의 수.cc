#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool Check(int n, vector<int>& v)
{
	vector<int> arr(n*50+1);
	for (int i = 0; i <= n*50; i++)
	{
		arr[i] = i*1000/n;
	}

	bool Result = true;
	for (int i = 0; i < v.size(); i++)
	{
		int target = v[i];
		if (!binary_search(arr.begin(), arr.end(), target))
		{
			Result = false;
			break;
		}
	}
	return Result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int ix = 0;
		while (s[ix] != '.') ix++;
		string tmp = s.substr(0, ix) + s.substr(ix + 1);
		v[i] = stoi(tmp);
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (Check(i, v))
		{
			cout << i;
			break;
		}
	}

	
	return 0;
}
