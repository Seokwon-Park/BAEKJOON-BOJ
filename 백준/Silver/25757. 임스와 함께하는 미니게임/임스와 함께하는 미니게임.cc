#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	char g;
	cin >> n >> g;
	vector<string> st;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		st.push_back(s);
	}

	sort(st.begin(), st.end());
	int sz = unique(st.begin(), st.end()) - st.begin();

	if (g == 'Y')
		cout << sz;
	else if (g == 'F')
		cout << sz / 2;
	else
		cout << sz / 3;


	return 0;
}