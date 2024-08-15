#include<reg51.h>    //include 8051 header file.
#define DATA P2			//Select port2 as a data output pin.

unsigned int i,j,k,l,m;

sbit rs=P1^0;      //select the pin P1.0 for register select.
sbit rw=P1^1;			 //select the pin P1.1 for read/write.
sbit en=P1^2;			 //select the pin P1.2 for Enable.

unsigned char name[]={"Hii"};
unsigned char title[]={"LinkedIN"};
unsigned char title2[]={"Family"};

void delay(unsigned int x) //Delay Function
{

	for(i=0;i<x;i++)
		for(j=0;j<1275;j++);
}


void lcddata(unsigned char dat) // Function for LCD data.
{

	DATA=dat;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
}

void lcdcmd(unsigned char comnd) // Function for LCD Command.
{
DATA=comnd;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
}

void main(){
	lcdcmd(0x38);  //command for 8-Bit,2 line,5x7 Dot.
	delay(15);
while(1){
	lcdcmd(0x0E);  //Command for : Display ON,Cursor ON.
	delay(150);
	lcdcmd(0x01);		//Command for : Clear Display Screen.
	delay(15);
	lcdcmd(0x06);	 //Command for : Entry MOde.
	delay(15);
	lcdcmd(0x80);	  //Command for : Force Cursor to beginning of 1st row.
	delay(150);
	for(k=0;name[k]!=(0);k++)
	{	
	lcddata(name[k]);
	}
	delay(150);
	lcdcmd(0x01);
	delay(15);
	lcdcmd(0x80);
	delay(15);
	for(l=0;title[l]!=(0);l++)
	{	
	lcddata(title[l]);
	}
	delay(150);
	lcdcmd(0xC3);    //Command for : Force Cursor to 3rd matrix of 2nd row.
	delay(15);
	for(m=0;title2[m]!=(0);m++)
		{	
	lcddata(title2[m]);
		}
	}
}



