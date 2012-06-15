#include <a_samp>

#undef MAX_PLAYERS
#define MAX_PLAYERS 32
#define SQL_HOST "localhost"
#define SQL_USER "root"
#define SQL_PASSWORD ""
#define SQL_DB "IRR"

new Logged[MAX_PLAYERS];
new String[128];
new pSkin[MAX_PLAYERS];
new Float:pX[MAX_PLAYERS];
new Float:pY[MAX_PLAYERS];
new Float:pZ[MAX_PLAYERS];
new Float:pAngle[MAX_PLAYERS];
new hspawn[MAX_PLAYERS];
new LSarea;
new LVarea;
new SFarea;
new PlayerText:loctd;
new PlayerText:mphtd;
new PlayerText:fueltd;
new PlayerText:sl1;
new PlayerText:sl2;
new PlayerText:sl3;
new PlayerText:sl4;
new PlayerText:sl5;
new chour;
new cmins;
new Text:deathcon;

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
	if(connect_mysql()) print("Connected to MYSQL Database.");
	SendRconCommand("loadfs camera");
	SetTimer("savetimer",3500,true);
	SetTimer("speedo",120,true);
	SetTimer("clock",1000,true);
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);
	ServerInit();
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
	SetPlayerWeather(playerid, 6);
	if(AccountExists(playerid) == 1) ShowLogin(playerid);
	else ShowRegister(playerid);
	createtextdraws(playerid);
	format(String,128,"%s has joined the server.",getname(playerid));
	TextDrawSetString(deathcon, String);
	TextDrawShowForAll(deathcon);
	SetTimer("deathconn",3000,false);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	Logged[playerid] = 0;
	destroytextdraws(playerid);
	format(String,128,"%s has left the server.",getname(playerid));
	TextDrawSetString(deathcon, String);
	TextDrawShowForAll(deathcon);
	SetTimer("deathconn",3000,false);
	return 1;
}

