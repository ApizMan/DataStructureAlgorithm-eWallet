#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bank{
    char holdername[20];
    char cardnumber[20];
    char expiredate[10];
    int CCV;
    char bankname[20];
    struct bank *next;
};

struct bank *newp, *front, *thisp, *pre;
void newbank();
void banklist();
void deletebank();
void payment();
void deletefirstbank();

int main ()
{
    payment();
}

void payment(){
    int choice;
    int status=0;
    front=NULL;
    do{
    banklist();
    printf("\n Press 1 to add a new bank card.");
    printf("\n Press 2 to delete a bank card.");
    printf("\n Press 3 to delete the first bank card.");
    printf("\n Press 4 to quit from card setting.");
    printf("\n Your choice:");
    scanf("%d",&choice);

    switch (choice){
    case 1:
        newbank();
        break;

    case 2:
        deletebank();
        break;

    case 3:
        deletefirstbank();
        break;

    case 4:
        status=1;
        break;

    default:
        printf("\nPlease enter a valid choice!");
        break;
    };
    }while (status==0);
}

void newbank(){
    newp=(struct bank *)malloc (sizeof(struct bank));
    printf("\n Please enter the card holder name:");
    fflush(stdin);
    fgets(newp->holdername, 20, stdin);
    printf("\n Please enter the card number (XXXXXXXXXXXXXXXX):");
    scanf("%s",&newp->cardnumber);
    printf("\n Please enter the expire date (XX/XX):");
    scanf("%s",&newp->expiredate);
    printf("\n Please enter the CCV (XXX):");
    scanf("%d",&newp->CCV);
    printf("\n Please enter the bank name:");
    fflush(stdin);
    fgets(newp->bankname, 20, stdin);



    if (front==NULL){
        front=newp;
        newp->next=NULL;
    }
    else{
        thisp=front;

   while(thisp->next !=NULL)
   {
    thisp=thisp->next;
   }

    thisp->next=newp;
    newp->next=NULL;
    }

}

void deletefirstbank(){
    thisp=front;
    if(front==NULL){
    printf("\n Empty List!");
    }
    else{
        front=front->next;
        free(thisp);
    }
}

void deletebank(){
    char number[20];
    if(front==NULL){
        printf("\n Empty List!");
    }

    else{
        printf("\n Please enter the bank card number to be delete:");
        scanf("%s",&number);

        thisp=front;

        do{
            if (strcmp(thisp->cardnumber,number)==0){
                break;
            }
            else{
                pre=thisp;
                thisp=thisp->next;
            }
        }while(thisp->next!=NULL);

        if (strcmp(thisp->cardnumber,number)!=0)
        {
            printf("\n The card number is not inside the list, please try again later.");
        }
        else{
            if (thisp==front){
                front=thisp->next;
                free(thisp);
            }
            else{
                pre->next=thisp->next;
                free(thisp);
            }
        }

    }
}

void banklist(){

    int i=0;
    if(front==NULL){
        printf("\n Empty List!");
    }
    else{
    thisp=front;
    do{
    i++;
    printf("\n %d.",i);
    printf("\n Bank name: %s",thisp->bankname);
    printf("\n Card holder name: %s",thisp->holdername);
    printf("\n Card Number: %s",thisp->cardnumber);
    printf("\n Expire Date: %s",thisp->expiredate);
    printf("\n CCV: %d",thisp->CCV);
    printf("\n");
    thisp=thisp->next;
    }while(thisp!=NULL);
    }

}
