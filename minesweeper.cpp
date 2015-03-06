/*
MINESWEEPER GAME IN C++

Created By :Rameshwar Bhaskaran
Date: 6th March 2015 

You are free to distribute,copy,modify and use the code as long as this comment header stays intact .
You may modify the code ,but please do cite the original source.

DISCLAIMER: The author of this code is not responsible for anything wrong that may happen by executing this code 

*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<assert.h>

using namespace std;

int matrix[9][9],visited[9][9],number_of_mines=0;

int no_of_neighbouring_mines(int i,int j)
{
int k,l;
int count=0; //count of neighboring mines
for(k=-1;k<=1;k++)
{
for(l=-1;l<=1;l++)
{
if(matrix[i+k][j+l]==1 && i+k>=0 && i+k<=8 && j+l>=0 &&j+l<=8)
count++;
}
}
return count;
}

int main()
{

//randomly allocating values to the matrix
srand(time(NULL));
int i,j;
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
matrix[i][j]=rand()%2;
if(matrix[i][j]==1)
number_of_mines++;
// 1 signifies mine ,0 its absence
visited[i][j]=0; 
//visited array holds 1 if visited ,else 0
}
}
//sample test- game without graphics and manually entering coordinates
while(1)
{
//printing the matrix
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
if(visited[i][j]==1)
printf("%d |",no_of_neighbouring_mines(i,j));
else
printf("  |");
}
printf("\n");
}

printf("\n \n Enter the coordinates to be selected ,enter -1 -1 to break :");
int x,y;
scanf("%d %d",&x,&y);
visited[x][y]=1;
if(x==-1 || y==-1)
break;
assert(x<9 && x>=0 && y>=0 &&y<9);
int gameon=number_of_mines;
if(matrix[x][y]==1)
{
printf("you lost!!\n");
break;
}
else
{
printf("%d\n",no_of_neighbouring_mines(x,y));
gameon--;
}
if(gameon==0)
{
printf("\n\n *****YOU WIN !!! ********");
break;
}
}
return 0;
}

