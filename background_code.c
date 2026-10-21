#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
    int sl;
};

struct node * create(struct node *head,struct node **tail)
{
    struct node *temp = NULL;
    for(int i=0;i<100;i++)
    {
        if(head==NULL)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->data = (i+1);
            head->next = NULL;
            head->prev = NULL;
            temp = head;
            *tail = head;
        }
        else
        {
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp->next->data = (i+1);
            temp->next->prev = temp;
            temp = temp->next;
            temp->next = NULL;
        }
    }
    *tail = temp;
    return(head);
}

void sandl(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        if((temp->data) == 2)
        {
            temp->sl = 21;
        }
        else if(temp->data == 7)
        {
            temp->sl = 22;
        }
        else if(temp->data == 22)
        {
            temp->sl = 19;
        }
        else if(temp->data == 27)
        {
            temp->sl = -21;
        }
        else if(temp->data == 28)
        {
            temp->sl = 49;
        }
        else if(temp->data == 30)
        {
            temp->sl = 2;
        }
        else if(temp->data == 35)
        {
            temp->sl = -30;
        }
        else if(temp->data == 39)
        {
            temp->sl = -36;
        }
        else if(temp->data == 44)
        {
            temp->sl = 14;
        }
        else if(temp->data == 50)
        {
            temp->sl = -16;
        }
        else if(temp->data == 54)
        {
            temp->sl = 15;
        }
        else if(temp->data == 59)
        {
            temp->sl = -13;
        }
        else if(temp->data == 66)
        {
            temp->sl = -42;
        }
        else if(temp->data == 70)
        {
            temp->sl = 20;
        }
        else if(temp->data == 73)
        {
            temp->sl = -61;
        }
        else if(temp->data == 76)
        {
            temp->sl = -13;
        }
        else if(temp->data == 80)
        {
            temp->sl = 3;
        }
        else if(temp->data == 87)
        {
            temp->sl = 6;
        }
        else if(temp->data == 89)
        {
            temp->sl = -22;
        }
        else if(temp->data == 97)
        {
            temp->sl = -11;
        }
        else if(temp->data == 99)
        {
            temp->sl = -70;
        }
        else
        {
            temp->sl = 0;
        }
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *player1,*player2;
    head = create(head,&tail);
    sandl(head);
    player1 = NULL;
    player2 = NULL;
    srand(time(NULL));
    int turn = 1;

    while(1)
    {
        if(turn == 1 && player1 == NULL)
        {
            printf("\n\nPlayer 1's turn : \n");
            printf("Current Place : 0\n");
            printf("Get 0 to Start the Game\n");
            int dice1 = (rand()%6);
            dice1++;
            printf("Dice : %d\n",dice1);
            if(dice1 == 1)
            {
                player1 = head;
                printf("Current Place : 1\n\n");
            }
            turn = 2;
        }

        else if(turn == 1 && player1 != NULL)
        {
            printf("\n\nPlayer 1's turn : \n");
            printf("Current Place : %d\n",player1->data);
            int dice1 = (rand()%6);
            dice1++;
            printf("Dice : %d\n",dice1);
            if(player1->data + dice1 <=100)
            {
                for(int i=1;i<=dice1;i++)
                {
                    player1 = player1->next;
                }
            }
            if((player1->sl) != 0)
            {
                if((player1->sl) > 0)
                {
                    printf("LADDER\n");
                    int a = player1->sl;
                    for(int i=1;i<=a;i++)
                    {
                        player1 = player1->next;
                    }
                }
                else if((player1->sl) < 0)
                {
                    printf("SNAKE\n");
                    int b = player1->sl;
                    for(int i=b;i<=-1;i++)
                    {
                        player1 = player1->prev;
                    }
                }
                else if((player1->sl == 0))
                {
                    player1 = player1;
                }
            }
            printf("Current Place : %d\n",player1->data);
            if(player1->data == 100)
            {
                printf("\nPlayer1 has WON THE GAME!\n");
                break;
            }
            turn = 2;
        }

        else if(turn == 2 && player2 == NULL)
        {
            printf("\n\nPlayer 2's turn : \n");
            printf("Current Place : 0\n");
            printf("Get 0 to Start the Game\n");
            int dice1 = (rand()%6);
            dice1++;
            printf("Dice : %d\n",dice1);
            if(dice1 == 1)
            {
                player2 = head;
                printf("Current Place : 1\n\n");
            }
            turn = 1;
        }

        else if(turn == 2 && player2 != NULL)
        {
            printf("\n\nPlayer 2's turn : \n");
            printf("Current Place : %d\n",player2->data);
            int dice2 = (rand()%6);
            dice2++;
            printf("Dice : %d\n",dice2);
            if(player2->data + dice2 <=100)
            {
                for(int i=1;i<=dice2;i++)
                {
                    player2 = player2->next;
                }
            }
            if((player2->sl) != 0)
            {
                if((player2->sl) > 0)
                {
                    printf("LADDER\n");
                    int a = player2->sl;
                    for(int i=1;i<=a;i++)
                    {
                        player2 = player2->next;
                    }
                }
                else if((player2->sl) < 0)
                {
                    printf("SNAKE\n");
                    int b = player2->sl;
                    for(int i=b;i<=-1;i++)
                    {
                        player2 = player2->prev;
                    }
                }
                else if((player2->sl == 0))
                {
                    player2 = player2;
                }
            }
            printf("Current Place : %d\n",player2->data);
            if(player2->data == 100)
            {
                printf("\nPlayer2 has WON THE GAME!\n");
                break;
            }
            turn = 1;
        }
    }
    return 0;
}
