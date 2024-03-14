#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string str;
	istringstream iss(s);
	vector<int> kda;
	while (getline(iss, str, '/'))
	{
		kda.push_back(stoi(str));
	}
	
	int k = kda[0];
	int d = kda[1];
	int a = kda[2];
	if (k + a < d || !d)
		cout << "hasu";
	else
		cout << "gosu";

	return 0;
}
