#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LEN 80

void reverse_string(char* str);
void trim_whitespace(char* str);
int count_vowels(char* str);

int main(void)
{
    char input_str[MAX_STRING_LEN];
    printf("Enter a string: ");
    fgets(input_str, MAX_STRING_LEN, stdin);

    // Remove newline character
    input_str[strcspn(input_str, "\n")] = '\0';

    // Reverse the string
    reverse_string(input_str);
    printf("Reversed string: %s\n", input_str);

    // Trim the whitespace from the string
    trim_whitespace(input_str);
    printf("Trimmed string: %s\n", input_str);

    // Count the number of vowels in the string
    int vowel_count = count_vowels(input_str);
    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}

void reverse_string(char* str)
{
    int len = strlen(str);
    int i = 0;
    int j = len - 1;

    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void trim_whitespace(char* str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    while (str[start] == ' ' || str[start] == '\t')
    {
        start++;
    }
    while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')
    {
        end--;
    }

    int trimmed_len = end - start + 1;
    memmove(str, str + start, trimmed_len);
    str[trimmed_len] = '\0';
}

int count_vowels(char* str)
{
    int count = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }

    return count;
}
