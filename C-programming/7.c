/*
 프로그램 작성일: 2020-05-19
 프로그램 설명: 사용자로부터 단수를 입력받아 구구단 출력
 		(1~9단은 단수*1~단수*9 출력,
		 10단 이후는 단수*1~단수*단수 출력)
*/

#include <stdio.h>

int main()
{
	int num; //사용자에게 입력받을 단수
	int i=1; 
	int j=9;
	int k=1; //i,j,k는 반복문에 사용할 변수

	printf("단수를 입력하시오: ");
	scanf("%d",&num); 

	for (i=1;i<=j;i++) //단수 반복 (i단) 
	{		
		for (k=1;k<=num;k++) //곱해지는 수 반복(i*k)
		{
			if ((num>=1)&&(num<=9)) //사용자에게 입력받은 단수가 1~9일 때
				printf("%d * %d = %d|",k,i,k*i); //1*1~단수*9  출력
			else if (num>=10) //사용자에게 입력 받은 단수가 10 이상일 때
			{
				if ((i>=10)&&(k<i)) //사용자가 입력한 단수보다 작은 단수를 곱할 때
					printf("          |"); 
				else if ((i==9)&&(k==num)) //9*9일 때
				{
					j=num; //10단 이상의 단도 출력해야 하므로 j의 값에 num을 넣어줌
					printf("%d * %d = %d|",k,i,k*i);
				}
				else
					printf("%d * %d = %d|",k,i,k*i);
			}
		}
		printf("\n");
	}

	return 0;
}
