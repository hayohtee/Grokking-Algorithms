#include <iostream>
#include <vector>

// Returns the sum of the elements of the
// vector using divide and conquer.
int sum(std::vector<int> arr);

int main()
{
    std::vector<int> arr = {2, 4, 6};

    std::cout << "The sum of elements in the vector is: " << sum(arr)
              << std::endl;

    return 0;
}

int sum(std::vector<int> arr)
{
    if (arr.empty())
        return 0;
    
    int firstElement = arr[0];
    arr.erase(arr.begin()); // remove the first element

    return (firstElement + sum(arr));
}