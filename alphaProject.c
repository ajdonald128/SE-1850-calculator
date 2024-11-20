#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Function prototypes
double parseNumber(const char *str, int *index);
void parseInput(const char *input, char *operation, double *numbers, int *numCount);
double performCalculation(char operation, double *numbers, int numCount);
void quadraticFormula(double a, double b, double c);
double calculateAverage(double *numbers, int count);
void calculateArea(char shapeType, double param1, double param2);
void performTrigonometry(char trigOp, double angle);
void test(char trigOp, double angle);

// Main function
int main() {
    char input[256];
    char operation;
    double numbers[10];
    int numCount = 0;
    char choice;

    printf("Welcome to the String-based Calculator!\n");

    do {
        // Get user input
        printf("\nEnter your calculation (e.g., '1 + 1' or 'a for average'): ");
        fgets(input, sizeof(input), stdin);

        // Parse input
        parseInput(input, &operation, numbers, &numCount);

        if (operation == 'q') {
            // Quadratic formula
            if (numCount < 3) {
                printf("Please provide three coefficients (a, b, c).\n");
            } else {
                quadraticFormula(numbers[0], numbers[1], numbers[2]);
            }
        } else if (operation == 'a') {
            // Average calculation
            double result = calculateAverage(numbers, numCount);
            printf("Average: %.2f\n", result);
        } else if (operation == 's' || operation == 'c' || operation == 't') {
            // Trigonometry functions
            performTrigonometry(operation, numbers[0]);
        } else if (operation == 'r' || operation == 't' || operation == 'c') {
            // Area calculations
            calculateArea(operation, numbers[0], numbers[1]);
        } else {
            // Basic arithmetic
            double result = performCalculation(operation, numbers, numCount);
            printf("Result: %.2f\n", result);
        }

        // Ask user to continue or quit
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator. Goodbye!\n");
    return 0;
}

// Parse a single number from a string
double parseNumber(const char *str, int *index) {
    double result = 0;
    sscanf(&str[*index], "%lf", &result);
    while (isdigit(str[*index]) || str[*index] == '.' || str[*index] == '-') {
        (*index)++;
    }
    return result;
}

// Parse user input into operation and numbers
void parseInput(const char *input, char *operation, double *numbers, int *numCount) {
    int i = 0, j = 0;
    *numCount = 0;

    // Read operation
    while (isspace(input[i])) i++;
    *operation = input[i++];
    
    // Read numbers
    while (input[i] != '\0') {
        while (isspace(input[i])) i++;
        if (isdigit(input[i]) || input[i] == '-' || input[i] == '.') {
            numbers[(*numCount)++] = parseNumber(input, &i);
        } else {
            i++;
        }
    }
}

// Perform basic arithmetic calculations
double performCalculation(char operation, double *numbers, int numCount) {
   // if (operation == '+') return numbers[0] + numbers[1];
   // if (operation == '-') return numbers[0] - numbers[1];
    //if (operation == '*') return numbers[0] * numbers[1];
   // if (operation == '/') {
    //    if (numbers[1] == 0) {
    //        printf("Error: Division by zero.\n");
 //           return 0;
    //    }
    //    return numbers[0] / numbers[1];
   // }
   // return 0;
}

// Solve quadratic formula
void quadraticFormula(double a, double b, double c) {
  //  double discriminant = b * b - 4 * a * c;

   // if (discriminant >= 0) {
    //    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    //    double root2 = (-b - sqrt(discriminant)) / (2 * a);
   //     printf("Roots: %.2f, %.2f\n", root1, root2);
   // } else {
     //   double realPart = -b / (2 * a);
    //    double imagPart = sqrt(-discriminant) / (2 * a);
     //   printf("Roots: %.2f + %.2fi, %.2f - %.2fi\n", realPart, imagPart, realPart, imagPart);
    }
}

// Calculate average of numbers
double calculateAverage(double *numbers, int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

// Calculate area of a shape
void calculateArea(char shapeType, double param1, double param2) {
   /**
   
    */
}

// Perform trigonometric operations
void performTrigonometry(char trigOp, double angle) {

  /**
   
    */
}