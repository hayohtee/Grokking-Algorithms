#include <iostream>
#include <vector>

template <class T>
int binary_search(std::vector<T> list, T item)
{
    int low = 0;
    int high = list.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        T guess = list[mid];
        
        if (guess == item)
            return mid;     // item found, return index
        
        if (guess < item)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;   // item not in the list
}

int main()
{
    std::vector<int> list = {1, 3, 5, 7, 9};

    std::cout << binary_search(list, 3) << std::endl;
    std::cout << binary_search(list, -1) << std::endl;

    return 0;
}