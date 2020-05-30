#include<stdio.h>
#include<string.h>
#include<time.h>
#include "csvparser.h"
#include "csvparser.c"

struct data{
	int cust_id;
	char fn[20];
	char ln[20];
	char dob[13];
	char ad[150];
	char eid[30];
	char ph[10];
};

void new_acc()
{
	struct data r;
	FILE *fp;
	char a[1];
 	fp=fopen("C:\\Users\\lawda\\Desktop\\docs\\assignment.csv","a");
	printf("\t\t KINDLY ENTER CORRECT DETAILS WHEN PROMPTED. THANK YOU FOR YOUR COOPERATION.\t\t\t\t\n");
	gets(a);
	printf("\nFirst Name:");
	gets(r.fn);
	printf("\nLast Name: ");
	gets(r.ln);
	printf("\nDate of birth(dd-mm-yyyy): ");
	gets(r.dob);
	printf("\nPermanent address: ");
	gets(r.ad);
	printf("\nEmail-id: ");
	gets(r.eid);
	printf("\nContact no.: ");
	gets(r.ph);
	
	fprintf(fp, " %s, %s, %s, %s, %s, %s\n",r.fn, r.ln, r.dob, r.ad, r.eid, r.ph);
	printf("\n Congratulations!! You have been registered as a new customer.\n");
	fclose(fp);
	printf(" Press 0 to exit. Press 1 to continue.\n");
	int k;
	scanf("%d", &k);
	if(k==1)
		new_acc();
			
	
	
}

void view_acc()
{
	int flag=1;
	struct data r;
	printf("\nKindly enter your date of birth in the format dd-mm-yyyy.\n");
	scanf("%s", r.dob);
	CsvParser *csvparser = CsvParser_new("C:\\Users\\lawda\\Desktop\\docs\\assignment.csv", ",", 1);
    CsvRow *row;
	
	 while (row = CsvParser_getRow(csvparser)) 
	{
        const char **rowFields = CsvParser_getFields(row);
        if(strcmp(r.dob, rowFields[2])==0)
		{
			flag=0;
			printf("First Name: %s\n", rowFields[0]);
			printf("Last Name: %s\n", rowFields[1]);
			printf("Date of birth: %s\n", rowFields[2]);
			printf("Address: %s\n", rowFields[3]);
			printf("Email_id: %s\n", rowFields[4]);
			printf("Contact no.: %s\n", rowFields[5]);
			
		}
	
	}
	if(flag)
		{
			printf("No such account exists. Press 0 to exit. Press 1 to continue.\n");
			int k;
			scanf("%d", &k);
			if(k==1)
				view_acc();
			else if(k==0)
				choice();
				flag=0;
		}
	printf(" Press 0 to exit. Press 1 to continue.\n");
	int k;
	scanf("%d", &k);
	if(k==1)
		view_acc();
		
}
 

void pay_bill()
{
	struct data r;
	CsvParser *csvparser = CsvParser_new("C:\\Users\\lawda\\Desktop\\docs\\assignment.csv", ",", 1);
    CsvRow *row;
    printf("Kindly enter your date of birth\n");
    scanf("%s", r.dob);
	int flag=1;
	 while ((row = CsvParser_getRow(csvparser))) 
	{
        const char **rowFields = CsvParser_getFields(row);
        if(strcmp(r.dob, rowFields[2])==0)
		{
			flag=0;
			printf("Kindly enter units of electricity consumed\n");
			int units,bill;
			scanf("%d", &units);
			printf("First Name: %s\n", rowFields[0]);
			printf("Last Name: %s\n", rowFields[1]);
			printf("Date of birth: %s\n", rowFields[2]);
			printf("Address: %s\n", rowFields[3]);
			printf("Email_id: %s\n", rowFields[4]);
			printf("Contact no.: %s\n", rowFields[5]);
			if(units<=20)
				bill=3;
			else if(units>=21 && units<=30)
				bill=3+(units-20)*7;
			else if(units>=31 && units<=40)
				bill=3+(10*7)+(units-30)*8;
			else
				bill=3+(10*7)+(10*8)+(units-40)*13;
			printf("Your bill is :Rs. %d\n",bill);
		}
		
	}
		if(flag)
		{
			printf("No such account exists. Press 0 to exit. Press 1 to continue.\n");
			int k;
			scanf("%d", &k);
			if(k==1)
				pay_bill();
			else if(k==0)
				choice();
				flag=0;
		}
	printf(" Press 0 to exit. Press 1 to continue.\n");
	int k;
	scanf("%d", &k);
	if(k==1)
		pay_bill();
}

void choice()
{
	
	printf("\t\t\t\t WELCOME TO THE DEPARTMENT OF ELECTRICITY \t\t\t\n\n");
	
	
	printf("\b 1) Create new account.\n ");
	printf("\b 2) View your existing account.\n");
	printf("\b 3) Pay electricity bill. \n");
	printf("\b 4) Exit.\n");
	printf("\b 5) Tariff Plan.\n\n\n");
	
	printf("Kindly enter your choice :\n\n");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: new_acc();
		break;
		case 2: view_acc();
		break;
		case 3: pay_bill();
		break;
		case 4: 
		{
			printf("Thank your for using our services. Wish you a good day.\n\n\n");
			break;
		}
		case 5:{
			printf("\t\t\t\t\t TARIFF PLAN\n\n\n");
			printf("\t\tUpto 20 units.......................................... Rs. 3/unit\n");
			printf("\t\tUpto 21 to 30 units.................................... Rs. 7/unit\n");
			printf("\t\tUpto 31 to 40 units.................................... Rs. 8.5/unit\n");
			printf("\t\tAbove 40............................................... Rs. 13/unit\n");
			printf("\t\t\t  Press 1 to continue. Press 0 to exit.\n");
			int i;
			scanf("%d", &i);
			if(i==1)
			{	
				choice();
			}
				else if(i==0)
				break;
		}
		default: 
		{
			printf("\t\t\t Wrong choice. Press 1 to continue. Press 0 to exit.\n");
			int i;
			scanf("%d", &i);
			if(i==1)
			{
				choice();
			}
			else if(i==0)
				break;
		}
	} 
}
	
int main()
{
    choice();
}



