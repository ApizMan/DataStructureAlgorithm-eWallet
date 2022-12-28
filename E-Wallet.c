#include <conio.h>
#include <stdio.h>  //stdio. h is the header file for standard input and output.
#include <stdlib.h> // includes functions involving memory allocation, process control, conversions and others.
#include <string.h>

#define TRUE 1
#define FALSE 0

// Nafiz
struct other_bank {
  char name[50];
  int card_bank_number;
  char holder[50];
};

// Nafiz
struct profile_signup {
  int bank_account;
  char bank_holder[50];
  int bank_branch;

  struct other_bank details;
};

// Nafiz
struct log_in {
  int member_status;
  char name[50];
  char email_login[20];
  char password_log_in[20];
};

// Nafiz
struct sign_up {
  char name[50];
  char email_signup[20];
  char pass_signup[20];
  char address[100];
  int age;

  struct profile_signup profile_details;
};

// Nafiz
struct internet {
  int internet_status;
  struct log_in lg_in_details;
  struct sign_up sg_up_details;
};

//Athirah
struct billing
{
    char bill[10];
    char mobileBill[20];
    char electricBill[20];
    char waterBill[20];

    struct billing *ptnext;
};

//Jaslyn
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

// chow
struct bank {
  char holdername[50];
  char cardnumber[20];
  char expiredate[10];
  int CVV;
  char bankname[20];
  struct bank *next;
};

// Dania
struct trans {
  int bill;
  int donate;
  int date;
  struct trans *ptrnext;
};

//Athirah
struct billing *newpt, *frontpt, *thispt, *prept;
void bill();
void billList();
void newbill();
void deletecurrbill();

//Jaslyn
struct donate *hdptr, *nwptr, *currptr;
void new_donate ();
void list_donate ();
void search_donate();

// chow
struct bank *newp, *front, *thisp, *pre;
void newbank();
void banklist();
void deletebank();
void payment();
void deletefirstbank();
void editbank();

// Dania
struct trans *headptr, *newptr, *currentptr, *previousptr;
void history();
void l_donate();
void list_bill();
void search_date();

