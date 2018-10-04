#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, string argv[])

{
    int i, n;
    //checking if user give right lenght of command line argument
    if (argc != 2)
    {
        printf("usage:./caesar key\n");
        return 1;
    }
// converting string into integer
    int k = atoi(argv[1]);
//printing error message if user give non positive key
    if (k < 0)
    {
        printf("hey!,user positive one please\n");
        return 1;

    }
//prompting user for plaintext
    string s = get_string("plaintext:");
    printf("ciphertext:");
    for (i  = 0, n = strlen(s); i < n ; i++)
    {
        //checking is character is uppercase
        if (isupper(s[i]))


        {
            printf("%c", (s[i] - 'A' + k) % 26 + 'A');
        }




        //checking is character is lower case

        else if (islower(s[i]))



        {





            printf("%c", (s[i] - 'a' + k) % 26 + 'a');
        }
        else








            //printing exact same input if input is non alphabetic


        {





            printf("%c", s[i]);
        }

    }
    //jumps to new line
    printf("\n");
}





