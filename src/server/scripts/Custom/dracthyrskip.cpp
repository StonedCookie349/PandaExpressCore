#include "Player.h"
#include "ObjectMgr.h"
#include "Map.h"
#include "Item.h"
#include "Spell.h"
#include "WorldSession.h"

class DrakThyrTeleportScript : public PlayerScript
{
public:
    DrakThyrTeleportScript() : PlayerScript("DrakThyrTeleportScript") {}

    void OnCreate(Player* player) override
    {
        if (player->GetRaceMask() == RACE_DRACTHYR_ALLIANCE || player->GetRaceMask() == RACE_DRACTHYR_HORDE)
        {
            if (player->GetTeam() == ALLIANCE || player->GetTeam() == HORDE)
            {
                // Teleport Drak'Thyr player to their faction's capital city
                if (player->GetTeam() == ALLIANCE)
                {
                    // Teleport to Alliance capital city (e.g., Stormwind City)
                    player->TeleportTo(0, -8839.24f, 626.68f, 94.09f, 0.0f);
                }
                else if (player->GetTeam() == HORDE)
                {
                    // Teleport to Horde capital city (e.g., Orgrimmar)
                    player->TeleportTo(1, 1637.35f, -4377.28f, 17.37f, 0.0f);
                }

                GiveItemsToPlayer(player, 1234, 5); // Give 5 of item ID 1234
                GiveItemsToPlayer(player, 5678, 10); // Give 10 of item ID 5678

                LevelUpPlayer(player, 60); // Level up player to level 60

                GiveSpellsToPlayer(player); // Give additional spells to player
            }
        }
    }

    void GiveItemsToPlayer(Player* player, uint32 itemId, uint32 itemCount)
    {
        for (uint32 i = 0; i < itemCount; ++i)
        {
            player->AddItem(193481, 1); // emblazoned ruby staff
            player->AddItem(194422, 1); // crimson dracthyr's drape
            player->AddItem(193914, 1); // crystalline lapis
            player->AddItem(191807, 1); // crimson dracthyr battlegear helm
            player->AddItem(191810, 1); // crimson dracthyr battlegear belt
            player->AddItem(196435, 1); // scytherins barbed necklace
            player->AddItem(191806, 1); // crimson dracthyr battlegear grips
            player->AddItem(194109, 1); // verdant dracthyrs band
            player->AddItem(191812, 1); // crimson dracthyr battlegear treads
            player->AddItem(191811, 1); // crimson dracthyr battlegear
            player->AddItem(194333, 1); // ekrazathals colored fang
            player->AddItem(191808, 1); // crimson dracthyr battlegear leggings
            player->AddItem(194335, 1); // emerald tear necklace
            player->AddItem(191809, 1); // crimson dracthyr battlegear minnion
            player->AddItem(193916, 1); // dragonkin signet ring
        }
    }

    void LevelUpPlayer(Player* player, uint32 level)
    {
        if (player->GetLevel() < level)
        {
            player->GiveLevel(level - player->GetLevel());
        }
    }

    void GiveSpellsToPlayer(Player* player)
    {
        player->LearnSpell(356995, false); // Disintegrate
        player->LearnSpell(357208, false); // Fire Breath
        player->LearnSpell(369536, false); // Soar
        player->LearnSpell(355913, false); // Emerald Blossom
        player->LearnSpell(367909, false); // Hover
        player->LearnSpell(367980, false); // Deep Breath
        player->LearnSpell(372014, false); // Visage
        player->LearnSpell(360022, false); // Chosen Identity
    }
};

void AddDrakThyrTeleportScripts()
{
    new DrakThyrTeleportScript();
}

void AddSC_DrakThyrTeleportScripts()
{
    AddDrakThyrTeleportScripts();
}
