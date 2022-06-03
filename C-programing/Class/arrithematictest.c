#include<stdio.h>
#include<stdlib.h>

void main()
{
int level_no , num1[10] , num2[10] , i = 0 , j = 0 , user_ans[10] , sys_ans[10] , k = 0 , l = 0 , check , opp = 0 , count = 0 , rep ;
char arop[10] , select ;

point_0 :
do
{
//here we get the level number
printf("\x1b[36m Enter Level Number(1-5): ");
scanf("%d",&level_no);

if(level_no == 1)
{
	for(i = 0 ; i < 10 ; i++)
	{
		num1[i] = 1 + rand()%10 ;
	}
	for(j = 0 ; j < 10 ; j++)
	{
		point_1 :
		check = 1 + rand()%10 ;
		if(check < num1[j])
			num2[j] = check ;
		else
			goto point_1 ;
	}
}

else if(level_no == 2)
{
	for(i = 0 ; i < 10 ; i++)
	{
		num1[i] = 1 + rand()%50 ;
	}
	for(j = 0 ; j < 10 ; j++)
	{
		point_2 :
		check = 1 + rand()%50 ;
		if(check < num1[j])
			num2[j] = check ;
		else
			goto point_2 ;
	}
}

else if(level_no == 3)
{
	for(i = 0 ; i < 10 ; i++)
	{
		num1[i] = 1 + rand()%100 ;
	}
	for(j = 0 ; j < 10 ; j++)
	{
		point_3 :
		check = 1 + rand()%100 ;
		if(check < num1[j])
			num2[j] = check ;
		else
			goto point_3 ;
	}
}

else if(level_no == 4)
{
	for(i = 0 ; i < 10 ; i++)
	{
		num1[i] = 1 + rand()%500 ;
	}
	for(j = 0 ; j < 10 ; j++)
	{
		point_4 :
		check = 1 + rand()%500 ;
		if(check < num1[j])
			num2[j] = check ;
		else
			goto point_4 ;
	}
}

else if(level_no == 5)
{
	for(i = 0 ; i < 10 ; i++)
	{
		num1[i] = 1 + rand()%1000 ;
	}
	for(j = 0 ; j < 10 ; j++)
	{
		point_5 :
		check = 1 + rand()%1000 ;
		if(check < num1[j])
			num2[j] = check ;
		else
			goto point_5 ;
	}
}

//if level number input is out of range
else
{
	printf("\x1b[35m Invalid Choice\n");
	goto point_0 ;
}

//generating random operators
for(i = 0 ; i < 10 ; i++)
{
	opp = rand()%2;
	if(opp == 0)
	{
		arop[i] = '+' ;
	}
	else if(opp == 1)
	{
		arop[i] = '-' ;
	}
	printf("\n\x1b[34m %d %c %d",num1[i],arop[i],num2[i]);
	for(k = 0 ; k < 10 ; k++)
	{
		if(arop[k] == '+')
		{
			sys_ans[k] = num1[k] + num2[k];
		}
		else if(arop[k] == '-')
		{
			sys_ans[k] = num1[k] - num2[k];
		}
	}
}

//taking answers from the users
printf("\n\x1b[33m Enter Your Answers\n");
for(l = 0 ; l < 10 ; l++)
{
	scanf("%d",&user_ans[l]);
}

//printing the problems alongwith actual answers and user answers
printf("\t\t      Answers\tYour Answers\n");
for(i = 0 ; i < 10 ; i++)
{	
	printf("\n\x1b[33m %d   %c   %d \t= \t%d\t\t%d \n",num1[i],arop[i],num2[i],sys_ans[i],user_ans[i]);
}

//checking how many answers are correct and giving the result
for(i = 0 ; i < 10 ; i++)
{
	if(sys_ans[i] != user_ans[i])
	{	
	count++;
	}
}
printf("\n\x1b[32m Correct Answers: %d",10-count);
printf("\n\x1b[31m Incorrect Answers: %d",count);

//repeating the programme on user demand
point_rep :
printf("\n\x1b[36m Press 1 to repeat the practice and 0 to quit:  ");
scanf("%d",&rep);

if(rep > 1 || rep < 0)
{
	printf("\n\x1b[28m Invalid Choice");
	goto point_rep ;
}
}while(rep == 1);
if(rep == 0)
	printf("\n\x1b[28m THANKS FOR USING THE PROGRAMME\n");
//end of programme
}	
