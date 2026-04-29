#include "search_engine.hpp"

int main()
{
    Engine myEngine;
    myEngine.print_info();

    /* Test 1: Suche nach "Coding"
    Query q1("Coding", 2);
    if (q1.is_valid()) {
        myEngine.search(q1);
    }*/

    std::string input;

    while (true) 
    { 
        std::cout << "Type your search term (or 'exit' to quit): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input);

        if (input == "exit") 
        {
            break;
        }
        std::cout << "Type your desired number of results: ";

        int temp = 0;
        bool valid_input = false;

        while (!valid_input)
        {
            if (!(std::cin >> temp))
            {
                std::cout << "Error: Input is not an integer. Try Again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (temp > MAX_RESULTS || temp < 0)
            {
                std::cout << "Error: Input is not in range. Try Again.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                valid_input = true;
            }
        }
        Query temp_query(input, temp);

        if (temp_query.is_valid()) 
        {
            myEngine.search(temp_query);
        }
        else
        {
            std::cout << "Error: Invalid Query." << std::endl;
        }
    }

    std::cout << "\nTotal Queries: " << Engine::get_total_queries() << std::endl;
    return 0;
}