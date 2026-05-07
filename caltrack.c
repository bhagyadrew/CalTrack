#include <stdio.h>

int main() {
    float weight, height, bmi;
    float goal, totalCalories = 0, calories;
    char meal[50];
    int choice;

    printf("=== CALTRACK - Personal Calorie Tracker ===\n\n");
    printf("Enter your weight (kg): ");
    scanf("%f", &weight);
    printf("Enter your height (cm): ");
    scanf("%f", &height);

    height = height / 100;
    bmi = weight / (height * height);

    printf("\n--- Your BMI: %.2f ---\n", bmi);

    if (bmi < 18.5) {
        printf("Status: Building Phase\n");
        goal = 2500;
        printf("Recommended daily calories: 2500 kcal\n");
    } else if (bmi < 25.0) {
        printf("Status: Optimal Range\n");
        goal = 2000;
        printf("Recommended daily calories: 2000 kcal\n");
    } else {
        printf("Status: Wellness Journey\n");
        goal = 1500;
        printf("Recommended daily calories: 1500 kcal\n");
    }

    printf("\n=== LOG YOUR MEALS ===\n");
    printf("1. Breakfast\n2. Lunch\n3. Dinner\n4. Snacks\n0. Done\n");

    while (1) {
        printf("\nEnter meal type (0 to finish): ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0) break;

        switch(choice) {
            case 1: printf("Breakfast item: "); break;
            case 2: printf("Lunch item: "); break;
            case 3: printf("Dinner item: "); break;
            case 4: printf("Snack item: "); break;
            default: printf("Invalid!\n"); continue;
        }

        fgets(meal, 50, stdin);
        printf("Calories: ");
        scanf("%f", &calories);
        totalCalories += calories;
        printf("Added! Total so far: %.1f kcal\n", totalCalories);
    }

    printf("\n=== DAILY SUMMARY ===\n");
    printf("Your goal:       %.1f kcal\n", goal);
    printf("Total consumed:  %.1f kcal\n", totalCalories);

    if (totalCalories > goal) {
        printf("\n⚠ Exceeded by %.1f kcal! Try lighter meals tomorrow.\n", totalCalories - goal);
    } else if (totalCalories < goal - 200) {
        printf("\n⚠ Under by %.1f kcal! Make sure you eat enough.\n", goal - totalCalories);
    } else {
        printf("\n✓ Great job! Within your calorie goal today!\n");
    }

    return 0;
}