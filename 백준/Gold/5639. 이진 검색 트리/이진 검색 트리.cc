#include <bits/stdc++.h>

using namespace std;

vector<int> bst;

void postorder(int st, int ed)
{
	int mid = st + 1;
	if (st == ed) return;
	if (st == ed - 1)
	{
		cout << bst[st] << '\n'; 
		return;
	}
	while (mid < ed && bst[mid] < bst[st])
	{
		mid++;
	}
	postorder(st + 1, mid);
	postorder(mid, ed);
	cout << bst[st] << '\n';
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	while (cin >> n)
	{
		bst.push_back(n);
	}

	postorder(0, bst.size());


	return 0;
}