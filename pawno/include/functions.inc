#if defined _IRfunctions_included
	#endinput
#endif
#define _IRfunctions_included
	
/*
	native getname(playerid);
	native scm(playerid, color, text[]);
	native rscm(playerid, color, text[], Float:range=-1);
	native setpintdata(playerid, table, field, data);
	native setpfltdata(playerid, table, field, Float:data);
	native setpstrdata(playerid, table, field, data[]);
	native getintdata(playerid, table, field);
	native getfltdata(playerid, table, field);
	native getstrdata(playerid, table, field);
	native connect_mysql();
	native AccountExists(playerid);
	native GetVehicleModelIDFromName(vname[]);
	native GetDistanceBetweenPlayers(playerid,playerid2);
	native GetDistanceBetweenVehicles(playerid, playerid2);
	native PointToPoint(Float:x, Float:y, Float:z, Float:x1, Float:x2, Float:x3);
	native ShowLogin(playerid);
	native ShowRegister(playerid);
	native spawn_camera(playerid);
	native LoginPlayer(playerid, pass[]);
	native RegisterPlayer(playerid, pass[]);
	native ServerInit();
	native SavePlayer();
	native CreateDynamicArea(Float:maxx,Float:minx,Float:maxy,Float:miny);
	native AreaCheck(playerid);
	native createtextdraws(playerid);
	native showtextdraws(playerid);
	native hidetextdraws(playerid);
	native setspdtdbars(playeris);
	native Speedo(playerid);
	native IsBike(modelid);
	native IsMotorBike(modelid);
	native IsBoat(modelid);
	native IsTrain(modelid);
	native IsHeli(modelid);
	native IsPlane(modelid);
	native IsCar(modelid);
	native IsRC(modeilid);
	native destroytextdraws(playerid);
	native SetCars();
	native LoadRefuel();
	native explode(const sSource[], aExplode[][], const sDelimiter[] = " ", iVertices = sizeof aExplode, iLength = sizeof aExplode[]);
	native fuelvehicles();
	native LoadMap();
	native refuel(playerid);
	native IsPetrolVeh(vehicleid);
	native IsFastCar(vehicleid);
	native GetCapacity(vehicleid);
	native IsNearRefuelCenter(playerid);
	native IsDeiselVehicle(vehicleid);
	native GivePlayerCash(playerid, amount);
	native GetPlayerCash(playerid);
	native IsJobVeh(vehicleid);
	native LoadJobs();
	native resetvars();
	native getoname(orgid);
	native LoadOStats(playerid);
	native getoname(orgid);
	native updateorgint(orgid, field[], data);
	native updateorgstr(orgid, field[], data[]);
	native updateorgflt(orgid, field[], Float:data);
	native getomemcnt(orgid);
	native LoadOcps();
	native Log(type, string[]);
	native StringContainsIP(string[]);
	native CreateDCones(playerid);
	native DestroyDCones(playerid);
	native ColouredText(string[]);
*/

new VehicleNames[212][] = {
	{"Landstalker"},
	{"Bravura"},
	{"Buffalo"},
	{"Linerunner"},
	{"Perrenial"},
	{"Sentinel"},
	{"Dumper"},
	{"Firetruck"},
	{"Trashmaster"},
	{"Stretch"},
	{"Manana"},
	{"Infernus"},
	{"Voodoo"},
	{"Pony"},
	{"Mule"},
	{"Cheetah"},
	{"Ambulance"},
	{"Leviathan"},
	{"Moonbeam"},
	{"Esperanto"},
	{"Taxi"},
	{"Washington"},
	{"Bobcat"},
	{"Mr Whoopee"},
	{"BF Injection"},
	{"Hunter"},
	{"Premier"},
	{"Enforcer"},
	{"Securicar"},
	{"Banshee"},
	{"Predator"},
	{"Bus"},
	{"Rhino"},
	{"Barracks"},
	{"Hotknife"},
	{"Trailer 1"}, //artict1
	{"Previon"},
	{"Coach"},
	{"Cabbie"},
	{"Stallion"},
	{"Rumpo"},
	{"RC Bandit"},
	{"Romero"},
	{"Packer"},
	{"Monster"},
	{"Admiral"},
	{"Squalo"},
	{"Seasparrow"},
	{"Pizzaboy"},
	{"Tram"},
	{"Trailer 2"}, //artict2
	{"Turismo"},
	{"Speeder"},
	{"Reefer"},
	{"Tropic"},
	{"Flatbed"},
	{"Yankee"},
	{"Caddy"},
	{"Solair"},
	{"Berkley's RC Van"},
	{"Skimmer"},
	{"PCJ-600"},
	{"Faggio"},
	{"Freeway"},
	{"RC Baron"},
	{"RC Raider"},
	{"Glendale"},
	{"Oceanic"},
	{"Sanchez"},
	{"Sparrow"},
	{"Patriot"},
	{"Quad"},
	{"Coastguard"},
	{"Dinghy"},
	{"Hermes"},
	{"Sabre"},
	{"Rustler"},
	{"ZR-350"},
	{"Walton"},
	{"Regina"},
	{"Comet"},
	{"BMX"},
	{"Burrito"},
	{"Camper"},
	{"Marquis"},
	{"Baggage"},
	{"Dozer"},
	{"Maverick"},
	{"News Chopper"},
	{"Rancher"},
	{"FBI Rancher"},
	{"Virgo"},
	{"Greenwood"},
	{"Jetmax"},
	{"Hotring"},
	{"Sandking"},
	{"Blista Compact"},
	{"Police Maverick"},
	{"Boxville"},
	{"Benson"},
	{"Mesa"},
	{"RC Goblin"},
	{"Hotring Racer A"}, //hotrina
	{"Hotring Racer B"}, //hotrinb
	{"Bloodring Banger"},
	{"Rancher"},
	{"Super GT"},
	{"Elegant"},
	{"Journey"},
	{"Bike"},
	{"Mountain Bike"},
	{"Beagle"},
	{"Cropdust"},
	{"Stunt"},
	{"Tanker"}, //petro
	{"Roadtrain"},
	{"Nebula"},
	{"Majestic"},
	{"Buccaneer"},
	{"Shamal"},
	{"Hydra"},
	{"FCR-900"},
	{"NRG-500"},
	{"HPV1000"},
	{"Cement Truck"},
	{"Tow Truck"},
	{"Fortune"},
	{"Cadrona"},
	{"FBI Truck"},
	{"Willard"},
	{"Forklift"},
	{"Tractor"},
	{"Combine"},
	{"Feltzer"},
	{"Remington"},
	{"Slamvan"},
	{"Blade"},
	{"Freight"},
	{"Streak"},
	{"Vortex"},
	{"Vincent"},
	{"Bullet"},
	{"Clover"},
	{"Sadler"},
	{"Firetruck LA"}, //firela
	{"Hustler"},
	{"Intruder"},
	{"Primo"},
	{"Cargobob"},
	{"Tampa"},
	{"Sunrise"},
	{"Merit"},
	{"Utility"},
	{"Nevada"},
	{"Yosemite"},
	{"Windsor"},
	{"Monster A"}, //monstera
	{"Monster B"}, //monsterb
	{"Uranus"},
	{"Jester"},
	{"Sultan"},
	{"Stratum"},
	{"Elegy"},
	{"Raindance"},
	{"RC Tiger"},
	{"Flash"},
	{"Tahoma"},
	{"Savanna"},
	{"Bandito"},
	{"Freight Flat"}, //freiflat
	{"Streak Carriage"}, //streakc
	{"Kart"},
	{"Mower"},
	{"Duneride"},
	{"Sweeper"},
	{"Broadway"},
	{"Tornado"},
	{"AT-400"},
	{"DFT-30"},
	{"Huntley"},
	{"Stafford"},
	{"BF-400"},
	{"Newsvan"},
	{"Tug"},
	{"Trailer 3"}, //petrotr
	{"Emperor"},
	{"Wayfarer"},
	{"Euros"},
	{"Hotdog"},
	{"Club"},
	{"Freight Carriage"}, //freibox
	{"Trailer 3"}, //artict3
	{"Andromada"},
	{"Dodo"},
	{"RC Cam"},
	{"Launch"},
	{"Police Car (LSPD)"},
	{"Police Car (SFPD)"},
	{"Police Car (LVPD)"},
	{"Police Ranger"},
	{"Picador"},
	{"S.W.A.T. Van"},
	{"Alpha"},
	{"Phoenix"},
	{"Glendale"},
	{"Sadler"},
	{"Luggage Trailer A"}, //bagboxa
	{"Luggage Trailer B"}, //bagboxb
	{"Stair Trailer"}, //tugstair
	{"Boxville"},
	{"Farm Plow"}, //farmtr1
	{"Utility Trailer"} //utiltr1
};
	
	
stock getname(playerid)
{
	new n[32];
	GetPlayerName(playerid, n, 32);
	return n;
}

stock scm(playerid, color, text[])
{
	return SendClientMessage(playerid, color, text);
}

stock rscm(playerid, color, text[], Float:range=-1.0)
{
	if(range <= -1) return SendClientMessage(playerid, color, text);
	else
	{
		new Float:p[3];
		GetPlayerPos(playerid, p[0],p[1],p[2]);
		for(new i;i<MAX_PLAYERS;i++)
		{
			if(IsPlayerConnected(playerid))
			{
				if(IsPlayerInRangeOfPoint(playerid, range, p[0],p[1],p[2])
				{
					SendClientMessage(playerid, color, text);
				}
			}
		}
	}
	return 1;
}

stock setpintdata(playerid, table[], field[], data)
{
	format(String, 128, "UPDATE `%s` SET `%s`=%d WHERE Name='%s'",table,field,data,getname(playerid));
	mysql_query(String);
	return 1;
}

stock setpfltdata(playerid, table[], field[], Float:data)
{
	format(String, 128, "UPDATE `%s` SET `%s`=%f WHERE Name='%s'",table,field,data,getname(playerid));
	mysql_query(String);
	return 1;
}	

stock setpstrdata(playerid, table[], field[], data[])
{
	format(String, 128, "UPDATE `%s` SET `%s`='%s' WHERE Name='%s'",table,field,data,getname(playerid));
	mysql_query(String);
	return 1;
}		

stock getintdata(playerid, table[], field[])
{
	format(String, 128, "SELECT %s FROM %s WHERE Name='%s'",field,table,getname(playerid));
	mysql_query(String);
	mysql_store_result();
	mysql_fetch_row_format(String, "|");
	new v;
	sscanf(String,"p<|>i",v);
	mysql_free_result();
	return v;
}

stock Float:getfltdata(playerid, table[], field[])
{
	format(String, 128, "SELECT %s FROM %s WHERE Name='%s'",field,table,getname(playerid));
	mysql_query(String);
	mysql_store_result();
	mysql_fetch_row_format(String, "|");
	new Float:v;
	sscanf(String,"p<|>f",v);
	mysql_free_result();
	return v;
}

stock getstrdata(playerid, table[], field[])
{
	format(String, 128, "SELECT %s FROM %s WHERE Name='%s'",field,table,getname(playerid));
	mysql_query(String);
	mysql_store_result();
	mysql_fetch_row_format(String, "|");
	new v[128];
	sscanf(String,"p<|>s[128]",v);
	mysql_free_result();
	return v;
}

stock AccountExists(playerid)
{
	if(getintdata(playerid, "users", "uID") > 0) return 1;
	return -1;
}

stock connect_mysql()
{
	return mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASSWORD);
}

stock GetVehicleModelIDFromName(name[])
{
	for(new i = 0; i < 211; i++)
	{
		if (strfind(VehicleNames[i], name, true) != -1 )
		return i + 400;
	}
	return -1;
}

stock GetDistanceBetweenPlayers(playerid,playerid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:tmpdis;
    GetPlayerPos(playerid,x1,y1,z1);
    GetPlayerPos(playerid2,x2,y2,z2);
    tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
    return floatround(tmpdis);
}

stock GetDistanceBetweenVehicles(vehicleid,vehicleid2)
{
    new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
    new Float:tmpdis;
    GetVehiclePos(vehicleid,x1,y1,z1);
    GetVehiclePos(vehicleid2,x2,y2,z2);
    tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
	return floatround(tmpdis);
}

stock PointToPoint(Float:x, Float:y, Float:z, Float:x2, Float:y2, Float:z2)
{
	new Float:tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x)),2)+floatpower(floatabs(floatsub(y2,y)),2)+floatpower(floatabs(floatsub(z2,z)),2));
    return floatround(tmpdis);
}

stock ShowLogin(playerid)
{
	scm(playerid,COLOR_ORANGE,"Hey There!");
	scm(playerid,COLOR_ORANGE,"Welcome to Ideal Roleplay (The Resurrection).");
	scm(playerid,COLOR_YELLOW,"Seems like you have already registered here before");
	scm(playerid,COLOR_YELLOW,"so you may proceed to LOGIN.");
	new lstr[256];
	format(lstr,256,"Your account has been identified as:\n\
		UserID: {FFFFFF}%d\n\
		{A9C4E4}Username: {FFFFFF}%s\n\
		{A9C4E4}IF this is your account {FFFFFF}please enter your password below {A9C4E4}to login.",getintdata(playerid,"users","uID"),getname(playerid));
	ShowPlayerDialog(playerid,1,DIALOG_STYLE_PASSWORD,"Login",lstr,"Login","Quit");
	spawn_camera(playerid);
	SetPlayerCameraPos(playerid,737.286,-1436.615,39.343);
	SetPlayerCameraLookAt(playerid,737.133,-1533.071,29.210, CAMERA_MOVE);
	SetPlayerTime(playerid,5,30);
	SetPlayerWeather(playerid, 6);
	spawn_camera(playerid);
	return 1;
}

stock ShowRegister(playerid)
{
	scm(playerid,COLOR_ORANGE,"Hey there!");
	scm(playerid,COLOR_ORANGE,"Welcome to Ideal Roleplay (The Resurrection).");
	scm(playerid,COLOR_YELLOW,"Seems like you haven't registered here yet");
	scm(playerid,COLOR_YELLOW,"so you may create an account right away.");
	new lstr[256];
	format(lstr,256,"Your account will be identified as:\n\
		{A9C4E4}Username: {FFFFFF}%s\n\
		{A9C4E4}If you wish to use another name please reconnect\n\
		{A9C4E4}else {FFFFFF}please enter a password below {A9C4E4}to register.",getname(playerid));
	ShowPlayerDialog(playerid,2,DIALOG_STYLE_PASSWORD,"Register",lstr,"Register","Quit");
	spawn_camera(playerid);
	return 1;
}


stock spawn_camera(playerid)
{
 	InterpolateCameraPos(playerid,737.286,-1436.615,39.343,713.984,-1768.145,55.055,10000);
	InterpolateCameraLookAt(playerid,675.730,-1729.415,62.378,712.978,-1848.934,43.395, 10000);
	return 1;
}

stock LoginPlayer(playerid, pass[])
{
	format(String,128,"SELECT uID FROM users WHERE Name='%s' AND Password=md5('%s')",getname(playerid),pass);
	mysql_query(String);
	mysql_store_result();
	if(!mysql_num_rows())
	{
		mysql_free_result();
		new lstr[256];
		format(lstr,256,"{FF0000}Wrong password, try again.{A9C4E4}\n\
			Your account has been identified as:\n\
			UserID: {FFFFFF}%d\n\
			{A9C4E4}Username: {FFFFFF}%s\n\
			{A9C4E4}IF this is your account {FFFFFF}please enter your password below {A9C4E4}to login.",getintdata(playerid,"users","uID"),getname(playerid));
		ShowPlayerDialog(playerid,1,DIALOG_STYLE_PASSWORD,"Login",lstr,"Login","Quit");
		return 1;
	}
	pSkin[playerid]=getintdata(playerid,"users","skin");
	pX[playerid]=getfltdata(playerid,"users", "x");
	pY[playerid]=getfltdata(playerid,"users", "y");
	pZ[playerid]=getfltdata(playerid,"users", "z");
	pAngle[playerid]=getfltdata(playerid,"users", "angle");
	Logged[playerid] = 2;
	if(GetPVarInt(playerid,"justreg") == 1) return 1,SetPVarInt(playerid,"justreg",0);
	scm(playerid,COLOR_GREEN,"Welcome back! You have successfully logged in.");
	return 1;
}

stock RegisterPlayer(playerid,pass[])
{
	format(String,128,"INSERT INTO users (Name,Password,skin) VALUES ('%s',md5('%s'),188)",getname(playerid),pass);
	mysql_query(String);
	format(String,128,"INSERT INTO camera (Name) VALUES ('%s')",getname(playerid));
	mysql_query(String);
	scm(playerid,COLOR_GREEN,"Your account has been created and has been automatically");
	scm(playerid,COLOR_GREEN,"logged in.");
	SetPVarInt(playerid,"justreg",1);
	LoginPlayer(playerid,pass);
	return 1;
}

