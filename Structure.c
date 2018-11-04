#include<stdio.h>
struct student* head=NULL;
struct student {
    int id;
    int marks;
    struct student* next;
};

int insart(int roll, int value)
{
    struct student* store;
    store=(struct student*)malloc(sizeof(struct student));
    store->id = roll;
    store->marks = value;
    store->next = NULL;
    if(head==NULL)
    {
        head=store;
    }
    else
    {
        store->next = head;
        head=store;
    }
}

void printfun()
{
    struct student* store;
    store=head;
    while(store->next != NULL)
    {
        printf("\t%d\t",store->id);
        printf("\t%d\t",store->marks);
        printf("\n");
        store=store->next;
    }
}


int main()
{
    insart(01,100);
    insart(02,99);
    insart(03,98);
    insart(04,97);
    insart(05,96);
    insart(06,95);
    insart(07,94);
    insart(9,93);
    insart(10,92);
    insart(11,91);
    insart(12,90);
    printfun();
    printf("\n");
    return 0;
}


