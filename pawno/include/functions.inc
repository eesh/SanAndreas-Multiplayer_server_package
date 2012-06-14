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

stock getfltdata(playerid, table[], field[])
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
	printf("%d",getintdata(playerid, "users", "uID"));
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
		ShowPlayerDialog(playerid,1,DIALOG_STYLE_PASSWORD,"Login",String,"Login","Quit");
	}
	Logged[playerid] = 1;
	if(GetPVarInt(playerid,"justreg") == 1) return 1;
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