#include <cstdio>

///product of polynomial
float p1[1001], p2[1001], fin[2002];
float tp[1001][2002];

int main()
{
	int k=0, k1=0, k2=0;
	int index;
	int maxIndex=0;

	scanf("%d", &k);
	k1 = k;

	while( k-- )
	{
		scanf("%d", &index);
		if( maxIndex<index )maxIndex = index;
		scanf("%f", &p1[index]);
	}
	scanf("%d", &k);
	k2 = k;
	while( k-- )
	{
		scanf("%d", &index);
		if( maxIndex<index )maxIndex = index;
		scanf("%f", &p2[index]);
	}
	int sumIndex, tpIndex = 0;

	for( int i=0;i<=maxIndex;i++ )
	{
		if( p2[i] )
		{
			for( int j=0;j<=maxIndex;j++ )
			{
				if( p1[j] )
				{
					tp[i][i+j] = (p2[i]*p1[j]);
					if( tpIndex<i+j )tpIndex = i+j;
				}
			}
		}
	}
	for( int i=0;i<=maxIndex;i++ )
	{
		for( int j=0;j<=tpIndex;j++ )
		{
			if( tp[i][j] )
			{
				fin[j] += tp[i][j];
			}
		}
	}

	for( int i=tpIndex;i>=0;i-- )
	{
		if( fin[i] )
		{
			sumIndex++;
		}
	}
	printf("%d ", sumIndex);
	for( int i=tpIndex;i>=0;i-- )
	{
		if( fin[i] )
		{
			sumIndex--;
			printf("%d %.1f", i, fin[i]);
			if( sumIndex )printf(" ");
		}
	}
	return 0;
}