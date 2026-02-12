#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//text[i] != '\0'
unsigned short detectPalindrome(char str[101]){
    unsigned short len = strlen(str);
    unsigned short halfWordLen = len / 2;
    for(int i=0; i < halfWordLen; i++){
        if(tolower(str[i]) != tolower(str[len-1-i])) return 0;
    }
    return 1;
}

int main() {
    char input[101];
    
    printf("Enter word: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0';                    //remove newline from string
    printf("Your Word \"%s\" is", input);
    if(detectPalindrome(input)) printf(" a Palindrome!\n");
    else                        printf(" NOT a Palindrome!\n");
    Sleep(5000);
    return 0;
}