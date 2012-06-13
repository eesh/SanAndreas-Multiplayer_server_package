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