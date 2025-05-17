MDE - Last Three Students
by Edwin Bartlett

Complete the given program that outputs the last three
students of an array that will be sorted in descending order
based on their grades.

1. The main function is provided in main.c

2. The "Student" structure and "MAX_STUDENTS" macro are defined
in types.h

3. In functions.h, write a function named
getLastThreeStudents that takes an array of Students structs
and the number of students. This function should:
    -Sort the students by descending order (use any sorting
     algorithm).
    -Dynamically allocate memory for a new array of Student
     structs to store the last three students.
    -Copy the last three students from the sorted array to the
     newly allocated array.
    -Return a pointer to the dynamically allocated array.

//============================== Sample Output 1 ==============================//
Last 3 Students (Sorted by Score):
Charlie: 78
Jack: 75
Frank: 70
//============================== END ==============================//
