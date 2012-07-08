#if defined _commands_included
	#endinput
#endif
#define _commands_included

//Admin Commands

CMD:givemoney(playerid,params[])
{
	new id,a;
	if(admin[playerid] < 3) return 0;
	if(sscanf(params,"ui",id,a)) return scm(playerid,0xFF0000FF,"[player] [amount]");
	if(id == playerid && admin[playerid] != 4) return scm(playerid,0xFF0000FF,"You cannot give yourself money.");
	if(a < 0 || a > 500000) return scm(playerid,0xFF0000FF,"You cannot lend more than $500000.");
	GivePlayerCash(id,a);
	new s[128],p[32],n[32];
	GetPlayerName(playerid,n,32);
	GetPlayerName(id,p,32);
	format(s,128,"AdminLog: %s has given %s %d dollars.",n,p,a);
	Log(1,s);
	return 1;
}

CMD:setoveh(playerid, params[])
{
	new id, query[256], Float:x, Float:y, Float:z, Float:r, mdl,c1,c2;
	if(!IsPlayerInAnyVehicle(playerid)) return scm(playerid,red,"you have to be in a vehicle.");
	if(sscanf(params,"ii",id,vid)) return scm(playerid,red,"[org] [veh id 1 - 8]");
	if(admin[playerid] != 4) return 0;
	mdl = GetVehicleModel(GetPlayerVehicleID(playerid));
	GetVehicleColor(GetPlayerVehicleID(playerid), c1, c2);
	GetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
	GetVehicleZAngle(GetPlayerVehicleID(playerid), r);
	format(query, sizeof(query), "INSERT INTO orgvehs (ID,Model,X,Y,Z,R,c1,c2,vid) VALUES (%d, %d, %f, %f, %f, %f, %d, %d, %d)", id, mdl ,x , y,z,r,c1,c2,vid);
	mysql_query(query);
	vorg[GetPlayerVehicleID(playerid)]=id;
	orgvid[GetPlayerVehicleID(playerid)]=vid;
	new a[128];
	format(a,128,"ALTER TABLE  `orgs` ORDER BY  `ID`");
	mysql_query(a);
	SendClientMessage(playerid, COLOR_ORANGE, "You have made this an org vehicle successfully.");
	return 1;
}

CMD:loadovehs(playerid,params[])
{
	if(admin[playerid] != 4) return 1;
	for(new i;i<MAX_VEHICLES;i++)
	{
	    if(vorg[i] > 0)
	    {
	        DestroyVehicle(i);
	        vorg[i]=0;
	        orgvid[i]=0;
	    }
	}
	LoadOvehs();
	scm(playerid,red,"Reloaded all org vehicles.");
	return 1;
}

CMD:deloveh(playerid,params[])
{
	new q[128];
	if(admin[playerid] != 4) return scm(playerid,0xFF0000FF,"You cannot use this command.");
 	if(sscanf(params,"i",vid)) return scm(playerid,red,"[vehicle id [/dl]]");
 	if(vorg[vid] == 0) return scm(playerid,red,"Thats not a org vehicle.");
	format(q,128,"DELETE FROM orgvehs WHERE ID=%d AND VID=%d",vorg[vid],orgvid[vid]);
	mysql_query(q);
	DestroyVehicle(vid);
	vorg[vid]=0;
	orgvid[vid]=0;
	scm(playerid,red,"Deleted.");
	return 1;
}

CMD:setpskin(playerid,params[])
{
	new id,sk,s[128],n[32],p[32];
	if(admin[playerid] < 2) return 0;
	if(sscanf(params,"ui",id,sk)) return scm(playerid,0xFF0000FF,"[playerid] [skinid]");
	if(sk < 0 && sk > 299 ) return scm(playerid,0xFF0000FF,"skins range 0-299.");
	SetPlayerSkin(id,sk);
	scm(playerid,red,"Playeer skin changed.");
	scm(id,red,"An admin has changed your skin.");
	GetPlayerName(playerid,n,32);
	GetPlayerName(id,p,32);
	format(s,128,"AdminLog: %s has changed %s's skin.",n,p);
	Log(1,s);
	return 1;
}

