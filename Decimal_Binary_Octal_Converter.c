#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{COORD c;c.X=x;c.Y=y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);}

double converter(double n,int from,int to)
{
	int i,a,c=n;
	double j,b,d=n-c;    

	for(i=1,a=0;c!=0;i*=from) 
		{
			a+=(c%to)*i;
	        c/=to;
	    }

	for(j=1,b=0;d!=0;j/=from) 
		{
			b+=int(d)*j;
			d=(d-int(d))*to;
		}

	return a+b;
}

int main()
{
	system("mode con: lines=20 cols=60");

    int end=1;
    system("cls");
	int from,to; double n;
    
    gotoxy(10,1);printf("DECIMAL-BINARY-OCTAL CONVERTER");
	gotoxy(1,3);printf("(2->Binary , 8->Octal , 10->Decimal) \n Base of the number to be converted : ");
	scanf("%d",&from);

	gotoxy(1,7); printf("Enter the number : ");
	gotoxy(20,5);printf(" ________________________");
	gotoxy(20,6);printf("|                        |");
    gotoxy(20,7);printf("|                        |");
    gotoxy(20,8);printf("|________________________|");
	gotoxy(22,7); scanf("%lf",&n);

	gotoxy(1,10);printf("Base of the number converted to : ");
	scanf("%d",&to);

	gotoxy(1,13); printf("Converted number : ");
	gotoxy(20,11);printf(" ________________________");
	gotoxy(20,12);printf("|                        |");
    gotoxy(20,13);printf("|                        |");
    gotoxy(20,14);printf("|________________________|");
	gotoxy(22,13);n=converter(n,from,to);(n==(long long)n)?printf("%22.0lf",n):printf("%22lf",n);
	gotoxy(20,15);printf("\n");
}