#include<iostream>
#include<cstring>

using namespace std;

int Min(int x, int y)
{
	return x < y ? x : y;
}


int main()
{
	int n, k;
	int ctype[101];
	int money[100001];
	cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		ctype[i] = 0;
		money[i] = 100001;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> ctype[i];
	}
	money[0] = 0;
	for(int i=1; i<=n; i++)
		for (int j = ctype[i]; j <= k; j++)
		{
			money[j] = Min(money[j], money[j - ctype[i]] + 1);
		}
	if (money[k] == 100001)
		money[k] = -1;

	for (int i = 1; i <= k; i++)
	{
		printf("%d\n", money[i]);
	}


	printf("\n%d\n", money[k]);

}