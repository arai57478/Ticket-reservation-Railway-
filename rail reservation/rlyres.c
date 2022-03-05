#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "conio2.h "
#include "rlyres.h"

int enterchoice()
{

    int choice,i;
    textcolor(YELLOW);
    gotoxy(30,2);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(int i=0;i<=79;i++)
        printf("-");
    gotoxy(1,4);
    for(int i=0;i<=79;i++)
        printf("-");
        textcolor(LIGHTGREEN);
    printf("\n--Select an option--");
    printf("\n1-View Trains");
    printf("\n2-Book Ticket");
    printf("\n3-View Ticket");
    printf("\n4-Search Ticket no. ");
    printf("\n5-View all Booking");
    printf("\n6-View train Booking");
    printf("\n7-Cancel Ticket");
    printf("\n8-Cancel Train");
    printf("\n9-Quit");
    printf("\n\n Enter choice :->");
    scanf("%d",&choice);
    clrscr();
    return choice;
}
void add_trains()
{

    Train alltrains[8]={
    {"123","BPl","DEl",2000,1300},
    {"133","BPl","BGl",2500,1200},
    {"113","BPl","NAG",2300,1240},
    {"103","HBJ","MUM",2000,1300},
    {"223","BPl","AGR",1900,1200},
    {"423","DEL","PUN",1700,1000},
    {"623","BPl","DEl",2700,1100},
    {"823","HBJ","ITR",800,400},
    };
FILE *fp=fopen("h:\\rail reservation system1\\alltrains.dat","rb");
if(fp==NULL)
{
    FILE *fp=fopen("h:\\rail reservation system1\\alltrains.dat","wb");
    fwrite(alltrains,8*sizeof(Train),1,fp);
    printf("file created and saved !\n");
}
else
     printf("file already present");
fclose(fp);
}
void view_trains()
{

    printf("train no\t from \t to\t first AC fare \t second AC fare \n");
    for(int i=0;i<=80;i++)
    {
    printf("-");
    }
    FILE *fp=fopen("h:\\rail reservation system1\\alltrains.dat","rb");
     Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
       printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    }
   printf("\n\n\n\n");
    fclose(fp);
}
int check_train_no(char *trainno)
{
    FILE *fp=fopen("h:\\rail reservation system1\\alltrains.dat","rb");
struct    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
   fclose(fp);
    return 0;
}
 Passenger *get_passenger_details()
{
     clrscr();
     static Passenger psn;
     textcolor(RED);
     gotoxy(40,1);
     printf("press '0' to exit !!");
     textcolor(LIGHTGREEN);
     gotoxy(1,1);
    printf("\n Enter your Name :");
    fflush(stdin);
     fgets(psn.p_name,20,stdin);
     char*pos;
     pos=strchr(psn.p_name,'\n');
     *pos='\0';
     if(strcmp(psn.p_name,"0")==0)
     {

         textcolor(LIGHTRED);
         gotoxy(1,25);
           printf("\t\t\t\t\t\t\t\t");
         printf("reservation cancelled");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
     }
      int valid;
     printf("Enter Gender(M / F) :");
     do
     {
         valid=1;
         fflush(stdin);
         scanf("%c",&psn.gender);
         if(psn.gender=='0')
         {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("reservation cancelled");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
         }
         if(psn.gender!='M' && psn.gender!='F')
         {
               textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("ERROR ! Gender should be M or F(in uppercase)!");
         valid=0;
         getch();
         gotoxy(22,3);
         printf(" \b");
         textcolor(LIGHTGREEN);
         }
     }
     while(valid==0);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t");
     gotoxy(1,4);
     printf("Enter train number :");
     do
     {
         fflush(stdin);
         scanf("%s",&psn.train_no);
         if(strcmp(psn.train_no,"0")==0)
         {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("reservation cancelled");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
         }
         valid=check_train_no(psn.train_no);
         if(valid==0)
         {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("ERROR ! Invalid train no!");
         getch();
         gotoxy(21,4);
         printf(" \t\t\t\t\t");
         textcolor(LIGHTGREEN);
         return NULL;
         }
     }
     while(valid==0);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t");
     gotoxy(1,5);
     printf("Enter tavelling class(First AC-F ,second AC-S:");
     do
     {
         valid=1;
         fflush(stdin);
         scanf("%c",&psn.p_class);
         if(psn.p_class=='0')
         {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("reservation cancelled");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
         }
         if(psn.p_class!='F' && psn.p_class!='S')
         {
               textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("ERROR ! travelling should be S or F(in uppercase)!");
         valid=0;
         getch();
         gotoxy(47,5);
         printf(" \b");
         textcolor(LIGHTGREEN);
         }
     }
     while(valid==0);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t");
     gotoxy(1,6);
     printf("Enter address : ");
     fflush(stdin);
     fgets(psn.address,20,stdin);

     pos=strchr(psn.address,'\n');
     *pos='\0';
     if(strcmp(psn.address,"0")==0)
     {

         textcolor(LIGHTRED);
         gotoxy(1,25);
           printf("\t\t\t\t\t\t\t\t");
           gotoxy(1,25);
         printf("reservation cancelled");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
     }
     printf("Enter age: ");
     do
     {

         valid=1;
         fflush(stdin);
         scanf("%d",&psn.age);
         if(psn.age==0)
         {
         textcolor(LIGHTRED);
         gotoxy(1,25);
           printf("\t\t\t\t\t\t\t\t");
           gotoxy(1,25);
         printf("reservation cancelled");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
      }
      if(psn.age<=0)
      {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("ERROR !Age should be positive");
         valid=0;
         getch();
         gotoxy(11,7);
         printf(" \b");
         textcolor(LIGHTGREEN);
        }
         }
     while(valid==0);
     gotoxy(1,25);
     printf("\t\t\t\t\t");
     gotoxy(1,8);
    printf("Enter mobile no :");
    do
    {
        fflush(stdin);
     fgets(psn.mob_no,12,stdin);

     pos=strchr(psn.mob_no,'\n');
     *pos='\0';
     if(strcmp(psn.mob_no,"0")==0)
     {

         textcolor(LIGHTRED);
         gotoxy(1,25);
           printf("\t\t\t\t\t\t\t\t");
         printf("reservation cancelled");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
     }
     valid=check_mob_no(psn.mob_no);
       if(valid==0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Invalid Mobile No");
            getch();
            gotoxy(19,8);
            printf("\t\t\t\t\t\t");
            gotoxy(19,8);
            textcolor(LIGHTGREEN);
            }
            }while(valid==0);
            return &psn;
}

