#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int main_exit;
void menu();
struct {

    char name[60];
    int acc_no;
    float amt;

    }add,upd,check,rem,transaction;

void fordelay(int j)
{   int i;
    for(i=0;i<j;i++);
}
void new_acc()
{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");  //append records data in file
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %f \n",&add.acc_no,add.name,&add.amt)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
                printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the amount to deposit:Rs");
    scanf("%f",&add.amt);
        fprintf(ptr,"%d %s %f \n",add.acc_no,add.name,add.amt);

    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:                               //declared so the compiler comes here
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");           //clears the current screen
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;                 // compiler goes to add_invalid:
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");   //read mode
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\n");

    while(fscanf(view,"%d %s %f ",&add.acc_no,add.name,&add.amt)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t",add.acc_no,add.name);
           test++;                               //similar to counter
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);                                            //structure_member.variable
    while (fscanf(old,"%d %s  %s %f",&add.acc_no,add.name,&add.amt)!=EOF)             //loop for old condition
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rs ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"\nAccount No.:%d\nName:%s\nAmount deposited:Rs%.2f \n\n",add.acc_no,add.name,add.amt);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:Rs ");
                    scanf("%f",&transaction.amt);
                    if(transaction.amt<=add.amt)
                {
                    add.amt-=transaction.amt;
                    fprintf(newrec,"\nAccount No.:%d\nName:%s\nAmount withdrawed:Rs%.2f \n\n",add.acc_no,add.name,add.amt);
                    printf("\n\nWithdrawn successfully!");
                }
                }   goto after_withdraw;
            }
            else
            {      //after_withdraw:
                  fprintf(newrec,"\nAccount No.:%d\nName:%s\nAmount:Rs%.2f \n\n",add.acc_no,add.name,add.amt);
            }
   }
   after_withdraw:
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)              //if comp goes inside abv func test=1
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}

void menu(void)
{   int choice;
    system("cls");
    system("color 9");           //color lightblue
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.For transactions\n\t\t3.Check the details of existing account\n\t\t4.Removing existing account\n\t\t5.View customer's list\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:transact();
        break;
        case 3:see();
        break;
        case 4:erase();
        break;
        case 5:view_list();
        break;
        case 6:close();
        break;
    }
}
void close(void)
{
}
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

         while(fscanf(ptr,"%d %s %f \n",&add.acc_no,add.name,&add.amt)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nAmount deposited:Rs %.2f \n\n",add.acc_no,add.name,add.amt);
            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s  %s %f",&add.acc_no,add.name,&add.amt)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)             //strcmpi()-case insensitive
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s\nAmount deposited:Rs%.2f \n\n",add.acc_no,add.name,add.amt);
            }
        }
    }

    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }
        else
           {
             system("cls");
            close();
            }
}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s  %s %f",&add.acc_no,add.name,&add.amt)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"\nAccount No.:%d\nName:%s\nAmount deposited:Rs%.2f \n\n",add.acc_no,add.name,add.amt);
        else
            {test++;
            printf("\nRecord deleted successfully!\n");

            }//test++;
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}
int main()
{
    char pass[10],password[10]="admin123";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);           //delay the function by some time
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
//password: admin123
