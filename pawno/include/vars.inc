#if defined _vars_included
	#endinput
#endif
#define _vars_included

new playerdcp;
new drivingtcp;
new coneshit;
new dscar;
new dcp;
new jsal[MAX_PLAYERS];
new mgcp;
new fjcp;
new mjcp;
new tjcp;
new trshcp;
new leader[MAX_PLAYERS];
new civil[MAX_PLAYERS];
new vel[MAX_PLAYERS];
new dlic[MAX_PLAYERS];
new admin[MAX_PLAYERS];
new newbie[MAX_PLAYERS];
new org[MAX_PLAYERS];
new job[MAX_PLAYERS];
new Money[MAX_PLAYERS];
new req[MAX_PLAYERS];
new fuel[MAX_VEHICLES];
new stalled[MAX_VEHICLES];
new vorg[MAX_VEHICLES];
new orgvid[MAX_PLAYERS];
new Float:refuelcp[20][3];
new Text3D:fuelcp[20];
new cpfuel[20][2];
new Logged[MAX_PLAYERS];
new String[128];
new pSkin[MAX_PLAYERS];
new Float:pX[MAX_PLAYERS];
new Float:pY[MAX_PLAYERS];
new Float:pZ[MAX_PLAYERS];
new Float:pAngle[MAX_PLAYERS];
new hspawn[MAX_PLAYERS];
new LSarea;
new LVarea;
new SFarea;
new LVclass;
new SFclass;
new LSclass;
new PlayerText:loctd;
new PlayerText:mphtd;
new PlayerText:fueltd;
new PlayerText:sl1;
new PlayerText:sl2;
new PlayerText:sl3;
new PlayerText:sl4;
new PlayerText:sl5;
new chour;
new cmins;
new Text:deathcon;
new vid,engine,lights,alarm,doors,bonnet,boot,objective;
new fjvehs[4];
new mjvehs[4];
new tjvehs[6];
new trshvehs[5];
new corg[MAX_CPS];
new vip[MAX_PLAYERS];
new vipcar[MAX_PLAYERS];

enum eorgdata
{
	ocolour,
	wpn1,
	wpn2,
	skin1,
	skin2,
	skin3,
	ammo1,
	ammo2,
	otype,
	oname[64],
	Float:cpx,
	Float:cpy,
	Float:cpz,
	Float:intx,
	Float:inty,
	Float:intz,
	Float:interior,
	memcount,
	oleader[32]
}

