
#pragma region 姥繕端人 壕伸 匂昔斗 奄沙 森薦
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
};

int main()
{
	/*
	point 姥繕端. 呉獄2鯵

	main()
	- 掩戚亜 3昔 point莫 壕伸 arr識情
	- 室 繊税 疎妊 脊径 閤奄
	- 室 繊税 疎妊 窒径
	*/
	struct point arr[3];
	int i, len;
	len = sizeof(arr) / sizeof(struct point);

	// 脊径
	for (i = 0; i < len; i++)
	{
		printf("繊税 疎妊 脊径: ");
		scanf_s("%d %d", &arr[i].xpos, &arr[i].ypos);
	}

	// 窒径
	for (i = 0; i < len; i++)
		printf("[%d, %d] \n", arr[i].xpos, arr[i].ypos);

	return 0;
}

#pragma endregion


#pragma region 尻柔庚薦 -> 送据舛左(姥繕端 壕伸)
#include <stdio.h>

struct employee
{
	char name[50];
	char addr_num[15];
	int  salary;
};


int main()
{
	/* 尻柔庚薦
	掩戚亜 3昔 壕伸稽 識情馬壱
	室 誤税 舛左研 脊径 閤焼辞 壕伸拭 煽舌廃 陥製, 壕伸拭 煽舌吉 汽戚斗研
	授辞企稽 窒径馬澗 森薦研 拙失廃陥.
	*/
	struct employee emp[3] = { 0, };
	int i, len;
	len = sizeof(emp) / sizeof(struct employee);

	for (i = 0; i < len; i++)
	{
		fputs("戚硯精?: ", stdout);
		scanf_s("%s", emp[i].name, (unsigned int)sizeof(emp[i].name));
		fputs("爽肯去系腰硲澗?: ", stdout);
		scanf_s("%s", emp[i].addr_num, (unsigned int)sizeof(emp[i].addr_num));
		fputs("杉厭精?: ", stdout);
		scanf_s("%d", &emp[i].salary);
	}

	printf("--- 送据 舛左 ---\n");
	for (i = 0; i < len; i++)
	{
		printf("戚硯		: %s \n", emp[i].name);
		printf("爽肯去系腰硲: %s \n", emp[i].addr_num);
		printf("蟹戚		: %d \n\n", emp[i].salary);
	}

	return 0;
}


#pragma endregion


#pragma region 姥繕端 匂昔斗 森獣
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xPos;
	int yPos;
};

int main()
{
	/*
	point 姥繕端 舛税.

	main()
	- point莫 痕呪 pos1. 1,2 稽 識疑段
	- point莫 痕呪 pos2. 100,200 稽 識疑段
	- point莫 匂昔斗 痕呪 pptr. pos1税 爽社稽 識疑段
	- pptr聖 醗遂背 x疎妊 4装亜
	- pptr聖 醗遂背 y疎妊 4装亜
	- pptr聖 醗遂背 疎妊 窒径

	- pptr. pos2税 爽社稽 段奄鉢
	- pptr聖 醗遂背 x疎妊 1装亜
	- pptr聖 醗遂背 y疎妊 2装亜
	- pptr聖 醗遂背 疎妊 窒径
	*/
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1;

	// (*pptr).member 莫殿
	(*pptr).xPos += 4;
	(*pptr).yPos += 4;
	printf("[%d,%d] \n", (*pptr).xPos, (*pptr).yPos);

	// pptr->member 莫殿
	pptr = &pos2;
	pptr->xPos += 1;
	pptr->yPos += 2;
	printf("[%d,%d] \n", pptr->xPos, pptr->yPos);

	return 0;
}




#pragma endregion


#pragma region 公 熱醸醸揮 姥繕端 匂昔斗 森薦 ( 走榎精 熱醸製 )
// start
// #include "header.h"
#include <stdio.h>

struct point
{
	int xPos;
	int yPos;
};

struct circle
{
	double radius;
	struct point* center; // 食奄 匂昔斗研 爽澗 暗心刊..
};

int main()
{
	/*
	point 姥繕端 舛税.

	circle 姥繕端 舛税.
	- 叔呪 radius(鋼走硯)
	- 切戟莫 -> 搾腔 / 痕呪誤 center ( main 敗呪亜 微闘 )

	main ( ) 5匝績
	- ??? cen. 2, 7稽 識疑段 ( 疎妊 )
	- ??? rad. 5.5 識疑段
	- ??? ring. 鋼走硯引 据税 掻宿 疎妊稽 識疑段 -> 糎仙戚政?
	- 据税 鋼走硯: 強 窒径
	- 据税 掻宿 [強, 強] 窒径 ( 疎妊 )
	*/
	struct point cen = { 2, 7 };
	double rad = 5.5;
	struct circle ring = { rad, &cen };
	// 焼竃 cen税 爽社葵聖 爽形檎 circle 照拭 赤澗 center稽 匂昔斗 痕呪稽
	// 識情聖 梅醸嬢醤走 生焼たたたたたたたたたたたたたたたたたたたたた
	printf("据税 鋼走硯: %.1f \n", ring.radius);
	printf("据税 掻宿 [%d, %d] \n", ring.center->xPos, (*ring.center).yPos);

	// 姥繕端 匂昔斗研 潤醤拝 依 旭精汽
	// struct circle ring = { rad, cen }; 
	/*
	printf("据税 鋼走硯: %.1f \n", ring.radius);
	printf("据税 掻宿 [%d, %d] \n", ring.center.xPos, ring.center.yPos);
	*/

	return 0;
}



