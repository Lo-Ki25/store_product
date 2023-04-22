#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Structure pour stocker les informations de produit
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

// Fonction pour ajouter un produit
void add_product(Product products[], int *num_products) {
    // Vérifier si le nombre maximum de produits a été atteint
    if (*num_products == MAX_PRODUCTS) {
        printf("Le nombre maximum de produits est atteint.\n");
        return;
    }

    // Demander les informations de produit à l'utilisateur
    printf("Nom du produit : ");
    scanf("%s", products[*num_products].name);
    printf("Quantite : ");
    scanf("%d", &products[*num_products].quantity);
    printf("Prix : ");
    scanf("%f", &products[*num_products].price);

    // Incrémenter le nombre de produits
    (*num_products)++;

    printf("Produit ajoute avec succes.\n");
}

// Fonction pour afficher tous les produits
void display_products(Product products[], int num_products) {
    // Vérifier s'il y a des produits à afficher
    if (num_products == 0) {
        printf("Aucun produit n'est disponible.\n");
        return;
    }

    // Afficher les informations de chaque produit
    printf("%-20s %-10s %-10s\n", "Nom", "Quantite", "Prix");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Fonction pour rechercher un produit par nom
void search_product(Product products[], int num_products) {
    // Vérifier s'il y a des produits à rechercher
    if (num_products == 0) {
        printf("Aucun produit n'est disponible.\n");
        return;
    }

    // Demander le nom du produit à rechercher
    char name[MAX_NAME_LENGTH];
    printf("Nom du produit a rechercher : ");
    scanf("%s", name);

    // Parcourir tous les produits et afficher les correspondances
    bool found = false;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%-20s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
            found = true;
        }
    }

    // Si aucun produit n'a été trouvé, afficher un message approprié
    if (!found) {
        printf("Aucun produit trouve avec ce nom.\n");
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (true) {
        // Afficher le menu d'options
        printf("\n1. Ajouter un produit\n");
        printf("2. Afficher tous les produits\n");
        printf("3. Rechercher un produit par nom\n");
        printf("4. Quitter\n");

        // Demander à l'utilisateur de choisir une option
        int choice;
        printf("\nVotre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                display_products(products, num_products);
                break;
            case 3:
                search_product(products, num_products);
                break;
            case 4:
                // Quitter le programme
                printf("Merci d'avoir utilise ce programme.\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    }
}


