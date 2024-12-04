#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
double parseNumber(const char *str, int *index, char operation);
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
double parseNumber(const char *str, int *index, char operation) {
    double result = 0;
	char tempString[20] = " ";
	int i = 0;
	char* endPtr;
    while (isdigit(str[*index]) || str[*index] == '.' || str[*index] == '-') {
		if (str[*index] == '-') {
			if (*index - 1 < 0 || str[*index - 1] == '+' || str[*index - 1] == '-' || str[*index - 1] == '/' || str[*index - 1] == '*' || isalpha(str[*index - 1])) {
				tempString[i] = str[*index]; //puts numbers into a string
				i++;
			}
			else if (str[*index - 1] == ' ' && !isalpha(operation)) {
				if (*index - 2 < 0 || str[*index - 2] == '+' || str[*index - 2] == '-' || str[*index - 2] == '/' || str[*index - 2] == '*' || isalpha(str[*index - 2])) {
					tempString[i] = str[*index]; //puts numbers into a string
					i++;
				}
			}
			else if (isalpha(operation)) {
				tempString[i] = str[*index]; //puts numbers into a string
				i++;
			}
			else {
				break;
			}
		}
		else if (str[*index] != '-') {
			tempString[i] = str[*index];
			i++;
		}
        (*index)++;
    }
	result = strtod(tempString, &endPtr); //converts string into a double
    return result;
}

// Parse user input into operation and numbers
void parseInput(const char *input, char *operation, double *numbers, int *numCount) {
    int i = 0, j = 0;
    *numCount = 0;
	*operation = ' ';

    // Read operation
    while (isspace(input[i])) i++;
	for (int k = 0; k <= sizeof(input); k++) {
		if (isalpha(input[k]) || input[k] == '+' || input[k] == '-' || input[k] == '/' || input[k] == '*') {
			if (input[k] == '-') {
				if (k - 1 < 0 || input[k - 1] == '+' || input[k - 1] == '-' || input[k - 1] == '/' || input[k - 1] == '*' || isalpha(*operation)) {
					continue;
				}
				else if (input[k - 1] == ' ' && !isalpha(*operation)) {
					if (input[k - 2] == '+' || input[k - 2] == '-' || input[k - 2] == '/' || input[k - 2] == '*' || isalpha(*operation)) {
						continue;
					}
				}
			}
			*operation = input[k];
		}
	}
    // Read numbers
    while (input[j] != '\0') {
        while (isspace(input[j])) {
			j++;
		}
        if (isdigit(input[j]) || input[j] == '-' || input[j] == '.') {
			if (input[j] == '-') {
				if (j - 1 < 0 || input[j - 1] == '+' || input[j-1] == '-' || input[j - 1] == '/' || input[j - 1] == '*' || isalpha(input[j -1])) {
					numbers[(*numCount)++] = parseNumber(input, &j, *operation);
				}
				else if (input[j - 1] == ' ' && !isalpha(*operation)) {
					if (j - 2 < 0 || input[j - 2] == '+' || input[j - 2] == '-' || input[j - 2] == '/' || input[j - 2] == '*' || isalpha(input[j - 2])) {
						numbers[(*numCount)++] = parseNumber(input, &j, *operation);
					}
				}
				else if (isalpha(*operation)) {
					numbers[(*numCount)++] = parseNumber(input, &j, *operation);
				}
				else {
					j++;
				}
			}
			else if (input[j] != '-') {
				numbers[(*numCount)++] = parseNumber(input, &j, *operation);
			}
        } else {
            j++;
        }
    }
	printf ("operation: %c\n", *operation);
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
