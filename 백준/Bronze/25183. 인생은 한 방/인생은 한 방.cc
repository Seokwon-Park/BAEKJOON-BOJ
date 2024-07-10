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
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 4; i++)
	{
		char prev = s[i];
		bool isOK = true;
		for (int j = 1; j< 5; j++)
		{
			if (abs(prev - s[i+j]) != 1)
			{
				isOK = false;
				break;
			}
			prev = s[i+j];
		}
		if (isOK)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
