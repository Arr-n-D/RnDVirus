class CfgPatches
{
	class RnDVirus
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts"};
	};
};
class CfgMods
{
	class RnDVirus
	{
		type = "mod";
		author = "R&D";
		name = "RnDVirus";
		dir = "RnDVirus";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"RnDVirus\scripts\4_world"};
			};

		};
	};
};

class CfgVehicles {
	class AntiChemInjector;

	class VirusVaccine: AntiChemInjector
	{
		scope = 2;
		displayName = "Virus vaccine";
		descriptionShort = "A vaccine to completely immunize you to the virus.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class VirusGiver: AntiChemInjector
	{
		scope = 2;
		displayName = "Virus giver";
		descriptionShort = "A syringe to give you the virus.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class BloodAP: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type A+";
		descriptionShort = "A syringe to give you blood type A+.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class BloodAM: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type A-";
		descriptionShort = "A syringe to give you blood type A-.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class BloodBP: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type B+";
		descriptionShort = "A syringe to give you blood type B+.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class BloodBM: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type B-";
		descriptionShort = "A syringe to give you blood type B-.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class BloodOP: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type O+";
		descriptionShort = "A syringe to give you blood type O+.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class BloodOM: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type O-";
		descriptionShort = "A syringe to give you blood type O-.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};


	class BloodABP: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type AB+";
		descriptionShort = "A syringe to give you blood type AB+.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	class BloodABM: AntiChemInjector
	{
		scope = 2;
		displayName = "Gives you blood type AB-";
		descriptionShort = "A syringe to give you blood type AB-.";
		debug_ItemCategory = 7;
		model = "Dressupbox\object\injector\injector.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
	};

	

};