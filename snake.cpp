#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<unistd.h>
using namespace std;
bool gameover;
const int width=20;
const int height =20;
int x,y,fruitx,fruity,score;
enum eDirection{STOP=0, LEFT,RIGHT,UP,DOWN};
eDirection dir;
void Setup()
{
	gameover=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx= rand()%width;
	fruity= rand()%height;
	score=0;
}
void draw()
{
	system("cls");
	for(int i=0;i<width+1;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
			{
				cout<<"#";
			}
			if(i==x && y==j)
			{
				cout<<"O";
			}
			else if(i==fruitx && j==fruity)
			{
				cout<<"F";
			}
			else
			cout<<" ";
			if(j==width-1)
			{
				cout<<"#";
			}
			
		}
		cout<<endl;
	}
	for(int i=0;i<width+1;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	cout<<"scrore:"<<score;
}

void input(){
	if(_kbhit()){
		switch(_getch())
		{
			case'a':
				dir=LEFT;
				break;
			case'd':
				dir=RIGHT;
				break;
			case'w':
				dir=UP;
				break;
			case's':
				dir=DOWN;
				break;
			case 'x':
				gameover=true;
				break;
		}
	}
}
void logic()
{
	switch (dir){
		case LEFT :
			sleep(1/9);
			y--;
			break;
			case RIGHT :
				sleep(1/9);
			y++;
			break;
			case UP :
			sleep(1/9);
			x--;
			break;
			case DOWN :
				sleep(1/9);
			x++;
			break;
			default:
			break;
	}
	if(x>width || x<0 || y>height || y<0)
	{
		gameover = true;
	}
	if(x==fruitx && y==fruity)
	{
		score++;
		fruitx= rand()%width;
	fruity= rand()%height;
	}
}
main()
{
	Setup();
	while(!gameover){
		draw();
		input();
		
		logic();
	}
}
