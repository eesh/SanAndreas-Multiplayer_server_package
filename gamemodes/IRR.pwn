#include <a_samp>
#include <GetVehicleColor>

#undef MAX_PLAYERS
#define MAX_PLAYERS 32
#define SQL_HOST "localhost"
#define SQL_USER "root"
#define SQL_PASSWORD ""
#define SQL_DB "IRR"
#define MAX_CPS 1000 //defines the maximum number of dynamic Checkpoints the server can hold.
#define MAX_ORGS 12 //defines the maximum organizations on the server.

/*
	Jobs:
	1-refueller
	2-mechanic
	3-taxi
	4-trash
*/

forward OnPlayerEnterVeh(playerid, vehicleid, seatid);

#include <vars>
#include <zcmd>
#include <sscanf>
#include <streamer>
#include <zones>
#include <a_mysql>
#include <colours>
#include <functions>
#include <commands>
#include <timers>

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
	SetTimer("fuellower",20000,true);
	LSclass=AddPlayerClass(188,1309.3624,-1468.3801,10.0469,267.9800,0,0,0,0,0,0); // LSclass
	SFclass=AddPlayerClass(23,-2419.0215,334.2801,35.1787,242.4099,0,0,0,0,0,0); // SFclass
	LVclass=AddPlayerClass(188,2363.2034,2379.1602,10.8203,91.6707,0,0,0,0,0,0); // LVclass
	ServerInit();
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	spawned[playerid] = 0;
	if(newbie[playerid] != 1) return 1;
	if(classid == LSclass)
	{
	    SetPlayerTime(playerid,5,30);
	    SetPlayerWeather(playerid, 2);
		SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
		SetPlayerCameraPos(playerid,2007.055,-1146.613,193.264);
		SetPlayerCameraLookAt(playerid,1961.049,-1161.452,180.622, CAMERA_MOVE);
		TextDrawSetString(deathcon, "Los Santos");
		TextDrawShowForPlayer(playerid, deathcon);
		SetPVarInt(playerid, "class", LSclass);
	}
	if(classid == SFclass)
	{
	    SetPlayerTime(playerid, 5, 30);
        SetPlayerWeather(playerid, 2);
	    SetPlayerCameraPos(playerid,-2226.421,676.515,234.722);
		SetPlayerCameraLookAt(playerid,-2172.755,646.338,214.668, CAMERA_MOVE);
		TextDrawSetString(deathcon, "San Fierro");
		TextDrawShowForPlayer(playerid, deathcon);
		SetPVarInt(playerid, "class", SFclass);
	}
	if(classid == LVclass)
	{
	    SetPlayerWeather(playerid, 5);
	    SetPlayerTime(playerid, 22, 00);
	    SetPlayerCameraPos(playerid,2055.252,1702.848,62.263);
		SetPlayerCameraLookAt(playerid,2055.086,1680.421,57.650, CAMERA_MOVE);
		TextDrawSetString(deathcon, "Las Venturas");
		TextDrawShowForPlayer(playerid, deathcon);
		SetPVarInt(playerid, "class", LVclass);
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
	SetPVarInt(playerid,"crefuel",-1);
    SetPlayerCameraPos(playerid,737.286,-1436.615,39.343);
	SetPlayerCameraLookAt(playerid,737.133,-1533.071,29.210, CAMERA_MOVE);
	SetPlayerTime(playerid,5,45);
	SetPlayerWeather(playerid, 6);
	if(AccountExists(playerid) == 1) ShowLogin(playerid);
	else ShowRegister(playerid);
	createtextdraws(playerid);
	format(String,128,"%s has joined the server.",getname(playerid));
	TextDrawSetString(deathcon, String);
	TextDrawShowForAll(deathcon);
	SetTimer("deathconn",3000,false);
	SetPlayerColor(playerid,0xFFFFFF00);
	spawned[playerid] =1;
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
	if(vip[playerid]!=0)
	{
		DestroyVehicle(vipcar[playerid]);
	}
	resetvars(playerid);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	spawned[playerid] = 1;
	TextDrawHideForPlayer(playerid, deathcon);
    showtextdraws(playerid);
    if(vip[playerid]) CheckVIP(playerid);
    SetPlayerSkin(playerid, pSkin[playerid]);
    if(newbie[playerid])
    {
        new classid=GetPVarInt(playerid,"class");
    	new r=random(1);
	    if(classid == LSclass)
	    {
	        SetPlayerPos(playerid,lspos[r][0],lspos[r][1],lspos[r][2]);
	        SetPlayerFacingAngle(playerid, lspos[r][3]);
	    }
	    if(classid == SFclass)
	    {
	        SetPlayerPos(playerid,sfpos[r][0],sfpos[r][1],sfpos[r][2]);
	        SetPlayerFacingAngle(playerid, sfpos[r][3]);
	    }
	    if(classid == LVclass)
	    {
	        SetPlayerPos(playerid,lvpos[r][0],lvpos[r][1],lvpos[r][2]);
	        SetPlayerFacingAngle(playerid, lvpos[r][3]);
	    }
    }
	if(hspawn[playerid] == 0)
	{
	    SetPlayerPos(playerid, pX[playerid], pY[playerid], pZ[playerid]);
	    SetPlayerFacingAngle(playerid, pAngle[playerid]);
	    TogglePlayerClock(playerid, true);
	    SetPlayerTime(playerid,chour,cmins);
	}
	else
	{
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
    	if(hspawn[playerid] == 1) { SetPlayerPos(playerid,1178.9723,-1323.2080,14.1464); SetPlayerFacingAngle(playerid, 169.4691); }
    	if(hspawn[playerid] == 2) { SetPlayerPos(playerid,1580.3074,1765.0140,10.8203); SetPlayerFacingAngle(playerid, 90.0850); }
    	if(hspawn[playerid] == 3) { SetPlayerPos(playerid,-2660.2834,627.9525,14.4531); SetPlayerFacingAngle(playerid, 180.5627); }
    	hspawn[playerid] = 0;
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	spawned[playerid] = 0;
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
	if(!Logged[playerid]) { scm(playerid,red,"You must be logged in before you can message anybody."); return 0; }
	if(incall[playerid]!=0)
 	{
	    for(new i=0;i<MAX_PLAYERS;i++)
     	{
	        if(incall[i]==phno[playerid])
			{
			    mcredit[playerid] -= 0.25;
			    if(mcredit[playerid] < 1) return scm(playerid,0xFF0000FF,"You are low on credit. Please recharge your credit."),cmd_hangup(playerid,"");
				format(String,128,"[Phone] %s: %s",getname(playerid),text);
		        SendClientMessage(i,SWAT_COLOR,String);
		        SendClientMessage(playerid,0xE1E4AAFF,String);
	        }
   		}
	    return 0;
    }
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
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
        OnPlayerEnterVeh(playerid,GetPlayerVehicleID(playerid),GetPlayerVehicleSeat(playerid));
    }
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
	new Menu:smenu=GetPlayerMenu(playerid);
	if(smenu == storemenu[0])
	{
	    if(row == 0)
	    {
	        if(GetPlayerCash(playerid) < 100) return ShowMessage(playerid, "Insufficient cash", "You cannot afford to buy a sim card at the moment.");
	        if(phno[playerid] != 0) return ShowMessage(playerid, "Mobile Phone", "You already have a mobile phone.\nPlease use /mynumber if you forgot your number.");
			new number=random(899999)+100000;
			phno[playerid] = number;
			format(String,128,"Your new number is %d.\nUse /phonehelp for a list of commands.",phno[playerid]);
			ShowMessage(playerid,"Mobile information:", String);
			setpintdata(playerid, "users", "phno", number);
			GivePlayerCash(playerid, -100);
	    }
	    if(row == 1)
	    {
            if(GetPlayerCash(playerid) < 1200) return ShowMessage(playerid, "Insufficient cash", "You cannot afford to buy a mobile phone at the moment.");
            ShowMenuForPlayer(storemenu[1], playerid);
	    }
	    if(row == 2)
	    {
			ShowMenuForPlayer(storemenu[2], playerid);
	    }
	    if(row == 3)
	    {
	        ShowMenuForPlayer(storemenu[3], playerid);
	    }
	    if(row == 4)
	    {
	        if(GetPlayerCash(playerid) < 200) return ShowMessage(playerid, "Insufficient cash", "You cannot afford to buy a pack of Royal Cigars.");
	        if(getintdata(playerid,"users","cigs") > 10) return ShowMessage(playerid, "Royal Cigars", "You already have more than 2 packs of cigars.");
	        setpintdata(playerid, "users", "cigs", getintdata(playerid, "users", "cigs")+5);
	        GivePlayerCash(playerid, -200);
	        ShowMessage(playerid, "Royal Cigars", "You have bought a pack of Royal Cigars containing 5 cigars.");
	    }
	    if(row == 5)
	    {
	        if(getintdata(playerid, "users", "wallet")) return ShowMessage(playerid, "Wallet", "You already have a wallet with you.");
	        if(GetPlayerCash(playerid) < 1000) return ShowMessage(playerid, "Insufficient cash", "You cannot afford to buy a wallet.");
	        setpintdata(playerid, "users", "wallet", 1);
	        GivePlayerCash(playerid, -1000);
	        ShowMessage(playerid, "Wallet", "You have purchased a wallet for $1000.");
	    }
	}
	if(smenu == storemenu[1])
	{
	    if(row == 9) return ShowMenuForPlayer(storemenu[0], playerid);
	    if(getintdata(playerid,"users","mobileid") == 18865+row) return ShowMessage(playerid,"Mobile Phone","You are using that model.");
		setpintdata(playerid,"users","mobileid", 18865+row);
		GivePlayerCash(playerid, -1200);
		ShowMessage(playerid,"Mobile Phone","You have bought a new mobile.");
	}
	if(smenu == storemenu[2])
	{
	    if(row == 3) return ShowMenuForPlayer(storemenu[0], playerid);
		if(row == 0)
		{
		    if(GetPlayerCash(playerid) < 10) return ShowMessage(playerid, "Insufficient cash", "You cannot afford this pack");
		    setpfltdata(playerid, "users", "mcredit", getfltdata(playerid, "users", "mcredit")+10);
		    format(String,128,"You just purchased a $10 credit pack.\nYour current mobile credit is $%d.",getfltdata(playerid, "users", "mcredit"));
		    ShowMessage(playerid, "Mobile credit", String);
		    GivePlayerCash(playerid, -10);
		}
		if(row == 1)
		{
		    if(GetPlayerCash(playerid) < 50) return ShowMessage(playerid, "Insufficient cash", "You cannot afford this pack");
		    setpfltdata(playerid, "users", "mcredit", getfltdata(playerid, "users", "mcredit")+50);
		    format(String,128,"You just purchased a $50 credit pack.\nYour current mobile credit is $%d.",getfltdata(playerid, "users", "mcredit"));
		    ShowMessage(playerid, "Mobile credit", String);
		    GivePlayerCash(playerid, -50);
		}
		if(row == 2)
		{
		    if(GetPlayerCash(playerid) < 200) return ShowMessage(playerid, "Insufficient cash", "You cannot afford this pack");
		    setpfltdata(playerid, "users", "mcredit", getfltdata(playerid, "users", "mcredit")+200);
		    format(String,128,"You just purchased a $200 credit pack.\nYour current mobile credit is $%d.",getfltdata(playerid, "users", "mcredit"));
		    ShowMessage(playerid, "Mobile credit", String);
		    GivePlayerCash(playerid, -200);
		}
	}
	if(smenu == storemenu[3])
	{
	    if(row == 3) return ShowMenuForPlayer(storemenu[0], playerid);
	    if(row == 0)
	    {
			if(GetPlayerCash(playerid) < 300) return ShowMessage(playerid, "Insufficient cash", "You cannot afford to buy this bundle.");
			if(getintdata(playerid, "users", "snacks") > 200) return ShowMessage(playerid, "Snacks Bundle", "You already have more than 200HP worth of snacks.");
			GivePlayerCash(playerid, -300);
			setpintdata(playerid, "users", "snacks", getintdata(playerid, "users", "snacks")+30);
			ShowMessage(playerid, "Snacks Bundle", "You have purchased a 30HP snacks bundle.");
	    }
	    if(row == 1)
	    {
			if(GetPlayerCash(playerid) < 500) return ShowMessage(playerid, "Insufficient cash", "You cannot afford to buy this bundle.");
			if(getintdata(playerid, "users", "snacks") > 200) return ShowMessage(playerid, "Snacks Bundle", "You already have more than 200HP worth of snacks.");
			GivePlayerCash(playerid, -500);
			setpintdata(playerid, "users", "snacks", getintdata(playerid, "users", "snacks")+50);
			ShowMessage(playerid, "Snacks Bundle", "You have purchased a 50HP snacks bundle.");
	    }
	    if(row == 2)
	    {
			if(GetPlayerCash(playerid) < 1000) return ShowMessage(playerid, "Insufficient cash", "You cannot afford to buy this bundle.");
			if(getintdata(playerid, "users", "snacks") > 200) return ShowMessage(playerid, "Snacks Bundle", "You already have more than 200HP worth of snacks.");
			GivePlayerCash(playerid, -1000);
			setpintdata(playerid, "users", "snacks", getintdata(playerid, "users", "snacks")+100);
			ShowMessage(playerid, "Snacks Bundle", "You have purchased a 100HP snacks bundle.");
	    }
	}
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	new Menu:smenu=GetPlayerMenu(playerid);
	if(smenu == storemenu[1] || smenu == storemenu[2] || smenu == storemenu[3]) ShowMenuForPlayer(storemenu[0], playerid);
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
    if(oldinteriorid == 0 && newinteriorid == 3 && dteststatus == playerid)
	{
	    if(coneshit)
	    {
	        dteststatus= -1;
	        GameTextForPlayer(playerid,"You have ~r~failed.",4000,5);
	        dlic[playerid] = 0;
	    }
	    else
	    {
	        dteststatus= -1;
	        GameTextForPlayer(playerid,"You have ~g~passed.",4000,5);
	        scm(playerid,0xFFCC00FF,"You have earned your license.");
	        dlic[playerid] = 1;
	        setpintdata(playerid,"users","dlic",1);
	    }
	}
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
	    case 3:
	    {
	        if(!response) return 1;
	        if(!dlic[playerid]) return scm(playerid,red,"Sorry you don't meet the requirements for the job.");
	        job[playerid] = 1;
	        setpintdata(playerid,"users","job",1);
	        ShowPlayerDialog(playerid, 999, DIALOG_STYLE_MSGBOX, "Job Application:","Congratulations! Your application for the job has been\naccepted and you're now officially a refueller.","Ok","");
	    }
	    case 4:
	    {
	        if(!response) return 1;
            if(!dlic[playerid]) return scm(playerid,red,"Sorry you don't meet the requirements for the job.");
            job[playerid] = 2;
            setpintdata(playerid,"users","job",2);
	        ShowPlayerDialog(playerid, 999, DIALOG_STYLE_MSGBOX, "Job Application:","Congratulations! Your application for the job has been\naccepted and you're now officially a mechanic.","Ok","");
	    }
		case 5:
	    {
	        if(!response) return 1;
            if(!dlic[playerid]) return scm(playerid,red,"Sorry you don't meet the requirements for the job.");
            job[playerid] = 3;
            setpintdata(playerid,"users","job",3);
	        ShowPlayerDialog(playerid, 999, DIALOG_STYLE_MSGBOX, "Job Application:","Congratulations! Your application for the job has been\naccepted and you're now officially a taxi driver.","Ok","");
	    }
	    case 6:
	    {
	        if(!response) return 1;
            if(!dlic[playerid]) return scm(playerid,red,"Sorry you don't meet the requirements for the job.");
            job[playerid] = 4;
            setpintdata(playerid,"users","job",4);
	        ShowPlayerDialog(playerid, 999, DIALOG_STYLE_MSGBOX, "Job Application:","Congratulations! Your application for the job has been\naccepted and you're now officially a trash collector.","Ok","");
	    }
	    case 7:
	    {
	        if(response)
		    {
		        switch(listitem)
				{
		        	case 0:
					{
					    if(dlic[playerid] == 1) return scm(playerid,COLOR_ORANGE,"You already have a license.");
					    if(dteststatus != -1 && dteststatus != playerid) return scm(playerid,-1,"Someone is taking a driving test. Please wait while he/she completes his/her session.");
					    GivePlayerCash(playerid,-5000);
					    scm(playerid,0xFFFF00FF,"You have been charged $5000 for your driving test. Good luck.");
	                    stalled[dscar]=0;
	                    fuel[dscar]=100;
	                    CreateDCones(playerid);
	                    SetVehicleToRespawn(dscar);
	                    SetPlayerPos(playerid,-2029.7200,-123.0914,35.1993);
	                    SetPlayerFacingAngle(playerid,180.0000);
	                    SetCameraBehindPlayer(playerid);
	                    SetVehicleParamsForPlayer(dscar,playerid,1,0);
						scm(playerid,0xFF0000FF,"Sit in the parked car and drive through the checkpoints.");
						scm(playerid,0xFF0000FF,"You will fail the test if you hit any of the cones.");
						SetPlayerInterior(playerid,0);
						SetTimerEx("dtimertest",4*60000,0,"d",playerid);
					}
				}
			}
		}
		case 8:
		{
		    if(!response) return 1;
		}
		case 9:
		{
		    if(!response) return 1;
		    if(phno[playerid] == 0) return ShowMessage(playerid, "Phone Number Required", "Please purchase a mobile before applying for an account\nso we can contact you via mobile.");
		    ShowPlayerDialog(playerid, 10, DIALOG_STYLE_INPUT, "Please fill in your details (1/5):", "Please enter your complete name:\nExample: John Wimbleton","Next", "Quit");
		}
		case 10:
		{
		    if(!response) return ShowPlayerDialog(playerid, 10, DIALOG_STYLE_INPUT, "Please fill in your details (1/5):", "Please enter your complete name:\nExample: John Wimbleton","Next", "Quit");
			if(strlen(inputtext) > 32 && strlen(inputtext) < 8) return ShowMessage(playerid, "Name required", "Please enter your complete name (8 - 32 characters):");
			ShowPlayerDialog(playerid, 11, DIALOG_STYLE_MSGBOX, "Please fill in your details (2/5)", "Pick your Gender:", "Male", "Female");
		}
		case 11:
		{
		    if(!response) SetPVarInt(playerid,"bgender", 2);
		    else SetPVarInt(playerid,"bgender", 1);
		    ShowPlayerDialog(playerid, 12, DIALOG_STYLE_INPUT, "Please fill in your details (3/5)", "How much do you earn per day?", "Next", "Back");
		}
		case 12:
		{
		    if(!response) return ShowPlayerDialog(playerid, 12, DIALOG_STYLE_INPUT, "Please fill in your details (3/5)", "How much do you earn per day?", "Next", "Back");
			if(strval(inputtext) > 500000) return ShowMessage(playerid, "Salary","Please enter your salary.");
			ShowPlayerDialog(playerid, 13, DIALOG_STYLE_INPUT, "Please fill in your details (4/5)", "Enter your Mobile Number:", "Next", "Back");
		}
		case 13:
		{
		    if(!response) return ShowPlayerDialog(playerid, 13, DIALOG_STYLE_INPUT, "Please fill in your details (4/5)", "Enter your Mobile Number:", "Next", "Back");
			if(phno[playerid] != strval(inputtext)) return ShowMessage(playerid,"Phone Number:","You entered an invalid phone number.");
			ShowPlayerDialog(playerid, 14, DIALOG_STYLE_INPUT, "Please fill in your details (5/5)", "Enter your desired ATM pin number(4 digit):", "Next", "Back");
		}
		case 14:
		{
		    if(!response) return ShowPlayerDialog(playerid, 14, DIALOG_STYLE_INPUT, "Please fill in your details (5/5)", "Enter your desired ATM pin number(4 digit):", "Next", "Back");
			if(strval(inputtext) <= 999 && strval(inputtext) > 9999) return ShowMessage(playerid, "Invalid number", "Please enter a valid pin code number");
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

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
    new panels, tires;
    GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    bonnet = doors & 0x7;
    if(bonnet == 3)
    {
		if(stalled[vehicleid] != 1 && IsCar(GetVehicleModel(vehicleid)) == 1)
		{
			SetVehicleVelocity(vehicleid,0,0,0);
			GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(vehicleid,VEHICLE_PARAMS_OFF,lights,alarm,doors,bonnet,boot,objective);
			scm(playerid,red,"This vehicles engine broke down. Please call a mechanic(525).");
			stalled[vehicleid]=1;
			new Float:h;
	        GetPlayerHealth(playerid,h);
			SetPlayerHealth(playerid,h-20);
/*			if(strlen(owner[vehicleid]) != 0)
			{
			    format(String,128,"UPDATE vehs SET fuel=%d,stalled=1 WHERE Name='%s'",fuel[vehicleid],owner[vehicleid]);
			    mysql_query(String);
			}*/
		}
	}
	if(dteststatus != -1 && vehicleid == dscar)
	{
	    coneshit++;
	}
    return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == dcp)
	{
	    if(dlic[playerid] == 1) return scm(playerid,COLOR_ORANGE,"You already have a driving license");
    	ShowPlayerDialog(playerid, 7, DIALOG_STYLE_LIST, "Welcome to driving school,", "Take Driving Test.", "ok","cancel");
	}
	if(fjcp == checkpointid)
	{
		ShowPlayerDialog(playerid,3,DIALOG_STYLE_MSGBOX,"Refueller","You may know that the gas stations also contain fuel.\nAs the fuel decreases whenever someone refuels,\nit is your job to refuel them. All you have to do \nis drive the fuel truck to the station and /fillstation.\n\n Do you want to work as a refueller?\
		\nRequirements:\n-Drivers Licence","Yes","No");
	}
	if(checkpointid == mjcp)
  	{
  	    ShowPlayerDialog(playerid,4,DIALOG_STYLE_MSGBOX,"Mechanic:","There are many cars around SA that breakdown\nwhen they hit something. They can only\nbe fixed by a mechanic using /fix.\nYou can fix upto 5 cars every 5mins by towing them here.\n\nDo you want to work as a mechanic?\
		  \nRequirements:\nDrivers License","Ok","Cancel");
  	}
  	if(checkpointid == tjcp)
  	{
  	    ShowPlayerDialog(playerid,5,DIALOG_STYLE_MSGBOX,"Taxi Driver:","There are many people around SA waiting for a taxi.\nWhen they call the taxi hotline(555)\nAll the taxi drivers will\nbe alerted about the cutormers location.\nThey can pay use using /paytaxi.\n\nDo you want to work as a Taxi driver?\
	    \nRequirements:\n-Drivers License\n-University Certificate will 25+ scoring","Ok","Cancel");
  	}
  	if(checkpointid == trshcp)
  	{
  	    ShowPlayerDialog(playerid,6,DIALOG_STYLE_MSGBOX,"Trash Collector:","Theres too much trash on the roads just\nwaiting to be picked up by\ntrashcollectors. If this trash\nis not cleaned, the total pollution rises and players spawn\nwith less health.\n\nDo you want to work as a trash collector?\
		  \nRequirements:\n-Drivers License","Ok","Cancel");
  	}
	if(checkpointid == mgcp)
  	{
  	    if(IsPlayerInAnyVehicle(playerid))
  	    {
  	        if(job[playerid] == 2)
  	        {
				jsal[playerid]+=50;
				stalled[GetPlayerVehicleID(playerid)] = 0;
				scm(playerid,red,"You have earned 50$ from the repair work.");
				RepairVehicle(GetPlayerVehicleID(playerid));
  	        }
  	    }
 	}
 	if(checkpointid==benter[0])
	{
	    SetPlayerPos(playerid, 2307.3640,-15.9177,26.7496);
		scm(playerid,red,"Welcome to the bank. Please walk into the checkpoints to proceed.");
		SetPVarInt(playerid,"bank",1);
	}
	if(checkpointid==benter[1])
	{
	    SetPlayerPos(playerid, 2307.3640,-15.9177,26.7496);
		scm(playerid,red,"Welcome to the bank. Please walk into the checkpoints to proceed.");
		SetPVarInt(playerid,"bank",2);
	}
	if(checkpointid==benter[2])
	{
	    SetPlayerPos(playerid, 2307.3640,-15.9177,26.7496);
		scm(playerid,red,"Welcome to the bank. Please walk into the checkpoints to proceed.");
		SetPVarInt(playerid,"bank",3);
	}
	if(checkpointid==bexit[0] || checkpointid == bexit[1])
	{
	    new bank=GetPVarInt(playerid,"bank");
	    if(bank == 1) return SetPlayerPos(playerid,1774.9896,-1666.3738,14.4282);
		if(bank == 2) return SetPlayerPos(playerid,2474.5425,1021.1511,10.8203);
        if(bank == 3) return SetPlayerPos(playerid,-2237.2200,251.7929,35.3262);
	}
	if(checkpointid == bmenu[0] || checkpointid == bmenu[1] || checkpointid == bmenu[2])
	{
	    ShowPlayerDialog(playerid, 8, DIALOG_STYLE_LIST, "Hello! What can we do for you?", "Bank Information\nGeneral Banking", "Select", "Leave");
	}
	if(checkpointid == bform)
	{
	    ShowPlayerDialog(playerid, 9, DIALOG_STYLE_MSGBOX, "Bank Application Form:", "In order to create an account here you need to fill out an\napplication form first. Would you like to fill it out?","Fill Form","Leave");
	}
	if(checkpointid == store[0] || checkpointid == store[1] || checkpointid == store[2])
	{
	    ShowMenuForPlayer(storemenu[0], playerid);
	}
	return 1;
}

