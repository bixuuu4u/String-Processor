#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EXIT_CHOICE 12
const int SIZE = 100;
const char *C_END = "\033[0m";
const char *RED = "\033[0;31m";
const char *BRED = "\033[1;31m";
const char *GREEN = "\033[0;32m";
const char *BGREEN = "\033[1;32m";
const char *YELLOW = "\033[0;33m";
const char *BYELLOW = "\033[1;33m";
const char *BLUE = "\033[0;34m";
const char *BBLUE = "\033[1;34m";
const char *PURPLE = "\033[0;35m";
const char *BPURPLE = "\033[1;35m";
const char *CYAN = "\033[0;36m";
const char *BCYAN = "\033[1;36m";
int menu();
int ifempty(char str[]);
void control(int choice, char str[]);
char *input(char *str);
void display(char *str);
void reverse(char str[]);
int is_palindrome(char str[]);
int count_words(char str[]);
int count_v_c(char str[], int *x, int *y);
void uppercase(char str[], char upperstring[]);
void lowercase(char str[], char upperstring[]);
void tobinary(char str[], char binary[]);
void capitalized(char str[], char capstring[]);
void titled(char str[], char titlestring[]);
int main()
{
  char string[SIZE];
  string[0] = '\0';

  printf("\n\t%sWelcome To String-Processor%s", BPURPLE, C_END);
  int choice;
  do
  {
    choice = menu();
    if (choice == EXIT_CHOICE)
    {
      printf("%s\nBye have fun!!%s", BPURPLE, C_END);
      printf("%s\nDevloped by-bixuuu4u%s", BPURPLE, C_END);
      exit(0);
    }
    if (choice != 1 && ifempty(string))
    {
      printf("%sError!!String is empty cant do that operation.%s", RED, C_END);
    }
    else
    {
      control(choice, string);
    }
  } while (choice != EXIT_CHOICE);

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
    if (is_palindrome(str))
    {
      printf("%s\n%s IS PALINDROME%s", GREEN, str, C_END);
    }
    else
    {
      printf("%s\n%s IS NOT PALINDROME%s", RED, str, C_END);
    }
    break;
  case 5:
    printf("%s\nWords in %s is %s:%d", BBLUE, str, C_END, count_words(str));
    break;
  case 6:
  {
    int vowel = 0, consonant = 0;
    count_v_c(str, &vowel, &consonant);
    printf("%sVowels:%s%d%s|Consonants:%s%d", BBLUE, C_END, vowel, BBLUE, C_END, consonant);
    break;
  }
  case 7:
  {
    char upperstring[SIZE];
    upperstring[0] = '\0';
    uppercase(str, upperstring);
    printf("%s\nString:%s%s", BBLUE, C_END, upperstring);
    break;
  }
  case 8:
  {
    char lowerstring[SIZE];
    lowerstring[0] = '\0';
    lowercase(str, lowerstring);
    printf("%s\nString:%s%s", BBLUE, C_END, lowerstring);
    break;
  }
  case 9:
  {
    char capstring[SIZE];
    capstring[0] = '\0';
    capitalized(str, capstring);
    printf("%s\nCapitalized String:%s%s", BBLUE, C_END, capstring);
    break;
  }
  case 10:
  {
    char titlestring[SIZE];
    titlestring[0] = '\0';
    titled(str, titlestring);
    printf("%s\nTitled String:%s%s", BBLUE, C_END, titlestring);
    break;
  }
  case 11:
  {
    char binary[SIZE * 9];
    binary[0] = '\0';
    tobinary(str, binary);
    printf("%s\nBinary Form:%s%s", BBLUE, C_END, binary);
    break;
  }

  default:
    break;
  }
}
int menu()
{
  int choice;
  printf("%s\n1.Enter String.%s", CYAN, C_END);
  printf("%s\n2.Display String.%s", CYAN, C_END);
  printf("%s\n3.Reverse String.%s", CYAN, C_END);
  printf("%s\n4.Check Palindrome.%s", CYAN, C_END);
  printf("%s\n5.Count Words.%s", CYAN, C_END);
  printf("%s\n6.Count Vowels & Consonants.%s", CYAN, C_END);
  printf("%s\n9.Capitalized.%s", CYAN, C_END);
  printf("%s\n7.Uppercase.%s", CYAN, C_END);
  printf("%s\n8.Lowercase.%s", CYAN, C_END);
  printf("%s\n9.Capitalized.%s", CYAN, C_END);
  printf("%s\n10.Titled.%s", CYAN, C_END);
  printf("%s\n11.Convert to Binary.%s", CYAN, C_END);
  printf("%s\n%d.Exit.%s", CYAN, EXIT_CHOICE, C_END);
  printf("%s\nPlease Enter Your Choice:%s", YELLOW, C_END);
  scanf("%d", &choice);
  while (getchar() != '\n')
    ;

  return choice;
}
void capitalized(char str[], char capstring[])
{
  int length = strlen(str);
  for (int i = 0; i < length; i++)
  {
    capstring[i] = tolower(str[i]);
  }
  if (length > 0 && isalpha(capstring[0]))
  {
    capstring[0] = toupper(capstring[0]);
  }
  capstring[length] = '\0';
}
void titled(char str[], char titlestring[])
{
  int length = strlen(str);
  int newWord = 1;

  for (int i = 0; i < length; i++)
  {
    titlestring[i] = tolower(str[i]);
  }
  titlestring[length] = '\0';

  for (int i = 0; i < length; i++)
  {
    if (newWord && isalpha(titlestring[i]))
    {
      titlestring[i] = toupper(titlestring[i]);
      newWord = 0;
    }
    if (titlestring[i] == ' ')
    {
      newWord = 1;
    }
  }
}

