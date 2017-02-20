#include<stdio.h>

#include<string.h>
void main() {
	int i, j,count=0,nl;
	char str[100];
	//clrscr();
	printf("enter the bit string:  ");
	gets(str);
	for (i=0;i<strlen(str);i++) {
		count=0;
		
		for (j=i;j<=(i+4);j++) {
			if(str[j]=='1') {
				count++;
			}
		}
		//if there is six ones then folling code execute to bit stuffing after five ones
		if(count==5) {
			nl=strlen(str);
			for (;nl>=(i+6);nl--) {
				str[nl]=str[nl-1];
			}
			str[i+5]='0';
			//i=i+7;
		}
str[strlen(str)]='\0';
	}
	puts(str);
	//getch();
}
