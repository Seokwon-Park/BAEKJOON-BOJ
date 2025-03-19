#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool checker(string a, string b)
{
	// a의 뒤에 b가 연결 될 수 있나?
	for (int i = 1; i <= b.size() && i <= a.size(); i++)
	{
		bool result = true;
		for (int j = 0; j < i; j++)
		{
			if (a[a.size() - i + j] != b[j])
			{
				result = false;
				break;
			}
		}
		if (result)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(checker(s[i], s[j]) || checker(s[j],s[i]))
				ans++;
		}
	}

	cout << ans;

	return 0;
}