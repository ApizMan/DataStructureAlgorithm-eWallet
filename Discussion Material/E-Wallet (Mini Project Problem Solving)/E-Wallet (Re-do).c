#include <stdio.h>
#include <string.h>
#include <conio.h>

int main (void)
{
    int internet_status;
    int member_status;
    int thumbprint_set;
    char email2[50];
    char password2[50];
    int age;
    char email1[50];
    char password1[50];
    int bank_account;
    char bank_holder_firstname[20];
    char bank_holder_lastname[20];
    char bank_branch[50];
    int payment_method;
    double  amount_topup = 0.0;
    double account_balance = 0.0;
    char username1[50];
    char password3[50];
    int confirmation;
    int total_balance;
    int destination;
    int counter = 1;
    double payment = 0.00;
    double net_balance = 0.00;
    int exit;


    printf("Loading... \n");
    printf("Are you have connect with internet? \n");
    printf("1. Yes \n");
    printf("2. No \n");
    printf("Selection: ");
    scanf("%d", &internet_status);
    printf("\n");

    if(internet_status == 1) /* if the user does have internet connection. */
    {
        printf("You are connected. Please wait a moment.. \n");
        printf("Already Sign Up? \n");
        printf("1. Yes \n");
        printf("2. No \n");
        printf("Selection: ");
        scanf("%d", &member_status);
        printf("\n");

        if(member_status == 1)
        {
            printf("You're Login.. \n");
            printf("Please key in your thumbprint \n");
            printf("1. Yes \n");
            printf("2. No \n");
            printf("Selection: ");
            scanf("%d", &thumbprint_set);
            printf("\n");

            if(thumbprint_set == 1)
            {
                printf("Login Successful!. Please Wait..");
            }
            else
            {
                printf("Please Enter email:");
                scanf("%s", &email1);

                printf("\nPlease enter password:");
                scanf("%s", &password1);

                do
                {
                    printf("Wrong email or password try again!\n");

                    printf("\nPlease Enter email:");
                    scanf("%s", &email1);

                    printf("\nPlease enter password:");
                    scanf("%s", &password1);
                }
                while (strcmp(email1, "ismail@gmail.com") != 0 && strcmp(password1, "ism@il123") != 0);
                printf("Login Successful!.");
            }
        }
        else
        {
            printf("Sign Up Form: ");
            printf("\nEmail: ");
            scanf("%s", &email2);
            printf("\nPassword: ");
            scanf("%s", &password2);
            printf("\nAge: ");
            scanf("%d", &age);

            if(age >= 18)
            {
                printf("Bank Detail: \n");
                printf("Bank Account: ");
                scanf("%d", &bank_account);
                printf("Bank Holder: ");
                scanf("%s %s", &bank_holder_firstname, &bank_holder_lastname);
                printf("Bank Branch: ");
                fgets(bank_branch, 50, stdin);
            }
            else
            {
                printf("You are under age.");
            }
        }
        do
        {
            do
            {
                printf("Homepage, icon, account_balance, payment_method \n");
                printf("1. Cash \n");
                printf("2. Bank Transfer \n");
                printf("Selection: ");
                scanf("%d", &payment_method);
                printf("\n");

                    if(payment_method == 1) /* Cash */
                    {
                        do
                        {
                            printf("Enter Amount(min RM5): ");
                            scanf("%lf", &amount_topup);
                            if(amount_topup >=5)
                            {
                                account_balance = account_balance + amount_topup;
                                printf("Your Wallet Successful Top Up \n");
                                printf("Notification Payment: Dear customer, you have made payment to your account total RM %lf . ", amount_topup);
                                printf("The current change in your account is RM %lf . ", account_balance);
                                printf("Thank you for using our E-Wallet.");
                            }
                            else
                            {
                                printf("You must top up more than RM 4.99 \n");
                            }
                        }while(amount_topup < 5);
                    }
                    else /* Bank Transfer */
                    {
                        do
                        {
                        printf("Enter Amount(min RM5): ");
                        scanf("%lf", &amount_topup);

                        if(amount_topup >= 5)
                        {
                            printf("Bank Login Form: ");

                            printf("\nPlease Enter username:");
                            scanf("%s", &username1);

                            printf("\nPlease enter password:");
                            scanf("%s", &password3);
                            do
                            {
                                printf("Wrong username or password try again!\n");

                                printf("\nPlease Enter username:");
                                scanf("%s", &username1);

                                printf("\nPlease enter password:");
                                scanf("%s", &password3);
                            }
                            while(strcmp(username1, "ismail123") != 0 && strcmp(password3, "ism@il123") != 0);
                            printf("Login Successful! \n");

                            account_balance = account_balance + amount_topup;
                            printf("Receipt: \n");
                            printf("Amount Top Up: RM %lf \n", amount_topup);
                            printf("Total Balance: RM %lf \n", account_balance);
                            printf("Series number: 000111222333 \n");
                            printf("Bank Holder: Ismail \n");

                            printf("Are you confirm for this payment? \n");
                            printf("1. Yes \n");
                            printf("2. No \n");
                            printf("Selection: ");
                            scanf("%d", &confirmation);
                            printf("\n");

                            if(confirmation == 1)
                            {
                                printf("Receipt: \n");
                                printf("Amount Top Up: RM %lf \n", amount_topup);
                                printf("Total Balance: RM %lf \n", account_balance);
                                printf("Series number: 000111222333 \n");
                                printf("Bank Holder: Ismail \n");
                            }
                            else
                            {
                                printf("Your Transfer Unsuccessful, Please Try Again. \n");
                            }
                        }
                        else
                        {
                            printf ("Your Top Up must be more than RM 4.99 \n");
                        }
                        }while (amount_topup < 5);
                    }
                printf ("QR Scan \n");
                printf ("Please enter your QR Code here, please \n");
                printf (" -            -\n");
                printf ("|              |\n");
                printf("\n");
                printf("       + \n");
                printf("\n");
                printf("|              |\n");
                printf(" -            - \n");

                if(account_balance >= 10)
                {
                    printf("Thank You. Enjoy Your Ride!. \n");
                    printf("Please Enter Your Destination: \n");
                    printf("1. Sri Raya \n");
                    printf("2. Taman Pertama \n");
                    printf("3. Bandar Utama \n");
                    printf("4. Kampung Selamat \n");
                    printf("5. Sungai Buloh \n");
                    printf("Selection: ");
                    scanf("%d", &destination);
                    printf("\n");
                    do
                    {
                        payment = payment + 2;
                        counter = counter +1;
                    }
                    while(counter <= destination);
                    printf ("QR Scan \n");
                    printf ("Please enter your QR Code here, please \n");
                    printf (" -            -\n");
                    printf ("|              |\n");
                    printf("\n");
                    printf("       + \n");
                    printf("\n");
                    printf("|              |\n");
                    printf(" -            - \n");
                    printf("\n");
                    net_balance = account_balance - payment;
                    printf("Thank You. Please, come again!. \n");
                    printf("\nNotification: Dear customer, RM %lf is deducted from your E-Wallet. \n", payment);
                    printf("Your total balance in your account is RM %lf . \n", net_balance);
                    printf("Thank you for using our E-Wallet.");

                }
                else
                {
                    printf("Sorry, not enough change. Please Top Up.");
                }
            }
            while(account_balance < 10);
        printf("\nExit Icon: \n");
        printf("We will miss you. Are you sure? \n");
        printf("1. Yes \n");
        printf("2. No \n");
        printf("Selection: ");
        scanf("%d", &exit);
        printf("\n");
        }
        while(exit == 2);
        printf("App Closing...");
    }
    else /* if the user doesn't have internet connection. */
    {
        printf("Please check your connection.");
    }
}
