#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 5

struct student
{
	int num;
	float score;
}
s[N];

void read( struct student s[N] )
{
	int i;
	for( i = 1; i <= 5; i ++) {
		printf("Please input the %d student information and scores\n", i);
		scanf("%d %f", &s[i].num, &s[i].score);
	}
	
}

int check()
{
	int i,number;
	printf("Please input the student number:\n");
	scanf("%d", &number);
	for ( i = 1; i <= 5; i ++) {
		if ( number == s[i].num){
			printf("%d\n%.2f", number, s[i].score);
		}
	}
}

int main()
{
	read(s);
	check(s);
}

