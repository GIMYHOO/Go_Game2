// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <WinSock2.h>
#include "GoGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GO_GAME_API UGoGameInstance : public UGameInstance
{
	GENERATED_BODY()	
private:
	
	WSADATA wsa;
	SOCKET client_sock;				// ╪рдо
	int retval;

public:
	
	UGoGameInstance();
	~UGoGameInstance();
	int recvn(SOCKET s, char* buf, int len, int flags);
	
	
};
