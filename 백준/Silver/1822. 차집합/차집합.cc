#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int na, nb;
	cin >> na >> nb;
	vector<int> a(na), b(nb);
	
	for (int i = 0; i < na; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < nb; i++)
	{
		cin >> b[i];
	}

	int answer = 0;
	vector<int> ansvec;
	sort(b.begin(), b.end());
	for (auto aa : a)
	{
		if (!binary_search(b.begin(), b.end(), aa))
		{
			ansvec.push_back(aa);
			answer++;
		}
	}
	sort(ansvec.begin(), ansvec.end());
	if (answer > 0)
	{
		cout << answer << '\n';
		for (auto i : ansvec)
		{
			cout << i << ' ';
		}
	}
	else
	{
		cout << 0;
	}

	return 0;
}