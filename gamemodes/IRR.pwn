#include <a_samp>

#undef MAX_PLAYERS
#define MAX_PLAYERS 32
#define SQL_HOST "localhost"
#define SQL_USER "root"
#define SQL_PASSWORD ""
#define SQL_DB "IRR"

new Logged[MAX_PLAYERS];
new String[128];

#include <zcmd>
#include <sscanf>
#include <streamer>
#include <zones>
#include <a_mysql>
#include <colours>
#include <functions>

main()
{
	print("\n----------------------------------");
	print(" Ideal Roleplay\n\t\t-The Resurrection");
	print("----------------------------------\n");
}

public OnGameModeInit()
{
	SetGameModeText("Resurrection v0.0.1");
	mysql_debug(1);
	if(connect_mysql()) print("Connected to MYSQL Database.");
	SendRconCommand("loadfs camera");
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid,737.286,-1436.615,39.343);
	SetPlayerCameraLookAt(playerid,737.133,-1533.071,29.210, CAMERA_CUT);
	SetPlayerTime(playerid,5,30);
	spawn_camera(playerid);
	return 1;
}

public OnPlayerConnect(playerid)
{
    SetPlayerCameraPos(playerid,737.286,-1436.615,39.343);
	SetPlayerCameraLookAt(playerid,737.133,-1533.071,29.210, CAMERA_MOVE);
	SetPlayerTime(playerid,5,30);
	print("test");
	if(AccountExists(playerid) == 1) ShowLogin(playerid),print("test");
	else ShowRegister(playerid),print("test");
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case 1:
	    {
	        if(!response) return Kick(playerid);
	        new pass[32];
	        mysql_real_escape_string(inputtext, pass);
	        if(strlen(pass) < 5 && strlen(pass) > 32) return scm(playerid, COLOR_RED, "Password should contain atleast 5 characters and max. 32 characters.");
	        LoginPlayer(playerid, pass);
	    }
	    case 2:
	    {
	        if(!response) return Kick(playerid);
	        new pass[32];
	        mysql_real_escape_string(inputtext, pass);
	        if(strlen(pass) < 5 && strlen(pass) > 32) return scm(playerid, COLOR_RED, "Password should contain atleast 5 characters and max. 32 characters.");
	        RegisterPlayer(playerid, pass);
	    }
	}
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	SetPlayerPosFindZ(playerid, fX, fY, fZ);
	return 1;
}

//Admin Commands

CMD:setweather(playerid,params[])
{
	new weatherid;
	if(sscanf(params,"i",weatherid)) return scm(playerid,-1,"/setweather [weatherid]");
	SetWeather(weatherid);
	return 1;
}

CMD:setpweather(playerid,params[])
{
	new weatherid,player;
	if(sscanf(params,"ui",player,weatherid)) return scm(playerid,-1,"/setplayerweather [playerid] [weatherid]");
	SetPlayerWeather(player, weatherid);
	return 1;
}

CMD:settime(playerid, params[])
{
	new hours,mins;
	if(sscanf(params,"ii",hours,mins)) return scm(playerid,-1,"/settime [hours] [minutes]");
	for(new i;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i)) SetPlayerTime(i, hours, mins);
	}
	return 1;
}

CMD:setplayertime(playerid, params[])
{
	new hours,mins,player;
	if(sscanf(params,"uii",player,hours,mins)) return scm(playerid,-1,"/settime [playerid] [hours] [minutes]");
 	if(IsPlayerConnected(player)) SetPlayerTime(player, hours, mins);
 	    else scm(playerid, 0xFF0000FF, "That player is offline.");
	return 1;
}
