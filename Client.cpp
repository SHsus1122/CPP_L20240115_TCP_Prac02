#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32")

using namespace std;

int main()
{
	// 1. Socket 시작 작업
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (Result != 0)
	{
		cout << "Winsock dll error : " << GetLastError() << endl;
		exit(-1);
	}

	// 호스트 정보를 저장하기 위한 구조체 포인터입니다.
	// gethostbyname 함수로 "naver.com" 의 정보를 얻습니다.
	HOSTENT* ServerInfo;
	ServerInfo = gethostbyname("naver.com");

	if (ServerInfo)
	{
		// 호스트 주소가 IPv4 주소인지 확인합니다.
		if (ServerInfo->h_addrtype == AF_INET)
		{
			// 정규 네이밍을 알아내는 방법
			cout << ServerInfo->h_name << endl;
			int i = 0;

			// IPv4 방식의 주소를 저장합니다.
			IN_ADDR IP;
			while (ServerInfo->h_addr_list[i] != 0)
			{
				// 받아온 4바이트의 정보를 다시 문자열로 변환
				// 이를 위해서 4바이트 타입인 long 타입의 포인터를 사용
				// 호스트의 IPv4 주소 목록을 반복하면서 주소를 가져와 출력합니다.
				IP.s_addr = *(u_long*)ServerInfo->h_addr_list[i];
				printf("ip : %s\n", inet_ntoa(IP));
				i++;
			}
		}
		// IPv6 를 한다면 else 를 추가해서 예외사항에 대해서 추가해줍니다.
	}

	WSACleanup();


	return 0;
}