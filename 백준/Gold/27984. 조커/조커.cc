#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

bool sf, qfin, q, fh, fl, st, tri, p;
bool isused[4][14];

pii getfreecard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (!isused[i][j])
			{
				return { i,j };
			}
		}
	}
	return { 0,0 };
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> shape(4);
	vector<int> number(14);
	for (int i = 0; i < 4; i++)
	{
		int s, r;
		cin >> s >> r;
		shape[s]++;
		number[r]++;
		isused[s][r] = true;
	}

	int s = -1, n = -1;

	//스트레이트 조건 확인
	int stnumber = 1;
	for (int i = 1; i <= 9; i++)
	{
		int cont = 0;
		for (int j = 0; j < 5; j++)
		{
			if (number[i + j] > 0)
			{
				cont++;
			}
		}
		if (cont == 4)
		{
			st = true;
			for (int j = 0; j < 5; j++)
			{
				if (number[i + j] == 0)
				{
					stnumber = i + j;
					break;
				}
			}
			break;
		}
	}
	//스트레이트 끝

	//플러시 조건 확인
	int maxshape = max_element(shape.begin(), shape.end()) - shape.begin();
	int flcond = shape[maxshape];
	if (flcond == 4) // 플러시 가능
	{
		fl = true;
	}
	//플러시 끝

	//같은 쌍 조건 확인
	int maxnumber = max_element(number.begin(), number.end()) - number.begin();
	int paircond = number[maxnumber];
	if (paircond == 4) // 이미 포카드인경우
	{
		qfin = true;
	}
	else if (paircond == 3) // 포카드 가능
	{
		q = true;
	}
	else if (paircond == 2) // 풀하우스 3/1의 경우는 무조건 포카드를 가면됨 2/2의 경우
	{
		if (count(number.begin(), number.end(), 2) == 2) // 2페어면 풀하우스 가능
		{
			fh = true;
		}
		else // 1페어라는 뜻이므로 무조건 트리플로 가는게 이득 그럼 투페어는 경우가 나올수가 없는듯?
		{
			tri = true;
		}
	}
	else// 여기서는 뭘해도 원페어까지만 만들 수 있음
	{
		p = true;
	}

	if (st && fl)
	{
		if (stnumber > 13)
		{
			n = stnumber - 5;
		}
		else
		{
			n = stnumber;
		}
		s = maxshape;
	}
	else if (qfin)
	{
		tie(s, n) = getfreecard();
	}
	else if (q || fh) // 어차피 포카드랑 풀하우스는 생성 조건이 같다. 가장 많은 카드번호의 다른모양을 찾는것
	{
		n = maxnumber;
		for (int i = 0; i < 4; i++)
		{
			if (!isused[i][n])
			{
				s = i;
				break;
			}
		}
	}
	else if (fl)
	{
		s = maxshape;
		for (int i = 1; i <= 13; i++)
		{
			if (!isused[s][i])
			{
				n = i;
				break;
			}
		}
	}
	else if (st)
	{
		n = stnumber;
		for (int i = 0; i < 4; i++)
		{
			if (!isused[i][n])
			{
				s = i;
				break;
			}
		}
	}
	else // 어차피 트리플이랑 원페어는 생성 조건이 같다. 가장 많은 카드번호의 다른모양을 찾는것
	{
		n = maxnumber;
		for (int i = 0; i < 4; i++)
		{
			if (!isused[i][n])
			{
				s = i;
				break;
			}
		}
	}
	
	cout << s << ' ' << n;



	return 0;
}