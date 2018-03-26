#include <stdio.h>
#include <cmath>

int main()
{
	int a, b, c;
	scanf("%d%d", &a, &b);
	a = a+b;
	c = std::abs(a);
	if( c<1000 )printf("%d", a);
	else if( c>=1000&&c<1000000 ){
		printf("%d,%03d", a/1000, c%1000);
	}else{
		printf("%d,%03d,%03d", a/1000000, (c/1000)%1000, c%1000);
	}
	return 0;
}