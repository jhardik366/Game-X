#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<iomanip>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void _setcursortype(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clreol()
{
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',info.dwSize.X - info.dwCursorPosition.X, coord,&written);
	gotoxy(coord.X, coord.Y);
}

int porr();
void executing(int);
void game();

class sm
{   
	int e[3];
	public:
		sm()
		{}
		void sm1();
		void rules();
		~sm()
		{}
};
void sm::rules()
{   
    system("cls");
	cout<<"\n\n\t\t\t THE RULES ARE AS FOLLOWS: \n";
	//-------------- ADD RULES ---------------------
	getch();
	system("cls");
	sm1();
}
void sm::sm1()
{	system("cls");
	_setcursortype(0,0);
	cout<<"\n\t\t\t\t WELCOME TO SLOT MACHINE";
	cout<<"\nPRESS ANY KEY TO SCROLL";
	getch();
	gotoxy(20,7);
	cout<<" __________";
	gotoxy(20,8);
	cout<<"|          |";
	gotoxy(20,9);
	cout<<"|          |";
	gotoxy(20,10);
	cout<<"|          |";
	gotoxy(20,11);
	cout<<"|          |";
	gotoxy(20,12);
	cout<<"|          |";
	gotoxy(20,13);
	cout<<"|          |";
	gotoxy(20,14);
	cout<<"|          |";
	gotoxy(20,15);
	cout<<"|          |";
	gotoxy(20,16);
	cout<<"|__________|";
	srand(time(0));
	e[0]=rand()%9;
	gotoxy(21,8);
	cout<<e[0];
	gotoxy(30,16);
	cout<<e[0];
	getch();
	gotoxy(33,7);
	cout<<" __________";
	gotoxy(33,8);
	cout<<"|          |";
	gotoxy(33,9);
	cout<<"|          |";
	gotoxy(33,10);
	cout<<"|          |";
	gotoxy(33,11);
	cout<<"|          |";
	gotoxy(33,12);
	cout<<"|          |";
	gotoxy(33,13);
	cout<<"|          |";
	gotoxy(33,14);
	cout<<"|          |";
	gotoxy(33,15);
	cout<<"|          |";
	gotoxy(33,16);
	cout<<"|__________|";
	srand(time(0));
	e[1]=rand()%9;
	gotoxy(34,8);
	cout<<e[1];
	gotoxy(43,16);
	cout<<e[1];
	getch();
	gotoxy(46,7);
	cout<<" __________";
	gotoxy(46,8);
	cout<<"|          |";
	gotoxy(46,9);
	cout<<"|          |";
	gotoxy(46,10);
	cout<<"|          |";
	gotoxy(46,11);
	cout<<"|          |";
	gotoxy(46,12);
	cout<<"|          |";
	gotoxy(46,13);
	cout<<"|          |";
	gotoxy(46,14);
	cout<<"|          |";
	gotoxy(46,15);
	cout<<"|          |";
	gotoxy(46,16);
	cout<<"|__________|";
	srand(time(0));
	e[2]=rand()%9;
	gotoxy(47,8);
	cout<<e[2];
	gotoxy(56,16);
	cout<<e[2];
	if((e[0]==e[1])&&(e[1]==e[2])&&(e[0]==e[2]))
	{	gotoxy(59,12);
		cout<<" YOU WON";
		getch();
		game();
	}
	else
	{	gotoxy(59,12);
		cout<<" YOU LOOSE";
		getch();
		game();
	}
}
class stb
{   
	public:
		stb()
		{}
		~stb()
		{}
		int x1,h,d1[100],g,p1,e1,y1;
		void patt(int);
		void patt1();
		void bullet(int);
		void shoot(int);
		void stb1();
		void rules();
}s2;
void stb::patt(int x1)
{	gotoxy(x1,22);
	cout<<" __";
	gotoxy(x1,23);
	cout<<"|===|";
	gotoxy(x1,24);
	cout<<"|===|";
	gotoxy(x1,25);
	cout<<"|===|";
}
void stb::patt1()
{       
	for(int i=5;i<80;i=i+5)
	{	gotoxy(i,1);
		cout<<" ___";
		gotoxy(i,2);
		cout<<"|   |";
		gotoxy(i,3);
		cout<<"|   |";
		gotoxy(i,4);
		cout<<"|___|";
	}
	for(int i=15;i<70;i=i+5)
	{	gotoxy(i,5);
		cout<<" ___";
		gotoxy(i,6);
		cout<<"|   |";
		gotoxy(i,7);
		cout<<"|   |";
		gotoxy(i,8);
		cout<<"|___|";
	}
	for(int i=25;i<60;i=i+5)
	{	gotoxy(i,9);
		cout<<" ___";
		gotoxy(i,10);
		cout<<"|   |";
		gotoxy(i,11);
		cout<<"|   |";
		gotoxy(i,12);
		cout<<"|___|";
	}
	gotoxy(22,3);
	cout<<"?";
	gotoxy(42,3);
	cout<<"?";
	gotoxy(62,3);
	cout<<"?";
	gotoxy(32,7);
	cout<<"?";
	gotoxy(52,7);
	cout<<"?";
}
void stb::bullet(int g)
{       
	h=20;
	while(h>g)
	{	gotoxy(x1+2,h);
		cout<<"|";
		 _setcursortype(0,0);
		Sleep(50);
		gotoxy(x1+2,h);
		cout<<"  ";
		h=h-2;
	}
}
void stb::shoot(int x1)
{	 
	if(d1[5]==1&&d1[10]==1&&d1[70]==1&&d1[75]==1&&d1[15]==2&&d1[20]==2&&d1[60]==2&&d1[65]==2&&d1[25]==3&&d1[30]==3&&d1[35]==3&&d1[40]==3&&d1[45]==3&&d1[50]==3&&d1[55]==3)
	{	
		gotoxy(25,16);
		cout<<"CONGRATULATIONS!!! YOU WIN";
		getch();
		game();
	}
	if(x1==5||x1==10||x1==70||x1==75)
	{  
	    if(d1[x1]==0)
		{	g=4;
			bullet(g);
			for(int mn=1;mn<5;mn++)
			{	gotoxy(x1,mn);
				cout<<"     ";
			}
			d1[x1]++;
		}
	}   //end of (x==5||x==10||x==70||x==75)
	else if(x1==15||x1==65)
	{
		if(d1[x1]==0)
		{   
			g=8;
			bullet(g);
			for(int mn=5;mn<9;mn++)
			{
				gotoxy(x1,mn);
				cout<<"     ";
			}
			d1[x1]++;
		}
		else if(d1[x1]==1)
		{
			g=4;
			bullet(g);
			for(int mn=1;mn<5;mn++)
			{	
				gotoxy(x1,mn);
				cout<<"     ";
			}
			d1[x1]++;
		}
	}   //end of (x==15||x==65)
	else if(x1==25||x1==55||x1==35||x1==45)
	{
		if(d1[x1]==0)
		{
			g=12;
			bullet(g);
			for(int mn=9;mn<13;mn++)
			{
				gotoxy(x1,mn);
				cout<<"     ";
			}
			d1[x1]++;
		}
		else if(d1[x1]==1)
		{
			g=8;
			bullet(g);
			for(int mn=5;mn<9;mn++)
			{
				gotoxy(x1,mn);
				cout<<"     ";
			}
			d1[x1]++;
		}
		else if(d1[x1]==2)
		{
			g=4;
			bullet(g);
			for(int mn=1;mn<5;mn++)
			{
				gotoxy(x1,mn);
				cout<<"     ";
			}
			d1[x1]++;
		}
	}  //end of (x==25||x==55||x==35||x==45)
	else if(x1==20||x1==30||x1==40||x1==50||x1==60)
	{
		if(x1==20||x1==60)
		{
			if(d1[x1]==0)
			{
				g=8;
				bullet(g);
				for(int mn=5;mn<9;mn++)
				{
					gotoxy(x1,mn);
					cout<<"     ";
				}
				d1[x1]++;
			}  //end of (d[x]==0)
			else if(d1[x1]==1)
			{
				g=4;
				bullet(g);
				p1=rand()%4;
				if(p1==0)
				{
					for(int mn=1;mn<9;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]=2;
					if(x1==20)
					{	for(int mn=1;mn<9;mn++)
						{	gotoxy(x1-5,mn);
							cout<<"     ";
						}
						d1[x1-5]=2;
					} //end of if(x==20)
					else if(x1==60)
					{	for(int mn=1;mn<9;mn++)
						{	gotoxy(x1+5,mn);
							cout<<"     ";
						}
						d1[x1+5]=2;
					}//end of else if(x==60)
				}//end ofif(p==0)
				else if(p1==1)
				{	for(int mn=1;mn<9;mn=mn+4)
					{	gotoxy(x1,mn);
						cout<<" ___";
						gotoxy(x1,mn+1);
						cout<<"|   |";
						gotoxy(x1,mn+2);
						cout<<"|   |";
						gotoxy(x1,mn+3);
						cout<<"|___|";
					}
					d1[x1]=0;
					if(x1==20)
					{	for(int mn=1;mn<9;mn=mn+4)
						{	gotoxy(x1-5,mn);
							cout<<" ___";
							gotoxy(x1-5,mn+1);
							cout<<"|   |";
							gotoxy(x1-5,mn+2);
							cout<<"|   |";
							gotoxy(x1-5,mn+3);
							cout<<"|___|";
						}
						d1[x1-5]=0;
					} //end of if(x==20)
					else if(x1==60)
					{	for(int mn=1;mn<9;mn=mn+4)
					{	gotoxy(x1+5,mn);
						cout<<" ___";
						gotoxy(x1+5,mn+1);
						cout<<"|   |";
						gotoxy(x1+5,mn+2);
						cout<<"|   |";
						gotoxy(x1+5,mn+3);
						cout<<"|___|";
					}
						d1[x1+5]=0;

					}//end of else if(x==60)
					gotoxy(x1+2,3);
					cout<<"?";
				}//end ofif(p==1)
				else if(p1==2)
				{	e1=e1+5;
					for(int mn=1;mn<5;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]++;
				}  //end of else if(p==2)
				else if(p1==3)
				{	e1=e1-5;
					for(int mn=1;mn<5;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]++;
				}// end ofelse if(p==3)
			}// end of else if(d[x]==1)
			else
			{	g=0;
				bullet(g);
			} // end of else
		}//end of if(x==20||x==60)
		else if(x1==30||x1==50)
		{   
		    if(d1[x1]==0)
			{	g=12;
				bullet(g);
				for(int mn=9;mn<13;mn++)
				{	gotoxy(x1,mn);
					cout<<"     ";
				}
				d1[x1]++;
			}  //end of (d[x]==0)
			else if(d1[x1]==2)
			{	g=4;
				bullet(g);
				for(int mn=1;mn<5;mn++)
				{	gotoxy(x1,mn);
					cout<<"     ";
				}
				d1[x1]++;
			}  //end of (d[x]==2)
			else if(d1[x1]==1)
			{ 
			    g=8;
				bullet(g);
				p1=rand()%4;
				if(p1==0)
				{
					for(int mn=1;mn<13;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]=3;
					if(x1==30)
					{	for(int mn=1;mn<13;mn++)
						{	gotoxy(x1-5,mn);
							cout<<"     ";
						}
						d1[x1-5]=3;
					} //end of if(x==30)
					else if(x1==50)
					{	for(int mn=1;mn<13;mn++)
						{	gotoxy(x1+5,mn);
							cout<<"     ";
						}
						d1[x1+5]=3;
					}//end of else if(x==60)
				}//end ofif(p==0)
				else if(p1==1)
				{	for(int mn=1;mn<13;mn=mn+4)
					{	gotoxy(x1,mn);
						cout<<" ___";
						gotoxy(x1,mn+1);
						cout<<"|   |";
						gotoxy(x1,mn+2);
						cout<<"|   |";
						gotoxy(x1,mn+3);
						cout<<"|___|";
					}
					d1[x1]=0;
					if(x1==20)
					{	for(int mn=1;mn<13;mn=mn+4)
						{	gotoxy(x1-5,mn);
							cout<<" ___";
							gotoxy(x1-5,mn+1);
							cout<<"|   |";
							gotoxy(x1-5,mn+2);
							cout<<"|   |";
							gotoxy(x1-5,mn+3);
							cout<<"|___|";
						}
						d1[x1-5]=0;
					} //end of if(x==30)
					else if(x1==50)
					{	for(int mn=1;mn<13;mn=mn+4)
						{	gotoxy(x1+5,mn);
							cout<<" ___";
							gotoxy(x1+5,mn+1);
							cout<<"|   |";
							gotoxy(x1+5,mn+2);
							cout<<"|   |";
							gotoxy(x1+5,mn+3);
							cout<<"|___|";
						}
						d1[x1+5]=0;

					}//end of else if(x==50)
					gotoxy(x1+2,7);
					cout<<"?";
				}//end ofif(p==1)
				else if(p1==2)
				{	e1=e1+5;
					for(int mn=5;mn<9;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]++;
				}  //end of else if(p==2)
				else if(p1==3)
				{	e1=e1-5;
					for(int mn=5;mn<9;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]++;
				}// end ofelse if(p==2)
			}// end of else if(d[x]==1)
			else
			{	g=0;
				bullet(g);
			} // end of else
		}//end of if(x==30||x==50)
		else if(x1==40)
		{   
		    if(d1[x1]==0)
			{	g=12;
				bullet(g);
				for(int mn=9;mn<13;mn++)
				{	gotoxy(x1,mn);
					cout<<"     ";
				}
				d1[x1]++;
			}  //end of (d[x]==0)
			else if(d1[x1]==1)
			{	g=8;
				bullet(g);
				for(int mn=5;mn<9;mn++)
				{	gotoxy(x1,mn);
					cout<<"     ";
				}
				d1[x1]++;
			}  //end of (d[x]==1)
			else if(d1[x1]==2)
			{
				g=4;
				bullet(g);
				p1=rand()%4;
				if(p1==0)
				{
					for(int mn=1;mn<13;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]=3;
					for(int mn=1;mn<13;mn++)
					{	gotoxy(x1-5,mn);
						cout<<"     ";
					}
					d1[x1-5]=3;
					for(int mn=1;mn<13;mn++)
					{	gotoxy(x1+5,mn);
						cout<<"     ";
					}
					d1[x1+5]=3;
				}//end ofif(p==0)
				else if(p1==1)
				{   for(int mn=1;mn<13;mn=mn+4)
					{	gotoxy(x1,mn);
						cout<<" ___";
						gotoxy(x1,mn+1);
						cout<<"|   |";
						gotoxy(x1,mn+2);
						cout<<"|   |";
						gotoxy(x1,mn+3);
						cout<<"|___|";
					}
					d1[x1]=0;
					for(int mn=1;mn<13;mn=mn+4)
					{	gotoxy(x1-5,mn);
						cout<<" ___";
						gotoxy(x1-5,mn+1);
						cout<<"|   |";
						gotoxy(x1-5,mn+2);
						cout<<"|   |";
						gotoxy(x1-5,mn+3);
						cout<<"|___|";
					}
					d1[x1-5]=0;
					for(int mn=1;mn<13;mn=mn+4)
					{	gotoxy(x1+5,mn);
						cout<<" ___";
						gotoxy(x1+5,mn+1);
						cout<<"|   |";
						gotoxy(x1+5,mn+2);
						cout<<"|   |";
						gotoxy(x1+5,mn+3);
						cout<<"|___|";
					}
					d1[x1+5]=0;
					gotoxy(x1+2,3);
					cout<<"?";
				}//end ofif(p==1)
				else if(p1==2)
				{	e1=e1+5;
					for(int mn=1;mn<5;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]++;
				}  //end of else if(p==2)
				else if(p1==3)
				{	e1=e1-5;
					for(int mn=1;mn<5;mn++)
					{	gotoxy(x1,mn);
						cout<<"     ";
					}
					d1[x1]++;
				}// end ofelse if(p==2)
			}// end of else if(d[x]==2)
			else
			{	g=0;
				bullet(g);
			} // end of else
		}//end of if(x==40)
	}// end of(x==20||x==30||x==40||x==50||x==60)
}
void stb::rules()
{   
	system("cls");
	cout<<"\n\n\t\t\t THE RULES ARE AS FOLLOWS: ";
	//-------------- ADD RULES ---------------------
	cout<<"\n\n ";
	gotoxy(10,16);
	cout<<" ___ ";
	gotoxy(10,17);
	cout<<"|   |  -> MOVES CAN BE ADDED UP  ";
	gotoxy(10,18);
	cout<<"|   |";
	gotoxy(10,19);
	cout<<"|   |  -> MOVES CAN BE DEDUCTED  ";
	gotoxy(10,20);
	cout<<"| ? |";
	gotoxy(10,21);
	cout<<"|   |  -> NO. OF BOXES CAN BE INCREASED ";
	gotoxy(10,22);
	cout<<"|   |";
	gotoxy(10,23);
	cout<<"|___|  -> NO. OF BOXES CAN BE DECREASED ";
	getch();
	system("cls");
	s2.stb1();
}
void stb::stb1()
{	system("cls");
	x1=40;
	patt1();
	patt(x1);
	srand(time(0));
	while(e1<20)
	{   
		gotoxy(2,15);
		y1=getche();
		gotoxy(2,15);
		clreol();
		for(int j=22;j<26;j++)
		{ 	for(int k=5;k<75;k++)   //main
			{	 gotoxy(k,j);
				 clreol();
			}
		}
		if((y1=='j'||y1=='J')&&(x1!=5))   //main
		x1=x1-5;
		else if((y1=='k'||y1=='K')&&(x1!=75))    //main
		x1=x1+5;
		if((x1==30)||(x1==40)||(x1==35)||(x1==25)||(x1==45)||(x1==5)||(x1==10)||(x1==15)||(x1==20)||(x1==50)||(x1==55)||(x1==60)||(x1==65)||(x1==70)||(x1==75)) //main
		  patt(x1);
		if(y1=='s'||y1=='S')
		  { shoot(x1);
			e1++;
			gotoxy(2,12);
			cout<<"NO OF MOVES USED";
			gotoxy(2,13);
			cout<<e1;
			if(e1<0&&e1>-101||e1>=10)
			{	gotoxy(4,13);
			cout<<"      ";
			}
			if(e1>=0&&e1<10)
			{	gotoxy(3,13);
			cout<<"       ";
			}
			if(e1<-9)
			{	gotoxy(5,13);
			cout<<"       ";
			}
			if(e1>19)
			{   system("cls");
				gotoxy(27,16);
				cout<<"OUT OF MOVES!!! YOU LOOSE";
				getch();
				game();
			}
		  }
		}
	getch();
}
class ttt
{	int a[10],t[10],l[10],i,j,x,y,b,c,d,ga;
	char vc;
	public:
	ttt()
	{}
	void pattern();
	void pattern1(int,int);
	void pattern2(int,int);
	int check();
	void ttt1();
	void rules();
	~ttt()
	{}
};
void ttt::rules()
{   
	system("cls");
	cout<<"\n\n\t\t\t THE RULES ARE AS FOLLOWS: \n";
	//-------------- ADD RULES ---------------------
	getch();
	system("cls");
	ttt1();
}
void ttt::ttt1()
{	
    system("cls");
	pattern();
	for(i=1,j=1;i<10;i++,j=j+2)
	{	if((i%2==1)||(i==1))
		{ 	gotoxy(55,j);
			cout<<"PLAYER 1:";
		}
		else
		{ 	gotoxy(55,j);
			cout<<"PLAYER 2:";
		}
		cin>>a[i];
		for(int k=0;k<i;k++)
		{  	if(a[i]==a[k])
			{ 	gotoxy(55,j+1);
				i--;
				cout<<" ENTER THE CORRECT CHOICE ";
			}
			else if(a[i]>9)
			{ 	gotoxy(55,j+1);
				i--;
				cout<<" ENTER THE CORRECT CHOICE ";
			}
		}
		if((i%2==1)||(i==1))
		{      	if(a[i]==1)
			{       t[1]=1;
				x=3;
				y=1;
			}
			else if(a[i]==2)
			{       t[2]=1;
				x=13;
				y=1;
			}
			else if(a[i]==3)
			{	t[3]=1;
				x=23;
				y=1;
			}
			else if(a[i]==4)
			{	t[4]=1;
				x=3;
				y=7;
			}
			else if(a[i]==5)
			{	t[5]=1;
				x=13;
				y=7;
			}
			else if(a[i]==6)
			{	t[6]=1;
				x=23;
				y=7;
			}
			else if(a[i]==7)
			{	t[7]=1;
				x=3;
				y=13;
			}
			else if(a[i]==8)
			{ 	t[8]=1;
				x=13;
				y=13;
			}
			else if(a[i]==9)
			{	t[9]=1;
				x=23;
				y=13;
			}
			pattern1(x,y);
		}
		else
		{	if(a[i]==1)
			{       l[1]=2;
				b=3;
				c=1;
			}
			else if(a[i]==2)
			{	l[2]=2;
				b=13;
				c=1;
			}
			else if(a[i]==3)
			{	l[3]=2;
				b=23;
				c=1;
			}
			else if(a[i]==4)
			{	l[4]=2;
				b=3;
				c=7;
			}
			else if(a[i]==5)
			{	l[5]=2;
				b=13;
				c=7;
			}
			else if(a[i]==6)
			{       l[6]=2;
				b=23;
				c=7;
			}
			else if(a[i]==7)
			{	l[7]=2;
				b=3;
				c=13;
			}
			else if(a[i]==8)
			{	l[8]=2;
				b=13;
				c=13;
			}
			else if(a[i]==9)
			{	l[9]=2;
				b=23;
				c=13;
			}
			pattern2(b,c);
		}
		d=check();
		if(d==0)
		break;
	}
	if(d==1)
	{	gotoxy(1,20);
		cout<<"THE MATCH IS DRAW";
		getch();
		game();
	}
	getch();
	return;

}
void ttt::pattern()
{	for(int i=1;i<18;i++)
	{	 gotoxy(10,i);
		 cout<<"|";
	}
	for(int i=1;i<18;i++)
	{	 gotoxy(20,i);
		 cout<<"|";
	}
	for(int i=1;i<30;i++)
	{	 gotoxy(i,6);
		 cout<<"-";
	}
	for(int i=1;i<30;i++)
	{	 gotoxy(i,12);
		 cout<<"-";
	}
}
void ttt::pattern1(int x, int y)
{      	gotoxy(x,y);
	cout<<"+++++";
	gotoxy(x,y+1);
	cout<<"+   +";
	gotoxy(x,y+2);
	cout<<"+   +";
	gotoxy(x,y+3);
	cout<<"+   +";
	gotoxy(x,y+4);
	cout<<"+++++";
}
void ttt::pattern2(int b,int c)
{       gotoxy(b,c);
	cout<<"+   +";
	gotoxy(b,c+1);
	cout<<" + +";
	gotoxy(b,c+2);
	cout<<"  + ";
	gotoxy(b,c+3);
	cout<<" + +";
	gotoxy(b,c+4);
	cout<<"+   +";
}
int ttt::check()
{	if(((t[1]==1)&&(t[2]==1)&&(t[3]==1))||((t[4]==1)&&(t[5]==1)&&(t[6]==1))||((t[7]==1)&&(t[8]==1)&&(t[9]==1))||((t[1]==1)&&(t[4]==1)&&(t[7]==1))||((t[2]==1)&&(t[5]==1)&&(t[8]==1))||((t[3]==1)&&(t[6]==1)&&(t[9]==1))||((t[1]==1)&&(t[5]==1)&&(t[9]==1))||((t[3]==1)&&(t[5]==1)&&(t[7]==1)))
	{       gotoxy(20,20);
		cout<<"\n PLAYER 1 WINS";
		getch();
		game();
	}
	else if(((l[1]==2)&&(l[2]==2)&&(l[3]==2))||((l[4]==2)&&(l[5]==2)&&(l[6]==2))||((l[7]==2)&&(l[8]==2)&&(l[9]==2))||((l[1]==2)&&(l[4]==2)&&(l[7]==2))||((l[2]==2)&&(l[5]==2)&&(l[8]==2))||((l[3]==2)&&(l[6]==2)&&(l[9]==2))||((l[1]==2)&&(l[5]==2)&&(l[9]==2))||((l[3]==2)&&(l[5]==2)&&(l[7]==2)))
	{       gotoxy(20,20);
		cout<<"\n PLAYER 2 WINS";
		getch();
		game();
	}
	else
	return 1;
}
class sh
{	int j,q,g,h,i,ch,x1,x,y,w,z1,z,s,r1,r2;
	public:
	sh()
	{}
	void pattern(int);
	int check();
	void p1();
	void p2();
	void call();
	void sh1();
	void rules();
	~sh()
	{}
};
void sh::rules()
{      
       system("cls");
       cout<<"\n\n\t\t\t THE RULES ARE AS FOLLOWS: \n";
       //-------------- ADD RULES ---------------------
       getch();
       system("cls");
       sh1();
}
void sh::pattern(int x1)
{	gotoxy(x1,22);
	cout<<" ___";
	gotoxy(x1,23);
	cout<<"|   |";
	gotoxy(x1,24);
	cout<<"|===|";
	gotoxy(x1,25);
	cout<<"|___|";
	return;
}
int sh::check()
{	if(((x1==y)||(x1==z)||(x1==z1))&&((i+3==21)||(i+3==23)||(i+3==25)||(i+3==22)||(i+3==24)))
	return 1;
	else
	{       s++;
		r2++;
		return 0;
	}
}
void sh::call()
{		gotoxy(3,1);
		ch=getche();
		gotoxy(3,1);
		cout<<" ";
		gotoxy(x1,22);
		cout<<"     ";
		gotoxy(x1,23);
		cout<<"     ";
		gotoxy(x1,24);
		cout<<"     ";
		gotoxy(x1,25);
		cout<<"     ";
		if((ch=='a'||ch=='A'))   //main
		x1=x1-5;
		else if((ch=='l'||ch=='L'))   //main
		x1=x1+5;
		if((x1==21)||(x1==51))
		{	gotoxy(5l,13);
			cout<<"GAME OVER";
			getch();
			Sleep(2000);
			game();
		}
		if((x1==31)||(x1==36)||(x1==26)||(x1==41)||(x1==46))
		pattern(x1);
		return;
}
void sh::p1()
{	for( j=1;j<25;j+=2)
	{	gotoxy(25,j);
		cout<<"|";
		gotoxy(51,j);
		cout<<"|";
	}
	for( j=2;j<25;j+=2)
	{	gotoxy(25,j);
		cout<<" ";
		gotoxy(51,j);
		cout<<" ";
	}
}
void sh::p2()
{	for( j=1;j<25;j+=2)
	{	gotoxy(25,j);
		cout<<" ";
		gotoxy(51,j);
		cout<<" ";
	}
	for( j=2;j<25;j+=2)
	{	gotoxy(25,j);
		cout<<"|";
		gotoxy(51,j);
		cout<<"|";
	}
}
void sh::sh1()
{	
    system("cls");
	x1=31,y=25,s=0,r1=25,r2=0;
	srand(time(0));
	_setcursortype(0,0);
	gotoxy(30,13);
	cout<<"L=> RIGHT";
	gotoxy(30,14);
	cout<<"A=> LEFT";
	gotoxy(30,17);
	cout<<"PRESS ANY KEY TO START";
	getch();
	system("cls");
	pattern(x1);
	while(q!=1)
	{	while(!kbhit())
		{	w=rand()%5;
			y=(26+(5*w));
			w=rand()%5;
			z=(26+(5*w));
			w=rand()%5;
			z1=(26+(5*w));
			for(i=1;i<22;i++)
			{       gotoxy(55,20);
				cout<<"YOUR SCORE IS:"<<s;
				if(r2>500)
				{	r1-=3;
					r2=0;
				}
				gotoxy(y,i);
				cout<<" __ ";
				gotoxy(y,i+1);
				cout<<"|  |";
				gotoxy(y,i+2);
				cout<<"|  |";
				gotoxy(y,i+3);
				cout<<"|__|";
				gotoxy(z,i);
				cout<<" __ ";
				gotoxy(z,i+1);
				cout<<"|  |";
				gotoxy(z,i+2);
				cout<<"|  |";
				gotoxy(z,i+3);
				cout<<"|__|";
				gotoxy(z1,i);
				cout<<" __ ";
				gotoxy(z1,i+1);
				cout<<"|  |";
				gotoxy(z1,i+2);
				cout<<"|  |";
				gotoxy(z1,i+3);
				cout<<"|__|";
				if(kbhit())
				call();
				q=check();
				if(q==1)
				{	gotoxy(5,13);
					cout<<"GAME OVER";
					getch();
					Sleep(2000);
					game();
				}
				Sleep(r1);
				p1();
				Sleep(r1);
				p2();
				if(i==21)
				{   gotoxy(y,i+3);
					cout<<"|  |";
					gotoxy(y,i);
					cout<<"    ";
					gotoxy(y,i+1);
					cout<<" __ ";
					Sleep(5);
					gotoxy(y,i+2);
					cout<<" __ ";
					gotoxy(y,i+1);
					cout<<"    ";
					Sleep(5);
					gotoxy(y,i+2);
					cout<<"    ";
					gotoxy(y,i+3);
					cout<<" __ ";
					Sleep(5);
					gotoxy(y,i+3);
					cout<<"    ";

					gotoxy(z,i+3);
					cout<<"|  |";
					gotoxy(z,i);
					cout<<"    ";
					gotoxy(z,i+1);
					cout<<" __ ";
					Sleep(5);
					gotoxy(z,i+2);
					cout<<" __ ";
					gotoxy(z,i+1);
					cout<<"    ";
					Sleep(5);
					gotoxy(z,i+2);
					cout<<"    ";
					gotoxy(z,i+3);
					cout<<" __ ";
					Sleep(5);
					gotoxy(z,i+3);
					cout<<"    ";

					gotoxy(z1,i+3);
					cout<<"|  |";
					gotoxy(z1,i);
					cout<<"    ";
					gotoxy(z1,i+1);
					cout<<" __ ";
					Sleep(5);
					gotoxy(z1,i+2);
					cout<<" __ ";
					gotoxy(z1,i+1);
					cout<<"    ";
					Sleep(5);
					gotoxy(z1,i+2);
					cout<<"    ";
					gotoxy(z1,i+3);
					cout<<" __ ";
					Sleep(5);
					gotoxy(z1,i+3);
					cout<<"    ";
				}
				else
				{	gotoxy(y,i);
					cout<<"    ";
					gotoxy(z,i);
					cout<<"    ";
					gotoxy(z1,i);
					cout<<"    ";
				}
			}

		}
	}
	getch();
	return;
}

