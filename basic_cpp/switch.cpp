#include<bits/stdc++.h>
using namespace std;

/*
If-else vs. Switch:
- If-else statements handle complex conditions and are flexible.
- Switch statements are concise, making the code cleaner and more structured, and are best used for comparing a single variable against multiple distinct values.

The switch Statement:
- Compares a variable to multiple distinct values.
- The break statement is crucial to prevent fall-through to subsequent cases.
- The default case serves as a catch-all for unmatched values.

Key Considerations:
- Requires a constant expression.
- Limited to integer or character types.
- The break keyword exits the switch statement.
- The default case is optional and executed if no case matches.
- Duplicate case values are not allowed.
- Nested switch statements are possible but can introduce complexity.
*/


int main() {
    int day;
    cout << "Enter a day number (1-7): ";
    cin >> day; // Input a day number from the user

    // Using switch to determine the day of the week
    switch(day) {
        case 1:
            cout << "Saturday" << endl;
            break; // Break prevents the fall-through to the next case
        case 2:
            cout << "Sunday" << endl;
            break; // Break prevents the fall-through to the next case
        case 3:
            cout << "Monday" << endl;
            break; // Break prevents the fall-through to the next case
        case 4:
            cout << "Tuesday" << endl;
            break; // Break prevents the fall-through to the next case
        case 5:
            cout << "Wednesday" << endl;
            break; // Break prevents the fall-through to the next case
        case 6:
            cout << "Thursday" << endl;
            break; // Break prevents the fall-through to the next case
        case 7:
            cout << "Friday" << endl;
            break; // Break prevents the fall-through to the next case
        default:
            cout << "Invalid Day" << endl; // This is executed if none of the above cases match
    }

    // Example without break statements to illustrate fall-through behavior
    cout << "\nExample without breaks:\n";
    switch(day) {
        case 1:
            cout << "Saturday" << endl;
        case 2:
            cout << "Sunday" << endl;
        case 3:
            cout << "Monday" << endl;
        case 4:
            cout << "Tuesday" << endl;
        case 5:
            cout << "Wednesday" << endl;
        case 6:
            cout << "Thursday" << endl;
        case 7:
            cout << "Friday" << endl;
        default:
            cout << "Invalid Day" << endl;
    }

    return 0; // Indicate that the program ended successfully
}
