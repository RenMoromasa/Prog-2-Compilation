#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define POKELIMIT 6
#define NUMENEMPOKEMON 5

enum status {FAINTED, HEALTHY};

typedef struct{
	char itemName[32];
	int itemQty;
}ItemDetails;

typedef struct ItemNode{
	ItemDetails item;
	struct ItemNode* nextItem;
}ItemNode, *TrainerBag;

typedef struct{
	char pokeDexNum[4];
	char pokeName[32];
	int combatPower;
	int status;
	ItemDetails heldItem;
}PokeDetails;

typedef struct{
	PokeDetails pokemon[POKELIMIT]; 
	int count;
}PokeBelt;

typedef struct{
	char trainerID[7];
	char trainerName[32];
	char trainerGender;
}TrainerDetails;

typedef struct{
	TrainerDetails details;
	PokeBelt team;
	TrainerBag bag;
}Trainer;

/* Provided Functions */
void generatePokeRecords(void);
void pause(void);
void loadBar(int barWidth, int loadTime);

/* Problem 1 */
void addPokemonToTeam(Trainer* T, PokeDetails P);
void initTrainer(Trainer* T, TrainerDetails TD, PokeDetails starter);
void displayPokemonTeam(PokeBelt PB);

/* Problem 2 */
void addItemToBag(Trainer* T, ItemDetails item);
void displayBagContents(TrainerBag TB);
void displayTrainer(Trainer T);

/* Problem 3 */
void useItem(TrainerBag* TB, char itemName[]);
void releasePokemon(PokeBelt* PB);

/* Problem 4 */
PokeDetails* getEnemyPokemon(void);
void pokeBattle(Trainer* T, PokeDetails enemy);

/* Problem 5 */
void saveFile(Trainer* T);
Trainer loadFile(TrainerDetails A);

int main(void)
{
	PokeDetails starters[3] = {{"001", "Bulbasaur", 100, HEALTHY, {"Miracle Seed", 1}},
							   {"002", "Squirtle", 100, HEALTHY, {"Mystic Water", 1}},
							   {"003", "Charmander", 100, HEALTHY, {"Charcoal", 1}}
							  };	
	PokeDetails* enemyPokemon;
 	
 	ItemDetails items[5] = {{"Potion", 5}, 
	 						{"Antidote", 1}, 
							{"Pokeball", 10}, 
							{"Town Map", 1}, 
							{"Chesto Berry", 2}
						   };
 	
	TrainerDetails AshKetchum = {"000001", "Ash Ketchum", 'M'};	
	Trainer Ash;
	Trainer Load;
	
	generatePokeRecords();
	/* Problem 1 */
	/* Instructions:
		1) Call the initTrainer() function. Pass the 1st index of starters as the 3rd parameter.
		2) Call the addPokemonToTeam() function, passing the 2nd index of starters to the function.
		3) Call the addPokemonToTeam() function, passing the 3rd index of starters to the function.
		4) Call the displayPokemonTeam() function.
		5) Call the pause() function.
	*/
	puts("PROBLEM 1");

	
	/* Problem 2 */
	/* Instructions:
		1) Call the addItemToBag() function, passing the 1st index of items.
		2) Call the addItemToBag() function, passing the 2nd index of items.
		3) Call the addItemToBag() function, passing the 3rd index of items.
		4) Call the addItemToBag() function, passing the 4th index of items.
		5) Call the addItemToBag() function, passing the 5th index of items.
		6) Call the addItemToBag() function, passing the 3rd index of items.
		7) Call the displayTrainer() function.
		8) Call the pause() function.
	*/
	puts("PROBLEM 2");

	
	/* Problem 3 */
	/* Instructions:
		1) Call the useItem() function, passing the name of the 1st item in array items.
		2) Call the useItem() function, passing the name of the 3rd item in array items.
		3) Call the useItem() function, passing the name of the 2nd item in array items.
		4) Call the releasePokemon() function.
		5) Call the releasePokemon() function.
		6) Call the releasePokemon() function.
		7) Call the addPokemonToTeam() function, passing starters[1] to the function.
		8) Call the addPokemonToTeam() function, passing starters[0] to the function.
		9) Call the displayTrainer() function.
		10) Call the pause() function.
	*/
	puts("PROBLEM 3");

	
	/* Problem 4.1 */
	/* Instructions:
		1) Call the getEnemyPokemon() function.
		2) Call the pokeBattle() function, passing enemyPokemon[0] as the 2nd parameter.
		3) Call the displayTrainer() function.
		4) Call the pause() function.
	*/
	puts("PROBLEM 4.1");

	
	/* Problem 4.2 */
	/* Instructions:
		1) Call the pokeBattle() function, passing enemyPokemon[3] as the 2nd parameter.
		2) Call the displayTrainer() function.
		3) Call the pause() function.
	*/
	puts("PROBLEM 4.2");

	
	/* Problem 5.1 */
	/* Instructions:
		1) Call the saveFile() function.
		2) Call the pause() function.
	*/
	puts("PROBLEM 5.1");
	
	
	/* Problem 5.2 */
	/* Instructions:
		1) Call the loadFile() function to store the read data into variable Load.
		2) Call the displayTrainer() function, passing Load as parameter.
		3) Call the pause() function.
	*/
	puts("PROBLEM 5.2");

	
	return 0;
}

