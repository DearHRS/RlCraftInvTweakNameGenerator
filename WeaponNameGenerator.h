#pragma once
#include <iostream>
#include <string>
#include <vector>

class WeaponNameGenerator
{
private:
	std::vector<std::string> tiers{
		"spartanfire:fire_dragonbone", "spartanfire:ice_dragonbone", "spartanfire:dragonbone", 
		"spartanweaponry:diamond", "spartanweaponry:steel", "spartanweaponry:iron", 
		"spartandefiled:umbrium", "spartanweaponry:bronze", "spartanweaponry:silver",
		"spartanweaponry:stone", "spartanweaponry:gold", "spartanweaponry:wood",
		"spartanfire:desert_venom", "spartanfire:jungle_venom", "spartanfire:desert", "spartanfire:jungle"
	};

	std::vector<std::string> weaponMod{
		"mujmajnkraftsbettersurvival"
	};

	std::vector<std::string> meleeWeaponType{
		"halberd", "battleaxe", "hammer", "warhammer", "staff", "pike", "spear", "glaive", "longsword",
		"katana", "greatsword", "saber", "mace", "lance", "rapier"
	};

	std::vector<std::string> rangedWeaponType{
		"longbow", "crossbow",
		"throwing_axe", "javelin", "throwing_knife", "dagger",
		"boomerang",
	};

	std::string CamelCase(std::string givenString);
	std::vector<std::string> SeparateModTier(std::string givenString);

public:
	WeaponNameGenerator();
	void Generate(std::vector<std::string>& weapons, std::vector<std::string>& tiers);
	void GenerateMelee();
	void GenerateRanged();
};