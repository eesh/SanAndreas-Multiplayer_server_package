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
*/
	
	
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

stock PointToPoint(Float:x, Float:y, Float:z, Float:x1, Float:x2, Float:x3)
{
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x)),2)+floatpower(floatabs(floatsub(y2,y)),2)+floatpower(floatabs(floatsub(z2,z)),2));
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
	Logged[playerid] = 1;
	if(GetPVarInt(playerid,"justreg") == 1) return 1,SetPVarInt(playerid,"justreg",0);
	scm(playerid,COLOR_GREEN,"Welcome back! You have successfully logged in.");
	return 1;
}

stock RegisterPlayer(playerid,pass[])
{
	format(String,128,"INSERT INTO users (Name,Password) VALUES ('%s',md5('%s'))",getname(playerid),pass);
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
	return 1;
}

stock ServerInit()
{
	LVarea=CreateDynamicArea(2989.536, -572.2159, 2966.18, 490.4708);
	LSarea=CreateDynamicArea(2977.858, -537.1823, 443.7593, -2954.502);
	SFarea=CreateDynamicArea( -595.5717, -2977.858, 2977.858, -2942.825);
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
		PlayerTextDrawShow(playerid, mphtd);
		PlayerTextDrawShow(playerid, fueltd);
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_NONE && GetPlayerState(playerid) == PLAYER_STATE_WASTED) return hidetextdraws(playerid);
	return 1;
}

stock hidetextdraws(playerid)
{
	PlayerTextDrawHide(playerid, loctd);
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		PlayerTextDrawHide(playerid, mphtd);
		PlayerTextDrawHide(playerid, fueltd);
	}
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
	if(mph < 25)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawShow(playerid, sl2);
		PlayerTextDrawHide(playerid, sl3);
		PlayerTextDrawHide(playerid, sl4);
		PlayerTextDrawHide(playerid, sl5);
	}
	if(mph < 50)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawShow(playerid, sl2);
		PlayerTextDrawShow(playerid, sl3);
		PlayerTextDrawHide(playerid, sl4);
		PlayerTextDrawHide(playerid, sl5);
	}
	if(mph < 75)
	{
		PlayerTextDrawShow(playerid, sl1);
		PlayerTextDrawShow(playerid, sl2);
		PlayerTextDrawShow(playerid, sl3);
		PlayerTextDrawHide(playerid, sl4);
		PlayerTextDrawHide(playerid, sl5);
	}
	if(mph < 100)
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