stock SavePlayer(playerid)
{
	if(Logged[playerid] == 0) return 1;
	if(GetPlayerState(playerid) == PLAYER_STATE_WASTED)	return 1;
	if(GetPlayerState(playerid) == PLAYER_STATE_NONE) return 1;
	new Float:p[4];
	GetPlayerPos(playerid, p[0],p[1],p[2]);
	GetPlayerFacingAngle(playerid,p[3]);
	setpfltdata(playerid, "users","x", p[0]);
	setpfltdata(playerid, "users","y", p[1]);
	setpfltdata(playerid, "users","z", p[2]);
	setpfltdata(playerid, "users","angle", p[3]);
	GetPlayerCameraPos(playerid, p[0],p[1],p[2]);
	setpfltdata(playerid, "camera","px", p[0]);
	setpfltdata(playerid, "camera","py", p[1]);
	setpfltdata(playerid, "camera","pz", p[2]);
	return 1;
}

stock ServerInit()
{
	chour=random(23);
	cmins=random(59);
	LVarea=CreateDynamicArea(2989.536, -572.2159, 2966.18, 490.4708);
	LSarea=CreateDynamicArea(2977.858, -537.1823, 443.7593, -2954.502);
	SFarea=CreateDynamicArea( -595.5717, -2977.858, 2977.858, -2942.825);
	dcp = CreateDynamicCP(-2033.0657,-117.2213,1035.1719, 1.0, 0,3, -1,30);
	LoadJobs();
	LoadOcps();
	LoadOvehs();
	SetCars();
	ManualVehicleEngineAndLights();
	LoadRefuel();
	LoadMap();
	fuelvehicles();
	//death and connect message textdraw
	deathcon = TextDrawCreate(503.000000, 157.000000, "_");
	TextDrawBackgroundColor(deathcon, 255);
	TextDrawFont(deathcon, 1);
	TextDrawLetterSize(deathcon, 0.260000, 1.400000);
	TextDrawColor(deathcon, -1);
	TextDrawSetOutline(deathcon, 0);
	TextDrawSetProportional(deathcon, 1);
	TextDrawSetShadow(deathcon, 1);
	TextDrawUseBox(deathcon, 1);
	TextDrawBoxColor(deathcon, 136);
	TextDrawTextSize(deathcon, 630.000000, 0.000000);
	return 1;
}

stock CreateDynamicArea(Float:maxx,Float:minx,Float:maxy,Float:miny)
{
	return CreateDynamicRectangle(minx,miny,maxx,maxy,-1,-1,-1);
}

stock AreaCheck(playerid)
{
	if(IsPlayerInDynamicArea(playerid,LVarea) && GetPVarInt(playerid,"Area") != LVarea)
	{
 		SetPVarInt(playerid,"Area",LVarea);
	}
	if(IsPlayerInDynamicArea(playerid,LSarea) && GetPVarInt(playerid,"Area") != LSarea)
	{
 		SetPVarInt(playerid,"Area",LSarea);
	}
	if(IsPlayerInDynamicArea(playerid,SFarea) && GetPVarInt(playerid,"Area") != SFarea)
	{
   		SetPVarInt(playerid,"Area",SFarea);
	}
	new z[32];
	GetPlayer2DZone(playerid,z,32);
	PlayerTextDrawSetString(playerid, loctd ,z);
	return 1;
}

stock createtextdraws(playerid)
{
	//location textdraws
	loctd = CreatePlayerTextDraw(playerid, 40.000000, 320.000000, "Rock Quarry");
	PlayerTextDrawBackgroundColor(playerid, loctd, 255);
	PlayerTextDrawFont(playerid, loctd, 3);
	PlayerTextDrawLetterSize(playerid, loctd, 0.340000, 1.000000);
	PlayerTextDrawColor(playerid, loctd, -1);
	PlayerTextDrawSetOutline(playerid, loctd, 1);
	PlayerTextDrawSetProportional(playerid, loctd, 1);
	
	//mph texdraws
	mphtd = CreatePlayerTextDraw(playerid, 506.000000, 361.000000, "MPH: 88");
	PlayerTextDrawBackgroundColor(playerid, mphtd, 255);
	PlayerTextDrawFont(playerid, mphtd, 1);
	PlayerTextDrawLetterSize(playerid, mphtd, 0.380000, 1.800000);
	PlayerTextDrawColor(playerid, mphtd, -1);
	PlayerTextDrawSetOutline(playerid, mphtd, 0);
	PlayerTextDrawSetProportional(playerid, mphtd, 1);
	PlayerTextDrawSetShadow(playerid, mphtd, 1);
	PlayerTextDrawUseBox(playerid, mphtd, 1);
	PlayerTextDrawBoxColor(playerid, mphtd, 153);
	PlayerTextDrawTextSize(playerid, mphtd, 599.000000, 0.000000);

	fueltd = CreatePlayerTextDraw(playerid, 506.000000, 380.000000, "Fuel: 100");
	PlayerTextDrawBackgroundColor(playerid, fueltd, 255);
	PlayerTextDrawFont(playerid, fueltd, 1);
	PlayerTextDrawLetterSize(playerid, fueltd, 0.380000, 1.800000);
	PlayerTextDrawColor(playerid, fueltd, -1);
	PlayerTextDrawSetOutline(playerid, fueltd, 0);
	PlayerTextDrawSetProportional(playerid, fueltd, 1);
	PlayerTextDrawSetShadow(playerid, fueltd, 1);
	PlayerTextDrawUseBox(playerid, fueltd, 1);
	PlayerTextDrawBoxColor(playerid, fueltd, 153);
	PlayerTextDrawTextSize(playerid, fueltd, 599.000000, 0.000000);

	sl1 = CreatePlayerTextDraw(playerid, 568.000000, 390.000000, "l");
	PlayerTextDrawBackgroundColor(playerid, sl1, 255);
	PlayerTextDrawFont(playerid, sl1, 1);
	PlayerTextDrawLetterSize(playerid, sl1, 0.500000, 0.599999);
	PlayerTextDrawColor(playerid, sl1, -1431655681);
	PlayerTextDrawSetOutline(playerid, sl1, 1);
	PlayerTextDrawSetProportional(playerid, sl1, 1);

	sl2 = CreatePlayerTextDraw(playerid, 574.000000, 387.000000, "l");
	PlayerTextDrawBackgroundColor(playerid, sl2, 255);
	PlayerTextDrawFont(playerid, sl2, 1);
	PlayerTextDrawLetterSize(playerid, sl2, 0.500000, 1.000000);
	PlayerTextDrawColor(playerid, sl2, -1431655681);
	PlayerTextDrawSetOutline(playerid, sl2, 1);
	PlayerTextDrawSetProportional(playerid, sl2, 1);

	sl3 = CreatePlayerTextDraw(playerid, 580.000000, 385.000000, "l");
	PlayerTextDrawBackgroundColor(playerid, sl3, 255);
	PlayerTextDrawFont(playerid, sl3, 1);
	PlayerTextDrawLetterSize(playerid, sl3, 0.500000, 1.200000);
	PlayerTextDrawColor(playerid, sl3, -1431655681);
	PlayerTextDrawSetOutline(playerid, sl3, 1);
	PlayerTextDrawSetProportional(playerid, sl3, 1);

	sl4 = CreatePlayerTextDraw(playerid, 586.000000, 382.000000, "l");
	PlayerTextDrawBackgroundColor(playerid, sl4, 255);
	PlayerTextDrawFont(playerid, sl4, 1);
	PlayerTextDrawLetterSize(playerid, sl4, 0.500000, 1.600000);
	PlayerTextDrawColor(playerid, sl4, -1431655681);
	PlayerTextDrawSetOutline(playerid, sl4, 1);
	PlayerTextDrawSetProportional(playerid, sl4, 1);

	sl5 = CreatePlayerTextDraw(playerid, 592.000000, 379.000000, "l");
	PlayerTextDrawBackgroundColor(playerid, sl5, 255);
	PlayerTextDrawFont(playerid, sl5, 1);
	PlayerTextDrawLetterSize(playerid, sl5, 0.500000, 2.000000);
	PlayerTextDrawColor(playerid, sl5, -1431655681);
	PlayerTextDrawSetOutline(playerid, sl5, 1);
	PlayerTextDrawSetProportional(playerid, sl5, 1);
	return 1;
}

stock showtextdraws(playerid)
{
	PlayerTextDrawShow(playerid, loctd);
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(IsBike(GetVehicleModel(GetPlayerVehicleID(playerid)))) return 1;
		format(String,128,"Fuel: %d",fuel[GetPlayerVehicleID(playerid)]);
		PlayerTextDrawSetString(playerid, fueltd, String);
		PlayerTextDrawShow(playerid, mphtd);
		PlayerTextDrawShow(playerid, fueltd);
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_NONE && GetPlayerState(playerid) == PLAYER_STATE_WASTED) return hidetextdraws(playerid);
	return 1;
}

stock hidetextdraws(playerid)
{
	PlayerTextDrawHide(playerid, loctd);
	PlayerTextDrawHide(playerid, mphtd);
	PlayerTextDrawHide(playerid, fueltd);
	PlayerTextDrawHide(playerid, sl1);
	PlayerTextDrawHide(playerid, sl2);
	PlayerTextDrawHide(playerid, sl3);
	PlayerTextDrawHide(playerid, sl4);
	PlayerTextDrawHide(playerid, sl5);
	return 1;
}

stock Speedo(playerid)
{
	new Float:p[3],mph;
    GetVehicleVelocity(GetPlayerVehicleID(playerid), p[0], p[1], p[2]);
    mph = floatround((floatsqroot(((p[0]*p[0])+(p[1]*p[1]))))*100,floatround_round);
	new s[128];
	format(s,128,"MPH: %d",mph);
	PlayerTextDrawSetString(playerid, mphtd,s);
	setspdtdbars(playerid, mph);
	return 1;
}

stock setspdtdbars(playerid, mph)
{
	if(mph < 5)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawHide(playerid, sl2);
		PlayerTextDrawHide(playerid, sl3);
		PlayerTextDrawHide(playerid, sl4);
		PlayerTextDrawHide(playerid, sl5);
	}
	if(mph < 25 && mph > 5)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawShow(playerid, sl2);
		PlayerTextDrawHide(playerid, sl3);
		PlayerTextDrawHide(playerid, sl4);
		PlayerTextDrawHide(playerid, sl5);
	}
	if(mph < 50 && mph > 25)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawShow(playerid, sl2);
		PlayerTextDrawShow(playerid, sl3);
		PlayerTextDrawHide(playerid, sl4);
		PlayerTextDrawHide(playerid, sl5);
	}
	if(mph < 75 && mph > 50)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawShow(playerid, sl2);
		PlayerTextDrawShow(playerid, sl3);
		PlayerTextDrawShow(playerid, sl4);
		PlayerTextDrawHide(playerid, sl5);
	}
	if(mph < 100  && mph > 75)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawShow(playerid, sl2);
		PlayerTextDrawShow(playerid, sl3);
		PlayerTextDrawShow(playerid, sl4);
		PlayerTextDrawShow(playerid, sl5);
	}
	return 1;
}

stock IsBike(vehicleid)
{
    switch(vehicleid)
    {
        case 509, 481, 510: return 1;
    }
    return 0;
}

stock IsMotorBike(vehicleid)
{
    switch(vehicleid)
    {
        case 581, 462, 521, 463, 522, 523, 461, 448, 471, 468, 586: return 1;
    }
    return 0;
}

stock IsBoat(vehicleid)
{
    switch(vehicleid)
    {
        case 472, 473, 493, 495, 484, 430, 454, 453, 452, 446: return 1;
    }
    return 0;
}

stock IsTrain(vehicleid)
{
    switch(vehicleid)
    {
        case 590, 569, 537, 538, 570, 449: return 1;
    }
    return 0;
}

stock IsRC(vehicleid)
{
    switch(vehicleid)
    {
        case 441, 464, 465, 501, 564, 594: return 1;
    }
    return 0;
}

stock IsHeli(vehicleid)
{
    switch(vehicleid)
    {
        case 417, 425, 447, 469, 487, 488, 497, 548, 563: return 1;
    }
    return 0;
}

stock IsPlane(vehicleid)
{
    switch(vehicleid)
    {
        case 460, 476, 511, 512, 513, 519, 520, 553, 577, 592, 593: return 1;
    }
    return 0;
}

stock IsCar(modelid)
{
	if(!IsPlane(modelid) && !IsHeli(modelid) && !IsBoat(modelid) && !IsMotorBike(modelid) && !IsRC(modelid) && IsBike(modelid) && !IsTrain(modelid)) return 1;
	return 0;
}

stock destroytextdraws(playerid)
{
	PlayerTextDrawDestroy(playerid, loctd);
	PlayerTextDrawDestroy(playerid, mphtd);
	PlayerTextDrawDestroy(playerid, fueltd);
	PlayerTextDrawDestroy(playerid, sl1);
	PlayerTextDrawDestroy(playerid, sl2);
	PlayerTextDrawDestroy(playerid, sl3);
	PlayerTextDrawDestroy(playerid, sl4);
	PlayerTextDrawDestroy(playerid, sl5);
	return 1;
}

