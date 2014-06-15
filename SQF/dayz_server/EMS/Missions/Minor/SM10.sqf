/*
	Helicopter Crash by lazyink (Full credit for code to TheSzerdi & TAW_Tonic)
	Updated to new format by Vampire
	Edited by Fuchs for EMS
*/
private ["_missName","_coords","_vehicle","_crate","_crate1","_crate2"];

//Name of the Mission
_missName = "Heli Crash";

[nil,nil,rTitleText,"A Mi8 helicopter has crashed! Check your map for the location!", "PLAIN",10] call RE;

//DZMSFindPos loops BIS_fnc_findSafePos until it gets a valid result
_coords = call DZMSFindPos;

[_coords,_missName] ExecVM DZMSAddMinMarker;

//DZMSBoxFill fills the box, DZMSProtectObj prevents it from disappearing
_crate = createVehicle ["USLaunchersBox",[(_coords select 0) - 10, _coords select 1,0],[], 0, "CAN_COLLIDE"];
[_crate,"weap"] ExecVM DZMSBoxSetup;
[_crate] call DZMSProtectObj;


_vehicle = createVehicle ["Mi8Wreck",[(_coords select 0) + 10, (_coords select 1) - 5,0],[], 0, "CAN_COLLIDE"];
[_vehicle] call DZMSProtectObj;

[_coords,5,2] ExecVM DZMSAISpawn;
sleep 1;

//Wait until the player is within 30meters
waitUntil{{isPlayer _x && _x distance _coords <= 30  } count playableunits > 0}; 

//Call DZMSSaveVeh to attempt to save the vehicles to the database
//If saving is off, the script will exit.
[_vehicle] ExecVM DZMSSaveVeh;
[_vehicle1] ExecVM DZMSSaveVeh;

//Let everyone know the mission is over
[nil,nil,rTitleText,"Good work, Survivors secured the crash site!!", "PLAIN",6] call RE;
diag_log format["[DZMS]: Minor SM10 Heli Crash Mission has Ended."];
deleteMarker "DZMSMinMarker";
deleteMarker "DZMSMinDot";

//Let the timer know the mission is over
DZMSMinDone = true;