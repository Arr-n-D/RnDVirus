modded class PluginTransmissionAgents
{
    void PluginTransmissionAgents()
    {
        RegisterAgent(new VirusAgent); 
        Print("Registered Virus Agent"); 
    }
};