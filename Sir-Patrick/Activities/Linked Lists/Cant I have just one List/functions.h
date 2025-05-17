#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*===============STUDENT RECORD LINKED LIST =====================*/
typedef struct{
	char fName[20];
	char lName[20];
}personName;

typedef struct{
	personName studentName;
	int idNumber;
}studentRecord;

typedef struct studentNode{
	studentRecord studentData;
	struct studentNode* next;
}studentNode,*studentNodePtr;
/*========================================================*/

/*===============GRADE RECORDS LINKED LIST =====================*/

typedef struct{
	int idNumber;
	int grades[3];
}gradeRecords;

typedef struct gradeNode{
	gradeRecords gradeData;
	struct gradeNode* next;
}gradeNode,*gradeNodePtr;

/*==========================================*/

/*===============COMBINED LINKED LIST=====================*/
typedef struct{
	gradeRecords grades;
	studentRecord studentInfo;
}fullRecord;


typedef struct node{
	fullRecord data;
	struct node* next;
}Node,*NodePtr;
/*=====================================================*/

/*===================FUNCTION PROTOTYPES=======================*/

/*These 2 functions aims to populate the student linked list, when inserting an item into the linked list it will be inserted at the very last*/
void insertLastStudent(studentNode** headRef, studentRecord record);
studentNode* populateStudents();

/*These 2 functions aims to populate the grades linked list, when inserting an item into the linked list it will be inserted at the very last*/
void insertLastGrades(gradeNode** headRef, gradeRecords record);
gradeNode* populateGradesRecord();

/* display will display in the proper format the information of the student from the fullRecord linked list with the the same idNum */
void display(Node* head,int idNum);

#endif