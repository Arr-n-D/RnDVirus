class VirusAgent extends AgentBase
{

	override void Init()
	{
		m_Type 					= RnDAgents.VIRUS;
		m_Invasibility 			= 0.8;
		m_TransferabilityIn		= 1;
		m_TransferabilityOut	= 1;
		m_MaxCount 				= 28800;
		m_Digestibility			= 0.1;
		m_AntibioticsResistance = 1;
		m_AutoinfectProbability = CalculateAutoinfectProbability( 1 ); // possibly get rid of as we might want item to person transmission? I like the idea of auto infection after a certain time. Possibly make the auto reinfection really random
		m_TransferabilityAirOut = 1;
		m_Potency 				= EStatLevels.GREAT;
		m_DieOffSpeed 			= 0.66;
	}

	override bool CanAutoinfectPlayer(PlayerBase player) // possibily to remove this as well
	{
		// check player blood type
		int blood_type = player.GetStatBloodType().Get();
		//   check O-, 			B+, 				AB- blood types, see scripts/3_game/constants.c@475
		if ( blood_type == 2 || blood_type == 16 || blood_type == 128 ) {
			return false;
		} else {
			if ( player.m_WasRecentlyGivenACleanBloodTransfusion ) {
				return false;
			} else {
				ItemBase mask = ItemBase.Cast(player.GetInventory().FindAttachment(InventorySlots.MASK));
				return (!mask);
			} 
		}
	}

	// modify transferability based on blood type of player based on the same logic as above? 
}