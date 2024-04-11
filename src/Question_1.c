#include<stdio.h>
#include<string.h>
// For strcmp(),strcpn()

int main()
{
    char ch [200] ; 
    do{
        printf ( "input your string here (# to quit):\n" ) ;
        scanf ( "%s" , ch ) ;   

        // Check if the input is "#", and if so, exit the loop
        if ( strcmp( ch , "#") == 0 )
            break ;

        // Remove the newline character from the input
        ch [ strcspn ( ch , "\n") ] = '\0' ;  

        for ( int i=0 ; i < strlen(ch) ; i++ ){
            printf ( "%c to ASCII: %d\n" , ch[i] , ch[i] );
            
            // 8 characters per line
            if ((i + 1) % 8 == 0) 
                printf( "\n" ) ;
        } 
    }
    while ( strcmp( ch , "#" ) != 0 ) ;
    // Continue processing input until the user enters "#"

    printf ( "Thank you!\n" ) ;
	return 0 ;
}