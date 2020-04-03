#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./substitution Key\n");
        exit(1);
    }
    int length = strlen(argv[1]);
    string key = argv[1];

    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters\n");
            exit(1);
        }
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                printf("exit");
                exit(1);
            }
        }
    }
    int z = 0;
    string text = get_string("plaintext:");
    int count = strlen(text);
    char cipher[count];
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if ((char)toupper(text[i]) == (char)toupper(alphabet[j]))
            {
                if (islower(text[i]))
                {
                    cipher[z++] = tolower(key[j]);

                }
                else
                {
                    cipher[z++] = toupper(key[j]);
                }
            }
            else if (!isalpha(text[i]) && text[i] != '\0')
            {
                cipher[z++] = text[i];
                break;
            }
        }

    }
    printf("ciphertext: ");
    for (int y = 0; y < count; y++)
    {
        printf("%c", cipher[y]);
    }
    printf("\n");

}