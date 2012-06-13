#if defined _gets_included
    #endinput
#endif
#define _gets_included

stock getjob(playerid)
{
	return playerid;
}

stock getjname(playerid)
{
	new q[128];
	format(q,128,"SELECT `name` FROM `jobs` WHERE ID=%d",playerid);
	mysql_query(q);
	mysql_store_result();
	new name[64],field[1][64];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(name,64,"%s",field[0]);
	mysql_free_result();
	return name;
}


stock getorg(id)
{
	new q[128];
	new n[32];
	GetPlayerName(id,n,32);
	format(q,128,"SELECT org FROM ostats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new value,field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	value=strval(field[0]);
	mysql_free_result();
	return value;
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


stock GetVehicleModelIDFromName(name[])
{
	for(new i = 0; i < 211; i++)
	{
	if ( strfind(VehicleNames[i], name, true) != -1 )
	return i + 400;
	}
	return -1;
}


stock GetHDetails(hid,&Float:x,&Float:y,&Float:z,&in)
{
	new q[128];
	format(q,128,"SELECT * FROM houses WHERE ID=%d",hid);
	mysql_query(q);
	mysql_store_result();
	new field[9][32];
	mysql_fetch_row_format(q, "|");
	explode(q,field,"|");
	x=strval(field[2]);
	y=strval(field[3]);
	z=strval(field[4]);
	in=strval(field[8]);
	mysql_free_result();
	return 1;
}


stock GetHEDetails(hid,&Float:x,&Float:y,&Float:z)
{
	new q[128];
	format(q,128,"SELECT * FROM houses WHERE ID=%d",hid);
	mysql_query(q);
	mysql_store_result();
	new field[8][32];
	mysql_fetch_row_format(q, "|");
	explode(q,field,"|");
	x=strval(field[5]);
	y=strval(field[6]);
	z=strval(field[7]);
	mysql_free_result();
	return 1;
}

stock getowner(id)
{
	new q[128];
	format(q,128,"SELECT owner FROM houses WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getoleader(id)
{
	new q[128];
	format(q,128,"SELECT Name FROM omem WHERE org=%d AND leader=1",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getomemcnt(id)
{
	new q[128];
	format(q,128,"SELECT * FROM omem WHERE org=%d",id);
	mysql_query(q);
	mysql_store_result();
	new howner;
	howner=mysql_num_rows()-1;
	mysql_free_result();
	return howner;
}

stock getbowner(id)
{
	new q[128];
	format(q,128,"SELECT owner FROM biz WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getrenter(id)
{
	new q[128];
	format(q,128,"SELECT renter FROM houses WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],renter[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(renter,32,"%s",field[0]);
	mysql_free_result();
	return renter;
}

stock gethouseprice(id)
{
	new q[128];
	format(q,128,"SELECT price FROM houses WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],cost;
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	cost=strval(field[0]);
	mysql_free_result();
	return cost;
}

stock gethouse(id)
{
	new q[128];
	new n[32];
	GetPlayerName(id,n,32);
	format(q,128,"SELECT house FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new value,field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	value=strval(field[0]);
	mysql_free_result();
	return value;
}

stock getbiz(id)
{
	new q[128];
	new n[32];
	GetPlayerName(id,n,32);
	format(q,128,"SELECT biz FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new value,field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	value=strval(field[0]);
	mysql_free_result();
	return value;
}

stock updatehouses(name[],inputtext[])
{
	new ss[128];
	format(ss, sizeof(String), "UPDATE houses SET owner='%s' WHERE owner='%s'",inputtext,name);
	mysql_query(ss);
	new sss[128];
	format(sss, sizeof(String), "UPDATE houses SET renter='%s' WHERE renter='%s'",inputtext,name);
	mysql_query(sss);
	return 1;
}

stock getpincode(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT pin FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new pin=strval(field[0]);
	mysql_free_result();
	return pin;
}

stock getrkey(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT rkey FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new pin=strval(field[0]);
	mysql_free_result();
	return pin;
}


stock getbal(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT balance FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}

stock getbans(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT bankans FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new ans[32];
	format(ans,32,"%s",field[0]);
	mysql_free_result();
	return ans;
}


stock getname(playerid)
{
        GetPlayerName(playerid, pName, sizeof(pName));
        return pName;
}

stock getbname(id)
{
	new q[128];
	format(q,128,"SELECT name FROM biz WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getoname(id)
{
	new q[128];
	format(q,128,"SELECT Name FROM orgs WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getbprice(id)
{
	new q[128];
	format(q,128,"SELECT price FROM biz WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],cost;
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	cost=strval(field[0]);
	mysql_free_result();
	return cost;
}


stock checkoveh(id,n)
{
	new q[128];
	format(q,128,"SELECT * FROM orgvehs WHERE VID=%d AND ID=%d",n,id);
	mysql_query(q);
	mysql_store_result();
	new v=mysql_num_rows();
	mysql_free_result();
	return v;
}

stock IsNumeric(const string[])
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if (string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}


stock CreateDynamicArea(Float:maxx,Float:mix,Float:maxy,Float:miny)
{
	return CreateDynamicRectangle(mix,miny,maxx,maxy,-1,-1,-1);
}


stock getjcp(hid,&Float:x,&Float:y,&Float:z)
{
	new q[128];
	format(q,128,"SELECT x,y,z FROM jobs WHERE ID=%d LIMIT 1",hid);
	mysql_query(q);
	mysql_store_result();
	new field[3][32];
	mysql_fetch_row_format(q, "|");
	explode(q,field,"|");
	x=strval(field[0]);
	y=strval(field[1]);
	z=strval(field[2]);
	mysql_free_result();
	return 1;
}


stock getstrikes(id)
{
	new q[128];
	format(q,128,"SELECT strike FROM stats WHERE Name='%s'",getname(id));
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q, "|");
	explode(q,field,"|");
	mysql_free_result();
	return strval(field[0]);
}


stock getwpnid(WeaponName[])
{
	for(new i = 0; i <= 46; i++)
	{
		switch(i)
			{
				case 0,19,20,21,44,45: continue;
				default:
				{
					new name[32]; GetWeaponName(i,name,32);
					if(strfind(name,WeaponName,true) != -1)
					return i;
				}
		}
	}
	return -1;
}

stock getfthr(id)
{
	new q[128];
	format(q,128,"SELECT Father FROM id WHERE Name='%s'",getname(id));
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getocolor(id)
{
	new q[128];
	format(q,128,"SELECT colour FROM orgs WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	mysql_free_result();
	return strval(field[0]);
}

stock getwife(id)
{
	new q[128];
	format(q,128,"SELECT Wife FROM id WHERE Name='%s'",getname(id));
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getdob(id)
{
	new q[128];
	format(q,128,"SELECT Birth FROM id WHERE Name='%s'",getname(id));
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getkids(id)
{
	new q[128];
	format(q,128,"SELECT kids FROM id WHERE Name='%s'",getname(id));
	mysql_query(q);
	mysql_store_result();
	new field[1][64],howner[64];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getcountry(id)
{
	new q[128];
	format(q,128,"SELECT Country FROM id WHERE Name='%s'",getname(id));
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock gethpass(id)
{
	new q[128];
	format(q,128,"SELECT Pass FROM houses WHERE ID=%d",id);
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return howner;
}

stock getage(id)
{
	new q[128];
	format(q,128,"SELECT age FROM id WHERE Name='%s'",getname(id));
	mysql_query(q);
	mysql_store_result();
	new field[1][32],howner[32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	format(howner,32,"%s",field[0]);
	mysql_free_result();
	return strval(howner);
}

stock checkvmdl(playerid,mdl)
{
	format(String,sizeof(String),"SELECT * FROM vehs WHERE Name='%s' AND Model=%d",getname(playerid),mdl);
	mysql_query(String);
	mysql_store_result();
	new v=mysql_num_rows();
	mysql_free_result();
	return v;
}

stock getcarcnt(playerid)
{
	format(String,sizeof(String),"SELECT * FROM vehs WHERE Name='%s'",getname(playerid));
	mysql_query(String);
	mysql_store_result();
	new v=mysql_num_rows();
	mysql_free_result();
	return v;
}

stock SaveVehs(playerid)
{
	if(getcarcnt(playerid) == 0) return 1;
	for(new i;i<MAX_VEHICLES;i++)
	{
	    if(strfind(owner[i],getname(playerid)) != -1)
	    {
	        new Float:p[4];
	        GetVehiclePos(i,p[0],p[1],p[2]);
	        GetVehicleZAngle(i,p[3]);
	        new q[164];
	        format(q,164,"UPDATE vehs SET X=%f, Y=%f, Z=%f, Rotation=%f WHERE Name='%s' AND Model=%d",p[0],p[1],p[2],p[3],getname(playerid),GetVehicleModel(i));
	        mysql_query(q);
	    }
	}
	return 1;
}


stock ptped(playerid)
{
	tped[playerid]=true;
	SetTimerEx("tptimer",4000,false,"i",playerid);
	return 1;
}


stock GetPointDistanceToPoint(Float:x1,Float:y1,Float:x2,Float:y2)
{
  	new Float:x, Float:y;
  	x = x1-x2;
  	y = y1-y2;
  	return floatround(floatsqroot(x*x+y*y),floatround_round);
}

stock getcans(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT cans FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}

stock getwallet(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT wallet FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}

stock getperm(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT perm FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}

stock getfreq(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT freq FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}

stock getsnax(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT snax FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}

stock getcigs(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT cigs FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}

stock getgps(playerid)
{
	new q[128];
	new n[32];
	GetPlayerName(playerid,n,32);
	format(q,128,"SELECT gps FROM stats WHERE Name='%s'",n);
	mysql_query(q);
	mysql_store_result();
	new field[1][32];
	mysql_fetch_row_format(q,"|");
	explode(q,field,"|");
	new bal=strval(field[0]);
	mysql_free_result();
	return bal;
}