stock SetCars()
{
	//Las_Venturas_General
	AddStaticVehicle(409,1944.0602,1346.0486,8.9093,180.2598,0,0);
	AddStaticVehicle(409,1944.3724,1335.7693,8.9094,178.7635,1,1);
	AddStaticVehicle(409,2039.6443,1008.3372,10.4717,178.7756,0,0);
	AddStaticVehicle(409,2108.1514,1440.6624,10.6203,268.1557,0,0);
	AddStaticVehicle(409,2176.3467,1676.1738,10.6203,179.9265,1,1);
	AddStaticVehicle(409,2035.1099,1917.6454,11.9762,180.5781,1,1);
	AddStaticVehicle(587,2075.4963,1490.6589,10.3973,0.9207,10,10);
	AddStaticVehicle(451,2148.8706,1398.3688,10.5208,359.6848,78,78);
	AddStaticVehicle(558,2132.6252,1409.2678,10.4506,180.3099,36,1);
	AddStaticVehicle(420,2039.7207,1335.4227,10.4504,178.9215,-1,-1);
	AddStaticVehicle(420,2159.9783,1687.9427,10.5331,15.7070,-1,-1);
	AddStaticVehicle(420,2217.6040,1838.1331,10.5980,180.3272,-1,-1);
	AddStaticVehicle(420,2040.1990,1344.9268,10.4492,178.6027,-1,-1);
	AddStaticVehicle(562,2039.9257,1019.8728,10.3308,179.7790,33,33);
	AddStaticVehicle(562,1881.7867,964.0424,10.4797,89.3165,33,33);
	AddStaticVehicle(562,1881.5303,991.9349,10.4789,88.5594,33,33);
	AddStaticVehicle(562,1881.8263,1035.1031,10.4788,90.5642,33,33);
	AddStaticVehicle(562,1882.0393,1054.4159,10.4798,90.3892,33,33);
	AddStaticVehicle(543,1665.9182,900.6049,10.6179,154.1468,66,84);
	AddStaticVehicle(561,1655.6388,999.3278,10.6343,1.6394,112,112);
	AddStaticVehicle(516,1677.3665,988.1376,10.6021,359.7391,16,16);
	AddStaticVehicle(411,1889.2765,1934.0405,13.5119,180.0616,4,4);
	AddStaticVehicle(422,2791.8364,1997.4441,10.8079,358.2167,8,10);
	AddStaticVehicle(402,2812.9854,2026.3202,10.5870,181.2861,46,46);
	AddStaticVehicle(401,2822.0801,2169.3892,10.5975,270.8597,59,59);
	AddStaticVehicle(402,2582.8459,2271.9075,10.6526,89.7938,58,58);
	AddStaticVehicle(561,2764.5786,1281.6991,10.4819,91.0993,72,72);
	AddStaticVehicle(405,2782.1956,1295.4828,10.6250,179.4644,65,65);
	AddStaticVehicle(414,2624.3726,1104.1190,10.8045,269.3916,101,101);
	AddStaticVehicle(463,2437.9824,2060.0774,10.3605,321.5250,66,66);
	AddStaticVehicle(463,2439.4592,2059.3762,10.3573,317.0827,125,125);
	AddStaticVehicle(463,2436.2813,2060.5950,10.3597,324.4647,70,70);
	AddStaticVehicle(533,2444.2742,1990.9354,10.5294,359.2699,83,83);
	AddStaticVehicle(480,2458.2346,1992.2141,10.5043,180.6471,92,92);
	AddStaticVehicle(482,2170.9219,1981.6818,10.8809,90.0917,52,52);
	AddStaticVehicle(402,2231.9128,1277.3851,10.5745,1.2022,22,22);
	AddStaticVehicle(451,2182.8376,1287.8752,10.4708,180.3702,123,1);
	AddStaticVehicle(415,2171.9434,1118.7880,12.3942,333.4859,36,1);
	AddStaticVehicle(429,2141.7615,1022.6919,10.5000,90.9348,13,13);
	AddStaticVehicle(436,2150.9563,987.4216,10.5865,180.8703,87,1);
	AddStaticVehicle(439,2133.0083,1006.8494,10.7160,89.0048,43,21);
	AddStaticVehicle(561,2163.0320,1006.4872,10.6988,270.5458,101,1);
	AddStaticVehicle(461,2132.7266,899.1528,10.4046,270.7793,61,1);
	AddStaticVehicle(462,2132.7463,906.0122,10.4196,268.0389,2,1);
	AddStaticVehicle(463,2475.0217,992.2781,10.3602,206.1178,7,7);
	AddStaticVehicle(474,2197.8374,936.0216,10.5829,185.2772,105,1);
	AddStaticVehicle(442,2485.1379,936.2085,10.6624,0.1062,25,109);
	AddStaticVehicle(587,2460.3796,918.7192,10.5355,90.4611,53,1);
	AddStaticVehicle(535,2455.4519,1275.5571,10.5843,270.0745,28,1);
	AddStaticVehicle(603,2389.2190,1658.2742,10.4453,358.7758,60,1);
	AddStaticVehicle(560,2039.5767,1560.1608,10.3773,179.5952,9,39);
	AddStaticVehicle(545,2075.7207,1482.4139,10.4829,359.4229,44,96);
	AddStaticVehicle(579,2168.6729,1412.4142,10.7456,179.3802,53,53);
	AddStaticVehicle(581,2353.1150,1405.4800,10.4148,272.0892,66,1);
	AddStaticVehicle(477,2352.6646,1436.9703,10.5496,269.3466,75,1);
	AddStaticVehicle(603,2300.3599,1466.0364,10.4462,90.1237,53,53);
	AddStaticVehicle(558,2300.8755,1458.6439,10.4778,90.3777,92,1);
	AddStaticVehicle(480,2292.5034,1454.7678,13.8155,270.6444,68,1);
	AddStaticVehicle(558,2285.8660,1518.0089,16.9278,0.2348,77,1);
	AddStaticVehicle(521,2351.9590,1487.6743,17.7851,268.5520,92,3);
	AddStaticVehicle(516,2322.5889,1423.0115,22.1984,89.6001,122,1);
	AddStaticVehicle(579,2352.2910,1472.8545,32.0779,268.4590,28,119);
	AddStaticVehicle(418,2332.3298,1387.9061,36.5387,179.0473,64,64);
	AddStaticVehicle(477,2293.1245,1455.2216,39.5112,270.0951,22,1);
	AddStaticVehicle(461,2279.1494,1387.7222,42.4054,181.3635,61,1);
	AddStaticVehicle(451,2351.6416,1415.7268,42.5269,269.3744,123,123);
	AddStaticVehicle(448,2631.0559,1845.8617,10.4164,264.5009,3,6);
	AddStaticVehicle(561,2632.0137,1858.2656,10.6989,270.9765,113,1);
	AddStaticVehicle(477,2602.6128,1846.6437,10.5729,90.5212,121,1);
	AddStaticVehicle(479,2631.2253,1794.8120,10.6166,270.0366,60,35);
	AddStaticVehicle(581,2600.0813,1691.2465,10.4108,89.1784,36,1);
	AddStaticVehicle(496,2631.7998,1681.1658,10.4784,271.2010,31,31);
	AddStaticVehicle(402,2214.7441,1512.2836,10.6519,269.6815,39,39);
	AddStaticVehicle(410,2038.7775,1588.8407,10.3258,179.6040,10,1);
	AddStaticVehicle(418,1742.2191,1906.1680,10.9136,90.2075,117,227);
	AddStaticVehicle(420,1731.2715,1974.9578,10.5994,273.0416,6,1);
	AddStaticVehicle(437,1736.9500,1878.4280,10.9183,269.9015,47,74);
	AddStaticVehicle(429,1702.7047,1804.3766,10.5000,359.9712,1,2);
	AddStaticVehicle(421,1602.3925,1839.9454,10.7028,178.4762,36,1);
	AddStaticVehicle(402,1471.5049,1928.6152,11.1104,91.6437,22,22);
	AddStaticVehicle(482,1450.1931,2017.9884,10.9038,90.8726,91,1);
	AddStaticVehicle(426,1453.9977,1957.7761,10.9630,179.0628,62,62);
	AddStaticVehicle(436,1368.7289,2020.8182,11.2117,88.9614,92,1);
	AddStaticVehicle(483,1117.3785,2112.5374,10.8094,0.4216,1,31);
	AddStaticVehicle(498,1049.3367,2135.9788,10.8916,87.9624,20,117);
	AddStaticVehicle(530,980.7039,2060.1577,10.5856,159.6553,114,1);
	AddStaticVehicle(542,1023.1682,2019.7904,10.9840,272.4500,31,93);
	AddStaticVehicle(554,991.6675,1886.8708,11.3290,270.6092,15,32);
	AddStaticVehicle(558,984.5507,1719.9063,8.2853,270.4343,24,1);
	AddStaticVehicle(522,949.3912,1662.1198,8.4159,269.5886,6,25);
	AddStaticVehicle(541,1113.0669,1726.9880,10.4451,179.9989,22,1);
	AddStaticVehicle(521,1024.1970,1724.4652,10.3911,93.4605,92,3);
	AddStaticVehicle(506,1041.7158,1357.1357,10.5246,85.3610,7,7);
	AddStaticVehicle(500,1042.7311,1346.4717,10.9230,81.1408,28,119);
	AddStaticVehicle(496,979.9923,1080.0503,10.5293,91.2658,53,56);
	AddStaticVehicle(482,979.7035,1104.7273,10.9448,90.7615,71,71);
	AddStaticVehicle(414,1425.6675,1039.2936,10.4327,90.1854,102,65);
	AddStaticVehicle(414,1451.7877,976.0687,10.4987,0.3869,67,1);
	AddStaticVehicle(410,2004.4067,735.3056,11.0296,180.8574,9,1);
	AddStaticVehicle(418,2168.8989,695.7342,11.4583,182.7091,117,227);
	AddStaticVehicle(429,2362.0627,731.0701,11.0945,0.1727,1,3);
	AddStaticVehicle(439,2362.4011,648.3926,11.2058,358.5358,43,21);
	AddStaticVehicle(460,2358.0769,519.0576,1.7602,270.6638,17,23);
	AddStaticVehicle(493,2292.9006,518.9941,-0.2127,269.6579,36,13);
	AddStaticVehicle(496,2086.2354,658.9543,10.8917,180.3410,66,72);
	AddStaticVehicle(506,1916.4235,698.4152,10.5369,359.5925,52,52);
	AddStaticVehicle(516,1852.8835,698.9276,11.0089,92.2719,119,1);
	AddStaticVehicle(521,1413.7998,772.0428,10.3920,92.6899,87,118);
	AddStaticVehicle(533,1484.0516,787.6008,10.5294,359.4022,74,1);
	AddStaticVehicle(545,1535.0472,787.3861,10.6314,0.8390,44,96);
	AddStaticVehicle(578,1645.1521,740.4365,11.4446,357.8964,1,1);
	AddStaticVehicle(484,1628.1273,571.8071,0.1587,269.3263,66,36);
	AddStaticVehicle(477,1544.6929,2132.2334,11.1514,269.0969,101,1);
	AddStaticVehicle(480,1613.6011,2207.0527,10.5919,271.9736,4,4);
	AddStaticVehicle(479,1519.2012,2291.0112,10.6331,0.9600,49,23);
	AddStaticVehicle(419,1340.8719,2246.3386,10.6215,92.0409,21,1);
	AddStaticVehicle(462,1431.4543,2237.3440,10.6230,267.7669,3,1);
	AddStaticVehicle(401,1508.7909,2091.1387,10.6953,271.2132,39,39);
	AddStaticVehicle(439,1068.4608,2185.2996,16.6151,91.1135,25,78);
	AddStaticVehicle(426,1126.5607,2323.6711,16.4615,90.0850,7,7);
	AddStaticVehicle(421,1135.4622,2253.0496,16.6012,270.1440,30,1);
	AddStaticVehicle(419,1115.4999,2310.4092,10.6371,267.7344,33,75);
	AddStaticVehicle(561,990.2859,2307.3047,11.1294,89.9585,101,101);
	AddStaticVehicle(400,1108.1198,1903.8445,10.9125,269.1945,113,1);
	AddStaticVehicle(403,1059.6801,1916.6881,11.4272,0.6038,101,1);
	AddStaticVehicle(402,2039.0864,1160.6543,10.5033,179.5146,22,22);
	AddStaticVehicle(411,1844.4286,1209.7379,10.5596,91.1955,116,1);
	AddStaticVehicle(522,1843.6981,1255.3601,10.3902,89.6382,3,8);
	AddStaticVehicle(439,1866.8518,1179.2153,10.7348,0.1707,37,78);
	AddStaticVehicle(587,1552.6906,1025.6267,10.5356,267.4064,66,1);
	AddStaticVehicle(543,1332.6006,1159.0437,10.6290,270.0148,8,90);
	AddStaticVehicle(545,1281.1134,2545.5876,10.6315,90.4074,30,1);
	AddStaticVehicle(420,1433.6541,2608.7395,10.6772,89.2627,6,76);
	AddStaticVehicle(508,1374.0249,2644.2893,11.1956,179.4467,1,1);
	AddStaticVehicle(437,1352.3561,2647.1230,10.9443,180.4328,105,20);
	AddStaticVehicle(451,1319.5608,2697.6628,10.5268,0.7027,61,61);
	AddStaticVehicle(437,1296.4653,2646.8472,10.9536,1.1869,54,7);
	AddStaticVehicle(561,1618.5776,2834.7361,10.6343,359.5821,25,78);
	AddStaticVehicle(581,1737.6124,2780.0356,10.6454,100.8438,54,1);
	AddStaticVehicle(579,1673.0441,2696.7334,10.7646,2.8550,37,37);
	AddStaticVehicle(522,1927.4393,2729.9841,10.3924,182.5768,6,25);
	AddStaticVehicle(562,1998.1213,2758.4885,10.4822,0.3794,116,1);
	AddStaticVehicle(542,2260.1184,2737.8931,10.5638,271.1407,24,118);
	AddStaticVehicle(498,2311.9609,2763.3215,10.8880,272.1044,13,120);
	AddStaticVehicle(421,2143.1143,2807.1777,10.5765,92.5022,30,72);
	AddStaticVehicle(480,2167.2463,2750.6987,10.5948,271.0785,12,12);
	AddStaticVehicle(419,2349.0527,2578.4849,10.6135,0.1656,2,39);
	AddStaticVehicle(448,2363.0669,2531.9736,10.4173,267.6790,3,6);
	AddStaticVehicle(541,2417.8662,2529.0085,10.4450,178.9855,36,8);
	AddStaticVehicle(415,2455.1401,2531.6060,21.6458,179.4472,0,1);
	AddStaticVehicle(418,2530.6252,2535.9524,21.9679,268.5749,81,81);
	AddStaticVehicle(436,2506.2002,2515.6663,21.6411,88.9685,11,1);
	AddStaticVehicle(474,2511.0984,2394.3940,10.5828,269.3660,97,1);
	AddStaticVehicle(477,2501.1006,2131.0410,10.4987,269.4453,92,1);
	AddStaticVehicle(518,2589.0198,2166.3142,10.4839,1.1502,17,1);
	AddStaticVehicle(533,2620.0979,2086.9114,10.5281,180.6504,79,1);
	AddStaticVehicle(535,2567.6167,2059.1948,10.5846,0.8758,28,1);
	AddStaticVehicle(541,2075.6462,1312.3136,10.2966,359.4287,2,1);
	AddStaticVehicle(546,2183.6970,1878.7114,10.5448,359.9918,78,38);
	AddStaticVehicle(410,2192.2410,1856.6902,10.6209,181.3348,75,1);
	AddStaticVehicle(480,2203.4363,1787.9412,10.5034,179.6947,60,1);
	AddStaticVehicle(541,2181.5310,1821.7205,10.4451,0.6193,51,1);
	AddStaticVehicle(533,2129.1848,1810.2720,10.3810,332.9410,74,1);
	AddStaticVehicle(477,2118.6621,1892.0770,10.3763,181.2668,6,6);
	AddStaticVehicle(410,2118.6233,1910.1948,10.7688,180.4238,40,110);
	AddStaticVehicle(496,2102.4214,2066.0054,10.5366,270.8547,66,72);
	AddStaticVehicle(477,2103.5483,2089.0322,10.5741,269.2954,101,1);
	AddStaticVehicle(516,2028.6848,2155.9724,10.6248,264.3126,2,39);
	AddStaticVehicle(522,1995.4116,2185.7837,10.3813,183.3891,36,105);
	AddStaticVehicle(508,2010.5963,2137.1594,11.1969,270.0610,1,1);
	AddStaticVehicle(414,2005.9337,2059.6008,10.9941,181.8287,110,93);
	AddStaticVehicle(414,2060.3394,2237.0127,10.5447,89.3482,121,93);
	AddStaticVehicle(448,2077.0784,2226.7166,10.4142,3.1701,3,6);
	AddStaticVehicle(420,2107.7361,2206.7979,10.8238,178.2615,6,76);
	AddStaticVehicle(516,2094.5530,2206.6326,10.5904,178.8517,119,45);
	AddStaticVehicle(477,2156.2788,2188.8767,10.3516,358.4281,14,14);
	AddStaticVehicle(415,2339.1323,2114.0562,10.4512,177.1576,20,1);
	AddStaticVehicle(409,2361.3320,2170.0618,10.5251,359.3094,1,1);
	AddStaticVehicle(461,2380.3523,2018.2645,10.3403,272.1906,13,1);
	AddStaticVehicle(587,2338.7590,1943.9525,10.4102,182.1740,40,1);
	AddStaticVehicle(482,2221.3479,1944.5293,9.7951,87.2554,37,37);
	AddStaticVehicle(479,2272.5029,1953.1041,9.4899,179.0292,7,7);
	AddStaticVehicle(541,2244.7246,1997.9194,15.4282,0.8475,12,32);
	AddStaticVehicle(541,2222.4797,1936.1879,25.9241,88.7210,68,8);
	AddStaticVehicle(415,2294.6262,1952.2435,26.0251,268.4258,7,7);
	AddStaticVehicle(436,2246.8062,1939.5153,31.5463,179.6696,33,0);
	AddStaticVehicle(461,2283.6470,1975.2380,28.4011,180.9682,62,62);
	AddStaticVehicle(477,2272.6033,2326.2434,10.5272,88.5973,61,61);
	AddStaticVehicle(428,2242.5024,2231.3748,10.9010,270.8860,4,75);
	AddStaticVehicle(516,2007.5071,2263.2092,17.6074,2.4052,13,76);
	AddStaticVehicle(522,2014.7938,2244.9580,23.4848,269.4012,8,82);
	AddStaticVehicle(436,1907.2633,2290.8406,11.0000,180.4904,84,1);
	AddStaticVehicle(480,1705.0334,2242.9836,10.5941,179.6409,12,12);
	AddStaticVehicle(436,1691.1774,2131.1426,11.0800,91.2325,87,1);
	AddStaticVehicle(414,1842.6188,2090.4556,10.8907,176.3065,36,36);
	AddStaticVehicle(436,1908.1819,2078.6570,10.5695,270.3529,53,1);
	AddStaticVehicle(516,1912.8295,2158.5737,10.6165,271.8315,47,47);
	AddStaticVehicle(525,1963.4600,2171.0208,10.6913,257.1353,1,1);
	AddStaticVehicle(496,1993.2476,2058.3521,10.5367,357.2019,53,56);
	AddStaticVehicle(535,2075.9631,1677.7250,10.4351,0.1849,118,1);
	AddStaticVehicle(418,2452.3093,1357.8304,10.9134,359.7694,61,61);
	AddStaticVehicle(415,2447.5730,1327.1135,10.5908,179.6456,0,1);
	AddStaticVehicle(414,2612.0542,1429.5336,10.9140,183.7790,24,1);
	AddStaticVehicle(420,2488.5161,1534.1761,10.5240,231.4538,6,1);
	AddStaticVehicle(409,2481.3877,1544.0386,10.5123,202.9677,1,1);
	AddStaticVehicle(579,2498.4194,1676.3019,10.5524,1.3521,101,101);
	AddStaticVehicle(474,2463.0220,1676.7267,10.5831,359.3129,97,1);
	AddStaticVehicle(518,2788.6519,2431.3220,10.4912,314.8943,2,39);
	AddStaticVehicle(516,2815.1465,2406.8418,10.6541,315.8335,119,1);
	AddStaticVehicle(506,2833.4592,2309.8750,10.5247,179.7437,76,76);
	AddStaticVehicle(516,2891.3560,2379.1252,10.6230,270.9466,41,29);
	AddStaticVehicle(402,2095.8645,2410.8191,45.0503,267.7614,110,110);
	AddStaticVehicle(516,2104.4490,2396.0525,40.6341,271.3880,119,62);
	AddStaticVehicle(402,2095.8438,2398.7417,27.8898,268.8989,99,81);
	AddStaticVehicle(477,2086.5784,2416.6394,23.4231,90.8221,3,3);
	AddStaticVehicle(516,2103.9829,2419.3713,14.8978,270.8129,24,55);
	AddStaticVehicle(561,2065.8535,2479.7612,10.6989,359.7305,4,1);
	AddStaticVehicle(414,2130.8403,2514.2134,10.9140,193.6682,24,1);
	AddStaticVehicle(410,1900.4618,2437.4229,10.4740,92.5165,45,1);
	AddStaticVehicle(408,1730.6010,2336.2703,11.3685,2.6346,26,26);
	AddStaticVehicle(486,2707.1851,822.1658,10.7179,2.5507,1,1);
	AddStaticVehicle(486,2707.0010,908.6336,10.8980,176.3525,1,1);
	AddStaticVehicle(482,2697.6646,885.6911,10.3113,271.4880,71,71);
	AddStaticVehicle(554,2701.6409,828.3740,10.1758,359.8369,15,32);
	AddStaticVehicle(524,2635.2407,848.0072,6.7986,311.1720,61,27);
	AddStaticVehicle(524,2630.1240,851.0532,6.9725,315.8478,65,31);
	AddStaticVehicle(530,2687.1553,909.9475,10.4912,199.4376,111,1);
	AddStaticVehicle(530,2683.3469,908.7888,10.4567,197.7386,112,1);
	AddStaticVehicle(455,2685.8137,864.3542,10.3588,358.5818,84,58);
	AddStaticVehicle(560,2705.9065,788.8524,10.6037,359.2399,33,0);
	AddStaticVehicle(403,2873.0920,920.3176,11.3572,94.3495,28,1);
	AddStaticVehicle(403,2873.2283,913.3622,11.7676,85.7952,24,77);
	AddStaticVehicle(435,2855.4207,896.0324,11.1716,359.7548,24,77);
	AddStaticVehicle(435,2818.0835,897.6704,11.3012,359.2285,24,77);
	AddStaticVehicle(435,2827.5466,897.5560,11.2943,0.9414,24,77);
	AddStaticVehicle(530,2884.7034,941.7674,10.5161,90.4367,112,1);
	AddStaticVehicle(530,2833.1492,996.5211,10.5144,173.6816,13,1);
	AddStaticVehicle(482,2805.1533,968.8243,10.8708,178.9079,48,48);
	AddStaticVehicle(560,2817.4512,941.4572,10.4556,0.9883,9,39);
	AddStaticVehicle(578,2840.3525,994.4778,11.3743,176.8262,1,1);
	//SF
	AddStaticVehicle(526,-2076.8745,-83.3129,34.9307,180.7876,41,29); // SF 1
	AddStaticVehicle(541,-2072.6519,-83.6942,34.7890,0.3747,22,1); // SF 2
	AddStaticVehicle(492,-2225.2229,-103.5545,35.1021,89.9358,24,55); // SF 3
	AddStaticVehicle(541,-2341.0403,-123.7668,34.9374,180.1301,22,1); // SF 4
	AddStaticVehicle(482,-2488.6428,-170.2669,25.7414,178.8747,52,52); // SF 5
	AddStaticVehicle(410,-2718.8550,-137.0350,3.9904,270.5024,10,1); // SF 6
	AddStaticVehicle(541,-2686.2205,-21.9472,3.9608,359.5682,22,1); // SF 7
	AddStaticVehicle(411,-2679.5566,-22.1540,4.0478,180.0000,112,1); // SF 8
	AddStaticVehicle(445,-2630.4065,-35.0360,4.2109,359.8727,45,45); // SF 9
	AddStaticVehicle(541,-2666.4521,-34.4620,3.9610,180.5059,22,1); // SF 10
	AddStaticVehicle(526,-2796.2485,-140.3208,6.9580,89.3404,17,1); // SF 11
	AddStaticVehicle(562,-2768.4617,-312.7769,6.6971,182.8082,36,1); // SF 12
	AddStaticVehicle(541,-2756.6785,-280.8696,6.6639,359.7320,22,1); // SF 13
	AddStaticVehicle(550,-2736.3743,-295.0723,6.8308,48.7114,53,53); // SF 14
	AddStaticVehicle(567,-2783.9966,-282.1502,6.9086,0.7152,102,114); // SF 15
	AddStaticVehicle(482,-2755.2356,213.3314,7.0472,1.2440,62,62); // SF 16
	AddStaticVehicle(475,-2774.6433,244.2279,6.9921,180.6805,9,39); // SF 17
	AddStaticVehicle(480,-2745.5496,385.2240,4.0142,1.0953,6,6); // SF 18
	AddStaticVehicle(541,-2572.7200,647.8560,14.0781,270.3313,22,1); // SF 19
	AddStaticVehicle(451,-2447.0881,741.4432,34.7220,359.6217,46,46); // SF 20
	AddStaticVehicle(550,-2416.5823,741.4110,34.8317,180.5734,10,10); // SF 21
	AddStaticVehicle(541,-2429.6675,742.0748,34.6406,0.1881,22,1); // SF 22
	AddStaticVehicle(541,-2273.9995,701.7526,48.9936,180.3527,22,1); // SF 23
	AddStaticVehicle(482,-2158.0571,654.5714,52.4901,270.5590,48,48); // SF 24
	AddStaticVehicle(402,-1950.3600,585.1112,34.9565,180.2083,110,110); // SF 25
	AddStaticVehicle(475,-2214.1746,306.3302,34.8885,180.0004,17,1); // SF 26
	AddStaticVehicle(411,-2265.8096,188.5923,34.8911,269.9189,75,1); // SF 27
	AddStaticVehicle(496,-2265.4163,137.0311,34.8880,90.0727,9,14); // SF 28
	AddStaticVehicle(579,-2267.8464,73.7564,35.0956,89.3161,53,53); // SF 29
	AddStaticVehicle(411,-2089.6306,-83.8725,34.8911,179.6518,75,1); // SF 30
	AddStaticVehicle(411,-2134.8396,844.3067,69.3414,0.1003,75,1); // SF 31
	AddStaticVehicle(418,-2071.7493,1019.0012,63.0149,359.2154,81,81); // SF 32
	AddStaticVehicle(491,-2218.2183,1168.4889,55.4046,271.3566,30,72); //
	AddStaticVehicle(550,-2024.1650,1224.9045,31.4651,268.9113,7,7); // SF 34
	AddStaticVehicle(542,-1977.5365,1279.9355,6.8535,271.7593,24,118); // SF 35
	AddStaticVehicle(542,-1645.4143,1303.7295,6.7725,314.3810,24,118); // SF 36
	AddStaticVehicle(475,-1655.9478,1314.8545,6.8415,134.9341,21,1); // SF 37
	AddStaticVehicle(542,-1778.9049,1312.0806,22.3058,353.7585,13,118); // SF 38
	AddStaticVehicle(462,-1817.0144,1291.5975,40.7447,182.3954,1,2); // SF 39
	AddStaticVehicle(411,-1799.0085,1293.1219,40.8936,0.0000,12,1); //
	AddStaticVehicle(411,-1785.1637,1311.6000,50.1724,356.7197,12,1); // SF 40
	AddStaticVehicle(461,-1834.9886,1286.7771,50.0257,201.8107,37,1); // SF 41
	AddStaticVehicle(461,-1490.6340,1000.5414,6.7756,270.1638,37,1); // SF 42
	AddStaticVehicle(445,-1784.0083,622.2576,31.6470,179.9936,39,39); // SF 43
	AddStaticVehicle(445,-2141.7495,359.6075,35.1174,359.2123,39,39); // SF 44
	AddStaticVehicle(567,-2173.3042,1104.7593,79.8772,180.1860,114,1); // SF 45
	AddStaticVehicle(567,-2645.1558,1336.8116,7.0331,92.6327,114,1); // SF 46
	AddStaticVehicle(411,-2623.0266,1378.1619,6.8679,181.6837,80,1); // SF 47
	AddStaticVehicle(550,-2474.1406,1314.6051,15.0718,269.1714,62,62); // SF 48
	AddStaticVehicle(550,-2619.5996,1351.8602,6.9674,91.7634,62,62); // SF 49
	AddStaticVehicle(545,-2381.0679,1304.8556,18.3647,275.8145,44,96); // SF 50
	//LS
	AddStaticVehicle(550,1321.2450,-873.1621,39.4322,359.9999,42,42); //
	AddStaticVehicle(587,1246.6383,-1067.8333,28.8602,91.0493,43,1); //
	AddStaticVehicle(418,1281.5398,-1096.0668,26.1133,90.0027,81,81); //
	AddStaticVehicle(542,1108.5640,-1025.0365,31.6609,180.2321,45,92); //
	AddStaticVehicle(526,1097.7228,-1060.9980,29.4092,89.5516,21,1); //
	AddStaticVehicle(410,1106.6772,-933.5498,42.8525,180.1632,36,1); //
	AddStaticVehicle(445,927.8521,-1001.1241,38.0096,0.0115,39,39); //
	AddStaticVehicle(529,1086.5901,-1194.5726,17.7404,270.0048,53,53); //
	AddStaticVehicle(526,1104.2838,-1226.5359,15.6035,180.2057,33,0); //
	AddStaticVehicle(567,1275.5518,-1370.4551,13.2024,0.1506,88,64); //
	AddStaticVehicle(492,1500.7690,-1487.2163,13.3387,180.0002,81,27); //
	AddStaticVehicle(579,1550.2422,-1479.9304,13.5932,270.0010,62,62); //
	AddStaticVehicle(482,1626.2533,-1511.8846,13.7473,179.9968,52,52); //
	AddStaticVehicle(405,1695.6564,-1528.0669,13.3574,180.0003,91,1); //
	AddStaticVehicle(402,1376.2291,-1638.7961,13.3094,180.1895,30,30); //
	AddStaticVehicle(567,1793.1951,-1703.7246,13.4263,270.0003,93,64); //
	AddStaticVehicle(526,1799.7880,-1442.4272,13.1779,180.0000,2,39); //
	AddStaticVehicle(529,1995.5079,-1470.4849,13.0943,269.9824,11,11); //
	AddStaticVehicle(542,2108.0090,-1368.5424,23.7584,180.0000,31,93); //
	AddStaticVehicle(491,2229.4663,-1362.5315,23.7425,64.2026,60,72); //
	AddStaticVehicle(567,2269.4050,-1448.4927,23.7865,140.1195,97,96); //
	AddStaticVehicle(492,2088.9241,-1597.7522,13.1198,180.0036,81,27); //
	AddStaticVehicle(534,2016.2578,-1707.8545,13.2902,270.0011,42,42); //
	AddStaticVehicle(492,1975.2714,-1783.1473,13.3380,89.2861,77,26); //
	AddStaticVehicle(445,1984.1888,-1995.4966,13.4188,359.8542,34,34); //
	AddStaticVehicle(529,1747.5696,-2094.1580,13.1773,179.9985,11,11); //
	AddStaticVehicle(526,2119.9241,-1778.4880,13.1550,90.0000,37,0); //
	AddStaticVehicle(492,2274.0708,-1753.9838,13.2431,275.4337,24,55); //
	AddStaticVehicle(567,2494.4512,-1756.7789,13.3537,8.5178,97,96); //
	AddStaticVehicle(419,2395.8081,-1543.3694,23.8026,359.4033,54,75); //
	AddStaticVehicle(542,2390.9006,-1490.8199,23.5945,270.0000,24,118); //
	AddStaticVehicle(545,2433.0439,-1243.2079,23.9987,0.0338,9,96); //
	AddStaticVehicle(445,2228.3032,-1173.5991,25.6075,89.9776,35,35); //
	AddStaticVehicle(475,2205.6729,-1168.9906,25.5653,270.0056,33,0); //
	AddStaticVehicle(529,2161.5532,-1177.8425,23.4380,89.9973,15,15); //
	AddStaticVehicle(526,2147.9209,-1180.3531,23.5913,270.0000,56,29); //
	AddStaticVehicle(492,2148.1479,-1157.3401,23.6224,269.9999,28,56); //
	AddStaticVehicle(492,1999.4919,-1275.6370,23.5990,180.0000,49,59); //
	AddStaticVehicle(410,1995.6538,-1089.9061,24.2985,80.9864,10,1); //
	AddStaticVehicle(492,1770.9160,-1061.6290,23.7475,180.0000,77,26); //
	AddStaticVehicle(405,1744.5664,-1085.3002,23.8581,360.0000,75,1); //
	AddStaticVehicle(526,1748.6042,-1012.8701,23.7368,165.0000,9,39); //
	AddStaticVehicle(542,1707.7836,-1035.8131,23.6791,179.9998,113,92); //
	AddStaticVehicle(475,1675.9918,-1111.4016,23.7154,89.9991,56,29); //
	AddStaticVehicle(415,-87.3338,-1197.3420,2.1238,343.7085,-1,-1); //
	AddStaticVehicle(566,324.3331,-1809.7196,4.2539,0.6248,-1,-1); //
	AddStaticVehicle(400,331.1441,-1788.8394,4.9732,177.8066,-1,-1); //
	AddStaticVehicle(400,641.7978,-1693.8873,14.9719,352.8624,-1,-1); //
	AddStaticVehicle(405,726.0670,-1670.1516,10.3960,90.1871,-1,-1); //
	AddStaticVehicle(412,1033.5475,-1598.5168,13.2201,179.9874,-1,-1); //
	AddStaticVehicle(412,1932.9056,-1770.6252,13.2206,179.8561,-1,-1); //
	AddStaticVehicle(517,-2571.6021,632.6934,14.3141,268.8023,-1,-1); //
	AddStaticVehicle(518,-2545.7302,657.7225,14.1300,87.9588,-1,-1); //
	AddStaticVehicle(516,-2574.1572,904.5121,64.6621,269.0101,-1,-1); //
	AddStaticVehicle(533,-2549.9177,1009.6293,77.9083,88.4608,-1,-1); //
	AddStaticVehicle(533,-2402.8464,950.2206,45.0060,269.7740,-1,-1); //
	AddStaticVehicle(535,-2333.3765,991.7084,50.4680,269.8790,-1,-1); //
	AddStaticVehicle(534,-2321.6765,987.5726,50.4178,133.1057,-1,-1); //
	AddStaticVehicle(600,1464.7698,-901.9435,54.5520,359.6159,8,90); //
	AddStaticVehicle(560,1531.4030,-813.7062,71.7256,87.4675,17,1); //
	AddStaticVehicle(498,1315.5525,-873.3976,39.6464,1.0716,27,107); //
	AddStaticVehicle(445,1172.6860,-881.3290,43.1818,187.8381,39,39); //
	AddStaticVehicle(436,1138.3018,-1025.7281,31.6784,177.6305,95,1); //
	AddStaticVehicle(581,1188.7845,-1128.5820,23.5710,178.1319,75,1); //
	AddStaticVehicle(579,1319.4713,-1162.2050,23.7549,0.0091,62,62); //
	AddStaticVehicle(562,1523.1542,-1166.4609,23.6475,268.2230,113,1); //
	AddStaticVehicle(561,1629.5168,-1102.9291,23.7199,270.2454,65,79); //
	AddStaticVehicle(558,1752.8689,-1046.5405,23.5913,180.0121,30,1); //
	AddStaticVehicle(509,1991.1073,-1096.9664,24.7763,258.2765,36,1); //
	AddStaticVehicle(400,1929.2941,698.0946,10.9126,180.0986,62,1); //
	AddStaticVehicle(589,1909.9926,708.4448,10.4784,358.7848,22,22); //
	AddStaticVehicle(579,2056.5552,738.7402,11.0891,359.8127,62,62); //
	AddStaticVehicle(560,2085.8096,659.2583,10.8544,359.8970,17,1); //
	AddStaticVehicle(554,2266.1096,727.6443,11.2619,181.0523,34,30); //
	AddStaticVehicle(484,2343.9363,534.9481,0.3248,179.6722,66,36); //
	AddStaticVehicle(473,2374.5557,527.7136,-0.2392,178.4412,56,53); //
	AddStaticVehicle(451,2440.8145,654.4768,10.8123,91.1819,16,16); //
	AddStaticVehicle(468,2577.1887,717.3626,10.4881,180.8334,6,6); //
	AddStaticVehicle(402,2639.3000,747.7779,10.6521,184.5006,39,39); //
	AddStaticVehicle(603,2460.4570,921.9199,10.6589,268.6309,13,1); //
	AddStaticVehicle(585,2563.6201,1050.0374,10.4068,358.3346,15,15); //
	AddStaticVehicle(567,2395.8271,987.0301,10.6916,359.2603,99,81); //
	AddStaticVehicle(482,2198.8699,938.3305,10.9406,267.8217,85,85); //
	AddStaticVehicle(480,2162.4746,1028.9669,10.5938,89.5006,73,45); //
	AddStaticVehicle(461,2122.8369,988.1715,10.3820,359.6115,79,1); //
	AddStaticVehicle(429,1881.7460,966.8181,10.5000,269.4858,1,3); //
	AddStaticVehicle(421,1866.8370,1179.8906,10.7182,179.4595,40,1); //
	AddStaticVehicle(411,1641.3663,1311.2384,10.5474,268.9972,106,1); //
	AddStaticVehicle(587,1676.2649,1297.5291,10.5474,179.8309,40,1); //
	AddStaticVehicle(562,1685.9722,1317.0586,10.4799,177.4565,92,1); //
	AddStaticVehicle(541,1708.2363,1286.8534,10.4452,1.3736,22,1); //
	AddStaticVehicle(481,1737.8279,1238.5122,10.3337,356.1134,1,1); //
	AddStaticVehicle(477,2075.6738,1286.8561,10.4267,359.4689,36,1); //
	AddStaticVehicle(445,1942.3718,1338.8889,9.0546,359.7181,47,47); //
	AddStaticVehicle(410,2039.1691,1498.4504,10.3272,179.6613,4,1); //
	AddStaticVehicle(562,2039.1936,1110.5585,10.3318,180.8678,11,1); //
	AddStaticVehicle(550,2331.7434,1454.8792,10.6346,270.3336,7,7); //
	AddStaticVehicle(545,2279.1721,1389.3380,23.4361,0.7794,40,96); //
	AddStaticVehicle(541,2312.3108,1387.7991,42.4453,359.4360,68,8); //
	AddStaticVehicle(535,2080.5203,1785.0828,10.4358,154.5925,55,1); //
	AddStaticVehicle(529,2228.9619,1878.9348,10.4538,180.3970,62,62); //
	AddStaticVehicle(506,2185.7078,2004.4518,10.5246,91.4531,52,52); //
	AddStaticVehicle(445,2102.6602,2095.6692,10.6953,269.6107,41,41); //
	AddStaticVehicle(414,2061.6804,2238.6421,10.3512,90.2433,67,1); //
	AddStaticVehicle(411,1891.5923,2320.6755,10.5482,269.5977,116,1); //
	AddStaticVehicle(400,2152.7659,2479.7717,10.9127,270.5681,113,1); //
	AddStaticVehicle(405,2068.5610,2416.6716,14.9985,271.4984,40,1); //
	AddStaticVehicle(402,2078.7571,2413.6074,32.1519,270.4853,30,30); //
	AddStaticVehicle(527,2378.7339,2310.2285,7.8560,357.7744,76,1); //
	AddStaticVehicle(480,2564.9128,2279.6392,10.5927,88.5402,4,4); //
	AddStaticVehicle(458,2623.5991,2206.3596,10.6987,359.7183,4,1); //
	AddStaticVehicle(400,2852.7493,2375.9255,10.9126,269.2732,36,1); //
	AddStaticVehicle(603,2822.2454,2154.9382,10.6578,89.2890,45,45); //
	AddStaticVehicle(560,2602.2776,2086.1982,10.5234,0.3899,41,29); //
	AddStaticVehicle(550,2297.0967,2154.7346,10.5567,89.1389,42,42); //
	AddStaticVehicle(541,2221.7278,1932.1428,9.4923,268.7917,58,8); //
	AddStaticVehicle(411,2222.2607,1936.0377,31.5067,269.3681,80,1); //
	AddStaticVehicle(505,2217.5842,2055.9902,10.9639,270.3010,14,123); //
	AddStaticVehicle(456,2486.5352,1990.9069,10.9938,178.6897,23,1); //
	AddStaticVehicle(451,2578.2297,1976.9822,10.5309,90.4666,46,46); //
	AddStaticVehicle(565,2487.8528,1533.6223,10.3713,52.6739,11,11); //
	AddStaticVehicle(559,2363.6689,1668.5753,10.4766,268.6927,68,8); //
	AddStaticVehicle(542,1935.4955,1784.0494,18.6482,357.6896,13,118); //
	AddStaticVehicle(541,1920.3885,1943.7880,7.2188,270.4478,22,1); //
	AddStaticVehicle(535,1908.1267,2100.2432,10.5907,88.1595,31,1); //
	AddStaticVehicle(521,1588.1646,1851.4167,10.3848,359.4211,36,0); //
	AddStaticVehicle(480,1597.8646,1838.4706,10.5943,359.6252,2,2); //
	AddStaticVehicle(477,1505.3346,1999.2552,10.5779,359.8872,36,1); //
	AddStaticVehicle(436,1312.7756,1967.6284,11.0214,271.4507,83,1); //
	AddStaticVehicle(429,1086.5005,1795.0507,10.5000,359.3700,3,1); //
	AddStaticVehicle(421,1021.9849,2020.1458,11.0475,270.5167,95,1); //
	AddStaticVehicle(418,1170.3134,2113.4617,10.9134,269.8659,61,61); //
	AddStaticVehicle(409,1135.2004,2227.7832,10.6304,89.5198,1,1); //
	AddStaticVehicle(405,1032.6729,1338.2822,10.6953,91.9499,36,1); //
	AddStaticVehicle(402,1386.0475,2266.3054,10.6520,269.8043,13,13); //
	AddStaticVehicle(400,1527.7081,2214.5681,10.9127,1.2097,62,1); //
	AddStaticVehicle(541,1281.5531,2571.0627,10.4453,269.7794,60,1); //
	AddStaticVehicle(529,1431.6321,2609.6025,10.3767,269.6648,62,62); //
	AddStaticVehicle(562,1589.8864,2746.3433,10.4805,180.2556,11,1); //
	AddStaticVehicle(560,2058.5696,2754.5747,10.5255,179.9061,56,29); //
	AddStaticVehicle(554,2167.1235,2724.1550,10.9068,89.6455,45,32); //
	AddStaticVehicle(521,2507.8875,2538.0767,10.3900,271.4493,115,118); //
	AddStaticVehicle(506,2404.0720,2552.3799,21.5795,271.7907,7,7); //
	AddStaticVehicle(483,2523.9927,2397.6511,4.2028,359.5775,1,31); //
	AddStaticVehicle(606,1319.0198,1278.8761,10.8741,358.6644,0,0); //
	AddStaticVehicle(606,1315.7921,1279.0552,10.8686,358.4582,0,0); //
	AddStaticVehicle(608,1325.5009,1278.6206,11.3512,358.5863,1,1); //
	AddStaticVehicle(607,1328.9275,1278.7310,10.8799,359.0547,0,0); //
	AddStaticVehicle(607,1322.2690,1278.9979,10.8789,0.6779,0,0); //
	AddStaticVehicle(608,1328.5328,1278.5657,11.3493,357.6434,1,1); //
	AddStaticVehicle(583,1306.2284,1279.1644,10.3604,0.1259,1,1); //
	AddStaticVehicle(485,1309.6497,1278.9296,10.4757,1.3538,1,76); //
	AddStaticVehicle(607,1312.9197,1279.0320,10.8800,0.1709,0,0); //
	AddStaticVehicle(583,1282.0785,1306.8701,10.3606,89.5282,1,1); //
	AddStaticVehicle(485,1282.1715,1303.6832,10.4768,88.7748,1,73);
	AddStaticVehicle(401,752.2120,-517.4899,16.2630,180.9480,-1,-1); //
	AddStaticVehicle(415,827.7466,-558.0411,15.9598,180.1013,-1,-1); //
	AddStaticVehicle(402,647.8092,-508.1571,16.1677,93.7831,-1,-1); //
	AddStaticVehicle(403,67.5152,-272.1744,2.1829,355.4753,-1,-1); //
	AddStaticVehicle(403,91.0979,-302.4714,2.1834,0.5072,-1,-1); //
	AddStaticVehicle(404,219.3275,-175.7851,1.3121,269.8401,-1,-1); //
	AddStaticVehicle(405,167.7203,-182.8350,1.4557,267.7198,-1,-1); //
	AddStaticVehicle(506,261.5539,-288.5855,1.2825,181.2994,-1,-1); //
	AddStaticVehicle(510,344.4188,-81.6111,1.0099,9.1275,-1,-1); //
	AddStaticVehicle(410,236.8556,-35.2415,1.0825,0.1204,-1,-1); //
	AddStaticVehicle(411,329.5299,66.0441,3.1965,29.2469,-1,-1); //
	AddStaticVehicle(412,1347.2938,206.7337,19.3921,335.6638,-1,-1); //
	AddStaticVehicle(414,1367.4105,365.9546,20.6484,66.2944,-1,-1); //
	AddStaticVehicle(415,1206.7766,318.5761,19.1785,155.3443,-1,-1); //
	AddStaticVehicle(418,1303.5868,271.3451,19.4993,335.9982,-1,-1); //
	AddStaticVehicle(419,1287.1287,358.0439,19.2037,336.4708,-1,-1); //
	AddStaticVehicle(421,1401.6633,460.0606,20.0933,153.8644,-1,-1); //
	AddStaticVehicle(422,2331.1714,199.2613,26.9197,269.6050,-1,-1); //
	AddStaticVehicle(466,2261.5154,105.9614,26.9191,178.8356,-1,-1); //
	AddStaticVehicle(467,2290.2239,5.6277,26.0758,180.2131,-1,-1); //
	AddStaticVehicle(468,2158.6082,-96.1325,2.4403,117.4792,-1,-1); //
	AddStaticVehicle(474,2207.8442,-46.7324,26.5430,269.8516,-1,-1); //
	AddStaticVehicle(475,2417.9641,-43.4096,26.7856,359.6609,-1,-1); //
	AddStaticVehicle(477,2551.2087,9.8717,26.7726,93.1877,-1,-1); //
	AddStaticVehicle(478,2607.9875,34.4303,26.3654,77.6015,-1,-1); //
	AddStaticVehicle(429,-1905.2866,299.4375,40.7266,271.1195,1,2); //
	AddStaticVehicle(486,-2090.5127,242.7202,35.7732,67.5618,1,1); //
	AddStaticVehicle(524,-2052.0847,236.2621,36.4294,178.3650,61,61); //
	AddStaticVehicle(524,-2097.3774,165.2897,36.0041,178.8941,62,61); //
	AddStaticVehicle(526,-1971.3158,171.8575,27.4541,90.5855,21,1); //
	AddStaticVehicle(552,-2022.4294,90.8141,27.7670,273.7314,56,56); //
	AddStaticVehicle(552,-2022.1084,85.8614,27.7344,271.0743,26,124); //
	AddStaticVehicle(544,-2054.0122,85.2275,28.6336,176.7726,3,1); //
	AddStaticVehicle(562,-2044.6924,16.1287,34.9882,0.6688,17,1); //
	AddStaticVehicle(565,-2172.4404,-16.4813,34.8665,178.3167,62,62); //
	AddStaticVehicle(571,-2211.0591,117.1090,34.6061,88.5148,91,2); //
	AddStaticVehicle(571,-2211.0564,114.8420,34.6043,90.0477,40,35); //
	AddStaticVehicle(571,-2211.0659,112.6831,34.6042,91.1616,36,2); //
	AddStaticVehicle(571,-2211.2114,110.1175,34.6042,88.9233,91,2); //
	AddStaticVehicle(575,-2265.6167,137.1491,34.7744,91.2677,25,96); //
	AddStaticVehicle(580,-2268.5840,73.6773,34.9602,270.3372,66,66); //
	AddStaticVehicle(588,-2312.8772,149.1098,35.2060,274.0015,1,1); //
	AddStaticVehicle(588,-2337.4949,-125.0173,35.2140,359.2008,1,1); //
	AddStaticVehicle(589,-2433.1289,-163.4712,35.0151,267.6021,23,23); //
	AddStaticVehicle(602,-2482.8127,-170.1374,25.4241,176.4949,18,1); //
	AddStaticVehicle(405,-2626.7563,-54.7974,4.2109,179.4656,75,1); //
	AddStaticVehicle(409,-2646.5894,-54.1564,4.1359,359.7118,1,1); //
	AddStaticVehicle(411,-2769.1206,-281.2938,6.7661,179.8209,112,1); //
	AddStaticVehicle(415,-2734.4485,-280.8882,6.8147,179.5777,62,1); //
	AddStaticVehicle(418,-2796.3843,-171.0415,7.2823,90.8440,95,95); //
	AddStaticVehicle(419,-2796.1924,-106.7902,6.9852,272.7523,59,75); //
	AddStaticVehicle(426,-2795.9248,62.6087,6.9305,271.3257,7,7); //
	AddStaticVehicle(429,-2796.5857,224.5166,6.8713,89.0463,10,10); //
	AddStaticVehicle(443,-2620.4185,362.9298,4.9248,179.7930,40,1); //
	AddStaticVehicle(445,-2586.9109,329.4692,4.7299,89.1026,43,43); //
	AddStaticVehicle(448,-2695.9919,260.6853,4.2329,0.7726,3,6); //
	AddStaticVehicle(448,-2693.5815,260.7118,4.2329,357.3912,3,6); //
	AddStaticVehicle(448,-2691.3418,260.7585,4.2329,353.9110,3,6); //
	AddStaticVehicle(451,-2677.8833,267.3719,4.0625,178.6765,18,18); //
	AddStaticVehicle(559,-2661.7183,267.8170,3.9923,178.8301,2,1); //
	AddStaticVehicle(560,-2691.6514,204.8560,4.0407,175.6085,33,0); //
	AddStaticVehicle(561,-2614.5735,205.4324,4.6780,180.4124,54,38); //
	AddStaticVehicle(579,-2496.6853,429.9834,27.7014,138.2882,7,7); //
	AddStaticVehicle(585,-2522.4956,338.0944,34.7028,250.0221,7,7); //
	AddStaticVehicle(586,-2231.9036,305.6049,34.6372,359.2047,27,1); //
	AddStaticVehicle(602,-2206.3301,293.1322,34.9244,176.7748,34,1); //
	AddStaticVehicle(413,-1839.9712,-12.4579,15.2031,265.2178,4,1); //
	AddStaticVehicle(414,-1702.6560,6.0448,3.6471,310.6551,25,1); //
	AddStaticVehicle(455,-1576.1462,129.3286,3.9885,191.8387,77,31); //
	AddStaticVehicle(455,-1582.4906,125.2536,3.9884,188.5327,84,15); //
	AddStaticVehicle(472,-1721.2571,229.2761,0.1612,268.9090,56,15); //
	AddStaticVehicle(493,-1166.9117,376.5560,-0.2497,314.0178,36,13); //
	AddStaticVehicle(595,-1405.7300,422.6519,0.1155,269.9644,112,20); //
	AddStaticVehicle(595,-1448.9185,492.3474,0.2030,90.1008,112,20); //
	AddStaticVehicle(595,-1447.2759,497.2918,0.1109,89.4109,112,20); //
	AddStaticVehicle(595,-1444.0980,510.4056,0.0260,90.0233,112,20); //
	AddStaticVehicle(595,-1443.9596,504.1204,0.1110,88.8799,112,20); //
	AddStaticVehicle(402,-1650.1583,447.8284,7.0112,319.2690,110,110); //
	AddStaticVehicle(584,-1673.5652,438.2655,8.3191,312.2207,1,1); //
	AddStaticVehicle(609,-1886.5978,-780.4764,32.0888,91.3563,36,36); //
	AddStaticVehicle(401,-1897.8999,-833.4014,31.8027,269.6782,47,47); //
	AddStaticVehicle(405,-1887.0624,-924.0665,31.8984,91.9239,36,1); //
	AddStaticVehicle(415,-2125.7036,-944.2942,31.7965,86.5048,92,1); //
	AddStaticVehicle(421,-2149.0671,-866.3207,31.9059,88.4498,4,1); //
	AddStaticVehicle(426,-2134.4766,-772.9711,31.7666,268.7208,62,62); //
	AddStaticVehicle(429,-2398.6885,-592.7461,132.3276,306.2448,10,10); //
	AddStaticVehicle(480,-2396.9888,-611.4351,132.4235,37.2766,12,12); //
	AddStaticVehicle(510,-2503.4036,-707.4057,138.9154,352.3842,46,46); //
	AddStaticVehicle(510,-2505.0813,-707.3054,138.9283,355.9090,28,28); //
	AddStaticVehicle(510,-2506.4668,-707.1571,138.9285,9.8891,2,2); //
	AddStaticVehicle(510,-2501.8384,-707.1030,138.9282,0.0685,46,46); //
	AddStaticVehicle(582,-2531.4204,-603.0839,132.6189,359.1676,49,11); //
	AddStaticVehicle(582,-2523.9617,-602.9024,132.6215,179.3327,110,113); //
	AddStaticVehicle(488,-2521.3113,-649.7479,148.0838,174.9095,2,29); //
	AddStaticVehicle(510,-2289.0537,-1662.4202,482.3694,86.5710,6,6); //
	AddStaticVehicle(510,-2289.3201,-1664.1458,482.3164,82.3072,2,2); //
	AddStaticVehicle(510,-2289.2871,-1665.8129,482.2463,96.0941,46,46); //
	AddStaticVehicle(568,-2354.7231,-1618.5918,483.5186,250.8739,9,39); //
	AddStaticVehicle(568,-2355.7930,-1622.8237,483.5284,258.0875,21,1); //
	AddStaticVehicle(568,-2356.4692,-1627.1140,483.5407,263.1468,37,0); //
	AddStaticVehicle(568,-2352.9575,-1613.8958,483.5036,259.7654,56,29); //
	AddStaticVehicle(500,-2407.2751,-2177.6304,33.4035,270.6624,75,84); //
	AddStaticVehicle(468,-2403.3340,-2207.9131,32.9581,297.4197,53,53); //
	AddStaticVehicle(468,-2402.6841,-2209.7104,32.9581,296.3233,6,6); //
	AddStaticVehicle(468,-2403.5400,-2205.8167,32.9582,287.3441,53,53); //
	AddStaticVehicle(468,-2401.8855,-2211.3325,32.9580,294.6902,6,6); //
	AddStaticVehicle(471,-2201.7754,-2252.6169,30.1834,324.8611,103,111); //
	AddStaticVehicle(475,-2101.1057,-2231.3479,30.4290,139.6052,17,1); //
	AddStaticVehicle(478,-2057.9905,-2381.1304,30.6123,148.5339,39,1); //
	AddStaticVehicle(514,-2005.5430,-2411.3469,31.2093,313.1228,40,1); //
	AddStaticVehicle(578,-1966.5819,-2434.4182,31.2496,223.7105,1,1); //
	AddStaticVehicle(450,-1946.3502,-2474.5950,31.7529,48.6660,1,1); //
	AddStaticVehicle(455,-2009.6317,-2453.9719,31.1900,131.3624,84,15); //
	AddStaticVehicle(463,-2071.5400,-2527.3865,30.1653,319.7093,11,11); //
	AddStaticVehicle(467,-2153.3953,-2549.1726,30.3572,139.8421,68,8); //
	AddStaticVehicle(475,-2200.6392,-2504.8418,30.4200,142.3926,37,0); //
	AddStaticVehicle(482,-1545.0787,-2739.9563,48.6595,145.0930,64,64); //
	AddStaticVehicle(408,-1903.6304,-1710.1368,22.3123,297.3090,26,26); //
	AddStaticVehicle(408,-1859.5891,-1677.2780,22.3117,249.2628,26,26); //
	AddStaticVehicle(422,-1826.3866,-1647.1190,21.7329,58.1514,96,25); //
	AddStaticVehicleEx(521,2783.7288,-1940.6019,13.1170,90.6794,-1,-1,800); //
	AddStaticVehicleEx(521,2783.7288,-1940.6019,13.1170,90.6794,-1,-1,800); //
	AddStaticVehicleEx(511,-1675.7136,-229.9866,15.5179,344.0345,-1,-1,800); //
	AddStaticVehicleEx(513,-1583.9857,-247.0308,14.6921,34.2597,-1,-1,800); //
	AddStaticVehicleEx(519,-1393.1699,-222.4236,15.0668,313.3135,-1,-1,800); //
	AddStaticVehicleEx(519,-1377.1195,-240.0481,15.0669,313.4708,-1,-1,800); //
	AddStaticVehicleEx(553,-1261.6978,-85.7397,15.4751,67.9821,-1,-1,800); //
	AddStaticVehicleEx(533,1337.6671,-913.1140,35.7288,170.1674,-1,-1,800); //
	AddStaticVehicleEx(588,1174.4049,-902.3995,43.2162,186.7283,-1,-1,800); //
	AddStaticVehicleEx(550,1050.3942,-967.6219,42.5087,98.9869,-1,-1,800); //
	AddStaticVehicleEx(542,980.4270,-933.5726,41.1082,177.4799,-1,-1,800); //
	AddStaticVehicleEx(554,763.5011,-1014.9727,24.1852,173.8052,-1,-1,800); //
	AddStaticVehicleEx(481,729.6544,-1112.8131,18.6685,73.4972,-1,-1,800); //
	AddStaticVehicleEx(540,621.0927,-1255.0803,17.5750,4.4799,-1,-1,800); //
	AddStaticVehicleEx(547,579.7669,-1306.2096,13.9232,274.5305,-1,-1,800); //
	AddStaticVehicleEx(547,584.0772,-1246.4462,17.5810,18.9667,-1,-1,800); //
	AddStaticVehicleEx(550,526.7630,-1366.7356,15.8960,106.1972,-1,-1,800); //
	AddStaticVehicleEx(552,470.1840,-1650.3263,24.5302,82.9081,-1,-1,800); //
	AddStaticVehicleEx(541,479.8284,-1524.9108,19.6965,359.6523,-1,-1,800); //
	AddStaticVehicleEx(546,456.1274,-1544.8816,28.0895,179.3204,-1,-1,800); //
	AddStaticVehicleEx(535,782.6390,-1602.3501,13.1468,272.8824,-1,-1,800); //
	AddStaticVehicleEx(551,782.9595,-1607.7546,13.1869,269.9299,-1,-1,800); //
	AddStaticVehicleEx(560,874.7614,-1533.9915,13.2605,358.4325,-1,-1,800); //
	AddStaticVehicleEx(560,870.4658,-1533.6078,13.2596,0.9670,-1,-1,800); //
	AddStaticVehicleEx(536,892.8334,-1518.9302,12.8700,181.1914,-1,-1,800); //
	AddStaticVehicleEx(581,1361.7506,-1272.6487,12.9751,1.3643,-1,-1,800); //
	AddStaticVehicleEx(581,1498.5602,-1178.3302,23.6708,357.9636,-1,-1,800); //
	AddStaticVehicleEx(555,1628.8875,-1090.9771,23.5933,88.9513,-1,-1,800); //
	AddStaticVehicleEx(565,1650.4406,-1088.8876,23.5316,267.5474,-1,-1,800); //
	AddStaticVehicleEx(543,1650.8781,-1045.3107,23.7167,359.6843,-1,-1,800); //
	AddStaticVehicleEx(589,1689.8522,-1035.4951,23.5643,181.4892,-1,-1,800); //
	AddStaticVehicleEx(481,1719.3370,-996.8038,23.5881,265.4233,-1,-1,800); //
	AddStaticVehicleEx(559,1707.4235,-1036.2537,23.5646,1.5765,-1,-1,800); //
	AddStaticVehicleEx(482,1770.3820,-1061.9573,24.0769,181.7129,-1,-1,800); //
	AddStaticVehicleEx(481,2007.8311,-1091.7542,24.1566,252.0490,-1,-1,800); //
	AddStaticVehicleEx(481,2081.6377,-1121.9648,23.7346,61.2664,-1,-1,800); //
	AddStaticVehicleEx(475,2076.3562,-1201.1140,23.6237,180.8792,-1,-1,800); //
	AddStaticVehicleEx(586,2118.5066,-1261.8704,23.5110,269.4809,-1,-1,800); //
	AddStaticVehicleEx(540,2137.8586,-1288.8418,24.0808,359.5400,-1,-1,800); //
	AddStaticVehicleEx(474,2207.5217,-1313.2577,23.7475,359.1768,-1,-1,800); //
	AddStaticVehicleEx(478,2230.8677,-1332.3181,23.9845,82.9695,-1,-1,800); //
	AddStaticVehicleEx(558,2251.4714,-1415.2290,23.4566,267.3613,-1,-1,800); //
	AddStaticVehicleEx(481,2303.8665,-1526.2378,25.4490,358.6113,-1,-1,800); //
	AddStaticVehicleEx(567,2391.2681,-1487.6388,23.6926,270.7365,-1,-1,800); //
	AddStaticVehicleEx(566,2477.2603,-1522.8961,23.7704,358.6246,-1,-1,800); //
	AddStaticVehicleEx(576,2393.0046,-1543.2936,23.6017,87.8834,-1,-1,800); //
	AddStaticVehicleEx(576,2461.4475,-1547.8245,23.6110,268.5865,-1,-1,800); //
	AddStaticVehicleEx(518,2408.1309,-1718.2363,13.3417,358.1817,-1,-1,800); //
	AddStaticVehicleEx(507,2300.8042,-1762.6940,13.4815,177.4648,-1,-1,800); //
	AddStaticVehicleEx(496,2158.7878,-1804.7484,13.0965,275.2472,-1,-1,800); //
	AddStaticVehicleEx(492,2384.3176,-1646.6667,13.3133,179.1472,-1,-1,800); //
	AddStaticVehicleEx(491,2361.7708,-1672.2157,13.3027,357.3527,-1,-1,800); //
	AddStaticVehicleEx(533,2297.0562,-1644.4729,14.4801,268.8877,-1,-1,800); //
	AddStaticVehicleEx(466,2292.3015,-1678.7524,13.9514,1.1228,-1,-1,800); //
	AddStaticVehicleEx(522,2370.2803,-1928.9896,12.9471,179.5428,-1,-1,800); //
	AddStaticVehicleEx(480,2376.8301,-1888.4204,13.2348,267.8036,-1,-1,800); //
	AddStaticVehicleEx(517,2486.9358,-1953.2742,13.2817,2.6028,-1,-1,800); //
	AddStaticVehicleEx(509,2166.2805,-1652.1503,14.5963,249.2960,-1,-1,800); //
	AddStaticVehicleEx(535,2162.6262,-1691.9241,14.8482,2.9926,-1,-1,800); //
	AddStaticVehicleEx(575,2091.1580,-1577.2268,12.8423,176.7057,-1,-1,800); //
	AddStaticVehicleEx(542,2095.9429,-1813.8141,13.1261,87.8065,-1,-1,800); //
	AddStaticVehicleEx(540,2095.7910,-1820.2150,13.2451,90.4529,-1,-1,800); //
	AddStaticVehicleEx(527,2096.3813,-1792.1418,13.1043,90.5735,-1,-1,800); //
	AddStaticVehicleEx(526,2096.2229,-1798.3186,13.1526,91.2749,-1,-1,800); //
	AddStaticVehicleEx(499,2253.7209,-2019.7913,13.5388,89.7401,-1,-1,800); //
	AddStaticVehicleEx(482,2399.5422,-2010.7516,13.6711,269.5295,-1,-1,800); //
	AddStaticVehicleEx(479,2442.9319,-1938.0757,13.2102,269.5161,-1,-1,800); //
	AddStaticVehicleEx(456,2454.1328,-2115.7917,13.7228,0.4757,-1,-1,800); //
	AddStaticVehicleEx(456,2464.7930,-2115.2671,13.7230,1.0521,-1,-1,800); //
	AddStaticVehicleEx(435,2497.3518,-2116.9885,14.1885,0.7246,-1,-1,800); //
	AddStaticVehicleEx(448,2113.2737,-1790.5194,13.1514,88.8585,-1,-1,800); //
	AddStaticVehicleEx(448,2115.9836,-1790.5013,13.1498,87.2883,-1,-1,800); //
	AddStaticVehicleEx(445,1939.0265,-2093.0903,13.4358,271.8255,-1,-1,800); //
	AddStaticVehicleEx(439,1947.2095,-2136.1812,13.4417,269.8404,-1,-1,800); //
	AddStaticVehicleEx(522,1924.1945,-2126.2539,13.1522,350.3619,-1,-1,800); //
	AddStaticVehicleEx(519,1969.1454,-2639.2175,14.4660,358.7224,-1,-1,800); //
	AddStaticVehicleEx(519,1945.1746,-2637.3726,14.4657,356.1463,-1,-1,800); //
	AddStaticVehicleEx(519,1880.1238,-2629.7681,14.4710,359.4804,-1,-1,800); //
	AddStaticVehicleEx(577,1560.1218,-2492.5469,13.4711,270.3940,-1,-1,800); //
	AddStaticVehicleEx(608,1578.3875,-2487.3977,14.0857,180.3246,-1,-1,800); //
	AddStaticVehicleEx(608,1578.3875,-2487.3977,14.0857,180.3246,-1,-1,800); //
	AddStaticVehicleEx(593,1644.9767,-2444.0994,14.0107,182.7824,-1,-1,800); //
	AddStaticVehicleEx(593,1929.0446,-2286.0874,14.0049,219.1900,-1,-1,800); //
	AddStaticVehicleEx(487,1991.4167,-2391.9656,13.7238,95.5655,-1,-1,800); //
	AddStaticVehicleEx(458,1777.8977,-1908.6227,13.2662,274.5224,-1,-1,800); //
	AddStaticVehicleEx(451,1804.0530,-1929.4115,13.0944,87.9596,-1,-1,800); //
	AddStaticVehicleEx(440,1836.4316,-1832.9225,13.6968,268.7869,-1,-1,800); //
	AddStaticVehicleEx(438,1807.3389,-1693.9253,13.5526,182.4231,-1,-1,800); //
	AddStaticVehicleEx(438,1807.8503,-1707.9884,13.5507,179.8914,-1,-1,800); //
	AddStaticVehicleEx(411,1502.6327,-1737.7787,13.1890,270.1201,-1,-1,800); //
	AddStaticVehicleEx(477,1273.5011,-1819.1731,13.1380,177.6100,-1,-1,800); //
	AddStaticVehicleEx(426,1981.3802,-1995.1207,13.2952,1.8390,-1,-1,800); //
	AddStaticVehicleEx(421,2059.4170,-1903.6840,13.4294,0.0844,-1,-1,800); //
	AddStaticVehicleEx(412,2272.9338,-1916.9769,13.3856,177.9940,-1,-1,800); //
	AddStaticVehicleEx(410,2455.1670,-2013.9408,13.0899,269.4857,-1,-1,800); //
	AddStaticVehicleEx(404,2495.5337,-1952.9114,13.1650,1.0000,-1,-1,800); //
	AddStaticVehicleEx(536,2685.4385,-2016.7670,13.2866,0.1530,-1,-1,800); //
	AddStaticVehicleEx(439,2785.9045,-1990.8274,13.2787,88.8559,-1,-1,800); //
	AddStaticVehicleEx(474,2860.4045,-1888.6034,10.6936,177.8680,-1,-1,800); //
	AddStaticVehicleEx(480,2787.2979,-1875.3142,9.6027,357.7939,-1,-1,800); //
	AddStaticVehicleEx(506,2691.4758,-1835.7737,9.1456,148.0832,-1,-1,800); //
	AddStaticVehicleEx(541,2686.1250,-1673.0629,9.0668,179.0863,-1,-1,800); //
	AddStaticVehicleEx(534,2681.0422,-1672.6323,9.1445,179.0301,-1,-1,800); //
	AddStaticVehicleEx(560,2656.6633,-1711.3947,9.0182,270.9878,-1,-1,800); //
	AddStaticVehicleEx(579,2797.8606,-1576.6202,10.8610,272.5172,-1,-1,800); //
	AddStaticVehicleEx(473,2952.9324,-1494.3938,-0.5386,179.7944,-1,-1,800); //
	AddStaticVehicleEx(468,2852.9495,-1355.4052,10.7339,87.7535,-1,-1,800); //
	AddStaticVehicleEx(498,2822.0554,-1183.5521,25.2903,269.3886,-1,-1,800); //
	AddStaticVehicleEx(467,2707.2188,-1274.1455,57.9142,317.1319,-1,-1,800); //
	AddStaticVehicleEx(481,2682.3574,-1229.1300,58.0649,1.6305,-1,-1,800); //
	AddStaticVehicleEx(481,2680.8782,-1229.3264,58.0427,8.7279,-1,-1,800); //
	AddStaticVehicleEx(481,2679.3772,-1229.2302,58.0218,1.0655,-1,-1,800); //
	AddStaticVehicleEx(481,2677.8269,-1229.3972,57.9836,4.5398,-1,-1,800); //
	AddStaticVehicleEx(481,2676.4521,-1229.3495,57.9622,7.3014,-1,-1,800); //
	AddStaticVehicleEx(481,2674.6467,-1229.4385,57.9212,0.0885,-1,-1,800); //
	AddStaticVehicleEx(481,2672.5381,-1229.3739,57.8881,2.8159,-1,-1,800); //
	AddStaticVehicleEx(475,2406.2375,-1225.1290,24.3070,266.5208,-1,-1,800); //
	AddStaticVehicleEx(518,2427.5522,-1242.3878,23.8847,179.0224,-1,-1,800); //
	AddStaticVehicleEx(445,2095.9556,-1321.3970,25.1225,178.6960,-1,-1,800); //
	AddStaticVehicleEx(442,2228.7141,-1347.2295,23.8164,90.0062,-1,-1,800); //
	AddStaticVehicleEx(545,1910.2866,-1116.5155,25.4757,1.1237,-1,-1,800); //
	AddStaticVehicleEx(560,1476.3217,-1081.9355,23.4433,179.7028,-1,-1,800); //
	AddStaticVehicleEx(560,1476.3148,-1081.9332,23.4463,179.2875,-1,-1,800); //
	AddStaticVehicleEx(545,1274.9490,-1368.3168,13.1548,178.0769,-1,-1,800); //
	AddStaticVehicleEx(400,1200.6284,-1486.3759,13.5432,180.2678,-1,-1,800); //
	AddStaticVehicleEx(402,1084.8485,-1382.3212,13.6130,179.9249,-1,-1,800); //
	AddStaticVehicleEx(409,691.9416,-1219.6808,16.4826,300.8021,-1,-1,800); //
	AddStaticVehicleEx(510,1029.5387,-1354.0190,13.3224,179.4008,-1,-1,800); //
	AddStaticVehicleEx(510,1030.9041,-1360.5942,13.1825,269.0087,-1,-1,800); //
	AddStaticVehicleEx(516,912.4714,-1374.8719,13.1735,178.6143,-1,-1,800); //
	AddStaticVehicleEx(547,959.5082,-1420.2642,13.2781,0.3919,-1,-1,800); //
	AddStaticVehicleEx(462,1870.7124,-1918.8859,14.6261,183.6568,-1,-1,800); //
	AddStaticVehicleEx(578,1986.9799,-2064.4924,14.0010,268.8354,-1,-1,800); //
	AddStaticVehicleEx(589,2228.2031,-1165.5743,25.4124,269.4379,-1,-1,800); //
	AddStaticVehicleEx(600,2161.7559,-1144.4954,24.4848,87.6283,-1,-1,800); //
	AddStaticVehicleEx(605,2161.2854,-1196.6990,23.6927,272.2280,-1,-1,800); //
	AddStaticVehicleEx(401,2105.3865,-1243.8546,24.9001,177.9621,-1,-1,800); //
	AddStaticVehicleEx(500,-123.5913,1177.3962,19.8762,359.9991,-1,-1,800); //
	AddStaticVehicleEx(500,-216.7799,1213.2996,19.8452,3.0818,-1,-1,800); //
	AddStaticVehicleEx(415,-288.3897,1179.8542,19.6897,269.0528,-1,-1,800); //
	AddStaticVehicleEx(422,-361.3862,1154.2800,19.7226,246.8571,-1,-1,800); //
	AddStaticVehicleEx(463,-306.4586,1120.3629,19.2859,180.9999,-1,-1,800); //
	AddStaticVehicleEx(467,-303.4465,1032.9596,19.3338,92.3324,-1,-1,800); //
	AddStaticVehicleEx(468,-239.3930,997.4286,19.4085,179.0247,-1,-1,800); //
	AddStaticVehicleEx(471,-126.4214,966.6174,19.5845,179.7658,-1,-1,800); //
	AddStaticVehicleEx(471,-90.1255,970.4841,19.4549,357.8087,-1,-1,800); //
	AddStaticVehicleEx(483,-45.1832,1046.6921,19.7523,180.2833,-1,-1,800); //
	AddStaticVehicleEx(489,-9.6922,1116.5823,20.1670,358.7961,-1,-1,800); //
	AddStaticVehicleEx(491,80.8661,1165.9410,18.4169,1.7189,-1,-1,800); //
	AddStaticVehicleEx(496,0.1630,1231.1431,19.0678,1.7264,-1,-1,800); //
	AddStaticVehicleEx(510,-102.7661,1222.3296,19.3424,178.2706,-1,-1,800); //
	AddStaticVehicleEx(526,-83.6517,1077.4059,19.5089,0.7055,-1,-1,800); //
	AddStaticVehicleEx(543,-51.0654,1124.4851,19.5628,86.5691,-1,-1,800); //
	AddStaticVehicleEx(549,-34.1254,1165.2958,19.1422,358.2312,-1,-1,800); //
	AddStaticVehicleEx(554,13.5667,1165.9158,19.6579,1.4834,-1,-1,800); //
	AddStaticVehicleEx(567,-177.2694,1220.8102,19.6092,270.0092,-1,-1,800); //
	AddStaticVehicleEx(579,-245.3346,1075.9780,19.6909,178.9216,-1,-1,800); //
	AddStaticVehicleEx(588,-154.1772,1113.3241,19.6427,178.3681,-1,-1,800); //
	AddStaticVehicleEx(400,-215.1304,974.0182,19.3988,88.9952,-1,-1,800); //
	AddStaticVehicleEx(403,-774.9956,1436.6976,14.3946,90.3753,-1,-1,800); //
	AddStaticVehicleEx(405,-790.2911,1496.8842,22.5180,268.2026,-1,-1,800); //
	AddStaticVehicleEx(454,-533.6370,1452.0820,0.1165,177.2320,-1,-1,800); //
	AddStaticVehicleEx(460,-533.3857,1613.2842,1.7266,135.2668,-1,-1,800); //
	AddStaticVehicleEx(471,437.7050,2528.5400,16.5133,110.7185,-1,-1,800); //
	AddStaticVehicleEx(478,363.5117,2470.9446,16.4732,55.1723,-1,-1,800); //
	AddStaticVehicleEx(593,291.1182,2539.1555,17.2837,176.7412,-1,-1,800); //
	AddStaticVehicleEx(593,326.7193,2536.6118,17.2650,181.6931,-1,-1,800); //
	AddStaticVehicleEx(600,-203.7972,2595.8479,62.4132,359.6264,-1,-1,800); //
	AddStaticVehicleEx(602,-280.5696,2691.7122,62.4875,176.4788,-1,-1,800); //
	AddStaticVehicleEx(603,-207.8121,2764.1755,62.4150,179.5785,-1,-1,800); //
	AddStaticVehicleEx(414,358.6452,859.3631,20.4789,328.2830,-1,-1,800); //
	AddStaticVehicleEx(414,354.9767,861.8252,20.4998,325.8882,-1,-1,800); //
	AddStaticVehicleEx(418,312.7471,877.7521,20.4915,311.6787,-1,-1,800); //
	AddStaticVehicleEx(487,-2228.1987,2325.4087,7.7236,356.7629,-1,-1,800); //
	AddStaticVehicleEx(484,-2192.2126,2395.9475,0.0558,140.2877,-1,-1,800); //
	AddStaticVehicleEx(473,-2210.6953,2424.5330,-0.2881,44.5848,-1,-1,800); //
	AddStaticVehicleEx(473,-2228.0364,2442.1738,-0.3879,225.1004,-1,-1,800); //
	AddStaticVehicleEx(460,-2240.4651,2534.0710,1.8286,194.7477,-1,-1,800); //
	AddStaticVehicleEx(460,-2251.1211,2531.2527,1.6640,194.5390,-1,-1,800); //
	AddStaticVehicleEx(472,-2223.9529,2398.5300,0.0071,38.6054,-1,-1,800); //
	AddStaticVehicleEx(454,-2249.7441,2426.4971,0.0100,220.2853,-1,-1,800); //
	AddStaticVehicleEx(480,-2272.3157,2291.2229,4.5950,90.2144,-1,-1,800); //
	AddStaticVehicleEx(483,-2272.5034,2314.9060,4.8127,89.2897,-1,-1,800); //
	AddStaticVehicleEx(507,-2479.5657,2224.5771,4.6609,180.8023,-1,-1,800); //
	AddStaticVehicleEx(516,-2467.3831,2224.3879,4.6777,360.0000,-1,-1,800); //
	AddStaticVehicleEx(524,-2396.9792,2363.8274,5.4538,92.1038,-1,-1,800); //
	AddStaticVehicleEx(530,-2515.9456,2292.5571,4.7451,90.4615,-1,-1,800); //
	AddStaticVehicleEx(540,-2557.4587,2264.2764,4.9212,335.5964,-1,-1,800); //
	AddStaticVehicleEx(572,-2434.7593,2350.4011,4.5487,12.7276,-1,-1,800); //
	AddStaticVehicleEx(580,-2619.2048,2352.3755,8.3304,0.5581,-1,-1,800); //
	AddStaticVehicleEx(581,-1597.4016,2689.3704,54.5407,1.3614,-1,-1,800); //
	AddStaticVehicleEx(582,-1466.7117,2652.9783,55.8913,271.6309,-1,-1,800); //
	AddStaticVehicleEx(584,-1400.7321,2654.0427,56.8400,87.6520,-1,-1,800); //
	AddStaticVehicleEx(587,-1400.5681,2634.5063,55.4479,90.6240,-1,-1,800); //
	AddStaticVehicleEx(600,-1447.1641,2585.1614,55.4799,181.0189,-1,-1,800); //
	AddStaticVehicleEx(605,-1474.2322,2541.3359,55.5851,334.6449,-1,-1,800); //
	AddStaticVehicleEx(604,-1448.2561,2556.4714,55.4767,264.8961,-1,-1,800); //
	AddStaticVehicleEx(400,-1527.9260,2644.1108,55.9283,90.5443,-1,-1,800); //
	AddStaticVehicleEx(413,-1566.9855,2640.2004,55.8155,271.4250,-1,-1,800); //
	return 1;
}

