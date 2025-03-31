#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EXIT_CHOICE 12
const int SIZE = 100;
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

  printf("\nWelcome To String-Processor");
  int choice;
  do
  {
    choice = menu();
    if (choice == EXIT_CHOICE)
    {
      printf("\nBye have fun!!");
      printf("\nDevloped by-bixuuu4u");
      exit(0);
    }
    if (choice != 1 && ifempty(string))
    {
      printf("Error!!String is empty cant do that operation.");
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
      printf("\n%s IS PALINDROME", str);
    }
    else
    {
      printf("\n%s IS NOT PALINDROME", str);
    }
    break;
  case 5:
    printf("\nWords in %s is %d", str, count_words(str));
    break;
  case 6:
  {
    int vowel = 0, consonant = 0;
    count_v_c(str, &vowel, &consonant);
    printf("Vowels:%d|Consonants:%d", vowel, consonant);
    break;
  }
  case 7:
  {
    char upperstring[SIZE];
    upperstring[0] = '\0';
    uppercase(str, upperstring);
    printf("\nString:%s", upperstring);
    break;
  }
  case 8:
  {
    char lowerstring[SIZE];
    lowerstring[0] = '\0';
    lowercase(str, lowerstring);
    printf("\nString:%s", lowerstring);
    break;
  }
  case 9:
  {
    char capstring[SIZE];
    capstring[0] = '\0';
    capitalized(str, capstring);
    printf("\nCapitalized String:%s", capstring);
    break;
  }
  case 10:
  {
    char titlestring[SIZE];
    titlestring[0] = '\0';
    titled(str, titlestring);
    printf("\nTitled String:%s", titlestring);
    break;
  }
  case 11:
  {
    char binary[SIZE * 9];
    binary[0] = '\0';
    tobinary(str, binary);
    printf("\nBinary Form:%s", binary);
    break;
  }
  case EXIT_CHOICE:
  {
    printf("\nBye have fun!!");
    printf("\nDevloped by-bixuuu4u");
    exit(0);
    break;
  }

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
  printf("\n9. Capitalized.");
  printf("\n7. Uppercase.");
  printf("\n8. Lowercase.");
  printf("\n9. Capitalized.");
  printf("\n10. Titled.");
  printf("\n11. Convert to Binary.");
  printf("\n%d. Exit.", EXIT_CHOICE);
  printf("\nPlease Enter Your Choice:");
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
  int bIndex = 0;
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
      binary[bIndex] = temp[j];
      bIndex++;
    }
    if (i < length - 1)
    {
      binary[bIndex] = ' ';
      bIndex++;
    }
  }
  binary[bIndex] = '\0';
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
      return 0;
    }
  }
  return 1;
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
  while (ifempty(str))
  {
    printf("Error!! Empty string not allowed. Please enter a non-empty string: ");
    fgets(str, SIZE, stdin);
    index = strcspn(str, "\n");
    str[index] = '\0';
  }
  return str;
}