#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const int SIZE = 100;
int menu();
char *input(char *str);
void display(char *str);
void reverse(char str[]);
int is_palindrome(char str[]);
int count_words(char str[]);
int count_v_c(char str[], int *x, int *y);
int main()
{
  char string[SIZE];
  int vowel = 0, consonant = 0;
  printf("\nWelcome To Sting-Processor");
  input(string);
  display(string);
  reverse(string);
  display(string);
  is_palindrome(string);
  int word = count_words(string);
  printf("\n%d", word);
  count_v_c(string, &vowel, &consonant);
  printf("\nV=%d,C=%d", vowel, consonant);
  return 0;
}
int count_v_c(char str[], int *x, int *y)
{
  int lenght = strlen(str);
  int c=0, v = 0;
  int index = 0;

  while (str[index] != '\0')
  {
  char ch = tolower(str[index]);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      v++;
    }
    else if(isalpha(ch))
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
  int lenght = strlen(str);
  for (int i = 0; i < lenght / 2; i++)
  {
    if (str[i] != str[lenght - i - 1])
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
  // puts("\n");
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