#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Common.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SharedDefines.h"
#include "World.h"
#include "WorldSession.h"
#include "Item.h"

class WorgenPaladinScript : public PlayerScript
{
public:
    WorgenPaladinScript() : PlayerScript("WorgenPaladinScript") {}

    void OnCreate(Player* player)
    {
        if (player->GetRaceMask() == RACE_WORGEN && player->GetClassMask() == CLASS_PALADIN)
        {
            // Customize the player's initial stats and abilities for a Worgen Paladin
            player->SetPowerType(POWER_MANA);
            player->SetPower(POWER_MANA, 100);
            player->SetMaxHealth(100);
            player->SetHealth(100);

            // Learn spells or abilities specific to a Worgen Paladin
            player->LearnSpell(20271, false, false);  // Judgment
            player->LearnSpell(20185, false, false);  // Judgment of Light
            player->LearnSpell(19740, false, false);  // Blessing of Might
            player->LearnSpell(20187, false, false);  // Seal of Righteousness
            player->LearnSpell(465, false, false);    // Devotion Aura
            player->LearnSpell(53489, false, false);  // The Art of War

            // Add starting items for a Worgen Paladin (Paladin starting armor set)
            player->AddItem(187726, 1);   // Paladin's Girdle
            player->AddItem(187722, 1);   // Paladin's Chestplate
            player->AddItem(187724, 1);   // Paladin's Gauntlets
            player->AddItem(187727, 1);   // Paladin's Sabatons
            player->AddItem(187723, 1);   // Paladin's Greaves
            player->AddItem(57155, 1);   // Worgen Slaying Sword


            // You can add more customizations or logic here if needed
        }
    }
};

    void AddSC_WorgenPaladinScript()
    {
        new WorgenPaladinScript();
    }
