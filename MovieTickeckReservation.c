#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
int flag=1;
typedef struct book
{
    int code;
    char name[20];
    char date[20];
    int cost;
    struct book *next;


} Book;
Book *head,*nptr,*temp,*save;
typedef struct user
{
    char name[20];
    char mobile[10];
    char movie_name[20];
    char date[20];
    int totalcost;
    int cost;
    int total_seat;
    struct user *next;

} User;
User *head1,*nptr1,*temp1,*save1;
void insert_details();//for inserting movie details
void viewAll(); // for view all data
void Delete(); // for deleting data
void frontface();
void book_ticket(); //for booking tickets
void view_Bokkings(); //for view old records of users,booked tickets
void cancel_booking();
void user_details();
void outputscreen1();
void outputscreen2();
void main()
{
    system("color A");
    char c;

    do
    {
        system("cls");
        frontface();
        printf("\n\t\t\t\tEnter >1< To Admin panel");
        printf("\n\t\t\t\tEnter >2< To User InterFace");
        printf("\n\t\t\t\tEnter >0< To Exit");
        printf("\n\t\t\t\tEnter your Choice ::");
        scanf("%s",&c);
        fflush(stdin);
        switch(c)
        {
        case '1':
            outputscreen1();
            break;
        case '2':
            outputscreen2();
            break;
        case '0':
            system("cls");
            printf("\n\t\t\t\tProgram Ended!!!");
            system("pause");
            exit(0);
            break;
        default:
            printf("\n\t\t\t\tinvalid Choice!!!\n");
            system("pause");
            main();
        }
    }
    while(c!=0);
}
void frontface()
{
    printf("\n\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\n");
    printf("\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Moive Ticket booking\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n");
    printf("\n\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
void outputscreen1()
{
    char c;
menu2:
    do
    {
        system("cls");
        frontface();

        printf("\n\t\t\t\tEnter >1< To Insert Movies");
        printf("\n\t\t\t\tEnter >2< To View All Movies");
        printf("\n\t\t\t\tEnter >3< To Delete Movies");
        printf("\n\t\t\t\tEnter >4< To Main Menu");
        printf("\n\t\t\t\tEnter >0< To Exit");
        printf("\n\t\t\t\tEnter your Choice ::");
        scanf("%s",&c);
        fflush(stdin);
        switch(c)
        {
        case '1' :
            insert_details();
            break;
        case '2':
            viewAll();
            break;

        case '3':
            Delete();
            break;
        case '4':
            main();
            break;
        case '0':
            system("cls");
            printf("\n\t\t\t\tProgram Ended!!!");
            system("pause");
            exit(0);
            break;
        default:
            printf("\n\t\t\t\tinvalid Choice!!!\n");
            system("pause");
            goto menu2;

        }
    }
    while(c!=0);
}
void outputscreen2()
{
    char c;
menu3:
    do
    {
        system("cls");
        frontface();

        printf("\n\t\t\t\tEnter >1< To Book Tickets");
        printf("\n\t\t\t\tEnter >2< To View All Bookings");
        printf("\n\t\t\t\tEnter >3< To Cancel Booking");
        printf("\n\t\t\t\tEnter >4< To Main Menu");
        printf("\n\t\t\t\tEnter >0< To Exit");
        printf("\n\t\t\t\tEnter your Choice ::");
        scanf("%s",&c);
        fflush(stdin);
        switch(c)
        {
        case '1' :
            book_ticket();
            break;
        case '2':
            view_Bokkings();
            break;

        case '3':
            cancel_booking();
            break;
        case '4':
            main();
            break;
        case '0':
            system("cls");
            printf("\n\t\t\t\tProgram Ended!!!");
            system("pause");
            exit(0);
            break;
        default:
            printf("\n\t\t\t\tinvalid Choice!!!\n");
            system("pause");
            goto menu3;

        }
    }
    while(c!=0);
}
void insert_details()
{
    system("cls");
    frontface();
    nptr=(Book*)malloc(sizeof(Book));
    printf("\t\t\t\tEnter movie code :- ");
    scanf("%d",&nptr->code);
    fflush(stdin);
    printf("\t\t\t\tEnter  name :- ");
    //scanf("%s",&nptr->name);
    fflush(stdin);
    gets(nptr->name);
    printf("\t\t\t\tEnter Release Date:- ");
    scanf("%s",&nptr->date);
    fflush(stdin);
    printf("\t\t\t\tEnter Ticket Price:- ");
    scanf("%d",&nptr->cost);
    fflush(stdin);
    nptr->next=NULL;
    if(head==NULL)
    {
        head=nptr;
    }
    else
    {

        nptr->next=head;
        head=nptr;
    }
}
void viewAll()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\n\t\t\t\tlist is empty\n");
        system("pause");

    }
    else
    {
        printf("\n++*===================================================================================================*++");
        printf("\n\tcode\t\t\tName\t\t\tdate\t\t\t\tcost");
        printf("\n++*===================================================================================================*++\n");

        while(temp!=NULL)
        {
            printf("\t%d",temp->code);
            printf("\t\t\t%s",temp->name);
            printf("\t\t\t%s",temp->date);
            printf("\t\t\t%d",temp->cost);
            printf("\n");
            temp=temp->next;
        }
    }
    system("pause");
}
void Delete()
{
    char c;
    int tempcode;
    //readfrmfile();
    if(head==NULL)
    {
        printf("\n\t\t\t\tlist is empty\n");
        system("pause");

    }
    else
    {
        viewAll();
error2:
        flag=1;
        printf("\t\t\t\tEnter the movie code to delete:");
        scanf("%d",&tempcode);
        fflush(stdin);

        if(head->code==tempcode)
        {
            head=NULL;
            flag=0;
            printf("\t\t\t\tSuccessfully Deleted\n");

        }

        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                save=temp;
                temp=temp->next;
                if(tempcode==temp->code)
                {
                    save->next=temp->next;
                    flag=0;
                    printf("\t\t\t\tSuccessfully Deleted");
                    break;
                }

            }

        }
        if(flag!=0)
        {
            printf("\n\t\t\t\tmovie Not FounD!\n");
            printf("\n\t\t\tpress 0 to prevoius menu any other number to delete again::");
            scanf("%s",&c);
            fflush(stdin);
            if(c=='0')
            {
                outputscreen1();

            }
            goto error2;
        }

    }
    system("pause");
    outputscreen1();
}
void user_details()
{

    printf("\n ENJOY MOVIE \n");
    printf("\n\t\tname : %s",nptr1->name);
    printf("\n\t\tmobile Number : %s",nptr1->mobile);
    printf("\n\t\tmovie name : %s",nptr1->movie_name);
    printf("\n\t\tTotal seats : %d",nptr1->total_seat);
    printf("\n\t\tcost per ticket : %d",nptr1->cost);
    printf("\n\t\tTotal Amount : %d\n",nptr1->totalcost);
    system("pause");
}
void book_ticket()
{
    int movie_code,i;
    char c;
    nptr1=(User*)malloc(sizeof(User));
error:
    flag=1;
    system("cls");
    if(head==NULL)
    {
        printf("\n\t\t\t\tNo movies FounD!\n");
        system("pause");

    }
    else
    {
        viewAll();
        printf("\n\t\t\t\tEnter movie code :");
        scanf("%d",&movie_code);
        temp=head;
        while(temp!=NULL)
        {
            if(temp->code==movie_code)
            {
                flag=0;
                strcpy(nptr1->movie_name,temp->name);
                strcpy(nptr1->date,temp->date);
                nptr1->cost=nptr->cost;
                printf("\n\t\t\t\tTotal number of tickets :");
                scanf("%d",&nptr1->total_seat);
                nptr1->totalcost=(nptr1->total_seat)*temp->cost;
                break;
            }
            temp=temp->next;
        }
        if(flag!=0)
        {
            printf("\n\t\t\t\tmovie Not FounD!\n");
            system("pause");
            goto error;
        }
        printf("\n\t\t\t\tyour name :");
        //scanf("%s",nptr1->name);
        fflush(stdin);
        gets(nptr1->name);
error1:
        printf("\n\t\t\t\tmobile number :");
        scanf("%s",&nptr1->mobile);
        fflush(stdin);
        for(i=0; i<strlen(nptr1->mobile); i++)
        {
            if(!isdigit(nptr1->mobile[i]))
            {
                printf("\n\t\t\t\tEnter  a valid Mobile Number\n");
                printf("\n\t\t\tpress 0 to prevoius menu any other number to Enter again::");
                scanf("%s",&c);
                fflush(stdin);
                if(c=='0')
                {
                    outputscreen2();

                }
                goto error1;
            }

        }

        nptr1->next=NULL;
        if(head1==NULL)
        {

            head1=nptr1;
            nptr1->next=NULL;
        }
        else
        {
            nptr1->next=head1;
            head1=nptr1;
        }
        user_details();
    }

}
void  view_Bokkings()
{
    temp1=head1;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\tlist is empty\n");
        system("pause");

    }
    else
    {


        while(temp1!=NULL)
        {
            printf("\n++*===================================================================================================*++");
            printf("\n\t\t\t\tname : %s",temp1->name);
            printf("\n\t\t\t\tmobile Number : %s",temp1->mobile);
            printf("\n\t\t\t\tmovie name : %s",temp1->movie_name);
            printf("\n\t\t\t\tTotal seats : %d",temp1->total_seat);
            printf("\n\t\t\t\tcost per ticket : %d",temp1->cost);
            printf("\n\t\t\t\tTotal Amount : %d\n",temp1->totalcost);
            printf("\n++*===================================================================================================*++");
            temp1=temp1->next;
        }
    }
    system("pause");
}
void cancel_booking()
{
    char c;
    char tempname[20];
    if(head1==NULL)
    {
        printf("\n\t\t\t\tlist is empty\n");

    }
    else
    {
error:
        flag=1;
        printf("\t\t\t\tEnter the user name to delete:");
        scanf("%s",&tempname);

        if(head1->name==tempname)
        {
            head1=NULL;
            flag=0;
            printf("\n\t\t\t\tSuccessfully Deleted\n");

        }

        else
        {
            temp1=head1;
            while(temp->next!=NULL)
            {
                save1=temp1;
                temp1=temp1->next;
                if(strcmp(temp->name,tempname)==0)
                {
                    save1->next=temp1->next;
                    flag=0;
                    printf("\n\t\t\t\tSuccessfully Deleted\n");
                    break;
                }

            }

        }
        if(flag!=0)
        {
            printf("\n\t\t\t\tUser Not FounD!\n");
            system("pause");
            printf("\n\t\t\tpress 0 to prevoius menu any other number to delete again::");
            scanf("%s",&c);
            fflush(stdin);
            if(c=='0')
            {
                outputscreen2();

            }
            goto error;
        }


    }
    system("pause");

}


