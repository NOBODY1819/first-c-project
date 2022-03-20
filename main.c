
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


 struct item
    {  
        int product_id;
     char product_name[15];
     int product_qua;
    float product_price;
    float product_wei;
    }itm; 


void wel_come(void);
int menu();
int make();
int edit();
int search();
int delete();


FILE *fp;

int main()
{  
    wel_come();
    menu();
}





void wel_come(void)

{
	printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\t     WELCOME TO \t |\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\t STOCK MGMT SYSTEM\t |\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Press any key to continue.........\t\t\t\t\t\t\t\t\t|\n");

	printf("---------------------------------------------------------------------------------------------------------\n");
	 
getch();
system("cls");
}


int menu()
{
    int choice;
    printf("          ------------      \n");
    printf("\t***Enter choice***\t\n\tPress <1> Make Entery.\n\tPress <2> Edit Entery.\n\tPress <3> Search.\n\tPress <4> Delete Entery.\n\tPress <5> Exit.\n");
     printf("         ------------      \n");
     printf("\t\t:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        make();
    break;

    case 2 :
        edit();
    break;
     
     case 3:
         search();
     break;
     
     case 4:
          delete();
     break;
     
     case 5:
		    printf("\t***System Exit***\t");
		      exit(0);
		break;
			
		default:
		    printf("Invalid Choice! System Exit\n");
			    getch();
    }
}
int make() //function for making new entery
{
       int a;
     do
     {
          
     printf("         ------------      \n");
      printf("*******Enter details*******\n");
       printf("        ------------      \n");
        printf("Enter Product Id :");
          scanf("%d",&itm.product_id);
        printf("Enter name :");
          scanf("%s",itm.product_name);
       printf("Enter price(in Rs) :");
         scanf("%f",&itm.product_price);
       printf("Enter quantity :");
          scanf("%d",&itm.product_qua);
        printf("Enter Weight(in gm) :");
        scanf("%f",&itm.product_wei);


    fp=fopen("stock report.txt","a");
    fprintf(fp,"\n%d %s %.2f %d %.2f",itm.product_id,itm.product_name,itm.product_price,itm.product_qua,itm.product_wei);
     printf("\n\tPress<1>Next Entry.\n\tPress<0>Main Menu\n \t:");
     scanf("%d",&a);
     }while (a==1);
     
     
     system("cls");
     menu();
}

int search() //function for search entery.
{
      
	char target[40];
	int a,found=0;
	FILE *sf;
	sf=fopen("stock report.txt","r");
    do
    {
   printf("       ------------      \n");   
	printf("\n\t\tEnter name to search : ");
	fflush(stdin);
	gets(target);
  printf("\n       ------------      \n");
	
	while (!feof(sf) && found==0)
	{
		fscanf(sf,"%i %s %f %i %f",&itm.product_id, itm.product_name, &itm.product_price, &itm.product_qua,&itm.product_wei);
        
		if(strcmp(target,itm.product_name)==0)
		{
			found=1;		
		}
	}
	
	if(found==1)
	{
		printf("\n\t****Record found****");
		printf("\nProduct Id\t\t:%i  \nProduct Name\t\t:%s \nProduct Price\t\t:%.2f \nProduct Quantity\t\t:%i \nProduct Weight\t\t:%.2f\n", itm.product_id, itm.product_name, itm.product_price, itm.product_qua, itm.product_wei);
	
	}
	else 
		printf("No Record found\n");
		fclose(fp);
    found=0;
          printf("\n\tPress<1>Search again.\n\tPress<0>Main Menu\n \t:");
     scanf("%d",&a);
      } while (a==1);
		
  menu();
}


int delete()   //function for deleting entery
{
	char target[40]; 
	int a,found=0;
	FILE *rf, *tf;
	rf=fopen("stock report.txt","r");
	tf=fopen("TempFile.txt","w+");
  printf("         ------------      \n");
	printf("\n\t\tEnter name to delete: ");
	fflush(stdin);
	scanf("%s",target);
  printf("         ------------      \n");

	while (fscanf(rf,"%i %s %f %i %f",&itm.product_id, itm.product_name, &itm.product_price, &itm.product_qua,&itm.product_wei)!=EOF)
	{
		if(strcmp(target,itm.product_name)==0)
		{
			found=1;
		}
		else
		{
			fprintf(tf,"%i %s %.4f %i %.4f\n",itm.product_id, itm.product_name, itm.product_price, itm.product_qua,itm.product_wei);
		}
	}
			if(!found)
			{
				printf("\n Record not Found");
				getch();
				menu();
			}
			else
			{
				printf("\n Record deleted");	
			}
      
			fclose(rf);
			fclose(tf);
			remove("stock report.txt");
			rename("TempFile.txt","stock report.txt");
     
			printf("\nPress any key to go to Main Menu!");
      getch();
		menu();
}

int edit()     //function for editing entery
{
  
	char target[40]; 
	int a,found=0;
	FILE *rf, *tf;
	rf=fopen("stock report.txt","r");
	tf=fopen("TempFile.txt","w+");
  printf("         ------------      \n");
	printf("\n\t\tEnter name to edit: ");

	fflush(stdin);
	scanf("%s",target);
  printf("         ------------      \n");

	while (fscanf(rf,"%i %s %f %i %f",&itm.product_id, itm.product_name, &itm.product_price, &itm.product_qua,&itm.product_wei)!=EOF)
	{
		if(strcmp(target,itm.product_name)==0)
		{
			found=1;
      printf("\n\t****Record found****");
    	printf("\nProduct Id\t\t:%i  \nProduct Name\t\t:%s \nProduct Price\t\t:%.2f \nProduct Quantity\t\t:%i \nProduct Weight\t\t:%.2f\n", itm.product_id, itm.product_name, itm.product_price, itm.product_qua, itm.product_wei);
	
      printf("\n\t****Enter new record****");
        printf("\nEnter Product Id :");
          scanf("%d",&itm.product_id);
        printf("\nEnter name :");
          scanf("%s",itm.product_name);
       printf("\nEnter price(in Rs) :");
         scanf("%f",&itm.product_price);
       printf("\nEnter quantity :");
          scanf("%d",&itm.product_qua);
        printf("\nEnter Weight(in gm) :");
        scanf("%f",&itm.product_wei);


        fprintf(tf,"%i %s %.4f %i %.4f\n",itm.product_id, itm.product_name, itm.product_price, itm.product_qua,itm.product_wei);
        	fflush(stdin);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");

		}
		else
		{
			fprintf(tf,"%i %s %.4f %i %.4f\n",itm.product_id, itm.product_name, itm.product_price, itm.product_qua,itm.product_wei);
		}
	}
			if(!found)
			{
				printf("\n Record not Found");
				getch();
				menu();
			}
		
			fclose(rf);
			fclose(tf);
			remove("stock report.txt");
			rename("TempFile.txt","stock report.txt");
     
			printf("\nPress any key to go to Main Menu!");
      getch();
		menu();
}