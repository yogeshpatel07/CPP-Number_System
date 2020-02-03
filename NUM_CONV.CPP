#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
char input[50],output[50],inp_ch[50],out_ch[50];
union REGS in,out;
void hide()
{
	in.x.ax=2;
	int86(0x33,&in,&out);
}

void show()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}

void status(int *x,int *y,int *m)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*m=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
}

void pr_optlst(int,int,int,int,char[][15]);

void create(char inp_ch[50],char out_ch[50],char input[50], char output[50])
{
	int poly[6];
	setbkcolor(BLUE);
	//to create main window
	setfillstyle(1,WHITE);
	bar(50,50,300,350);
	setcolor(BLACK);
	line(50,70,300,70);


	// to create exit bar
	setfillstyle(1,RED);
	bar(280,50,300,70);
	setcolor(YELLOW);
	outtextxy(285,55,"X");
	setcolor(BLACK);
	outtextxy(55,55,"Comp.Number System Converter");


	// to create from box
	setcolor(BLACK);
	outtextxy(70,85,"From:");
	setfillstyle(1,GREEN);
	bar(70,100,280,130);
	outtextxy(80,110,inp_ch);
	poly[0] = 260;        /* 1st vertex */
	poly[1] = 110;
	poly[2] = 270; /* 2nd */
	poly[3] = 110;
	poly[4] = 265; /* 3rd */
	poly[5] = 120;
	setfillstyle(1, RED);
	fillpoly(3, poly);
	line(250,100,250,130);
	setcolor(YELLOW);


	// to create input box
	setcolor(BLACK);
	outtextxy(70,140,"Here Enter Input Number:");
	setfillstyle(1,GREEN);
	bar(70,150,280,180);
//nput

	// to create to box
	setcolor(BLACK);
	outtextxy(70,200,"To:");
	setfillstyle(1,GREEN);
	bar(70,210,280,240);
	outtextxy(80,220,out_ch);
	poly[0] = 260;        /* 1st vertex */
	poly[1] = 220;
	poly[2] = 270; /* 2nd */
	poly[3] = 220;
	poly[4] = 265; /* 3rd */
	poly[5] = 230;
	setfillstyle(1, RED);
	fillpoly(3, poly);
	line(250,210,250,240);


	// to create output box
	setcolor(BLACK);
	outtextxy(70,250,"Output is:");
	setfillstyle(1,GREEN);
	bar(70,260,280,290);
	setcolor(YELLOW);
	outtextxy(75,160,input);
	outtextxy(75,270,output);
}

char * enter_data(char[], char[], char[]);
char *calculate(char[],char[], char[]);

