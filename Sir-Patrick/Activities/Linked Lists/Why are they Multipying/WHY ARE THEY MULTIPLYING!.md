WHY ARE THEY MULTIPLYING!
by Patrick Roy Elalto

THE LIST ITS GETTING LARGER!

 

You are in charge of an invasion of numbers, to overwhelm your opponents. But simply amassing these numbers isnt a simple task, and it would be much to difficult to get these numbers yourself. So you decide instead to generate these new numbers based on the value of the previous node.

 

Create a program that will ask the user for a number of nodes to be added to the linked list. Populate these nodes first.

 

After the linked list has been properly populated modify in it such a way that you insert a new node inbetween all the nodes in the linked list effectively doubling the size of the linked list.

 

The values to insert inbetween the nodes will be determined if the PREVIOUS NODE is EVEN or ODD

 

If the previous node is EVEN the value of the node to be inserted will be DOUBLE the previous value

If the previous node is ODD the value of the node to be inserted will be +1 of the previous value

Sample Output 1

Enter the number of nodes: 6
Enter the values for the nodes:
6
5
4
3
2
1
Original list:
6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
Modified list:
6 -> 12 -> 5 -> 6 -> 4 -> 8 -> 3 -> 4 -> 2 -> 4 -> 1 -> 2 -> NULL
Sample Output 2

Enter the number of nodes: 5
Enter the values for the nodes:
9
15
5
3
7
Original list:
9 -> 15 -> 5 -> 3 -> 7 -> NULL
Modified list:
9 -> 10 -> 15 -> 16 -> 5 -> 6 -> 3 -> 4 -> 7 -> 8 -> NULL
Sample Output 3

Enter the number of nodes: 5
Enter the values for the nodes:
2
4
6
8
10
Original list:
2 -> 4 -> 6 -> 8 -> 10 -> NULL
Modified list:
2 -> 4 -> 4 -> 8 -> 6 -> 12 -> 8 -> 16 -> 10 -> 20 -> NULL