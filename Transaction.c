#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void history();
void list_donate();
void list_bill();
void search_date();

struct trans
{
	int bill;
	int donate;
	int date;
	struct trans *ptrnext;
};

struct trans *headptr, *newptr, *currentptr, *previousptr;

int main()
{
    donate();
}

void donate()
{
	char ch;
	int status=0;
	headptr=NULL;
    do
	{
		printf("\n 1 My list bill: ");
		printf("\n 2 My list donation: ");
		printf("\n 3 Exit");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);

		switch(ch)
		{
		case '1': list_donate();
		break;
		case '2': list_bill();
		break;
		case '3': status=1;
		break;

		default:
		    printf("\nPlease enter valid choice!");
		}
	}while(status=0);
 return 0;
}

void list_donate()
{
  if (headptr==NULL)
	{
		printf("\nEmpty list");
		return;
	}
    else
    {
        printf("\nList Donation\n");
	    currentptr=headptr;

	    do
        {
		printf("\n\n%d",currentptr->donate);
		printf("\n");

		currentptr=currentptr->ptrnext;
	    }

	    while(currentptr !=NULL);

	    printf("\nEnd of list!\n\n");
    }

}

void list_bill()
{
	if (headptr==NULL)
	{
		printf("\nEmpty list");
		return;
	}
    else
    {
        printf("\nList Bill\n");
	    currentptr=headptr;

	    do
        {
		printf("\n\n%d",currentptr->bill);
		printf("\n");

		currentptr=currentptr->ptrnext;
	    }

	    while(currentptr !=NULL);

	    printf("\nEnd of list!\n\n");
    }
}

void search_date();

int searchDate()
{
    if (headptr=NULL)
    {
	printf("\nThe list is empty!\n");
    }
    else
    {
        printf("\nSearch date: ");
        scanf("%d",&searchDate);

        currentptr=headptr;
        while(currentptr->ptrnext!=NULL);
        {
            if (currentptr->date == searchDate)
            {
                printf("\nDate: %d ",searchDate);
                printf("\nList Bill");
                return;
            }
            else
            {
                printf("\nSorry, no match found\n");
            }
        }
    }
}
