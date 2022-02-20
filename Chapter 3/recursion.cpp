#include <iostream>

int factorial(int n);

void countDown(int n);

int main()
{
    std::cout << "The factorial of 5 is " << factorial(5) 
              << std::endl;

    std::cout << "Counting down from 5: ";
    countDown(5);

    return 0;
}


int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return (n * factorial(n - 1));
}

void countDown(int n)
{
    std::cout << n << " ";
    
    if (n <= 0)
    {
        std::cout << std::endl;
        return;
    }
    else 
        countDown(n - 1);
}
