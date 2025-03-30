# String-Processor

A simple menu-driven C program that performs various string manipulation operations. This project allows users to input a string and apply operations like reversing, palindrome checking, word counting, and vowel/consonant counting.

## Features

- **Enter String**: Input a string (up to 99 characters).
- **Display String**: Show the current string.
- **Reverse String**: Reverse the order of characters in the string.
- **Check Palindrome**: Determine if the string is a palindrome (case-insensitive).
- **Count Words**: Count the number of non-space characters in the string (see Current Limitations).
- **Count Vowels & Consonants**: Calculate the number of vowels and consonants in the string.
- **Exit**: Terminate the program with a farewell message.

## Welcome To String-Processor

1.Enter String.<br>
2.Display String.<br>
3.Reverse String.<br>
4.Check Palindrome.<br>
5.Count Words.<br>
6.Count Vowels & Consonants.<br>
7.Exit.<br>
Please Enter Your Choice: 1<br>

Enter Your String: Hello World<br>
<br>
1.Enter String.<br>
2.Display String.<br>
3.Reverse String.<br>
4.Check Palindrome.<br>
5.Count Words.<br>
6.Count Vowels & Consonants.<br>
7.Exit.<br>
Please Enter Your Choice: 2<br>
Your String: Hello World<br>
<br>
1.Enter String.<br>
2.Display String.<br>
3.Reverse String.<br>
4.Check Palindrome.<br>
5.Count Words.<br>
6.Count Vowels & Consonants.<br>
7.Exit.<br>
Please Enter Your Choice: 7<br>
<br>
Bye have fun!!<br>
Devloped by-bixuuu4u<br>

# Code Structure

## Main Functions:

- `menu()`: Displays the menu and captures user choice.
- `control()`: Handles the logic for each menu option.
- `input()`: Reads a string from the user.
- `display()`: Prints the current string.
- `reverse()`: Reverses the string in place.
- `is_palindrome()`: Checks if the string is a palindrome.
- `count_words()`: Counts non-space characters (to be updated for word counting).
- `count_v_c()`: Counts vowels and consonants using pointers.

## Libraries Used:

- `<stdio.h>`: For input/output operations.
- `<stdlib.h>`: For `exit()` function.
- `<string.h>`: For string manipulation (`strlen`, `strcspn`).
- `<ctype.h>`: For character type checking (`tolower`, `isalpha`).

## Current Limitations

- The `count_words()` function currently counts individual non-space characters instead of actual words (e.g., "Hello World" returns 10 instead of 2).
- Output formatting is minimal and could be improved for better readability.

## Future Updates

- **Improved Word Counting**: Modify `count_words()` to accurately count words (sequences of non-space characters separated by spaces).
- **Better Print Formatting**: Enhance the output display with aligned text, borders, or color (if supported by the terminal) for a more polished user experience.
-**Convert String to Uppercase & Lowercase**
-**Convert To Binary**
## Developer

Developed by: **bixuuu4u**

## License

This project is open-source and free to use/modify. No formal license is applied yet.
