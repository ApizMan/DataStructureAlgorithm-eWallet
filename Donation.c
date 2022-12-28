#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void new_donate ();
void list_donate ();
void search_donate();

struct donate
{
    int amount;
    int agency;
    int donate;
    char name[40];
    int id;
    int acc_num;
    int *n;

    struct donate *ptrnext;


};

struct donate *headptr, *newptr, *currptr;

int main()
{
    donate();
}

void search_donation(){

  //donationagency
  struct donate *n;

  n[0].id=1;
  strcpy(n[0].name, "MERCY Malaysia");
  n[0].acc_num = 8000792908;
  n[1].id=2;
  strcpy(n[1].name, "Malaysian Relief Agency");
  n[1].acc_num = 564098206365;
  n[2].id=3;
  strcpy(n[2].name, "Yayasan Food Bank Malaysia");
  n[2].acc_num = 566010630584;
  n[3].id=4;
  strcpy(n[3].name, "Malaysia Flood Relief");
  n[3].acc_num = 21219800040683;


}

void searchDonate(){

  int agency,num,cont;
  struct donate *n;
  search_donation();
  system("cls");
  search_donation:
  printf("=============================\n");
  printf("   SEARCH AGENCY TO DONATE   \n");
  printf("=============================\n");
  printf("[1] MERCY Malaysia\n");
  printf("[2] Malaysian Relief Agency\n");
  printf("[3] Yayasan Food Bank Malaysia\n");
  printf("[4] Malaysia Flood Agency\n");
  printf("[5] BACK TO HOMEPAGE\n");
  printf("SELECT AGENCY TO SEARCH: \n");
  scanf("%d",&agency);
  system("cls");
  switch(agency)
  {
    case 1:
    agency_search:
    system("cls");
    printf("=============================\n");
    printf("        AGENCY  SEARCH       \n");
    printf("=============================\n");
    for(int i=0;i<6;i++)
    {
      printf("[%d] %s\n",i+1,n[i].name);
    }
    printf("ENTER AGENCY ID: \n");
    scanf("%d",&num);
    num=num-1;
    printf("THE AGENCY WITH ID NUMBER = %d IS \n%s\nRM%.2f\n",num+1,n[num].name,n[num].acc_num);
    printf("CONTINUE SEARCH? (1-Yes,2-No)");
    scanf("%d",&cont);
    if(cont==1){
      goto agency_search;
    }
    else
    {
      goto search_donation;
    }
    break;


    case 2: exit(0);

        break;

    }
}


int donate()
{
    char ch;
    int choice=TRUE;

    headptr=NULL;
    while (choice==TRUE)
    {
        printf("\na - Search agency to donate ");
        printf("\nl - List donations");
        printf("\nx - Exit");

        printf("\nEnter your Choice: ");
        scanf(" %c",&ch);

        switch(ch){
        case 'a' : new_donate();
        break;
        case 'l' : list_donate();
        break;
        case 'x' : choice=FALSE;
        break;
        default: printf("\nEnter only from above\n");
        }
    }
}

void new_donate()
{
    int agency;
    newptr=(struct donate*)malloc(sizeof (struct donate));

    system ("cls");

  printf("=============================\n");
  printf("       AGENCY TO DONATE      \n");
  printf("=============================\n");
  printf("[1] MERCY Malaysia\n");
  printf("[2] Malaysian Relief Agency\n");
  printf("[3] Yayasan Food Bank Malaysia\n");
  printf("[4] Malaysia Flood Agency\n");
  printf("[5] BACK TO HOMEPAGE\n");
  printf("\nSELECT AGENCY TO DONATE [1/2/3/4]: \n");
  scanf("%d",&agency);
  if (agency==1)
  {
      printf (" \nMERCY Malaysia ");
      printf (" Account Number : 8000792908 [MAYBANK] ");
  }
  else if (agency==2)
  {
      printf (" Malaysian Relief Agency ");
      printf (" Account Number : 564098206365 [MAYBANK] ");
  }
  else if (agency==3)
  {
      printf (" Yayasan Foodbank Malaysia ");
      printf (" Account Number : 566010630584 [MAYBANK] ");
  }
  else if (agency==4)
  {
      printf (" Malaysia Flood Agency ");
      printf (" Account Number :  21219800040683 [RHB BANK]");
  }
  else
  {
      printf ("\nNo agency detected");
      exit (0);
  }

  printf("\nEnter amount to donate: ");
  scanf("%d",&newptr->donate);


  if(headptr==NULL)
  {
      headptr=newptr;
      newptr->ptrnext;
  }
  else
  {
      newptr->ptrnext=headptr;
      headptr=newptr;
  }
}

void list_donate()
{
    if (headptr==(struct donate*)NULL)
    {
        printf("\nEmpty list of donation\n");
        return;
    }

    currptr=headptr;

    while(currptr !=(struct donate *)NULL)
    {
        printf("\n%d",currptr->donate);
        currptr=currptr->ptrnext;
    }
    printf("\n");
}

