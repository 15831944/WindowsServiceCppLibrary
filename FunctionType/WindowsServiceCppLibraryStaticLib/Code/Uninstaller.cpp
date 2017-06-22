#include "stdafx.h"
#include "Uninstaller.hpp"
#include <Windows.h>
#include <ShlObj.h>
#include <stdexcept>

static std::string GetErrorMessageA() {
	char* lpMessageBuffer = nullptr;
	const DWORD code = GetLastError();
	const DWORD length = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, code, LANG_USER_DEFAULT, (LPSTR)&lpMessageBuffer, 0, NULL);
	if (length == 0) throw std::runtime_error("�G���[���b�Z�[�W�擾���ɃG���[���������܂����B\n�G���[�R�[�h : " + std::to_string(GetLastError()));
	DWORD i = length - 3;
	for (; '\r' != lpMessageBuffer[i] && '\n' != lpMessageBuffer[i] && '\0' != lpMessageBuffer[i]; i++);//���s�����폜
	lpMessageBuffer[i] = '\0';
	std::string s = "�G���[�R�[�h : " + std::to_string(code) + "�@" + lpMessageBuffer;
	LocalFree(lpMessageBuffer);
	return s;
}

static void CloseServiceHandles(SC_HANDLE &Service, SC_HANDLE &scm) {
	CloseServiceHandle(Service);
	CloseServiceHandle(scm);
}

void WinSvcLib::Uninstaller::Uninstall(const std::basic_string<TCHAR> ServiceName) {
	if (FALSE == IsUserAnAdmin()) throw std::runtime_error("�Ǘ��Ҍ����ł̋N�����K�v�ł��B");
	SC_HANDLE scm = NULL, Service = NULL;
	if ((scm = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT)) == NULL) {
		CloseServiceHandles(Service, scm);
		throw std::runtime_error(
			"Failed In OpenSCManager Function\n"
			+ GetErrorMessageA()
		);
	}
	if ((Service = OpenService(scm, ServiceName.c_str(), DELETE)) == NULL) {
		CloseServiceHandles(Service, scm);
		throw std::runtime_error(
			"Failed In OpenService Function\n"
			+ GetErrorMessageA()
		);
	}
	if (FALSE == DeleteService(Service)) {
		CloseServiceHandles(Service, scm);
		throw std::runtime_error(
			"Failed In DeleteService Function\n"
			+ GetErrorMessageA()
		);
	}
	CloseServiceHandles(Service, scm);
}
