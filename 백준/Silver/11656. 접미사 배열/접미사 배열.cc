#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;

	vector<string> arr;
	string tmp = "";

	for (auto it = str.rbegin(); it != str.rend(); it++)
	{
		tmp += *it;
		string s(tmp.rbegin(), tmp.rend());
		arr.push_back(s);
	}

	sort(arr.begin(), arr.end());

	for (auto s : arr)
	{
		cout << s << '\n';
	}

	return 0;
}