stock LoadRefuel()
{
	new q[128];
	format(q,128,"SELECT * FROM refuel");
	mysql_query(q);
	mysql_store_result();
	for(new i=mysql_retrieve_row();i<mysql_num_rows();i++)
	{
	    new field[4][32];
	    mysql_fetch_row_format(q,"|");
		explode(q,field,"|");
		refuelcp[i][0]=strval(field[1]);
		refuelcp[i][1]=strval(field[2]);
		refuelcp[i][2]=strval(field[3]);
		cpfuel[i][0]=random(500);
		cpfuel[i][1]=random(500);
		format(String,128,"{0066CC}Petrol: {FF0000}%d\n\n{0066CC}Diesel: {FF0000}%d",cpfuel[i][0],cpfuel[i][1]);
		fuelcp[i]=CreateDynamic3DTextLabel(String,0xFFFFFFFF,strval(field[1]),strval(field[2]),strval(field[3])+2,10);
	}
	mysql_free_result();
	print("loaded gas stations");
	return 1;
}

stock explode(const sSource[], aExplode[][], const sDelimiter[] = " ", iVertices = sizeof aExplode, iLength = sizeof aExplode[]) // Created by Westie
{
	new
		iNode,
		iPointer,
		iPrevious = -1,
		iDelimiter = strlen(sDelimiter);

	while(iNode < iVertices)
	{
		iPointer = strfind(sSource, sDelimiter, false, iPointer);

		if(iPointer == -1)
		{
			strmid(aExplode[iNode], sSource, iPrevious, strlen(sSource), iLength);
			break;
		}
		else
		{
			strmid(aExplode[iNode], sSource, iPrevious, iPointer, iLength);
		}

		iPrevious = (iPointer += iDelimiter);
		++iNode;
	}
	return iPrevious;
}

