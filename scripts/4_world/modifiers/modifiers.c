modded class ModifiersManager
{
    override void Init()
    {
        super.Init();
        AddModifier(new VirusMdfr);
        Print("Registered Virus Modifier ");
    }
};