#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		
		string sg;
		cin >> sg;
		while (sg != "6174")
		{
			string sl = sg;
			sort(sl.begin(), sl.end());
			sort(sg.begin(), sg.end(), greater<char>());
			string res = to_string(stoi(sg) - stoi(sl));
			cnt++;
			sg = (res.size() < 4 ? string(4 - res.size(), '0') + res : res);
		}
		cout << cnt << '\n';

	}

	return 0;
}