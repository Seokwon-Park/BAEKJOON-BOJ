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
	set<string> st;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		st.insert(s);
	}
	if (g == 'Y')
		cout << st.size();
	else if (g == 'F')
		cout << st.size() / 2;
	else
		cout << st.size() / 3;


	return 0;
}