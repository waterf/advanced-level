#include <iostream>
#include <stdio.h>
using namespace std;

float a[1000]={0}, b[1000]={0}, sum[1000]={0};
int flag[1000]={0};

int main()
{
	int num1, num2, n, count=0;
	cin >> num1;
	while( num1-- )
	{
		cin >> n;
		cin >> a[n];
		flag[n] = 1;
	}
	cin >> num2;
	while( num2-- )
	{
		cin >> n;
		cin >> b[n];
		flag[n] = 1;
	}
	int i=1000;
	while( i-- )
	{
		if( flag[i] )
		{
			sum[i] = a[i] + b[i];
			if( !sum[i] )flag[i] = 0;
		}
	}
	i = 1000;
	while( i-- )
	{
		if( flag[i] )
		{
			count ++;
		}
	}
	cout << count;
	if( count )cout << " ";
	i = 1000;
	while( i-- )
	{
		if( flag[i] )
		{
			count--;
			cout << i << " ";
			printf("%.1f", sum[i]);
			if( count )cout << " ";
		}
	}
	return 0;
}
