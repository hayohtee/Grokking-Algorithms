#include <iostream>
#include <map>

// check if a person have already voted before:
// if their name is on the list print "kick them out"
// else print "let them vote"
void checkVoter(const std::string &name,
                std::map<std::string, bool> &voted);

int main()
{
    std::map<std::string, bool> voted;
    voted["Jim"] = true;
    voted["Pam"] = true;
    voted["Mike"] = true;

    checkVoter("Tom", voted);
    checkVoter("Mike", voted);
    checkVoter("Mike", voted);

    return 0;
}

void checkVoter(const std::string &name,
                std::map<std::string, bool> &voted)
{
    if (voted.find(name) != voted.end())
    {
        std::cout << "Kick them out!\n";
    }
    else
    {
        voted[name] = true;
        std::cout << "Let them vote!\n";
    }
}
