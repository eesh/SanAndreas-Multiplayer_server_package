#if defined _timers_included
	#endinput
#endif
#define _timers_included





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
	if(cmins == 60) chour++,cmins=0;
	if(chour == 24) chour = 0;
	SetWorldTime(chour);
	for(new i;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i))
		{
			if(Logged[i] == 1 && GetPlayerState(i) != PLAYER_STATE_WASTED)
			{
				SetAreaWeather(i);
				SetPlayerTime(i, chour, cmins);
				new k,ud,lr;
				GetPlayerKeys(i,k,ud,lr);
				if(k == KEY_HANDBRAKE && vel[i]==0)	refuel(i);
			}
		}
	}
	return 1;
}

forward deathconn();
public deathconn()
{
	TextDrawHideForAll(deathcon);
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
	scm(playerid,0xA9C4E4FF,"You have started the vehicle.");
	return 1;
}

forward Phone(playerid);
public Phone(playerid)
{
	if(incall[playerid]==0)
	{
	    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
		SendClientMessage(playerid,red,"Player didn't respond.");
		for(new i=0;i<MAX_PLAYERS;i++)
		{
			if(phno[i]==calling[playerid])
		    {
	      		SendClientMessage(playerid,0xE1E4AAFF,"You didnt respond to the call.");
			    break;
		    }
 		}
	    calling[playerid]=0;
	}
	return 1;
}


forward fuellower();
public fuellower()
{
	for(new i=0;i<MAX_VEHICLES;i++)
	{
	    if(IsBike(GetVehicleModel(i))) continue;
	    GetVehicleParamsEx(i,engine,lights,alarm,doors,bonnet,boot,objective);
	    if(fuel[i]==0) { SetVehicleParamsEx(i,0,lights,alarm,doors,bonnet,boot,objective); continue; }
		if(engine == 1)
		{
			fuel[i]-=1;
		}
/*		if(strlen(owner[i]) != 0)
		{
		    format(String,128,"UPDATE vehs SET fuel=%d WHERE Name='%s' AND Model=%d",fuel[i],owner[i],GetVehicleModel(i));
		    mysql_query(String);
		}*/
	}
	for(new p;p<MAX_PLAYERS;p++)
	{
        new v;
        v=GetPlayerVehicleID(p);
        if(v == 0) continue;
        format(String,128,"Fuel: %d", fuel[v]);
        PlayerTextDrawSetString(p, fueltd, String);
    }
	return 1;
}
//get camera coords and interpolate on spawn to make the spawn effect look cooler. make sure to save it on logging off though.