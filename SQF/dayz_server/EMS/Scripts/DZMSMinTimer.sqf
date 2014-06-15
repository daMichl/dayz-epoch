/*
	DayZ Mission System Timer by Vampire
	Based on fnc_hTime by TAW_Tonic and SMFinder by Craig
	This function is launched by the Init and runs continuously.
*/
private["_run","_timeDiff","_timeVar","_wait","_cntMis","_ranMis","_varName"];

//Let's get our time Min and Max
_timeDiff = DZMSMinorMax - DZMSMinorMin;
_timeVar = _timeDiff + DZMSMinorMin;

diag_log format ["[DZMS]: Minor Mission Clock Starting!"];

//Lets get the loop going
_run = true;
while {_run} do
{
	//Lets wait the random time
	_wait  = round(random _timeVar);
	sleep _wait;
	
	//Let's check that there are missions in the array.
	//If there are none, lets end the timer.
	_cntMis = count DZMSMinorArray;
	if (_cntMis == 0) then { _run = false; };
	
	//Lets pick a mission
	_ranMis = floor (random _cntMis);
	_varName = DZMSMinorArray select _ranMis;
	
	//Let's Run the Mission
	[] execVM format ["\z\addons\dayz_server\EMS\Missions\Minor\%1.sqf",_varName];
	diag_log format ["[DZMS]: Running Minor Mission %1.",_varName];
	
	//Let's wait for it to finish or timeout
	waitUntil {DZMSMinDone};
	DZMSMinDone = nil;
};