stock fuelvehicles()
{
	for(new i;i<MAX_VEHICLES;i++)
	{
		fuel[i] = GetCapacity(GetVehicleModel(i));
		if(IsBike(GetVehicleModel(i)))
		{
			SetVehicleParamsEx(i,1,-1,-1,-1,-1,-1,-1);
		}
	}
	return 1;
}

forward startengine(playerid);
public startengine(playerid)
{
    new chance=random(5);
	if(chance == 3) return scm(playerid,0xFF0000FF,"The engine failed to {FFFFFF}start{FF0000}. Please try again.");
	vid = GetPlayerVehicleID(playerid);
	SetVehicleParamsEx(vid,1,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vid,1,lights,alarm,doors,bonnet,boot,objective);
	return 1;
}

stock LoadMap()
{
	new query[128],tmp;
	format(query,128,"SELECT * FROM map");
	mysql_query(query);
	mysql_store_result();
	tmp=mysql_num_rows();
	for(new i=mysql_retrieve_row();i<tmp;i++)
	{
	    new field[6][32];
	    mysql_fetch_row_format(query , "|");
	    explode(query , field, "|");
	    new Float:x,Float:y,Float:z,t;
	    x=strval(field[1]);
	    y=strval(field[2]);
	    z=strval(field[3]);
	    t=strval(field[4]);
	   	CreateDynamicMapIcon(x,y,z,t,-1,-1,-1,-1,100.0);
	}
	print("loaded map icons");
	mysql_free_result();
	return 1;
}


