#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int SIZE = 100;
char *input(char *str);
void display(char *str);
void reverse(char str[]);
int is_palindrome(char str[]);
int main()
{
  char string[SIZE];

  printf("\nWelcome To Sting-Processor");
  input(string);
  display(string);
  reverse(string);
  display(string);
  if (is_palindrome(string))
  {
    printf("\nTrue");
  }
  else
  {
    printf("\nFalse");
  }
  return 0;
}
int is_palindrome(char str[])
{
  int lenght = strlen(str);
  for (int i = 0; i < lenght / 2; i++)
  {
    if (str[i] != str[lenght - i - 1])
    {
      return 0;
    }
    return 1;
  }
}
void reverse(char str[])
{
  int lenght = strlen(str);
  for (int i = 0; i < lenght / 2; i++)
  {
    int temp = str[lenght - i - 1];
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