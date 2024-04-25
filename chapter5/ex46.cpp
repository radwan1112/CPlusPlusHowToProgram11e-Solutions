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

int ask_question()
{
    int num1{random_int(1, 10)};
    int num2{random_int(1, 10)};
    int answer{};
    std::cout << "How much is " << num1 << " times " << num2 << " ? ";
    std::cin >> answer;
    std::cin.ignore();
    if (answer != num1 * num2)
    {
        switch (random_int(1, 4))
        {
        case 1:
            std::cout << "No. Wrong answer." << '\n';
            break;
        case 2:
            std::cout << "Wrong!" << '\n';
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
        return 0;
    }
    else
    {
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
        return 1;
    }
}

void begin_exam()
{
    std::cout << "Multiplication Performance Test" << '\n';
    int no_of_questions{10};
    int correct{};
    for (int i = 0; i < no_of_questions; i++)
    {
        correct += ask_question();
    }
    double percentage{(static_cast<double>(correct) / 10.0) * 100.0};
    std::cout << "Your final grade " << percentage << "%" << '\n';
    if (percentage < 75)
    {
        std::cout << "Please ask your teacher for extra help." << '\n';
    }
    else
    {
        std::cout << "Congratulations, you are ready to go to the next level!" << '\n';
    }
}

int main()
{
    while (true)
    {
        begin_exam();
        std::cout << "\nPress Enter to continue or ctrl + c to exit..." << '\n';
        std::cin.ignore();
    }
    return 0;
}