int porr()
{   
    system("cls");
	int q;
	system("cls");
	cout<<"\n";
	cout<<"\n 1. PLAY";
	cout<<"\n 2. RULES";
	cout<<"\n\n ENTER YOUR CHOICE: ";
	cin>>q;
	return q;
}
void game()
{   
    system("cls");
	int choice;
	cout<<"\n";
	cout<<"\t ____________________________________________________\n";
	cout<<"\t|      |                                            |\n";
	cout<<"\t| S.NO |                    GAMES                   |\n";
	cout<<"\t|______|____________________________________________|\n";
	cout<<"\t|      |                                            |\n";
	cout<<"\t|  1.  |                SLOT MACHINE                |\n";
	cout<<"\t|      |                                            |\n";
	cout<<"\t|  2.  |             SHOOTING THE BOXES             |\n";
	cout<<"\t|      |                                            |\n";
	cout<<"\t|  3.  |                TIC-TAC-TOE                 |\n";
	cout<<"\t|      |                                            |\n";
	cout<<"\t|  4.  |                REAL RACING                 |\n";
	cout<<"\t|______|____________________________________________|\n";
	gotoxy(10,16);
	cout<<"IF YOU WANT TO EXIT, PLEASE PRESS '0'";
	gotoxy(10,18);
	cout<<"WHICH GAME YOU WANT TO PLAY ? ";
	cin>>choice;
	if(choice==0)
	{	
	    system("cls");
		exit(0);
	}
	gotoxy(10,20);
	executing(choice);
}
void executing(int choice)
{   
	int cho;
	switch(choice)
	{
		case 1: cho=porr();
				if(cho==1)
				{ 
					sm s1;
					s1.sm1();
					game();
			  	}
			  	else
			  	{ 
				  	sm s1;
					s1.rules();
			  	}
		case 2: cho=porr();
			    if(cho==1)
			  	{
					s2.stb1();
					game();
			  	}
			  	else
			  	{
					s2.rules();
				}
		case 3: cho=porr();
			  	if(cho==1)
			  	{ 
				  	ttt s3;
					s3.ttt1();
					game();
			  	}
			  	else
			  	{ 
				  	ttt s3;
					s3.rules();
			  	}
		case 4: cho=porr();
			  	if(cho==1)
			  	{
				  	sh s4;
					s4.sh1();
					game();
			  	}
			    else
			   	{ 
					sh s4;
					s4.rules();
			    }
		default: cout<<" WRONG CHOICE ";
			  	 game();
	}
}
int main()
{	
	system("cls");
	_setcursortype(0,0);
	game();
	getch();
	return 0;
}
