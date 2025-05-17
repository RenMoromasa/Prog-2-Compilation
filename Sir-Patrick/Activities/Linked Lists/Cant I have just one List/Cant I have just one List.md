Cant I have just one List?
by Patrick Roy Elalto

Students have started to ask to see their grades for their exams, so you decide to create an application to get the data necessary to show the students their grades, until you realize that theres an issue.

The data to show the grades isnt in a single list, but rather separated into 2 lists, one list containing the name of the students, and another list containing their respective grades. Both of these lists contain an idNumber member to help connect these lists together.

Since you have a completely different idea for the flow of your application, you decide to instead CREATE a NEW LINKED LIST, that contains the information of both lists, this way you only deal with a single List.

Student List:

{ {"Patrick", "Elalto"} , 13100270}

Grades List:

{ {80,81,82}, 13100270 }

Notice in this example that both lists contain a node with an idNumber of 13100270, this means that these nodes are connected, so "Patrick Elalto" has a grade of "80 , 81 , 82".

Note that both Student and Grades Linked List are properly populated already, if you are curious to what the data in these lists are you will have to display those items yourself.

Sample Output 1

Input ID Number of Student: 13100270

STUDENT NAME EXAM 1 Grade EXAM 2 Grade EXAM 3 Grade

---

Darwin Connelly 78 85 91
Sample Output 2

Input ID Number of Student: 15205423

STUDENT NAME EXAM 1 Grade EXAM 2 Grade EXAM 3 Grade

---

Catharine Keeling 80 83 81
Sample Output 3

Input ID Number of Student: 13622790

STUDENT NAME EXAM 1 Grade EXAM 2 Grade EXAM 3 Grade

---

Angus Auer 84 82 99
