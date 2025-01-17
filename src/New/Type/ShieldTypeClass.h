#pragma once

#include <Utilities/Enumerable.h>
#include <Utilities/Template.h>
#include <Utilities/GeneralUtils.h>
#include <Ext/Rules/Body.h>
#include <Utilities/TemplateDef.h>

class ShieldTypeClass final : public Enumerable<ShieldTypeClass>
{
public:
	Valueable<int> Strength;
	Nullable<int> InitialStrength;
	ArmorType Armor;
	Valueable<bool> Powered;
	Valueable<double> Respawn;
	Valueable<int> Respawn_Rate;
	Valueable<double> SelfHealing;
	Valueable<int> SelfHealing_Rate;

	Valueable<bool> AbsorbOverDamage;
	Valueable<int> BracketDelta;
	Valueable<AttachedAnimFlag> IdleAnim_OfflineAction;
	Valueable<AttachedAnimFlag> IdleAnim_TemporalAction;
	Nullable<AnimTypeClass*> IdleAnim;
	Nullable<AnimTypeClass*> BreakAnim;
	Nullable<AnimTypeClass*> HitAnim;
	Nullable<WeaponTypeClass*> BreakWeapon;
	Valueable<double> AbsorbPercent;
	Valueable<double> PassPercent;

	Nullable<bool> AllowTransfer;
private:
	Valueable<double> Respawn_Rate__InMinutes;
	Valueable<double> SelfHealing_Rate__InMinutes;

public:
	ShieldTypeClass(const char* const pTitle) : Enumerable<ShieldTypeClass>(pTitle)
		, Strength(0)
		, InitialStrength()
		, Armor(Armor::None)
		, Powered(false)
		, Respawn(0.0)
		, Respawn_Rate(0)
		, SelfHealing(0.0)
		, SelfHealing_Rate(0)
		, AbsorbOverDamage(false)
		, BracketDelta(0)
		, IdleAnim_OfflineAction(AttachedAnimFlag::Hides)
		, IdleAnim_TemporalAction(AttachedAnimFlag::Hides)
		, IdleAnim()
		, BreakAnim()
		, HitAnim()
		, BreakWeapon()
		, AbsorbPercent(1.0)
		, PassPercent(0.0)
		, Respawn_Rate__InMinutes(0.0)
		, SelfHealing_Rate__InMinutes(0.0)
		, AllowTransfer()
	{};

	virtual ~ShieldTypeClass() override = default;

	virtual void LoadFromINI(CCINIClass* pINI) override;
	virtual void LoadFromStream(PhobosStreamReader& Stm);
	virtual void SaveToStream(PhobosStreamWriter& Stm);

private:
	template <typename T>
	void Serialize(T& Stm);
};
