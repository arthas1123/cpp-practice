#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>

int main()
{
    std::string options[3] = {"Rock", "Paper", "Scissors"};
    std::srand(std::time(nullptr)); // Initialize random seed
    int random_number = std::rand() % 3;
    std::string computer = options[random_number];

    std::string playerInput;
    std::string player;
    std::cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors, or type the name): \n";
    std::cout << "1. Rock \n";
    std::cout << "2. Paper \n";
    std::cout << "3. Scissors \n";
    std::cin >> playerInput;

    // Check if the input is a number
    if (std::isdigit(playerInput[0]))
    {
        int choice = std::stoi(playerInput); // Convert string to integer
        if (choice >= 1 && choice <= 3)
        {
            player = options[choice - 1]; // Map 1 to Rock, 2 to Paper, 3 to Scissors
        }
        else
        {
            std::cout << "Invalid choice! Please enter a number between 1 and 3.\n";
            return 1;
        }
    }
    else
    {
        // Assume it's a string input for "Rock", "Paper", or "Scissors"
        player = playerInput;
    }

    std::cout << "You chose: " << player << "\n";
    std::cout << "The computer chose: " << computer << "\n";

    // Game logic
    if (player == computer)
    {
        std::cout << "Tie! \n";
    }
    else if (player == "Rock" && computer == "Paper" ||
             player == "Paper" && computer == "Scissors" ||
             player == "Scissors" && computer == "Rock")
    {
        std::cout << "You lose! \n";
    }
    else
    {
        std::cout << "You win! \n";
    }

    return 0;
}
