#include <stdio.h>
int main()
{
	//1.
	/*int arr[5][5];
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cnt++;
			if (i%2 != 0)
			{
				arr[i][4 - j] = cnt;
			}
			else
			{
				arr[i][j] = cnt;
			}
			
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}*/

	//2. 달팽이 배열 다시 확인
	int arr2[5][5];
	int cnt = 1;
	int ch = 0;
	int i = 0, j;
	

	for (j = 0; j < 5; j++)
	{
		arr2[i][j] = cnt;
		cnt++;
	}
	for (i = 1; i < 5; i++)
	{
		arr2[i][4] = cnt;
		cnt++;
	}
	for ( j = 0; i < 5; i++)
	{
		arr2[4][4 - j] = cnt;
		cnt++;
	}
	for (i = 1; i < 4; i++)
	{
		arr2[5 - i][j] = cnt;
		cnt++;
	}
	for ( j = 0; j < 4; j++)
	{
		arr2[1][j] = cnt;
		cnt++;
	}
	for ( j = 1; j < 4; j++)
	{
		arr2[3][j] = cnt;
		cnt++;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%2d ", arr2[i][j]);
		}
		printf("\n");
	}

	return 0;
}