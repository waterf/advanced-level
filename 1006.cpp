#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int m;
	char ID[15], signIn[15], signOut[15];
	char minId[15], maxId[15], tempIn[15], tempOut[15];
	cin >> m;
	for( int i=0;i<m;i++ )
	{
		cin >> ID >> signIn >> signOut;
		if( !i )
		{
			strcpy(tempIn, signIn);
			strcpy(tempOut, signOut);
		}
		if( strcmp(tempIn, signIn)>=0 )
		{	
			strcpy(tempIn, signIn);
			strcpy(minId, ID);
		}
		if( strcmp(tempOut, signOut)<=0 )
		{
			strcpy(tempOut, signOut);
			strcpy(maxId, ID);
		}
	}
	cout << minId << " " << maxId;
	return 0;
} 