/* Again your very own basic definition*/
class DZE_Base_Object : All {
	scope = 0;
	side = 3;
	icon = "\ca\data\data\Unknown_object.paa";
	nameSound = "object";
	simulation = "house";
	picture = "pictureStaticObject";
	model="";
	sound = "Building";
	placement = "vertical";
	ladders[] = {};
	vehicleClass =  "";
	displayName = "";
	mapSize = 7.5;
	animated = true;
	armor = 2200;
	destrType = "DestructBuilding";
	damageResistance = 0.004;
	// static 
	reversed = 0;
	hasDriver = 0;
	accuracy = 0.1;
	cost = 1000;
	weapons[] = {};
	magazines[] = {};
	irTarget = 0;
	type = 1;
	threat[] = {0,0,0};
	maxSpeed = 0;
	
	//coefInside = 4;
	//coefInsideHeur = 4;

	// test settings from h barrier to see if this prevents glitching though a door
	coefInside = 0.5;
	coefInsideHeur = 0.8;

	class DestructionEffects {
		class Sound {
			simulation = "sound";
			type = "DestrHouse";
			position = "destructionEffect1";
			intensity = 1;
			interval = 1;
			lifeTime = 0.05;
		};

		class DestroyPhase1 {
			simulation = "destroy";
			type = "DelayedDestruction";
			lifeTime = 2.5;
			position = "";
			intensity = 1;
			interval = 1;
		};

		class DamageAround1 {
			simulation = "damageAround";
			type = "DamageAroundHouse";
			position = "";
			intensity = 1;
			interval = 1;
			lifeTime = 1;
		};
	};
};

/* Your very own base class for buildings*/
class DZE_Housebase : DZE_Base_Object {
	scope = 1;
	model = "";
	icon = "";
	displayName = "";
	animated = true;
	vehicleClass = "DayZ Epoch Buildables";
	nameSound = "house";
	accuracy = 0.2;
	typicalCargo[] = {};
	transportAmmo = 0;
	transportRepair = 0;
	transportFuel = 0;
	mapSize = 11;
	cost = 0;
	armor = 2200;
	reversed = 0;
	/*extern*/ class DestructionEffects;
};

class Land_DZE_WoodDoor_Base: DZE_Housebase {
	model = "\z\addons\dayz_epoch\models\small_wall_door_anim.p3d";	/* path to the object */
	displayName =  "Wood Door Base"; 		/* entry in Stringtable.csv */
	nameSound = "";						
	mapSize = 8;						/* Size of the icon */
	icon = "\ca\data\data\Unknown_object.paa";			/* Path to the picture shown in the editor. */
	accuracy = 1000;   
	armor = 2200;						/* "Lifepoints", if you like to call it that way.*/
	destrType = "DestructBuilding";		/* type of destruction, when armor = 0 */
	scope = 2;							/* Display it in the editor? 1 = No, 2 = Yes */
	offset[] = {0,1.5,0};
	class DestructionEffects : DestructionEffects
	{
		class Ruin1
		{
		simulation = "ruin";
		type = "\z\addons\dayz_epoch\models\wood_wreck_frame.p3d"; /* path to the object*/
			/* Warning, if you use a custom rubble model, it has to be defined in the cfgvehicles (see below)*/
		position = "";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
		};
	};
	maintainBuilding[] = {{"PartWoodPlywood",1},{"PartWoodLumber",1}};
};




class Land_DZE_WoodDoorLocked_Base: DZE_Housebase {
	model = "\z\addons\dayz_epoch\models\small_wall_door_anim.p3d";	/* path to the object */
	displayName =  "Wood Door Base"; 		/* entry in Stringtable.csv */
	nameSound = "";						
	mapSize = 8;						/* Size of the icon */
	icon = "\ca\data\data\Unknown_object.paa";			/* Path to the picture shown in the editor. */
	accuracy = 1000;   
	armor = 2500;						/* "Lifepoints", if you like to call it that way.*/
	destrType = "DestructBuilding";		/* type of destruction, when armor = 0 */
	scope = 2;							/* Display it in the editor? 1 = No, 2 = Yes */
	offset[] = {0,1.5,0};
	class DestructionEffects : DestructionEffects
	{
		class Ruin1
		{
		simulation = "ruin";
		type = "\z\addons\dayz_epoch\models\wood_wreck_frame.p3d"; /* path to the object*/
			/* Warning, if you use a custom rubble model, it has to be defined in the cfgvehicles (see below)*/
		position = "";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
		};
	};
	maintainBuilding[] = {{"PartWoodPlywood",1},{"PartWoodLumber",1}};
	lockable = 3;
};

