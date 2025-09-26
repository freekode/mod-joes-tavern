#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "BMWorldScript.h"
#include "BMConfig.h"

void ModBeerMaster_WorldScript::OnBeforeConfigLoad(bool /*reload*/)
{
    InitConfig();
}

void ModBeerMaster_WorldScript::InitConfig()
{
    modBmEnabled = sConfigMgr->GetOption<bool>("BeerMaster.Enable", true);
    modBmAnnounce = sConfigMgr->GetOption<bool>("BeerMaster.Announce", true);
}
