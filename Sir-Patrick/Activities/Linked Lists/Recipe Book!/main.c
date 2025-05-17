#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


// Function to check if a recipe can be made with the available ingredients
int canMakeRecipe(Recipe recipe, IngredientNode* ingredients) {
    /* 6.) Write code to check if Recipe can be made using the available ingredients*/
}

int findRecipe(Recipe* recipeList,char* recipeName){
    /* 3.) Write the code to find the selected recipe */
}

int main() {
    IngredientNode* ingredients = NULL;
    ingredients=populate();

    Recipe* recipes = populateRecipe();
    printf("\nRecipes:\n");
    printRecipes(recipes,MAX_RECIPES);
    /* 1.) Print Recipes */


    // Ask user for recipe choice
    char recipeName[50];
    printf("\nEnter the name of the recipe you want to check: ");
    scanf("%[^\n]s",recipeName);

    int foundRecipe = findRecipe(recipes,recipeName);
    /* 2.) Call to check if recipe exits */



    /* 4.) Display the Recipe and Display its Individual ingredients */



    /* 5.) Call Function to check if Recipe can be made based on
    available ingredients*/



    return 0;
}