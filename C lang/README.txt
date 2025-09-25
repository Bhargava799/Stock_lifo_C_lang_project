Problem Statement: (includes a Stock Table)
Companies and people often buy and sells stocks. Often they buy the same stock for different
prices at different times. Say a person owns 1000 shares a certain stock (such as Checkpoint), she
may have bought the stock in amounts of 100 shares over 10 different times with 10 different
prices.
In this assignment, you will be using a stack for LIFO accounting. You should use an array
based implementation for your stack based implementation or a linked list for implementing your
stack. Your stack should have records with the following fields:
➢ The name of the stock (a string or int)
➢ The number of shares of a stock (an int)
➢ The purchase price (can be a decimal)
You can assume that the first element of the structure is the security bought first, the second
was bought second, etc.
Create a program that should have the user able to enter information about various stocks, the
amount of shares, and the price. The user can then enter a query about a certain stock and the
cost according to the LIFO accounting methods for a certain number of shares.
The following could be your menu:
➢ Press 1 to enter a new stock.
➢ Press 2 to find the LIFO price for a stock.
➢ If 1 is pressed, the user needs to enter the stock symbol, and the number of shares, and
the price.
➢ If 2 is pressed, the user needs to enter the stock symbol being queried and the number of
shares in question.


ALGORITHM
Step 1: Start
Step 2: Define Data Structure
Create a structure StockRecord that holds: stock_name , a string representing the name of the stock. Shares: An integer representing the number of shares purchased. Price: A decimal value representing the price per share.
Step 3: Define a structure 
Stack to hold an array of StockRecord objects and an integer top representing the index of the top of the stack.
Step 4: Define a function initStack that sets top to -1, indicating an empty stack. Step 5: Check if Stack is Empty:
Function isEmpty returns 1 if top == -1 (true), indicating the stack is empty.
Step 6: Check if Stack is Full:
Function isFull returns 1 if top == MAX_STOCKS - 1 (true), indicating the stack is full.
Step 7: Push a Stock Record:
Function push adds a StockRecord to the stack if it is not full. Increment top and add the record at the new top position. If the stack is full, print an error message.
Step 8: Pop a Stock Record:
Function pop removes and returns the top StockRecord if the stack is not empty. Decrement top and return the popped record. If the stack is empty, print an error message and return an empty StockRecord.
Step 9: Calculate LIFO Price
calculateLIFO Function: Takes the stack, a stock name, and the number of shares to sell as input. Initializes remainingShares to the requested number of shares. Initializes totalCost to 0.0. Creates a temporary stack to store records during processing. While there are remainingShares and the stack is not empty: Pop a StockRecord from the stack. If the stock_name matches: Calculate sharesToUse as the minimum of remainingShares and the shares in the popped record. Add sharesToUse * price to totalCost. Subtract sharesToUse from remainingShares. If the popped record has leftover shares, push the remainder back to the temporary stack. Push unmatched records directly into the temporary stack. Restore the original stack by popping all records from the temporary stack and pushing them back onto the main stack. If remainingShares > 0, print an error message and return -1 (indicating insufficient shares). Return totalCost for the requested shares.
Step 10: Main Function and Menu Loop
Main Function and User Interaction. Initialize the stockStack. Display a menu to the user in a loop: Option 1: Add a new stock record: Prompt for stock_name, shares, and price. Create a StockRecord and use push to add it to stockStack. Display a confirmation message. Option 2: Calculate LIFO price for a stock sale: Prompt for stock_name and shares. Use calculateLIFO to determine the total cost. Display the total cost if valid (greater than or equal to zero). Option 3: Exit the program: Break out of the loop and terminate. Invalid Input: Display an error message and return to the menu.
Step 11: Stop

Conclusion

This project implements a stack for Last-In-First-Out (LIFO) accounting to manage stock purchases and sales. It allows users to enter stock details and calculate the cost of selling specific shares, following LIFO rules. The project demonstrates how data structures like stacks can simplify real-world financial operations. Overall, it provides a clear and functional solution for basic stock management.

What I Learned

How to implement linked lists and stack operations (push and pop) in C.

How to manage dynamic memory using malloc and free.

How to create a menu-driven program for user input.

How to apply LIFO accounting logic in a real-world scenario.

How to debug and test a program that manages multiple records dynamically.
