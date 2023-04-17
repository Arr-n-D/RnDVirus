//syringes
class VirusVaccine: AntiChemInjector
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionInjectSelf);
        AddAction(ActionInjectTarget);
	}
	
	override void OnApply(PlayerBase player)
	{
        player.RemoveAgent(RnDAgents.VIRUS);
		player.m_WasRecentlyGivenACleanBloodTransfusion = true;
	}

};
//syringes
class VirusGiver: AntiChemInjector
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionInjectSelf);
        AddAction(ActionInjectTarget);
	}
	
	override void OnApply(PlayerBase player)
	{
        player.InsertAgent(RnDAgents.VIRUS, 3600);
	}
};
