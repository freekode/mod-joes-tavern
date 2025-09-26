#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "../BMConfig.h"
#include "BMTeleportItemScript.h"

uint32 DIVINE_SPELL_ID = 642;
uint32 DIVINE_DURATION_MS = 60000;

bool ModBeerMaster_Teleport_ItemScript::OnUse(Player *player, Item *item, const SpellCastTargets &)
{
    if (!modBmEnabled)
        return false;

    GameTele const *teleportLocation = GetTeleportLocation();
    if (!teleportLocation)
    {
        LOG_ERROR("module", "[BeerMaster] no teleport location found");
        return false;
    }

    player->HandleEmoteCommand(EMOTE_ONESHOT_EAT);
    ChatHandler(player->GetSession()).PSendSysMessage("You are drinkin this strange beer...");

    GetDrunk(player, 10);

    BMSchedule(player, 5s,
             [player, this]
             { this->GetDrunk(player, 50); });
    BMSchedule(player, 10s,
             [player, this]
             { this->GetDrunk(player, 100); });

    BMSchedule(player, 15s,
             [player, teleportLocation, this]
             { this->Teleport(player, teleportLocation); });

    BMSchedule(player, 16s,
             [player, this]
             { this->AfterTeleport(player); });

    return false;
}

void ModBeerMaster_Teleport_ItemScript::GetDrunk(Player *player, uint8 value)
{
    if (!player->IsInWorld())
        return;

    player->SetDrunkValue(value);
}

void ModBeerMaster_Teleport_ItemScript::Teleport(Player *player, GameTele const *tele)
{
    if (!player->IsInWorld())
        return;

    player->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
}

void ModBeerMaster_Teleport_ItemScript::AfterTeleport(Player *player)
{
    if (!player->IsInWorld())
        return;

    player->SetDrunkValue(0);
    player->CastSpell(player, DIVINE_SPELL_ID, true);
    player->GetAura(DIVINE_SPELL_ID)->SetDuration(DIVINE_DURATION_MS);
}

GameTele const *ModBeerMaster_Teleport_ItemScript::GetTeleportLocation()
{
    QueryResult result = WorldDatabase.Query("SELECT name FROM game_tele ORDER BY RAND() LIMIT 1");
    Field *fields = result->Fetch();
    std::string teleportName = fields[0].Get<std::string>();

    GameTele const *tele = sObjectMgr->GetGameTele(teleportName);
    if (!tele)
        return nullptr;

    return tele;
}
