#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	cin >> n;
	string tmp = "";
	int tmpn = 0;
	for (int i = 0; i < n.length(); i++)
	{
		tmp += n[i];
		tmpn = stoi(tmp);
		while (tmpn >= 20000303)
		{
			tmpn -= 20000303;
		}
		tmp = to_string(tmpn);
	}
	cout << tmpn;
	

	return 0;
}