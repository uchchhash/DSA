#include<bits/stdc++.h>
using namespace std;

/*
If-else Statement:
- Used to execute a block of code only if a certain condition is met.
- Provides flexibility to conditionally execute code based on whether the specified condition is true.
- Optional else statement specifies what code to execute if the condition in the if statement is not met.

Flow of Control:
- If the test condition in the if statement is true, the block of code inside the if block will be executed.
- If the test condition is false, the code inside the else block (if present) will be executed.

Simplifying Code with "else if":
- else if statements streamline code when multiple conditions need to be checked.
- Example: Grading students based on their marks within specific ranges.
- Each else if statement allows for additional conditions to be evaluated if the preceding conditions are not met.
- Reduces redundancy and improves readability compared to multiple independent if statements.
*/




int main() {
    // Declare an integer variable to store age
    int age;
    
    // Prompt the user to enter their age
    cout << "Enter your age: ";
    cin >> age; // Take input from the user

    // If-else example
    if (age >= 18) { // Check if age is 18 or more
        cout << "You are an Adult" << endl; // If true, print this message
    } else { // If the condition above is not true
        cout << "You are not an Adult" << endl; // Print this message
    }

    // Else-if example
    if (age < 13) { // Check if age is less than 13
        cout << "You are a Child" << endl; // If true, print this message
    } else if (age >= 13 && age < 18) { // Else, check if age is between 13 and 17 inclusive
        cout << "You are a Teenager" << endl; // If true, print this message
    } else { // If none of the above conditions are true
        cout << "You are an Adult" << endl; // Print this message
    }

    // Nested if-else example
    if (age >= 18) { // Check if age is 18 or more
        cout << "You are eligible to vote" << endl; // If true, print this message

        if (age >= 21) { // Nested check: If age is 21 or more
            cout << "You are eligible to drink alcohol in some countries" << endl; // If true, print this message
        } else { // Nested else
            cout << "You are not eligible to drink alcohol in some countries" << endl; // If false, print this message
        }

    } else { // If the initial age check is false
        cout << "You are not eligible to vote" << endl; // Print this message
    }

    // Complex else-if usage
    if (age < 0) { // Check if age is less than 0
        cout << "Invalid age" << endl; // If true, print this message
    } else if (age == 0) { // Check if age is exactly 0
        cout << "You are just born" << endl; // If true, print this message
    } else if (age < 13) { // Check if age is less than 13
        cout << "You are a Child" << endl; // If true, print this message
    } else if (age >= 13 && age < 18) { // Check if age is between 13 and 17 inclusive
        cout << "You are a Teenager" << endl; // If true, print this message
    } else if (age >= 18 && age < 65) { // Check if age is between 18 and 64 inclusive
        cout << "You are an Adult" << endl; // If true, print this message
    } else { // If none of the above conditions are true
        cout << "You are a Senior" << endl; // Print this message
    }

    return 0; // Indicate that the program ended successfully
}
