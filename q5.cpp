#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add(char*** specie, int row, int col, int len) {
    for (int i = 0; i < row; i++) {
        printf("\n Enter Name of Animal: ");
        fgets(specie[i][0], len, stdin);
        specie[i][0][strcspn(specie[i][0], "\n")] = '\0';
        for (int j = 1; j <= col; j++) {  // Adjust for supplies
            printf("\n Enter Name of Supply: ");
            fgets(specie[i][j], len, stdin);
            specie[i][j][strcspn(specie[i][j], "\n")] = '\0';
        }
    }
}

void update(char*** specie, int row, int col) {
    char search[50];
    printf("\n Enter supply name to update: ");
    scanf("%[^\n]%*c", search);  // Using %[^\n] to capture the entire line and %*c to flush the newline
    search[strcspn(search, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 1; j <= col; j++) {  // Start from 1 to skip the animal name
            if (strcmp(specie[i][j], search) == 0) {
                printf("\n Enter New Supply: ");
                scanf("%[^\n]%*c", specie[i][j]);  // Input for new supply
                specie[i][j][strcspn(specie[i][j], "\n")] = '\0';
                found = 1;
                printf("\n Supply updated successfully\n");
                return;
            }
        }
    }

    if (!found) {
        printf("\n No Supply found\n");
    }
}

void deleteSpeice(char*** specie, int* row, int col) {
    char search[50];
    printf("\n Enter Animal name to delete: ");
    scanf("%[^\n]%*c", search);  // Input the animal name
    search[strcspn(search, "\n")] = '\0';

    int found = 0, index = -1;
    for (int i = 0; i < *row; i++) {
        if (strcmp(specie[i][0], search) == 0) {  // Check animal name
            found = 1;
            index = i;
            for (int j = 0; j <= col; j++) {
                free(specie[i][j]);
            }
            free(specie[i]);
            break;
        }
    }

    if (found) {
        for (int k = index; k < *row - 1; k++) {
            specie[k] = specie[k + 1];
        }
        (*row)--;
        specie = (char***)realloc(specie, (*row) * sizeof(char**));
        if (specie == NULL) {
            printf("\n Memory reallocation failed\n");
            exit(1);
        }
        printf("\n %s Deleted Successfully\n", search);
    } else {
        printf("\n No Animal found\n");
    }
}

void display(char*** specie, int row, int col) {
    for (int i = 0; i < row; i++) {
        printf("\n Animal Name: %s\n", specie[i][0]);
        printf(" Supplies:\n");
        for (int j = 1; j <= col; j++) {
            printf("  - %s\n", specie[i][j]);
        }
    }
}

int main(void) {
    int n, m, len = 50;
    printf("Welcome To Pets in Heart");
    printf("\n Enter Number of Species: ");
    scanf("%d", &n);
    printf("\n Enter Number of Supplies: ");
    scanf("%d", &m);
    getchar();  // Flush newline

    char*** speciesSupplies = (char***)malloc(n * sizeof(char**));
    if (speciesSupplies == NULL) {
        printf("\n Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        speciesSupplies[i] = (char**)malloc((m + 1) * sizeof(char*));
        if (speciesSupplies[i] == NULL) {
            printf("\n Memory allocation failed\n");
            exit(1);
        }
        for (int j = 0; j <= m; j++) {
            speciesSupplies[i][j] = (char*)malloc(len * sizeof(char));
            if (speciesSupplies[i][j] == NULL) {
                printf("\n Memory allocation failed\n");
                exit(1);
            }
        }
    }

    add(speciesSupplies, n, m, len);
    display(speciesSupplies, n, m);

    int exitProgram = 0;
    while (!exitProgram) {
        int choice;
        printf("\n 1 for delete, 2 for update, 3 for exit: ");
        scanf("%d", &choice);
        getchar();  // Flush newline
        switch (choice) {
            case 1:
                deleteSpeice(speciesSupplies, &n, m);
                break;
            case 2:
                update(speciesSupplies, n, m);
                display(speciesSupplies, n, m);
                break;
            case 3:
                printf("\n Bye bye :)\n");
                exitProgram = 1;
                break;
            default:
                printf("\n Invalid choice!");
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);

    return 0;
}

