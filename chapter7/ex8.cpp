#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include <ctime>

// Global declaration
std::random_device rd; // Random device to seed the engine
std::mt19937 engine(rd());

int randomNumberGenerator(int x1, int x2)
{
    std::uniform_int_distribution<int> distribution(x1, x2);
    return distribution(engine);
}

void moveHare(int *pos)
{
    int move{randomNumberGenerator(1, 10)};

    if (move >= 1 && move <= 3)
    {
        *pos += 1; // Small hop
    }
    else if (move >= 4 && move <= 5)
    {
        // Sleep
    }
    else if (move >= 6 && move <= 7)
    {
        *pos += 9; // Big hop
    }
    else if (move >= 8 && move <= 9)
    {
        *pos -= 2; // Small slip;
    }
    else
    {
        *pos -= 12; // Big slip
    }
    if (*pos < 0)
    {
        *pos = 0;
    }
    if (*pos > 69)
    {
        *pos = 69;
    }
}

void moveTortoise(int *pos)
{
    int move{randomNumberGenerator(1, 10)};
    if (move >= 1 && move <= 5)
    {
        *pos += 3;
    }
    else if (move >= 6 && move <= 7)
    {
        *pos -= 6;
    }
    else
    {
        *pos += 1;
    }
    if (*pos < 0)
    {
        *pos = 0;
    }
    if (*pos > 69)
    {
        *pos = 69;
    }
}

void dispalyTrack(const std::array<std::string, 70> &track)
{
    for (const std::string &square : track)
    {
        std::cout << square;
    }
    std::cout << std::endl;
}

void updateTrack(std::array<std::string, 70> &track, int harePos, int torPos)
{
    track.fill("_");
    if (harePos == torPos && harePos != 0)
    {
        track[harePos] = "OUCH!!!";
    }
    else if (harePos == 0 && torPos == 0)
    {
        track[harePos] = "S";
    }
    else
    {
        track[harePos] = "H";
        track[torPos] = "T";
    }
}

void startRace()
{
    std::array<std::string, 70> track;
    track.fill("_");
    int harePos{0};
    int tortoisePos{0};
    std::cout << "BANG!!!!!\nAND THEY'RE OFF!!!!!\n"
              << std::endl;
    updateTrack(track, harePos, tortoisePos);
    dispalyTrack(track);
    while (harePos < 69 && tortoisePos < 69)
    {
        moveHare(&harePos);
        moveTortoise(&tortoisePos);
        updateTrack(track, harePos, tortoisePos);
        dispalyTrack(track);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    if (harePos == 69)
    {
        std::cout << "Hare wins. Yuch." << '\n';
    }
    else if (harePos == tortoisePos)
    {
        std::cout << "It's a tie." << '\n';
    }
    else
    {
        std::cout << "Tortoise wins!!! YAY!!!" << '\n';
    }
    std::cout << "Hare Current position: " << harePos << '\n';
    std::cout << "Tortoise Current position: " << tortoisePos << '\n';
}

int main()
{
    startRace();
    return 0;
}