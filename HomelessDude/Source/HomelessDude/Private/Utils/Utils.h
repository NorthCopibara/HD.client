#pragma once

//TODO
#define STRINGIFY(Identifier) #Identifier
#define ENUM_VALUE_TO_STRING(EnumType, EnumValue) \
FindObject<UEnum>(ANY_PACKAGE, TEXT(STRINGIFY(EnumType)), true)->GetNameStringByIndex(static_cast<uint8>(EnumValue));

class Utils
{
public:
	template<typename EnumType>
	static EnumType StringToEnum(FString String)
	{
		const UEnum* Enum = StaticEnum<EnumType>();
		int64 EnumValue = Enum->GetValueByNameString(String);
		return static_cast<EnumType>(EnumValue);
	}
};
