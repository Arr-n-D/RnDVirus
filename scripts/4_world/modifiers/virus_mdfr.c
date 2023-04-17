class VirusMdfr: ModifierBase
{
	const int AGENT_THRESHOLD_ACTIVATE = 3600;
	const int AGENT_THRESHOLD_DEACTIVATE = 3500;
	
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= RnDModifiers.MDF_VIRUS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	
	override string GetDebugText()
	{
		return ("Activate threshold: "+AGENT_THRESHOLD_ACTIVATE + "| " +"Deativate threshold: "+AGENT_THRESHOLD_DEACTIVATE);
	}
	
	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(RnDAgents.VIRUS) >= AGENT_THRESHOLD_ACTIVATE) 
		{
			return true;
		}
		return false;
	}

	override protected void OnActivate(PlayerBase player)
	{
		player.IncreaseDiseaseCount();
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		return (player.GetSingleAgentCount(RnDAgents.VIRUS) <= AGENT_THRESHOLD_DEACTIVATE);
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		float chance_of_cough = player.GetSingleAgentCountNormalized(RnDAgents.VIRUS);

		int blood_type = player.GetStatBloodType().Get();
		
		// check O-, B+, AB- blood types, see scripts/3_game/constants.c@475
		if ( blood_type == 2 || blood_type == 16 || blood_type == 128 ) {
			player.RemoveAgent(RnDAgents.VIRUS);
		}

		if ( player.m_WasRecentlyGivenACleanBloodTransfusion ) {
			player.RemoveAgent(RnDAgents.VIRUS);
		}
		
		if( Math.RandomFloat01() < chance_of_cough / Math.RandomInt(5,20) )
		{
			player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		}

		if( Math.RandomFloat01() < chance_of_cough / Math.RandomInt(5,20) )
		{
			player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_SNEEZE);
		}
	}
};