public OnPlayerLeaveDynamicCP(playerid, checkpointid)
{
	return 1;
}


public OnPlayerEnterDynamicRaceCP(playerid, checkpointid)
{
    if(checkpointid == playerdcp)
	{
	    drivingtcp++;
	    DestroyDynamicRaceCP(checkpointid);
	    OnPlayerEnterDCP(playerid, drivingtcp);
	}
	return 1;
}

public OnPlayerLeaveDynamicRaceCP(playerid, checkpointid)
{
	return 1;
}

public OnPlayerEnterVeh(playerid, vehicleid, seatid)
{
    GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
    if(IsBike(GetVehicleModel(vehicleid))) { SetVehicleParamsEx(vehicleid,1,lights,alarm,doors,bonnet,boot,objective); }
	if(vehicleid == dscar)
	{
	    if(dteststatus != playerid) return RemovePlayerFromVehicle(playerid);
	    ShowPlayerDialog(playerid,999,DIALOG_STYLE_MSGBOX,"Driving Test","Drive through the track without hitting the cones.\n\nTurn on the engine using {FFCC00}/engine","Ok","");
	    drivingtcp = 1;
	    new Float:p[3],Float:q[3];
	    GetDCPcoords(drivingtcp,p[0],p[1],p[2]);
	    GetDCPcoords(drivingtcp+1,q[0],q[1],q[2]);
	    playerdcp=CreateDynamicRaceCP(0,p[0],p[1],p[2],q[0],q[1],q[2],4,0,0,playerid,100);
	}
	if(vorg[vehicleid] != 0)
 	{
		if(vorg[vehicleid] != org[playerid])
	    {
	    	if(seatid == 0)
	    	{
	    		if(admin[playerid] < 3)
	    		{
	    			RemovePlayerFromVehicle(playerid);
	    			format(String,128,"You have to be in %s to be able use this vehicle.",orgdata[vorg[vehicleid]][oname]);
	    			SendClientMessage(playerid, red, String);
   				}
	    		else
	    		{
	    			SendClientMessage(playerid,COLOR_ORANGE,"**You have been granted access to the org vehicle.");
	    		}
	    	}
	    }
  	}
	if(IsJobVeh(vehicleid) != 0 && seatid == 0)
	{
	    new jveh=IsJobVeh(vehicleid);
	    if(job[playerid] != jveh)
	    {
     		RemovePlayerFromVehicle(playerid);
	        switch(jveh)
	        {
	            case 1:SendClientMessage(playerid,red,"You have to work as a Refueller to use this vehicle.");
	            case 2:SendClientMessage(playerid,red,"You have to work as a Mechanic to use this vehicle.");
	            case 3:SendClientMessage(playerid,red,"You have to work as a Taxi Driver to use this vehicle.");
	            case 4:SendClientMessage(playerid,red,"You have to work as a Trash Collector to use this vehicle.");
	        }
	    }
	    else
		{
		    switch(jveh)
	        {
	            case 1:SendClientMessage(playerid,COLOR_GREEN,"Goto Gas Stations and /fillstation to fuel them.");
	            case 2:SendClientMessage(playerid,COLOR_GREEN,"/fix broken cars and drive them to mechanic garage to fix them.");
	            case 3:SendClientMessage(playerid,COLOR_GREEN,"Once you drop passengers, let them /paytaxi you.");
	            case 4:SendClientMessage(playerid,COLOR_GREEN,"/starttrash to start collecting trash.");
	        }
		}
	}
	return 1;
}