CMD:setleader(playerid, params[])
{
	new id,sl;
	if(admin[playerid]!=4) return 0;
	if(sscanf(params,"ui",id,sl)) return SendClientMessage(playerid, red, "USAGE:/setleader [playerid] [orgid]");
	if(id == INVALID_PLAYER_ID) SendClientMessage(playerid, 0xFF0000AA, "Player not found");
	if(!CheckOrgExists(sl)) return scm(playerid,0xFF0000FF,"Invalid organisation.");
	format(String, sizeof(String), "UPDATE users SET org=%d, req=0, lead=1 WHERE name='%s'", sl, getname(id));
	mysql_query(String);
	if(org[id] != sl) orgdata[sl][memcount]++;
	org[id]=sl;
	leader[id]=1;
	format(String,128,"You have been set leader of the faction %s.",getoname(sl));
	SendClientMessage(id, COLOR_ORANGE,String);
    LoadOstats(id);
    cmd_oskin(id, "");
	setpintdata(id,"users","job",0);
	job[id] = 0;
	format(orgdata[sl][oleader],32,"%s",getname(id));
	return 1;
}

CMD:vrespawn(playerid, params[])
{
	new sec,string[128];
	if(admin[playerid]<2) return 0;
	if(sscanf(params,"i",sec)) return SendClientMessage(playerid, red, "USAGE:/vrespawn [seconds]");
	SetTimer("vrespawn", sec*1000, false);
	format(string, sizeof(string), "~All currently unoccupied vehicles will respawn in %d seconds.",sec);
	SendClientMessageToAll(COLOR_ORANGE, string);
	return 1;
}

forward vrespawn();
public vrespawn()
{
	new u[MAX_VEHICLES];
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerInAnyVehicle(i)) u[GetPlayerVehicleID(i)]=1;
 	}
 	for(new i;i<MAX_VEHICLES;i++)
 	{
 	    if(u[i] != 1) SetVehicleToRespawn(i); else continue;// && strlen(owner[i]) == 0) SetVehicleToRespawn(i); else continue;
 	}
	SendClientMessageToAll(COLOR_ORANGE, "~All vehicles have been respawned.");
	return 1;
}

CMD:setco(playerid, params[])
{
	new id,sl;
	if(admin[playerid]!=4) return 0;
	if(sscanf(params,"ui",id,sl)) return SendClientMessage(playerid, red, "USAGE:/setco [playerid] [org]");
	if (id == INVALID_PLAYER_ID) SendClientMessage(playerid, 0xFF0000AA, "Player not found");
	if(!CheckOrgExists(sl)) return scm(playerid,0xFF0000FF,"Invalid organisation.");
	format(String, sizeof(String), "UPDATE users SET org=%d, lead=2, osal=9000 WHERE name='%s'", sl, getname(sl));
	mysql_query(String);
	if(org[id] != sl) orgdata[sl][memcount]++;
	org[id]=sl;
	leader[id]=2;
	format(String,128,"You have been set co-leader of the faction %s.",getoname(sl));
	SendClientMessage(id, COLOR_ORANGE,String);
	LoadOstats(id);
	cmd_oskin(id,"");
	setpintdata(id,"users","job",0);
	job[id]=0;
	return 1;
}

