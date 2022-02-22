#include <iostream>
#include <vector>

template <class T>
std::vector<T> quickSort(std::vector<T> arr);

template <class T>
void print(const std::vector<T>& arr);

int main()
{
    std::vector<int> arr = {3, 5, 2, 1, 4, 2, 7};
    
    std::cout << "Before sorted: \n";
    print(arr);

    std::cout << "Using quick sort: \n";
    print(quickSort(arr));

    return 0;
}

template <class T>
std::vector<T> quickSort(std::vector<T> arr)
{
    if (arr.size() < 2)
        return arr;

    // pivot points to an element somewhere in the middle.
    const T* pivot = &arr.front() + arr.size() / 2 - 1;
    std::vector<T> less;
    std::vector<T> greater;

    // iterate from the first element to the last element using pointer
    for (const T* item = &arr.front(); item <= &arr.back(); item++)
    {
        // skip pivot element
        if (item == pivot)
            continue;
        
        if (*item <= *pivot)
            less.push_back(*item);
        else
            greater.push_back(*item);
    }

    std::vector<T> sortedLess = quickSort(less);
    std::vector<T> sortedGreater = quickSort(greater);

    sortedLess.push_back(*pivot);
    sortedLess.insert(sortedLess.end(), sortedGreater.begin(),
                      sortedGreater.end());
    
    return sortedLess;
}


template <class T>
void print(const std::vector<T>& arr)
{
    std::cout << '[';
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i != arr.size() - 1)
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i] << "]\n";
    }
}