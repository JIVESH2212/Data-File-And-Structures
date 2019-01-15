#include <stdio.h>
#include <conio.h>
void towers_of_hanoi (int n, char *a, char *b, char *c);
int cnt=0;
int main (void)
{
int n;
printf("Enter number of discs: ");
scanf("%d",&n);
towers_of_hanoi (n, "Tower 1", "Tower 2", "Tower 3");
getch();
}
void towers_of_hanoi (int n, char *a, char *b, char *c)
{
if (n == 1)
{
++cnt;
printf ("\n%5d: Move disk 1 from %s to %s", cnt, a, c);
return;
}
else
{
towers_of_hanoi (n-1, a, c, b);
++cnt;
printf ("\n%5d: Move disk %d from %s to %s", cnt, n, a, c);
towers_of_hanoi (n-1, b, a, c);
return;
}
}




Output of the program:
RUN 1:
Enter the number of discs: 3
1: Move disk 1 from tower 1 to tower 3.
2: Move disk 2 from tower 1 to tower 2.
3: Move disk 1 from tower 3 to tower 2.
4: Move disk 3 from tower 1 to tower 3.
5: Move disk 1 from tower 2 to tower 1.
6: Move disk 2 from tower 2 to tower 3.
7: Move disk 1 from tower 1 to tower 3.
RUN 2:
Enter the number of discs: 4
1: Move disk 1 from tower 1 to tower 2.
2: Move disk 2 from tower 1 to tower 3.
3: Move disk 1 from tower 2 to tower 3.
4: Move disk 3 from tower 1 to tower 2.
5: Move disk 1 from tower 3 to tower 1.
6: Move disk 2 from tower 3 to tower 2.
7: Move disk 1 from tower 1 to tower 2.
8: Move disk 4 from tower 1 to tower 3.
9: Move disk 1 from tower 2 to tower 3.
10: Move disk 2 from tower 2 to tower 1.
11: Move disk 1 from tower 3 to tower 1.
12: Move disk 3 from tower 2 to tower 3.
13: Move disk 1 from tower 1 to tower 2.
14: Move disk 2 from tower 1 to tower 3.
15: Move disk 1 from tower 2 to tower 3.