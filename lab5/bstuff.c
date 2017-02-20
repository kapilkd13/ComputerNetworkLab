#include<stdio.h>

void main()
{     
char frame[100],str[50][50];
char flag='z';
char esc='x';
int i,j,k=0,n;
frame[k++]='z';
//clrscr();
printf("Enter no.of String :\t");
scanf("%d",&n);
printf("Enter String \n");
for(i=0;i<=n;i++)
  {
gets(str[i]);
  }
printf("You entered :\n");
for(i=0;i<=n;i++)
   {
puts(str[i]);
   }
 
printf("\n");
for(i=1;i<=n;i++)
  {
for(j=0;j<strlen(str[i]);j++)
      {
    if(str[i][j]!=flag&&str[i][j]!=esc)
    {
        frame[k++]=str[i][j];
    }
    else{
        frame[k++]='x';
        frame[k++]=str[i][j];
    }
      }
  }
 
frame[k++]='z';
frame[k++]='\0';

printf("Byte stuffing at sender side:\n\n");

for(i=0;i<k;i++)
  {
printf("%c",frame[i]);
  }

printf("\nByte after destuffing\n\n");

for(i=0;i<k;i++)
  {
if(frame[i]=='x'|| frame[i]=='z')
     {
i++;
     }
printf("%c",frame[i]);
  }
printf("\n");

}
