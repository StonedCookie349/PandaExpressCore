#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Player.h>
#include <World.h>

using namespace std;
using namespace bots;

// Function to generate a random integer within a given range
int getRandomInt(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned int>(time(nullptr)));
        initialized = true;
    }
    return min + rand() % ((max + 1) - min);
}

// Function to generate a random race
Race getRandomRace() {
    int raceIndex = getRandomInt(RACE_NONE + 1, RACE_DRAENEI - 1);
    return static_cast<Race>(raceIndex);
}

// Function to generate a random class
Class getRandomClass() {
    int classIndex = getRandomInt(CLASS_WARRIOR, CLASS_DEATH_KNIGHT);
    return static_cast<Class>(classIndex);
}

// Function to generate a random name
string getRandomName() {
    // Implement your name generation logic here based on WoW naming rules
    // For simplicity, let's use random letters for now
    string name;
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int nameLength = getRandomInt(4, 8); // Generate a name between 4 and 8 characters long

    for (int i = 0; i < nameLength; ++i) {
        name += alphabet[getRandomInt(0, 25)];
    }

    return name;
}

int main() {
    // Connect to the TrinityCore server
    sLog->outString("Connecting to TrinityCore server...");
    if (!sWorld->SetInitialWorldSettings()) {
        sLog->outError("Failed to initialize world settings.");
        return 1;
    }

    // Create and spawn persistent bots
    const int numBots = 10;  // Number of bots to spawn
    for (int i = 0; i < numBots; ++i) {
        // Generate random race, class, and name for the bot
        Race race = getRandomRace();
        Class playerClass = getRandomClass();
        string name = getRandomName();

        // Create the bot character
        Player* bot = sObjectMgr->CreatePlayer();
        if (!bot) {
            sLog->outError("Failed to create bot character.");
            return 1;
        }

        // Set the bot's race, class, and name
        bot->SetRace(race);
        bot->SetClass(playerClass);
        bot->SetName(name);

        // Spawn the bot in the world
        if (!bot->Create(sWorld->GetNextPlayerGuid())) {
            sLog->outError("Failed to spawn bot character.");
            return 1;
        }

        // Add the bot to the world
        if (!sWorld->AddPlayer(bot)) {
            sLog->outError("Failed to add bot character to the world.");
            return 1;
        }

        sLog->outString("Spawned bot: Race = " + sObjectMgr->GetRaceName(race) +
                        ", Class = " + sObjectMgr->GetClassName(playerClass) +
                        ", Name = " + name);
    }

    // Keep the program running to maintain the bots
    while (true) {
        // Additional logic or functionality can be added here if needed
    }

    return 0;
}
