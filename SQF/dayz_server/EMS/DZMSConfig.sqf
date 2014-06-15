/*
	DayZ Mission System Config by Vampire
	DZMS: https://github.com/SMVampire/DZMS-DayZMissionSystem
*/

///////////////////////////////////////////////////////////////////////
// Do you want your players to gain humanity from killing mission AI?
DZMSMissHumanity = true;

// How Much Humanity?
DZMSCntHumanity = 100;

// Do you want AI kills to count as bandit kills?
DZMSCntBanditKls = false;

// Do you want AI that players run over to not have gear?
DZMSRunGear = false;

// How long before bodies disappear? (in seconds) (default = 2400)
DZMSBodyTime = 2400;

//////////////////////////////////////////////////////////////////////////////////////////
// You can adjust the weapons that spawn in weapon crates inside DZMSWeaponCrateList.sqf
// You can adjust the AI's gear inside DZMSAIConfig.sqf in the ExtConfig folder also.
//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Do you want vehicles from missions to save to the Database? (this means they will stay after a restart)
// If False, vehicles will disappear on restart. It will warn a player who gets inside of a vehicle.
// This is experimental, and off by default in this version.
DZMSSaveVehicles = false;

/*
There are two types of missions that run simultaneously on a the server.
The two types are Major and Minor missions.

Major missions have a higher AI count, but also have more crates to loot.
Minor missions have less AI than Major missions, but have crates that reflect that.

Below is the array of mission file names and the minimum and maximum times they run.
Do not edit the Arrays unless you know what you are doing.
*/
DZMSMajorArray = ["SM1","SM2","SM3","SM4","SM5","SM6","SM7","SM8","SM9","SM10","SM11","SM12","SM13"];
DZMSMinorArray = ["SM1","SM2","SM3","SM4","SM5","SM6","SM7","SM8","SM9","SM10","SM11","SM12","SM13"];

/////////////////////////////////////////////////////////////////////////////////////////////
// The Minumum time in seconds before a major mission will run.
// At least this much time will pass between major missions. Default = 960 (10.8 Minutes)
DZMSMajorMin = 960;

// Maximum time in seconds before a major mission will run.
// A major mission will always run before this much time has passed. Default = 2900 (33.33 Minutes)
DZMSMajorMax = 2900;

// Time in seconds before a minor mission will run.
// At least this much time will pass between minor missions. Default = 960 (10 Minutes)
DZMSMinorMin = 960;

// Maximum time in seconds before a minor mission will run.
// A minor mission will always run before this much time has passed. Default = 1730;(16.5 Minutes)
DZMSMinorMax = 1730;



/*=============================================================================================*/
// Do Not Edit Below This Line
/*=============================================================================================*/
DZMSVersion = "RC1.0";
DZMSConfigured = true;