void main()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	int x,y,m;
	char qu;
	int px,py;
	int h;
	char xp[50];
	//double inp=0,outp=0;

	char options[4][15]={"binary","octal","decimal","hexadecimal"};
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}
	strcpy(input,"0");
	strcpy(output,"0");
	strcpy(inp_ch,"binary");
	strcpy(out_ch,"binary");
	create(inp_ch,out_ch,input,output);
	while(1)
	{
		show();
		status(&x,&y,&m);
		if(m==1)
		{
			if(x>=280 && x<=300 && y>=50 && y<=70) //click on X to exit
			{
				setcolor(YELLOW);
				outtextxy(60,10,"press ""Y"" to exit convertor program");
				outtextxy(60,20,"else press any key to continue");
				qu=getch();
				if(qu=='y' || qu=='Y')
				{
					exit(0);
				}
				cleardevice();
				hide();
				create(inp_ch,out_ch,input,output);
				show();
				status(&x,&y,&m);
			}

			else if(x>=70  && x<=280  && y>=100  && y<=130)
			{
				show();
				status(&px,&py,&m);
				if(m==1)
				{
					pr_optlst(70,130,280,210,options);
					h=0;
					while(h!=1)
					{
						show();
						status(&x,&y,&m);
						if(m==1)
						{
							hide();
							if(px!=x || py!=y)
							{
								if(x>=70  && x<=280 && y>130  && y<=150 )
								{
									strcpy(inp_ch,options[0]);
									h=1;
									strcpy(input,"0");
								}
								else if(x>=70  && x<=280 && y>150  && y<=170 )
								{
									strcpy(inp_ch,options[1]);
									h=1;
									strcpy(input,"0");
								}
								else if(x>=70  && x<=280 && y>170  && y<=190 )
								{
									strcpy(inp_ch,options[2]);
									h=1;
									strcpy(input,"0");
								}
								else if(x>=70  && x<=280 && y>190  && y<=210 )
								{
									strcpy(inp_ch,options[3]);
									h=1;
									strcpy(input,"0");
								}
								else
								{
									strcpy(inp_ch,inp_ch);
									h=1;
								}
							}
						} //sub if(m==1)

					} //while(h!=1)

				}  //sub if(m==1)
				strcpy(output,calculate(inp_ch,out_ch,input));
				show();
				status(&x,&y,&m);

			} // if( 1st options)

			else if(x>=70  && x<=280  && y>=210  && y<=240)
			{
				show();
				status(&px,&py,&m);
				if(m==1)
				{
					pr_optlst(70,240,280,320,options);
					h=0;
					while(h!=1)
					{
						show();
						status(&x,&y,&m);
						if(m==1)
						{
							hide();
							if(px!=x || py!=y)
							{
								if(x>=70  && x<=280 && y>240  && y<=260 )
								{
									strcpy(out_ch,options[0]);
									h=1;
									strcpy(input,"0");
								}
								else if(x>=70  && x<=280 && y>260  && y<=280 )
								{
									strcpy(out_ch,options[1]);
									h=1;
									strcpy(input,"0");
								}
								else if(x>=70  && x<=280 && y>280  && y<=300 )
								{
									strcpy(out_ch,options[2]);
									h=1;
									strcpy(input,"0");
								}
								else if(x>=70  && x<=280 && y>300  && y<=320 )
								{
									strcpy(out_ch,options[3]);
									h=1;
									strcpy(input,"0");
								}
								else
								{
									strcpy(out_ch,out_ch);
									h=1;
								}
							}
						} //sub if(m==1)

					} //while(h!=1)

				}  //sub if(m==1)
				strcpy(output,calculate(inp_ch,out_ch,input));
				show();
				status(&x,&y,&m);

			} // if( 1st options)

			else if(x>=70 && x<=280 && y>=150 && y<=180 )//click on input box
			{
				strcpy(input,enter_data(inp_ch,out_ch,output));
				strcpy(output,calculate(inp_ch,out_ch,input));
			}


			hide();
			create(inp_ch,out_ch,input,output);
			show();
			status(&x,&y,&m);
		}   // main if(m==1)

	} // main while loop


} // main function

char *enter_data(char inp_ch[50],char out_ch[50],char output[50])
{
	int h,q,l,i,t;
	int len=0;
	char inp[50];
	char chp[50],*endptr;
 //	double invalue=0;
	char ch='0';
	char ap[50]="",bp[50],cp[50],dp[50];
	hide();
	while(ch!='\r')
	{
		delay(200);
		cleardevice();

		create(inp_ch,out_ch,ap,output);
		setbkcolor(BLUE);
		setcolor(YELLOW);
		setfillstyle(1,RED);
		bar(70,150,280,180);
		outtextxy(70,165,ap);
		ch=getch();
		if(strcmp(inp_ch,"binary")==0)
		{
			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
				if(len>0)
				{
					len--;
				}
			}

			if((ch=='0' || ch=='1') && len<=19)
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
				len++;
			}
		}
		else if(strcmp(inp_ch,"octal")==0)
		{
			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
				if(len>0)
				{
					len--;
				}
			}

			if((ch=='0' || ch=='1'|| ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7') && len<=15)
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
				len++;
			}
		}
		else if(strcmp(inp_ch,"decimal")==0)
		{
			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
				if(len>0)
				{
					len--;
				}
			}

			if((ch=='0' || ch=='1'|| ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9') && len<=15)
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
				len++;
			}
		}
		else if(strcmp(inp_ch,"hexadecimal")==0)
		{
			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
				if(len>0)
				{
					len--;
				}
			}

			if((ch=='0' || ch=='1'|| ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' || ch=='a' || ch=='b'|| ch=='c'|| ch=='d' || ch=='e' || ch=='f'|| ch=='A' || ch=='B'|| ch=='C'|| ch=='D' || ch=='E' || ch=='F') && len<=9)
			{
				if(ch=='a')
				{
					ch='A';
				}
				if(ch=='b')
				{
					ch='B';
				}
				if(ch=='c')
				{
					ch='C';
				}
				if(ch=='d')
				{
					ch='D';
				}
				if(ch=='e')
				{
					ch='E';
				}
				if(ch=='f')
				{
					ch='F';
				}
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
				len++;
			}
		}
		else
		{
		;
		}
	 }
  //	 invalue = strtod(ap, &endptr);
	 strcpy(dp,ap);
	 return(dp);
}

