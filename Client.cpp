#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32")

using namespace std;

int main()
{
	// 1. Socket ���� �۾�
	WSAData wsaData;
	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (Result != 0)
	{
		cout << "Winsock dll error : " << GetLastError() << endl;
		exit(-1);
	}

	// ȣ��Ʈ ������ �����ϱ� ���� ����ü �������Դϴ�.
	// gethostbyname �Լ��� "naver.com" �� ������ ����ϴ�.
	HOSTENT* ServerInfo;
	ServerInfo = gethostbyname("naver.com");

	/*
	if (ServerInfo)
	{
		// ȣ��Ʈ �ּҰ� IPv4 �ּ����� Ȯ���մϴ�.
		if (ServerInfo->h_addrtype == AF_INET)
		{
			// ���� ���̹��� �˾Ƴ��� ���
			cout << ServerInfo->h_name << endl;
			int i = 0;

			// IPv4 ����� �ּҸ� �����մϴ�.
			IN_ADDR IP;
			while (ServerInfo->h_addr_list[i] != 0)
			{
				// �޾ƿ� 4����Ʈ�� ������ �ٽ� ���ڿ��� ��ȯ
				// �̸� ���ؼ� 4����Ʈ Ÿ���� long Ÿ���� �����͸� ���
				// ȣ��Ʈ�� IPv4 �ּ� ����� �ݺ��ϸ鼭 �ּҸ� ������ ����մϴ�.
				IP.s_addr = *(u_long*)ServerInfo->h_addr_list[i];

				// inet_ntoa : �޾ƿ� IP �� ���ڿ��� ��ȯ���ִ� �Լ��Դϴ�.
				printf("ip : %s\n", inet_ntoa(IP));
				i++;
			}
		}
		// IPv6 �� �Ѵٸ� else �� �߰��ؼ� ���ܻ��׿� ���ؼ� �߰����ݴϴ�.
	}
	*/

	// ������ ������, Reverse DNS
	char IPAddress[] = "223.130.200.107";
	ServerInfo = gethostbyaddr(IPAddress, strlen(IPAddress), AF_INET);
	if (ServerInfo)
	{
		if (ServerInfo->h_addrtype == AF_INET)
		{
			cout << ServerInfo->h_name << endl;
		}
	}

	WSACleanup();

	return 0;
}