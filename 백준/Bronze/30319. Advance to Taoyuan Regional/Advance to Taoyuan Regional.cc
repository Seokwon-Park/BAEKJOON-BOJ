#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string tmp;
	vector<int> ymd;
	istringstream iss(s);
	while (getline(iss, tmp, '-'))
	{
		ymd.push_back(stoi(tmp));
	}

	int m, d;
	int carry = 0;
	if (21 - ymd[2] <= 0)
	{
		d = 21 - ymd[2] + 30;
		carry = 1;
	}
	else
	{
		d = 21 - ymd[2];
	}

	if (10 - ymd[1] - carry >= 1)
	{
		if (d >= 5)
			cout << "GOOD";
		else
			cout << "TOO LATE";
	}
	else
		cout << "TOO LATE";

	return 0;
}