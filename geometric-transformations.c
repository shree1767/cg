#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
int gd=DETECT,gm,i,j,k,ch;
float tx,ty,x,y,ang,n,temp;
float a[5][3],si,co,b[5][3],c[5][3];
initgraph(&gd,&gm,"z:\\turboc3\\bgi");
n=4;
a[0][0]=0;
a[0][1]=0;
a[1][0]=100;
a[1][1]=0;
a[2][0]=100;
a[2][1]=100;
a[3][0]=0;
a[3][1]=100;
a[4][0]=0;
a[4][1]=0;
while(1)
{
cleardevice();

gotoxy(1,8);
printf("\n\t****program to perform 2d Transformations*****");
printf("\n\t 1.accept the polygon");
printf("\n\t 2.perform translation");
printf("\n\t 3.perform scaling");
printf("\n\t 4.perform rotation");
printf("\n\t 5.perform reflection");
printf("\n\t 6.perform shearing");
printf("\n\t 7.exit");
printf("\n\t Enter ur choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
cleardevice();
gotoxy(1,1);
printf("\n\t Enter no of points:");
scanf("%f",&n);
for(i=0;i<n;i++)
{
printf("\n\t Enter x,y coordinates for %d:",i+1);
scanf("%f%f",&a[i][0],&a[i][1]);
}
a[i][0]=a[0][0];
a[i][1]=a[0][1];
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
case 2:
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
gotoxy(1,1);
printf("enter translation vector tx and ty \n\t:");
scanf("%f%f",&x,&y);
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0]+x,240-a[i][1]+y,320+a[i+1][0]+x,240-a[i+1][1]+y);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
case 3:
cleardevice();

for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
gotoxy(1,1);
printf("enter scaling vector tx and ty \n\t:");
scanf("%f%f",&x,&y);
if(x==0)
x=1;
if(y==0)
y=1;
cleardevice();
for(i=0;i<n;i++)
line(320+(a[i][0]*x),240-(a[i][1]*y),320+(a[i+1][0]*x),240-(a[i+1][1]*y));
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
case 4:
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
gotoxy(1,1);
printf("enter angle of rotation\n\t:");
scanf("%f",&ang);
ang=ang*0.01745;
gotoxy(1,3);
printf("enter the point of rotation\n\t");
scanf("%f%f",&x,&y);
gotoxy(1,5);
printf("1.clockwise 2.anti clockwise \n\t");
scanf("%d",&k);
si=sin(ang);
co=cos(ang);
for(i=0;i<n+1;i++)
{
c[i][0]=a[i][0];
c[i][1]=a[i][1];
c[i][2]=1;
}
b[0][0]=co;
b[0][1]=si;
b[0][2]=0;
b[1][0]=(-si);
b[1][1]=co;
b[1][2]=0;
b[2][0]=(-x*co)+(y*si)+x;
b[2][1]=(-x*si)-(y*co)+y;

b[2][2]=1;
if(k==1)
{
b[0][1]=(-si);
b[1][0]=(si);
b[2][0]=(-x*co)+(y*si)+x;
b[2][1]=(-x*si)-(y*co)+y;
}
for(i=0;i<n+1;i++)
{
for(j=0;j<3;j++)
{
a[i][j]=0;
for(k=0;k<3;k++)
a[i][j]=a[i][j]+c[i][k]*b[k][j];
}
}
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
case 5:
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
gotoxy(1,1);
printf("\n1.Reflection about y-axis");
printf("\n2.Reflection about x-axis");
printf("\n3.Reflection about origin");
printf("\n4.Reflection about line y=x");
printf("\n5.Reflection about line y=-x");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
for(i=0;i<n+1;i++)
a[i][0]=a[i][0]*(-1);
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;

case 2:
for(i=0;i<n+1;i++)
a[i][1]=a[i][1]*(-1);
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
case 3:
for(i=0;i<n+1;i++)
{
a[i][1]=a[i][1]*(-1);
a[i][0]=a[i][0]*(-1);
}
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
case 4:
for(i=0;i<n+1;i++)
{
temp=a[i][0];
a[i][0]=a[i][1];
a[i][1]=temp;
}
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
line(0,479,639,0);
getch();
break;
case 5:
for(i=0;i<n+1;i++)
{
temp=a[i][0];
a[i][0]=a[i][1];
a[i][1]=temp;
}
for(i=0;i<n+1;i++)
{
a[i][1]=a[i][1]*(-1);
a[i][0]=a[i][0]*(-1);
}

cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
line(0,0,639,479);
getch();
break;
default:
break;
}
case 6:
cleardevice();
for(i=0;i<n;i++)
line(320+a[i][0],240-a[i][1],320+a[i+1][0],240-a[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
gotoxy(1,1);
printf("\n1.x shear with y reference line");
printf("\n2.y shear with x reference line");
printf("\n enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nenter the x-shear parameter value:");
scanf("%f",&temp);
printf("\n enter the yrefline:");
scanf("%f",&ty);
b[0][0]=1;
b[0][1]=0;
b[0][2]=0;
b[1][0]=temp;
b[1][1]=1;
b[1][2]=0;
b[2][0]=(-temp)*(ty);
b[2][1]=0;
b[2][2]=1;
for(i=0;i<n+1;i++)
a[i][2]=1;
for(i=0;i<n+1;i++)
{
for(j=0;j<3;j++)
{
c[i][j]=0;
for(k=0;k<3;k++)
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
cleardevice();

for(i=0;i<n;i++)
line(320+c[i][0],240-c[i][1],320+c[i+1][0],240-c[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
case 2:
printf("\n enter the y-shear parameter value:");
scanf("%f",&temp);
printf("enter the xref line: ");
scanf("%f", &tx);
b[0][0]=1;
b[0][1]=temp;
b[0][2]=0;
b[1][0]=0;
b[1][1]=1;
b[1][2]=0;
b[2][0]=0;
b[2][1]=(-temp)*(tx);
b[2][2]=1;
for(i=0;i<n+1;i++)
{
for(j=0;j<3;j++)
{
c[i][j]=0;
for(k=0;k<3;k++)
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
cleardevice();
for(i=0;i<n;i++)
line(320+c[i][0],240-c[i][1],320+c[i+1][0],240-c[i+1][1]);
line(0,240,639,240);
line(320,0,320,479);
getch();
break;
default:
break;
}
break;
case 7:
exit(1);
closegraph();
restorecrtmode();
break;
default:
break;
}
}
}
