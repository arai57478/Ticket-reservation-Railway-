#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"

int main()
{
   int choice;
   add_trains();
   Passenger *ptr;
   int ticket_no;
   char* Train_no;


   while(1)
   {

       choice=enterchoice();
       if(choice==9)
        exit(0);
       switch(choice)
       {

       case 1:
           view_trains();
           getch();
           clrscr();
           break;
       case 2:

           ptr=get_passenger_details();
            clrscr();
            if(ptr!=NULL)
            {
              int ticket_no=book_ticket(*ptr);
                if(ticket_no==-1)
                {
                    textcolor(LIGHTRED);
                    printf("Booking Failed!");

                }
                else
                {
                    textcolor(LIGHTGREEN);
                    printf("Ticket Successfully Booked\nYour ticket no is %d",ticket_no);
               }
                textcolor(WHITE);
                printf("\nPress any key to go back to the main screen");
                getch();
                clrscr();
            }
           break;
       case 3:
                       clrscr();
           char* pmob_no;
           pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                int* pticket_no;
               pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
           break;
       case 4:
             clrscr();
             int t=accept_ticket_no();
             view_ticket(t);
             getch();
             clrscr();
            break;

       case 5:
           clrscr();
             view_all_bookings();
           getch();
           clrscr();
           break;
       case 6:
            clrscr();
           char* p_train;
           p_train=accept_train_no();
             view_bookings(p_train);
             getch();
            clrscr();
           break;
       case 7:
           clrscr();
           ticket_no=accept_ticket_no();
           if(ticket_no!=NULL)
           {
            int result=cancel_ticket(ticket_no);
            if(result==0)
             {
               printf("no ticket is booked for ticket no %",ticket_no);
             }
           else if(result==1)
             {
              printf("Ticket No.%d Successfully cancelled !!",ticket_no);
            }
            printf("\nPress any key to continue");
           }
           getch();
           clrscr();
           break;
       case 8:
             clrscr();
          Train_no=accept_train_no();
           if(Train_no!=NULL)
           {
            int result=cancel_train(Train_no);
            if(result==0)
             {
               printf("No ticket is booked for train no %s",Train_no);
             }
           else if(result==1)
             {
              printf("Train  No.%s Successfully cancelled !!",Train_no);
            }
            printf("\nPress any key to continue");
           }
           getch();
           clrscr();
           break;
       default :
           textcolor(LIGHTRED);
           printf("wrong choice! try again\n");
           getch();
           clrscr();
           break;
       }
   }
   return 0;
}
