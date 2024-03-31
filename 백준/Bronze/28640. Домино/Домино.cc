#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isExist[7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	istringstream issa(a);
	string tmp;
	while (getline(issa, tmp, '|'))
	{
		isExist[tmp.size()] = true;
	}

	istringstream issb(b);
	while (getline(issb, tmp, '|'))
	{
		if (isExist[tmp.size()])
		{
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";

	return 0;
}