int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
       while(*p_mob!='\0')
      {
           if(isdigit(*p_mob)==0)
               return 0;
        p_mob++;
     }
      return 1;
     }
int get_booked_ticket_count(char *train_no,char tc)
 {
  FILE *fp=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
 if(fp==NULL)
  return 0;
  Passenger pr;
  int count=0;
  while(fread(&pr,sizeof(pr),1,fp)==1)
{
if(strcmp(pr.train_no,train_no)==0&& pr.p_class==tc)
++count;
}
fclose(fp);
return 0;
}
int last_ticket_no()
{
    FILE *fp=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger p;
    fseek(fp,-1L*sizeof(p),SEEK_END);
    fread(&p,sizeof(p),1,fp);
    fclose(fp);
    return p.ticketno;
}
int book_ticket(Passenger p)
{
    int x;
    x=get_booked_ticket_count(p.train_no,p.p_class);
    if(x==20)
    {
        printf("All seats full in train no %s in %c class!",p.train_no,p.p_class);
        return-1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("h:\\rail reservation system1\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! File cannot be opened");
        return -1;
    }
fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}

char *accept_mob_no()
{
static char mob_no[13];
char *pos;
int valid;
printf("Enter the valid mobile number");
do
{
fflush(stdin);
fgets(mob_no,13,stdin);
pos =strchr(mob_no,'\n');
if(pos!=NULL)
*pos='\0';
if(strcmp(mob_no,"0")==0)
{
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("Cancelling input...!");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
}
valid=check_mob_no(mob_no);
if(valid==0)
{
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("Error! invalid MOblie no");
         getch();
         gotoxy(30,1);
         printf("\t\t\t\t\t\t");
         gotoxy(30,1);
         textcolor(LIGHTGREEN);
         }
}
     while(valid==0);
     clrscr();
     return mob_no;
}
int* get_ticket_no(char *p_mob_no)
{
   int count=0;
   FILE *fp=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
   if(fp==NULL)
    {
        return NULL;
    }
   Passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
          *(p+i)=pr.ticketno;
            i++;
      }
    }
*(p+i)=-1;
fclose(fp);
return p;
}

void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(LIGHTGREEN);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("---------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(LIGHTGREEN);
getch();
}

