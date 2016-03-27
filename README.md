# Simple-Database
simple-database-challenge

## Synopsis

This project is for the simple-database-challenge(https://www.thumbtack.com/challenges/simple-database). 

## Thought process

The description of the challenge gives me a lot of hints. As for me, the most confused part of the challenge is how to implement the BEGIN and ROOLBACK commands. In the description,

BEGIN – Open a new transaction block.  (I need to create a block to store the updates in this transaction)

ROLLBACK – Undo all of the commands issued in the most recent transaction block, and close the block. (I need to maintain a stack to store all blocks, and pop the top block when meets ROLLBACK command after undo the updates in the top block)

And the left things are easy.

## Flaws

I am confused how to show the error message when there is no entry in the database.
I got two ways to implement this. 
1. Return INT_MIN or any specific number.  But, there is a probability that the value of the varible is exactly equal to the specific number.
2. Use strings to store the values, so it's easily to determain whether there is an entry in the database. But, it's need more effort to translate the format of the values.

From my view, it doesn't make sense to use a string to store a integer. And it's reasonable to set a key-value which don't allow user to use. So, I choose the first implementation.

I know this problem could be solved by return a NULL to a interger in JAVA, but what should I do in C++.


## Installation and Tests

1. Unzip simple-database.zip
2. Go into the simple-database directory by command line  (i.e cd simple-database/)
3. Complie the main.cpp file into an executable program   (i.e g++ main.cpp -o hello)
4. Execute program with arguments, which means passing a file of commands to standard input     (i.e ./hello test.txt)
5. Or execute program interactively   (i.e ./hello)

