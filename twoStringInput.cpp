#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    char *ptr1 = str1;
    char *ptr2 = str2;

    // Input two strings using pointers
    printf("Enter the first string: ");
    scanf("%s", ptr1);
    printf("Enter the second string: ");
    scanf("%s", ptr2);

    // Find and print the lengths of the strings using strlen() function
    printf("Length of first string: %d\n", (int)strlen(ptr1));
    printf("Length of second string: %d\n", (int)strlen(ptr2));

    // Compare strings using strcmp() function
    if (strcmp(ptr1, ptr2) == 0)
        printf("Strings are the same.\n");
    else
        printf("Strings are different.\n");

    // Concatenate strings using strcat() function
    while (*ptr1) 
        ptr1++;
    while (*ptr2) { 
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0'; 

    printf("Concatenated string: %s\n", str1);

    return 0;
}
