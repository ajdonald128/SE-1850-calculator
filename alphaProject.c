#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
double parseNumber(const char *str, int *index);
void parseInput(const char *input, char *operation, double *numbers, int *numCount);
double performCalculation(char operation, double *numbers, int numCount);
void quadraticFormula(double a, double b, double c);
double calculateAverage(double *numbers, int count);
void calculateArea(char shapeType, double param1, double param2);
void performTrigonometry(char trigOp, double angle);

// Main function
int main() {
    char input[256];
    char operation;
    double numbers[10];
    int numCount = 0;
    char choice;

    printf("Welcome to the String-based Calculator!\n");

    do {
        printf("\nEnter your calculation (e.g., '1 + 1', 'a for average', 'q for quadratic formula'): ");
        fgets(input, sizeof(input), stdin);

        parseInput(input, &operation, numbers, &numCount);

        if (operation == 'q') {
            if (numCount < 3) {
                printf("Please provide three coefficients (a, b, c).\n");
            } else {
                quadraticFormula(numbers[0], numbers[1], numbers[2]);
            }
        } else if (operation == 'a') {
            if (numCount > 0) {
                double result = calculateAverage(numbers, numCount);
                printf("Average: %.2f\n", result);
            } else {
                printf("No numbers provided for average calculation.\n");
            }
        } else if (operation == 's' || operation == 'c' || operation == 't') {
            performTrigonometry(operation, numbers[0]);
        } else if (operation == 'T' || operation == 'R' || operation == 'C') {
            if (numCount < 2) {
                printf("Please provide two parameters for area calculation.\n");
            } else {
                calculateArea(operation, numbers[0], numbers[1]);
            }
        } else if (strchr("+-*/", operation) && numCount >= 2) {
            double result = performCalculation(operation, numbers, numCount);
            printf("Result: %.2f\n", result);
        } else {
            printf("Unsupported operation or insufficient inputs.\n");
        }

        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator. Goodbye!\n");
    return 0;
}

// Parse a single number from a string
double parseNumber(const char *str, int *index) {
    char *endPtr;
    double value = strtod(&str[*index], &endPtr);
    *index = endPtr - str;
    return value;
}

// Parse user input into operation and numbers
void parseInput(const char *input, char *operation, double *numbers, int *numCount) {
    int i = 0;
    *numCount = 0;

    // Skip whitespace
    while (isspace(input[i])) i++;

    // Detect operation
    if (isalpha(input[i]) || strchr("+-*/", input[i])) {
        *operation = input[i++];
    } else {
        *operation = '+';  // Default operation
    }

    // Parse numbers
    while (input[i] != '\0') {
        while (isspace(input[i])) i++;
        if (isdigit(input[i]) || input[i] == '-') {
            numbers[(*numCount)++] = parseNumber(input, &i);
        } else {
            i++;
        }
    }
}

// Perform basic arithmetic calculations
double performCalculation(char operation, double *numbers, int numCount) {
    switch (operation) {
        case '+': return numbers[0] + numbers[1];
        case '-': return numbers[0] - numbers[1];
        case '*': return numbers[0] * numbers[1];
        case '/':
            if (numbers[1] == 0) {
                printf("Error: Division by zero.\n");
                return 0;
            }
            return numbers[0] / numbers[1];
        default:
            return 0;
    }
}

// Solve quadratic formula
void quadraticFormula(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots: %.2f, %.2f\n", root1, root2);
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots: %.2f + %.2fi, %.2f - %.2fi\n", realPart, imagPart, realPart, imagPart);
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
    switch (shapeType) {
        case 'C':
            printf("Area of circle: %.2f\n", M_PI * param1 * param1);
            break;
        case 'R':
            printf("Area of rectangle: %.2f\n", param1 * param2);
            break;
        case 'T':
            printf("Area of triangle: %.2f\n", 0.5 * param1 * param2);
            break;
        default:
            printf("Invalid shape type.\n");
    }
}

// Perform trigonometric operations
void performTrigonometry(char trigOp, double angle) {
    double radians = angle * M_PI / 180.0;
    switch (trigOp) {
        case 's': printf("sin(%.2f) = %.2f\n", angle, sin(radians)); break;
        case 'c': printf("cos(%.2f) = %.2f\n", angle, cos(radians)); break;
        case 't': printf("tan(%.2f) = %.2f\n", angle, tan(radians)); break;
        default: printf("Invalid trigonometric function.\n");
    }
}