void tobinary(char str[], char binary[])
{
  int length = strlen(str);
  int bitIndex = 0;
  for (int i = 0; i < length; i++)
  {
    int num = (unsigned char)str[i];
    char temp[8];
    int tTindex = 7;

    while (tTindex >= 0)
    {
      temp[tTindex] = (num) % 2 + '0';
      num /= 2;
      tTindex--;
    }
    for (int j = 0; j < 8; j++)
    {
      binary[bitIndex] = temp[j];
      bitIndex++;
    }
    if (i < length - 1)
    {
      binary[bitIndex] = ' ';
      bitIndex++;
    }
  }
  binary[bitIndex] = '\0';
}
int ifempty(char str[])
{
  return (strlen(str) == 0);
}
void uppercase(char str[], char upperstring[])
{
  int length = strlen(str);

  for (int i = 0; i < length; i++)
  {
    if (isalpha(str[i]))
    {
      upperstring[i] = toupper(str[i]);
    }
    else
    {
      upperstring[i] = str[i];
    }
  }
  upperstring[length] = '\0';
}
void lowercase(char str[], char lowerstring[])
{
  int length = strlen(str);

  for (int i = 0; i < length; i++)
  {
    if (isalpha(str[i]))
    {
      lowerstring[i] = tolower(str[i]);
    }
    else
    {
      lowerstring[i] = str[i];
    }
  }
  lowerstring[length] = '\0';
}
int count_v_c(char str[], int *x, int *y)
{
  int length = strlen(str);
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
      return 0;
    }
  }
  return 1;
}
void reverse(char str[])
{
  int left = 0,
      right = strlen(str) - 1;
  while (left < right)
  {
    char temp = str[left];
    str[left++] = str[right];
    str[right--] = temp;
  }
}
void display(char *str)
{
  printf("%sYour String:%s", BBLUE, C_END);
  puts(str);
}
char *input(char *str)
{
  printf("%s\nEnter Your String:%s ", YELLOW, C_END);
  fgets(str, SIZE, stdin);
  int index = strcspn(str, "\n");
  str[index] = '\0';
  while (ifempty(str))
  {
    printf("%sError!! Empty string not allowed. Please enter a non-empty string: %s", RED, C_END);
    fgets(str, SIZE, stdin);
    index = strcspn(str, "\n");
    str[index] = '\0';
  }
  return str;
}