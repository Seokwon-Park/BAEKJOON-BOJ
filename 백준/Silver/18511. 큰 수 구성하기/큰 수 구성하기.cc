#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string n;
int m, k;
int ntoi;
int mx = INT_MIN;
int v[3];
string newstr;

void func(int n)
{
	if (!newstr.empty())
	{
		int tmp = stoi(newstr);
		if (tmp <= ntoi)
		{
			mx = max(tmp, mx);
		}
	}
	if (n == m)
		return;
	for (int i = 0; i < k; i++)
	{
		newstr.push_back(v[i] + '0');
		func(n + 1);
		newstr.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	m = n.size();
	ntoi = stoi(n);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
	}
	func(0);
	cout << mx;

	return 0;
}