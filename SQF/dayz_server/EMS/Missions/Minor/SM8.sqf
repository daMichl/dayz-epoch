/*
	Bandit Party by lazyink (Full credit for code to TheSzerdi & TAW_Tonic)
	Updated to new format by Vampire
	Edited by Fuchs for EMS
*/
private ["_missName","_coords","_crash","_tent","_crate"];

//Name of the Mission
_missName = "Bandit Party";

//DZMSFindPos loops BIS_fnc_findSafePos until it gets a valid result
_coords = call DZMSFindPos;

[nil,nil,rTitleText,"A bandit party has taken up a vantage point, check your map for the location!", "PLAIN",10] call RE;

//DZMSAddMinMarker is a simple script that adds a marker to the location
[_coords,_missName] ExecVM DZMSAddMinMarker;

//Add scenery
_crash = createVehicle ["UralWreck",_coords,[], 0, "CAN_COLLIDE"];

//DZMSProtectObj prevents it from disappearing
[_crash] call DZMSProtectObj;

//DZMSAISpawn spawns AI to the mission.
//Usage: [_coords, count, skillLevel]
[_coords,5,1] ExecVM DZMSAISpawn;
sleep 1;

_crate = createVehicle ["USLaunchersBox",[(_coords select 0) + 3, _coords select 1,0],[], 0, "CAN_COLLIDE"];
[_crate,"weap"] ExecVM DZMSBoxSetup;
[_crate] call DZMSProtectObj;

//This function is !! Not tested !!
/*
_tent = createVehicle ["TentStorage",_coords select 1,[], 0, "NONE"];
_tent call DZMSProtectObj;
sleep 1;

_tent addWeaponCargoGlobal   ["ItemCompass", 2];
_tent addWeaponCargoGlobal   ["ItemGPS", 3];
_tent addWeaponCargoGlobal   ["NVGoggles", 1];
_tent addMagazineCargoGlobal ["FoodCanBakedBeans", 4];
_tent addMagazineCargoGlobal ["ItemBandage", 4];
_tent addMagazineCargoGlobal ["ItemMorphine", 4];
_tent addMagazineCargoGlobal ["ItemPainkiller", 4];
_tent addMagazineCargoGlobal ["ItemAntibiotic", 2];
_tent addWeaponCargoGlobal   ["ItemKnife", 2];
_tent addWeaponCargoGlobal   ["ItemToolbox", 2];
_tent addWeaponCargoGlobal   ["ItemMatches", 2];
_tent addMagazineCargoGlobal ["ItemBloodbag", 2];
_tent addMagazineCargoGlobal ["ItemJerryCan", 2];
_tent addMagazineCargoGlobal ["MP5A5", 2];
_tent addMagazineCargoGlobal ["30Rnd_9x19_MP5", 5];
_tent addMagazineCargoGlobal ["glock17_EP1", 2];
_tent addMagazineCargoGlobal ["17Rnd_9x19_glock17", 4];
*/
//Wait until the player is within 30meters
waitUntil{{isPlayer _x && _x distance _coords <= 30 } count playableunits > 0}; 

//Let everyone know the mission is over
[nil,nil,rTitleText,"Survivors have annihilated the bandit party and secured the vantage point!", "PLAIN",6] call RE;
diag_log format["[DZMS]: Minor SM8 Bandit Party Mission has Ended."];
deleteMarker "DZMSMinMarker";
deleteMarker "DZMSMinDot";

//Let the timer know the mission is over
DZMSMinDone = true;