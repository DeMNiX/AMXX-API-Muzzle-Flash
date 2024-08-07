#if defined _api_muzzleflash_included
	#endinput
#endif
#define _api_muzzleflash_included

enum MuzzleFlash {
	Invalid_MuzzleFlash = -1
};

#if !defined _cssdk_const_included
	#define BIT(%0)                         (1<<(%0))
#endif 

enum {
	MuzzleFlashFlag_Once = BIT(0),		// Destroy after all frames are played back
	MuzzleFlashFlag_Static = BIT(1),	// Static MuzzleFlash (Can destroy by 'zc_muzzle_destroy')
	MuzzleFlashFlag_Cyclical = BIT(2),	// The sprite is played in a circle until it is removed using 'zc_muzzle_destroy'
	MuzzleFlashFlag_RandomAngle = BIT(3),	// The sprite will choose random angle sprite every call
};

/**
 * Custom MuzzleFlash Properties
 * 
 * get -> zc_muzzle_get_property
 * set -> zc_muzzle_set_property
 */
enum eMuzzleProperties {
	// ClassName of your MuzzleFlash (Default value: "ent_muzzleflash_x")
	ZC_MUZZLE_CLASSNAME = 0,	// char[ MAX_NAME_LENGTH ] | get

	// Sprite path of your MuzzleFlash (Default value: "")
	ZC_MUZZLE_SPRITE,		// char[ MAX_RESOURCE_PATH_LENGTH ] | get/set

	// Attachment for MuzzleFlash (Default value: 1)
	ZC_MUZZLE_ATTACHMENT,		// cell | get/set

	// Scale of MuzzleFlash (Default value: 0.05)
	ZC_MUZZLE_SCALE,		// Float | get/set

	// Update Time (var_nextthink) of MuzzleFlash (Default value: 0.035)
	ZC_MUZZLE_UPDATE_TIME,		// Float | get/set

	// MuzzleFlash display Time (Default value: 1.0)
	ZC_MUZZLE_FRAMERATE_MLT,	// Float | get/set

	// Color of MuzzleFlash (RGB) (Default value: 0.0, 0.0, 0.0)
	ZC_MUZZLE_COLOR,		// Float[ 3 ] | get/set

	// Brightness of MuzzleFlash (Default value: 255.0) 
	ZC_MUZZLE_ALPHA,		// Float | get/set

	// Max frames of MuzzleFlash (It is specified automatically based on how many frames there are in the sprite)
	ZC_MUZZLE_MAX_FRAMES,		// Float | get/set

	// Flags of MuzzleFlash. Specify values MuzzleFlashFlag_* (Default value: MuzzleFlashFlag_Once)
	ZC_MUZZLE_FLAGS,		// cell | get/set

	// After how long to show MuzzleFlash (Default value: 0.0)
	ZC_MUZZLE_START_TIME,        	// Float | get/set

	// Angles of muzzleflash (Default value: 0.0 to 359.0)
	ZC_MUZZLE_ANGLE        	// Float | get/set
};

/**
 * @return					Returns a index of the Muzzle Flash
 */
native MuzzleFlash: zc_muzzle_init( );

/**
 * @param iMuzzleId				Muzzle Flash Index (if Invalid_MuzzleFlash (-1), the full array is being cleared)
 * 
 * @return					Returns true if you deleted Muzzle Flash Array or Muzzle Flash index in Array
 */
native bool: zc_muzzle_clear( const MuzzleFlash: iMuzzleId = Invalid_MuzzleFlash );

/**
 * Get a Muzzle Flash property
 * 
 * @param iMuzzleId				Muzzle Flash index
 * @param iProperty				Muzzle Flash property
 * @param any:...				Other attributes
 */
native any: zc_muzzle_get_property( const MuzzleFlash: iMuzzleId, eMuzzleProperties: iProperty, any:... );

/**
 * Set a Muzzle Flash property
 * 
 * @param iMuzzleId				Muzzle Flash index
 * @param iProperty				Muzzle Flash property
 * @param any:...				Other attributes
 */
native zc_muzzle_set_property( const MuzzleFlash: iMuzzleId, eMuzzleProperties: iProperty, any:... );

/**
 * Find active Muzzle Flash
 * 
 * @param pPlayer				Player Index
 * @param iMuzzleId				Muzzle Flash index (if Invalid_MuzzleFlash (-1), find first any Muzzle Flash)
 * 
 * @return					Returns a index of Muzzle Flash entity
 */
native zc_muzzle_find( const pPlayer, const MuzzleFlash: iMuzzleId = Invalid_MuzzleFlash );

/**
 * Draw Muzzle Flash
 * 
 * @param pPlayer				Player Index
 * @param iMuzzleId				Muzzle Flash index
 * 
 * @return					Returns a index of Muzzle Flash entity
 */
native zc_muzzle_draw( const pPlayer, const MuzzleFlash: iMuzzleId = Invalid_MuzzleFlash );

/**
 * Destroy Muzzle Flash
 * 
 * @param pPlayer				Player Index (Delete for All Players: 0)
 * @param iMuzzleId				Muzzle Flash index (Delete all Muzzle Flashes: -1 / Invalid_MuzzleFlash)
 * 
 * @return					Returns true if you deleted Muzzle Flash, false if an error occurred somewhere
 */
native bool: zc_muzzle_destroy( const pPlayer, const MuzzleFlash: iMuzzleId = Invalid_MuzzleFlash );
