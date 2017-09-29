/* PROGRAMMER: Mia Saint Clair
 * CLASS: CS41 Data Structures
 * ASSIGNMENT: Program 1 - Linked Lists
 * DESCRIPTION: This program acts as a reverse polish notation calculator
 * It reads values in from the console in reverse polish notation then
 * calculates and outputs the answer. The program accounts for errors
 * involving too many operators or operands and for division by 0.
 */
#include "Stack.h"

//PROTOTYPES
bool isOperator(const string input);
void performOperation(const string input, Stack & calculator);

int main(){

	//VARIABLE DECLARATION
	Stack calculator;
	string input;
	float num;
	int countOperand = 0;
	int countOperator = 0;
	int elementRatio = 0;

	cout << "Enter your calculations: \n";

	//Runs until user enters 0
	cin >> input;
	while(input != "0\n")
	{
		//Checks if the value entered is a numerical value, if so it
		//pushes the number onto the stack of linked lists
		if(istringstream(input) >> num)
		{
			calculator.push(num);
			countOperand++;
		}
		// check for operator in function returning bool and if so,
		//performs specified operation on the two numbers on the top
		//of the stack and pushes the answer onto the stack
		else if(isOperator(input))
		{
			countOperator++;
			performOperation(input, calculator);
		}
		//program does not output any answers until = is read in,
		//checks for errors involving too many operators/operands by
		//keeping counts of each and checking that there is one more
		//operand than operator and resets counts after equation is done
		else if(input[0] == '=')
		{
			elementRatio = countOperand - countOperator;
			if(elementRatio == 1)
				calculator.printHead();
			else if (elementRatio < 1)
				cout << "Error: Too many operators\n";
			else
				cout << "Error: too many operands\n";
			countOperand = 0;
			countOperator = 0;
		}
		cin >> input;
	}
	cout << "ending calculator";
	return 0;
}

//Function checks if input is a operator + - * or / returning bool
bool isOperator(const string input)
{
    bool isOp = false;
	static const string operators = "-+*/";

    if (operators.find_first_of(input) != string::npos)
    		isOp = true;
    return isOp;
}

//performs the specified calculation on the first two numbers on the stack
//pops those numbers off the stack and pushes result of operation on it
//Checks for divide by zero error here
void performOperation(const string input, Stack & calculator)
{
	float op2 = calculator.pop();
	float op1 = calculator.pop();
	float result = 0;
	switch (input[0])
	{
	case '+': result = op1 + op2;
		break;
    case '-': result = op1 - op2;
    		break;
    case '*': result = op1 * op2;
    		break;
    case '/':
    		if(op2 != 0)
    			result = op1 / op2;
    		else
    			cout << "ERROR: DIVISION BY 0";
    		break;
    default: cout << "ERROR ON OPERATION";
    		break;
	}
	calculator.push(result);
}


/* OUTPUT:
 * Enter your calculations:
 * 10 15 - =
 * -5
 * 10 15 + =
 * 25
 * 2.5 3.5 + =
 * 6
 * 10 0 / =
 * ERROR: DIVISION BY 00
 * 12 20 30 / =
 * Error: too many operands
 * 10 20 * / =
 * Error: Too many operators
 * -10 -30 - =
 * 20
 * 100 10 50 25 / * - -2 / =
 * -40
 * 0
 */
