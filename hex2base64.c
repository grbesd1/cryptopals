/**
* Title               : Convert Hexadecimal to Base64
* Program Description : Write a C Program to Convert
* Hexadecimal Number to Base64 Number.
* Author              : Ganesh Biradar
* Interface           : Console
* IDE                 : Vim Editor with gcc compiler
* Operating System    : Ubuntu 10.04
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char Base64[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
				  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
				  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
				  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
				  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
				  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
				  'w', 'x', 'y', 'z', '0', '1', '2', '3',
				  '4', '5', '6', '7', '8', '9', '+', '/',
};

int hexbit[] = {0};
char Base64String[]={};

int main()
{
	char hex[] = {0};
	int bp8 = 1, remainder = 0, decimal = 1,temp = 0;
	int length = 0, count = 0, leftover = 0;
	int i, j = 0,k;
	scanf("%s",hex);
	for(i=0;hex[i]!='\0';i++)
	{
		switch(hex[i]){
			case '0' :  hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=0;
						break;
			case '1' :  hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=1;
						break;
			case '2' :  hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=0;
						break;
			case '3' :  hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=1;
						break;
			case '4' :  hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=0;
						break;
			case '5' :  hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=1;
						break;
			case '6' :  hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=0;
						break;
			case '7' :  hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=1;
						break;
			case '8' :  hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=0;
						break;
			case '9' :  hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=0;
						hexbit[j++]=1;
						break;
			case 'a' :  hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=0;
						break;
			case 'b' :  hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=1;
						hexbit[j++]=1;
						break;
			case 'c' :  hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=0;
						break;
			case 'd' :  hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=0;
						hexbit[j++]=1;
						break;
			case 'e' :  hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=0;
						break;
			case 'f' :  hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=1;
						hexbit[j++]=0;
						break;
			default :   
						break;
			}
	}
	length = j-1;
	count = length/6;
	printf("length = %d count = %d\n",length,count);
	leftover = length%6;
	if(leftover > 0 && leftover < 6)
	{
		count+=1;
		printf("leiftover = %d count = %d\n",leftover,count);
	}

	count *= 6;
	
	while(j < count)
		hexbit[j++] = 0;
			
		
	for(i=0; i < count; bp8++)
	{
		decimal = 1;
		for(k = i; k < (bp8*6); k++)
		{
			remainder = remainder + hexbit[k] * decimal;
			decimal *= 2;
		}
		if(remainder >= 0 || remainder < 64)
		{
			Base64String[bp8-1] = Base64[remainder];
			remainder = 0;
		}
		temp = ++i * 6;
		i = temp;
	}
	Base64String[bp8] = '\0';
	printf("Base64String is \n%s\n",Base64String);
	return 0;
}

