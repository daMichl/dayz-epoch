/*																					//
	Weapons Cache Mission by lazyink (Original Full Code by TheSzerdi & TAW_Tonic)
	New Mission Format by Vampire
	Edited by Fuchs for EMS
*/	

private ["_missName","_coords","_crate","_crash","_vehicle"];

//Name of the Mission
_missName = "Abandoned Platoon";

//DZMSFindPos loops BIS_fnc_findSafePos until it gets a valid result
_coords = call DZMSFindPos;

[nil,nil,rTitleText,"A general has fled and abandon his platoon and their resources, wipe them out quickly!", "PLAIN",10] call RE;

//DZMSAddminMarker is a simple script that adds a marker to the location
[_coords,_missName] ExecVM DZMSAddMinMarker;

_crate = createVehicle ["USLaunchersBox",_coords,[], 0, "CAN_COLLIDE"];

//Add the scenery
_crash = createVehicle ["uralwreck", _coords,[], 0, "CAN_COLLIDE"];
[_crash] call DZMSProtectObj;

_vehicle = createVehicle ["HMMWV_DZ",[(_coords select 0) + 25, (_coords select 1) - 5,0],[], 0, "CAN_COLLIDE"];
[_vehicle] call DZMSSetupVehicle;

//DZMSBoxFill fills the box, DZMSProtectObj prevents it from disappearing
[_crate,"weap"] ExecVM DZMSBoxSetup;
[_crate] call DZMSProtectObj;

//DZMSAISpawn spawns AI to the mission.
//Usage: [_coords, count, skillLevel]
[_coords,6,1] ExecVM DZMSAISpawn;
sleep 5;

//Wait until the player is within 30meters
waitUntil{ {isPlayer _x && _x distance _coords <= 30 } count playableunits > 0 }; 

//Let everyone know the mission is over
[nil,nil,rTitleText,"Survivors have obliterated the abandoned platoon, what a grim fate.", "PLAIN",6] call RE;
diag_log format["[DZMS]: Minor SM7 Weapon Cache Mission has Ended."];
deleteMarker "DZMSMinMarker";
deleteMarker "DZMSMinDot";

//Let the timer know the mission is over
DZMSMinDone = true;