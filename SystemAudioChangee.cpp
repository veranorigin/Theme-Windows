#include"SystemAudioChange.h"
#include<windows.h>
#include<string>

int SystemAudioChange::SoloChange(std::wstring key,std::wstring value,HKEY base_key_in_SAC){
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

int SystemAudioChange::do_the_change(){
	HKEY base_key_in_SAC;//整个系统语音的改变总共要需要最底层的键了。
	LONG error_1 = RegOpenKeyExW(HKEY_CURRENT_USER,L"AppEvents\\Schemes\\Apps\\.Default",0,KEY_READ | KEY_WRITE,&base_key_in_SAC);
	if(this->to_change_list._point_Default == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L".Default",this->to_change_list._point_Default,base_key_in_SAC);
	}
	if(this->to_change_list.CriticalBatteryAlarm == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"CriticalBatteryAlarm",this->to_change_list.CriticalBatteryAlarm,base_key_in_SAC);
	}
	if(this->to_change_list.DeviceConnect == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"DeviceConnect",this->to_change_list.DeviceConnect,base_key_in_SAC);
	}
	if(this->to_change_list.DeviceDisconnect == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"DeviceDisconnect",this->to_change_list.DeviceDisconnect,base_key_in_SAC);
	}
	if(this->to_change_list.DeviceFail == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"DeviceFail",this->to_change_list.DeviceFail,base_key_in_SAC);
	}
	if(this->to_change_list.FaxBeep == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"FaxBeep",this->to_change_list.FaxBeep,base_key_in_SAC);
	}
	if(this->to_change_list.LowBatteryAlarm == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"LowBatteryAlarm",this->to_change_list.LowBatteryAlarm,base_key_in_SAC);
	}
	if(this->to_change_list.MailBeep == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"MailBeep",this->to_change_list.MailBeep,base_key_in_SAC);
	}
	if(this->to_change_list.MessageNudge == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"MessageNudge",this->to_change_list.MessageNudge,base_key_in_SAC);
	}
	if(this->to_change_list.Notification_point_Default == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"Notification.Default",this->to_change_list.Notification_point_Default,base_key_in_SAC);
	}
	if(this->to_change_list.Notification_point_IM == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"Notification.IM",this->to_change_list.Notification_point_IM,base_key_in_SAC);
	}
	if(this->to_change_list.Notification_point_Mail == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"Notification.Mail",this->to_change_list.Notification_point_Mail,base_key_in_SAC);
	}
	if(this->to_change_list.Notification_point_Proximity == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"Notification.Proximity",this->to_change_list.Notification_point_Proximity,base_key_in_SAC);
	}
	if(this->to_change_list.Notification_point_Reminder == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"Notification.Reminder",this->to_change_list.Notification_point_Reminder,base_key_in_SAC);
	}
	if(this->to_change_list.Notification_point_SMS == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"Notification.SMS",this->to_change_list.Notification_point_SMS,base_key_in_SAC);
	}
	if(this->to_change_list.ProximityConnection == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"ProximityConnection",this->to_change_list.ProximityConnection,base_key_in_SAC);
	}
	if(this->to_change_list.SystemAsterisk == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"SystemAsterisk",this->to_change_list.SystemAsterisk,base_key_in_SAC);
	}
	if(this->to_change_list.SystemExclamation == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"SystemExclamation",this->to_change_list.SystemExclamation,base_key_in_SAC);
	}
	if(this->to_change_list.SystemHand == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"SystemHand",this->to_change_list.SystemHand,base_key_in_SAC);
	}
	if(this->to_change_list.SystemNotification == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"SystemNotification",this->to_change_list.SystemNotification,base_key_in_SAC);
	}
	if(this->to_change_list.WindowsUAC == L"0"){
		this->changed_list.push_back(L"0");
	}else{
		int error_default = this->SoloChange(L"WindowsUAC",this->to_change_list.WindowsUAC,base_key_in_SAC);
	}
}