CMD:setocp(playerid, params[])
{
	new Float:x,Float:y,Float:z,id,tmp;
	if(admin[playerid]!=4) return 0;
	if(sscanf(params,"i",id)) return SendClientMessage(playerid, red, "USAGE:/setcp [org]");
	GetPlayerPos(playerid, x,y,z);
	format(String,128,"INSERT INTO orgs (orgid, cpx, cpy, cpz) VALUES (%d, %f, %f, %f)",id,x,y,z);
	mysql_query(String);
	tmp=CreateDynamicCP(x,y,z,1.0,0,0,-1,100.0);
	corg[tmp]=id;
	SendClientMessage(playerid, COLOR_ORANGE, "Family Checkpoint set.");
	return 1;
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

COMMAND:ocreate(playerid,params[])
{
	new id,name[32],type;
	if(admin[playerid]!=4) return SendClientMessage(playerid, red, "You dont have the permission to do that.");
	if(sscanf(params,"iis",id,type,name)) return SendClientMessage(playerid, red, "USAGE:/ocreate [id] [type] [name]");
	if(CheckOrgExists(id)) return SendClientMessage(playerid, red, "Org exists use /oname, /ocolour etc. to edit");
	if(strlen(name) > 100) return scm(playerid,0xFF0000FF,"Name too big.");
	mysql_real_escape_string(name,name);
	format(orgdata[id][oname],64,"%s",name);
	orgdata[id][ocolour]=4294967295;
	orgdata[id][ammo1]=500;
	orgdata[id][ammo2]=500;
	orgdata[id][otype]=type;
	format(String,128,"INSERT INTO orgs (org) VALUES (%d)",id);
	mysql_query(String);
	updateorgdata(id);
	format(String,128,"Create %s successfully.",name);
	SendClientMessage(playerid, COLOR_ORANGE, String);
 	return 1;
}

COMMAND:oname(playerid, params[])
{
	new id,name[64];
	if(admin[playerid]!=4) return 0;
	if(sscanf(params,"is",id,name)) return SendClientMessage(playerid, red, "USAGE:/oname [id] [name]");
	format(orgdata[id][oname],64,"%s",name);
	updateorgstr(id,"name",name);
	format(String,128,"Organization Name changed to %s.",orgdata[id][oname]);
	scm(playerid,COLOR_ORANGE,String);
	return 1;
}

CMD:oweapons(playerid, params[])
{
	new id,w1,w2,a1,a2;
	if(admin[playerid]!=4) return 0;
	if(sscanf(params,"iiiii",id,w1,a1,w2,a2)) return SendClientMessage(playerid, red, "USAGE:/oweapons [org] [wpn1] [am1] [wpn2] [am2]");
	orgdata[id][wpn1]=w1;
	orgdata[id][wpn2]=w2;
	orgdata[id][ammo1]=a1;
	orgdata[id][ammo2]=a2;
	format(String,128,"UPDATE orgs SET wpn1=%d, wpn2=%d, ammo1=%d, ammo2=%d WHERE orgid=%d",w1,w2,a1,a2,id);
	mysql_query(String);
	for(new i=0;i<MAX_PLAYERS;i++)
	{
	    LoadOstats(i);
	}
	SendClientMessage(playerid, COLOR_ORANGE, "Organisation weapons changed.");
	return 1;
}

CMD:oskins(playerid, params[])
{
	new id, sskin1,sskin2,sskin3;
	if(admin[playerid]!=4) return 0;
	if(sscanf(params,"iiii",id,skin1,skin2,skin3)) return SendClientMessage(playerid, red, "USAGE:/oskins [org] [s1] [s2] [s3]");
	format(String,sizeof(String), "UPDATE orgs SET skin1=%d, skin2=%d, skin3=%d WHERE orgid=%d",sskin1,sskin2,sskin3,id);
	mysql_query(String);
	orgdata[id][skin1]=sskin1;
	orgdata[id][skin2]=sskin2;
	orgdata[id][skin3]=sskin3;
    for(new i=0;i<MAX_PLAYERS;i++)
	{
	    LoadOstats(i);
	}
	return 1;
}

CMD:ocolour(playerid, params[])
{
	new id,colour[32];
	if(admin[playerid]!=4) return 0;
 	if(sscanf(params,"ix",id,colour)) return SendClientMessage(playerid, red, "USAGE:/ocolour [id] [0xcolourhexFF]");
	orgdata[id][ocolour]=getocolor(id);
	format(String, sizeof(String), "UPDATE orgs SET Colour=%d WHERE orgid=%d",colour,id);
 	mysql_query(String);
	scm(playerid,COLOR_ORANGE,"Organization colour has been modified.");
  	return 1;
}

CMD:orgtype(playerid, params[])
{
	new id,t,ty[32];
	if(admin[playerid]!=4) return 0;
	if(sscanf(params,"ii",id,t)) return SendClientMessage(playerid, red, "USAGE:/orgtype [orgid] [1-law,2-gang/mafia,3-pvt]");
	format(String,128,"UPDATE orgs SET type=%d WHERE orgid=%d",t,id);
	mysql_query(String);
	orgdata[id][otype]=t;
	switch(t)
	{
		case 1: ty="Government";
		case 2: ty="Gang/Mafia";
		case 3: ty="Pvt. Business";
	}
	format(String,128,"Organization type has been set to %s",ty);
	scm(playerid,COLOR_ORANGE,String);
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
    if(stalled[vid] == 1) return scm(playerid,0xFF0000FF,"This vehicles engine broke down. Please call a mechanic.");
    GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
    if(fuel[vid] == 0) return scm(playerid,red,"There is no fuel in this vehicle."),SetVehicleParamsEx(vid,0,lights,alarm,doors,bonnet,boot,objective);
    if(engine != 1)
    {
        if(fuel[vid] <= 5 && fuel[vid] > 0) return scm(playerid,0xFF0000FF,"This vehicles fuel is low. Please call a mechanic or use a refuel can.");
 		if(fuel[vid] == 0) return scm(playerid,red,"There is no fuel in this vehicle."),SetVehicleParamsEx(vid,0,lights,alarm,doors,bonnet,boot,objective);
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

CMD:accept(playerid, params[])
{
	new id;
	if(sscanf(params,"u",id)) return SendClientMessage(playerid, red, "USAGE:/accept [id]");
	if(!IsPlayerConnected(id)) return scm(playerid,0xFF0000FF,"Player doesnt exist.");
	if(leader[playerid] != 1 && leader[playerid] != 2) return SendClientMessage(playerid, red, "Your not a leader or co.");
	if(req[id] != org[playerid]) return SendClientMessage(playerid, red, "The player is not requesting to join your org.");
	if(org[id] != org[playerid]) orgdata[playerid][memcount]++;
	format(String,sizeof(String), "UPDATE users SET org=%d, req=0, lead=0 WHERE name='%s'",org[playerid],getname(id));
	mysql_query(String);
	format(String, sizeof(String), "Your application for %s has been accepted.",orgdata[org[playerid]][oname]);
	SendClientMessage(id, COLOR_ORANGE, String);
	format(String, 128, "You have accepted %s into your organisation.",getname(id));
	SendClientMessage(playerid, COLOR_ORANGE, String);
	LoadOstats(id);
	cmd_oskin(id,"");
	setpintdata(id,"users","job",0);
	job[id] = 0;
	return 1;
}

CMD:oskin(playerid, params[])
{
	if(org[playerid] == 0) return 1;
//	if(pjailed[playerid] == 1) return scm(playerid,0xFF0000FF,"You cannot use this command when jailed.");
	if(GetPlayerWantedLevel(playerid) > 0) return scm(playerid,0xFF0000FF,"You cannot use this command when wanted.");
	LoadOstats(playerid);
	new tmp;
	if(org[playerid]<1) return SendClientMessage(playerid, red, "Your not in an organisation.");
	if(GetPlayerSkin(playerid) != orgdata[org[playerid]][skin1] || orgdata[org[playerid]][skin2] || orgdata[org[playerid]][skin3])
	{
	    civil[playerid]=GetPlayerSkin(playerid);
	    format(String,128,"UPDATE users SET civil=%d WHERE name='%s'",civil[playerid],getname(playerid));
	}
	SetPlayerColor(playerid, orgdata[org[playerid]][ocolour]);
	tmp=GetPlayerSkin(playerid);
	if(tmp != orgdata[org[playerid]][skin1])
	{
		SetPlayerSkin(playerid, orgdata[org[playerid]][skin1]);
	}
	if(tmp == orgdata[org[playerid]][skin1])
	{
		SetPlayerSkin(playerid,	orgdata[org[playerid]][skin2]);
	}
	if(tmp == orgdata[org[playerid]][skin2])
	{
		SetPlayerSkin(playerid, orgdata[org[playerid]][skin3]);
	}
	ResetPlayerWeapons(playerid);
	GivePlayerWeapon(playerid, orgdata[org[playerid]][wpn1],orgdata[org[playerid]][ammo1]);
	GivePlayerWeapon(playerid, orgdata[org[playerid]][wpn2],orgdata[org[playerid]][ammo2]);
	return 1;
}


CMD:request(playerid, params[])
{
	new id;
    if(sscanf(params, "i", id)) return SendClientMessage(playerid, red, "USAGE:/request [org]");
    if(org[playerid]>0) return SendClientMessage(playerid, red, "Your already in an org.");
    if(!CheckOrgExists(id)) return SendClientMessage(playerid, red, "Org doesnt exist.");
    if(getomemcnt(id) >= 8) return scm(playerid,0xFF0000FF,"Organisation is full sorry.");
    req[playerid]=id;
    format(String, sizeof String, "%s is requesting to join %s.", getname(playerid), getoname(id));
    SendClientMessageToAll(COLOR_ORANGE, String);
    return 1;
}

CMD:setskin(playerid,params[])
{
	new id;
	if(vip[playerid]==0) return scm(playerid,0xFF0000FF,"Your not a vip.");
	if(sscanf(params,"i",id)) return scm(playerid,0xFF0000FF,"USAGE:/setskin [skin id]");
	if(id < 0 || id >= 300) return scm(playerid,0xFF0000FF,"skin ids range is b/w 0-199 so enter a valid skin id.");
	SetPlayerSkin(playerid, id);
	if(GetPlayerSkin(playerid) == id) SendClientMessage(playerid,COLOR_ORANGE,"*Skin changed.");
	else SendClientMessage(playerid,red,"Invalid skin id.");
	return 1;
}

CMD:car(playerid,params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return scm(playerid,0xFF0000FF,"Your either not in a vehicle or your not the driver.");
	ShowPlayerDialog(playerid,43,DIALOG_STYLE_LIST,"Car options:","Engine\nLights\nLock\nHood\nBoot\nUnlock","Ok","Cancel");
	return 1;
}

CMD:setvip(playerid,params[])
{
	if(admin[playerid] < 4) return 0;
	new id,t,time;
	if(sscanf(params,"ui",id,t)) return SendClientMessage(playerid, red, "USAGE:/setvip [playerid] [acc. type]");
	time=gettime();
	time+=2592000*t;
	setpintdata(playerid,"users","vip",1);
	format(String,256,"INSERT INTO `vip` (name,type,time) VALUES ('%s',%d,%d)",getname(id),t,time);
	mysql_query(String);
	vip[id]=t;
	SendClientMessage(id, COLOR_ORANGE, "You are now a vip.");
	format(String,128,"You have made %s a vip. type:%d",getname(id),t);
	SendClientMessage(playerid,COLOR_ORANGE,String);
	return 1;
}

CMD:setveh(playerid,params[])
{
	new car,name[32];
	if(vip[playerid]<1) return SendClientMessage(playerid, red, "Your not a vip.");
	if(sscanf(params,"s",name)) return SendClientMessage(playerid, red, "USAGE:/setveh [model]");
	car = GetVehicleModelIDFromName(name);
	if(car == 520 || car == 432 || car == 415) return scm(playerid,red,"You cannot spawn this vehicle");
	DestroyVehicle(vipcar[playerid]);
	new Float:x,Float:y,Float:z,Float:p[4];
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid,p[3]);
	vipcar[playerid]=CreateVehicle(car,x+1,y+1,z+0.2,0.0,0,1,-1);
	SetVehicleVirtualWorld(vipcar[playerid],GetPlayerVirtualWorld(playerid));
	stalled[vipcar[playerid]]=0;
	fuel[vipcar[playerid]]=100;
	PutPlayerInVehicle(playerid,vipcar[playerid],0);
	SetVehicleParamsEx(vipcar[playerid],1,0,alarm,doors,bonnet,boot,objective);
	SetVehicleZAngle(GetPlayerVehicleID(playerid),p[3]);
	format(String,COLOR_YELLOW,"You have spawned a {FFFFFF}%s {FF8000}as your vip vehicle.",VehicleNames[car-400]);
	SendClientMessage(playerid,COLOR_ORANGE,String);
	return 1;
}

CMD:exitveh(playerid,params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER && !IsPlane(GetVehicleModel(GetPlayerVehicleID(playerid)))) return 1;
	new Float:p[3];
	GetPlayerPos(playerid,p[0],p[1],p[2]);
	SetPlayerPos(playerid,p[0],p[1],p[2]+2);
	return 1;
}

CMD:eject(playerid,params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 1;
    new id;
    if(sscanf(params,"u",id)) return scm(playerid,0xFF0000FF,"[playerid]");
    if(!IsPlayerInVehicle(id,GetPlayerVehicleID(playerid))) return scm(playerid,0xFF0000FF,"The player is not in your vehicle.");
    RemovePlayerFromVehicle(id);
    scm(id,red,"You have been ejected.");
    return 1;
}

CMD:vehcol(playerid,params[])
{
	new c1,c2;
	if(vip[playerid]<1) return SendClientMessage(playerid, red, "Your not a vip.");
	if(sscanf(params,"ii",c1,c2)) return SendClientMessage(playerid, red, "USAGE:/vehcol [id] [id2]");
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, red, "Your not in a vehicle or your not the driver.");
	new id,name[32];
	id=GetPlayerVehicleID(playerid);
	ChangeVehicleColor(id,c1,c2);
	GetPlayerName(playerid,name,32);
	OnVehicleRespray(playerid,GetPlayerVehicleID(playerid),c1,c2);
	SendClientMessage(playerid, COLOR_ORANGE,"Vehicle color changed.");
	return 1;
}

