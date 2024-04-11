#include <stdio.h>
#include <string.h>
// For strcpy()

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

    for ( int i = 0 ; i < 6 ; i++ ) {
        restart :
        printf( "Input your Marks in Course %s:\n" , Course_Code[i] ) ;
        scanf( "%d" , &Marks[i] ) ;

        // Use a switch statement to assign grades and grade points based on marks
        switch (Marks[i]) {
            case 85 ... 100:
                strcpy(Grade[i], "A");
                Grade_Points[i] = 4.00;
                strcpy(Description[i], "Distinction");
                break;
            case 80 ... 84:
                strcpy(Grade[i], "A-");
                Grade_Points[i] = 3.70;
                strcpy(Description[i], "Distinction");
                break;
            case 75 ... 79:
                strcpy(Grade[i], "B+");
                Grade_Points[i] = 3.30;
                strcpy(Description[i], "Good");
                break;
            case 70 ... 74:
                strcpy(Grade[i], "B");
                Grade_Points[i] = 3.00;
                strcpy(Description[i], "Good");
                break;
            case 65 ... 69:
                strcpy(Grade[i], "B-");
                Grade_Points[i] = 2.70;
                strcpy(Description[i], "Good");
                break;
            case 60 ... 64:
                strcpy(Grade[i], "C+");
                Grade_Points[i] = 2.30;
                strcpy(Description[i], "Pass");
                break;
            case 55 ... 59:
                strcpy(Grade[i], "C");
                Grade_Points[i] = 2.00;
                strcpy(Description[i], "Pass");
                break;
            case 50 ... 54:
                strcpy(Grade[i], "C-");
                Grade_Points[i] = 1.70;
                strcpy(Description[i], "Conditional Pass");
                break;
            case 45 ... 49:
                strcpy(Grade[i], "D+");
                Grade_Points[i] = 1.30;
                strcpy(Description[i], "Fail");
                break;
            case 40 ... 44:
                strcpy(Grade[i], "D");
                Grade_Points[i] = 1.00;
                strcpy(Description[i], "Fail");
                break;
            case 0 ... 39:
                strcpy(Grade[i], "F");
                Grade_Points[i] = 0.00;
                strcpy(Description[i], "Fail");
                break; 
            // Prompt for input again for an invalid mark
            default:
                printf("Invalid mark. Please enter a mark between 0 and 100.\n");
                goto  restart;
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