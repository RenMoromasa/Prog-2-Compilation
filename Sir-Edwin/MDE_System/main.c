#include <stdio.h>
#include <string.h>
#include "types.h"
#include "functions.h"

int main() {
    Aquarium aquariums[MAX_AQUARIUMS];

    // Initialize aquariums
    strcpy(aquariums[0].aquarium_name, "Reef Tank");
    aquariums[0].capacity = 5;
    aquariums[0].fish_count = 0;

    strcpy(aquariums[1].aquarium_name, "Freshwater Tank");
    aquariums[1].capacity = 3;
    aquariums[1].fish_count = 0;

    // Create some fish
    Fish fish1;
    strcpy(fish1.name, "Nemo");
    fish1.age = 1;
    strcpy(fish1.colors[0].color, "Orange");
    strcpy(fish1.colors[1].color, "White");
    fish1.colors[2].color[0] = '\0'; //terminate the color array

    Fish fish2;
    strcpy(fish2.name, "Dory");
    fish2.age = 2;
    strcpy(fish2.colors[0].color, "Blue");
    strcpy(fish2.colors[1].color, "Yellow");
    fish2.colors[2].color[0] = '\0';

    Fish fish3;
    strcpy(fish3.name, "Goldie");
    fish3.age = 3;
    strcpy(fish3.colors[0].color, "Gold");
    fish3.colors[1].color[0] = '\0';

    Fish fish4;
    strcpy(fish4.name, "Guppy");
    fish4.age = 1;
    strcpy(fish4.colors[0].color, "Red");
    strcpy(fish4.colors[1].color, "Black");
    strcpy(fish4.colors[2].color, "Silver");

    // Add fish to aquariums
    aquariums[0] = addFish(aquariums[0], fish1);
    aquariums[0] = addFish(aquariums[0], fish2);
    aquariums[1] = addFish(aquariums[1], fish3);
    aquariums[1] = addFish(aquariums[1], fish4);
    aquariums[0] = addFish(aquariums[0], fish3); //add goldie to reef tank to test capacity.
    aquariums[1] = addFish(aquariums[1], fish1);//add nemo to freshwater to test capacity.

    // Display aquariums
    for (int i = 0; i < 2; i++) {
        displayAquarium(aquariums[i]);
    }

    return 0;
}