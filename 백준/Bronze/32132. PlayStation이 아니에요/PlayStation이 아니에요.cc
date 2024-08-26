#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<bool> isPrint(55, true);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (i+1 < n && s[i] == 'P' && s[i + 1] == 'S')
		{
			int off = 2;
			while (i + off < n && (s[i + off] == '4' || s[i + off] == '5'))
			{
				isPrint[i + off] = false;
				off++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (isPrint[i])
			cout << s[i];
	}
	

	return 0;
}