int accept_ticket_no()
{
     int s;
     int valid;
    printf("Enter valid ticket number :");
    do
    {
    fflush(stdin);
    scanf("%d",&s);
    if(s==0)
       {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("Cancelling input...!");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;

     }
          if(s<0)
    {
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("Error! invalid MOblie no");
         getch();
         gotoxy(21,1);
         printf("\t\t\t\t\t\t");
         gotoxy(21,1);
         textcolor(LIGHTGREEN);
         valid==0;
         }
         if(s>0)
            valid=1;
     }while(valid==0);
     clrscr();
     return s;
}
void view_ticket(int ticket_no)
{
    FILE *fp;
    fp=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
   if(fp==NULL)
    {
        printf("No booking done yet");
        return NULL;
    }
     Passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(pr.ticketno==ticket_no)
      {
         printf("Details of ticket no %d are \n Passenger name : %s \n Gender : %c \n Train no : %s \n Class : %c \n Address : %s \n Age : %d \n Ticket no. : %d \n Moblie no : %s",ticket_no,pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.ticketno,pr.mob_no);
         break;
      }
    }
    fclose(fp);

}
void view_all_bookings()
{
      printf("name     \tGender\tTrain no  Class\tAddress\t Age\tTicket no\tMob no\n");
    for(int i=0;i<=80;i++)
    {
    printf("-");
    }
    FILE *fp=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
    Passenger pr;
    textcolor(WHITE);
    int row=4;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
     printf("\n%s",pr.p_name);
      gotoxy(12,row);
      printf("\t%c \t %s \t %c\t%s\t %d \t %d \t    %s ",pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.ticketno,pr.mob_no);
      row++;
    }
   printf("\n\n\n\n");
   textcolor(LIGHTGREEN);
    fclose(fp);

}
char* accept_train_no()
{
static char t_no[10];
char *pos;
int valid;
printf("Enter the valid train number");
do
{
fflush(stdin);
fgets(t_no,10,stdin);
pos =strchr(t_no,'\n');
if(pos!=NULL)
*pos='\0';
if(strcmp(t_no,"0")==0)
{
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("Cancelling input...!");
         getch();
         textcolor(LIGHTGREEN);
         return NULL;
}
valid=check_train_no(t_no);
if(valid==0)
{
         textcolor(LIGHTRED);
         gotoxy(1,25);
         printf("\t\t\t\t\t\t\t\t");
         printf("Error! invalid Train no");
         getch();
         gotoxy(29,1);
         printf("\t\t\t\t\t\t");
         gotoxy(29,1);
         textcolor(LIGHTGREEN);
         }
}
     while(valid==0);
     clrscr();
     return t_no;
}
void view_bookings(char* train__no)
{
    printf("name     \tGender\tTrain no  Class\tAddress\t Age\tTicket no\tMob no\n");
    for(int i=0;i<=80;i++)
    {
    printf("-");
    }
    FILE *fp=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
    Passenger pr;
    textcolor(WHITE);
    int row=4;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.train_no,train__no)==0)
      {
       printf("\n%s",pr.p_name);
      gotoxy(12,row);
      printf("\t%c \t %s \t %c\t%s\t %d \t %d \t    %s ",pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.ticketno,pr.mob_no);
      row++;
      }

   }
   printf("\n\n\n\n");
   textcolor(LIGHTGREEN);
    fclose(fp);
   getch();

}
int cancel_ticket(int ticket_no)
{
    FILE *fp1;
fp1=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
if(fp1==NULL)
{
    textcolor(LIGHTRED);
printf("\nNo bookings done yet fo ticket no. %d!",ticket_no);
return -1;
}
FILE *fp2;
fp2=fopen("h:\\rail reservation system1\\temp.dat","wb");
Passenger pr;
int found=0;
while(fread(&pr,sizeof(pr),1,fp1)==1)
{
 if(pr.ticketno==ticket_no)
  {
   found=1;
   }
  else
{
fwrite(&pr,sizeof(pr),1,fp2);
}
}
fclose(fp1);
fclose(fp2);
if(found==0)
{
 remove("h:\\rail reservation system1\\temp.dat");
}
else
{
 remove("h:\\rail reservation system1\\allbookings.dat");
 rename("h:\\rail reservation system1\\temp.dat","h:\\rail reservation system1\\allbookings.dat");
}
return found;
}
int cancel_train(char *Train_no)
{
FILE *fp1;
fp1=fopen("h:\\rail reservation system1\\allbookings.dat","rb");
if(fp1==NULL)
{
    textcolor(LIGHTRED);
printf("\nNo bookings done yet for train no. %s!",Train_no);
return -1;
}
FILE *fp2;
fp2=fopen("h:\\rail reservation system1\\temp.dat","wb");
Passenger pr;
int found=0;
while(fread(&pr,sizeof(pr),1,fp1)==1)
{
 if(strcmp(pr.train_no,Train_no)==0)
  {
   found=1;
   }
  else
{
fwrite(&pr,sizeof(pr),1,fp2);
}
}
fclose(fp1);
fclose(fp2);
if(found==0)
{
 remove("h:\\rail reservation system1\\temp.dat");
}
else
{
 remove("h:\\rail reservation system1\\allbookings.dat");
 rename("h:\\rail reservation system1\\temp.dat","h:\\rail reservation system1\\allbookings.dat");
}
return found;
}








