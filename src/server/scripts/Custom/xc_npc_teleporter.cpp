#include "ScriptPCH.h"
/*
GOSSIP_ICON_CHAT       =  0 // white chat bubble
GOSSIP_ICON_VENDOR     =  1 // brown bag
GOSSIP_ICON_TAXI       =  2 // flightmarker (paperplane)
GOSSIP_ICON_TRAINER    =  3 // brown book (trainer)
GOSSIP_ICON_INTERACT_1 =  4 // golden interaction wheel
GOSSIP_ICON_INTERACT_2 =  5 // golden interaction wheel
GOSSIP_ICON_MONEY_BAG  =  6 // brown bag (with gold coin in lower corner)
GOSSIP_ICON_TALK       =  7 // white chat bubble (with "..." inside)
GOSSIP_ICON_TABARD     =  8 // white tabard
GOSSIP_ICON_BATTLE     =  9 // two crossed swords
GOSSIP_ICON_DOT        = 10 // yellow dot/point
*/
class npc_teleporter : public CreatureScript
{
private:
    enum telePayPrices
    {
        PRICE_FACTIONCHANGE = 500000000,  // Factionchange price
        PRICE_RACECHANGE = 50000000,    // Racechange price
    };
    bool tele_pay(telePayPrices price, Player * player)
    {
        if(player->GetMoney() < uint32(price))
            return false;
        player->ModifyMoney( - int32(price) );
        return true;
    }

public:
    npc_teleporter() : CreatureScript("npc_teleporter") { }
 
