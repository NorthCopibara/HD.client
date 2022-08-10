#pragma once

class Player
{
public:
	void SetAuthToken(FString Token) { AccessToken = Token; }
	FString GetAuthToken() const { return AccessToken; }
	
private:
	FString AccessToken{};
};
