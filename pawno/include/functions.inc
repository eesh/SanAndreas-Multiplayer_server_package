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
	format(String, 128, "SELECT %s FROM %s WHERE Name='%s'",table,field,getname(playerid));
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
	format(String, 128, "SELECT %s FROM %s WHERE Name='%s'",table,field,getname(playerid));
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
	format(String, 128, "SELECT %s FROM %s WHERE Name='%s'",table,field,getname(playerid));
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
	return mysql_connect(SQL_HOST, SQL_USER, SQL_USER, SQL_PASSWORD);
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