    bool OnGossipHello(Player* player, Creature* creature)
        {
        player->ADD_GOSSIP_ITEM(3, sObjectMgr->GBKToUtf8("世界那么大，我想去看看（传送）"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
		player->ADD_GOSSIP_ITEM(3, sObjectMgr->GBKToUtf8("更改阵营和种族"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
		player->ADD_GOSSIP_ITEM(3, sObjectMgr->GBKToUtf8("辅助功能"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 400);
        
		/* if (player->getLevel() == 1)
        {
            player->ADD_GOSSIP_ITEM(6, "Character level boost na 80 [Mozne pouze na levelu 1]", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1000);
        }
        else
            {} */
		
        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        return true;
    }
 
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /* sender */, uint32 actions)
    {
        player->PlayerTalkClass->ClearMenus();
 
        switch (actions)
        {   
			case GOSSIP_ACTION_INFO_DEF+500:
				player->ADD_GOSSIP_ITEM(3, sObjectMgr->GBKToUtf8("世界那么大，我想去看看（传送）"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
				player->ADD_GOSSIP_ITEM(3, sObjectMgr->GBKToUtf8("更改种族和职业"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 99);
				player->ADD_GOSSIP_ITEM(3, sObjectMgr->GBKToUtf8("辅助功能"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 400);
                player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                break;
			//default menu in Teleporty
            case GOSSIP_ACTION_INFO_DEF+1:
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("主要城市"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("五人副本"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("团队副本"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
				player->ADD_GOSSIP_ITEM(9, sObjectMgr->GBKToUtf8("四大竞技场"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("野外PVP"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回主菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 500);
                player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                break;
            //default menu in Hlavni Mesta
              case GOSSIP_ACTION_INFO_DEF+2:
                if (player->GetTeam() == ALLIANCE)
                { //Teleporty->Alliance
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("暴风城"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("铁炉堡"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("达纳苏斯"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("埃索达"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
                }
                else if (player->GetTeam() == HORDE)
                { //Teleporty->Horda
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("奥格瑞玛"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("雷霆崖"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("幽暗城"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
					player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("银月城"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);					
                } // Teleporty->Neutral
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("达拉然"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("沙塔斯城"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                break;
// -----------------------------------------------------------------------------------------------------------------------------------
            // @TODO
            // Teleporty->Dungeony
            case GOSSIP_ACTION_INFO_DEF+3:
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("60年代经典旧世"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 101);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("70年代燃烧的远征"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 102);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("80年代巫妖王之怒"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 103);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                break;
                  
            case GOSSIP_ACTION_INFO_DEF+101:
				if (player->GetTeam() == HORDE)
                  {
					  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("怒焰裂谷(13-20)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 258); //og dungeon
                  }
                else if (player->GetTeam() == ALLIANCE)
                  {
					  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("暴风城监狱(21-29)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 265); //sw dungeon
                  }
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("死亡矿井(16-24)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 253);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("哀嚎洞穴(16-24)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 269);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("影牙城堡(17-25)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 264);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("黑暗深渊(20-28)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 251);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("诺莫瑞根(24-40)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 255);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("剃刀沼泽(23-31)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 260);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("剃刀高地(33-41)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 259);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("血色大厅(28-44)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 261);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("血色修道院(28-44)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 262);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("奥达曼(36-44)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 268);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("祖尔法拉克(42-50)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 270);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("玛拉顿(橙色)(40-52)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 257);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("玛拉顿(紫色)(40-52)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 271);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("沉没的神庙(45-54)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 267);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("厄运之槌(54-61)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 254);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("黑石深渊(48-60)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 252);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("黑石塔(53-61)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 256);	  
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("通灵学院(56-61)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 263);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("斯坦索姆(56-61)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 266);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                break;

            //Teleporty->Dungeony->Classic->Blackfathom Deeps
            case GOSSIP_ACTION_INFO_DEF+251:
                  player->TeleportTo(1, 4249.990234f, 740.101990f, -25.671000f, 1.444685f);
                  break;
            //Teleporty->Dungeony->Classic->Blackrock Depths
            case GOSSIP_ACTION_INFO_DEF+252:
                  player->TeleportTo(0, -7185.222168f, -914.324890f, 165.490677f, 5.282977f);
                  break;
            //Teleporty->Dungeony->Classic->Deadmines
            case GOSSIP_ACTION_INFO_DEF+253:
                  player->TeleportTo(36, -14.429828f, -384.258636f, 62.045132f, 4.703894f);
                  break;
            //Teleporty->Dungeony->Classic->Dire Maul
            case GOSSIP_ACTION_INFO_DEF+254:
                  player->TeleportTo(1, -3825.994629f, 1250.354736f, 160.228470f, 3.208350f);
                  break;
            //Teleporty->Dungeony->Classic->Gnomeregan
            case GOSSIP_ACTION_INFO_DEF+255:
                  player->TeleportTo(0, -5163.528320f, 922.043518f, 257.177643f, 1.472134f);
                  break;
            //Teleporty->Dungeony->Classic->Lower Blackrock Spire
            case GOSSIP_ACTION_INFO_DEF+256:
                  player->TeleportTo(0, -7527.928223f, -1225.440918f, 285.731995f, 5.296260f);
                  break;
            //Teleporty->Dungeony->Classic->Maraudon (Orange)
            case GOSSIP_ACTION_INFO_DEF+257:
                  player->TeleportTo(1, -1463.166504f, 2618.319092f, 76.945068f, 3.271252f);
                  break;
            //Teleporty->Dungeony->Classic->Maraudon (Purple)
            case GOSSIP_ACTION_INFO_DEF+271:
                  player->TeleportTo(1, -1189.408691f, 2882.358887f, 85.834839f, 5.073660f);
                  break;
            //Teleporty->Dungeony->Classic->Ragefire Chasm
            case GOSSIP_ACTION_INFO_DEF+258:
                  player->TeleportTo(1, 1810.191772f, -4407.271484f,  -18.738428f, 5.168476f);
                  break;
            //Teleporty->Dungeony->Classic->Razorfen Downs
            case GOSSIP_ACTION_INFO_DEF+259:
                  player->TeleportTo(1, -4656.138672f, -2521.188477f, 81.194313f, 4.243077f);
                  break;
            //Teleporty->Dungeony->Classic->Razorfen Kraul
            case GOSSIP_ACTION_INFO_DEF+260:
                  player->TeleportTo(1, -4467.738770f, -1669.918579f, 81.893188f, 0.969829f);
                  break;
            //Teleporty->Dungeony->Classic->Scarlet Halls
            case GOSSIP_ACTION_INFO_DEF+261:
                  player->TeleportTo(0, 2876.619141f, -817.552795f, 160.332947f, 3.489504f);
                  break;
            //Teleporty->Dungeony->Classic->Scarlet Monastery
            case GOSSIP_ACTION_INFO_DEF+262:
                  player->TeleportTo(0, 2910.298828f, -803.588074f, 160.332001f, 0.431354f);
                  break;
            //Teleporty->Dungeony->Classic->Scholomance
            case GOSSIP_ACTION_INFO_DEF+263:
                  player->TeleportTo(0, 1269.640015f, -2556.209961f, 93.608795f, 0.410529f);
                  break;
            //Teleporty->Dungeony->Classic->Shadowfang Keep
            case GOSSIP_ACTION_INFO_DEF+264:
                  player->TeleportTo(0, -234.518295f, 1563.581299f, 76.892097f, 1.171587f);
                  break;
            //Teleporty->Dungeony->Classic->Stormwind Stockade
            case GOSSIP_ACTION_INFO_DEF+265:
                  player->TeleportTo(0, -8774.969727f, 838.182617f, 92.325050f, 0.661656f);
                  break;
            //Teleporty->Dungeony->Classic->Stratholme
            case GOSSIP_ACTION_INFO_DEF+266:
                  player->TeleportTo(0, 3387.753174f, -3342.637695f, 142.263321f, 4.949344f);
                  break;
            //Teleporty->Dungeony->Classic->Sunken Temple
            case GOSSIP_ACTION_INFO_DEF+267:
                  player->TeleportTo(0, -10180.093750f, -3994.306152f, -110.021835f, 6.018850f);
                  break;
            //Teleporty->Dungeony->Classic->Uldaman
            case GOSSIP_ACTION_INFO_DEF+268:
                  player->TeleportTo(0, -6069.571777f, -2955.145752f, 209.777130f, 0.045160f);
                  break;
            //Teleporty->Dungeony->Classic->Wailing Caverns
            case GOSSIP_ACTION_INFO_DEF+269:
                  player->TeleportTo(1, -734.069763f, -2217.539551f, 16.951948f, 2.812345f);
                  break;
            //Teleporty->Dungeony->Classic->Zul'Farrak
            case GOSSIP_ACTION_INFO_DEF+270:
                  player->TeleportTo(1, -6801.189941f, -2893.020020f, 9.003880f, 0.158639f);
                  break;

            case GOSSIP_ACTION_INFO_DEF+102:
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("地狱火城墙(60-62)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+285);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("鲜血熔炉(61-63)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+286);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("破碎大厅(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+287);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("奴隶围栏(62-64)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+282);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("蒸汽地窖(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+283);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("幽暗沼泽(63-65)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+284);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("奥金尼地穴(65-67)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+276);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("法力陵墓(64-66)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+277);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("塞泰克大厅(67-69)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+278);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("暗影迷宫(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+279);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("能源舰(69-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+290);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("生态船(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+289);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("禁魔监狱(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+288);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("时光之穴-黑色沼泽(69-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+280);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("时光之穴-旧希尔斯布莱德丘陵(66-68)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+281);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("魔导师平台(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+275);
				  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  break;

            //Teleporty->Dungeony->TBC->Magister's Terrace
            case GOSSIP_ACTION_INFO_DEF+275:
                  player->TeleportTo(530, 12885.429688f, -7325.166016f, 65.491074f, 4.522146f);
                  break;
            //Teleporty->Dungeony->TBC->Auchenai Crypts
            case GOSSIP_ACTION_INFO_DEF+276:
                  player->TeleportTo(530, -3362.520996f, 5215.177246f, -101.049004f, 1.542387f);
                  break;
            //Teleporty->Dungeony->TBC->Mana-Tombs
            case GOSSIP_ACTION_INFO_DEF+277:
                  player->TeleportTo(530, -3088.955811f, 4943.725586f, -100.917038f, 6.250142f);
                  break;
            //Teleporty->Dungeony->TBC->Sethekk Halls
            case GOSSIP_ACTION_INFO_DEF+278:
                  player->TeleportTo(530, -3338.709961f, 4703.580078f, -100.968002f, 3.577920f);
                  break;
            //Teleporty->Dungeony->TBC->Shadow Labyrinth
            case GOSSIP_ACTION_INFO_DEF+279:
                  player->TeleportTo(530, -3639.954834f, 4942.987305f, -101.047997f, 3.123836f);
                  break;
            //Teleporty->Dungeony->TBC->Opening of the Dark Portal
            case GOSSIP_ACTION_INFO_DEF+280:
                  player->TeleportTo(1, -8736.190430f, -4217.858887f, -209.500824f, 2.238328f);
                  break;
            //Teleporty->Dungeony->TBC->The Escape from Durnholde
            case GOSSIP_ACTION_INFO_DEF+281:
                  player->TeleportTo(1, -8373.632812f, -4061.769531f, -208.450119f, 0.079310f);
                  break;
            //Teleporty->Dungeony->TBC->The Slave Pens
            case GOSSIP_ACTION_INFO_DEF+282:
                  player->TeleportTo(530, 720.003113f, 7001.970215f, -73.074898f, 0.766925f);
                  break;
            //Teleporty->Dungeony->TBC->The Steamvault
            case GOSSIP_ACTION_INFO_DEF+283:
                  player->TeleportTo(530, 816.775391f, 6932.341309f, -80.418930f, 1.478896f);
                  break;
            //Teleporty->Dungeony->TBC->The Underbog
            case GOSSIP_ACTION_INFO_DEF+284:
                  player->TeleportTo(530, 777.217896f, 6767.418945f, -71.416809f, 4.955063f);
                  break;
            //Teleporty->Dungeony->TBC->Hellfire Ramparts
            case GOSSIP_ACTION_INFO_DEF+285:
                  player->TeleportTo(530, -361.881378f, 3071.402100f, -15.095100f, 1.800872f);
                  break;
            //Teleporty->Dungeony->TBC->The Blood Furnace
            case GOSSIP_ACTION_INFO_DEF+286:
                  player->TeleportTo(530, -298.108246f, 3156.342529f, 31.638258f, 2.152012f);
                  break;
            //Teleporty->Dungeony->TBC->The Shattered Halls
            case GOSSIP_ACTION_INFO_DEF+287:
                  player->TeleportTo(530, -308.492798f, 3073.893311f, -3.649153f, 1.793798f);
                  break;
            //Teleporty->Dungeony->TBC->The Arcatraz
            case GOSSIP_ACTION_INFO_DEF+288:
                  player->TeleportTo(530, 3308.426025f, 1341.306763f, 505.558990f, 5.092538f);
                  break;
            //Teleporty->Dungeony->TBC->The Botanica
            case GOSSIP_ACTION_INFO_DEF+289:
                  player->TeleportTo(530, 3405.266846f, 1489.725464f, 182.837982f, 5.605815f);
                  break;
            //Teleporty->Dungeony->TBC->The Mechanar
            case GOSSIP_ACTION_INFO_DEF+290:
                  player->TeleportTo(530, 2871.482422f, 1554.425659f, 252.159256f, 3.879534f);
                  break;

            case GOSSIP_ACTION_INFO_DEF+103:
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("达克萨隆要塞(74-76)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+292);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("古达克(76-78)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+293);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("冠军的试炼(80-82)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+294);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("紫罗兰监狱(75-77)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+295);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("安卡赫特-古代王国(73-75)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+296);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("艾卓-尼鲁布(72-74)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+297);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("时光之穴-净化斯坦索姆(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+298);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("映像大厅(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+299);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("萨隆矿坑(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+300);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("灵魂洪炉(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+301);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("魔枢(71-73)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+302);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("魔环(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+303);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("闪电大厅(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+304);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("岩石大厅(77-79)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+305);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("乌特加德城堡(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+306);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("乌特加德之巅(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+307);
				  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  break;

            //Teleporty->Dungeony->WoTLK->Drak'Tharon Keep
            case GOSSIP_ACTION_INFO_DEF+292:
                  player->TeleportTo(571, 4774.345215f, -2029.793579f, 229.380539f, 1.532860f);
                  break;
            //Teleporty->Dungeony->WoTLK->Gundrak
            case GOSSIP_ACTION_INFO_DEF+293:
                  player->TeleportTo(571, 6710.056641f, -4652.769531f, 446.281311f, 3.913191f);
                  break;
            //Teleporty->Dungeony->WoTLK->Trial of the Champion
            case GOSSIP_ACTION_INFO_DEF+294:
                  player->TeleportTo(571, 8583.36621f, 792.042175f, 558.234985f, 3.145521f);
                  break;
            //Teleporty->Dungeony->WoTLK->Violet Hold
            case GOSSIP_ACTION_INFO_DEF+295:
                  player->TeleportTo(571, 5695.223633f, 505.486938f, 652.679932f, 4.039818f);
                  break;
            //Teleporty->Dungeony->WoTLK->Ahn'kahet: The Old Kingdom
            case GOSSIP_ACTION_INFO_DEF+296:
                  player->TeleportTo(571, 3643.332520f, 2036.998291f, 1.787575f, 4.330539f);
                  break;
            //Teleporty->Dungeony->WoTLK->Azjol-Nerub
            case GOSSIP_ACTION_INFO_DEF+297:
                  player->TeleportTo(571, 3678.062012f, 2166.449219f, 35.798393f, 2.414165f);
                  break;
            //Teleporty->Dungeony->WoTLK->The Culling of Stratholme
            case GOSSIP_ACTION_INFO_DEF+298:
                  player->TeleportTo(1, -8755.279297f, -4450.120605f, -199.690613f, 4.561416f);
                  break;
            //Teleporty->Dungeony->WoTLK->Halls of Reflection
            case GOSSIP_ACTION_INFO_DEF+299:
                  player->TeleportTo(571, 5629.565430f, 1982.262329f, 801.119202f, 4.630351f);
                  break;
            //Teleporty->Dungeony->WoTLK->Pit of Saron
            case GOSSIP_ACTION_INFO_DEF+300:
                  player->TeleportTo(571, 5599.693848f, 2016.552856f, 798.041138f, 3.813539f);
                  break;
            //Teleporty->Dungeony->WoTLK->The Forge of Souls
            case GOSSIP_ACTION_INFO_DEF+301:
                  player->TeleportTo(571, 5666.433105f, 2008.780029f, 798.041626f, 5.378444f);
                  break;
            //Teleporty->Dungeony->WoTLK->The Nexus
            case GOSSIP_ACTION_INFO_DEF+302:
                  player->TeleportTo(571, 3893.687500f, 6985.163086f, 69.488113f, 0.033498f);
                  break;
            //Teleporty->Dungeony->WoTLK->The Oculus
            case GOSSIP_ACTION_INFO_DEF+303:
                  player->TeleportTo(571, 3879.775391f, 6984.564941f, 106.320000f, 3.133479f);
                  break;
            //Teleporty->Dungeony->WoTLK->Halls of Lightning
            case GOSSIP_ACTION_INFO_DEF+304:
                  player->TeleportTo(571, 9182.778320f, -1385.894409f, 1110.215698f, 5.536058f);
                  break;
            //Teleporty->Dungeony->WoTLK->Halls of Stone
            case GOSSIP_ACTION_INFO_DEF+305:
                  player->TeleportTo(571, 8921.901367f, -979.332825f, 1039.282837f, 1.563244f);
                  break;
            //Teleporty->Dungeony->WoTLK->Utgarde Keep
            case GOSSIP_ACTION_INFO_DEF+306:
                  player->TeleportTo(571, 1225.117310f, -4863.395508f, 41.248001f, 0.285698f);
                  break;
            //Teleporty->Dungeony->WoTLK->Utgarde Pinnacle
            case GOSSIP_ACTION_INFO_DEF+307:
                  player->TeleportTo(571, 1243.534180f, -4857.321777f, 217.504395f, 3.415591f);
                  break;
// -----------------------------------------------------------------------------------------------------------------------------------

            //Teleporty->Aliance->Stormwind
            case GOSSIP_ACTION_INFO_DEF+7:
                  player->TeleportTo(0, -8832.95f, 623.306f, 93.7561f, 0.704069f);
                  break;
            //Teleporty->Aliance->Ironforge
            case GOSSIP_ACTION_INFO_DEF+8:
                  player->TeleportTo(0, -4920.96f, -955.293f, 501.8f, 2.25831f);
                  break;
            //Teleporty->Aliance->Darnassus
            case GOSSIP_ACTION_INFO_DEF+9:
                  player->TeleportTo(1, 9949.56f, 2284.21f, 1341.39f, 1.52518f); 
                  break;
            //Teleporty->Aliance->Exodar
            case GOSSIP_ACTION_INFO_DEF+10:
                  player->TeleportTo(530, -3965.7f, -11653.6f, -138.844f, 6.19286f); 
                  break;
            //Teleporty->Horde->Orgrimmar
            case GOSSIP_ACTION_INFO_DEF+11:
                  player->TeleportTo(1, 1629.6f, -4373.44f, 31.2937f, 3.52875f);
                  break;
            //Teleporty->Horde->Thunderbluff
            case GOSSIP_ACTION_INFO_DEF+12:
                  player->TeleportTo(1, -1277.37f, 124.804f, 131.287f, 5.22274f);
                  break;
            //Teleporty->Horde->Undercity
            case GOSSIP_ACTION_INFO_DEF+13:
                  player->TeleportTo(0, 1584.07f, 241.987f, -52.1534f, 0.049647f);
                  break;
            //Teleporty->Horde->Silvermoon
            case GOSSIP_ACTION_INFO_DEF+14:
                  player->TeleportTo(530, 9487.69f, -7279.2f, 14.2866f, 6.16478f); 
                  break;
            //Teleporty->Neutral->Dalaran
            case GOSSIP_ACTION_INFO_DEF+15:
                  player->TeleportTo(571, 5807.86f, 588.231f, 661.373f, 1.6675f);
                  break;
            //Teleporty->Neutral->Shattrath
            case GOSSIP_ACTION_INFO_DEF+16:
                  player->TeleportTo(530, -1838.16f, 5301.79f, -12.428f, 5.9517f);
                  break;
// -----------------------------------------------------------------------------------------------------------------------------------
            // Teleporty->Raidy
            case GOSSIP_ACTION_INFO_DEF+4:
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("60年代经典旧世"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+18);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("70年代燃烧的远征"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+19);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("80年代巫妖王之怒"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+20);
				player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                  // player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Cataclysm", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+21);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  break;

            case GOSSIP_ACTION_INFO_DEF+18:
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("安其拉废墟(60-62)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+191);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("安其拉神殿(60-62)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+187);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("黑翼之巢(60-62)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+188);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("熔火之心(60-62)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+189);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("奥妮克希亚的巢穴(60-62)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+190);
				    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                    break;
            // Teleporty->Raidy->Classic->Ahn'Qiraj Temple
            case GOSSIP_ACTION_INFO_DEF+187:
                    player->TeleportTo(1, -8251.438477f, 1980.816284f, 129.071732f, 0.804158f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+188:
            // Teleporty->Raidy->Classic->Blackwing Lair
                    player->TeleportTo(229, 164.538025f, -474.945831f, 116.842003f, 6.254234f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+189:
            // Teleporty->Raidy->Classic->The Molten Core
                    player->TeleportTo(230, 1126.640015f, -459.940002f, -102.535004f, 3.460950f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+190:
            // Teleporty->Raidy->Classic->Onyxia's Lair
                    player->TeleportTo(1, -4711.304199f, -3728.890869f, 54.272491f, 3.3771842f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+191:
            // Teleporty->Raidy->Classic->Ruins of Ahn'Qiraj
                    player->TeleportTo(1, -8409.820312f, 1499.060059f, 27.717899f, 2.569731f);
                    break;

            case GOSSIP_ACTION_INFO_DEF+19:
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("黑暗神殿(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+198);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("格鲁尔的巢穴(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+199);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("卡拉赞(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+201);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("玛瑟里顿的巢穴(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+202);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("毒蛇神殿(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+203);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("风暴要塞(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+204);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("海加尔峰(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+205);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("太阳之井高地(70-72)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+206);
				    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                    break;
            // Teleporty->Raidy->TBC->Black Temple
            case GOSSIP_ACTION_INFO_DEF+198:
                    player->TeleportTo(530, -3649.919922f, 317.468994f, 35.282700f, 3.017463f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+199:
            // Teleporty->Raidy->TBC->Gruul's Lair
                    player->TeleportTo(530, 3530.060059f, 5104.080078f, 3.508610f, 5.511170f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+201:
            // Teleporty->Raidy->TBC->Karazhan
                    player->TeleportTo(0, -11118.144531f, -2010.659546f, 47.079243f, 0.697804f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+202:
            // Teleporty->Raidy->TBC->Magtheridon's Lair
                    player->TeleportTo(530, -315.805634f, 3091.487305f, -116.449791f, 5.237383f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+203:
            // Teleporty->Raidy->TBC->Serpentshrine Cavern
                    player->TeleportTo(530, 794.041626f, 6865.174316f, -64.574829f, 6.281073f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+204:
            // Teleporty->Raidy->TBC->Tempest Keep
                    player->TeleportTo(530, 3091.015137f, 1414.614136f, 189.874359f, 4.615965f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+205:
            // Teleporty->Raidy->TBC->The Battle for Mount Hyjal
                    player->TeleportTo(1, -8177.890137f, -4181.229980f, -167.552002f, 0.970586f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+206:
            // Teleporty->Raidy->TBC->The Sunwell
                    player->TeleportTo(530, 12565.356445f, -6774.626953f, 15.091568f, 3.156428f);
                    break;

            case GOSSIP_ACTION_INFO_DEF+20:
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("冰冠堡垒(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+217);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("纳克萨玛斯(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+207);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("永恒之眼(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+209);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("黑曜石圣殿(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+210);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("晶红圣殿(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+211);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("十字军的试炼(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+212);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("奥杜尔(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+213);
                    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("阿尔卡冯的宝库(80)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+214);
				    player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                    break;
            // Teleporty->Raidy->WoTLK->Icecrown Citadel
            case GOSSIP_ACTION_INFO_DEF+217:
                    player->TeleportTo(571, 5799.885254f, 2075.655762f, 636.063904f, 3.533497f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+207:
            // Teleporty->Raidy->WoTLK->Naxxramas
                    player->TeleportTo(571, 3668.719971f, -1262.459961f, 243.621994f, 4.785000f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+209:
            // Teleporty->Raidy->WoTLK->The Eye of Eternity
                    player->TeleportTo(571, 3859.766602f, 6989.591309f, 152.042007f, 5.804890f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+210:
            // Teleporty->Raidy->WoTLK->The Obsidian Sanctum
                    player->TeleportTo(571, 3457.202393f, 262.678711f, -113.871857f, 3.218489f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+211:
            // Teleporty->Raidy->WoTLK->The Ruby Sanctum
                    player->TeleportTo(571, 3604.820068f, 191.464005f, -113.679001f, 2.199120f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+212:
            // Teleporty->Raidy->WoTLK->Trial of the Crusader
                    player->TeleportTo(571, 8515.660156f, 721.949646f, 558.248291f, 1.566860f);
                    break;
            case GOSSIP_ACTION_INFO_DEF+219:
            // Teleporty->Raidy->WoTLK->Ulduar
                    player->TeleportTo(571, 9182.520508f, -1384.432007f, 1110.190918f, 5.539923f);
                    break;
            // Teleporty->Raidy->WoTLK->Vault of Archavon
                    player->TeleportTo(571, 5453.720215f, 2840.790039f, 421.277069f, 0.000000f);
                    break;

            /* 
            // ========================= CATACLYSM RAIDS =========================
            case GOSSIP_ACTION_INFO_DEF+21:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Baradin Hold", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+213);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Blackwing Descent", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+214);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Dragon Soul", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+215);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Firelands", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+213);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "The Bastion of Twilight", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+227);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Throne of the Four Winds", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+218);
                    player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                    break;
            case GOSSIP_ACTION_INFO_DEF+213:
            // Teleporty->Raidy->Cataclysm->Baradin Hold
                    player->TeleportTo(732, -1244.412231, 1050.048828, 106.994591, 3.123164);
                    break;
             case GOSSIP_ACTION_INFO_DEF+214:
            // Teleporty->Raidy->Cataclysm->Blackwing Descent
                    player->TeleportTo(0, -7534.607910, -1209.698242, 477.728760, 1.900531);
                    break;
             case GOSSIP_ACTION_INFO_DEF+215:
            // Teleporty->Raidy->Cataclysm->Dragon Soul
                    player->TeleportTo(1, -8293.348633, -4520.624023, -218.217743, 0.252107);
                    break;
             case GOSSIP_ACTION_INFO_DEF+216:
            // Teleporty->Raidy->Cataclysm->Firelands
                    player->TeleportTo(720, -541.505005, 309.490997, 115.55699, 0.000000);
                    break;
             case GOSSIP_ACTION_INFO_DEF+227:
            // Teleporty->Raidy->Cataclysm->The Bastion of Twilight
                    player->TeleportTo(0, -4891.221191, -4239.565918, 827.764343, 2.083040);
                    break;
             case GOSSIP_ACTION_INFO_DEF+218:
            // Teleporty->Raidy->Cataclysm->Throne of the Four Winds
                    player->TeleportTo(1, -11355.089844, 58.024860, 723.884521, 1.940545);
                    break;
        */
// -----------------------------------------------------------------------------------------------------------------------------------
            // Teleporty->Areny
            case GOSSIP_ACTION_INFO_DEF+5:
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("巨槌竞技场"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+69);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("古拉巴什竞技场"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+40);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("鲜血之环竞技场"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+41);
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("纳格兰竞技场"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+42);
				  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  break;

            // Teleport->Areny->Dire Maul Arena
            case GOSSIP_ACTION_INFO_DEF+69:
                  player->TeleportTo(1, -3761.421631f, 1132.415283f, 132.032684f, 4.722603f);
                  break;
            // Teleport->Areny->Gurubashi Arena
            case GOSSIP_ACTION_INFO_DEF+40:
                  player->TeleportTo(0, -13277.400391f, 127.372002f, 26.141800f, 1.118780f);
                  break;
            // Teleport->Areny->Circle of Blood Arena
            case GOSSIP_ACTION_INFO_DEF+41:
                  player->TeleportTo(530, 2838.639893f, 5929.214844f, 11.100544f, 2.444200f);
                  break;
            // Teleport->Areny->Nagrand Arena
            case GOSSIP_ACTION_INFO_DEF+42:
                  player->TeleportTo(530, -1994.498779f, 6576.810059f, 10.878504f, 2.239219f);
                  break;

            // Teleporty->Outdoor pvP
            case GOSSIP_ACTION_INFO_DEF+6:
                  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("冬拥湖"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+60);
				  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回上一级菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                  /* player->ADD_GOSSIP_ITEM(2, "Tol Barad", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+61); */
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  break;
            // Teleporty->Outdoor PvP->Wintergrasp
            case GOSSIP_ACTION_INFO_DEF+60:
                  player->TeleportTo(571, 4755.256348f, 2041.23266f, 426.041260f, 1.679780f);
                  break;
            /*
            // Teleporty->Outdoor PvP->Tol Barad
            case GOSSIP_ACTION_INFO_DEF+61:
                  player->TeleportTo(732, -119.110046, 1387.650879, 22.130121, 5.470919);
                  break;
            */
// -----------------------------------------------------------------------------------------------------------------------------------
            //Character Customize
            case GOSSIP_ACTION_INFO_DEF+99:
                  player->ADD_GOSSIP_ITEM(8, sObjectMgr->GBKToUtf8("更换阵营(50000G)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+231);
                  player->ADD_GOSSIP_ITEM(8, sObjectMgr->GBKToUtf8("更换种族(5000G)"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+232);
				  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回主菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 500);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  break;

            //Character Customize->Zmena Frakce
            case GOSSIP_ACTION_INFO_DEF+231:
                if(tele_pay(PRICE_FACTIONCHANGE, player))
                {
                  player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                  player->CastSpell(player, 61456, false);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  creature->Whisper(sObjectMgr->GBKToUtf8("更换成功，请返回角色选择菜单选择阵营！"), LANG_UNIVERSAL, player);
                }
				else{creature->Whisper(sObjectMgr->GBKToUtf8("更换失败，很抱歉，您的金币不够！"), LANG_UNIVERSAL, player);}
                  break;
            //Chacarter Customize->Zmena Rasy
            case GOSSIP_ACTION_INFO_DEF+232:
                if(tele_pay(PRICE_RACECHANGE, player))
                {
                  player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                  player->CastSpell(player, 61456, false);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  creature->Whisper(sObjectMgr->GBKToUtf8("更换成功，请返回角色选择菜单选择种族！"), LANG_UNIVERSAL, player);
                }
				else{creature->Whisper(sObjectMgr->GBKToUtf8("更换失败，很抱歉，您的金币不够！"), LANG_UNIVERSAL, player);}
                  break;
// -----------------------------------------------------------------------------------------------------------------------------------
            //Characters Tools      
            case GOSSIP_ACTION_INFO_DEF+400:
                  player->ADD_GOSSIP_ITEM(1, sObjectMgr->GBKToUtf8("恢复全部生命"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+23);
                  player->ADD_GOSSIP_ITEM(1, sObjectMgr->GBKToUtf8("恢复全部魔法"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+24);
                  player->ADD_GOSSIP_ITEM(1, sObjectMgr->GBKToUtf8("重置技能CD"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+25);
                  player->ADD_GOSSIP_ITEM(1, sObjectMgr->GBKToUtf8("重置所有状态"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+26);
                  player->ADD_GOSSIP_ITEM(1, sObjectMgr->GBKToUtf8("脱离战斗"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+27);
				  player->ADD_GOSSIP_ITEM(2, sObjectMgr->GBKToUtf8("返回主菜单"), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 500);
                  player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                  break;

            //Characters tools->Doplneni HP
            case GOSSIP_ACTION_INFO_DEF+23:
                  if (player->IsInCombat() || player->duel)
                  {
					creature->Whisper(sObjectMgr->GBKToUtf8("战斗或决斗状态下不能使用此功能哦！"), LANG_UNIVERSAL, player);
                    return false;
                  }
                  else
                  {
                    player->CLOSE_GOSSIP_MENU();
                    player->SetHealth(player->GetMaxHealth());
                    player->CastSpell(player, 61456, false);
                    creature->Whisper(sObjectMgr->GBKToUtf8("血都加满了，小伙伴去继续战斗吧！"), LANG_UNIVERSAL, player);
                  }
                  break;
            //Character tools->Doplneni Many
            case GOSSIP_ACTION_INFO_DEF+24:
                  if (player->IsInCombat() || player-> duel)
                  {
					creature->Whisper(sObjectMgr->GBKToUtf8("战斗或决斗状态下不能使用此功能哦！"), LANG_UNIVERSAL, player);
                    return false;
                  }
                  else
                  {
                    player->CLOSE_GOSSIP_MENU();
                    player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
                    player->CastSpell(player, 61456, false);
                    creature->Whisper(sObjectMgr->GBKToUtf8("蓝都加满了，小伙伴去继续施法吧！"), LANG_UNIVERSAL, player);
                  }
                  break;
              //Character tools->Zruseni Cooldownu
              case GOSSIP_ACTION_INFO_DEF+25:
                    if (player->IsInCombat() || player-> duel)
                    {
					  creature->Whisper(sObjectMgr->GBKToUtf8("战斗或决斗状态下不能使用此功能哦！"), LANG_UNIVERSAL, player);
                      return false;
                    }
                    else
                    {
                      player->CLOSE_GOSSIP_MENU();
                      player->RemoveAllSpellCooldown();
                      player->RemoveArenaSpellCooldowns();
                      player->CastSpell(player, 75459, false);
                      creature->Whisper(sObjectMgr->GBKToUtf8("亲，所有技能已重置了哦！"), LANG_UNIVERSAL, player);
                    }
                    break;
                //Character tools->Zruseni Sated
              case GOSSIP_ACTION_INFO_DEF+26:
			        if (player->IsInCombat() || player-> duel)
                    {
					  creature->Whisper(sObjectMgr->GBKToUtf8("战斗或决斗状态下不能使用此功能哦！"), LANG_UNIVERSAL, player);
                      return false;
                    }
                    else
                    {
                    player->CLOSE_GOSSIP_MENU();
                    player->RemoveAurasDueToSpell(57724);
                    player->RemoveAurasDueToSpell(57723);
                    player->RemoveAurasDueToSpell(61988);
                    player->RemoveAurasDueToSpell(61987);
                    player->RemoveAurasDueToSpell(25771);
                    player->CastSpell(player, 61456, false);
                    creature->Whisper(sObjectMgr->GBKToUtf8("所有状态已重置，有没有感觉神清气爽啊！"), LANG_UNIVERSAL, player);
                    }
					break;
              //Character tools->Zruseni Combatu
              case GOSSIP_ACTION_INFO_DEF+27:
                    if (player->duel)
                    {
					  creature->Whisper(sObjectMgr->GBKToUtf8("决斗状态下不能使用此功能哦！"), LANG_UNIVERSAL, player);
                      return false;
                    }
                    else
                    {
                      player->CLOSE_GOSSIP_MENU();
                      player->CombatStop();
                      player->CastSpell(player, 61456, false);
                      creature->Whisper(sObjectMgr->GBKToUtf8("已脱离战斗！"), LANG_UNIVERSAL, player);
                    }
                    break;
			        /* case GOSSIP_ACTION_INFO_DEF+1000:
                    player->GiveLevel(80);
                    player->TeleportTo(0, -11215.299805f, -1808.140015f, -28.437000f, 1.617380f);
                    player->AddItem(23162,4);
                    player->AddItem(500001,1);
                    creature->Whisper("Tvoje postava byla boostnuta na level 80!", LANG_UNIVERSAL, player);
                    break; */
        }
        return true;
    }
};

void AddSC_npc_teleporter()
{
    new npc_teleporter;
}