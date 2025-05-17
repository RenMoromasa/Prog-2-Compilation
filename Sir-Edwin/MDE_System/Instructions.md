MDE - Aquarium Management System
by Edwin Bartlett

Due to the overwhelming number of fish they have, Cebu
Ocean Park is losing track of their aquariums. You are tasked
with creating a simple aquarium management system to track 
and manage the number of fish in each aquarium.

1. The main program is provided in main.c This outlines the 
expected input that the business owner wants to provide.

2. Define the corresponding structures in types.h:
    -Create a structure named "Color" to represent the color
    of a fish.
    -Create a structure named "Fish" to represent a fish.
    -Create a structure named "Aquarium" to represent an 
    aquarium

3. Create the required functions in functions.h:
    -Aquarium addFish(Aquarium aquarium, Fish fish)
    This function should add a "Fish" to an "Aquarium".
        -Check if the aquarium has reached its capacity.
        -If there is space, add the fish to the "fish_list"
         and increment "fish_count".
        -Print a message indicating that the fish was 
         added or that the aquarium is full.
    -void displayAquarium(Aquarium aquarium)- This
     function should display the detauks if an "Aquarium".
        Print the aquarium's name, capacity, and current
        fish count.
        If the aquarium is not empty, iterate through the 
        "fish_list" and print the name, age, and colors of
        each fish.

//============================== Sample Output 1 ==============================//
Nemo added to Reef Tank.
Dory added to Reef Tank.
Goldie added to Freshwater Tank.
Guppy added to Freshwater Tank.
Goldie added to Reef Tank.
Nemo added to Freshwater Tank.

Aquarium: Reef Tank
Capacity: 5
Fish Count: 3
Fish List:
- Name: Nemo, Age: 1, Colors: Orange White
- Name: Dory, Age: 2, Colors: Blue Yellow
- Name: Goldie, Age: 3, Colors: Gold

Aquarium: Freshwater Tank
Capacity: 3
Fish Count: 3
Fish List:
- Name: Goldie, Age: 3, Colors: Gold
- Name: Guppy, Age: 1, Colors: Red Black Silver
- Name: Nemo, Age: 1, Colors: Orange White
//============================== END ==============================//

