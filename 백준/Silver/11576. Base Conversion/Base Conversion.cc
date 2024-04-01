#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	vector<int> va(n);
	int dec = 0;
	int apow = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> va[i];
	}
	for (int i = n-1; i >=0; i--)
	{
		dec += apow * va[i];
		apow *= a;
	}

	vector<int> vb;
	while (dec)
	{
		vb.push_back(dec % b);
		dec /= b;
	}

	for (int i = vb.size() - 1; i >= 0; i--)
	{
		cout << vb[i] << ' ';
	}

	return 0;
}
