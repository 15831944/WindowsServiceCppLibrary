#ifndef __INSTALLLER_HPP__
#define __INSTALLLER_HPP__
#ifdef SVCINSTALLER_EXPORTS
#define INSTALL_LIB __declspec(dllexport)
#else
#define INSTALL_LIB __declspec(dllimport)
#endif
#include "Common.hpp"
#include <string>
#include <Windows.h>

namespace WinSvcLib {
	namespace Installer {
		enum class ExecuteUser : short {
			System			= 0,
			LocalService	= 1,
			NetworkService	= 2
		};
		enum class ServiceStartType : DWORD {
			BootStart		= 0x00000000, // �V�X�e�����[�_�[���J�n����f�o�C�X�h���C�o�̎w��
			SystemStart		= 0x00000001, // IoInitSystem�֐����J�n����f�o�C�X�h���C�o���w��
			AutoStart		= 0x00000002, // �����J�n
			ManualStart		= 0x00000003, // �蓮�J�n
			Disabled		= 0x00000004, // ����
			DelayStart		= 0x00000005  // �x���J�n
		};
		enum class ServiceErrorControlType : DWORD {
			Ignore			= 0x00000000, // SERVICE_ERROR_IGNORE
			Normal			= 0x00000001, // SERVICE_ERROR_NORMAL
			Severe			= 0x00000002, // SERVICE_ERROR_SEVERE
			Critical		= 0x00000003  // SERVICE_ERROR_CRITICAL
		};
		void INSTALL_LIB InstallerLibInit(const std::basic_string<TCHAR> ServiceName, const std::basic_string<TCHAR> ExecuteFilePath, bool IsDeviceDriver);
		void INSTALL_LIB SetServiceDescription(LPTSTR Description);
		void INSTALL_LIB ChangeServiceType(const ServiceType Type);
		void INSTALL_LIB ChangeStartType(const ServiceStartType StartType);
		void INSTALL_LIB ChangeDisplayName(const std::basic_string<TCHAR> DisplayName);
		void INSTALL_LIB SetLoadOrderGroup(const std::basic_string<TCHAR> LoadOrderGroup);
		void INSTALL_LIB SetDependencies(LPCTSTR Dependencies);
		void INSTALL_LIB ChangeExecuteUser(const std::basic_string<TCHAR> UserName);
		void INSTALL_LIB ChangeExecuteUser(const ExecuteUser User);
		void INSTALL_LIB SetUserPassword(const std::basic_string<TCHAR> Passoword);
		void INSTALL_LIB InstallerLibEnd(LPDWORD lpdwTagId);
	}
}
#endif
