/*
	CH47 Mission by lazyink (Full credit for original code to TheSzerdi & TAW_Tonic)
	Updated to New Mission Format by Vampire
	Edited by Fuchs for EMS
*/

private ["_missName","_coords","_vehicle"];

//Name of the Mission
_missName = "Bandit UH1H";

//DZMSFindPos loops BIS_fnc_findSafePos until it gets a valid result
_coords = call DZMSFindPos;

[nil,nil,rTitleText,"A bandit UH1H has landed! Secure its fire power for yourself!", "PLAIN",10] call RE;

//DZMSAddMajMarker is a simple script that adds markers
[_coords,_missname] ExecVM DZMSAddMajMarker;
//Create the vehicles

_vehicle = createVehicle ["UH1H_DZE",[(_coords select 0) + 10, (_coords select 1) - 10,0],[], 0, "CAN_COLLIDE"];
[_vehicle] call DZMSSetupVehicle;
	
//DZMSAISpawn spawns AI to the mission.
//Usage: [_coords, count, skillLevel]
[_coords,5,1] ExecVM DZMSAISpawn;
sleep 5;


//Wait until the player is within 30meters
waitUntil{{isPlayer _x && _x distance _coords <= 30  } count playableunits > 0};

//Call DZMSSaveVeh to attempt to save the vehicles to the database
//If saving is off, the script will exit.
[_vehicle] ExecVM DZMSSaveVeh;

//Let everyone know the mission is over
[nil,nil,rTitleText,"Survivors have secured the UH1H helicopter!", "PLAIN",6] call RE;
diag_log format["[DZMS]: Major SM10 UH1H Mission has Ended."];
deleteMarker "DZMSMajMarker";
deleteMarker "DZMSMajDot";

//Let the timer know the mission is over
DZMSMajDone = true;