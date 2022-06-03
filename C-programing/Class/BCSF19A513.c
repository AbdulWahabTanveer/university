#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define over 10
//Sets Max overs

#define color 35
//Range(31-36)

#define players 7
//note that useable players are size-1 so 7 players means 6 wickets
//Sets Number of Players


int legalfn(void);
//To decide between legal(wicket or runs) and no ball or wide delivery

int score(void);
//To return score at a legal delivery

int freebies(int legal);
//To return score at no ball or wide
//Printing of score at each ball is also done in functions

void result(int sum,int sum1,int wickets2);
//Returns result of The Match

void resultwickets(int wickets1,int wickets2);
//Returns result when Scores are Level



int main(){

    int i,sum1,sum2,wickets1,wickets2,extra1,extra2;
    int ball,legal,sball,state=2;

    do{
        sum1=0,sum2=0,wickets1=0,wickets2=0,extra1=0,extra2=0,state=2;
        //Sets all variables for Use

        srand(time(0));
        //sets new seed for random numbers

        printf("\x1b[%dm",color);
        //Agains sets the desired color for overs tables

        for(i=1;i<=over;i++){
        //runs once for a single over

            printf("Over%d:",i);
            //prints starter for over line

            for(ball=1;ball<=6;ball++){
            //simulates each ball of an over

                    if(players-1==wickets1)
                        break;
                    //A check for all players out

                    legal=legalfn();
                    //Decides the ball
                    //(1 for out 2 for legal,0 for wide,-1 for no ball)

                    if (legal>0){
                        if(legal==2)
                            sball=score();//(0-6)print
                        else{
                            sball=0;
                            printf(" O");
                            wickets1++;
                        }
                    }
                    //sball in all is the current ball score
                    else{
                        ball--;
                        //in case of no ball or wide the ball is
                        //not considered

                        sball=freebies(legal);//1-6
                        extra1=extra1+sball;
                        //and the score is also added to extra1 to calculate extras
                    }
                    sum1 = sum1+sball;
                    //adds the score of each ball in sum1
                    //Inner loop ends
                }

                printf("\n");
        }

        printf("\n\x1b[0mRuns:%d , Wkts:%d , Extras:%d\n\n",sum1,wickets1,extra1);
        //prints the overall stats after 1st innings
        //Also resets the color to default for printing this line

        printf("\x1b[%dm",color);
        //Agains sets the desired color for overs tables

        for(i=1;i<=over;i++){
        //runs once for a single over

            printf("Over%d:",i);
            //prints starter for over line

            for(ball=1;ball<=6;ball++){
            //simulates each ball of an over

                    if(players-1==wickets2 || sum2>sum1)
                        break;
                    //A check to see all out OR Target reached conditions

                    legal=legalfn();
                    //Decides the ball
                    //(1 for out 2 for legal,0 for wide,-1 for no ball)

                    if (legal>0){
                        if(legal>1)
                        sball=score();
                        //sball in all is the current ball score
                        else{
                            sball=0;
                            printf(" O");
                            wickets2++;
                        }
                    }
                    else{
                        ball--;
                        //in case of no ball or wide the ball is
                        //not considered

                        sball=freebies(legal);
                        extra2=extra2+sball;
                        //and the score is also added to extra2 to calculate extras
                    }
                    sum2 = sum2+sball;
                    //adds the score of each ball in sum2
                    //Inner loop ends
                }

                printf("\n");
            }

        printf("\n\x1b[0mRuns:%d , Wkts:%d , Extras:%d\n",sum2,wickets2,extra2);
        //prints the overall stats after 2nd innings

        printf("\x1b[32m");
        //Changes color to green for result line


        if(sum1!=sum2)
            result(sum1,sum2,wickets2);
            //Decides based on runs
        else
            resultwickets(wickets1,wickets2);
            //Decides based on wickets

        printf("\x1b[0m");
        //Resets color to default

        printf("\nEnter 1 to repeat or 2 to Terminate:");
        scanf("%d",&state);

        //if(state!=1 || state!=2)
            //break;
        //for any worst case ;)

        printf("\n");

    }while(state==1);
    //Repeatition loop terminates here.

    printf("\x1b[32m\n\nThanks for playing Cricket simulator!\nI will see you next time Insha Allah");
    printf("\nAllah Hafiz\n\x1b[0m");
    //prints ending statement in green and resets color to default
    return 0;
}




int legalfn(void){
            int tb=(rand()%(22));
            int legal=2;
            //variable reset or legal delivery

            if(tb==12)
            //symbolizes Wicket(Increased probability by OR)
                legal=1;

            if(tb==4)
            //symbolizes Wide
                legal=0;

            if(tb==14)
            //symbolizes No Ball
                legal=-1;

            return legal;
}


int score(void){

            int sb;
            //A variable to generate random numbers
            //used as scores at a legal delivery

            sb=rand()%7;//0-6
            if(sb==0)
            //show Z instead of 0(Zero)
                printf(" Z");
            else
            //otherwise prints unchanged score
                printf(" %d",sb);

            return sb;
}


int freebies(int legal){
            int sball;
            //Sball Gives the score

            if (legal==0){
                sball=((rand()%5)+1);
                //At wide the score is between 1-5
                printf(" W%d",sball);

            }

            if (legal==-1){
                sball=((rand()%7)+1);
                //At No ball the score is between 1-7
                printf(" N%d",sball);

            }
            return sball;
}


void result(int sum1,int sum2,int wickets2){

    if(sum1>sum2)
    //If team A score is greator
        printf(" \nMatch Result:Team A Won by %d runs\n",sum1-sum2);

    if(sum2>sum1)
    //If team B score is greator
        printf(" \nMatch Result:Team B Won by %d Wickets\n",players-1-wickets2);
}


void resultwickets(int wickets1,int wickets2){

    if(wickets1>wickets2)
    //If team A lose less wickets
        printf(" \nMatch Result:Team B Won by draw decided on wickets\n");

    else if(wickets2>wickets1)
    //If team B lose less wickets
        printf(" \nMatch Result:Team A Won by draw decided on wickets\n");

    else if(wickets2==wickets1)
    //If wickets are equal and socres are equal its a draw
        printf(" \nMatch Result:Its a Draw\n");

}
