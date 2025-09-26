#include "BMWorldScript.h"
#include "BMPlayerScript.h"
#include "BMTeleportItemScript.h"
#include "BMTakeMeHomeItemScript.h"

void AddBeerMasterScripts()
{
    new ModBeerMaster_WorldScript();
    new ModBeerMaster_PlayerScript();
    new ModBeerMaster_Teleport_ItemScript();
    new ModBeerMaster_TakeMeHome_ItemScript();
}
