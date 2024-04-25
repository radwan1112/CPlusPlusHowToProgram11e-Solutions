#include <iostream>
#include <random>

int random_int()
{
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    static std::uniform_int_distribution randomInt{1, 10};
    const int num{randomInt(engine)};
    return num;
}

void ask_question()
{
    int num1{random_int()};
    int num2{random_int()};
    int answer{};
    std::cout << "How much is " << num1 << " times " << num2 << " ? ";
    std::cin >> answer;
    while (answer != num1 * num2)
    {
        std::cout << "No, Please try again." << '\n';
        std::cin >> answer;
    }
    std::cout << "Very good!" << '\n';
}

int main()
{
    int no_of_questions{10};

    for (int i = 0; i < no_of_questions; i++)
    {
        ask_question();
    }

    return 0;
}