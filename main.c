#include <stdio.h>
#include <string.h>

int ascii_to_char(){
    char c;
    int d;
    printf("====Convert ASCII number to Character====\n");
    printf("Please input a number. >");
    fflush(stdout);
    scanf(" %d", &d);
    //Limit to printable chars 
    if (d > 32 && d < 127){
        c = d;
        printf("The code %d is %c.\n\n",d,c);
    }
    else{
        //return error
        printf("The number %d is out of range. Returning...\n\n",d);
    }
    return 0;
}
int char_to_ascii(){
    char c[]="a";
    int d;
    printf("====Convert Character to ASCII number====\n");
    printf("Please input a single character. >");
    fflush(stdout);
    scanf(" %s", c);
    //Use only the first letter
    d = c[0];
    if (d > 32 && d < 127){
        printf("The character %c is %d.\n\n",c[0],d);
    }
    else{
        printf("The character is out of range. Returning...\n\n");
    }
    fflush(stdout);
    return 0;
}

int display_ascii_table(){
    printf("====ASCII table====\n");
    //Print table with a bit of formatting
    printf("Number\t| Character\n");
    for(int i = 33; i < 127; i++){
        printf("%d\t| %c\n",i,i);
    }
    printf("\n\n");
    fflush(stdout);
    return 0;
}

int show_menu(){
    char c[] = "a";
    int state;

    //Show menu
    printf("~~ASCII character program~~\n");
    printf("Input 1,2,3 or q\n");
    printf("1: ASCII NUMBER\t-> CHAR\n");
    printf("2: CHAR\t\t-> ASCII NUMBER\n");
    printf("3: DISPLAY ASCII TABLE\n");
    printf("q: Quit\n");
    //Take input
    printf("Mode: ");
    fflush(stdout);
    scanf(" %s", c);
    //handle non single character input
    if(strlen(c)>1){
        printf("Input length too long.\n\n");
        return 1;
    }
    else if (c[0] == 'q'){
        return 0;
    }
    else if (c[0] == '1'){
        ascii_to_char();
        return 1;
    }
    else if (c[0] == '2'){
        char_to_ascii();
        return 1;
    }
    else if (c[0] == '3'){
        display_ascii_table();
        return 1;
    }
    else{
        printf("Input does not match any.\n\n");
        fflush(stdout);
        return 1;
    }
}

int main(){
    int state;
    while (1){
        state = show_menu();
        if (state == 0){
            printf("done. bye~\n");
            fflush(stdout);
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}
