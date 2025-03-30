#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const int SIZE = 100;
int menu();
void control(int choice, char str[]);
char *input(char *str);
void display(char *str);
void reverse(char str[]);
int is_palindrome(char str[]);
int count_words(char str[]);
int count_v_c(char str[], int *x, int *y);
int main()
{
  char string[SIZE];
  printf("\nWelcome To String-Processor");

  while (1)
  {
    int choice = menu();
    control(choice, string);
    if (choice == 7)
      break;
  }
  return 0;
}
void control(int choice, char str[])
{
  switch (choice)
  {
  case 1:
    input(str);
    break;
  case 2:
    display(str);
    break;
  case 3:
    reverse(str);
    break;
  case 4:
    is_palindrome(str);
    break;
  case 5:
    printf("\nWords in %s is %d", str, count_words(str));
    break;
  case 6:
  {
    int vowel = 0, consonant = 0;
    count_v_c(str, &vowel, &consonant);
    printf("Vowels:%d|Cosonants:%d", vowel, consonant);
    break;
  }
  case 7:
    printf("\nBye have fun!!");
    printf("\nDevloped by-bixuuu4u");
    exit(0);
    break;

  default:
    break;
  }
}
int menu()
{
  int choice;
  printf("\n1.Enter String.");
  printf("\n2.Display String.");
  printf("\n3.Reverse String.");
  printf("\n4.Check Palindrome.");
  printf("\n5.Count Words.");
  printf("\n6.Count Vowels & Consonants.");
  printf("\n7.Exit.");
  printf("\nPlease Enter Your Choice:");
  scanf("%d", &choice);
  while (getchar() != '\n')
    ;

  return choice;
}
int count_v_c(char str[], int *x, int *y)
{
  int lenght = strlen(str);
  int c = 0, v = 0;
  int index = 0;

  while (str[index] != '\0')
  {
    char ch = tolower(str[index]);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      v++;
    }
    else if (isalpha(ch))
    {
      c++;
    }
    index++;
  }
  *x = v;
  *y = c;
  return 0;
}
int count_words(char str[])
{
  int lenght = strlen(str);
  int counter = 0;
  for (int i = 0; i < lenght; i++)
  {
    if (str[i] != ' ' && str[i] != '\0')
    {
      counter++;
    }
  }
  return counter;
}
int is_palindrome(char str[])
{
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++)
  {
    if (tolower(str[i]) != tolower(str[length - i - 1]))
    {
      return printf("\nFalse");
    }
  }
  return printf("\nTrue");
}
void reverse(char str[])
{
  int lenght = strlen(str);
  for (int i = 0; i < lenght / 2; i++)
  {
    char temp = str[lenght - i - 1];
    str[lenght - i - 1] = str[i];
    str[i] = temp;
  }
}
void display(char *str)
{
  printf("Your String: ");
  puts(str);
}
char *input(char *str)
{
  printf("\nEnter Your String: ");
  fgets(str, SIZE, stdin);
  int index = strcspn(str, "\n");
  str[index] = '\0';
  return str;
}