/*
 프로그램 작성일: 2020-05-01
 프로그램 설명: 사용자에게 시간을 입력 받은 후 그 시간보다 45분 앞서는 시간 출력, 시간의 범위가 잘못되었을 경우 잘못되었다는 메시지 출력
*/

#include <stdio.h>

int main()
{
	int h=0, m=0; //시간, 분 변수 선언

	printf("몇 시, 몇 분에 일어나길 원하십니까?\n");
	scanf("%d %d",&h,&m); //사용자에게 시간과 분을 입력받음

	if ((h>23) || (h<0)) //시의 잘못된 범위
		printf("시를 잘못 입력하셨습니다. 시는 0~23 사이에 있어야 합니다.\n");
	if ((m>59) || (m<0)) //분의 잘못된 범위
		printf("분을 잘못 입력하셨습니다. 분은 0~59 사이에 있어야 합니다.\n");
	if ((h>=0)&&(h<=23)&&(m>=0)&&(m<=59)) 
       	{
		if (m>=45) //분이 45분과 59분 사이일 경우
		       	printf("%d %d\n",h,m-45);
		else //분이 0분과 44분 사이일 경우
	       	{
			if (h!=0) //0시가 아닐 경우
			       	printf("%d %d\n",h-1,60+m-45);
			else //0시일 경우
			       	printf("%d %d\n",24+h-1,60+m-45);
		}
	}

	return 0;
}