class CinderWallDoor_DZ_Base: DZE_Housebase {
	model = "\z\addons\dayz_epoch\models\steel_garage_door.p3d";	/* path to the object */
	displayName =  "Block Garage Door Base"; 		/* entry in Stringtable.csv */
	nameSound = "";						
	mapSize = 8;						/* Size of the icon */
	icon = "\ca\data\data\Unknown_object.paa";			/* Path to the picture shown in the editor. */
	accuracy = 1000;   
	armor = 4000;					/* "Lifepoints", if you like to call it that way.*/
	destrType = "DestructBuilding";		/* type of destruction, when armor = 0 */
	scope = 2;							/* Display it in the editor? 1 = No, 2 = Yes */
	offset[] = {0,1.5,0};
	maintainBuilding[] = {{"MortarBucket",1}};
	class DestructionEffects : DestructionEffects
	{
		class Ruin1
		{
		simulation = "ruin";
		type = "\z\addons\dayz_epoch\models\wreck_cinder.p3d"; /* path to the object*/
			/* Warning, if you use a custom rubble model, it has to be defined in the cfgvehicles (see below)*/
		position = "";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
		};
	};
};

class CinderWallDoorLocked_DZ_Base: DZE_Housebase {
	model = "\z\addons\dayz_epoch\models\steel_garage_door.p3d";	/* path to the object */
	displayName =  "Block Garage Door Base"; 		/* entry in Stringtable.csv */
	nameSound = "";						
	mapSize = 8;						/* Size of the icon */
	icon = "\ca\data\data\Unknown_object.paa";			/* Path to the picture shown in the editor. */
	accuracy = 1000;   
	armor = 4000;					/* "Lifepoints", if you like to call it that way.*/
	destrType = "DestructBuilding";		/* type of destruction, when armor = 0 */
	scope = 2;							/* Display it in the editor? 1 = No, 2 = Yes */
	offset[] = {0,1.5,0};
	maintainBuilding[] = {{"MortarBucket",1}};
	lockable = 3;
	class DestructionEffects : DestructionEffects
	{
		class Ruin1
		{
		simulation = "ruin";
		type = "\z\addons\dayz_epoch\models\wreck_cinder.p3d"; /* path to the object*/
			/* Warning, if you use a custom rubble model, it has to be defined in the cfgvehicles (see below)*/
		position = "";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
		};
	};
};

/* Your doorsegment is derivated from the normal wall.*/
class Land_DZE_WoodDoor: Land_DZE_WoodDoor_Base {
	model = "\z\addons\dayz_epoch\models\small_wall_door_anim.p3d";
	displayName = $STR_EPOCH_WALLWITHDOOR;
	GhostPreview = "WoodDoor_Preview_DZ"; 
	upgradeBuilding[] = {"Land_DZE_WoodDoorLocked",{},{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			condition="this animationPhase ""Open_door"" < 0.5";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			condition="this animationPhase ""Open_door"" >= 0.5";
			statement="this animate [""Open_door"", 0];";
		};
	};
};

class Land_DZE_WoodDoorLocked: Land_DZE_WoodDoorLocked_Base {
	model = "\z\addons\dayz_epoch\models\small_wall_door_locked_anim.p3d";
	displayName = $STR_EPOCH_WALLWITHDOORLOCKED;
	GhostPreview = "WoodDoor_Preview_DZ"; 
	downgradeBuilding[] = {"Land_DZE_WoodDoor",{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
		class Open_hinge {
			source = "user";
			animPeriod = 1; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			//condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			statement="this animate [""Open_door"", 0]";
		};
		class Lock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_LOCK;
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			statement="PVDZE_handleSafeGear = [player,this,4];publicVariableServer ""PVDZE_handleSafeGear"";this animate [""Open_hinge"", 0]";
		};
		class Unlock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="(!keypadCancel and DZE_Lock_Door == (this getvariable['CharacterID','0'])) and (this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			statement="this animate [""Open_hinge"", 1]";
		};
		class Unlock_Door_Dialog : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="!keypadCancel and DZE_Lock_Door != (this getvariable['CharacterID','0'])";
			statement="dayz_selectedDoor = this;DZE_topCombo = 0;DZE_midCombo = 0;DZE_botCombo = 0;if(DZE_doorManagement) then {createdialog ""DoorAccess"";} else {createdialog ""ComboLockUI"";};";
		};
	};
};

class Land_DZE_LargeWoodDoor: Land_DZE_WoodDoor_Base {
	model = "\z\addons\dayz_epoch\models\large_wall_door_anim.p3d";
	displayName = $STR_EPOCH_LARGEWALLWITHDOOR;
	GhostPreview = "LargeWoodDoor_Preview_DZ";
	upgradeBuilding[] = {"Land_DZE_LargeWoodDoorLocked",{},{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			condition="this animationPhase ""Open_door"" < 0.5";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			condition="this animationPhase ""Open_door"" >= 0.5";
			statement="this animate [""Open_door"", 0]";
		};
	};
};

