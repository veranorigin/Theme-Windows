#include"SystemAudioChange.h"
#include<windows.h>
#include<string>

HKEY base_key_in_SAC;//整个系统语音的改变总共要需要最底层的键了。
LONG error_1 = RegOpenKeyExW(HKEY_CURRENT_USER,L"AppEvents\\Schemes\\Apps\\.Default",0,KEY_READ | KEY_WRITE,&base_key_in_SAC);
int SystemAudioChange::SoloChange(std::wstring key,std::wstring value){
	HKEY using_hkey;
	HKEY current_hkey;
	DWORD all;
	LONG error_2 = RegCreateKeyExW(base_key_in_SAC,(std::wstring(L"\\")+key+L"\\NewPlan"+std::to_wstring(this->num)).c_str(),
		0,nullptr,REG_OPTION_NON_VOLATILE,
		KEY_READ | KEY_WRITE,nullptr,
		&using_hkey,
		&all
	);
	LONG error_3 = RegSetValueExW(
		using_hkey,
		nullptr,
		0,
		REG_SZ,
		reinterpret_cast<const BYTE*>(value.c_str()),
		static_cast<DWORD>((value.size() + 1) * sizeof(wchar_t))
	);
	LONG error_4 = RegOpenKeyExW(HKEY_CURRENT_USER,(std::wstring(L"AppEvents\\Schemes\\Apps\\.Default\\")+key+L"\\.Current").c_str(),0,KEY_READ | KEY_WRITE,&current_hkey);
	wchar_t buffer[1024];
	DWORD size = sizeof(buffer);
	DWORD type = REG_SZ;
	LONG error_5 = RegQueryValueExW(
		current_hkey,
		nullptr,
		nullptr,
		&type,
		(LPBYTE)buffer,
		&size
	);
	this->changed_list.push_back(std::wstring(buffer));
	LONG error_6 = RegSetValueExW(
		current_hkey,
		nullptr,
		0,
		REG_SZ,
		reinterpret_cast<const BYTE*>(value.c_str()),
		static_cast<DWORD>((value.size() + 1) * sizeof(wchar_t))
		);
	if(error_2 == ERROR_SUCCESS&&error_3 == ERROR_SUCCESS&&error_4 == ERROR_SUCCESS&&error_5 == ERROR_SUCCESS&&error_6 == ERROR_SUCCESS){
		return 1;
	}else{
		return 0;
	}
}
