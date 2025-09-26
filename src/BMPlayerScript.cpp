#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "BMConfig.h"
#include "BMPlayerScript.h"

void ModBeerMaster_PlayerScript::OnPlayerLogin(Player *player)
{
    if (modBmAnnounce && modBmEnabled)
    {
        ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Beer Master |rmodule.");
    }
}
