#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fName[32];
	char mi;
	char lName[16];
}fullName;

typedef struct{
	int score;			//Score of the student.
	int totalScore;		//Total score of the exam.
}exam;

typedef struct{
	exam exams[4];
	int numExams;
}grades;

typedef struct{
	fullName name;
	char idNum[9];
	char course[5];
	char gender;
	grades examScores;
}student;

typedef struct{
	char idNum[9];
	int index;
}studIndex;

/*
Write the code for the function getExamPassers(). The function will receive an array of students, 
the number of students, and an integer from 0-3 which indicates which of the four major exams to check.
The function will iterate through the list of students to find their scores for the specified exam. 
The function will store into an array of studIndex the idnumbers and indices of the students who got a score 
that is at least 60% of the total score. Return the array of studIndex to the calling function. Let the member "index"
of the array of studIndex contain a -1 to serve as a sentinel value.
*/

studIndex* getExamPassers(student S[], int numStuds, int examNum)
{
	int i, j;
	studIndex temp[numStuds];
	studIndex* passers;
	
	for(i = j = 0; i < numStuds; i++){
		if(S[i].examScores.exams[examNum].score >=  S[i].examScores.exams[examNum].totalScore * .60){
			strcpy(temp[j].idNum, S[i].idNum);
			temp[j].index = i;
			j++;
		}
	}	
	passers = malloc(sizeof(studIndex) * (j+1));
	if(passers != NULL){
		memcpy(passers, temp, sizeof(studIndex) * j);
		passers[j].index = -1;
	}
	
	return passers;
}

void displayStudent(student S[], int numStuds, int ndx, int examNum)
{
	printf("ID: %s | Name: %s %c. %s | Program: %s | Scores: %d\n", S[ndx].idNum, S[ndx].name.fName, S[ndx].name.mi, S[ndx].name.lName, S[ndx].course,
	S[ndx].examScores.exams[examNum].score);
}

void displayExamPassers(student S[], int numStuds, studIndex SI[], int examNum)
{
	int i;
	printf("Exam Number: %d\n", examNum+1);
	for(i = 0; SI[i].index != -1; i++){
		displayStudent(S, numStuds, SI[i].index, examNum);
	}
}

int main(void)
{
	student students[10] = {
	    {{"Alice", 'B', "Johnson"}, "22101234", "BSCS", 'F', {{{85, 100}, {75, 100}, {60, 100}, {90, 100}}, 4 }},
	    {{"Bob", 'C', "Smith"}, "21102345", "BSIT", 'M', {{{45, 100}, {70, 100}, {80, 100}, {65, 100}}, 4 }},
	    {{"Charlie", 'D', "Brown"}, "20103456", "BSIS", 'M', {{{78, 100}, {60, 100}, {85, 100}, {55, 100}}, 4 }},
	    {{"Diana", 'E', "Clark"}, "19104567", "BSCS", 'F', {{{60, 100}, {62, 100}, {90, 100}, {50, 100}}, 4 }},
	    {{"Ethan", 'F', "Lewis"}, "18105678", "BSIT", 'M', {{{70, 100}, {80, 100}, {90, 100}, {30, 100}}, 4 }},
	    {{"Fiona", 'G', "Martinez"}, "22106789", "BSIS", 'F', {{{85, 100}, {88, 100}, {90, 100}, {40, 100}}, 4 }},
	    {{"George", 'H', "Wilson"}, "21107890", "BSCS", 'M', {{{67, 100}, {75, 100}, {80, 100}, {90, 100}}, 4 }},
	    {{"Hannah", 'I', "Moore"}, "20108901", "BSIT", 'F', {{{55, 100}, {60, 100}, {85, 100}, {95, 100}}, 4 }},
	    {{"Ian", 'J', "Taylor"}, "19109012", "BSIS", 'M', {{{30, 100}, {40, 100}, {60, 100}, {70, 100}}, 4 }},
	    {{"Julia", 'K', "Anderson"}, "18101234", "BSCS", 'F', {{{90, 100}, {85, 100}, {70, 100}, {40, 100}}, 4 }}
	};
	int numStuds = sizeof(students) / sizeof(student);
	
	studIndex* exam1Passers = getExamPassers(students, numStuds, 0);
	studIndex* exam2Passers = getExamPassers(students, numStuds, 1);
	studIndex* exam3Passers = getExamPassers(students, numStuds, 2);
	studIndex* exam4Passers = getExamPassers(students, numStuds, 3);
	studIndex* exam5Passers = getExamPassers(students, numStuds, 4);
	
	displayExamPassers(students, numStuds, exam1Passers, 0);
	displayExamPassers(students, numStuds, exam2Passers, 1);
	displayExamPassers(students, numStuds, exam3Passers, 2);
	displayExamPassers(students, numStuds, exam4Passers, 3);
	
	return 0;
}
