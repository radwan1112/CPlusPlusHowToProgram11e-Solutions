#include <iostream>
#include <random>
#include <cmath>

int random_int(int x1, int x2)
{
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    std::uniform_int_distribution randomInt{x1, x2};
    const int num{randomInt(engine)};
    return num;
}

int ask_question(int operation, int level)
{
    int x1{0};
    int x2{static_cast<int>(pow(10, level)) - 1};

    int num1{random_int(x1, x2)};
    int num2{random_int(x1, x2)};
    int answer{};
    int result{};

    if (operation == 5)
    {
        operation = random_int(1, 4);
    }

    switch (operation)
    {
    case 1:
        result = num1 + num2;
        std::cout << "How much is " << num1 << " + " << num2 << " ? ";
        break;
    case 2:
        result = num1 - num2;
        std::cout << "How much is " << num1 << " - " << num2 << " ? ";
        break;
    case 3:
        result = num1 * num2;
        std::cout << "How much is " << num1 << " * " << num2 << " ? ";
        break;
    case 4:
        if (num2 == 0)
        {
            num2 = 1;
        }
        result = num1 / num2;
        std::cout << "How much is " << num1 << " / " << num2 << " ? ";
        break;
    default:
        std::cout << "Error" << '\n';
        break;
    }

    std::cin >> answer;

    if (answer != result)
    {
        switch (random_int(1, 4))
        {
        case 1:
            std::cout << "Incorrect." << '\n';
            break;
        case 2:
            std::cout << "Wrong!." << '\n';
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

void start_test(int questions, int operation)
{
    int level{};
    std::cout << "Choose difficulty level (1-5): ";
    std::cin >> level;
    while (level < 1 || level > 5)
    {
        std::cout << "No such level!" << '\n';
        std::cout << "Choose difficulty level (1-5): ";
        std::cin >> level;
    }
    int i{};
    int correct{};
    while (i < questions)
    {
        correct += ask_question(operation, level);
        i++;
    }
    std::cout << "Correct: " << correct << '\n';
    std::cout << "Wrong: " << questions - correct << '\n';
    std::cout << "Score: " << (static_cast<double>(correct) / questions) * 100 << '\n';
}

int main()
{
    int no_of_questions{10};

    int option{};

    do
    {
        std::cout << "1. Addition problems." << '\n';
        std::cout << "2. Subtraction problems." << '\n';
        std::cout << "3. Multiplication problems." << '\n';
        std::cout << "4. Divison problems." << '\n';
        std::cout << "5. Random mixture." << '\n';
        std::cout << "6. Exit." << '\n';
        std::cout << "\nEnter option: ";

        std::cin >> option;

        switch (option)
        {
        case 1:
            start_test(no_of_questions, 1);
            break;
        case 2:
            start_test(no_of_questions, 2);
            break;
        case 3:
            start_test(no_of_questions, 3);
            break;
        case 4:
            start_test(no_of_questions, 4);
            break;
        case 5:
            start_test(no_of_questions, 5);
        default:
            option = 6;
            break;
        }
    } while (option != 6);

    return 0;
}