#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	list<int> L;
	for (int i = 0; i < n; i++)
	{
		L.push_back(i + 1);
	}
	list<int>::iterator itr = L.begin();
	
	cout << '<';
	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < k; j++)
		{
			if (itr == L.end()) itr = L.begin();
			itr++;
		}
		if (itr == L.begin()) itr = L.end();
		cout << *(--itr);
		if (i != n - 1) cout << ", ";
		itr = L.erase(itr);
	}
	cout << '>';

	return 0;
}
