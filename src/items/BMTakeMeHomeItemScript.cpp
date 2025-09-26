#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "../BMConfig.h"
#include "BMTakeMeHomeItemScript.h"

bool ModBeerMaster_TakeMeHome_ItemScript::OnUse(Player *player, Item *item, const SpellCastTargets &)
{
    if (!modBmEnabled)
        return false;

    player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
    BMSchedule(player, 1s,
               [player]
               {
                   player->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
                   player->TextEmote("I'm home!");
               });
    return false;
}
