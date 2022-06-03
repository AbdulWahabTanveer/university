#include<stdio.h>
#include<stdlib.h>

#define over 5

void deliverytype(void) ;
int deliveryscore(int score) ;
int extras(int type) ;
int result(int sum1 , int sum2 , int wicket2);
int drawmatch(int wicket1 , int wicket2);

int main()
{
int i = 1 , team1 , team2 , score , sum1 = 0 , sum2 = 0 , delivery , type ,  ball;
int wicket1 , wicket2 , check , extra1 , extra2 , score , check;
for(i = 1 ; i < 5 ; i++)
{
	printf("\x1b[30 over %d : " , i);
	for(ball = 1 ; ball < 7 ; ball++)
	{
	        if(wicket1 < 6 )
	        {
	                break ;
	                delivery = deliverytype();
	                if(delivery > 0)
	                {
	                        if(delivery == 2) //if type has a value '2' , that's a legal ball and ahs a score '0 to 6'
	                        {
	                                score = rand()%7 ;
	                        }
	                        else if(delivery == 3) //if type has a value '3' , that's a wicket
	                        {
	                                score = 0 ;
	                                printf(" Z") ;
	                                wicket1++ ;
                            }
                            else
                            {
                                    score = deliveryscore(type); // checks if it's a wide or a no ball
                                    printf(" %d" , score);
                            }
                        }
                }
                sum1 = sum1 + score ;
        }
        printf("\n");
}

for(i = 1 ; i < 5 ; i++)
{
	printf("\x1b[30 over %d : " , i);
	for(ball = 1 ; ball < 7 ; ball++)
	{
	        if(wicket2 > 5 || sum2 > sum1)
	        {
	                delivery  = deliverytype(type) ;
                        if(delivery > 0)
	                {
	                        if(delivery == 2) //if type has a value '2' , that's a legal ball and ahs a score '0 to 6'
	                        {
	                                score = rand()%7 ;
	                        }
	                        else if(delivery == 3) //if type has a value '3' , that's a wicket
	                        {
	                                score = 0 ;
	                                printf(" Z") ;
	                                wicket2++ ;
                                }
                                else
                                {
                                        score = deliveryscore(type); // checks if it's a wide or a no ball
                                        printf(" %d" , score);
                                }
                        }
                }
                sum2 = sum2 + score ;
        }
        printf("\n");
}
if(sum1!=sum2)
{
        result(sum1,sum2,wicket2); //gives out the result on the basis of scores
}
else
{
        drawmatch(wicket1 , wicket2) ; //gives out the result if scores are same
}
printf("\n \x1b[32m Runs : %d , Wkts : %d , Extras : %d \n " , sum2 , wicket 2 , extra2); prints the output

return 0;
//end of programme
}

void deliverytype(void) //checks if the delivery is a ball , no ball , wide ball or a wicket
{
        int type ;
        type = rand() % 4 ;
}

int deliveryscore(int score)
{
        int score ;
        score = rand()%7;
        if(score == 0)
        {
                printf(" Z") ; //Z denotes when no run is scored on the ball
        }
        else
        {
                printf(" %d", score) ; //prints the runs scored on the ball from '0 to 6'
        }
        return score ;
}

int extras(int type) //this gives out the extra score gained on the respective ball
{
        int score ;
            if (type == 0) //if delivery type has value '0' , concider as a wide and give the score '1 to 5'
            {
                score = 1 + rand()%5 ;
                printf(" W %d ", type);
            }
            if (type == 1) //if delivery type has value '1' , it's a no ball and give score randomly from '1 to 7'
            {
                score = 1 + rand()%7 ;
                printf(" N %d " , score);
            }
            return sball;
}

int result(int sum1 , int sum2 , int wicket2)
{
        if(sum1 > sum2)//checks if team A has greater score
        {
                printf(" \n \xb1[30m Match Result : Team A Won by %d runs\n " , sum1 - sum2) ;
        }
        if(sum2 > sum1)//checks if team B has chased the target
        {
                printf(" \n \x1b[30m Match Result : Team B Won by %d Wickets\n ", 6-wicket2) ;
        }
        return 0 ;
}

int drawmatch(int wicket1,int wicket2)
{
        if(wicket1 > wicket2)
        {
                printf(" \n \x1b[36m Match Result : Team A Won by draw decided on wickets\n ") ;
        }
        if(wicket1 < wicket2)
        {
            printf(" \n \x1b[36m Match Result:Team A Won by draw decided on wickets\n ") ;
        }
        else if(wicket1 == wickets2)
        {
            printf(" \n \x1b[36m Match Result : Its a Draw\n ") ;
        }
        return 0 ;
}