class Land_DZE_LargeWoodDoorLocked: Land_DZE_WoodDoorLocked_Base {
	model = "\z\addons\dayz_epoch\models\large_wall_door_locked_anim.p3d";
	displayName = $STR_EPOCH_LARGEWALLWITHDOORLOCKED;
	GhostPreview = "LargeWoodDoor_Preview_DZ";
	downgradeBuilding[] = {"Land_DZE_LargeWoodDoor",{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
		class Open_hinge {
			source = "user";
			animPeriod = 1; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			//condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			statement="this animate [""Open_door"", 0]";
		};
		class Lock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_LOCK;
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			statement="PVDZE_handleSafeGear = [player,this,4];publicVariableServer ""PVDZE_handleSafeGear"";this animate [""Open_hinge"", 0]";
		};
		class Unlock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="(!keypadCancel and DZE_Lock_Door == (this getvariable['CharacterID','0'])) and (this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			statement="this animate [""Open_hinge"", 1]";
		};
		class Unlock_Door_Dialog : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="!keypadCancel and DZE_Lock_Door != (this getvariable['CharacterID','0'])";
			statement="dayz_selectedDoor = this;DZE_topCombo = 0;DZE_midCombo = 0;DZE_botCombo = 0;if(DZE_doorManagement) then {createdialog ""DoorAccess"";} else {createdialog ""ComboLockUI"";};";
		};
	};
};

class Land_DZE_GarageWoodDoor: Land_DZE_WoodDoor_Base {
	model = "\z\addons\dayz_epoch\models\Garage_door_anim.p3d";
	displayName = $STR_EPOCH_WOODGARAGEDOOR;
	GhostPreview = "GarageWoodDoor_Preview_DZ";
	upgradeBuilding[] = {"Land_DZE_GarageWoodDoorLocked",{},{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			condition="this animationPhase ""Open_door"" < 0.5";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			condition="this animationPhase ""Open_door"" >= 0.5";
			statement="this animate [""Open_door"", 0]";
		};
	};
};

class Land_DZE_GarageWoodDoorLocked: Land_DZE_WoodDoorLocked_Base {
	model = "\z\addons\dayz_epoch\models\Garage_door_locked_anim.p3d";
	displayName = $STR_EPOCH_WOODGARAGEDOORLOCKED;
	GhostPreview = "GarageWoodDoor_Preview_DZ";
	downgradeBuilding[] = {"Land_DZE_GarageWoodDoor",{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
		class Open_hinge {
			source = "user";
			animPeriod = 1; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			//condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			statement="this animate [""Open_door"", 0]";
		};
		class Lock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_LOCK;
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			statement="PVDZE_handleSafeGear = [player,this,4];publicVariableServer ""PVDZE_handleSafeGear"";this animate [""Open_hinge"", 0]";
		};
		class Unlock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="(!keypadCancel and DZE_Lock_Door == (this getvariable['CharacterID','0'])) and (this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			statement="this animate [""Open_hinge"", 1]";
		};
		class Unlock_Door_Dialog : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="!keypadCancel and DZE_Lock_Door != (this getvariable['CharacterID','0'])";
			statement="dayz_selectedDoor = this;DZE_topCombo = 0;DZE_midCombo = 0;DZE_botCombo = 0;if(DZE_doorManagement) then {createdialog ""DoorAccess"";} else {createdialog ""ComboLockUI"";};";
		};
	};
};


class CinderWallDoorLocked_DZ: CinderWallDoorLocked_DZ_Base {
	model = "\z\addons\dayz_epoch\models\steel_garage_locked.p3d";
	displayName = $STR_EPOCH_BLOCKGARAGEDOORLOCKED;
	GhostPreview = "CinderWallDoorway_Preview_DZ";
	downgradeBuilding[] = {"CinderWallDoor_DZ",{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
		class Open_latch {
			source = "user";
			animPeriod = 1; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_latch"" == 1)";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			//condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_latch"" == 1)";
			statement="this animate [""Open_door"", 0]";
		};
		class Lock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_LOCK;
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_latch"" == 1)";
			statement="PVDZE_handleSafeGear = [player,this,4];publicVariableServer ""PVDZE_handleSafeGear"";this animate [""Open_latch"", 0]";
		};
		class Unlock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="(!keypadCancel and DZE_Lock_Door == (this getvariable['CharacterID','0'])) and (this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_latch"" == 0)";
			statement="this animate [""Open_latch"", 1]";
		};
		class Unlock_Door_Dialog : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="!keypadCancel and DZE_Lock_Door != (this getvariable['CharacterID','0'])";
			statement="dayz_selectedDoor = this;DZE_topCombo = 0;DZE_midCombo = 0;DZE_botCombo = 0;if(DZE_doorManagement) then {createdialog ""DoorAccess"";} else {createdialog ""ComboLockUI"";};";
		};
	};
};


