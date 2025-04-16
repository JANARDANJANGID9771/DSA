#include <stdio.h>
#include <string.h>

// string.h = header file

int main()
{
    char str1[50] = "Anything";
    char str2[20] = "Aneyname";

    char emptyString[20] = "";

    //    str1 and str2
    //    Anything Anyname

    //    str2 and str1
    //   Anyname Anything
    // copying string str1 into emptystring

    //    strcpy(emptyString, str1);

    //    printf("%s \n",emptyString);

    //    strcat(str1 , str2);

    //    printf("%s \n ", str1);
    //    printf("%d \n ", str2);

    // calculate charter numer value
    int lengthofString = strlen(str2);
    printf("%d \n", lengthofString);

    return 0;
}