stock IsNearRefuelCenter(playerid)
{
	if(GetPVarInt(playerid,"crefuel") == -1) 
	{
		for(new i;i<sizeof(refuelcp);i++)
		{
			if(IsPlayerInRangeOfPoint(playerid,4,refuelcp[i][0],refuelcp[i][1],refuelcp[i][2]))
			SetPVarInt(playerid,"crefuel",i);
			return i;
		}
	}
	new i=GetPVarInt(playerid,"crefuel");
	if(IsPlayerInRangeOfPoint(playerid,4,refuelcp[i][0],refuelcp[i][1],refuelcp[i][2]) < 4) return i;
	SetPVarInt(playerid,"crefuel",-1);
	return -1;
}

stock refuel(playerid)
{
	new check=IsNearRefuelCenter(playerid);
	if(check == -1) return 1;
	if(!IsPlayerInAnyVehicle(playerid)) return 1;
	if(fuel[GetPlayerVehicleID(playerid)] == 100) return scm(playerid,0xFF0000FF,"The fuel tank of your vehicle is full.");
	if(GetPlayerMoney(playerid) < 8) return scm(playerid,0xFF0000FF,"You dont have enough money.");
	GetVehicleParamsEx(GetPlayerVehicleID(playerid),engine,lights,alarm,doors,bonnet,boot,objective);
	if(engine == 1)
	{
	    scm(playerid,0xFFFF00FF,"You cannot refuel when the engine is on.");
	    return 1;
	}
	new v=GetPlayerVehicleID(playerid),f;
	f=fuel[v];
	if(f < 97)
	{
		if(IsPetrolVeh(GetPlayerVehicleID(playerid)) && cpfuel[check][0] < 3) return scm(playerid,red,"Theres not enough petrol in this gas station.");
	    if(IsDesielVeh(GetPlayerVehicleID(playerid)) && cpfuel[check][1] < 3) return scm(playerid,red,"Theres not enough desiel in this gas station.");
        if(IsPetrolVeh(GetPlayerVehicleID(playerid))) cpfuel[check][0]=cpfuel[check][0]-3;
		if(!IsPetrolVeh(GetPlayerVehicleID(playerid))) cpfuel[check][1]=cpfuel[check][1]-3;
		format(String,128,"{FFCC66}Petrol: {FF0000}%d\n\n{FF66CC}Diesel: {FF0000}%d",cpfuel[check][0],cpfuel[check][1]);
		UpdateDynamic3DTextLabelText(fuelcp[check],0xFFFFFF,String);
		f=fuel[v]+3;
	    GivePlayerCash(playerid, -8);
	    fuel[v]=f;
		format(String,128,"Fuel: %d", fuel[v]);
		PlayerTextDrawSetString(playerid,fueltd, String);
	}
	if(fuel[GetPlayerVehicleID(playerid)] > 97 && fuel[v] < 100)
	{
	    if(IsPetrolVeh(GetPlayerVehicleID(playerid)) && cpfuel[check][0] < 3) return scm(playerid,red,"Theres not enough petrol in this gas station.");
	    if(IsDesielVeh(GetPlayerVehicleID(playerid)) && cpfuel[check][1] < 3) return scm(playerid,red,"Theres not enough desiel in this gas station.");
        if(IsPetrolVeh(GetPlayerVehicleID(playerid))) cpfuel[check][0]=cpfuel[check][0]-3;
		if(!IsPetrolVeh(GetPlayerVehicleID(playerid))) cpfuel[check][1]=cpfuel[check][1]-3;
		new tmp;
		tmp=GetCapacity(GetPlayerVehicleID(playerid)) - fuel[GetPlayerVehicleID(playerid)];
		fuel[GetPlayerVehicleID(playerid)]=fuel[GetPlayerVehicleID(playerid)]+tmp;
		GivePlayerCash(playerid, -8);
		format(String,128,"{FFCC66}Petrol: {FF0000}%d\n\n{FF66CC}Diesel: {FF0000}%d",cpfuel[check][0],cpfuel[check][1]);
		UpdateDynamic3DTextLabelText(fuelcp[check],0xFFFFFF,String);
		format(String,128,"Fuel: %d", fuel[v]);
		PlayerTextDrawSetString(playerid,fueltd, String);
		SendClientMessage(playerid,red,"The fuel tank of your vehicle is now full.");
  		return 1;
	}
	return 1;
}