#pragma endregion


#pragma region 尻柔庚薦 -> 姥繕端人 壕伸税 因搭繊引 託戚繊
// start
// #include "header.h"
#include <stdio.h>

struct info
{
	char id[50];
	char passwd[30];
	char name[50];
	int age;
};

int main()
{
	/*
	昔斗掛 朝凪 噺据 1誤税 焼戚巨(smartC), 搾腔腰硲(sm8448), 蟹戚(20), 戚硯(重室企)
	舛左研 痕呪稽 識情敗引 疑獣拭 段奄鉢 廃 板 窒径馬壱切 廃陥.
	噺据税 舛左研 姥繕端研 紫遂馬走 省壱 坦軒馬澗 覗稽益轡引, -> ?
	姥繕端研 紫遂馬澗 覗稽益轡,
	砧 鯵研 拙失廃 板 姥繕端人 壕伸税 旭精 繊引 託戚繊聖 搾嘘 竺誤
	*/
	// 姥繕端 紫遂
	struct info member = { "smartC", "sm8448", "重室企", 20 };
	// 窒径
	printf("焼戚巨: %s \n搾腔腰硲: %s\n戚硯: %s\n蟹戚: %d\n\n", member.id, member.passwd, member.name, member.age);


	// 姥繕端 耕紫遂 ->
	char* memberArr[4] = { "smartA", "sm1234", "MZ", "15" };

	//窒径
	printf("焼戚巨: %s \n搾腔腰硲: %s\n戚硯: %s\n蟹戚: %s\n\n", memberArr[0], memberArr[1], memberArr[2], memberArr[3]);

	/*
	因搭繊
	壕伸聖 紫遂馬食 葵聖 煽舌馬壱 窒径拝 呪 赤陥.

	託戚繊
	壕伸精 姥繕端人 陥牽惟 旭精 切戟莫級晦軒幻 煽舌拝 呪 赤壱,
	姥繕端澗 辞稽 陥献 切戟莫生稽亀 煽舌拝 呪 赤陥.

	printf拝 凶 [] .id 去 妊薄戚 陥硯

	壕伸精 仙紫遂拭 嬢形崇戚 赤走幻,
	姥繕端澗 壕伸聖 紫遂馬檎辞 益 壕伸聖 嬢巨辞窮走 陥獣 紫遂拝 呪 赤惟
	切戟莫生稽 壕伸戚蟹 痕呪級聖 舛税馬食 陥獣 紫遂拝 呪 赤陥.
	*/


	return 0;
}



#pragma endregion


#pragma region 尻柔庚薦 -> 堂鍵 員 達奄
// start
// #include "header.h"
#include <stdio.h>

struct rectangle {
	// 姥繕端 照拭辞 識情引 疑獣拭 段奄鉢研 馬形梅製
	int width, height, area;
};
// } 戚係惟幻 床食閃赤聖 凶 庚薦澗 舛税亜 魁蟹走 省紹製	  ; 稽 魁鎧醤敗 !

int main() // 尻柔庚薦
{
	// rectangle r1 = { 3,7 }, r2 = { 2,5 }; // 切戟莫切端亜 堂携製, struct 皐股醸奄凶庚
	struct rectangle r1 = { 3,7 }, r2 = { 2,5 };
	// int larger; 
	//	眼焼鎧形馬澗 切戟莫戚 陥硯, r1戚蟹 r2研 眼焼鎧醤馬澗汽 
	//	4郊戚闘稽 12郊戚闘税 鎧遂聖 眼焼鎧形梅奄凶庚 !
	struct rectangle larger;
	r1.area = r1.width * r1.height;
	r2.area = r2.width * r2.height;

	// if ( r1 > r2 ) // 姥繕端税 呉獄 掻 檎旋聖 搾嘘背醤馬糠稽 姥繕端.area 研 搾嘘背醤敗
	if (r1.area > r2.area)
		larger = r1;
	else
		larger = r2;
	printf("希 笛 紫唖莫税 檎旋精 %d脊艦陥.", larger.area);


	return 0;
}




#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





