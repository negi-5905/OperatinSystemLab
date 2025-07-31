#include <stdio.h>
#include <string.h>

int main() {
    FILE *f1, *f2;
    char line1[100], line2[100];
    f1 = fopen("my_details.txt", "w");
  
    fprintf(f1, "Name: Mayank\n");
    fprintf(f1, "City: Dehradun\n");
    fprintf(f1, "Age: 21\n");
    fclose(f1);

    f2 = fopen("friend_details.txt", "w");
    fprintf(f2, "Name: Rahul\n");
    fprintf(f2, "City: Dehradun\n");
    fprintf(f2, "Age: 22\n");
    fclose(f2);

    f1 = fopen("my_details.txt", "r");
    f2 = fopen("friend_details.txt", "r");

    printf("Matching lines:\n");

    while (fgets(line1, sizeof(line1), f1)) {
        rewind(f2);
        while (fgets(line2, sizeof(line2), f2)) {
            if (strcmp(line1, line2) == 0) {
                printf("%s", line1);
            }
        }
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
