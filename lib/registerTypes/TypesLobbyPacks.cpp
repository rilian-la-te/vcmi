/*
 * TypesLobbyPacks.cpp, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#include "StdInc.h"
#include "RegisterTypes.h"

#include "../mapping/CMapInfo.h"
#include "../StartInfo.h"
#include "../gameState/CGameState.h"
#include "../gameState/CGameStateCampaign.h"
#include "../gameState/TavernHeroesPool.h"
#include "../mapping/CMap.h"
#include "../mapObjects/CObjectHandler.h"
#include "../CCreatureHandler.h"
#include "../VCMI_Lib.h"
#include "../CArtHandler.h"
#include "../CHeroHandler.h"
#include "../spells/CSpellHandler.h"
#include "../CTownHandler.h"
#include "../RoadHandler.h"
#include "../RiverHandler.h"
#include "../TerrainHandler.h"
#include "../campaign/CampaignState.h"
#include "../rmg/CMapGenOptions.h"

#include "../serializer/BinaryDeserializer.h"
#include "../serializer/BinarySerializer.h"
#include "../serializer/CTypeList.h"

VCMI_LIB_NAMESPACE_BEGIN

template void registerTypesLobbyPacks<BinaryDeserializer>(BinaryDeserializer & s);
template void registerTypesLobbyPacks<BinarySerializer>(BinarySerializer & s);
template void registerTypesLobbyPacks<CTypeList>(CTypeList & s);


VCMI_LIB_NAMESPACE_END
