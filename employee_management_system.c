#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct date
{
	int day,month,year;
};

struct employee
{
	int eid;
	char first_name[30]; 
	char last_name[30];
	char email[30];
	char mobile_no[12];
	int age;
	struct date dob;
	struct date doj;
	int salary;
	char dept[30];
	char branch[30];
};

struct	employee e;
char choice[5];

void welcomescreen();
void title();
void login();
void mainmenu();

void createrecord();
void searchrecord();
void displayrecord();
void deleterecord();
void ex_it();

void main()
{
	
	welcomescreen();
	title();
	login();
		
}
void welcomescreen()
{
	printf("\n\n\n\n\n\t\t\t\t\t\t ----- WELCOME TO -----");
	printf("\n\n\n\n\t\t-----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\t  SK Developers, Pune.");
	printf("\n\t\t-----------------------------------------------------------------------------------\n");
	
	
	printf("\n\n\n\t\t\t\t\t\tPress any key to proceed : ");
	getch();
	system("cls");
}
void title()
{
	printf("\n\t\t---------------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\t  SK Developers, Pune.");
	printf("\n\t\t---------------------------------------------------------------------------------------\n");
}
void login()
{
	int a=0;
	char username[20];
	char password[10];
	
	char myusername[20]="sneha";
	char mypassword[10]="1003";
	
	do
	{
		printf("\n\n\t\t\t\t\t\t Enter Username :- ");
		scanf("%s",&username);
		printf("\n\t\t\t\t\t\t Enter Password :- ");
		scanf("%s",&password);
		if(strcmp(username,myusername)==0 && strcmp(password,mypassword)==0)
		{
			printf("\n\n\n\t\t\t\t\t\tLogin Successfull...");
			printf("\n\n\n\n\t\t\t\t\tPress any key to see Main-Menu : ");
			getch();
			mainmenu();
			break;
		}
		else
		{
			printf("\n\n\n\n\t\t\t\t\tPassword Incorrect : Try Again...\n\n");
			a++;
			getch();
		}
	}while(a<=2);
	if(a>2)
	{
		printf("\n\n\n\t\t\t\tYou have cross the limit, you cannot login...");
		getch();
		ex_it();
	}
}
void mainmenu()
{
	system("cls");
	int c;
	
		title();
		
		printf("\n\n\t\t\t\t\t\t----DATABASE----\n");
		
		printf("\n\n\n\t\t\t\t\t    1.Add New employee Record : ");
		printf("\n\t\t\t\t\t    2.Search employee Record: ");
		printf("\n\t\t\t\t\t    3.Display employees Record : ");
		printf("\n\t\t\t\t\t    4.Delete employee Record : ");
		printf("\n\t\t\t\t\t    5.Exit : ");
		
		A:
		printf("\n\n\n\t\t\t\t\tEnter your choice from 1 to 5 : \n");
		printf("\n\t\t\t\t\tYour choice is : ");
		scanf("%d",&c);
		
		switch (c)
		{
			case 1:
				createrecord();
			break;
			
			case 2:
				searchrecord();
			break;
			
			case 3:
				displayrecord();
			break;
			
			case 4:
				deleterecord();
			break;
			
			case 5:
				ex_it();
			break;
			
			default :
				printf("\n\n\n\t\t\t\t  Invalid Option. Please Select Right Option");
				getch();
				goto A;		
		}
}
void createrecord()
{
	system("cls");
	title();
	
	FILE*fp=fopen("orgrecord.doc","a");
	
	printf("\n\n\t\t\t\t\t  Add New Patients Record :");
	
		printf("\n\n\n\tID : ");
		scanf("%d",&e.eid);
		
		printf("\n\tFirst Name : ");
		scanf("%s",&e.first_name);
		
		printf("\n\tLast Name : ");
		scanf("%s",&e.last_name);
		
		printf("\n\tEmail : ");
		scanf("%s",&e.email);
		
		printf("\n\tMobile No. : ");
		scanf("%s",&e.mobile_no);
		
		printf("\n\tAge : ");
		scanf("%d",&e.age);
		
		printf("\n\tDOB [dd/mm/yyy] : ");
		scanf("%d/%d/%d",&e.dob.day,&e.dob.month,&e.dob.year);
		
		printf("\n\tSalary : ");
		scanf("%d",&e.salary);
		
		printf("\n\tDepartment : ");
		scanf("%s",&e.dept);
		
		printf("\n\tBranch Location : ");
		scanf("%s",&e.branch);
		
		printf("\n\tDate of Joining: ");
		scanf("%d/%d/%d",&e.doj.day,&e.doj.month,&e.doj.year);
		
		fwrite(&e,sizeof(struct employee),1,fp);
		
		printf("\n\n\t\t\t\tInformation Added Successfully...");
		
		fclose(fp);	
		getch();
		
		char choice1[5]="yes";
		char choice2[5]="no";
		sd:
		printf("\n\n\t\t\t\t\tWant to Add More...? [Yes/No] : ");
		scanf("%s",&choice);
		
		if(strcmp(choice1,choice)==0)
		{
			createrecord();
		}
		else if(strcmp(choice2,choice)==0)
		{
			printf("\n\t\t\t\t\tThank You....");
			getch();
			mainmenu();
			getch();
		}
		else
		{
			printf("\n\t\t\t\t\tChoose Valid Option...");
			goto sd;
		}

}
void searchrecord()
{
	system("cls");
	title();
	
	int c;
	int id1, found=0;
	char name1[30];
	char dept1[30];
	
		F:
		printf("\n\n\n\t\t\t\t\tEnter your choice : \n");
		
		printf("\n\n\t\t\t\t\t1.To Search Record Using Employee-Id : ");
		printf("\n\t\t\t\t\t2.To Search Record Using Employee-Name : ");
		printf("\n\t\t\t\t\t3.To Search Record Using Department : ");
	
		printf("\n\n\t\t\t\t\tYour choice is 1/2/3 : ");
		scanf("%d",&c);
		
				if(c==1)
				{
					A:
					system("cls");
					
					title();
						
					FILE *fp=fopen("orgrecord.doc","r");
					
					
					printf("\n\n\tEnter Employee-Id To Be Search : ");
					scanf("%d",&id1);
					
					while(fread(&e,sizeof(struct employee),1,fp))
					{
						if(e.eid == id1)
						{
							found=1;
							printf("\n\t 1] Employees ID \t\t: %d",e.eid);
							printf("\n\t 2] Employees First Name \t: %s",e.first_name);
							printf("\n\t 3] Employees Last Name \t: %s",e.last_name);
							printf("\n\t 4] Employees Email-Add \t: %s",e.email);
							printf("\n\t 5] Employees Mob-No. \t\t: %s",e.mobile_no);
							printf("\n\t 6] Employees Age \t\t: %d",e.age);
							printf("\n\t 7] Employees DOB \t\t: %d/%d/%d",e.dob.day,e.dob.month,e.dob.year);
							printf("\n\t 8] Employees Salary \t\t: %d",e.salary);
							printf("\n\t 9] Employees Department\t: %s",e.dept);
							printf("\n\t10] Employees Branch Location\t: %s",e.branch);
							printf("\n\t11] Employees DOJ\t\t: %d/%d/%d\n\n",e.doj.day,e.doj.month,e.doj.year);				
						}
					}
					if(!found)
					{
						printf("\n\n\tRecord not found !!!...Try Again...");
						getch();
						goto A;
					}
					
							char choice1[5]="yes";
							char choice2[5]="no";
							sd:
							printf("\n\n\t\t\t\t\tWant to Search More...? [Yes/No] : ");
							scanf("%s",&choice);
							
							if(strcmp(choice1,choice)==0)
							{
								searchrecord();
							}
							else if(strcmp(choice2,choice)==0)
							{
								printf("\n\t\t\t\t\tThank You....");
								getch();
								mainmenu();
								getch();
							}
							else
							{
								printf("\n\t\t\t\t\tChoose Valid Option...");
								goto sd;
							}
							
					fclose(fp);	
				}
				if(c==2)
				{
					B:
					system("cls");
					
					title();
						
					FILE *fp=fopen("orgrecord.doc","r");
					
					
					printf("\n\n\tEnter Name To Be Search : ");
					scanf("%s",&name1);
					
					while(fread(&e,sizeof(struct employee),1,fp))
					{
						if(strcmp(e.first_name,name1)==0)
						{
							found=1;
							printf("\n\t 1] Employees ID \t\t: %d",e.eid);
							printf("\n\t 2] Employees First Name \t: %s",e.first_name);
							printf("\n\t 3] Employees Last Name \t: %s",e.last_name);
							printf("\n\t 4] Employees Email-Add \t: %s",e.email);
							printf("\n\t 5] Employees Mob-No. \t\t: %s",e.mobile_no);
							printf("\n\t 6] Employees Age \t\t: %d",e.age);
							printf("\n\t 7] Employees DOB \t\t: %d/%d/%d",e.dob.day,e.dob.month,e.dob.year);
							printf("\n\t 8] Employees Salary \t\t: %d",e.salary);
							printf("\n\t 9] Employees Department\t: %s",e.dept);
							printf("\n\t10] Employees Branch Location\t: %s",e.branch);
							printf("\n\t11] Employees DOJ\t\t: %d/%d/%d\n\n",e.doj.day,e.doj.month,e.doj.year);		
						}
					}
					if(!found)
					{
						printf("\n\n\tRecord not found !!!...Try Again...");
						getch();
						goto B;
					}
					
							char choice1[5]="yes";
							char choice2[5]="no";
							nd:
							printf("\n\n\t\t\t\t\tWant to Search More...? [Yes/No] : ");
							scanf("%s",&choice);
							
							if(strcmp(choice1,choice)==0)
							{
								searchrecord();
							}
							else if(strcmp(choice2,choice)==0)
							{
								printf("\n\t\t\t\t\tThank You....");
								getch();
								mainmenu();
								getch();
							}
							else
							{
								printf("\n\t\t\t\t\tChoose Valid Option...");
								goto nd;
							}
							
					fclose(fp);	
				}
				if(c==3)
				{
					C:
					system("cls");
					
					title();
						
					FILE *fp=fopen("orgrecord.doc","r");
					
					
					printf("\n\n\tEnter Department Name To Be Search : ");
					scanf("%s",&dept1);
					
					while(fread(&e,sizeof(struct employee),1,fp))
					{
						if(strcmp(e.dept,dept1)==0)
						{
							found=1;
							printf("\n\t 1] Employees ID \t\t: %d",e.eid);
							printf("\n\t 2] Employees First Name \t: %s",e.first_name);
							printf("\n\t 3] Employees Last Name \t: %s",e.last_name);
							printf("\n\t 4] Employees Email-Add \t: %s",e.email);
							printf("\n\t 5] Employees Mob-No. \t\t: %s",e.mobile_no);
							printf("\n\t 6] Employees Age \t\t: %d",e.age);
							printf("\n\t 7] Employees DOB \t\t: %d/%d/%d",e.dob.day,e.dob.month,e.dob.year);
							printf("\n\t 8] Employees Salary \t\t: %d",e.salary);
							printf("\n\t 9] Employees Department\t: %s",e.dept);
							printf("\n\t10] Employees Branch Location\t: %s",e.branch);
							printf("\n\t11] Employees DOJ\t\t: %d/%d/%d\n\n",e.doj.day,e.doj.month,e.doj.year);				
						}
					}
					if(!found)
					{
						printf("\n\n\tRecord not found !!!...Try Again...");
						getch();
						goto C;
					}
					
							char choice1[5]="yes";
							char choice2[5]="no";
							dd:
							printf("\n\n\t\t\t\t\tWant to Search More...? [Yes/No] : ");
							scanf("%s",&choice);
							
							if(strcmp(choice1,choice)==0)
							{
								searchrecord();
							}
							else if(strcmp(choice2,choice)==0)
							{
								printf("\n\t\t\t\t\tThank You....");
								getch();
								mainmenu();
								getch();
							}
							else
							{
								printf("\n\t\t\t\t\tChoose Valid Option...");
								goto dd;
							}
							
					fclose(fp);	
				}				
}
void displayrecord()
{
	system("cls");
	title();
		
	FILE *fp=fopen("orgrecord.doc","r");
	
	while(fread(&e,sizeof(struct employee),1,fp))
	{
		printf("\n\t 1] Employees ID \t\t: %d",e.eid);
		printf("\n\t 2] Employees First Name \t: %s",e.first_name);
		printf("\n\t 3] Employees Last Name \t: %s",e.last_name);
		printf("\n\t 4] Employees Email-Add \t: %s",e.email);
		printf("\n\t 5] Employees Mob-No. \t\t: %s",e.mobile_no);
		printf("\n\t 6] Employees Age \t\t: %d",e.age);
		printf("\n\t 7] Employees DOB \t\t: %d/%d/%d",e.dob.day,e.dob.month,e.dob.year);
		printf("\n\t 8] Employees Salary \t\t: %d",e.salary);
		printf("\n\t 9] Employees Department\t: %s",e.dept);
		printf("\n\t10] Employees Branch Location\t: %s",e.branch);
		printf("\n\t11] Employees DOJ\t\t: %d/%d/%d\n\n",e.doj.day,e.doj.month,e.doj.year);
	}
	
	fclose(fp);
	printf("\n\n\n\t\t\t\t      Press any key to back to Main Menu : ");
	getch();
	mainmenu();
}
void deleterecord()
{
	system("cls");
	title();
	int id1, found=0;
	
	FILE *fp=fopen("orgrecord.doc","r");
	FILE *fp1=fopen("temprecord.doc","w");
					
		printf("\n\n\tEnter Id To Be Delete : ");
		scanf("%d",&id1);
					
		while(fread(&e,sizeof(struct employee),1,fp))
			{
				if(e.eid == id1)
					{
						found=1;			
					}
				else
						fwrite(&e,sizeof(struct employee),1,fp1);
			}
				fclose(fp);
				fclose(fp1);
					
			if(found)
				{
					fp1=fopen("temprecord.doc","r");
					fp=fopen("orgrecord.doc","w");
						
					while(fread(&e,sizeof(struct employee),1,fp1))
					{
						fwrite(&e,sizeof(struct employee),1,fp);
					}
					fclose(fp);
					fclose(fp1);
				}
	printf("\n\n\t\t\t\tInformation Deleted Successfully...");
	getch;
	printf("\n\n\n\n\t\t\t\t\tPress any key to back to Main-Menu : ");
	getch();
	mainmenu();					
}
void ex_it()
{
	exit(0);
}
