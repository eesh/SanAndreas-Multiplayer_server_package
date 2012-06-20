#if defined _commands_included
	#endinput
#endif
#define _commands_included

//Admin Commands

CMD:setweather(playerid,params[])
{
	if(admin[playerid] < 3) return 1;
	new weatherid;
	if(sscanf(params,"i",weatherid)) return scm(playerid,-1,"/setweather [weatherid]");
	SetWeather(weatherid);
	return 1;
}

CMD:setpweather(playerid,params[])
{
	if(admin[playerid] < 2) return 1;
	new weatherid,player;
	if(sscanf(params,"ui",player,weatherid)) return scm(playerid,-1,"/setplayerweather [playerid] [weatherid]");
	SetPlayerWeather(player, weatherid);
	return 1;
}

CMD:settime(playerid, params[])
{
	if(admin[playerid] < 3) return 1;
	new h,m;
	if(sscanf(params,"ii",h,m)) return scm(playerid,-1,"/settime [hours] [minutes]");
	if(h >= 24 && h <= -1) return scm(playerid,red,"Please set a time between 0 - 23 hours and 0 - 59 minutes only");
	if(m >= 59 && m <= -1) return scm(playerid,red,"Please set a time between 0 - 23 hours and 0 - 59 minutes only");
	chour=h,cmins=m;
	SetWorldTime(chour);
	format(String, 128,"Admin %s has set the world time to %d:%d",getname(playerid),chour,cmins);
	SendClientMessageToAll(admin_colour,String);
	return 1;
}

//Player Commands

CMD:debug(playerid,params[])
{
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerInterior(playerid, 0);
	return 1;
}

COMMAND:engine(playerid, params[])
{
    if(IsBike(GetVehicleModel(GetPlayerVehicleID(playerid)))) return scm(playerid,red,"Bicycles do not have an engine.");
    if(GetPlayerState(playerid) != 2) return scm(playerid,0xFF0000FF,"Your not the driver.");
    vid = GetPlayerVehicleID(playerid);
//    if(stalled[vid] == 1) return scm(playerid,0xFF0000FF,"This vehicles engine broke down. Please call a mechanic.");
    GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
//    if(fuel[vid] == 0) return scm(playerid,red,"There is no fuel in this vehicle."),SetVehicleParamsEx(vid,0,lights,alarm,doors,bonnet,boot,objective);
    if(engine != 1)
    {
//        setfuel(playerid,0);
 //       if(fuel[vid] <= 5 && fuel[vid] > 0) return scm(playerid,0xFF0000FF,"This vehicles fuel is low. Please call a mechanic or use a refuel can.");
   // 	if(fuel[vid] == 0) return scm(playerid,red,"There is no fuel in this vehicle."),SetVehicleParamsEx(vid,0,lights,alarm,doors,bonnet,boot,objective);
		SetTimerEx("startengine",3000,false,"d",playerid);
		GameTextForPlayer(playerid,"Starting engine.~n~Please Wait....",3000,5);
    }
    else
    {
        SetVehicleParamsEx(vid,0,lights,alarm,doors,bonnet,boot,objective);
    }
    return true;
}

COMMAND:lights(playerid, params[])
{
    if(!IsPlayerConnected(playerid)) return false;
    if(GetPlayerState(playerid) != 2) return false;
    vid = GetPlayerVehicleID(playerid);
    GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
    if(lights != 1)
    {
        SetVehicleParamsEx(vid,engine,1,alarm,doors,bonnet,boot,objective);
    }
    else
    {
        SetVehicleParamsEx(vid,engine,0,alarm,doors,bonnet,boot,objective);
    }
    return true;
}

COMMAND:hood(playerid, params[])
{
    if(!IsPlayerConnected(playerid)) return false;
    if(GetPlayerState(playerid) != 2) return false;
    vid = GetPlayerVehicleID(playerid);
    GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
    if(bonnet != 1)
    {
        SetVehicleParamsEx(vid,engine,lights,alarm,doors,1,boot,objective);
    }
    else
    {
        SetVehicleParamsEx(vid,engine,lights,alarm,doors,0,boot,objective);
    }
    return true;
}

COMMAND:boot(playerid, params[])
{
    if(!IsPlayerConnected(playerid)) return false;
    if(GetPlayerState(playerid) != 2) return false;
    vid = GetPlayerVehicleID(playerid);
    GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
    if(boot != 1)
    {
        SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,1,objective);
    }
    else
    {
        SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,0,objective);
    }
    return true;
}

CMD:spawn(playerid,params[])
{
	new Float:p[4],n[32],c1,c2;
	GetPlayerPos(playerid, p[0],p[1],p[2]);
	GetPlayerFacingAngle(playerid, p[3]);
	if(sscanf(params,"s[32]I(0)I(1)",n,c1,c2)) return scm(playerid,-1,"/spawn [model name] [colour 1] [colour 2]");
	new mdl=GetVehicleModelIDFromName(n);
	if(mdl < 400 && mdl > 611) return scm(playerid,-1,"Invalid vehicle model name.");
	vid = CreateVehicle(mdl,p[0],p[1],p[2],p[3],c1,c2,-1);
	PutPlayerInVehicle(playerid,vid,0);
	return 1;
}