COMMAND:me(playerid, params[])
{
	new name[32];
    if(isnull(params)) return SendClientMessage(playerid, red, "Usage: /me [action]");
    if(StringContainsIP(params)) return OnPlayerText(playerid,params);
    GetPlayerName(playerid, name, MAX_PLAYER_NAME);
    format(String, sizeof(String), "%s %s", name, params);
    SendClientMessageToAll(0xFF9900AA,String);
    return 1;
}

COMMAND:shout(playerid, params[])
{
	new name[32];
	if(isnull(params)) return SendClientMessage(playerid, COLOR_RED, "USAGE:/shout [MESSAGE]");
	if(StringContainsIP(params)) return OnPlayerText(playerid,params);
	GetPlayerName(playerid, name, MAX_PLAYER_NAME);
	format(String, sizeof(String), "%s[Shouts]: %s", name, params);
	SendClientMessageToAll(0x6896EF55, String);
	return 1;
}

CMD:ooc(playerid,params[])
{
	new s[128],n[32];
	if(sscanf(params,"s",params)) return scm(playerid,0xFF0000FF,"USAGE:/ooc [msg]");
	if(StringContainsIP(params)) return OnPlayerText(playerid,params);
	GetPlayerName(playerid,n,32);
	format(s,128,"[OOC]((%s: %s ))",n,params);
	SendClientMessageToAll(0x009900FF,s);
	return 1;
}

CMD:setpj(playerid,params[])
{
	new id,veh=GetPlayerVehicleID(playerid);
	if(vip[playerid]==0) return scm(playerid,0xFF0000FF,"Your not a vip.");
	if(sscanf(params,"i",id)) return scm(playerid,0xFF0000FF,"USAGE:/setpj [id]");
	ChangeVehiclePaintjob(veh,id);
	OnVehiclePaintjob(playerid, veh, id);
	if(GetPlayerSkin(playerid) == id) SendClientMessage(playerid,COLOR_ORANGE,"*PaintJob changed.");
	return 1;
}