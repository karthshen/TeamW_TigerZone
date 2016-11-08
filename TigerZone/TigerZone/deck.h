stack board::makedeck(){
//side: field = 1, town = 2, field with road = 3
//cent: field = 1, connected town = 2, crossroad = 3, monastery = 4
//shield: 1 = true, 0 = false	
	//initialize an array of tiles to form the pieces of a deck
	tile deck[72];
	
	deck[0] 	= tile(2,3,3,2,2,0); deck[1] 	= tile(2,3,3,2,2,0); deck[2] 	= tile(2,3,3,2,2,0);
	deck[3] 	= tile(2,2,1,2,2,1);
	deck[4] 	= tile(2,2,1,2,2,1); deck[5] 	= tile(2,2,1,2,2,1); deck[6] 	= tile(2,2,1,2,2,1);
	deck[7] 	= tile(2,1,1,2,2,1); deck[8] 	= tile(2,1,1,2,2,1);
	deck[9] 	= tile(2,1,1,2,2,0); deck[10] 	= tile(2,1,1,2,2,0); deck[11] 	= tile(2,1,1,2,2,0);
	deck[12] 	= tile(2,3,3,2,2,1); deck[13] 	= tile(2,3,3,2,2,1); 

	deck[14] 	= tile(1,1,3,3,1,0); deck[15] 	= tile(1,1,3,3,1,0); deck[16] 	= tile(1,1,3,3,1,0);
	deck[17] 	= tile(1,1,3,3,1,0); deck[18] 	= tile(1,1,3,3,1,0); deck[19] 	= tile(1,1,3,3,1,0);
	deck[20] 	= tile(1,1,3,3,1,0); deck[21] 	= tile(1,1,3,3,1,0); deck[22] 	= tile(1,1,3,3,1,0);

	deck[23] 	= tile(1,3,3,3,3,0); deck[24] 	= tile(1,3,3,3,3,0); deck[25] 	= tile(1,3,3,3,3,0); deck[26] 	= tile(1,3,3,3,3,0);
	deck[27] 	= tile(3,3,3,3,3,0);
	deck[28] 	= tile(2,2,3,2,2,1); deck[29] 	= tile(2,2,3,2,2,1);
	deck[30] 	= tile(2,2,3,2,2,0);

	deck[31] 	= tile(1,3,1,3,1,0); deck[32] 	= tile(1,3,1,3,1,0); deck[33] 	= tile(1,3,1,3,1,0); deck[34] 	= tile(1,3,1,3,1,0);
	deck[35] 	= tile(1,3,1,3,1,0); deck[36] 	= tile(1,3,1,3,1,0); deck[37] 	= tile(1,3,1,3,1,0); deck[38] 	= tile(1,3,1,3,1,0);

	deck[39] 	= tile(2,3,3,3,3,0); deck[40] 	= tile(2,3,3,3,3,0); deck[41] 	= tile(2,3,3,3,3,0);
	deck[42] 	= tile(2,2,2,2,2,1);
	deck[43] 	= tile(2,3,1,3,1,0); deck[44] 	= tile(2,3,1,3,1,0); deck[45] 	= tile(2,3,1,3,1,0); deck[46] 	= tile(2,3,1,3,1,0);

	deck[47] 	= tile(2,1,1,1,1,0); deck[48] 	= tile(2,1,1,1,1,0); deck[49] 	= tile(2,1,1,1,1,0); 
	deck[50] 	= tile(2,1,1,1,1,0); deck[51] 	= tile(2,1,1,1,1,0);

	deck[52] 	= tile(1,1,3,1,4,0); deck[53] 	= tile(1,1,3,1,4,0);
	deck[54] 	= tile(1,1,1,1,4,0); deck[55] 	= tile(1,1,1,1,4,0); deck[56] 	= tile(1,1,1,1,4,0); deck[57] 	= tile(1,1,1,1,4,0);
	deck[58] 	= tile(2,1,1,2,1,0); deck[59] 	= tile(2,1,1,2,1,0);

	deck[60] 	= tile(2,3,3,1,1,0); deck[61] 	= tile(2,3,3,1,1,0); deck[62] 	= tile(2,3,3,1,1,0);

	deck[63] 	= tile(2,1,3,3,1,0); deck[64] 	= tile(2,1,3,3,1,0); deck[65] 	= tile(2,1,3,3,1,0);

	deck[66] 	= tile(1,2,1,2,2,1); deck[67] 	= tile(1,2,1,2,2,1);

	deck[68] 	= tile(1,2,1,2,2,0);

	deck[69] 	= tile(1,2,1,2,1,0); deck[70] 	= tile(1,2,1,2,1,0); deck[71] 	= tile(1,2,1,2,1,0);

	//will need to also form a stack using these values.
	//Use deck[45] as the starting tile.
	//incorporate RNG with removal for randomized deck stack later down the line
}