char * calculate(char inp_ch[50],char out_ch[50],char input[50])
{
	char output[50];
	int l,i,a,t;
	char m[50],ot[50]="",ip[50],*endptr;
	long double vv;
	double p=0,q=0;
	long pp=0,qq=0;
	char ll[5];
	if(strcmp(inp_ch,"binary")==0)
	{
		if(strcmp(out_ch,"binary")==0)
		{
			strcpy(output,input);
		}
		if(strcmp(out_ch,"octal")==0)
		{
			l=strlen(input)-1;
			while(l>=0)
			{
				for(i=0;i<3;i++)
				{
					if(l<0)
					{
						m[i]='0';
					}
					else
					{
						m[i]=input[l];
					}
					l--;
				}//end of  for loop
				m[i]='\0';
				strrev(m);
				if(strcmp(m,"000")==0)
				{
					strcat(ot,"0");
				}
				else if(strcmp(m,"001")==0)
				{
					strcat(ot,"1");
				}
				else if(strcmp(m,"010")==0)
				{
					strcat(ot,"2");
				}
				else if(strcmp(m,"011")==0)
				{
					strcat(ot,"3");
				}
				else if(strcmp(m,"100")==0)
				{
					strcat(ot,"4");
				}
				else if(strcmp(m,"101")==0)
				{
					strcat(ot,"5");
				}
				else if(strcmp(m,"110")==0)
				{
					strcat(ot,"6");
				}
				else if(strcmp(m,"111")==0)
				{
					strcat(ot,"7");
				}
				else
				{
					;
				}
			}//end of while loop
			strrev(ot);
			strcpy(output,ot);
		}//end bin_to_oct
		if(strcmp(out_ch,"decimal")==0)
		{
			l=strlen(input)-1;
			i=0;
			while(l>=0)
			{
				m[i]=input[l];
				a=int(m[i]-48);
				p=a*pow(2,i);
				i++;
				l--;
				q=q+p;

			}//end of while loop
			sprintf(ot,"%.0f",q);
			strcpy(output,ot);
		}//end of bin_to_dec
		if(strcmp(out_ch,"hexadecimal")==0)
		{
			l=strlen(input)-1;
			while(l>=0)
			{
				for(i=0;i<4;i++)
				{
					if(l<0)
					{
						m[i]='0';
					}
					else
					{
						m[i]=input[l];
					}
					l--;
				}//end of  for loop
				m[i]='\0';
				strrev(m);
				if(strcmp(m,"0000")==0)
				{
					strcat(ot,"0");
				}
				else if(strcmp(m,"0001")==0)
				{
					strcat(ot,"1");
				}
				else if(strcmp(m,"0010")==0)
				{
					strcat(ot,"2");
				}
				else if(strcmp(m,"0011")==0)
				{
					strcat(ot,"3");
				}
				else if(strcmp(m,"0100")==0)
				{
					strcat(ot,"4");
				}
				else if(strcmp(m,"0101")==0)
				{
					strcat(ot,"5");
				}
				else if(strcmp(m,"0110")==0)
				{
					strcat(ot,"6");
				}
				else if(strcmp(m,"0111")==0)
				{
					strcat(ot,"7");
				}
				else if(strcmp(m,"1000")==0)
				{
					strcat(ot,"8");
				}else if(strcmp(m,"1001")==0)
				{
					strcat(ot,"9");
				}
				else if(strcmp(m,"1010")==0)
				{
					strcat(ot,"A");
				}
				else if(strcmp(m,"1011")==0)
				{
					strcat(ot,"B");
				}
				else if(strcmp(m,"1100")==0)
				{
					strcat(ot,"C");
				}
				else if(strcmp(m,"1101")==0)
				{
					strcat(ot,"D");
				}
				else if(strcmp(m,"1110")==0)
				{
					strcat(ot,"E");
				}
				else if(strcmp(m,"1111")==0)
				{
					strcat(ot,"F");
				}
				else
				{
					;
				}
			}//end of while loop
			strrev(ot);
			strcpy(output,ot);
		}//end of bin_to_hex_dec
	}  //end of bin comp
	if(strcmp(inp_ch,"octal")==0)
	{
		if(strcmp(out_ch,"binary")==0)
		{
			strcpy(ip,input);
			strrev(ip);
			i=0;
			l=strlen(ip)-1;
			while(l>=0)
			{
				m[i]=ip[l];
				a=int(m[i]-48);
				if(a==0)
				{
					strcat(ot,"000");
				}
				else if(a==1)
				{
					strcat(ot,"001");
				}
				else if(a==2)
				{
					strcat(ot,"010");
				}
				else if(a==3)
				{
					strcat(ot,"011");
				}
				else if(a==4)
				{
					strcat(ot,"100");
				}
				else if(a==5)
				{
					strcat(ot,"101");
				}
				else if(a==6)
				{
					strcat(ot,"110");
				}
				else if(a==7)
				{
					strcat(ot,"111");
				}
				else
				{
					;
				}
				l--;
				i++;
			}
			strcpy(output,ot);
		}//end of oct_to_bin
		if(strcmp(out_ch,"octal")==0)
		{
			strcpy(output,input);
		}
		if(strcmp(out_ch,"decimal")==0)
		{
			l=strlen(input)-1;
			i=0;
			while(l>=0)
			{
				m[i]=input[l];
				a=int(m[i]-48);
				p=a*pow(8,i);
				q=q+p;
				i++;
				l--;
			}
			sprintf(ot,"%.0f",q);
			strcpy(output,ot);
		}// end of oct_to_dec
		if(strcmp(out_ch,"hexadecimal")==0)
		{
			l=strlen(input)-1;
			i=0;
			while(l>=0)
			{
				m[i]=input[l];
				a=int(m[i]-48);
				pp=a*pow(8,i);
				qq=qq+pp;
				i++;
				l--;
			}
			if(qq==0)
			{
				strcat(ot,"0");
			}
			else
			{
				while(qq>0)
				{
					pp=qq%16;
					qq=qq/16;
					if(pp==10)
					{
						strcat(ot,"A");
					}
					else if(pp==11)
					{
						strcat(ot,"B");
					}
					else if(pp==12)
					{
						strcat(ot,"C");
					}
					else if(pp==13)
					{
						strcat(ot,"D");
					}
					else if(pp==14)
					{
						strcat(ot,"E");
					}
					else if(pp==15)
					{
						strcat(ot,"F");
					}
					else
					{
						sprintf(ll,"%d",pp);
						strcat(ot,ll);
					}
				}
			}
			strrev(ot);
			strcpy(output,ot);
		}//end of oct_to_hexdec
	}// end of inp_ch=octal

	if(strcmp(inp_ch,"decimal")==0)
	{
		if(strcmp(out_ch,"binary")==0)
		{
			qq=strtol(input,&endptr,10);
			if(qq==0)
			{
				strcpy(ot,"0");
			}
			else
			{
				while(qq>0)
				{
					pp=qq%2;
					qq=qq/2;
					sprintf(ll,"%d",pp);
					strcat(ot,ll);
				}
			}
			strrev(ot);
			strcpy(output,ot);
		} //endof dec_to_bin

		if(strcmp(out_ch,"octal")==0)
		{
			qq=strtol(input,&endptr,10);
			if(qq==0)
			{
				strcat(ot,"0");
			}
			else
			{
				while(qq>0)
				{
					pp=qq%8;
					qq=qq/8;
					sprintf(ll,"%d",pp);
					strcat(ot,ll);
				}
			}
			strrev(ot);
			strcpy(output,ot);
		}  //end f dec_to_oct

		if(strcmp(out_ch,"decimal")==0)
		{
			strcpy(output,input);

		} //end of dec_to_dec

		if(strcmp(out_ch,"hexadecimal")==0)
		{
			l=strlen(input)-1;
			i=0;
			qq=strtol(input,&endptr,10);
			if(qq==0)
			{
				strcat(ot,"0");
			}
			else
			{
				while(qq>0)
				{
					pp=qq%16;
					qq=qq/16;
					if(pp==10)
					{
						strcpy(ll,"A");
					}
					else if(pp==11)
					{
						strcpy(ll,"B");
					}
					else if(pp==12)
					{
						strcpy(ll,"C");
					}
					else if(pp==13)
					{
						strcpy(ll,"D");
					}
					else if(pp==14)
					{
						strcpy(ll,"E");
					}
					else if(pp==15)
					{
						strcpy(ll,"F");
					}
					else
					{
						sprintf(ll,"%d",pp);
					}
					strcat(ot,ll);
				}
			}
			strrev(ot);
			strcpy(output,ot);
		}  //end _ofdec_to_hexdec
	}//end of decimal convrt
	if(strcmp(inp_ch,"hexadecimal")==0)
	{
		if(strcmp(out_ch,"binary")==0)
		{
			strcpy(ip,input);
			strrev(ip);
			l=strlen(ip)-1;
			i=0;
			while(l>=0)
			{
				m[i]=ip[l];
				a=int(m[i]-48);
				if(a==0)
				{
					strcat(ot,"0000");
				}
				else if(a==1)
				{
					strcat(ot,"0001");
				}
				else if(a==2)
				{
					strcat(ot,"0010");
				}
				else if(a==3)
				{
					strcat(ot,"0011");
				}
				else if(a==4)
				{
					strcat(ot,"0100");
				}
				else if(a==5)
				{
					strcat(ot,"0101");
				}
				else if(a==6)
				{
					strcat(ot,"0110");
				}
				else if(a==7)
				{
					strcat(ot,"0111");
				}
				else if(a==8)
				{
					strcat(ot,"1000");
				}
				else if(a==9)
				{
					strcat(ot,"1001");
				}
				else if(a==49 ||a==17)
				{
					strcat(ot,"1010");
				}
				else if(a==50 || a==18)
				{
					strcat(ot,"1011");
				}else if(a==51 || a==19)
				{
					strcat(ot,"1100");
				}
				else if(a==52 || a==20)
				{
					strcat(ot,"1101");
				}
				else if(a==53 || a==21)
				{
					strcat(ot,"1110");
				}
				else if(a==54 || a==22)
				{
					strcat(ot,"1111");
				}
				else
				{
					;
				}
				l--;
				i++;
			}
			strcpy(output,ot);

		}//end of hexa_to_bin

		if(strcmp(out_ch,"octal")==0)
		{
			l=strlen(input)-1;
			i=0;
			while(l>=0)
			{
				m[i]=input[l];
				if(m[i]=='a' || m[i]=='A')
				{
					a=10;
				}
				else if(m[i]=='b' || m[i]=='B')
				{
					a=11;
				}
				else if(m[i]=='c' || m[i]=='C')
				{
					a=12;
				}
				else if(m[i]=='d' || m[i]=='D')
				{
					a=13;
				}
				else if(m[i]=='e' || m[i]=='E')
				{
					a=14;
				}
				else if(m[i]=='f' || m[i]=='F')
				{
					a=15;
				}
				else
				{
					a=int(m[i]-48);
				}
				pp=a*pow(16,i);
				qq=qq+pp;
				i++;
				l--;
			}
			//qq=strtol(input,&endptr,10);
			if(qq==0)
			{
				strcat(ot,"0");
			}
			else
			{
				while(qq>0)
				{
					pp=qq%8;
					qq=qq/8;
					sprintf(ll,"%d",pp);
					strcat(ot,ll);
				}
			}
			strrev(ot);
			strcpy(output,ot);

		}//end of hexa_to_oct

		if(strcmp(out_ch,"decimal")==0)
		{
			l=strlen(input)-1;
			i=0;
			while(l>=0)
			{
				m[i]=input[l];
				if(m[i]=='a' || m[i]=='A')
				{
					a=10;
				}
				else if(m[i]=='b' || m[i]=='B')
				{
					a=11;
				}
				else if(m[i]=='c' || m[i]=='C')
				{
					a=12;
				}
				else if(m[i]=='d' || m[i]=='D')
				{
					a=13;
				}
				else if(m[i]=='e' || m[i]=='E')
				{
					a=14;
				}
				else if(m[i]=='f' || m[i]=='F')
				{
					a=15;
				}
				else
				{
					a=int(m[i]-48);
				}
				pp=a*pow(16,i);
				qq=qq+pp;
				i++;
				l--;
			}
				sprintf(ot,"%d",qq);
		       //	strrev(ot);
			strcpy(output,ot);
		}//end of hexa_to_dec

		if(strcmp(out_ch,"hexadecimal")==0)
		{
			strcpy(output,input);
		}//end of hexa__to_hexa

	}//end of hexa_conv
	return output;
}

void pr_optlst(int sx,int sy,int h,int w,char options[][15])
{
	char opt[20];
	hide();
	setfillstyle(1,BLUE);
	bar(sx,sy,h,w);
	setcolor(YELLOW);
	line(sx,sy+20,h,sy+20);
	line(sx,sy+40,h,sy+40);
	line(sx,sy+60,h,sy+60);
	strcpy(opt,options[0]);
	outtextxy(sx+10,sy+8,opt);
	strcpy(opt,options[1]);
	outtextxy(sx+10,sy+28,opt);
	strcpy(opt,options[2]);
	outtextxy(sx+10,sy+48,opt);
	strcpy(opt,options[3]);
	outtextxy(sx+10,sy+68,opt);
	show();
}