#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LEN 80

char *reverse_string(char *str);
char *trim_whitespace(char *str);
int count_vowels(char *str);

int main(void)
{
    char input_str[MAX_STRING_LEN];
    printf("Enter a string: ");
    fgets(input_str, MAX_STRING_LEN, stdin);

    char *reversed_str = reverse_string(input_str);
    printf("Reversed string: %s\n", reversed_str);
    free(reversed_str);

    char *trimmed_str = trim_whitespace(input_str);
    printf("Trimmed string: %s\n", trimmed_str);
    free(trimmed_str);

    int vowel_count = count_vowels(input_str);
    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}

char *reverse_string(char *str)
{
    int len = strlen(str);
    char *result = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        result[i] = str[len - i - 1];
    }
    result[len] = '\0';

    return result;
}

char *trim_whitespace(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    while (str[start] == ' ')
    {
        start++;
    }
    while (str[end] == ' ' || str[end] == '\n')
    {
        end--;
    }

    char *result = (char *)malloc(end - start + 2);
    strncpy(result, &str[start], end - start + 1);
    result[end - start + 1] = '\0';

    return result;
}

int count_vowels(char *str)
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

