#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

typedef std::vector<std::string> listOfPeople;

bool isSeller(const std::string &person);

bool breadthFirstSearch(std::queue<std::string> &searchQueue,
                        std::map<std::string, listOfPeople> &graph);

void addNamesToQueue(std::queue<std::string> &searchQueue,
                     listOfPeople &peopleList);

int main()
{
    // graph implementation
    std::map<std::string, listOfPeople> graph;
    graph["you"] = {"alice", "bob", "claire"};
    graph["bob"] = {"anuj", "peggy"};
    graph["alice"] = {"peggy"};
    graph["claire"] = {"thom", "jonny"};
    graph["anuj"] = {};
    graph["peggy"] = {};
    graph["thom"] = {};
    graph["johhy"] = {};

    std::queue<std::string> searchQueue;

    // add a neighbors to the search queue
    addNamesToQueue(searchQueue, graph["you"]);

    bool found = breadthFirstSearch(searchQueue, graph);

    if (!found)
    {
        std::cout << "No mango seller found\n";
    }

    return 0;
}

bool isSeller(const std::string &person)
{
    // true if person's name ends with 'm'
    return (*std::prev(person.end()) == 'm');
}

void addNamesToQueue(std::queue<std::string> &searchQueue,
                     listOfPeople &peopleList)
{
    for (auto people : peopleList)
        searchQueue.push(people);
}

bool breadthFirstSearch(std::queue<std::string> &searchQueue,
                        std::map<std::string, listOfPeople> &graph)
{
    listOfPeople searched;

    while (!searchQueue.empty())
    {
        std::string person = searchQueue.front();
        searchQueue.pop();

        // check if person is not present in the list of searched person
        if (std::find(searched.begin(), searched.end(), person) == searched.end())
        {
            if (isSeller(person))
            {
                std::cout << person << " is the seller\n";
                return true;
            }
            else
            {
                addNamesToQueue(searchQueue, graph[person]);
                searched.push_back(person);
            }
        }
    }

    return false;
}
