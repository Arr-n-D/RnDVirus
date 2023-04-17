modded class PlayerBase {

    const int EVENT_1_INTERVAL_MIN = 25;
	const int EVENT_1_INTERVAL_MAX = 80;
    const int TIME_UNTIL_REINFECTION_MIN = 28800; // this is times in seconds, so 8 hours is 28800 seconds
    const int TIME_UNTIL_REINFECTION_MAX = 43200; // this is times in seconds, so 12 hours is 43200 seconds

	protected float m_NextEvent1;
	protected float m_Time1;

    bool m_WasRecentlyGivenACleanBloodTransfusion;
    protected float m_TimeSinceLastInfection;
   
    override void OnScheduledTick(float deltaTime) {
		super.OnScheduledTick(deltaTime);

		if(GetGame().IsDedicatedServer()) {
            if (GetSingleAgentCount(RnDAgents.VIRUS) >= 1) { // From the minute we're infected, we start spreading the virus, even if we're not showing symptoms yet
                m_Time1 += deltaTime;
                if (m_Time1 >= m_NextEvent1 )
                {
                    SpreadAgentsEx(3, 1) // 100% chance of spreading the virus to 3 meters away
                    
                    if(Math.RandomFloat01() < 0.25) //creates a spreading cooldown once in a while
                    {
                        m_NextEvent1 = Math.RandomFloatInclusive( EVENT_1_INTERVAL_MIN * 2, EVENT_1_INTERVAL_MAX * 2 );
                    }
                    else
                    {
                        m_NextEvent1 = Math.RandomFloatInclusive( EVENT_1_INTERVAL_MIN, EVENT_1_INTERVAL_MAX );
                    }
                
                    m_Time1 = 0;
                }
            }

            if (m_WasRecentlyGivenACleanBloodTransfusion) {
                m_TimeSinceLastInfection += deltaTime;
                if (m_TimeSinceLastInfection >= Math.RandomFloatInclusive(TIME_UNTIL_REINFECTION_MIN, TIME_UNTIL_REINFECTION_MAX)) {
                    m_WasRecentlyGivenACleanBloodTransfusion = false;
                    m_TimeSinceLastInfection = 0;
                }
            }
        }
	};

    bool GetWasRecentlyGivenACleanBloodTransfusion() {
        return m_WasRecentlyGivenACleanBloodTransfusion;
    }

    float GetTimeSinceLastInfection() {
        return m_TimeSinceLastInfection;
    }
};