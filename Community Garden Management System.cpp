#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Plant {
    int id;
    char name[50];
    char gardener[50];
    int waterDays;
    int harvest;
};

void addPlant();
void viewPlants();
void searchPlant();
void updatePlant();
void deletePlant();

int main() {
    int choice;

    while (1) {
        printf("\n===== COMMUNITY GARDEN MANAGEMENT =====\n");
        printf("1. Add Plant\n");
        printf("2. View Plants\n");
        printf("3. Search Plant\n");
        printf("4. Update Plant\n");
        printf("5. Delete Plant\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addPlant(); break;
            case 2: viewPlants(); break;
            case 3: searchPlant(); break;
            case 4: updatePlant(); break;
            case 5: deletePlant(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void addPlant() {
    FILE *fp;
    struct Plant p;

    fp = fopen("garden.txt", "a");

    printf("Enter Plant ID: ");
    scanf("%d", &p.id);

    printf("Enter Plant Name: ");
    scanf("%s", p.name);

    printf("Enter Gardener Name: ");
    scanf("%s", p.gardener);

    printf("Water every how many days: ");
    scanf("%d", &p.waterDays);

    printf("Harvest Quantity: ");
    scanf("%d", &p.harvest);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("Plant Added Successfully!\n");
}

void viewPlants() {
    FILE *fp;
    struct Plant p;

    fp = fopen("garden.txt", "r");

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Plant Records ---\n");

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d", p.id);
        printf("\nPlant: %s", p.name);
        printf("\nGardener: %s", p.gardener);
        printf("\nWater Every: %d days", p.waterDays);
        printf("\nHarvest: %d\n", p.harvest);
    }

    fclose(fp);
}

void searchPlant() {
    FILE *fp;
    struct Plant p;
    int id, found = 0;

    printf("Enter Plant ID to search: ");
    scanf("%d", &id);

    fp = fopen("garden.txt", "r");

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("\nPlant Found\n");
            printf("Name: %s\n", p.name);
            printf("Gardener: %s\n", p.gardener);
            printf("Water Days: %d\n", p.waterDays);
            printf("Harvest: %d\n", p.harvest);
            found = 1;
        }
    }

    if (!found)
        printf("Plant not found.\n");

    fclose(fp);
}

void updatePlant() {
    FILE *fp, *temp;
    struct Plant p;
    int id, found = 0;

    printf("Enter Plant ID to update: ");
    scanf("%d", &id);

    fp = fopen("garden.txt", "r");
    temp = fopen("temp.txt", "w");

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("Enter new Plant Name: ");
            scanf("%s", p.name);

            printf("Enter new Gardener: ");
            scanf("%s", p.gardener);

            printf("Enter Water Days: ");
            scanf("%d", &p.waterDays);

            printf("Enter Harvest: ");
            scanf("%d", &p.harvest);

            found = 1;
        }

        fwrite(&p, sizeof(p), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("garden.txt");
    rename("temp.txt", "garden.txt");

    if (found)
        printf("Record Updated!\n");
    else
        printf("Plant not found.\n");
}

void deletePlant() {
    FILE *fp, *temp;
    struct Plant p;
    int id, found = 0;

    printf("Enter Plant ID to delete: ");
    scanf("%d", &id);

    fp = fopen("garden.txt", "r");
    temp = fopen("temp.txt", "w");

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id != id) {
            fwrite(&p, sizeof(p), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("garden.txt");
    rename("temp.txt", "garden.txt");

    if (found)
        printf("Record Deleted!\n");
    else
        printf("Plant not found.\n");
}
