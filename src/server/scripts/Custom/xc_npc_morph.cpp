/*
Developer: Dway
Script: Npc Morpher
ScriptName: npc_morph  ��۱��νű�
*/
 
#include "ScriptPCH.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"
 
#define reward 24245 //reward id
#define pocet 1 //pocet rewardu
#define deffender_morpher_text_buy sObjectMgr->GBKToUtf8("���γɹ� ������1�����ߣ�") //dostatek marek
#define deffender_morpher_text_err sObjectMgr->GBKToUtf8("����ʧ�ܣ����߲���") //nedostatek marek
 
class npc_morph : public CreatureScript
{
public:
    npc_morph() : CreatureScript("npc_morph")
    {
    }
    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->IsInCombat())
        {
            pPlayer->CLOSE_GOSSIP_MENU();
			pCreature->Whisper(sObjectMgr->GBKToUtf8("ս�����޷��仯���Σ�"), LANG_UNIVERSAL, pPlayer);
            return true;
        }
 
        pPlayer->PlayerTalkClass->ClearMenus();
		pPlayer->ADD_GOSSIP_ITEM(9, sObjectMgr->GBKToUtf8("��ԭ����"), GOSSIP_SENDER_MAIN, 20001);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ϣ������˹��������"), GOSSIP_SENDER_MAIN, 20002);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("�Ŷ���"), GOSSIP_SENDER_MAIN, 20003);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("������"), GOSSIP_SENDER_MAIN, 20004);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("��ά��Ӱ��"), GOSSIP_SENDER_MAIN, 20005);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("�����"), GOSSIP_SENDER_MAIN, 20006);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("���"), GOSSIP_SENDER_MAIN, 20007);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʳʬ��"), GOSSIP_SENDER_MAIN, 20008);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("���麣��"), GOSSIP_SENDER_MAIN, 20009);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("��֪"), GOSSIP_SENDER_MAIN, 20010);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("������˹"), GOSSIP_SENDER_MAIN, 20012);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("������"), GOSSIP_SENDER_MAIN, 20013);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("���з"), GOSSIP_SENDER_MAIN, 20014);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("�־�ħ��"), GOSSIP_SENDER_MAIN, 20015);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("����սʿ"), GOSSIP_SENDER_MAIN, 20016);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("Ѫħ"), GOSSIP_SENDER_MAIN, 20017);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("���ﰲ�����������"), GOSSIP_SENDER_MAIN, 20018);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("���Ⱥ���"), GOSSIP_SENDER_MAIN, 20019);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("������̩��˹"), GOSSIP_SENDER_MAIN, 20022);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʳ��ħ"), GOSSIP_SENDER_MAIN, 20023);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʥ������"), GOSSIP_SENDER_MAIN, 20027);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʥ��װѪ����"), GOSSIP_SENDER_MAIN, 20011);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʥ��װ����"), GOSSIP_SENDER_MAIN, 20024);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʥ��װ��ҹ����"), GOSSIP_SENDER_MAIN, 20025);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʥ��װ�ؾ�"), GOSSIP_SENDER_MAIN, 20020);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("ʥ��װŮ٪��"), GOSSIP_SENDER_MAIN, 20021);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("٪��ǱˮԱ"), GOSSIP_SENDER_MAIN, 20026);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("����ǱˮԱ"), GOSSIP_SENDER_MAIN, 20028);
		pPlayer->ADD_GOSSIP_ITEM(6, sObjectMgr->GBKToUtf8("��ħǱˮԱ"), GOSSIP_SENDER_MAIN, 20029);
        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
        return true;
    }
    void SendDefaultMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
    {
        switch (uiAction)
        {
        case 20001://Demorph
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->DeMorph();
            break;
 
        case 20002://Lady Sylvanas Windrunner
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(28213);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
        case 20003://Gul'dan
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(16642);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20004://Akama
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(20681);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20005://Maiev Shadowsong
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(20628);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20006://Medivh
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(18718);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20007://Tucnak
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(24698);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20008://Geist
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(24579);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20009://Undead Pirat
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(25042);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20010://Velen the Prophet
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(17822);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
				pCreature->Whisper(deffender_morpher_text_err, LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20011://Christmas Blood Elf 18+
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
				pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(18785);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20012://Arthas
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(21976);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20013://Lich king
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(22235);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20014://Humr
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(19726);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20015://Terrorfiend
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(18373);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20016://Troll na netopyrovi
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(15303);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20017://Teron Gorefiend
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(21576);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20018://King Varian Wrynn
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(28127);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20019://Naga
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(18390);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20020://Santa Goblin
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(15698);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20021://Christmas Gnome Female
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(15799);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20022://Aldaron the Reckless
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(15925);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20023://Ogre
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(1122);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20024://Christmas Undead
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(18811);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20025://Christmas Night Elf. 18+
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(15748);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20026://Gnome Diver
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(27657);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20027://Santa Claus Gnom
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(15806);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20028://Human Diver
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(23426);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        case 20029://Troll Diver
            if (pPlayer->HasItemCount(reward, pocet))
            {
                pPlayer->DestroyItemCount(reward, pocet, true, false);
                pCreature->Whisper(deffender_morpher_text_buy, LANG_UNIVERSAL, pPlayer,true);
                pPlayer->SetDisplayId(17272);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            else
            {
                pCreature->Whisper(deffender_morpher_text_err,LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
            }
            break;
 
        }
    }
 
 
    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        if (uiSender == GOSSIP_SENDER_MAIN)
            SendDefaultMenu(pPlayer, pCreature, uiAction);
        return true;
    }
 
};
 
void AddSC_npc_morph()
{
    new npc_morph;
}