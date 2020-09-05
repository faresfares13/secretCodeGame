#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>

//global numbers
int a = 0;
int b = 0;
int c = 0;
int d = 0;
char ua = 0;
char ub = 0;
char uc = 0;
char ud = 0;

int isMiss();
int isHit();
void crazy();
void hard();
void moderate();
void easy();
void getPassword();
int menu();
void getSecreteCode();

int main()
{ 
	srand(time(NULL));
	int playAgain = 1;
	while (playAgain == 1)
	{
		getSecreteCode();
		int choice = menu();
		switch (choice)
		{
		case 1:
			easy();
			break;
		case 2:
			moderate();
			break;
		case 3:
			hard();
			break;
		case 4:
			crazy();
			break;
		default:
			printf("Something wrong!!\nPlease restart the game.\n");
			break;
		}
		printf("Do you want to play again?\n");
		printf("for YES answer 1 | for NO answer any number\n");
		scanf("%d", &playAgain);
		system("cls");//clean the screen
	}
	printf("\nBye Bye :) \n");
	//printf("\n%d\n", choice);
	system("PAUSE");
	return 0;
}
/*
input: none
output: 4 numbers 

the function store four different random numbers 
in four varables (a,b,c,d) 
*/
void getSecreteCode()
{
	a = rand() % 5 + 1; //first number
	
	do {
		b = rand() % 5 + 1; //second number
	} while (b == a);

	do {
		c = rand() % 5 + 1; //third number
	} while (c == a || c == b);

	do {
		d = rand() % 5 + 1; //fourth number
	} while (d == a || d == b || d == c);

	//printf("%d%d%d%d\n", a,b,c,d);
}
/*
input:none
output: integer number
the function view the menu to the user,
and give the user to choice the game role
*/
int menu()
{
	int choice = 0;
	printf("\t\t\t\tWelcome to \"CODE - BREAKER\"!!!\n");

	printf("A secret password was chosen to protect the credit card of Pancratius,");
	printf("the descendant of Antiochus.\n");
	printf("Your mission is to stop Pancratius by revealing his secret password.\n");

	printf("The rules are as follows :\n");
	printf("1. In each round you try to guess the secret password(4 distinct digits)\n");
	printf("2. After every guess you'll receive two hints about the password\n");
	printf("\t@ HITS : The number of digits in your guess which were exactly right.\n");
	printf("\t@ MISSES : The number of digits in your guess which belongs to ");
	printf("the password but were miss - placed.\n");
	printf("3. If you'll fail to guess the password after a certain number of rounds");
	printf("Pancratius will buy all the gifts for Hanukkah!!!\n");

	printf("Please choose the game level :\n");
	printf("1 - Easy(20 rounds)\n");
	printf("2 - Moderate(15 rounds)\n");
	printf("3 - Hard(10 rounds)\n");
	printf("4 - Crazy(random number of rounds 5 - 25)\n");
	
	do {
		printf("Make a choice : \n");
		scanf("%d", &choice);
	} while (choice < 1 || choice>4);
	return choice;
}
void easy()
{
	int hits = 0;
	int miss = 0;
	int i = 20;
	int turn = 1;
	while (i)
	{
		getPassword();
		if (ua == ub || ua == uc || ua == ud || ub == uc || ub == ud || uc == ud)
		{
			i--;
		}
		hits = isHit();
		miss = isMiss();
		printf("Hits:%d\n", hits);
		printf("Miss:%d\n", miss);
		i--;
		printf("%d gussess left\n", i);
		if (hits == 4)
		{
			printf("******************\nGREAT!!!\n");
			printf("Congralations, You get the password in %d attempts!!\n******************\n", turn);
			i = 0;
		}
		hits = 0;
		miss = 0;
		turn++;
		
	}
	
}
void moderate()
{
	int hits = 0;
	int miss = 0;
	int i = 15;
	int turn = 1;
	while (i)
	{
		getPassword();
		if (ua == ub || ua == uc || ua == ud || ub == uc || ub == ud || uc == ud)
		{
			i--;
		}
		hits = isHit();
		miss = isMiss();
		printf("Hits:%d\n", hits);
		printf("Miss:%d\n", miss);
		i--;
		printf("%d gussess left\n", i);
		if (hits == 4)
		{
			printf("******************\nGREAT!!!\n");
			printf("Congralations, You get the password in %d attempts!!\n******************\n", turn);
			i = 0;
		}
		hits = 0;
		miss = 0;
		turn++;

	}

}
void hard()
{
	int hits = 0;
	int miss = 0;
	int i = 10;
	int turn = 1;
	while (i)
	{
		getPassword();
		if (ua == ub || ua == uc || ua == ud || ub == uc || ub == ud || uc == ud)
		{
			i--;
		}
		hits = isHit();
		miss = isMiss();
		printf("Hits:%d\n", hits);
		printf("Miss:%d\n", miss);
		i--;
		printf("%d gussess left\n", i);
		if (hits == 4)
		{
			printf("******************\nGREAT!!!\n");
			printf("Congralations, You get the password in %d attempts!!\n******************\n", turn);
			i = 0;
		}
		hits = 0;
		miss = 0;
		turn++;

	}

}
void crazy()
{
	int hits = 0;
	int miss = 0;
	int i = rand() % 20 + 5;
	//printf("&&%d&&", i);
	int turn = 1;
	while (i)
	{
		getPassword();
		if (ua == ub || ua == uc || ua == ud || ub == uc || ub == ud || uc == ud)
		{
			i--;
		}
		hits = isHit();
		miss = isMiss();
		printf("Hits:%d\n", hits);
		printf("Miss:%d\n", miss);
		i--;
		//printf("%d gussess left\n", i);
		if (hits == 4)
		{
			printf("******************\nGREAT!!!\n");
			printf("Congralations, You get the password in %d attempts!!\n******************\n", turn);
			i = 0;
		}
		hits = 0;
		miss = 0;
		turn++;

	}
}
/*
return user guss password
*/
void getPassword()
{
	printf("Enter your gussing password, each digit betwen 1-6\n");
	ua = _getch();
	_putch(ua);
	ub = _getch();
	_putch(ub);
	uc = _getch();
	_putch(uc);
	ud = _getch();
	_putch(ud);
	//printf("\n** %d **\n", ua);
	printf("\n");
}
/*
check hit numbers
*/
int isHit()
{
	//printf("hiiiiiii");
	ua -= '0';
	ub -= '0';
	uc -= '0';
	ud -= '0';
	int count = 0;
	if (ua == a)
	{
		count++;
	}
	if (ub == b)
	{
		count++;
	}
	if (uc == c)
	{
		count++;
	}
	if (ud == d)
	{
		count++;
	}
	return count;
}
/*
check miss numbers
*/
int isMiss()
{
	int count = 0;
	if (ua == b || ua == c || ua == d)
	{
		count++;
	}
	if (ub == a || ub == c || ub == d)
	{
		count++;
	}
	if (uc == a || uc == b || uc == d)
	{
		count++;
	}
	if (ud == a || ud == b || ud == c)
	{
		count++;
	}
	return count;
}