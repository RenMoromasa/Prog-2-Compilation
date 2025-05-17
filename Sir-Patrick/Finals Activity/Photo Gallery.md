Photo Gallery
by Patrick Roy Elalto

You are asked to purge a folder to save up space within your drive, but at the same time you want to keep all photos within that folder. You can consider an item is a photo if it ends with the extension ".jpg"

 

Ask the user to continuously input file names until the user inputs "0" . After each input add the file name into a Linked List.

 

Once user has inputted 0, the user inputs will stop and the process of removing all non-photo file begins.

 

Once all non-photo files are removed, display the new contents of the linked list after the purging of files.

 

 

HINTS:

 

To check if the file name ends with ".jpg" we can use strcmp together with strlen. For example our string is called filename.

 

We would start by accessing filename, this would be referring to the starting address of that string, we then want to move to the end of the string we can do this by accessing (filename + strlen(filename) ), finally we move 4 bytes to get to 4 characters BEFORE end of string (filename + strlen(filename) - 4 ).

 

**filename**:

This is a pointer to the first character of the string filename.
**strlen(filename)**:

This returns the length of the string, excluding the null terminator '\0'.
For example, if filename = "image.jpg", strlen(filename) is 9 (since "image.jpg" has 9 characters).
**filename + strlen(filename)**:

This moves the pointer filename to the end of the string (just after the last character).
For "image.jpg", it points right after 'g', where the null terminator '\0' is located.
**filename + strlen(filename) - 4**:

This moves the pointer 4 positions backward from the end of the string.
In "image.jpg", moving 4 positions backward from '\0' points to the start of the substring .jpg.
 

 

So in short to be able to access the last 4 characters of a string we can use (filename + strlen(filename) - 4 ). Now you just need to integrate this with strcmp or something similar to check if the last 4 characters end with ".jpg"

Sample Output 1


Enter the photo filename: picnic.xls

Enter the photo filename: zebra.bmp

Enter the photo filename: emerald.rar

Enter the photo filename: church.jpg

Enter the photo filename: lego

Enter the photo filename: takoyaki.jpg

Enter the photo filename: image.jpg

Enter the photo filename: 0
Adding of photos to the gallery will be stopped...

CURRENT GALLERY:
picnic.xls
zebra.bmp
emerald.rar
church.jpg
lego
takoyaki.jpg
image.jpg


Removing All Non-Photo Files


UPDATED GALLERY:
church.jpg
takoyaki.jpg
image.jpg
Sample Output 2


Enter the photo filename: image1.jpg

Enter the photo filename: image2.jpg

Enter the photo filename: file.pdf

Enter the photo filename: file2.xls

Enter the photo filename: file3.rar

Enter the photo filename: image3.jpg

Enter the photo filename: phonebook.c

Enter the photo filename: image4.jpg

Enter the photo filename: 0
Adding of photos to the gallery will be stopped...

CURRENT GALLERY:
image1.jpg
image2.jpg
file.pdf
file2.xls
file3.rar
image3.jpg
phonebook.c
image4.jpg


Removing All Non-Photo Files


UPDATED GALLERY:
image1.jpg
image2.jpg
image3.jpg
image4.jpg