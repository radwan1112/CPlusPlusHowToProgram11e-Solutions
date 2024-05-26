#include <iostream>
#include <array>
#include <string>
#include <random>

int main()
{
    std::array<std::string, 10> articles = {"the", "a", "an", "some", "any", "one", "each", "every", "these", "those"};
    std::array<std::string, 10> nouns = {"cat", "dog", "bird", "car", "house", "tree", "boy", "girl", "apple", "book"};
    std::array<std::string, 10> verbs = {"runs", "jumps", "flies", "eats", "reads", "writes", "sings", "drives", "sleeps", "swims"};
    std::array<std::string, 10> prepositions = {"on", "over", "under", "beside", "with", "about", "against", "among", "around", "through"};

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(0, 9); // Uniform distribution between 10 and 100

    std::string sentence{};

    sentence += articles.at(dist(engine)) + " ";
    sentence += nouns.at(dist(engine)) + " ";
    sentence += verbs.at(dist(engine)) + " ";
    sentence += prepositions.at(dist(engine)) + " ";
    sentence += articles.at(dist(engine)) + " ";
    sentence += nouns.at(dist(engine)) + " ";

    std::cout << sentence << '\n';

    return 0;
}