#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int total=0;
int count=0;
int present;
int hotel();
char email[20];
char pass[20];
char age_val[2];
char contact[10];
char name1[20];
int signup();
int login();
int check(char *);
int validate(char *,int);
void hot_dis(int);
void hot_init();
int cart();
int food();
void food_dis();
void confirm();
struct account{
    char name[100];
    char age[100];
    char mail[100];
    char pwd[100];
    char no[100];
}a[100];
struct hotels{
       char hot_name[20];
       char dish1[20];
       char dish2[20];
       char dish3[20];
       int p1;
       int p2;
       int p3;
}h[3];
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n*********************** SWIGGY - ONLINE FOOD DELIVERY ***********************\n");
        printf("\n\t\t\t\t1.SIGN UP\n\t\t\t\t2.LOGIN\n\t\t\t\t3.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(1);
            break;
        }
    }
}
int signup()
{
    char id[100];
    printf("\n\t\t**** SIGN UP ****\n");
    printf("\t\te-mail id  \t");
    scanf("%s",id);
    if(!validate(id,3))
    {
        printf("\t\tEnter a valid mail id\n");
        return 0;
    }
    if(!check(id))
    {
        strcpy(a[count].mail,id);
        printf("\t\tname       \t");
        scanf("%s",name1);
        if(!validate(name1,1))
        {
        printf("\t\tEnter a valid name\n");
        return 0;
        }
        strcpy(a[count].name,name1);

        printf("\t\tage        \t");
        scanf("%s",age_val);
        if(!validate(age_val,2))
        {
        printf("\t\tEnter a valid age\n");
        return 0;
        }
        strcpy(a[count].age,age_val);

        printf("\t\tcontact no \t");
        scanf("%s",contact);
        if(!validate(contact,5))
        {
        printf("\t\tEnter a valid contact number\n");
        return 0;
        }
        strcpy(a[count].no,contact);

        printf("\t\tpassword   \t");
        scanf("%s",pass);
        if(!validate(pass,4))
        {
        printf("\t\tEnter a strong password  \n");
        return 0;
        }
        strcpy(a[count].pwd,pass);
	printf("Successfully Signed up :) :) Login to continue\n");
        count++;
    }
    else
    {
        printf("\t\tAccount already exist\n");
    }
}
int login()
{
    char id[100];
    int c;
     printf("\t\t**** LOGIN ****\n");
     printf("\t\temail id   \t");
     scanf("%s",id);
     if(!validate(id,3))
    {
        printf("\t\tEnter a valid mail id\n");
        return 0;
    }
    if(check(id))
    {
         printf("\t\tpassword   \t");
         scanf("%s",pass);
         if(!(strcmp(a[present].pwd,pass)))
         {
             hot_init();
                printf("\n\t\t\t**** FOOD PURCHASING ****\n");
                printf("\t\t\t\t1.BY HOTEL\n\t\t\t\t2.BY FOOD\n\t\t\t\t3.EXIT\n");
                scanf("%d",&c);
                switch(c)
                {
                case 1:
                    {
                       hotel();
                        break;
                    }
                case 2:
                    {
                        food();
                        break;
                    }
                case 3:
                    {
                        exit(1);
                        break;
                    }
                }
         }
         else{
            printf("\nmail id and password does not match\n");
         }
    }
    else{
        printf("Account does not exists, Sign up to create an account\n");
    }
}
int check(char *str)
{
    present=0;
    int i;
    for(i=0;i<count;i++)
    {
        if(!strcmp(a[i].mail,str))
        {
            present=i;
            return 1;
        }
    }
    return 0;
}
int validate(char *str,int n)
{
    int len,i,number=0,small=0,upper=0,special=0;
    char *ptr;
    switch(n)
    {
        case 1:
            {
                 len=strlen(str);
                 for(i=0;i<len;i++)
                {
                        if(!(((str[i]>96)&&(str[i]<123))||((str[i]>64)&&(str[i]<91))))
                        {
                        return 0;
                        }
                }
                   return 1;
		break;
                }
        case 2:
            {
                len=strlen(str);
                for(i=0;i<len;i++)
               {
                     if(str[0]=='0')
                         return 0;
                     if(!((str[i]>47)&&(str[i]<60)))
                         return 0;
                }
                return 1;
		break;
            }
        case 3:
            {
                    len=strlen(str);
                    ptr=strchr(str,'@');
                    if((len>6)&&(ptr))
                    {
                        return 1;
                    }
                  return 0;
		break;
            }
        case 4:
            {
                   len=strlen(str);
                   for(i=0;i<len;i++)
                   {
                       if(str[i]>='0' && str[i]<='9')
                        number=1;
                       if(str[i]>='a' && str[i]<='z')
                        small=1;
                       if(str[i]>='A' && str[i]<='Z')
                        upper=1;
                       if(str[i]=='!'||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='&'||str[i]=='*')
                        special=1;
                   }
                   if(len>8 && small && upper && number && special)
                    return 1;
                   else
                    return 0;
		break;
            }
        case 5:
            {
               len=strlen(str);
               if(str[0]=='0')
                return 0;
               for(i=0;i<len;i++)
               {
                     if((!((str[i]>47)&&(str[i]<60)))||(len<10))
                         return 0;
                }
                return 1;
		break;
            }

    }
}
int hotel()
{
    int ch,n,nums;
    total=0;
    printf("\t\t\t****HOTELS LIST****\n");
    printf("\t\t\t-------------------\n");
    printf("\t\t\t  1.The Cascade\n");
    printf("\t\t\t  2.Golden Dragon\n");
    printf("\t\t\t  3.Park Plaza\n");
    printf("\t\t\t-------------------\n");
    scanf("%d",&ch);
    while(1)
    {
       hot_dis(ch);
       printf("Enter your choice---->");
       scanf("%d",&n);
       switch(n)
       {
       case 1:
        {
            printf("Enter the count of %s--->",h[ch].dish1);
            scanf("%d",&nums);
            total=total+(nums*h[ch].p1);
            break;
        }
        case 2:
        {
            printf("Enter the count of %s--->",h[ch].dish2);
            scanf("%d",&nums);
            total=total+(nums*h[ch].p2);
            break;
        }
        case 3:
        {
            printf("Enter the count of %s--->",h[ch].dish3);
            scanf("%d",&nums);
            total=total+(nums*h[ch].p3);
            break;
        }
        case 4:
            {
                cart();
                return 0;
                break;
            }
       }
    }
}
void hot_dis(int i)
{
     printf("\n\t\tHOTEL-%s",h[i].hot_name);
     printf("\n\t\t-----------------------------------\n");
     printf("\t\t|\tDISH\t         | PRICE  | \n");
     printf("\t\t-----------------------------------\n");
     printf("\t\t|1. %s   |  %d   | \n",h[i].dish1,h[i].p1);
     printf("\t\t|2. %s   |  %d   | \n",h[i].dish2,h[i].p2);
     printf("\t\t|3. %s   |  %d   | \n",h[i].dish3,h[i].p3);
     printf("\t\t|4. cart\n");
     printf("\t\t-----------------------------------\n");
}
void hot_init()
{
    strcpy(h[1].hot_name,"The Cascade       ");
    strcpy(h[1].dish1,"Dragon Prawns     ");
    strcpy(h[1].dish2,"Chicken Wantons   ");
    strcpy(h[1].dish3,"Schezwan Noodles  ");
    h[1].p1=350;
    h[1].p2=280;
    h[1].p3=300;
    strcpy(h[2].hot_name,"Golden Dragon     ");
    strcpy(h[2].dish1,"Tiger Prawns      ");
    strcpy(h[2].dish2,"Chicken Momos     ");
    strcpy(h[2].dish3,"Schezwan Rice     ");
    h[2].p1=300;
    h[2].p2=250;
    h[2].p3=280;
    strcpy(h[3].hot_name,"Park Plaza        ");
    strcpy(h[3].dish1,"American Chopsuey ");
    strcpy(h[3].dish2,"Spring Roll       ");
    strcpy(h[3].dish3,"Lamb Roll         ");
    h[3].p1=350;
    h[3].p2=230;
    h[3].p3=300;
}
int cart()
{
    int ans;
    printf("\t\t**** CART ****\n");
    printf("\t\t ----------------\n");
    printf("\t\t|   TOTAL = %d   |\n",total);
    printf("\t\t ----------------\n");
    printf("\n\n Do you want to confirm your order?\n1.yes\t2.no --->");
    scanf("%d",&ans);
    if(ans==1){
        confirm();
        return 0;
    }
    else
    {
        printf("Thank you for showing interest :)\n");
        return 0;
        }
}
void confirm()
{
    printf("Thank you for ordering :) :) your food is being prepared :) :)\n");
    exit(1);
}
int food()
{
     int n,nums,val,ch;
     total=0;
    while(1)
    {
       food_dis();
       printf("Enter your choice---->");
       scanf("%d",&n);
       if(n!=10){
       if(n<4)
        ch=1;
       else if(n>3&&n<7)
        ch=2;
       else
        ch=3;
        if(n%3==0)
            val=3;
        else
            val=n%3;
       switch(val)
       {
       case 1:
        {   printf("%s -----> Hotel %s\n",h[ch].dish1,h[ch].hot_name);
            printf("Enter the count of %s--->",h[ch].dish1);
            scanf("%d",&nums);
            total=total+(nums*h[ch].p1);
            break;
        }
        case 2:
        { printf("%s -----> Hotel %s\n",h[ch].dish2,h[ch].hot_name);
            printf("Enter the count of %s--->",h[ch].dish2);
            scanf("%d",&nums);
            total=total+(nums*h[ch].p2);
            break;
        }
        case 3:
        { printf("%s -----> Hotel %s\n",h[ch].dish3,h[ch].hot_name);
            printf("Enter the count of %s--->",h[ch].dish3);
            scanf("%d",&nums);
            total=total+(nums*h[ch].p3);
            break;
        }
        }
       }
       else
        {
        cart();
        return 0;
       }
    }
}
void food_dis()
{
    int i,c=0;
    printf("\n\t\t-----------------------------------\n");
     printf("\t\t|\tDISH\t         | PRICE  | \n");
     printf("\t\t-----------------------------------\n");
     for(i=1;i<=3;i++){
            if(i==2)
                c=3;
            if(i==3)
                c=6;
     printf("\t\t|%d. %s   |  %d   | \n",c+1,h[i].dish1,h[i].p1);
     printf("\t\t|%d. %s   |  %d   | \n",c+2,h[i].dish2,h[i].p2);
     printf("\t\t|%d. %s   |  %d   | \n",c+3,h[i].dish3,h[i].p3);
     c++;
    }
    printf("\t\t|10. cart\n");
     printf("\t\t-----------------------------------\n");
}

