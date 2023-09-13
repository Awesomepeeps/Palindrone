/** Author: Nikaansh Singh
 *  Last Edited: 9/12/23
 *  This is a program to determin if a string less that 80 charecters is a palindrome or not
**/

#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main()
{
  //Making Variables
  char input[80];
  char cleaninp[80];
  char copystr[80];
  int charcount = 0;
  int isalftr = 0;
  int isdigtr = 0;

  //Gets input from user
  cout << "Please type in your string?" << endl;
  cin.get(input, 80, '\n');
  cin.get();

  //Sets the other two strings to be empty
  for (int i = 0; i < 80; i++) {
    cleaninp[i] = '\0';
    copystr[i] = '\0';
  }
  
  //Makes it all lowercase and gets rid of everything that is not a letter or digit
  for (int i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
    isalftr = (isalpha(input[i]) != 0);
    isdigtr = (isdigit(input[i]) != 0);
      
    //Sets the string cleanint to the filtered input
    if (isalftr == 1 || isdigtr == 1) {
      cleaninp[charcount] = input[i];
      charcount++;
    }
  }
  
  //Makes a copy of the clean string and gets the length of the clean string
  strcpy(copystr, cleaninp);
  int lenstr = strlen(cleaninp) - 1;

  //Puts one of the copies backwards
  for (int i = 0; i < strlen(cleaninp); i++) {
    cleaninp[i] = copystr[lenstr];
    lenstr--;
  }

  //Compares the normal and the backwards input to see if it is a plaindrome
  if (strcmp(cleaninp, copystr) == 0) {
    cout << "Palindrome!" << endl;
  }
  else {
    cout << "Not a Palindrome." << endl;
  }  
}
