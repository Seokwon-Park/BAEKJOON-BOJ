#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string a;
	string b;
	cin >> a >> b;
	vector<int> aa(26);
	vector<int> bb(26);

	vector<bool> aaa(n, true);
	vector<bool> bbb(n, true);
	for(int i = 0; i< n; i++)
	{
		char c = a[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			aaa[i] = false;
		}
		aa[c - 'a']++;
	}

	for (int i = 0; i < n; i++)
	{
		char c = b[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			bbb[i] = false;
		}
		bb[c - 'a']++;
	}

	if (aa != bb)
	{
		cout << "NO";
		return 0;
	}
	if (a[0] != b[0] || a[n - 1] != b[n - 1])
	{
		cout << "NO";
		return 0;
	}

	string aaaa = "";
	string bbbb = "";
	for (int i = 0; i < n; i++)
	{
		if (aaa[i])
			aaaa += a[i];
		if (bbb[i])
			bbbb += b[i];
	}
	if (aaaa != bbbb)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES";


	return 0;
}