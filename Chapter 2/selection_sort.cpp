#include <iostream>
#include <vector>

template <class T>
int findSmallest(const std::vector<T>& arr);

template <class T>
std::vector<T> selectionSort(std::vector<T>& arr);

template <class T>
void print(const std::vector<T>& arr);

int main()
{
    std::vector<int> arr = {1, 3, 2, 5, 4, 6, 7};

    std::cout << "Before sorting:\n";
    print(arr);

    std::vector<int> sortedArr = selectionSort(arr);
    std::cout << "After sorting:\n";
    print(sortedArr);

    return 0;
}


template <class T>
int findSmallest(const std::vector<T>& arr)
{
    T smallest = arr[0];
    size_t smallest_index = 0;

    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            smallest_index = i;
        }
    }

    return smallest_index;
}

template <class T>
std::vector<T> selectionSort(std::vector<T>& arr)
{
    std::vector<T> newArr;

    while (!arr.empty())
    {
        size_t smallest_index = findSmallest(arr);
        newArr.push_back(arr[smallest_index]);
        arr.erase(arr.begin() + smallest_index);
    }

    return newArr;
}

template <class T>
void print(const std::vector<T>& arr)
{
    std::cout << "[";

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i != arr.size() - 1)
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i];
    }

    std::cout << "]\n";
}
