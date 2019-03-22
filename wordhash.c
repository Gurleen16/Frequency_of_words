#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Hash
{
  struct word *head;
  struct word *tail;
};
struct Hash arr[256];
struct word
{
char str[10];
int count;
struct word *next;
};
void makingnull()
{
  for(int i=0;i<256;i++)
  {
    arr[i].head=NULL;
    arr[i].tail=NULL;
  }

}
void insertintable(int index,int count1,char long1[])
{
    struct word *ptr;
    ptr=(struct word *)malloc(sizeof(struct word));
    if(arr[(int)long1[index]].head==NULL)
    {
        arr[(int)long1[index]].head=ptr;
        arr[(int)long1[index]].tail=ptr;
    }
    else
        arr[(int)long1[index]].tail->next=ptr;
    int j=0;
    for(int i=index;i<index+count1;i++)
    {
        ptr->str[j]=long1[i];
        j++;
    }
    ptr->count=1;
    ptr->next=NULL;
    arr[(int)long1[index]].tail=ptr;
}
int nowcompare(char s[10],int count1)
{
    int flag;
    struct word *temp;
    temp=arr[(int)s[0]].head;
    while(temp!=NULL)
    {
        for(int i=0;i<count1;i++)
        {
            if(temp->str[i]==s[i])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            temp->count=temp->count+1;
            return 1;
            break;
        }
        else
        {
            temp=temp->next;

        }
    }
    return 0;
}
void checkword(int index,int count1,char long1[])
{
    char s[10];
    int j=0;
    for(int i=index;i<index+count1;i++)
    {
        s[j]=long1[i];
        j++;
    }
    if(arr[(int)s[0]].head== NULL)
    {
        insertintable(index,count1,long1);
    }
    else
    {
        int g=nowcompare(s,count1);
        if(g==0)
        insertintable(index,count1,long1);
    }
}
void findword(char longest[])
{
    int flag=0;
    int len=strlen(longest);
    int ind,count=0;
    for(int i=0;i<len;i++)
    {
        if(longest[i]==' '&&flag==1)
        {
            flag=0;
            checkword(ind,count,longest);
            count=0;
        }
        else if(longest[i]==' ')
            flag=0;
        else
        {
            if(flag==0)
            {
                count=1;
                ind=i;
                flag=1;
            }
            else
            {
                count++;
            }

        }
    }
    checkword(ind,count,longest);
}
void printtable()
{
  for(int i=0;i<256;i++)
  {
    struct word *temp;
    temp=arr[i].head;
    while(temp!=NULL)
    {
      printf("%s %d\n",temp->str,temp->count );
      temp=temp->next;
    }
  }
}
int main()
{
    char longer[100];
    makingnull();
    scanf("%[^\n]s",longer);
    findword(longer);
    printtable();
}