new orgdata[MAX_ORGS][eorgdata];
new dteststatus=-1;
new coneobjs[592];
new Float:dcones[592][3]=
{
	{-2044.69995117,-115.69999695,34.50000000}, //Object number 0
	{-2044.50000000,-117.69999695,34.50000000}, //Object number 1
	{-2044.40002441,-119.69999695,34.50000000}, //Object number 2
	{-2049.60009766,-116.30000305,34.59999847}, //Object number 3
	{-2049.30004883,-117.90000153,34.59999847}, //Object number 4
	{-2049.10009766,-120.09999847,34.59999847}, //Object number 5
	{-2048.89990234,-122.40000153,34.59999847}, //Object number 6
	{-2044.09997559,-121.59999847,34.50000000}, //Object number 7
	{-2044.00000000,-123.80000305,34.59999847}, //Object number 8
	{-2048.80004883,-124.69999695,34.59999847}, //Object number 9
	{-2048.60009766,-127.00000000,34.59999847}, //Object number 10
	{-2043.90002441,-125.80000305,34.59999847}, //Object number 11
	{-2043.80004883,-127.69999695,34.59999847}, //Object number 12
	{-2048.39990234,-129.10000610,34.59999847}, //Object number 13
	{-2048.19995117,-131.19999695,34.59999847}, //Object number 14
	{-2043.69995117,-129.39999390,34.59999847}, //Object number 15
	{-2043.40002441,-130.89999390,34.59999847}, //Object number 16
	{-2042.50000000,-132.50000000,34.59999847}, //Object number 17
	{-2047.40002441,-133.00000000,34.59999847}, //Object number 18
	{-2046.40002441,-135.19999695,34.59999847}, //Object number 19
	{-2041.80004883,-133.80000305,34.59999847}, //Object number 20
	{-2044.90002441,-137.00000000,34.59999847}, //Object number 21
	{-2043.30004883,-138.60000610,34.59999847}, //Object number 22
	{-2040.50000000,-135.00000000,34.59999847}, //Object number 23
	{-2038.50000000,-136.39999390,34.59999847}, //Object number 24
	{-2042.00000000,-139.69999695,34.59999847}, //Object number 25
	{-2040.40002441,-140.80000305,34.59999847}, //Object number 26
	{-2038.19995117,-141.60000610,34.59999847}, //Object number 27
	{-2036.59997559,-137.19999695,34.59999847}, //Object number 28
	{-2035.69995117,-141.89999390,34.59999847}, //Object number 29
	{-2034.00000000,-142.00000000,34.59999847}, //Object number 30
	{-2032.30004883,-142.10000610,34.59999847}, //Object number 31
	{-2034.50000000,-137.39999390,34.59999847}, //Object number 32
	{-2032.80004883,-137.50000000,34.59999847}, //Object number 33
	{-2031.09997559,-137.60000610,34.59999847}, //Object number 34
	{-2029.09997559,-137.60000610,34.59999847}, //Object number 35
	{-2027.40002441,-137.60000610,34.59999847}, //Object number 36
	{-2030.50000000,-142.00000000,34.59999847}, //Object number 37
	{-2028.50000000,-142.00000000,34.59999847}, //Object number 38
	{-2026.80004883,-142.00000000,34.59999847}, //Object number 39
	{-2024.80004883,-142.00000000,34.59999847}, //Object number 40
	{-2025.50000000,-137.69999695,34.59999847}, //Object number 41
	{-2024.00000000,-137.69999695,34.59999847}, //Object number 42
	{-2022.30004883,-137.69999695,34.59999847}, //Object number 43
	{-2019.40002441,-137.60000610,34.59999847}, //Object number 44
	{-2020.80004883,-137.60000610,34.59999847}, //Object number 45
	{-2017.90002441,-138.19999695,34.59999847}, //Object number 46
	{-2017.90002441,-139.69999695,34.59999847}, //Object number 47
	{-2017.90002441,-141.39999390,34.59999847}, //Object number 48
	{-2017.90002441,-143.39999390,34.59999847}, //Object number 49
	{-2017.90002441,-145.10000610,34.59999847}, //Object number 50
	{-2017.90002441,-146.80000305,34.59999847}, //Object number 51
	{-2023.90002441,-142.60000610,34.59999847}, //Object number 52
	{-2023.30004883,-143.60000610,34.59999847}, //Object number 53
	{-2023.30004883,-145.60000610,34.59999847}, //Object number 54
	{-2023.30004883,-147.30000305,34.59999847}, //Object number 55
	{-2023.29980469,-147.29980469,34.59999847}, //Object number 56
	{-2017.80004883,-149.50000000,34.59999847}, //Object number 57
	{-2023.30004883,-149.69999695,34.59999847}, //Object number 58
	{-2023.19995117,-152.19999695,34.59999847}, //Object number 59
	{-2017.69995117,-152.00000000,34.59999847}, //Object number 60
	{-2017.59997559,-155.00000000,34.59999847}, //Object number 61
	{-2023.19995117,-154.50000000,34.59999847}, //Object number 62
	{-2023.19995117,-157.10000610,34.59999847}, //Object number 63
	{-2017.50000000,-157.19999695,34.59999847}, //Object number 64
	{-2017.50000000,-157.19921875,34.59999847}, //Object number 65
	{-2023.19995117,-159.30000305,34.59999847}, //Object number 66
	{-2023.30004883,-160.39999390,34.59999847}, //Object number 67
	{-2024.50000000,-160.39999390,34.59999847}, //Object number 68
	{-2025.09997559,-159.50000000,34.59999847}, //Object number 69
	{-2025.80004883,-158.19999695,34.59999847}, //Object number 70
	{-2017.80004883,-159.19999695,34.59999847}, //Object number 71
	{-2017.80004883,-161.39999390,34.59999847}, //Object number 72
	{-2017.80004883,-163.60000610,34.59999847}, //Object number 73
	{-2017.80004883,-165.80000305,34.59999847}, //Object number 74
	{-2017.80004883,-167.00000000,34.59999847}, //Object number 75
	{-2017.80004883,-168.80000305,34.59999847}, //Object number 76
	{-2017.80004883,-170.50000000,34.59999847}, //Object number 77
	{-2018.09997559,-171.50000000,34.59999847}, //Object number 78
	{-2018.90002441,-172.19999695,34.59999847}, //Object number 79
	{-2019.90002441,-172.19999695,34.59999847}, //Object number 80
	{-2020.90002441,-172.19999695,34.59999847}, //Object number 81
	{-2021.90002441,-172.19999695,34.59999847}, //Object number 82
	{-2022.90002441,-172.19999695,34.59999847}, //Object number 83
	{-2023.90002441,-171.89999390,34.59999847}, //Object number 84
	{-2024.90002441,-170.89999390,34.59999847}, //Object number 85
	{-2025.59997559,-169.39999390,34.59999847}, //Object number 86
	{-2026.40002441,-167.80000305,34.59999847}, //Object number 87
	{-2027.09997559,-166.50000000,34.59999847}, //Object number 88
	{-2027.90002441,-164.89999390,34.59999847}, //Object number 89
	{-2028.59997559,-163.60000610,34.59999847}, //Object number 90
	{-2029.30004883,-162.30000305,34.59999847}, //Object number 91
	{-2030.19995117,-160.50000000,34.59999847}, //Object number 92
	{-2031.09997559,-158.69999695,34.59999847}, //Object number 93
	{-2031.69995117,-157.60000610,34.59999847}, //Object number 94
	{-2032.50000000,-156.00000000,34.59999847}, //Object number 95
	{-2026.30004883,-157.00000000,34.59999847}, //Object number 96
	{-2027.00000000,-155.69999695,34.59999847}, //Object number 97
	{-2027.50000000,-154.80000305,34.59999847}, //Object number 98
	{-2028.30004883,-153.19999695,34.59999847}, //Object number 99
	{-2027.90002441,-153.89999390,34.59999847}, //Object number 100
	{-2028.90002441,-152.19999695,34.59999847}, //Object number 101
	{-2029.40002441,-151.30000305,34.59999847}, //Object number 102
	{-2030.00000000,-150.19999695,34.59999847}, //Object number 103
	{-2030.59997559,-149.10000610,34.59999847}, //Object number 104
	{-2031.30004883,-147.80000305,34.59999847}, //Object number 105
	{-2033.09997559,-154.80000305,34.59999847}, //Object number 106
	{-2033.59997559,-153.89999390,34.59999847}, //Object number 107
	{-2034.09997559,-153.00000000,34.59999847}, //Object number 108
	{-2034.69995117,-151.89999390,34.59999847}, //Object number 109
	{-2035.19995117,-151.00000000,34.59999847}, //Object number 110
	{-2035.19921875,-151.00000000,34.59999847}, //Object number 111
	{-2032.50000000,-146.80000305,34.59999847}, //Object number 112
	{-2033.59997559,-146.10000610,34.59999847}, //Object number 113
	{-2034.90002441,-145.50000000,34.59999847}, //Object number 114
	{-2036.50000000,-144.89999390,34.59999847}, //Object number 115
	{-2036.50000000,-144.89941406,34.59999847}, //Object number 116
	{-2036.00000000,-150.60000610,34.59999847}, //Object number 117
	{-2037.50000000,-150.69999695,34.59999847}, //Object number 118
	{-2036.80004883,-150.60000610,34.59999847}, //Object number 119
	{-2038.50000000,-150.69999695,34.59999847}, //Object number 120
	{-2039.50000000,-150.80000305,34.59999847}, //Object number 121
	{-2040.50000000,-150.89999390,34.59999847}, //Object number 122
	{-2037.69995117,-144.89999390,34.59999847}, //Object number 123
	{-2038.69995117,-145.00000000,34.59999847}, //Object number 124
	{-2039.69995117,-145.10000610,34.59999847}, //Object number 125
	{-2040.69995117,-145.19999695,34.59999847}, //Object number 126
	{-2040.69921875,-145.19921875,34.59999847}, //Object number 127
	{-2042.30004883,-145.39999390,34.59999847}, //Object number 128
	{-2043.90002441,-145.60000610,34.59999847}, //Object number 129
	{-2045.50000000,-145.80000305,34.59999847}, //Object number 130
	{-2046.50000000,-145.89999390,34.59999847}, //Object number 131
	{-2047.50000000,-146.00000000,34.59999847}, //Object number 132
	{-2048.69995117,-146.10000610,34.59999847}, //Object number 133
	{-2049.89990234,-146.19999695,34.59999847}, //Object number 134
	{-2051.60009766,-146.30000305,34.59999847}, //Object number 135
	{-2052.80004883,-146.39999390,34.59999847}, //Object number 136
	{-2041.80004883,-151.00000000,34.59999847}, //Object number 137
	{-2043.00000000,-151.10000610,34.59999847}, //Object number 138
	{-2044.50000000,-151.19999695,34.59999847}, //Object number 139
	{-2046.19995117,-151.30000305,34.59999847}, //Object number 140
	{-2047.40002441,-151.39999390,34.59999847}, //Object number 141
	{-2048.89990234,-151.50000000,34.59999847}, //Object number 142
	{-2050.60009766,-151.60000610,34.59999847}, //Object number 143
	{-2051.80004883,-151.69999695,34.59999847}, //Object number 144
	{-2053.00000000,-151.80000305,34.59999847}, //Object number 145
	{-2054.30004883,-146.60000610,34.59999847}, //Object number 146
	{-2055.50000000,-146.69999695,34.59999847}, //Object number 147
	{-2057.50000000,-146.89999390,34.59999847}, //Object number 148
	{-2058.69995117,-147.00000000,34.59999847}, //Object number 149
	{-2054.50000000,-151.89999390,34.59999847}, //Object number 150
	{-2055.50000000,-152.00000000,34.59999847}, //Object number 151
	{-2056.50000000,-152.10000610,34.59999847}, //Object number 152
	{-2057.69995117,-152.19999695,34.59999847}, //Object number 153
	{-2059.19995117,-152.30000305,34.59999847}, //Object number 154
	{-2059.19921875,-152.29980469,34.59999847}, //Object number 155
	{-2060.89990234,-152.39999390,34.59999847}, //Object number 156
	{-2060.30004883,-147.10000610,34.59999847}, //Object number 157
	{-2061.50000000,-147.19999695,34.59999847}, //Object number 158
	{-2062.69995117,-147.30000305,34.59999847}, //Object number 159
	{-2063.69995117,-147.39999390,34.59999847}, //Object number 160
	{-2064.89990234,-147.50000000,34.59999847}, //Object number 161
	{-2066.60009766,-147.60000610,34.59999847}, //Object number 162
	{-2067.60009766,-147.69999695,34.59999847}, //Object number 163
	{-2068.60009766,-147.80000305,34.59999847}, //Object number 164
	{-2062.19995117,-152.50000000,34.59999847}, //Object number 165
	{-2063.39990234,-152.60000610,34.59999847}, //Object number 166
	{-2064.60009766,-152.69999695,34.59999847}, //Object number 167
	{-2065.80004883,-152.80000305,34.59999847}, //Object number 168
	{-2067.80004883,-153.00000000,34.59999847}, //Object number 169
	{-2066.80004883,-152.89999390,34.59999847}, //Object number 170
	{-2068.30004883,-153.30000305,34.59999847}, //Object number 171
	{-2068.80004883,-154.30000305,34.59999847}, //Object number 172
	{-2068.80004883,-155.30000305,34.59999847}, //Object number 173
	{-2068.80004883,-156.00000000,34.59999847}, //Object number 174
	{-2068.80004883,-157.19999695,34.59999847}, //Object number 175
	{-2068.80004883,-158.39999390,34.59999847}, //Object number 176
	{-2068.80004883,-159.60000610,34.59999847}, //Object number 177
	{-2068.80004883,-160.60000610,34.59999847}, //Object number 178
	{-2068.80004883,-161.60000610,34.59999847}, //Object number 179
	{-2068.80004883,-162.30000305,34.59999847}, //Object number 180
	{-2068.80004883,-163.30000305,34.59999847}, //Object number 181
	{-2068.80004883,-164.80000305,34.59999847}, //Object number 182
	{-2068.80004883,-165.30000305,34.59999847}, //Object number 183
	{-2068.80004883,-167.00000000,34.59999847}, //Object number 184
	{-2068.80004883,-167.19999695,34.59999847}, //Object number 185
	{-2068.80004883,-168.39999390,34.59999847}, //Object number 186
	{-2068.80004883,-169.60000610,34.59999847}, //Object number 187
	{-2068.89990234,-166.10000610,34.59999847}, //Object number 188
	{-2068.80004883,-170.60000610,34.59999847}, //Object number 189
	{-2069.89990234,-147.89999390,34.59999847}, //Object number 190
	{-2070.89990234,-147.89999390,34.59999847}, //Object number 191
	{-2071.80004883,-148.00000000,34.59999847}, //Object number 192
	{-2072.89990234,-148.00000000,34.59999847}, //Object number 193
	{-2073.89990234,-148.10000610,34.59999847}, //Object number 194
	{-2074.60009766,-148.39999390,34.59999847}, //Object number 195
	{-2075.00000000,-149.19999695,34.59999847}, //Object number 196
	{-2075.39990234,-150.00000000,34.59999847}, //Object number 197
	{-2075.80004883,-150.80000305,34.59999847}, //Object number 198
	{-2076.00000000,-151.60000610,34.59999847}, //Object number 199
	{-2076.19995117,-152.60000610,34.59999847}, //Object number 200
	{-2076.39990234,-153.39999390,34.59999847}, //Object number 201
	{-2076.60009766,-154.19999695,34.59999847}, //Object number 202
	{-2076.50000000,-154.89999390,34.59999847}, //Object number 203
	{-2076.39990234,-155.60000610,34.59999847}, //Object number 204
	{-2076.39990234,-156.60000610,34.59999847}, //Object number 205
	{-2076.39990234,-157.60000610,34.59999847}, //Object number 206
	{-2076.39990234,-158.60000610,34.59999847}, //Object number 207
	{-2076.39990234,-159.30000305,34.59999847}, //Object number 208
	{-2076.39990234,-160.30000305,34.59999847}, //Object number 209
	{-2076.39990234,-161.30000305,34.59999847}, //Object number 210
	{-2076.39990234,-162.50000000,34.59999847}, //Object number 211
	{-2076.39990234,-163.50000000,34.59999847}, //Object number 212
	{-2076.39990234,-164.50000000,34.59999847}, //Object number 213
	{-2076.39990234,-166.00000000,34.59999847}, //Object number 214
	{-2076.39990234,-166.69999695,34.59999847}, //Object number 215
	{-2076.39990234,-167.89999390,34.59999847}, //Object number 216
	{-2076.39990234,-169.39999390,34.59999847}, //Object number 217
	{-2076.39941406,-169.39941406,34.59999847}, //Object number 218
	{-2076.39990234,-170.60000610,34.59999847}, //Object number 219
	{-2076.39990234,-171.80000305,34.59999847}, //Object number 220
	{-2076.39990234,-172.80000305,34.59999847}, //Object number 221
	{-2076.39990234,-174.00000000,34.59999847}, //Object number 222
	{-2076.39990234,-175.50000000,34.59999847}, //Object number 223
	{-2076.39990234,-177.00000000,34.59999847}, //Object number 224
	{-2068.80004883,-171.60000610,34.59999847}, //Object number 225
	{-2068.80004883,-172.60000610,34.59999847}, //Object number 226
	{-2068.80004883,-173.60000610,34.59999847}, //Object number 227
	{-2068.80004883,-175.30000305,34.59999847}, //Object number 228
	{-2068.80004883,-176.30000305,34.59999847}, //Object number 229
	{-2068.69995117,-177.80000305,34.59999847}, //Object number 230
	{-2068.69921875,-177.79980469,34.59999847}, //Object number 231
	{-2068.19995117,-179.00000000,34.59999847}, //Object number 232
	{-2066.89990234,-179.00000000,34.59999847}, //Object number 233
	{-2065.60009766,-179.00000000,34.59999847}, //Object number 234
	{-2064.60009766,-179.00000000,34.59999847}, //Object number 235
	{-2063.60009766,-179.00000000,34.59999847}, //Object number 236
	{-2062.30004883,-179.00000000,34.59999847}, //Object number 237
	{-2061.30004883,-179.00000000,34.59999847}, //Object number 238
	{-2060.10009766,-179.00000000,34.59999847}, //Object number 239
	{-2059.10009766,-179.00000000,34.59999847}, //Object number 240
	{-2057.89990234,-179.00000000,34.59999847}, //Object number 241
	{-2056.69995117,-179.00000000,34.59999847}, //Object number 242
	{-2055.50000000,-179.00000000,34.59999847}, //Object number 243
	{-2054.80004883,-179.00000000,34.59999847}, //Object number 244
	{-2076.30004883,-178.19999695,34.59999847}, //Object number 245
	{-2076.30004883,-179.39999390,34.59999847}, //Object number 246
	{-2076.30004883,-180.60000610,34.59999847}, //Object number 247
	{-2076.30004883,-181.60000610,34.59999847}, //Object number 248
	{-2076.30004883,-182.80000305,34.59999847}, //Object number 249
	{-2076.30004883,-183.80000305,34.59999847}, //Object number 250
	{-2076.30004883,-184.80000305,34.59999847}, //Object number 251
	{-2075.60009766,-185.60000610,34.59999847}, //Object number 252
	{-2074.60009766,-186.39999390,34.59999847}, //Object number 253
	{-2073.39990234,-186.89999390,34.59999847}, //Object number 254
	{-2072.39990234,-187.39999390,34.59999847}, //Object number 255
	{-2071.10009766,-187.39999390,34.59999847}, //Object number 256
	{-2069.30004883,-187.50000000,34.59999847}, //Object number 257
	{-2067.80004883,-187.50000000,34.59999847}, //Object number 258
	{-2066.50000000,-187.50000000,34.59999847}, //Object number 259
	{-2065.00000000,-187.39999390,34.59999847}, //Object number 260
	{-2063.50000000,-187.30000305,34.59999847}, //Object number 261
	{-2062.30004883,-187.30000305,34.59999847}, //Object number 262
	{-2061.10009766,-187.30000305,34.59999847}, //Object number 263
	{-2060.10009766,-187.30000305,34.59999847}, //Object number 264
	{-2058.60009766,-187.30000305,34.59999847}, //Object number 265
	{-2057.10009766,-187.30000305,34.59999847}, //Object number 266
	{-2055.80004883,-187.30000305,34.59999847}, //Object number 267
	{-2054.30004883,-187.30000305,34.59999847}, //Object number 268
	{-2053.00000000,-187.30000305,34.59999847}, //Object number 269
	{-2051.80004883,-187.30000305,34.59999847}, //Object number 270
	{-2051.79980469,-187.29980469,34.59999847}, //Object number 271
	{-2050.50000000,-187.30000305,34.59999847}, //Object number 272
	{-2049.50000000,-187.30000305,34.59999847}, //Object number 273
	{-2048.00000000,-187.30000305,34.59999847}, //Object number 274
	{-2046.50000000,-187.30000305,34.59999847}, //Object number 275
	{-2053.50000000,-179.00000000,34.59999847}, //Object number 276
	{-2052.30004883,-179.00000000,34.59999847}, //Object number 277
	{-2051.30004883,-179.00000000,34.59999847}, //Object number 278
	{-2050.30004883,-179.00000000,34.59999847}, //Object number 279
	{-2049.00000000,-179.00000000,34.59999847}, //Object number 280
	{-2047.30004883,-179.00000000,34.59999847}, //Object number 281
	{-2046.30004883,-179.00000000,34.59999847}, //Object number 282
	{-2045.50000000,-179.00000000,34.59999847}, //Object number 283
	{-2044.30004883,-179.00000000,34.59999847}, //Object number 284
	{-2043.00000000,-179.00000000,34.59999847}, //Object number 285
	{-2041.50000000,-179.00000000,34.59999847}, //Object number 286
	{-2040.50000000,-179.00000000,34.59999847}, //Object number 287
	{-2039.50000000,-179.00000000,34.59999847}, //Object number 288
	{-2038.30004883,-179.00000000,34.59999847}, //Object number 289
	{-2045.09997559,-187.19999695,34.59999847}, //Object number 290
	{-2043.80004883,-187.19999695,34.59999847}, //Object number 291
	{-2042.50000000,-187.19999695,34.59999847}, //Object number 292
	{-2041.30004883,-187.19999695,34.59999847}, //Object number 293
	{-2040.00000000,-187.19999695,34.59999847}, //Object number 294
	{-2038.80004883,-187.19999695,34.59999847}, //Object number 295
	{-2037.50000000,-187.19999695,34.59999847}, //Object number 296
	{-2037.50000000,-187.19921875,34.59999847}, //Object number 297
	{-2036.30004883,-187.19999695,34.59999847}, //Object number 298
	{-2035.30004883,-188.00000000,34.59999847}, //Object number 299
	{-2035.30004883,-189.30000305,34.59999847}, //Object number 300
	{-2036.30004883,-189.30000305,34.59999847}, //Object number 301
	{-2037.30004883,-189.30000305,34.59999847}, //Object number 302
	{-2038.30004883,-189.30000305,34.59999847}, //Object number 303
	{-2037.19995117,-179.10000610,34.59999847}, //Object number 304
	{-2036.19995117,-179.10000610,34.59999847}, //Object number 305
	{-2035.19995117,-179.10000610,34.59999847}, //Object number 306
	{-2034.19995117,-179.10000610,34.59999847}, //Object number 307
	{-2032.90002441,-179.10000610,34.59999847}, //Object number 308
	{-2031.59997559,-179.10000610,34.59999847}, //Object number 309
	{-2030.59997559,-179.10000610,34.59999847}, //Object number 310
	{-2029.59997559,-179.10000610,34.59999847}, //Object number 311
	{-2028.59997559,-179.10000610,34.59999847}, //Object number 312
	{-2027.80004883,-179.10000610,34.59999847}, //Object number 313
	{-2027.09997559,-179.89999390,34.59999847}, //Object number 314
	{-2026.90002441,-180.69999695,34.59999847}, //Object number 315
	{-2026.90002441,-181.69999695,34.59999847}, //Object number 316
	{-2026.90002441,-182.69999695,34.59999847}, //Object number 317
	{-2026.90002441,-183.69999695,34.59999847}, //Object number 318
	{-2026.90002441,-184.69999695,34.59999847}, //Object number 319
	{-2026.90002441,-185.89999390,34.59999847}, //Object number 320
	{-2026.90002441,-186.89999390,34.59999847}, //Object number 321
	{-2026.90002441,-187.89999390,34.59999847}, //Object number 322
	{-2026.90002441,-188.60000610,34.59999847}, //Object number 323
	{-2026.90002441,-189.30000305,34.59999847}, //Object number 324
	{-2026.90002441,-190.30000305,34.59999847}, //Object number 325
	{-2026.90002441,-191.00000000,34.59999847}, //Object number 326
	{-2026.90002441,-192.00000000,34.59999847}, //Object number 327
	{-2026.90002441,-193.19999695,34.59999847}, //Object number 328
	{-2026.89941406,-193.19921875,34.59999847}, //Object number 329
	{-2026.90002441,-194.39999390,34.59999847}, //Object number 330
	{-2026.90002441,-194.89999390,34.59999847}, //Object number 331
	{-2026.90002441,-196.10000610,34.59999847}, //Object number 332
	{-2027.40002441,-197.10000610,34.59999847}, //Object number 333
	{-2028.40002441,-197.10000610,34.59999847}, //Object number 334
	{-2029.59997559,-197.10000610,34.59999847}, //Object number 335
	{-2030.80004883,-197.10000610,34.59999847}, //Object number 336
	{-2032.00000000,-197.10000610,34.59999847}, //Object number 337
	{-2033.19995117,-197.10000610,34.59999847}, //Object number 338
	{-2033.19921875,-197.09960938,34.59999847}, //Object number 339
	{-2034.19995117,-197.10000610,34.59999847}, //Object number 340
	{-2034.69995117,-197.10000610,34.59999847}, //Object number 341
	{-2035.19995117,-197.10000610,34.59999847}, //Object number 342
	{-2036.19995117,-197.10000610,34.59999847}, //Object number 343
	{-2037.40002441,-197.10000610,34.59999847}, //Object number 344
	{-2038.59997559,-197.10000610,34.59999847}, //Object number 345
	{-2039.30004883,-197.10000610,34.59999847}, //Object number 346
	{-2040.30004883,-197.10000610,34.59999847}, //Object number 347
	{-2041.30004883,-197.10000610,34.59999847}, //Object number 348
	{-2042.30004883,-197.10000610,34.59999847}, //Object number 349
	{-2043.50000000,-197.10000610,34.59999847}, //Object number 350
	{-2044.50000000,-197.10000610,34.59999847}, //Object number 351
	{-2045.00000000,-197.10000610,34.59999847}, //Object number 352
	{-2046.00000000,-197.10000610,34.59999847}, //Object number 353
	{-2047.00000000,-197.10000610,34.59999847}, //Object number 354
	{-2047.50000000,-197.10000610,34.59999847}, //Object number 355
	{-2039.40002441,-189.19999695,34.59999847}, //Object number 356
	{-2040.59997559,-189.19999695,34.59999847}, //Object number 357
	{-2041.59997559,-189.19999695,34.59999847}, //Object number 358
	{-2042.80004883,-189.19999695,34.59999847}, //Object number 359
	{-2042.79980469,-189.19921875,34.59999847}, //Object number 360
	{-2043.80004883,-189.19999695,34.59999847}, //Object number 361
	{-2044.80004883,-189.19999695,34.59999847}, //Object number 362
	{-2046.00000000,-189.19999695,34.59999847}, //Object number 363
	{-2047.30004883,-189.19999695,34.59999847}, //Object number 364
	{-2048.30004883,-189.19999695,34.59999847}, //Object number 365
	{-2049.80004883,-189.19999695,34.59999847}, //Object number 366
	{-2050.80004883,-189.19999695,34.59999847}, //Object number 367
	{-2051.80004883,-189.19999695,34.59999847}, //Object number 368
	{-2053.80004883,-189.19999695,34.59999847}, //Object number 369
	{-2048.69995117,-197.10000610,34.59999847}, //Object number 370
	{-2049.89990234,-197.10000610,34.59999847}, //Object number 371
	{-2051.10009766,-197.10000610,34.59999847}, //Object number 372
	{-2052.10009766,-197.10000610,34.59999847}, //Object number 373
	{-2053.60009766,-197.10000610,34.59999847}, //Object number 374
	{-2054.60009766,-197.10000610,34.59999847}, //Object number 375
	{-2055.60009766,-197.10000610,34.59999847}, //Object number 376
	{-2056.80004883,-197.10000610,34.59999847}, //Object number 377
	{-2058.00000000,-197.10000610,34.59999847}, //Object number 378
	{-2059.50000000,-197.10000610,34.59999847}, //Object number 379
	{-2055.19995117,-189.10000610,34.59999847}, //Object number 380
	{-2056.19995117,-189.10000610,34.59999847}, //Object number 381
	{-2057.39990234,-189.10000610,34.59999847}, //Object number 382
	{-2058.60009766,-189.10000610,34.59999847}, //Object number 383
	{-2059.80004883,-189.10000610,34.59999847}, //Object number 384
	{-2060.80004883,-189.10000610,34.59999847}, //Object number 385
	{-2061.80004883,-189.10000610,34.59999847}, //Object number 386
	{-2063.00000000,-189.10000610,34.59999847}, //Object number 387
	{-2064.00000000,-189.10000610,34.59999847}, //Object number 388
	{-2065.30004883,-189.10000610,34.59999847}, //Object number 389
	{-2066.30004883,-189.10000610,34.59999847}, //Object number 390
	{-2060.69995117,-197.00000000,34.59999847}, //Object number 391
	{-2061.89990234,-197.00000000,34.59999847}, //Object number 392
	{-2062.89990234,-197.00000000,34.59999847}, //Object number 393
	{-2064.60009766,-197.00000000,34.59999847}, //Object number 394
	{-2065.80004883,-197.00000000,34.59999847}, //Object number 395
	{-2066.80004883,-197.00000000,34.59999847}, //Object number 396
	{-2067.30004883,-197.00000000,34.59999847}, //Object number 397
	{-2068.30004883,-197.00000000,34.59999847}, //Object number 398
	{-2069.00000000,-197.00000000,34.59999847}, //Object number 399
	{-2070.00000000,-197.00000000,34.59999847}, //Object number 400
	{-2071.00000000,-197.00000000,34.59999847}, //Object number 401
	{-2072.00000000,-197.00000000,34.59999847}, //Object number 402
	{-2072.80004883,-197.00000000,34.59999847}, //Object number 403
	{-2074.30004883,-197.00000000,34.59999847}, //Object number 404
	{-2075.00000000,-197.00000000,34.59999847}, //Object number 405
	{-2075.50000000,-197.00000000,34.59999847}, //Object number 406
	{-2076.50000000,-197.00000000,34.59999847}, //Object number 407
	{-2067.80004883,-189.19999695,34.59999847}, //Object number 408
	{-2068.80004883,-189.19999695,34.59999847}, //Object number 409
	{-2070.00000000,-189.19999695,34.59999847}, //Object number 410
	{-2071.80004883,-189.19999695,34.59999847}, //Object number 411
	{-2073.00000000,-189.19999695,34.59999847}, //Object number 412
	{-2074.30004883,-189.19999695,34.59999847}, //Object number 413
	{-2076.00000000,-189.19999695,34.59999847}, //Object number 414
	{-2077.30004883,-189.19999695,34.59999847}, //Object number 415
	{-2079.00000000,-189.19999695,34.59999847}, //Object number 416
	{-2080.80004883,-189.19999695,34.59999847}, //Object number 417
	{-2078.30004883,-196.89999390,34.59999847}, //Object number 418
	{-2079.30004883,-196.89999390,34.59999847}, //Object number 419
	{-2080.80004883,-196.89999390,34.59999847}, //Object number 420
	{-2082.00000000,-196.89999390,34.59999847}, //Object number 421
	{-2083.50000000,-196.89999390,34.59999847}, //Object number 422
	{-2085.00000000,-196.89999390,34.59999847}, //Object number 423
	{-2085.69995117,-197.00000000,34.59999847}, //Object number 424
	{-2086.69995117,-196.89999390,34.59999847}, //Object number 425
	{-2087.69995117,-196.89999390,34.59999847}, //Object number 426
	{-2088.69995117,-196.89999390,34.59999847}, //Object number 427
	{-2089.39990234,-196.89999390,34.59999847}, //Object number 428
	{-2090.60009766,-197.00000000,34.59999847}, //Object number 429
	{-2091.60009766,-197.00000000,34.59999847}, //Object number 430
	{-2092.60009766,-196.00000000,34.59999847}, //Object number 431
	{-2092.69995117,-194.80000305,34.59999847}, //Object number 432
	{-2092.69995117,-193.80000305,34.59999847}, //Object number 433
	{-2092.80004883,-192.60000610,34.59999847}, //Object number 434
	{-2092.89990234,-191.39999390,34.59999847}, //Object number 435
	{-2093.00000000,-190.19999695,34.59999847}, //Object number 436
	{-2082.00000000,-189.19999695,34.59999847}, //Object number 437
	{-2083.50000000,-189.30000305,34.59999847}, //Object number 438
	{-2084.50000000,-189.30000305,34.59999847}, //Object number 439
	{-2085.50000000,-189.30000305,34.59999847}, //Object number 440
	{-2086.50000000,-189.30000305,34.59999847}, //Object number 441
	{-2086.60009766,-188.10000610,34.59999847}, //Object number 442
	{-2086.60009766,-187.10000610,34.59999847}, //Object number 443
	{-2086.69995117,-185.89999390,34.59999847}, //Object number 444
	{-2086.80004883,-184.69999695,34.59999847}, //Object number 445
	{-2086.89990234,-183.00000000,34.59999847}, //Object number 446
	{-2087.00000000,-181.50000000,34.59999847}, //Object number 447
	{-2087.00000000,-181.50000000,34.59999847}, //Object number 448
	{-2093.10009766,-189.00000000,34.59999847}, //Object number 449
	{-2093.10009766,-188.00000000,34.59999847}, //Object number 450
	{-2093.19995117,-186.80000305,34.59999847}, //Object number 451
	{-2093.19921875,-186.79980469,34.59999847}, //Object number 452
	{-2093.19995117,-185.80000305,34.59999847}, //Object number 453
	{-2093.19995117,-184.60000610,34.59999847}, //Object number 454
	{-2093.19995117,-183.10000610,34.59999847}, //Object number 455
	{-2093.19995117,-181.80000305,34.59999847}, //Object number 456
	{-2093.19995117,-180.60000610,34.59999847}, //Object number 457
	{-2093.19995117,-179.10000610,34.59999847}, //Object number 458
	{-2093.19921875,-179.09960938,34.59999847}, //Object number 459
	{-2093.30004883,-177.89999390,34.59999847}, //Object number 460
	{-2093.39990234,-176.89999390,34.59999847}, //Object number 461
	{-2093.50000000,-175.69999695,34.59999847}, //Object number 462
	{-2087.00000000,-180.10000610,34.59999847}, //Object number 463
	{-2087.10009766,-178.39999390,34.59999847}, //Object number 464
	{-2087.19995117,-176.89999390,34.59999847}, //Object number 465
	{-2087.30004883,-175.39999390,34.59999847}, //Object number 466
	{-2087.39990234,-174.19999695,34.59999847}, //Object number 467
	{-2087.39941406,-174.19921875,34.59999847}, //Object number 468
	{-2087.50000000,-172.69999695,34.59999847}, //Object number 469
	{-2087.60009766,-171.19999695,34.59999847}, //Object number 470
	{-2087.69995117,-170.00000000,34.59999847}, //Object number 471
	{-2087.80004883,-168.80000305,34.59999847}, //Object number 472
	{-2087.89990234,-167.30000305,34.59999847}, //Object number 473
	{-2088.00000000,-165.60000610,34.59999847}, //Object number 474
	{-2093.60009766,-174.19999695,34.59999847}, //Object number 475
	{-2093.59960938,-174.19921875,34.59999847}, //Object number 476
	{-2093.69995117,-172.69999695,34.59999847}, //Object number 477
	{-2093.80004883,-171.19999695,34.59999847}, //Object number 478
	{-2093.60009766,-169.89999390,34.59999847}, //Object number 479
	{-2093.69995117,-168.19999695,34.59999847}, //Object number 480
	{-2093.50000000,-166.69999695,34.59999847}, //Object number 481
	{-2093.50000000,-166.69921875,34.59999847}, //Object number 482
	{-2093.60009766,-165.50000000,34.59999847}, //Object number 483
	{-2093.39990234,-164.50000000,34.59999847}, //Object number 484
	{-2093.50000000,-163.30000305,34.59999847}, //Object number 485
	{-2093.60009766,-162.10000610,34.59999847}, //Object number 486
	{-2093.60009766,-161.10000610,34.59999847}, //Object number 487
	{-2088.00000000,-164.39999390,34.59999847}, //Object number 488
	{-2088.10009766,-163.19999695,34.59999847}, //Object number 489
	{-2088.10009766,-162.39999390,34.59999847}, //Object number 490
	{-2088.19995117,-161.19999695,34.59999847}, //Object number 491
	{-2088.19921875,-161.19921875,34.59999847}, //Object number 492
	{-2088.19995117,-160.19999695,34.59999847}, //Object number 493
	{-2093.69995117,-160.19999695,34.59999847}, //Object number 494
	{-2093.80004883,-159.00000000,34.59999847}, //Object number 495
	{-2088.00000000,-159.19999695,34.59999847}, //Object number 496
	{-2087.30004883,-157.89999390,34.59999847}, //Object number 497
	{-2086.60009766,-157.39999390,34.59999847}, //Object number 498
	{-2085.39990234,-156.60000610,34.59999847}, //Object number 499
	{-2084.19995117,-155.80000305,34.59999847}, //Object number 500
	{-2083.19995117,-155.00000000,34.59999847}, //Object number 501
	{-2093.60009766,-157.89999390,34.59999847}, //Object number 502
	{-2093.10009766,-156.89999390,34.59999847}, //Object number 503
	{-2092.39990234,-156.10000610,34.59999847}, //Object number 504
	{-2091.69995117,-155.30000305,34.59999847}, //Object number 505
	{-2090.69995117,-154.50000000,34.59999847}, //Object number 506
	{-2090.00000000,-153.69999695,34.59999847}, //Object number 507
	{-2089.00000000,-152.89999390,34.59999847}, //Object number 508
	{-2088.30004883,-152.10000610,34.59999847}, //Object number 509
	{-2087.60009766,-151.80000305,34.59999847}, //Object number 510
	{-2086.89990234,-151.30000305,34.59999847}, //Object number 511
	{-2086.19995117,-150.80000305,34.59999847}, //Object number 512
	{-2085.50000000,-150.30000305,34.59999847}, //Object number 513
	{-2084.50000000,-149.80000305,34.59999847}, //Object number 514
	{-2083.50000000,-149.30000305,34.59999847}, //Object number 515
	{-2083.50000000,-149.29980469,34.59999847}, //Object number 516
	{-2083.00000000,-148.60000610,34.59999847}, //Object number 517
	{-2082.69995117,-147.60000610,34.59999847}, //Object number 518
	{-2082.69995117,-146.60000610,34.59999847}, //Object number 519
	{-2082.69995117,-145.80000305,34.59999847}, //Object number 520
	{-2082.69995117,-144.60000610,34.59999847}, //Object number 521
	{-2082.69995117,-143.30000305,34.59999847}, //Object number 522
	{-2082.69995117,-142.50000000,34.59999847}, //Object number 523
	{-2082.69995117,-141.30000305,34.59999847}, //Object number 524
	{-2082.69995117,-140.30000305,34.59999847}, //Object number 525
	{-2082.69995117,-139.10000610,34.59999847}, //Object number 526
	{-2082.00000000,-154.39999390,34.59999847}, //Object number 527
	{-2081.19995117,-153.89999390,34.59999847}, //Object number 528
	{-2080.39990234,-153.19999695,34.59999847}, //Object number 529
	{-2079.60009766,-152.50000000,34.59999847}, //Object number 530
	{-2079.10009766,-151.80000305,34.59999847}, //Object number 531
	{-2078.30004883,-151.10000610,34.59999847}, //Object number 532
	{-2077.80004883,-150.39999390,34.59999847}, //Object number 533
	{-2077.50000000,-149.69999695,34.59999847}, //Object number 534
	{-2077.19995117,-148.69999695,34.59999847}, //Object number 535
	{-2077.19995117,-147.69999695,34.59999847}, //Object number 536
	{-2077.19995117,-146.39999390,34.59999847}, //Object number 537
	{-2077.19995117,-145.39999390,34.59999847}, //Object number 538
	{-2077.19995117,-144.39999390,34.59999847}, //Object number 539
	{-2077.19995117,-143.60000610,34.59999847}, //Object number 540
	{-2077.19995117,-142.60000610,34.59999847}, //Object number 541
	{-2077.19995117,-141.80000305,34.59999847}, //Object number 542
	{-2077.19995117,-141.30000305,34.59999847}, //Object number 543
	{-2077.19995117,-140.10000610,34.59999847}, //Object number 544
	{-2077.19995117,-139.10000610,34.59999847}, //Object number 545
	{-2077.19995117,-138.30000305,34.59999847}, //Object number 546
	{-2077.19995117,-137.50000000,34.59999847}, //Object number 547
	{-2076.69995117,-136.30000305,34.59999847}, //Object number 548
	{-2075.69995117,-135.60000610,34.59999847}, //Object number 549
	{-2074.69995117,-135.39999390,34.59999847}, //Object number 550
	{-2073.19995117,-135.19999695,34.59999847}, //Object number 551
	{-2072.39990234,-135.19999695,34.59999847}, //Object number 552
	{-2071.60009766,-135.19999695,34.59999847}, //Object number 553
	{-2070.60009766,-135.19999695,34.59999847}, //Object number 554
	{-2069.30004883,-135.19999695,34.59999847}, //Object number 555
	{-2068.50000000,-135.19999695,34.59999847}, //Object number 556
	{-2067.50000000,-135.19999695,34.59999847}, //Object number 557
	{-2082.60009766,-137.89999390,34.59999847}, //Object number 558
	{-2082.60009766,-136.60000610,34.59999847}, //Object number 559
	{-2082.60009766,-135.80000305,34.59999847}, //Object number 560
	{-2082.60009766,-135.00000000,34.59999847}, //Object number 561
	{-2082.60009766,-134.50000000,34.59999847}, //Object number 562
	{-2082.60009766,-133.30000305,34.59999847}, //Object number 563
	{-2082.60009766,-132.50000000,34.59999847}, //Object number 564
	{-2082.10009766,-131.50000000,34.59999847}, //Object number 565
	{-2081.60009766,-131.00000000,34.59999847}, //Object number 566
	{-2080.60009766,-130.50000000,34.59999847}, //Object number 567
	{-2079.60009766,-130.30000305,34.59999847}, //Object number 568
	{-2078.80004883,-130.30000305,34.59999847}, //Object number 569
	{-2077.50000000,-130.30000305,34.59999847}, //Object number 570
	{-2076.80004883,-130.30000305,34.59999847}, //Object number 571
	{-2075.50000000,-130.30000305,34.59999847}, //Object number 572
	{-2074.80004883,-130.30000305,34.59999847}, //Object number 573
	{-2074.00000000,-130.30000305,34.59999847}, //Object number 574
	{-2073.30004883,-130.30000305,34.59999847}, //Object number 575
	{-2072.30004883,-130.30000305,34.59999847}, //Object number 576
	{-2071.30004883,-130.30000305,34.59999847}, //Object number 577
	{-2070.30004883,-130.30000305,34.59999847}, //Object number 578
	{-2069.00000000,-130.30000305,34.59999847}, //Object number 579
	{-2067.30004883,-130.30000305,34.59999847}, //Object number 580
	{-2065.80004883,-130.30000305,34.59999847}, //Object number 581
	{-2065.89990234,-135.30000305,34.59999847}, //Object number 582
	{-2064.39990234,-135.30000305,34.59999847}, //Object number 583
	{-2062.60009766,-135.30000305,34.59999847}, //Object number 584
	{-2060.80004883,-135.30000305,34.59999847}, //Object number 585
	{-2060.00000000,-135.30000305,34.59999847}, //Object number 586
	{-2063.89990234,-130.19999695,34.59999847}, //Object number 587
	{-2062.89990234,-130.19999695,34.59999847}, //Object number 588
	{-2061.10009766,-130.19999695,34.59999847}, //Object number 589
	{-2059.80004883,-130.19999695,34.59999847}, //Object number 590
	{-2059.79980469,-130.19921875,34.59999847} //Object number 591
};