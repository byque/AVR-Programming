// A font alphabet in 5x8
 


const uint8_t thinFont[94][5] = {
	//     -- ASCII 32
	{0, 0, 0, 0, 0},
	//  !  -- ASCII 33
	{0, 0, 223, 0, 0},
	//  "  -- ASCII 34
	{0, 3, 0, 3, 0},
	//  #  -- ASCII 35
	{36, 255, 36, 255, 36},
	//  $  -- ASCII 36
	{76, 146, 255, 146, 100},
	//  %  -- ASCII 37
	{2, 197, 50, 76, 163},
	//  &  -- ASCII 38
	{96, 150, 153, 102, 144},
	//  '  -- ASCII 39
	{0, 0, 3, 0, 0},
	//  (  -- ASCII 40
	{0, 60, 66, 129, 0},
	//  )  -- ASCII 41
	{0, 129, 66, 60, 0},
	//  *  -- ASCII 42
	{16, 84, 56, 84, 16},
	//  +  -- ASCII 43
	{16, 16, 124, 16, 16},
	//  ,  -- ASCII 44
	{0, 0, 192, 0, 0},
	//  -  -- ASCII 45
	{16, 16, 16, 16, 16},
	//  .  -- ASCII 46
	{0, 0, 192, 192, 0},
	//  /  -- ASCII 47
	{0, 192, 48, 12, 3},
	//  0  -- ASCII 48
	{126, 145, 137, 133, 126},
	//  1  -- ASCII 49
	{0, 130, 255, 128, 0},
	//  2  -- ASCII 50
	{198, 161, 145, 137, 134},
	//  3  -- ASCII 51
	{66, 129, 137, 137, 118},
	//  4  -- ASCII 52
	{48, 40, 36, 34, 255},
	//  5  -- ASCII 53
	{79, 137, 137, 137, 113},
	//  6  -- ASCII 54
	{126, 137, 137, 137, 112},
	//  7  -- ASCII 55
	{1, 1, 225, 25, 7},
	//  8  -- ASCII 56
	{118, 137, 137, 137, 118},
	//  9  -- ASCII 57
	{14, 145, 145, 145, 126},
	//  :  -- ASCII 58
	{0, 0, 204, 0, 0},
	//  ;  -- ASCII 59
	{0, 0, 64, 40, 0},
	//  <  -- ASCII 60
	{0, 16, 40, 68, 130},
	//  =  -- ASCII 61
	{36, 36, 36, 36, 36},
	//  >  -- ASCII 62
	{0, 130, 68, 40, 16},
	//  ?  -- ASCII 63
	{2, 1, 185, 5, 2},
	//  @  -- ASCII 64
	{126, 129, 153, 165, 190},
	//  A  -- ASCII 65
	{254, 17, 17, 17, 254},
	//  B  -- ASCII 66
	{255, 137, 137, 137, 118},
	//  C  -- ASCII 67
	{126, 129, 129, 129, 66},
	//  D  -- ASCII 68
	{255, 129, 129, 66, 60},
	//  E  -- ASCII 69
	{255, 137, 137, 137, 129},
	//  F  -- ASCII 70
	{255, 9, 9, 9, 1},
	//  G  -- ASCII 71
	{126, 129, 145, 145, 114},
	//  H  -- ASCII 72
	{255, 8, 8, 8, 255},
	//  I  -- ASCII 73
	{0, 129, 255, 129, 0},
	//  J  -- ASCII 74
	{96, 128, 129, 127, 1},
	//  K  -- ASCII 75
	{255, 24, 36, 66, 129},
	//  L  -- ASCII 76
	{255, 128, 128, 128, 128},
	//  M  -- ASCII 77
	{255, 2, 4, 2, 255},
	//  N  -- ASCII 78
	{255, 4, 8, 16, 255},
	//  O  -- ASCII 79
	{126, 129, 129, 129, 126},
	//  P  -- ASCII 80
	{255, 17, 17, 17, 14},
	//  Q  -- ASCII 81
	{126, 129, 193, 129, 126},
	//  R  -- ASCII 82
	{255, 17, 49, 81, 142},
	//  S  -- ASCII 83
	{70, 137, 137, 137, 114},
	//  T  -- ASCII 84
	{1, 1, 255, 1, 1},
	//  U  -- ASCII 85
	{127, 128, 128, 128, 127},
	//  V  -- ASCII 86
	{7, 56, 192, 56, 7},
	//  W  -- ASCII 87
	{255, 64, 32, 64, 255},
	//  X  -- ASCII 88
	{195, 36, 24, 36, 195},
	//  Y  -- ASCII 89
	{3, 12, 240, 12, 3},
	//  Z  -- ASCII 90
	{225, 145, 137, 133, 131},
	//  [  -- ASCII 91
	{0, 255, 129, 129, 0},
	//  \  -- ASCII 92
	{0, 3, 12, 48, 192},
	//  ]  -- ASCII 93
	{0, 129, 129, 255, 0},
	//  ^  -- ASCII 94
	{2, 1, 0, 1, 2},
	//  _  -- ASCII 95
	{0, 0, 0, 0, 0},
	//  `  -- ASCII 96
	{0, 0, 0, 0, 0},
	//  a  -- ASCII 97
	{96, 148, 148, 148, 248},
	//  b  -- ASCII 98
	{255, 132, 132, 132, 120},
	//  c  -- ASCII 99
	{120, 132, 132, 132, 72},
	//  d  -- ASCII 100
	{120, 132, 132, 132, 255},
	//  e  -- ASCII 101
	{120, 148, 148, 148, 88},
	//  f  -- ASCII 102
	{0, 4, 254, 5, 1},
	//  g  -- ASCII 103
	{120, 132, 132, 132, 252},
	//  h  -- ASCII 104
	{255, 4, 4, 4, 248},
	//  i  -- ASCII 105
	{0, 132, 253, 128, 0},
	//  j  -- ASCII 106
	{0, 0, 0, 4, 253},
	//  k  -- ASCII 107
	{0, 255, 48, 72, 132},
	//  l  -- ASCII 108
	{0, 129, 255, 128, 0},
	//  m  -- ASCII 109
	{252, 4, 252, 4, 248},
	//  n  -- ASCII 110
	{252, 4, 4, 4, 248},
	//  o  -- ASCII 111
	{120, 132, 132, 132, 120},
	//  p  -- ASCII 112
	{252, 132, 132, 132, 120},
	//  q  -- ASCII 113
	{120, 132, 132, 132, 252},
	//  r  -- ASCII 114
	{252, 8, 4, 4, 4},
	//  s  -- ASCII 115
	{136, 148, 148, 148, 100},
	//  t  -- ASCII 116
	{0, 4, 127, 132, 128},
	//  u  -- ASCII 117
	{124, 128, 128, 128, 252},
	//  v  -- ASCII 118
	{12, 48, 192, 48, 12},
	//  w  -- ASCII 119
	{124, 128, 240, 128, 124},
	//  x  -- ASCII 120
	{132, 72, 48, 72, 132},
	//  y  -- ASCII 121
	{124, 128, 128, 128, 252},
	//  z  -- ASCII 122
	{196, 164, 148, 140, 132},
	//  {  -- ASCII 123
	{0, 8, 118, 129, 129},
	//  |  -- ASCII 124
	{0, 0, 255, 0, 0},
	//  }  -- ASCII 125
	{0, 129, 129, 118, 8},
};

