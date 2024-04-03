#include <bits/stdc++.h>

using namespace std;

using ll = long long;
char m[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	vector<int> v;

	for (int i = 0; i < a.size(); i++)
	{
		v.push_back(m[a[i] - 'A']);
		v.push_back(m[b[i] - 'A']);
	}

	while (v.size() > 2)
	{
		vector<int>tmp( v.size() - 1);
		for (int j = 0; j < v.size()-1; j++)
		{
			tmp[j] = (v[j] + v[j + 1]) % 10;
		}
		v = tmp;
	}

	cout << v[0] << v[1];

	return 0;
}