int main() {

  // Nafiz
  int choose = TRUE;
  char selection, log_out;

  struct internet checking;
  struct log_in detail = {1, "Ismail", "ismail@gmail.com", "ism@il123"};

  do {
    printf("\n");
    printf("Loading... \n");
    printf("Are you have connect with internet? \n");
    printf("1. Yes \n");
    printf("2. No \n");
    printf("Selection: ");
    scanf("%d", &checking.internet_status);
    printf("\n");

    if (checking.internet_status == 1) {
      printf("You are connected.");

      do {
        printf("Please wait a moment.. \n");
        printf("Already Sign Up? \n");
        printf("1. Yes \n");
        printf("2. No \n");
        printf("Selection: ");
        scanf("%d", &checking.lg_in_details.member_status);
        printf("\n");

        if (checking.lg_in_details.member_status == 1) { // user are member

          printf("Log-In Form:- \n");
          printf("--------------------------------\n");
          do {
            do {

              printf("\nPlease Enter email:");
              scanf("%s", &checking.lg_in_details.email_login);

              printf("\nPlease enter password:");
              scanf("%s", &checking.lg_in_details.password_log_in);

              if (strcmp(checking.lg_in_details.password_log_in, "ism@il123") ==
                  0) {
                if (strcmp(checking.lg_in_details.email_login,
                           "ismail@gmail.com") == 0) {
                  break;
                } else {
                  printf("Password/Email is Wrong!!");
                  printf("\n");
                }
              } else {
                printf("Password/Email is Wrong!!");
                printf("\n");
              }
            } while (strcmp(checking.lg_in_details.password_log_in,
                            "ism@il123") != 0);
          } while (strcmp(checking.lg_in_details.email_login,
                          "ismail@gmail.com") != 0);
          printf("Login Successful!.");
          printf("\n");
          break;
        } else { // user not a member
          printf("Sign Up Form:- \n");
          printf("--------------------------------\n");
          printf("\nFull Name:");
          fflush(stdin);
          fgets(checking.sg_up_details.name, 50, stdin);
          fflush(stdin);
          printf("\nEmail: ");
          scanf("%s", &checking.sg_up_details.email_signup);
          printf("\nPassword: ");
          scanf("%s", &checking.sg_up_details.pass_signup);
          printf("\nAddress: ");
          fflush(stdin);
          fgets(checking.sg_up_details.address, 100, stdin);
          fflush(stdin);
          printf("\nAge: ");
          scanf("%d", &checking.sg_up_details.age);
          if (checking.sg_up_details.age >= 18) {
            printf("\n");
            printf("Alright, you account have been created. You good to go.");
            printf("\n");
          } else {
            printf("You are under age. You are not eligible to create this "
                   "E-Wallet account. Sorry T_T");
            printf("\n");
          }
        }

      } while (checking.sg_up_details.age < 18);

      printf("\n");
      if (checking.lg_in_details.member_status == 1) {
        printf("\nWELDOME, %s", detail.name);
      } else {
        printf("\nWELDOME, %s", checking.sg_up_details.name);
      }
      while (choose == TRUE)

      {
        // Main Page:
        printf("\n Home Page: \n");
        printf("--------------------------------\n");
        printf("b. Pay Bill \n");
        printf("d. Donating \n");
        printf("p. Payment/Card Bank Setting \n");
        printf("t. Transaction History \n");
        printf("x: Log-Out \n");
        printf("Selection: ");
        scanf(" %c", &selection);

        switch (selection) {
        case 'b':
          // Athirah
          bill();
          break;
        case 'd':
          // Anith
          donate();
          break;
        case 'p':
          // Chow
          payment();
          break;
        case 't':
          // Dania
          transaction();
          break;
        case 'x':
          choose = FALSE;
          break;

        default:
          printf(
              "\nEnter only one from the above and only use Lowercase only.");
        }
      }

    } else if (checking.internet_status ==
               2) { // doesn't have internet connection
      printf("Please check your connection.");
      printf("\n");
    } else {
      printf("Please Enter the right input!!");
      printf("\n");
    }

  } while (checking.internet_status != 1);

  return 0;
}

