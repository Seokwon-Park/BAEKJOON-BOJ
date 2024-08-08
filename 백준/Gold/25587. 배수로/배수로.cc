#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int A[100005];
int B[100005];
vector<int> p(100005, -1);
vector<int> sz(100005, 1);
int cnt;

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

// 몰랐던 유파 풀이방식
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) // 일단 마을 번호가 작은 쪽이 parent가 되도록.
		swap(a, b);
	p[b] = a;

	// 만약 합치는 그룹 둘다 홍수거나, 둘다 홍수가 안난다면 어차피 합쳐도 홍수 안남.
	// 이외의 경우에 대해서만 생각해주면 됨

	//a 가 홍수인 경우
	if (A[a] < B[a] && A[b] >= B[b]) 
	{
		if (A[a] + A[b] >= B[a] + B[b]) // 만약 a, b그룹 합쳐서 홍수가 안나면
		{
			cnt -= sz[a]; // a그룹 크기만큼 홍수난 동네를 빼주면 된다.
		}
		else
		{
			cnt += sz[b]; // 홍수가난다면 b그룹이 홍수나는 도시가 되므로 더해준다.
		}
	}
	else if(A[a] >= B[a] && A[b] < B[b]) // 이하동문
	{
		if (A[a] + A[b] >= B[a] + B[b])
		{
			cnt -= sz[b];
		}
		else
		{
			cnt += sz[a];
		}
	}
	sz[a] += sz[b]; // 합치고 나서는 결과를 갱신해준다.
	A[a] += A[b]; 
	B[a] += B[b];
}

bool isSameGroup(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> B[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (B[i] > A[i])
			cnt++;
	}

	for (int i = 0; i < m; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int x, y;
			cin >> x >> y;
			if (!isSameGroup(x, y))
			{
				uni(x, y);
			}
		}
		else
		{
			cout << cnt << '\n';
		}
	}


	return 0;
}