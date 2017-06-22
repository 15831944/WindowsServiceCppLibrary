#ifndef __INSTALLLER_HPP__
#define __INSTALLLER_HPP__
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
		void InstallerLibInit(const std::basic_string<TCHAR> ServiceName, const std::basic_string<TCHAR> ExecuteFilePath, bool IsDeviceDriver);
		void SetServiceDescription(LPTSTR Description);
		void ChangeServiceType(const ServiceType Type);
		void ChangeStartType(const ServiceStartType StartType);
		void ChangeDisplayName(const std::basic_string<TCHAR> DisplayName);
		void SetLoadOrderGroup(const std::basic_string<TCHAR> LoadOrderGroup);
		void SetDependencies(LPCTSTR Dependencies);
		void ChangeExecuteUser(const std::basic_string<TCHAR> UserName);
		void ChangeExecuteUser(const ExecuteUser User);
		void SetUserPassword(const std::basic_string<TCHAR> Passoword);
		void InstallerLibEnd(LPDWORD lpdwTagId);
	}
}
#endif
