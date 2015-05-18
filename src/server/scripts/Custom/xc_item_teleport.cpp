class xc_item_teleport : public ItemScript
{
public:
	xc_item_teleport() : ItemScript("xc_item_teleport") {}
	bool OnUse (Player* player, Item* item, SpellCastTargets const& targets)
		{
			if (!player->isInCombat())
			{
				OnGossipHello(player, item);
				return true;
			}
			else
			{
				player->ClearInCombat();
				return false;
			}
		}

				
	bool OnGossipHello(Player* player, Item* pitem)
		{
		sObjectMgr->LoadxcItemTeleportMenu(0, player, pitem);
		return true;
		}

	bool OnGossipSelect(Player* player, Item* pitem, uint32 uiSender, uint32 uiAction)
    {
		sObjectMgr->RunxcItemTeleport(uiAction, uiSender, player, pitem);
		return true;
    }

	void ObjectMgr::LoadxcItemTeleportMenu(uint32 MenuId, Player* player, Item* pitem)
{
	uint32 faction = 0;
	if(player->GetTeamId() == ALLIANCE)
		faction = 1;
	else
		faction = 2;
	

	player->PlayerTalkClass->ClearMenus(); //清除菜单项

	for(xyItemTeleMap::iterator ltr=m_xyItemTeleMap.begin(); ltr != m_xyItemTeleMap.end(); ++ltr)
	{
		if(ltr->second.parentid == MenuId && (ltr->second.factionid == 0 || faction == ltr->second.factionid))  // 载入指定页面的菜单
		{
			player->PlayerTalkClass->GetGossipMenu().AddMenuItem(0, ltr->second.title.c_str(), ltr->second.menuid, ltr->second.usetype + 1000, "", 0);
		}
	}
	player->PlayerTalkClass->SendGossipMenu(907, pitem->GetGUID()); // 发送菜单
}

bool ObjectMgr::RunxcItemTeleport(uint32 action, uint32 sender, Player *player,Item *pitem)
{
	if(player->isInCombat())
	{
		player->PlayerTalkClass->ClearMenus();
		return false;
	}

	xyItemTeleMap::iterator itr = m_xyItemTeleMap.find(sender);
	if(itr == m_xyItemTeleMap.end())
	{
		switch (action)
		{
		case 1102:
			PvpRankLevelUP(player, pitem);
			return true;
		case 1501:
			if (player->GetYB() > 0)
			{
				player->ModifyYB( -1 );
				player->ModifyJF( GetIntConfig(YB2JF));
				player->ShowYBtoJF(pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的元宝不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1502:
			if (player->GetYB() >= 5)
			{
				player->ModifyYB( -5 );
				player->ModifyJF( GetIntConfig(YB2JF) * 5);
				player->ShowYBtoJF(pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的元宝不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1503:
			if (player->GetYB() >= 10)
			{
				player->ModifyYB( -10 );
				player->ModifyJF( GetIntConfig(YB2JF) * 10);
				player->ShowYBtoJF(pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的元宝不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1504:
			if (player->GetYB() >= 50)
			{
				player->ModifyYB( -50 );
				player->ModifyJF( GetIntConfig(YB2JF) * 50);
				player->ShowYBtoJF(pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的元宝不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1505:
			if (player->GetYB() >= 100)
			{
				player->ModifyYB( -100 );
				player->ModifyJF( GetIntConfig(YB2JF) * 100);
				player->ShowYBtoJF(pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的元宝不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1506:
			if (player->GetYB() >= 1000)
			{
				player->ModifyYB( -1000 );
				player->ModifyJF( GetIntConfig(YB2JF) * 1000);
				player->ShowYBtoJF(pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的元宝不足"));

			player->PlayerTalkClass->CloseGossip();
			break;
		case 1701:
			if (player->GetIsgeted())
			{
				ChatHandler(player).PSendSysMessage(GBKToUtf8("你今天已经领取过排行榜奖励,无论在几个排行榜中也只能领取一次奖励"));
				return false;
			}
			player->SetGetCredit(true);//设置为已经领取奖励
			player->AddItem(GetIntConfig(PHcredit),1);
			player->PlayerTalkClass->CloseGossip();
			ChatHandler(player).PSendSysMessage(GBKToUtf8("|CFFFF0000恭喜你获得排行奖励|r"));
			break;
		case 1601:
			if (player->GetJF() > 0)
			{
				player->ModifyJF( -1 );
				player->ModifyCurrency(395, 100);
				ShowCharge(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1602:
			if (player->GetJF() >= 5)
			{
				player->ModifyJF( -5 );
				player->ModifyCurrency(395,500);
				ShowCharge(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1603:
			if (player->GetJF() >= 10)
			{
				player->ModifyJF( -10 );
				player->ModifyCurrency( 395,1000);
				ShowCharge(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1604:
			if (player->GetJF() >= 50)
			{
				player->ModifyJF( -50 );
				player->ModifyCurrency( 395,5000);
				ShowCharge(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1605:
			if (player->GetJF() >= 100)
			{
				player->ModifyJF( -100 );
				player->ModifyCurrency( 395,10000);
				ShowCharge(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1606:
			if (player->GetJF() >= 1000)
			{
				player->ModifyJF( -1000 );
				player->ModifyCurrency( 395,100000);
				ShowCharge(player,pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));

			player->PlayerTalkClass->CloseGossip();
			break;

		case 1901:
			if (player->GetJF() > 0)
			{
				player->ModifyJF( -1 );
				player->ModifyCurrency(390, 100);
				ShowHonor(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1902:
			if (player->GetJF() >= 5)
			{
				player->ModifyJF( -5 );
				player->ModifyCurrency(390,500);
				ShowHonor(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1903:
			if (player->GetJF() >= 10)
			{
				player->ModifyJF( -10 );
				player->ModifyCurrency(390,1000);
				ShowHonor(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1904:
			if (player->GetJF() >= 50)
			{
				player->ModifyJF( -50 );
				player->ModifyCurrency( 390,5000);
				ShowHonor(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1905:
			if (player->GetJF() >= 100)
			{
				player->ModifyJF( -100 );
				player->ModifyCurrency( 390,10000);
				ShowHonor(player,pitem);
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));
			player->PlayerTalkClass->CloseGossip();
			break;
		case 1906:
			if (player->GetJF() >= 1000)
			{
				player->ModifyJF( -1000 );
				player->ModifyCurrency( 390,100000);
				ShowHonor(player,pitem);
				player->SaveJF();
				return true;
			}
			else
				ChatHandler(player).PSendSysMessage(GBKToUtf8("兑换失败,您的积分不足"));

			player->PlayerTalkClass->CloseGossip();
			break;
		}
		return false;
	}

	switch(itr->second.needtype)
	{
		case 1://需要人物等级
			if(player->getLevel() < itr->second.needv1 || player->getLevel() > itr->second.needv2)
			{
				ChatHandler(player).PSendSysMessage(12002, itr->second.needv1, itr->second.needv2);
				player->PlayerTalkClass->CloseGossip();
				return false;
			}
			break;
		case 2://需要VIP等级
			if(player->GetPlayerViplevel() < (uint32)itr->second.needv1 || player->GetPlayerViplevel() > (uint32)itr->second.needv2)
			{
				ChatHandler(player).PSendSysMessage(12001,itr->second.needv1,itr->second.needv2);
				player->PlayerTalkClass->CloseGossip();
				return false;
			}
			break;
		case 3://需要积分
			if(player->GetJF() < (uint32)abs(itr->second.needv1))
			{
				ChatHandler(player).PSendSysMessage(12005, (uint32)abs(itr->second.needv1));
				player->PlayerTalkClass->CloseGossip();
				return false; 
			}

			if(itr->second.needv1 < 0)
				player->ModifyJF(itr->second.needv1);
			break;
		case 4://需要金币
			if(player->GetMoney() < (uint32)abs(itr->second.needv1))
			{
				ChatHandler(player).PSendSysMessage(12006, itr->second.needv1);
				player->PlayerTalkClass->CloseGossip();
				return false;
			}
			if(itr->second.needv1 < 0)
				player->ModifyMoney(itr->second.needv1);
			break;
		case 5: // 需要物品
			if(player->GetItemCount(itr->second.needv1, false) < (uint32)abs(itr->second.needv2))
			{
				ChatHandler(player).PSendSysMessage(12003, sObjectMgr->GetItemNameLink(itr->second.needv1), abs(itr->second.needv2), player->GetItemCount(itr->second.needv1, false));
				player->PlayerTalkClass->CloseGossip();
				return false;
			}
			if(itr->second.needv2 < 0) // 如果NeedV2字段为负,就减掉相应的个数
				player->DestroyItemCount(itr->second.needv1,(uint32)abs(itr->second.needv2),true);
			break;
	}

	switch(action)
	{
	case 1000: // 显示指定菜单
		LoadxyItemTeleportMenu(sender, player, pitem);
		return true;
	case 1001://传送
		xyTeleportFromMenuId(player, sender);
		break;
	case 1002://查询积分
		player->GetPayYB();
		ChatHandler(player).PSendSysMessage(12000, player->GetPlayerViplevel(), player->GetJF(),player->GetYB());
		break;
	case 1003: // 修理装备
		player->DurabilityRepairAll(false, 0, false);
		break;
	case 1004://升级会员
		if(player->UpdatePlayerVipLevel(itr->second.usev1) == itr->second.usev1)
		{
			ChatHandler(player).PSendSysMessage(12004, player->GetPlayerViplevel());
		}
		break;
	case 1005: // 个人银行
		player->GetSession()->SendShowBank(player->GetGUID());
		break;
	case 1006: //军衔系统
		ShowPvpRankMenu(player, pitem);
		return true;
	case 1007://元宝兑换积分
		player->ShowYBtoJF(pitem);
		return true;
	case 1008: //血量排行
		ShowPHmenu(player,pitem,1);
		return true;
	case 1009: //经络排行
		ShowPHmenu(player,pitem,2);
		return true;
	case 1010: //境界排行
		ShowPHmenu(player,pitem,3);
		return true;
	case 1011://击杀排行
		ShowPHmenu(player,pitem,4);
		return true;
	case 1012:
		ShowBossSpawn(player,pitem);
		return true;
	case 1021://兑换其它货币
		ShowCharge(player,pitem);
		return true;
	case 1022:
		ShowHonor(player,pitem);
		return true;
	}
	player->PlayerTalkClass->CloseGossip();
	return true;
}
	
	
};

