/*  Book has- name, price, publisher, page 
    page has- no, topic 
 one single book has many pages in this problem
    1. Build the required structures 
    2. write down the operations needed. (eg. methods/functions)
    3. implement the necessary code (all values will be taken from the user)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Page
{
    int no;
    char topic[20];
    struct Page *next;
}Page;

typedef struct Book
{
    char name[20];
    int price;
    char publisher[20];
    Page *pg;
}Book;

void addPage(Book *bk)
{
    int no;
    char topic[20];
    printf("Enter Page No:");
    scanf("%d",&no);
    printf("\n");
    printf("Enter Topic:");
    scanf("%s",topic);
    printf("\n");

    Page *newPage = (Page*)malloc(sizeof(Page));
    newPage->no = no;
    strcpy(newPage->topic,topic);
    newPage->next = NULL;

    if(bk->pg == NULL)
    {
        bk->pg = newPage;
        return;
    }

    Page *temp = bk->pg;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newPage;
}

void display(Book *bk)
{
    if(bk == NULL)
    {
        printf("There is no book available!\n");
        return;
    }
    printf("Book Name: %s\t",bk->name);
    printf("Book Price: %d\t\t",bk->price);
    printf("Book Publisher: %s\n",bk->publisher);
    Page *temp = bk->pg;
    if(temp == NULL)
    {
        printf("This book has no pages!\n");
        return;
    }
    while(temp != NULL)
    {
        printf("Page No: %d\tPage Topic: %s\n",temp->no,temp->topic);
        temp = temp->next;
    }
}

void deletePage(Book *bk,int pg)
{
    if(bk == NULL)
    {
        printf("There is no book available!\n");
        return;
    }
    Page *temp = bk->pg;
    if(temp == NULL)
    {
        printf("This book has no pages!\n");
        return;
    }
    if(temp->no==pg)
    {
        Page *del=temp;
        bk->pg=temp->next;
        free(del);
        printf("Page %d has been deleted\n",pg);
        return;
    }
    while(temp->next != NULL)
    {
        if(temp->next->no==pg)
        {
            Page *del=temp->next;
            temp->next=temp->next->next;
            free(del);
            printf("Page %d has been deleted\n",pg);
            return;
        }
        temp=temp->next;
    }
    printf("Page Not Found!\n");
}

void findPage(Book *bk, int pg)
{
    if(bk == NULL)
    {
        printf("There is no book available!\n");
        return;
    }
    Page *temp = bk->pg;
    if(temp == NULL)
    {
        printf("This book has no pages!\n");
        return;
    }
    while(temp!= NULL)
    {
        if(temp->no==pg)
        {
            printf("Page Found!\n");
            printf("Topic Name: %s",temp->topic);
            return;
        }
        temp=temp->next;
    }
    printf("Page Not Found!\n");
}

int main()
{
    char name[20];
    int price;
    char publisher[20];

    printf("Enter Book Name: ");
    scanf("%s",name);
    printf("\n");
    printf("Enter Price: ");
    scanf("%d",&price);
    printf("\n");
    printf("Enter Publisher: ");
    scanf("%s",publisher);
    printf("\n");

    Book *bk=(Book*)malloc(sizeof(Book));
    strcpy(bk->name,name);
    bk->price=price;
    strcpy(bk->publisher,publisher);
    bk->pg=NULL;

    printf("\t Welcome To Your Book :)\n");

    while(1)
    {
        int ch;
        printf("1. Add Page\n2. Delete page\n3. Show Book\n4.Find Page\n5. Exit\n");
        printf("Enter Your coice: ");
        scanf("%d",&ch);
        printf("\n");
        if(ch==1)
        {
            addPage(bk);
        }
        else if(ch==2)
        {
            int pg;
            printf("Enter Page No: ");
            scanf("%d",&pg);
            printf("\n");
            deletePage(bk,pg);
        }
        else if(ch==3)
        {
            display(bk);
        }
        else if(ch==4)
        {
            int pg;
            printf("Enter Page No: ");
            scanf("%d",&pg);
            printf("\n");
            findPage(bk,pg);
        }
        else if(ch==5)
        {
            printf("Thank You!\n");
            break;
        }
        else
        {
            printf("Invalid Input... Try Again!\n");
        }
        printf("\n");
    }
    //display(bk);
    return 0;
}
