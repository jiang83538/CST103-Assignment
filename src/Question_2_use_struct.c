#include <stdio.h>
#include <string.h>
// For strcpy()

// Define a structure to represent a course
struct Course{
    int Lower, Upper ; // Lower and upper marks for the grade range
    char Grade[6] ;
    float Grade_Points;
    char Description[20] ;
} ;

int main() {
    char Course_Code[6][10] = {
        "MPU1.1-I" , "CYS102" , "MPU3192" , "CYS101" , "CYS103" , "CST103"
    } ; // Arrays to store course information
    
    int Marks[6] ; 
    char Grade[6][3] ;
    float Grade_Points[6] ;
    char Description[6][20] ;

    int Credit[6] = {
        2 , 3 , 2 , 3 , 3 , 4
    } ;
    float GPA = 0 ;

    // Define a table of grade information using the Course structure
    struct Course table[] =
    {
        {85, 100, "A",  4.00, "Distinction"},
        {80, 84,  "A-", 3.70, "Distinction"},
        {75, 79,  "B+", 3.30, "Good"},
        {70, 74,  "B",  3.00, "Good"},
        {65, 69,  "B-", 2.70, "Good"},
        {60, 64,  "C+", 2.30, "Pass"},
        {55, 59,  "C",  2.00, "Pass"},
        {50, 54,  "C-", 1.70, "Conditional Pass"},
        {45, 49,  "D+", 1.30, "Fail"},
        {40, 44,  "D",  1.00, "Fail"},
        {0,  39,  "F",  0.00, "Fail"}
    }; 

    // Loop to input and process marks for each course
    for ( int i = 0 ; i < 6 ; i++ ) {
        restart :
        printf( "Input your Marks in Course %s:\n" , Course_Code[i] ) ;
        scanf( "%d" , &Marks[i] ) ;
        
        // Check if marks are valid, else ask for input again
        if( Marks[i] < 0 || Marks[i] > 100 ){
            printf("Invalid mark. Please enter a mark between 0 and 100.\n");
            goto restart ;
        }

        // Find the corresponding grade and grade information
        for ( int j = 0 ; j < 11 ; j++ ) {
            if (Marks[i] >= table[j].Lower
                && 
                Marks[i] <= table[j].Upper) {
                strcpy( Grade[i], table[j].Grade ) ;
                Grade_Points[i] = table[j].Grade_Points ;
                strcpy( Description[i], table[j].Description ) ;
                break ;
            }
        }
    }

    // Display the results
    printf( "Course code  Final mark  Grade  Grade Points  Description\n" );
    for (int i = 0; i < 6; i++) {
        printf("%-8s     %6d        %-2s     %5.2f       %s\n",
                Course_Code[i], Marks[i], Grade[i], Grade_Points[i], Description[i]);
        GPA += Grade_Points[i] * Credit[i] ; 
    }

    // Calculate and display the GPA
    printf("The GPA of 202309 semester:%.2f" , 
            GPA / ( 2 + 3 + 2 + 3 + 3 + 4 ) ) ;

    return 0 ;
}