#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <string>
int m[20][20]={0};
int xh=3,yh=0,head=4;
using namespace std;
class dod{
public:
///////////////////////////////////////////////////////
void start(){
for(int i=0;i<20;i++){
for(int j=0;j<20;j++){m[i][j]=0;}
}
m[0][0]=1;m[1][0]=2;m[2][0]=3;m[3][0]=4;
}
///////////////////////////////////////////////////////
void print(){
for(int i=0;i<20;i++){
for(int j=0;j<20;j++){

if((m[i][j])==0){cout<<" ";}
else if((m[i][j])==-5){cout<<"v";}
else
{cout<<"O";}
/////{cout<<m[i][j];}
}
cout<<endl;
}
}
////////////////////////////////////////////////////////
int ch(char in){
int tx=0,ty=0;
switch(in){
case'w':tx=-1;break;
case's':tx=1;break;
case'a':ty=-1;break;
case'd':ty=1;break;
}
if(m[tx+xh][ty+yh]==0){return 0;}
else if(m[tx+xh][ty+yh]==-5){return 1;}
else return 2;
}
////////////////////////////////////////////////////////
void a_dd(char c){
head++;
switch(c){
case'w':m[xh-1][yh]=head;break;
case's':m[xh+1][yh]=head;break;
case'a':m[xh][yh-1]=head;break;
case'd':m[xh][yh+1]=head;break;
}
}
///////////////////////////////////////////////////////
void mov(char con){
switch(con){
case'w':m[xh-1][yh]=head+1;xh--;break;
case's':m[xh+1][yh]=head+1;xh++;break;
case'a':m[xh][yh-1]=head+1;yh--;break;
case'd':m[xh][yh+1]=head+1;yh++;break;
default:break;
}
if(xh==20){xh=0;}
if(yh==20){yh=0;}
if(xh<0){xh=20;}
if(yh<0){yh=20;}
for(int i=0;i<20;i++){
for(int j=0;j<20;j++){if(m[i][j]>0){m[i][j]--;}}
}
}
///////////////////////////////////////////////////////
int rad(){
for(int i=0;i<20;i++){
for(int j=0;j<20;j++){if(m[i][j]==-5){m[i][j]=0;}}
}
while(1==1){
srand(time(0));
int rx,ry;
rx=rand()%20;ry=rand()%20;
if(m[rx][ry]==0){m[rx][ry]=-5;break;}
}
}
//////////////////////////////////////////////////////
}dod;
int main()
{
dod.start();
while(1==1){
dod.rad();
for(int i=0;i<10;i++){
system("clear");
dod.print();
char control;
//if((control=getchar())=='w'){control ='w';}
cin>>control;
int check=dod.ch(control);
///cout<<check<<endl;
dod.mov(control);
if(check==0){dod.mov(control);}
if(check==1){dod.a_dd(control);}
if(check==2){ system("clear");dod.print();cout<<endl<<"you lose "<<endl;}
}
}
return 0;
}
