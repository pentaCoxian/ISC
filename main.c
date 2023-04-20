#include <stdio.h>
#include <string.h>

// lookup table using array for special chars
const char lookup[33][10] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US", "SPACE"};

int ascii_to_char()
{
    char c;
    int d;

    printf("====Convert ASCII number to Character====\n");
    printf("Please input a number. >");
    fflush(stdout);
    scanf(" %d", &d);
    // Limit to printable chars
    if (d > 32 && d < 127)
    {
        c = d;
        printf("The code %d is %c.\n\n", d, c);
    }
    else if (d <= 32 && d >= 0)
    {
        printf("The code %d is the control character %s.\n\n", d, lookup[d]);
    }
    else if (d == 127)
    {
        printf("The code %d is the control character DEL.\n\n", d);
    }
    else
    {
        // return error
        printf("The number %d is out of range. Returning...\n\n", d);
    }
    fflush(stdout);
    return 0;
}
int char_to_ascii()
{
    char c[] = "a";
    int d;
    printf("====Convert Character to ASCII number====\n");
    printf("Please input a single character. >");
    fflush(stdout);
    scanf(" %s", c);
    // Use only the first letter
    d = c[0];
    if (d > 32 && d < 127)
    {
        printf("The character %c is %d.\n\n", c[0], d);
    }
    else
    {
        printf("The character is out of range. Returning...\n\n");
    }
    fflush(stdout);
    return 0;
}

int display_ascii_table()
{
    printf("====ASCII table====\n");
    // Print table with a bit of formatting
    printf("Number\t| Character\n");
    for (int i = 0; i < 128; i++)
    {
        if (i >= 0 && i <= 32)
        {
            printf("%d\t| %s\n", i, lookup[i]);
        }
        else if (i > 32 && i < 127)
        {
            printf("%d\t| %c\n", i, i);
        }
        else if (i == 127)
        {
            printf("%d\t| DEL\n", i);
        }
    }
    printf("\n\n");
    fflush(stdout);
    return 0;
}

int show_menu()
{
    char c[] = "a";
    int state;

    // Show menu
    printf("~~ASCII character program~~\n");
    printf("Input 1,2,3 or q\n");
    printf("1: ASCII NUMBER\t-> CHAR\n");
    printf("2: CHAR\t\t-> ASCII NUMBER\n");
    printf("3: DISPLAY ASCII TABLE\n");
    printf("q: Quit\n");
    // Take input as string to treat multi digit inputs
    printf("Mode: ");
    fflush(stdout);
    scanf(" %s", c);
    // handle non single character input
    if (strlen(c) > 1)
    {
        printf("Input length too long.\n\n");
        return 1;
    }
    else if (c[0] == 'q')
    {
        return 0;
    }
    else if (c[0] == '1')
    {
        ascii_to_char();
        return 1;
    }
    else if (c[0] == '2')
    {
        char_to_ascii();
        return 1;
    }
    else if (c[0] == '3')
    {
        display_ascii_table();
        return 1;
    }
    else
    {
        printf("Input does not match any.\n\n");
        fflush(stdout);
        return 1;
    }
}

int main()
{
    int state;
    while (1)
    {
        state = show_menu();
        // Quit if show menu returns with 0 and otherwise continue looping
        if (state == 0)
        {
            printf("done. bye~\n");
            fflush(stdout);
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
