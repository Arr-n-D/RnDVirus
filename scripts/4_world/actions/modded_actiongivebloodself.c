modded class ActionGiveBloodSelf: ActionContinuousBase {
    override void OnEndServer(ActionData action_data) {
        super.OnEndServer(action_data);
        
        ActionGiveBloodData action_data_b = ActionGiveBloodData.Cast( action_data );
        
        int bloodtypetarget = action_data_b.m_Player.GetStatBloodType().Get();
		bool bloodmatch = BloodTypes.MatchBloodCompatibility(action_data_b.m_ItemBloodType, bloodtypetarget);

        if (bloodmatch && ( action_data_b.m_Player.GetSingleAgentCount(RnDAgents.VIRUS) >= 1 ) && !( action_data.m_MainItem.ContainsAgent(RnDAgents.VIRUS) ) ) {
            action_data_b.m_Player.RemoveAgent(RnDAgents.VIRUS);
            action_data_b.m_Player.m_WasRecentlyGivenACleanBloodTransfusion = true;
        }
    }
}