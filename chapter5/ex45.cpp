#include <iostream>
#include <random>

int random_int(int x1, int x2)
{
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    std::uniform_int_distribution randomInt{x1, x2};
    const int num{randomInt(engine)};
    return num;
}

void ask_question()
{
    int num1{random_int(1, 10)};
    int num2{random_int(1, 10)};
    int answer{};
    std::cout << "How much is " << num1 << " times " << num2 << " ? ";
    std::cin >> answer;
    while (answer != num1 * num2)
    {
        switch (random_int(1, 4))
        {
        case 1:
            std::cout << "No. Please try again." << '\n';
            break;
        case 2:
            std::cout << "Wrong. Try once more." << '\n';
            break;
        case 3:
            std::cout << "Don't give up!." << '\n';
            break;
        case 4:
            std::cout << "No. Keep trying" << '\n';
            break;
        default:
            std::cout << "Logical error in the code!" << '\n';
            break;
        }
        std::cin >> answer;
    }

    switch (random_int(1, 4))
    {
    case 1:
        std::cout << "Very good!" << '\n';
        break;
    case 2:
        std::cout << "Excellent!" << '\n';
        break;
    case 3:
        std::cout << "Nice work!" << '\n';
        break;
    case 4:
        std::cout << "Keep up the good work!" << '\n';
        break;
    default:
        std::cout << "Logical error in the code!" << '\n';
        break;
    }
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