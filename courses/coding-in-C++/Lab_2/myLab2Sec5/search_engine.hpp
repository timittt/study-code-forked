#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <iostream>
#include <string>
#include <vector>

constexpr int THRESHOLD_POPULARITY = 6;
constexpr int MAX_RESULTS = 10;

// --- KLASSE QUERY ---
class Query {
private:
    std::string prompt;
    int result_count;
public:
    Query(const std::string& p, const int c) 
        : prompt(p), result_count(c) {}

    // Validierung
    bool is_valid() const 
    {
        return !prompt.empty(); 
    }
    std::string get_prompt() const
    {
        return prompt; 
    }
    int get_result_count() const 
    {
        return result_count; 
    }
};

// --- KLASSE RESOURCE ---
class Resource {
private:
    std::string address;
    std::string content;
    int ranking;
public:
    Resource(const std::string& a, const std::string& c, const int r) : address(a), content(c), ranking(r) 
    {}
    bool is_popular() const
    {
        return ranking > THRESHOLD_POPULARITY;
    }
    std::string get_content() const 
    {
        return content;
    }
    std::string get_address() const
    {
        return address; 
    }
};

// --- KLASSE ENGINE ---
class Engine {
private:
    static int query_counter;
    std::vector<Resource> catalog;

public:
    Engine() {
        // Testdaten
        catalog.push_back(Resource("wiki.org", "Wikipedia is the world's largest online encyclopedia", 10));
        catalog.push_back(Resource("cpp-resources.com", "C++ resources library: useful help for programming", 6));
        catalog.push_back(Resource("wetter.de", "The weather is nice today, sunny, 22 degrees Celsius", 7));
        catalog.push_back(Resource("youtube.com", "Watch videos online for free", 9));
        catalog.push_back(Resource("braunagel.de", "Coding lernen. Study-Code - Von Informatikern fuer Informatiker", 2));
    }

    void search(const Query& q) 
    {
        query_counter++;
        int found_count = 0;
        std::string search_term = q.get_prompt();

        std::cout << "--- Search Results for: " << search_term << " ---" << std::endl;

        // Range based for loop
        for (const auto& res : catalog) {
            if (found_count >= q.get_result_count()) 
            {
                break;
            }

            if (res.get_content().find(search_term) != std::string::npos)
            {
                found_count++;
                std::cout << "Result No. " << found_count << std::endl;
                if (res.is_popular())
                {
                    std::cout << "Popular ";
                }
                std::cout << "Content by: " << res.get_address() << std::endl;
                std::cout << res.get_content() << std::endl << std::endl;
            }
        }
    }

    void print_info(void) const
    {
        std::cout << "This is a study-code search engine\nType your prompt and how many results you want to get\n";
    }

    static int get_total_queries()
    {
        return query_counter; 
    }
};

// Static member
int Engine::query_counter = 0;

#endif // !SEARCH_ENGINE_HPP
