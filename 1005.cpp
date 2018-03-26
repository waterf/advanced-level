#include <iostream>
#include <cstdio>

//const char *str[] = {"one", "two"};
const char str[][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char str1;
int num[100];

int main()
{
	int sum = 0, i=0;
	scanf("%c", &str1);
	while( str1!='\n' )
	{
		sum += str1-'0';
		scanf("%c", &str1);
	}
	while( sum )
	{
		num[i++] = sum%10;
		sum /= 10;
	}
	for( int j=i-1;j>=0;j-- )
	{
		printf("%s", str[num[j]]);
		if( j )printf(" ");
	}
	return 0;
}

