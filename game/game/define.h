#pragma once



#define FREEKEY	0x10	// 눌르지 않은 상태. // 00010000
#define PULLKEY	0x20	// 눌렀다 띄었을때   // 00100000
#define PUSHKEY	0x40	// 누르자 마자      // 01000000
#define HOLDKEY	0x80	// 누르고 있는 중    // 10000000


#define CHARACTERMOVESPEED	5
#define ENEMYTYPE1MOVESPEED 2