stock IsPetrolVeh(v)
{
	new mdl=GetVehicleModel(v);
	if(
	mdl == 401 || mdl == 404 || mdl == 405 || mdl == 410 || mdl == 412 || mdl == 420 || mdl == 419 || mdl == 421 || mdl == 422 || mdl == 426 || mdl == 436 || mdl == 438 ||
 	mdl == 439 || mdl == 440 || mdl == 466 || mdl == 480 || mdl == 516 || mdl == 529 || mdl == 542 || mdl == 555 || mdl == 575 || mdl == 605 || mdl == 467 || mdl == 482 ||
	mdl == 517 || mdl == 537 || mdl == 543 || mdl == 558 || mdl == 576 || mdl == 468 || mdl == 491 || mdl == 492 || mdl == 496 || mdl == 500 || mdl == 507 || mdl == 518 ||
	mdl == 521 || mdl == 523 || mdl == 526 || mdl == 527 || mdl == 533 || mdl == 534 || mdl == 335 || mdl == 335 || mdl == 540 || mdl == 546 || mdl == 547 || mdl == 549 ||
	mdl == 550 || mdl == 551 || mdl == 559 || mdl == 565 || mdl == 566 || mdl == 567 || mdl == 580 || mdl == 585 || mdl == 587 || mdl == 604) return 1;
	return 0;
}

