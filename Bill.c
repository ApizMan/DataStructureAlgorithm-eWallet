#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct billing
{
    char bill[10];
    char mobileBill[20];
    char electricBill[20];
    char waterBill[20];

    struct billing *ptnext;
};

struct billing *newpt, *frontpt, *thispt, *prept;
void bill();
void billList();
void newbill();
void deletecurrbill();

int main()
{
    bill();
}

void bill(){
    int choice;
    int status=0;
    frontpt=NULL;
    do{
    billList();
    printf("\n Press 1 to add a new bill.");
    printf("\n Press 2 to delete current bill.");
    printf("\n Press 3 to quit from bill.");
    printf("\n Your choice:");
    scanf("%d",&choice);

    switch (choice){
    case 1:
        newbill();
        break;

    case 2:
        deletecurrbill();
        break;

    case 3:
        status=1;
        break;

    default:
        printf("\nPlease enter a valid choice!");
        break;
    };
    }while (status==0);
}

void newbill(){
    newpt=(struct billing *)malloc (sizeof(struct billing));
    printf("\n Please enter the bill code ex(1010):");
    scanf("%s",&newpt->bill,10);
    printf("\n Please enter new mobile bill:");
    scanf("%s",&newpt->mobileBill, 20);
    printf("\n Please enter new electricity bill:");
    scanf("%s",&newpt->electricBill, 20);
    printf("\n Please enter new water bill:");
    scanf("%s",&newpt->waterBill, 20);



    if (frontpt==NULL){
        frontpt=newpt;
        newpt->ptnext=NULL;
    }
    else{
        thispt=frontpt;

   while(thispt->ptnext !=NULL)
   {
    thispt=thispt->ptnext;
   }

    thispt->ptnext=newpt;
    newpt->ptnext=NULL;
    }
}

void billList(){
    int i=0;
    if(frontpt==NULL){
        printf("\n Empty List!");
    }
    else{
    thispt=frontpt;
    do{
    i++;
    printf("\n %d.",i);
    printf("\n Bill code: %s",thispt->bill);
    printf("\n Mobile bill: %s",thispt->mobileBill);
    printf("\n Electric Bill: %s",thispt->electricBill);
    printf("\n Water Bill: %s",thispt->waterBill);
    printf("\n");
    thispt=thispt->ptnext;
    }while(thispt!=NULL);
    }
}


void deletecurrbill(){
    char number[10];
    if(frontpt==NULL){
        printf("\n Empty List!");
    }

    else{
        printf("\n Please enter the bill code to be delete:");
        scanf("%s",&number);

        thispt=frontpt;

        do{
            if (strcmp(thispt->bill,number)==0){
                break;
            }
            else{
                prept=thispt;
                thispt=thispt->ptnext;
            }
        }while(thispt->ptnext!=NULL);

        if (strcmp(thispt->bill,number)!=0)
        {
            printf("\n The bill code is not inside the list, please try again later.");
        }
        else{
            if (thispt==frontpt){
                frontpt=thispt->ptnext;
                free(thispt);
            }
            else{
                prept->ptnext=thispt->ptnext;
                free(thispt);
            }
            printf("\n The bill has been delete!");
        }

    }
}
