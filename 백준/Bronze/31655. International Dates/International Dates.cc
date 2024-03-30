#include <bits/stdc++.h>

using namespace std;

using ll = long long;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	istringstream iss(s);
	string tmp;
	vector<int> date;
	while (getline(iss, tmp, '/'))
	{
		date.push_back(stoi(tmp));
	}
	if (date[0] <= 12 && date[1] <= 12)
		cout << "either";
	else if(date[0] <= 12)
		cout << "US";
	else
		cout << "EU";


	return 0;
}