/***************************************************************/
/**************** Provided Function Definitions ****************/
/***************************************************************/

void generatePokeRecords(void)
{
	PokeDetails pokemon[5] = {{"074", "Geodude", 74, HEALTHY, {"Hard Stone", 1}},
							  {"016", "Pidgey", 36, HEALTHY, {"", 0}},
							  {"041", "Zubat", 57, HEALTHY, {"", 0}},
							  {"150", "Mewtwo", 4096, HEALTHY, {"Mewtwonite X", 1}},
							  {"129", "Magikarp", 1, HEALTHY, {"Dragon Scale", 0}}
							 };
	FILE* fp = fopen("pokeRecords.txt", "w");
	if(fp != NULL){
		fwrite(pokemon, sizeof(PokeDetails), 5, fp);
		fclose(fp);
	}						 	
}

void pause(void)
{
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void loadBar(int barWidth, int loadTime)
{
    char loadBar[barWidth + 1]; 
    int loadState = 0, percent;
    
    memset(loadBar, '-', barWidth); 
    loadBar[barWidth] = '\0' ;
	printf("\n"); 
    for(percent = 0; percent <= 100; percent++){ 
        loadState = (percent * barWidth)/100; 
        memset(loadBar,'#',loadState) ; 
        printf("\rLOADING(%d%%):%s",percent,loadBar) ; 
        Sleep(loadTime*10); 
    } 
    Sleep(1000);
    printf("\nCOMPLETED!\n");
}

/*********************************************************************/
/**************** Functions Definitions for Problem 1 ****************/
/*********************************************************************/

/****************************************************************************************************
* addPokemonToTeam() - This function will add a new Pokemon into the Trainer's team as long as the  *
* there is still space in his Pokebelt.   															*
****************************************************************************************************/
void addPokemonToTeam(Trainer* T, PokeDetails P)
{

}

/****************************************************************************************************
* initTrainer() - This function will initialize the new Trainer with the passed TrainerDetails, as  *
* well as add their selected starter Pokemon to their team. Make sure to initialize all the other	*
* Trainer fields, specifically, their PokeBelt and TrainerBag to their respective EMPTY values.		*
****************************************************************************************************/
void initTrainer(Trainer* T, TrainerDetails TD, PokeDetails starter)
{

}

/****************************************************************************************************
* displayPokemonTeam() - This function will display ALL the Pokemon in the trainer's Pokebelt.		*
* Display each pokemon with the proper formatting given.											*
****************************************************************************************************/
void displayPokemonTeam(PokeBelt PB)
{
	printf("\n\n<-- Your Team -->\n");
	printf("%-20s", "Pokedex Number");
	printf("%-20s", "Pokemon");
	printf("%-20s", "Combat Power");
	printf("%-20s", "Held Item");
	printf("%-20s", "Status");
}

/*********************************************************************/
/**************** Functions Definitions for Problem 2 ****************/
/*********************************************************************/

/****************************************************************************************************
* addItemToBag() - This function adds an item into the Trainer's bag. If the item is already inside *
* the Trainer's bag, update the itemQty to be the sum of the current itemQty and the new itemQty.   *
* Else, if the item does not exist, insert the item into its proper place in the bag, sorted by	    *
* itemName.																							*
****************************************************************************************************/
void addItemToBag(Trainer* T, ItemDetails item)
{

}

/****************************************************************************************************
* displayBagContents() - This function will display ALL the contents inside a Trainer's bag			*
* with the proper format. 																			*
****************************************************************************************************/
void displayBagContents(TrainerBag TB)
{
	printf("\n\n<-- Your Bag -->\n");
	printf("%-20s", "Item Name");
	printf("%-20s", "Quantity");
}

/****************************************************************************************************
* displayTrainer() - This function will display ALL the details about the trainer, as well as all	*
* the pokemon on his/her team, and all the contents of their bag.								  	*
****************************************************************************************************/
void displayTrainer(Trainer T)
{
	printf("\n\n<-- %s: %s |%c| -->\n");
}

/*********************************************************************/
/**************** Functions Definitions for Problem 3 ****************/
/*********************************************************************/

/****************************************************************************************************
* useItem() - This function will go through the Trainer's bag and check if the passed itemName  	*
* matches any item within the bag. If it does, then decrement the item's qty and print a message    *
* stating that 1 pc of that item was used. If the item's qty reaches zero, delete the item from the *
* bag. 																								*
****************************************************************************************************/
void useItem(TrainerBag* TB, char itemName[])
{

}

/****************************************************************************************************
* releasePokemon() - This function will release the FIRST pokemon on the Trainer's team. This is	*
* Specifically, the function will delete the FIRST pokemon in the Pokebelt. Deletion is only		*
* possible when the Trainer still has more than one pokemon on his team.							*
****************************************************************************************************/
void releasePokemon(PokeBelt* PB)
{

}

/*********************************************************************/
/**************** Functions Definitions for Problem 4 ****************/
/*********************************************************************/

/****************************************************************************************************
* getEnemyPokemon() - This function will read ALL the records from a file called "pokeRecords.txt", *
* and store it in a dynamically allocated array. Return the array to the calling function			*
****************************************************************************************************/
PokeDetails* getEnemyPokemon(void)
{

}

/****************************************************************************************************
* pokeBattle() - This function simulates a Pokemon battle between a Trainer and a wild Pokemon. 	*
* A Pokemon battle usually follows this format: (Pseudocode)										*
*   0) Battle begins and will continue while the Trainer still has HEALTHY Pokemon on his team and 	*
*      the Enemy Pokemon is still HEALTHY.															*
* 	1) If the trainer's current Pokemon status is FAINTED, then increment your iterator such that   *
*	   you can check the next pokemon on the Trainer's Team.										*
*   2) Else, that Pokemon will battle with the enemy Pokemon.										*
*  	3) If the Trainer's Pokemon is stronger than the enemy Pokemon, then the enemy Pokemon's status *
*	   is set to FAINTED. The strength of a Pokemon is determined by its combatPower.				*
* 	4) If the enemy Pokemon has a heldItem, add that item to the Trainer's bag, and set the 		*
*	   enemy's heldItem to be "", and qty to be 0.													*
*	5) Finally, add the enemy Pokemon to the Trainer's team.										*
* 	6) Else, if the enemy Pokemon is stronger than the Trainer's Pokemon, set the Trainer's Pokemon * 
*	   status to FAINTED, and increment your iterator such that you can check the next pokemon on   *
*	   the Trainer's team.																			*
* 	7) If the Trainer runs out of healthy Pokemon, he loses the battle, and blacks out. 			*
****************************************************************************************************/
void pokeBattle(Trainer* T, PokeDetails enemy)
{

}

/*********************************************************************/
/**************** Functions Definitions for Problem 5 ****************/
/*********************************************************************/

/****************************************************************************************************
* saveFile() - This function will write into two seperate files ALL the Trainer's Pokemon and Items.*
* The Trainer's Pokemon will be saved in a file called "trainerPokemon.dat", while the items are to *
* be saved in a file named "trainerItems.dat".														*
****************************************************************************************************/
void saveFile(Trainer* T)
{

}

/****************************************************************************************************
* loadFile() - This function will read from the 2 files previously created, and store the data into *
* a Trainer variable which will be returned to the calling function.							    *
****************************************************************************************************/
Trainer loadFile(TrainerDetails A)
{
	printf("\nLoading data from file...");
	loadBar(20, 3);
}

