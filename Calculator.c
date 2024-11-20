#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main(int argc, char* argv[]) {
	char input[50];
	double nums[5];
	int operation_locs[3] = {0, 0, 0};
	int operation_num = 0;
	char operations[3];
	char equation_char;
	char temp_string[5];
	int count = 0;
	int count2 = 0;
	char* endPtr;
	int equation_nums = 0;
	int string_size = 0;
	char keep_going = ' ';
	printf("Do you want to enter an equation? enter q to quit: ");
	scanf("%c", &keep_going);
	while (keep_going != 'q') {
		printf("Enter an equation: ");
		scanf("%s", input);
		fflush(stdout);
		printf("\n");
		equation_char = input[count];
		int j;
		while (equation_char != '\0') {
			if (equation_char == '+' || equation_char == '-' || equation_char == '/' || equation_char == '*' || equation_char == '^') {
				if (equation_char == '-') {
					if (input[count - 1] != '+' && input[count - 1] != '-' && input[count - 1] != '/' && input[count - 1] != '*' && input[count - 1] != '^' && count - 1 > -1){
						operation_locs[operation_num] = count;
						operations[operation_num] = equation_char;
						operation_num += 1;	
					}
				}
				else {
					operation_locs[operation_num] = count;
					operations[operation_num] = equation_char;
					operation_num += 1;
				}
			}
			count += 1;
			equation_char = input[count];
		}
		printf("%d\n", operation_num);
		equation_char = ' ';
		for (int i = 0; i < operation_num; i++) {
			if (operations[i] == '+') {
				j = operation_locs[i];
				while (equation_char != '+' && equation_char != '/' && equation_char != '*' && equation_char != '\0' && equation_char != '^') {
					equation_char = input[j + 1 + count2];
					if (equation_char == '-') {
						if (input[j + count2] != '+' && input[count2 + j] != '-' && input[count2 + j] != '/' && input[count2 + j] != '*' && input[count2 + j] != '^') {
							break;
						}
						else if ((j + count2) < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				count2 = 0;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				equation_char = ' ';
				while ((j - string_size - 1) >= 0 && equation_char != '+' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size - 1];
					if (equation_char == '-') {
						if ((j - string_size - 2) < 0) {
							string_size += 1;
							break;
						}
						if (input[j - string_size - 2] != '+' && input[j - string_size - 2] != '-' && input[j - string_size - 2] != '/' && input[j - string_size - 2] != '*' && input[j - string_size - 2] != '^') {
							break;
						}
					}
					string_size += 1;
				}
				equation_char = ' ';
				while ((j - string_size + count2) >= 0 && equation_char != '+' && equation_char != '/' && equation_char != '*'&& equation_char != '^') {
					equation_char = input[j - string_size + count2];
					if (equation_char == '-') {
						if ((j - string_size + count2 - 1) < 0) {
							temp_string[count2] = equation_char;
							break;
						}
						if (input[j - string_size + count2 - 1] != '+' && input[j - string_size + count2 - 1] != '-' && input[j - string_size + count2 - 1] != '/' && input[j - string_size + count2 - 1] != '*' && input[j - string_size + count2 - 1] != '^') {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				equation_nums += 1;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				count2 = 0;
				printf("%lf %lf\n", nums[0], nums[1]);
				printf("%lf", nums[0] + nums[1]);
			}
			equation_nums = 0;
			string_size = 0;
			if (operations[i] == '-') {
				j = operation_locs[i];
				while (equation_char != '+' && equation_char != '/' && equation_char != '*' && equation_char != '\0' && equation_char != '^') {
					equation_char = input[j + 1 + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				count2 = 0;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				equation_char = ' ';
				while ((j - string_size - 1) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size - 1];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					string_size += 1;
				}
				equation_char = ' ';
				while ((j - string_size + count2) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				equation_nums += 1;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				count2 = 0;
				printf("%lf", nums[1] - nums[0]);
			}
			equation_nums = 0;
			string_size = 0;
			if (operations[i] == '*') {
				j = operation_locs[i];
				while (equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '\0' && equation_char != '^') {
					equation_char = input[j + 1 + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				count2 = 0;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				equation_char = ' ';
				while ((j - string_size - 1) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size - 1];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					string_size += 1;
				}
				equation_char = ' ';
				while ((j - string_size + count2) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				equation_nums += 1;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				count2 = 0;
				printf("%lf", nums[1] * nums[0]);
			}
			equation_nums = 0;
			string_size = 0;
			if (operations[i] == '/') {
				j = operation_locs[i];
				while (equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '\0' && equation_char != '^') {
					equation_char = input[j + 1 + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				count2 = 0;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				equation_char = ' ';
				while ((j - string_size - 1) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size - 1];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					string_size += 1;
				}
				equation_char = ' ';
				while ((j - string_size + count2) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				equation_nums += 1;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				count2 = 0;
				printf("%lf", nums[1] / nums[0]);
			}
			equation_nums = 0;
			string_size = 0;
			if (operations[i] == '^') {
				j = operation_locs[i];
				while (equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '\0' && equation_char != '^') {
					equation_char = input[j + 1 + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				count2 = 0;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				equation_char = ' ';
				while ((j - string_size - 1) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size - 1];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					string_size += 1;
				}
				equation_char = ' ';
				while ((j - string_size + count2) >= 0 && equation_char != '+' && equation_char != '-' && equation_char != '/' && equation_char != '*' && equation_char != '^') {
					equation_char = input[j - string_size + count2];
					if (equation_char == '-') {
						if (input[count2 - 1] == '+' || input[count2 - 1] == '-' || input[count2 - 1] == '/' || input[count2 - 1] == '*' || input[count2 - 1] == '^' || count2 - 1 < 0) {
							break;
						}
					}
					temp_string[count2] = equation_char;
					count2 += 1;
				}
				equation_nums += 1;
				nums[equation_nums] = strtod(temp_string, &endPtr);
				count2 = 0;
				printf("%lf", pow(nums[1], nums[0]));
			}
		}
		printf("\n");
		printf("Do you want to enter another equation? enter q to quit: ");
		scanf("%c", &keep_going);
	}
}