//Athirah
void bill(){
    int choice;
    int status=0;
    frontpt=NULL;
    do{
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

//Athirah
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

//Athirah
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

//Athirah
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

//Jaslyn
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

//Jaslyn
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

//Jaslyn
int donate()
{
    char ch;
    int choice=TRUE;

    hdptr=NULL;
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

//Jaslyn
void new_donate()
{
    int agency;
    nwptr=(struct donate*)malloc(sizeof (struct donate));

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
  scanf("%d",&nwptr->donate);


  if(hdptr==NULL)
  {
      hdptr=nwptr;
      nwptr->ptrnext;
  }
  else
  {
      nwptr->ptrnext=hdptr;
      hdptr=nwptr;
  }
}

//Jaslyn
void list_donate()
{
    if (hdptr==(struct donate*)NULL)
    {
        printf("\nEmpty list of donation\n");
        return;
    }

    currptr=hdptr;

    while(currptr !=(struct donate *)NULL)
    {
        printf("\n%d",currptr->donate);
        currptr=currptr->ptrnext;
    }
    printf("\n");
}


// chow
void payment() {
  int choice;
  int status = 0;
  front = NULL;
  do {
    banklist();
    printf("\n Press 1 to add a new bank card.");
    printf("\n Press 2 to edit a bank card.");
    printf("\n Press 3 to delete a bank card.");
    printf("\n Press 4 to delete the first bank card.");
    printf("\n Press 5 to quit from card setting.");
    printf("\n Your choice:");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      newbank();
      break;

    case 2:
      editbank();
      break;

    case 3:
      deletebank();
      break;

    case 4:
      deletefirstbank();
      break;

    case 5:
      status = 1;
      break;

    default:
      printf("\nPlease enter a valid choice!");
      break;
    };
  } while (status == 0);
}

// chow
void newbank() {
  newp = (struct bank *)malloc(sizeof(struct bank));
  printf("\n Please enter the card holder name:");
  fflush(stdin);
  fgets(newp->holdername, 50, stdin);
  printf("\n Please enter the card number (XXXXXXXXXXXXXXXX):");
  scanf("%s", &newp->cardnumber);
  printf("\n Please enter the expire date (XX/XX):");
  scanf("%s", &newp->expiredate);
  printf("\n Please enter the CVV (XXX):");
  scanf("%d", &newp->CVV);
  printf("\n Please enter the bank name:");
  fflush(stdin);
  fgets(newp->bankname, 20, stdin);

  if (front == NULL) {
    front = newp;
    newp->next = NULL;
  } else {
    thisp = front;

    while (thisp->next != NULL) {
      thisp = thisp->next;
    }

    thisp->next = newp;
    newp->next = NULL;
  }
}

// chow
void deletefirstbank() {
  thisp = front;
  if (front == NULL) {
    printf("\n Empty List!");
  } else {
    front = front->next;
    free(thisp);
  }
}

// chow
void deletebank() {
  char number[20];
  if (front == NULL) {
    printf("\n Empty List!");
  }

  else {
    printf("\n Please enter the bank card number to be delete:");
    scanf("%s", &number);

    thisp = front;

    do {
      if (strcmp(thisp->cardnumber, number) == 0) {
        break;
      } else {
        pre = thisp;
        thisp = thisp->next;
      }
    } while (thisp->next != NULL);

    if (strcmp(thisp->cardnumber, number) != 0) {
      printf(
          "\n The card number is not inside the list, please try again later.");
    } else {
      if (thisp == front) {
        front = thisp->next;
        free(thisp);
      } else {
        pre->next = thisp->next;
        free(thisp);
      }
      printf("\n The card has been delete!");
    }
  }
}

// chow
void banklist() {

  int i = 0;
  if (front == NULL) {
    printf("\n Empty List!");
  } else {
    thisp = front;
    do {
      i++;
      printf("\n %d.", i);
      printf("\n Bank name: %s", thisp->bankname);
      printf("\n Card holder name: %s", thisp->holdername);
      printf("\n Card Number: %s", thisp->cardnumber);
      printf("\n Expire Date: %s", thisp->expiredate);
      printf("\n CCV: %d", thisp->CVV);
      printf("\n");
      thisp = thisp->next;
    } while (thisp != NULL);
  }
}

//chow
void editbank() {
  int y = 0;
  do {
    deletebank();
    banklist();
    printf("\n Please enter the detail of the card:");
    newbank();
    printf("\n Exit editing? yes=1, no=2:");
    scanf("%d", &y);
  } while (y == 0);
}

// Dania
void transaction()
{
	char ch;
	int status=0;
    do
	{
		printf("\n 1 My list bill: ");
		printf("\n 2 My list donation: ");
		printf("\n 3 Search List: ");
		printf("\n 4 Exit");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);

		switch(ch)
		{
		case '1': list_bill();
		break;
		case '2': l_donate();
		break;
        case '3': search();
		break;
		case '4': status=1;
		break;

		default:
		    printf("\nPlease enter valid choice!");
		}
	}while(status=0);
 return 0;
}

// Dania
void l_donate() {
  if (hdptr == NULL) {
    printf("\nEmpty list");
    return;
  } else {
    printf("\nList Donation\n");
    currptr = hdptr;

    do {
      printf("\n\n%d", currptr->donate);
      printf("\n");

      currptr = currptr->ptrnext;
    }

    while (currptr != NULL);

    printf("\nEnd of list!\n\n");
  }
}

// Dania
void list_bill() {
    billList();
}

// Dania
void search_date();

// Dania
int search() {
  if (headptr = NULL) {
    printf("\nThe list is empty!\n");
  } else {
    printf("\nSearch no. list: ");
    scanf("%d", &search);

    currentptr = headptr;
    while (currentptr->ptrnext != NULL)
      ;
    {
      if (currentptr->date == search) {
        printf("\n no. List: %d ", search);
        printf("\nList Bill");
        return;
      } else {
        printf("\nSorry, no match found\n");
      }
    }
  }
}