class CinderWallDoor_DZ: CinderWallDoor_DZ_Base {
	model = "\z\addons\dayz_epoch\models\steel_garage_door.p3d";
	displayName = $STR_EPOCH_BLOCKGARAGEDOOR;
	GhostPreview = "CinderWallDoorway_Preview_DZ";
	upgradeBuilding[] = {"CinderWallDoorLocked_DZ",{},{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			condition="this animationPhase ""Open_door"" < 0.5";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			condition="this animationPhase ""Open_door"" >= 0.5";
			statement="this animate [""Open_door"", 0]";
		};
	};
};



class CinderWallDoorSmallLocked_DZ: CinderWallDoorLocked_DZ_Base {
	model = "\z\addons\dayz_epoch\models\Steel_door_locked.p3d";
	displayName = $STR_EPOCH_BLOCKDOORLOCKED;
	GhostPreview = "CinderWallSmallDoorway_Preview_DZ";
	downgradeBuilding[] = {"CinderWallDoorSmall_DZ",{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
		class Open_latch {
			source = "user";
			animPeriod = 1; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{			
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_latch"" == 1)";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			//condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_hinge"" == 1)";
			condition="(this animationPhase ""Open_door"" == 1) and (this animationPhase ""Open_latch"" == 1)";
			statement="this animate [""Open_door"", 0]";
		};
		class Lock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_LOCK;
			condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_latch"" == 1)";
			statement="PVDZE_handleSafeGear = [player,this,4];publicVariableServer ""PVDZE_handleSafeGear"";this animate [""Open_latch"", 0]";
		};
		class Unlock_Door : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="(!keypadCancel and DZE_Lock_Door == (this getvariable['CharacterID','0'])) and (this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_latch"" == 0)";
			statement="this animate [""Open_latch"", 1]";
		};
		class Unlock_Door_Dialog : Open_Door
		{
			displayName=$STR_EPOCH_DOORS_UNLOCK;
			//condition="(this animationPhase ""Open_door"" == 0) and (this animationPhase ""Open_hinge"" == 0)";
			condition="!keypadCancel and DZE_Lock_Door != (this getvariable['CharacterID','0'])";
			statement="dayz_selectedDoor = this;DZE_topCombo = 0;DZE_midCombo = 0;DZE_botCombo = 0;if(DZE_doorManagement) then {createdialog ""DoorAccess"";} else {createdialog ""ComboLockUI"";};";
		};
	};
};


class CinderWallDoorSmall_DZ: CinderWallDoor_DZ_Base {
	model = "\z\addons\dayz_epoch\models\Steel_door.p3d";
	displayName = $STR_EPOCH_BLOCKDOOR;
	GhostPreview = "CinderWallSmallDoorway_Preview_DZ";
	upgradeBuilding[] = {"CinderWallDoorSmallLocked_DZ",{},{{"ItemComboLock",1}}};
	/* Arma needs to know, how the animation trigger is triggered*/
	class AnimationSources {
			/* name must be identical to the one given by the model.cfg ("Open_Door")" */
		class Open_door {
			source = "user";
			animPeriod = 4; /* duration in seconds */
			initPhase = 0; 
		};
	};
	
	/* The entry to the actionmenu */
	class UserActions
	{
		class Open_Door
		{
			displayName=$STR_DN_OUT_O_DOOR;
			onlyforplayer = true;
			position="Door_knopf";
			radius=3; /* visibility distance of the entry */
			condition="this animationPhase ""Open_door"" < 0.5";
			statement="this animate [""Open_door"", 1]";
		};
		class Close_Door : Open_Door
		{
			displayName=$STR_DN_OUT_C_DOOR;
			condition="this animationPhase ""Open_door"" >= 0.5";
			statement="this animate [""Open_door"", 0]";
		};
	};
};

/*
	Vanilla DayZ buildables are defined in \dayz_buildings\configs\
	Only included here to overwrite vanilla ItemPadlock with Epoch ItemComboLock
*/
class WoodenGate_Base;
class WoodenGate_1: WoodenGate_Base
{
	class Upgrade { //to next stage
		requiredTools[] = {"ItemEtool","ItemToolbox"}; 
		requiredParts[] = {"ItemLog","ItemComboLock"};
		create = "WoodenGate_2";
	};
	class Disassembly {
		requiredTools[] = {"ItemToolbox"};
	};
};
