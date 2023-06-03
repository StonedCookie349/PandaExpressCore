#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include "Item.h"
#include "SpellInfo.h"
#include "Inventory.h"

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
            AddStartingItem(player, 187726, 1);   // Paladin's Girdle
            AddStartingItem(player, 187722, 1);   // Paladin's Chestplate
            AddStartingItem(player, 187724, 1);   // Paladin's Gauntlets
            AddStartingItem(player, 187727, 1);   // Paladin's Sabatons
            AddStartingItem(player, 187723, 1);   // Paladin's Greaves
            AddStartingItem(player, 57155, 1);   // Worgen Slaying Sword


            // You can add more customizations or logic here if needed
        }
    }

private:
    static void AddStartingItem(Player* player, uint32 itemId, uint32 count);
};

void WorgenPaladinScript::AddStartingItem(Player* player, uint32 itemId, uint32 count)
{
        player->AddItem(itemId, count);
};

void AddSC_WorgenPaladinScript()
{
    new WorgenPaladinScript();
}

void AddCustomScripts()
{
    AddSC_WorgenPaladinScript();
}
