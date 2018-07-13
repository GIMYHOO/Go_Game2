// Fill out your copyright notice in the Description page of Project Settings.

#include "GoGameInstance.h"
#include <stdio.h>
#include <stdlib.h>


#define MAXUSER 10
#define SERVERPORT 9000
#define SERVERIP "127.0.0.1"
#define BUFSIZE 512


UGoGameInstance::UGoGameInstance()
{
	// 윈속 초기화
	


	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		UE_LOG(LogClass, Warning, TEXT("SOCKET_ERROR"));
	}

	client_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (client_sock == INVALID_SOCKET)
	{
		UE_LOG(LogClass, Warning, TEXT("SOCKET_ERROR"));
	}

	//connect()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(SERVERPORT);
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);

	retval = connect(client_sock, (SOCKADDR*)&serveraddr, sizeof(SOCKADDR));
	if (retval == SOCKET_ERROR)
	{
		UE_LOG(LogClass, Warning, TEXT("SOCKET_ERROR"));
	}

}

UGoGameInstance::~UGoGameInstance()
{
	closesocket(client_sock);
	WSACleanup();
}


int UGoGameInstance::recvn(SOCKET s, char * buf, int len, int flags)
{
	int received;
	char* ptr = buf;
	int left = len;

	while (left > 0)
	{
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
		{
			return SOCKET_ERROR;
		}
		else if (received == 0)
		{
			break;
		}
		left -= received;
		ptr += received;
	}
	return (len - left);
}
