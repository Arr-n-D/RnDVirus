modded class ActionGiveBloodTarget: ActionContinuousBase {
    override void OnEndServer(ActionData action_data) {
        super.OnEndServer(action_data);
        
        ActionGiveBloodData action_data_b = ActionGiveBloodData.Cast( action_data );
        PlayerBase player_target = PlayerBase.Cast(action_data.m_Target.GetObject());

        int bloodtypetarget = player_target.GetStatBloodType().Get();
		bool bloodmatch = BloodTypes.MatchBloodCompatibility(action_data_b.m_ItemBloodType, bloodtypetarget);

        if (bloodmatch && ( player_target.GetSingleAgentCount(RnDAgents.VIRUS) >= 1) && !( action_data.m_MainItem.ContainsAgent(RnDAgents.VIRUS) )) {
            player_target.RemoveAgent(RnDAgents.VIRUS);
            player_target.m_WasRecentlyGivenACleanBloodTransfusion = true;
        }
    }
}