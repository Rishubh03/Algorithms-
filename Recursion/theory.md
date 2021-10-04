# What is Recursion? 

The process in which a function calls itself directly or indirectly is called recursion and the corresponding function is called as recursive function.

# What is base condition in recursion? 

In the recursive program, the solution to the base case is provided and the solution of the bigger problem is expressed in terms of smaller problems. 

int fact(int n)
{
    if (n < = 1) // base case
        return 1;
    else    
        return n*fact(n-1);    
}

# How a particular problem is solved using recursion? 

	1. The idea is to represent a problem in terms of one or more smaller problems, 
	2. And add one or more base conditions that stop the recursion.

# Why Stack Overflow error occurs in recursion? 

If the base case is not reached or not defined, then the stack overflow problem may arise. 

Example 
int fact(int n)
{
    // wrong base case (it may cause
    // stack overflow).
    if (n == 100) 
        return 1;

    else
        return n*fact(n-1);
}

# What is the difference between direct and indirect recursion? 

A function fun is called direct recursive if it calls the same function fun.
A function fun is called indirect recursive if it calls another function say fun_new and fun_new calls fun directly or indirectly. 

// An example of direct recursion

void directRecFun()
{
    // Some code....

    directRecFun();

    // Some code...
}

// An example of indirect recursion

void indirectRecFun1()
{
    // Some code...

    indirectRecFun2();

    // Some code...
}
void indirectRecFun2()
{
    // Some code...

    indirectRecFun1();

    // Some code...
}

Sample Problems:

	1. Print 1 to N
	2. Print N to 1
	3. Print Fibonacci series
	4. Find Factorial
	5. Print sum of N natural Numbers

# What are the disadvantages of recursive programming over iterative programming? 

	1. Both have the same problem-solving powers.
	2. Every recursive program can be written iteratively and vice versa is also true.
	3. The recursive program has greater space requirements than iterative program as all functions will remain in the stack until the base case is reached.
	4. It also has greater time requirements because of function calls and returns overhead.

# What are the advantages of recursive programming over iterative programming? 

	1. Recursion provides a clean and simple way to write code.
	2. Some problems are inherently recursive like tree traversals, Tower of Hanoi, etc. but we can write such codes also iteratively with the help of a stack data structure.
	
# What is difference between tailed and non-tailed recursion? 
A recursive function is tail recursive when recursive call is the last thing executed by the function.

# Which one is Better-Tail Recursive or Non Tail-Recursive?
The tail-recursive functions are considered better than non-tail recursive functions as tail-recursion can be optimized by the compiler.
The idea used by compilers to optimize tail-recursive functions is simple, since the recursive call is the last statement, there is nothing left to do in the current function, so saving the current function’s stack frame is of no use.
