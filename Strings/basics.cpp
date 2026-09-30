1. ASCII value of a character
char c = 'A';

cout << (int)c;

Output:

65

Common ASCII:

'A' = 65
'B' = 66
...
'Z' = 90

'a' = 97
'b' = 98
...
'z' = 122

'0' = 48
'1' = 49
...
'9' = 57
2. Character → ASCII
char c = 'a';

int x = c;

cout << x;  // 97
3. ASCII → Character
int x = 65;

char c = x;

cout << c;  // A
4. Digit character → integer

Very important:

char c = '7';

int x = c - '0';

cout << x;  // 7

Why?

'7' = 55
'0' = 48

55 - 48 = 7
5. Integer → digit character
int x = 7;

char c = x + '0';

cout << c;  // '7'
6. Check whether character is a digit
if(isdigit(c))
    cout << "Digit";

Examples:

isdigit('5');   // true
isdigit('A');   // false
7. Check whether alphabet
if(isalpha(c))
    cout << "Alphabet";
8. Check uppercase
if(isupper(c))
    cout << "Uppercase";
9. Check lowercase
if(islower(c))
    cout << "Lowercase";
10. Character → uppercase
char c = 'a';

c = toupper(c);

cout << c;  // A
11. Character → lowercase
char c = 'A';

c = tolower(c);

cout << c;  // a
12. Check if character is vowel
char c = 'a';

if(c == 'a' || c == 'e' || c == 'i' || 
   c == 'o' || c == 'u') {
    cout << "Vowel";
}

For uppercase + lowercase:

c = tolower(c);

if(c == 'a' || c == 'e' || c == 'i' || 
   c == 'o' || c == 'u') {
    cout << "Vowel";
}
