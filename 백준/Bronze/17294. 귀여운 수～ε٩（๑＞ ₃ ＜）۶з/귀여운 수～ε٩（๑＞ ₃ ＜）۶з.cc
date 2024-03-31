#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string k;
	cin >> k;
	if (k.size() == 1)
	{
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		return 0;
	}
	int d = k[1] - k[0];
	for (int i = 1; i < k.size()-1; i++)
	{
		int diff = k[i + 1] - k[i];
		if (diff != d)
		{
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			return 0;
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";

	return 0;
}