public OnPlayerSpawn(playerid)
{
    showtextdraws(playerid);
	if(hspawn[playerid] == 0)
	{
	    SetPlayerPos(playerid, pX[playerid], pY[playerid], pZ[playerid]);
	    SetPlayerFacingAngle(playerid, pAngle[playerid]);
	    SetPlayerSkin(playerid, pSkin[playerid]);
	    TogglePlayerClock(playerid, true);
	}
	else
	{
		cmd_debug(playerid, "");
    	if(hspawn[playerid] == 1) { SetPlayerPos(playerid,1178.9723,-1323.2080,14.1464); SetPlayerFacingAngle(playerid, 169.4691); }
    	if(hspawn[playerid] == 2) { SetPlayerPos(playerid,1580.3074,1765.0140,10.8203); SetPlayerFacingAngle(playerid, 90.0850); }
    	if(hspawn[playerid] == 3) { SetPlayerPos(playerid,-2660.2834,627.9525,14.4531); SetPlayerFacingAngle(playerid, 180.5627); }
    	hspawn[playerid] = 0;
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	hidetextdraws(playerid);
    if(IsPlayerInDynamicArea(playerid, LSarea)) hspawn[playerid] = 1;
   	if(IsPlayerInDynamicArea(playerid, LVarea)) hspawn[playerid] = 2;
   	if(IsPlayerInDynamicArea(playerid, SFarea)) hspawn[playerid] = 3;
	new
		msg[128],
		killerName[MAX_PLAYER_NAME],
		reasonMsg[32],
		playerName[MAX_PLAYER_NAME];
	GetPlayerName(killerid, killerName, sizeof(killerName));
	GetPlayerName(playerid, playerName, sizeof(playerName));
	if (killerid != INVALID_PLAYER_ID)
	{
		switch (reason)
		{
			case 0:
			{
				reasonMsg = "Unarmed";
			}
			case 1:
			{
				reasonMsg = "Brass Knuckles";
			}
			case 2:
			{
				reasonMsg = "Golf Club";
			}
			case 3:
			{
				reasonMsg = "Night Stick";
			}
			case 4:
			{
				reasonMsg = "Knife";
			}
			case 5:
			{
				reasonMsg = "Baseball Bat";
			}
			case 6:
			{
				reasonMsg = "Shovel";
			}
			case 7:
			{
				reasonMsg = "Pool Cue";
			}
			case 8:
			{
				reasonMsg = "Katana";
			}
			case 9:
			{
				reasonMsg = "Chainsaw";
			}
			case 10:
			{
				reasonMsg = "Dildo";
			}
			case 11:
			{
				reasonMsg = "Dildo";
			}
			case 12:
			{
				reasonMsg = "Vibrator";
			}
			case 13:
			{
				reasonMsg = "Vibrator";
			}
			case 14:
			{
				reasonMsg = "Flowers";
			}
			case 15:
			{
				reasonMsg = "Cane";
			}
			case 16,18:
			{
			    format(String,128,"INSERT INTO ban (Name,reason) VALUES ('%s','wpn hax')",getname(killerid));
	    		mysql_query(String);
	    		Ban(killerid);
			}
			case 22:
			{
				reasonMsg = "Pistol";
			}
			case 23:
			{
				reasonMsg = "Silenced Pistol";
			}
			case 24:
			{
				reasonMsg = "Desert Eagle";
			}
			case 25:
			{
				reasonMsg = "Shotgun";
			}
			case 26:
			{
				reasonMsg = "Sawn-off Shotgun";
			}
			case 27:
			{
				reasonMsg = "Combat Shotgun";
			}
			case 28:
			{
				reasonMsg = "MAC-10";
			}
			case 29:
			{
				reasonMsg = "MP5";
			}
			case 30:
			{
				reasonMsg = "AK-47";
			}
			case 31:
			{
				if (GetPlayerState(killerid) == PLAYER_STATE_DRIVER)
				{
					switch (GetVehicleModel(GetPlayerVehicleID(killerid)))
					{
						case 447:
						{
							reasonMsg = "Sea Sparrow Machine Gun";
						}
						default:
						{
							reasonMsg = "M4";
						}
					}
				}
				else
				{
					reasonMsg = "M4";
				}
			}
			case 32:
			{
				reasonMsg = "TEC-9";
			}
			case 33:
			{
				reasonMsg = "Rifle";
			}
			case 34:
			{
				reasonMsg = "Sniper Rifle";
			}
			case 35,36:
			{
			    format(String,128,"INSERT INTO ban (Name,reason) VALUES ('%s','wpn hax')",getname(killerid));
	    		mysql_query(String);
	    		Ban(killerid);
			}
			case 38:
			{
				if (GetPlayerState(killerid) == PLAYER_STATE_DRIVER)
				{
					switch (GetVehicleModel(GetPlayerVehicleID(killerid)))
					{
						case 425:
						{
							reasonMsg = "Hunter Machine Gun";
						}
						default:
						{
							reasonMsg = "Minigun";
						}
					}
				}
				else
				{
					reasonMsg = "Minigun";
					format(String,128,"INSERT INTO ban (Name,reason) VALUES ('%s','wpn hax')",getname(killerid));
	    			mysql_query(String);
	    			Ban(killerid);
				}
			}
			case 39:
			{
					format(String,128,"INSERT INTO ban (Name,reason) VALUES ('%s','wpn hax')",getname(killerid));
	    			mysql_query(String);
	    			Ban(killerid);
			}
			case 41:
			{
				reasonMsg = "Spraycan";
			}
			case 42:
			{
				reasonMsg = "Fire Extinguisher";
			}
			case 49:
			{
    			reasonMsg = "Vehicle";
			}
			case 50:
			{
				if (GetPlayerState(killerid) == PLAYER_STATE_DRIVER)
				{
					switch (GetVehicleModel(GetPlayerVehicleID(killerid)))
					{
						case 417, 425, 447, 465, 469, 487, 488, 497, 501, 548, 563:
						{
							reasonMsg = "Helicopter Blades";
						}
						default:
						{
							reasonMsg = "Vehicle";
						}
					}
				}
				else
				{
					reasonMsg = "Vehicle";
				}
			}
			case 51:
			{
				if (GetPlayerState(killerid) == PLAYER_STATE_DRIVER)
				{
					switch (GetVehicleModel(GetPlayerVehicleID(killerid)))
					{
						case 425:
						{
							reasonMsg = "Hunter Rockets";
						}
						case 432:
						{
							reasonMsg = "Rhino Turret";
						}
						case 520:
						{
							reasonMsg = "Hydra Rockets";
						}
						default:
						{
							reasonMsg = "Explosion";
						}
					}
				}
				else
				{
					reasonMsg = "Explosion";
				}
			}
			default:
			{
				reasonMsg = "";
			}
		}
		format(msg, sizeof(msg), "%s was killed by %s with a %s.", playerName, killerName, reasonMsg);
	}
	else
	{
		switch (reason)
		{
			case 53:
			{
				format(msg, sizeof(msg), "%s drowned in water.", playerName);
			}
			case 54:
			{
				format(msg, sizeof(msg), "%s fell off a height.", playerName);
			}
			default:
			{
				format(msg, sizeof(msg), "%s died.", playerName);
			}
		}
	}
	TextDrawSetString(deathcon, msg);
	TextDrawShowForAll(deathcon);
	SetTimer("deathconn",3000,false);
	SendDeathMessage(killerid,playerid,reason);
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
	if(!Logged[playerid]) { scm(playerid,red,"You mussed be logged in before you can message anybody."); return 0; }
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
	hidetextdraws(playerid);
	showtextdraws(playerid);
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
	if(Logged[playerid] != 2) return scm(playerid,red,"You must be logged in before you can spawn.");
	Logged[playerid] = 1;
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
	SetPlayerPos(playerid, fX, fY,fZ+5);
	return 1;
}

public OnPlayerCommandReceived(playerid, cmdtext[])
{
	if(!Logged[playerid]) return scm(playerid,red,"You must be logged in before you can use any command."),0;
	if(GetPlayerState(playerid) == PLAYER_STATE_WASTED) return scm(playerid,red,"You cannot use any commands when your dead."),0;
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

//Player Commands

CMD:debug(playerid,params[])
{
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerInterior(playerid, 0);
	return 1;
}

// timers
forward savetimer();
public savetimer()
{
	for(new i=0;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i) && GetPlayerState(i) != PLAYER_STATE_WASTED)
	    {
	        SavePlayer(i);
	        AreaCheck(i);
	    }
	}
	return 1;
}

forward speedo();
public speedo()
{
    for(new i=0;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i) && GetPlayerState(i) == PLAYER_STATE_DRIVER)
	    {
	        Speedo(i);
	    }
	}
	return 1;
}

forward clock();
public clock()
{
	cmins++;
	if(cmins == 60) chour++;
	if(chour == 34) chour = 0;
	SetWorldTime(chour);
	for(new i;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i) && Logged[i] == 1) SetPlayerTime(i, chour, cmins);
	}
	return 1;
}

forward deathcontd();
public deathcontd()
{
	TextDrawHideForAll(deathcon);
	return 1;
}
//get camera coords and interpolate on spawn to make the spawn effect look cooler. make sure to save it on logging off though.