stock IsDesielVeh(v)
{
    if(!IsPetrolVeh(v)) return 1;
	return 0;
}

stock GetCapacity(vehicleid)
{
	new mdl=GetVehicleModel(vehicleid);
	if(IsBike(mdl)) return 0;
	if(IsHeli(mdl)) return 75;
	if(IsPlane(mdl)) return 150;
	if(IsMotorBike(mdl)) return 50;
	if(IsFastCar(mdl)) return 120;
	return 100;
}

stock IsFastCar(vehicleid)
{
	new VehicleModel=GetVehicleModel(vehicleid);
    if(VehicleModel == 402 || VehicleModel == 411 || VehicleModel == 415 || VehicleModel == 429 ||
	   VehicleModel == 434 || VehicleModel == 451 || VehicleModel == 477 || VehicleModel == 480 ||
	   VehicleModel == 494 || VehicleModel == 502 || VehicleModel == 503 || VehicleModel == 506 ||
	   VehicleModel == 522 || VehicleModel == 541 || VehicleModel == 560 || VehicleModel == 603) return 1; // Sport car
	return 0;
}

stock resetvars(playerid)
{
	SetPVarInt(playerid, "crefuel",-1);
	job[playerid] = 0;
	org[playerid] = 0;
	Money[playerid] = 0;
	admin[playerid] = 0;
	vip[playerid]=0;
	dlic[playerid]=0;
	vipcar[playerid]=0;
	req[playerid]=0;
	leader[playerid]=0;
	return 1;
}

stock GivePlayerCash(playerid, amount)
{
	ResetPlayerMoney(playerid);
	Money[playerid]+=amount;
	GivePlayerMoney(playerid, Money[playerid]);
	return 1;
}

stock GetPlayerCash(playerid) 
{
	return Money[playerid];
}

stock LoadJobs()
{
	fjcp=CreateDynamicCP(285.3521,1425.9495,10.5859,1.0,0,0,-1,100.0);
	fjvehs[0]=AddStaticVehicle(524,282.7017,1455.4984,11.5180,89.2696,0,1); // fveh
	fjvehs[1]=AddStaticVehicle(524,282.6774,1461.2642,11.5152,90.4342,0,1); // fveh
	fjvehs[2]=AddStaticVehicle(524,282.8173,1449.5874,11.5181,91.5803,0,1); // fveh
	fjvehs[3]=AddStaticVehicle(524,283.0300,1444.0322,11.5159,90.5346,0,1); // fveh
	mjvehs[0]=AddStaticVehicleEx(525,-1883.97961426,-1640.63403320,21.73999977,181.99993896,-1,-1,15); //Tow Truck
	mjvehs[1]=AddStaticVehicleEx(525,-1892.99182129,-1641.05102539,21.73999977,181.99853516,-1,-1,15); //Tow Truck
	mjvehs[2]=AddStaticVehicleEx(525,-1834.45300293,-1638.36853027,21.73999977,180.00000000,-1,-1,15); //Tow Truck
	mjvehs[3]=AddStaticVehicleEx(525,-1827.91015625,-1638.55627441,21.73999977,180.00000000,-1,-1,15); //Tow Truck
	mgcp=CreateDynamicCP(-1860.4327,-1611.0386,21.4881,4.0,0,0,-1,100.0);
	mjcp=CreateDynamicCP(-1888.5319,-1642.0157,21.7500,1.0,0,0,-1,100);
	tjcp=CreateDynamicCP(1743.1898,-1863.4309,13.5751,1.0,0,0,-1,100);
	tjvehs[0]=AddStaticVehicle(420,1749.2529,-1859.7515,13.2704,271.1065,6,6); // taxi 1
	tjvehs[1]=AddStaticVehicle(420,1737.0516,-1859.9260,13.2720,271.0742,6,6); // taxi 2
	tjvehs[2]=AddStaticVehicle(420,1763.7013,-1859.4799,13.2718,270.3394,6,6); // taxi 3
	tjvehs[3]=AddStaticVehicle(438,1770.7509,-1859.3623,13.4924,270.9401,6,6); // cab 1
	tjvehs[4]=AddStaticVehicle(438,1777.8868,-1859.2908,13.4956,270.2206,6,6); // cab 2
	tjvehs[5]=AddStaticVehicle(438,1788.8846,-1859.3545,13.4931,271.2159,6,6); // cab 3
	trshcp=CreateDynamicCP(-2130.0718,-188.3774,35.3203,1.0,0,0,-1,100);
	trshvehs[0]=AddStaticVehicle(408,-2123.6453,-199.6926,35.8611,179.6025,0,1); // trash 1
	trshvehs[1]=AddStaticVehicle(408,-2114.4351,-198.8337,35.8647,181.7618,0,1); // trash 2
	trshvehs[2]=AddStaticVehicle(408,-2102.3960,-198.6151,35.8532,178.7317,0,1); // trash 3
	trshvehs[3]=AddStaticVehicle(408,-2146.0430,-202.9311,35.8811,269.1339,0,1); // trash 5
	trshvehs[4]=AddStaticVehicle(408,-2146.2498,-187.7718,35.8686,269.9481,0,1); // trash 6
	CreateDynamic3DTextLabel("Mechanic-Garage",-1,-1862.7615,-1630.3010,21.8849,100.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,0,0,-1,100);
	return 1;
}

stock IsJobVeh(v)
{
	if(v == fjvehs[0] || v == fjvehs[1] || v == fjvehs[2] || v == fjvehs[3]) return 1;
	if(v == mjvehs[0] || v == mjvehs[1] || v == mjvehs[2] || v == mjvehs[3]) return 2;
	if(v == tjvehs[0] || v == tjvehs[1] || v == tjvehs[2] || v == tjvehs[3]) return 3;
	if(v == tjvehs[4] || v == tjvehs[5]) return 3;
	if(v == trshvehs[0] || v == trshvehs[1] || v == trshvehs[2] || v == trshvehs[3] || v == trshvehs[4]) return 4;
	return 0;
}

stock CheckOrgExists(id)
{
	if(strlen(orgdata[id][oname]) > 1) return 1;
	else return 0;
}

stock updateorgdata(id)
{
	new str[512];
	format(str,512,"UPDATE orgs SET oname='%s', skin1=%d, skin2=%d, skin3=%d, wpn1=%d, wpn2=%d, ocolour=%d, type=%d WHERE orgid=%d",\
	orgdata[id][oname],orgdata[id][skin1],orgdata[id][skin2],orgdata[id][skin3],orgdata[id][wpn1],orgdata[id][wpn2],orgdata[id][ocolour],orgdata[id][otype],id);
	format(str,512,"UPDATE orgs SET cpx='%s', cpy=%d, cpz=%d, intx=%d, inty=%d, intz=%d, interior=%d, memcount=%d, ammo1=%d, ammo2=%d, leader='%s' WHERE orgid=%d",\
	orgdata[id][cpx],orgdata[id][cpy],orgdata[id][cpz],orgdata[id][intx],orgdata[id][inty],orgdata[id][intz],orgdata[id][interior],\
	orgdata[id][memcount],orgdata[id][ammo1],orgdata[id][ammo2],orgdata[id][oleader],id);
	return 1;
}	

stock updateorgint(orgid, field[], data)
{
	format(String, 128, "UPDATE orgs SET `%s`=%d WHERE orgid=%d",field,data,orgid);
	mysql_query(String);
	return 1;
}

stock updateorgflt(orgid, field[], Float:data)
{
	format(String, 128, "UPDATE orgs SET `%s`=%f WHERE orgid=%d",field,data,orgid);
	mysql_query(String);
	return 1;
}	

stock updateorgstr(orgid, field[], data[])
{
	format(String, 128, "UPDATE orgs SET `%s`='%s' WHERE orgid=%d",field,data,orgid);
	mysql_query(String);
	return 1;
}	

stock getocolor(id)
{
	/*format(String,128,"SELECT ocolour FROM orgs WHERE orgid=%d",id);
	mysql_query(String);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(String,"|");
	explode(String,field,"|");
	mysql_free_result();
	return strval(field[0]);*/
	return orgdata[id][ocolour];
}

stock getoname(orgid)
{
	return orgdata[orgid][oname];
}

stock LoadOstats(playerid)
{
	org[playerid]=getintdata(playerid,"users","org");
	req[playerid]=getintdata(playerid,"users","req");
	return 1;
}

stock getomemcnt(orgid)
{
	return orgdata[orgid][memcount];
}

stock LoadOcps()
{
	new query[256],tmp;
    format(query,sizeof(query),"SELECT ID,CPX,CPY,CPZ FROM `orgs` ORDER BY orgid");
    mysql_query(query);
    mysql_store_result();
    tmp=mysql_num_rows();
	for(new i=mysql_retrieve_row();i<tmp;i++)
	{
		new field[4][128];
		if(mysql_num_rows() == 0) continue;
		mysql_fetch_row_format(query, "|");
		explode(query, field, "|");
		new cpid,Float:x,Float:y,Float:z;
		x=strval(field[1]);
		y=strval(field[2]);
		z=strval(field[3]);
		cpid=CreateDynamicCP(x,y,z,1.0,0,0,-1,100.0);
		corg[cpid]=strval(field[0]);
    }
	mysql_free_result();
	return print("loaded faction checkpoints");
}

stock Log(log,msg[])
{
	if(log == 1)
	{
	    for(new i;i<MAX_PLAYERS;i++)
	    {
	        if(admin[i] != 0)
	        {
	            scm(i,0xA9C4E4FF,msg);
	        }
	 	}
	}
	return 1;
}

stock CreateDCones(playerid)
{
	for(new i,s=sizeof(dcones);i<s;i++)
	{
		coneobjs[i]=CreateDynamicObject(1238,dcones[i][0],dcones[i][1],dcones[i][2],0,0,0,0,0,playerid,200);
	}
	dteststatus=playerid;
	coneshit = 0;
	return 1;
}

stock DestroyDCones()
{
	for(new i,s=sizeof(coneobjs);i<s;i++)
	{
		DestroyDynamicObject(coneobjs[i]);
	}
	return 1;
}

stock StringContainsIP(string[])
{
    new
        dotCount
    ;
    for(new i; string[i] != EOS; ++i)
    {
        if(('0' <= string[i] <= '9') || string[i] == '.' || string[i] == ':')
        {
            if((string[i] == '.') && (string[i + 1] != '.') && ('0' <= string[i - 1] <= '9'))
            {
                ++dotCount;
            }
            continue;
        }
    }
    return (dotCount > 2);
}

stock ColouredText(text[])
{
    new
        pos = -1,
        string[(128 + 16)]
    ;
    strmid(string, text, 0, 128, (sizeof(string) - 16));

    while((pos = strfind(string, "!", true, (pos + 1))) != -1)
    {
        new
            i = (pos + 1),
            hexCount
        ;
        for( ; ((string[i] != 0) && (hexCount < 6)); ++i, ++hexCount)
        {
            if(!(('a' <= string[i] <= 'f') || ('A' <= string[i] <= 'F') || ('0' <= string[i] <= '9')))
            {
                break;
            }
        }
        if((hexCount == 6) && !(hexCount < 6))
        {
            string[pos] = '{';
            strins(string, "}", i);
        }
    }
    return string;
}

stock dtesttimer(playerid)
{
	if(dteststatus == playerid)
	{
		scm(playerid,-1,"You took too long to complete the test.");
		coneshit = 0;
		DestroyDCones();
		SetPlayerPos(-2031.0657,-118.2214,1035.1719);
		SetPlayerInterior(playerid, 3);
  		SetVehicleToRespawn(dscar);
		dteststatus=-1;
	}
	return 1;
}

stock OnPlayerEnterDCP(playerid, cpid)
{
    if(cpid < 9)
	{
	    new Float:p[3],Float:q[3];
	    GetDCPcoords(drivingtcp,p[0],p[1],p[2]);
	    GetDCPcoords(drivingtcp+1,q[0],q[1],q[2]);
	    playerdcp=CreateDynamicRaceCP(0,p[0],p[1],p[2],q[0],q[1],q[2],4,0,0,playerid,100);
	}
	if(cpid == 9)
	{
		new Float:p[3],Float:q[3];
	    GetDCPcoords(drivingtcp,p[0],p[1],p[2]);
	    GetDCPcoords(drivingtcp+1,q[0],q[1],q[2]);
	    playerdcp=CreateDynamicRaceCP(1,p[0],p[1],p[2],q[0],q[1],q[2],4,0,0,playerid,100);
	}
	if(cpid == 10)
	{
	    SetVehicleParamsForPlayer(dscar,playerid,0,1);
	    format(String,128,"You have hit %d cones.",coneshit);
	    scm(playerid,0xFFCC00FF,"Now please turn off the engine and get back inside the room.");
	    scm(playerid,-1,String);
		DestroyDCones();
	}
	return 1;
}

stock GetDCPcoords(cpid, &Float:x, &Float:y, &Float:z)
{
	format(String,128,"SELECT X,Y,Z FROM drive WHERE ID=%d",cpid);
	mysql_query(String);
	mysql_store_result();
	mysql_fetch_row_format(String,"|");
	new p[3][32];
	explode(String,p,"|");
	x=strval(p[0]);
	y=strval(p[1]);
	z=strval(p[2]);
	mysql_free_result();
	return 1;
}

stock LoadOvehs()
{
	new query[128];
    format(query,128,"SELECT * FROM `orgvehs`");
    mysql_query(query);
    mysql_store_result();
    new t=mysql_num_rows();
	for(new i=mysql_retrieve_row();i<t;i++)
        {
            new field[13][128],c1,c2;
            mysql_fetch_row_format(query, "|");
            explode(query, field, "|");
            new mdl,vidid,Float:x,Float:y,Float:z,Float:r;
            mdl=strval(field[1]);
            x=strval(field[2]);
            y=strval(field[3]);
            z=strval(field[4]);
            r=strval(field[5]);
            c1=strval(field[6]);
            c2=strval(field[7]);
            vidid=CreateVehicle(mdl,x,y,z+0.2,r,c1,c2,-1);
            vorg[vidid]=strval(field[0]);
            orgvid[vidid]=strval(field[8]);
  		}
	mysql_free_result();
	return print("loaded faction vehicles");
}